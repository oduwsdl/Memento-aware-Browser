// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_OBSERVATION_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_OBSERVATION_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8IDBObservationType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAdd, kPut, kDelete, kClear };

  static V8IDBObservationType Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "IDBObservationType", exception_state);
    return result.has_value()
               ? V8IDBObservationType(static_cast<Enum>(result.value()))
               : V8IDBObservationType();
  }
  static base::Optional<V8IDBObservationType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8IDBObservationType(static_cast<Enum>(result.value()));
  }

  constexpr V8IDBObservationType() = default;
  explicit constexpr V8IDBObservationType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8IDBObservationType(const V8IDBObservationType&) = default;
  constexpr V8IDBObservationType(V8IDBObservationType&&) = default;
  ~V8IDBObservationType() = default;

  V8IDBObservationType& operator=(const V8IDBObservationType&) = default;
  V8IDBObservationType& operator=(V8IDBObservationType&&) = default;
  V8IDBObservationType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"add", "put", "delete",
                                                        "clear"};
};

inline bool operator==(const V8IDBObservationType& lhs,
                       V8IDBObservationType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8IDBObservationType::Enum lhs,
                       const V8IDBObservationType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_OBSERVATION_TYPE_H_
