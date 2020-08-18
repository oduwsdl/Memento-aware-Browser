// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_RECIPIENT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_RECIPIENT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8USBRecipient final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kDevice, kInterface, kEndpoint, kOther };

  static V8USBRecipient Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "USBRecipient", exception_state);
    return result.has_value()
               ? V8USBRecipient(static_cast<Enum>(result.value()))
               : V8USBRecipient();
  }
  static base::Optional<V8USBRecipient> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8USBRecipient(static_cast<Enum>(result.value()));
  }

  constexpr V8USBRecipient() = default;
  explicit constexpr V8USBRecipient(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8USBRecipient(const V8USBRecipient&) = default;
  constexpr V8USBRecipient(V8USBRecipient&&) = default;
  ~V8USBRecipient() = default;

  V8USBRecipient& operator=(const V8USBRecipient&) = default;
  V8USBRecipient& operator=(V8USBRecipient&&) = default;
  V8USBRecipient& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"device", "interface",
                                                        "endpoint", "other"};
};

inline bool operator==(const V8USBRecipient& lhs, V8USBRecipient::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8USBRecipient::Enum lhs, const V8USBRecipient& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_RECIPIENT_H_
