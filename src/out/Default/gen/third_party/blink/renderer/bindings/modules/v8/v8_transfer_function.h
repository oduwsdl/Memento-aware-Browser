// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_TRANSFER_FUNCTION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_TRANSFER_FUNCTION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8TransferFunction final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kSRGB, kPq, kHlg };

  static V8TransferFunction Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "TransferFunction", exception_state);
    return result.has_value()
               ? V8TransferFunction(static_cast<Enum>(result.value()))
               : V8TransferFunction();
  }
  static base::Optional<V8TransferFunction> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8TransferFunction(static_cast<Enum>(result.value()));
  }

  constexpr V8TransferFunction() = default;
  explicit constexpr V8TransferFunction(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8TransferFunction(const V8TransferFunction&) = default;
  constexpr V8TransferFunction(V8TransferFunction&&) = default;
  ~V8TransferFunction() = default;

  V8TransferFunction& operator=(const V8TransferFunction&) = default;
  V8TransferFunction& operator=(V8TransferFunction&&) = default;
  V8TransferFunction& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"srgb", "pq", "hlg"};
};

inline bool operator==(const V8TransferFunction& lhs,
                       V8TransferFunction::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8TransferFunction::Enum lhs,
                       const V8TransferFunction& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_TRANSFER_FUNCTION_H_
