// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_ENCODED_AUDIO_FRAME_METADATA_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_ENCODED_AUDIO_FRAME_METADATA_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class MODULES_EXPORT RTCEncodedAudioFrameMetadata : public IDLDictionaryBase {
 public:
  static RTCEncodedAudioFrameMetadata* Create() { return MakeGarbageCollected<RTCEncodedAudioFrameMetadata>(); }
  static RTCEncodedAudioFrameMetadata* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<RTCEncodedAudioFrameMetadata>();
  }

  RTCEncodedAudioFrameMetadata();
  virtual ~RTCEncodedAudioFrameMetadata();

  bool hasContributingSources() const { return has_contributing_sources_; }
  const Vector<uint32_t>& contributingSources() const {
    DCHECK(has_contributing_sources_);
    return contributing_sources_;
  }
  void setContributingSources(const Vector<uint32_t>&);

  bool hasSynchronizationSource() const { return has_synchronization_source_; }
  uint32_t synchronizationSource() const {
    DCHECK(has_synchronization_source_);
    return synchronization_source_;
  }
  inline void setSynchronizationSource(uint32_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_contributing_sources_ = false;
  bool has_synchronization_source_ = false;

  Vector<uint32_t> contributing_sources_;
  uint32_t synchronization_source_;

  friend class V8RTCEncodedAudioFrameMetadata;
};

void RTCEncodedAudioFrameMetadata::setSynchronizationSource(uint32_t value) {
  synchronization_source_ = value;
  has_synchronization_source_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_ENCODED_AUDIO_FRAME_METADATA_H_
