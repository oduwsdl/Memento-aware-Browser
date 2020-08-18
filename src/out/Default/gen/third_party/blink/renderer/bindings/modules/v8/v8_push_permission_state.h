// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PUSH_PERMISSION_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PUSH_PERMISSION_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8PushPermissionState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kDenied, kGranted, kPrompt };

  static V8PushPermissionState Create(v8::Isolate* isolate,
                                      v8::Local<v8::Value> value,
                                      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "PushPermissionState", exception_state);
    return result.has_value()
               ? V8PushPermissionState(static_cast<Enum>(result.value()))
               : V8PushPermissionState();
  }
  static base::Optional<V8PushPermissionState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8PushPermissionState(static_cast<Enum>(result.value()));
  }

  constexpr V8PushPermissionState() = default;
  explicit constexpr V8PushPermissionState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8PushPermissionState(const V8PushPermissionState&) = default;
  constexpr V8PushPermissionState(V8PushPermissionState&&) = default;
  ~V8PushPermissionState() = default;

  V8PushPermissionState& operator=(const V8PushPermissionState&) = default;
  V8PushPermissionState& operator=(V8PushPermissionState&&) = default;
  V8PushPermissionState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"denied", "granted",
                                                        "prompt"};
};

inline bool operator==(const V8PushPermissionState& lhs,
                       V8PushPermissionState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8PushPermissionState::Enum lhs,
                       const V8PushPermissionState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PUSH_PERMISSION_STATE_H_
