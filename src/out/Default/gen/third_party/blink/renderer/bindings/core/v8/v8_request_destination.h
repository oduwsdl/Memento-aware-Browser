// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_DESTINATION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_DESTINATION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8RequestDestination final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    k,
    kAudio,
    kAudioworklet,
    kDocument,
    kEmbed,
    kFont,
    kFrame,
    kIFrame,
    kImage,
    kManifest,
    kObject,
    kPaintworklet,
    kReport,
    kScript,
    kSharedworker,
    kStyle,
    kTrack,
    kVideo,
    kWorker,
    kXslt
  };

  static V8RequestDestination Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RequestDestination", exception_state);
    return result.has_value()
               ? V8RequestDestination(static_cast<Enum>(result.value()))
               : V8RequestDestination();
  }
  static base::Optional<V8RequestDestination> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RequestDestination(static_cast<Enum>(result.value()));
  }

  constexpr V8RequestDestination() = default;
  explicit constexpr V8RequestDestination(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RequestDestination(const V8RequestDestination&) = default;
  constexpr V8RequestDestination(V8RequestDestination&&) = default;
  ~V8RequestDestination() = default;

  V8RequestDestination& operator=(const V8RequestDestination&) = default;
  V8RequestDestination& operator=(V8RequestDestination&&) = default;
  V8RequestDestination& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "",       "audio",        "audioworklet", "document", "embed",
      "font",   "frame",        "iframe",       "image",    "manifest",
      "object", "paintworklet", "report",       "script",   "sharedworker",
      "style",  "track",        "video",        "worker",   "xslt"};
};

inline bool operator==(const V8RequestDestination& lhs,
                       V8RequestDestination::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RequestDestination::Enum lhs,
                       const V8RequestDestination& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_DESTINATION_H_
