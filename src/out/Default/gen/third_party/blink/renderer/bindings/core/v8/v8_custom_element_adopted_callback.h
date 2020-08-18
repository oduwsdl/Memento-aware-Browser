// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/callback_function.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CUSTOM_ELEMENT_ADOPTED_CALLBACK_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CUSTOM_ELEMENT_ADOPTED_CALLBACK_H_

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/callback_function_base.h"
#include "third_party/blink/renderer/platform/bindings/v8_value_or_script_wrappable_adapter.h"
#include "third_party/blink/renderer/platform/wtf/forward.h"

namespace blink {

class Document;

class CORE_EXPORT V8CustomElementAdoptedCallback final : public CallbackFunctionBase {
 public:
  static V8CustomElementAdoptedCallback* Create(v8::Local<v8::Function> callback_function) {
    return MakeGarbageCollected<V8CustomElementAdoptedCallback>(callback_function);
  }

  explicit V8CustomElementAdoptedCallback(v8::Local<v8::Function> callback_function)
      : CallbackFunctionBase(callback_function) {}
  ~V8CustomElementAdoptedCallback() override = default;

  // NameClient overrides:
  const char* NameInHeapSnapshot() const override;

  // Performs "invoke".
  // https://heycam.github.io/webidl/#es-invoking-callback-functions
  v8::Maybe<void> Invoke(bindings::V8ValueOrScriptWrappableAdapter callback_this_value, Document* oldOwner, Document* newOwner) WARN_UNUSED_RESULT;

  // Performs "invoke", and then reports an exception, if any, to the global
  // error handler such as DevTools' console.
  void InvokeAndReportException(bindings::V8ValueOrScriptWrappableAdapter callback_this_value, Document* oldOwner, Document* newOwner);
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CUSTOM_ELEMENT_ADOPTED_CALLBACK_H_
