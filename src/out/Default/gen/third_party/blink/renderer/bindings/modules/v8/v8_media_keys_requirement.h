// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_KEYS_REQUIREMENT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_KEYS_REQUIREMENT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8MediaKeysRequirement final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kRequired, kOptional, kNotAllowed };

  static V8MediaKeysRequirement Create(v8::Isolate* isolate,
                                       v8::Local<v8::Value> value,
                                       ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "MediaKeysRequirement", exception_state);
    return result.has_value()
               ? V8MediaKeysRequirement(static_cast<Enum>(result.value()))
               : V8MediaKeysRequirement();
  }
  static base::Optional<V8MediaKeysRequirement> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8MediaKeysRequirement(static_cast<Enum>(result.value()));
  }

  constexpr V8MediaKeysRequirement() = default;
  explicit constexpr V8MediaKeysRequirement(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8MediaKeysRequirement(const V8MediaKeysRequirement&) = default;
  constexpr V8MediaKeysRequirement(V8MediaKeysRequirement&&) = default;
  ~V8MediaKeysRequirement() = default;

  V8MediaKeysRequirement& operator=(const V8MediaKeysRequirement&) = default;
  V8MediaKeysRequirement& operator=(V8MediaKeysRequirement&&) = default;
  V8MediaKeysRequirement& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"required", "optional",
                                                        "not-allowed"};
};

inline bool operator==(const V8MediaKeysRequirement& lhs,
                       V8MediaKeysRequirement::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8MediaKeysRequirement::Enum lhs,
                       const V8MediaKeysRequirement& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_MEDIA_KEYS_REQUIREMENT_H_
