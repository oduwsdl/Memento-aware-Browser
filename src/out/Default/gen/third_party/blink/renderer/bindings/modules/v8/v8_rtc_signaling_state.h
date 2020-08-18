// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_SIGNALING_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_SIGNALING_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCSignalingState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kStable,
    kHaveLocalOffer,
    kHaveRemoteOffer,
    kHaveLocalPranswer,
    kHaveRemotePranswer,
    kClosed
  };

  static V8RTCSignalingState Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCSignalingState", exception_state);
    return result.has_value()
               ? V8RTCSignalingState(static_cast<Enum>(result.value()))
               : V8RTCSignalingState();
  }
  static base::Optional<V8RTCSignalingState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCSignalingState(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCSignalingState() = default;
  explicit constexpr V8RTCSignalingState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCSignalingState(const V8RTCSignalingState&) = default;
  constexpr V8RTCSignalingState(V8RTCSignalingState&&) = default;
  ~V8RTCSignalingState() = default;

  V8RTCSignalingState& operator=(const V8RTCSignalingState&) = default;
  V8RTCSignalingState& operator=(V8RTCSignalingState&&) = default;
  V8RTCSignalingState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"stable",
                                                        "have-local-offer",
                                                        "have-remote-offer",
                                                        "have-local-pranswer",
                                                        "have-remote-pranswer",
                                                        "closed"};
};

inline bool operator==(const V8RTCSignalingState& lhs,
                       V8RTCSignalingState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCSignalingState::Enum lhs,
                       const V8RTCSignalingState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_SIGNALING_STATE_H_
