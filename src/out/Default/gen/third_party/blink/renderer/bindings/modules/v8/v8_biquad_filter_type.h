// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BIQUAD_FILTER_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BIQUAD_FILTER_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8BiquadFilterType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kLowpass,
    kHighpass,
    kBandpass,
    kLowshelf,
    kHighshelf,
    kPeaking,
    kNotch,
    kAllpass
  };

  static V8BiquadFilterType Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "BiquadFilterType", exception_state);
    return result.has_value()
               ? V8BiquadFilterType(static_cast<Enum>(result.value()))
               : V8BiquadFilterType();
  }
  static base::Optional<V8BiquadFilterType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8BiquadFilterType(static_cast<Enum>(result.value()));
  }

  constexpr V8BiquadFilterType() = default;
  explicit constexpr V8BiquadFilterType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8BiquadFilterType(const V8BiquadFilterType&) = default;
  constexpr V8BiquadFilterType(V8BiquadFilterType&&) = default;
  ~V8BiquadFilterType() = default;

  V8BiquadFilterType& operator=(const V8BiquadFilterType&) = default;
  V8BiquadFilterType& operator=(V8BiquadFilterType&&) = default;
  V8BiquadFilterType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "lowpass",   "highpass", "bandpass", "lowshelf",
      "highshelf", "peaking",  "notch",    "allpass"};
};

inline bool operator==(const V8BiquadFilterType& lhs,
                       V8BiquadFilterType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8BiquadFilterType::Enum lhs,
                       const V8BiquadFilterType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BIQUAD_FILTER_TYPE_H_
