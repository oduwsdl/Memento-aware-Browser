// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FONT_FACE_LOAD_STATUS_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FONT_FACE_LOAD_STATUS_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8FontFaceLoadStatus final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kUnloaded, kLoading, kLoaded, kError };

  static V8FontFaceLoadStatus Create(v8::Isolate* isolate,
                                     v8::Local<v8::Value> value,
                                     ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "FontFaceLoadStatus", exception_state);
    return result.has_value()
               ? V8FontFaceLoadStatus(static_cast<Enum>(result.value()))
               : V8FontFaceLoadStatus();
  }
  static base::Optional<V8FontFaceLoadStatus> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8FontFaceLoadStatus(static_cast<Enum>(result.value()));
  }

  constexpr V8FontFaceLoadStatus() = default;
  explicit constexpr V8FontFaceLoadStatus(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8FontFaceLoadStatus(const V8FontFaceLoadStatus&) = default;
  constexpr V8FontFaceLoadStatus(V8FontFaceLoadStatus&&) = default;
  ~V8FontFaceLoadStatus() = default;

  V8FontFaceLoadStatus& operator=(const V8FontFaceLoadStatus&) = default;
  V8FontFaceLoadStatus& operator=(V8FontFaceLoadStatus&&) = default;
  V8FontFaceLoadStatus& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"unloaded", "loading",
                                                        "loaded", "error"};
};

inline bool operator==(const V8FontFaceLoadStatus& lhs,
                       V8FontFaceLoadStatus::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8FontFaceLoadStatus::Enum lhs,
                       const V8FontFaceLoadStatus& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_FONT_FACE_LOAD_STATUS_H_
