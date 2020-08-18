// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/xr/xr_hit_test_options_init.h"

#include "third_party/blink/renderer/modules/xr/xr_ray.h"
#include "third_party/blink/renderer/modules/xr/xr_space.h"

namespace blink {

XRHitTestOptionsInit::XRHitTestOptionsInit() {
}

XRHitTestOptionsInit::~XRHitTestOptionsInit() = default;

void XRHitTestOptionsInit::setEntityTypes(const Vector<String>& value) {
  entity_types_ = value;
  has_entity_types_ = true;
}

void XRHitTestOptionsInit::Trace(Visitor* visitor) const {
  visitor->Trace(offset_ray_);
  visitor->Trace(space_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
