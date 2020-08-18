// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_EFFECTIVE_CONNECTION_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_EFFECTIVE_CONNECTION_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8EffectiveConnectionType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kSlow2G, k2G, k3G, k4G };

  static V8EffectiveConnectionType Create(v8::Isolate* isolate,
                                          v8::Local<v8::Value> value,
                                          ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "EffectiveConnectionType",
        exception_state);
    return result.has_value()
               ? V8EffectiveConnectionType(static_cast<Enum>(result.value()))
               : V8EffectiveConnectionType();
  }
  static base::Optional<V8EffectiveConnectionType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8EffectiveConnectionType(static_cast<Enum>(result.value()));
  }

  constexpr V8EffectiveConnectionType() = default;
  explicit constexpr V8EffectiveConnectionType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8EffectiveConnectionType(const V8EffectiveConnectionType&) =
      default;
  constexpr V8EffectiveConnectionType(V8EffectiveConnectionType&&) = default;
  ~V8EffectiveConnectionType() = default;

  V8EffectiveConnectionType& operator=(const V8EffectiveConnectionType&) =
      default;
  V8EffectiveConnectionType& operator=(V8EffectiveConnectionType&&) = default;
  V8EffectiveConnectionType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"slow-2g", "2g", "3g",
                                                        "4g"};
};

inline bool operator==(const V8EffectiveConnectionType& lhs,
                       V8EffectiveConnectionType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8EffectiveConnectionType::Enum lhs,
                       const V8EffectiveConnectionType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_EFFECTIVE_CONNECTION_TYPE_H_
