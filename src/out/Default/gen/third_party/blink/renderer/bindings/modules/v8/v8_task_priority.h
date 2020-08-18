// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_TASK_PRIORITY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_TASK_PRIORITY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8TaskPriority final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kUserBlocking, kUserVisible, kBackground };

  static V8TaskPriority Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "TaskPriority", exception_state);
    return result.has_value()
               ? V8TaskPriority(static_cast<Enum>(result.value()))
               : V8TaskPriority();
  }
  static base::Optional<V8TaskPriority> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8TaskPriority(static_cast<Enum>(result.value()));
  }

  constexpr V8TaskPriority() = default;
  explicit constexpr V8TaskPriority(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8TaskPriority(const V8TaskPriority&) = default;
  constexpr V8TaskPriority(V8TaskPriority&&) = default;
  ~V8TaskPriority() = default;

  V8TaskPriority& operator=(const V8TaskPriority&) = default;
  V8TaskPriority& operator=(V8TaskPriority&&) = default;
  V8TaskPriority& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "user-blocking", "user-visible", "background"};
};

inline bool operator==(const V8TaskPriority& lhs, V8TaskPriority::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8TaskPriority::Enum lhs, const V8TaskPriority& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_TASK_PRIORITY_H_
