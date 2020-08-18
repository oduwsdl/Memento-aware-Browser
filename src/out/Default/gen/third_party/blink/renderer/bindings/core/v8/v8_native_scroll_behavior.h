// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_NATIVE_SCROLL_BEHAVIOR_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_NATIVE_SCROLL_BEHAVIOR_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8NativeScrollBehavior final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kDisableNativeScroll,
    kPerformBeforeNativeScroll,
    kPerformAfterNativeScroll
  };

  static V8NativeScrollBehavior Create(v8::Isolate* isolate,
                                       v8::Local<v8::Value> value,
                                       ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "NativeScrollBehavior", exception_state);
    return result.has_value()
               ? V8NativeScrollBehavior(static_cast<Enum>(result.value()))
               : V8NativeScrollBehavior();
  }
  static base::Optional<V8NativeScrollBehavior> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8NativeScrollBehavior(static_cast<Enum>(result.value()));
  }

  constexpr V8NativeScrollBehavior() = default;
  explicit constexpr V8NativeScrollBehavior(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8NativeScrollBehavior(const V8NativeScrollBehavior&) = default;
  constexpr V8NativeScrollBehavior(V8NativeScrollBehavior&&) = default;
  ~V8NativeScrollBehavior() = default;

  V8NativeScrollBehavior& operator=(const V8NativeScrollBehavior&) = default;
  V8NativeScrollBehavior& operator=(V8NativeScrollBehavior&&) = default;
  V8NativeScrollBehavior& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "disable-native-scroll", "perform-before-native-scroll",
      "perform-after-native-scroll"};
};

inline bool operator==(const V8NativeScrollBehavior& lhs,
                       V8NativeScrollBehavior::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8NativeScrollBehavior::Enum lhs,
                       const V8NativeScrollBehavior& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_NATIVE_SCROLL_BEHAVIOR_H_
