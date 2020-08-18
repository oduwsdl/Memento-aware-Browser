// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_ARRAY_BUFFER_OR_ARRAY_BUFFER_VIEW_OR_JSON_WEB_KEY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_ARRAY_BUFFER_OR_ARRAY_BUFFER_VIEW_OR_JSON_WEB_KEY_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_json_web_key.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/flexible_array_buffer_view.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class DOMArrayBuffer;

class MODULES_EXPORT ArrayBufferOrArrayBufferViewOrJsonWebKey final {
  DISALLOW_NEW();
 public:
  ArrayBufferOrArrayBufferViewOrJsonWebKey();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsArrayBuffer() const { return type_ == SpecificType::kArrayBuffer; }
  DOMArrayBuffer* GetAsArrayBuffer() const;
  void SetArrayBuffer(DOMArrayBuffer*);
  static ArrayBufferOrArrayBufferViewOrJsonWebKey FromArrayBuffer(DOMArrayBuffer*);

  bool IsArrayBufferView() const { return type_ == SpecificType::kArrayBufferView; }
  NotShared<DOMArrayBufferView> GetAsArrayBufferView() const;
  void SetArrayBufferView(NotShared<DOMArrayBufferView>);
  static ArrayBufferOrArrayBufferViewOrJsonWebKey FromArrayBufferView(NotShared<DOMArrayBufferView>);

  bool IsJsonWebKey() const { return type_ == SpecificType::kJsonWebKey; }
  JsonWebKey* GetAsJsonWebKey() const;
  void SetJsonWebKey(JsonWebKey*);
  static ArrayBufferOrArrayBufferViewOrJsonWebKey FromJsonWebKey(JsonWebKey*);

  ArrayBufferOrArrayBufferViewOrJsonWebKey(const ArrayBufferOrArrayBufferViewOrJsonWebKey&);
  ~ArrayBufferOrArrayBufferViewOrJsonWebKey();
  ArrayBufferOrArrayBufferViewOrJsonWebKey& operator=(const ArrayBufferOrArrayBufferViewOrJsonWebKey&);
  void Trace(Visitor*) const;

 private:
  enum class SpecificType {
    kNone,
    kArrayBuffer,
    kArrayBufferView,
    kJsonWebKey,
  };
  SpecificType type_;

  Member<DOMArrayBuffer> array_buffer_;
  NotShared<DOMArrayBufferView> array_buffer_view_;
  Member<JsonWebKey> json_web_key_;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const ArrayBufferOrArrayBufferViewOrJsonWebKey&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8ArrayBufferOrArrayBufferViewOrJsonWebKey final {
 public:
  MODULES_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, ArrayBufferOrArrayBufferViewOrJsonWebKey&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const ArrayBufferOrArrayBufferViewOrJsonWebKey&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, ArrayBufferOrArrayBufferViewOrJsonWebKey& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, ArrayBufferOrArrayBufferViewOrJsonWebKey& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<ArrayBufferOrArrayBufferViewOrJsonWebKey> : public NativeValueTraitsBase<ArrayBufferOrArrayBufferViewOrJsonWebKey> {
  MODULES_EXPORT static ArrayBufferOrArrayBufferViewOrJsonWebKey NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  MODULES_EXPORT static ArrayBufferOrArrayBufferViewOrJsonWebKey NullValue() { return ArrayBufferOrArrayBufferViewOrJsonWebKey(); }
};

template <>
struct V8TypeOf<ArrayBufferOrArrayBufferViewOrJsonWebKey> {
  typedef V8ArrayBufferOrArrayBufferViewOrJsonWebKey Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::ArrayBufferOrArrayBufferViewOrJsonWebKey)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_ARRAY_BUFFER_OR_ARRAY_BUFFER_VIEW_OR_JSON_WEB_KEY_H_
