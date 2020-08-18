// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_ANIMATION_PLAY_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_ANIMATION_PLAY_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8AnimationPlayState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kIdle,
    kPending,
    kRunning,
    kPaused,
    kFinished
  };

  static V8AnimationPlayState Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "AnimationPlayState", exception_state);
    return result.has_value()
               ? V8AnimationPlayState(static_cast<Enum>(result.value()))
               : V8AnimationPlayState();
  }
  static base::Optional<V8AnimationPlayState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8AnimationPlayState(static_cast<Enum>(result.value()));
  }

  constexpr V8AnimationPlayState() = default;
  explicit constexpr V8AnimationPlayState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8AnimationPlayState(const V8AnimationPlayState&) = default;
  constexpr V8AnimationPlayState(V8AnimationPlayState&&) = default;
  ~V8AnimationPlayState() = default;

  V8AnimationPlayState& operator=(const V8AnimationPlayState&) = default;
  V8AnimationPlayState& operator=(V8AnimationPlayState&&) = default;
  V8AnimationPlayState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "idle", "pending", "running", "paused", "finished"};
};

inline bool operator==(const V8AnimationPlayState& lhs,
                       V8AnimationPlayState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8AnimationPlayState::Enum lhs,
                       const V8AnimationPlayState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_ANIMATION_PLAY_STATE_H_
