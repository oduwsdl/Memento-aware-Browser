// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/bindings/modules/v8/v8_background_fetch_failure_reason.h"

namespace blink {

const char* const V8BackgroundFetchFailureReason::string_table_[];

static_assert(std::is_trivially_copyable<V8BackgroundFetchFailureReason>::value,
              "");

V8BackgroundFetchFailureReason& V8BackgroundFetchFailureReason::operator=(
    const String& str_value) {
  const auto& index =
      bindings::FindIndexInEnumStringTable(str_value, string_table_);
  CHECK(index.has_value());
  return operator=(
      V8BackgroundFetchFailureReason(static_cast<Enum>(index.value())));
}

}  // namespace blink
