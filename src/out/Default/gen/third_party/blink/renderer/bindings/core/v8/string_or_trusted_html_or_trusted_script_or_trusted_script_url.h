// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_STRING_OR_TRUSTED_HTML_OR_TRUSTED_SCRIPT_OR_TRUSTED_SCRIPT_URL_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_STRING_OR_TRUSTED_HTML_OR_TRUSTED_SCRIPT_OR_TRUSTED_SCRIPT_URL_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class TrustedHTML;
class TrustedScript;
class TrustedScriptURL;

class CORE_EXPORT StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL final {
  DISALLOW_NEW();
 public:
  StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsString() const { return type_ == SpecificType::kString; }
  const String& GetAsString() const;
  void SetString(const String&);
  static StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL FromString(const String&);

  bool IsTrustedHTML() const { return type_ == SpecificType::kTrustedHTML; }
  TrustedHTML* GetAsTrustedHTML() const;
  void SetTrustedHTML(TrustedHTML*);
  static StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL FromTrustedHTML(TrustedHTML*);

  bool IsTrustedScript() const { return type_ == SpecificType::kTrustedScript; }
  TrustedScript* GetAsTrustedScript() const;
  void SetTrustedScript(TrustedScript*);
  static StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL FromTrustedScript(TrustedScript*);

  bool IsTrustedScriptURL() const { return type_ == SpecificType::kTrustedScriptURL; }
  TrustedScriptURL* GetAsTrustedScriptURL() const;
  void SetTrustedScriptURL(TrustedScriptURL*);
  static StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL FromTrustedScriptURL(TrustedScriptURL*);

  StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL(const StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL&);
  ~StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL();
  StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL& operator=(const StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL&);
  void Trace(Visitor*) const;

 private:
  enum class SpecificType {
    kNone,
    kString,
    kTrustedHTML,
    kTrustedScript,
    kTrustedScriptURL,
  };
  SpecificType type_;

  String string_;
  Member<TrustedHTML> trusted_html_;
  Member<TrustedScript> trusted_script_;
  Member<TrustedScriptURL> trusted_script_url_;

  friend CORE_EXPORT v8::Local<v8::Value> ToV8(const StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL final {
 public:
  CORE_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL&, UnionTypeConversionMode, ExceptionState&);
};

CORE_EXPORT v8::Local<v8::Value> ToV8(const StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL> : public NativeValueTraitsBase<StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL> {
  CORE_EXPORT static StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  CORE_EXPORT static StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL NullValue() { return StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL(); }
};

template <>
struct V8TypeOf<StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL> {
  typedef V8StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::StringOrTrustedHTMLOrTrustedScriptOrTrustedScriptURL)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_STRING_OR_TRUSTED_HTML_OR_TRUSTED_SCRIPT_OR_TRUSTED_SCRIPT_URL_H_
