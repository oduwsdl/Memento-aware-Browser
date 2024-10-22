// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/web_applications/components/app_shortcut_manager.h"

#include <utility>

#include "base/callback.h"
#include "base/feature_list.h"
#include "base/no_destructor.h"
#include "base/strings/utf_string_conversions.h"
#include "build/build_config.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/web_applications/components/web_app_run_on_os_login.h"
#include "chrome/common/chrome_features.h"
#include "content/public/browser/browser_task_traits.h"
#include "content/public/browser/browser_thread.h"

#if defined(OS_MACOSX)
#include "chrome/browser/web_applications/components/app_shim_registry_mac.h"
#endif

namespace web_app {

namespace {

AppShortcutManager::ShortcutCallback& GetShortcutUpdateCallbackForTesting() {
  static base::NoDestructor<AppShortcutManager::ShortcutCallback> callback;
  return *callback;
}

}  // namespace

AppShortcutManager::AppShortcutManager(Profile* profile) : profile_(profile) {}

AppShortcutManager::~AppShortcutManager() = default;

void AppShortcutManager::SetSubsystems(AppRegistrar* registrar) {
  registrar_ = registrar;
}

void AppShortcutManager::Start() {
  DCHECK(registrar_);
  app_registrar_observer_.Add(registrar_);

#if defined(OS_MACOSX)
  // Ensure that all installed apps are included in the AppShimRegistry when the
  // profile is loaded. This is redundant, because apps are registered when they
  // are installed. It is necessary, however, because app registration was added
  // long after app installation launched. This should be removed after shipping
  // for a few versions (whereupon it may be assumed that most applications have
  // been registered).
  std::vector<AppId> app_ids = registrar_->GetAppIds();
  for (const auto& app_id : app_ids) {
    AppShimRegistry::Get()->OnAppInstalledForProfile(app_id,
                                                     profile_->GetPath());
  }
#endif
}

void AppShortcutManager::Shutdown() {
  app_registrar_observer_.RemoveAll();
}

void AppShortcutManager::OnWebAppInstalled(const AppId& app_id) {
#if defined(OS_MACOSX)
  AppShimRegistry::Get()->OnAppInstalledForProfile(app_id, profile_->GetPath());
#endif
}

void AppShortcutManager::OnWebAppManifestUpdated(const AppId& app_id,
                                                 base::StringPiece old_name) {
  if (!CanCreateShortcuts())
    return;

  GetShortcutInfoForApp(
      app_id, base::BindOnce(
                  &AppShortcutManager::OnShortcutInfoRetrievedUpdateShortcuts,
                  weak_ptr_factory_.GetWeakPtr(), base::UTF8ToUTF16(old_name)));
}

void AppShortcutManager::OnWebAppUninstalled(const AppId& app_id) {
  std::unique_ptr<ShortcutInfo> shortcut_info = BuildShortcutInfo(app_id);
  base::FilePath shortcut_data_dir =
      internals::GetShortcutDataDir(*shortcut_info);

  if (base::FeatureList::IsEnabled(features::kDesktopPWAsRunOnOsLogin)) {
    internals::GetShortcutIOTaskRunner()->PostTask(
        FROM_HERE,
        base::BindOnce(&internals::UnregisterRunOnOsLogin,
                       shortcut_info->profile_path, shortcut_info->title));
  }

  internals::PostShortcutIOTask(
      base::BindOnce(&internals::DeletePlatformShortcuts, shortcut_data_dir),
      std::move(shortcut_info));

  DeleteSharedAppShims(app_id);
}

void AppShortcutManager::OnWebAppProfileWillBeDeleted(const AppId& app_id) {
  DeleteSharedAppShims(app_id);
}

void AppShortcutManager::SetShortcutUpdateCallbackForTesting(
    base::OnceCallback<void(const ShortcutInfo*)> callback) {
  GetShortcutUpdateCallbackForTesting() = std::move(callback);
}

void AppShortcutManager::DeleteSharedAppShims(const AppId& app_id) {
#if defined(OS_MACOSX)
  bool delete_multi_profile_shortcuts =
      AppShimRegistry::Get()->OnAppUninstalledForProfile(app_id,
                                                         profile_->GetPath());
  if (delete_multi_profile_shortcuts) {
    web_app::internals::GetShortcutIOTaskRunner()->PostTask(
        FROM_HERE,
        base::BindOnce(&web_app::internals::DeleteMultiProfileShortcutsForApp,
                       app_id));
  }
#endif
}

bool AppShortcutManager::CanCreateShortcuts() const {
#if defined(OS_CHROMEOS)
  return false;
#else
  return true;
#endif
}

void AppShortcutManager::SuppressShortcutsForTesting() {
  suppress_shortcuts_for_testing_ = true;
}

void AppShortcutManager::CreateShortcuts(const AppId& app_id,
                                         bool add_to_desktop,
                                         CreateShortcutsCallback callback) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  DCHECK(CanCreateShortcuts());

  GetShortcutInfoForApp(
      app_id, base::BindOnce(
                  &AppShortcutManager::OnShortcutInfoRetrievedCreateShortcuts,
                  weak_ptr_factory_.GetWeakPtr(), add_to_desktop,
                  base::BindOnce(&AppShortcutManager::OnShortcutsCreated,
                                 weak_ptr_factory_.GetWeakPtr(), app_id,
                                 std::move(callback))));
}

void AppShortcutManager::RegisterShortcutsMenuWithOs(
    const AppId& app_id,
    const std::vector<WebApplicationShortcutsMenuItemInfo>& shortcut_infos,
    const ShortcutsMenuIconsBitmaps& shortcuts_menu_icons_bitmaps) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  if (!web_app::ShouldRegisterShortcutsMenuWithOs() ||
      suppress_shortcuts_for_testing()) {
    return;
  }

  std::unique_ptr<ShortcutInfo> shortcut_info = BuildShortcutInfo(app_id);
  if (!shortcut_info)
    return;

  // |shortcut_data_dir| is located in per-app OS integration resources
  // directory. See GetOsIntegrationResourcesDirectoryForApp function for more
  // info.
  base::FilePath shortcut_data_dir =
      internals::GetShortcutDataDir(*shortcut_info);
  web_app::RegisterShortcutsMenuWithOs(
      shortcut_info->extension_id, shortcut_info->profile_path,
      shortcut_data_dir, shortcut_infos, shortcuts_menu_icons_bitmaps);
}

void AppShortcutManager::UnregisterShortcutsMenuWithOs(const AppId& app_id) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  if (!web_app::ShouldRegisterShortcutsMenuWithOs())
    return;

  // TODO(https://crbug.com/1069298): Get profile_path without using
  // shortcut_info.
  std::unique_ptr<ShortcutInfo> shortcut_info = BuildShortcutInfo(app_id);
  if (!shortcut_info)
    return;

  web_app::UnregisterShortcutsMenuWithOs(shortcut_info->extension_id,
                                         shortcut_info->profile_path);
}

void AppShortcutManager::OnShortcutsCreated(const AppId& app_id,
                                            CreateShortcutsCallback callback,
                                            bool success) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  std::move(callback).Run(success);
}

void AppShortcutManager::OnShortcutInfoRetrievedCreateShortcuts(
    bool add_to_desktop,
    CreateShortcutsCallback callback,
    std::unique_ptr<ShortcutInfo> info) {
  if (suppress_shortcuts_for_testing_) {
    std::move(callback).Run(/*shortcut_created=*/true);
    return;
  }

  if (info == nullptr) {
    std::move(callback).Run(/*shortcut_created=*/false);
    return;
  }

  base::FilePath shortcut_data_dir = internals::GetShortcutDataDir(*info);

  ShortcutLocations locations;
  locations.on_desktop = add_to_desktop;
  locations.applications_menu_location = APP_MENU_LOCATION_SUBDIR_CHROMEAPPS;

  // Remove any previously created App Icon Shortcuts Menu.
  if (!base::FeatureList::IsEnabled(
          features::kDesktopPWAsAppIconShortcutsMenu) &&
      web_app::ShouldRegisterShortcutsMenuWithOs()) {
    web_app::UnregisterShortcutsMenuWithOs(info->extension_id,
                                           info->profile_path);
  }

  internals::ScheduleCreatePlatformShortcuts(
      std::move(shortcut_data_dir), locations, SHORTCUT_CREATION_BY_USER,
      std::move(info), std::move(callback));
}

void AppShortcutManager::RegisterRunOnOsLogin(
    const AppId& app_id,
    RegisterRunOnOsLoginCallback callback) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);

  GetShortcutInfoForApp(
      app_id,
      base::BindOnce(
          &AppShortcutManager::OnShortcutInfoRetrievedRegisterRunOnOsLogin,
          weak_ptr_factory_.GetWeakPtr(), std::move(callback)));
}

void AppShortcutManager::OnShortcutInfoRetrievedRegisterRunOnOsLogin(
    RegisterRunOnOsLoginCallback callback,
    std::unique_ptr<ShortcutInfo> info) {
  ScheduleRegisterRunOnOsLogin(std::move(info), std::move(callback));
}

void AppShortcutManager::OnShortcutInfoRetrievedUpdateShortcuts(
    base::string16 old_name,
    std::unique_ptr<ShortcutInfo> shortcut_info) {
  if (GetShortcutUpdateCallbackForTesting())
    std::move(GetShortcutUpdateCallbackForTesting()).Run(shortcut_info.get());

  if (suppress_shortcuts_for_testing() || !shortcut_info)
    return;

  base::FilePath shortcut_data_dir =
      internals::GetShortcutDataDir(*shortcut_info);
  internals::PostShortcutIOTask(
      base::BindOnce(&internals::UpdatePlatformShortcuts,
                     std::move(shortcut_data_dir), std::move(old_name)),
      std::move(shortcut_info));
}

}  // namespace web_app
