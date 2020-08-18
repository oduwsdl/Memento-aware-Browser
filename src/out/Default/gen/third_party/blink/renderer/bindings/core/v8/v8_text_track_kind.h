// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_TEXT_TRACK_KIND_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_TEXT_TRACK_KIND_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8TextTrackKind final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kSubtitles,
    kCaptions,
    kDescriptions,
    kChapters,
    kMetadata
  };

  static V8TextTrackKind Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "TextTrackKind", exception_state);
    return result.has_value()
               ? V8TextTrackKind(static_cast<Enum>(result.value()))
               : V8TextTrackKind();
  }
  static base::Optional<V8TextTrackKind> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8TextTrackKind(static_cast<Enum>(result.value()));
  }

  constexpr V8TextTrackKind() = default;
  explicit constexpr V8TextTrackKind(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8TextTrackKind(const V8TextTrackKind&) = default;
  constexpr V8TextTrackKind(V8TextTrackKind&&) = default;
  ~V8TextTrackKind() = default;

  V8TextTrackKind& operator=(const V8TextTrackKind&) = default;
  V8TextTrackKind& operator=(V8TextTrackKind&&) = default;
  V8TextTrackKind& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "subtitles", "captions", "descriptions", "chapters", "metadata"};
};

inline bool operator==(const V8TextTrackKind& lhs, V8TextTrackKind::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8TextTrackKind::Enum lhs, const V8TextTrackKind& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_TEXT_TRACK_KIND_H_
