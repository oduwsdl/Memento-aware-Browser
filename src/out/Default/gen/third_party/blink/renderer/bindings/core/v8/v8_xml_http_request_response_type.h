// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_XML_HTTP_REQUEST_RESPONSE_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_XML_HTTP_REQUEST_RESPONSE_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class CORE_EXPORT V8XMLHttpRequestResponseType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    k,
    kArraybuffer,
    kBlob,
    kDocument,
    kJson,
    kText
  };

  static V8XMLHttpRequestResponseType Create(v8::Isolate* isolate,
                                             v8::Local<v8::Value> value,
                                             ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "XMLHttpRequestResponseType",
        exception_state);
    return result.has_value()
               ? V8XMLHttpRequestResponseType(static_cast<Enum>(result.value()))
               : V8XMLHttpRequestResponseType();
  }
  static base::Optional<V8XMLHttpRequestResponseType> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8XMLHttpRequestResponseType(static_cast<Enum>(result.value()));
  }

  constexpr V8XMLHttpRequestResponseType() = default;
  explicit constexpr V8XMLHttpRequestResponseType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8XMLHttpRequestResponseType(const V8XMLHttpRequestResponseType&) =
      default;
  constexpr V8XMLHttpRequestResponseType(V8XMLHttpRequestResponseType&&) =
      default;
  ~V8XMLHttpRequestResponseType() = default;

  V8XMLHttpRequestResponseType& operator=(const V8XMLHttpRequestResponseType&) =
      default;
  V8XMLHttpRequestResponseType& operator=(V8XMLHttpRequestResponseType&&) =
      default;
  V8XMLHttpRequestResponseType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "", "arraybuffer", "blob", "document", "json", "text"};
};

inline bool operator==(const V8XMLHttpRequestResponseType& lhs,
                       V8XMLHttpRequestResponseType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8XMLHttpRequestResponseType::Enum lhs,
                       const V8XMLHttpRequestResponseType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_XML_HTTP_REQUEST_RESPONSE_TYPE_H_
