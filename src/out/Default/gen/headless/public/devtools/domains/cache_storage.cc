// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/cache_storage.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace cache_storage {

ExperimentalDomain* Domain::GetExperimental() {
  return static_cast<ExperimentalDomain*>(this);
}


void ExperimentalDomain::DeleteCache(std::unique_ptr<DeleteCacheParams> params, base::OnceCallback<void(std::unique_ptr<DeleteCacheResult>)> callback) {
  dispatcher_->SendMessage("CacheStorage.deleteCache", params->Serialize(), base::BindOnce(&Domain::HandleDeleteCacheResponse, std::move(callback)));
}
void ExperimentalDomain::DeleteEntry(std::unique_ptr<DeleteEntryParams> params, base::OnceCallback<void(std::unique_ptr<DeleteEntryResult>)> callback) {
  dispatcher_->SendMessage("CacheStorage.deleteEntry", params->Serialize(), base::BindOnce(&Domain::HandleDeleteEntryResponse, std::move(callback)));
}
void ExperimentalDomain::RequestCacheNames(std::unique_ptr<RequestCacheNamesParams> params, base::OnceCallback<void(std::unique_ptr<RequestCacheNamesResult>)> callback) {
  dispatcher_->SendMessage("CacheStorage.requestCacheNames", params->Serialize(), base::BindOnce(&Domain::HandleRequestCacheNamesResponse, std::move(callback)));
}
void ExperimentalDomain::RequestCachedResponse(std::unique_ptr<RequestCachedResponseParams> params, base::OnceCallback<void(std::unique_ptr<RequestCachedResponseResult>)> callback) {
  dispatcher_->SendMessage("CacheStorage.requestCachedResponse", params->Serialize(), base::BindOnce(&Domain::HandleRequestCachedResponseResponse, std::move(callback)));
}
void ExperimentalDomain::RequestEntries(std::unique_ptr<RequestEntriesParams> params, base::OnceCallback<void(std::unique_ptr<RequestEntriesResult>)> callback) {
  dispatcher_->SendMessage("CacheStorage.requestEntries", params->Serialize(), base::BindOnce(&Domain::HandleRequestEntriesResponse, std::move(callback)));
}


// static
void Domain::HandleDeleteCacheResponse(base::OnceCallback<void(std::unique_ptr<DeleteCacheResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DeleteCacheResult> result = DeleteCacheResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleDeleteEntryResponse(base::OnceCallback<void(std::unique_ptr<DeleteEntryResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DeleteEntryResult> result = DeleteEntryResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleRequestCacheNamesResponse(base::OnceCallback<void(std::unique_ptr<RequestCacheNamesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<RequestCacheNamesResult> result = RequestCacheNamesResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleRequestCachedResponseResponse(base::OnceCallback<void(std::unique_ptr<RequestCachedResponseResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<RequestCachedResponseResult> result = RequestCachedResponseResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleRequestEntriesResponse(base::OnceCallback<void(std::unique_ptr<RequestEntriesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<RequestEntriesResult> result = RequestEntriesResult::Parse(response, &errors);
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


}  // namespace cache_storage

} // namespace headless
