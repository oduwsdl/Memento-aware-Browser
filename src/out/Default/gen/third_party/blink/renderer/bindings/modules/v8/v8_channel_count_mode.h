// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CHANNEL_COUNT_MODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CHANNEL_COUNT_MODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8ChannelCountMode final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kMax, kClampedMax, kExplicit };

  static V8ChannelCountMode Create(v8::Isolate* isolate,
                                   v8::Local<v8::Value> value,
                                   ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ChannelCountMode", exception_state);
    return result.has_value()
               ? V8ChannelCountMode(static_cast<Enum>(result.value()))
               : V8ChannelCountMode();
  }
  static base::Optional<V8ChannelCountMode> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ChannelCountMode(static_cast<Enum>(result.value()));
  }

  constexpr V8ChannelCountMode() = default;
  explicit constexpr V8ChannelCountMode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ChannelCountMode(const V8ChannelCountMode&) = default;
  constexpr V8ChannelCountMode(V8ChannelCountMode&&) = default;
  ~V8ChannelCountMode() = default;

  V8ChannelCountMode& operator=(const V8ChannelCountMode&) = default;
  V8ChannelCountMode& operator=(V8ChannelCountMode&&) = default;
  V8ChannelCountMode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"max", "clamped-max",
                                                        "explicit"};
};

inline bool operator==(const V8ChannelCountMode& lhs,
                       V8ChannelCountMode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ChannelCountMode::Enum lhs,
                       const V8ChannelCountMode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_CHANNEL_COUNT_MODE_H_
