// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CLIENT_LIFECYCLE_STATE_QUERY_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CLIENT_LIFECYCLE_STATE_QUERY_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8ClientLifecycleStateQuery final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kActive, kFrozen, kAll };

  static V8ClientLifecycleStateQuery Create(v8::Isolate* isolate,
                                            v8::Local<v8::Value> value,
                                            ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ClientLifecycleStateQuery",
        exception_state);
    return result.has_value()
               ? V8ClientLifecycleStateQuery(static_cast<Enum>(result.value()))
               : V8ClientLifecycleStateQuery();
  }
  static base::Optional<V8ClientLifecycleStateQuery> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ClientLifecycleStateQuery(static_cast<Enum>(result.value()));
  }

  constexpr V8ClientLifecycleStateQuery() = default;
  explicit constexpr V8ClientLifecycleStateQuery(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ClientLifecycleStateQuery(const V8ClientLifecycleStateQuery&) =
      default;
  constexpr V8ClientLifecycleStateQuery(V8ClientLifecycleStateQuery&&) =
      default;
  ~V8ClientLifecycleStateQuery() = default;

  V8ClientLifecycleStateQuery& operator=(const V8ClientLifecycleStateQuery&) =
      default;
  V8ClientLifecycleStateQuery& operator=(V8ClientLifecycleStateQuery&&) =
      default;
  V8ClientLifecycleStateQuery& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"active", "frozen",
                                                        "all"};
};

inline bool operator==(const V8ClientLifecycleStateQuery& lhs,
                       V8ClientLifecycleStateQuery::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ClientLifecycleStateQuery::Enum lhs,
                       const V8ClientLifecycleStateQuery& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CLIENT_LIFECYCLE_STATE_QUERY_H_
