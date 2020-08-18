// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_APP_BANNER_PROMPT_OUTCOME_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_APP_BANNER_PROMPT_OUTCOME_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8AppBannerPromptOutcome final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAccepted, kDismissed };

  static V8AppBannerPromptOutcome Create(v8::Isolate* isolate,
                                         v8::Local<v8::Value> value,
                                         ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "AppBannerPromptOutcome",
        exception_state);
    return result.has_value()
               ? V8AppBannerPromptOutcome(static_cast<Enum>(result.value()))
               : V8AppBannerPromptOutcome();
  }
  static base::Optional<V8AppBannerPromptOutcome> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8AppBannerPromptOutcome(static_cast<Enum>(result.value()));
  }

  constexpr V8AppBannerPromptOutcome() = default;
  explicit constexpr V8AppBannerPromptOutcome(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8AppBannerPromptOutcome(const V8AppBannerPromptOutcome&) = default;
  constexpr V8AppBannerPromptOutcome(V8AppBannerPromptOutcome&&) = default;
  ~V8AppBannerPromptOutcome() = default;

  V8AppBannerPromptOutcome& operator=(const V8AppBannerPromptOutcome&) =
      default;
  V8AppBannerPromptOutcome& operator=(V8AppBannerPromptOutcome&&) = default;
  V8AppBannerPromptOutcome& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"accepted",
                                                        "dismissed"};
};

inline bool operator==(const V8AppBannerPromptOutcome& lhs,
                       V8AppBannerPromptOutcome::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8AppBannerPromptOutcome::Enum lhs,
                       const V8AppBannerPromptOutcome& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_APP_BANNER_PROMPT_OUTCOME_H_
