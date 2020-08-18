// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/nfc/ndef_message_init.h"

#include "third_party/blink/renderer/modules/nfc/ndef_record_init.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

NDEFMessageInit::NDEFMessageInit() {
}

NDEFMessageInit::~NDEFMessageInit() = default;

void NDEFMessageInit::setRecords(const HeapVector<Member<NDEFRecordInit>>& value) {
  records_ = value;
  has_records_ = true;
}

void NDEFMessageInit::Trace(Visitor* visitor) const {
  visitor->Trace(records_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
