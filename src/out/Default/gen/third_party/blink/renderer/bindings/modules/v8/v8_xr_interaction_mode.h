// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_INTERACTION_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_INTERACTION_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8XRInteractionMode final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kScreenSpace, kWorldSpace };

  static V8XRInteractionMode Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "XRInteractionMode", exception_state);
    return result.has_value()
               ? V8XRInteractionMode(static_cast<Enum>(result.value()))
               : V8XRInteractionMode();
  }
  static base::Optional<V8XRInteractionMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8XRInteractionMode(static_cast<Enum>(result.value()));
  }

  constexpr V8XRInteractionMode() = default;
  explicit constexpr V8XRInteractionMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8XRInteractionMode(const V8XRInteractionMode&) = default;
  constexpr V8XRInteractionMode(V8XRInteractionMode&&) = default;
  ~V8XRInteractionMode() = default;

  V8XRInteractionMode& operator=(const V8XRInteractionMode&) = default;
  V8XRInteractionMode& operator=(V8XRInteractionMode&&) = default;
  V8XRInteractionMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"screen-space",
                                                        "world-space"};
};

inline bool operator==(const V8XRInteractionMode& lhs,
                       V8XRInteractionMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8XRInteractionMode::Enum lhs,
                       const V8XRInteractionMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_INTERACTION_MODE_H_
