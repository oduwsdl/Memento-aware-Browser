// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_RESIZE_QUALITY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_RESIZE_QUALITY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ResizeQuality final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kPixelated, kLow, kMedium, kHigh };

  static V8ResizeQuality Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ResizeQuality", exception_state);
    return result.has_value()
               ? V8ResizeQuality(static_cast<Enum>(result.value()))
               : V8ResizeQuality();
  }
  static base::Optional<V8ResizeQuality> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ResizeQuality(static_cast<Enum>(result.value()));
  }

  constexpr V8ResizeQuality() = default;
  explicit constexpr V8ResizeQuality(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ResizeQuality(const V8ResizeQuality&) = default;
  constexpr V8ResizeQuality(V8ResizeQuality&&) = default;
  ~V8ResizeQuality() = default;

  V8ResizeQuality& operator=(const V8ResizeQuality&) = default;
  V8ResizeQuality& operator=(V8ResizeQuality&&) = default;
  V8ResizeQuality& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"pixelated", "low",
                                                        "medium", "high"};
};

inline bool operator==(const V8ResizeQuality& lhs, V8ResizeQuality::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ResizeQuality::Enum lhs, const V8ResizeQuality& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_RESIZE_QUALITY_H_
