// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/apps/platform_apps/api/generated_api_registration.h"

#include "build/build_config.h"
#include "build/chromeos_buildflags.h"

#include "chrome/browser/apps/platform_apps/api/media_galleries/media_galleries_api.h"
#include "chrome/browser/apps/platform_apps/api/music_manager_private/music_manager_private_api.h"
#include "chrome/browser/apps/platform_apps/api/sync_file_system/sync_file_system_api.h"
#if (defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS))
#include "chrome/browser/apps/platform_apps/api/webstore_widget_private/webstore_widget_private_api.h"
#endif  // (defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS))
#include "chrome/browser/apps/platform_apps/api/browser/browser_api.h"

#include "extensions/browser/extension_function_registry.h"

namespace chrome_apps {
namespace api {

// static
void ChromeAppsGeneratedFunctionRegistry::RegisterAll(ExtensionFunctionRegistry* registry) {
  constexpr ExtensionFunctionRegistry::FactoryEntry kEntries[] = {
    {
      &NewExtensionFunction<MediaGalleriesGetMediaFileSystemsFunction>,
      MediaGalleriesGetMediaFileSystemsFunction::static_function_name(),
      MediaGalleriesGetMediaFileSystemsFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<MediaGalleriesAddUserSelectedFolderFunction>,
      MediaGalleriesAddUserSelectedFolderFunction::static_function_name(),
      MediaGalleriesAddUserSelectedFolderFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<MediaGalleriesGetMetadataFunction>,
      MediaGalleriesGetMetadataFunction::static_function_name(),
      MediaGalleriesGetMetadataFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<MediaGalleriesAddGalleryWatchFunction>,
      MediaGalleriesAddGalleryWatchFunction::static_function_name(),
      MediaGalleriesAddGalleryWatchFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<MediaGalleriesRemoveGalleryWatchFunction>,
      MediaGalleriesRemoveGalleryWatchFunction::static_function_name(),
      MediaGalleriesRemoveGalleryWatchFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<MusicManagerPrivateGetDeviceIdFunction>,
      MusicManagerPrivateGetDeviceIdFunction::static_function_name(),
      MusicManagerPrivateGetDeviceIdFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemRequestFileSystemFunction>,
      SyncFileSystemRequestFileSystemFunction::static_function_name(),
      SyncFileSystemRequestFileSystemFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemSetConflictResolutionPolicyFunction>,
      SyncFileSystemSetConflictResolutionPolicyFunction::static_function_name(),
      SyncFileSystemSetConflictResolutionPolicyFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemGetConflictResolutionPolicyFunction>,
      SyncFileSystemGetConflictResolutionPolicyFunction::static_function_name(),
      SyncFileSystemGetConflictResolutionPolicyFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemGetUsageAndQuotaFunction>,
      SyncFileSystemGetUsageAndQuotaFunction::static_function_name(),
      SyncFileSystemGetUsageAndQuotaFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemGetFileStatusFunction>,
      SyncFileSystemGetFileStatusFunction::static_function_name(),
      SyncFileSystemGetFileStatusFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemGetFileStatusesFunction>,
      SyncFileSystemGetFileStatusesFunction::static_function_name(),
      SyncFileSystemGetFileStatusesFunction::static_histogram_value(),
    },
    {
      &NewExtensionFunction<SyncFileSystemGetServiceStatusFunction>,
      SyncFileSystemGetServiceStatusFunction::static_function_name(),
      SyncFileSystemGetServiceStatusFunction::static_histogram_value(),
    },
    #if (defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS))
    {
      &NewExtensionFunction<WebstoreWidgetPrivateInstallWebstoreItemFunction>,
      WebstoreWidgetPrivateInstallWebstoreItemFunction::static_function_name(),
      WebstoreWidgetPrivateInstallWebstoreItemFunction::static_histogram_value(),
    },
    #endif  // (defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS))
    {
      &NewExtensionFunction<BrowserOpenTabFunction>,
      BrowserOpenTabFunction::static_function_name(),
      BrowserOpenTabFunction::static_histogram_value(),
    },
  };
  for (const auto& entry : kEntries) {
      registry->Register(entry);
  }
}

}  // namespace api
}  // namespace chrome_apps
