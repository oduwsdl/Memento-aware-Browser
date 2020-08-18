// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_ENDING_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_ENDING_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8EndingType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kTransparent, kNative };

  static V8EndingType Create(v8::Isolate* isolate,
                             v8::Local<v8::Value> value,
                             ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "EndingType", exception_state);
    return result.has_value() ? V8EndingType(static_cast<Enum>(result.value()))
                              : V8EndingType();
  }
  static base::Optional<V8EndingType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8EndingType(static_cast<Enum>(result.value()));
  }

  constexpr V8EndingType() = default;
  explicit constexpr V8EndingType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8EndingType(const V8EndingType&) = default;
  constexpr V8EndingType(V8EndingType&&) = default;
  ~V8EndingType() = default;

  V8EndingType& operator=(const V8EndingType&) = default;
  V8EndingType& operator=(V8EndingType&&) = default;
  V8EndingType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"transparent",
                                                        "native"};
};

inline bool operator==(const V8EndingType& lhs, V8EndingType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8EndingType::Enum lhs, const V8EndingType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_ENDING_TYPE_H_
