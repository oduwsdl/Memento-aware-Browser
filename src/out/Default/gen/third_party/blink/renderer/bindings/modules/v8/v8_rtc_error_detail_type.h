// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ERROR_DETAIL_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ERROR_DETAIL_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCErrorDetailType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kDataChannelFailure,
    kDtlsFailure,
    kFingerprintFailure,
    kIdpBadScriptFailure,
    kIdpExecutionFailure,
    kIdpLoadFailure,
    kIdpNeedLogin,
    kIdpTimeout,
    kIdpTlsFailure,
    kIdpTokenExpired,
    kIdpTokenInvalid,
    kSctpFailure,
    kSdpSyntaxError,
    kHardwareEncoderNotAvailable,
    kHardwareEncoderError
  };

  static V8RTCErrorDetailType Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCErrorDetailType", exception_state);
    return result.has_value()
               ? V8RTCErrorDetailType(static_cast<Enum>(result.value()))
               : V8RTCErrorDetailType();
  }
  static base::Optional<V8RTCErrorDetailType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCErrorDetailType(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCErrorDetailType() = default;
  explicit constexpr V8RTCErrorDetailType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCErrorDetailType(const V8RTCErrorDetailType&) = default;
  constexpr V8RTCErrorDetailType(V8RTCErrorDetailType&&) = default;
  ~V8RTCErrorDetailType() = default;

  V8RTCErrorDetailType& operator=(const V8RTCErrorDetailType&) = default;
  V8RTCErrorDetailType& operator=(V8RTCErrorDetailType&&) = default;
  V8RTCErrorDetailType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "data-channel-failure",  "dtls-failure",
      "fingerprint-failure",   "idp-bad-script-failure",
      "idp-execution-failure", "idp-load-failure",
      "idp-need-login",        "idp-timeout",
      "idp-tls-failure",       "idp-token-expired",
      "idp-token-invalid",     "sctp-failure",
      "sdp-syntax-error",      "hardware-encoder-not-available",
      "hardware-encoder-error"};
};

inline bool operator==(const V8RTCErrorDetailType& lhs,
                       V8RTCErrorDetailType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCErrorDetailType::Enum lhs,
                       const V8RTCErrorDetailType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_ERROR_DETAIL_TYPE_H_
