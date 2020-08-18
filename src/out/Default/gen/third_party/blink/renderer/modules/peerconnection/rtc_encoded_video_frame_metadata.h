// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_ENCODED_VIDEO_FRAME_METADATA_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_ENCODED_VIDEO_FRAME_METADATA_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class MODULES_EXPORT RTCEncodedVideoFrameMetadata : public IDLDictionaryBase {
 public:
  static RTCEncodedVideoFrameMetadata* Create() { return MakeGarbageCollected<RTCEncodedVideoFrameMetadata>(); }
  static RTCEncodedVideoFrameMetadata* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<RTCEncodedVideoFrameMetadata>();
  }

  RTCEncodedVideoFrameMetadata();
  virtual ~RTCEncodedVideoFrameMetadata();

  bool hasContributingSources() const { return has_contributing_sources_; }
  const Vector<uint32_t>& contributingSources() const {
    DCHECK(has_contributing_sources_);
    return contributing_sources_;
  }
  void setContributingSources(const Vector<uint32_t>&);

  bool hasDependencies() const { return has_dependencies_; }
  const Vector<int64_t>& dependencies() const {
    DCHECK(has_dependencies_);
    return dependencies_;
  }
  void setDependencies(const Vector<int64_t>&);

  bool hasFrameId() const { return has_frame_id_; }
  int64_t frameId() const {
    DCHECK(has_frame_id_);
    return frame_id_;
  }
  inline void setFrameId(int64_t);

  bool hasHeight() const { return has_height_; }
  uint16_t height() const {
    DCHECK(has_height_);
    return height_;
  }
  inline void setHeight(uint16_t);

  bool hasSpatialIndex() const { return has_spatial_index_; }
  int32_t spatialIndex() const {
    DCHECK(has_spatial_index_);
    return spatial_index_;
  }
  inline void setSpatialIndex(int32_t);

  bool hasSynchronizationSource() const { return has_synchronization_source_; }
  uint32_t synchronizationSource() const {
    DCHECK(has_synchronization_source_);
    return synchronization_source_;
  }
  inline void setSynchronizationSource(uint32_t);

  bool hasTemporalIndex() const { return has_temporal_index_; }
  int32_t temporalIndex() const {
    DCHECK(has_temporal_index_);
    return temporal_index_;
  }
  inline void setTemporalIndex(int32_t);

  bool hasWidth() const { return has_width_; }
  uint16_t width() const {
    DCHECK(has_width_);
    return width_;
  }
  inline void setWidth(uint16_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_contributing_sources_ = false;
  bool has_dependencies_ = false;
  bool has_frame_id_ = false;
  bool has_height_ = false;
  bool has_spatial_index_ = false;
  bool has_synchronization_source_ = false;
  bool has_temporal_index_ = false;
  bool has_width_ = false;

  Vector<uint32_t> contributing_sources_;
  Vector<int64_t> dependencies_;
  int64_t frame_id_;
  uint16_t height_;
  int32_t spatial_index_;
  uint32_t synchronization_source_;
  int32_t temporal_index_;
  uint16_t width_;

  friend class V8RTCEncodedVideoFrameMetadata;
};

void RTCEncodedVideoFrameMetadata::setFrameId(int64_t value) {
  frame_id_ = value;
  has_frame_id_ = true;
}

void RTCEncodedVideoFrameMetadata::setHeight(uint16_t value) {
  height_ = value;
  has_height_ = true;
}

void RTCEncodedVideoFrameMetadata::setSpatialIndex(int32_t value) {
  spatial_index_ = value;
  has_spatial_index_ = true;
}

void RTCEncodedVideoFrameMetadata::setSynchronizationSource(uint32_t value) {
  synchronization_source_ = value;
  has_synchronization_source_ = true;
}

void RTCEncodedVideoFrameMetadata::setTemporalIndex(int32_t value) {
  temporal_index_ = value;
  has_temporal_index_ = true;
}

void RTCEncodedVideoFrameMetadata::setWidth(uint16_t value) {
  width_ = value;
  has_width_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_ENCODED_VIDEO_FRAME_METADATA_H_
