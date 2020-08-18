// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_PLAYBACK_DIRECTION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_PLAYBACK_DIRECTION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8PlaybackDirection final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kNormal,
    kReverse,
    kAlternate,
    kAlternateReverse
  };

  static V8PlaybackDirection Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "PlaybackDirection", exception_state);
    return result.has_value()
               ? V8PlaybackDirection(static_cast<Enum>(result.value()))
               : V8PlaybackDirection();
  }
  static base::Optional<V8PlaybackDirection> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8PlaybackDirection(static_cast<Enum>(result.value()));
  }

  constexpr V8PlaybackDirection() = default;
  explicit constexpr V8PlaybackDirection(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8PlaybackDirection(const V8PlaybackDirection&) = default;
  constexpr V8PlaybackDirection(V8PlaybackDirection&&) = default;
  ~V8PlaybackDirection() = default;

  V8PlaybackDirection& operator=(const V8PlaybackDirection&) = default;
  V8PlaybackDirection& operator=(V8PlaybackDirection&&) = default;
  V8PlaybackDirection& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "normal", "reverse", "alternate", "alternate-reverse"};
};

inline bool operator==(const V8PlaybackDirection& lhs,
                       V8PlaybackDirection::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8PlaybackDirection::Enum lhs,
                       const V8PlaybackDirection& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_PLAYBACK_DIRECTION_H_
