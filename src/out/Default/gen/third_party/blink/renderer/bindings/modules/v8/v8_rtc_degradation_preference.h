// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_DEGRADATION_PREFERENCE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_DEGRADATION_PREFERENCE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCDegradationPreference final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kMaintainFramerate,
    kMaintainResolution,
    kBalanced
  };

  static V8RTCDegradationPreference Create(v8::Isolate* isolate,
                                           v8::Local<v8::Value> value,
                                           ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCDegradationPreference",
        exception_state);
    return result.has_value()
               ? V8RTCDegradationPreference(static_cast<Enum>(result.value()))
               : V8RTCDegradationPreference();
  }
  static base::Optional<V8RTCDegradationPreference> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCDegradationPreference(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCDegradationPreference() = default;
  explicit constexpr V8RTCDegradationPreference(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCDegradationPreference(const V8RTCDegradationPreference&) =
      default;
  constexpr V8RTCDegradationPreference(V8RTCDegradationPreference&&) = default;
  ~V8RTCDegradationPreference() = default;

  V8RTCDegradationPreference& operator=(const V8RTCDegradationPreference&) =
      default;
  V8RTCDegradationPreference& operator=(V8RTCDegradationPreference&&) = default;
  V8RTCDegradationPreference& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "maintain-framerate", "maintain-resolution", "balanced"};
};

inline bool operator==(const V8RTCDegradationPreference& lhs,
                       V8RTCDegradationPreference::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCDegradationPreference::Enum lhs,
                       const V8RTCDegradationPreference& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_DEGRADATION_PREFERENCE_H_
