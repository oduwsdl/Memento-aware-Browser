// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/xr/xr_render_state_init.h"

#include "third_party/blink/renderer/modules/xr/xr_webgl_layer.h"

namespace blink {

XRRenderStateInit::XRRenderStateInit() {
}

XRRenderStateInit::~XRRenderStateInit() = default;

void XRRenderStateInit::Trace(Visitor* visitor) const {
  visitor->Trace(base_layer_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
