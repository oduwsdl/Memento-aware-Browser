// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_WRITE_COMMAND_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_WRITE_COMMAND_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8WriteCommandType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kTruncate, kSeek, kWrite };

  static V8WriteCommandType Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "WriteCommandType", exception_state);
    return result.has_value()
               ? V8WriteCommandType(static_cast<Enum>(result.value()))
               : V8WriteCommandType();
  }
  static base::Optional<V8WriteCommandType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8WriteCommandType(static_cast<Enum>(result.value()));
  }

  constexpr V8WriteCommandType() = default;
  explicit constexpr V8WriteCommandType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8WriteCommandType(const V8WriteCommandType&) = default;
  constexpr V8WriteCommandType(V8WriteCommandType&&) = default;
  ~V8WriteCommandType() = default;

  V8WriteCommandType& operator=(const V8WriteCommandType&) = default;
  V8WriteCommandType& operator=(V8WriteCommandType&&) = default;
  V8WriteCommandType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"truncate", "seek",
                                                        "write"};
};

inline bool operator==(const V8WriteCommandType& lhs,
                       V8WriteCommandType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8WriteCommandType::Enum lhs,
                       const V8WriteCommandType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_WRITE_COMMAND_TYPE_H_
