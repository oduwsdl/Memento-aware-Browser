// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_BEHAVIOR_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_BEHAVIOR_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ScrollBehavior final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAuto, kInstant, kSmooth };

  static V8ScrollBehavior Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ScrollBehavior", exception_state);
    return result.has_value()
               ? V8ScrollBehavior(static_cast<Enum>(result.value()))
               : V8ScrollBehavior();
  }
  static base::Optional<V8ScrollBehavior> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ScrollBehavior(static_cast<Enum>(result.value()));
  }

  constexpr V8ScrollBehavior() = default;
  explicit constexpr V8ScrollBehavior(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ScrollBehavior(const V8ScrollBehavior&) = default;
  constexpr V8ScrollBehavior(V8ScrollBehavior&&) = default;
  ~V8ScrollBehavior() = default;

  V8ScrollBehavior& operator=(const V8ScrollBehavior&) = default;
  V8ScrollBehavior& operator=(V8ScrollBehavior&&) = default;
  V8ScrollBehavior& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"auto", "instant",
                                                        "smooth"};
};

inline bool operator==(const V8ScrollBehavior& lhs,
                       V8ScrollBehavior::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ScrollBehavior::Enum lhs,
                       const V8ScrollBehavior& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_BEHAVIOR_H_
