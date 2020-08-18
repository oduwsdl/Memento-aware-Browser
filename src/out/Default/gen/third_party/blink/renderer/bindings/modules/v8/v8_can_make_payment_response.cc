// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_can_make_payment_response.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8CanMakePaymentResponseKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "accountBalance",
    "canMakePayment",
    "readyForMinimalUI",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8CanMakePaymentResponse::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, CanMakePaymentResponse* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8CanMakePaymentResponseKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> account_balance_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&account_balance_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (account_balance_value.IsEmpty() || account_balance_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> account_balance_cpp_value = account_balance_value;
    if (!account_balance_cpp_value.Prepare(exception_state))
      return;
    impl->setAccountBalance(account_balance_cpp_value);
  }

  v8::Local<v8::Value> can_make_payment_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&can_make_payment_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (can_make_payment_value.IsEmpty() || can_make_payment_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool can_make_payment_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, can_make_payment_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setCanMakePayment(can_make_payment_cpp_value);
  }

  v8::Local<v8::Value> ready_for_minimal_ui_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&ready_for_minimal_ui_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (ready_for_minimal_ui_value.IsEmpty() || ready_for_minimal_ui_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool ready_for_minimal_ui_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, ready_for_minimal_ui_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setReadyForMinimalUI(ready_for_minimal_ui_cpp_value);
  }
}

v8::Local<v8::Value> CanMakePaymentResponse::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8CanMakePaymentResponse(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8CanMakePaymentResponse(const CanMakePaymentResponse* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8CanMakePaymentResponseKeys(isolate).data();
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  auto create_property = [dictionary, context, keys, isolate](
                             size_t key_index, v8::Local<v8::Value> value) {
    bool added_property;
    v8::Local<v8::Name> key = keys[key_index].Get(isolate);
    if (!dictionary->CreateDataProperty(context, key, value)
             .To(&added_property)) {
      return false;
    }
    return added_property;
  };

  v8::Local<v8::Value> account_balance_value;
  bool account_balance_has_value_or_default = false;
  if (impl->hasAccountBalance()) {
    account_balance_value = V8String(isolate, impl->accountBalance());
    account_balance_has_value_or_default = true;
  }
  if (account_balance_has_value_or_default &&
      !create_property(0, account_balance_value)) {
    return false;
  }

  v8::Local<v8::Value> can_make_payment_value;
  bool can_make_payment_has_value_or_default = false;
  if (impl->hasCanMakePayment()) {
    can_make_payment_value = v8::Boolean::New(isolate, impl->canMakePayment());
    can_make_payment_has_value_or_default = true;
  }
  if (can_make_payment_has_value_or_default &&
      !create_property(1, can_make_payment_value)) {
    return false;
  }

  v8::Local<v8::Value> ready_for_minimal_ui_value;
  bool ready_for_minimal_ui_has_value_or_default = false;
  if (impl->hasReadyForMinimalUI()) {
    ready_for_minimal_ui_value = v8::Boolean::New(isolate, impl->readyForMinimalUI());
    ready_for_minimal_ui_has_value_or_default = true;
  }
  if (ready_for_minimal_ui_has_value_or_default &&
      !create_property(2, ready_for_minimal_ui_value)) {
    return false;
  }

  return true;
}

CanMakePaymentResponse* NativeValueTraits<CanMakePaymentResponse>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  CanMakePaymentResponse* impl = MakeGarbageCollected<CanMakePaymentResponse>();
  V8CanMakePaymentResponse::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
