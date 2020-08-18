// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_OFFSCREEN_RENDERING_CONTEXT_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_OFFSCREEN_RENDERING_CONTEXT_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8OffscreenRenderingContextType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    k2D,
    kWebGL,
    kWebGL2,
    kWebGL2Compute,
    kBitmaprenderer
  };

  static V8OffscreenRenderingContextType Create(
      v8::Isolate* isolate,
      v8::Local<v8::Value> value,
      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "OffscreenRenderingContextType",
        exception_state);
    return result.has_value() ? V8OffscreenRenderingContextType(
                                    static_cast<Enum>(result.value()))
                              : V8OffscreenRenderingContextType();
  }
  static base::Optional<V8OffscreenRenderingContextType> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8OffscreenRenderingContextType(static_cast<Enum>(result.value()));
  }

  constexpr V8OffscreenRenderingContextType() = default;
  explicit constexpr V8OffscreenRenderingContextType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8OffscreenRenderingContextType(
      const V8OffscreenRenderingContextType&) = default;
  constexpr V8OffscreenRenderingContextType(V8OffscreenRenderingContextType&&) =
      default;
  ~V8OffscreenRenderingContextType() = default;

  V8OffscreenRenderingContextType& operator=(
      const V8OffscreenRenderingContextType&) = default;
  V8OffscreenRenderingContextType& operator=(
      V8OffscreenRenderingContextType&&) = default;
  V8OffscreenRenderingContextType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "2d", "webgl", "webgl2", "webgl2-compute", "bitmaprenderer"};
};

inline bool operator==(const V8OffscreenRenderingContextType& lhs,
                       V8OffscreenRenderingContextType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8OffscreenRenderingContextType::Enum lhs,
                       const V8OffscreenRenderingContextType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_OFFSCREEN_RENDERING_CONTEXT_TYPE_H_
