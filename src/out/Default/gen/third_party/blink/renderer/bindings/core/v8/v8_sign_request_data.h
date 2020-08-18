// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SIGN_REQUEST_DATA_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SIGN_REQUEST_DATA_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8SignRequestData final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kOmit, kInclude, kHeadersOnly };

  static V8SignRequestData Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "SignRequestData", exception_state);
    return result.has_value()
               ? V8SignRequestData(static_cast<Enum>(result.value()))
               : V8SignRequestData();
  }
  static base::Optional<V8SignRequestData> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8SignRequestData(static_cast<Enum>(result.value()));
  }

  constexpr V8SignRequestData() = default;
  explicit constexpr V8SignRequestData(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8SignRequestData(const V8SignRequestData&) = default;
  constexpr V8SignRequestData(V8SignRequestData&&) = default;
  ~V8SignRequestData() = default;

  V8SignRequestData& operator=(const V8SignRequestData&) = default;
  V8SignRequestData& operator=(V8SignRequestData&&) = default;
  V8SignRequestData& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"omit", "include",
                                                        "headers-only"};
};

inline bool operator==(const V8SignRequestData& lhs,
                       V8SignRequestData::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8SignRequestData::Enum lhs,
                       const V8SignRequestData& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SIGN_REQUEST_DATA_H_
