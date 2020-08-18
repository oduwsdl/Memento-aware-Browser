// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/array_buffer_view_or_blob_or_string_or_form_data_or_readable_stream.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_blob.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_form_data.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_readable_stream.h"

namespace blink {

ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream() : type_(SpecificType::kNone) {}

NotShared<DOMArrayBufferView> ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::GetAsArrayBufferView() const {
  DCHECK(IsArrayBufferView());
  return array_buffer_view_;
}

void ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::SetArrayBufferView(NotShared<DOMArrayBufferView> value) {
  DCHECK(IsNull());
  array_buffer_view_ = value;
  type_ = SpecificType::kArrayBufferView;
}

ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::FromArrayBufferView(NotShared<DOMArrayBufferView> value) {
  ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream container;
  container.SetArrayBufferView(value);
  return container;
}

Blob* ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::GetAsBlob() const {
  DCHECK(IsBlob());
  return blob_;
}

void ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::SetBlob(Blob* value) {
  DCHECK(IsNull());
  blob_ = value;
  type_ = SpecificType::kBlob;
}

ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::FromBlob(Blob* value) {
  ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream container;
  container.SetBlob(value);
  return container;
}

FormData* ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::GetAsFormData() const {
  DCHECK(IsFormData());
  return form_data_;
}

void ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::SetFormData(FormData* value) {
  DCHECK(IsNull());
  form_data_ = value;
  type_ = SpecificType::kFormData;
}

ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::FromFormData(FormData* value) {
  ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream container;
  container.SetFormData(value);
  return container;
}

ReadableStream* ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::GetAsReadableStream() const {
  DCHECK(IsReadableStream());
  return readable_stream_;
}

void ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::SetReadableStream(ReadableStream* value) {
  DCHECK(IsNull());
  readable_stream_ = value;
  type_ = SpecificType::kReadableStream;
}

ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::FromReadableStream(ReadableStream* value) {
  ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream container;
  container.SetReadableStream(value);
  return container;
}

const String& ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::GetAsString() const {
  DCHECK(IsString());
  return string_;
}

void ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::SetString(const String& value) {
  DCHECK(IsNull());
  string_ = value;
  type_ = SpecificType::kString;
}

ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::FromString(const String& value) {
  ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream container;
  container.SetString(value);
  return container;
}

ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream(const ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream&) = default;
ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::~ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream() = default;
ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream& ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::operator=(const ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream&) = default;

void ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::Trace(Visitor* visitor) const {
  visitor->Trace(array_buffer_view_);
  visitor->Trace(blob_);
  visitor->Trace(form_data_);
  visitor->Trace(readable_stream_);
}

void V8ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (V8Blob::HasInstance(v8_value, isolate)) {
    Blob* cpp_value = V8Blob::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetBlob(cpp_value);
    return;
  }

  if (V8FormData::HasInstance(v8_value, isolate)) {
    FormData* cpp_value = V8FormData::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetFormData(cpp_value);
    return;
  }

  if (V8ReadableStream::HasInstance(v8_value, isolate)) {
    ReadableStream* cpp_value = V8ReadableStream::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetReadableStream(cpp_value);
    return;
  }

  if (v8_value->IsArrayBufferView()) {
    NotShared<DOMArrayBufferView> cpp_value = ToNotShared<NotShared<DOMArrayBufferView>>(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetArrayBufferView(cpp_value);
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

v8::Local<v8::Value> ToV8(const ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::SpecificType::kNone:
      return v8::Null(isolate);
    case ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::SpecificType::kArrayBufferView:
      return ToV8(impl.GetAsArrayBufferView(), creationContext, isolate);
    case ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::SpecificType::kBlob:
      return ToV8(impl.GetAsBlob(), creationContext, isolate);
    case ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::SpecificType::kFormData:
      return ToV8(impl.GetAsFormData(), creationContext, isolate);
    case ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::SpecificType::kReadableStream:
      return ToV8(impl.GetAsReadableStream(), creationContext, isolate);
    case ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::SpecificType::kString:
      return V8String(isolate, impl.GetAsString());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream NativeValueTraits<ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream impl;
  V8ArrayBufferViewOrBlobOrStringOrFormDataOrReadableStream::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

