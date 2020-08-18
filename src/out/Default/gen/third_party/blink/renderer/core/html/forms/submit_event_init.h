// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_HTML_FORMS_SUBMIT_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_HTML_FORMS_SUBMIT_EVENT_INIT_H_

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/dom/events/event_init.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class HTMLElement;

class CORE_EXPORT SubmitEventInit : public EventInit {
 public:
  static SubmitEventInit* Create() { return MakeGarbageCollected<SubmitEventInit>(); }
  static SubmitEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<SubmitEventInit>();
  }

  SubmitEventInit();
  virtual ~SubmitEventInit();

  bool hasSubmitter() const { return has_submitter_; }
  HTMLElement* submitter() const {
    return submitter_;
  }
  inline void setSubmitter(HTMLElement*);
  inline void setSubmitterToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasSubmitterNonNull() const { return has_submitter_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasSubmitterNonNull| in advance to check the condition.
  HTMLElement* submitterNonNull() const {
    DCHECK(hasSubmitterNonNull());
    return submitter_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_submitter_ = false;

  Member<HTMLElement> submitter_;

  friend class V8SubmitEventInit;
};

void SubmitEventInit::setSubmitter(HTMLElement* value) {
  submitter_ = value;
  has_submitter_ = true;
}

void SubmitEventInit::setSubmitterToNull() {
  submitter_ = Member<HTMLElement>();
  has_submitter_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_HTML_FORMS_SUBMIT_EVENT_INIT_H_
