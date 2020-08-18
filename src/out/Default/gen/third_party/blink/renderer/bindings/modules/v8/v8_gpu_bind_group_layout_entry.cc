// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_bind_group_layout_entry.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8GPUBindGroupLayoutEntryKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "binding",
    "hasDynamicOffset",
    "multisampled",
    "storageTextureFormat",
    "textureComponentType",
    "type",
    "viewDimension",
    "visibility",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8GPUBindGroupLayoutEntry::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, GPUBindGroupLayoutEntry* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): binding, type, visibility.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8GPUBindGroupLayoutEntryKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> binding_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&binding_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (binding_value.IsEmpty() || binding_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member binding is undefined.");
    return;
  } else {
    uint32_t binding_cpp_value = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(isolate, binding_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setBinding(binding_cpp_value);
  }

  v8::Local<v8::Value> has_dynamic_offset_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&has_dynamic_offset_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (has_dynamic_offset_value.IsEmpty() || has_dynamic_offset_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool has_dynamic_offset_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, has_dynamic_offset_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setHasDynamicOffset(has_dynamic_offset_cpp_value);
  }

  v8::Local<v8::Value> multisampled_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&multisampled_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (multisampled_value.IsEmpty() || multisampled_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool multisampled_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, multisampled_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setMultisampled(multisampled_cpp_value);
  }

  v8::Local<v8::Value> storage_texture_format_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&storage_texture_format_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (storage_texture_format_value.IsEmpty() || storage_texture_format_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> storage_texture_format_cpp_value = storage_texture_format_value;
    if (!storage_texture_format_cpp_value.Prepare(exception_state))
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
    if (!IsValidEnum(storage_texture_format_cpp_value, kValidValues, base::size(kValidValues), "GPUTextureFormat", exception_state))
      return;
    impl->setStorageTextureFormat(storage_texture_format_cpp_value);
  }

  v8::Local<v8::Value> texture_component_type_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&texture_component_type_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (texture_component_type_value.IsEmpty() || texture_component_type_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> texture_component_type_cpp_value = texture_component_type_value;
    if (!texture_component_type_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "float",
        "sint",
        "uint",
    };
    if (!IsValidEnum(texture_component_type_cpp_value, kValidValues, base::size(kValidValues), "GPUTextureComponentType", exception_state))
      return;
    impl->setTextureComponentType(texture_component_type_cpp_value);
  }

  v8::Local<v8::Value> type_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&type_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (type_value.IsEmpty() || type_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member type is undefined.");
    return;
  } else {
    V8StringResource<> type_cpp_value = type_value;
    if (!type_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "uniform-buffer",
        "storage-buffer",
        "readonly-storage-buffer",
        "sampler",
        "comparison-sampler",
        "sampled-texture",
        "readonly-storage-texture",
        "writeonly-storage-texture",
    };
    if (!IsValidEnum(type_cpp_value, kValidValues, base::size(kValidValues), "GPUBindingType", exception_state))
      return;
    impl->setType(type_cpp_value);
  }

  v8::Local<v8::Value> view_dimension_value;
  if (!v8Object->Get(context, keys[6].Get(isolate)).ToLocal(&view_dimension_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (view_dimension_value.IsEmpty() || view_dimension_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> view_dimension_cpp_value = view_dimension_value;
    if (!view_dimension_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "1d",
        "2d",
        "2d-array",
        "cube",
        "cube-array",
        "3d",
    };
    if (!IsValidEnum(view_dimension_cpp_value, kValidValues, base::size(kValidValues), "GPUTextureViewDimension", exception_state))
      return;
    impl->setViewDimension(view_dimension_cpp_value);
  }

  v8::Local<v8::Value> visibility_value;
  if (!v8Object->Get(context, keys[7].Get(isolate)).ToLocal(&visibility_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (visibility_value.IsEmpty() || visibility_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member visibility is undefined.");
    return;
  } else {
    uint32_t visibility_cpp_value = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(isolate, visibility_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setVisibility(visibility_cpp_value);
  }
}

v8::Local<v8::Value> GPUBindGroupLayoutEntry::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8GPUBindGroupLayoutEntry(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8GPUBindGroupLayoutEntry(const GPUBindGroupLayoutEntry* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8GPUBindGroupLayoutEntryKeys(isolate).data();
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

  v8::Local<v8::Value> binding_value;
  bool binding_has_value_or_default = false;
  if (impl->hasBinding()) {
    binding_value = v8::Integer::NewFromUnsigned(isolate, impl->binding());
    binding_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (binding_has_value_or_default &&
      !create_property(0, binding_value)) {
    return false;
  }

  v8::Local<v8::Value> has_dynamic_offset_value;
  bool has_dynamic_offset_has_value_or_default = false;
  if (impl->hasHasDynamicOffset()) {
    has_dynamic_offset_value = v8::Boolean::New(isolate, impl->hasDynamicOffset());
    has_dynamic_offset_has_value_or_default = true;
  } else {
    has_dynamic_offset_value = v8::Boolean::New(isolate, false);
    has_dynamic_offset_has_value_or_default = true;
  }
  if (has_dynamic_offset_has_value_or_default &&
      !create_property(1, has_dynamic_offset_value)) {
    return false;
  }

  v8::Local<v8::Value> multisampled_value;
  bool multisampled_has_value_or_default = false;
  if (impl->hasMultisampled()) {
    multisampled_value = v8::Boolean::New(isolate, impl->multisampled());
    multisampled_has_value_or_default = true;
  } else {
    multisampled_value = v8::Boolean::New(isolate, false);
    multisampled_has_value_or_default = true;
  }
  if (multisampled_has_value_or_default &&
      !create_property(2, multisampled_value)) {
    return false;
  }

  v8::Local<v8::Value> storage_texture_format_value;
  bool storage_texture_format_has_value_or_default = false;
  if (impl->hasStorageTextureFormat()) {
    storage_texture_format_value = V8String(isolate, impl->storageTextureFormat());
    storage_texture_format_has_value_or_default = true;
  }
  if (storage_texture_format_has_value_or_default &&
      !create_property(3, storage_texture_format_value)) {
    return false;
  }

  v8::Local<v8::Value> texture_component_type_value;
  bool texture_component_type_has_value_or_default = false;
  if (impl->hasTextureComponentType()) {
    texture_component_type_value = V8String(isolate, impl->textureComponentType());
    texture_component_type_has_value_or_default = true;
  } else {
    texture_component_type_value = V8String(isolate, "float");
    texture_component_type_has_value_or_default = true;
  }
  if (texture_component_type_has_value_or_default &&
      !create_property(4, texture_component_type_value)) {
    return false;
  }

  v8::Local<v8::Value> type_value;
  bool type_has_value_or_default = false;
  if (impl->hasType()) {
    type_value = V8String(isolate, impl->type());
    type_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (type_has_value_or_default &&
      !create_property(5, type_value)) {
    return false;
  }

  v8::Local<v8::Value> view_dimension_value;
  bool view_dimension_has_value_or_default = false;
  if (impl->hasViewDimension()) {
    view_dimension_value = V8String(isolate, impl->viewDimension());
    view_dimension_has_value_or_default = true;
  } else {
    view_dimension_value = V8String(isolate, "2d");
    view_dimension_has_value_or_default = true;
  }
  if (view_dimension_has_value_or_default &&
      !create_property(6, view_dimension_value)) {
    return false;
  }

  v8::Local<v8::Value> visibility_value;
  bool visibility_has_value_or_default = false;
  if (impl->hasVisibility()) {
    visibility_value = v8::Integer::NewFromUnsigned(isolate, impl->visibility());
    visibility_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (visibility_has_value_or_default &&
      !create_property(7, visibility_value)) {
    return false;
  }

  return true;
}

GPUBindGroupLayoutEntry* NativeValueTraits<GPUBindGroupLayoutEntry>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPUBindGroupLayoutEntry* impl = MakeGarbageCollected<GPUBindGroupLayoutEntry>();
  V8GPUBindGroupLayoutEntry::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
