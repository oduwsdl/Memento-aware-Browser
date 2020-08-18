// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_COOKIE_SAME_SITE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_COOKIE_SAME_SITE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8CookieSameSite final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kStrict, kLax, kNone };

  static V8CookieSameSite Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "CookieSameSite", exception_state);
    return result.has_value()
               ? V8CookieSameSite(static_cast<Enum>(result.value()))
               : V8CookieSameSite();
  }
  static base::Optional<V8CookieSameSite> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8CookieSameSite(static_cast<Enum>(result.value()));
  }

  constexpr V8CookieSameSite() = default;
  explicit constexpr V8CookieSameSite(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8CookieSameSite(const V8CookieSameSite&) = default;
  constexpr V8CookieSameSite(V8CookieSameSite&&) = default;
  ~V8CookieSameSite() = default;

  V8CookieSameSite& operator=(const V8CookieSameSite&) = default;
  V8CookieSameSite& operator=(V8CookieSameSite&&) = default;
  V8CookieSameSite& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"strict", "lax",
                                                        "none"};
};

inline bool operator==(const V8CookieSameSite& lhs,
                       V8CookieSameSite::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8CookieSameSite::Enum lhs,
                       const V8CookieSameSite& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_COOKIE_SAME_SITE_H_
