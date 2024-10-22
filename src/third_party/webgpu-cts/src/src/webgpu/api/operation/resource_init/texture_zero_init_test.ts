import { TextureUsage } from '../../../../common/constants.js';
import { TestCaseRecorder } from '../../../../common/framework/logging/test_case_recorder.js';
import { params, poptions, pbool } from '../../../../common/framework/params_builder.js';
import { CaseParams } from '../../../../common/framework/params_utils.js';
import { assert, unreachable } from '../../../../common/framework/util/util.js';
import { kTextureAspects, kTextureFormatInfo, kTextureFormats } from '../../../capability_info.js';
import { GPUTest } from '../../../gpu_test.js';
import { createTextureUploadBuffer } from '../../../util/texture/layout.js';
import { BeginEndRange, SubresourceRange } from '../../../util/texture/subresource.js';
import { PerTexelComponent, getTexelDataRepresentation } from '../../../util/texture/texelData.js';

enum UninitializeMethod {
  Creation = 'Creation', // The texture was just created. It is uninitialized.
  StoreOpClear = 'StoreOpClear', // The texture was rendered to with GPUStoreOp "clear"
}
const kUninitializeMethods = Object.keys(UninitializeMethod) as UninitializeMethod[];

export enum ReadMethod {
  Sample = 'Sample', // The texture is sampled from
  CopyToBuffer = 'CopyToBuffer', // The texture is copied to a buffer
  CopyToTexture = 'CopyToTexture', // The texture is copied to another texture
  DepthTest = 'DepthTest', // The texture is read as a depth buffer
  StencilTest = 'StencilTest', // The texture is read as a stencil buffer
  ColorBlending = 'ColorBlending', // Read the texture by blending as a color attachment
  Storage = 'Storage', // Read the texture as a storage texture
}

// Test with these mip level counts
type MipLevels = 1 | 5;
const kMipLevelCounts: MipLevels[] = [1, 5];

// For each mip level count, define the mip ranges to leave uninitialized.
const kUninitializedMipRangesToTest: { [k in MipLevels]: BeginEndRange[] } = {
  1: [{ begin: 0, end: 1 }], // Test the only mip
  5: [
    { begin: 0, end: 2 },
    { begin: 3, end: 4 },
  ], // Test a range and a single mip
};

// Test with these sample counts.
type SampleCounts = 1 | 4;
const kSampleCounts: SampleCounts[] = [1, 4];

// Test with these slice counts. This means the depth of a 3d texture or the number
// or layers in a 2D or a 1D texture array.
type SliceCounts = 1 | 7;

// For each slice count, define the slices to leave uninitialized.
const kUninitializedSliceRangesToTest: { [k in SliceCounts]: BeginEndRange[] } = {
  1: [{ begin: 0, end: 1 }], // Test the only slice
  7: [
    { begin: 2, end: 4 },
    { begin: 6, end: 7 },
  ], // Test a range and a single slice
};

// Test with these combinations of texture dimension and sliceCount.
const kCreationSizes: Array<{
  dimension: GPUTextureDimension;
  sliceCount: SliceCounts;
}> = [
  // { dimension: '1d', sliceCount: 7 }, // TODO: 1d textures
  { dimension: '2d', sliceCount: 1 }, // 2d textures
  { dimension: '2d', sliceCount: 7 }, // 2d array textures
  // { dimension: '3d', sliceCount: 7 }, // TODO: 3d textures
];

// Enums to abstract over color / depth / stencil values in textures. Depending on the texture format,
// the data for each value may have a different representation. These enums are converted to a
// representation such that their values can be compared. ex.) An integer is needed to upload to an
// unsigned normalized format, but its value is read as a float in the shader.
export const enum InitializedState {
  Canary, // Set on initialized subresources. It should stay the same. On discarded resources, we should observe zero.
  Zero, // We check that uninitialized subresources are in this state when read back.
}

export function initializedStateAsFloat(state: InitializedState): number {
  switch (state) {
    case InitializedState.Zero:
      return 0;
    case InitializedState.Canary:
      return 1;
    default:
      unreachable();
  }
}

export function initializedStateAsUint(state: InitializedState): number {
  switch (state) {
    case InitializedState.Zero:
      return 0;
    case InitializedState.Canary:
      return 255;
    default:
      unreachable();
  }
}

export function initializedStateAsSint(state: InitializedState): number {
  switch (state) {
    case InitializedState.Zero:
      return 0;
    case InitializedState.Canary:
      return -1;
    default:
      unreachable();
  }
}

export function initializedStateAsColor(
  state: InitializedState,
  format: GPUTextureFormat
): [number, number, number, number] {
  let value;
  if (format.indexOf('uint') !== -1) {
    value = initializedStateAsUint(state);
  } else if (format.indexOf('sint') !== -1) {
    value = initializedStateAsSint(state);
  } else {
    value = initializedStateAsFloat(state);
  }
  return [value, value, value, value];
}

export function initializedStateAsDepth(state: InitializedState): number {
  switch (state) {
    case InitializedState.Zero:
      return 0;
    case InitializedState.Canary:
      return 1;
    default:
      unreachable();
  }
}

export function initializedStateAsStencil(state: InitializedState): number {
  switch (state) {
    case InitializedState.Zero:
      return 0;
    case InitializedState.Canary:
      return 42;
    default:
      unreachable();
  }
}

interface TestParams {
  format: GPUTextureFormat;
  aspect: GPUTextureAspect;
  dimension: GPUTextureDimension;
  sliceCount: SliceCounts;
  mipLevelCount: MipLevels;
  sampleCount: SampleCounts;
  uninitializeMethod: UninitializeMethod;
  readMethod: ReadMethod;
  nonPowerOfTwo: boolean;
}

function getRequiredTextureUsage(
  format: GPUTextureFormat,
  sampleCount: SampleCounts,
  uninitializeMethod: UninitializeMethod,
  readMethod: ReadMethod
): GPUTextureUsageFlags {
  let usage: GPUTextureUsageFlags = TextureUsage.CopyDst;

  switch (uninitializeMethod) {
    case UninitializeMethod.Creation:
      break;
    case UninitializeMethod.StoreOpClear:
      usage |= TextureUsage.OutputAttachment;
      break;
    default:
      unreachable();
  }

  switch (readMethod) {
    case ReadMethod.CopyToBuffer:
    case ReadMethod.CopyToTexture:
      usage |= TextureUsage.CopySrc;
      break;
    case ReadMethod.Sample:
      usage |= TextureUsage.Sampled;
      break;
    case ReadMethod.Storage:
      usage |= TextureUsage.Storage;
      break;
    case ReadMethod.DepthTest:
    case ReadMethod.StencilTest:
    case ReadMethod.ColorBlending:
      usage |= TextureUsage.OutputAttachment;
      break;
    default:
      unreachable();
  }

  if (sampleCount > 1) {
    // Copies to multisampled textures are not allowed. We need OutputAttachment to initialize
    // canary data in multisampled textures.
    usage |= TextureUsage.OutputAttachment;
  }

  if (!kTextureFormatInfo[format].copyable) {
    // Copies are not possible. We need OutputAttachment to initialize
    // canary data.
    assert(kTextureFormatInfo[format].renderable);
    usage |= TextureUsage.OutputAttachment;
  }

  return usage;
}

export abstract class TextureZeroInitTest extends GPUTest {
  protected stateToTexelComponents: { [k in InitializedState]: PerTexelComponent<number> };

  constructor(rec: TestCaseRecorder, params: CaseParams) {
    super(rec, params);

    const stateToTexelComponents = (state: InitializedState) => {
      const [R, G, B, A] = initializedStateAsColor(state, this.params.format);
      return {
        R,
        G,
        B,
        A,
        Depth: initializedStateAsDepth(state),
        Stencil: initializedStateAsStencil(state),
      };
    };

    this.stateToTexelComponents = {
      [InitializedState.Zero]: stateToTexelComponents(InitializedState.Zero),
      [InitializedState.Canary]: stateToTexelComponents(InitializedState.Canary),
    };
  }

  get params(): TestParams {
    return super.params as TestParams;
  }

  get textureWidth(): number {
    let width = 1 << this.params.mipLevelCount;
    if (this.params.nonPowerOfTwo) {
      width = 2 * width - 1;
    }
    return width;
  }

  get textureHeight(): number {
    let height = 1 << this.params.mipLevelCount;
    if (this.params.nonPowerOfTwo) {
      height = 2 * height - 1;
    }
    return height;
  }

  // Used to iterate subresources and check that their uninitialized contents are zero when accessed
  *iterateUninitializedSubresources(): Generator<SubresourceRange> {
    for (const mipRange of kUninitializedMipRangesToTest[this.params.mipLevelCount]) {
      for (const sliceRange of kUninitializedSliceRangesToTest[this.params.sliceCount]) {
        yield new SubresourceRange({ mipRange, sliceRange });
      }
    }
  }

  // Used to iterate and initialize other subresources not checked for zero-initialization.
  // Zero-initialization of uninitialized subresources should not have side effects on already
  // initialized subresources.
  *iterateInitializedSubresources(): Generator<SubresourceRange> {
    const uninitialized: boolean[][] = new Array(this.params.mipLevelCount);
    for (let level = 0; level < uninitialized.length; ++level) {
      uninitialized[level] = new Array(this.params.sliceCount);
    }
    for (const subresources of this.iterateUninitializedSubresources()) {
      for (const { level, slice } of subresources.each()) {
        uninitialized[level][slice] = true;
      }
    }
    for (let level = 0; level < uninitialized.length; ++level) {
      for (let slice = 0; slice < uninitialized[level].length; ++slice) {
        if (!uninitialized[level][slice]) {
          yield new SubresourceRange({
            mipRange: { begin: level, count: 1 },
            sliceRange: { begin: slice, count: 1 },
          });
        }
      }
    }
  }

  *generateTextureViewDescriptorsForRendering(
    aspect: GPUTextureAspect,
    subresourceRange?: SubresourceRange
  ): Generator<GPUTextureViewDescriptor> {
    const viewDescriptor: GPUTextureViewDescriptor = {
      dimension: '2d',
      aspect,
    };

    if (subresourceRange === undefined) {
      return viewDescriptor;
    }

    for (const { level, slice } of subresourceRange.each()) {
      yield {
        ...viewDescriptor,
        baseMipLevel: level,
        mipLevelCount: 1,
        baseArrayLayer: slice,
        arrayLayerCount: 1,
      };
    }
  }

  abstract checkContents(
    texture: GPUTexture,
    state: InitializedState,
    subresourceRange: SubresourceRange
  ): void;

  private initializeWithStoreOp(
    state: InitializedState,
    texture: GPUTexture,
    subresourceRange?: SubresourceRange
  ): void {
    const commandEncoder = this.device.createCommandEncoder();
    for (const viewDescriptor of this.generateTextureViewDescriptorsForRendering(
      this.params.aspect,
      subresourceRange
    )) {
      if (kTextureFormatInfo[this.params.format].color) {
        commandEncoder
          .beginRenderPass({
            colorAttachments: [
              {
                attachment: texture.createView(viewDescriptor),
                storeOp: 'store',
                loadValue: initializedStateAsColor(state, this.params.format),
              },
            ],
          })
          .endPass();
      } else {
        commandEncoder
          .beginRenderPass({
            colorAttachments: [],
            depthStencilAttachment: {
              attachment: texture.createView(viewDescriptor),
              depthStoreOp: 'store',
              depthLoadValue: initializedStateAsDepth(state),
              stencilStoreOp: 'store',
              stencilLoadValue: initializedStateAsStencil(state),
            },
          })
          .endPass();
      }
    }
    this.queue.submit([commandEncoder.finish()]);
  }

  private initializeWithCopy(
    texture: GPUTexture,
    state: InitializedState,
    subresourceRange: SubresourceRange
  ): void {
    if (this.params.dimension === '1d' || this.params.dimension === '3d') {
      // TODO: https://github.com/gpuweb/gpuweb/issues/69
      // Copies with 1D and 3D textures are not yet specified
      unreachable();
    }

    const firstSubresource = subresourceRange.each().next().value;
    assert(typeof firstSubresource !== 'undefined');

    const largestWidth = this.textureWidth >> firstSubresource.level;
    const largestHeight = this.textureHeight >> firstSubresource.level;

    const texelData = new Uint8Array(
      getTexelDataRepresentation(this.params.format).getBytes(this.stateToTexelComponents[state])
    );
    const { buffer, bytesPerRow, rowsPerImage } = createTextureUploadBuffer(
      texelData,
      this.device,
      this.params.format,
      this.params.dimension,
      [largestWidth, largestHeight, 1]
    );

    const commandEncoder = this.device.createCommandEncoder();

    for (const { level, slice } of subresourceRange.each()) {
      const width = this.textureWidth >> level;
      const height = this.textureHeight >> level;

      commandEncoder.copyBufferToTexture(
        {
          buffer,
          bytesPerRow,
          rowsPerImage,
        },
        { texture, mipLevel: level, arrayLayer: slice },
        { width, height, depth: 1 }
      );
    }
    this.queue.submit([commandEncoder.finish()]);
    buffer.destroy();
  }

  initializeTexture(
    texture: GPUTexture,
    state: InitializedState,
    subresourceRange: SubresourceRange
  ): void {
    if (this.params.sampleCount > 1 || !kTextureFormatInfo[this.params.format].copyable) {
      // Copies to multisampled textures not yet specified.
      // Use a storeOp for now.
      assert(kTextureFormatInfo[this.params.format].renderable);
      this.initializeWithStoreOp(state, texture, subresourceRange);
    } else {
      this.initializeWithCopy(texture, state, subresourceRange);
    }
  }

  discardTexture(texture: GPUTexture, subresourceRange: SubresourceRange): void {
    const commandEncoder = this.device.createCommandEncoder();

    for (const desc of this.generateTextureViewDescriptorsForRendering(
      this.params.aspect,
      subresourceRange
    )) {
      if (kTextureFormatInfo[this.params.format].color) {
        commandEncoder
          .beginRenderPass({
            colorAttachments: [
              {
                attachment: texture.createView(desc),
                storeOp: 'clear',
                loadValue: 'load',
              },
            ],
          })
          .endPass();
      } else {
        commandEncoder
          .beginRenderPass({
            colorAttachments: [],
            depthStencilAttachment: {
              attachment: texture.createView(desc),
              depthStoreOp: 'clear',
              depthLoadValue: 'load',
              stencilStoreOp: 'clear',
              stencilLoadValue: 'load',
            },
          })
          .endPass();
      }
    }
    this.queue.submit([commandEncoder.finish()]);
  }

  static generateParams(readMethods: ReadMethod[]) {
    return (
      // TODO: Consider making a list of "valid" texture descriptors in capability_info.
      params()
        .combine(poptions('format', kTextureFormats))
        .combine(poptions('aspect', kTextureAspects))
        .unless(
          ({ format, aspect }) =>
            (aspect === 'depth-only' && !kTextureFormatInfo[format].depth) ||
            (aspect === 'stencil-only' && !kTextureFormatInfo[format].stencil)
        )
        .combine(poptions('mipLevelCount', kMipLevelCounts))
        .combine(poptions('sampleCount', kSampleCounts))
        // Multisampled textures may only have one mip
        .unless(({ sampleCount, mipLevelCount }) => sampleCount > 1 && mipLevelCount > 1)
        .combine(poptions('uninitializeMethod', kUninitializeMethods))
        .combine(poptions('readMethod', readMethods))
        .unless(
          ({ readMethod, format }) =>
            // It doesn't make sense to copy from a packed depth format.
            // This is not specified yet, but it will probably be disallowed as the bits may
            // be vendor-specific.
            // TODO: Test copying out of the stencil aspect.
            (readMethod === ReadMethod.CopyToBuffer || readMethod === ReadMethod.CopyToTexture) &&
            (format === 'depth24plus' || format === 'depth24plus-stencil8')
        )
        .unless(
          ({ readMethod, format }) =>
            (readMethod === ReadMethod.DepthTest && !kTextureFormatInfo[format].depth) ||
            (readMethod === ReadMethod.StencilTest && !kTextureFormatInfo[format].stencil) ||
            (readMethod === ReadMethod.ColorBlending && !kTextureFormatInfo[format].color) ||
            // TODO: Test with depth sampling
            (readMethod === ReadMethod.Sample && kTextureFormatInfo[format].depth)
        )
        .unless(
          ({ readMethod, sampleCount }) =>
            // We can only read from multisampled textures by sampling.
            sampleCount > 1 &&
            (readMethod === ReadMethod.CopyToBuffer || readMethod === ReadMethod.CopyToTexture)
        )
        .combine(kCreationSizes)
        // Multisampled 3D / 2D array textures not supported.
        .unless(({ sampleCount, sliceCount }) => sampleCount > 1 && sliceCount > 1)
        .filter(({ format, sampleCount, uninitializeMethod, readMethod }) => {
          const usage = getRequiredTextureUsage(
            format,
            sampleCount,
            uninitializeMethod,
            readMethod
          );

          if (usage & TextureUsage.OutputAttachment && !kTextureFormatInfo[format].renderable) {
            return false;
          }

          if (usage & TextureUsage.Storage && !kTextureFormatInfo[format].storage) {
            return false;
          }

          return true;
        })
        .combine(pbool('nonPowerOfTwo'))
    );
  }

  run(): void {
    const {
      format,
      dimension,
      mipLevelCount,
      sliceCount,
      sampleCount,
      uninitializeMethod,
      readMethod,
    } = this.params;

    const usage = getRequiredTextureUsage(format, sampleCount, uninitializeMethod, readMethod);

    const texture = this.device.createTexture({
      size: [this.textureWidth, this.textureHeight, sliceCount],
      format,
      dimension,
      usage,
      mipLevelCount,
      sampleCount,
    });

    // Initialize some subresources with canary values
    for (const subresourceRange of this.iterateInitializedSubresources()) {
      this.initializeTexture(texture, InitializedState.Canary, subresourceRange);
    }

    switch (uninitializeMethod) {
      case UninitializeMethod.Creation:
        break;
      case UninitializeMethod.StoreOpClear:
        // Initialize the rest of the resources.
        for (const subresourceRange of this.iterateUninitializedSubresources()) {
          this.initializeTexture(texture, InitializedState.Canary, subresourceRange);
        }
        // Then use a store op to discard their contents.
        for (const subresourceRange of this.iterateUninitializedSubresources()) {
          this.discardTexture(texture, subresourceRange);
        }
        break;
      default:
        unreachable();
    }

    // Check that all uninitialized resources are zero.
    for (const subresourceRange of this.iterateUninitializedSubresources()) {
      this.checkContents(texture, InitializedState.Zero, subresourceRange);
    }

    // Check the all other resources are unchanged.
    for (const subresourceRange of this.iterateInitializedSubresources()) {
      this.checkContents(texture, InitializedState.Canary, subresourceRange);
    }
  }
}
