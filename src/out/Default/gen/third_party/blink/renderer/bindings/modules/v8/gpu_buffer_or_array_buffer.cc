// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/gpu_buffer_or_array_buffer.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_buffer.h"

namespace blink {

GPUBufferOrArrayBuffer::GPUBufferOrArrayBuffer() : type_(SpecificType::kNone) {}

DOMArrayBuffer* GPUBufferOrArrayBuffer::GetAsArrayBuffer() const {
  DCHECK(IsArrayBuffer());
  return array_buffer_;
}

void GPUBufferOrArrayBuffer::SetArrayBuffer(DOMArrayBuffer* value) {
  DCHECK(IsNull());
  array_buffer_ = value;
  type_ = SpecificType::kArrayBuffer;
}

GPUBufferOrArrayBuffer GPUBufferOrArrayBuffer::FromArrayBuffer(DOMArrayBuffer* value) {
  GPUBufferOrArrayBuffer container;
  container.SetArrayBuffer(value);
  return container;
}

GPUBuffer* GPUBufferOrArrayBuffer::GetAsGPUBuffer() const {
  DCHECK(IsGPUBuffer());
  return gpu_buffer_;
}

void GPUBufferOrArrayBuffer::SetGPUBuffer(GPUBuffer* value) {
  DCHECK(IsNull());
  gpu_buffer_ = value;
  type_ = SpecificType::kGPUBuffer;
}

GPUBufferOrArrayBuffer GPUBufferOrArrayBuffer::FromGPUBuffer(GPUBuffer* value) {
  GPUBufferOrArrayBuffer container;
  container.SetGPUBuffer(value);
  return container;
}

GPUBufferOrArrayBuffer::GPUBufferOrArrayBuffer(const GPUBufferOrArrayBuffer&) = default;
GPUBufferOrArrayBuffer::~GPUBufferOrArrayBuffer() = default;
GPUBufferOrArrayBuffer& GPUBufferOrArrayBuffer::operator=(const GPUBufferOrArrayBuffer&) = default;

void GPUBufferOrArrayBuffer::Trace(Visitor* visitor) const {
  visitor->Trace(array_buffer_);
  visitor->Trace(gpu_buffer_);
}

void V8GPUBufferOrArrayBuffer::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    GPUBufferOrArrayBuffer& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (V8GPUBuffer::HasInstance(v8_value, isolate)) {
    GPUBuffer* cpp_value = V8GPUBuffer::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetGPUBuffer(cpp_value);
    return;
  }

  if (v8_value->IsArrayBuffer()) {
    DOMArrayBuffer* cpp_value = V8ArrayBuffer::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetArrayBuffer(cpp_value);
    return;
  }

  exception_state.ThrowTypeError("The provided value is not of type '(GPUBuffer or ArrayBuffer)'");
}

v8::Local<v8::Value> ToV8(const GPUBufferOrArrayBuffer& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case GPUBufferOrArrayBuffer::SpecificType::kNone:
      return v8::Null(isolate);
    case GPUBufferOrArrayBuffer::SpecificType::kArrayBuffer:
      return ToV8(impl.GetAsArrayBuffer(), creationContext, isolate);
    case GPUBufferOrArrayBuffer::SpecificType::kGPUBuffer:
      return ToV8(impl.GetAsGPUBuffer(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

GPUBufferOrArrayBuffer NativeValueTraits<GPUBufferOrArrayBuffer>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPUBufferOrArrayBuffer impl;
  V8GPUBufferOrArrayBuffer::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

