// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_PRIMITIVE_TOPOLOGY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_PRIMITIVE_TOPOLOGY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUPrimitiveTopology final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kPointList,
    kLineList,
    kLineStrip,
    kTriangleList,
    kTriangleStrip
  };

  static V8GPUPrimitiveTopology Create(v8::Isolate* isolate,
                                       v8::Local<v8::Value> value,
                                       ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUPrimitiveTopology", exception_state);
    return result.has_value()
               ? V8GPUPrimitiveTopology(static_cast<Enum>(result.value()))
               : V8GPUPrimitiveTopology();
  }
  static base::Optional<V8GPUPrimitiveTopology> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUPrimitiveTopology(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUPrimitiveTopology() = default;
  explicit constexpr V8GPUPrimitiveTopology(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUPrimitiveTopology(const V8GPUPrimitiveTopology&) = default;
  constexpr V8GPUPrimitiveTopology(V8GPUPrimitiveTopology&&) = default;
  ~V8GPUPrimitiveTopology() = default;

  V8GPUPrimitiveTopology& operator=(const V8GPUPrimitiveTopology&) = default;
  V8GPUPrimitiveTopology& operator=(V8GPUPrimitiveTopology&&) = default;
  V8GPUPrimitiveTopology& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "point-list", "line-list", "line-strip", "triangle-list",
      "triangle-strip"};
};

inline bool operator==(const V8GPUPrimitiveTopology& lhs,
                       V8GPUPrimitiveTopology::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUPrimitiveTopology::Enum lhs,
                       const V8GPUPrimitiveTopology& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_PRIMITIVE_TOPOLOGY_H_
