// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_ATTESTATION_CONVEYANCE_PREFERENCE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_ATTESTATION_CONVEYANCE_PREFERENCE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8AttestationConveyancePreference final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kIndirect, kDirect, kEnterprise };

  static V8AttestationConveyancePreference Create(
      v8::Isolate* isolate,
      v8::Local<v8::Value> value,
      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "AttestationConveyancePreference",
        exception_state);
    return result.has_value() ? V8AttestationConveyancePreference(
                                    static_cast<Enum>(result.value()))
                              : V8AttestationConveyancePreference();
  }
  static base::Optional<V8AttestationConveyancePreference> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8AttestationConveyancePreference(static_cast<Enum>(result.value()));
  }

  constexpr V8AttestationConveyancePreference() = default;
  explicit constexpr V8AttestationConveyancePreference(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8AttestationConveyancePreference(
      const V8AttestationConveyancePreference&) = default;
  constexpr V8AttestationConveyancePreference(
      V8AttestationConveyancePreference&&) = default;
  ~V8AttestationConveyancePreference() = default;

  V8AttestationConveyancePreference& operator=(
      const V8AttestationConveyancePreference&) = default;
  V8AttestationConveyancePreference& operator=(
      V8AttestationConveyancePreference&&) = default;
  V8AttestationConveyancePreference& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "indirect",
                                                        "direct", "enterprise"};
};

inline bool operator==(const V8AttestationConveyancePreference& lhs,
                       V8AttestationConveyancePreference::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8AttestationConveyancePreference::Enum lhs,
                       const V8AttestationConveyancePreference& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_ATTESTATION_CONVEYANCE_PREFERENCE_H_
