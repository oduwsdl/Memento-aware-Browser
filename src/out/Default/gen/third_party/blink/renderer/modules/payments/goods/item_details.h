// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_GOODS_ITEM_DETAILS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_GOODS_ITEM_DETAILS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class PaymentCurrencyAmount;

class MODULES_EXPORT ItemDetails : public IDLDictionaryBase {
 public:
  static ItemDetails* Create() { return MakeGarbageCollected<ItemDetails>(); }
  static ItemDetails* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ItemDetails>();
  }

  ItemDetails();
  virtual ~ItemDetails();

  bool hasDescription() const { return !description_.IsNull(); }
  const String& description() const {
    return description_;
  }
  inline void setDescription(const String&);

  bool hasItemId() const { return !item_id_.IsNull(); }
  const String& itemId() const {
    return item_id_;
  }
  inline void setItemId(const String&);

  bool hasPrice() const { return !!price_; }
  PaymentCurrencyAmount* price() const {
    return price_;
  }
  void setPrice(PaymentCurrencyAmount*);

  bool hasTitle() const { return !title_.IsNull(); }
  const String& title() const {
    return title_;
  }
  inline void setTitle(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  String description_;
  String item_id_;
  Member<PaymentCurrencyAmount> price_;
  String title_;

  friend class V8ItemDetails;
};

void ItemDetails::setDescription(const String& value) {
  description_ = value;
}

void ItemDetails::setItemId(const String& value) {
  item_id_ = value;
}

void ItemDetails::setTitle(const String& value) {
  title_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_GOODS_ITEM_DETAILS_H_
