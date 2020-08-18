// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_INTERNAL_ENUM_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_INTERNAL_ENUM_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class V8InternalEnum final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kFoo, kBar, kBaz };

  static V8InternalEnum Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "InternalEnum", exception_state);
    return result.has_value()
               ? V8InternalEnum(static_cast<Enum>(result.value()))
               : V8InternalEnum();
  }
  static base::Optional<V8InternalEnum> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8InternalEnum(static_cast<Enum>(result.value()));
  }

  constexpr V8InternalEnum() = default;
  explicit constexpr V8InternalEnum(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8InternalEnum(const V8InternalEnum&) = default;
  constexpr V8InternalEnum(V8InternalEnum&&) = default;
  ~V8InternalEnum() = default;

  V8InternalEnum& operator=(const V8InternalEnum&) = default;
  V8InternalEnum& operator=(V8InternalEnum&&) = default;
  V8InternalEnum& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"foo", "bar", "baz"};
};

inline bool operator==(const V8InternalEnum& lhs, V8InternalEnum::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8InternalEnum::Enum lhs, const V8InternalEnum& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_INTERNAL_ENUM_H_
