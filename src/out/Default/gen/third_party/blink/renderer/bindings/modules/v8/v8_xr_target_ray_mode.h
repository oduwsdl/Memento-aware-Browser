// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_TARGET_RAY_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_TARGET_RAY_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8XRTargetRayMode final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kGaze, kTrackedPointer, kScreen };

  static V8XRTargetRayMode Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "XRTargetRayMode", exception_state);
    return result.has_value()
               ? V8XRTargetRayMode(static_cast<Enum>(result.value()))
               : V8XRTargetRayMode();
  }
  static base::Optional<V8XRTargetRayMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8XRTargetRayMode(static_cast<Enum>(result.value()));
  }

  constexpr V8XRTargetRayMode() = default;
  explicit constexpr V8XRTargetRayMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8XRTargetRayMode(const V8XRTargetRayMode&) = default;
  constexpr V8XRTargetRayMode(V8XRTargetRayMode&&) = default;
  ~V8XRTargetRayMode() = default;

  V8XRTargetRayMode& operator=(const V8XRTargetRayMode&) = default;
  V8XRTargetRayMode& operator=(V8XRTargetRayMode&&) = default;
  V8XRTargetRayMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "gaze", "tracked-pointer", "screen"};
};

inline bool operator==(const V8XRTargetRayMode& lhs,
                       V8XRTargetRayMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8XRTargetRayMode::Enum lhs,
                       const V8XRTargetRayMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_TARGET_RAY_MODE_H_
