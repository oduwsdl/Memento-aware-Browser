// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_NAVIGATION_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_NAVIGATION_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8NavigationType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNavigate, kReload, kBackForward, kPrerender };

  static V8NavigationType Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "NavigationType", exception_state);
    return result.has_value()
               ? V8NavigationType(static_cast<Enum>(result.value()))
               : V8NavigationType();
  }
  static base::Optional<V8NavigationType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8NavigationType(static_cast<Enum>(result.value()));
  }

  constexpr V8NavigationType() = default;
  explicit constexpr V8NavigationType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8NavigationType(const V8NavigationType&) = default;
  constexpr V8NavigationType(V8NavigationType&&) = default;
  ~V8NavigationType() = default;

  V8NavigationType& operator=(const V8NavigationType&) = default;
  V8NavigationType& operator=(V8NavigationType&&) = default;
  V8NavigationType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "navigate", "reload", "back_forward", "prerender"};
};

inline bool operator==(const V8NavigationType& lhs,
                       V8NavigationType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8NavigationType::Enum lhs,
                       const V8NavigationType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_NAVIGATION_TYPE_H_
