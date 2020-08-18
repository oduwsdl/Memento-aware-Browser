// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PAYMENT_DELEGATION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PAYMENT_DELEGATION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8PaymentDelegation final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kShippingAddress,
    kPayerName,
    kPayerPhone,
    kPayerEmail
  };

  static V8PaymentDelegation Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "PaymentDelegation", exception_state);
    return result.has_value()
               ? V8PaymentDelegation(static_cast<Enum>(result.value()))
               : V8PaymentDelegation();
  }
  static base::Optional<V8PaymentDelegation> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8PaymentDelegation(static_cast<Enum>(result.value()));
  }

  constexpr V8PaymentDelegation() = default;
  explicit constexpr V8PaymentDelegation(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8PaymentDelegation(const V8PaymentDelegation&) = default;
  constexpr V8PaymentDelegation(V8PaymentDelegation&&) = default;
  ~V8PaymentDelegation() = default;

  V8PaymentDelegation& operator=(const V8PaymentDelegation&) = default;
  V8PaymentDelegation& operator=(V8PaymentDelegation&&) = default;
  V8PaymentDelegation& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "shippingAddress", "payerName", "payerPhone", "payerEmail"};
};

inline bool operator==(const V8PaymentDelegation& lhs,
                       V8PaymentDelegation::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8PaymentDelegation::Enum lhs,
                       const V8PaymentDelegation& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PAYMENT_DELEGATION_H_
