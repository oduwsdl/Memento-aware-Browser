// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PUSH_MESSAGING_PUSH_SUBSCRIPTION_CHANGE_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PUSH_MESSAGING_PUSH_SUBSCRIPTION_CHANGE_EVENT_INIT_H_

#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/service_worker/extendable_event_init.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class PushSubscription;

class MODULES_EXPORT PushSubscriptionChangeEventInit : public ExtendableEventInit {
 public:
  static PushSubscriptionChangeEventInit* Create() { return MakeGarbageCollected<PushSubscriptionChangeEventInit>(); }
  static PushSubscriptionChangeEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<PushSubscriptionChangeEventInit>();
  }

  PushSubscriptionChangeEventInit();
  virtual ~PushSubscriptionChangeEventInit();

  bool hasNewSubscription() const { return !!new_subscription_; }
  PushSubscription* newSubscription() const {
    return new_subscription_;
  }
  inline void setNewSubscription(PushSubscription*);

  bool hasOldSubscription() const { return !!old_subscription_; }
  PushSubscription* oldSubscription() const {
    return old_subscription_;
  }
  inline void setOldSubscription(PushSubscription*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  Member<PushSubscription> new_subscription_;
  Member<PushSubscription> old_subscription_;

  friend class V8PushSubscriptionChangeEventInit;
};

void PushSubscriptionChangeEventInit::setNewSubscription(PushSubscription* value) {
  new_subscription_ = value;
}

void PushSubscriptionChangeEventInit::setOldSubscription(PushSubscription* value) {
  old_subscription_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PUSH_MESSAGING_PUSH_SUBSCRIPTION_CHANGE_EVENT_INIT_H_
