// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_ARRAY_BUFFER_OR_ARRAY_BUFFER_VIEW_OR_READABLE_STREAM_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_ARRAY_BUFFER_OR_ARRAY_BUFFER_VIEW_OR_READABLE_STREAM_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/flexible_array_buffer_view.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class DOMArrayBuffer;
class ReadableStream;

class MODULES_EXPORT ArrayBufferOrArrayBufferViewOrReadableStream final {
  DISALLOW_NEW();
 public:
  ArrayBufferOrArrayBufferViewOrReadableStream();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsArrayBuffer() const { return type_ == SpecificType::kArrayBuffer; }
  DOMArrayBuffer* GetAsArrayBuffer() const;
  void SetArrayBuffer(DOMArrayBuffer*);
  static ArrayBufferOrArrayBufferViewOrReadableStream FromArrayBuffer(DOMArrayBuffer*);

  bool IsArrayBufferView() const { return type_ == SpecificType::kArrayBufferView; }
  NotShared<DOMArrayBufferView> GetAsArrayBufferView() const;
  void SetArrayBufferView(NotShared<DOMArrayBufferView>);
  static ArrayBufferOrArrayBufferViewOrReadableStream FromArrayBufferView(NotShared<DOMArrayBufferView>);

  bool IsReadableStream() const { return type_ == SpecificType::kReadableStream; }
  ReadableStream* GetAsReadableStream() const;
  void SetReadableStream(ReadableStream*);
  static ArrayBufferOrArrayBufferViewOrReadableStream FromReadableStream(ReadableStream*);

  ArrayBufferOrArrayBufferViewOrReadableStream(const ArrayBufferOrArrayBufferViewOrReadableStream&);
  ~ArrayBufferOrArrayBufferViewOrReadableStream();
  ArrayBufferOrArrayBufferViewOrReadableStream& operator=(const ArrayBufferOrArrayBufferViewOrReadableStream&);
  void Trace(Visitor*) const;

 private:
  enum class SpecificType {
    kNone,
    kArrayBuffer,
    kArrayBufferView,
    kReadableStream,
  };
  SpecificType type_;

  Member<DOMArrayBuffer> array_buffer_;
  NotShared<DOMArrayBufferView> array_buffer_view_;
  Member<ReadableStream> readable_stream_;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const ArrayBufferOrArrayBufferViewOrReadableStream&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8ArrayBufferOrArrayBufferViewOrReadableStream final {
 public:
  MODULES_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, ArrayBufferOrArrayBufferViewOrReadableStream&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const ArrayBufferOrArrayBufferViewOrReadableStream&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, ArrayBufferOrArrayBufferViewOrReadableStream& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, ArrayBufferOrArrayBufferViewOrReadableStream& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<ArrayBufferOrArrayBufferViewOrReadableStream> : public NativeValueTraitsBase<ArrayBufferOrArrayBufferViewOrReadableStream> {
  MODULES_EXPORT static ArrayBufferOrArrayBufferViewOrReadableStream NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  MODULES_EXPORT static ArrayBufferOrArrayBufferViewOrReadableStream NullValue() { return ArrayBufferOrArrayBufferViewOrReadableStream(); }
};

template <>
struct V8TypeOf<ArrayBufferOrArrayBufferViewOrReadableStream> {
  typedef V8ArrayBufferOrArrayBufferViewOrReadableStream Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::ArrayBufferOrArrayBufferViewOrReadableStream)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_ARRAY_BUFFER_OR_ARRAY_BUFFER_VIEW_OR_READABLE_STREAM_H_
