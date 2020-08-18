// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FORM_STATE_RESTORE_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FORM_STATE_RESTORE_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8FormStateRestoreMode final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kRestore, kAutocomplete };

  static V8FormStateRestoreMode Create(v8::Isolate* isolate,
                                       v8::Local<v8::Value> value,
                                       ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "FormStateRestoreMode", exception_state);
    return result.has_value()
               ? V8FormStateRestoreMode(static_cast<Enum>(result.value()))
               : V8FormStateRestoreMode();
  }
  static base::Optional<V8FormStateRestoreMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8FormStateRestoreMode(static_cast<Enum>(result.value()));
  }

  constexpr V8FormStateRestoreMode() = default;
  explicit constexpr V8FormStateRestoreMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8FormStateRestoreMode(const V8FormStateRestoreMode&) = default;
  constexpr V8FormStateRestoreMode(V8FormStateRestoreMode&&) = default;
  ~V8FormStateRestoreMode() = default;

  V8FormStateRestoreMode& operator=(const V8FormStateRestoreMode&) = default;
  V8FormStateRestoreMode& operator=(V8FormStateRestoreMode&&) = default;
  V8FormStateRestoreMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"restore",
                                                        "autocomplete"};
};

inline bool operator==(const V8FormStateRestoreMode& lhs,
                       V8FormStateRestoreMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8FormStateRestoreMode::Enum lhs,
                       const V8FormStateRestoreMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FORM_STATE_RESTORE_MODE_H_
