// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CSS_NUMERIC_BASE_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CSS_NUMERIC_BASE_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8CSSNumericBaseType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kLength,
    kAngle,
    kTime,
    kFrequency,
    kResolution,
    kFlex,
    kPercent
  };

  static V8CSSNumericBaseType Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "CSSNumericBaseType", exception_state);
    return result.has_value()
               ? V8CSSNumericBaseType(static_cast<Enum>(result.value()))
               : V8CSSNumericBaseType();
  }
  static base::Optional<V8CSSNumericBaseType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8CSSNumericBaseType(static_cast<Enum>(result.value()));
  }

  constexpr V8CSSNumericBaseType() = default;
  explicit constexpr V8CSSNumericBaseType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8CSSNumericBaseType(const V8CSSNumericBaseType&) = default;
  constexpr V8CSSNumericBaseType(V8CSSNumericBaseType&&) = default;
  ~V8CSSNumericBaseType() = default;

  V8CSSNumericBaseType& operator=(const V8CSSNumericBaseType&) = default;
  V8CSSNumericBaseType& operator=(V8CSSNumericBaseType&&) = default;
  V8CSSNumericBaseType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "length", "angle", "time", "frequency", "resolution", "flex", "percent"};
};

inline bool operator==(const V8CSSNumericBaseType& lhs,
                       V8CSSNumericBaseType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8CSSNumericBaseType::Enum lhs,
                       const V8CSSNumericBaseType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CSS_NUMERIC_BASE_TYPE_H_
