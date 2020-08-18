// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BACKGROUND_FETCH_RESULT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BACKGROUND_FETCH_RESULT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8BackgroundFetchResult final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { k, kSuccess, kFailure };

  static V8BackgroundFetchResult Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "BackgroundFetchResult",
        exception_state);
    return result.has_value()
               ? V8BackgroundFetchResult(static_cast<Enum>(result.value()))
               : V8BackgroundFetchResult();
  }
  static base::Optional<V8BackgroundFetchResult> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8BackgroundFetchResult(static_cast<Enum>(result.value()));
  }

  constexpr V8BackgroundFetchResult() = default;
  explicit constexpr V8BackgroundFetchResult(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8BackgroundFetchResult(const V8BackgroundFetchResult&) = default;
  constexpr V8BackgroundFetchResult(V8BackgroundFetchResult&&) = default;
  ~V8BackgroundFetchResult() = default;

  V8BackgroundFetchResult& operator=(const V8BackgroundFetchResult&) = default;
  V8BackgroundFetchResult& operator=(V8BackgroundFetchResult&&) = default;
  V8BackgroundFetchResult& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"", "success",
                                                        "failure"};
};

inline bool operator==(const V8BackgroundFetchResult& lhs,
                       V8BackgroundFetchResult::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8BackgroundFetchResult::Enum lhs,
                       const V8BackgroundFetchResult& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BACKGROUND_FETCH_RESULT_H_
