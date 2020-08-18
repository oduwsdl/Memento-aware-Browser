// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PURCHASE_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PURCHASE_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8PurchaseType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kRepeatable, kOnetime };

  static V8PurchaseType Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "PurchaseType", exception_state);
    return result.has_value()
               ? V8PurchaseType(static_cast<Enum>(result.value()))
               : V8PurchaseType();
  }
  static base::Optional<V8PurchaseType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8PurchaseType(static_cast<Enum>(result.value()));
  }

  constexpr V8PurchaseType() = default;
  explicit constexpr V8PurchaseType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8PurchaseType(const V8PurchaseType&) = default;
  constexpr V8PurchaseType(V8PurchaseType&&) = default;
  ~V8PurchaseType() = default;

  V8PurchaseType& operator=(const V8PurchaseType&) = default;
  V8PurchaseType& operator=(V8PurchaseType&&) = default;
  V8PurchaseType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"repeatable",
                                                        "onetime"};
};

inline bool operator==(const V8PurchaseType& lhs, V8PurchaseType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8PurchaseType::Enum lhs, const V8PurchaseType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PURCHASE_TYPE_H_
