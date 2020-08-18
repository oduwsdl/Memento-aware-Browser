// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_power_preference.h"

namespace blink {

const char* const V8GPUPowerPreference::string_table_[];

static_assert(std::is_trivially_copyable<V8GPUPowerPreference>::value, "");

V8GPUPowerPreference& V8GPUPowerPreference::operator=(const String& str_value) {
  const auto& index =
      bindings::FindIndexInEnumStringTable(str_value, string_table_);
  CHECK(index.has_value());
  return operator=(V8GPUPowerPreference(static_cast<Enum>(index.value())));
}

}  // namespace blink
