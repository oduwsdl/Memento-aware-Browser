// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_ROLE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_ROLE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCIceRole final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kControlling, kControlled };

  static V8RTCIceRole Create(v8::Isolate* isolate,
                             v8::Local<v8::Value> value,
                             ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCIceRole", exception_state);
    return result.has_value() ? V8RTCIceRole(static_cast<Enum>(result.value()))
                              : V8RTCIceRole();
  }
  static base::Optional<V8RTCIceRole> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCIceRole(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCIceRole() = default;
  explicit constexpr V8RTCIceRole(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCIceRole(const V8RTCIceRole&) = default;
  constexpr V8RTCIceRole(V8RTCIceRole&&) = default;
  ~V8RTCIceRole() = default;

  V8RTCIceRole& operator=(const V8RTCIceRole&) = default;
  V8RTCIceRole& operator=(V8RTCIceRole&&) = default;
  V8RTCIceRole& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"controlling",
                                                        "controlled"};
};

inline bool operator==(const V8RTCIceRole& lhs, V8RTCIceRole::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCIceRole::Enum lhs, const V8RTCIceRole& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ICE_ROLE_H_
