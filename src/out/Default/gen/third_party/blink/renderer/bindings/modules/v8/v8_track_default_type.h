// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_TRACK_DEFAULT_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_TRACK_DEFAULT_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8TrackDefaultType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAudio, kVideo, kText };

  static V8TrackDefaultType Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "TrackDefaultType", exception_state);
    return result.has_value()
               ? V8TrackDefaultType(static_cast<Enum>(result.value()))
               : V8TrackDefaultType();
  }
  static base::Optional<V8TrackDefaultType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8TrackDefaultType(static_cast<Enum>(result.value()));
  }

  constexpr V8TrackDefaultType() = default;
  explicit constexpr V8TrackDefaultType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8TrackDefaultType(const V8TrackDefaultType&) = default;
  constexpr V8TrackDefaultType(V8TrackDefaultType&&) = default;
  ~V8TrackDefaultType() = default;

  V8TrackDefaultType& operator=(const V8TrackDefaultType&) = default;
  V8TrackDefaultType& operator=(V8TrackDefaultType&&) = default;
  V8TrackDefaultType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"audio", "video",
                                                        "text"};
};

inline bool operator==(const V8TrackDefaultType& lhs,
                       V8TrackDefaultType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8TrackDefaultType::Enum lhs,
                       const V8TrackDefaultType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_TRACK_DEFAULT_TYPE_H_
