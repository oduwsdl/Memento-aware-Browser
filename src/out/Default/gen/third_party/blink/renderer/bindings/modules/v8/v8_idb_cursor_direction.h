// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_CURSOR_DIRECTION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_CURSOR_DIRECTION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8IDBCursorDirection final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNext, kNextunique, kPrev, kPrevunique };

  static V8IDBCursorDirection Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "IDBCursorDirection", exception_state);
    return result.has_value()
               ? V8IDBCursorDirection(static_cast<Enum>(result.value()))
               : V8IDBCursorDirection();
  }
  static base::Optional<V8IDBCursorDirection> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8IDBCursorDirection(static_cast<Enum>(result.value()));
  }

  constexpr V8IDBCursorDirection() = default;
  explicit constexpr V8IDBCursorDirection(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8IDBCursorDirection(const V8IDBCursorDirection&) = default;
  constexpr V8IDBCursorDirection(V8IDBCursorDirection&&) = default;
  ~V8IDBCursorDirection() = default;

  V8IDBCursorDirection& operator=(const V8IDBCursorDirection&) = default;
  V8IDBCursorDirection& operator=(V8IDBCursorDirection&&) = default;
  V8IDBCursorDirection& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"next", "nextunique",
                                                        "prev", "prevunique"};
};

inline bool operator==(const V8IDBCursorDirection& lhs,
                       V8IDBCursorDirection::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8IDBCursorDirection::Enum lhs,
                       const V8IDBCursorDirection& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_IDB_CURSOR_DIRECTION_H_
