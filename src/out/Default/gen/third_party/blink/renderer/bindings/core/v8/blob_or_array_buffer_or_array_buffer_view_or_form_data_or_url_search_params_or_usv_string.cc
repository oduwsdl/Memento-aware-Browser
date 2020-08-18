// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/blob_or_array_buffer_or_array_buffer_view_or_form_data_or_url_search_params_or_usv_string.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_blob.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_form_data.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_url_search_params.h"

namespace blink {

BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString() : type_(SpecificType::kNone) {}

DOMArrayBuffer* BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsArrayBuffer() const {
  DCHECK(IsArrayBuffer());
  return array_buffer_;
}

void BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetArrayBuffer(DOMArrayBuffer* value) {
  DCHECK(IsNull());
  array_buffer_ = value;
  type_ = SpecificType::kArrayBuffer;
}

BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromArrayBuffer(DOMArrayBuffer* value) {
  BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetArrayBuffer(value);
  return container;
}

NotShared<DOMArrayBufferView> BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsArrayBufferView() const {
  DCHECK(IsArrayBufferView());
  return array_buffer_view_;
}

void BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetArrayBufferView(NotShared<DOMArrayBufferView> value) {
  DCHECK(IsNull());
  array_buffer_view_ = value;
  type_ = SpecificType::kArrayBufferView;
}

BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromArrayBufferView(NotShared<DOMArrayBufferView> value) {
  BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetArrayBufferView(value);
  return container;
}

Blob* BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsBlob() const {
  DCHECK(IsBlob());
  return blob_;
}

void BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetBlob(Blob* value) {
  DCHECK(IsNull());
  blob_ = value;
  type_ = SpecificType::kBlob;
}

BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromBlob(Blob* value) {
  BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetBlob(value);
  return container;
}

FormData* BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsFormData() const {
  DCHECK(IsFormData());
  return form_data_;
}

void BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetFormData(FormData* value) {
  DCHECK(IsNull());
  form_data_ = value;
  type_ = SpecificType::kFormData;
}

BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromFormData(FormData* value) {
  BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetFormData(value);
  return container;
}

URLSearchParams* BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsURLSearchParams() const {
  DCHECK(IsURLSearchParams());
  return url_search_params_;
}

void BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetURLSearchParams(URLSearchParams* value) {
  DCHECK(IsNull());
  url_search_params_ = value;
  type_ = SpecificType::kURLSearchParams;
}

BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromURLSearchParams(URLSearchParams* value) {
  BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetURLSearchParams(value);
  return container;
}

const String& BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsUSVString() const {
  DCHECK(IsUSVString());
  return usv_string_;
}

void BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetUSVString(const String& value) {
  DCHECK(IsNull());
  usv_string_ = value;
  type_ = SpecificType::kUSVString;
}

BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromUSVString(const String& value) {
  BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetUSVString(value);
  return container;
}

BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString(const BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString&) = default;
BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::~BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString() = default;
BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString& BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::operator=(const BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString&) = default;

void BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::Trace(Visitor* visitor) const {
  visitor->Trace(array_buffer_);
  visitor->Trace(array_buffer_view_);
  visitor->Trace(blob_);
  visitor->Trace(form_data_);
  visitor->Trace(url_search_params_);
}

void V8BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString& impl,
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

  if (V8URLSearchParams::HasInstance(v8_value, isolate)) {
    URLSearchParams* cpp_value = V8URLSearchParams::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetURLSearchParams(cpp_value);
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

  {
    V8StringResource<> cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetUSVString(cpp_value);
    return;
  }
}

v8::Local<v8::Value> ToV8(const BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kNone:
      return v8::Null(isolate);
    case BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kArrayBuffer:
      return ToV8(impl.GetAsArrayBuffer(), creationContext, isolate);
    case BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kArrayBufferView:
      return ToV8(impl.GetAsArrayBufferView(), creationContext, isolate);
    case BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kBlob:
      return ToV8(impl.GetAsBlob(), creationContext, isolate);
    case BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kFormData:
      return ToV8(impl.GetAsFormData(), creationContext, isolate);
    case BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kURLSearchParams:
      return ToV8(impl.GetAsURLSearchParams(), creationContext, isolate);
    case BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kUSVString:
      return V8String(isolate, impl.GetAsUSVString());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString NativeValueTraits<BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString impl;
  V8BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

