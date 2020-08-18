// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_HIT_TEST_TRACKABLE_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_HIT_TEST_TRACKABLE_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8XRHitTestTrackableType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kPoint, kPlane };

  static V8XRHitTestTrackableType Create(v8::Isolate* isolate,
                                         v8::Local<v8::Value> value,
                                         ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "XRHitTestTrackableType",
        exception_state);
    return result.has_value()
               ? V8XRHitTestTrackableType(static_cast<Enum>(result.value()))
               : V8XRHitTestTrackableType();
  }
  static base::Optional<V8XRHitTestTrackableType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8XRHitTestTrackableType(static_cast<Enum>(result.value()));
  }

  constexpr V8XRHitTestTrackableType() = default;
  explicit constexpr V8XRHitTestTrackableType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8XRHitTestTrackableType(const V8XRHitTestTrackableType&) = default;
  constexpr V8XRHitTestTrackableType(V8XRHitTestTrackableType&&) = default;
  ~V8XRHitTestTrackableType() = default;

  V8XRHitTestTrackableType& operator=(const V8XRHitTestTrackableType&) =
      default;
  V8XRHitTestTrackableType& operator=(V8XRHitTestTrackableType&&) = default;
  V8XRHitTestTrackableType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"point", "plane"};
};

inline bool operator==(const V8XRHitTestTrackableType& lhs,
                       V8XRHitTestTrackableType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8XRHitTestTrackableType::Enum lhs,
                       const V8XRHitTestTrackableType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_HIT_TEST_TRACKABLE_TYPE_H_
