// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_WEB_APPLICATIONS_COMPONENTS_APP_REGISTRAR_OBSERVER_H_
#define CHROME_BROWSER_WEB_APPLICATIONS_COMPONENTS_APP_REGISTRAR_OBSERVER_H_

#include "base/observer_list_types.h"
#include "chrome/browser/web_applications/components/web_app_id.h"

namespace base {
class Time;
}

namespace web_app {

class AppRegistrarObserver : public base::CheckedObserver {
 public:
  virtual void OnWebAppInstalled(const AppId& app_id) {}

  // Called when any field of a web app's local manifest is updated.
  // Note that |old_name| will always be the same as the current name as we
  // don't support name updating yet. See TODO(crbug.com/1088338).
  virtual void OnWebAppManifestUpdated(const AppId& app_id,
                                       base::StringPiece old_name) {}

  // |app_id| still registered in the AppRegistrar. For bookmark apps, use
  // BookmarkAppRegistrar::FindExtension to convert this |app_id| to Extension
  // pointer.
  virtual void OnWebAppUninstalled(const AppId& app_id) {}

  // For bookmark apps, use BookmarkAppRegistrar::FindExtension to convert this
  // |app_id| to Extension pointer.
  virtual void OnWebAppProfileWillBeDeleted(const AppId& app_id) {}

  virtual void OnAppRegistrarShutdown() {}

  virtual void OnAppRegistrarDestroyed() {}

  virtual void OnWebAppLocallyInstalledStateChanged(const AppId& app_id,
                                                    bool is_locally_installed) {
  }

  // The disabled status WebApp::chromeos_data().is_disabled of the app backing
  // |app_id| changed.
  virtual void OnWebAppDisabledStateChanged(const AppId& app_id,
                                            bool is_disabled) {}
  virtual void OnWebAppLastLaunchTimeChanged(const AppId& app_id,
                                             const base::Time& time) {}
  virtual void OnWebAppInstallTimeChanged(const AppId& app_id,
                                          const base::Time& time) {}
};

}  // namespace web_app

#endif  // CHROME_BROWSER_WEB_APPLICATIONS_COMPONENTS_APP_REGISTRAR_OBSERVER_H_
