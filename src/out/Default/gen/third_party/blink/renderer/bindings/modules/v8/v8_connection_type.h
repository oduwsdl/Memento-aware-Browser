// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONNECTION_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONNECTION_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8ConnectionType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kCellular,
    kBluetooth,
    kEthernet,
    kWifi,
    kWimax,
    kOther,
    kNone,
    kUnknown
  };

  static V8ConnectionType Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ConnectionType", exception_state);
    return result.has_value()
               ? V8ConnectionType(static_cast<Enum>(result.value()))
               : V8ConnectionType();
  }
  static base::Optional<V8ConnectionType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ConnectionType(static_cast<Enum>(result.value()));
  }

  constexpr V8ConnectionType() = default;
  explicit constexpr V8ConnectionType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ConnectionType(const V8ConnectionType&) = default;
  constexpr V8ConnectionType(V8ConnectionType&&) = default;
  ~V8ConnectionType() = default;

  V8ConnectionType& operator=(const V8ConnectionType&) = default;
  V8ConnectionType& operator=(V8ConnectionType&&) = default;
  V8ConnectionType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "cellular", "bluetooth", "ethernet", "wifi",
      "wimax",    "other",     "none",     "unknown"};
};

inline bool operator==(const V8ConnectionType& lhs,
                       V8ConnectionType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ConnectionType::Enum lhs,
                       const V8ConnectionType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONNECTION_TYPE_H_
