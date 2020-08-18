// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CSS_MATH_OPERATOR_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CSS_MATH_OPERATOR_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8CSSMathOperator final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kSum, kProduct, kNegate, kInvert, kMin, kMax };

  static V8CSSMathOperator Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "CSSMathOperator", exception_state);
    return result.has_value()
               ? V8CSSMathOperator(static_cast<Enum>(result.value()))
               : V8CSSMathOperator();
  }
  static base::Optional<V8CSSMathOperator> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8CSSMathOperator(static_cast<Enum>(result.value()));
  }

  constexpr V8CSSMathOperator() = default;
  explicit constexpr V8CSSMathOperator(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8CSSMathOperator(const V8CSSMathOperator&) = default;
  constexpr V8CSSMathOperator(V8CSSMathOperator&&) = default;
  ~V8CSSMathOperator() = default;

  V8CSSMathOperator& operator=(const V8CSSMathOperator&) = default;
  V8CSSMathOperator& operator=(V8CSSMathOperator&&) = default;
  V8CSSMathOperator& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "sum", "product", "negate", "invert", "min", "max"};
};

inline bool operator==(const V8CSSMathOperator& lhs,
                       V8CSSMathOperator::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8CSSMathOperator::Enum lhs,
                       const V8CSSMathOperator& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CSS_MATH_OPERATOR_H_
