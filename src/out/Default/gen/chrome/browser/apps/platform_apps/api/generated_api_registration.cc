// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/apps/platform_apps/api/generated_api_registration.h"

#include "chrome/browser/apps/platform_apps/api/media_galleries/media_galleries_api.h"
#include "chrome/browser/apps/platform_apps/api/music_manager_private/music_manager_private_api.h"
#include "chrome/browser/apps/platform_apps/api/sync_file_system/sync_file_system_api.h"
#if defined(OS_CHROMEOS)
#include "chrome/browser/apps/platform_apps/api/webstore_widget_private/webstore_widget_private_api.h"
#endif  // defined(OS_CHROMEOS)
#include "chrome/browser/apps/platform_apps/api/browser/browser_api.h"

#include "extensions/browser/extension_function_registry.h"

namespace chrome_apps {
namespace api {

// static
void ChromeAppsGeneratedFunctionRegistry::RegisterAll(ExtensionFunctionRegistry* registry) {
  constexpr ExtensionFunctionRegistry::FactoryEntry kEntries[] = {
    {
      &NewExtensionFunction<MediaGalleriesGetMediaFileSystemsFunction>,
      MediaGalleriesGetMediaFileSystemsFunction::function_name(),
      MediaGalleriesGetMediaFileSystemsFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<MediaGalleriesAddUserSelectedFolderFunction>,
      MediaGalleriesAddUserSelectedFolderFunction::function_name(),
      MediaGalleriesAddUserSelectedFolderFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<MediaGalleriesGetMetadataFunction>,
      MediaGalleriesGetMetadataFunction::function_name(),
      MediaGalleriesGetMetadataFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<MediaGalleriesAddGalleryWatchFunction>,
      MediaGalleriesAddGalleryWatchFunction::function_name(),
      MediaGalleriesAddGalleryWatchFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<MediaGalleriesRemoveGalleryWatchFunction>,
      MediaGalleriesRemoveGalleryWatchFunction::function_name(),
      MediaGalleriesRemoveGalleryWatchFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<MusicManagerPrivateGetDeviceIdFunction>,
      MusicManagerPrivateGetDeviceIdFunction::function_name(),
      MusicManagerPrivateGetDeviceIdFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemRequestFileSystemFunction>,
      SyncFileSystemRequestFileSystemFunction::function_name(),
      SyncFileSystemRequestFileSystemFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemSetConflictResolutionPolicyFunction>,
      SyncFileSystemSetConflictResolutionPolicyFunction::function_name(),
      SyncFileSystemSetConflictResolutionPolicyFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemGetConflictResolutionPolicyFunction>,
      SyncFileSystemGetConflictResolutionPolicyFunction::function_name(),
      SyncFileSystemGetConflictResolutionPolicyFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemGetUsageAndQuotaFunction>,
      SyncFileSystemGetUsageAndQuotaFunction::function_name(),
      SyncFileSystemGetUsageAndQuotaFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemGetFileStatusFunction>,
      SyncFileSystemGetFileStatusFunction::function_name(),
      SyncFileSystemGetFileStatusFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemGetFileStatusesFunction>,
      SyncFileSystemGetFileStatusesFunction::function_name(),
      SyncFileSystemGetFileStatusesFunction::histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemGetServiceStatusFunction>,
      SyncFileSystemGetServiceStatusFunction::function_name(),
      SyncFileSystemGetServiceStatusFunction::histogram_value(),
    },
    #if defined(OS_CHROMEOS)
    {
      &NewExtensionFunction<WebstoreWidgetPrivateInstallWebstoreItemFunction>,
      WebstoreWidgetPrivateInstallWebstoreItemFunction::function_name(),
      WebstoreWidgetPrivateInstallWebstoreItemFunction::histogram_value(),
    },
    #endif  // defined(OS_CHROMEOS)
    {
      &NewExtensionFunction<BrowserOpenTabFunction>,
      BrowserOpenTabFunction::function_name(),
      BrowserOpenTabFunction::histogram_value(),
    },
  };
  for (const auto& entry : kEntries) {
      registry->Register(entry);
  }
}

}  // namespace api
}  // namespace chrome_apps
