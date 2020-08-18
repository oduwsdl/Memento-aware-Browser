// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_ADDRESS_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_ADDRESS_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUAddressMode final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kClampToEdge, kRepeat, kMirrorRepeat };

  static V8GPUAddressMode Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUAddressMode", exception_state);
    return result.has_value()
               ? V8GPUAddressMode(static_cast<Enum>(result.value()))
               : V8GPUAddressMode();
  }
  static base::Optional<V8GPUAddressMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUAddressMode(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUAddressMode() = default;
  explicit constexpr V8GPUAddressMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUAddressMode(const V8GPUAddressMode&) = default;
  constexpr V8GPUAddressMode(V8GPUAddressMode&&) = default;
  ~V8GPUAddressMode() = default;

  V8GPUAddressMode& operator=(const V8GPUAddressMode&) = default;
  V8GPUAddressMode& operator=(V8GPUAddressMode&&) = default;
  V8GPUAddressMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "clamp-to-edge", "repeat", "mirror-repeat"};
};

inline bool operator==(const V8GPUAddressMode& lhs,
                       V8GPUAddressMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUAddressMode::Enum lhs,
                       const V8GPUAddressMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_ADDRESS_MODE_H_
