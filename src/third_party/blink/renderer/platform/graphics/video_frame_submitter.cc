// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/platform/graphics/video_frame_submitter.h"

#include <utility>

#include "base/bind.h"
#include "base/metrics/histogram_macros.h"
#include "base/threading/sequenced_task_runner_handle.h"
#include "base/trace_event/trace_event.h"
#include "cc/metrics/video_playback_roughness_reporter.h"
#include "components/viz/common/resources/resource_id.h"
#include "components/viz/common/resources/returned_resource.h"
#include "media/base/video_frame.h"
#include "media/base/video_types.h"
#include "mojo/public/cpp/bindings/remote.h"
#include "services/viz/public/cpp/gpu/context_provider_command_buffer.h"
#include "services/viz/public/mojom/compositing/compositor_frame_sink.mojom-blink.h"
#include "services/viz/public/mojom/hit_test/hit_test_region_list.mojom-blink.h"
#include "third_party/blink/public/common/thread_safe_browser_interface_broker_proxy.h"
#include "third_party/blink/public/mojom/frame_sinks/embedded_frame_sink.mojom-blink.h"
#include "third_party/blink/public/platform/platform.h"
#include "third_party/blink/renderer/platform/graphics/canvas_resource.h"
#include "ui/gfx/presentation_feedback.h"

namespace blink {

VideoFrameSubmitter::VideoFrameSubmitter(
    WebContextProviderCallback context_provider_callback,
    cc::PlaybackRoughnessReportingCallback roughness_reporting_callback,
    std::unique_ptr<VideoFrameResourceProvider> resource_provider)
    : context_provider_callback_(context_provider_callback),
      resource_provider_(std::move(resource_provider)),
      rotation_(media::VIDEO_ROTATION_0),
      roughness_reporter_(std::make_unique<cc::VideoPlaybackRoughnessReporter>(
          std::move(roughness_reporting_callback))),
      frame_trackers_(false, nullptr) {
  DETACH_FROM_THREAD(thread_checker_);
}

VideoFrameSubmitter::~VideoFrameSubmitter() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  if (context_provider_)
    context_provider_->RemoveObserver(this);

  // Release VideoFrameResourceProvider early since its destruction will make
  // calls back into this class via the viz::SharedBitmapReporter interface.
  resource_provider_.reset();
}

void VideoFrameSubmitter::StopUsingProvider() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  if (is_rendering_)
    StopRendering();
  video_frame_provider_ = nullptr;
}

void VideoFrameSubmitter::StartRendering() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  DCHECK(!is_rendering_);
  is_rendering_ = true;

  if (compositor_frame_sink_) {
    compositor_frame_sink_->SetNeedsBeginFrame(IsDrivingFrameUpdates());
  }

  frame_trackers_.StartSequence(cc::FrameSequenceTrackerType::kVideo);
}

void VideoFrameSubmitter::StopRendering() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  DCHECK(is_rendering_);
  DCHECK(video_frame_provider_);

  is_rendering_ = false;

  frame_trackers_.StopSequence(cc::FrameSequenceTrackerType::kVideo);
  roughness_reporter_->Reset();

  UpdateSubmissionState();
}

void VideoFrameSubmitter::DidReceiveFrame() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  DCHECK(video_frame_provider_);
  SubmitSingleFrame();
}

bool VideoFrameSubmitter::IsDrivingFrameUpdates() const {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);

  // We drive frame updates only when we believe that something is consuming
  // them.  This is different than VideoLayer, which drives updates any time
  // they're in the layer tree.
  return (is_rendering_ && ShouldSubmit()) || force_begin_frames_;
}

void VideoFrameSubmitter::Initialize(cc::VideoFrameProvider* provider,
                                     bool is_media_stream) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  if (!provider)
    return;

  DCHECK(!video_frame_provider_);
  video_frame_provider_ = provider;
  is_media_stream_ = is_media_stream;
  context_provider_callback_.Run(
      nullptr, base::BindOnce(&VideoFrameSubmitter::OnReceivedContextProvider,
                              weak_ptr_factory_.GetWeakPtr()));
}

void VideoFrameSubmitter::SetRotation(media::VideoRotation rotation) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  rotation_ = rotation;
}

void VideoFrameSubmitter::EnableSubmission(
    viz::SurfaceId surface_id,
    base::TimeTicks local_surface_id_allocation_time) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);

  // TODO(lethalantidote): Set these fields earlier in the constructor. Will
  // need to construct VideoFrameSubmitter later in order to do this.
  frame_sink_id_ = surface_id.frame_sink_id();
  child_local_surface_id_allocator_.UpdateFromParent(
      viz::LocalSurfaceIdAllocation(surface_id.local_surface_id(),
                                    local_surface_id_allocation_time));
  if (resource_provider_->IsInitialized())
    StartSubmitting();
}

void VideoFrameSubmitter::SetIsSurfaceVisible(bool is_visible) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  is_surface_visible_ = is_visible;
  UpdateSubmissionState();
}

void VideoFrameSubmitter::SetIsPageVisible(bool is_visible) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  is_page_visible_ = is_visible;
  UpdateSubmissionState();
}

void VideoFrameSubmitter::SetForceBeginFrames(bool force_begin_frames) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  force_begin_frames_ = force_begin_frames;
  UpdateSubmissionState();
}

void VideoFrameSubmitter::SetForceSubmit(bool force_submit) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  force_submit_ = force_submit;
  UpdateSubmissionState();
}

void VideoFrameSubmitter::OnContextLost() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  receiver_.reset();

  if (context_provider_)
    context_provider_->RemoveObserver(this);

  waiting_for_compositor_ack_ = false;
  last_frame_id_.reset();

  resource_provider_->OnContextLost();

  // |compositor_frame_sink_| should be reset last.
  compositor_frame_sink_.reset();

  context_provider_callback_.Run(
      context_provider_,
      base::BindOnce(&VideoFrameSubmitter::OnReceivedContextProvider,
                     weak_ptr_factory_.GetWeakPtr()));
}

void VideoFrameSubmitter::DidReceiveCompositorFrameAck(
    const WTF::Vector<viz::ReturnedResource>& resources) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  ReclaimResources(resources);
  waiting_for_compositor_ack_ = false;
}

void VideoFrameSubmitter::OnBeginFrame(
    const viz::BeginFrameArgs& args,
    WTF::HashMap<uint32_t, ::viz::mojom::blink::FrameTimingDetailsPtr>
        timing_details) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  TRACE_EVENT0("media", "VideoFrameSubmitter::OnBeginFrame");

  last_begin_frame_args_ = args;

  for (const auto& pair : timing_details) {
    if (viz::FrameTokenGT(pair.key, *next_frame_token_))
      continue;
    auto& feedback = *pair.value->presentation_feedback;
#ifdef OS_LINUX
    // TODO: On Linux failure flag is unreliable, and perfectly rendered frames
    // are reported as failures all the time.
    bool presentation_failure = false;
#else
    bool presentation_failure =
        feedback.flags & gfx::PresentationFeedback::kFailure;
#endif
    if (!presentation_failure &&
        !ignorable_submitted_frames_.contains(pair.key)) {
      frame_trackers_.NotifyFramePresented(
          pair.key, gfx::PresentationFeedback(
                        feedback.timestamp, feedback.interval, feedback.flags));

      // We assume that presentation feedback is reliable if
      // 1. (kHWCompletion) OS told us that the frame was shown at that time
      //  or
      // 2. (kVSync) at least presentation time is aligned with vsyncs intervals
      uint32_t reliable_feedback_mask =
          gfx::PresentationFeedback::kHWCompletion |
          gfx::PresentationFeedback::kVSync;
      bool reliable_timestamp = feedback.flags & reliable_feedback_mask;
      roughness_reporter_->FramePresented(pair.key, feedback.timestamp,
                                          reliable_timestamp);
    }

    ignorable_submitted_frames_.erase(pair.key);
    TRACE_EVENT_NESTABLE_ASYNC_END_WITH_TIMESTAMP0(
        "media", "VideoFrameSubmitter", TRACE_ID_LOCAL(pair.key),
        feedback.timestamp);
  }
  frame_trackers_.NotifyBeginImplFrame(args);

  base::ScopedClosureRunner end_frame(
      base::BindOnce(&cc::FrameSequenceTrackerCollection::NotifyFrameEnd,
                     base::Unretained(&frame_trackers_), args, args));
  base::ScopedClosureRunner roughness_processing(
      base::BindOnce(&cc::VideoPlaybackRoughnessReporter::ProcessFrameWindow,
                     base::Unretained(roughness_reporter_.get())));

  // Don't call UpdateCurrentFrame() for MISSED BeginFrames. Also don't call it
  // after StopRendering() has been called (forbidden by API contract).
  viz::BeginFrameAck current_begin_frame_ack(args, false);
  if (args.type == viz::BeginFrameArgs::MISSED || !is_rendering_) {
    compositor_frame_sink_->DidNotProduceFrame(current_begin_frame_ack);
    frame_trackers_.NotifyImplFrameCausedNoDamage(current_begin_frame_ack);
    return;
  }

  // Update the current frame, even if we haven't gotten an ack for a previous
  // frame yet. That probably signals a dropped frame, and this will let the
  // provider know that it happened, since we won't PutCurrentFrame this one.
  // Note that we should DidNotProduceFrame with or without the ack.
  if (!video_frame_provider_ || !video_frame_provider_->UpdateCurrentFrame(
                                    args.frame_time + args.interval,
                                    args.frame_time + 2 * args.interval)) {
    compositor_frame_sink_->DidNotProduceFrame(current_begin_frame_ack);
    frame_trackers_.NotifyImplFrameCausedNoDamage(current_begin_frame_ack);
    return;
  }

  // We do have a new frame that we could display.  See if we're supposed to
  // actually submit a frame or not, and try to submit one.
  auto video_frame = video_frame_provider_->GetCurrentFrame();
  if (!SubmitFrame(current_begin_frame_ack, std::move(video_frame))) {
    compositor_frame_sink_->DidNotProduceFrame(current_begin_frame_ack);
    frame_trackers_.NotifyImplFrameCausedNoDamage(current_begin_frame_ack);
    return;
  }

  // We submitted a frame!

  // We still signal PutCurrentFrame here, rather than on the ack, so that it
  // lines up with the correct frame.  Otherwise, any intervening calls to
  // OnBeginFrame => UpdateCurrentFrame will cause the put to signal that the
  // later frame was displayed.
  video_frame_provider_->PutCurrentFrame();
}

void VideoFrameSubmitter::ReclaimResources(
    const WTF::Vector<viz::ReturnedResource>& resources) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  resource_provider_->ReceiveReturnsFromParent(resources);
}

void VideoFrameSubmitter::DidAllocateSharedBitmap(
    base::ReadOnlySharedMemoryRegion region,
    const viz::SharedBitmapId& id) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  DCHECK(compositor_frame_sink_);
  compositor_frame_sink_->DidAllocateSharedBitmap(std::move(region), id);
}

void VideoFrameSubmitter::DidDeleteSharedBitmap(const viz::SharedBitmapId& id) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  DCHECK(compositor_frame_sink_);
  compositor_frame_sink_->DidDeleteSharedBitmap(id);
}

void VideoFrameSubmitter::OnReceivedContextProvider(
    bool use_gpu_compositing,
    scoped_refptr<viz::RasterContextProvider> context_provider) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  if (!use_gpu_compositing) {
    resource_provider_->Initialize(nullptr, this);
    if (frame_sink_id_.is_valid())
      StartSubmitting();
    return;
  }

  bool has_good_context = false;
  while (!has_good_context) {
    if (!context_provider) {
      // Delay to retry getting the context_provider.
      constexpr base::TimeDelta kGetContextProviderRetryTimeout =
          base::TimeDelta::FromMilliseconds(150);

      base::ThreadTaskRunnerHandle::Get()->PostDelayedTask(
          FROM_HERE,
          base::BindOnce(
              context_provider_callback_, context_provider_,
              base::BindOnce(&VideoFrameSubmitter::OnReceivedContextProvider,
                             weak_ptr_factory_.GetWeakPtr())),
          kGetContextProviderRetryTimeout);
      return;
    }

    // Note that |context_provider| is now null after the move, such that if we
    // end up having !|has_good_context|, we will retry to obtain the
    // context_provider.
    context_provider_ = std::move(context_provider);
    auto result = context_provider_->BindToCurrentThread();

    has_good_context =
        result == gpu::ContextResult::kSuccess &&
        context_provider_->ContextGL()->GetGraphicsResetStatusKHR() ==
            GL_NO_ERROR;
  }
  context_provider_->AddObserver(this);
  resource_provider_->Initialize(context_provider_.get(), nullptr);

  if (frame_sink_id_.is_valid())
    StartSubmitting();
}

void VideoFrameSubmitter::StartSubmitting() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  DCHECK(frame_sink_id_.is_valid());

  mojo::Remote<mojom::blink::EmbeddedFrameSinkProvider> provider;
  Platform::Current()->GetBrowserInterfaceBroker()->GetInterface(
      provider.BindNewPipeAndPassReceiver());

  provider->CreateCompositorFrameSink(
      frame_sink_id_, receiver_.BindNewPipeAndPassRemote(),
      compositor_frame_sink_.BindNewPipeAndPassReceiver());
  if (!surface_embedder_.is_bound()) {
    provider->ConnectToEmbedder(frame_sink_id_,
                                surface_embedder_.BindNewPipeAndPassReceiver());
  } else {
    GenerateNewSurfaceId();
  }

  compositor_frame_sink_.set_disconnect_handler(base::BindOnce(
      &VideoFrameSubmitter::OnContextLost, base::Unretained(this)));

  if (!compositor_frame_sink_)
    return;

  compositor_frame_sink_->InitializeCompositorFrameSinkType(
      is_media_stream_ ? viz::mojom::CompositorFrameSinkType::kMediaStream
                       : viz::mojom::CompositorFrameSinkType::kVideo);
  UpdateSubmissionState();
}

void VideoFrameSubmitter::UpdateSubmissionState() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  if (!compositor_frame_sink_)
    return;

  compositor_frame_sink_->SetNeedsBeginFrame(IsDrivingFrameUpdates());

  // These two calls are very important; they are responsible for significant
  // memory savings when content is off-screen.
  //
  // While off-screen, we do not submit frames (unless |force_submit_| is true),
  // which prevents GPU resource creation and accumulation on the remote side.
  // During the transition to off-screen we further send an empty frame with the
  // intent to evict any resources held for the previous frame. Combined these
  // optimizations save 30-50% in cc:: resource memory usage.
  //
  // See https://crbug.com/829813 and https://crbug.com/829565.
  if (ShouldSubmit()) {
    // Submit even if we're rendering, otherwise we may display an empty frame
    // before the next OnBeginFrame() which can cause a visible flash.
    SubmitSingleFrame();
  } else {
    // Post a delayed task to submit an empty frame. We don't do this here,
    // since there is a race between when we're notified that the player is not
    // visible, and when auto-PiP starts. In PiP, we'll be set to force submit,
    // but we're notified after we find out that the page is hidden.  If we
    // submit an empty frame now, then there will be a flicker in the video
    // when the empty frame is displayed. By delaying the empty frame, we give
    // the auto-PiP a chance to start. Note that the empty frame isn't required
    // for visual correctness; it's just for resource cleanup. We can delay
    // resource cleanup a little.
    //
    // If there are any in-flight empty frame requests, this cancels them. We
    // want to wait until any group of state changes stabilizes.
    empty_frame_timer_.Start(
        FROM_HERE, base::TimeDelta::FromMilliseconds(500),
        base::BindOnce(&VideoFrameSubmitter::SubmitEmptyFrameIfNeeded,
                       base::Unretained(this)));
  }
}

void VideoFrameSubmitter::SubmitEmptyFrameIfNeeded() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  if (!compositor_frame_sink_)
    return;

  // If we are allowed to submit real frames, then don't send a blank frame
  // since the last real frame might actually be visible.
  //
  // We do not actually submit a real frame here, though; that should be done
  // (if desired) by whatever switched us to ShouldSubmit() mode.
  if (ShouldSubmit())
    return;

  // If we don't have a frame size, then we can't send a blank frame.
  if (frame_size_.IsEmpty())
    return;

  SubmitEmptyFrame();
}

bool VideoFrameSubmitter::SubmitFrame(
    const viz::BeginFrameAck& begin_frame_ack,
    scoped_refptr<media::VideoFrame> video_frame) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  DCHECK(video_frame);
  TRACE_EVENT1("media", "VideoFrameSubmitter::SubmitFrame", "frame",
               video_frame->AsHumanReadableString());

  if (!compositor_frame_sink_ || !ShouldSubmit())
    return false;

  // Not submitting a frame when waiting for a previous ack saves memory by
  // not building up unused remote side resources. See https://crbug.com/830828.
  //
  // Similarly we don't submit the same frame multiple times.
  if (waiting_for_compositor_ack_ || last_frame_id_ == video_frame->unique_id())
    return false;

  last_frame_id_ = video_frame->unique_id();

  gfx::Size frame_size(video_frame->natural_size());
  if (rotation_ == media::VIDEO_ROTATION_90 ||
      rotation_ == media::VIDEO_ROTATION_270) {
    frame_size = gfx::Size(frame_size.height(), frame_size.width());
  }

  if (frame_size.IsEmpty()) {
    // We're not supposed to get 0x0 frames.  For now, just ignore it until we
    // track down where they're coming from.  Creating a CompositorFrame with an
    // empty output rectangle isn't allowed.
    // crbug.com/979564
    return false;
  }

  if (frame_size_ != frame_size) {
    if (!frame_size_.IsEmpty())
      GenerateNewSurfaceId();
    frame_size_ = frame_size;
  }

  auto frame_token = ++next_frame_token_;
  auto source_id = begin_frame_ack.frame_id.source_id;
  if (source_id != viz::BeginFrameArgs::kManualSourceId) {
    // Roughness reporter only cares about true video frames.
    roughness_reporter_->FrameSubmitted(frame_token, *video_frame.get(),
                                        last_begin_frame_args_.interval);
  }
  auto compositor_frame = CreateCompositorFrame(frame_token, begin_frame_ack,
                                                std::move(video_frame));

  WebVector<viz::ResourceId> resources;
  const auto& quad_list = compositor_frame.render_pass_list.back()->quad_list;
  if (!quad_list.empty()) {
    DCHECK_EQ(quad_list.size(), 1u);
    resources.Assign(quad_list.front()->resources);
  }

  WebVector<viz::TransferableResource> resource_list;
  resource_provider_->PrepareSendToParent(resources, &resource_list);
  compositor_frame.resource_list = resource_list.ReleaseVector();

  // We can pass nullptr for the HitTestData as the CompositorFram will not
  // contain any SurfaceDrawQuads.
  compositor_frame_sink_->SubmitCompositorFrame(
      child_local_surface_id_allocator_.GetCurrentLocalSurfaceIdAllocation()
          .local_surface_id(),
      std::move(compositor_frame), nullptr, 0);
  frame_trackers_.NotifySubmitFrame(frame_token, false, begin_frame_ack,
                                    last_begin_frame_args_);
  resource_provider_->ReleaseFrameResources();

  waiting_for_compositor_ack_ = true;
  return true;
}

void VideoFrameSubmitter::SubmitEmptyFrame() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  DCHECK(compositor_frame_sink_ && !ShouldSubmit());
  DCHECK(!frame_size_.IsEmpty());
  TRACE_EVENT0("media", "VideoFrameSubmitter::SubmitEmptyFrame");

  // If there's nothing to submit to or we've already submitted an empty frame,
  // don't submit another one.
  if (!compositor_frame_sink_ || !last_frame_id_.has_value())
    return;

  last_frame_id_.reset();
  auto begin_frame_ack = viz::BeginFrameAck::CreateManualAckWithDamage();
  auto frame_token = ++next_frame_token_;
  auto compositor_frame =
      CreateCompositorFrame(frame_token, begin_frame_ack, nullptr);

  compositor_frame_sink_->SubmitCompositorFrame(
      child_local_surface_id_allocator_.GetCurrentLocalSurfaceIdAllocation()
          .local_surface_id(),
      std::move(compositor_frame), nullptr, 0);
  frame_trackers_.NotifySubmitFrame(frame_token, false, begin_frame_ack,
                                    last_begin_frame_args_);

  // We don't set |waiting_for_compositor_ack_| here since we want to allow a
  // subsequent real frame to replace it at any time if needed.
}

void VideoFrameSubmitter::SubmitSingleFrame() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);

  // If we haven't gotten a valid result yet from |context_provider_callback_|
  // |resource_provider_| will remain uninitialized.
  // |video_frame_provider_| may be null if StopUsingProvider has been called,
  // which could happen if the |video_frame_provider_| is destructing while we
  // are waiting for the ContextProvider.
  if (!resource_provider_->IsInitialized() || !video_frame_provider_)
    return;

  auto video_frame = video_frame_provider_->GetCurrentFrame();
  if (!video_frame)
    return;

  if (SubmitFrame(viz::BeginFrameAck::CreateManualAckWithDamage(),
                  std::move(video_frame))) {
    video_frame_provider_->PutCurrentFrame();
  }
}

bool VideoFrameSubmitter::ShouldSubmit() const {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  return (is_surface_visible_ && is_page_visible_) || force_submit_;
}

viz::CompositorFrame VideoFrameSubmitter::CreateCompositorFrame(
    uint32_t frame_token,
    const viz::BeginFrameAck& begin_frame_ack,
    scoped_refptr<media::VideoFrame> video_frame) {
  DCHECK(!frame_size_.IsEmpty());

  viz::CompositorFrame compositor_frame;
  compositor_frame.metadata.begin_frame_ack = begin_frame_ack;
  compositor_frame.metadata.frame_token = frame_token;
  compositor_frame.metadata.preferred_frame_interval =
      video_frame_provider_
          ? video_frame_provider_->GetPreferredRenderInterval()
          : viz::BeginFrameArgs::MinInterval();

  if (video_frame && video_frame->metadata()->decode_end_time.has_value()) {
    base::TimeTicks value = *video_frame->metadata()->decode_end_time;
    TRACE_EVENT_NESTABLE_ASYNC_BEGIN_WITH_TIMESTAMP0(
        "media", "VideoFrameSubmitter", TRACE_ID_LOCAL(frame_token), value);
    TRACE_EVENT_NESTABLE_ASYNC_BEGIN_WITH_TIMESTAMP0(
        "media", "Pre-submit buffering", TRACE_ID_LOCAL(frame_token), value);
    TRACE_EVENT_NESTABLE_ASYNC_END0("media", "Pre-submit buffering",
                                    TRACE_ID_LOCAL(frame_token));

    if (begin_frame_ack.frame_id.source_id ==
        viz::BeginFrameArgs::kManualSourceId)
      ignorable_submitted_frames_.insert(frame_token);

    UMA_HISTOGRAM_TIMES("Media.VideoFrameSubmitter.PreSubmitBuffering",
                        base::TimeTicks::Now() - value);
  } else {
    TRACE_EVENT_NESTABLE_ASYNC_BEGIN1("media", "VideoFrameSubmitter",
                                      TRACE_ID_LOCAL(frame_token),
                                      "empty video frame?", !video_frame);
  }

  // We don't assume that the ack is marked as having damage.  However, we're
  // definitely emitting a CompositorFrame that damages the entire surface.
  compositor_frame.metadata.begin_frame_ack.has_damage = true;
  compositor_frame.metadata.device_scale_factor = 1;
  compositor_frame.metadata.may_contain_video = true;
  compositor_frame.metadata.local_surface_id_allocation_time =
      child_local_surface_id_allocator_.GetCurrentLocalSurfaceIdAllocation()
          .allocation_time();

  // Specify size of shared quad state and quad lists so that RenderPass doesn't
  // allocate using the defaults of 32 and 128 since we only append one quad.
  auto render_pass = viz::RenderPass::Create(/*shared_quad_state_list_size=*/1u,
                                             /*quad_list_size*/ 1u);
  render_pass->SetNew(1, gfx::Rect(frame_size_), gfx::Rect(frame_size_),
                      gfx::Transform());

  if (video_frame) {
    compositor_frame.metadata.content_color_usage =
        video_frame->ColorSpace().GetContentColorUsage();
    const bool is_opaque = media::IsOpaque(video_frame->format());
    resource_provider_->AppendQuads(render_pass.get(), std::move(video_frame),
                                    rotation_, is_opaque);
  }

  compositor_frame.render_pass_list.emplace_back(std::move(render_pass));
  return compositor_frame;
}

void VideoFrameSubmitter::GenerateNewSurfaceId() {
  last_frame_id_.reset();

  // We need a new id in the event of context loss.
  child_local_surface_id_allocator_.GenerateId();

  surface_embedder_->SetLocalSurfaceId(
      child_local_surface_id_allocator_.GetCurrentLocalSurfaceIdAllocation()
          .local_surface_id());
}

}  // namespace blink
