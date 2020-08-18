// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_USV_STRING_OR_UINT_32_ARRAY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_USV_STRING_OR_UINT_32_ARRAY_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_uint32_array.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/flexible_array_buffer_view.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT USVStringOrUint32Array final {
  DISALLOW_NEW();
 public:
  USVStringOrUint32Array();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsUSVString() const { return type_ == SpecificType::kUSVString; }
  const String& GetAsUSVString() const;
  void SetUSVString(const String&);
  static USVStringOrUint32Array FromUSVString(const String&);

  bool IsUint32Array() const { return type_ == SpecificType::kUint32Array; }
  NotShared<DOMUint32Array> GetAsUint32Array() const;
  void SetUint32Array(NotShared<DOMUint32Array>);
  static USVStringOrUint32Array FromUint32Array(NotShared<DOMUint32Array>);

  USVStringOrUint32Array(const USVStringOrUint32Array&);
  ~USVStringOrUint32Array();
  USVStringOrUint32Array& operator=(const USVStringOrUint32Array&);
  void Trace(Visitor*) const;

 private:
  enum class SpecificType {
    kNone,
    kUSVString,
    kUint32Array,
  };
  SpecificType type_;

  String usv_string_;
  NotShared<DOMUint32Array> uint32_array_;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const USVStringOrUint32Array&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8USVStringOrUint32Array final {
 public:
  MODULES_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, USVStringOrUint32Array&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const USVStringOrUint32Array&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, USVStringOrUint32Array& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, USVStringOrUint32Array& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<USVStringOrUint32Array> : public NativeValueTraitsBase<USVStringOrUint32Array> {
  MODULES_EXPORT static USVStringOrUint32Array NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  MODULES_EXPORT static USVStringOrUint32Array NullValue() { return USVStringOrUint32Array(); }
};

template <>
struct V8TypeOf<USVStringOrUint32Array> {
  typedef V8USVStringOrUint32Array Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::USVStringOrUint32Array)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_USV_STRING_OR_UINT_32_ARRAY_H_
