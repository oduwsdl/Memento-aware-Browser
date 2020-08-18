// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_QUIC_TRANSPORT_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_QUIC_TRANSPORT_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCQuicTransportState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kNew,
    kConnecting,
    kConnected,
    kClosed,
    kFailed
  };

  static V8RTCQuicTransportState Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCQuicTransportState",
        exception_state);
    return result.has_value()
               ? V8RTCQuicTransportState(static_cast<Enum>(result.value()))
               : V8RTCQuicTransportState();
  }
  static base::Optional<V8RTCQuicTransportState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCQuicTransportState(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCQuicTransportState() = default;
  explicit constexpr V8RTCQuicTransportState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCQuicTransportState(const V8RTCQuicTransportState&) = default;
  constexpr V8RTCQuicTransportState(V8RTCQuicTransportState&&) = default;
  ~V8RTCQuicTransportState() = default;

  V8RTCQuicTransportState& operator=(const V8RTCQuicTransportState&) = default;
  V8RTCQuicTransportState& operator=(V8RTCQuicTransportState&&) = default;
  V8RTCQuicTransportState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "new", "connecting", "connected", "closed", "failed"};
};

inline bool operator==(const V8RTCQuicTransportState& lhs,
                       V8RTCQuicTransportState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCQuicTransportState::Enum lhs,
                       const V8RTCQuicTransportState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_QUIC_TRANSPORT_STATE_H_
