// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SDP_SEMANTICS_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SDP_SEMANTICS_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8SdpSemantics final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kPlanB, kUnifiedPlan };

  static V8SdpSemantics Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "SdpSemantics", exception_state);
    return result.has_value()
               ? V8SdpSemantics(static_cast<Enum>(result.value()))
               : V8SdpSemantics();
  }
  static base::Optional<V8SdpSemantics> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8SdpSemantics(static_cast<Enum>(result.value()));
  }

  constexpr V8SdpSemantics() = default;
  explicit constexpr V8SdpSemantics(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8SdpSemantics(const V8SdpSemantics&) = default;
  constexpr V8SdpSemantics(V8SdpSemantics&&) = default;
  ~V8SdpSemantics() = default;

  V8SdpSemantics& operator=(const V8SdpSemantics&) = default;
  V8SdpSemantics& operator=(V8SdpSemantics&&) = default;
  V8SdpSemantics& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"plan-b",
                                                        "unified-plan"};
};

inline bool operator==(const V8SdpSemantics& lhs, V8SdpSemantics::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8SdpSemantics::Enum lhs, const V8SdpSemantics& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SDP_SEMANTICS_H_
