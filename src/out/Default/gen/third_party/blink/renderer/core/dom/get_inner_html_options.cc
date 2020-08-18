// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/dom/get_inner_html_options.h"

#include "third_party/blink/renderer/core/dom/shadow_root.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

GetInnerHTMLOptions::GetInnerHTMLOptions() {
  setIncludeShadowRoots(true);
}

GetInnerHTMLOptions::~GetInnerHTMLOptions() = default;

void GetInnerHTMLOptions::setClosedRoots(const HeapVector<Member<ShadowRoot>>& value) {
  closed_roots_ = value;
  has_closed_roots_ = true;
}

void GetInnerHTMLOptions::Trace(Visitor* visitor) const {
  visitor->Trace(closed_roots_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
