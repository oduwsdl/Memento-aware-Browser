// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_vertex_buffer_layout_descriptor.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_vertex_attribute_descriptor.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8GPUVertexBufferLayoutDescriptorKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "arrayStride",
    "attributes",
    "stepMode",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8GPUVertexBufferLayoutDescriptor::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, GPUVertexBufferLayoutDescriptor* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): arrayStride, attributes.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8GPUVertexBufferLayoutDescriptorKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> array_stride_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&array_stride_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (array_stride_value.IsEmpty() || array_stride_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member arrayStride is undefined.");
    return;
  } else {
    uint64_t array_stride_cpp_value = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(isolate, array_stride_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setArrayStride(array_stride_cpp_value);
  }

  v8::Local<v8::Value> attributes_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&attributes_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (attributes_value.IsEmpty() || attributes_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member attributes is undefined.");
    return;
  } else {
    HeapVector<Member<GPUVertexAttributeDescriptor>> attributes_cpp_value = NativeValueTraits<IDLSequence<GPUVertexAttributeDescriptor>>::NativeValue(isolate, attributes_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setAttributes(attributes_cpp_value);
  }

  v8::Local<v8::Value> step_mode_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&step_mode_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (step_mode_value.IsEmpty() || step_mode_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> step_mode_cpp_value = step_mode_value;
    if (!step_mode_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "vertex",
        "instance",
    };
    if (!IsValidEnum(step_mode_cpp_value, kValidValues, base::size(kValidValues), "GPUInputStepMode", exception_state))
      return;
    impl->setStepMode(step_mode_cpp_value);
  }
}

v8::Local<v8::Value> GPUVertexBufferLayoutDescriptor::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8GPUVertexBufferLayoutDescriptor(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8GPUVertexBufferLayoutDescriptor(const GPUVertexBufferLayoutDescriptor* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8GPUVertexBufferLayoutDescriptorKeys(isolate).data();
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

  v8::Local<v8::Value> array_stride_value;
  bool array_stride_has_value_or_default = false;
  if (impl->hasArrayStride()) {
    array_stride_value = v8::Number::New(isolate, static_cast<double>(impl->arrayStride()));
    array_stride_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (array_stride_has_value_or_default &&
      !create_property(0, array_stride_value)) {
    return false;
  }

  v8::Local<v8::Value> attributes_value;
  bool attributes_has_value_or_default = false;
  if (impl->hasAttributes()) {
    attributes_value = ToV8(impl->attributes(), creationContext, isolate);
    attributes_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (attributes_has_value_or_default &&
      !create_property(1, attributes_value)) {
    return false;
  }

  v8::Local<v8::Value> step_mode_value;
  bool step_mode_has_value_or_default = false;
  if (impl->hasStepMode()) {
    step_mode_value = V8String(isolate, impl->stepMode());
    step_mode_has_value_or_default = true;
  } else {
    step_mode_value = V8String(isolate, "vertex");
    step_mode_has_value_or_default = true;
  }
  if (step_mode_has_value_or_default &&
      !create_property(2, step_mode_value)) {
    return false;
  }

  return true;
}

GPUVertexBufferLayoutDescriptor* NativeValueTraits<GPUVertexBufferLayoutDescriptor>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPUVertexBufferLayoutDescriptor* impl = MakeGarbageCollected<GPUVertexBufferLayoutDescriptor>();
  V8GPUVertexBufferLayoutDescriptor::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
