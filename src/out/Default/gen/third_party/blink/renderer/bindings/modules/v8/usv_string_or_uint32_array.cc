// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/usv_string_or_uint32_array.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"

namespace blink {

USVStringOrUint32Array::USVStringOrUint32Array() : type_(SpecificType::kNone) {}

const String& USVStringOrUint32Array::GetAsUSVString() const {
  DCHECK(IsUSVString());
  return usv_string_;
}

void USVStringOrUint32Array::SetUSVString(const String& value) {
  DCHECK(IsNull());
  usv_string_ = value;
  type_ = SpecificType::kUSVString;
}

USVStringOrUint32Array USVStringOrUint32Array::FromUSVString(const String& value) {
  USVStringOrUint32Array container;
  container.SetUSVString(value);
  return container;
}

NotShared<DOMUint32Array> USVStringOrUint32Array::GetAsUint32Array() const {
  DCHECK(IsUint32Array());
  return uint32_array_;
}

void USVStringOrUint32Array::SetUint32Array(NotShared<DOMUint32Array> value) {
  DCHECK(IsNull());
  uint32_array_ = value;
  type_ = SpecificType::kUint32Array;
}

USVStringOrUint32Array USVStringOrUint32Array::FromUint32Array(NotShared<DOMUint32Array> value) {
  USVStringOrUint32Array container;
  container.SetUint32Array(value);
  return container;
}

USVStringOrUint32Array::USVStringOrUint32Array(const USVStringOrUint32Array&) = default;
USVStringOrUint32Array::~USVStringOrUint32Array() = default;
USVStringOrUint32Array& USVStringOrUint32Array::operator=(const USVStringOrUint32Array&) = default;

void USVStringOrUint32Array::Trace(Visitor* visitor) const {
  visitor->Trace(uint32_array_);
}

void V8USVStringOrUint32Array::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    USVStringOrUint32Array& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (v8_value->IsUint32Array()) {
    NotShared<DOMUint32Array> cpp_value = ToNotShared<NotShared<DOMUint32Array>>(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetUint32Array(cpp_value);
    return;
  }

  {
    V8StringResource<> cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetUSVString(cpp_value);
    return;
  }
}

v8::Local<v8::Value> ToV8(const USVStringOrUint32Array& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case USVStringOrUint32Array::SpecificType::kNone:
      return v8::Null(isolate);
    case USVStringOrUint32Array::SpecificType::kUSVString:
      return V8String(isolate, impl.GetAsUSVString());
    case USVStringOrUint32Array::SpecificType::kUint32Array:
      return ToV8(impl.GetAsUint32Array(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

USVStringOrUint32Array NativeValueTraits<USVStringOrUint32Array>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  USVStringOrUint32Array impl;
  V8USVStringOrUint32Array::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

