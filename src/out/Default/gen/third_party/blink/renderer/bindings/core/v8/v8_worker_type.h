// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_WORKER_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_WORKER_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8WorkerType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kClassic, kModule };

  static V8WorkerType Create(v8::Isolate* isolate,
                             v8::Local<v8::Value> value,
                             ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "WorkerType", exception_state);
    return result.has_value() ? V8WorkerType(static_cast<Enum>(result.value()))
                              : V8WorkerType();
  }
  static base::Optional<V8WorkerType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8WorkerType(static_cast<Enum>(result.value()));
  }

  constexpr V8WorkerType() = default;
  explicit constexpr V8WorkerType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8WorkerType(const V8WorkerType&) = default;
  constexpr V8WorkerType(V8WorkerType&&) = default;
  ~V8WorkerType() = default;

  V8WorkerType& operator=(const V8WorkerType&) = default;
  V8WorkerType& operator=(V8WorkerType&&) = default;
  V8WorkerType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"classic", "module"};
};

inline bool operator==(const V8WorkerType& lhs, V8WorkerType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8WorkerType::Enum lhs, const V8WorkerType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_WORKER_TYPE_H_
