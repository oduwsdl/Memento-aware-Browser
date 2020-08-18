// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_HANDEDNESS_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_HANDEDNESS_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8XRHandedness final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kLeft, kRight };

  static V8XRHandedness Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "XRHandedness", exception_state);
    return result.has_value()
               ? V8XRHandedness(static_cast<Enum>(result.value()))
               : V8XRHandedness();
  }
  static base::Optional<V8XRHandedness> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8XRHandedness(static_cast<Enum>(result.value()));
  }

  constexpr V8XRHandedness() = default;
  explicit constexpr V8XRHandedness(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8XRHandedness(const V8XRHandedness&) = default;
  constexpr V8XRHandedness(V8XRHandedness&&) = default;
  ~V8XRHandedness() = default;

  V8XRHandedness& operator=(const V8XRHandedness&) = default;
  V8XRHandedness& operator=(V8XRHandedness&&) = default;
  V8XRHandedness& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "left",
                                                        "right"};
};

inline bool operator==(const V8XRHandedness& lhs, V8XRHandedness::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8XRHandedness::Enum lhs, const V8XRHandedness& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_HANDEDNESS_H_
