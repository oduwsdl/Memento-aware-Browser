// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_PEER_CONNECTION_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_PEER_CONNECTION_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCPeerConnectionState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kNew,
    kConnecting,
    kConnected,
    kDisconnected,
    kFailed,
    kClosed
  };

  static V8RTCPeerConnectionState Create(v8::Isolate* isolate,
                                         v8::Local<v8::Value> value,
                                         ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCPeerConnectionState",
        exception_state);
    return result.has_value()
               ? V8RTCPeerConnectionState(static_cast<Enum>(result.value()))
               : V8RTCPeerConnectionState();
  }
  static base::Optional<V8RTCPeerConnectionState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCPeerConnectionState(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCPeerConnectionState() = default;
  explicit constexpr V8RTCPeerConnectionState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCPeerConnectionState(const V8RTCPeerConnectionState&) = default;
  constexpr V8RTCPeerConnectionState(V8RTCPeerConnectionState&&) = default;
  ~V8RTCPeerConnectionState() = default;

  V8RTCPeerConnectionState& operator=(const V8RTCPeerConnectionState&) =
      default;
  V8RTCPeerConnectionState& operator=(V8RTCPeerConnectionState&&) = default;
  V8RTCPeerConnectionState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "new", "connecting", "connected", "disconnected", "failed", "closed"};
};

inline bool operator==(const V8RTCPeerConnectionState& lhs,
                       V8RTCPeerConnectionState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCPeerConnectionState::Enum lhs,
                       const V8RTCPeerConnectionState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_PEER_CONNECTION_STATE_H_
