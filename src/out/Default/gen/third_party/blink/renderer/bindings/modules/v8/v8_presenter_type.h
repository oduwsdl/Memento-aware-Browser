// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PRESENTER_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PRESENTER_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8PresenterType final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kDelegatedInkTrail };

  static V8PresenterType Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "PresenterType", exception_state);
    return result.has_value()
               ? V8PresenterType(static_cast<Enum>(result.value()))
               : V8PresenterType();
  }
  static base::Optional<V8PresenterType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8PresenterType(static_cast<Enum>(result.value()));
  }

  constexpr V8PresenterType() = default;
  explicit constexpr V8PresenterType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8PresenterType(const V8PresenterType&) = default;
  constexpr V8PresenterType(V8PresenterType&&) = default;
  ~V8PresenterType() = default;

  V8PresenterType& operator=(const V8PresenterType&) = default;
  V8PresenterType& operator=(V8PresenterType&&) = default;
  V8PresenterType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"delegated-ink-trail"};
};

inline bool operator==(const V8PresenterType& lhs, V8PresenterType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8PresenterType::Enum lhs, const V8PresenterType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PRESENTER_TYPE_H_
