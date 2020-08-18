// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_NOTIFICATION_DIRECTION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_NOTIFICATION_DIRECTION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8NotificationDirection final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAuto, kLtr, kRtl };

  static V8NotificationDirection Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "NotificationDirection",
        exception_state);
    return result.has_value()
               ? V8NotificationDirection(static_cast<Enum>(result.value()))
               : V8NotificationDirection();
  }
  static base::Optional<V8NotificationDirection> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8NotificationDirection(static_cast<Enum>(result.value()));
  }

  constexpr V8NotificationDirection() = default;
  explicit constexpr V8NotificationDirection(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8NotificationDirection(const V8NotificationDirection&) = default;
  constexpr V8NotificationDirection(V8NotificationDirection&&) = default;
  ~V8NotificationDirection() = default;

  V8NotificationDirection& operator=(const V8NotificationDirection&) = default;
  V8NotificationDirection& operator=(V8NotificationDirection&&) = default;
  V8NotificationDirection& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"auto", "ltr", "rtl"};
};

inline bool operator==(const V8NotificationDirection& lhs,
                       V8NotificationDirection::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8NotificationDirection::Enum lhs,
                       const V8NotificationDirection& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_NOTIFICATION_DIRECTION_H_
