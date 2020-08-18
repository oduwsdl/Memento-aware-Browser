// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/boolean_or_double_or_constrain_double_range.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"

namespace blink {

BooleanOrDoubleOrConstrainDoubleRange::BooleanOrDoubleOrConstrainDoubleRange() : type_(SpecificType::kNone) {}

bool BooleanOrDoubleOrConstrainDoubleRange::GetAsBoolean() const {
  DCHECK(IsBoolean());
  return boolean_;
}

void BooleanOrDoubleOrConstrainDoubleRange::SetBoolean(bool value) {
  DCHECK(IsNull());
  boolean_ = value;
  type_ = SpecificType::kBoolean;
}

BooleanOrDoubleOrConstrainDoubleRange BooleanOrDoubleOrConstrainDoubleRange::FromBoolean(bool value) {
  BooleanOrDoubleOrConstrainDoubleRange container;
  container.SetBoolean(value);
  return container;
}

ConstrainDoubleRange* BooleanOrDoubleOrConstrainDoubleRange::GetAsConstrainDoubleRange() const {
  DCHECK(IsConstrainDoubleRange());
  return constrain_double_range_;
}

void BooleanOrDoubleOrConstrainDoubleRange::SetConstrainDoubleRange(ConstrainDoubleRange* value) {
  DCHECK(IsNull());
  constrain_double_range_ = value;
  type_ = SpecificType::kConstrainDoubleRange;
}

BooleanOrDoubleOrConstrainDoubleRange BooleanOrDoubleOrConstrainDoubleRange::FromConstrainDoubleRange(ConstrainDoubleRange* value) {
  BooleanOrDoubleOrConstrainDoubleRange container;
  container.SetConstrainDoubleRange(value);
  return container;
}

double BooleanOrDoubleOrConstrainDoubleRange::GetAsDouble() const {
  DCHECK(IsDouble());
  return double_;
}

void BooleanOrDoubleOrConstrainDoubleRange::SetDouble(double value) {
  DCHECK(IsNull());
  double_ = value;
  type_ = SpecificType::kDouble;
}

BooleanOrDoubleOrConstrainDoubleRange BooleanOrDoubleOrConstrainDoubleRange::FromDouble(double value) {
  BooleanOrDoubleOrConstrainDoubleRange container;
  container.SetDouble(value);
  return container;
}

BooleanOrDoubleOrConstrainDoubleRange::BooleanOrDoubleOrConstrainDoubleRange(const BooleanOrDoubleOrConstrainDoubleRange&) = default;
BooleanOrDoubleOrConstrainDoubleRange::~BooleanOrDoubleOrConstrainDoubleRange() = default;
BooleanOrDoubleOrConstrainDoubleRange& BooleanOrDoubleOrConstrainDoubleRange::operator=(const BooleanOrDoubleOrConstrainDoubleRange&) = default;

void BooleanOrDoubleOrConstrainDoubleRange::Trace(Visitor* visitor) const {
  visitor->Trace(constrain_double_range_);
}

void V8BooleanOrDoubleOrConstrainDoubleRange::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    BooleanOrDoubleOrConstrainDoubleRange& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (IsUndefinedOrNull(v8_value)) {
    ConstrainDoubleRange* cpp_value = NativeValueTraits<ConstrainDoubleRange>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetConstrainDoubleRange(cpp_value);
    return;
  }

  if (v8_value->IsObject()) {
    ConstrainDoubleRange* cpp_value = NativeValueTraits<ConstrainDoubleRange>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetConstrainDoubleRange(cpp_value);
    return;
  }

  if (v8_value->IsBoolean()) {
    impl.SetBoolean(v8_value.As<v8::Boolean>()->Value());
    return;
  }

  if (v8_value->IsNumber()) {
    double cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetDouble(cpp_value);
    return;
  }

  {
    double cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetDouble(cpp_value);
    return;
  }
}

v8::Local<v8::Value> ToV8(const BooleanOrDoubleOrConstrainDoubleRange& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case BooleanOrDoubleOrConstrainDoubleRange::SpecificType::kNone:
      return v8::Null(isolate);
    case BooleanOrDoubleOrConstrainDoubleRange::SpecificType::kBoolean:
      return v8::Boolean::New(isolate, impl.GetAsBoolean());
    case BooleanOrDoubleOrConstrainDoubleRange::SpecificType::kConstrainDoubleRange:
      return ToV8(impl.GetAsConstrainDoubleRange(), creationContext, isolate);
    case BooleanOrDoubleOrConstrainDoubleRange::SpecificType::kDouble:
      return v8::Number::New(isolate, impl.GetAsDouble());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

BooleanOrDoubleOrConstrainDoubleRange NativeValueTraits<BooleanOrDoubleOrConstrainDoubleRange>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  BooleanOrDoubleOrConstrainDoubleRange impl;
  V8BooleanOrDoubleOrConstrainDoubleRange::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

