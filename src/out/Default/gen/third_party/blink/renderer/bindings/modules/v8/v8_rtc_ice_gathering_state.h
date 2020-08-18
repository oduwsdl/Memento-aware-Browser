// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_GATHERING_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_GATHERING_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCIceGatheringState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNew, kGathering, kComplete };

  static V8RTCIceGatheringState Create(v8::Isolate* isolate,
                                       v8::Local<v8::Value> value,
                                       ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCIceGatheringState", exception_state);
    return result.has_value()
               ? V8RTCIceGatheringState(static_cast<Enum>(result.value()))
               : V8RTCIceGatheringState();
  }
  static base::Optional<V8RTCIceGatheringState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCIceGatheringState(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCIceGatheringState() = default;
  explicit constexpr V8RTCIceGatheringState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCIceGatheringState(const V8RTCIceGatheringState&) = default;
  constexpr V8RTCIceGatheringState(V8RTCIceGatheringState&&) = default;
  ~V8RTCIceGatheringState() = default;

  V8RTCIceGatheringState& operator=(const V8RTCIceGatheringState&) = default;
  V8RTCIceGatheringState& operator=(V8RTCIceGatheringState&&) = default;
  V8RTCIceGatheringState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"new", "gathering",
                                                        "complete"};
};

inline bool operator==(const V8RTCIceGatheringState& lhs,
                       V8RTCIceGatheringState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCIceGatheringState::Enum lhs,
                       const V8RTCIceGatheringState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_GATHERING_STATE_H_
