// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_error_detail_type.h"

namespace blink {

const char* const V8RTCErrorDetailType::string_table_[];

static_assert(std::is_trivially_copyable<V8RTCErrorDetailType>::value, "");

V8RTCErrorDetailType& V8RTCErrorDetailType::operator=(const String& str_value) {
  const auto& index =
      bindings::FindIndexInEnumStringTable(str_value, string_table_);
  CHECK(index.has_value());
  return operator=(V8RTCErrorDetailType(static_cast<Enum>(index.value())));
}

}  // namespace blink
