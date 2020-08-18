// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/timing/measure_memory/measure_memory_breakdown.h"

namespace blink {

MeasureMemoryBreakdown::MeasureMemoryBreakdown() {
}

MeasureMemoryBreakdown::~MeasureMemoryBreakdown() = default;

void MeasureMemoryBreakdown::setAttribution(const Vector<String>& value) {
  attribution_ = value;
  has_attribution_ = true;
}

void MeasureMemoryBreakdown::setUserAgentSpecificTypes(const Vector<String>& value) {
  user_agent_specific_types_ = value;
  has_user_agent_specific_types_ = true;
}

void MeasureMemoryBreakdown::Trace(Visitor* visitor) const {
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
