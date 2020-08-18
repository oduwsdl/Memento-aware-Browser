// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PRESENTATION_CONNECTION_CLOSE_REASON_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PRESENTATION_CONNECTION_CLOSE_REASON_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8PresentationConnectionCloseReason final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kError, kClosed, kWentaway };

  static V8PresentationConnectionCloseReason Create(
      v8::Isolate* isolate,
      v8::Local<v8::Value> value,
      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "PresentationConnectionCloseReason",
        exception_state);
    return result.has_value() ? V8PresentationConnectionCloseReason(
                                    static_cast<Enum>(result.value()))
                              : V8PresentationConnectionCloseReason();
  }
  static base::Optional<V8PresentationConnectionCloseReason> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8PresentationConnectionCloseReason(
        static_cast<Enum>(result.value()));
  }

  constexpr V8PresentationConnectionCloseReason() = default;
  explicit constexpr V8PresentationConnectionCloseReason(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8PresentationConnectionCloseReason(
      const V8PresentationConnectionCloseReason&) = default;
  constexpr V8PresentationConnectionCloseReason(
      V8PresentationConnectionCloseReason&&) = default;
  ~V8PresentationConnectionCloseReason() = default;

  V8PresentationConnectionCloseReason& operator=(
      const V8PresentationConnectionCloseReason&) = default;
  V8PresentationConnectionCloseReason& operator=(
      V8PresentationConnectionCloseReason&&) = default;
  V8PresentationConnectionCloseReason& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"error", "closed",
                                                        "wentaway"};
};

inline bool operator==(const V8PresentationConnectionCloseReason& lhs,
                       V8PresentationConnectionCloseReason::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8PresentationConnectionCloseReason::Enum lhs,
                       const V8PresentationConnectionCloseReason& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PRESENTATION_CONNECTION_CLOSE_REASON_H_
