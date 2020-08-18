// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_SCHEDULER_SCHEDULER_POST_TASK_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_SCHEDULER_SCHEDULER_POST_TASK_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class AbortSignal;

class MODULES_EXPORT SchedulerPostTaskOptions : public IDLDictionaryBase {
 public:
  static SchedulerPostTaskOptions* Create() { return MakeGarbageCollected<SchedulerPostTaskOptions>(); }
  static SchedulerPostTaskOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<SchedulerPostTaskOptions>();
  }

  SchedulerPostTaskOptions();
  virtual ~SchedulerPostTaskOptions();

  bool hasDelay() const { return has_delay_; }
  int32_t delay() const {
    DCHECK(has_delay_);
    return delay_;
  }
  inline void setDelay(int32_t);

  bool hasPriority() const { return !priority_.IsNull(); }
  const String& priority() const {
    return priority_;
  }
  inline void setPriority(const String&);
  inline void setPriorityToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasPriorityNonNull() const { return !priority_.IsNull(); }
  // Returns the value if this member has a non-null value.  Call
  // |hasPriorityNonNull| in advance to check the condition.
  const String& priorityNonNull() const {
    DCHECK(hasPriorityNonNull());
    return priority_;
  }

  bool hasSignal() const { return has_signal_; }
  AbortSignal* signal() const {
    return signal_;
  }
  inline void setSignal(AbortSignal*);
  inline void setSignalToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasSignalNonNull() const { return has_signal_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasSignalNonNull| in advance to check the condition.
  AbortSignal* signalNonNull() const {
    DCHECK(hasSignalNonNull());
    return signal_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_delay_ = false;
  bool has_signal_ = false;

  int32_t delay_;
  String priority_;
  Member<AbortSignal> signal_;

  friend class V8SchedulerPostTaskOptions;
};

void SchedulerPostTaskOptions::setDelay(int32_t value) {
  delay_ = value;
  has_delay_ = true;
}

void SchedulerPostTaskOptions::setPriority(const String& value) {
  priority_ = value;
}

void SchedulerPostTaskOptions::setPriorityToNull() {
  priority_ = String();
}

void SchedulerPostTaskOptions::setSignal(AbortSignal* value) {
  signal_ = value;
  has_signal_ = true;
}

void SchedulerPostTaskOptions::setSignalToNull() {
  signal_ = Member<AbortSignal>();
  has_signal_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_SCHEDULER_SCHEDULER_POST_TASK_OPTIONS_H_
