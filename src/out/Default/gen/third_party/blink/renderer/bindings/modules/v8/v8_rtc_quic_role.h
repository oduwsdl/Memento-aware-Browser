// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_QUIC_ROLE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_QUIC_ROLE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCQuicRole final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAuto, kClient, kServer };

  static V8RTCQuicRole Create(v8::Isolate* isolate,
                              v8::Local<v8::Value> value,
                              ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCQuicRole", exception_state);
    return result.has_value() ? V8RTCQuicRole(static_cast<Enum>(result.value()))
                              : V8RTCQuicRole();
  }
  static base::Optional<V8RTCQuicRole> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCQuicRole(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCQuicRole() = default;
  explicit constexpr V8RTCQuicRole(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCQuicRole(const V8RTCQuicRole&) = default;
  constexpr V8RTCQuicRole(V8RTCQuicRole&&) = default;
  ~V8RTCQuicRole() = default;

  V8RTCQuicRole& operator=(const V8RTCQuicRole&) = default;
  V8RTCQuicRole& operator=(V8RTCQuicRole&&) = default;
  V8RTCQuicRole& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"auto", "client",
                                                        "server"};
};

inline bool operator==(const V8RTCQuicRole& lhs, V8RTCQuicRole::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCQuicRole::Enum lhs, const V8RTCQuicRole& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_QUIC_ROLE_H_
