// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_COMPONENT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_COMPONENT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCIceComponent final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kRtp, kRtcp };

  static V8RTCIceComponent Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCIceComponent", exception_state);
    return result.has_value()
               ? V8RTCIceComponent(static_cast<Enum>(result.value()))
               : V8RTCIceComponent();
  }
  static base::Optional<V8RTCIceComponent> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCIceComponent(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCIceComponent() = default;
  explicit constexpr V8RTCIceComponent(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCIceComponent(const V8RTCIceComponent&) = default;
  constexpr V8RTCIceComponent(V8RTCIceComponent&&) = default;
  ~V8RTCIceComponent() = default;

  V8RTCIceComponent& operator=(const V8RTCIceComponent&) = default;
  V8RTCIceComponent& operator=(V8RTCIceComponent&&) = default;
  V8RTCIceComponent& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"rtp", "rtcp"};
};

inline bool operator==(const V8RTCIceComponent& lhs,
                       V8RTCIceComponent::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCIceComponent::Enum lhs,
                       const V8RTCIceComponent& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_COMPONENT_H_
