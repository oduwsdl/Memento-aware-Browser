// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_BITMAP_PIXEL_FORMAT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_BITMAP_PIXEL_FORMAT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ImageBitmapPixelFormat final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kDefault, kUint8 };

  static V8ImageBitmapPixelFormat Create(v8::Isolate* isolate,
                                         v8::Local<v8::Value> value,
                                         ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ImageBitmapPixelFormat",
        exception_state);
    return result.has_value()
               ? V8ImageBitmapPixelFormat(static_cast<Enum>(result.value()))
               : V8ImageBitmapPixelFormat();
  }
  static base::Optional<V8ImageBitmapPixelFormat> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ImageBitmapPixelFormat(static_cast<Enum>(result.value()));
  }

  constexpr V8ImageBitmapPixelFormat() = default;
  explicit constexpr V8ImageBitmapPixelFormat(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ImageBitmapPixelFormat(const V8ImageBitmapPixelFormat&) = default;
  constexpr V8ImageBitmapPixelFormat(V8ImageBitmapPixelFormat&&) = default;
  ~V8ImageBitmapPixelFormat() = default;

  V8ImageBitmapPixelFormat& operator=(const V8ImageBitmapPixelFormat&) =
      default;
  V8ImageBitmapPixelFormat& operator=(V8ImageBitmapPixelFormat&&) = default;
  V8ImageBitmapPixelFormat& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"default", "uint8"};
};

inline bool operator==(const V8ImageBitmapPixelFormat& lhs,
                       V8ImageBitmapPixelFormat::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ImageBitmapPixelFormat::Enum lhs,
                       const V8ImageBitmapPixelFormat& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_BITMAP_PIXEL_FORMAT_H_
