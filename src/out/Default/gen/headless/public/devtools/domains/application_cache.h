// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_APPLICATION_CACHE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_APPLICATION_CACHE_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_application_cache.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace application_cache {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  virtual void OnApplicationCacheStatusUpdated(const ApplicationCacheStatusUpdatedParams& params) {}
  virtual void OnNetworkStateUpdated(const NetworkStateUpdatedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  virtual void OnApplicationCacheStatusUpdated(const ApplicationCacheStatusUpdatedParams& params) final {}
  virtual void OnNetworkStateUpdated(const NetworkStateUpdatedParams& params) final {}
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

  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleGetApplicationCacheForFrameResponse(base::OnceCallback<void(std::unique_ptr<GetApplicationCacheForFrameResult>)> callback, const base::Value& response);
  static void HandleGetFramesWithManifestsResponse(base::OnceCallback<void(std::unique_ptr<GetFramesWithManifestsResult>)> callback, const base::Value& response);
  static void HandleGetManifestForFrameResponse(base::OnceCallback<void(std::unique_ptr<GetManifestForFrameResult>)> callback, const base::Value& response);

  void DispatchApplicationCacheStatusUpdatedEvent(const base::Value& params);
  void DispatchNetworkStateUpdatedEvent(const base::Value& params);

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

  // Enables application cache domain notifications.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Returns relevant application cache data for the document in given frame.
  void GetApplicationCacheForFrame(std::unique_ptr<GetApplicationCacheForFrameParams> params, base::OnceCallback<void(std::unique_ptr<GetApplicationCacheForFrameResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetApplicationCacheForFrameResult>)>());

  // Returns array of frame identifiers with manifest urls for each frame containing a document
  // associated with some application cache.
  void GetFramesWithManifests(std::unique_ptr<GetFramesWithManifestsParams> params, base::OnceCallback<void(std::unique_ptr<GetFramesWithManifestsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetFramesWithManifestsResult>)>());

  // Returns manifest URL for document in the given frame.
  void GetManifestForFrame(std::unique_ptr<GetManifestForFrameParams> params, base::OnceCallback<void(std::unique_ptr<GetManifestForFrameResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetManifestForFrameResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace application_cache
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_APPLICATION_CACHE_H_
