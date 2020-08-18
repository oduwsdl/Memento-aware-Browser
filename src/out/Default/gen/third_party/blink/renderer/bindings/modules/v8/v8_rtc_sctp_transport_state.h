// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_SCTP_TRANSPORT_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_SCTP_TRANSPORT_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCSctpTransportState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kConnecting, kConnected, kClosed };

  static V8RTCSctpTransportState Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCSctpTransportState",
        exception_state);
    return result.has_value()
               ? V8RTCSctpTransportState(static_cast<Enum>(result.value()))
               : V8RTCSctpTransportState();
  }
  static base::Optional<V8RTCSctpTransportState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCSctpTransportState(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCSctpTransportState() = default;
  explicit constexpr V8RTCSctpTransportState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCSctpTransportState(const V8RTCSctpTransportState&) = default;
  constexpr V8RTCSctpTransportState(V8RTCSctpTransportState&&) = default;
  ~V8RTCSctpTransportState() = default;

  V8RTCSctpTransportState& operator=(const V8RTCSctpTransportState&) = default;
  V8RTCSctpTransportState& operator=(V8RTCSctpTransportState&&) = default;
  V8RTCSctpTransportState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"connecting",
                                                        "connected", "closed"};
};

inline bool operator==(const V8RTCSctpTransportState& lhs,
                       V8RTCSctpTransportState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCSctpTransportState::Enum lhs,
                       const V8RTCSctpTransportState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_SCTP_TRANSPORT_STATE_H_
