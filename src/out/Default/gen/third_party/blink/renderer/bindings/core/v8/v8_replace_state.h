// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REPLACE_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REPLACE_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ReplaceState final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kActive, kRemoved, kPersisted };

  static V8ReplaceState Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ReplaceState", exception_state);
    return result.has_value()
               ? V8ReplaceState(static_cast<Enum>(result.value()))
               : V8ReplaceState();
  }
  static base::Optional<V8ReplaceState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ReplaceState(static_cast<Enum>(result.value()));
  }

  constexpr V8ReplaceState() = default;
  explicit constexpr V8ReplaceState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ReplaceState(const V8ReplaceState&) = default;
  constexpr V8ReplaceState(V8ReplaceState&&) = default;
  ~V8ReplaceState() = default;

  V8ReplaceState& operator=(const V8ReplaceState&) = default;
  V8ReplaceState& operator=(V8ReplaceState&&) = default;
  V8ReplaceState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"active", "removed",
                                                        "persisted"};
};

inline bool operator==(const V8ReplaceState& lhs, V8ReplaceState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ReplaceState::Enum lhs, const V8ReplaceState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REPLACE_STATE_H_
