// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/bindings/core/v8/v8_scroll_behavior.h"

namespace blink {

const char* const V8ScrollBehavior::string_table_[];

static_assert(std::is_trivially_copyable<V8ScrollBehavior>::value, "");

V8ScrollBehavior& V8ScrollBehavior::operator=(const String& str_value) {
  const auto& index =
      bindings::FindIndexInEnumStringTable(str_value, string_table_);
  CHECK(index.has_value());
  return operator=(V8ScrollBehavior(static_cast<Enum>(index.value())));
}

}  // namespace blink
