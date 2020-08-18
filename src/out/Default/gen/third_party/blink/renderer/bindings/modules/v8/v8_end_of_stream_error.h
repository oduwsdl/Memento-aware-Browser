// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_END_OF_STREAM_ERROR_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_END_OF_STREAM_ERROR_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8EndOfStreamError final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kNetwork, kDecode };

  static V8EndOfStreamError Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "EndOfStreamError", exception_state);
    return result.has_value()
               ? V8EndOfStreamError(static_cast<Enum>(result.value()))
               : V8EndOfStreamError();
  }
  static base::Optional<V8EndOfStreamError> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8EndOfStreamError(static_cast<Enum>(result.value()));
  }

  constexpr V8EndOfStreamError() = default;
  explicit constexpr V8EndOfStreamError(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8EndOfStreamError(const V8EndOfStreamError&) = default;
  constexpr V8EndOfStreamError(V8EndOfStreamError&&) = default;
  ~V8EndOfStreamError() = default;

  V8EndOfStreamError& operator=(const V8EndOfStreamError&) = default;
  V8EndOfStreamError& operator=(V8EndOfStreamError&&) = default;
  V8EndOfStreamError& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"network", "decode"};
};

inline bool operator==(const V8EndOfStreamError& lhs,
                       V8EndOfStreamError::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8EndOfStreamError::Enum lhs,
                       const V8EndOfStreamError& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_END_OF_STREAM_ERROR_H_
