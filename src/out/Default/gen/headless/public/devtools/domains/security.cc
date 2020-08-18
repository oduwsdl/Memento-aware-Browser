// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/security.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace security {

ExperimentalDomain* Domain::GetExperimental() {
  return static_cast<ExperimentalDomain*>(this);
}

void Domain::AddObserver(Observer* observer) {
  RegisterEventHandlersIfNeeded();
  observers_.AddObserver(observer);
}

void Domain::RemoveObserver(Observer* observer) {
  observers_.RemoveObserver(observer);
}

void Domain::RegisterEventHandlersIfNeeded() {
  if (event_handlers_registered_)
    return;
  event_handlers_registered_ = true;
  dispatcher_->RegisterEventHandler(
      "Security.certificateError",
      base::BindRepeating(&Domain::DispatchCertificateErrorEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Security.visibleSecurityStateChanged",
      base::BindRepeating(&Domain::DispatchVisibleSecurityStateChangedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Security.securityStateChanged",
      base::BindRepeating(&Domain::DispatchSecurityStateChangedEvent,
                          base::Unretained(this)));
}

void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("Security.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}

void Domain::Disable(base::OnceClosure callback) {
  std::unique_ptr<DisableParams> params = DisableParams::Builder()
      .Build();
  dispatcher_->SendMessage("Security.disable", params->Serialize(), std::move(callback));
}
void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Security.disable", params->Serialize(), std::move(callback));
}
void Domain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("Security.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}

void Domain::Enable(base::OnceClosure callback) {
  std::unique_ptr<EnableParams> params = EnableParams::Builder()
      .Build();
  dispatcher_->SendMessage("Security.enable", params->Serialize(), std::move(callback));
}
void Domain::Enable(std::unique_ptr<EnableParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Security.enable", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::SetIgnoreCertificateErrors(std::unique_ptr<SetIgnoreCertificateErrorsParams> params, base::OnceCallback<void(std::unique_ptr<SetIgnoreCertificateErrorsResult>)> callback) {
  dispatcher_->SendMessage("Security.setIgnoreCertificateErrors", params->Serialize(), base::BindOnce(&Domain::HandleSetIgnoreCertificateErrorsResponse, std::move(callback)));
}
void Domain::HandleCertificateError(std::unique_ptr<HandleCertificateErrorParams> params, base::OnceCallback<void(std::unique_ptr<HandleCertificateErrorResult>)> callback) {
  dispatcher_->SendMessage("Security.handleCertificateError", params->Serialize(), base::BindOnce(&Domain::HandleHandleCertificateErrorResponse, std::move(callback)));
}

void Domain::HandleCertificateError(int event_id, ::headless::security::CertificateErrorAction action, base::OnceClosure callback) {
  std::unique_ptr<HandleCertificateErrorParams> params = HandleCertificateErrorParams::Builder()
      .SetEventId(std::move(event_id))
      .SetAction(std::move(action))
      .Build();
  dispatcher_->SendMessage("Security.handleCertificateError", params->Serialize(), std::move(callback));
}
void Domain::HandleCertificateError(std::unique_ptr<HandleCertificateErrorParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Security.handleCertificateError", params->Serialize(), std::move(callback));
}
void Domain::SetOverrideCertificateErrors(std::unique_ptr<SetOverrideCertificateErrorsParams> params, base::OnceCallback<void(std::unique_ptr<SetOverrideCertificateErrorsResult>)> callback) {
  dispatcher_->SendMessage("Security.setOverrideCertificateErrors", params->Serialize(), base::BindOnce(&Domain::HandleSetOverrideCertificateErrorsResponse, std::move(callback)));
}

void Domain::SetOverrideCertificateErrors(bool override, base::OnceClosure callback) {
  std::unique_ptr<SetOverrideCertificateErrorsParams> params = SetOverrideCertificateErrorsParams::Builder()
      .SetOverride(std::move(override))
      .Build();
  dispatcher_->SendMessage("Security.setOverrideCertificateErrors", params->Serialize(), std::move(callback));
}
void Domain::SetOverrideCertificateErrors(std::unique_ptr<SetOverrideCertificateErrorsParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Security.setOverrideCertificateErrors", params->Serialize(), std::move(callback));
}


// static
void Domain::HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = DisableResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = EnableResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetIgnoreCertificateErrorsResponse(base::OnceCallback<void(std::unique_ptr<SetIgnoreCertificateErrorsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetIgnoreCertificateErrorsResult> result = SetIgnoreCertificateErrorsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleHandleCertificateErrorResponse(base::OnceCallback<void(std::unique_ptr<HandleCertificateErrorResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<HandleCertificateErrorResult> result = HandleCertificateErrorResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetOverrideCertificateErrorsResponse(base::OnceCallback<void(std::unique_ptr<SetOverrideCertificateErrorsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetOverrideCertificateErrorsResult> result = SetOverrideCertificateErrorsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchCertificateErrorEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<CertificateErrorParams> parsed_params(CertificateErrorParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnCertificateError(*parsed_params);
  }
}

void Domain::DispatchVisibleSecurityStateChangedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<VisibleSecurityStateChangedParams> parsed_params(VisibleSecurityStateChangedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnVisibleSecurityStateChanged(*parsed_params);
  }
}

void Domain::DispatchSecurityStateChangedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<SecurityStateChangedParams> parsed_params(SecurityStateChangedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnSecurityStateChanged(*parsed_params);
  }
}

Domain::Domain(internal::MessageDispatcher* dispatcher)
    : dispatcher_(dispatcher) {
}

Domain::~Domain() {}

ExperimentalDomain::ExperimentalDomain(internal::MessageDispatcher* dispatcher)
    : Domain(dispatcher) {}

ExperimentalDomain::~ExperimentalDomain() {}

void ExperimentalDomain::AddObserver(ExperimentalObserver* observer) {
  RegisterEventHandlersIfNeeded();
  observers_.AddObserver(observer);
}

void ExperimentalDomain::RemoveObserver(ExperimentalObserver* observer) {
  observers_.RemoveObserver(observer);
}

}  // namespace security

} // namespace headless
