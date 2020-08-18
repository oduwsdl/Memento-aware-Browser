// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_TEXT_TRACK_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_TEXT_TRACK_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8TextTrackMode final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kDisabled, kHidden, kShowing };

  static V8TextTrackMode Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "TextTrackMode", exception_state);
    return result.has_value()
               ? V8TextTrackMode(static_cast<Enum>(result.value()))
               : V8TextTrackMode();
  }
  static base::Optional<V8TextTrackMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8TextTrackMode(static_cast<Enum>(result.value()));
  }

  constexpr V8TextTrackMode() = default;
  explicit constexpr V8TextTrackMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8TextTrackMode(const V8TextTrackMode&) = default;
  constexpr V8TextTrackMode(V8TextTrackMode&&) = default;
  ~V8TextTrackMode() = default;

  V8TextTrackMode& operator=(const V8TextTrackMode&) = default;
  V8TextTrackMode& operator=(V8TextTrackMode&&) = default;
  V8TextTrackMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"disabled", "hidden",
                                                        "showing"};
};

inline bool operator==(const V8TextTrackMode& lhs, V8TextTrackMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8TextTrackMode::Enum lhs, const V8TextTrackMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_TEXT_TRACK_MODE_H_
