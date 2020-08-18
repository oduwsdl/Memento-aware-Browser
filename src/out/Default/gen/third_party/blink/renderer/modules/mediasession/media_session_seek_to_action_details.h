// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_MEDIASESSION_MEDIA_SESSION_SEEK_TO_ACTION_DETAILS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_MEDIASESSION_MEDIA_SESSION_SEEK_TO_ACTION_DETAILS_H_

#include "third_party/blink/renderer/modules/mediasession/media_session_action_details.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT MediaSessionSeekToActionDetails : public MediaSessionActionDetails {
 public:
  static MediaSessionSeekToActionDetails* Create() { return MakeGarbageCollected<MediaSessionSeekToActionDetails>(); }
  static MediaSessionSeekToActionDetails* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<MediaSessionSeekToActionDetails>();
  }

  MediaSessionSeekToActionDetails();
  virtual ~MediaSessionSeekToActionDetails();

  bool hasFastSeek() const { return has_fast_seek_; }
  bool fastSeek() const {
    DCHECK(has_fast_seek_);
    return fast_seek_;
  }
  inline void setFastSeek(bool);

  bool hasSeekTime() const { return has_seek_time_; }
  double seekTime() const {
    DCHECK(has_seek_time_);
    return seek_time_;
  }
  inline void setSeekTime(double);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_fast_seek_ = false;
  bool has_seek_time_ = false;

  bool fast_seek_;
  double seek_time_;

  friend class V8MediaSessionSeekToActionDetails;
};

void MediaSessionSeekToActionDetails::setFastSeek(bool value) {
  fast_seek_ = value;
  has_fast_seek_ = true;
}

void MediaSessionSeekToActionDetails::setSeekTime(double value) {
  seek_time_ = value;
  has_seek_time_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_MEDIASESSION_MEDIA_SESSION_SEEK_TO_ACTION_DETAILS_H_
