// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_CAN_MAKE_PAYMENT_RESPONSE_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_CAN_MAKE_PAYMENT_RESPONSE_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT CanMakePaymentResponse : public IDLDictionaryBase {
 public:
  static CanMakePaymentResponse* Create() { return MakeGarbageCollected<CanMakePaymentResponse>(); }
  static CanMakePaymentResponse* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<CanMakePaymentResponse>();
  }

  CanMakePaymentResponse();
  virtual ~CanMakePaymentResponse();

  bool hasAccountBalance() const { return !account_balance_.IsNull(); }
  const String& accountBalance() const {
    return account_balance_;
  }
  inline void setAccountBalance(const String&);

  bool hasCanMakePayment() const { return has_can_make_payment_; }
  bool canMakePayment() const {
    DCHECK(has_can_make_payment_);
    return can_make_payment_;
  }
  inline void setCanMakePayment(bool);

  bool hasReadyForMinimalUI() const { return has_ready_for_minimal_ui_; }
  bool readyForMinimalUI() const {
    DCHECK(has_ready_for_minimal_ui_);
    return ready_for_minimal_ui_;
  }
  inline void setReadyForMinimalUI(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_can_make_payment_ = false;
  bool has_ready_for_minimal_ui_ = false;

  String account_balance_;
  bool can_make_payment_;
  bool ready_for_minimal_ui_;

  friend class V8CanMakePaymentResponse;
};

void CanMakePaymentResponse::setAccountBalance(const String& value) {
  account_balance_ = value;
}

void CanMakePaymentResponse::setCanMakePayment(bool value) {
  can_make_payment_ = value;
  has_can_make_payment_ = true;
}

void CanMakePaymentResponse::setReadyForMinimalUI(bool value) {
  ready_for_minimal_ui_ = value;
  has_ready_for_minimal_ui_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_CAN_MAKE_PAYMENT_RESPONSE_H_
