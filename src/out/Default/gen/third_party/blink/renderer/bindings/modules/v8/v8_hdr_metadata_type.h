// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_HDR_METADATA_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_HDR_METADATA_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8HdrMetadataType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kSmpteSt2086, kSmpteSt209410, kSmpteSt209440 };

  static V8HdrMetadataType Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "HdrMetadataType", exception_state);
    return result.has_value()
               ? V8HdrMetadataType(static_cast<Enum>(result.value()))
               : V8HdrMetadataType();
  }
  static base::Optional<V8HdrMetadataType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8HdrMetadataType(static_cast<Enum>(result.value()));
  }

  constexpr V8HdrMetadataType() = default;
  explicit constexpr V8HdrMetadataType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8HdrMetadataType(const V8HdrMetadataType&) = default;
  constexpr V8HdrMetadataType(V8HdrMetadataType&&) = default;
  ~V8HdrMetadataType() = default;

  V8HdrMetadataType& operator=(const V8HdrMetadataType&) = default;
  V8HdrMetadataType& operator=(V8HdrMetadataType&&) = default;
  V8HdrMetadataType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "smpteSt2086", "smpteSt2094-10", "smpteSt2094-40"};
};

inline bool operator==(const V8HdrMetadataType& lhs,
                       V8HdrMetadataType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8HdrMetadataType::Enum lhs,
                       const V8HdrMetadataType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_HDR_METADATA_TYPE_H_
