// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_METERING_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_METERING_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8MeteringMode final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kManual, kSingleShot, kContinuous };

  static V8MeteringMode Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "MeteringMode", exception_state);
    return result.has_value()
               ? V8MeteringMode(static_cast<Enum>(result.value()))
               : V8MeteringMode();
  }
  static base::Optional<V8MeteringMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8MeteringMode(static_cast<Enum>(result.value()));
  }

  constexpr V8MeteringMode() = default;
  explicit constexpr V8MeteringMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8MeteringMode(const V8MeteringMode&) = default;
  constexpr V8MeteringMode(V8MeteringMode&&) = default;
  ~V8MeteringMode() = default;

  V8MeteringMode& operator=(const V8MeteringMode&) = default;
  V8MeteringMode& operator=(V8MeteringMode&&) = default;
  V8MeteringMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "none", "manual", "single-shot", "continuous"};
};

inline bool operator==(const V8MeteringMode& lhs, V8MeteringMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8MeteringMode::Enum lhs, const V8MeteringMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_METERING_MODE_H_
