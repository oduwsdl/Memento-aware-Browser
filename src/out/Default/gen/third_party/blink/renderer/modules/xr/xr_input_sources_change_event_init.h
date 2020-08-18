// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_INPUT_SOURCES_CHANGE_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_INPUT_SOURCES_CHANGE_EVENT_INIT_H_

#include "third_party/blink/renderer/core/dom/events/event_init.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class XRInputSource;
class XRSession;

class MODULES_EXPORT XRInputSourcesChangeEventInit : public EventInit {
 public:
  static XRInputSourcesChangeEventInit* Create() { return MakeGarbageCollected<XRInputSourcesChangeEventInit>(); }
  static XRInputSourcesChangeEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<XRInputSourcesChangeEventInit>();
  }

  XRInputSourcesChangeEventInit();
  virtual ~XRInputSourcesChangeEventInit();

  bool hasAdded() const { return has_added_; }
  const HeapVector<Member<XRInputSource>>& added() const {
    DCHECK(has_added_);
    return added_;
  }
  void setAdded(const HeapVector<Member<XRInputSource>>&);

  bool hasRemoved() const { return has_removed_; }
  const HeapVector<Member<XRInputSource>>& removed() const {
    DCHECK(has_removed_);
    return removed_;
  }
  void setRemoved(const HeapVector<Member<XRInputSource>>&);

  bool hasSession() const { return !!session_; }
  XRSession* session() const {
    return session_;
  }
  inline void setSession(XRSession*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_added_ = false;
  bool has_removed_ = false;

  HeapVector<Member<XRInputSource>> added_;
  HeapVector<Member<XRInputSource>> removed_;
  Member<XRSession> session_;

  friend class V8XRInputSourcesChangeEventInit;
};

void XRInputSourcesChangeEventInit::setSession(XRSession* value) {
  session_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_INPUT_SOURCES_CHANGE_EVENT_INIT_H_
