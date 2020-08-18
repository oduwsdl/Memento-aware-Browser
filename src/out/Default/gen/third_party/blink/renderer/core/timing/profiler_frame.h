// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_FRAME_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_FRAME_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class CORE_EXPORT ProfilerFrame : public IDLDictionaryBase {
 public:
  static ProfilerFrame* Create() { return MakeGarbageCollected<ProfilerFrame>(); }
  static ProfilerFrame* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ProfilerFrame>();
  }

  ProfilerFrame();
  virtual ~ProfilerFrame();

  bool hasColumn() const { return has_column_; }
  uint64_t column() const {
    DCHECK(has_column_);
    return column_;
  }
  inline void setColumn(uint64_t);

  bool hasLine() const { return has_line_; }
  uint64_t line() const {
    DCHECK(has_line_);
    return line_;
  }
  inline void setLine(uint64_t);

  bool hasName() const { return !name_.IsNull(); }
  const String& name() const {
    return name_;
  }
  inline void setName(const String&);

  bool hasResourceId() const { return has_resource_id_; }
  uint64_t resourceId() const {
    DCHECK(has_resource_id_);
    return resource_id_;
  }
  inline void setResourceId(uint64_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_column_ = false;
  bool has_line_ = false;
  bool has_resource_id_ = false;

  uint64_t column_;
  uint64_t line_;
  String name_;
  uint64_t resource_id_;

  friend class V8ProfilerFrame;
};

void ProfilerFrame::setColumn(uint64_t value) {
  column_ = value;
  has_column_ = true;
}

void ProfilerFrame::setLine(uint64_t value) {
  line_ = value;
  has_line_ = true;
}

void ProfilerFrame::setName(const String& value) {
  name_ = value;
}

void ProfilerFrame::setResourceId(uint64_t value) {
  resource_id_ = value;
  has_resource_id_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PROFILER_FRAME_H_
