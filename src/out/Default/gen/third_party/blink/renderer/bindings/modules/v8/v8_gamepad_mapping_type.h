// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GAMEPAD_MAPPING_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GAMEPAD_MAPPING_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GamepadMappingType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { k, kStandard, kXRStandard };

  static V8GamepadMappingType Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GamepadMappingType", exception_state);
    return result.has_value()
               ? V8GamepadMappingType(static_cast<Enum>(result.value()))
               : V8GamepadMappingType();
  }
  static base::Optional<V8GamepadMappingType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GamepadMappingType(static_cast<Enum>(result.value()));
  }

  constexpr V8GamepadMappingType() = default;
  explicit constexpr V8GamepadMappingType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GamepadMappingType(const V8GamepadMappingType&) = default;
  constexpr V8GamepadMappingType(V8GamepadMappingType&&) = default;
  ~V8GamepadMappingType() = default;

  V8GamepadMappingType& operator=(const V8GamepadMappingType&) = default;
  V8GamepadMappingType& operator=(V8GamepadMappingType&&) = default;
  V8GamepadMappingType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"", "standard",
                                                        "xr-standard"};
};

inline bool operator==(const V8GamepadMappingType& lhs,
                       V8GamepadMappingType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GamepadMappingType::Enum lhs,
                       const V8GamepadMappingType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GAMEPAD_MAPPING_TYPE_H_
