// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_STRING_OR_WORKER_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_STRING_OR_WORKER_OPTIONS_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_worker_options.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class CORE_EXPORT StringOrWorkerOptions final {
  DISALLOW_NEW();
 public:
  StringOrWorkerOptions();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsString() const { return type_ == SpecificType::kString; }
  const String& GetAsString() const;
  void SetString(const String&);
  static StringOrWorkerOptions FromString(const String&);

  bool IsWorkerOptions() const { return type_ == SpecificType::kWorkerOptions; }
  WorkerOptions* GetAsWorkerOptions() const;
  void SetWorkerOptions(WorkerOptions*);
  static StringOrWorkerOptions FromWorkerOptions(WorkerOptions*);

  StringOrWorkerOptions(const StringOrWorkerOptions&);
  ~StringOrWorkerOptions();
  StringOrWorkerOptions& operator=(const StringOrWorkerOptions&);
  void Trace(Visitor*) const;

 private:
  enum class SpecificType {
    kNone,
    kString,
    kWorkerOptions,
  };
  SpecificType type_;

  String string_;
  Member<WorkerOptions> worker_options_;

  friend CORE_EXPORT v8::Local<v8::Value> ToV8(const StringOrWorkerOptions&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8StringOrWorkerOptions final {
 public:
  CORE_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, StringOrWorkerOptions&, UnionTypeConversionMode, ExceptionState&);
};

CORE_EXPORT v8::Local<v8::Value> ToV8(const StringOrWorkerOptions&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, StringOrWorkerOptions& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, StringOrWorkerOptions& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<StringOrWorkerOptions> : public NativeValueTraitsBase<StringOrWorkerOptions> {
  CORE_EXPORT static StringOrWorkerOptions NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  CORE_EXPORT static StringOrWorkerOptions NullValue() { return StringOrWorkerOptions(); }
};

template <>
struct V8TypeOf<StringOrWorkerOptions> {
  typedef V8StringOrWorkerOptions Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::StringOrWorkerOptions)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_STRING_OR_WORKER_OPTIONS_H_
