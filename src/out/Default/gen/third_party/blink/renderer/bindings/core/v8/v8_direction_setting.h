// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_DIRECTION_SETTING_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_DIRECTION_SETTING_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8DirectionSetting final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { k, kRl, kLr };

  static V8DirectionSetting Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "DirectionSetting", exception_state);
    return result.has_value()
               ? V8DirectionSetting(static_cast<Enum>(result.value()))
               : V8DirectionSetting();
  }
  static base::Optional<V8DirectionSetting> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8DirectionSetting(static_cast<Enum>(result.value()));
  }

  constexpr V8DirectionSetting() = default;
  explicit constexpr V8DirectionSetting(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8DirectionSetting(const V8DirectionSetting&) = default;
  constexpr V8DirectionSetting(V8DirectionSetting&&) = default;
  ~V8DirectionSetting() = default;

  V8DirectionSetting& operator=(const V8DirectionSetting&) = default;
  V8DirectionSetting& operator=(V8DirectionSetting&&) = default;
  V8DirectionSetting& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"", "rl", "lr"};
};

inline bool operator==(const V8DirectionSetting& lhs,
                       V8DirectionSetting::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8DirectionSetting::Enum lhs,
                       const V8DirectionSetting& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_DIRECTION_SETTING_H_
