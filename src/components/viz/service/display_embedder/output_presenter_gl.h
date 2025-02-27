// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_VIZ_SERVICE_DISPLAY_EMBEDDER_OUTPUT_PRESENTER_GL_H_
#define COMPONENTS_VIZ_SERVICE_DISPLAY_EMBEDDER_OUTPUT_PRESENTER_GL_H_

#include "components/viz/service/display_embedder/output_presenter.h"
#include "components/viz/service/viz_service_export.h"
#include "gpu/command_buffer/common/shared_image_usage.h"
#include "gpu/command_buffer/service/shared_image_factory.h"

namespace gl {
class GLSurface;
}  // namespace gl

namespace viz {

class VIZ_SERVICE_EXPORT OutputPresenterGL : public OutputPresenter {
 public:
  static const uint32_t kDefaultSharedImageUsage;

  static std::unique_ptr<OutputPresenterGL> Create(
      SkiaOutputSurfaceDependency* deps,
      gpu::MemoryTracker* memory_tracker);

  OutputPresenterGL(scoped_refptr<gl::GLSurface> gl_surface,
                    SkiaOutputSurfaceDependency* deps,
                    gpu::MemoryTracker* memory_tracker,
                    uint32_t shared_image_usage = kDefaultSharedImageUsage);
  ~OutputPresenterGL() override;

  gl::GLSurface* gl_surface() { return gl_surface_.get(); }

  // OutputPresenter implementation:
  void InitializeCapabilities(OutputSurface::Capabilities* capabilities) final;
  bool Reshape(const gfx::Size& size,
               float device_scale_factor,
               const gfx::ColorSpace& color_space,
               gfx::BufferFormat format,
               gfx::OverlayTransform transform) final;
  std::vector<std::unique_ptr<Image>> AllocateImages(
      gfx::ColorSpace color_space,
      gfx::Size image_size,
      size_t num_images) final;
  void SwapBuffers(SwapCompletionCallback completion_callback,
                   BufferPresentedCallback presentation_callback) final;
  void PostSubBuffer(const gfx::Rect& rect,
                     SwapCompletionCallback completion_callback,
                     BufferPresentedCallback presentation_callback) final;
  void CommitOverlayPlanes(SwapCompletionCallback completion_callback,
                           BufferPresentedCallback presentation_callback,
                           std::vector<ui::LatencyInfo> latency_info) final;
  void SchedulePrimaryPlane(
      const OverlayProcessorInterface::OutputSurfaceOverlayPlane& plane,
      Image* image,
      bool is_submitted) final;
  std::vector<OverlayData> ScheduleOverlays(
      SkiaOutputSurface::OverlayList overlays) final;

 private:
  scoped_refptr<gl::GLSurface> gl_surface_;
  SkiaOutputSurfaceDependency* dependency_;
  const bool supports_async_swap_;

  ResourceFormat image_format_;

  // Shared Image factories
  gpu::SharedImageFactory shared_image_factory_;
  gpu::SharedImageRepresentationFactory shared_image_representation_factory_;
  uint32_t shared_image_usage_;
};

}  // namespace viz

#endif  // COMPONENTS_VIZ_SERVICE_DISPLAY_EMBEDDER_OUTPUT_PRESENTER_GL_H_
