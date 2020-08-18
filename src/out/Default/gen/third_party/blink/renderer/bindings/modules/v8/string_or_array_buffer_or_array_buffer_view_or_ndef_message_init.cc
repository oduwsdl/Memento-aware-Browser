// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/string_or_array_buffer_or_array_buffer_view_or_ndef_message_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"

namespace blink {

StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit() : type_(SpecificType::kNone) {}

DOMArrayBuffer* StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::GetAsArrayBuffer() const {
  DCHECK(IsArrayBuffer());
  return array_buffer_;
}

void StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::SetArrayBuffer(DOMArrayBuffer* value) {
  DCHECK(IsNull());
  array_buffer_ = value;
  type_ = SpecificType::kArrayBuffer;
}

StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::FromArrayBuffer(DOMArrayBuffer* value) {
  StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit container;
  container.SetArrayBuffer(value);
  return container;
}

NotShared<DOMArrayBufferView> StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::GetAsArrayBufferView() const {
  DCHECK(IsArrayBufferView());
  return array_buffer_view_;
}

void StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::SetArrayBufferView(NotShared<DOMArrayBufferView> value) {
  DCHECK(IsNull());
  array_buffer_view_ = value;
  type_ = SpecificType::kArrayBufferView;
}

StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::FromArrayBufferView(NotShared<DOMArrayBufferView> value) {
  StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit container;
  container.SetArrayBufferView(value);
  return container;
}

NDEFMessageInit* StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::GetAsNDEFMessageInit() const {
  DCHECK(IsNDEFMessageInit());
  return ndef_message_init_;
}

void StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::SetNDEFMessageInit(NDEFMessageInit* value) {
  DCHECK(IsNull());
  ndef_message_init_ = value;
  type_ = SpecificType::kNDEFMessageInit;
}

StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::FromNDEFMessageInit(NDEFMessageInit* value) {
  StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit container;
  container.SetNDEFMessageInit(value);
  return container;
}

const String& StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::GetAsString() const {
  DCHECK(IsString());
  return string_;
}

void StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::SetString(const String& value) {
  DCHECK(IsNull());
  string_ = value;
  type_ = SpecificType::kString;
}

StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::FromString(const String& value) {
  StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit container;
  container.SetString(value);
  return container;
}

StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit(const StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit&) = default;
StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::~StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit() = default;
StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit& StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::operator=(const StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit&) = default;

void StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::Trace(Visitor* visitor) const {
  visitor->Trace(array_buffer_);
  visitor->Trace(array_buffer_view_);
  visitor->Trace(ndef_message_init_);
}

void V8StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (IsUndefinedOrNull(v8_value)) {
    NDEFMessageInit* cpp_value = NativeValueTraits<NDEFMessageInit>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetNDEFMessageInit(cpp_value);
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
    NDEFMessageInit* cpp_value = NativeValueTraits<NDEFMessageInit>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetNDEFMessageInit(cpp_value);
    return;
  }

  {
    V8StringResource<> cpp_value = v8_value;
    if (!cpp_value.Prepare(exception_state))
      return;
    impl.SetString(cpp_value);
    return;
  }
}

v8::Local<v8::Value> ToV8(const StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::SpecificType::kNone:
      return v8::Null(isolate);
    case StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::SpecificType::kArrayBuffer:
      return ToV8(impl.GetAsArrayBuffer(), creationContext, isolate);
    case StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::SpecificType::kArrayBufferView:
      return ToV8(impl.GetAsArrayBufferView(), creationContext, isolate);
    case StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::SpecificType::kNDEFMessageInit:
      return ToV8(impl.GetAsNDEFMessageInit(), creationContext, isolate);
    case StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::SpecificType::kString:
      return V8String(isolate, impl.GetAsString());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit NativeValueTraits<StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit impl;
  V8StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

