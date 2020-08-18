// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_SAMPLE_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_SAMPLE_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class CORE_EXPORT ProfilerSample : public IDLDictionaryBase {
 public:
  static ProfilerSample* Create() { return MakeGarbageCollected<ProfilerSample>(); }
  static ProfilerSample* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ProfilerSample>();
  }

  ProfilerSample();
  virtual ~ProfilerSample();

  bool hasStackId() const { return has_stack_id_; }
  uint64_t stackId() const {
    DCHECK(has_stack_id_);
    return stack_id_;
  }
  inline void setStackId(uint64_t);

  bool hasTimestamp() const { return has_timestamp_; }
  double timestamp() const {
    DCHECK(has_timestamp_);
    return timestamp_;
  }
  inline void setTimestamp(double);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_stack_id_ = false;
  bool has_timestamp_ = false;

  uint64_t stack_id_;
  double timestamp_;

  friend class V8ProfilerSample;
};

void ProfilerSample::setStackId(uint64_t value) {
  stack_id_ = value;
  has_stack_id_ = true;
}

void ProfilerSample::setTimestamp(double value) {
  timestamp_ = value;
  has_timestamp_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_SAMPLE_H_
