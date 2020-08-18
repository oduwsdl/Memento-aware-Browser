// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CREDENTIAL_MEDIATION_REQUIREMENT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CREDENTIAL_MEDIATION_REQUIREMENT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8CredentialMediationRequirement final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kSilent, kOptional, kRequired };

  static V8CredentialMediationRequirement Create(
      v8::Isolate* isolate,
      v8::Local<v8::Value> value,
      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "CredentialMediationRequirement",
        exception_state);
    return result.has_value() ? V8CredentialMediationRequirement(
                                    static_cast<Enum>(result.value()))
                              : V8CredentialMediationRequirement();
  }
  static base::Optional<V8CredentialMediationRequirement> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8CredentialMediationRequirement(static_cast<Enum>(result.value()));
  }

  constexpr V8CredentialMediationRequirement() = default;
  explicit constexpr V8CredentialMediationRequirement(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8CredentialMediationRequirement(
      const V8CredentialMediationRequirement&) = default;
  constexpr V8CredentialMediationRequirement(
      V8CredentialMediationRequirement&&) = default;
  ~V8CredentialMediationRequirement() = default;

  V8CredentialMediationRequirement& operator=(
      const V8CredentialMediationRequirement&) = default;
  V8CredentialMediationRequirement& operator=(
      V8CredentialMediationRequirement&&) = default;
  V8CredentialMediationRequirement& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"silent", "optional",
                                                        "required"};
};

inline bool operator==(const V8CredentialMediationRequirement& lhs,
                       V8CredentialMediationRequirement::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8CredentialMediationRequirement::Enum lhs,
                       const V8CredentialMediationRequirement& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CREDENTIAL_MEDIATION_REQUIREMENT_H_
