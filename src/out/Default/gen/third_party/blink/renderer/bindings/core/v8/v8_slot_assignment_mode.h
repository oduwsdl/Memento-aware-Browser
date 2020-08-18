// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SLOT_ASSIGNMENT_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SLOT_ASSIGNMENT_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8SlotAssignmentMode final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kManual, kAuto };

  static V8SlotAssignmentMode Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "SlotAssignmentMode", exception_state);
    return result.has_value()
               ? V8SlotAssignmentMode(static_cast<Enum>(result.value()))
               : V8SlotAssignmentMode();
  }
  static base::Optional<V8SlotAssignmentMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8SlotAssignmentMode(static_cast<Enum>(result.value()));
  }

  constexpr V8SlotAssignmentMode() = default;
  explicit constexpr V8SlotAssignmentMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8SlotAssignmentMode(const V8SlotAssignmentMode&) = default;
  constexpr V8SlotAssignmentMode(V8SlotAssignmentMode&&) = default;
  ~V8SlotAssignmentMode() = default;

  V8SlotAssignmentMode& operator=(const V8SlotAssignmentMode&) = default;
  V8SlotAssignmentMode& operator=(V8SlotAssignmentMode&&) = default;
  V8SlotAssignmentMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"manual", "auto"};
};

inline bool operator==(const V8SlotAssignmentMode& lhs,
                       V8SlotAssignmentMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8SlotAssignmentMode::Enum lhs,
                       const V8SlotAssignmentMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SLOT_ASSIGNMENT_MODE_H_
