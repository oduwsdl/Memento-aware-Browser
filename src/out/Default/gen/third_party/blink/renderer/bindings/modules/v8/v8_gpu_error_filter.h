// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_ERROR_FILTER_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_ERROR_FILTER_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUErrorFilter final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kOutOfMemory, kValidation };

  static V8GPUErrorFilter Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUErrorFilter", exception_state);
    return result.has_value()
               ? V8GPUErrorFilter(static_cast<Enum>(result.value()))
               : V8GPUErrorFilter();
  }
  static base::Optional<V8GPUErrorFilter> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUErrorFilter(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUErrorFilter() = default;
  explicit constexpr V8GPUErrorFilter(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUErrorFilter(const V8GPUErrorFilter&) = default;
  constexpr V8GPUErrorFilter(V8GPUErrorFilter&&) = default;
  ~V8GPUErrorFilter() = default;

  V8GPUErrorFilter& operator=(const V8GPUErrorFilter&) = default;
  V8GPUErrorFilter& operator=(V8GPUErrorFilter&&) = default;
  V8GPUErrorFilter& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "out-of-memory",
                                                        "validation"};
};

inline bool operator==(const V8GPUErrorFilter& lhs,
                       V8GPUErrorFilter::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUErrorFilter::Enum lhs,
                       const V8GPUErrorFilter& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_ERROR_FILTER_H_
