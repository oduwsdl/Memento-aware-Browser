// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MIDI_PORT_CONNECTION_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MIDI_PORT_CONNECTION_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8MIDIPortConnectionState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kOpen, kClosed, kPending };

  static V8MIDIPortConnectionState Create(v8::Isolate* isolate,
                                          v8::Local<v8::Value> value,
                                          ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "MIDIPortConnectionState",
        exception_state);
    return result.has_value()
               ? V8MIDIPortConnectionState(static_cast<Enum>(result.value()))
               : V8MIDIPortConnectionState();
  }
  static base::Optional<V8MIDIPortConnectionState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8MIDIPortConnectionState(static_cast<Enum>(result.value()));
  }

  constexpr V8MIDIPortConnectionState() = default;
  explicit constexpr V8MIDIPortConnectionState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8MIDIPortConnectionState(const V8MIDIPortConnectionState&) =
      default;
  constexpr V8MIDIPortConnectionState(V8MIDIPortConnectionState&&) = default;
  ~V8MIDIPortConnectionState() = default;

  V8MIDIPortConnectionState& operator=(const V8MIDIPortConnectionState&) =
      default;
  V8MIDIPortConnectionState& operator=(V8MIDIPortConnectionState&&) = default;
  V8MIDIPortConnectionState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"open", "closed",
                                                        "pending"};
};

inline bool operator==(const V8MIDIPortConnectionState& lhs,
                       V8MIDIPortConnectionState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8MIDIPortConnectionState::Enum lhs,
                       const V8MIDIPortConnectionState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MIDI_PORT_CONNECTION_STATE_H_
