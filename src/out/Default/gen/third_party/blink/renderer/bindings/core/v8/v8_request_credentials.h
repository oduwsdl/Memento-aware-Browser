// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_CREDENTIALS_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_CREDENTIALS_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8RequestCredentials final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kOmit, kSameOrigin, kInclude };

  static V8RequestCredentials Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RequestCredentials", exception_state);
    return result.has_value()
               ? V8RequestCredentials(static_cast<Enum>(result.value()))
               : V8RequestCredentials();
  }
  static base::Optional<V8RequestCredentials> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RequestCredentials(static_cast<Enum>(result.value()));
  }

  constexpr V8RequestCredentials() = default;
  explicit constexpr V8RequestCredentials(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RequestCredentials(const V8RequestCredentials&) = default;
  constexpr V8RequestCredentials(V8RequestCredentials&&) = default;
  ~V8RequestCredentials() = default;

  V8RequestCredentials& operator=(const V8RequestCredentials&) = default;
  V8RequestCredentials& operator=(V8RequestCredentials&&) = default;
  V8RequestCredentials& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"omit", "same-origin",
                                                        "include"};
};

inline bool operator==(const V8RequestCredentials& lhs,
                       V8RequestCredentials::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RequestCredentials::Enum lhs,
                       const V8RequestCredentials& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_CREDENTIALS_H_
