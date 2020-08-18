// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_REQUEST_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_REQUEST_EVENT_INIT_H_

#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/service_worker/extendable_event_init.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class PaymentMethodData;
class PaymentDetailsModifier;
class PaymentShippingOption;
class PaymentOptions;
class PaymentCurrencyAmount;

class MODULES_EXPORT PaymentRequestEventInit : public ExtendableEventInit {
 public:
  static PaymentRequestEventInit* Create() { return MakeGarbageCollected<PaymentRequestEventInit>(); }
  static PaymentRequestEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<PaymentRequestEventInit>();
  }

  PaymentRequestEventInit();
  virtual ~PaymentRequestEventInit();

  bool hasInstrumentKey() const { return !instrument_key_.IsNull(); }
  const String& instrumentKey() const {
    return instrument_key_;
  }
  inline void setInstrumentKey(const String&);

  bool hasMethodData() const { return has_method_data_; }
  const HeapVector<Member<PaymentMethodData>>& methodData() const {
    DCHECK(has_method_data_);
    return method_data_;
  }
  void setMethodData(const HeapVector<Member<PaymentMethodData>>&);

  bool hasModifiers() const { return has_modifiers_; }
  const HeapVector<Member<PaymentDetailsModifier>>& modifiers() const {
    DCHECK(has_modifiers_);
    return modifiers_;
  }
  void setModifiers(const HeapVector<Member<PaymentDetailsModifier>>&);

  bool hasPaymentOptions() const { return !!payment_options_; }
  PaymentOptions* paymentOptions() const {
    return payment_options_;
  }
  void setPaymentOptions(PaymentOptions*);

  bool hasPaymentRequestId() const { return !payment_request_id_.IsNull(); }
  const String& paymentRequestId() const {
    return payment_request_id_;
  }
  inline void setPaymentRequestId(const String&);

  bool hasPaymentRequestOrigin() const { return !payment_request_origin_.IsNull(); }
  const String& paymentRequestOrigin() const {
    return payment_request_origin_;
  }
  inline void setPaymentRequestOrigin(const String&);

  bool hasShippingOptions() const { return has_shipping_options_; }
  const HeapVector<Member<PaymentShippingOption>>& shippingOptions() const {
    DCHECK(has_shipping_options_);
    return shipping_options_;
  }
  void setShippingOptions(const HeapVector<Member<PaymentShippingOption>>&);

  bool hasTopOrigin() const { return !top_origin_.IsNull(); }
  const String& topOrigin() const {
    return top_origin_;
  }
  inline void setTopOrigin(const String&);

  bool hasTotal() const { return !!total_; }
  PaymentCurrencyAmount* total() const {
    return total_;
  }
  void setTotal(PaymentCurrencyAmount*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_method_data_ = false;
  bool has_modifiers_ = false;
  bool has_shipping_options_ = false;

  String instrument_key_;
  HeapVector<Member<PaymentMethodData>> method_data_;
  HeapVector<Member<PaymentDetailsModifier>> modifiers_;
  Member<PaymentOptions> payment_options_;
  String payment_request_id_;
  String payment_request_origin_;
  HeapVector<Member<PaymentShippingOption>> shipping_options_;
  String top_origin_;
  Member<PaymentCurrencyAmount> total_;

  friend class V8PaymentRequestEventInit;
};

void PaymentRequestEventInit::setInstrumentKey(const String& value) {
  instrument_key_ = value;
}

void PaymentRequestEventInit::setPaymentRequestId(const String& value) {
  payment_request_id_ = value;
}

void PaymentRequestEventInit::setPaymentRequestOrigin(const String& value) {
  payment_request_origin_ = value;
}

void PaymentRequestEventInit::setTopOrigin(const String& value) {
  top_origin_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_REQUEST_EVENT_INIT_H_
