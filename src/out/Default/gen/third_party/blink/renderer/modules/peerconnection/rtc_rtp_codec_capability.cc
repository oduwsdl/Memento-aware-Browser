// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/peerconnection/rtc_rtp_codec_capability.h"

namespace blink {

RTCRtpCodecCapability::RTCRtpCodecCapability() {
}

RTCRtpCodecCapability::~RTCRtpCodecCapability() = default;

void RTCRtpCodecCapability::setScalabilityModes(const Vector<String>& value) {
  scalability_modes_ = value;
  has_scalability_modes_ = true;
}

void RTCRtpCodecCapability::Trace(Visitor* visitor) const {
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
