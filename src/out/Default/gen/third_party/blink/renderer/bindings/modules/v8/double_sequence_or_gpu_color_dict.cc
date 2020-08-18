// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/double_sequence_or_gpu_color_dict.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_iterator.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"

namespace blink {

DoubleSequenceOrGPUColorDict::DoubleSequenceOrGPUColorDict() : type_(SpecificType::kNone) {}

const Vector<double>& DoubleSequenceOrGPUColorDict::GetAsDoubleSequence() const {
  DCHECK(IsDoubleSequence());
  return double_sequence_;
}

void DoubleSequenceOrGPUColorDict::SetDoubleSequence(const Vector<double>& value) {
  DCHECK(IsNull());
  double_sequence_ = value;
  type_ = SpecificType::kDoubleSequence;
}

DoubleSequenceOrGPUColorDict DoubleSequenceOrGPUColorDict::FromDoubleSequence(const Vector<double>& value) {
  DoubleSequenceOrGPUColorDict container;
  container.SetDoubleSequence(value);
  return container;
}

GPUColorDict* DoubleSequenceOrGPUColorDict::GetAsGPUColorDict() const {
  DCHECK(IsGPUColorDict());
  return gpu_color_dict_;
}

void DoubleSequenceOrGPUColorDict::SetGPUColorDict(GPUColorDict* value) {
  DCHECK(IsNull());
  gpu_color_dict_ = value;
  type_ = SpecificType::kGPUColorDict;
}

DoubleSequenceOrGPUColorDict DoubleSequenceOrGPUColorDict::FromGPUColorDict(GPUColorDict* value) {
  DoubleSequenceOrGPUColorDict container;
  container.SetGPUColorDict(value);
  return container;
}

DoubleSequenceOrGPUColorDict::DoubleSequenceOrGPUColorDict(const DoubleSequenceOrGPUColorDict&) = default;
DoubleSequenceOrGPUColorDict::~DoubleSequenceOrGPUColorDict() = default;
DoubleSequenceOrGPUColorDict& DoubleSequenceOrGPUColorDict::operator=(const DoubleSequenceOrGPUColorDict&) = default;

void DoubleSequenceOrGPUColorDict::Trace(Visitor* visitor) const {
  visitor->Trace(gpu_color_dict_);
}

void V8DoubleSequenceOrGPUColorDict::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    DoubleSequenceOrGPUColorDict& impl,
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

  exception_state.ThrowTypeError("The provided value is not of type '(sequence<double> or GPUColorDict)'");
}

v8::Local<v8::Value> ToV8(const DoubleSequenceOrGPUColorDict& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case DoubleSequenceOrGPUColorDict::SpecificType::kNone:
      return v8::Null(isolate);
    case DoubleSequenceOrGPUColorDict::SpecificType::kDoubleSequence:
      return ToV8(impl.GetAsDoubleSequence(), creationContext, isolate);
    case DoubleSequenceOrGPUColorDict::SpecificType::kGPUColorDict:
      return ToV8(impl.GetAsGPUColorDict(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

DoubleSequenceOrGPUColorDict NativeValueTraits<DoubleSequenceOrGPUColorDict>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  DoubleSequenceOrGPUColorDict impl;
  V8DoubleSequenceOrGPUColorDict::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

