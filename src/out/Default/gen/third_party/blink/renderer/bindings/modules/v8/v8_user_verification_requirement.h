// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USER_VERIFICATION_REQUIREMENT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USER_VERIFICATION_REQUIREMENT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8UserVerificationRequirement final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kRequired, kPreferred, kDiscouraged };

  static V8UserVerificationRequirement Create(v8::Isolate* isolate,
                                              v8::Local<v8::Value> value,
                                              ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "UserVerificationRequirement",
        exception_state);
    return result.has_value() ? V8UserVerificationRequirement(
                                    static_cast<Enum>(result.value()))
                              : V8UserVerificationRequirement();
  }
  static base::Optional<V8UserVerificationRequirement> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8UserVerificationRequirement(static_cast<Enum>(result.value()));
  }

  constexpr V8UserVerificationRequirement() = default;
  explicit constexpr V8UserVerificationRequirement(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8UserVerificationRequirement(
      const V8UserVerificationRequirement&) = default;
  constexpr V8UserVerificationRequirement(V8UserVerificationRequirement&&) =
      default;
  ~V8UserVerificationRequirement() = default;

  V8UserVerificationRequirement& operator=(
      const V8UserVerificationRequirement&) = default;
  V8UserVerificationRequirement& operator=(V8UserVerificationRequirement&&) =
      default;
  V8UserVerificationRequirement& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"required", "preferred",
                                                        "discouraged"};
};

inline bool operator==(const V8UserVerificationRequirement& lhs,
                       V8UserVerificationRequirement::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8UserVerificationRequirement::Enum lhs,
                       const V8UserVerificationRequirement& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USER_VERIFICATION_REQUIREMENT_H_
