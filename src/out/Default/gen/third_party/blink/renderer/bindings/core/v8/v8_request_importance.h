// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_IMPORTANCE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_IMPORTANCE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8RequestImportance final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kLow, kAuto, kHigh };

  static V8RequestImportance Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "RequestImportance", exception_state);
    return result.has_value()
               ? V8RequestImportance(static_cast<Enum>(result.value()))
               : V8RequestImportance();
  }
  static base::Optional<V8RequestImportance> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8RequestImportance(static_cast<Enum>(result.value()));
  }

  constexpr V8RequestImportance() = default;
  explicit constexpr V8RequestImportance(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8RequestImportance(const V8RequestImportance&) = default;
  constexpr V8RequestImportance(V8RequestImportance&&) = default;
  ~V8RequestImportance() = default;

  V8RequestImportance& operator=(const V8RequestImportance&) = default;
  V8RequestImportance& operator=(V8RequestImportance&&) = default;
  V8RequestImportance& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"low", "auto", "high"};
};

inline bool operator==(const V8RequestImportance& lhs,
                       V8RequestImportance::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8RequestImportance::Enum lhs,
                       const V8RequestImportance& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_REQUEST_IMPORTANCE_H_
