// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_CACHE_STORAGE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_CACHE_STORAGE_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_cache_storage.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace cache_storage {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT Domain {
 public:

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleDeleteCacheResponse(base::OnceCallback<void(std::unique_ptr<DeleteCacheResult>)> callback, const base::Value& response);
  static void HandleDeleteEntryResponse(base::OnceCallback<void(std::unique_ptr<DeleteEntryResult>)> callback, const base::Value& response);
  static void HandleRequestCacheNamesResponse(base::OnceCallback<void(std::unique_ptr<RequestCacheNamesResult>)> callback, const base::Value& response);
  static void HandleRequestCachedResponseResponse(base::OnceCallback<void(std::unique_ptr<RequestCachedResponseResult>)> callback, const base::Value& response);
  static void HandleRequestEntriesResponse(base::OnceCallback<void(std::unique_ptr<RequestEntriesResult>)> callback, const base::Value& response);


  internal::MessageDispatcher* dispatcher_;  // Not owned.

 private:
  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();


  // Deletes a cache.
  void DeleteCache(std::unique_ptr<DeleteCacheParams> params, base::OnceCallback<void(std::unique_ptr<DeleteCacheResult>)> callback = base::OnceCallback<void(std::unique_ptr<DeleteCacheResult>)>());

  // Deletes a cache entry.
  void DeleteEntry(std::unique_ptr<DeleteEntryParams> params, base::OnceCallback<void(std::unique_ptr<DeleteEntryResult>)> callback = base::OnceCallback<void(std::unique_ptr<DeleteEntryResult>)>());

  // Requests cache names.
  void RequestCacheNames(std::unique_ptr<RequestCacheNamesParams> params, base::OnceCallback<void(std::unique_ptr<RequestCacheNamesResult>)> callback = base::OnceCallback<void(std::unique_ptr<RequestCacheNamesResult>)>());

  // Fetches cache entry.
  void RequestCachedResponse(std::unique_ptr<RequestCachedResponseParams> params, base::OnceCallback<void(std::unique_ptr<RequestCachedResponseResult>)> callback = base::OnceCallback<void(std::unique_ptr<RequestCachedResponseResult>)>());

  // Requests data from cache.
  void RequestEntries(std::unique_ptr<RequestEntriesParams> params, base::OnceCallback<void(std::unique_ptr<RequestEntriesResult>)> callback = base::OnceCallback<void(std::unique_ptr<RequestEntriesResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace cache_storage
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_CACHE_STORAGE_H_
