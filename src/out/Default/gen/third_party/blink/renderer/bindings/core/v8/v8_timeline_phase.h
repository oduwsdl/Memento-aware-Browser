// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_TIMELINE_PHASE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_TIMELINE_PHASE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8TimelinePhase final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kInactive, kBefore, kActive, kAfter };

  static V8TimelinePhase Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "TimelinePhase", exception_state);
    return result.has_value()
               ? V8TimelinePhase(static_cast<Enum>(result.value()))
               : V8TimelinePhase();
  }
  static base::Optional<V8TimelinePhase> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8TimelinePhase(static_cast<Enum>(result.value()));
  }

  constexpr V8TimelinePhase() = default;
  explicit constexpr V8TimelinePhase(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8TimelinePhase(const V8TimelinePhase&) = default;
  constexpr V8TimelinePhase(V8TimelinePhase&&) = default;
  ~V8TimelinePhase() = default;

  V8TimelinePhase& operator=(const V8TimelinePhase&) = default;
  V8TimelinePhase& operator=(V8TimelinePhase&&) = default;
  V8TimelinePhase& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"inactive", "before",
                                                        "active", "after"};
};

inline bool operator==(const V8TimelinePhase& lhs, V8TimelinePhase::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8TimelinePhase::Enum lhs, const V8TimelinePhase& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_TIMELINE_PHASE_H_
