// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SERVICE_WORKER_UPDATE_VIA_CACHE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SERVICE_WORKER_UPDATE_VIA_CACHE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8ServiceWorkerUpdateViaCache final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t { kImports, kAll, kNone };

  static V8ServiceWorkerUpdateViaCache Create(v8::Isolate* isolate,
                                              v8::Local<v8::Value> value,
                                              ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "ServiceWorkerUpdateViaCache",
        exception_state);
    return result.has_value() ? V8ServiceWorkerUpdateViaCache(
                                    static_cast<Enum>(result.value()))
                              : V8ServiceWorkerUpdateViaCache();
  }
  static base::Optional<V8ServiceWorkerUpdateViaCache> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8ServiceWorkerUpdateViaCache(static_cast<Enum>(result.value()));
  }

  constexpr V8ServiceWorkerUpdateViaCache() = default;
  explicit constexpr V8ServiceWorkerUpdateViaCache(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8ServiceWorkerUpdateViaCache(
      const V8ServiceWorkerUpdateViaCache&) = default;
  constexpr V8ServiceWorkerUpdateViaCache(V8ServiceWorkerUpdateViaCache&&) =
      default;
  ~V8ServiceWorkerUpdateViaCache() = default;

  V8ServiceWorkerUpdateViaCache& operator=(
      const V8ServiceWorkerUpdateViaCache&) = default;
  V8ServiceWorkerUpdateViaCache& operator=(V8ServiceWorkerUpdateViaCache&&) =
      default;
  V8ServiceWorkerUpdateViaCache& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"imports", "all",
                                                        "none"};
};

inline bool operator==(const V8ServiceWorkerUpdateViaCache& lhs,
                       V8ServiceWorkerUpdateViaCache::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8ServiceWorkerUpdateViaCache::Enum lhs,
                       const V8ServiceWorkerUpdateViaCache& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SERVICE_WORKER_UPDATE_VIA_CACHE_H_
