// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GAMEPAD_HAPTICS_RESULT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GAMEPAD_HAPTICS_RESULT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GamepadHapticsResult final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kComplete,
    kPreempted,
    kInvalidParameter,
    kNotSupported
  };

  static V8GamepadHapticsResult Create(v8::Isolate* isolate,
                                       v8::Local<v8::Value> value,
                                       ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GamepadHapticsResult", exception_state);
    return result.has_value()
               ? V8GamepadHapticsResult(static_cast<Enum>(result.value()))
               : V8GamepadHapticsResult();
  }
  static base::Optional<V8GamepadHapticsResult> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GamepadHapticsResult(static_cast<Enum>(result.value()));
  }

  constexpr V8GamepadHapticsResult() = default;
  explicit constexpr V8GamepadHapticsResult(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GamepadHapticsResult(const V8GamepadHapticsResult&) = default;
  constexpr V8GamepadHapticsResult(V8GamepadHapticsResult&&) = default;
  ~V8GamepadHapticsResult() = default;

  V8GamepadHapticsResult& operator=(const V8GamepadHapticsResult&) = default;
  V8GamepadHapticsResult& operator=(V8GamepadHapticsResult&&) = default;
  V8GamepadHapticsResult& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "complete", "preempted", "invalid-parameter", "not-supported"};
};

inline bool operator==(const V8GamepadHapticsResult& lhs,
                       V8GamepadHapticsResult::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GamepadHapticsResult::Enum lhs,
                       const V8GamepadHapticsResult& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GAMEPAD_HAPTICS_RESULT_H_
