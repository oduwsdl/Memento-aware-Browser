// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CAN_PLAY_TYPE_RESULT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CAN_PLAY_TYPE_RESULT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8CanPlayTypeResult final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { k, kMaybe, kProbably };

  static V8CanPlayTypeResult Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "CanPlayTypeResult", exception_state);
    return result.has_value()
               ? V8CanPlayTypeResult(static_cast<Enum>(result.value()))
               : V8CanPlayTypeResult();
  }
  static base::Optional<V8CanPlayTypeResult> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8CanPlayTypeResult(static_cast<Enum>(result.value()));
  }

  constexpr V8CanPlayTypeResult() = default;
  explicit constexpr V8CanPlayTypeResult(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8CanPlayTypeResult(const V8CanPlayTypeResult&) = default;
  constexpr V8CanPlayTypeResult(V8CanPlayTypeResult&&) = default;
  ~V8CanPlayTypeResult() = default;

  V8CanPlayTypeResult& operator=(const V8CanPlayTypeResult&) = default;
  V8CanPlayTypeResult& operator=(V8CanPlayTypeResult&&) = default;
  V8CanPlayTypeResult& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"", "maybe",
                                                        "probably"};
};

inline bool operator==(const V8CanPlayTypeResult& lhs,
                       V8CanPlayTypeResult::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8CanPlayTypeResult::Enum lhs,
                       const V8CanPlayTypeResult& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_CAN_PLAY_TYPE_RESULT_H_
