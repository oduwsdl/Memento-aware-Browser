// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_RENDER_STATE_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_RENDER_STATE_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class XRWebGLLayer;

class MODULES_EXPORT XRRenderStateInit : public IDLDictionaryBase {
 public:
  static XRRenderStateInit* Create() { return MakeGarbageCollected<XRRenderStateInit>(); }
  static XRRenderStateInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<XRRenderStateInit>();
  }

  XRRenderStateInit();
  virtual ~XRRenderStateInit();

  bool hasBaseLayer() const { return has_base_layer_; }
  XRWebGLLayer* baseLayer() const {
    return base_layer_;
  }
  inline void setBaseLayer(XRWebGLLayer*);
  inline void setBaseLayerToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasBaseLayerNonNull() const { return has_base_layer_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasBaseLayerNonNull| in advance to check the condition.
  XRWebGLLayer* baseLayerNonNull() const {
    DCHECK(hasBaseLayerNonNull());
    return base_layer_;
  }

  bool hasDepthFar() const { return has_depth_far_; }
  double depthFar() const {
    DCHECK(has_depth_far_);
    return depth_far_;
  }
  inline void setDepthFar(double);

  bool hasDepthNear() const { return has_depth_near_; }
  double depthNear() const {
    DCHECK(has_depth_near_);
    return depth_near_;
  }
  inline void setDepthNear(double);

  bool hasInlineVerticalFieldOfView() const { return has_inline_vertical_field_of_view_; }
  double inlineVerticalFieldOfView() const {
    DCHECK(has_inline_vertical_field_of_view_);
    return inline_vertical_field_of_view_;
  }
  inline void setInlineVerticalFieldOfView(double);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_base_layer_ = false;
  bool has_depth_far_ = false;
  bool has_depth_near_ = false;
  bool has_inline_vertical_field_of_view_ = false;

  Member<XRWebGLLayer> base_layer_;
  double depth_far_;
  double depth_near_;
  double inline_vertical_field_of_view_;

  friend class V8XRRenderStateInit;
};

void XRRenderStateInit::setBaseLayer(XRWebGLLayer* value) {
  base_layer_ = value;
  has_base_layer_ = true;
}

void XRRenderStateInit::setBaseLayerToNull() {
  base_layer_ = Member<XRWebGLLayer>();
  has_base_layer_ = true;
}

void XRRenderStateInit::setDepthFar(double value) {
  depth_far_ = value;
  has_depth_far_ = true;
}

void XRRenderStateInit::setDepthNear(double value) {
  depth_near_ = value;
  has_depth_near_ = true;
}

void XRRenderStateInit::setInlineVerticalFieldOfView(double value) {
  inline_vertical_field_of_view_ = value;
  has_inline_vertical_field_of_view_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_RENDER_STATE_INIT_H_
