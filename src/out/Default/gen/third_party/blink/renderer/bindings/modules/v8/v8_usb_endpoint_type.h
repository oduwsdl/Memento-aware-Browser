// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_ENDPOINT_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_ENDPOINT_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8USBEndpointType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kBulk, kInterrupt, kIsochronous };

  static V8USBEndpointType Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "USBEndpointType", exception_state);
    return result.has_value()
               ? V8USBEndpointType(static_cast<Enum>(result.value()))
               : V8USBEndpointType();
  }
  static base::Optional<V8USBEndpointType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8USBEndpointType(static_cast<Enum>(result.value()));
  }

  constexpr V8USBEndpointType() = default;
  explicit constexpr V8USBEndpointType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8USBEndpointType(const V8USBEndpointType&) = default;
  constexpr V8USBEndpointType(V8USBEndpointType&&) = default;
  ~V8USBEndpointType() = default;

  V8USBEndpointType& operator=(const V8USBEndpointType&) = default;
  V8USBEndpointType& operator=(V8USBEndpointType&&) = default;
  V8USBEndpointType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"bulk", "interrupt",
                                                        "isochronous"};
};

inline bool operator==(const V8USBEndpointType& lhs,
                       V8USBEndpointType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8USBEndpointType::Enum lhs,
                       const V8USBEndpointType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_ENDPOINT_TYPE_H_
