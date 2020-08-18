// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_EXTENSION_NAME_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_EXTENSION_NAME_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUExtensionName final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kTextureCompressionBC };

  static V8GPUExtensionName Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUExtensionName", exception_state);
    return result.has_value()
               ? V8GPUExtensionName(static_cast<Enum>(result.value()))
               : V8GPUExtensionName();
  }
  static base::Optional<V8GPUExtensionName> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUExtensionName(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUExtensionName() = default;
  explicit constexpr V8GPUExtensionName(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUExtensionName(const V8GPUExtensionName&) = default;
  constexpr V8GPUExtensionName(V8GPUExtensionName&&) = default;
  ~V8GPUExtensionName() = default;

  V8GPUExtensionName& operator=(const V8GPUExtensionName&) = default;
  V8GPUExtensionName& operator=(V8GPUExtensionName&&) = default;
  V8GPUExtensionName& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"textureCompressionBC"};
};

inline bool operator==(const V8GPUExtensionName& lhs,
                       V8GPUExtensionName::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUExtensionName::Enum lhs,
                       const V8GPUExtensionName& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_EXTENSION_NAME_H_
