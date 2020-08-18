// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_SESSION_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_SESSION_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8XRSessionMode final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kInline, kImmersiveVr, kImmersiveAr };

  static V8XRSessionMode Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "XRSessionMode", exception_state);
    return result.has_value()
               ? V8XRSessionMode(static_cast<Enum>(result.value()))
               : V8XRSessionMode();
  }
  static base::Optional<V8XRSessionMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8XRSessionMode(static_cast<Enum>(result.value()));
  }

  constexpr V8XRSessionMode() = default;
  explicit constexpr V8XRSessionMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8XRSessionMode(const V8XRSessionMode&) = default;
  constexpr V8XRSessionMode(V8XRSessionMode&&) = default;
  ~V8XRSessionMode() = default;

  V8XRSessionMode& operator=(const V8XRSessionMode&) = default;
  V8XRSessionMode& operator=(V8XRSessionMode&&) = default;
  V8XRSessionMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "inline", "immersive-vr", "immersive-ar"};
};

inline bool operator==(const V8XRSessionMode& lhs, V8XRSessionMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8XRSessionMode::Enum lhs, const V8XRSessionMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_SESSION_MODE_H_
