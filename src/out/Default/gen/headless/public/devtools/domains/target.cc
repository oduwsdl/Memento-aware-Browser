// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/target.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace target {

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
      "Target.attachedToTarget",
      base::BindRepeating(&Domain::DispatchAttachedToTargetEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Target.detachedFromTarget",
      base::BindRepeating(&Domain::DispatchDetachedFromTargetEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Target.receivedMessageFromTarget",
      base::BindRepeating(&Domain::DispatchReceivedMessageFromTargetEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Target.targetCreated",
      base::BindRepeating(&Domain::DispatchTargetCreatedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Target.targetDestroyed",
      base::BindRepeating(&Domain::DispatchTargetDestroyedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Target.targetCrashed",
      base::BindRepeating(&Domain::DispatchTargetCrashedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Target.targetInfoChanged",
      base::BindRepeating(&Domain::DispatchTargetInfoChangedEvent,
                          base::Unretained(this)));
}

void Domain::ActivateTarget(std::unique_ptr<ActivateTargetParams> params, base::OnceCallback<void(std::unique_ptr<ActivateTargetResult>)> callback) {
  dispatcher_->SendMessage("Target.activateTarget", params->Serialize(), base::BindOnce(&Domain::HandleActivateTargetResponse, std::move(callback)));
}

void Domain::ActivateTarget(const std::string& target_id, base::OnceClosure callback) {
  std::unique_ptr<ActivateTargetParams> params = ActivateTargetParams::Builder()
      .SetTargetId(std::move(target_id))
      .Build();
  dispatcher_->SendMessage("Target.activateTarget", params->Serialize(), std::move(callback));
}
void Domain::ActivateTarget(std::unique_ptr<ActivateTargetParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Target.activateTarget", params->Serialize(), std::move(callback));
}
void Domain::AttachToTarget(std::unique_ptr<AttachToTargetParams> params, base::OnceCallback<void(std::unique_ptr<AttachToTargetResult>)> callback) {
  dispatcher_->SendMessage("Target.attachToTarget", params->Serialize(), base::BindOnce(&Domain::HandleAttachToTargetResponse, std::move(callback)));
}

void Domain::AttachToTarget(const std::string& target_id, base::OnceCallback<void(std::unique_ptr<AttachToTargetResult>)> callback) {
  std::unique_ptr<AttachToTargetParams> params = AttachToTargetParams::Builder()
      .SetTargetId(std::move(target_id))
      .Build();
dispatcher_->SendMessage("Target.attachToTarget", params->Serialize(), base::BindOnce(&Domain::HandleAttachToTargetResponse, std::move(callback)));
}
void ExperimentalDomain::AttachToBrowserTarget(std::unique_ptr<AttachToBrowserTargetParams> params, base::OnceCallback<void(std::unique_ptr<AttachToBrowserTargetResult>)> callback) {
  dispatcher_->SendMessage("Target.attachToBrowserTarget", params->Serialize(), base::BindOnce(&Domain::HandleAttachToBrowserTargetResponse, std::move(callback)));
}
void Domain::CloseTarget(std::unique_ptr<CloseTargetParams> params, base::OnceCallback<void(std::unique_ptr<CloseTargetResult>)> callback) {
  dispatcher_->SendMessage("Target.closeTarget", params->Serialize(), base::BindOnce(&Domain::HandleCloseTargetResponse, std::move(callback)));
}

void Domain::CloseTarget(const std::string& target_id, base::OnceCallback<void(std::unique_ptr<CloseTargetResult>)> callback) {
  std::unique_ptr<CloseTargetParams> params = CloseTargetParams::Builder()
      .SetTargetId(std::move(target_id))
      .Build();
dispatcher_->SendMessage("Target.closeTarget", params->Serialize(), base::BindOnce(&Domain::HandleCloseTargetResponse, std::move(callback)));
}
void ExperimentalDomain::ExposeDevToolsProtocol(std::unique_ptr<ExposeDevToolsProtocolParams> params, base::OnceCallback<void(std::unique_ptr<ExposeDevToolsProtocolResult>)> callback) {
  dispatcher_->SendMessage("Target.exposeDevToolsProtocol", params->Serialize(), base::BindOnce(&Domain::HandleExposeDevToolsProtocolResponse, std::move(callback)));
}
void ExperimentalDomain::CreateBrowserContext(std::unique_ptr<CreateBrowserContextParams> params, base::OnceCallback<void(std::unique_ptr<CreateBrowserContextResult>)> callback) {
  dispatcher_->SendMessage("Target.createBrowserContext", params->Serialize(), base::BindOnce(&Domain::HandleCreateBrowserContextResponse, std::move(callback)));
}
void ExperimentalDomain::GetBrowserContexts(std::unique_ptr<GetBrowserContextsParams> params, base::OnceCallback<void(std::unique_ptr<GetBrowserContextsResult>)> callback) {
  dispatcher_->SendMessage("Target.getBrowserContexts", params->Serialize(), base::BindOnce(&Domain::HandleGetBrowserContextsResponse, std::move(callback)));
}
void Domain::CreateTarget(std::unique_ptr<CreateTargetParams> params, base::OnceCallback<void(std::unique_ptr<CreateTargetResult>)> callback) {
  dispatcher_->SendMessage("Target.createTarget", params->Serialize(), base::BindOnce(&Domain::HandleCreateTargetResponse, std::move(callback)));
}

void Domain::CreateTarget(const std::string& url, base::OnceCallback<void(std::unique_ptr<CreateTargetResult>)> callback) {
  std::unique_ptr<CreateTargetParams> params = CreateTargetParams::Builder()
      .SetUrl(std::move(url))
      .Build();
dispatcher_->SendMessage("Target.createTarget", params->Serialize(), base::BindOnce(&Domain::HandleCreateTargetResponse, std::move(callback)));
}
void Domain::DetachFromTarget(std::unique_ptr<DetachFromTargetParams> params, base::OnceCallback<void(std::unique_ptr<DetachFromTargetResult>)> callback) {
  dispatcher_->SendMessage("Target.detachFromTarget", params->Serialize(), base::BindOnce(&Domain::HandleDetachFromTargetResponse, std::move(callback)));
}

void Domain::DetachFromTarget(base::OnceClosure callback) {
  std::unique_ptr<DetachFromTargetParams> params = DetachFromTargetParams::Builder()
      .Build();
  dispatcher_->SendMessage("Target.detachFromTarget", params->Serialize(), std::move(callback));
}
void Domain::DetachFromTarget(std::unique_ptr<DetachFromTargetParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Target.detachFromTarget", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::DisposeBrowserContext(std::unique_ptr<DisposeBrowserContextParams> params, base::OnceCallback<void(std::unique_ptr<DisposeBrowserContextResult>)> callback) {
  dispatcher_->SendMessage("Target.disposeBrowserContext", params->Serialize(), base::BindOnce(&Domain::HandleDisposeBrowserContextResponse, std::move(callback)));
}
void ExperimentalDomain::GetTargetInfo(std::unique_ptr<GetTargetInfoParams> params, base::OnceCallback<void(std::unique_ptr<GetTargetInfoResult>)> callback) {
  dispatcher_->SendMessage("Target.getTargetInfo", params->Serialize(), base::BindOnce(&Domain::HandleGetTargetInfoResponse, std::move(callback)));
}
void Domain::GetTargets(std::unique_ptr<GetTargetsParams> params, base::OnceCallback<void(std::unique_ptr<GetTargetsResult>)> callback) {
  dispatcher_->SendMessage("Target.getTargets", params->Serialize(), base::BindOnce(&Domain::HandleGetTargetsResponse, std::move(callback)));
}

void Domain::GetTargets(base::OnceCallback<void(std::unique_ptr<GetTargetsResult>)> callback) {
  std::unique_ptr<GetTargetsParams> params = GetTargetsParams::Builder()
      .Build();
dispatcher_->SendMessage("Target.getTargets", params->Serialize(), base::BindOnce(&Domain::HandleGetTargetsResponse, std::move(callback)));
}
void Domain::SendMessageToTarget(std::unique_ptr<SendMessageToTargetParams> params, base::OnceCallback<void(std::unique_ptr<SendMessageToTargetResult>)> callback) {
  dispatcher_->SendMessage("Target.sendMessageToTarget", params->Serialize(), base::BindOnce(&Domain::HandleSendMessageToTargetResponse, std::move(callback)));
}

void Domain::SendMessageToTarget(const std::string& message, base::OnceClosure callback) {
  std::unique_ptr<SendMessageToTargetParams> params = SendMessageToTargetParams::Builder()
      .SetMessage(std::move(message))
      .Build();
  dispatcher_->SendMessage("Target.sendMessageToTarget", params->Serialize(), std::move(callback));
}
void Domain::SendMessageToTarget(std::unique_ptr<SendMessageToTargetParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Target.sendMessageToTarget", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::SetAutoAttach(std::unique_ptr<SetAutoAttachParams> params, base::OnceCallback<void(std::unique_ptr<SetAutoAttachResult>)> callback) {
  dispatcher_->SendMessage("Target.setAutoAttach", params->Serialize(), base::BindOnce(&Domain::HandleSetAutoAttachResponse, std::move(callback)));
}
void Domain::SetDiscoverTargets(std::unique_ptr<SetDiscoverTargetsParams> params, base::OnceCallback<void(std::unique_ptr<SetDiscoverTargetsResult>)> callback) {
  dispatcher_->SendMessage("Target.setDiscoverTargets", params->Serialize(), base::BindOnce(&Domain::HandleSetDiscoverTargetsResponse, std::move(callback)));
}

void Domain::SetDiscoverTargets(bool discover, base::OnceClosure callback) {
  std::unique_ptr<SetDiscoverTargetsParams> params = SetDiscoverTargetsParams::Builder()
      .SetDiscover(std::move(discover))
      .Build();
  dispatcher_->SendMessage("Target.setDiscoverTargets", params->Serialize(), std::move(callback));
}
void Domain::SetDiscoverTargets(std::unique_ptr<SetDiscoverTargetsParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Target.setDiscoverTargets", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::SetRemoteLocations(std::unique_ptr<SetRemoteLocationsParams> params, base::OnceCallback<void(std::unique_ptr<SetRemoteLocationsResult>)> callback) {
  dispatcher_->SendMessage("Target.setRemoteLocations", params->Serialize(), base::BindOnce(&Domain::HandleSetRemoteLocationsResponse, std::move(callback)));
}


// static
void Domain::HandleActivateTargetResponse(base::OnceCallback<void(std::unique_ptr<ActivateTargetResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ActivateTargetResult> result = ActivateTargetResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleAttachToTargetResponse(base::OnceCallback<void(std::unique_ptr<AttachToTargetResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<AttachToTargetResult> result = AttachToTargetResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleAttachToBrowserTargetResponse(base::OnceCallback<void(std::unique_ptr<AttachToBrowserTargetResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<AttachToBrowserTargetResult> result = AttachToBrowserTargetResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleCloseTargetResponse(base::OnceCallback<void(std::unique_ptr<CloseTargetResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<CloseTargetResult> result = CloseTargetResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleExposeDevToolsProtocolResponse(base::OnceCallback<void(std::unique_ptr<ExposeDevToolsProtocolResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ExposeDevToolsProtocolResult> result = ExposeDevToolsProtocolResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleCreateBrowserContextResponse(base::OnceCallback<void(std::unique_ptr<CreateBrowserContextResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<CreateBrowserContextResult> result = CreateBrowserContextResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetBrowserContextsResponse(base::OnceCallback<void(std::unique_ptr<GetBrowserContextsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetBrowserContextsResult> result = GetBrowserContextsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleCreateTargetResponse(base::OnceCallback<void(std::unique_ptr<CreateTargetResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<CreateTargetResult> result = CreateTargetResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleDetachFromTargetResponse(base::OnceCallback<void(std::unique_ptr<DetachFromTargetResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DetachFromTargetResult> result = DetachFromTargetResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleDisposeBrowserContextResponse(base::OnceCallback<void(std::unique_ptr<DisposeBrowserContextResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DisposeBrowserContextResult> result = DisposeBrowserContextResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetTargetInfoResponse(base::OnceCallback<void(std::unique_ptr<GetTargetInfoResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetTargetInfoResult> result = GetTargetInfoResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetTargetsResponse(base::OnceCallback<void(std::unique_ptr<GetTargetsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetTargetsResult> result = GetTargetsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSendMessageToTargetResponse(base::OnceCallback<void(std::unique_ptr<SendMessageToTargetResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SendMessageToTargetResult> result = SendMessageToTargetResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetAutoAttachResponse(base::OnceCallback<void(std::unique_ptr<SetAutoAttachResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetAutoAttachResult> result = SetAutoAttachResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetDiscoverTargetsResponse(base::OnceCallback<void(std::unique_ptr<SetDiscoverTargetsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetDiscoverTargetsResult> result = SetDiscoverTargetsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetRemoteLocationsResponse(base::OnceCallback<void(std::unique_ptr<SetRemoteLocationsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetRemoteLocationsResult> result = SetRemoteLocationsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchAttachedToTargetEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<AttachedToTargetParams> parsed_params(AttachedToTargetParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnAttachedToTarget(*parsed_params);
  }
}

void Domain::DispatchDetachedFromTargetEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<DetachedFromTargetParams> parsed_params(DetachedFromTargetParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnDetachedFromTarget(*parsed_params);
  }
}

void Domain::DispatchReceivedMessageFromTargetEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ReceivedMessageFromTargetParams> parsed_params(ReceivedMessageFromTargetParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnReceivedMessageFromTarget(*parsed_params);
  }
}

void Domain::DispatchTargetCreatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<TargetCreatedParams> parsed_params(TargetCreatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnTargetCreated(*parsed_params);
  }
}

void Domain::DispatchTargetDestroyedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<TargetDestroyedParams> parsed_params(TargetDestroyedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnTargetDestroyed(*parsed_params);
  }
}

void Domain::DispatchTargetCrashedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<TargetCrashedParams> parsed_params(TargetCrashedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnTargetCrashed(*parsed_params);
  }
}

void Domain::DispatchTargetInfoChangedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<TargetInfoChangedParams> parsed_params(TargetInfoChangedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnTargetInfoChanged(*parsed_params);
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

}  // namespace target

} // namespace headless
