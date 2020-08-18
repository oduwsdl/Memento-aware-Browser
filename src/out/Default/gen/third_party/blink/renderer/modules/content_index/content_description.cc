// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/content_index/content_description.h"

#include "third_party/blink/renderer/modules/content_index/content_icon_definition.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

ContentDescription::ContentDescription() {
  setCategory(WTF::g_empty_string);
  setIcons(HeapVector<Member<ContentIconDefinition>>());
}

ContentDescription::~ContentDescription() = default;

void ContentDescription::setIcons(const HeapVector<Member<ContentIconDefinition>>& value) {
  icons_ = value;
  has_icons_ = true;
}

void ContentDescription::Trace(Visitor* visitor) const {
  visitor->Trace(icons_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
