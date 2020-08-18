// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_KEY_MESSAGE_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_KEY_MESSAGE_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8MediaKeyMessageType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kLicenseRequest,
    kLicenseRenewal,
    kLicenseRelease,
    kIndividualizationRequest
  };

  static V8MediaKeyMessageType Create(v8::Isolate* isolate,
                                      v8::Local<v8::Value> value,
                                      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "MediaKeyMessageType", exception_state);
    return result.has_value()
               ? V8MediaKeyMessageType(static_cast<Enum>(result.value()))
               : V8MediaKeyMessageType();
  }
  static base::Optional<V8MediaKeyMessageType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8MediaKeyMessageType(static_cast<Enum>(result.value()));
  }

  constexpr V8MediaKeyMessageType() = default;
  explicit constexpr V8MediaKeyMessageType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8MediaKeyMessageType(const V8MediaKeyMessageType&) = default;
  constexpr V8MediaKeyMessageType(V8MediaKeyMessageType&&) = default;
  ~V8MediaKeyMessageType() = default;

  V8MediaKeyMessageType& operator=(const V8MediaKeyMessageType&) = default;
  V8MediaKeyMessageType& operator=(V8MediaKeyMessageType&&) = default;
  V8MediaKeyMessageType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "license-request", "license-renewal", "license-release",
      "individualization-request"};
};

inline bool operator==(const V8MediaKeyMessageType& lhs,
                       V8MediaKeyMessageType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8MediaKeyMessageType::Enum lhs,
                       const V8MediaKeyMessageType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_KEY_MESSAGE_TYPE_H_
