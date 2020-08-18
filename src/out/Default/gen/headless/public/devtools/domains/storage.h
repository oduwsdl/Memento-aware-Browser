// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_STORAGE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_STORAGE_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_browser.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/devtools/domains/types_storage.h"
#include "headless/public/devtools/domains/types_target.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace storage {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // A cache's contents have been modified.
  virtual void OnCacheStorageContentUpdated(const CacheStorageContentUpdatedParams& params) {}
  // A cache has been added/deleted.
  virtual void OnCacheStorageListUpdated(const CacheStorageListUpdatedParams& params) {}
  // The origin's IndexedDB object store has been modified.
  virtual void OnIndexedDBContentUpdated(const IndexedDBContentUpdatedParams& params) {}
  // The origin's IndexedDB database list has been modified.
  virtual void OnIndexedDBListUpdated(const IndexedDBListUpdatedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Experimental: A cache's contents have been modified.
  virtual void OnCacheStorageContentUpdated(const CacheStorageContentUpdatedParams& params) final {}
  // Experimental: A cache has been added/deleted.
  virtual void OnCacheStorageListUpdated(const CacheStorageListUpdatedParams& params) final {}
  // Experimental: The origin's IndexedDB object store has been modified.
  virtual void OnIndexedDBContentUpdated(const IndexedDBContentUpdatedParams& params) final {}
  // Experimental: The origin's IndexedDB database list has been modified.
  virtual void OnIndexedDBListUpdated(const IndexedDBListUpdatedParams& params) final {}
};

class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleClearDataForOriginResponse(base::OnceCallback<void(std::unique_ptr<ClearDataForOriginResult>)> callback, const base::Value& response);
  static void HandleGetCookiesResponse(base::OnceCallback<void(std::unique_ptr<GetCookiesResult>)> callback, const base::Value& response);
  static void HandleSetCookiesResponse(base::OnceCallback<void(std::unique_ptr<SetCookiesResult>)> callback, const base::Value& response);
  static void HandleClearCookiesResponse(base::OnceCallback<void(std::unique_ptr<ClearCookiesResult>)> callback, const base::Value& response);
  static void HandleGetUsageAndQuotaResponse(base::OnceCallback<void(std::unique_ptr<GetUsageAndQuotaResult>)> callback, const base::Value& response);
  static void HandleTrackCacheStorageForOriginResponse(base::OnceCallback<void(std::unique_ptr<TrackCacheStorageForOriginResult>)> callback, const base::Value& response);
  static void HandleTrackIndexedDBForOriginResponse(base::OnceCallback<void(std::unique_ptr<TrackIndexedDBForOriginResult>)> callback, const base::Value& response);
  static void HandleUntrackCacheStorageForOriginResponse(base::OnceCallback<void(std::unique_ptr<UntrackCacheStorageForOriginResult>)> callback, const base::Value& response);
  static void HandleUntrackIndexedDBForOriginResponse(base::OnceCallback<void(std::unique_ptr<UntrackIndexedDBForOriginResult>)> callback, const base::Value& response);

  void DispatchCacheStorageContentUpdatedEvent(const base::Value& params);
  void DispatchCacheStorageListUpdatedEvent(const base::Value& params);
  void DispatchIndexedDBContentUpdatedEvent(const base::Value& params);
  void DispatchIndexedDBListUpdatedEvent(const base::Value& params);

  internal::MessageDispatcher* dispatcher_;  // Not owned.
  base::ObserverList<ExperimentalObserver>::Unchecked observers_;

 protected:
  void RegisterEventHandlersIfNeeded();

 private:
  bool event_handlers_registered_ = false;

  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();

  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(ExperimentalObserver* observer);
  void RemoveObserver(ExperimentalObserver* observer);

  // Clears storage for origin.
  void ClearDataForOrigin(std::unique_ptr<ClearDataForOriginParams> params, base::OnceCallback<void(std::unique_ptr<ClearDataForOriginResult>)> callback = base::OnceCallback<void(std::unique_ptr<ClearDataForOriginResult>)>());

  // Returns all browser cookies.
  void GetCookies(std::unique_ptr<GetCookiesParams> params, base::OnceCallback<void(std::unique_ptr<GetCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetCookiesResult>)>());

  // Sets given cookies.
  void SetCookies(std::unique_ptr<SetCookiesParams> params, base::OnceCallback<void(std::unique_ptr<SetCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetCookiesResult>)>());

  // Clears cookies.
  void ClearCookies(std::unique_ptr<ClearCookiesParams> params, base::OnceCallback<void(std::unique_ptr<ClearCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<ClearCookiesResult>)>());

  // Returns usage and quota in bytes.
  void GetUsageAndQuota(std::unique_ptr<GetUsageAndQuotaParams> params, base::OnceCallback<void(std::unique_ptr<GetUsageAndQuotaResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetUsageAndQuotaResult>)>());

  // Registers origin to be notified when an update occurs to its cache storage list.
  void TrackCacheStorageForOrigin(std::unique_ptr<TrackCacheStorageForOriginParams> params, base::OnceCallback<void(std::unique_ptr<TrackCacheStorageForOriginResult>)> callback = base::OnceCallback<void(std::unique_ptr<TrackCacheStorageForOriginResult>)>());

  // Registers origin to be notified when an update occurs to its IndexedDB.
  void TrackIndexedDBForOrigin(std::unique_ptr<TrackIndexedDBForOriginParams> params, base::OnceCallback<void(std::unique_ptr<TrackIndexedDBForOriginResult>)> callback = base::OnceCallback<void(std::unique_ptr<TrackIndexedDBForOriginResult>)>());

  // Unregisters origin from receiving notifications for cache storage.
  void UntrackCacheStorageForOrigin(std::unique_ptr<UntrackCacheStorageForOriginParams> params, base::OnceCallback<void(std::unique_ptr<UntrackCacheStorageForOriginResult>)> callback = base::OnceCallback<void(std::unique_ptr<UntrackCacheStorageForOriginResult>)>());

  // Unregisters origin from receiving notifications for IndexedDB.
  void UntrackIndexedDBForOrigin(std::unique_ptr<UntrackIndexedDBForOriginParams> params, base::OnceCallback<void(std::unique_ptr<UntrackIndexedDBForOriginResult>)> callback = base::OnceCallback<void(std::unique_ptr<UntrackIndexedDBForOriginResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace storage
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_STORAGE_H_
