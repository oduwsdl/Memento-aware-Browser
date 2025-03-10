// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_NEARBY_SHARING_NEARBY_SHARING_SERVICE_IMPL_H_
#define CHROME_BROWSER_NEARBY_SHARING_NEARBY_SHARING_SERVICE_IMPL_H_

#include <memory>

#include "base/memory/weak_ptr.h"
#include "base/scoped_observer.h"
#include "chrome/browser/nearby_sharing/nearby_process_manager.h"
#include "chrome/browser/nearby_sharing/nearby_sharing_service.h"
#include "components/keyed_service/core/keyed_service.h"
#include "components/prefs/pref_change_registrar.h"

class NearbyConnectionsManager;

class PrefService;
class Profile;

class NearbySharingServiceImpl : public NearbySharingService,
                                 public KeyedService,
                                 public NearbyProcessManager::Observer {
 public:
  explicit NearbySharingServiceImpl(
      PrefService* prefs,
      Profile* profile,
      std::unique_ptr<NearbyConnectionsManager> nearby_connections_manager);
  ~NearbySharingServiceImpl() override;

  // NearbySharingService:
  void RegisterSendSurface(TransferUpdateCallback* transferCallback,
                           ShareTargetDiscoveredCallback* discoveryCallback,
                           StatusCodesCallback status_codes_callback) override;
  void UnregisterSendSurface(
      TransferUpdateCallback* transferCallback,
      ShareTargetDiscoveredCallback* discoveryCallback,
      StatusCodesCallback status_codes_callback) override;
  void RegisterReceiveSurface(
      TransferUpdateCallback* transferCallback,
      StatusCodesCallback status_codes_callback) override;
  void UnregisterReceiveSurface(
      TransferUpdateCallback* transferCallback,
      StatusCodesCallback status_codes_callback) override;
  void SendText(const ShareTarget& share_target,
                std::string text,
                StatusCodesCallback status_codes_callback) override;
  void SendFiles(const ShareTarget& share_target,
                 const std::vector<base::FilePath>& files,
                 StatusCodesCallback status_codes_callback) override;
  void Accept(const ShareTarget& share_target,
              StatusCodesCallback status_codes_callback) override;
  void Reject(const ShareTarget& share_target,
              StatusCodesCallback status_codes_callback) override;
  void Cancel(const ShareTarget& share_target,
              StatusCodesCallback status_codes_callback) override;
  void Open(const ShareTarget& share_target,
            StatusCodesCallback status_codes_callback) override;

  // NearbyProcessManager::Observer:
  void OnNearbyProfileChanged(Profile* profile) override;
  void OnNearbyProcessStarted() override;
  void OnNearbyProcessStopped() override;

 private:
  bool IsEnabled();
  void OnEnabledPrefChanged();

  PrefService* prefs_;
  Profile* profile_;
  std::unique_ptr<NearbyConnectionsManager> nearby_connections_manager_;
  PrefChangeRegistrar pref_change_registrar_;
  ScopedObserver<NearbyProcessManager, NearbyProcessManager::Observer>
      nearby_process_observer_{this};
};

#endif  // CHROME_BROWSER_NEARBY_SHARING_NEARBY_SHARING_SERVICE_IMPL_H_
