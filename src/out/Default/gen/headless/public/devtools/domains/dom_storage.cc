// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/dom_storage.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace dom_storage {

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
      "DOMStorage.domStorageItemAdded",
      base::BindRepeating(&Domain::DispatchDomStorageItemAddedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "DOMStorage.domStorageItemRemoved",
      base::BindRepeating(&Domain::DispatchDomStorageItemRemovedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "DOMStorage.domStorageItemUpdated",
      base::BindRepeating(&Domain::DispatchDomStorageItemUpdatedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "DOMStorage.domStorageItemsCleared",
      base::BindRepeating(&Domain::DispatchDomStorageItemsClearedEvent,
                          base::Unretained(this)));
}

void ExperimentalDomain::Clear(std::unique_ptr<ClearParams> params, base::OnceCallback<void(std::unique_ptr<ClearResult>)> callback) {
  dispatcher_->SendMessage("DOMStorage.clear", params->Serialize(), base::BindOnce(&Domain::HandleClearResponse, std::move(callback)));
}
void ExperimentalDomain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("DOMStorage.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}
void ExperimentalDomain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("DOMStorage.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}
void ExperimentalDomain::GetDOMStorageItems(std::unique_ptr<GetDOMStorageItemsParams> params, base::OnceCallback<void(std::unique_ptr<GetDOMStorageItemsResult>)> callback) {
  dispatcher_->SendMessage("DOMStorage.getDOMStorageItems", params->Serialize(), base::BindOnce(&Domain::HandleGetDOMStorageItemsResponse, std::move(callback)));
}
void ExperimentalDomain::RemoveDOMStorageItem(std::unique_ptr<RemoveDOMStorageItemParams> params, base::OnceCallback<void(std::unique_ptr<RemoveDOMStorageItemResult>)> callback) {
  dispatcher_->SendMessage("DOMStorage.removeDOMStorageItem", params->Serialize(), base::BindOnce(&Domain::HandleRemoveDOMStorageItemResponse, std::move(callback)));
}
void ExperimentalDomain::SetDOMStorageItem(std::unique_ptr<SetDOMStorageItemParams> params, base::OnceCallback<void(std::unique_ptr<SetDOMStorageItemResult>)> callback) {
  dispatcher_->SendMessage("DOMStorage.setDOMStorageItem", params->Serialize(), base::BindOnce(&Domain::HandleSetDOMStorageItemResponse, std::move(callback)));
}


// static
void Domain::HandleClearResponse(base::OnceCallback<void(std::unique_ptr<ClearResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ClearResult> result = ClearResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
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
void Domain::HandleGetDOMStorageItemsResponse(base::OnceCallback<void(std::unique_ptr<GetDOMStorageItemsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetDOMStorageItemsResult> result = GetDOMStorageItemsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleRemoveDOMStorageItemResponse(base::OnceCallback<void(std::unique_ptr<RemoveDOMStorageItemResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<RemoveDOMStorageItemResult> result = RemoveDOMStorageItemResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetDOMStorageItemResponse(base::OnceCallback<void(std::unique_ptr<SetDOMStorageItemResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetDOMStorageItemResult> result = SetDOMStorageItemResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchDomStorageItemAddedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<DomStorageItemAddedParams> parsed_params(DomStorageItemAddedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnDomStorageItemAdded(*parsed_params);
  }
}

void Domain::DispatchDomStorageItemRemovedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<DomStorageItemRemovedParams> parsed_params(DomStorageItemRemovedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnDomStorageItemRemoved(*parsed_params);
  }
}

void Domain::DispatchDomStorageItemUpdatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<DomStorageItemUpdatedParams> parsed_params(DomStorageItemUpdatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnDomStorageItemUpdated(*parsed_params);
  }
}

void Domain::DispatchDomStorageItemsClearedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<DomStorageItemsClearedParams> parsed_params(DomStorageItemsClearedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnDomStorageItemsCleared(*parsed_params);
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

}  // namespace dom_storage

} // namespace headless
