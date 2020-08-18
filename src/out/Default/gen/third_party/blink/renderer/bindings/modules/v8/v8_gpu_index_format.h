// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_INDEX_FORMAT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_INDEX_FORMAT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUIndexFormat final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kUint16, kUint32 };

  static V8GPUIndexFormat Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUIndexFormat", exception_state);
    return result.has_value()
               ? V8GPUIndexFormat(static_cast<Enum>(result.value()))
               : V8GPUIndexFormat();
  }
  static base::Optional<V8GPUIndexFormat> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUIndexFormat(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUIndexFormat() = default;
  explicit constexpr V8GPUIndexFormat(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUIndexFormat(const V8GPUIndexFormat&) = default;
  constexpr V8GPUIndexFormat(V8GPUIndexFormat&&) = default;
  ~V8GPUIndexFormat() = default;

  V8GPUIndexFormat& operator=(const V8GPUIndexFormat&) = default;
  V8GPUIndexFormat& operator=(V8GPUIndexFormat&&) = default;
  V8GPUIndexFormat& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"uint16", "uint32"};
};

inline bool operator==(const V8GPUIndexFormat& lhs,
                       V8GPUIndexFormat::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUIndexFormat::Enum lhs,
                       const V8GPUIndexFormat& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_INDEX_FORMAT_H_
