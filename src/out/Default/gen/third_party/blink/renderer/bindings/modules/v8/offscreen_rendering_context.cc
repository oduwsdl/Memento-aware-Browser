// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/offscreen_rendering_context.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_image_bitmap_rendering_context.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_offscreen_canvas_rendering_context_2d.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl2_compute_rendering_context.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl2_rendering_context.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_rendering_context.h"

namespace blink {

OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext() : type_(SpecificType::kNone) {}

ImageBitmapRenderingContext* OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::GetAsImageBitmapRenderingContext() const {
  DCHECK(IsImageBitmapRenderingContext());
  return image_bitmap_rendering_context_;
}

void OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::SetImageBitmapRenderingContext(ImageBitmapRenderingContext* value) {
  DCHECK(IsNull());
  image_bitmap_rendering_context_ = value;
  type_ = SpecificType::kImageBitmapRenderingContext;
}

OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::FromImageBitmapRenderingContext(ImageBitmapRenderingContext* value) {
  OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext container;
  container.SetImageBitmapRenderingContext(value);
  return container;
}

OffscreenCanvasRenderingContext2D* OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::GetAsOffscreenCanvasRenderingContext2D() const {
  DCHECK(IsOffscreenCanvasRenderingContext2D());
  return offscreen_canvas_rendering_context_2d_;
}

void OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::SetOffscreenCanvasRenderingContext2D(OffscreenCanvasRenderingContext2D* value) {
  DCHECK(IsNull());
  offscreen_canvas_rendering_context_2d_ = value;
  type_ = SpecificType::kOffscreenCanvasRenderingContext2D;
}

OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::FromOffscreenCanvasRenderingContext2D(OffscreenCanvasRenderingContext2D* value) {
  OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext container;
  container.SetOffscreenCanvasRenderingContext2D(value);
  return container;
}

WebGL2ComputeRenderingContext* OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::GetAsWebGL2ComputeRenderingContext() const {
  DCHECK(IsWebGL2ComputeRenderingContext());
  return webgl2_compute_rendering_context_;
}

void OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::SetWebGL2ComputeRenderingContext(WebGL2ComputeRenderingContext* value) {
  DCHECK(IsNull());
  webgl2_compute_rendering_context_ = value;
  type_ = SpecificType::kWebGL2ComputeRenderingContext;
}

OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::FromWebGL2ComputeRenderingContext(WebGL2ComputeRenderingContext* value) {
  OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext container;
  container.SetWebGL2ComputeRenderingContext(value);
  return container;
}

WebGL2RenderingContext* OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::GetAsWebGL2RenderingContext() const {
  DCHECK(IsWebGL2RenderingContext());
  return webgl2_rendering_context_;
}

void OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::SetWebGL2RenderingContext(WebGL2RenderingContext* value) {
  DCHECK(IsNull());
  webgl2_rendering_context_ = value;
  type_ = SpecificType::kWebGL2RenderingContext;
}

OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::FromWebGL2RenderingContext(WebGL2RenderingContext* value) {
  OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext container;
  container.SetWebGL2RenderingContext(value);
  return container;
}

WebGLRenderingContext* OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::GetAsWebGLRenderingContext() const {
  DCHECK(IsWebGLRenderingContext());
  return webgl_rendering_context_;
}

void OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::SetWebGLRenderingContext(WebGLRenderingContext* value) {
  DCHECK(IsNull());
  webgl_rendering_context_ = value;
  type_ = SpecificType::kWebGLRenderingContext;
}

OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::FromWebGLRenderingContext(WebGLRenderingContext* value) {
  OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext container;
  container.SetWebGLRenderingContext(value);
  return container;
}

OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext(const OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext&) = default;
OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::~OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext() = default;
OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext& OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::operator=(const OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext&) = default;

void OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::Trace(Visitor* visitor) const {
  visitor->Trace(image_bitmap_rendering_context_);
  visitor->Trace(offscreen_canvas_rendering_context_2d_);
  visitor->Trace(webgl2_compute_rendering_context_);
  visitor->Trace(webgl2_rendering_context_);
  visitor->Trace(webgl_rendering_context_);
}

void V8OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (V8ImageBitmapRenderingContext::HasInstance(v8_value, isolate)) {
    ImageBitmapRenderingContext* cpp_value = V8ImageBitmapRenderingContext::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetImageBitmapRenderingContext(cpp_value);
    return;
  }

  if (V8OffscreenCanvasRenderingContext2D::HasInstance(v8_value, isolate)) {
    OffscreenCanvasRenderingContext2D* cpp_value = V8OffscreenCanvasRenderingContext2D::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetOffscreenCanvasRenderingContext2D(cpp_value);
    return;
  }

  if (V8WebGL2ComputeRenderingContext::HasInstance(v8_value, isolate)) {
    WebGL2ComputeRenderingContext* cpp_value = V8WebGL2ComputeRenderingContext::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetWebGL2ComputeRenderingContext(cpp_value);
    return;
  }

  if (V8WebGL2RenderingContext::HasInstance(v8_value, isolate)) {
    WebGL2RenderingContext* cpp_value = V8WebGL2RenderingContext::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetWebGL2RenderingContext(cpp_value);
    return;
  }

  if (V8WebGLRenderingContext::HasInstance(v8_value, isolate)) {
    WebGLRenderingContext* cpp_value = V8WebGLRenderingContext::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetWebGLRenderingContext(cpp_value);
    return;
  }

  exception_state.ThrowTypeError("The provided value is not of type '(OffscreenCanvasRenderingContext2D or WebGLRenderingContext or WebGL2RenderingContext or WebGL2ComputeRenderingContext or ImageBitmapRenderingContext)'");
}

v8::Local<v8::Value> ToV8(const OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::SpecificType::kNone:
      return v8::Null(isolate);
    case OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::SpecificType::kImageBitmapRenderingContext:
      return ToV8(impl.GetAsImageBitmapRenderingContext(), creationContext, isolate);
    case OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::SpecificType::kOffscreenCanvasRenderingContext2D:
      return ToV8(impl.GetAsOffscreenCanvasRenderingContext2D(), creationContext, isolate);
    case OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::SpecificType::kWebGL2ComputeRenderingContext:
      return ToV8(impl.GetAsWebGL2ComputeRenderingContext(), creationContext, isolate);
    case OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::SpecificType::kWebGL2RenderingContext:
      return ToV8(impl.GetAsWebGL2RenderingContext(), creationContext, isolate);
    case OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::SpecificType::kWebGLRenderingContext:
      return ToV8(impl.GetAsWebGLRenderingContext(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext NativeValueTraits<OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext impl;
  V8OffscreenCanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrWebGL2ComputeRenderingContextOrImageBitmapRenderingContext::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

