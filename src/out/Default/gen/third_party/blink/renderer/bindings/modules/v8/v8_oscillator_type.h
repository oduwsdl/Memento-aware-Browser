// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_OSCILLATOR_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_OSCILLATOR_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8OscillatorType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kSine,
    kSquare,
    kSawtooth,
    kTriangle,
    kCustom
  };

  static V8OscillatorType Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "OscillatorType", exception_state);
    return result.has_value()
               ? V8OscillatorType(static_cast<Enum>(result.value()))
               : V8OscillatorType();
  }
  static base::Optional<V8OscillatorType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8OscillatorType(static_cast<Enum>(result.value()));
  }

  constexpr V8OscillatorType() = default;
  explicit constexpr V8OscillatorType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8OscillatorType(const V8OscillatorType&) = default;
  constexpr V8OscillatorType(V8OscillatorType&&) = default;
  ~V8OscillatorType() = default;

  V8OscillatorType& operator=(const V8OscillatorType&) = default;
  V8OscillatorType& operator=(V8OscillatorType&&) = default;
  V8OscillatorType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "sine", "square", "sawtooth", "triangle", "custom"};
};

inline bool operator==(const V8OscillatorType& lhs,
                       V8OscillatorType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8OscillatorType::Enum lhs,
                       const V8OscillatorType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_OSCILLATOR_TYPE_H_
