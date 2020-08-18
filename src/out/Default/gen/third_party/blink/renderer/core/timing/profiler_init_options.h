// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_INIT_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_INIT_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class CORE_EXPORT ProfilerInitOptions : public IDLDictionaryBase {
 public:
  static ProfilerInitOptions* Create() { return MakeGarbageCollected<ProfilerInitOptions>(); }
  static ProfilerInitOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ProfilerInitOptions>();
  }

  ProfilerInitOptions();
  virtual ~ProfilerInitOptions();

  bool hasMaxBufferSize() const { return has_max_buffer_size_; }
  uint32_t maxBufferSize() const {
    DCHECK(has_max_buffer_size_);
    return max_buffer_size_;
  }
  inline void setMaxBufferSize(uint32_t);

  bool hasSampleInterval() const { return has_sample_interval_; }
  double sampleInterval() const {
    DCHECK(has_sample_interval_);
    return sample_interval_;
  }
  inline void setSampleInterval(double);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_max_buffer_size_ = false;
  bool has_sample_interval_ = false;

  uint32_t max_buffer_size_;
  double sample_interval_;

  friend class V8ProfilerInitOptions;
};

void ProfilerInitOptions::setMaxBufferSize(uint32_t value) {
  max_buffer_size_ = value;
  has_max_buffer_size_ = true;
}

void ProfilerInitOptions::setSampleInterval(double value) {
  sample_interval_ = value;
  has_sample_interval_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_INIT_OPTIONS_H_
