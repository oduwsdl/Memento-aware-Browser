// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/callback_interface.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SQL_STATEMENT_ERROR_CALLBACK_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SQL_STATEMENT_ERROR_CALLBACK_H_

#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/callback_interface_base.h"
#include "third_party/blink/renderer/platform/bindings/v8_value_or_script_wrappable_adapter.h"

namespace blink {

class SQLError;
class SQLTransaction;

class MODULES_EXPORT V8SQLStatementErrorCallback final : public CallbackInterfaceBase {
 public:
  static V8SQLStatementErrorCallback* Create(v8::Local<v8::Object> callback_object) {
    return MakeGarbageCollected<V8SQLStatementErrorCallback>(callback_object);
  }

  explicit V8SQLStatementErrorCallback(v8::Local<v8::Object> callback_object)
      : CallbackInterfaceBase(callback_object,
                              kSingleOperation) {}
  ~V8SQLStatementErrorCallback() override = default;

  // NameClient overrides:
  const char* NameInHeapSnapshot() const override;

  // Performs "call a user object's operation".
  // https://heycam.github.io/webidl/#call-a-user-objects-operation
  v8::Maybe<bool> handleEvent(bindings::V8ValueOrScriptWrappableAdapter callback_this_value, SQLTransaction* transaction, SQLError* error) WARN_UNUSED_RESULT;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SQL_STATEMENT_ERROR_CALLBACK_H_
