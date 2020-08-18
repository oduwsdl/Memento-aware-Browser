// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CLIENT_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CLIENT_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8ClientType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kWindow, kWorker, kSharedworker, kAll };

  static V8ClientType Create(v8::Isolate* isolate,
                             v8::Local<v8::Value> value,
                             ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ClientType", exception_state);
    return result.has_value() ? V8ClientType(static_cast<Enum>(result.value()))
                              : V8ClientType();
  }
  static base::Optional<V8ClientType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ClientType(static_cast<Enum>(result.value()));
  }

  constexpr V8ClientType() = default;
  explicit constexpr V8ClientType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ClientType(const V8ClientType&) = default;
  constexpr V8ClientType(V8ClientType&&) = default;
  ~V8ClientType() = default;

  V8ClientType& operator=(const V8ClientType&) = default;
  V8ClientType& operator=(V8ClientType&&) = default;
  V8ClientType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"window", "worker",
                                                        "sharedworker", "all"};
};

inline bool operator==(const V8ClientType& lhs, V8ClientType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ClientType::Enum lhs, const V8ClientType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CLIENT_TYPE_H_
