// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_FILTER_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_FILTER_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUFilterMode final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNearest, kLinear };

  static V8GPUFilterMode Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUFilterMode", exception_state);
    return result.has_value()
               ? V8GPUFilterMode(static_cast<Enum>(result.value()))
               : V8GPUFilterMode();
  }
  static base::Optional<V8GPUFilterMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUFilterMode(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUFilterMode() = default;
  explicit constexpr V8GPUFilterMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUFilterMode(const V8GPUFilterMode&) = default;
  constexpr V8GPUFilterMode(V8GPUFilterMode&&) = default;
  ~V8GPUFilterMode() = default;

  V8GPUFilterMode& operator=(const V8GPUFilterMode&) = default;
  V8GPUFilterMode& operator=(V8GPUFilterMode&&) = default;
  V8GPUFilterMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"nearest", "linear"};
};

inline bool operator==(const V8GPUFilterMode& lhs, V8GPUFilterMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUFilterMode::Enum lhs, const V8GPUFilterMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_FILTER_MODE_H_
