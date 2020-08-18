// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/gpu_load_op_or_unsigned_long_enforce_range.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"

namespace blink {

GPULoadOpOrUnsignedLongEnforceRange::GPULoadOpOrUnsignedLongEnforceRange() : type_(SpecificType::kNone) {}

const String& GPULoadOpOrUnsignedLongEnforceRange::GetAsGPULoadOp() const {
  DCHECK(IsGPULoadOp());
  return gpu_load_op_;
}

void GPULoadOpOrUnsignedLongEnforceRange::SetGPULoadOp(const String& value) {
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

GPULoadOpOrUnsignedLongEnforceRange GPULoadOpOrUnsignedLongEnforceRange::FromGPULoadOp(const String& value) {
  GPULoadOpOrUnsignedLongEnforceRange container;
  container.SetGPULoadOp(value);
  return container;
}

uint32_t GPULoadOpOrUnsignedLongEnforceRange::GetAsUnsignedLong() const {
  DCHECK(IsUnsignedLong());
  return unsigned_long_enforce_range_;
}

void GPULoadOpOrUnsignedLongEnforceRange::SetUnsignedLong(uint32_t value) {
  DCHECK(IsNull());
  unsigned_long_enforce_range_ = value;
  type_ = SpecificType::kUnsignedLongEnforceRange;
}

GPULoadOpOrUnsignedLongEnforceRange GPULoadOpOrUnsignedLongEnforceRange::FromUnsignedLong(uint32_t value) {
  GPULoadOpOrUnsignedLongEnforceRange container;
  container.SetUnsignedLong(value);
  return container;
}

GPULoadOpOrUnsignedLongEnforceRange::GPULoadOpOrUnsignedLongEnforceRange(const GPULoadOpOrUnsignedLongEnforceRange&) = default;
GPULoadOpOrUnsignedLongEnforceRange::~GPULoadOpOrUnsignedLongEnforceRange() = default;
GPULoadOpOrUnsignedLongEnforceRange& GPULoadOpOrUnsignedLongEnforceRange::operator=(const GPULoadOpOrUnsignedLongEnforceRange&) = default;

void GPULoadOpOrUnsignedLongEnforceRange::Trace(Visitor* visitor) const {
}

void V8GPULoadOpOrUnsignedLongEnforceRange::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    GPULoadOpOrUnsignedLongEnforceRange& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (v8_value->IsNumber()) {
    uint32_t cpp_value = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetUnsignedLong(cpp_value);
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

v8::Local<v8::Value> ToV8(const GPULoadOpOrUnsignedLongEnforceRange& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case GPULoadOpOrUnsignedLongEnforceRange::SpecificType::kNone:
      return v8::Null(isolate);
    case GPULoadOpOrUnsignedLongEnforceRange::SpecificType::kGPULoadOp:
      return V8String(isolate, impl.GetAsGPULoadOp());
    case GPULoadOpOrUnsignedLongEnforceRange::SpecificType::kUnsignedLongEnforceRange:
      return v8::Integer::NewFromUnsigned(isolate, impl.GetAsUnsignedLong());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

GPULoadOpOrUnsignedLongEnforceRange NativeValueTraits<GPULoadOpOrUnsignedLongEnforceRange>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPULoadOpOrUnsignedLongEnforceRange impl;
  V8GPULoadOpOrUnsignedLongEnforceRange::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

