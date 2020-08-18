// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONTACT_PROPERTY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONTACT_PROPERTY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8ContactProperty final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAddress, kEmail, kIcon, kName, kTel };

  static V8ContactProperty Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ContactProperty", exception_state);
    return result.has_value()
               ? V8ContactProperty(static_cast<Enum>(result.value()))
               : V8ContactProperty();
  }
  static base::Optional<V8ContactProperty> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ContactProperty(static_cast<Enum>(result.value()));
  }

  constexpr V8ContactProperty() = default;
  explicit constexpr V8ContactProperty(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ContactProperty(const V8ContactProperty&) = default;
  constexpr V8ContactProperty(V8ContactProperty&&) = default;
  ~V8ContactProperty() = default;

  V8ContactProperty& operator=(const V8ContactProperty&) = default;
  V8ContactProperty& operator=(V8ContactProperty&&) = default;
  V8ContactProperty& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"address", "email",
                                                        "icon", "name", "tel"};
};

inline bool operator==(const V8ContactProperty& lhs,
                       V8ContactProperty::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ContactProperty::Enum lhs,
                       const V8ContactProperty& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONTACT_PROPERTY_H_
