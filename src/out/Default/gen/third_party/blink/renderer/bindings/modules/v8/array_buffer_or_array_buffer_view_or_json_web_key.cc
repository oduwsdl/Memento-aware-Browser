// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/array_buffer_or_array_buffer_view_or_json_web_key.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"

namespace blink {

ArrayBufferOrArrayBufferViewOrJsonWebKey::ArrayBufferOrArrayBufferViewOrJsonWebKey() : type_(SpecificType::kNone) {}

DOMArrayBuffer* ArrayBufferOrArrayBufferViewOrJsonWebKey::GetAsArrayBuffer() const {
  DCHECK(IsArrayBuffer());
  return array_buffer_;
}

void ArrayBufferOrArrayBufferViewOrJsonWebKey::SetArrayBuffer(DOMArrayBuffer* value) {
  DCHECK(IsNull());
  array_buffer_ = value;
  type_ = SpecificType::kArrayBuffer;
}

ArrayBufferOrArrayBufferViewOrJsonWebKey ArrayBufferOrArrayBufferViewOrJsonWebKey::FromArrayBuffer(DOMArrayBuffer* value) {
  ArrayBufferOrArrayBufferViewOrJsonWebKey container;
  container.SetArrayBuffer(value);
  return container;
}

NotShared<DOMArrayBufferView> ArrayBufferOrArrayBufferViewOrJsonWebKey::GetAsArrayBufferView() const {
  DCHECK(IsArrayBufferView());
  return array_buffer_view_;
}

void ArrayBufferOrArrayBufferViewOrJsonWebKey::SetArrayBufferView(NotShared<DOMArrayBufferView> value) {
  DCHECK(IsNull());
  array_buffer_view_ = value;
  type_ = SpecificType::kArrayBufferView;
}

ArrayBufferOrArrayBufferViewOrJsonWebKey ArrayBufferOrArrayBufferViewOrJsonWebKey::FromArrayBufferView(NotShared<DOMArrayBufferView> value) {
  ArrayBufferOrArrayBufferViewOrJsonWebKey container;
  container.SetArrayBufferView(value);
  return container;
}

JsonWebKey* ArrayBufferOrArrayBufferViewOrJsonWebKey::GetAsJsonWebKey() const {
  DCHECK(IsJsonWebKey());
  return json_web_key_;
}

void ArrayBufferOrArrayBufferViewOrJsonWebKey::SetJsonWebKey(JsonWebKey* value) {
  DCHECK(IsNull());
  json_web_key_ = value;
  type_ = SpecificType::kJsonWebKey;
}

ArrayBufferOrArrayBufferViewOrJsonWebKey ArrayBufferOrArrayBufferViewOrJsonWebKey::FromJsonWebKey(JsonWebKey* value) {
  ArrayBufferOrArrayBufferViewOrJsonWebKey container;
  container.SetJsonWebKey(value);
  return container;
}

ArrayBufferOrArrayBufferViewOrJsonWebKey::ArrayBufferOrArrayBufferViewOrJsonWebKey(const ArrayBufferOrArrayBufferViewOrJsonWebKey&) = default;
ArrayBufferOrArrayBufferViewOrJsonWebKey::~ArrayBufferOrArrayBufferViewOrJsonWebKey() = default;
ArrayBufferOrArrayBufferViewOrJsonWebKey& ArrayBufferOrArrayBufferViewOrJsonWebKey::operator=(const ArrayBufferOrArrayBufferViewOrJsonWebKey&) = default;

void ArrayBufferOrArrayBufferViewOrJsonWebKey::Trace(Visitor* visitor) const {
  visitor->Trace(array_buffer_);
  visitor->Trace(array_buffer_view_);
  visitor->Trace(json_web_key_);
}

void V8ArrayBufferOrArrayBufferViewOrJsonWebKey::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    ArrayBufferOrArrayBufferViewOrJsonWebKey& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (IsUndefinedOrNull(v8_value)) {
    JsonWebKey* cpp_value = NativeValueTraits<JsonWebKey>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetJsonWebKey(cpp_value);
    return;
  }

  if (v8_value->IsArrayBuffer()) {
    DOMArrayBuffer* cpp_value = V8ArrayBuffer::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetArrayBuffer(cpp_value);
    return;
  }

  if (v8_value->IsArrayBufferView()) {
    NotShared<DOMArrayBufferView> cpp_value = ToNotShared<NotShared<DOMArrayBufferView>>(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetArrayBufferView(cpp_value);
    return;
  }

  if (v8_value->IsObject()) {
    JsonWebKey* cpp_value = NativeValueTraits<JsonWebKey>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetJsonWebKey(cpp_value);
    return;
  }

  exception_state.ThrowTypeError("The provided value is not of type '((ArrayBuffer or ArrayBufferView) or JsonWebKey)'");
}

v8::Local<v8::Value> ToV8(const ArrayBufferOrArrayBufferViewOrJsonWebKey& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case ArrayBufferOrArrayBufferViewOrJsonWebKey::SpecificType::kNone:
      return v8::Null(isolate);
    case ArrayBufferOrArrayBufferViewOrJsonWebKey::SpecificType::kArrayBuffer:
      return ToV8(impl.GetAsArrayBuffer(), creationContext, isolate);
    case ArrayBufferOrArrayBufferViewOrJsonWebKey::SpecificType::kArrayBufferView:
      return ToV8(impl.GetAsArrayBufferView(), creationContext, isolate);
    case ArrayBufferOrArrayBufferViewOrJsonWebKey::SpecificType::kJsonWebKey:
      return ToV8(impl.GetAsJsonWebKey(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

ArrayBufferOrArrayBufferViewOrJsonWebKey NativeValueTraits<ArrayBufferOrArrayBufferViewOrJsonWebKey>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ArrayBufferOrArrayBufferViewOrJsonWebKey impl;
  V8ArrayBufferOrArrayBufferViewOrJsonWebKey::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

