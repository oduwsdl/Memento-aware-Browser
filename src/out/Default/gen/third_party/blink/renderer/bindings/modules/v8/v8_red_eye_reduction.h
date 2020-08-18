// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RED_EYE_REDUCTION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RED_EYE_REDUCTION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RedEyeReduction final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNever, kAlways, kControllable };

  static V8RedEyeReduction Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RedEyeReduction", exception_state);
    return result.has_value()
               ? V8RedEyeReduction(static_cast<Enum>(result.value()))
               : V8RedEyeReduction();
  }
  static base::Optional<V8RedEyeReduction> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RedEyeReduction(static_cast<Enum>(result.value()));
  }

  constexpr V8RedEyeReduction() = default;
  explicit constexpr V8RedEyeReduction(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RedEyeReduction(const V8RedEyeReduction&) = default;
  constexpr V8RedEyeReduction(V8RedEyeReduction&&) = default;
  ~V8RedEyeReduction() = default;

  V8RedEyeReduction& operator=(const V8RedEyeReduction&) = default;
  V8RedEyeReduction& operator=(V8RedEyeReduction&&) = default;
  V8RedEyeReduction& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"never", "always",
                                                        "controllable"};
};

inline bool operator==(const V8RedEyeReduction& lhs,
                       V8RedEyeReduction::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RedEyeReduction::Enum lhs,
                       const V8RedEyeReduction& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RED_EYE_REDUCTION_H_
