// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_SDP_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_SDP_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCSdpType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kOffer, kPranswer, kAnswer, kRollback };

  static V8RTCSdpType Create(v8::Isolate* isolate,
                             v8::Local<v8::Value> value,
                             ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCSdpType", exception_state);
    return result.has_value() ? V8RTCSdpType(static_cast<Enum>(result.value()))
                              : V8RTCSdpType();
  }
  static base::Optional<V8RTCSdpType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCSdpType(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCSdpType() = default;
  explicit constexpr V8RTCSdpType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCSdpType(const V8RTCSdpType&) = default;
  constexpr V8RTCSdpType(V8RTCSdpType&&) = default;
  ~V8RTCSdpType() = default;

  V8RTCSdpType& operator=(const V8RTCSdpType&) = default;
  V8RTCSdpType& operator=(V8RTCSdpType&&) = default;
  V8RTCSdpType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"offer", "pranswer",
                                                        "answer", "rollback"};
};

inline bool operator==(const V8RTCSdpType& lhs, V8RTCSdpType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCSdpType::Enum lhs, const V8RTCSdpType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_SDP_TYPE_H_
