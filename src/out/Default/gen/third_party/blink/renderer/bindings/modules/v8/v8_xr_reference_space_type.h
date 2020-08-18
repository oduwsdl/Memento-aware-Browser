// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_REFERENCE_SPACE_TYPE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_REFERENCE_SPACE_TYPE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8XRReferenceSpaceType final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kBoundedFloor,
    kLocal,
    kLocalFloor,
    kUnbounded,
    kViewer
  };

  static V8XRReferenceSpaceType Create(v8::Isolate* isolate,
                                       v8::Local<v8::Value> value,
                                       ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "XRReferenceSpaceType", exception_state);
    return result.has_value()
               ? V8XRReferenceSpaceType(static_cast<Enum>(result.value()))
               : V8XRReferenceSpaceType();
  }
  static base::Optional<V8XRReferenceSpaceType> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8XRReferenceSpaceType(static_cast<Enum>(result.value()));
  }

  constexpr V8XRReferenceSpaceType() = default;
  explicit constexpr V8XRReferenceSpaceType(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8XRReferenceSpaceType(const V8XRReferenceSpaceType&) = default;
  constexpr V8XRReferenceSpaceType(V8XRReferenceSpaceType&&) = default;
  ~V8XRReferenceSpaceType() = default;

  V8XRReferenceSpaceType& operator=(const V8XRReferenceSpaceType&) = default;
  V8XRReferenceSpaceType& operator=(V8XRReferenceSpaceType&&) = default;
  V8XRReferenceSpaceType& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "bounded-floor", "local", "local-floor", "unbounded", "viewer"};
};

inline bool operator==(const V8XRReferenceSpaceType& lhs,
                       V8XRReferenceSpaceType::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8XRReferenceSpaceType::Enum lhs,
                       const V8XRReferenceSpaceType& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_XR_REFERENCE_SPACE_TYPE_H_
