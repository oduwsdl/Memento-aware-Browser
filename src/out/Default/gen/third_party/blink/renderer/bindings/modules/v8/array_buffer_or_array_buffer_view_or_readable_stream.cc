// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/array_buffer_or_array_buffer_view_or_readable_stream.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_readable_stream.h"

namespace blink {

ArrayBufferOrArrayBufferViewOrReadableStream::ArrayBufferOrArrayBufferViewOrReadableStream() : type_(SpecificType::kNone) {}

DOMArrayBuffer* ArrayBufferOrArrayBufferViewOrReadableStream::GetAsArrayBuffer() const {
  DCHECK(IsArrayBuffer());
  return array_buffer_;
}

void ArrayBufferOrArrayBufferViewOrReadableStream::SetArrayBuffer(DOMArrayBuffer* value) {
  DCHECK(IsNull());
  array_buffer_ = value;
  type_ = SpecificType::kArrayBuffer;
}

ArrayBufferOrArrayBufferViewOrReadableStream ArrayBufferOrArrayBufferViewOrReadableStream::FromArrayBuffer(DOMArrayBuffer* value) {
  ArrayBufferOrArrayBufferViewOrReadableStream container;
  container.SetArrayBuffer(value);
  return container;
}

NotShared<DOMArrayBufferView> ArrayBufferOrArrayBufferViewOrReadableStream::GetAsArrayBufferView() const {
  DCHECK(IsArrayBufferView());
  return array_buffer_view_;
}

void ArrayBufferOrArrayBufferViewOrReadableStream::SetArrayBufferView(NotShared<DOMArrayBufferView> value) {
  DCHECK(IsNull());
  array_buffer_view_ = value;
  type_ = SpecificType::kArrayBufferView;
}

ArrayBufferOrArrayBufferViewOrReadableStream ArrayBufferOrArrayBufferViewOrReadableStream::FromArrayBufferView(NotShared<DOMArrayBufferView> value) {
  ArrayBufferOrArrayBufferViewOrReadableStream container;
  container.SetArrayBufferView(value);
  return container;
}

ReadableStream* ArrayBufferOrArrayBufferViewOrReadableStream::GetAsReadableStream() const {
  DCHECK(IsReadableStream());
  return readable_stream_;
}

void ArrayBufferOrArrayBufferViewOrReadableStream::SetReadableStream(ReadableStream* value) {
  DCHECK(IsNull());
  readable_stream_ = value;
  type_ = SpecificType::kReadableStream;
}

ArrayBufferOrArrayBufferViewOrReadableStream ArrayBufferOrArrayBufferViewOrReadableStream::FromReadableStream(ReadableStream* value) {
  ArrayBufferOrArrayBufferViewOrReadableStream container;
  container.SetReadableStream(value);
  return container;
}

ArrayBufferOrArrayBufferViewOrReadableStream::ArrayBufferOrArrayBufferViewOrReadableStream(const ArrayBufferOrArrayBufferViewOrReadableStream&) = default;
ArrayBufferOrArrayBufferViewOrReadableStream::~ArrayBufferOrArrayBufferViewOrReadableStream() = default;
ArrayBufferOrArrayBufferViewOrReadableStream& ArrayBufferOrArrayBufferViewOrReadableStream::operator=(const ArrayBufferOrArrayBufferViewOrReadableStream&) = default;

void ArrayBufferOrArrayBufferViewOrReadableStream::Trace(Visitor* visitor) const {
  visitor->Trace(array_buffer_);
  visitor->Trace(array_buffer_view_);
  visitor->Trace(readable_stream_);
}

void V8ArrayBufferOrArrayBufferViewOrReadableStream::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    ArrayBufferOrArrayBufferViewOrReadableStream& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (V8ReadableStream::HasInstance(v8_value, isolate)) {
    ReadableStream* cpp_value = V8ReadableStream::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetReadableStream(cpp_value);
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

  exception_state.ThrowTypeError("The provided value is not of type '(ArrayBuffer or ArrayBufferView or ReadableStream)'");
}

v8::Local<v8::Value> ToV8(const ArrayBufferOrArrayBufferViewOrReadableStream& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case ArrayBufferOrArrayBufferViewOrReadableStream::SpecificType::kNone:
      return v8::Null(isolate);
    case ArrayBufferOrArrayBufferViewOrReadableStream::SpecificType::kArrayBuffer:
      return ToV8(impl.GetAsArrayBuffer(), creationContext, isolate);
    case ArrayBufferOrArrayBufferViewOrReadableStream::SpecificType::kArrayBufferView:
      return ToV8(impl.GetAsArrayBufferView(), creationContext, isolate);
    case ArrayBufferOrArrayBufferViewOrReadableStream::SpecificType::kReadableStream:
      return ToV8(impl.GetAsReadableStream(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

ArrayBufferOrArrayBufferViewOrReadableStream NativeValueTraits<ArrayBufferOrArrayBufferViewOrReadableStream>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ArrayBufferOrArrayBufferViewOrReadableStream impl;
  V8ArrayBufferOrArrayBufferViewOrReadableStream::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

