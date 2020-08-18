// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_SETTING_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_SETTING_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ScrollSetting final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { k, kUp };

  static V8ScrollSetting Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ScrollSetting", exception_state);
    return result.has_value()
               ? V8ScrollSetting(static_cast<Enum>(result.value()))
               : V8ScrollSetting();
  }
  static base::Optional<V8ScrollSetting> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ScrollSetting(static_cast<Enum>(result.value()));
  }

  constexpr V8ScrollSetting() = default;
  explicit constexpr V8ScrollSetting(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ScrollSetting(const V8ScrollSetting&) = default;
  constexpr V8ScrollSetting(V8ScrollSetting&&) = default;
  ~V8ScrollSetting() = default;

  V8ScrollSetting& operator=(const V8ScrollSetting&) = default;
  V8ScrollSetting& operator=(V8ScrollSetting&&) = default;
  V8ScrollSetting& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"", "up"};
};

inline bool operator==(const V8ScrollSetting& lhs, V8ScrollSetting::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ScrollSetting::Enum lhs, const V8ScrollSetting& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_SETTING_H_
