// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FULLSCREEN_NAVIGATION_UI_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FULLSCREEN_NAVIGATION_UI_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8FullscreenNavigationUI final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kAuto, kShow, kHide };

  static V8FullscreenNavigationUI Create(v8::Isolate* isolate,
                                         v8::Local<v8::Value> value,
                                         ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "FullscreenNavigationUI",
        exception_state);
    return result.has_value()
               ? V8FullscreenNavigationUI(static_cast<Enum>(result.value()))
               : V8FullscreenNavigationUI();
  }
  static base::Optional<V8FullscreenNavigationUI> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8FullscreenNavigationUI(static_cast<Enum>(result.value()));
  }

  constexpr V8FullscreenNavigationUI() = default;
  explicit constexpr V8FullscreenNavigationUI(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8FullscreenNavigationUI(const V8FullscreenNavigationUI&) = default;
  constexpr V8FullscreenNavigationUI(V8FullscreenNavigationUI&&) = default;
  ~V8FullscreenNavigationUI() = default;

  V8FullscreenNavigationUI& operator=(const V8FullscreenNavigationUI&) =
      default;
  V8FullscreenNavigationUI& operator=(V8FullscreenNavigationUI&&) = default;
  V8FullscreenNavigationUI& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"auto", "show", "hide"};
};

inline bool operator==(const V8FullscreenNavigationUI& lhs,
                       V8FullscreenNavigationUI::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8FullscreenNavigationUI::Enum lhs,
                       const V8FullscreenNavigationUI& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FULLSCREEN_NAVIGATION_UI_H_
