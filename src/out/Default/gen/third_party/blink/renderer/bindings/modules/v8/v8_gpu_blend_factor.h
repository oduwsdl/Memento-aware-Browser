// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_BLEND_FACTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_BLEND_FACTOR_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUBlendFactor final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kZero,
    kOne,
    kSrcColor,
    kOneMinusSrcColor,
    kSrcAlpha,
    kOneMinusSrcAlpha,
    kDstColor,
    kOneMinusDstColor,
    kDstAlpha,
    kOneMinusDstAlpha,
    kSrcAlphaSaturated,
    kBlendColor,
    kOneMinusBlendColor
  };

  static V8GPUBlendFactor Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUBlendFactor", exception_state);
    return result.has_value()
               ? V8GPUBlendFactor(static_cast<Enum>(result.value()))
               : V8GPUBlendFactor();
  }
  static base::Optional<V8GPUBlendFactor> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUBlendFactor(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUBlendFactor() = default;
  explicit constexpr V8GPUBlendFactor(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUBlendFactor(const V8GPUBlendFactor&) = default;
  constexpr V8GPUBlendFactor(V8GPUBlendFactor&&) = default;
  ~V8GPUBlendFactor() = default;

  V8GPUBlendFactor& operator=(const V8GPUBlendFactor&) = default;
  V8GPUBlendFactor& operator=(V8GPUBlendFactor&&) = default;
  V8GPUBlendFactor& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "zero",
      "one",
      "src-color",
      "one-minus-src-color",
      "src-alpha",
      "one-minus-src-alpha",
      "dst-color",
      "one-minus-dst-color",
      "dst-alpha",
      "one-minus-dst-alpha",
      "src-alpha-saturated",
      "blend-color",
      "one-minus-blend-color"};
};

inline bool operator==(const V8GPUBlendFactor& lhs,
                       V8GPUBlendFactor::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUBlendFactor::Enum lhs,
                       const V8GPUBlendFactor& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_BLEND_FACTOR_H_
