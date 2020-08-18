// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_POWER_PREFERENCE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_POWER_PREFERENCE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUPowerPreference final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kLowPower, kHighPerformance };

  static V8GPUPowerPreference Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUPowerPreference", exception_state);
    return result.has_value()
               ? V8GPUPowerPreference(static_cast<Enum>(result.value()))
               : V8GPUPowerPreference();
  }
  static base::Optional<V8GPUPowerPreference> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUPowerPreference(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUPowerPreference() = default;
  explicit constexpr V8GPUPowerPreference(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUPowerPreference(const V8GPUPowerPreference&) = default;
  constexpr V8GPUPowerPreference(V8GPUPowerPreference&&) = default;
  ~V8GPUPowerPreference() = default;

  V8GPUPowerPreference& operator=(const V8GPUPowerPreference&) = default;
  V8GPUPowerPreference& operator=(V8GPUPowerPreference&&) = default;
  V8GPUPowerPreference& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"low-power",
                                                        "high-performance"};
};

inline bool operator==(const V8GPUPowerPreference& lhs,
                       V8GPUPowerPreference::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUPowerPreference::Enum lhs,
                       const V8GPUPowerPreference& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_POWER_PREFERENCE_H_
