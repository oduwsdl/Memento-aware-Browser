// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_TRANSPORT_POLICY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_TRANSPORT_POLICY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCIceTransportPolicy final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kRelay, kAll };

  static V8RTCIceTransportPolicy Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCIceTransportPolicy",
        exception_state);
    return result.has_value()
               ? V8RTCIceTransportPolicy(static_cast<Enum>(result.value()))
               : V8RTCIceTransportPolicy();
  }
  static base::Optional<V8RTCIceTransportPolicy> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCIceTransportPolicy(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCIceTransportPolicy() = default;
  explicit constexpr V8RTCIceTransportPolicy(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCIceTransportPolicy(const V8RTCIceTransportPolicy&) = default;
  constexpr V8RTCIceTransportPolicy(V8RTCIceTransportPolicy&&) = default;
  ~V8RTCIceTransportPolicy() = default;

  V8RTCIceTransportPolicy& operator=(const V8RTCIceTransportPolicy&) = default;
  V8RTCIceTransportPolicy& operator=(V8RTCIceTransportPolicy&&) = default;
  V8RTCIceTransportPolicy& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"relay", "all"};
};

inline bool operator==(const V8RTCIceTransportPolicy& lhs,
                       V8RTCIceTransportPolicy::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCIceTransportPolicy::Enum lhs,
                       const V8RTCIceTransportPolicy& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_TRANSPORT_POLICY_H_
