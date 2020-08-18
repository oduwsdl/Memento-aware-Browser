// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_shader_module_descriptor.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_uint32_array.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_object_descriptor_base.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/flexible_array_buffer_view.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8GPUShaderModuleDescriptorKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "code",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8GPUShaderModuleDescriptor::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, GPUShaderModuleDescriptor* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): code.");
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

  const auto* keys = eternalV8GPUShaderModuleDescriptorKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> code_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&code_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (code_value.IsEmpty() || code_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member code is undefined.");
    return;
  } else {
    USVStringOrUint32Array code_cpp_value;
    V8USVStringOrUint32Array::ToImpl(isolate, code_value, code_cpp_value, UnionTypeConversionMode::kNotNullable, exception_state);
    if (exception_state.HadException())
      return;
    impl->setCode(code_cpp_value);
  }
}

v8::Local<v8::Value> GPUShaderModuleDescriptor::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8GPUShaderModuleDescriptor(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8GPUShaderModuleDescriptor(const GPUShaderModuleDescriptor* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8GPUObjectDescriptorBase(impl, dictionary, creationContext, isolate))
    return false;

  const auto* keys = eternalV8GPUShaderModuleDescriptorKeys(isolate).data();
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

  v8::Local<v8::Value> code_value;
  bool code_has_value_or_default = false;
  if (impl->hasCode()) {
    code_value = ToV8(impl->code(), creationContext, isolate);
    code_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (code_has_value_or_default &&
      !create_property(0, code_value)) {
    return false;
  }

  return true;
}

GPUShaderModuleDescriptor* NativeValueTraits<GPUShaderModuleDescriptor>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPUShaderModuleDescriptor* impl = MakeGarbageCollected<GPUShaderModuleDescriptor>();
  V8GPUShaderModuleDescriptor::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
