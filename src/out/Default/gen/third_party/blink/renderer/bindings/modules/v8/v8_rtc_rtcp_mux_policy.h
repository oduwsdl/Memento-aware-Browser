// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_RTCP_MUX_POLICY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_RTCP_MUX_POLICY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCRtcpMuxPolicy final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNegotiate, kRequire };

  static V8RTCRtcpMuxPolicy Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCRtcpMuxPolicy", exception_state);
    return result.has_value()
               ? V8RTCRtcpMuxPolicy(static_cast<Enum>(result.value()))
               : V8RTCRtcpMuxPolicy();
  }
  static base::Optional<V8RTCRtcpMuxPolicy> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCRtcpMuxPolicy(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCRtcpMuxPolicy() = default;
  explicit constexpr V8RTCRtcpMuxPolicy(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCRtcpMuxPolicy(const V8RTCRtcpMuxPolicy&) = default;
  constexpr V8RTCRtcpMuxPolicy(V8RTCRtcpMuxPolicy&&) = default;
  ~V8RTCRtcpMuxPolicy() = default;

  V8RTCRtcpMuxPolicy& operator=(const V8RTCRtcpMuxPolicy&) = default;
  V8RTCRtcpMuxPolicy& operator=(V8RTCRtcpMuxPolicy&&) = default;
  V8RTCRtcpMuxPolicy& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"negotiate", "require"};
};

inline bool operator==(const V8RTCRtcpMuxPolicy& lhs,
                       V8RTCRtcpMuxPolicy::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCRtcpMuxPolicy::Enum lhs,
                       const V8RTCRtcpMuxPolicy& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_RTCP_MUX_POLICY_H_
