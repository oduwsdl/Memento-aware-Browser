// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_FORMAT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_FORMAT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUTextureFormat final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kR8Unorm,
    kR8Snorm,
    kR8Uint,
    kR8Sint,
    kR16Uint,
    kR16Sint,
    kR16Float,
    kRg8Unorm,
    kRg8Snorm,
    kRg8Uint,
    kRg8Sint,
    kR32Uint,
    kR32Sint,
    kR32Float,
    kRg16Uint,
    kRg16Sint,
    kRg16Float,
    kRgba8Unorm,
    kRgba8UnormSrgb,
    kRgba8Snorm,
    kRgba8Uint,
    kRgba8Sint,
    kBgra8Unorm,
    kBgra8UnormSrgb,
    kRgb10A2Unorm,
    kRg11B10Float,
    kRg32Uint,
    kRg32Sint,
    kRg32Float,
    kRgba16Uint,
    kRgba16Sint,
    kRgba16Float,
    kRgba32Uint,
    kRgba32Sint,
    kRgba32Float,
    kDepth32Float,
    kDepth24Plus,
    kDepth24PlusStencil8,
    kBc1RgbaUnorm,
    kBc1RgbaUnormSrgb,
    kBc2RgbaUnorm,
    kBc2RgbaUnormSrgb,
    kBc3RgbaUnorm,
    kBc3RgbaUnormSrgb,
    kBc4RUnorm,
    kBc4RSnorm,
    kBc5RgUnorm,
    kBc5RgSnorm,
    kBc6HRgbUfloat,
    kBc6HRgbSfloat,
    kBc7RgbaUnorm,
    kBc7RgbaUnormSrgb
  };

  static V8GPUTextureFormat Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUTextureFormat", exception_state);
    return result.has_value()
               ? V8GPUTextureFormat(static_cast<Enum>(result.value()))
               : V8GPUTextureFormat();
  }
  static base::Optional<V8GPUTextureFormat> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUTextureFormat(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUTextureFormat() = default;
  explicit constexpr V8GPUTextureFormat(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUTextureFormat(const V8GPUTextureFormat&) = default;
  constexpr V8GPUTextureFormat(V8GPUTextureFormat&&) = default;
  ~V8GPUTextureFormat() = default;

  V8GPUTextureFormat& operator=(const V8GPUTextureFormat&) = default;
  V8GPUTextureFormat& operator=(V8GPUTextureFormat&&) = default;
  V8GPUTextureFormat& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "r8unorm",         "r8snorm",
      "r8uint",          "r8sint",
      "r16uint",         "r16sint",
      "r16float",        "rg8unorm",
      "rg8snorm",        "rg8uint",
      "rg8sint",         "r32uint",
      "r32sint",         "r32float",
      "rg16uint",        "rg16sint",
      "rg16float",       "rgba8unorm",
      "rgba8unorm-srgb", "rgba8snorm",
      "rgba8uint",       "rgba8sint",
      "bgra8unorm",      "bgra8unorm-srgb",
      "rgb10a2unorm",    "rg11b10float",
      "rg32uint",        "rg32sint",
      "rg32float",       "rgba16uint",
      "rgba16sint",      "rgba16float",
      "rgba32uint",      "rgba32sint",
      "rgba32float",     "depth32float",
      "depth24plus",     "depth24plus-stencil8",
      "bc1-rgba-unorm",  "bc1-rgba-unorm-srgb",
      "bc2-rgba-unorm",  "bc2-rgba-unorm-srgb",
      "bc3-rgba-unorm",  "bc3-rgba-unorm-srgb",
      "bc4-r-unorm",     "bc4-r-snorm",
      "bc5-rg-unorm",    "bc5-rg-snorm",
      "bc6h-rgb-ufloat", "bc6h-rgb-sfloat",
      "bc7-rgba-unorm",  "bc7-rgba-unorm-srgb"};
};

inline bool operator==(const V8GPUTextureFormat& lhs,
                       V8GPUTextureFormat::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUTextureFormat::Enum lhs,
                       const V8GPUTextureFormat& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_FORMAT_H_
