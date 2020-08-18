// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/contacts_picker/contact_info.h"

#include "third_party/blink/renderer/core/fileapi/blob.h"
#include "third_party/blink/renderer/modules/contacts_picker/contact_address.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

ContactInfo::ContactInfo() {
}

ContactInfo::~ContactInfo() = default;

void ContactInfo::setAddress(const HeapVector<Member<ContactAddress>>& value) {
  address_ = value;
  has_address_ = true;
}

void ContactInfo::setEmail(const Vector<String>& value) {
  email_ = value;
  has_email_ = true;
}

void ContactInfo::setIcon(const HeapVector<Member<Blob>>& value) {
  icon_ = value;
  has_icon_ = true;
}

void ContactInfo::setName(const Vector<String>& value) {
  name_ = value;
  has_name_ = true;
}

void ContactInfo::setTel(const Vector<String>& value) {
  tel_ = value;
  has_tel_ = true;
}

void ContactInfo::Trace(Visitor* visitor) const {
  visitor->Trace(address_);
  visitor->Trace(icon_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
