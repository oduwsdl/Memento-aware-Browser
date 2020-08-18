// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_SESSION_ACTION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_SESSION_ACTION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8MediaSessionAction final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kPlay,
    kPause,
    kPrevioustrack,
    kNexttrack,
    kSeekbackward,
    kSeekforward,
    kSkipad,
    kStop,
    kSeekto
  };

  static V8MediaSessionAction Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "MediaSessionAction", exception_state);
    return result.has_value()
               ? V8MediaSessionAction(static_cast<Enum>(result.value()))
               : V8MediaSessionAction();
  }
  static base::Optional<V8MediaSessionAction> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8MediaSessionAction(static_cast<Enum>(result.value()));
  }

  constexpr V8MediaSessionAction() = default;
  explicit constexpr V8MediaSessionAction(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8MediaSessionAction(const V8MediaSessionAction&) = default;
  constexpr V8MediaSessionAction(V8MediaSessionAction&&) = default;
  ~V8MediaSessionAction() = default;

  V8MediaSessionAction& operator=(const V8MediaSessionAction&) = default;
  V8MediaSessionAction& operator=(V8MediaSessionAction&&) = default;
  V8MediaSessionAction& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "play",        "pause",  "previoustrack", "nexttrack", "seekbackward",
      "seekforward", "skipad", "stop",          "seekto"};
};

inline bool operator==(const V8MediaSessionAction& lhs,
                       V8MediaSessionAction::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8MediaSessionAction::Enum lhs,
                       const V8MediaSessionAction& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_SESSION_ACTION_H_
