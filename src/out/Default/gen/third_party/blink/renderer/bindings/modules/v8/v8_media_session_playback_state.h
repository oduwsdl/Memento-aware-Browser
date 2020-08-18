// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_SESSION_PLAYBACK_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_SESSION_PLAYBACK_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8MediaSessionPlaybackState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kPaused, kPlaying };

  static V8MediaSessionPlaybackState Create(v8::Isolate* isolate,
                                            v8::Local<v8::Value> value,
                                            ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "MediaSessionPlaybackState",
        exception_state);
    return result.has_value()
               ? V8MediaSessionPlaybackState(static_cast<Enum>(result.value()))
               : V8MediaSessionPlaybackState();
  }
  static base::Optional<V8MediaSessionPlaybackState> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8MediaSessionPlaybackState(static_cast<Enum>(result.value()));
  }

  constexpr V8MediaSessionPlaybackState() = default;
  explicit constexpr V8MediaSessionPlaybackState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8MediaSessionPlaybackState(const V8MediaSessionPlaybackState&) =
      default;
  constexpr V8MediaSessionPlaybackState(V8MediaSessionPlaybackState&&) =
      default;
  ~V8MediaSessionPlaybackState() = default;

  V8MediaSessionPlaybackState& operator=(const V8MediaSessionPlaybackState&) =
      default;
  V8MediaSessionPlaybackState& operator=(V8MediaSessionPlaybackState&&) =
      default;
  V8MediaSessionPlaybackState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "paused",
                                                        "playing"};
};

inline bool operator==(const V8MediaSessionPlaybackState& lhs,
                       V8MediaSessionPlaybackState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8MediaSessionPlaybackState::Enum lhs,
                       const V8MediaSessionPlaybackState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_SESSION_PLAYBACK_STATE_H_
