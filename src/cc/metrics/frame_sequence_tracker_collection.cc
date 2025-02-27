// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cc/metrics/frame_sequence_tracker_collection.h"

#include "base/memory/ptr_util.h"
#include "cc/metrics/compositor_frame_reporting_controller.h"
#include "cc/metrics/frame_sequence_tracker.h"
#include "cc/metrics/throughput_ukm_reporter.h"

namespace cc {

namespace {

using ThreadType = FrameSequenceMetrics::ThreadType;

bool IsScrollType(FrameSequenceTrackerType type) {
  return type == FrameSequenceTrackerType::kTouchScroll ||
         type == FrameSequenceTrackerType::kWheelScroll ||
         type == FrameSequenceTrackerType::kScrollbarScroll;
}

}  // namespace

FrameSequenceTrackerCollection::FrameSequenceTrackerCollection(
    bool is_single_threaded,
    CompositorFrameReportingController* compositor_frame_reporting_controller)
    : is_single_threaded_(is_single_threaded),
      compositor_frame_reporting_controller_(
          compositor_frame_reporting_controller) {}

FrameSequenceTrackerCollection::~FrameSequenceTrackerCollection() {
  frame_trackers_.clear();
  removal_trackers_.clear();
}

FrameSequenceTracker* FrameSequenceTrackerCollection::StartSequenceInternal(
    FrameSequenceTrackerType type,
    FrameSequenceMetrics::ThreadType scrolling_thread) {
  DCHECK_NE(FrameSequenceTrackerType::kCustom, type);
  if (is_single_threaded_)
    return nullptr;
  auto key = std::make_pair(type, scrolling_thread);
  if (frame_trackers_.contains(key))
    return frame_trackers_[key].get();

  auto tracker = base::WrapUnique(
      new FrameSequenceTracker(type, throughput_ukm_reporter_.get()));
  frame_trackers_[key] = std::move(tracker);

  if (compositor_frame_reporting_controller_)
    compositor_frame_reporting_controller_->AddActiveTracker(type);

  auto* metrics = frame_trackers_[key]->metrics();
  if (accumulated_metrics_.contains(key)) {
    metrics->AdoptTrace(accumulated_metrics_[key].get());
  }
  if (IsScrollType(type)) {
    DCHECK_NE(scrolling_thread, ThreadType::kUnknown);
    metrics->SetScrollingThread(scrolling_thread);
  }
  return frame_trackers_[key].get();
}

FrameSequenceTracker* FrameSequenceTrackerCollection::StartSequence(
    FrameSequenceTrackerType type) {
  DCHECK(!IsScrollType(type));
  return StartSequenceInternal(type, ThreadType::kUnknown);
}

FrameSequenceTracker* FrameSequenceTrackerCollection::StartScrollSequence(
    FrameSequenceTrackerType type,
    FrameSequenceMetrics::ThreadType scrolling_thread) {
  DCHECK(IsScrollType(type));
  return StartSequenceInternal(type, scrolling_thread);
}

void FrameSequenceTrackerCollection::StopSequence(
    FrameSequenceTrackerType type) {
  DCHECK_NE(FrameSequenceTrackerType::kCustom, type);

  auto key = std::make_pair(type, ThreadType::kUnknown);
  if (IsScrollType(type)) {
    key = std::make_pair(type, ThreadType::kCompositor);
    if (!frame_trackers_.contains(key))
      key = std::make_pair(type, ThreadType::kMain);
  }

  if (!frame_trackers_.contains(key))
    return;

  std::unique_ptr<FrameSequenceTracker> tracker =
      std::move(frame_trackers_[key]);

  if (compositor_frame_reporting_controller_)
    compositor_frame_reporting_controller_->RemoveActiveTracker(
        tracker->type());

  frame_trackers_.erase(key);
  tracker->ScheduleTerminate();
  removal_trackers_.push_back(std::move(tracker));
  DestroyTrackers();
}

void FrameSequenceTrackerCollection::StartCustomSequence(int sequence_id) {
  DCHECK(!base::Contains(custom_frame_trackers_, sequence_id));

  // base::Unretained() is safe here because |this| owns FrameSequenceTracker
  // and FrameSequenceMetrics.
  custom_frame_trackers_[sequence_id] =
      base::WrapUnique(new FrameSequenceTracker(
          sequence_id,
          base::BindOnce(
              &FrameSequenceTrackerCollection::AddCustomTrackerResult,
              base::Unretained(this), sequence_id)));
}

void FrameSequenceTrackerCollection::StopCustomSequence(int sequence_id) {
  auto it = custom_frame_trackers_.find(sequence_id);
  // This happens when an animation is aborted before starting.
  if (it == custom_frame_trackers_.end())
    return;

  std::unique_ptr<FrameSequenceTracker> tracker = std::move(it->second);
  custom_frame_trackers_.erase(it);
  tracker->ScheduleTerminate();
  removal_trackers_.push_back(std::move(tracker));
  DestroyTrackers();
}

void FrameSequenceTrackerCollection::ClearAll() {
  frame_trackers_.clear();
  custom_frame_trackers_.clear();
  removal_trackers_.clear();
}

void FrameSequenceTrackerCollection::NotifyBeginImplFrame(
    const viz::BeginFrameArgs& args) {
  RecreateTrackers(args);
  for (auto& tracker : frame_trackers_)
    tracker.second->ReportBeginImplFrame(args);
  for (auto& tracker : custom_frame_trackers_)
    tracker.second->ReportBeginImplFrame(args);
}

void FrameSequenceTrackerCollection::NotifyBeginMainFrame(
    const viz::BeginFrameArgs& args) {
  for (auto& tracker : frame_trackers_)
    tracker.second->ReportBeginMainFrame(args);
  for (auto& tracker : custom_frame_trackers_)
    tracker.second->ReportBeginMainFrame(args);
}

void FrameSequenceTrackerCollection::NotifyMainFrameProcessed(
    const viz::BeginFrameArgs& args) {
  for (auto& tracker : frame_trackers_)
    tracker.second->ReportMainFrameProcessed(args);
  for (auto& tracker : custom_frame_trackers_)
    tracker.second->ReportMainFrameProcessed(args);
}

void FrameSequenceTrackerCollection::NotifyImplFrameCausedNoDamage(
    const viz::BeginFrameAck& ack) {
  for (auto& tracker : frame_trackers_)
    tracker.second->ReportImplFrameCausedNoDamage(ack);
  for (auto& tracker : custom_frame_trackers_)
    tracker.second->ReportImplFrameCausedNoDamage(ack);

  // Removal trackers continue to process any frames which they started
  // observing.
  for (auto& tracker : removal_trackers_)
    tracker->ReportImplFrameCausedNoDamage(ack);
}

void FrameSequenceTrackerCollection::NotifyMainFrameCausedNoDamage(
    const viz::BeginFrameArgs& args) {
  for (auto& tracker : frame_trackers_)
    tracker.second->ReportMainFrameCausedNoDamage(args);
  for (auto& tracker : custom_frame_trackers_)
    tracker.second->ReportMainFrameCausedNoDamage(args);
}

void FrameSequenceTrackerCollection::NotifyPauseFrameProduction() {
  for (auto& tracker : frame_trackers_)
    tracker.second->PauseFrameProduction();
  for (auto& tracker : custom_frame_trackers_)
    tracker.second->PauseFrameProduction();
}

void FrameSequenceTrackerCollection::NotifySubmitFrame(
    uint32_t frame_token,
    bool has_missing_content,
    const viz::BeginFrameAck& ack,
    const viz::BeginFrameArgs& origin_args) {
  for (auto& tracker : frame_trackers_) {
    tracker.second->ReportSubmitFrame(frame_token, has_missing_content, ack,
                                      origin_args);
  }
  for (auto& tracker : custom_frame_trackers_) {
    tracker.second->ReportSubmitFrame(frame_token, has_missing_content, ack,
                                      origin_args);
  }

  // Removal trackers continue to process any frames which they started
  // observing.
  for (auto& tracker : removal_trackers_) {
    tracker->ReportSubmitFrame(frame_token, has_missing_content, ack,
                               origin_args);
  }

  // TODO(crbug.com/1072482): find a proper way to terminate a tracker. Please
  // refer to details in FrameSequenceTracker::ReportSubmitFrame
  DestroyTrackers();
}

void FrameSequenceTrackerCollection::NotifyFrameEnd(
    const viz::BeginFrameArgs& args,
    const viz::BeginFrameArgs& main_args) {
  for (auto& tracker : frame_trackers_)
    tracker.second->ReportFrameEnd(args, main_args);
  for (auto& tracker : custom_frame_trackers_)
    tracker.second->ReportFrameEnd(args, main_args);

  // Removal trackers continue to process any frames which they started
  // observing.
  for (auto& tracker : removal_trackers_)
    tracker->ReportFrameEnd(args, main_args);
  DestroyTrackers();
}

void FrameSequenceTrackerCollection::NotifyFramePresented(
    uint32_t frame_token,
    const gfx::PresentationFeedback& feedback) {
  for (auto& tracker : frame_trackers_)
    tracker.second->ReportFramePresented(frame_token, feedback);
  for (auto& tracker : custom_frame_trackers_)
    tracker.second->ReportFramePresented(frame_token, feedback);
  for (auto& tracker : removal_trackers_)
    tracker->ReportFramePresented(frame_token, feedback);

  DestroyTrackers();
}

bool FrameSequenceTrackerCollection::HasThroughputData() const {
  return throughput_ukm_reporter_ &&
         throughput_ukm_reporter_->HasThroughputData();
}

int FrameSequenceTrackerCollection::TakeLastAggregatedPercent() {
  DCHECK(throughput_ukm_reporter_);
  return throughput_ukm_reporter_->TakeLastAggregatedPercent();
}

int FrameSequenceTrackerCollection::TakeLastImplPercent() {
  DCHECK(throughput_ukm_reporter_);
  return throughput_ukm_reporter_->TakeLastImplPercent();
}

base::Optional<int> FrameSequenceTrackerCollection::TakeLastMainPercent() {
  DCHECK(throughput_ukm_reporter_);
  return throughput_ukm_reporter_->TakeLastMainPercent();
}

base::Optional<int>
FrameSequenceTrackerCollection::CurrentUniversalThroughput() {
  DCHECK(throughput_ukm_reporter_);
  return throughput_ukm_reporter_->current_universal_throughput();
}

void FrameSequenceTrackerCollection::ComputeUniversalThroughputForTesting() {
  DCHECK(throughput_ukm_reporter_);
  const auto type = FrameSequenceTrackerType::kUniversal;
  auto key = std::make_pair(type, ThreadType::kUnknown);
  DCHECK(frame_trackers_.contains(key));
  throughput_ukm_reporter_->ComputeUniversalThroughput(
      frame_trackers_[key]->metrics());
}

void FrameSequenceTrackerCollection::DestroyTrackers() {
  for (auto& tracker : removal_trackers_) {
    if (tracker->termination_status() ==
        FrameSequenceTracker::TerminationStatus::kReadyForTermination) {
      // The tracker is ready to be terminated.
      // For non kCustom typed trackers, take the metrics from the tracker.
      // merge with any outstanding metrics from previous trackers of the same
      // type. If there are enough frames to report the metrics, then report the
      // metrics and destroy it. Otherwise, retain it to be merged with
      // follow-up sequences.
      // For kCustom typed trackers, |metrics| invokes AddCustomTrackerResult
      // on its destruction, which add its data to |custom_tracker_results_|
      // to be picked up by caller.
      auto metrics = tracker->TakeMetrics();
      if (metrics->type() == FrameSequenceTrackerType::kCustom)
        continue;

      auto key = std::make_pair(metrics->type(), metrics->GetEffectiveThread());
      if (accumulated_metrics_.contains(key)) {
        metrics->Merge(std::move(accumulated_metrics_[key]));
        accumulated_metrics_.erase(key);
      }

      if (metrics->HasEnoughDataForReporting()) {
        // Do this before ReportMetrics() which clears the throughput data.
        if (metrics->type() == FrameSequenceTrackerType::kUniversal)
          throughput_ukm_reporter_->ComputeUniversalThroughput(metrics.get());
        metrics->ReportMetrics();
      }
      if (metrics->HasDataLeftForReporting()) {
        accumulated_metrics_[key] = std::move(metrics);
      }
    }
  }

  base::EraseIf(
      removal_trackers_,
      [](const std::unique_ptr<FrameSequenceTracker>& tracker) {
        return tracker->termination_status() ==
               FrameSequenceTracker::TerminationStatus::kReadyForTermination;
      });
}

void FrameSequenceTrackerCollection::RecreateTrackers(
    const viz::BeginFrameArgs& args) {
  std::vector<std::pair<FrameSequenceTrackerType, ThreadType>>
      recreate_trackers;
  for (const auto& tracker : frame_trackers_) {
    if (tracker.second->ShouldReportMetricsNow(args))
      recreate_trackers.push_back(tracker.first);
  }

  for (const auto& key : recreate_trackers) {
    DCHECK(frame_trackers_[key]);
    auto tracker_type = key.first;
    ThreadType thread_type = key.second;

    // StopSequence put the tracker in the |removal_trackers_|, which will
    // report its throughput data when its frame is presented.
    StopSequence(tracker_type);

    // The frame sequence is still active, so create a new tracker to keep
    // tracking this sequence.
    if (thread_type != FrameSequenceMetrics::ThreadType::kUnknown) {
      DCHECK(IsScrollType(tracker_type));
      StartScrollSequence(tracker_type, thread_type);
    } else {
      StartSequence(tracker_type);
    }
  }
}

ActiveFrameSequenceTrackers
FrameSequenceTrackerCollection::FrameSequenceTrackerActiveTypes() {
  ActiveFrameSequenceTrackers encoded_types = 0;
  for (const auto& key : frame_trackers_) {
    auto thread_type = key.first.first;
    encoded_types |= static_cast<ActiveFrameSequenceTrackers>(
        1 << static_cast<unsigned>(thread_type));
  }
  return encoded_types;
}

CustomTrackerResults
FrameSequenceTrackerCollection::TakeCustomTrackerResults() {
  CustomTrackerResults results;
  results.swap(custom_tracker_results_);
  return results;
}

FrameSequenceTracker*
FrameSequenceTrackerCollection::GetRemovalTrackerForTesting(
    FrameSequenceTrackerType type) {
  for (const auto& tracker : removal_trackers_)
    if (tracker->type() == type)
      return tracker.get();
  return nullptr;
}

void FrameSequenceTrackerCollection::SetUkmManager(UkmManager* manager) {
  DCHECK(frame_trackers_.empty());
  if (manager)
    throughput_ukm_reporter_ = std::make_unique<ThroughputUkmReporter>(manager);
  else
    throughput_ukm_reporter_ = nullptr;
}

void FrameSequenceTrackerCollection::AddCustomTrackerResult(
    int custom_sequence_id,
    FrameSequenceMetrics::ThroughputData throughput_data) {
  // |custom_tracker_results_| should be picked up timely.
  DCHECK_LT(custom_tracker_results_.size(), 500u);
  custom_tracker_results_[custom_sequence_id] = std::move(throughput_data);
}

}  // namespace cc
