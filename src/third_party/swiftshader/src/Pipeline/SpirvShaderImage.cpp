// Copyright 2019 The SwiftShader Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "SpirvShader.hpp"

#include "System/Types.hpp"

#include "Vulkan/VkDescriptorSetLayout.hpp"
#include "Vulkan/VkPipelineLayout.hpp"

#include <spirv/unified1/spirv.hpp>

namespace {

VkFormat SpirvFormatToVulkanFormat(spv::ImageFormat format)
{
	switch(format)
	{
		case spv::ImageFormatRgba32f: return VK_FORMAT_R32G32B32A32_SFLOAT;
		case spv::ImageFormatRgba32i: return VK_FORMAT_R32G32B32A32_SINT;
		case spv::ImageFormatRgba32ui: return VK_FORMAT_R32G32B32A32_UINT;
		case spv::ImageFormatR32f: return VK_FORMAT_R32_SFLOAT;
		case spv::ImageFormatR32i: return VK_FORMAT_R32_SINT;
		case spv::ImageFormatR32ui: return VK_FORMAT_R32_UINT;
		case spv::ImageFormatRgba8: return VK_FORMAT_R8G8B8A8_UNORM;
		case spv::ImageFormatRgba8Snorm: return VK_FORMAT_R8G8B8A8_SNORM;
		case spv::ImageFormatRgba8i: return VK_FORMAT_R8G8B8A8_SINT;
		case spv::ImageFormatRgba8ui: return VK_FORMAT_R8G8B8A8_UINT;
		case spv::ImageFormatRgba16f: return VK_FORMAT_R16G16B16A16_SFLOAT;
		case spv::ImageFormatRgba16i: return VK_FORMAT_R16G16B16A16_SINT;
		case spv::ImageFormatRgba16ui: return VK_FORMAT_R16G16B16A16_UINT;
		case spv::ImageFormatRg32f: return VK_FORMAT_R32G32_SFLOAT;
		case spv::ImageFormatRg32i: return VK_FORMAT_R32G32_SINT;
		case spv::ImageFormatRg32ui: return VK_FORMAT_R32G32_UINT;
		case spv::ImageFormatRg16f: return VK_FORMAT_R16G16_SFLOAT;
		case spv::ImageFormatRg16i: return VK_FORMAT_R16G16_SINT;
		case spv::ImageFormatRg16ui: return VK_FORMAT_R16G16_UINT;

		default:
			UNSUPPORTED("SPIR-V ImageFormat %u", format);
			return VK_FORMAT_UNDEFINED;
	}
}

sw::SIMD::Float sRGBtoLinear(sw::SIMD::Float c)
{
	sw::SIMD::Float lc = c * sw::SIMD::Float(1.0f / 12.92f);
	sw::SIMD::Float ec = sw::power((c + sw::SIMD::Float(0.055f)) * sw::SIMD::Float(1.0f / 1.055f), sw::SIMD::Float(2.4f));

	sw::SIMD::Int linear = CmpLT(c, sw::SIMD::Float(0.04045f));

	return rr::As<sw::SIMD::Float>((linear & rr::As<sw::SIMD::Int>(lc)) | (~linear & rr::As<sw::SIMD::Int>(ec)));  // TODO: IfThenElse()
}

}  // anonymous namespace

namespace sw {

SpirvShader::EmitResult SpirvShader::EmitImageSampleImplicitLod(Variant variant, InsnIterator insn, EmitState *state) const
{
	return EmitImageSample({ variant, Implicit }, insn, state);
}

SpirvShader::EmitResult SpirvShader::EmitImageGather(Variant variant, InsnIterator insn, EmitState *state) const
{
	ImageInstruction instruction = { variant, Gather };
	instruction.gatherComponent = !instruction.isDref() ? getObject(insn.word(5)).constantValue[0] : 0;

	return EmitImageSample(instruction, insn, state);
}

SpirvShader::EmitResult SpirvShader::EmitImageSampleExplicitLod(Variant variant, InsnIterator insn, EmitState *state) const
{
	auto isDref = (variant == Dref) || (variant == ProjDref);
	uint32_t imageOperands = static_cast<spv::ImageOperandsMask>(insn.word(isDref ? 6 : 5));
	imageOperands &= ~spv::ImageOperandsConstOffsetMask;  // Dealt with later.

	if((imageOperands & spv::ImageOperandsLodMask) == imageOperands)
	{
		return EmitImageSample({ variant, Lod }, insn, state);
	}
	else if((imageOperands & spv::ImageOperandsGradMask) == imageOperands)
	{
		return EmitImageSample({ variant, Grad }, insn, state);
	}
	else
		UNSUPPORTED("Image Operands %x", imageOperands);

	return EmitResult::Continue;
}

SpirvShader::EmitResult SpirvShader::EmitImageFetch(InsnIterator insn, EmitState *state) const
{
	return EmitImageSample({ None, Fetch }, insn, state);
}

SpirvShader::EmitResult SpirvShader::EmitImageSample(ImageInstruction instruction, InsnIterator insn, EmitState *state) const
{
	auto &resultType = getType(insn.resultTypeId());
	auto &result = state->createIntermediate(insn.resultId(), resultType.componentCount);
	Array<SIMD::Float> out(4);

	// TODO(b/153380916): When we're in a code path that is always executed,
	// i.e. post-dominators of the entry block, we don't have to dynamically
	// check whether any lanes are active, and can elide the jump.
	If(AnyTrue(state->activeLaneMask()))
	{
		EmitImageSampleUnconditional(out, instruction, insn, state);
	}

	for(auto i = 0u; i < resultType.componentCount; i++) { result.move(i, out[i]); }

	return EmitResult::Continue;
}

void SpirvShader::EmitImageSampleUnconditional(Array<SIMD::Float> &out, ImageInstruction instruction, InsnIterator insn, EmitState *state) const
{
	Object::ID sampledImageId = insn.word(3);  // For OpImageFetch this is just an Image, not a SampledImage.
	Object::ID coordinateId = insn.word(4);

	auto imageDescriptor = state->getPointer(sampledImageId).base;  // vk::SampledImageDescriptor*

	// If using a separate sampler, look through the OpSampledImage instruction to find the sampler descriptor
	auto &sampledImage = getObject(sampledImageId);
	auto samplerDescriptor = (sampledImage.opcode() == spv::OpSampledImage) ? state->getPointer(sampledImage.definition.word(4)).base : imageDescriptor;

	auto coordinate = Operand(this, state, coordinateId);

	Pointer<Byte> sampler = samplerDescriptor + OFFSET(vk::SampledImageDescriptor, sampler);  // vk::Sampler*
	Pointer<Byte> texture = imageDescriptor + OFFSET(vk::SampledImageDescriptor, texture);    // sw::Texture*

	// Above we assumed that if the SampledImage operand is not the result of an OpSampledImage,
	// it must be a combined image sampler loaded straight from the descriptor set. For OpImageFetch
	// it's just an Image operand, so there's no sampler descriptor data.
	if(getType(sampledImage).opcode() != spv::OpTypeSampledImage)
	{
		sampler = Pointer<Byte>(nullptr);
	}

	uint32_t imageOperands = spv::ImageOperandsMaskNone;
	bool lodOrBias = false;
	Object::ID lodOrBiasId = 0;
	bool grad = false;
	Object::ID gradDxId = 0;
	Object::ID gradDyId = 0;
	bool constOffset = false;
	Object::ID offsetId = 0;
	bool sample = false;
	Object::ID sampleId = 0;

	uint32_t operand = (instruction.isDref() || instruction.samplerMethod == Gather) ? 6 : 5;

	if(insn.wordCount() > operand)
	{
		imageOperands = static_cast<spv::ImageOperandsMask>(insn.word(operand++));

		if(imageOperands & spv::ImageOperandsBiasMask)
		{
			lodOrBias = true;
			lodOrBiasId = insn.word(operand);
			operand++;
			imageOperands &= ~spv::ImageOperandsBiasMask;

			ASSERT(instruction.samplerMethod == Implicit);
			instruction.samplerMethod = Bias;
		}

		if(imageOperands & spv::ImageOperandsLodMask)
		{
			lodOrBias = true;
			lodOrBiasId = insn.word(operand);
			operand++;
			imageOperands &= ~spv::ImageOperandsLodMask;
		}

		if(imageOperands & spv::ImageOperandsGradMask)
		{
			ASSERT(!lodOrBias);  // SPIR-V 1.3: "It is invalid to set both the Lod and Grad bits." Bias is for ImplicitLod, Grad for ExplicitLod.
			grad = true;
			gradDxId = insn.word(operand + 0);
			gradDyId = insn.word(operand + 1);
			operand += 2;
			imageOperands &= ~spv::ImageOperandsGradMask;
		}

		if(imageOperands & spv::ImageOperandsConstOffsetMask)
		{
			constOffset = true;
			offsetId = insn.word(operand);
			operand++;
			imageOperands &= ~spv::ImageOperandsConstOffsetMask;
		}

		if(imageOperands & spv::ImageOperandsSampleMask)
		{
			sample = true;
			sampleId = insn.word(operand);
			imageOperands &= ~spv::ImageOperandsSampleMask;

			ASSERT(instruction.samplerMethod == Fetch);
			instruction.sample = true;
		}

		if(imageOperands != 0)
		{
			UNSUPPORTED("Image operand %x", imageOperands);
		}
	}

	Array<SIMD::Float> in(16);  // Maximum 16 input parameter components.

	uint32_t coordinates = coordinate.componentCount - instruction.isProj();
	instruction.coordinates = coordinates;

	uint32_t i = 0;
	for(; i < coordinates; i++)
	{
		if(instruction.isProj())
		{
			in[i] = coordinate.Float(i) / coordinate.Float(coordinates);  // TODO(b/129523279): Optimize using reciprocal.
		}
		else
		{
			in[i] = coordinate.Float(i);
		}
	}

	if(instruction.isDref())
	{
		auto drefValue = Operand(this, state, insn.word(5));

		if(instruction.isProj())
		{
			in[i] = drefValue.Float(0) / coordinate.Float(coordinates);  // TODO(b/129523279): Optimize using reciprocal.
		}
		else
		{
			in[i] = drefValue.Float(0);
		}

		i++;
	}

	if(lodOrBias)
	{
		auto lodValue = Operand(this, state, lodOrBiasId);
		in[i] = lodValue.Float(0);
		i++;
	}
	else if(grad)
	{
		auto dxValue = Operand(this, state, gradDxId);
		auto dyValue = Operand(this, state, gradDyId);
		ASSERT(dxValue.componentCount == dxValue.componentCount);

		instruction.grad = dxValue.componentCount;

		for(uint32_t j = 0; j < dxValue.componentCount; j++, i++)
		{
			in[i] = dxValue.Float(j);
		}

		for(uint32_t j = 0; j < dxValue.componentCount; j++, i++)
		{
			in[i] = dyValue.Float(j);
		}
	}
	else if(instruction.samplerMethod == Fetch)
	{
		// The instruction didn't provide a lod operand, but the sampler's Fetch
		// function requires one to be present. If no lod is supplied, the default
		// is zero.
		in[i] = As<SIMD::Float>(SIMD::Int(0));
		i++;
	}

	if(constOffset)
	{
		auto offsetValue = Operand(this, state, offsetId);
		instruction.offset = offsetValue.componentCount;

		for(uint32_t j = 0; j < offsetValue.componentCount; j++, i++)
		{
			in[i] = As<SIMD::Float>(offsetValue.Int(j));  // Integer values, but transfered as float.
		}
	}

	if(sample)
	{
		auto sampleValue = Operand(this, state, sampleId);
		in[i] = As<SIMD::Float>(sampleValue.Int(0));
	}

	auto cacheIt = state->routine->samplerCache.find(insn.resultId());
	ASSERT(cacheIt != state->routine->samplerCache.end());
	auto &cache = cacheIt->second;
	auto cacheHit = cache.imageDescriptor == imageDescriptor && cache.sampler == sampler;

	If(!cacheHit)
	{
		cache.function = Call(getImageSampler, instruction.parameters, imageDescriptor, sampler);
		cache.imageDescriptor = imageDescriptor;
		cache.sampler = sampler;
	}

	Call<ImageSampler>(cache.function, texture, &in[0], &out[0], state->routine->constants);
}

SpirvShader::EmitResult SpirvShader::EmitImageQuerySizeLod(InsnIterator insn, EmitState *state) const
{
	auto &resultTy = getType(Type::ID(insn.resultTypeId()));
	auto imageId = Object::ID(insn.word(3));
	auto lodId = Object::ID(insn.word(4));

	auto &dst = state->createIntermediate(insn.resultId(), resultTy.componentCount);
	GetImageDimensions(state, resultTy, imageId, lodId, dst);

	return EmitResult::Continue;
}

SpirvShader::EmitResult SpirvShader::EmitImageQuerySize(InsnIterator insn, EmitState *state) const
{
	auto &resultTy = getType(Type::ID(insn.resultTypeId()));
	auto imageId = Object::ID(insn.word(3));
	auto lodId = Object::ID(0);

	auto &dst = state->createIntermediate(insn.resultId(), resultTy.componentCount);
	GetImageDimensions(state, resultTy, imageId, lodId, dst);

	return EmitResult::Continue;
}

SpirvShader::EmitResult SpirvShader::EmitImageQueryLod(InsnIterator insn, EmitState *state) const
{
	return EmitImageSample({ None, Query }, insn, state);
}

void SpirvShader::GetImageDimensions(EmitState const *state, Type const &resultTy, Object::ID imageId, Object::ID lodId, Intermediate &dst) const
{
	auto routine = state->routine;
	auto &image = getObject(imageId);
	auto &imageType = getType(image);

	ASSERT(imageType.definition.opcode() == spv::OpTypeImage);
	bool isArrayed = imageType.definition.word(5) != 0;
	bool isCubeMap = imageType.definition.word(3) == spv::DimCube;

	const DescriptorDecorations &d = descriptorDecorations.at(imageId);
	auto descriptorType = routine->pipelineLayout->getDescriptorType(d.DescriptorSet, d.Binding);

	Pointer<Byte> descriptor = state->getPointer(imageId).base;

	Pointer<Int> extent;
	Int arrayLayers;

	switch(descriptorType)
	{
		case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
		case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
		{
			extent = descriptor + OFFSET(vk::StorageImageDescriptor, extent);                           // int[3]*
			arrayLayers = *Pointer<Int>(descriptor + OFFSET(vk::StorageImageDescriptor, arrayLayers));  // uint32_t
			break;
		}
		case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
		case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
		case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
		{
			extent = descriptor + OFFSET(vk::SampledImageDescriptor, extent);                           // int[3]*
			arrayLayers = *Pointer<Int>(descriptor + OFFSET(vk::SampledImageDescriptor, arrayLayers));  // uint32_t
			break;
		}
		default:
			UNREACHABLE("Image descriptorType: %d", int(descriptorType));
	}

	auto dimensions = resultTy.componentCount - (isArrayed ? 1 : 0);
	std::vector<Int> out;
	if(lodId != 0)
	{
		auto lodVal = Operand(this, state, lodId);
		ASSERT(lodVal.componentCount == 1);
		auto lod = lodVal.Int(0);
		auto one = SIMD::Int(1);
		for(uint32_t i = 0; i < dimensions; i++)
		{
			dst.move(i, Max(SIMD::Int(extent[i]) >> lod, one));
		}
	}
	else
	{
		for(uint32_t i = 0; i < dimensions; i++)
		{
			dst.move(i, SIMD::Int(extent[i]));
		}
	}

	if(isArrayed)
	{
		auto numElements = isCubeMap ? (arrayLayers / 6) : RValue<Int>(arrayLayers);
		dst.move(dimensions, SIMD::Int(numElements));
	}
}

SpirvShader::EmitResult SpirvShader::EmitImageQueryLevels(InsnIterator insn, EmitState *state) const
{
	auto &resultTy = getType(Type::ID(insn.resultTypeId()));
	ASSERT(resultTy.componentCount == 1);
	auto imageId = Object::ID(insn.word(3));

	const DescriptorDecorations &d = descriptorDecorations.at(imageId);
	auto descriptorType = state->routine->pipelineLayout->getDescriptorType(d.DescriptorSet, d.Binding);

	Pointer<Byte> descriptor = state->getPointer(imageId).base;
	Int mipLevels = 0;
	switch(descriptorType)
	{
		case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
		case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
		case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
			mipLevels = *Pointer<Int>(descriptor + OFFSET(vk::SampledImageDescriptor, mipLevels));  // uint32_t
			break;
		default:
			UNREACHABLE("Image descriptorType: %d", int(descriptorType));
	}

	auto &dst = state->createIntermediate(insn.resultId(), 1);
	dst.move(0, SIMD::Int(mipLevels));

	return EmitResult::Continue;
}

SpirvShader::EmitResult SpirvShader::EmitImageQuerySamples(InsnIterator insn, EmitState *state) const
{
	auto &resultTy = getType(Type::ID(insn.resultTypeId()));
	ASSERT(resultTy.componentCount == 1);
	auto imageId = Object::ID(insn.word(3));
	auto imageTy = getType(getObject(imageId));
	ASSERT(imageTy.definition.opcode() == spv::OpTypeImage);
	ASSERT(imageTy.definition.word(3) == spv::Dim2D);
	ASSERT(imageTy.definition.word(6 /* MS */) == 1);

	const DescriptorDecorations &d = descriptorDecorations.at(imageId);
	auto descriptorType = state->routine->pipelineLayout->getDescriptorType(d.DescriptorSet, d.Binding);

	Pointer<Byte> descriptor = state->getPointer(imageId).base;
	Int sampleCount = 0;
	switch(descriptorType)
	{
		case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
			sampleCount = *Pointer<Int>(descriptor + OFFSET(vk::StorageImageDescriptor, sampleCount));  // uint32_t
			break;
		case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
		case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
		case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
			sampleCount = *Pointer<Int>(descriptor + OFFSET(vk::SampledImageDescriptor, sampleCount));  // uint32_t
			break;
		default:
			UNREACHABLE("Image descriptorType: %d", int(descriptorType));
	}

	auto &dst = state->createIntermediate(insn.resultId(), 1);
	dst.move(0, SIMD::Int(sampleCount));

	return EmitResult::Continue;
}

SIMD::Pointer SpirvShader::GetTexelAddress(EmitState const *state, Pointer<Byte> imageBase, Int imageSizeInBytes, Operand const &coordinate, Type const &imageType, Pointer<Byte> descriptor, int texelSize, Object::ID sampleId, bool useStencilAspect, OutOfBoundsBehavior outOfBoundsBehavior) const
{
	auto routine = state->routine;
	bool isArrayed = imageType.definition.word(5) != 0;
	auto dim = static_cast<spv::Dim>(imageType.definition.word(3));
	int dims = coordinate.componentCount - (isArrayed ? 1 : 0);

	SIMD::Int u = coordinate.Int(0);
	SIMD::Int v = SIMD::Int(0);

	if(coordinate.componentCount > 1)
	{
		v = coordinate.Int(1);
	}

	if(dim == spv::DimSubpassData)
	{
		u += routine->windowSpacePosition[0];
		v += routine->windowSpacePosition[1];
	}

	auto rowPitch = SIMD::Int(*Pointer<Int>(descriptor + (useStencilAspect
	                                                          ? OFFSET(vk::StorageImageDescriptor, stencilRowPitchBytes)
	                                                          : OFFSET(vk::StorageImageDescriptor, rowPitchBytes))));
	auto slicePitch = SIMD::Int(
	    *Pointer<Int>(descriptor + (useStencilAspect
	                                    ? OFFSET(vk::StorageImageDescriptor, stencilSlicePitchBytes)
	                                    : OFFSET(vk::StorageImageDescriptor, slicePitchBytes))));
	auto samplePitch = SIMD::Int(
	    *Pointer<Int>(descriptor + (useStencilAspect
	                                    ? OFFSET(vk::StorageImageDescriptor, stencilSamplePitchBytes)
	                                    : OFFSET(vk::StorageImageDescriptor, samplePitchBytes))));

	SIMD::Int ptrOffset = u * SIMD::Int(texelSize);

	if(dims > 1)
	{
		ptrOffset += v * rowPitch;
	}

	SIMD::Int w = 0;
	if((dims > 2) || isArrayed)
	{
		if(dims > 2)
		{
			w += coordinate.Int(2);
		}

		if(isArrayed)
		{
			w += coordinate.Int(dims);
		}

		ptrOffset += w * slicePitch;
	}

	if(dim == spv::DimSubpassData)
	{
		// Multiview input attachment access is to the layer corresponding to the current view
		ptrOffset += SIMD::Int(routine->viewID) * slicePitch;
	}

	if(sampleId.value())
	{
		Operand sample(this, state, sampleId);
		ptrOffset += sample.Int(0) * samplePitch;
	}

	// If the out-of-bounds behavior is set to nullify, then each coordinate must be tested individually.
	// Other out-of-bounds behaviors work properly by just comparing the offset against the total size.
	if(outOfBoundsBehavior == OutOfBoundsBehavior::Nullify)
	{
		auto width = SIMD::UInt(*Pointer<UInt>(descriptor + OFFSET(vk::StorageImageDescriptor, extent.width)));
		SIMD::Int oobMask = As<SIMD::Int>(CmpNLT(As<SIMD::UInt>(u), width));

		if(dims > 1)
		{
			auto height = SIMD::UInt(*Pointer<UInt>(descriptor + OFFSET(vk::StorageImageDescriptor, extent.height)));
			oobMask |= As<SIMD::Int>(CmpNLT(As<SIMD::UInt>(v), height));
		}

		if((dims > 2) || isArrayed)
		{
			auto depth = *Pointer<UInt>(descriptor + OFFSET(vk::StorageImageDescriptor, extent.depth));
			auto arrayLayers = *Pointer<UInt>(descriptor + OFFSET(vk::StorageImageDescriptor, arrayLayers));
			oobMask |= As<SIMD::Int>(CmpNLT(As<SIMD::UInt>(w), SIMD::UInt(depth * arrayLayers)));
		}

		constexpr int32_t OOB_OFFSET = 0x7FFFFFFF - 16;  // SIMD pointer offsets are signed 32-bit, so this is the largest offset (for 16-byte texels).
		static_assert(OOB_OFFSET >= MAX_MEMORY_ALLOCATION_SIZE, "the largest offset must be guaranteed to be out-of-bounds");

		ptrOffset = (ptrOffset & ~oobMask) | (oobMask & SIMD::Int(OOB_OFFSET));  // oob ? OOB_OFFSET : ptrOffset  // TODO: IfThenElse()
	}

	return SIMD::Pointer(imageBase, imageSizeInBytes, ptrOffset);
}

SpirvShader::EmitResult SpirvShader::EmitImageRead(InsnIterator insn, EmitState *state) const
{
	auto &resultType = getType(Type::ID(insn.word(1)));
	auto imageId = Object::ID(insn.word(3));
	auto &image = getObject(imageId);
	auto &imageType = getType(image);

	Object::ID sampleId = 0;

	if(insn.wordCount() > 5)
	{
		int operand = 6;
		auto imageOperands = insn.word(5);
		if(imageOperands & spv::ImageOperandsSampleMask)
		{
			sampleId = insn.word(operand++);
			imageOperands &= ~spv::ImageOperandsSampleMask;
		}

		// Should be no remaining image operands.
		ASSERT(!imageOperands);
	}

	ASSERT(imageType.definition.opcode() == spv::OpTypeImage);
	auto dim = static_cast<spv::Dim>(imageType.definition.word(3));

	auto coordinate = Operand(this, state, insn.word(4));
	const DescriptorDecorations &d = descriptorDecorations.at(imageId);

	// For subpass data, format in the instruction is spv::ImageFormatUnknown. Get it from
	// the renderpass data instead. In all other cases, we can use the format in the instruction.
	auto vkFormat = (dim == spv::DimSubpassData)
	                    ? inputAttachmentFormats[d.InputAttachmentIndex]
	                    : SpirvFormatToVulkanFormat(static_cast<spv::ImageFormat>(imageType.definition.word(8)));

	// Depth+Stencil image attachments select aspect based on the Sampled Type of the
	// OpTypeImage. If float, then we want the depth aspect. If int, we want the stencil aspect.
	auto useStencilAspect = (vkFormat == VK_FORMAT_D32_SFLOAT_S8_UINT &&
	                         getType(imageType.definition.word(2)).opcode() == spv::OpTypeInt);

	if(useStencilAspect)
	{
		vkFormat = VK_FORMAT_S8_UINT;
	}

	auto pointer = state->getPointer(imageId);
	Pointer<Byte> binding = pointer.base;
	Pointer<Byte> imageBase = *Pointer<Pointer<Byte>>(binding + (useStencilAspect
	                                                                 ? OFFSET(vk::StorageImageDescriptor, stencilPtr)
	                                                                 : OFFSET(vk::StorageImageDescriptor, ptr)));

	auto imageSizeInBytes = *Pointer<Int>(binding + OFFSET(vk::StorageImageDescriptor, sizeInBytes));

	auto &dst = state->createIntermediate(insn.resultId(), resultType.componentCount);

	// "The value returned by a read of an invalid texel is undefined,
	//  unless that read operation is from a buffer resource and the robustBufferAccess feature is enabled."
	// TODO: Don't always assume a buffer resource.
	//
	// While we could be using OutOfBoundsBehavior::RobustBufferAccess for read operations from buffer resources,
	// emulating the glsl function loadImage() requires that this function returns 0 when used with out of bounds
	// coordinates, so we have to use OutOfBoundsBehavior::Nullify in that case.
	auto robustness = OutOfBoundsBehavior::Nullify;

	auto texelSize = vk::Format(vkFormat).bytes();
	auto texelPtr = GetTexelAddress(state, imageBase, imageSizeInBytes, coordinate, imageType, binding, texelSize, sampleId, useStencilAspect, robustness);

	SIMD::Int packed[4];
	// Round up texel size: for formats smaller than 32 bits per texel, we will emit a bunch
	// of (overlapping) 32b loads here, and each lane will pick out what it needs from the low bits.
	// TODO: specialize for small formats?
	for(auto i = 0; i < (texelSize + 3) / 4; i++)
	{
		packed[i] = texelPtr.Load<SIMD::Int>(robustness, state->activeLaneMask(), false, std::memory_order_relaxed, std::min(texelSize, 4));
		texelPtr += sizeof(float);
	}

	// Format support requirements here come from two sources:
	// - Minimum required set of formats for loads from storage images
	// - Any format supported as a color or depth/stencil attachment, for input attachments
	switch(vkFormat)
	{
		case VK_FORMAT_R32G32B32A32_SFLOAT:
		case VK_FORMAT_R32G32B32A32_SINT:
		case VK_FORMAT_R32G32B32A32_UINT:
			dst.move(0, packed[0]);
			dst.move(1, packed[1]);
			dst.move(2, packed[2]);
			dst.move(3, packed[3]);
			break;
		case VK_FORMAT_R32_SINT:
		case VK_FORMAT_R32_UINT:
			dst.move(0, packed[0]);
			// Fill remaining channels with 0,0,1 (of the correct type)
			dst.move(1, SIMD::Int(0));
			dst.move(2, SIMD::Int(0));
			dst.move(3, SIMD::Int(1));
			break;
		case VK_FORMAT_R32_SFLOAT:
		case VK_FORMAT_D32_SFLOAT:
		case VK_FORMAT_D32_SFLOAT_S8_UINT:
			dst.move(0, packed[0]);
			// Fill remaining channels with 0,0,1 (of the correct type)
			dst.move(1, SIMD::Float(0));
			dst.move(2, SIMD::Float(0));
			dst.move(3, SIMD::Float(1));
			break;
		case VK_FORMAT_D16_UNORM:
			dst.move(0, SIMD::Float(packed[0] & SIMD::Int(0xffff)) * SIMD::Float(1.0f / 65535.0f));
			dst.move(1, SIMD::Float(0));
			dst.move(2, SIMD::Float(0));
			dst.move(3, SIMD::Float(1));
			break;
		case VK_FORMAT_R16G16B16A16_SINT:
			dst.move(0, (packed[0] << 16) >> 16);
			dst.move(1, (packed[0]) >> 16);
			dst.move(2, (packed[1] << 16) >> 16);
			dst.move(3, (packed[1]) >> 16);
			break;
		case VK_FORMAT_R16G16B16A16_UINT:
			dst.move(0, packed[0] & SIMD::Int(0xffff));
			dst.move(1, (packed[0] >> 16) & SIMD::Int(0xffff));
			dst.move(2, packed[1] & SIMD::Int(0xffff));
			dst.move(3, (packed[1] >> 16) & SIMD::Int(0xffff));
			break;
		case VK_FORMAT_R16G16B16A16_SFLOAT:
			dst.move(0, halfToFloatBits(As<SIMD::UInt>(packed[0]) & SIMD::UInt(0x0000FFFF)));
			dst.move(1, halfToFloatBits((As<SIMD::UInt>(packed[0]) & SIMD::UInt(0xFFFF0000)) >> 16));
			dst.move(2, halfToFloatBits(As<SIMD::UInt>(packed[1]) & SIMD::UInt(0x0000FFFF)));
			dst.move(3, halfToFloatBits((As<SIMD::UInt>(packed[1]) & SIMD::UInt(0xFFFF0000)) >> 16));
			break;
		case VK_FORMAT_R8G8B8A8_SNORM:
			dst.move(0, Min(Max(SIMD::Float(((packed[0] << 24) & SIMD::Int(0xFF000000))) * SIMD::Float(1.0f / float(0x7f000000)), SIMD::Float(-1.0f)), SIMD::Float(1.0f)));
			dst.move(1, Min(Max(SIMD::Float(((packed[0] << 16) & SIMD::Int(0xFF000000))) * SIMD::Float(1.0f / float(0x7f000000)), SIMD::Float(-1.0f)), SIMD::Float(1.0f)));
			dst.move(2, Min(Max(SIMD::Float(((packed[0] << 8) & SIMD::Int(0xFF000000))) * SIMD::Float(1.0f / float(0x7f000000)), SIMD::Float(-1.0f)), SIMD::Float(1.0f)));
			dst.move(3, Min(Max(SIMD::Float(((packed[0]) & SIMD::Int(0xFF000000))) * SIMD::Float(1.0f / float(0x7f000000)), SIMD::Float(-1.0f)), SIMD::Float(1.0f)));
			break;
		case VK_FORMAT_R8G8B8A8_UNORM:
		case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
			dst.move(0, SIMD::Float((packed[0] & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			dst.move(1, SIMD::Float(((packed[0] >> 8) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			dst.move(2, SIMD::Float(((packed[0] >> 16) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			dst.move(3, SIMD::Float(((packed[0] >> 24) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			break;
		case VK_FORMAT_R8G8B8A8_SRGB:
		case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
			dst.move(0, ::sRGBtoLinear(SIMD::Float((packed[0] & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f)));
			dst.move(1, ::sRGBtoLinear(SIMD::Float(((packed[0] >> 8) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f)));
			dst.move(2, ::sRGBtoLinear(SIMD::Float(((packed[0] >> 16) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f)));
			dst.move(3, SIMD::Float(((packed[0] >> 24) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			break;
		case VK_FORMAT_B8G8R8A8_UNORM:
			dst.move(0, SIMD::Float(((packed[0] >> 16) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			dst.move(1, SIMD::Float(((packed[0] >> 8) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			dst.move(2, SIMD::Float((packed[0] & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			dst.move(3, SIMD::Float(((packed[0] >> 24) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			break;
		case VK_FORMAT_B8G8R8A8_SRGB:
			dst.move(0, ::sRGBtoLinear(SIMD::Float(((packed[0] >> 16) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f)));
			dst.move(1, ::sRGBtoLinear(SIMD::Float(((packed[0] >> 8) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f)));
			dst.move(2, ::sRGBtoLinear(SIMD::Float((packed[0] & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f)));
			dst.move(3, SIMD::Float(((packed[0] >> 24) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			break;
		case VK_FORMAT_R8G8B8A8_UINT:
		case VK_FORMAT_A8B8G8R8_UINT_PACK32:
			dst.move(0, (As<SIMD::UInt>(packed[0]) & SIMD::UInt(0xFF)));
			dst.move(1, ((As<SIMD::UInt>(packed[0]) >> 8) & SIMD::UInt(0xFF)));
			dst.move(2, ((As<SIMD::UInt>(packed[0]) >> 16) & SIMD::UInt(0xFF)));
			dst.move(3, ((As<SIMD::UInt>(packed[0]) >> 24) & SIMD::UInt(0xFF)));
			break;
		case VK_FORMAT_R8G8B8A8_SINT:
		case VK_FORMAT_A8B8G8R8_SINT_PACK32:
			dst.move(0, (packed[0] << 24) >> 24);
			dst.move(1, (packed[0] << 16) >> 24);
			dst.move(2, (packed[0] << 8) >> 24);
			dst.move(3, (packed[0]) >> 24);
			break;
		case VK_FORMAT_R8_UNORM:
			dst.move(0, SIMD::Float((packed[0] & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			dst.move(1, SIMD::Float(0));
			dst.move(2, SIMD::Float(0));
			dst.move(3, SIMD::Float(1));
			break;
		case VK_FORMAT_R8_UINT:
		case VK_FORMAT_S8_UINT:
			dst.move(0, (As<SIMD::UInt>(packed[0]) & SIMD::UInt(0xFF)));
			dst.move(1, SIMD::UInt(0));
			dst.move(2, SIMD::UInt(0));
			dst.move(3, SIMD::UInt(1));
			break;
		case VK_FORMAT_R8_SINT:
			dst.move(0, (packed[0] << 24) >> 24);
			dst.move(1, SIMD::Int(0));
			dst.move(2, SIMD::Int(0));
			dst.move(3, SIMD::Int(1));
			break;
		case VK_FORMAT_R8G8_UNORM:
			dst.move(0, SIMD::Float((packed[0] & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			dst.move(1, SIMD::Float(((packed[0] >> 8) & SIMD::Int(0xFF))) * SIMD::Float(1.0f / 255.f));
			dst.move(2, SIMD::Float(0));
			dst.move(3, SIMD::Float(1));
			break;
		case VK_FORMAT_R8G8_UINT:
			dst.move(0, (As<SIMD::UInt>(packed[0]) & SIMD::UInt(0xFF)));
			dst.move(1, ((As<SIMD::UInt>(packed[0]) >> 8) & SIMD::UInt(0xFF)));
			dst.move(2, SIMD::UInt(0));
			dst.move(3, SIMD::UInt(1));
			break;
		case VK_FORMAT_R8G8_SINT:
			dst.move(0, (packed[0] << 24) >> 24);
			dst.move(1, (packed[0] << 16) >> 24);
			dst.move(2, SIMD::Int(0));
			dst.move(3, SIMD::Int(1));
			break;
		case VK_FORMAT_R16_SFLOAT:
			dst.move(0, halfToFloatBits(As<SIMD::UInt>(packed[0]) & SIMD::UInt(0x0000FFFF)));
			dst.move(1, SIMD::Float(0));
			dst.move(2, SIMD::Float(0));
			dst.move(3, SIMD::Float(1));
			break;
		case VK_FORMAT_R16_UINT:
			dst.move(0, packed[0] & SIMD::Int(0xffff));
			dst.move(1, SIMD::UInt(0));
			dst.move(2, SIMD::UInt(0));
			dst.move(3, SIMD::UInt(1));
			break;
		case VK_FORMAT_R16_SINT:
			dst.move(0, (packed[0] << 16) >> 16);
			dst.move(1, SIMD::Int(0));
			dst.move(2, SIMD::Int(0));
			dst.move(3, SIMD::Int(1));
			break;
		case VK_FORMAT_R16G16_SFLOAT:
			dst.move(0, halfToFloatBits(As<SIMD::UInt>(packed[0]) & SIMD::UInt(0x0000FFFF)));
			dst.move(1, halfToFloatBits((As<SIMD::UInt>(packed[0]) & SIMD::UInt(0xFFFF0000)) >> 16));
			dst.move(2, SIMD::Float(0));
			dst.move(3, SIMD::Float(1));
			break;
		case VK_FORMAT_R16G16_UINT:
			dst.move(0, packed[0] & SIMD::Int(0xffff));
			dst.move(1, (packed[0] >> 16) & SIMD::Int(0xffff));
			dst.move(2, SIMD::UInt(0));
			dst.move(3, SIMD::UInt(1));
			break;
		case VK_FORMAT_R16G16_SINT:
			dst.move(0, (packed[0] << 16) >> 16);
			dst.move(1, (packed[0]) >> 16);
			dst.move(2, SIMD::Int(0));
			dst.move(3, SIMD::Int(1));
			break;
		case VK_FORMAT_R32G32_SINT:
		case VK_FORMAT_R32G32_UINT:
			dst.move(0, packed[0]);
			dst.move(1, packed[1]);
			dst.move(2, SIMD::Int(0));
			dst.move(3, SIMD::Int(1));
			break;
		case VK_FORMAT_R32G32_SFLOAT:
			dst.move(0, packed[0]);
			dst.move(1, packed[1]);
			dst.move(2, SIMD::Float(0));
			dst.move(3, SIMD::Float(1));
			break;
		case VK_FORMAT_A2B10G10R10_UINT_PACK32:
			dst.move(0, (packed[0]) & SIMD::Int(0x3FF));
			dst.move(1, (packed[0] >> 10) & SIMD::Int(0x3FF));
			dst.move(2, (packed[0] >> 20) & SIMD::Int(0x3FF));
			dst.move(3, (packed[0] >> 30) & SIMD::Int(0x3));
			break;
		case VK_FORMAT_A2R10G10B10_UINT_PACK32:
			dst.move(2, (packed[0]) & SIMD::Int(0x3FF));
			dst.move(1, (packed[0] >> 10) & SIMD::Int(0x3FF));
			dst.move(0, (packed[0] >> 20) & SIMD::Int(0x3FF));
			dst.move(3, (packed[0] >> 30) & SIMD::Int(0x3));
			break;
		case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
			dst.move(0, SIMD::Float((packed[0]) & SIMD::Int(0x3FF)) * SIMD::Float(1.0f / 0x3FF));
			dst.move(1, SIMD::Float((packed[0] >> 10) & SIMD::Int(0x3FF)) * SIMD::Float(1.0f / 0x3FF));
			dst.move(2, SIMD::Float((packed[0] >> 20) & SIMD::Int(0x3FF)) * SIMD::Float(1.0f / 0x3FF));
			dst.move(3, SIMD::Float((packed[0] >> 30) & SIMD::Int(0x3)) * SIMD::Float(1.0f / 0x3));
			break;
		case VK_FORMAT_A2R10G10B10_UNORM_PACK32:
			dst.move(2, SIMD::Float((packed[0]) & SIMD::Int(0x3FF)) * SIMD::Float(1.0f / 0x3FF));
			dst.move(1, SIMD::Float((packed[0] >> 10) & SIMD::Int(0x3FF)) * SIMD::Float(1.0f / 0x3FF));
			dst.move(0, SIMD::Float((packed[0] >> 20) & SIMD::Int(0x3FF)) * SIMD::Float(1.0f / 0x3FF));
			dst.move(3, SIMD::Float((packed[0] >> 30) & SIMD::Int(0x3)) * SIMD::Float(1.0f / 0x3));
			break;
		case VK_FORMAT_R5G6B5_UNORM_PACK16:
			dst.move(0, SIMD::Float((packed[0] >> 11) & SIMD::Int(0x1F)) * SIMD::Float(1.0f / 0x1F));
			dst.move(1, SIMD::Float((packed[0] >> 5) & SIMD::Int(0x3F)) * SIMD::Float(1.0f / 0x3F));
			dst.move(2, SIMD::Float((packed[0]) & SIMD::Int(0x1F)) * SIMD::Float(1.0f / 0x1F));
			dst.move(3, SIMD::Float(1));
			break;
		case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
			dst.move(0, SIMD::Float((packed[0] >> 10) & SIMD::Int(0x1F)) * SIMD::Float(1.0f / 0x1F));
			dst.move(1, SIMD::Float((packed[0] >> 5) & SIMD::Int(0x1F)) * SIMD::Float(1.0f / 0x1F));
			dst.move(2, SIMD::Float((packed[0]) & SIMD::Int(0x1F)) * SIMD::Float(1.0f / 0x1F));
			dst.move(3, SIMD::Float((packed[0] >> 15) & SIMD::Int(0x1)));
			break;
		default:
			UNSUPPORTED("VkFormat %d", int(vkFormat));
			break;
	}

	return EmitResult::Continue;
}

SpirvShader::EmitResult SpirvShader::EmitImageWrite(InsnIterator insn, EmitState *state) const
{
	auto imageId = Object::ID(insn.word(1));
	auto &image = getObject(imageId);
	auto &imageType = getType(image);

	ASSERT(imageType.definition.opcode() == spv::OpTypeImage);

	// TODO(b/131171141): Not handling any image operands yet.
	ASSERT(insn.wordCount() == 4);

	auto coordinate = Operand(this, state, insn.word(2));
	auto texel = Operand(this, state, insn.word(3));

	Pointer<Byte> binding = state->getPointer(imageId).base;
	Pointer<Byte> imageBase = *Pointer<Pointer<Byte>>(binding + OFFSET(vk::StorageImageDescriptor, ptr));
	auto imageSizeInBytes = *Pointer<Int>(binding + OFFSET(vk::StorageImageDescriptor, sizeInBytes));

	SIMD::Int packed[4];
	auto numPackedElements = 0u;
	int texelSize = 0;
	auto format = static_cast<spv::ImageFormat>(imageType.definition.word(8));
	switch(format)
	{
		case spv::ImageFormatRgba32f:
		case spv::ImageFormatRgba32i:
		case spv::ImageFormatRgba32ui:
			texelSize = 16;
			packed[0] = texel.Int(0);
			packed[1] = texel.Int(1);
			packed[2] = texel.Int(2);
			packed[3] = texel.Int(3);
			numPackedElements = 4;
			break;
		case spv::ImageFormatR32f:
		case spv::ImageFormatR32i:
		case spv::ImageFormatR32ui:
			texelSize = 4;
			packed[0] = texel.Int(0);
			numPackedElements = 1;
			break;
		case spv::ImageFormatRgba8:
			texelSize = 4;
			packed[0] = (SIMD::UInt(Round(Min(Max(texel.Float(0), SIMD::Float(0.0f)), SIMD::Float(1.0f)) * SIMD::Float(255.0f)))) |
			            ((SIMD::UInt(Round(Min(Max(texel.Float(1), SIMD::Float(0.0f)), SIMD::Float(1.0f)) * SIMD::Float(255.0f)))) << 8) |
			            ((SIMD::UInt(Round(Min(Max(texel.Float(2), SIMD::Float(0.0f)), SIMD::Float(1.0f)) * SIMD::Float(255.0f)))) << 16) |
			            ((SIMD::UInt(Round(Min(Max(texel.Float(3), SIMD::Float(0.0f)), SIMD::Float(1.0f)) * SIMD::Float(255.0f)))) << 24);
			numPackedElements = 1;
			break;
		case spv::ImageFormatRgba8Snorm:
			texelSize = 4;
			packed[0] = (SIMD::Int(Round(Min(Max(texel.Float(0), SIMD::Float(-1.0f)), SIMD::Float(1.0f)) * SIMD::Float(127.0f))) &
			             SIMD::Int(0xFF)) |
			            ((SIMD::Int(Round(Min(Max(texel.Float(1), SIMD::Float(-1.0f)), SIMD::Float(1.0f)) * SIMD::Float(127.0f))) &
			              SIMD::Int(0xFF))
			             << 8) |
			            ((SIMD::Int(Round(Min(Max(texel.Float(2), SIMD::Float(-1.0f)), SIMD::Float(1.0f)) * SIMD::Float(127.0f))) &
			              SIMD::Int(0xFF))
			             << 16) |
			            ((SIMD::Int(Round(Min(Max(texel.Float(3), SIMD::Float(-1.0f)), SIMD::Float(1.0f)) * SIMD::Float(127.0f))) &
			              SIMD::Int(0xFF))
			             << 24);
			numPackedElements = 1;
			break;
		case spv::ImageFormatRgba8i:
		case spv::ImageFormatRgba8ui:
			texelSize = 4;
			packed[0] = (SIMD::UInt(texel.UInt(0) & SIMD::UInt(0xff))) |
			            (SIMD::UInt(texel.UInt(1) & SIMD::UInt(0xff)) << 8) |
			            (SIMD::UInt(texel.UInt(2) & SIMD::UInt(0xff)) << 16) |
			            (SIMD::UInt(texel.UInt(3) & SIMD::UInt(0xff)) << 24);
			numPackedElements = 1;
			break;
		case spv::ImageFormatRgba16f:
			texelSize = 8;
			packed[0] = floatToHalfBits(texel.UInt(0), false) | floatToHalfBits(texel.UInt(1), true);
			packed[1] = floatToHalfBits(texel.UInt(2), false) | floatToHalfBits(texel.UInt(3), true);
			numPackedElements = 2;
			break;
		case spv::ImageFormatRgba16i:
		case spv::ImageFormatRgba16ui:
			texelSize = 8;
			packed[0] = SIMD::UInt(texel.UInt(0) & SIMD::UInt(0xffff)) | (SIMD::UInt(texel.UInt(1) & SIMD::UInt(0xffff)) << 16);
			packed[1] = SIMD::UInt(texel.UInt(2) & SIMD::UInt(0xffff)) | (SIMD::UInt(texel.UInt(3) & SIMD::UInt(0xffff)) << 16);
			numPackedElements = 2;
			break;
		case spv::ImageFormatRg32f:
		case spv::ImageFormatRg32i:
		case spv::ImageFormatRg32ui:
			texelSize = 8;
			packed[0] = texel.Int(0);
			packed[1] = texel.Int(1);
			numPackedElements = 2;
			break;
		case spv::ImageFormatRg16f:
			texelSize = 4;
			packed[0] = floatToHalfBits(texel.UInt(0), false) | floatToHalfBits(texel.UInt(1), true);
			numPackedElements = 1;
			break;
		case spv::ImageFormatRg16i:
		case spv::ImageFormatRg16ui:
			texelSize = 4;
			packed[0] = SIMD::UInt(texel.UInt(0) & SIMD::UInt(0xffff)) | (SIMD::UInt(texel.UInt(1) & SIMD::UInt(0xffff)) << 16);
			numPackedElements = 1;
			break;

		case spv::ImageFormatR11fG11fB10f:
		case spv::ImageFormatR16f:
		case spv::ImageFormatRgba16:
		case spv::ImageFormatRgb10A2:
		case spv::ImageFormatRg16:
		case spv::ImageFormatRg8:
		case spv::ImageFormatR16:
		case spv::ImageFormatR8:
		case spv::ImageFormatRgba16Snorm:
		case spv::ImageFormatRg16Snorm:
		case spv::ImageFormatRg8Snorm:
		case spv::ImageFormatR16Snorm:
		case spv::ImageFormatR8Snorm:
		case spv::ImageFormatRg8i:
		case spv::ImageFormatR16i:
		case spv::ImageFormatR8i:
		case spv::ImageFormatRgb10a2ui:
		case spv::ImageFormatRg8ui:
		case spv::ImageFormatR16ui:
		case spv::ImageFormatR8ui:
			UNSUPPORTED("spv::ImageFormat %d", int(format));
			break;

		default:
			UNREACHABLE("spv::ImageFormat %d", int(format));
			break;
	}

	// SPIR-V 1.4: "If the coordinates are outside the image, the memory location that is accessed is undefined."

	// Emulating the glsl function imageStore() requires that this function is noop when used with out of bounds
	// coordinates, so we have to use OutOfBoundsBehavior::Nullify in that case.
	auto robustness = OutOfBoundsBehavior::Nullify;

	auto texelPtr = GetTexelAddress(state, imageBase, imageSizeInBytes, coordinate, imageType, binding, texelSize, 0, false, robustness);

	for(auto i = 0u; i < numPackedElements; i++)
	{
		texelPtr.Store(packed[i], robustness, state->activeLaneMask());
		texelPtr += sizeof(float);
	}

	return EmitResult::Continue;
}

SpirvShader::EmitResult SpirvShader::EmitImageTexelPointer(InsnIterator insn, EmitState *state) const
{
	auto &resultType = getType(Type::ID(insn.word(1)));
	auto imageId = Object::ID(insn.word(3));
	auto &image = getObject(imageId);
	// Note: OpImageTexelPointer is unusual in that the image is passed by pointer.
	// Look through to get the actual image type.
	auto &imageType = getType(getType(image).element);
	Object::ID resultId = insn.word(2);

	ASSERT(imageType.opcode() == spv::OpTypeImage);
	ASSERT(resultType.storageClass == spv::StorageClassImage);
	ASSERT(getType(resultType.element).opcode() == spv::OpTypeInt);

	auto coordinate = Operand(this, state, insn.word(4));

	Pointer<Byte> binding = state->getPointer(imageId).base;
	Pointer<Byte> imageBase = *Pointer<Pointer<Byte>>(binding + OFFSET(vk::StorageImageDescriptor, ptr));
	auto imageSizeInBytes = *Pointer<Int>(binding + OFFSET(vk::StorageImageDescriptor, sizeInBytes));

	auto ptr = GetTexelAddress(state, imageBase, imageSizeInBytes, coordinate, imageType, binding, sizeof(uint32_t), 0, false, OutOfBoundsBehavior::UndefinedValue);

	state->createPointer(resultId, ptr);

	return EmitResult::Continue;
}

SpirvShader::EmitResult SpirvShader::EmitSampledImageCombineOrSplit(InsnIterator insn, EmitState *state) const
{
	// Propagate the image pointer in both cases.
	// Consumers of OpSampledImage will look through to find the sampler pointer.

	Object::ID resultId = insn.word(2);
	Object::ID imageId = insn.word(3);

	state->createPointer(resultId, state->getPointer(imageId));

	return EmitResult::Continue;
}

}  // namespace sw