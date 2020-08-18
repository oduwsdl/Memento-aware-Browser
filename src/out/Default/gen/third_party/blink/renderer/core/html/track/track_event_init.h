// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_HTML_TRACK_TRACK_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_HTML_TRACK_TRACK_EVENT_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/video_track_or_audio_track_or_text_track.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/dom/events/event_init.h"
#include "third_party/blink/renderer/core/html/track/audio_track.h"
#include "third_party/blink/renderer/core/html/track/text_track.h"
#include "third_party/blink/renderer/core/html/track/video_track.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class CORE_EXPORT TrackEventInit : public EventInit {
 public:
  static TrackEventInit* Create() { return MakeGarbageCollected<TrackEventInit>(); }
  static TrackEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<TrackEventInit>();
  }

  TrackEventInit();
  virtual ~TrackEventInit();

  bool hasTrack() const { return !track_.IsNull(); }
  const VideoTrackOrAudioTrackOrTextTrack& track() const {
    return track_;
  }
  void setTrack(const VideoTrackOrAudioTrackOrTextTrack&);
  void setTrackToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasTrackNonNull() const { return !track_.IsNull(); }
  // Returns the value if this member has a non-null value.  Call
  // |hasTrackNonNull| in advance to check the condition.
  const VideoTrackOrAudioTrackOrTextTrack& trackNonNull() const {
    DCHECK(hasTrackNonNull());
    return track_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  VideoTrackOrAudioTrackOrTextTrack track_;

  friend class V8TrackEventInit;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_HTML_TRACK_TRACK_EVENT_INIT_H_
