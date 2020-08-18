// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/timing/measure_memory/measure_memory.h"

#include "third_party/blink/renderer/core/timing/measure_memory/measure_memory_breakdown.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

MeasureMemory::MeasureMemory() {
}

MeasureMemory::~MeasureMemory() = default;

void MeasureMemory::setBreakdown(const HeapVector<Member<MeasureMemoryBreakdown>>& value) {
  breakdown_ = value;
  has_breakdown_ = true;
}

void MeasureMemory::Trace(Visitor* visitor) const {
  visitor->Trace(breakdown_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
