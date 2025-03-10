// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/modules/peerconnection/thermal_resource.h"

#include "third_party/webrtc/rtc_base/ref_counted_object.h"

namespace blink {

namespace {

const int kReportIntervalSeconds = 10;

}  // namespace

// static
scoped_refptr<ThermalResource> ThermalResource::Create(
    scoped_refptr<base::SequencedTaskRunner> task_runner) {
  return new rtc::RefCountedObject<ThermalResource>(std::move(task_runner));
}

ThermalResource::ThermalResource(
    scoped_refptr<base::SequencedTaskRunner> task_runner)
    : task_runner_(std::move(task_runner)) {}

void ThermalResource::OnThermalMeasurement(
    base::PowerObserver::DeviceThermalState measurement) {
  base::AutoLock auto_lock(lock_);
  measurement_ = measurement;
  ++measurement_id_;
  ReportMeasurementWhileHoldingLock(measurement_id_);
}

std::string ThermalResource::Name() const {
  return "ThermalResource";
}

void ThermalResource::SetResourceListener(webrtc::ResourceListener* listener) {
  base::AutoLock auto_lock(lock_);
  listener_ = listener;
  if (listener_ &&
      measurement_ != base::PowerObserver::DeviceThermalState::kUnknown) {
    ReportMeasurementWhileHoldingLock(measurement_id_);
  }
}

void ThermalResource::ReportMeasurement(size_t measurement_id) {
  base::AutoLock auto_lock(lock_);
  ReportMeasurementWhileHoldingLock(measurement_id);
}

// EXCLUSIVE_LOCKS_REQUIRED(&lock_)
void ThermalResource::ReportMeasurementWhileHoldingLock(size_t measurement_id) {
  // Stop repeating measurements if the measurement was invalidated or we don't
  // have a listtener.
  if (measurement_id != measurement_id_ || !listener_)
    return;
  switch (measurement_) {
    case base::PowerObserver::DeviceThermalState::kUnknown:
      // Stop repeating measurements.
      return;
    case base::PowerObserver::DeviceThermalState::kNominal:
    case base::PowerObserver::DeviceThermalState::kFair:
      listener_->OnResourceUsageStateMeasured(
          this, webrtc::ResourceUsageState::kUnderuse);
      break;
    case base::PowerObserver::DeviceThermalState::kSerious:
    case base::PowerObserver::DeviceThermalState::kCritical:
      listener_->OnResourceUsageStateMeasured(
          this, webrtc::ResourceUsageState::kOveruse);
      break;
  }
  // Repeat the reporting every 10 seconds until a new measurement is made or
  // the listener is unregistered.
  task_runner_->PostDelayedTask(
      FROM_HERE,
      base::BindOnce(&ThermalResource::ReportMeasurement,
                     scoped_refptr<ThermalResource>(this), measurement_id),
      base::TimeDelta::FromSeconds(kReportIntervalSeconds));
}

}  // namespace blink
