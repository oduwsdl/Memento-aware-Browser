// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/bindings/core/v8/v8_font_face_load_status.h"

namespace blink {

const char* const V8FontFaceLoadStatus::string_table_[];

static_assert(std::is_trivially_copyable<V8FontFaceLoadStatus>::value, "");

V8FontFaceLoadStatus& V8FontFaceLoadStatus::operator=(const String& str_value) {
  const auto& index =
      bindings::FindIndexInEnumStringTable(str_value, string_table_);
  CHECK(index.has_value());
  return operator=(V8FontFaceLoadStatus(static_cast<Enum>(index.value())));
}

}  // namespace blink
