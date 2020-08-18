// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_TRACE_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_TRACE_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class ProfilerStack;
class ProfilerSample;
class ProfilerFrame;

class CORE_EXPORT ProfilerTrace : public IDLDictionaryBase {
 public:
  static ProfilerTrace* Create() { return MakeGarbageCollected<ProfilerTrace>(); }
  static ProfilerTrace* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ProfilerTrace>();
  }

  ProfilerTrace();
  virtual ~ProfilerTrace();

  bool hasFrames() const { return has_frames_; }
  const HeapVector<Member<ProfilerFrame>>& frames() const {
    DCHECK(has_frames_);
    return frames_;
  }
  void setFrames(const HeapVector<Member<ProfilerFrame>>&);

  bool hasResources() const { return has_resources_; }
  const Vector<String>& resources() const {
    DCHECK(has_resources_);
    return resources_;
  }
  void setResources(const Vector<String>&);

  bool hasSamples() const { return has_samples_; }
  const HeapVector<Member<ProfilerSample>>& samples() const {
    DCHECK(has_samples_);
    return samples_;
  }
  void setSamples(const HeapVector<Member<ProfilerSample>>&);

  bool hasStacks() const { return has_stacks_; }
  const HeapVector<Member<ProfilerStack>>& stacks() const {
    DCHECK(has_stacks_);
    return stacks_;
  }
  void setStacks(const HeapVector<Member<ProfilerStack>>&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_frames_ = false;
  bool has_resources_ = false;
  bool has_samples_ = false;
  bool has_stacks_ = false;

  HeapVector<Member<ProfilerFrame>> frames_;
  Vector<String> resources_;
  HeapVector<Member<ProfilerSample>> samples_;
  HeapVector<Member<ProfilerStack>> stacks_;

  friend class V8ProfilerTrace;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_TRACE_H_
