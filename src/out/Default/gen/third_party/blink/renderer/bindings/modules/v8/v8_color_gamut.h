// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_COLOR_GAMUT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_COLOR_GAMUT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8ColorGamut final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kSRGB, kP3, kRec2020 };

  static V8ColorGamut Create(v8::Isolate* isolate,
                             v8::Local<v8::Value> value,
                             ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ColorGamut", exception_state);
    return result.has_value() ? V8ColorGamut(static_cast<Enum>(result.value()))
                              : V8ColorGamut();
  }
  static base::Optional<V8ColorGamut> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ColorGamut(static_cast<Enum>(result.value()));
  }

  constexpr V8ColorGamut() = default;
  explicit constexpr V8ColorGamut(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ColorGamut(const V8ColorGamut&) = default;
  constexpr V8ColorGamut(V8ColorGamut&&) = default;
  ~V8ColorGamut() = default;

  V8ColorGamut& operator=(const V8ColorGamut&) = default;
  V8ColorGamut& operator=(V8ColorGamut&&) = default;
  V8ColorGamut& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"srgb", "p3",
                                                        "rec2020"};
};

inline bool operator==(const V8ColorGamut& lhs, V8ColorGamut::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ColorGamut::Enum lhs, const V8ColorGamut& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_COLOR_GAMUT_H_
