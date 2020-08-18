// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PAYMENT_SHIPPING_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PAYMENT_SHIPPING_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8PaymentShippingType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kShipping, kDelivery, kPickup };

  static V8PaymentShippingType Create(v8::Isolate* isolate,
                                      v8::Local<v8::Value> value,
                                      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "PaymentShippingType", exception_state);
    return result.has_value()
               ? V8PaymentShippingType(static_cast<Enum>(result.value()))
               : V8PaymentShippingType();
  }
  static base::Optional<V8PaymentShippingType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8PaymentShippingType(static_cast<Enum>(result.value()));
  }

  constexpr V8PaymentShippingType() = default;
  explicit constexpr V8PaymentShippingType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8PaymentShippingType(const V8PaymentShippingType&) = default;
  constexpr V8PaymentShippingType(V8PaymentShippingType&&) = default;
  ~V8PaymentShippingType() = default;

  V8PaymentShippingType& operator=(const V8PaymentShippingType&) = default;
  V8PaymentShippingType& operator=(V8PaymentShippingType&&) = default;
  V8PaymentShippingType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"shipping", "delivery",
                                                        "pickup"};
};

inline bool operator==(const V8PaymentShippingType& lhs,
                       V8PaymentShippingType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8PaymentShippingType::Enum lhs,
                       const V8PaymentShippingType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PAYMENT_SHIPPING_TYPE_H_
