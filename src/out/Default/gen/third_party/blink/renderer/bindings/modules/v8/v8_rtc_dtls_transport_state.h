// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_DTLS_TRANSPORT_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_DTLS_TRANSPORT_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCDtlsTransportState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kNew,
    kConnecting,
    kConnected,
    kClosed,
    kFailed
  };

  static V8RTCDtlsTransportState Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCDtlsTransportState",
        exception_state);
    return result.has_value()
               ? V8RTCDtlsTransportState(static_cast<Enum>(result.value()))
               : V8RTCDtlsTransportState();
  }
  static base::Optional<V8RTCDtlsTransportState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCDtlsTransportState(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCDtlsTransportState() = default;
  explicit constexpr V8RTCDtlsTransportState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCDtlsTransportState(const V8RTCDtlsTransportState&) = default;
  constexpr V8RTCDtlsTransportState(V8RTCDtlsTransportState&&) = default;
  ~V8RTCDtlsTransportState() = default;

  V8RTCDtlsTransportState& operator=(const V8RTCDtlsTransportState&) = default;
  V8RTCDtlsTransportState& operator=(V8RTCDtlsTransportState&&) = default;
  V8RTCDtlsTransportState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "new", "connecting", "connected", "closed", "failed"};
};

inline bool operator==(const V8RTCDtlsTransportState& lhs,
                       V8RTCDtlsTransportState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCDtlsTransportState::Enum lhs,
                       const V8RTCDtlsTransportState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_DTLS_TRANSPORT_STATE_H_
