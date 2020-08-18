// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_MESSAGE_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_MESSAGE_EVENT_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/dom/events/event_init.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class EventTarget;
class MessagePort;
class UserActivation;

class CORE_EXPORT MessageEventInit : public EventInit {
 public:
  static MessageEventInit* Create() { return MakeGarbageCollected<MessageEventInit>(); }
  static MessageEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<MessageEventInit>();
  }

  MessageEventInit();
  virtual ~MessageEventInit();

  bool hasData() const { return !(data_.IsEmpty() || data_.IsUndefined()); }
  ScriptValue data() const {
    return data_;
  }
  void setData(ScriptValue);

  bool hasLastEventId() const { return !last_event_id_.IsNull(); }
  const String& lastEventId() const {
    return last_event_id_;
  }
  inline void setLastEventId(const String&);

  bool hasOrigin() const { return !origin_.IsNull(); }
  const String& origin() const {
    return origin_;
  }
  inline void setOrigin(const String&);

  bool hasPorts() const { return has_ports_; }
  const HeapVector<Member<MessagePort>>& ports() const {
    DCHECK(has_ports_);
    return ports_;
  }
  void setPorts(const HeapVector<Member<MessagePort>>&);

  bool hasSource() const { return has_source_; }
  EventTarget* source() const {
    return source_;
  }
  inline void setSource(EventTarget*);
  inline void setSourceToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasSourceNonNull() const { return has_source_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasSourceNonNull| in advance to check the condition.
  EventTarget* sourceNonNull() const {
    DCHECK(hasSourceNonNull());
    return source_;
  }

  bool hasUserActivation() const { return has_user_activation_; }
  UserActivation* userActivation() const {
    return user_activation_;
  }
  inline void setUserActivation(UserActivation*);
  inline void setUserActivationToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasUserActivationNonNull() const { return has_user_activation_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasUserActivationNonNull| in advance to check the condition.
  UserActivation* userActivationNonNull() const {
    DCHECK(hasUserActivationNonNull());
    return user_activation_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_ports_ = false;
  bool has_source_ = false;
  bool has_user_activation_ = false;

  ScriptValue data_;
  String last_event_id_;
  String origin_;
  HeapVector<Member<MessagePort>> ports_;
  Member<EventTarget> source_;
  Member<UserActivation> user_activation_;

  friend class V8MessageEventInit;
};

void MessageEventInit::setLastEventId(const String& value) {
  last_event_id_ = value;
}

void MessageEventInit::setOrigin(const String& value) {
  origin_ = value;
}

void MessageEventInit::setSource(EventTarget* value) {
  source_ = value;
  has_source_ = true;
}

void MessageEventInit::setSourceToNull() {
  source_ = Member<EventTarget>();
  has_source_ = true;
}

void MessageEventInit::setUserActivation(UserActivation* value) {
  user_activation_ = value;
  has_user_activation_ = true;
}

void MessageEventInit::setUserActivationToNull() {
  user_activation_ = Member<UserActivation>();
  has_user_activation_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_MESSAGE_EVENT_INIT_H_
