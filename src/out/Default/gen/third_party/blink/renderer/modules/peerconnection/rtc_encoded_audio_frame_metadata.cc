// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/peerconnection/rtc_encoded_audio_frame_metadata.h"

namespace blink {

RTCEncodedAudioFrameMetadata::RTCEncodedAudioFrameMetadata() {
}

RTCEncodedAudioFrameMetadata::~RTCEncodedAudioFrameMetadata() = default;

void RTCEncodedAudioFrameMetadata::setContributingSources(const Vector<uint32_t>& value) {
  contributing_sources_ = value;
  has_contributing_sources_ = true;
}

void RTCEncodedAudioFrameMetadata::Trace(Visitor* visitor) const {
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
