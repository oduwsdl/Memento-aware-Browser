// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PUSH_ENCRYPTION_KEY_NAME_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PUSH_ENCRYPTION_KEY_NAME_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8PushEncryptionKeyName final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kP256Dh, kAuth };

  static V8PushEncryptionKeyName Create(v8::Isolate* isolate,
                                        v8::Local<v8::Value> value,
                                        ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "PushEncryptionKeyName",
        exception_state);
    return result.has_value()
               ? V8PushEncryptionKeyName(static_cast<Enum>(result.value()))
               : V8PushEncryptionKeyName();
  }
  static base::Optional<V8PushEncryptionKeyName> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8PushEncryptionKeyName(static_cast<Enum>(result.value()));
  }

  constexpr V8PushEncryptionKeyName() = default;
  explicit constexpr V8PushEncryptionKeyName(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8PushEncryptionKeyName(const V8PushEncryptionKeyName&) = default;
  constexpr V8PushEncryptionKeyName(V8PushEncryptionKeyName&&) = default;
  ~V8PushEncryptionKeyName() = default;

  V8PushEncryptionKeyName& operator=(const V8PushEncryptionKeyName&) = default;
  V8PushEncryptionKeyName& operator=(V8PushEncryptionKeyName&&) = default;
  V8PushEncryptionKeyName& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"p256dh", "auth"};
};

inline bool operator==(const V8PushEncryptionKeyName& lhs,
                       V8PushEncryptionKeyName::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8PushEncryptionKeyName::Enum lhs,
                       const V8PushEncryptionKeyName& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_PUSH_ENCRYPTION_KEY_NAME_H_
