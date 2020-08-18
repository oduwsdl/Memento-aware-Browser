// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PAYMENT_COMPLETE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PAYMENT_COMPLETE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8PaymentComplete final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kFail, kSuccess, kUnknown };

  static V8PaymentComplete Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "PaymentComplete", exception_state);
    return result.has_value()
               ? V8PaymentComplete(static_cast<Enum>(result.value()))
               : V8PaymentComplete();
  }
  static base::Optional<V8PaymentComplete> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8PaymentComplete(static_cast<Enum>(result.value()));
  }

  constexpr V8PaymentComplete() = default;
  explicit constexpr V8PaymentComplete(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8PaymentComplete(const V8PaymentComplete&) = default;
  constexpr V8PaymentComplete(V8PaymentComplete&&) = default;
  ~V8PaymentComplete() = default;

  V8PaymentComplete& operator=(const V8PaymentComplete&) = default;
  V8PaymentComplete& operator=(V8PaymentComplete&&) = default;
  V8PaymentComplete& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"fail", "success",
                                                        "unknown"};
};

inline bool operator==(const V8PaymentComplete& lhs,
                       V8PaymentComplete::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8PaymentComplete::Enum lhs,
                       const V8PaymentComplete& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PAYMENT_COMPLETE_H_
