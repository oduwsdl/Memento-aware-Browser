// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_MEDIA_CAPABILITIES_VIDEO_CONFIGURATION_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_MEDIA_CAPABILITIES_VIDEO_CONFIGURATION_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT VideoConfiguration : public IDLDictionaryBase {
 public:
  static VideoConfiguration* Create() { return MakeGarbageCollected<VideoConfiguration>(); }
  static VideoConfiguration* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<VideoConfiguration>();
  }

  VideoConfiguration();
  virtual ~VideoConfiguration();

  bool hasBitrate() const { return has_bitrate_; }
  uint32_t bitrate() const {
    DCHECK(has_bitrate_);
    return bitrate_;
  }
  inline void setBitrate(uint32_t);

  bool hasColorGamut() const { return !color_gamut_.IsNull(); }
  const String& colorGamut() const {
    return color_gamut_;
  }
  inline void setColorGamut(const String&);

  bool hasContentType() const { return !content_type_.IsNull(); }
  const String& contentType() const {
    return content_type_;
  }
  inline void setContentType(const String&);

  bool hasFramerate() const { return has_framerate_; }
  double framerate() const {
    DCHECK(has_framerate_);
    return framerate_;
  }
  inline void setFramerate(double);

  bool hasHdrMetadataType() const { return !hdr_metadata_type_.IsNull(); }
  const String& hdrMetadataType() const {
    return hdr_metadata_type_;
  }
  inline void setHdrMetadataType(const String&);

  bool hasHeight() const { return has_height_; }
  uint32_t height() const {
    DCHECK(has_height_);
    return height_;
  }
  inline void setHeight(uint32_t);

  bool hasTransferFunction() const { return !transfer_function_.IsNull(); }
  const String& transferFunction() const {
    return transfer_function_;
  }
  inline void setTransferFunction(const String&);

  bool hasWidth() const { return has_width_; }
  uint32_t width() const {
    DCHECK(has_width_);
    return width_;
  }
  inline void setWidth(uint32_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_bitrate_ = false;
  bool has_framerate_ = false;
  bool has_height_ = false;
  bool has_width_ = false;

  uint32_t bitrate_;
  String color_gamut_;
  String content_type_;
  double framerate_;
  String hdr_metadata_type_;
  uint32_t height_;
  String transfer_function_;
  uint32_t width_;

  friend class V8VideoConfiguration;
};

void VideoConfiguration::setBitrate(uint32_t value) {
  bitrate_ = value;
  has_bitrate_ = true;
}

void VideoConfiguration::setColorGamut(const String& value) {
  color_gamut_ = value;
}

void VideoConfiguration::setContentType(const String& value) {
  content_type_ = value;
}

void VideoConfiguration::setFramerate(double value) {
  framerate_ = value;
  has_framerate_ = true;
}

void VideoConfiguration::setHdrMetadataType(const String& value) {
  hdr_metadata_type_ = value;
}

void VideoConfiguration::setHeight(uint32_t value) {
  height_ = value;
  has_height_ = true;
}

void VideoConfiguration::setTransferFunction(const String& value) {
  transfer_function_ = value;
}

void VideoConfiguration::setWidth(uint32_t value) {
  width_ = value;
  has_width_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_MEDIA_CAPABILITIES_VIDEO_CONFIGURATION_H_
