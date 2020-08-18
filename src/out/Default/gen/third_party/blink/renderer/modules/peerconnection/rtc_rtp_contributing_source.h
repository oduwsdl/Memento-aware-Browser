// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_RTP_CONTRIBUTING_SOURCE_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_RTP_CONTRIBUTING_SOURCE_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT RTCRtpContributingSource : public IDLDictionaryBase {
 public:
  static RTCRtpContributingSource* Create() { return MakeGarbageCollected<RTCRtpContributingSource>(); }
  static RTCRtpContributingSource* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<RTCRtpContributingSource>();
  }

  RTCRtpContributingSource();
  virtual ~RTCRtpContributingSource();

  bool hasAudioLevel() const { return has_audio_level_; }
  double audioLevel() const {
    DCHECK(has_audio_level_);
    return audio_level_;
  }
  inline void setAudioLevel(double);

  bool hasCaptureTimestamp() const { return has_capture_timestamp_; }
  double captureTimestamp() const {
    DCHECK(has_capture_timestamp_);
    return capture_timestamp_;
  }
  inline void setCaptureTimestamp(double);

  bool hasRtpTimestamp() const { return has_rtp_timestamp_; }
  uint32_t rtpTimestamp() const {
    DCHECK(has_rtp_timestamp_);
    return rtp_timestamp_;
  }
  inline void setRtpTimestamp(uint32_t);

  bool hasSource() const { return has_source_; }
  uint32_t source() const {
    DCHECK(has_source_);
    return source_;
  }
  inline void setSource(uint32_t);

  bool hasTimestamp() const { return has_timestamp_; }
  double timestamp() const {
    DCHECK(has_timestamp_);
    return timestamp_;
  }
  inline void setTimestamp(double);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_audio_level_ = false;
  bool has_capture_timestamp_ = false;
  bool has_rtp_timestamp_ = false;
  bool has_source_ = false;
  bool has_timestamp_ = false;

  double audio_level_;
  double capture_timestamp_;
  uint32_t rtp_timestamp_;
  uint32_t source_;
  double timestamp_;

  friend class V8RTCRtpContributingSource;
};

void RTCRtpContributingSource::setAudioLevel(double value) {
  audio_level_ = value;
  has_audio_level_ = true;
}

void RTCRtpContributingSource::setCaptureTimestamp(double value) {
  capture_timestamp_ = value;
  has_capture_timestamp_ = true;
}

void RTCRtpContributingSource::setRtpTimestamp(uint32_t value) {
  rtp_timestamp_ = value;
  has_rtp_timestamp_ = true;
}

void RTCRtpContributingSource::setSource(uint32_t value) {
  source_ = value;
  has_source_ = true;
}

void RTCRtpContributingSource::setTimestamp(double value) {
  timestamp_ = value;
  has_timestamp_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_RTP_CONTRIBUTING_SOURCE_H_
