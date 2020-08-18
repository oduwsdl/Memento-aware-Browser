// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_STACK_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_STACK_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class CORE_EXPORT ProfilerStack : public IDLDictionaryBase {
 public:
  static ProfilerStack* Create() { return MakeGarbageCollected<ProfilerStack>(); }
  static ProfilerStack* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ProfilerStack>();
  }

  ProfilerStack();
  virtual ~ProfilerStack();

  bool hasFrameId() const { return has_frame_id_; }
  uint64_t frameId() const {
    DCHECK(has_frame_id_);
    return frame_id_;
  }
  inline void setFrameId(uint64_t);

  bool hasParentId() const { return has_parent_id_; }
  uint64_t parentId() const {
    DCHECK(has_parent_id_);
    return parent_id_;
  }
  inline void setParentId(uint64_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_frame_id_ = false;
  bool has_parent_id_ = false;

  uint64_t frame_id_;
  uint64_t parent_id_;

  friend class V8ProfilerStack;
};

void ProfilerStack::setFrameId(uint64_t value) {
  frame_id_ = value;
  has_frame_id_ = true;
}

void ProfilerStack::setParentId(uint64_t value) {
  parent_id_ = value;
  has_parent_id_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_STACK_H_
