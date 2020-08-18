// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/document_or_xml_http_request_body_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_blob.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_document.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_form_data.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_url_search_params.h"
#include "third_party/blink/renderer/core/animation/document_animation.h"
#include "third_party/blink/renderer/core/css/font_face_source.h"
#include "third_party/blink/renderer/core/dom/document_and_element_event_handlers.h"
#include "third_party/blink/renderer/core/dom/document_or_shadow_root.h"
#include "third_party/blink/renderer/core/dom/global_event_handlers.h"
#include "third_party/blink/renderer/core/dom/non_element_parent_node.h"
#include "third_party/blink/renderer/core/dom/parent_node.h"
#include "third_party/blink/renderer/core/fullscreen/document_fullscreen.h"
#include "third_party/blink/renderer/core/svg/svg_document_extensions.h"
#include "third_party/blink/renderer/core/xml/document_xpath_evaluator.h"

namespace blink {

DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString() : type_(SpecificType::kNone) {}

DOMArrayBuffer* DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsArrayBuffer() const {
  DCHECK(IsArrayBuffer());
  return array_buffer_;
}

void DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetArrayBuffer(DOMArrayBuffer* value) {
  DCHECK(IsNull());
  array_buffer_ = value;
  type_ = SpecificType::kArrayBuffer;
}

DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromArrayBuffer(DOMArrayBuffer* value) {
  DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetArrayBuffer(value);
  return container;
}

NotShared<DOMArrayBufferView> DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsArrayBufferView() const {
  DCHECK(IsArrayBufferView());
  return array_buffer_view_;
}

void DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetArrayBufferView(NotShared<DOMArrayBufferView> value) {
  DCHECK(IsNull());
  array_buffer_view_ = value;
  type_ = SpecificType::kArrayBufferView;
}

DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromArrayBufferView(NotShared<DOMArrayBufferView> value) {
  DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetArrayBufferView(value);
  return container;
}

Blob* DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsBlob() const {
  DCHECK(IsBlob());
  return blob_;
}

void DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetBlob(Blob* value) {
  DCHECK(IsNull());
  blob_ = value;
  type_ = SpecificType::kBlob;
}

DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromBlob(Blob* value) {
  DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetBlob(value);
  return container;
}

Document* DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsDocument() const {
  DCHECK(IsDocument());
  return document_;
}

void DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetDocument(Document* value) {
  DCHECK(IsNull());
  document_ = value;
  type_ = SpecificType::kDocument;
}

DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromDocument(Document* value) {
  DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetDocument(value);
  return container;
}

FormData* DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsFormData() const {
  DCHECK(IsFormData());
  return form_data_;
}

void DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetFormData(FormData* value) {
  DCHECK(IsNull());
  form_data_ = value;
  type_ = SpecificType::kFormData;
}

DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromFormData(FormData* value) {
  DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetFormData(value);
  return container;
}

URLSearchParams* DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsURLSearchParams() const {
  DCHECK(IsURLSearchParams());
  return url_search_params_;
}

void DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetURLSearchParams(URLSearchParams* value) {
  DCHECK(IsNull());
  url_search_params_ = value;
  type_ = SpecificType::kURLSearchParams;
}

DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromURLSearchParams(URLSearchParams* value) {
  DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetURLSearchParams(value);
  return container;
}

const String& DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::GetAsUSVString() const {
  DCHECK(IsUSVString());
  return usv_string_;
}

void DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SetUSVString(const String& value) {
  DCHECK(IsNull());
  usv_string_ = value;
  type_ = SpecificType::kUSVString;
}

DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::FromUSVString(const String& value) {
  DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString container;
  container.SetUSVString(value);
  return container;
}

DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString(const DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString&) = default;
DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::~DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString() = default;
DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString& DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::operator=(const DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString&) = default;

void DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::Trace(Visitor* visitor) const {
  visitor->Trace(array_buffer_);
  visitor->Trace(array_buffer_view_);
  visitor->Trace(blob_);
  visitor->Trace(document_);
  visitor->Trace(form_data_);
  visitor->Trace(url_search_params_);
}

void V8DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString& impl,
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

  if (V8Document::HasInstance(v8_value, isolate)) {
    Document* cpp_value = V8Document::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetDocument(cpp_value);
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

v8::Local<v8::Value> ToV8(const DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kNone:
      return v8::Null(isolate);
    case DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kArrayBuffer:
      return ToV8(impl.GetAsArrayBuffer(), creationContext, isolate);
    case DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kArrayBufferView:
      return ToV8(impl.GetAsArrayBufferView(), creationContext, isolate);
    case DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kBlob:
      return ToV8(impl.GetAsBlob(), creationContext, isolate);
    case DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kDocument:
      return ToV8(impl.GetAsDocument(), creationContext, isolate);
    case DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kFormData:
      return ToV8(impl.GetAsFormData(), creationContext, isolate);
    case DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kURLSearchParams:
      return ToV8(impl.GetAsURLSearchParams(), creationContext, isolate);
    case DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::SpecificType::kUSVString:
      return V8String(isolate, impl.GetAsUSVString());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString NativeValueTraits<DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString impl;
  V8DocumentOrBlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

