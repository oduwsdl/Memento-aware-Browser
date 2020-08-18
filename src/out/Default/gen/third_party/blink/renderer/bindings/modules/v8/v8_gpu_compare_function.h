// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_COMPARE_FUNCTION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_COMPARE_FUNCTION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUCompareFunction final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kNever,
    kLess,
    kEqual,
    kLessEqual,
    kGreater,
    kNotEqual,
    kGreaterEqual,
    kAlways
  };

  static V8GPUCompareFunction Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUCompareFunction", exception_state);
    return result.has_value()
               ? V8GPUCompareFunction(static_cast<Enum>(result.value()))
               : V8GPUCompareFunction();
  }
  static base::Optional<V8GPUCompareFunction> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUCompareFunction(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUCompareFunction() = default;
  explicit constexpr V8GPUCompareFunction(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUCompareFunction(const V8GPUCompareFunction&) = default;
  constexpr V8GPUCompareFunction(V8GPUCompareFunction&&) = default;
  ~V8GPUCompareFunction() = default;

  V8GPUCompareFunction& operator=(const V8GPUCompareFunction&) = default;
  V8GPUCompareFunction& operator=(V8GPUCompareFunction&&) = default;
  V8GPUCompareFunction& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "never",   "less",      "equal",         "less-equal",
      "greater", "not-equal", "greater-equal", "always"};
};

inline bool operator==(const V8GPUCompareFunction& lhs,
                       V8GPUCompareFunction::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUCompareFunction::Enum lhs,
                       const V8GPUCompareFunction& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_COMPARE_FUNCTION_H_
