// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/timing/performance_measure_options.h"

namespace blink {

PerformanceMeasureOptions::PerformanceMeasureOptions() {
}

PerformanceMeasureOptions::~PerformanceMeasureOptions() = default;

void PerformanceMeasureOptions::setDetail(ScriptValue value) {
  detail_ = value;
}

void PerformanceMeasureOptions::setEnd(const StringOrDouble& value) {
  end_ = value;
}

void PerformanceMeasureOptions::setStart(const StringOrDouble& value) {
  start_ = value;
}

void PerformanceMeasureOptions::Trace(Visitor* visitor) const {
  visitor->Trace(detail_);
  visitor->Trace(end_);
  visitor->Trace(start_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
