// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_STENCIL_OPERATION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_STENCIL_OPERATION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUStencilOperation final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kKeep,
    kZero,
    kReplace,
    kInvert,
    kIncrementClamp,
    kDecrementClamp,
    kIncrementWrap,
    kDecrementWrap
  };

  static V8GPUStencilOperation Create(v8::Isolate* isolate,
                                      v8::Local<v8::Value> value,
                                      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUStencilOperation", exception_state);
    return result.has_value()
               ? V8GPUStencilOperation(static_cast<Enum>(result.value()))
               : V8GPUStencilOperation();
  }
  static base::Optional<V8GPUStencilOperation> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUStencilOperation(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUStencilOperation() = default;
  explicit constexpr V8GPUStencilOperation(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUStencilOperation(const V8GPUStencilOperation&) = default;
  constexpr V8GPUStencilOperation(V8GPUStencilOperation&&) = default;
  ~V8GPUStencilOperation() = default;

  V8GPUStencilOperation& operator=(const V8GPUStencilOperation&) = default;
  V8GPUStencilOperation& operator=(V8GPUStencilOperation&&) = default;
  V8GPUStencilOperation& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"keep",
                                                        "zero",
                                                        "replace",
                                                        "invert",
                                                        "increment-clamp",
                                                        "decrement-clamp",
                                                        "increment-wrap",
                                                        "decrement-wrap"};
};

inline bool operator==(const V8GPUStencilOperation& lhs,
                       V8GPUStencilOperation::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUStencilOperation::Enum lhs,
                       const V8GPUStencilOperation& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_STENCIL_OPERATION_H_
