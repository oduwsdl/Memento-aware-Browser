// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/gpu_load_op_or_double_sequence_or_gpu_color_dict.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_iterator.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"

namespace blink {

GPULoadOpOrDoubleSequenceOrGPUColorDict::GPULoadOpOrDoubleSequenceOrGPUColorDict() : type_(SpecificType::kNone) {}

const Vector<double>& GPULoadOpOrDoubleSequenceOrGPUColorDict::GetAsDoubleSequence() const {
  DCHECK(IsDoubleSequence());
  return double_sequence_;
}

void GPULoadOpOrDoubleSequenceOrGPUColorDict::SetDoubleSequence(const Vector<double>& value) {
  DCHECK(IsNull());
  double_sequence_ = value;
  type_ = SpecificType::kDoubleSequence;
}

GPULoadOpOrDoubleSequenceOrGPUColorDict GPULoadOpOrDoubleSequenceOrGPUColorDict::FromDoubleSequence(const Vector<double>& value) {
  GPULoadOpOrDoubleSequenceOrGPUColorDict container;
  container.SetDoubleSequence(value);
  return container;
}

GPUColorDict* GPULoadOpOrDoubleSequenceOrGPUColorDict::GetAsGPUColorDict() const {
  DCHECK(IsGPUColorDict());
  return gpu_color_dict_;
}

void GPULoadOpOrDoubleSequenceOrGPUColorDict::SetGPUColorDict(GPUColorDict* value) {
  DCHECK(IsNull());
  gpu_color_dict_ = value;
  type_ = SpecificType::kGPUColorDict;
}

GPULoadOpOrDoubleSequenceOrGPUColorDict GPULoadOpOrDoubleSequenceOrGPUColorDict::FromGPUColorDict(GPUColorDict* value) {
  GPULoadOpOrDoubleSequenceOrGPUColorDict container;
  container.SetGPUColorDict(value);
  return container;
}

const String& GPULoadOpOrDoubleSequenceOrGPUColorDict::GetAsGPULoadOp() const {
  DCHECK(IsGPULoadOp());
  return gpu_load_op_;
}

void GPULoadOpOrDoubleSequenceOrGPUColorDict::SetGPULoadOp(const String& value) {
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

GPULoadOpOrDoubleSequenceOrGPUColorDict GPULoadOpOrDoubleSequenceOrGPUColorDict::FromGPULoadOp(const String& value) {
  GPULoadOpOrDoubleSequenceOrGPUColorDict container;
  container.SetGPULoadOp(value);
  return container;
}

GPULoadOpOrDoubleSequenceOrGPUColorDict::GPULoadOpOrDoubleSequenceOrGPUColorDict(const GPULoadOpOrDoubleSequenceOrGPUColorDict&) = default;
GPULoadOpOrDoubleSequenceOrGPUColorDict::~GPULoadOpOrDoubleSequenceOrGPUColorDict() = default;
GPULoadOpOrDoubleSequenceOrGPUColorDict& GPULoadOpOrDoubleSequenceOrGPUColorDict::operator=(const GPULoadOpOrDoubleSequenceOrGPUColorDict&) = default;

void GPULoadOpOrDoubleSequenceOrGPUColorDict::Trace(Visitor* visitor) const {
  visitor->Trace(gpu_color_dict_);
}

void V8GPULoadOpOrDoubleSequenceOrGPUColorDict::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    GPULoadOpOrDoubleSequenceOrGPUColorDict& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (IsUndefinedOrNull(v8_value)) {
    GPUColorDict* cpp_value = NativeValueTraits<GPUColorDict>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetGPUColorDict(cpp_value);
    return;
  }

  if (v8_value->IsObject()) {
    ScriptIterator script_iterator = ScriptIterator::FromIterable(
        isolate, v8_value.As<v8::Object>(), exception_state);
    if (exception_state.HadException())
      return;
    if (!script_iterator.IsNull()) {
      Vector<double> cpp_value = NativeValueTraits<IDLSequence<IDLDouble>>::NativeValue(isolate, std::move(script_iterator), exception_state);
      if (exception_state.HadException())
        return;
      impl.SetDoubleSequence(cpp_value);
      return;
    }
  }

  if (v8_value->IsObject()) {
    GPUColorDict* cpp_value = NativeValueTraits<GPUColorDict>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetGPUColorDict(cpp_value);
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

v8::Local<v8::Value> ToV8(const GPULoadOpOrDoubleSequenceOrGPUColorDict& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case GPULoadOpOrDoubleSequenceOrGPUColorDict::SpecificType::kNone:
      return v8::Null(isolate);
    case GPULoadOpOrDoubleSequenceOrGPUColorDict::SpecificType::kDoubleSequence:
      return ToV8(impl.GetAsDoubleSequence(), creationContext, isolate);
    case GPULoadOpOrDoubleSequenceOrGPUColorDict::SpecificType::kGPUColorDict:
      return ToV8(impl.GetAsGPUColorDict(), creationContext, isolate);
    case GPULoadOpOrDoubleSequenceOrGPUColorDict::SpecificType::kGPULoadOp:
      return V8String(isolate, impl.GetAsGPULoadOp());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

GPULoadOpOrDoubleSequenceOrGPUColorDict NativeValueTraits<GPULoadOpOrDoubleSequenceOrGPUColorDict>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPULoadOpOrDoubleSequenceOrGPUColorDict impl;
  V8GPULoadOpOrDoubleSequenceOrGPUColorDict::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

