// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_AUDIO_CONTEXT_LATENCY_CATEGORY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_AUDIO_CONTEXT_LATENCY_CATEGORY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8AudioContextLatencyCategory final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kBalanced, kInteractive, kPlayback };

  static V8AudioContextLatencyCategory Create(v8::Isolate* isolate,
                                              v8::Local<v8::Value> value,
                                              ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "AudioContextLatencyCategory",
        exception_state);
    return result.has_value() ? V8AudioContextLatencyCategory(
                                    static_cast<Enum>(result.value()))
                              : V8AudioContextLatencyCategory();
  }
  static base::Optional<V8AudioContextLatencyCategory> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8AudioContextLatencyCategory(static_cast<Enum>(result.value()));
  }

  constexpr V8AudioContextLatencyCategory() = default;
  explicit constexpr V8AudioContextLatencyCategory(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8AudioContextLatencyCategory(
      const V8AudioContextLatencyCategory&) = default;
  constexpr V8AudioContextLatencyCategory(V8AudioContextLatencyCategory&&) =
      default;
  ~V8AudioContextLatencyCategory() = default;

  V8AudioContextLatencyCategory& operator=(
      const V8AudioContextLatencyCategory&) = default;
  V8AudioContextLatencyCategory& operator=(V8AudioContextLatencyCategory&&) =
      default;
  V8AudioContextLatencyCategory& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "balanced", "interactive", "playback"};
};

inline bool operator==(const V8AudioContextLatencyCategory& lhs,
                       V8AudioContextLatencyCategory::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8AudioContextLatencyCategory::Enum lhs,
                       const V8AudioContextLatencyCategory& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_AUDIO_CONTEXT_LATENCY_CATEGORY_H_
