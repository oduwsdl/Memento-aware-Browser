// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_DECODING_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_DECODING_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8MediaDecodingType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kFile, kMediaSource };

  static V8MediaDecodingType Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "MediaDecodingType", exception_state);
    return result.has_value()
               ? V8MediaDecodingType(static_cast<Enum>(result.value()))
               : V8MediaDecodingType();
  }
  static base::Optional<V8MediaDecodingType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8MediaDecodingType(static_cast<Enum>(result.value()));
  }

  constexpr V8MediaDecodingType() = default;
  explicit constexpr V8MediaDecodingType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8MediaDecodingType(const V8MediaDecodingType&) = default;
  constexpr V8MediaDecodingType(V8MediaDecodingType&&) = default;
  ~V8MediaDecodingType() = default;

  V8MediaDecodingType& operator=(const V8MediaDecodingType&) = default;
  V8MediaDecodingType& operator=(V8MediaDecodingType&&) = default;
  V8MediaDecodingType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"file", "media-source"};
};

inline bool operator==(const V8MediaDecodingType& lhs,
                       V8MediaDecodingType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8MediaDecodingType::Enum lhs,
                       const V8MediaDecodingType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_DECODING_TYPE_H_
