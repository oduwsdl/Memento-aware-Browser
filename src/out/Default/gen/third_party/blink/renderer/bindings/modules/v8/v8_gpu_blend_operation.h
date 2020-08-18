// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_BLEND_OPERATION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_BLEND_OPERATION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUBlendOperation final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kAdd,
    kSubtract,
    kReverseSubtract,
    kMin,
    kMax
  };

  static V8GPUBlendOperation Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUBlendOperation", exception_state);
    return result.has_value()
               ? V8GPUBlendOperation(static_cast<Enum>(result.value()))
               : V8GPUBlendOperation();
  }
  static base::Optional<V8GPUBlendOperation> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUBlendOperation(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUBlendOperation() = default;
  explicit constexpr V8GPUBlendOperation(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUBlendOperation(const V8GPUBlendOperation&) = default;
  constexpr V8GPUBlendOperation(V8GPUBlendOperation&&) = default;
  ~V8GPUBlendOperation() = default;

  V8GPUBlendOperation& operator=(const V8GPUBlendOperation&) = default;
  V8GPUBlendOperation& operator=(V8GPUBlendOperation&&) = default;
  V8GPUBlendOperation& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "add", "subtract", "reverse-subtract", "min", "max"};
};

inline bool operator==(const V8GPUBlendOperation& lhs,
                       V8GPUBlendOperation::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUBlendOperation::Enum lhs,
                       const V8GPUBlendOperation& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_BLEND_OPERATION_H_
