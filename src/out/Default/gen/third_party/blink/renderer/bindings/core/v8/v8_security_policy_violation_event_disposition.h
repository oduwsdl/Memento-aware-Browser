// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SECURITY_POLICY_VIOLATION_EVENT_DISPOSITION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SECURITY_POLICY_VIOLATION_EVENT_DISPOSITION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8SecurityPolicyViolationEventDisposition final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kEnforce, kReport };

  static V8SecurityPolicyViolationEventDisposition Create(
      v8::Isolate* isolate,
      v8::Local<v8::Value> value,
      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_,
        "SecurityPolicyViolationEventDisposition", exception_state);
    return result.has_value() ? V8SecurityPolicyViolationEventDisposition(
                                    static_cast<Enum>(result.value()))
                              : V8SecurityPolicyViolationEventDisposition();
  }
  static base::Optional<V8SecurityPolicyViolationEventDisposition> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8SecurityPolicyViolationEventDisposition(
        static_cast<Enum>(result.value()));
  }

  constexpr V8SecurityPolicyViolationEventDisposition() = default;
  explicit constexpr V8SecurityPolicyViolationEventDisposition(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8SecurityPolicyViolationEventDisposition(
      const V8SecurityPolicyViolationEventDisposition&) = default;
  constexpr V8SecurityPolicyViolationEventDisposition(
      V8SecurityPolicyViolationEventDisposition&&) = default;
  ~V8SecurityPolicyViolationEventDisposition() = default;

  V8SecurityPolicyViolationEventDisposition& operator=(
      const V8SecurityPolicyViolationEventDisposition&) = default;
  V8SecurityPolicyViolationEventDisposition& operator=(
      V8SecurityPolicyViolationEventDisposition&&) = default;
  V8SecurityPolicyViolationEventDisposition& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"enforce", "report"};
};

inline bool operator==(const V8SecurityPolicyViolationEventDisposition& lhs,
                       V8SecurityPolicyViolationEventDisposition::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8SecurityPolicyViolationEventDisposition::Enum lhs,
                       const V8SecurityPolicyViolationEventDisposition& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SECURITY_POLICY_VIOLATION_EVENT_DISPOSITION_H_
