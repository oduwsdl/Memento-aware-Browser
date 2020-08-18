// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONTENT_CATEGORY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONTENT_CATEGORY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8ContentCategory final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { k, kHomepage, kArticle, kVideo, kAudio };

  static V8ContentCategory Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ContentCategory", exception_state);
    return result.has_value()
               ? V8ContentCategory(static_cast<Enum>(result.value()))
               : V8ContentCategory();
  }
  static base::Optional<V8ContentCategory> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ContentCategory(static_cast<Enum>(result.value()));
  }

  constexpr V8ContentCategory() = default;
  explicit constexpr V8ContentCategory(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ContentCategory(const V8ContentCategory&) = default;
  constexpr V8ContentCategory(V8ContentCategory&&) = default;
  ~V8ContentCategory() = default;

  V8ContentCategory& operator=(const V8ContentCategory&) = default;
  V8ContentCategory& operator=(V8ContentCategory&&) = default;
  V8ContentCategory& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "", "homepage", "article", "video", "audio"};
};

inline bool operator==(const V8ContentCategory& lhs,
                       V8ContentCategory::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ContentCategory::Enum lhs,
                       const V8ContentCategory& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CONTENT_CATEGORY_H_
