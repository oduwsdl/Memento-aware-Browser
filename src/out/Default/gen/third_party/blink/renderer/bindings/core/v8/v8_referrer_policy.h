// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REFERRER_POLICY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REFERRER_POLICY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ReferrerPolicy final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    k,
    kNoReferrer,
    kNoReferrerWhenDowngrade,
    kSameOrigin,
    kOrigin,
    kStrictOrigin,
    kOriginWhenCrossOrigin,
    kStrictOriginWhenCrossOrigin,
    kUnsafeUrl
  };

  static V8ReferrerPolicy Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ReferrerPolicy", exception_state);
    return result.has_value()
               ? V8ReferrerPolicy(static_cast<Enum>(result.value()))
               : V8ReferrerPolicy();
  }
  static base::Optional<V8ReferrerPolicy> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ReferrerPolicy(static_cast<Enum>(result.value()));
  }

  constexpr V8ReferrerPolicy() = default;
  explicit constexpr V8ReferrerPolicy(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ReferrerPolicy(const V8ReferrerPolicy&) = default;
  constexpr V8ReferrerPolicy(V8ReferrerPolicy&&) = default;
  ~V8ReferrerPolicy() = default;

  V8ReferrerPolicy& operator=(const V8ReferrerPolicy&) = default;
  V8ReferrerPolicy& operator=(V8ReferrerPolicy&&) = default;
  V8ReferrerPolicy& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "",
      "no-referrer",
      "no-referrer-when-downgrade",
      "same-origin",
      "origin",
      "strict-origin",
      "origin-when-cross-origin",
      "strict-origin-when-cross-origin",
      "unsafe-url"};
};

inline bool operator==(const V8ReferrerPolicy& lhs,
                       V8ReferrerPolicy::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ReferrerPolicy::Enum lhs,
                       const V8ReferrerPolicy& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REFERRER_POLICY_H_
