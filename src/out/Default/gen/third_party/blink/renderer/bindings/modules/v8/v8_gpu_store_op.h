// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_STORE_OP_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_STORE_OP_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUStoreOp final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kStore, kClear };

  static V8GPUStoreOp Create(v8::Isolate* isolate,
                             v8::Local<v8::Value> value,
                             ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUStoreOp", exception_state);
    return result.has_value() ? V8GPUStoreOp(static_cast<Enum>(result.value()))
                              : V8GPUStoreOp();
  }
  static base::Optional<V8GPUStoreOp> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUStoreOp(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUStoreOp() = default;
  explicit constexpr V8GPUStoreOp(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUStoreOp(const V8GPUStoreOp&) = default;
  constexpr V8GPUStoreOp(V8GPUStoreOp&&) = default;
  ~V8GPUStoreOp() = default;

  V8GPUStoreOp& operator=(const V8GPUStoreOp&) = default;
  V8GPUStoreOp& operator=(V8GPUStoreOp&&) = default;
  V8GPUStoreOp& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"store", "clear"};
};

inline bool operator==(const V8GPUStoreOp& lhs, V8GPUStoreOp::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUStoreOp::Enum lhs, const V8GPUStoreOp& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_STORE_OP_H_
