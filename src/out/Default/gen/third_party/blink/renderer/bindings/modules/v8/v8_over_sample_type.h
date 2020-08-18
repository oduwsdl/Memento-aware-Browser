// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_OVER_SAMPLE_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_OVER_SAMPLE_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8OverSampleType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, k2X, k4X };

  static V8OverSampleType Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "OverSampleType", exception_state);
    return result.has_value()
               ? V8OverSampleType(static_cast<Enum>(result.value()))
               : V8OverSampleType();
  }
  static base::Optional<V8OverSampleType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8OverSampleType(static_cast<Enum>(result.value()));
  }

  constexpr V8OverSampleType() = default;
  explicit constexpr V8OverSampleType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8OverSampleType(const V8OverSampleType&) = default;
  constexpr V8OverSampleType(V8OverSampleType&&) = default;
  ~V8OverSampleType() = default;

  V8OverSampleType& operator=(const V8OverSampleType&) = default;
  V8OverSampleType& operator=(V8OverSampleType&&) = default;
  V8OverSampleType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "2x", "4x"};
};

inline bool operator==(const V8OverSampleType& lhs,
                       V8OverSampleType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8OverSampleType::Enum lhs,
                       const V8OverSampleType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_OVER_SAMPLE_TYPE_H_
