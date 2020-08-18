// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_NOTIFICATION_PERMISSION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_NOTIFICATION_PERMISSION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8NotificationPermission final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kDefault, kDenied, kGranted };

  static V8NotificationPermission Create(v8::Isolate* isolate,
                                         v8::Local<v8::Value> value,
                                         ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "NotificationPermission",
        exception_state);
    return result.has_value()
               ? V8NotificationPermission(static_cast<Enum>(result.value()))
               : V8NotificationPermission();
  }
  static base::Optional<V8NotificationPermission> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8NotificationPermission(static_cast<Enum>(result.value()));
  }

  constexpr V8NotificationPermission() = default;
  explicit constexpr V8NotificationPermission(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8NotificationPermission(const V8NotificationPermission&) = default;
  constexpr V8NotificationPermission(V8NotificationPermission&&) = default;
  ~V8NotificationPermission() = default;

  V8NotificationPermission& operator=(const V8NotificationPermission&) =
      default;
  V8NotificationPermission& operator=(V8NotificationPermission&&) = default;
  V8NotificationPermission& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"default", "denied",
                                                        "granted"};
};

inline bool operator==(const V8NotificationPermission& lhs,
                       V8NotificationPermission::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8NotificationPermission::Enum lhs,
                       const V8NotificationPermission& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_NOTIFICATION_PERMISSION_H_
