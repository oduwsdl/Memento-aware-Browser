// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_OPERATION_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_OPERATION_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8OperationType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kTokenRequest, kSendSrr, kSrrTokenRedemption };

  static V8OperationType Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "OperationType", exception_state);
    return result.has_value()
               ? V8OperationType(static_cast<Enum>(result.value()))
               : V8OperationType();
  }
  static base::Optional<V8OperationType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8OperationType(static_cast<Enum>(result.value()));
  }

  constexpr V8OperationType() = default;
  explicit constexpr V8OperationType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8OperationType(const V8OperationType&) = default;
  constexpr V8OperationType(V8OperationType&&) = default;
  ~V8OperationType() = default;

  V8OperationType& operator=(const V8OperationType&) = default;
  V8OperationType& operator=(V8OperationType&&) = default;
  V8OperationType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "token-request", "send-srr", "srr-token-redemption"};
};

inline bool operator==(const V8OperationType& lhs, V8OperationType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8OperationType::Enum lhs, const V8OperationType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_OPERATION_TYPE_H_
