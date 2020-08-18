// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BACKGROUND_FETCH_FAILURE_REASON_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BACKGROUND_FETCH_FAILURE_REASON_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8BackgroundFetchFailureReason final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    k,
    kAborted,
    kBadStatus,
    kFetchError,
    kQuotaExceeded,
    kDownloadTotalExceeded
  };

  static V8BackgroundFetchFailureReason Create(
      v8::Isolate* isolate,
      v8::Local<v8::Value> value,
      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "BackgroundFetchFailureReason",
        exception_state);
    return result.has_value() ? V8BackgroundFetchFailureReason(
                                    static_cast<Enum>(result.value()))
                              : V8BackgroundFetchFailureReason();
  }
  static base::Optional<V8BackgroundFetchFailureReason> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8BackgroundFetchFailureReason(static_cast<Enum>(result.value()));
  }

  constexpr V8BackgroundFetchFailureReason() = default;
  explicit constexpr V8BackgroundFetchFailureReason(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8BackgroundFetchFailureReason(
      const V8BackgroundFetchFailureReason&) = default;
  constexpr V8BackgroundFetchFailureReason(V8BackgroundFetchFailureReason&&) =
      default;
  ~V8BackgroundFetchFailureReason() = default;

  V8BackgroundFetchFailureReason& operator=(
      const V8BackgroundFetchFailureReason&) = default;
  V8BackgroundFetchFailureReason& operator=(V8BackgroundFetchFailureReason&&) =
      default;
  V8BackgroundFetchFailureReason& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "",
      "aborted",
      "bad-status",
      "fetch-error",
      "quota-exceeded",
      "download-total-exceeded"};
};

inline bool operator==(const V8BackgroundFetchFailureReason& lhs,
                       V8BackgroundFetchFailureReason::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8BackgroundFetchFailureReason::Enum lhs,
                       const V8BackgroundFetchFailureReason& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BACKGROUND_FETCH_FAILURE_REASON_H_
