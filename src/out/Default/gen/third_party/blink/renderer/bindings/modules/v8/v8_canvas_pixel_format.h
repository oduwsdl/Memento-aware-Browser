// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CANVAS_PIXEL_FORMAT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CANVAS_PIXEL_FORMAT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8CanvasPixelFormat final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kUint8, k1010102, k12121212, kFloat16 };

  static V8CanvasPixelFormat Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "CanvasPixelFormat", exception_state);
    return result.has_value()
               ? V8CanvasPixelFormat(static_cast<Enum>(result.value()))
               : V8CanvasPixelFormat();
  }
  static base::Optional<V8CanvasPixelFormat> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8CanvasPixelFormat(static_cast<Enum>(result.value()));
  }

  constexpr V8CanvasPixelFormat() = default;
  explicit constexpr V8CanvasPixelFormat(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8CanvasPixelFormat(const V8CanvasPixelFormat&) = default;
  constexpr V8CanvasPixelFormat(V8CanvasPixelFormat&&) = default;
  ~V8CanvasPixelFormat() = default;

  V8CanvasPixelFormat& operator=(const V8CanvasPixelFormat&) = default;
  V8CanvasPixelFormat& operator=(V8CanvasPixelFormat&&) = default;
  V8CanvasPixelFormat& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "uint8", "10-10-10-2", "12-12-12-12", "float16"};
};

inline bool operator==(const V8CanvasPixelFormat& lhs,
                       V8CanvasPixelFormat::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8CanvasPixelFormat::Enum lhs,
                       const V8CanvasPixelFormat& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CANVAS_PIXEL_FORMAT_H_
