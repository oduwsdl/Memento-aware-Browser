// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/unsigned_long_enforce_range_sequence_or_gpu_origin_2d_dict.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_iterator.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"

namespace blink {

UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict() : type_(SpecificType::kNone) {}

GPUOrigin2DDict* UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::GetAsGPUOrigin2DDict() const {
  DCHECK(IsGPUOrigin2DDict());
  return gpu_origin_2d_dict_;
}

void UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::SetGPUOrigin2DDict(GPUOrigin2DDict* value) {
  DCHECK(IsNull());
  gpu_origin_2d_dict_ = value;
  type_ = SpecificType::kGPUOrigin2DDict;
}

UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::FromGPUOrigin2DDict(GPUOrigin2DDict* value) {
  UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict container;
  container.SetGPUOrigin2DDict(value);
  return container;
}

const Vector<uint32_t>& UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::GetAsUnsignedLongEnforceRangeSequence() const {
  DCHECK(IsUnsignedLongEnforceRangeSequence());
  return unsigned_long_enforce_range_sequence_;
}

void UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::SetUnsignedLongEnforceRangeSequence(const Vector<uint32_t>& value) {
  DCHECK(IsNull());
  unsigned_long_enforce_range_sequence_ = value;
  type_ = SpecificType::kUnsignedLongEnforceRangeSequence;
}

UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::FromUnsignedLongEnforceRangeSequence(const Vector<uint32_t>& value) {
  UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict container;
  container.SetUnsignedLongEnforceRangeSequence(value);
  return container;
}

UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict(const UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict&) = default;
UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::~UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict() = default;
UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict& UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::operator=(const UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict&) = default;

void UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::Trace(Visitor* visitor) const {
  visitor->Trace(gpu_origin_2d_dict_);
}

void V8UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (IsUndefinedOrNull(v8_value)) {
    GPUOrigin2DDict* cpp_value = NativeValueTraits<GPUOrigin2DDict>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetGPUOrigin2DDict(cpp_value);
    return;
  }

  if (v8_value->IsObject()) {
    ScriptIterator script_iterator = ScriptIterator::FromIterable(
        isolate, v8_value.As<v8::Object>(), exception_state);
    if (exception_state.HadException())
      return;
    if (!script_iterator.IsNull()) {
      Vector<uint32_t> cpp_value = NativeValueTraits<IDLSequence<IDLUnsignedLongEnforceRange>>::NativeValue(isolate, std::move(script_iterator), exception_state);
      if (exception_state.HadException())
        return;
      impl.SetUnsignedLongEnforceRangeSequence(cpp_value);
      return;
    }
  }

  if (v8_value->IsObject()) {
    GPUOrigin2DDict* cpp_value = NativeValueTraits<GPUOrigin2DDict>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetGPUOrigin2DDict(cpp_value);
    return;
  }

  exception_state.ThrowTypeError("The provided value is not of type '(sequence<[EnforceRange] unsigned long> or GPUOrigin2DDict)'");
}

v8::Local<v8::Value> ToV8(const UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::SpecificType::kNone:
      return v8::Null(isolate);
    case UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::SpecificType::kGPUOrigin2DDict:
      return ToV8(impl.GetAsGPUOrigin2DDict(), creationContext, isolate);
    case UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::SpecificType::kUnsignedLongEnforceRangeSequence:
      return ToV8(impl.GetAsUnsignedLongEnforceRangeSequence(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict NativeValueTraits<UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict impl;
  V8UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

