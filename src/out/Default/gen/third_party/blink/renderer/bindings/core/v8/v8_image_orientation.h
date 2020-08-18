// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_ORIENTATION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_ORIENTATION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ImageOrientation final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kFlipY };

  static V8ImageOrientation Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ImageOrientation", exception_state);
    return result.has_value()
               ? V8ImageOrientation(static_cast<Enum>(result.value()))
               : V8ImageOrientation();
  }
  static base::Optional<V8ImageOrientation> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ImageOrientation(static_cast<Enum>(result.value()));
  }

  constexpr V8ImageOrientation() = default;
  explicit constexpr V8ImageOrientation(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ImageOrientation(const V8ImageOrientation&) = default;
  constexpr V8ImageOrientation(V8ImageOrientation&&) = default;
  ~V8ImageOrientation() = default;

  V8ImageOrientation& operator=(const V8ImageOrientation&) = default;
  V8ImageOrientation& operator=(V8ImageOrientation&&) = default;
  V8ImageOrientation& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "flipY"};
};

inline bool operator==(const V8ImageOrientation& lhs,
                       V8ImageOrientation::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ImageOrientation::Enum lhs,
                       const V8ImageOrientation& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_ORIENTATION_H_
