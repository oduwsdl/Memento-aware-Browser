// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_QUIC_STREAM_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_QUIC_STREAM_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCQuicStreamState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNew, kOpening, kOpen, kClosing, kClosed };

  static V8RTCQuicStreamState Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCQuicStreamState", exception_state);
    return result.has_value()
               ? V8RTCQuicStreamState(static_cast<Enum>(result.value()))
               : V8RTCQuicStreamState();
  }
  static base::Optional<V8RTCQuicStreamState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCQuicStreamState(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCQuicStreamState() = default;
  explicit constexpr V8RTCQuicStreamState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCQuicStreamState(const V8RTCQuicStreamState&) = default;
  constexpr V8RTCQuicStreamState(V8RTCQuicStreamState&&) = default;
  ~V8RTCQuicStreamState() = default;

  V8RTCQuicStreamState& operator=(const V8RTCQuicStreamState&) = default;
  V8RTCQuicStreamState& operator=(V8RTCQuicStreamState&&) = default;
  V8RTCQuicStreamState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "new", "opening", "open", "closing", "closed"};
};

inline bool operator==(const V8RTCQuicStreamState& lhs,
                       V8RTCQuicStreamState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCQuicStreamState::Enum lhs,
                       const V8RTCQuicStreamState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_QUIC_STREAM_STATE_H_
