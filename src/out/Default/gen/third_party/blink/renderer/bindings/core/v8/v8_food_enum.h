// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FOOD_ENUM_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FOOD_ENUM_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class V8FoodEnum final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kBread, kSpaghetti, kSushi };

  static V8FoodEnum Create(v8::Isolate* isolate,
                           v8::Local<v8::Value> value,
                           ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "FoodEnum", exception_state);
    return result.has_value() ? V8FoodEnum(static_cast<Enum>(result.value()))
                              : V8FoodEnum();
  }
  static base::Optional<V8FoodEnum> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8FoodEnum(static_cast<Enum>(result.value()));
  }

  constexpr V8FoodEnum() = default;
  explicit constexpr V8FoodEnum(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8FoodEnum(const V8FoodEnum&) = default;
  constexpr V8FoodEnum(V8FoodEnum&&) = default;
  ~V8FoodEnum() = default;

  V8FoodEnum& operator=(const V8FoodEnum&) = default;
  V8FoodEnum& operator=(V8FoodEnum&&) = default;
  V8FoodEnum& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"Bread", "Spaghetti",
                                                        "Sushi"};
};

inline bool operator==(const V8FoodEnum& lhs, V8FoodEnum::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8FoodEnum::Enum lhs, const V8FoodEnum& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FOOD_ENUM_H_
