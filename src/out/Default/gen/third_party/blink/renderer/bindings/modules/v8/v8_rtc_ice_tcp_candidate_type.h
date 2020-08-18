// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_TCP_CANDIDATE_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_TCP_CANDIDATE_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCIceTcpCandidateType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kActive, kPassive, kSo };

  static V8RTCIceTcpCandidateType Create(v8::Isolate* isolate,
                                         v8::Local<v8::Value> value,
                                         ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCIceTcpCandidateType",
        exception_state);
    return result.has_value()
               ? V8RTCIceTcpCandidateType(static_cast<Enum>(result.value()))
               : V8RTCIceTcpCandidateType();
  }
  static base::Optional<V8RTCIceTcpCandidateType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCIceTcpCandidateType(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCIceTcpCandidateType() = default;
  explicit constexpr V8RTCIceTcpCandidateType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCIceTcpCandidateType(const V8RTCIceTcpCandidateType&) = default;
  constexpr V8RTCIceTcpCandidateType(V8RTCIceTcpCandidateType&&) = default;
  ~V8RTCIceTcpCandidateType() = default;

  V8RTCIceTcpCandidateType& operator=(const V8RTCIceTcpCandidateType&) =
      default;
  V8RTCIceTcpCandidateType& operator=(V8RTCIceTcpCandidateType&&) = default;
  V8RTCIceTcpCandidateType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"active", "passive",
                                                        "so"};
};

inline bool operator==(const V8RTCIceTcpCandidateType& lhs,
                       V8RTCIceTcpCandidateType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCIceTcpCandidateType::Enum lhs,
                       const V8RTCIceTcpCandidateType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_TCP_CANDIDATE_TYPE_H_
