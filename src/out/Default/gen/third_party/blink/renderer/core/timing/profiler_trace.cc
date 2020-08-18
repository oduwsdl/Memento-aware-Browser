// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/timing/profiler_trace.h"

#include "third_party/blink/renderer/core/timing/profiler_frame.h"
#include "third_party/blink/renderer/core/timing/profiler_sample.h"
#include "third_party/blink/renderer/core/timing/profiler_stack.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

ProfilerTrace::ProfilerTrace() {
}

ProfilerTrace::~ProfilerTrace() = default;

void ProfilerTrace::setFrames(const HeapVector<Member<ProfilerFrame>>& value) {
  frames_ = value;
  has_frames_ = true;
}

void ProfilerTrace::setResources(const Vector<String>& value) {
  resources_ = value;
  has_resources_ = true;
}

void ProfilerTrace::setSamples(const HeapVector<Member<ProfilerSample>>& value) {
  samples_ = value;
  has_samples_ = true;
}

void ProfilerTrace::setStacks(const HeapVector<Member<ProfilerStack>>& value) {
  stacks_ = value;
  has_stacks_ = true;
}

void ProfilerTrace::Trace(Visitor* visitor) const {
  visitor->Trace(frames_);
  visitor->Trace(samples_);
  visitor->Trace(stacks_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
