// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_REQUEST_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_REQUEST_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8USBRequestType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kStandard, kClass, kVendor };

  static V8USBRequestType Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "USBRequestType", exception_state);
    return result.has_value()
               ? V8USBRequestType(static_cast<Enum>(result.value()))
               : V8USBRequestType();
  }
  static base::Optional<V8USBRequestType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8USBRequestType(static_cast<Enum>(result.value()));
  }

  constexpr V8USBRequestType() = default;
  explicit constexpr V8USBRequestType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8USBRequestType(const V8USBRequestType&) = default;
  constexpr V8USBRequestType(V8USBRequestType&&) = default;
  ~V8USBRequestType() = default;

  V8USBRequestType& operator=(const V8USBRequestType&) = default;
  V8USBRequestType& operator=(V8USBRequestType&&) = default;
  V8USBRequestType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"standard", "class",
                                                        "vendor"};
};

inline bool operator==(const V8USBRequestType& lhs,
                       V8USBRequestType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8USBRequestType::Enum lhs,
                       const V8USBRequestType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_REQUEST_TYPE_H_
