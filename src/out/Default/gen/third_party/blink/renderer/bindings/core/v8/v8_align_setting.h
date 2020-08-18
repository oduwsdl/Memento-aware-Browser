// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_ALIGN_SETTING_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_ALIGN_SETTING_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8AlignSetting final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kStart, kCenter, kEnd, kLeft, kRight };

  static V8AlignSetting Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "AlignSetting", exception_state);
    return result.has_value()
               ? V8AlignSetting(static_cast<Enum>(result.value()))
               : V8AlignSetting();
  }
  static base::Optional<V8AlignSetting> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8AlignSetting(static_cast<Enum>(result.value()));
  }

  constexpr V8AlignSetting() = default;
  explicit constexpr V8AlignSetting(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8AlignSetting(const V8AlignSetting&) = default;
  constexpr V8AlignSetting(V8AlignSetting&&) = default;
  ~V8AlignSetting() = default;

  V8AlignSetting& operator=(const V8AlignSetting&) = default;
  V8AlignSetting& operator=(V8AlignSetting&&) = default;
  V8AlignSetting& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"start", "center",
                                                        "end", "left", "right"};
};

inline bool operator==(const V8AlignSetting& lhs, V8AlignSetting::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8AlignSetting::Enum lhs, const V8AlignSetting& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_ALIGN_SETTING_H_
