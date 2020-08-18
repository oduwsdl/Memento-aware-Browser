// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/bindings/modules/v8/v8_public_key_credential_type.h"

namespace blink {

const char* const V8PublicKeyCredentialType::string_table_[];

static_assert(std::is_trivially_copyable<V8PublicKeyCredentialType>::value, "");

V8PublicKeyCredentialType& V8PublicKeyCredentialType::operator=(
    const String& str_value) {
  const auto& index =
      bindings::FindIndexInEnumStringTable(str_value, string_table_);
  CHECK(index.has_value());
  return operator=(V8PublicKeyCredentialType(static_cast<Enum>(index.value())));
}

}  // namespace blink
