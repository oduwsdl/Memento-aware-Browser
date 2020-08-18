// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_APPEND_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_APPEND_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8AppendMode final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kSegments, kSequence };

  static V8AppendMode Create(v8::Isolate* isolate,
                             v8::Local<v8::Value> value,
                             ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "AppendMode", exception_state);
    return result.has_value() ? V8AppendMode(static_cast<Enum>(result.value()))
                              : V8AppendMode();
  }
  static base::Optional<V8AppendMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8AppendMode(static_cast<Enum>(result.value()));
  }

  constexpr V8AppendMode() = default;
  explicit constexpr V8AppendMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8AppendMode(const V8AppendMode&) = default;
  constexpr V8AppendMode(V8AppendMode&&) = default;
  ~V8AppendMode() = default;

  V8AppendMode& operator=(const V8AppendMode&) = default;
  V8AppendMode& operator=(V8AppendMode&&) = default;
  V8AppendMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"segments", "sequence"};
};

inline bool operator==(const V8AppendMode& lhs, V8AppendMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8AppendMode::Enum lhs, const V8AppendMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_APPEND_MODE_H_
