// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_LOCAL_DISCOVERY_SERVICE_DISCOVERY_CLIENT_MAC_H_
#define CHROME_BROWSER_LOCAL_DISCOVERY_SERVICE_DISCOVERY_CLIENT_MAC_H_

#import <Foundation/Foundation.h>
#include <memory>
#include <string>

#include "base/mac/scoped_nsobject.h"
#include "base/macros.h"
#include "base/memory/weak_ptr.h"
#include "base/single_thread_task_runner.h"
#include "base/threading/thread_task_runner_handle.h"
#include "chrome/browser/local_discovery/service_discovery_shared_client.h"

namespace base {
class Thread;
}

@class NetServiceBrowser;
@class NetServiceResolver;

namespace local_discovery {

// Implementation of ServiceDiscoveryClient that uses the Bonjour SDK.
// https://developer.apple.com/library/mac/documentation/Networking/Conceptual/
// NSNetServiceProgGuide/Articles/BrowsingForServices.html
class ServiceDiscoveryClientMac : public ServiceDiscoverySharedClient {
 public:
  ServiceDiscoveryClientMac();

 private:
  friend class ServiceDiscoveryClientMacTest;

  ~ServiceDiscoveryClientMac() override;

  // ServiceDiscoveryClient implementation.
  std::unique_ptr<ServiceWatcher> CreateServiceWatcher(
      const std::string& service_type,
      ServiceWatcher::UpdatedCallback callback) override;
  std::unique_ptr<ServiceResolver> CreateServiceResolver(
      const std::string& service_name,
      ServiceResolver::ResolveCompleteCallback callback) override;
  std::unique_ptr<LocalDomainResolver> CreateLocalDomainResolver(
      const std::string& domain,
      net::AddressFamily address_family,
      LocalDomainResolver::IPAddressCallback callback) override;

  void StartThreadIfNotStarted();

  std::unique_ptr<base::Thread> service_discovery_thread_;

  DISALLOW_COPY_AND_ASSIGN(ServiceDiscoveryClientMac);
};

class ServiceWatcherImplMac : public ServiceWatcher {
 public:
  ServiceWatcherImplMac(
      const std::string& service_type,
      ServiceWatcher::UpdatedCallback callback,
      scoped_refptr<base::SingleThreadTaskRunner> service_discovery_runner);

  ~ServiceWatcherImplMac() override;

  void OnServicesUpdate(ServiceWatcher::UpdateType update,
                        const std::string& service);

 private:
  void Start() override;
  void DiscoverNewServices() override;
  void SetActivelyRefreshServices(bool actively_refresh_services) override;
  std::string GetServiceType() const override;

  void StartOnDiscoveryThread(
      ServiceWatcher::UpdatedCallback callback,
      scoped_refptr<base::SingleThreadTaskRunner> callback_runner);
  void DiscoverOnDiscoveryThread();

  // These members should only be accessed on the object creator's sequence.
  const std::string service_type_;
  ServiceWatcher::UpdatedCallback callback_;
  bool started_ = false;

  scoped_refptr<base::SingleThreadTaskRunner> service_discovery_runner_;
  // |browser_| lives on the |service_discovery_runner_|. It is released
  // by move()ing it to StopServiceBrowser().
  base::scoped_nsobject<NetServiceBrowser> browser_;

  base::WeakPtrFactory<ServiceWatcherImplMac> weak_factory_{this};

  DISALLOW_COPY_AND_ASSIGN(ServiceWatcherImplMac);
};

class ServiceResolverImplMac : public ServiceResolver {
 public:
  ServiceResolverImplMac(
      const std::string& service_name,
      ServiceResolver::ResolveCompleteCallback callback,
      scoped_refptr<base::SingleThreadTaskRunner> service_discovery_runner);

  ~ServiceResolverImplMac() override;

 private:
  void StartResolving() override;
  std::string GetName() const override;

  void OnResolveComplete(RequestStatus status,
                         const ServiceDescription& description);

  void StartResolvingOnDiscoveryThread(
      ServiceResolver::ResolveCompleteCallback callback,
      scoped_refptr<base::SingleThreadTaskRunner> callback_runner);
  void StopResolving();

  // These members should only be accessed on the object creator's sequence.
  const std::string service_name_;
  ServiceResolver::ResolveCompleteCallback callback_;
  bool has_resolved_ = false;

  scoped_refptr<base::SingleThreadTaskRunner> service_discovery_runner_;
  // |resolver_| lives on the |service_discovery_runner_|. It is released
  // by move()ing it to StopServiceResolver().
  base::scoped_nsobject<NetServiceResolver> resolver_;

  base::WeakPtrFactory<ServiceResolverImplMac> weak_factory_{this};

  DISALLOW_COPY_AND_ASSIGN(ServiceResolverImplMac);
};

// Parses the data out of the |service|, updating the |description| with the
// results.
void ParseNetService(NSNetService* service, ServiceDescription& description);

}  // namespace local_discovery

#endif  // CHROME_BROWSER_LOCAL_DISCOVERY_SERVICE_DISCOVERY_CLIENT_MAC_H_
