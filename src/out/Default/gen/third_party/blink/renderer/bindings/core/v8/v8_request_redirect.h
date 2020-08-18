// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_REDIRECT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_REDIRECT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8RequestRedirect final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kFollow, kError, kManual };

  static V8RequestRedirect Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RequestRedirect", exception_state);
    return result.has_value()
               ? V8RequestRedirect(static_cast<Enum>(result.value()))
               : V8RequestRedirect();
  }
  static base::Optional<V8RequestRedirect> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RequestRedirect(static_cast<Enum>(result.value()));
  }

  constexpr V8RequestRedirect() = default;
  explicit constexpr V8RequestRedirect(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RequestRedirect(const V8RequestRedirect&) = default;
  constexpr V8RequestRedirect(V8RequestRedirect&&) = default;
  ~V8RequestRedirect() = default;

  V8RequestRedirect& operator=(const V8RequestRedirect&) = default;
  V8RequestRedirect& operator=(V8RequestRedirect&&) = default;
  V8RequestRedirect& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"follow", "error",
                                                        "manual"};
};

inline bool operator==(const V8RequestRedirect& lhs,
                       V8RequestRedirect::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RequestRedirect::Enum lhs,
                       const V8RequestRedirect& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_REDIRECT_H_
