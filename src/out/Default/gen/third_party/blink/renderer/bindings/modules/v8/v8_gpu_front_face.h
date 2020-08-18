// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_FRONT_FACE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_FRONT_FACE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUFrontFace final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kCcw, kCw };

  static V8GPUFrontFace Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUFrontFace", exception_state);
    return result.has_value()
               ? V8GPUFrontFace(static_cast<Enum>(result.value()))
               : V8GPUFrontFace();
  }
  static base::Optional<V8GPUFrontFace> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUFrontFace(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUFrontFace() = default;
  explicit constexpr V8GPUFrontFace(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUFrontFace(const V8GPUFrontFace&) = default;
  constexpr V8GPUFrontFace(V8GPUFrontFace&&) = default;
  ~V8GPUFrontFace() = default;

  V8GPUFrontFace& operator=(const V8GPUFrontFace&) = default;
  V8GPUFrontFace& operator=(V8GPUFrontFace&&) = default;
  V8GPUFrontFace& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"ccw", "cw"};
};

inline bool operator==(const V8GPUFrontFace& lhs, V8GPUFrontFace::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUFrontFace::Enum lhs, const V8GPUFrontFace& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_FRONT_FACE_H_
