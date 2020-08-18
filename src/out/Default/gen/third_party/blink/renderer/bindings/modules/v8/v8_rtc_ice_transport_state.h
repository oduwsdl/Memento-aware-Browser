// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_TRANSPORT_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_TRANSPORT_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCIceTransportState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kNew,
    kChecking,
    kConnected,
    kCompleted,
    kDisconnected,
    kFailed,
    kClosed
  };

  static V8RTCIceTransportState Create(v8::Isolate* isolate,
                                       v8::Local<v8::Value> value,
                                       ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCIceTransportState", exception_state);
    return result.has_value()
               ? V8RTCIceTransportState(static_cast<Enum>(result.value()))
               : V8RTCIceTransportState();
  }
  static base::Optional<V8RTCIceTransportState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCIceTransportState(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCIceTransportState() = default;
  explicit constexpr V8RTCIceTransportState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCIceTransportState(const V8RTCIceTransportState&) = default;
  constexpr V8RTCIceTransportState(V8RTCIceTransportState&&) = default;
  ~V8RTCIceTransportState() = default;

  V8RTCIceTransportState& operator=(const V8RTCIceTransportState&) = default;
  V8RTCIceTransportState& operator=(V8RTCIceTransportState&&) = default;
  V8RTCIceTransportState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "new",          "checking", "connected", "completed",
      "disconnected", "failed",   "closed"};
};

inline bool operator==(const V8RTCIceTransportState& lhs,
                       V8RTCIceTransportState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCIceTransportState::Enum lhs,
                       const V8RTCIceTransportState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_TRANSPORT_STATE_H_
