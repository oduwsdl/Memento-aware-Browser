// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_EDIT_CONTEXT_ENTER_KEY_HINT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_EDIT_CONTEXT_ENTER_KEY_HINT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8EditContextEnterKeyHint final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kEnter,
    kDone,
    kGo,
    kNext,
    kPrevious,
    kSearch,
    kSend
  };

  static V8EditContextEnterKeyHint Create(v8::Isolate* isolate,
                                          v8::Local<v8::Value> value,
                                          ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "EditContextEnterKeyHint",
        exception_state);
    return result.has_value()
               ? V8EditContextEnterKeyHint(static_cast<Enum>(result.value()))
               : V8EditContextEnterKeyHint();
  }
  static base::Optional<V8EditContextEnterKeyHint> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8EditContextEnterKeyHint(static_cast<Enum>(result.value()));
  }

  constexpr V8EditContextEnterKeyHint() = default;
  explicit constexpr V8EditContextEnterKeyHint(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8EditContextEnterKeyHint(const V8EditContextEnterKeyHint&) =
      default;
  constexpr V8EditContextEnterKeyHint(V8EditContextEnterKeyHint&&) = default;
  ~V8EditContextEnterKeyHint() = default;

  V8EditContextEnterKeyHint& operator=(const V8EditContextEnterKeyHint&) =
      default;
  V8EditContextEnterKeyHint& operator=(V8EditContextEnterKeyHint&&) = default;
  V8EditContextEnterKeyHint& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "enter", "done", "go", "next", "previous", "search", "send"};
};

inline bool operator==(const V8EditContextEnterKeyHint& lhs,
                       V8EditContextEnterKeyHint::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8EditContextEnterKeyHint::Enum lhs,
                       const V8EditContextEnterKeyHint& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_EDIT_CONTEXT_ENTER_KEY_HINT_H_
