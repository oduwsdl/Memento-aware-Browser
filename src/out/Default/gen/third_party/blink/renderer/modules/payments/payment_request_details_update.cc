// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/payments/payment_request_details_update.h"

#include "third_party/blink/renderer/modules/payments/address_errors.h"
#include "third_party/blink/renderer/modules/payments/payment_currency_amount.h"
#include "third_party/blink/renderer/modules/payments/payment_details_modifier.h"
#include "third_party/blink/renderer/modules/payments/payment_shipping_option.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

PaymentRequestDetailsUpdate::PaymentRequestDetailsUpdate() {
}

PaymentRequestDetailsUpdate::~PaymentRequestDetailsUpdate() = default;

void PaymentRequestDetailsUpdate::setModifiers(const HeapVector<Member<PaymentDetailsModifier>>& value) {
  modifiers_ = value;
  has_modifiers_ = true;
}

void PaymentRequestDetailsUpdate::setPaymentMethodErrors(ScriptValue value) {
  payment_method_errors_ = value;
}

void PaymentRequestDetailsUpdate::setShippingAddressErrors(AddressErrors* value) {
  shipping_address_errors_ = value;
}

void PaymentRequestDetailsUpdate::setShippingOptions(const HeapVector<Member<PaymentShippingOption>>& value) {
  shipping_options_ = value;
  has_shipping_options_ = true;
}

void PaymentRequestDetailsUpdate::setTotal(PaymentCurrencyAmount* value) {
  total_ = value;
}

void PaymentRequestDetailsUpdate::Trace(Visitor* visitor) const {
  visitor->Trace(modifiers_);
  visitor->Trace(payment_method_errors_);
  visitor->Trace(shipping_address_errors_);
  visitor->Trace(shipping_options_);
  visitor->Trace(total_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
