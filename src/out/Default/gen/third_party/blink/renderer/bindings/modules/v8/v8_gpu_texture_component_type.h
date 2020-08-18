// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_COMPONENT_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_COMPONENT_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUTextureComponentType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kFloat, kSint, kUint };

  static V8GPUTextureComponentType Create(v8::Isolate* isolate,
                                          v8::Local<v8::Value> value,
                                          ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUTextureComponentType",
        exception_state);
    return result.has_value()
               ? V8GPUTextureComponentType(static_cast<Enum>(result.value()))
               : V8GPUTextureComponentType();
  }
  static base::Optional<V8GPUTextureComponentType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUTextureComponentType(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUTextureComponentType() = default;
  explicit constexpr V8GPUTextureComponentType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUTextureComponentType(const V8GPUTextureComponentType&) =
      default;
  constexpr V8GPUTextureComponentType(V8GPUTextureComponentType&&) = default;
  ~V8GPUTextureComponentType() = default;

  V8GPUTextureComponentType& operator=(const V8GPUTextureComponentType&) =
      default;
  V8GPUTextureComponentType& operator=(V8GPUTextureComponentType&&) = default;
  V8GPUTextureComponentType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"float", "sint",
                                                        "uint"};
};

inline bool operator==(const V8GPUTextureComponentType& lhs,
                       V8GPUTextureComponentType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUTextureComponentType::Enum lhs,
                       const V8GPUTextureComponentType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_TEXTURE_COMPONENT_TYPE_H_
