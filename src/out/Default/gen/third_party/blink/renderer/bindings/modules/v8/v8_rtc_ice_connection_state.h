// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_CONNECTION_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_CONNECTION_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCIceConnectionState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kNew,
    kChecking,
    kConnected,
    kCompleted,
    kFailed,
    kDisconnected,
    kClosed
  };

  static V8RTCIceConnectionState Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCIceConnectionState",
        exception_state);
    return result.has_value()
               ? V8RTCIceConnectionState(static_cast<Enum>(result.value()))
               : V8RTCIceConnectionState();
  }
  static base::Optional<V8RTCIceConnectionState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCIceConnectionState(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCIceConnectionState() = default;
  explicit constexpr V8RTCIceConnectionState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCIceConnectionState(const V8RTCIceConnectionState&) = default;
  constexpr V8RTCIceConnectionState(V8RTCIceConnectionState&&) = default;
  ~V8RTCIceConnectionState() = default;

  V8RTCIceConnectionState& operator=(const V8RTCIceConnectionState&) = default;
  V8RTCIceConnectionState& operator=(V8RTCIceConnectionState&&) = default;
  V8RTCIceConnectionState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "new",    "checking",     "connected", "completed",
      "failed", "disconnected", "closed"};
};

inline bool operator==(const V8RTCIceConnectionState& lhs,
                       V8RTCIceConnectionState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCIceConnectionState::Enum lhs,
                       const V8RTCIceConnectionState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_CONNECTION_STATE_H_
