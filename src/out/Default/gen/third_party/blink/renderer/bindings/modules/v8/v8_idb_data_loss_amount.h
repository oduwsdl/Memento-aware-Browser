// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_DATA_LOSS_AMOUNT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_DATA_LOSS_AMOUNT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8IDBDataLossAmount final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNone, kTotal };

  static V8IDBDataLossAmount Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "IDBDataLossAmount", exception_state);
    return result.has_value()
               ? V8IDBDataLossAmount(static_cast<Enum>(result.value()))
               : V8IDBDataLossAmount();
  }
  static base::Optional<V8IDBDataLossAmount> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8IDBDataLossAmount(static_cast<Enum>(result.value()));
  }

  constexpr V8IDBDataLossAmount() = default;
  explicit constexpr V8IDBDataLossAmount(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8IDBDataLossAmount(const V8IDBDataLossAmount&) = default;
  constexpr V8IDBDataLossAmount(V8IDBDataLossAmount&&) = default;
  ~V8IDBDataLossAmount() = default;

  V8IDBDataLossAmount& operator=(const V8IDBDataLossAmount&) = default;
  V8IDBDataLossAmount& operator=(V8IDBDataLossAmount&&) = default;
  V8IDBDataLossAmount& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"none", "total"};
};

inline bool operator==(const V8IDBDataLossAmount& lhs,
                       V8IDBDataLossAmount::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8IDBDataLossAmount::Enum lhs,
                       const V8IDBDataLossAmount& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_DATA_LOSS_AMOUNT_H_
