// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_bundle_encoder_descriptor.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_object_descriptor_base.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8GPURenderBundleEncoderDescriptorKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "colorFormats",
    "depthStencilFormat",
    "sampleCount",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8GPURenderBundleEncoderDescriptor::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, GPURenderBundleEncoderDescriptor* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): colorFormats.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  V8GPUObjectDescriptorBase::ToImpl(isolate, v8_value, impl, exception_state);
  if (exception_state.HadException())
    return;

  const auto* keys = eternalV8GPURenderBundleEncoderDescriptorKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> color_formats_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&color_formats_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (color_formats_value.IsEmpty() || color_formats_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member colorFormats is undefined.");
    return;
  } else {
    Vector<String> color_formats_cpp_value = NativeValueTraits<IDLSequence<IDLString>>::NativeValue(isolate, color_formats_value, exception_state);
    if (exception_state.HadException())
      return;
    const char* const kValidValues[] = {
        "r8unorm",
        "r8snorm",
        "r8uint",
        "r8sint",
        "r16uint",
        "r16sint",
        "r16float",
        "rg8unorm",
        "rg8snorm",
        "rg8uint",
        "rg8sint",
        "r32uint",
        "r32sint",
        "r32float",
        "rg16uint",
        "rg16sint",
        "rg16float",
        "rgba8unorm",
        "rgba8unorm-srgb",
        "rgba8snorm",
        "rgba8uint",
        "rgba8sint",
        "bgra8unorm",
        "bgra8unorm-srgb",
        "rgb10a2unorm",
        "rg11b10float",
        "rg32uint",
        "rg32sint",
        "rg32float",
        "rgba16uint",
        "rgba16sint",
        "rgba16float",
        "rgba32uint",
        "rgba32sint",
        "rgba32float",
        "depth32float",
        "depth24plus",
        "depth24plus-stencil8",
        "bc1-rgba-unorm",
        "bc1-rgba-unorm-srgb",
        "bc2-rgba-unorm",
        "bc2-rgba-unorm-srgb",
        "bc3-rgba-unorm",
        "bc3-rgba-unorm-srgb",
        "bc4-r-unorm",
        "bc4-r-snorm",
        "bc5-rg-unorm",
        "bc5-rg-snorm",
        "bc6h-rgb-ufloat",
        "bc6h-rgb-sfloat",
        "bc7-rgba-unorm",
        "bc7-rgba-unorm-srgb",
    };
    if (!IsValidEnum(color_formats_cpp_value, kValidValues, base::size(kValidValues), "GPUTextureFormat", exception_state))
      return;
    impl->setColorFormats(color_formats_cpp_value);
  }

  v8::Local<v8::Value> depth_stencil_format_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&depth_stencil_format_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (depth_stencil_format_value.IsEmpty() || depth_stencil_format_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> depth_stencil_format_cpp_value = depth_stencil_format_value;
    if (!depth_stencil_format_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "r8unorm",
        "r8snorm",
        "r8uint",
        "r8sint",
        "r16uint",
        "r16sint",
        "r16float",
        "rg8unorm",
        "rg8snorm",
        "rg8uint",
        "rg8sint",
        "r32uint",
        "r32sint",
        "r32float",
        "rg16uint",
        "rg16sint",
        "rg16float",
        "rgba8unorm",
        "rgba8unorm-srgb",
        "rgba8snorm",
        "rgba8uint",
        "rgba8sint",
        "bgra8unorm",
        "bgra8unorm-srgb",
        "rgb10a2unorm",
        "rg11b10float",
        "rg32uint",
        "rg32sint",
        "rg32float",
        "rgba16uint",
        "rgba16sint",
        "rgba16float",
        "rgba32uint",
        "rgba32sint",
        "rgba32float",
        "depth32float",
        "depth24plus",
        "depth24plus-stencil8",
        "bc1-rgba-unorm",
        "bc1-rgba-unorm-srgb",
        "bc2-rgba-unorm",
        "bc2-rgba-unorm-srgb",
        "bc3-rgba-unorm",
        "bc3-rgba-unorm-srgb",
        "bc4-r-unorm",
        "bc4-r-snorm",
        "bc5-rg-unorm",
        "bc5-rg-snorm",
        "bc6h-rgb-ufloat",
        "bc6h-rgb-sfloat",
        "bc7-rgba-unorm",
        "bc7-rgba-unorm-srgb",
    };
    if (!IsValidEnum(depth_stencil_format_cpp_value, kValidValues, base::size(kValidValues), "GPUTextureFormat", exception_state))
      return;
    impl->setDepthStencilFormat(depth_stencil_format_cpp_value);
  }

  v8::Local<v8::Value> sample_count_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&sample_count_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (sample_count_value.IsEmpty() || sample_count_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t sample_count_cpp_value = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(isolate, sample_count_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setSampleCount(sample_count_cpp_value);
  }
}

v8::Local<v8::Value> GPURenderBundleEncoderDescriptor::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8GPURenderBundleEncoderDescriptor(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8GPURenderBundleEncoderDescriptor(const GPURenderBundleEncoderDescriptor* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8GPUObjectDescriptorBase(impl, dictionary, creationContext, isolate))
    return false;

  const auto* keys = eternalV8GPURenderBundleEncoderDescriptorKeys(isolate).data();
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  auto create_property = [dictionary, context, keys, isolate](
                             size_t key_index, v8::Local<v8::Value> value) {
    bool added_property;
    v8::Local<v8::Name> key = keys[key_index].Get(isolate);
    if (!dictionary->CreateDataProperty(context, key, value)
             .To(&added_property)) {
      return false;
    }
    return added_property;
  };

  v8::Local<v8::Value> color_formats_value;
  bool color_formats_has_value_or_default = false;
  if (impl->hasColorFormats()) {
    color_formats_value = ToV8(impl->colorFormats(), creationContext, isolate);
    color_formats_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (color_formats_has_value_or_default &&
      !create_property(0, color_formats_value)) {
    return false;
  }

  v8::Local<v8::Value> depth_stencil_format_value;
  bool depth_stencil_format_has_value_or_default = false;
  if (impl->hasDepthStencilFormat()) {
    depth_stencil_format_value = V8String(isolate, impl->depthStencilFormat());
    depth_stencil_format_has_value_or_default = true;
  }
  if (depth_stencil_format_has_value_or_default &&
      !create_property(1, depth_stencil_format_value)) {
    return false;
  }

  v8::Local<v8::Value> sample_count_value;
  bool sample_count_has_value_or_default = false;
  if (impl->hasSampleCount()) {
    sample_count_value = v8::Integer::NewFromUnsigned(isolate, impl->sampleCount());
    sample_count_has_value_or_default = true;
  } else {
    sample_count_value = v8::Integer::NewFromUnsigned(isolate, 1u);
    sample_count_has_value_or_default = true;
  }
  if (sample_count_has_value_or_default &&
      !create_property(2, sample_count_value)) {
    return false;
  }

  return true;
}

GPURenderBundleEncoderDescriptor* NativeValueTraits<GPURenderBundleEncoderDescriptor>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPURenderBundleEncoderDescriptor* impl = MakeGarbageCollected<GPURenderBundleEncoderDescriptor>();
  V8GPURenderBundleEncoderDescriptor::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
