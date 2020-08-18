// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONTEXT_FRAME_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONTEXT_FRAME_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8ContextFrameType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kTopLevel, kNested, kAuxiliary, kNone };

  static V8ContextFrameType Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ContextFrameType", exception_state);
    return result.has_value()
               ? V8ContextFrameType(static_cast<Enum>(result.value()))
               : V8ContextFrameType();
  }
  static base::Optional<V8ContextFrameType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ContextFrameType(static_cast<Enum>(result.value()));
  }

  constexpr V8ContextFrameType() = default;
  explicit constexpr V8ContextFrameType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ContextFrameType(const V8ContextFrameType&) = default;
  constexpr V8ContextFrameType(V8ContextFrameType&&) = default;
  ~V8ContextFrameType() = default;

  V8ContextFrameType& operator=(const V8ContextFrameType&) = default;
  V8ContextFrameType& operator=(V8ContextFrameType&&) = default;
  V8ContextFrameType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"top-level", "nested",
                                                        "auxiliary", "none"};
};

inline bool operator==(const V8ContextFrameType& lhs,
                       V8ContextFrameType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ContextFrameType::Enum lhs,
                       const V8ContextFrameType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONTEXT_FRAME_TYPE_H_
