// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_HID_UNIT_SYSTEM_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_HID_UNIT_SYSTEM_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8HIDUnitSystem final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kNone,
    kSiLinear,
    kSiRotation,
    kEnglishLinear,
    kEnglishRotation,
    kVendorDefined,
    kReserved
  };

  static V8HIDUnitSystem Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "HIDUnitSystem", exception_state);
    return result.has_value()
               ? V8HIDUnitSystem(static_cast<Enum>(result.value()))
               : V8HIDUnitSystem();
  }
  static base::Optional<V8HIDUnitSystem> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8HIDUnitSystem(static_cast<Enum>(result.value()));
  }

  constexpr V8HIDUnitSystem() = default;
  explicit constexpr V8HIDUnitSystem(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8HIDUnitSystem(const V8HIDUnitSystem&) = default;
  constexpr V8HIDUnitSystem(V8HIDUnitSystem&&) = default;
  ~V8HIDUnitSystem() = default;

  V8HIDUnitSystem& operator=(const V8HIDUnitSystem&) = default;
  V8HIDUnitSystem& operator=(V8HIDUnitSystem&&) = default;
  V8HIDUnitSystem& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "none",           "si-linear",        "si-rotation",
      "english-linear", "english-rotation", "vendor-defined",
      "reserved"};
};

inline bool operator==(const V8HIDUnitSystem& lhs, V8HIDUnitSystem::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8HIDUnitSystem::Enum lhs, const V8HIDUnitSystem& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_HID_UNIT_SYSTEM_H_
