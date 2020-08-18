// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_KEY_STATUS_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_KEY_STATUS_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8MediaKeyStatus final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kUsable,
    kExpired,
    kReleased,
    kOutputRestricted,
    kOutputDownscaled,
    kStatusPending,
    kInternalError
  };

  static V8MediaKeyStatus Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "MediaKeyStatus", exception_state);
    return result.has_value()
               ? V8MediaKeyStatus(static_cast<Enum>(result.value()))
               : V8MediaKeyStatus();
  }
  static base::Optional<V8MediaKeyStatus> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8MediaKeyStatus(static_cast<Enum>(result.value()));
  }

  constexpr V8MediaKeyStatus() = default;
  explicit constexpr V8MediaKeyStatus(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8MediaKeyStatus(const V8MediaKeyStatus&) = default;
  constexpr V8MediaKeyStatus(V8MediaKeyStatus&&) = default;
  ~V8MediaKeyStatus() = default;

  V8MediaKeyStatus& operator=(const V8MediaKeyStatus&) = default;
  V8MediaKeyStatus& operator=(V8MediaKeyStatus&&) = default;
  V8MediaKeyStatus& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"usable",
                                                        "expired",
                                                        "released",
                                                        "output-restricted",
                                                        "output-downscaled",
                                                        "status-pending",
                                                        "internal-error"};
};

inline bool operator==(const V8MediaKeyStatus& lhs,
                       V8MediaKeyStatus::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8MediaKeyStatus::Enum lhs,
                       const V8MediaKeyStatus& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_KEY_STATUS_H_
