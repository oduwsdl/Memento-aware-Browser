// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_PEER_CONNECTION_ICE_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_PEER_CONNECTION_ICE_EVENT_INIT_H_

#include "third_party/blink/renderer/core/dom/events/event_init.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class RTCIceCandidate;

class MODULES_EXPORT RTCPeerConnectionIceEventInit : public EventInit {
 public:
  static RTCPeerConnectionIceEventInit* Create() { return MakeGarbageCollected<RTCPeerConnectionIceEventInit>(); }
  static RTCPeerConnectionIceEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<RTCPeerConnectionIceEventInit>();
  }

  RTCPeerConnectionIceEventInit();
  virtual ~RTCPeerConnectionIceEventInit();

  bool hasCandidate() const { return has_candidate_; }
  RTCIceCandidate* candidate() const {
    return candidate_;
  }
  inline void setCandidate(RTCIceCandidate*);
  inline void setCandidateToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasCandidateNonNull() const { return has_candidate_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasCandidateNonNull| in advance to check the condition.
  RTCIceCandidate* candidateNonNull() const {
    DCHECK(hasCandidateNonNull());
    return candidate_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_candidate_ = false;

  Member<RTCIceCandidate> candidate_;

  friend class V8RTCPeerConnectionIceEventInit;
};

void RTCPeerConnectionIceEventInit::setCandidate(RTCIceCandidate* value) {
  candidate_ = value;
  has_candidate_ = true;
}

void RTCPeerConnectionIceEventInit::setCandidateToNull() {
  candidate_ = Member<RTCIceCandidate>();
  has_candidate_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_PEER_CONNECTION_ICE_EVENT_INIT_H_
