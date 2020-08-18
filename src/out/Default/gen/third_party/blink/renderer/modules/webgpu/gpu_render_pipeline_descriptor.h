// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_PIPELINE_DESCRIPTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_PIPELINE_DESCRIPTOR_H_

#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/webgpu/gpu_pipeline_descriptor_base.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class GPUProgrammableStageDescriptor;
class GPUVertexStateDescriptor;
class GPUColorStateDescriptor;
class GPURasterizationStateDescriptor;
class GPUDepthStencilStateDescriptor;

class MODULES_EXPORT GPURenderPipelineDescriptor : public GPUPipelineDescriptorBase {
 public:
  static GPURenderPipelineDescriptor* Create() { return MakeGarbageCollected<GPURenderPipelineDescriptor>(); }
  static GPURenderPipelineDescriptor* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPURenderPipelineDescriptor>();
  }

  GPURenderPipelineDescriptor();
  virtual ~GPURenderPipelineDescriptor();

  bool hasAlphaToCoverageEnabled() const { return has_alpha_to_coverage_enabled_; }
  bool alphaToCoverageEnabled() const {
    DCHECK(has_alpha_to_coverage_enabled_);
    return alpha_to_coverage_enabled_;
  }
  inline void setAlphaToCoverageEnabled(bool);

  bool hasColorStates() const { return has_color_states_; }
  const HeapVector<Member<GPUColorStateDescriptor>>& colorStates() const {
    DCHECK(has_color_states_);
    return color_states_;
  }
  void setColorStates(const HeapVector<Member<GPUColorStateDescriptor>>&);

  bool hasDepthStencilState() const { return !!depth_stencil_state_; }
  GPUDepthStencilStateDescriptor* depthStencilState() const {
    return depth_stencil_state_;
  }
  void setDepthStencilState(GPUDepthStencilStateDescriptor*);

  bool hasFragmentStage() const { return !!fragment_stage_; }
  GPUProgrammableStageDescriptor* fragmentStage() const {
    return fragment_stage_;
  }
  void setFragmentStage(GPUProgrammableStageDescriptor*);

  bool hasPrimitiveTopology() const { return !primitive_topology_.IsNull(); }
  const String& primitiveTopology() const {
    return primitive_topology_;
  }
  inline void setPrimitiveTopology(const String&);

  bool hasRasterizationState() const { return !!rasterization_state_; }
  GPURasterizationStateDescriptor* rasterizationState() const {
    return rasterization_state_;
  }
  void setRasterizationState(GPURasterizationStateDescriptor*);

  bool hasSampleCount() const { return has_sample_count_; }
  uint32_t sampleCount() const {
    DCHECK(has_sample_count_);
    return sample_count_;
  }
  inline void setSampleCount(uint32_t);

  bool hasSampleMask() const { return has_sample_mask_; }
  uint32_t sampleMask() const {
    DCHECK(has_sample_mask_);
    return sample_mask_;
  }
  inline void setSampleMask(uint32_t);

  bool hasVertexStage() const { return !!vertex_stage_; }
  GPUProgrammableStageDescriptor* vertexStage() const {
    return vertex_stage_;
  }
  void setVertexStage(GPUProgrammableStageDescriptor*);

  bool hasVertexState() const { return !!vertex_state_; }
  GPUVertexStateDescriptor* vertexState() const {
    return vertex_state_;
  }
  void setVertexState(GPUVertexStateDescriptor*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_alpha_to_coverage_enabled_ = false;
  bool has_color_states_ = false;
  bool has_sample_count_ = false;
  bool has_sample_mask_ = false;

  bool alpha_to_coverage_enabled_;
  HeapVector<Member<GPUColorStateDescriptor>> color_states_;
  Member<GPUDepthStencilStateDescriptor> depth_stencil_state_;
  Member<GPUProgrammableStageDescriptor> fragment_stage_;
  String primitive_topology_;
  Member<GPURasterizationStateDescriptor> rasterization_state_;
  uint32_t sample_count_;
  uint32_t sample_mask_;
  Member<GPUProgrammableStageDescriptor> vertex_stage_;
  Member<GPUVertexStateDescriptor> vertex_state_;

  friend class V8GPURenderPipelineDescriptor;
};

void GPURenderPipelineDescriptor::setAlphaToCoverageEnabled(bool value) {
  alpha_to_coverage_enabled_ = value;
  has_alpha_to_coverage_enabled_ = true;
}

void GPURenderPipelineDescriptor::setPrimitiveTopology(const String& value) {
  primitive_topology_ = value;
}

void GPURenderPipelineDescriptor::setSampleCount(uint32_t value) {
  sample_count_ = value;
  has_sample_count_ = true;
}

void GPURenderPipelineDescriptor::setSampleMask(uint32_t value) {
  sample_mask_ = value;
  has_sample_mask_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_PIPELINE_DESCRIPTOR_H_
