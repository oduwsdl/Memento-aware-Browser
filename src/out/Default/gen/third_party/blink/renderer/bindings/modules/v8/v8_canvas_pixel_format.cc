// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/bindings/modules/v8/v8_canvas_pixel_format.h"

namespace blink {

const char* const V8CanvasPixelFormat::string_table_[];

static_assert(std::is_trivially_copyable<V8CanvasPixelFormat>::value, "");

V8CanvasPixelFormat& V8CanvasPixelFormat::operator=(const String& str_value) {
  const auto& index =
      bindings::FindIndexInEnumStringTable(str_value, string_table_);
  CHECK(index.has_value());
  return operator=(V8CanvasPixelFormat(static_cast<Enum>(index.value())));
}

}  // namespace blink
