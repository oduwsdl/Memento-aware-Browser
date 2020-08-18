// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CANVAS_COLOR_SPACE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CANVAS_COLOR_SPACE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8CanvasColorSpace final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kSRGB, kRec2020, kP3 };

  static V8CanvasColorSpace Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "CanvasColorSpace", exception_state);
    return result.has_value()
               ? V8CanvasColorSpace(static_cast<Enum>(result.value()))
               : V8CanvasColorSpace();
  }
  static base::Optional<V8CanvasColorSpace> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8CanvasColorSpace(static_cast<Enum>(result.value()));
  }

  constexpr V8CanvasColorSpace() = default;
  explicit constexpr V8CanvasColorSpace(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8CanvasColorSpace(const V8CanvasColorSpace&) = default;
  constexpr V8CanvasColorSpace(V8CanvasColorSpace&&) = default;
  ~V8CanvasColorSpace() = default;

  V8CanvasColorSpace& operator=(const V8CanvasColorSpace&) = default;
  V8CanvasColorSpace& operator=(V8CanvasColorSpace&&) = default;
  V8CanvasColorSpace& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"srgb", "rec2020",
                                                        "p3"};
};

inline bool operator==(const V8CanvasColorSpace& lhs,
                       V8CanvasColorSpace::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8CanvasColorSpace::Enum lhs,
                       const V8CanvasColorSpace& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CANVAS_COLOR_SPACE_H_
