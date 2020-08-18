// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_REMOTE_PLAYBACK_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_REMOTE_PLAYBACK_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RemotePlaybackState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kConnecting, kConnected, kDisconnected };

  static V8RemotePlaybackState Create(v8::Isolate* isolate,
                                      v8::Local<v8::Value> value,
                                      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RemotePlaybackState", exception_state);
    return result.has_value()
               ? V8RemotePlaybackState(static_cast<Enum>(result.value()))
               : V8RemotePlaybackState();
  }
  static base::Optional<V8RemotePlaybackState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RemotePlaybackState(static_cast<Enum>(result.value()));
  }

  constexpr V8RemotePlaybackState() = default;
  explicit constexpr V8RemotePlaybackState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RemotePlaybackState(const V8RemotePlaybackState&) = default;
  constexpr V8RemotePlaybackState(V8RemotePlaybackState&&) = default;
  ~V8RemotePlaybackState() = default;

  V8RemotePlaybackState& operator=(const V8RemotePlaybackState&) = default;
  V8RemotePlaybackState& operator=(V8RemotePlaybackState&&) = default;
  V8RemotePlaybackState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "connecting", "connected", "disconnected"};
};

inline bool operator==(const V8RemotePlaybackState& lhs,
                       V8RemotePlaybackState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RemotePlaybackState::Enum lhs,
                       const V8RemotePlaybackState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_REMOTE_PLAYBACK_STATE_H_
