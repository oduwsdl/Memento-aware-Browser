// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_MEDIASESSION_MEDIA_POSITION_STATE_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_MEDIASESSION_MEDIA_POSITION_STATE_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT MediaPositionState : public IDLDictionaryBase {
 public:
  static MediaPositionState* Create() { return MakeGarbageCollected<MediaPositionState>(); }
  static MediaPositionState* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<MediaPositionState>();
  }

  MediaPositionState();
  virtual ~MediaPositionState();

  bool hasDuration() const { return has_duration_; }
  double duration() const {
    DCHECK(has_duration_);
    return duration_;
  }
  inline void setDuration(double);

  bool hasPlaybackRate() const { return has_playback_rate_; }
  double playbackRate() const {
    DCHECK(has_playback_rate_);
    return playback_rate_;
  }
  inline void setPlaybackRate(double);

  bool hasPosition() const { return has_position_; }
  double position() const {
    DCHECK(has_position_);
    return position_;
  }
  inline void setPosition(double);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_duration_ = false;
  bool has_playback_rate_ = false;
  bool has_position_ = false;

  double duration_;
  double playback_rate_;
  double position_;

  friend class V8MediaPositionState;
};

void MediaPositionState::setDuration(double value) {
  duration_ = value;
  has_duration_ = true;
}

void MediaPositionState::setPlaybackRate(double value) {
  playback_rate_ = value;
  has_playback_rate_ = true;
}

void MediaPositionState::setPosition(double value) {
  position_ = value;
  has_position_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_MEDIASESSION_MEDIA_POSITION_STATE_H_
