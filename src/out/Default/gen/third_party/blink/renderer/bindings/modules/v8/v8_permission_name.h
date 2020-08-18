// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PERMISSION_NAME_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PERMISSION_NAME_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8PermissionName final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kGeolocation,
    kNotifications,
    kPush,
    kMidi,
    kCamera,
    kMicrophone,
    kBackgroundFetch,
    kBackgroundSync,
    kPersistentStorage,
    kAmbientLightSensor,
    kAccelerometer,
    kGyroscope,
    kMagnetometer,
    kScreenWakeLock,
    kNfc,
    kAccessibilityEvents,
    kClipboardRead,
    kClipboardWrite,
    kPaymentHandler,
    kIdleDetection,
    kPeriodicBackgroundSync,
    kSystemWakeLock,
    kStorageAccess,
    kWindowPlacement
  };

  static V8PermissionName Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "PermissionName", exception_state);
    return result.has_value()
               ? V8PermissionName(static_cast<Enum>(result.value()))
               : V8PermissionName();
  }
  static base::Optional<V8PermissionName> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8PermissionName(static_cast<Enum>(result.value()));
  }

  constexpr V8PermissionName() = default;
  explicit constexpr V8PermissionName(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8PermissionName(const V8PermissionName&) = default;
  constexpr V8PermissionName(V8PermissionName&&) = default;
  ~V8PermissionName() = default;

  V8PermissionName& operator=(const V8PermissionName&) = default;
  V8PermissionName& operator=(V8PermissionName&&) = default;
  V8PermissionName& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "geolocation",
      "notifications",
      "push",
      "midi",
      "camera",
      "microphone",
      "background-fetch",
      "background-sync",
      "persistent-storage",
      "ambient-light-sensor",
      "accelerometer",
      "gyroscope",
      "magnetometer",
      "screen-wake-lock",
      "nfc",
      "accessibility-events",
      "clipboard-read",
      "clipboard-write",
      "payment-handler",
      "idle-detection",
      "periodic-background-sync",
      "system-wake-lock",
      "storage-access",
      "window-placement"};
};

inline bool operator==(const V8PermissionName& lhs,
                       V8PermissionName::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8PermissionName::Enum lhs,
                       const V8PermissionName& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PERMISSION_NAME_H_
