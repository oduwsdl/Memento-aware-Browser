// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/indexeddb.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace indexeddb {

ExperimentalDomain* Domain::GetExperimental() {
  return static_cast<ExperimentalDomain*>(this);
}


void ExperimentalDomain::ClearObjectStore(std::unique_ptr<ClearObjectStoreParams> params, base::OnceCallback<void(std::unique_ptr<ClearObjectStoreResult>)> callback) {
  dispatcher_->SendMessage("IndexedDB.clearObjectStore", params->Serialize(), base::BindOnce(&Domain::HandleClearObjectStoreResponse, std::move(callback)));
}
void ExperimentalDomain::DeleteDatabase(std::unique_ptr<DeleteDatabaseParams> params, base::OnceCallback<void(std::unique_ptr<DeleteDatabaseResult>)> callback) {
  dispatcher_->SendMessage("IndexedDB.deleteDatabase", params->Serialize(), base::BindOnce(&Domain::HandleDeleteDatabaseResponse, std::move(callback)));
}
void ExperimentalDomain::DeleteObjectStoreEntries(std::unique_ptr<DeleteObjectStoreEntriesParams> params, base::OnceCallback<void(std::unique_ptr<DeleteObjectStoreEntriesResult>)> callback) {
  dispatcher_->SendMessage("IndexedDB.deleteObjectStoreEntries", params->Serialize(), base::BindOnce(&Domain::HandleDeleteObjectStoreEntriesResponse, std::move(callback)));
}
void ExperimentalDomain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("IndexedDB.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}
void ExperimentalDomain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("IndexedDB.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}
void ExperimentalDomain::RequestData(std::unique_ptr<RequestDataParams> params, base::OnceCallback<void(std::unique_ptr<RequestDataResult>)> callback) {
  dispatcher_->SendMessage("IndexedDB.requestData", params->Serialize(), base::BindOnce(&Domain::HandleRequestDataResponse, std::move(callback)));
}
void ExperimentalDomain::GetMetadata(std::unique_ptr<GetMetadataParams> params, base::OnceCallback<void(std::unique_ptr<GetMetadataResult>)> callback) {
  dispatcher_->SendMessage("IndexedDB.getMetadata", params->Serialize(), base::BindOnce(&Domain::HandleGetMetadataResponse, std::move(callback)));
}
void ExperimentalDomain::RequestDatabase(std::unique_ptr<RequestDatabaseParams> params, base::OnceCallback<void(std::unique_ptr<RequestDatabaseResult>)> callback) {
  dispatcher_->SendMessage("IndexedDB.requestDatabase", params->Serialize(), base::BindOnce(&Domain::HandleRequestDatabaseResponse, std::move(callback)));
}
void ExperimentalDomain::RequestDatabaseNames(std::unique_ptr<RequestDatabaseNamesParams> params, base::OnceCallback<void(std::unique_ptr<RequestDatabaseNamesResult>)> callback) {
  dispatcher_->SendMessage("IndexedDB.requestDatabaseNames", params->Serialize(), base::BindOnce(&Domain::HandleRequestDatabaseNamesResponse, std::move(callback)));
}


// static
void Domain::HandleClearObjectStoreResponse(base::OnceCallback<void(std::unique_ptr<ClearObjectStoreResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ClearObjectStoreResult> result = ClearObjectStoreResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleDeleteDatabaseResponse(base::OnceCallback<void(std::unique_ptr<DeleteDatabaseResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DeleteDatabaseResult> result = DeleteDatabaseResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleDeleteObjectStoreEntriesResponse(base::OnceCallback<void(std::unique_ptr<DeleteObjectStoreEntriesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DeleteObjectStoreEntriesResult> result = DeleteObjectStoreEntriesResult::Parse(response, &errors);
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
void Domain::HandleRequestDataResponse(base::OnceCallback<void(std::unique_ptr<RequestDataResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<RequestDataResult> result = RequestDataResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetMetadataResponse(base::OnceCallback<void(std::unique_ptr<GetMetadataResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetMetadataResult> result = GetMetadataResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleRequestDatabaseResponse(base::OnceCallback<void(std::unique_ptr<RequestDatabaseResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<RequestDatabaseResult> result = RequestDatabaseResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleRequestDatabaseNamesResponse(base::OnceCallback<void(std::unique_ptr<RequestDatabaseNamesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<RequestDatabaseNamesResult> result = RequestDatabaseNamesResult::Parse(response, &errors);
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


}  // namespace indexeddb

} // namespace headless
