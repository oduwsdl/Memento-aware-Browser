// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_ENCODED_VIDEO_CHUNK_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_ENCODED_VIDEO_CHUNK_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8EncodedVideoChunkType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kKey, kDelta };

  static V8EncodedVideoChunkType Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "EncodedVideoChunkType",
        exception_state);
    return result.has_value()
               ? V8EncodedVideoChunkType(static_cast<Enum>(result.value()))
               : V8EncodedVideoChunkType();
  }
  static base::Optional<V8EncodedVideoChunkType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8EncodedVideoChunkType(static_cast<Enum>(result.value()));
  }

  constexpr V8EncodedVideoChunkType() = default;
  explicit constexpr V8EncodedVideoChunkType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8EncodedVideoChunkType(const V8EncodedVideoChunkType&) = default;
  constexpr V8EncodedVideoChunkType(V8EncodedVideoChunkType&&) = default;
  ~V8EncodedVideoChunkType() = default;

  V8EncodedVideoChunkType& operator=(const V8EncodedVideoChunkType&) = default;
  V8EncodedVideoChunkType& operator=(V8EncodedVideoChunkType&&) = default;
  V8EncodedVideoChunkType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"key", "delta"};
};

inline bool operator==(const V8EncodedVideoChunkType& lhs,
                       V8EncodedVideoChunkType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8EncodedVideoChunkType::Enum lhs,
                       const V8EncodedVideoChunkType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_ENCODED_VIDEO_CHUNK_TYPE_H_
