// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_ASPECT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_ASPECT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUTextureAspect final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAll, kStencilOnly, kDepthOnly };

  static V8GPUTextureAspect Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUTextureAspect", exception_state);
    return result.has_value()
               ? V8GPUTextureAspect(static_cast<Enum>(result.value()))
               : V8GPUTextureAspect();
  }
  static base::Optional<V8GPUTextureAspect> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUTextureAspect(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUTextureAspect() = default;
  explicit constexpr V8GPUTextureAspect(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUTextureAspect(const V8GPUTextureAspect&) = default;
  constexpr V8GPUTextureAspect(V8GPUTextureAspect&&) = default;
  ~V8GPUTextureAspect() = default;

  V8GPUTextureAspect& operator=(const V8GPUTextureAspect&) = default;
  V8GPUTextureAspect& operator=(V8GPUTextureAspect&&) = default;
  V8GPUTextureAspect& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"all", "stencil-only",
                                                        "depth-only"};
};

inline bool operator==(const V8GPUTextureAspect& lhs,
                       V8GPUTextureAspect::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUTextureAspect::Enum lhs,
                       const V8GPUTextureAspect& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_ASPECT_H_
