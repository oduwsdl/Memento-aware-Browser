// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FILL_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FILL_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8FillMode final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kForwards, kBackwards, kBoth, kAuto };

  static V8FillMode Create(v8::Isolate* isolate,
                           v8::Local<v8::Value> value,
                           ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "FillMode", exception_state);
    return result.has_value() ? V8FillMode(static_cast<Enum>(result.value()))
                              : V8FillMode();
  }
  static base::Optional<V8FillMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8FillMode(static_cast<Enum>(result.value()));
  }

  constexpr V8FillMode() = default;
  explicit constexpr V8FillMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8FillMode(const V8FillMode&) = default;
  constexpr V8FillMode(V8FillMode&&) = default;
  ~V8FillMode() = default;

  V8FillMode& operator=(const V8FillMode&) = default;
  V8FillMode& operator=(V8FillMode&&) = default;
  V8FillMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "none", "forwards", "backwards", "both", "auto"};
};

inline bool operator==(const V8FillMode& lhs, V8FillMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8FillMode::Enum lhs, const V8FillMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FILL_MODE_H_
