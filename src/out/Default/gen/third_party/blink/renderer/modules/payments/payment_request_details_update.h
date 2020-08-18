// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_REQUEST_DETAILS_UPDATE_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_REQUEST_DETAILS_UPDATE_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class AddressErrors;
class PaymentDetailsModifier;
class PaymentShippingOption;
class PaymentCurrencyAmount;

class MODULES_EXPORT PaymentRequestDetailsUpdate : public IDLDictionaryBase {
 public:
  static PaymentRequestDetailsUpdate* Create() { return MakeGarbageCollected<PaymentRequestDetailsUpdate>(); }
  static PaymentRequestDetailsUpdate* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<PaymentRequestDetailsUpdate>();
  }

  PaymentRequestDetailsUpdate();
  virtual ~PaymentRequestDetailsUpdate();

  bool hasError() const { return !error_.IsNull(); }
  const String& error() const {
    return error_;
  }
  inline void setError(const String&);

  bool hasModifiers() const { return has_modifiers_; }
  const HeapVector<Member<PaymentDetailsModifier>>& modifiers() const {
    DCHECK(has_modifiers_);
    return modifiers_;
  }
  void setModifiers(const HeapVector<Member<PaymentDetailsModifier>>&);

  bool hasPaymentMethodErrors() const { return !(payment_method_errors_.IsEmpty() || payment_method_errors_.IsNull() || payment_method_errors_.IsUndefined()); }
  ScriptValue paymentMethodErrors() const {
    return payment_method_errors_;
  }
  void setPaymentMethodErrors(ScriptValue);

  bool hasShippingAddressErrors() const { return !!shipping_address_errors_; }
  AddressErrors* shippingAddressErrors() const {
    return shipping_address_errors_;
  }
  void setShippingAddressErrors(AddressErrors*);

  bool hasShippingOptions() const { return has_shipping_options_; }
  const HeapVector<Member<PaymentShippingOption>>& shippingOptions() const {
    DCHECK(has_shipping_options_);
    return shipping_options_;
  }
  void setShippingOptions(const HeapVector<Member<PaymentShippingOption>>&);

  bool hasTotal() const { return !!total_; }
  PaymentCurrencyAmount* total() const {
    return total_;
  }
  void setTotal(PaymentCurrencyAmount*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_modifiers_ = false;
  bool has_shipping_options_ = false;

  String error_;
  HeapVector<Member<PaymentDetailsModifier>> modifiers_;
  ScriptValue payment_method_errors_;
  Member<AddressErrors> shipping_address_errors_;
  HeapVector<Member<PaymentShippingOption>> shipping_options_;
  Member<PaymentCurrencyAmount> total_;

  friend class V8PaymentRequestDetailsUpdate;
};

void PaymentRequestDetailsUpdate::setError(const String& value) {
  error_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_REQUEST_DETAILS_UPDATE_H_
