// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/push_messaging/push_subscription_change_event_init.h"

#include "third_party/blink/renderer/modules/push_messaging/push_subscription.h"

namespace blink {

PushSubscriptionChangeEventInit::PushSubscriptionChangeEventInit() {
}

PushSubscriptionChangeEventInit::~PushSubscriptionChangeEventInit() = default;

void PushSubscriptionChangeEventInit::Trace(Visitor* visitor) const {
  visitor->Trace(new_subscription_);
  visitor->Trace(old_subscription_);
  ExtendableEventInit::Trace(visitor);
}

}  // namespace blink
