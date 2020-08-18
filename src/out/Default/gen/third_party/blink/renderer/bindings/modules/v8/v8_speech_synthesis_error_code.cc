// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/bindings/modules/v8/v8_speech_synthesis_error_code.h"

namespace blink {

const char* const V8SpeechSynthesisErrorCode::string_table_[];

static_assert(std::is_trivially_copyable<V8SpeechSynthesisErrorCode>::value,
              "");

V8SpeechSynthesisErrorCode& V8SpeechSynthesisErrorCode::operator=(
    const String& str_value) {
  const auto& index =
      bindings::FindIndexInEnumStringTable(str_value, string_table_);
  CHECK(index.has_value());
  return operator=(
      V8SpeechSynthesisErrorCode(static_cast<Enum>(index.value())));
}

}  // namespace blink
