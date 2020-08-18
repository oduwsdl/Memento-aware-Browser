// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/gpu_load_op_or_float.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"

namespace blink {

GPULoadOpOrFloat::GPULoadOpOrFloat() : type_(SpecificType::kNone) {}

float GPULoadOpOrFloat::GetAsFloat() const {
  DCHECK(IsFloat());
  return float_;
}

void GPULoadOpOrFloat::SetFloat(float value) {
  DCHECK(IsNull());
  float_ = value;
  type_ = SpecificType::kFloat;
}

GPULoadOpOrFloat GPULoadOpOrFloat::FromFloat(float value) {
  GPULoadOpOrFloat container;
  container.SetFloat(value);
  return container;
}

const String& GPULoadOpOrFloat::GetAsGPULoadOp() const {
  DCHECK(IsGPULoadOp());
  return gpu_load_op_;
}

void GPULoadOpOrFloat::SetGPULoadOp(const String& value) {
  DCHECK(IsNull());
  NonThrowableExceptionState exception_state;
  const char* const kValidValues[] = {
      "load",
  };
  if (!IsValidEnum(value, kValidValues, base::size(kValidValues), "GPULoadOp", exception_state)) {
    NOTREACHED();
    return;
  }
  gpu_load_op_ = value;
  type_ = SpecificType::kGPULoadOp;
}

GPULoadOpOrFloat GPULoadOpOrFloat::FromGPULoadOp(const String& value) {
  GPULoadOpOrFloat container;
  container.SetGPULoadOp(value);
  return container;
}

GPULoadOpOrFloat::GPULoadOpOrFloat(const GPULoadOpOrFloat&) = default;
GPULoadOpOrFloat::~GPULoadOpOrFloat() = default;
GPULoadOpOrFloat& GPULoadOpOrFloat::operator=(const GPULoadOpOrFloat&) = default;

void GPULoadOpOrFloat::Trace(Visitor* visitor) const {
}

void V8GPULoadOpOrFloat::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    GPULoadOpOrFloat& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (v8_value->IsNumber()) {
    float cpp_value = NativeValueTraits<IDLFloat>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetFloat(cpp_value);
    return;
  }

  {
    V8StringResource<> cpp_value = v8_value;
    if (!cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "load",
    };
    if (!IsValidEnum(cpp_value, kValidValues, base::size(kValidValues), "GPULoadOp", exception_state))
      return;
    impl.SetGPULoadOp(cpp_value);
    return;
  }
}

v8::Local<v8::Value> ToV8(const GPULoadOpOrFloat& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case GPULoadOpOrFloat::SpecificType::kNone:
      return v8::Null(isolate);
    case GPULoadOpOrFloat::SpecificType::kFloat:
      return v8::Number::New(isolate, impl.GetAsFloat());
    case GPULoadOpOrFloat::SpecificType::kGPULoadOp:
      return V8String(isolate, impl.GetAsGPULoadOp());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

GPULoadOpOrFloat NativeValueTraits<GPULoadOpOrFloat>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPULoadOpOrFloat impl;
  V8GPULoadOpOrFloat::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

