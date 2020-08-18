// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_ORIENTATION_LOCK_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_ORIENTATION_LOCK_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8OrientationLockType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kAny,
    kNatural,
    kLandscape,
    kPortrait,
    kPortraitPrimary,
    kPortraitSecondary,
    kLandscapePrimary,
    kLandscapeSecondary
  };

  static V8OrientationLockType Create(v8::Isolate* isolate,
                                      v8::Local<v8::Value> value,
                                      ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "OrientationLockType", exception_state);
    return result.has_value()
               ? V8OrientationLockType(static_cast<Enum>(result.value()))
               : V8OrientationLockType();
  }
  static base::Optional<V8OrientationLockType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8OrientationLockType(static_cast<Enum>(result.value()));
  }

  constexpr V8OrientationLockType() = default;
  explicit constexpr V8OrientationLockType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8OrientationLockType(const V8OrientationLockType&) = default;
  constexpr V8OrientationLockType(V8OrientationLockType&&) = default;
  ~V8OrientationLockType() = default;

  V8OrientationLockType& operator=(const V8OrientationLockType&) = default;
  V8OrientationLockType& operator=(V8OrientationLockType&&) = default;
  V8OrientationLockType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"any",
                                                        "natural",
                                                        "landscape",
                                                        "portrait",
                                                        "portrait-primary",
                                                        "portrait-secondary",
                                                        "landscape-primary",
                                                        "landscape-secondary"};
};

inline bool operator==(const V8OrientationLockType& lhs,
                       V8OrientationLockType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8OrientationLockType::Enum lhs,
                       const V8OrientationLockType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_ORIENTATION_LOCK_TYPE_H_
