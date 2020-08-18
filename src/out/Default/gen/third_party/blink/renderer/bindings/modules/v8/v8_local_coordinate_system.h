// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_LOCAL_COORDINATE_SYSTEM_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_LOCAL_COORDINATE_SYSTEM_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8LocalCoordinateSystem final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kDevice, kScreen };

  static V8LocalCoordinateSystem Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "LocalCoordinateSystem",
        exception_state);
    return result.has_value()
               ? V8LocalCoordinateSystem(static_cast<Enum>(result.value()))
               : V8LocalCoordinateSystem();
  }
  static base::Optional<V8LocalCoordinateSystem> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8LocalCoordinateSystem(static_cast<Enum>(result.value()));
  }

  constexpr V8LocalCoordinateSystem() = default;
  explicit constexpr V8LocalCoordinateSystem(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8LocalCoordinateSystem(const V8LocalCoordinateSystem&) = default;
  constexpr V8LocalCoordinateSystem(V8LocalCoordinateSystem&&) = default;
  ~V8LocalCoordinateSystem() = default;

  V8LocalCoordinateSystem& operator=(const V8LocalCoordinateSystem&) = default;
  V8LocalCoordinateSystem& operator=(V8LocalCoordinateSystem&&) = default;
  V8LocalCoordinateSystem& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"device", "screen"};
};

inline bool operator==(const V8LocalCoordinateSystem& lhs,
                       V8LocalCoordinateSystem::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8LocalCoordinateSystem::Enum lhs,
                       const V8LocalCoordinateSystem& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_LOCAL_COORDINATE_SYSTEM_H_
