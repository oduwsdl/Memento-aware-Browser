// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/array_buffer_or_array_buffer_view_or_blob_or_usv_string_or_write_params.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_blob.h"

namespace blink {

ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams() : type_(SpecificType::kNone) {}

DOMArrayBuffer* ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::GetAsArrayBuffer() const {
  DCHECK(IsArrayBuffer());
  return array_buffer_;
}

void ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::SetArrayBuffer(DOMArrayBuffer* value) {
  DCHECK(IsNull());
  array_buffer_ = value;
  type_ = SpecificType::kArrayBuffer;
}

ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::FromArrayBuffer(DOMArrayBuffer* value) {
  ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams container;
  container.SetArrayBuffer(value);
  return container;
}

NotShared<DOMArrayBufferView> ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::GetAsArrayBufferView() const {
  DCHECK(IsArrayBufferView());
  return array_buffer_view_;
}

void ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::SetArrayBufferView(NotShared<DOMArrayBufferView> value) {
  DCHECK(IsNull());
  array_buffer_view_ = value;
  type_ = SpecificType::kArrayBufferView;
}

ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::FromArrayBufferView(NotShared<DOMArrayBufferView> value) {
  ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams container;
  container.SetArrayBufferView(value);
  return container;
}

Blob* ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::GetAsBlob() const {
  DCHECK(IsBlob());
  return blob_;
}

void ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::SetBlob(Blob* value) {
  DCHECK(IsNull());
  blob_ = value;
  type_ = SpecificType::kBlob;
}

ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::FromBlob(Blob* value) {
  ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams container;
  container.SetBlob(value);
  return container;
}

const String& ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::GetAsUSVString() const {
  DCHECK(IsUSVString());
  return usv_string_;
}

void ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::SetUSVString(const String& value) {
  DCHECK(IsNull());
  usv_string_ = value;
  type_ = SpecificType::kUSVString;
}

ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::FromUSVString(const String& value) {
  ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams container;
  container.SetUSVString(value);
  return container;
}

WriteParams* ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::GetAsWriteParams() const {
  DCHECK(IsWriteParams());
  return write_params_;
}

void ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::SetWriteParams(WriteParams* value) {
  DCHECK(IsNull());
  write_params_ = value;
  type_ = SpecificType::kWriteParams;
}

ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::FromWriteParams(WriteParams* value) {
  ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams container;
  container.SetWriteParams(value);
  return container;
}

ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams(const ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams&) = default;
ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::~ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams() = default;
ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams& ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::operator=(const ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams&) = default;

void ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::Trace(Visitor* visitor) const {
  visitor->Trace(array_buffer_);
  visitor->Trace(array_buffer_view_);
  visitor->Trace(blob_);
  visitor->Trace(write_params_);
}

void V8ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (IsUndefinedOrNull(v8_value)) {
    WriteParams* cpp_value = NativeValueTraits<WriteParams>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetWriteParams(cpp_value);
    return;
  }

  if (V8Blob::HasInstance(v8_value, isolate)) {
    Blob* cpp_value = V8Blob::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetBlob(cpp_value);
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
    WriteParams* cpp_value = NativeValueTraits<WriteParams>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetWriteParams(cpp_value);
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

v8::Local<v8::Value> ToV8(const ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::SpecificType::kNone:
      return v8::Null(isolate);
    case ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::SpecificType::kArrayBuffer:
      return ToV8(impl.GetAsArrayBuffer(), creationContext, isolate);
    case ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::SpecificType::kArrayBufferView:
      return ToV8(impl.GetAsArrayBufferView(), creationContext, isolate);
    case ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::SpecificType::kBlob:
      return ToV8(impl.GetAsBlob(), creationContext, isolate);
    case ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::SpecificType::kUSVString:
      return V8String(isolate, impl.GetAsUSVString());
    case ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::SpecificType::kWriteParams:
      return ToV8(impl.GetAsWriteParams(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams NativeValueTraits<ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams impl;
  V8ArrayBufferOrArrayBufferViewOrBlobOrUSVStringOrWriteParams::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

