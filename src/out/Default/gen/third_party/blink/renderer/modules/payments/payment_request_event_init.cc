// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/payments/payment_request_event_init.h"

#include "third_party/blink/renderer/modules/payments/payment_currency_amount.h"
#include "third_party/blink/renderer/modules/payments/payment_details_modifier.h"
#include "third_party/blink/renderer/modules/payments/payment_method_data.h"
#include "third_party/blink/renderer/modules/payments/payment_options.h"
#include "third_party/blink/renderer/modules/payments/payment_shipping_option.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

PaymentRequestEventInit::PaymentRequestEventInit() {
}

PaymentRequestEventInit::~PaymentRequestEventInit() = default;

void PaymentRequestEventInit::setMethodData(const HeapVector<Member<PaymentMethodData>>& value) {
  method_data_ = value;
  has_method_data_ = true;
}

void PaymentRequestEventInit::setModifiers(const HeapVector<Member<PaymentDetailsModifier>>& value) {
  modifiers_ = value;
  has_modifiers_ = true;
}

void PaymentRequestEventInit::setPaymentOptions(PaymentOptions* value) {
  payment_options_ = value;
}

void PaymentRequestEventInit::setShippingOptions(const HeapVector<Member<PaymentShippingOption>>& value) {
  shipping_options_ = value;
  has_shipping_options_ = true;
}

void PaymentRequestEventInit::setTotal(PaymentCurrencyAmount* value) {
  total_ = value;
}

void PaymentRequestEventInit::Trace(Visitor* visitor) const {
  visitor->Trace(method_data_);
  visitor->Trace(modifiers_);
  visitor->Trace(payment_options_);
  visitor->Trace(shipping_options_);
  visitor->Trace(total_);
  ExtendableEventInit::Trace(visitor);
}

}  // namespace blink
