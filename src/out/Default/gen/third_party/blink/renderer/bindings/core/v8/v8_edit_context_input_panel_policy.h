// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_EDIT_CONTEXT_INPUT_PANEL_POLICY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_EDIT_CONTEXT_INPUT_PANEL_POLICY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8EditContextInputPanelPolicy final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAuto, kManual };

  static V8EditContextInputPanelPolicy Create(v8::Isolate* isolate,
                                              v8::Local<v8::Value> value,
                                              ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "EditContextInputPanelPolicy",
        exception_state);
    return result.has_value() ? V8EditContextInputPanelPolicy(
                                    static_cast<Enum>(result.value()))
                              : V8EditContextInputPanelPolicy();
  }
  static base::Optional<V8EditContextInputPanelPolicy> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8EditContextInputPanelPolicy(static_cast<Enum>(result.value()));
  }

  constexpr V8EditContextInputPanelPolicy() = default;
  explicit constexpr V8EditContextInputPanelPolicy(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8EditContextInputPanelPolicy(
      const V8EditContextInputPanelPolicy&) = default;
  constexpr V8EditContextInputPanelPolicy(V8EditContextInputPanelPolicy&&) =
      default;
  ~V8EditContextInputPanelPolicy() = default;

  V8EditContextInputPanelPolicy& operator=(
      const V8EditContextInputPanelPolicy&) = default;
  V8EditContextInputPanelPolicy& operator=(V8EditContextInputPanelPolicy&&) =
      default;
  V8EditContextInputPanelPolicy& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"auto", "manual"};
};

inline bool operator==(const V8EditContextInputPanelPolicy& lhs,
                       V8EditContextInputPanelPolicy::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8EditContextInputPanelPolicy::Enum lhs,
                       const V8EditContextInputPanelPolicy& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_EDIT_CONTEXT_INPUT_PANEL_POLICY_H_
