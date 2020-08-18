// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SCREEN_IDLE_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SCREEN_IDLE_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8ScreenIdleState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kLocked, kUnlocked };

  static V8ScreenIdleState Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ScreenIdleState", exception_state);
    return result.has_value()
               ? V8ScreenIdleState(static_cast<Enum>(result.value()))
               : V8ScreenIdleState();
  }
  static base::Optional<V8ScreenIdleState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ScreenIdleState(static_cast<Enum>(result.value()));
  }

  constexpr V8ScreenIdleState() = default;
  explicit constexpr V8ScreenIdleState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ScreenIdleState(const V8ScreenIdleState&) = default;
  constexpr V8ScreenIdleState(V8ScreenIdleState&&) = default;
  ~V8ScreenIdleState() = default;

  V8ScreenIdleState& operator=(const V8ScreenIdleState&) = default;
  V8ScreenIdleState& operator=(V8ScreenIdleState&&) = default;
  V8ScreenIdleState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"locked", "unlocked"};
};

inline bool operator==(const V8ScreenIdleState& lhs,
                       V8ScreenIdleState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ScreenIdleState::Enum lhs,
                       const V8ScreenIdleState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SCREEN_IDLE_STATE_H_
