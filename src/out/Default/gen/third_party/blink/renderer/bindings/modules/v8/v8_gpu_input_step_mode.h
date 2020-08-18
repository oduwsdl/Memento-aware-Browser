// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_INPUT_STEP_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_INPUT_STEP_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUInputStepMode final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kVertex, kInstance };

  static V8GPUInputStepMode Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUInputStepMode", exception_state);
    return result.has_value()
               ? V8GPUInputStepMode(static_cast<Enum>(result.value()))
               : V8GPUInputStepMode();
  }
  static base::Optional<V8GPUInputStepMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUInputStepMode(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUInputStepMode() = default;
  explicit constexpr V8GPUInputStepMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUInputStepMode(const V8GPUInputStepMode&) = default;
  constexpr V8GPUInputStepMode(V8GPUInputStepMode&&) = default;
  ~V8GPUInputStepMode() = default;

  V8GPUInputStepMode& operator=(const V8GPUInputStepMode&) = default;
  V8GPUInputStepMode& operator=(V8GPUInputStepMode&&) = default;
  V8GPUInputStepMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"vertex", "instance"};
};

inline bool operator==(const V8GPUInputStepMode& lhs,
                       V8GPUInputStepMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUInputStepMode::Enum lhs,
                       const V8GPUInputStepMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_INPUT_STEP_MODE_H_
