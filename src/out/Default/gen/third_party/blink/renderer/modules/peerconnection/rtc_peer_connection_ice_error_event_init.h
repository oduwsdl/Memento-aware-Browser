// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_PEER_CONNECTION_ICE_ERROR_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_PEER_CONNECTION_ICE_ERROR_EVENT_INIT_H_

#include "third_party/blink/renderer/core/dom/events/event_init.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT RTCPeerConnectionIceErrorEventInit : public EventInit {
 public:
  static RTCPeerConnectionIceErrorEventInit* Create() { return MakeGarbageCollected<RTCPeerConnectionIceErrorEventInit>(); }
  static RTCPeerConnectionIceErrorEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<RTCPeerConnectionIceErrorEventInit>();
  }

  RTCPeerConnectionIceErrorEventInit();
  virtual ~RTCPeerConnectionIceErrorEventInit();

  bool hasAddress() const { return !address_.IsNull(); }
  const String& address() const {
    return address_;
  }
  inline void setAddress(const String&);
  inline void setAddressToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasAddressNonNull() const { return !address_.IsNull(); }
  // Returns the value if this member has a non-null value.  Call
  // |hasAddressNonNull| in advance to check the condition.
  const String& addressNonNull() const {
    DCHECK(hasAddressNonNull());
    return address_;
  }

  bool hasErrorCode() const { return has_error_code_; }
  uint16_t errorCode() const {
    DCHECK(has_error_code_);
    return error_code_;
  }
  inline void setErrorCode(uint16_t);

  bool hasHostCandidate() const { return !host_candidate_.IsNull(); }
  const String& hostCandidate() const {
    return host_candidate_;
  }
  inline void setHostCandidate(const String&);

  bool hasPort() const { return has_port_; }
  uint16_t port() const {
    DCHECK(has_port_);
    return port_;
  }
  inline void setPort(uint16_t);
  inline void setPortToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasPortNonNull() const { return has_port_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasPortNonNull| in advance to check the condition.
  uint16_t portNonNull() const {
    DCHECK(hasPortNonNull());
    return port_;
  }

  bool hasStatusText() const { return !status_text_.IsNull(); }
  const String& statusText() const {
    return status_text_;
  }
  inline void setStatusText(const String&);

  bool hasUrl() const { return !url_.IsNull(); }
  const String& url() const {
    return url_;
  }
  inline void setUrl(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_error_code_ = false;
  bool has_port_ = false;

  String address_;
  uint16_t error_code_;
  String host_candidate_;
  uint16_t port_;
  String status_text_;
  String url_;

  friend class V8RTCPeerConnectionIceErrorEventInit;
};

void RTCPeerConnectionIceErrorEventInit::setAddress(const String& value) {
  address_ = value;
}

void RTCPeerConnectionIceErrorEventInit::setAddressToNull() {
  address_ = String();
}

void RTCPeerConnectionIceErrorEventInit::setErrorCode(uint16_t value) {
  error_code_ = value;
  has_error_code_ = true;
}

void RTCPeerConnectionIceErrorEventInit::setHostCandidate(const String& value) {
  host_candidate_ = value;
}

void RTCPeerConnectionIceErrorEventInit::setPort(uint16_t value) {
  port_ = value;
  has_port_ = true;
}

void RTCPeerConnectionIceErrorEventInit::setPortToNull() {
  has_port_ = false;
}

void RTCPeerConnectionIceErrorEventInit::setStatusText(const String& value) {
  status_text_ = value;
}

void RTCPeerConnectionIceErrorEventInit::setUrl(const String& value) {
  url_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_PEER_CONNECTION_ICE_ERROR_EVENT_INIT_H_
