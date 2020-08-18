// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RECORDING_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RECORDING_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RecordingState final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kInactive, kRecording, kPaused };

  static V8RecordingState Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RecordingState", exception_state);
    return result.has_value()
               ? V8RecordingState(static_cast<Enum>(result.value()))
               : V8RecordingState();
  }
  static base::Optional<V8RecordingState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RecordingState(static_cast<Enum>(result.value()));
  }

  constexpr V8RecordingState() = default;
  explicit constexpr V8RecordingState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RecordingState(const V8RecordingState&) = default;
  constexpr V8RecordingState(V8RecordingState&&) = default;
  ~V8RecordingState() = default;

  V8RecordingState& operator=(const V8RecordingState&) = default;
  V8RecordingState& operator=(V8RecordingState&&) = default;
  V8RecordingState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"inactive", "recording",
                                                        "paused"};
};

inline bool operator==(const V8RecordingState& lhs,
                       V8RecordingState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RecordingState::Enum lhs,
                       const V8RecordingState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RECORDING_STATE_H_
