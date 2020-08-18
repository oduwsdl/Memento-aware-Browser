// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SHADOW_ROOT_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SHADOW_ROOT_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ShadowRootMode final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kOpen, kClosed };

  static V8ShadowRootMode Create(v8::Isolate* isolate,
                                 v8::Local<v8::Value> value,
                                 ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ShadowRootMode", exception_state);
    return result.has_value()
               ? V8ShadowRootMode(static_cast<Enum>(result.value()))
               : V8ShadowRootMode();
  }
  static base::Optional<V8ShadowRootMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ShadowRootMode(static_cast<Enum>(result.value()));
  }

  constexpr V8ShadowRootMode() = default;
  explicit constexpr V8ShadowRootMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ShadowRootMode(const V8ShadowRootMode&) = default;
  constexpr V8ShadowRootMode(V8ShadowRootMode&&) = default;
  ~V8ShadowRootMode() = default;

  V8ShadowRootMode& operator=(const V8ShadowRootMode&) = default;
  V8ShadowRootMode& operator=(V8ShadowRootMode&&) = default;
  V8ShadowRootMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"open", "closed"};
};

inline bool operator==(const V8ShadowRootMode& lhs,
                       V8ShadowRootMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ShadowRootMode::Enum lhs,
                       const V8ShadowRootMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SHADOW_ROOT_MODE_H_
