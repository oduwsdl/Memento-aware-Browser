// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_EYE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_EYE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8XREye final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kLeft, kRight };

  static V8XREye Create(v8::Isolate* isolate,
                        v8::Local<v8::Value> value,
                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "XREye", exception_state);
    return result.has_value() ? V8XREye(static_cast<Enum>(result.value()))
                              : V8XREye();
  }
  static base::Optional<V8XREye> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8XREye(static_cast<Enum>(result.value()));
  }

  constexpr V8XREye() = default;
  explicit constexpr V8XREye(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8XREye(const V8XREye&) = default;
  constexpr V8XREye(V8XREye&&) = default;
  ~V8XREye() = default;

  V8XREye& operator=(const V8XREye&) = default;
  V8XREye& operator=(V8XREye&&) = default;
  V8XREye& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "left",
                                                        "right"};
};

inline bool operator==(const V8XREye& lhs, V8XREye::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8XREye::Enum lhs, const V8XREye& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_EYE_H_
