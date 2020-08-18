// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_BROWSER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_BROWSER_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_browser.h"
#include "headless/public/devtools/domains/types_target.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace browser {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

// The Browser domain defines methods and events for browser managing.
class HEADLESS_EXPORT Domain {
 public:

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

  // Close browser gracefully.
  void Close(std::unique_ptr<CloseParams> params, base::OnceCallback<void(std::unique_ptr<CloseResult>)> callback = base::OnceCallback<void(std::unique_ptr<CloseResult>)>());
  void Close(base::OnceClosure callback = base::OnceClosure());
  void Close(std::unique_ptr<CloseParams> params, base::OnceClosure callback);

  // Returns version information.
  void GetVersion(std::unique_ptr<GetVersionParams> params, base::OnceCallback<void(std::unique_ptr<GetVersionResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetVersionResult>)>());
  void GetVersion(base::OnceCallback<void(std::unique_ptr<GetVersionResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetVersionResult>)>());

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleSetPermissionResponse(base::OnceCallback<void(std::unique_ptr<SetPermissionResult>)> callback, const base::Value& response);
  static void HandleGrantPermissionsResponse(base::OnceCallback<void(std::unique_ptr<GrantPermissionsResult>)> callback, const base::Value& response);
  static void HandleResetPermissionsResponse(base::OnceCallback<void(std::unique_ptr<ResetPermissionsResult>)> callback, const base::Value& response);
  static void HandleSetDownloadBehaviorResponse(base::OnceCallback<void(std::unique_ptr<SetDownloadBehaviorResult>)> callback, const base::Value& response);
  static void HandleCloseResponse(base::OnceCallback<void(std::unique_ptr<CloseResult>)> callback, const base::Value& response);
  static void HandleCrashResponse(base::OnceCallback<void(std::unique_ptr<CrashResult>)> callback, const base::Value& response);
  static void HandleCrashGpuProcessResponse(base::OnceCallback<void(std::unique_ptr<CrashGpuProcessResult>)> callback, const base::Value& response);
  static void HandleGetVersionResponse(base::OnceCallback<void(std::unique_ptr<GetVersionResult>)> callback, const base::Value& response);
  static void HandleGetBrowserCommandLineResponse(base::OnceCallback<void(std::unique_ptr<GetBrowserCommandLineResult>)> callback, const base::Value& response);
  static void HandleGetHistogramsResponse(base::OnceCallback<void(std::unique_ptr<GetHistogramsResult>)> callback, const base::Value& response);
  static void HandleGetHistogramResponse(base::OnceCallback<void(std::unique_ptr<GetHistogramResult>)> callback, const base::Value& response);
  static void HandleGetWindowBoundsResponse(base::OnceCallback<void(std::unique_ptr<GetWindowBoundsResult>)> callback, const base::Value& response);
  static void HandleGetWindowForTargetResponse(base::OnceCallback<void(std::unique_ptr<GetWindowForTargetResult>)> callback, const base::Value& response);
  static void HandleSetWindowBoundsResponse(base::OnceCallback<void(std::unique_ptr<SetWindowBoundsResult>)> callback, const base::Value& response);
  static void HandleSetDockTileResponse(base::OnceCallback<void(std::unique_ptr<SetDockTileResult>)> callback, const base::Value& response);


  internal::MessageDispatcher* dispatcher_;  // Not owned.

 private:
  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();


  // Set permission settings for given origin.
  void SetPermission(std::unique_ptr<SetPermissionParams> params, base::OnceCallback<void(std::unique_ptr<SetPermissionResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetPermissionResult>)>());

  // Grant specific permissions to the given origin and reject all others.
  void GrantPermissions(std::unique_ptr<GrantPermissionsParams> params, base::OnceCallback<void(std::unique_ptr<GrantPermissionsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GrantPermissionsResult>)>());

  // Reset all permission management for all origins.
  void ResetPermissions(std::unique_ptr<ResetPermissionsParams> params, base::OnceCallback<void(std::unique_ptr<ResetPermissionsResult>)> callback = base::OnceCallback<void(std::unique_ptr<ResetPermissionsResult>)>());

  // Set the behavior when downloading a file.
  void SetDownloadBehavior(std::unique_ptr<SetDownloadBehaviorParams> params, base::OnceCallback<void(std::unique_ptr<SetDownloadBehaviorResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetDownloadBehaviorResult>)>());

  // Crashes browser on the main thread.
  void Crash(std::unique_ptr<CrashParams> params, base::OnceCallback<void(std::unique_ptr<CrashResult>)> callback = base::OnceCallback<void(std::unique_ptr<CrashResult>)>());

  // Crashes GPU process.
  void CrashGpuProcess(std::unique_ptr<CrashGpuProcessParams> params, base::OnceCallback<void(std::unique_ptr<CrashGpuProcessResult>)> callback = base::OnceCallback<void(std::unique_ptr<CrashGpuProcessResult>)>());

  // Returns the command line switches for the browser process if, and only if
  // --enable-automation is on the commandline.
  void GetBrowserCommandLine(std::unique_ptr<GetBrowserCommandLineParams> params, base::OnceCallback<void(std::unique_ptr<GetBrowserCommandLineResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetBrowserCommandLineResult>)>());

  // Get Chrome histograms.
  void GetHistograms(std::unique_ptr<GetHistogramsParams> params, base::OnceCallback<void(std::unique_ptr<GetHistogramsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetHistogramsResult>)>());

  // Get a Chrome histogram by name.
  void GetHistogram(std::unique_ptr<GetHistogramParams> params, base::OnceCallback<void(std::unique_ptr<GetHistogramResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetHistogramResult>)>());

  // Get position and size of the browser window.
  void GetWindowBounds(std::unique_ptr<GetWindowBoundsParams> params, base::OnceCallback<void(std::unique_ptr<GetWindowBoundsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetWindowBoundsResult>)>());

  // Get the browser window that contains the devtools target.
  void GetWindowForTarget(std::unique_ptr<GetWindowForTargetParams> params, base::OnceCallback<void(std::unique_ptr<GetWindowForTargetResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetWindowForTargetResult>)>());

  // Set position and/or size of the browser window.
  void SetWindowBounds(std::unique_ptr<SetWindowBoundsParams> params, base::OnceCallback<void(std::unique_ptr<SetWindowBoundsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetWindowBoundsResult>)>());

  // Set dock tile details, platform-specific.
  void SetDockTile(std::unique_ptr<SetDockTileParams> params, base::OnceCallback<void(std::unique_ptr<SetDockTileResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetDockTileResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace browser
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_BROWSER_H_
