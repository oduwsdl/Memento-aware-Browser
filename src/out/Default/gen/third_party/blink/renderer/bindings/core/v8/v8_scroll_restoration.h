// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_RESTORATION_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_RESTORATION_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ScrollRestoration final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAuto, kManual };

  static V8ScrollRestoration Create(v8::Isolate* isolate,
                                    v8::Local<v8::Value> value,
                                    ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ScrollRestoration", exception_state);
    return result.has_value()
               ? V8ScrollRestoration(static_cast<Enum>(result.value()))
               : V8ScrollRestoration();
  }
  static base::Optional<V8ScrollRestoration> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ScrollRestoration(static_cast<Enum>(result.value()));
  }

  constexpr V8ScrollRestoration() = default;
  explicit constexpr V8ScrollRestoration(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ScrollRestoration(const V8ScrollRestoration&) = default;
  constexpr V8ScrollRestoration(V8ScrollRestoration&&) = default;
  ~V8ScrollRestoration() = default;

  V8ScrollRestoration& operator=(const V8ScrollRestoration&) = default;
  V8ScrollRestoration& operator=(V8ScrollRestoration&&) = default;
  V8ScrollRestoration& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"auto", "manual"};
};

inline bool operator==(const V8ScrollRestoration& lhs,
                       V8ScrollRestoration::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ScrollRestoration::Enum lhs,
                       const V8ScrollRestoration& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_RESTORATION_H_
