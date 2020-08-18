// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SELECTION_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SELECTION_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8SelectionMode final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kSelect, kStart, kEnd, kPreserve };

  static V8SelectionMode Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "SelectionMode", exception_state);
    return result.has_value()
               ? V8SelectionMode(static_cast<Enum>(result.value()))
               : V8SelectionMode();
  }
  static base::Optional<V8SelectionMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8SelectionMode(static_cast<Enum>(result.value()));
  }

  constexpr V8SelectionMode() = default;
  explicit constexpr V8SelectionMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8SelectionMode(const V8SelectionMode&) = default;
  constexpr V8SelectionMode(V8SelectionMode&&) = default;
  ~V8SelectionMode() = default;

  V8SelectionMode& operator=(const V8SelectionMode&) = default;
  V8SelectionMode& operator=(V8SelectionMode&&) = default;
  V8SelectionMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"select", "start",
                                                        "end", "preserve"};
};

inline bool operator==(const V8SelectionMode& lhs, V8SelectionMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8SelectionMode::Enum lhs, const V8SelectionMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SELECTION_MODE_H_
