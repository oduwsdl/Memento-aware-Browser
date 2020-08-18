// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_PREMULTIPLY_ALPHA_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_PREMULTIPLY_ALPHA_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8PremultiplyAlpha final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kPremultiply, kDefault };

  static V8PremultiplyAlpha Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "PremultiplyAlpha", exception_state);
    return result.has_value()
               ? V8PremultiplyAlpha(static_cast<Enum>(result.value()))
               : V8PremultiplyAlpha();
  }
  static base::Optional<V8PremultiplyAlpha> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8PremultiplyAlpha(static_cast<Enum>(result.value()));
  }

  constexpr V8PremultiplyAlpha() = default;
  explicit constexpr V8PremultiplyAlpha(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8PremultiplyAlpha(const V8PremultiplyAlpha&) = default;
  constexpr V8PremultiplyAlpha(V8PremultiplyAlpha&&) = default;
  ~V8PremultiplyAlpha() = default;

  V8PremultiplyAlpha& operator=(const V8PremultiplyAlpha&) = default;
  V8PremultiplyAlpha& operator=(V8PremultiplyAlpha&&) = default;
  V8PremultiplyAlpha& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "premultiply",
                                                        "default"};
};

inline bool operator==(const V8PremultiplyAlpha& lhs,
                       V8PremultiplyAlpha::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8PremultiplyAlpha::Enum lhs,
                       const V8PremultiplyAlpha& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_PREMULTIPLY_ALPHA_H_
