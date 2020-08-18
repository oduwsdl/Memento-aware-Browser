// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_DATA_STORAGE_FORMAT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_DATA_STORAGE_FORMAT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8ImageDataStorageFormat final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kUint8, kUint16, kFloat32 };

  static V8ImageDataStorageFormat Create(v8::Isolate* isolate,
                                         v8::Local<v8::Value> value,
                                         ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ImageDataStorageFormat",
        exception_state);
    return result.has_value()
               ? V8ImageDataStorageFormat(static_cast<Enum>(result.value()))
               : V8ImageDataStorageFormat();
  }
  static base::Optional<V8ImageDataStorageFormat> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ImageDataStorageFormat(static_cast<Enum>(result.value()));
  }

  constexpr V8ImageDataStorageFormat() = default;
  explicit constexpr V8ImageDataStorageFormat(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ImageDataStorageFormat(const V8ImageDataStorageFormat&) = default;
  constexpr V8ImageDataStorageFormat(V8ImageDataStorageFormat&&) = default;
  ~V8ImageDataStorageFormat() = default;

  V8ImageDataStorageFormat& operator=(const V8ImageDataStorageFormat&) =
      default;
  V8ImageDataStorageFormat& operator=(V8ImageDataStorageFormat&&) = default;
  V8ImageDataStorageFormat& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"uint8", "uint16",
                                                        "float32"};
};

inline bool operator==(const V8ImageDataStorageFormat& lhs,
                       V8ImageDataStorageFormat::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ImageDataStorageFormat::Enum lhs,
                       const V8ImageDataStorageFormat& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_IMAGE_DATA_STORAGE_FORMAT_H_
