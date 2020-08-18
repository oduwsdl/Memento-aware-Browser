// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/bindings/core/v8/v8_resize_observer_box_options.h"

namespace blink {

const char* const V8ResizeObserverBoxOptions::string_table_[];

static_assert(std::is_trivially_copyable<V8ResizeObserverBoxOptions>::value,
              "");

V8ResizeObserverBoxOptions& V8ResizeObserverBoxOptions::operator=(
    const String& str_value) {
  const auto& index =
      bindings::FindIndexInEnumStringTable(str_value, string_table_);
  CHECK(index.has_value());
  return operator=(
      V8ResizeObserverBoxOptions(static_cast<Enum>(index.value())));
}

}  // namespace blink
