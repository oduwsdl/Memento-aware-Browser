// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BINARY_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BINARY_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8BinaryType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kBlob, kArraybuffer };

  static V8BinaryType Create(v8::Isolate* isolate,
                             v8::Local<v8::Value> value,
                             ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "BinaryType", exception_state);
    return result.has_value() ? V8BinaryType(static_cast<Enum>(result.value()))
                              : V8BinaryType();
  }
  static base::Optional<V8BinaryType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8BinaryType(static_cast<Enum>(result.value()));
  }

  constexpr V8BinaryType() = default;
  explicit constexpr V8BinaryType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8BinaryType(const V8BinaryType&) = default;
  constexpr V8BinaryType(V8BinaryType&&) = default;
  ~V8BinaryType() = default;

  V8BinaryType& operator=(const V8BinaryType&) = default;
  V8BinaryType& operator=(V8BinaryType&&) = default;
  V8BinaryType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"blob", "arraybuffer"};
};

inline bool operator==(const V8BinaryType& lhs, V8BinaryType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8BinaryType::Enum lhs, const V8BinaryType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BINARY_TYPE_H_
