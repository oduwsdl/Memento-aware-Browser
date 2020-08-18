// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MIDI_PORT_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MIDI_PORT_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8MIDIPortType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kInput, kOutput };

  static V8MIDIPortType Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "MIDIPortType", exception_state);
    return result.has_value()
               ? V8MIDIPortType(static_cast<Enum>(result.value()))
               : V8MIDIPortType();
  }
  static base::Optional<V8MIDIPortType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8MIDIPortType(static_cast<Enum>(result.value()));
  }

  constexpr V8MIDIPortType() = default;
  explicit constexpr V8MIDIPortType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8MIDIPortType(const V8MIDIPortType&) = default;
  constexpr V8MIDIPortType(V8MIDIPortType&&) = default;
  ~V8MIDIPortType() = default;

  V8MIDIPortType& operator=(const V8MIDIPortType&) = default;
  V8MIDIPortType& operator=(V8MIDIPortType&&) = default;
  V8MIDIPortType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"input", "output"};
};

inline bool operator==(const V8MIDIPortType& lhs, V8MIDIPortType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8MIDIPortType::Enum lhs, const V8MIDIPortType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MIDI_PORT_TYPE_H_
