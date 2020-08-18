// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_TRANSFER_STATUS_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_TRANSFER_STATUS_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8USBTransferStatus final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kOk, kStall, kBabble };

  static V8USBTransferStatus Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "USBTransferStatus", exception_state);
    return result.has_value()
               ? V8USBTransferStatus(static_cast<Enum>(result.value()))
               : V8USBTransferStatus();
  }
  static base::Optional<V8USBTransferStatus> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8USBTransferStatus(static_cast<Enum>(result.value()));
  }

  constexpr V8USBTransferStatus() = default;
  explicit constexpr V8USBTransferStatus(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8USBTransferStatus(const V8USBTransferStatus&) = default;
  constexpr V8USBTransferStatus(V8USBTransferStatus&&) = default;
  ~V8USBTransferStatus() = default;

  V8USBTransferStatus& operator=(const V8USBTransferStatus&) = default;
  V8USBTransferStatus& operator=(V8USBTransferStatus&&) = default;
  V8USBTransferStatus& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"ok", "stall",
                                                        "babble"};
};

inline bool operator==(const V8USBTransferStatus& lhs,
                       V8USBTransferStatus::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8USBTransferStatus::Enum lhs,
                       const V8USBTransferStatus& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_USB_TRANSFER_STATUS_H_
