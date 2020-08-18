// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_TRANSACTION_DURABILITY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_TRANSACTION_DURABILITY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8IDBTransactionDurability final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kDefault, kStrict, kRelaxed };

  static V8IDBTransactionDurability Create(v8::Isolate* isolate,
                                           v8::Local<v8::Value> value,
                                           ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "IDBTransactionDurability",
        exception_state);
    return result.has_value()
               ? V8IDBTransactionDurability(static_cast<Enum>(result.value()))
               : V8IDBTransactionDurability();
  }
  static base::Optional<V8IDBTransactionDurability> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8IDBTransactionDurability(static_cast<Enum>(result.value()));
  }

  constexpr V8IDBTransactionDurability() = default;
  explicit constexpr V8IDBTransactionDurability(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8IDBTransactionDurability(const V8IDBTransactionDurability&) =
      default;
  constexpr V8IDBTransactionDurability(V8IDBTransactionDurability&&) = default;
  ~V8IDBTransactionDurability() = default;

  V8IDBTransactionDurability& operator=(const V8IDBTransactionDurability&) =
      default;
  V8IDBTransactionDurability& operator=(V8IDBTransactionDurability&&) = default;
  V8IDBTransactionDurability& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"default", "strict",
                                                        "relaxed"};
};

inline bool operator==(const V8IDBTransactionDurability& lhs,
                       V8IDBTransactionDurability::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8IDBTransactionDurability::Enum lhs,
                       const V8IDBTransactionDurability& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_TRANSACTION_DURABILITY_H_
