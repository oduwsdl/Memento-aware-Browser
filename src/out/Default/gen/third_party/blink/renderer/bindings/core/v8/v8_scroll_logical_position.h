// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_LOGICAL_POSITION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_LOGICAL_POSITION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ScrollLogicalPosition final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kStart, kCenter, kEnd, kNearest };

  static V8ScrollLogicalPosition Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ScrollLogicalPosition",
        exception_state);
    return result.has_value()
               ? V8ScrollLogicalPosition(static_cast<Enum>(result.value()))
               : V8ScrollLogicalPosition();
  }
  static base::Optional<V8ScrollLogicalPosition> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ScrollLogicalPosition(static_cast<Enum>(result.value()));
  }

  constexpr V8ScrollLogicalPosition() = default;
  explicit constexpr V8ScrollLogicalPosition(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ScrollLogicalPosition(const V8ScrollLogicalPosition&) = default;
  constexpr V8ScrollLogicalPosition(V8ScrollLogicalPosition&&) = default;
  ~V8ScrollLogicalPosition() = default;

  V8ScrollLogicalPosition& operator=(const V8ScrollLogicalPosition&) = default;
  V8ScrollLogicalPosition& operator=(V8ScrollLogicalPosition&&) = default;
  V8ScrollLogicalPosition& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"start", "center",
                                                        "end", "nearest"};
};

inline bool operator==(const V8ScrollLogicalPosition& lhs,
                       V8ScrollLogicalPosition::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ScrollLogicalPosition::Enum lhs,
                       const V8ScrollLogicalPosition& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_LOGICAL_POSITION_H_
