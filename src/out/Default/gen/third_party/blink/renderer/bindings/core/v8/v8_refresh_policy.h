// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REFRESH_POLICY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REFRESH_POLICY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8RefreshPolicy final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kRefresh };

  static V8RefreshPolicy Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RefreshPolicy", exception_state);
    return result.has_value()
               ? V8RefreshPolicy(static_cast<Enum>(result.value()))
               : V8RefreshPolicy();
  }
  static base::Optional<V8RefreshPolicy> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RefreshPolicy(static_cast<Enum>(result.value()));
  }

  constexpr V8RefreshPolicy() = default;
  explicit constexpr V8RefreshPolicy(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RefreshPolicy(const V8RefreshPolicy&) = default;
  constexpr V8RefreshPolicy(V8RefreshPolicy&&) = default;
  ~V8RefreshPolicy() = default;

  V8RefreshPolicy& operator=(const V8RefreshPolicy&) = default;
  V8RefreshPolicy& operator=(V8RefreshPolicy&&) = default;
  V8RefreshPolicy& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "refresh"};
};

inline bool operator==(const V8RefreshPolicy& lhs, V8RefreshPolicy::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RefreshPolicy::Enum lhs, const V8RefreshPolicy& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REFRESH_POLICY_H_
