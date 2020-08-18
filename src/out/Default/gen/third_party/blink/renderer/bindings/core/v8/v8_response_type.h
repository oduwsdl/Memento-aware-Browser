// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_RESPONSE_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_RESPONSE_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ResponseType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kBasic,
    kCors,
    kDefault,
    kError,
    kOpaque,
    kOpaqueredirect
  };

  static V8ResponseType Create(v8::Isolate* isolate,
                               v8::Local<v8::Value> value,
                               ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ResponseType", exception_state);
    return result.has_value()
               ? V8ResponseType(static_cast<Enum>(result.value()))
               : V8ResponseType();
  }
  static base::Optional<V8ResponseType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ResponseType(static_cast<Enum>(result.value()));
  }

  constexpr V8ResponseType() = default;
  explicit constexpr V8ResponseType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ResponseType(const V8ResponseType&) = default;
  constexpr V8ResponseType(V8ResponseType&&) = default;
  ~V8ResponseType() = default;

  V8ResponseType& operator=(const V8ResponseType&) = default;
  V8ResponseType& operator=(V8ResponseType&&) = default;
  V8ResponseType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "basic", "cors", "default", "error", "opaque", "opaqueredirect"};
};

inline bool operator==(const V8ResponseType& lhs, V8ResponseType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ResponseType::Enum lhs, const V8ResponseType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_RESPONSE_TYPE_H_
