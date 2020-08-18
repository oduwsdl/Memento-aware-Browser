// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_TIMELINE_AUTO_KEYWORD_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_TIMELINE_AUTO_KEYWORD_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ScrollTimelineAutoKeyword final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAuto };

  static V8ScrollTimelineAutoKeyword Create(v8::Isolate* isolate,
                                            v8::Local<v8::Value> value,
                                            ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ScrollTimelineAutoKeyword",
        exception_state);
    return result.has_value()
               ? V8ScrollTimelineAutoKeyword(static_cast<Enum>(result.value()))
               : V8ScrollTimelineAutoKeyword();
  }
  static base::Optional<V8ScrollTimelineAutoKeyword> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ScrollTimelineAutoKeyword(static_cast<Enum>(result.value()));
  }

  constexpr V8ScrollTimelineAutoKeyword() = default;
  explicit constexpr V8ScrollTimelineAutoKeyword(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ScrollTimelineAutoKeyword(const V8ScrollTimelineAutoKeyword&) =
      default;
  constexpr V8ScrollTimelineAutoKeyword(V8ScrollTimelineAutoKeyword&&) =
      default;
  ~V8ScrollTimelineAutoKeyword() = default;

  V8ScrollTimelineAutoKeyword& operator=(const V8ScrollTimelineAutoKeyword&) =
      default;
  V8ScrollTimelineAutoKeyword& operator=(V8ScrollTimelineAutoKeyword&&) =
      default;
  V8ScrollTimelineAutoKeyword& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"auto"};
};

inline bool operator==(const V8ScrollTimelineAutoKeyword& lhs,
                       V8ScrollTimelineAutoKeyword::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ScrollTimelineAutoKeyword::Enum lhs,
                       const V8ScrollTimelineAutoKeyword& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_SCROLL_TIMELINE_AUTO_KEYWORD_H_
