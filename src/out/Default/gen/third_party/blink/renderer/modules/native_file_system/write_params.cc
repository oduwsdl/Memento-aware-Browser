// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/native_file_system/write_params.h"

namespace blink {

WriteParams::WriteParams() {
}

WriteParams::~WriteParams() = default;

void WriteParams::setData(const ArrayBufferOrArrayBufferViewOrBlobOrUSVString& value) {
  data_ = value;
}

void WriteParams::setDataToNull() {
  data_ = ArrayBufferOrArrayBufferViewOrBlobOrUSVString();
}

void WriteParams::Trace(Visitor* visitor) const {
  visitor->Trace(data_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
