// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_RTP_CODEC_CAPABILITY_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_RTP_CODEC_CAPABILITY_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class MODULES_EXPORT RTCRtpCodecCapability : public IDLDictionaryBase {
 public:
  static RTCRtpCodecCapability* Create() { return MakeGarbageCollected<RTCRtpCodecCapability>(); }
  static RTCRtpCodecCapability* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<RTCRtpCodecCapability>();
  }

  RTCRtpCodecCapability();
  virtual ~RTCRtpCodecCapability();

  bool hasChannels() const { return has_channels_; }
  uint16_t channels() const {
    DCHECK(has_channels_);
    return channels_;
  }
  inline void setChannels(uint16_t);

  bool hasClockRate() const { return has_clock_rate_; }
  uint32_t clockRate() const {
    DCHECK(has_clock_rate_);
    return clock_rate_;
  }
  inline void setClockRate(uint32_t);

  bool hasMimeType() const { return !mime_type_.IsNull(); }
  const String& mimeType() const {
    return mime_type_;
  }
  inline void setMimeType(const String&);

  bool hasScalabilityModes() const { return has_scalability_modes_; }
  const Vector<String>& scalabilityModes() const {
    DCHECK(has_scalability_modes_);
    return scalability_modes_;
  }
  void setScalabilityModes(const Vector<String>&);

  bool hasSdpFmtpLine() const { return !sdp_fmtp_line_.IsNull(); }
  const String& sdpFmtpLine() const {
    return sdp_fmtp_line_;
  }
  inline void setSdpFmtpLine(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_channels_ = false;
  bool has_clock_rate_ = false;
  bool has_scalability_modes_ = false;

  uint16_t channels_;
  uint32_t clock_rate_;
  String mime_type_;
  Vector<String> scalability_modes_;
  String sdp_fmtp_line_;

  friend class V8RTCRtpCodecCapability;
};

void RTCRtpCodecCapability::setChannels(uint16_t value) {
  channels_ = value;
  has_channels_ = true;
}

void RTCRtpCodecCapability::setClockRate(uint32_t value) {
  clock_rate_ = value;
  has_clock_rate_ = true;
}

void RTCRtpCodecCapability::setMimeType(const String& value) {
  mime_type_ = value;
}

void RTCRtpCodecCapability::setSdpFmtpLine(const String& value) {
  sdp_fmtp_line_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_RTP_CODEC_CAPABILITY_H_
