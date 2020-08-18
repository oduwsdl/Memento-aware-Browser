// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_DIMENSION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_DIMENSION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUTextureDimension final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { k1d, k2D, k3d };

  static V8GPUTextureDimension Create(v8::Isolate* isolate,
                                      v8::Local<v8::Value> value,
                                      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUTextureDimension", exception_state);
    return result.has_value()
               ? V8GPUTextureDimension(static_cast<Enum>(result.value()))
               : V8GPUTextureDimension();
  }
  static base::Optional<V8GPUTextureDimension> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUTextureDimension(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUTextureDimension() = default;
  explicit constexpr V8GPUTextureDimension(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUTextureDimension(const V8GPUTextureDimension&) = default;
  constexpr V8GPUTextureDimension(V8GPUTextureDimension&&) = default;
  ~V8GPUTextureDimension() = default;

  V8GPUTextureDimension& operator=(const V8GPUTextureDimension&) = default;
  V8GPUTextureDimension& operator=(V8GPUTextureDimension&&) = default;
  V8GPUTextureDimension& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"1d", "2d", "3d"};
};

inline bool operator==(const V8GPUTextureDimension& lhs,
                       V8GPUTextureDimension::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUTextureDimension::Enum lhs,
                       const V8GPUTextureDimension& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_DIMENSION_H_
