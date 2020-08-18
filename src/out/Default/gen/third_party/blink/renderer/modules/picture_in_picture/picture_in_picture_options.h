// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PICTURE_IN_PICTURE_PICTURE_IN_PICTURE_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PICTURE_IN_PICTURE_PICTURE_IN_PICTURE_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT PictureInPictureOptions : public IDLDictionaryBase {
 public:
  static PictureInPictureOptions* Create() { return MakeGarbageCollected<PictureInPictureOptions>(); }
  static PictureInPictureOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<PictureInPictureOptions>();
  }

  PictureInPictureOptions();
  virtual ~PictureInPictureOptions();

  bool hasHeight() const { return has_height_; }
  int32_t height() const {
    DCHECK(has_height_);
    return height_;
  }
  inline void setHeight(int32_t);

  bool hasInteractive() const { return has_interactive_; }
  bool interactive() const {
    DCHECK(has_interactive_);
    return interactive_;
  }
  inline void setInteractive(bool);

  bool hasWidth() const { return has_width_; }
  int32_t width() const {
    DCHECK(has_width_);
    return width_;
  }
  inline void setWidth(int32_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_height_ = false;
  bool has_interactive_ = false;
  bool has_width_ = false;

  int32_t height_;
  bool interactive_;
  int32_t width_;

  friend class V8PictureInPictureOptions;
};

void PictureInPictureOptions::setHeight(int32_t value) {
  height_ = value;
  has_height_ = true;
}

void PictureInPictureOptions::setInteractive(bool value) {
  interactive_ = value;
  has_interactive_ = true;
}

void PictureInPictureOptions::setWidth(int32_t value) {
  width_ = value;
  has_width_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PICTURE_IN_PICTURE_PICTURE_IN_PICTURE_OPTIONS_H_
