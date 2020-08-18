// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_PIXEL_FORMAT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_PIXEL_FORMAT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ImagePixelFormat final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kUint8, kUint16 };

  static V8ImagePixelFormat Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ImagePixelFormat", exception_state);
    return result.has_value()
               ? V8ImagePixelFormat(static_cast<Enum>(result.value()))
               : V8ImagePixelFormat();
  }
  static base::Optional<V8ImagePixelFormat> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ImagePixelFormat(static_cast<Enum>(result.value()));
  }

  constexpr V8ImagePixelFormat() = default;
  explicit constexpr V8ImagePixelFormat(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ImagePixelFormat(const V8ImagePixelFormat&) = default;
  constexpr V8ImagePixelFormat(V8ImagePixelFormat&&) = default;
  ~V8ImagePixelFormat() = default;

  V8ImagePixelFormat& operator=(const V8ImagePixelFormat&) = default;
  V8ImagePixelFormat& operator=(V8ImagePixelFormat&&) = default;
  V8ImagePixelFormat& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"uint8", "uint16"};
};

inline bool operator==(const V8ImagePixelFormat& lhs,
                       V8ImagePixelFormat::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ImagePixelFormat::Enum lhs,
                       const V8ImagePixelFormat& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_PIXEL_FORMAT_H_
