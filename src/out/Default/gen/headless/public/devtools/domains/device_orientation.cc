// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/device_orientation.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace device_orientation {

ExperimentalDomain* Domain::GetExperimental() {
  return static_cast<ExperimentalDomain*>(this);
}


void ExperimentalDomain::ClearDeviceOrientationOverride(std::unique_ptr<ClearDeviceOrientationOverrideParams> params, base::OnceCallback<void(std::unique_ptr<ClearDeviceOrientationOverrideResult>)> callback) {
  dispatcher_->SendMessage("DeviceOrientation.clearDeviceOrientationOverride", params->Serialize(), base::BindOnce(&Domain::HandleClearDeviceOrientationOverrideResponse, std::move(callback)));
}
void ExperimentalDomain::SetDeviceOrientationOverride(std::unique_ptr<SetDeviceOrientationOverrideParams> params, base::OnceCallback<void(std::unique_ptr<SetDeviceOrientationOverrideResult>)> callback) {
  dispatcher_->SendMessage("DeviceOrientation.setDeviceOrientationOverride", params->Serialize(), base::BindOnce(&Domain::HandleSetDeviceOrientationOverrideResponse, std::move(callback)));
}


// static
void Domain::HandleClearDeviceOrientationOverrideResponse(base::OnceCallback<void(std::unique_ptr<ClearDeviceOrientationOverrideResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ClearDeviceOrientationOverrideResult> result = ClearDeviceOrientationOverrideResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetDeviceOrientationOverrideResponse(base::OnceCallback<void(std::unique_ptr<SetDeviceOrientationOverrideResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetDeviceOrientationOverrideResult> result = SetDeviceOrientationOverrideResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

Domain::Domain(internal::MessageDispatcher* dispatcher)
    : dispatcher_(dispatcher) {
}

Domain::~Domain() {}

ExperimentalDomain::ExperimentalDomain(internal::MessageDispatcher* dispatcher)
    : Domain(dispatcher) {}

ExperimentalDomain::~ExperimentalDomain() {}


}  // namespace device_orientation

} // namespace headless
