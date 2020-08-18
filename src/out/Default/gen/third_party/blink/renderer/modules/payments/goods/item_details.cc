// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/payments/goods/item_details.h"

#include "third_party/blink/renderer/modules/payments/payment_currency_amount.h"

namespace blink {

ItemDetails::ItemDetails() {
}

ItemDetails::~ItemDetails() = default;

void ItemDetails::setPrice(PaymentCurrencyAmount* value) {
  price_ = value;
}

void ItemDetails::Trace(Visitor* visitor) const {
  visitor->Trace(price_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
