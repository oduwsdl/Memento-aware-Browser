// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_RTP_TRANSCEIVER_DIRECTION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_RTP_TRANSCEIVER_DIRECTION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCRtpTransceiverDirection final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kSendrecv,
    kSendonly,
    kRecvonly,
    kInactive,
    kStopped
  };

  static V8RTCRtpTransceiverDirection Create(v8::Isolate* isolate,
                                             v8::Local<v8::Value> value,
                                             ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCRtpTransceiverDirection",
        exception_state);
    return result.has_value()
               ? V8RTCRtpTransceiverDirection(static_cast<Enum>(result.value()))
               : V8RTCRtpTransceiverDirection();
  }
  static base::Optional<V8RTCRtpTransceiverDirection> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCRtpTransceiverDirection(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCRtpTransceiverDirection() = default;
  explicit constexpr V8RTCRtpTransceiverDirection(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCRtpTransceiverDirection(const V8RTCRtpTransceiverDirection&) =
      default;
  constexpr V8RTCRtpTransceiverDirection(V8RTCRtpTransceiverDirection&&) =
      default;
  ~V8RTCRtpTransceiverDirection() = default;

  V8RTCRtpTransceiverDirection& operator=(const V8RTCRtpTransceiverDirection&) =
      default;
  V8RTCRtpTransceiverDirection& operator=(V8RTCRtpTransceiverDirection&&) =
      default;
  V8RTCRtpTransceiverDirection& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "sendrecv", "sendonly", "recvonly", "inactive", "stopped"};
};

inline bool operator==(const V8RTCRtpTransceiverDirection& lhs,
                       V8RTCRtpTransceiverDirection::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCRtpTransceiverDirection::Enum lhs,
                       const V8RTCRtpTransceiverDirection& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_RTP_TRANSCEIVER_DIRECTION_H_
