// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_REQUEST_READY_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_REQUEST_READY_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8IDBRequestReadyState final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kPending, kDone };

  static V8IDBRequestReadyState Create(v8::Isolate* isolate,
                                       v8::Local<v8::Value> value,
                                       ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "IDBRequestReadyState", exception_state);
    return result.has_value()
               ? V8IDBRequestReadyState(static_cast<Enum>(result.value()))
               : V8IDBRequestReadyState();
  }
  static base::Optional<V8IDBRequestReadyState> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8IDBRequestReadyState(static_cast<Enum>(result.value()));
  }

  constexpr V8IDBRequestReadyState() = default;
  explicit constexpr V8IDBRequestReadyState(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8IDBRequestReadyState(const V8IDBRequestReadyState&) = default;
  constexpr V8IDBRequestReadyState(V8IDBRequestReadyState&&) = default;
  ~V8IDBRequestReadyState() = default;

  V8IDBRequestReadyState& operator=(const V8IDBRequestReadyState&) = default;
  V8IDBRequestReadyState& operator=(V8IDBRequestReadyState&&) = default;
  V8IDBRequestReadyState& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"pending", "done"};
};

inline bool operator==(const V8IDBRequestReadyState& lhs,
                       V8IDBRequestReadyState::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8IDBRequestReadyState::Enum lhs,
                       const V8IDBRequestReadyState& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_REQUEST_READY_STATE_H_
