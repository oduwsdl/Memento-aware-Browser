// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_payment_request_details_update.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_address_errors.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_payment_currency_amount.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_payment_details_modifier.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_payment_shipping_option.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8PaymentRequestDetailsUpdateKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "error",
    "modifiers",
    "paymentMethodErrors",
    "shippingAddressErrors",
    "shippingOptions",
    "total",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8PaymentRequestDetailsUpdate::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, PaymentRequestDetailsUpdate* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8PaymentRequestDetailsUpdateKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> error_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&error_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (error_value.IsEmpty() || error_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> error_cpp_value = error_value;
    if (!error_cpp_value.Prepare(exception_state))
      return;
    impl->setError(error_cpp_value);
  }

  v8::Local<v8::Value> modifiers_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&modifiers_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (modifiers_value.IsEmpty() || modifiers_value->IsUndefined()) {
    // Do nothing.
  } else {
    HeapVector<Member<PaymentDetailsModifier>> modifiers_cpp_value = NativeValueTraits<IDLSequence<PaymentDetailsModifier>>::NativeValue(isolate, modifiers_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setModifiers(modifiers_cpp_value);
  }

  v8::Local<v8::Value> payment_method_errors_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&payment_method_errors_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (payment_method_errors_value.IsEmpty() || payment_method_errors_value->IsUndefined()) {
    // Do nothing.
  } else {
    ScriptValue payment_method_errors_cpp_value = NativeValueTraits<IDLObject>::NativeValue(isolate, payment_method_errors_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setPaymentMethodErrors(payment_method_errors_cpp_value);
  }

  v8::Local<v8::Value> shipping_address_errors_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&shipping_address_errors_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (shipping_address_errors_value.IsEmpty() || shipping_address_errors_value->IsUndefined()) {
    // Do nothing.
  } else {
    AddressErrors* shipping_address_errors_cpp_value = NativeValueTraits<AddressErrors>::NativeValue(isolate, shipping_address_errors_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setShippingAddressErrors(shipping_address_errors_cpp_value);
  }

  v8::Local<v8::Value> shipping_options_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&shipping_options_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (shipping_options_value.IsEmpty() || shipping_options_value->IsUndefined()) {
    // Do nothing.
  } else {
    HeapVector<Member<PaymentShippingOption>> shipping_options_cpp_value = NativeValueTraits<IDLSequence<PaymentShippingOption>>::NativeValue(isolate, shipping_options_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setShippingOptions(shipping_options_cpp_value);
  }

  v8::Local<v8::Value> total_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&total_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (total_value.IsEmpty() || total_value->IsUndefined()) {
    // Do nothing.
  } else {
    PaymentCurrencyAmount* total_cpp_value = NativeValueTraits<PaymentCurrencyAmount>::NativeValue(isolate, total_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setTotal(total_cpp_value);
  }
}

v8::Local<v8::Value> PaymentRequestDetailsUpdate::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8PaymentRequestDetailsUpdate(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8PaymentRequestDetailsUpdate(const PaymentRequestDetailsUpdate* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8PaymentRequestDetailsUpdateKeys(isolate).data();
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

  v8::Local<v8::Value> error_value;
  bool error_has_value_or_default = false;
  if (impl->hasError()) {
    error_value = V8String(isolate, impl->error());
    error_has_value_or_default = true;
  }
  if (error_has_value_or_default &&
      !create_property(0, error_value)) {
    return false;
  }

  v8::Local<v8::Value> modifiers_value;
  bool modifiers_has_value_or_default = false;
  if (impl->hasModifiers()) {
    modifiers_value = FreezeV8Object(ToV8(impl->modifiers(), creationContext, isolate), isolate);
    modifiers_has_value_or_default = true;
  }
  if (modifiers_has_value_or_default &&
      !create_property(1, modifiers_value)) {
    return false;
  }

  v8::Local<v8::Value> payment_method_errors_value;
  bool payment_method_errors_has_value_or_default = false;
  if (impl->hasPaymentMethodErrors()) {
    DCHECK(impl->paymentMethodErrors().IsObject());
    payment_method_errors_value = impl->paymentMethodErrors().V8Value();
    payment_method_errors_has_value_or_default = true;
  }
  if (payment_method_errors_has_value_or_default &&
      !create_property(2, payment_method_errors_value)) {
    return false;
  }

  v8::Local<v8::Value> shipping_address_errors_value;
  bool shipping_address_errors_has_value_or_default = false;
  if (impl->hasShippingAddressErrors()) {
    shipping_address_errors_value = ToV8(impl->shippingAddressErrors(), creationContext, isolate);
    shipping_address_errors_has_value_or_default = true;
  }
  if (shipping_address_errors_has_value_or_default &&
      !create_property(3, shipping_address_errors_value)) {
    return false;
  }

  v8::Local<v8::Value> shipping_options_value;
  bool shipping_options_has_value_or_default = false;
  if (impl->hasShippingOptions()) {
    shipping_options_value = FreezeV8Object(ToV8(impl->shippingOptions(), creationContext, isolate), isolate);
    shipping_options_has_value_or_default = true;
  }
  if (shipping_options_has_value_or_default &&
      !create_property(4, shipping_options_value)) {
    return false;
  }

  v8::Local<v8::Value> total_value;
  bool total_has_value_or_default = false;
  if (impl->hasTotal()) {
    total_value = ToV8(impl->total(), creationContext, isolate);
    total_has_value_or_default = true;
  }
  if (total_has_value_or_default &&
      !create_property(5, total_value)) {
    return false;
  }

  return true;
}

PaymentRequestDetailsUpdate* NativeValueTraits<PaymentRequestDetailsUpdate>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  PaymentRequestDetailsUpdate* impl = MakeGarbageCollected<PaymentRequestDetailsUpdate>();
  V8PaymentRequestDetailsUpdate::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
