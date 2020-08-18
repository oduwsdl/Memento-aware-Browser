// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_CULL_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_CULL_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUCullMode final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kFront, kBack };

  static V8GPUCullMode Create(v8::Isolate* isolate,
                              v8::Local<v8::Value> value,
                              ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUCullMode", exception_state);
    return result.has_value() ? V8GPUCullMode(static_cast<Enum>(result.value()))
                              : V8GPUCullMode();
  }
  static base::Optional<V8GPUCullMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUCullMode(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUCullMode() = default;
  explicit constexpr V8GPUCullMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUCullMode(const V8GPUCullMode&) = default;
  constexpr V8GPUCullMode(V8GPUCullMode&&) = default;
  ~V8GPUCullMode() = default;

  V8GPUCullMode& operator=(const V8GPUCullMode&) = default;
  V8GPUCullMode& operator=(V8GPUCullMode&&) = default;
  V8GPUCullMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "front",
                                                        "back"};
};

inline bool operator==(const V8GPUCullMode& lhs, V8GPUCullMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUCullMode::Enum lhs, const V8GPUCullMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_CULL_MODE_H_
