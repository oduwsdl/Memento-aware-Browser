// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_AUTO_KEYWORD_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_AUTO_KEYWORD_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8AutoKeyword final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAuto };

  static V8AutoKeyword Create(v8::Isolate* isolate,
                              v8::Local<v8::Value> value,
                              ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "AutoKeyword", exception_state);
    return result.has_value() ? V8AutoKeyword(static_cast<Enum>(result.value()))
                              : V8AutoKeyword();
  }
  static base::Optional<V8AutoKeyword> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8AutoKeyword(static_cast<Enum>(result.value()));
  }

  constexpr V8AutoKeyword() = default;
  explicit constexpr V8AutoKeyword(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8AutoKeyword(const V8AutoKeyword&) = default;
  constexpr V8AutoKeyword(V8AutoKeyword&&) = default;
  ~V8AutoKeyword() = default;

  V8AutoKeyword& operator=(const V8AutoKeyword&) = default;
  V8AutoKeyword& operator=(V8AutoKeyword&&) = default;
  V8AutoKeyword& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"auto"};
};

inline bool operator==(const V8AutoKeyword& lhs, V8AutoKeyword::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8AutoKeyword::Enum lhs, const V8AutoKeyword& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_AUTO_KEYWORD_H_
