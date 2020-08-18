// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_BUNDLE_POLICY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_BUNDLE_POLICY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8RTCBundlePolicy final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kBalanced, kMaxCompat, kMaxBundle };

  static V8RTCBundlePolicy Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RTCBundlePolicy", exception_state);
    return result.has_value()
               ? V8RTCBundlePolicy(static_cast<Enum>(result.value()))
               : V8RTCBundlePolicy();
  }
  static base::Optional<V8RTCBundlePolicy> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RTCBundlePolicy(static_cast<Enum>(result.value()));
  }

  constexpr V8RTCBundlePolicy() = default;
  explicit constexpr V8RTCBundlePolicy(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RTCBundlePolicy(const V8RTCBundlePolicy&) = default;
  constexpr V8RTCBundlePolicy(V8RTCBundlePolicy&&) = default;
  ~V8RTCBundlePolicy() = default;

  V8RTCBundlePolicy& operator=(const V8RTCBundlePolicy&) = default;
  V8RTCBundlePolicy& operator=(V8RTCBundlePolicy&&) = default;
  V8RTCBundlePolicy& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "balanced", "max-compat", "max-bundle"};
};

inline bool operator==(const V8RTCBundlePolicy& lhs,
                       V8RTCBundlePolicy::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RTCBundlePolicy::Enum lhs,
                       const V8RTCBundlePolicy& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_RTC_BUNDLE_POLICY_H_
