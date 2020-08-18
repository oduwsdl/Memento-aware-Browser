// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/streams/queuing_strategy_init.h"

namespace blink {

QueuingStrategyInit::QueuingStrategyInit() {
}

QueuingStrategyInit::~QueuingStrategyInit() = default;

void QueuingStrategyInit::setHighWaterMark(ScriptValue value) {
  high_water_mark_ = value;
}

void QueuingStrategyInit::Trace(Visitor* visitor) const {
  visitor->Trace(high_water_mark_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
