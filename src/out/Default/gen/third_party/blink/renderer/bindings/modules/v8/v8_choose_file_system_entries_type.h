// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CHOOSE_FILE_SYSTEM_ENTRIES_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CHOOSE_FILE_SYSTEM_ENTRIES_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8ChooseFileSystemEntriesType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kOpenFile, kSaveFile, kOpenDirectory };

  static V8ChooseFileSystemEntriesType Create(v8::Isolate* isolate,
                                              v8::Local<v8::Value> value,
                                              ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ChooseFileSystemEntriesType",
        exception_state);
    return result.has_value() ? V8ChooseFileSystemEntriesType(
                                    static_cast<Enum>(result.value()))
                              : V8ChooseFileSystemEntriesType();
  }
  static base::Optional<V8ChooseFileSystemEntriesType> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ChooseFileSystemEntriesType(static_cast<Enum>(result.value()));
  }

  constexpr V8ChooseFileSystemEntriesType() = default;
  explicit constexpr V8ChooseFileSystemEntriesType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ChooseFileSystemEntriesType(
      const V8ChooseFileSystemEntriesType&) = default;
  constexpr V8ChooseFileSystemEntriesType(V8ChooseFileSystemEntriesType&&) =
      default;
  ~V8ChooseFileSystemEntriesType() = default;

  V8ChooseFileSystemEntriesType& operator=(
      const V8ChooseFileSystemEntriesType&) = default;
  V8ChooseFileSystemEntriesType& operator=(V8ChooseFileSystemEntriesType&&) =
      default;
  V8ChooseFileSystemEntriesType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "open-file", "save-file", "open-directory"};
};

inline bool operator==(const V8ChooseFileSystemEntriesType& lhs,
                       V8ChooseFileSystemEntriesType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ChooseFileSystemEntriesType::Enum lhs,
                       const V8ChooseFileSystemEntriesType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CHOOSE_FILE_SYSTEM_ENTRIES_TYPE_H_
