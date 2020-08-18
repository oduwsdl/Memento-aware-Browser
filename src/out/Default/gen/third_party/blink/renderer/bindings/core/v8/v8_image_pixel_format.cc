// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/bindings/core/v8/v8_image_pixel_format.h"

namespace blink {

const char* const V8ImagePixelFormat::string_table_[];

static_assert(std::is_trivially_copyable<V8ImagePixelFormat>::value, "");

V8ImagePixelFormat& V8ImagePixelFormat::operator=(const String& str_value) {
  const auto& index =
      bindings::FindIndexInEnumStringTable(str_value, string_table_);
  CHECK(index.has_value());
  return operator=(V8ImagePixelFormat(static_cast<Enum>(index.value())));
}

}  // namespace blink
