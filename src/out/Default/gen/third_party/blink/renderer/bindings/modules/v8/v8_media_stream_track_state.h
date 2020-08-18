// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_STREAM_TRACK_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_STREAM_TRACK_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8MediaStreamTrackState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kLive, kEnded };

  static V8MediaStreamTrackState Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "MediaStreamTrackState",
        exception_state);
    return result.has_value()
               ? V8MediaStreamTrackState(static_cast<Enum>(result.value()))
               : V8MediaStreamTrackState();
  }
  static base::Optional<V8MediaStreamTrackState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8MediaStreamTrackState(static_cast<Enum>(result.value()));
  }

  constexpr V8MediaStreamTrackState() = default;
  explicit constexpr V8MediaStreamTrackState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8MediaStreamTrackState(const V8MediaStreamTrackState&) = default;
  constexpr V8MediaStreamTrackState(V8MediaStreamTrackState&&) = default;
  ~V8MediaStreamTrackState() = default;

  V8MediaStreamTrackState& operator=(const V8MediaStreamTrackState&) = default;
  V8MediaStreamTrackState& operator=(V8MediaStreamTrackState&&) = default;
  V8MediaStreamTrackState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"live", "ended"};
};

inline bool operator==(const V8MediaStreamTrackState& lhs,
                       V8MediaStreamTrackState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8MediaStreamTrackState::Enum lhs,
                       const V8MediaStreamTrackState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_STREAM_TRACK_STATE_H_
