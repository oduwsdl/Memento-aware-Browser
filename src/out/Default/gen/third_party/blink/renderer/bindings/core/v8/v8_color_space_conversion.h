// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_COLOR_SPACE_CONVERSION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_COLOR_SPACE_CONVERSION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ColorSpaceConversion final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kDefault };

  static V8ColorSpaceConversion Create(v8::Isolate* isolate,
                                       v8::Local<v8::Value> value,
                                       ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ColorSpaceConversion", exception_state);
    return result.has_value()
               ? V8ColorSpaceConversion(static_cast<Enum>(result.value()))
               : V8ColorSpaceConversion();
  }
  static base::Optional<V8ColorSpaceConversion> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ColorSpaceConversion(static_cast<Enum>(result.value()));
  }

  constexpr V8ColorSpaceConversion() = default;
  explicit constexpr V8ColorSpaceConversion(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ColorSpaceConversion(const V8ColorSpaceConversion&) = default;
  constexpr V8ColorSpaceConversion(V8ColorSpaceConversion&&) = default;
  ~V8ColorSpaceConversion() = default;

  V8ColorSpaceConversion& operator=(const V8ColorSpaceConversion&) = default;
  V8ColorSpaceConversion& operator=(V8ColorSpaceConversion&&) = default;
  V8ColorSpaceConversion& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "default"};
};

inline bool operator==(const V8ColorSpaceConversion& lhs,
                       V8ColorSpaceConversion::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ColorSpaceConversion::Enum lhs,
                       const V8ColorSpaceConversion& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_COLOR_SPACE_CONVERSION_H_
