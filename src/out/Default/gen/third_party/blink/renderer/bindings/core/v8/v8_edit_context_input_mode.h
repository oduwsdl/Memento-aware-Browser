// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_EDIT_CONTEXT_INPUT_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_EDIT_CONTEXT_INPUT_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8EditContextInputMode final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kNone,
    kText,
    kDecimal,
    kSearch,
    kEmail,
    kNumeric,
    kTel,
    kUrl,
    kPassword
  };

  static V8EditContextInputMode Create(v8::Isolate* isolate,
                                       v8::Local<v8::Value> value,
                                       ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "EditContextInputMode", exception_state);
    return result.has_value()
               ? V8EditContextInputMode(static_cast<Enum>(result.value()))
               : V8EditContextInputMode();
  }
  static base::Optional<V8EditContextInputMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8EditContextInputMode(static_cast<Enum>(result.value()));
  }

  constexpr V8EditContextInputMode() = default;
  explicit constexpr V8EditContextInputMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8EditContextInputMode(const V8EditContextInputMode&) = default;
  constexpr V8EditContextInputMode(V8EditContextInputMode&&) = default;
  ~V8EditContextInputMode() = default;

  V8EditContextInputMode& operator=(const V8EditContextInputMode&) = default;
  V8EditContextInputMode& operator=(V8EditContextInputMode&&) = default;
  V8EditContextInputMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "none",    "text", "decimal", "search",  "email",
      "numeric", "tel",  "url",     "password"};
};

inline bool operator==(const V8EditContextInputMode& lhs,
                       V8EditContextInputMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8EditContextInputMode::Enum lhs,
                       const V8EditContextInputMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_EDIT_CONTEXT_INPUT_MODE_H_
