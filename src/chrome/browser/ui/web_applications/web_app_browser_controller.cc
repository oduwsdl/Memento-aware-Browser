// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/web_applications/web_app_browser_controller.h"

#include "base/bind_helpers.h"
#include "base/strings/string_util.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/ui/browser.h"
#include "chrome/browser/ui/browser_commands.h"
#include "chrome/browser/ui/browser_window.h"
#include "chrome/browser/ui/web_applications/web_app_dialog_manager.h"
#include "chrome/browser/ui/web_applications/web_app_launch_utils.h"
#include "chrome/browser/ui/web_applications/web_app_ui_manager_impl.h"
#include "chrome/browser/web_applications/components/app_icon_manager.h"
#include "chrome/browser/web_applications/components/web_app_constants.h"
#include "chrome/browser/web_applications/components/web_app_helpers.h"
#include "chrome/browser/web_applications/web_app_provider.h"
#include "content/public/browser/web_contents.h"
#include "ui/gfx/favicon_size.h"
#include "ui/gfx/image/image.h"
#include "url/gurl.h"

#if defined(OS_CHROMEOS)
#include "chrome/browser/chromeos/apps/apk_web_app_service.h"

namespace {
constexpr char kRelationship[] = "delegate_permission/common.handle_all_urls";
}
#endif

namespace web_app {

WebAppBrowserController::WebAppBrowserController(Browser* browser)
    : AppBrowserController(browser,
                           GetAppIdFromApplicationName(browser->app_name())),
      provider_(*WebAppProvider::Get(browser->profile())) {
  registrar_observer_.Add(&provider_.registrar());
  PerformDigitalAssetLinkVerification(browser);
}

WebAppBrowserController::~WebAppBrowserController() = default;

bool WebAppBrowserController::HasMinimalUiButtons() const {
  return registrar().GetAppEffectiveDisplayMode(GetAppId()) ==
         DisplayMode::kMinimalUi;
}

bool WebAppBrowserController::IsHostedApp() const {
  return true;
}

#if defined(OS_CHROMEOS)
bool WebAppBrowserController::ShouldShowCustomTabBar() const {
  if (AppBrowserController::ShouldShowCustomTabBar())
    return true;

  return is_verified_.value_or(false);
}

void WebAppBrowserController::OnRelationshipCheckComplete(
    digital_asset_links::RelationshipCheckResult result) {
  bool should_show_cct = false;
  switch (result) {
    case digital_asset_links::RelationshipCheckResult::kSuccess:
      should_show_cct = false;
      break;
    case digital_asset_links::RelationshipCheckResult::kFailure:
    case digital_asset_links::RelationshipCheckResult::kNoConnection:
      should_show_cct = true;
      break;
  }
  is_verified_ = should_show_cct;
  browser()->window()->UpdateCustomTabBarVisibility(should_show_cct,
                                                    false /* animate */);
}
#endif  // OS_CHROMEOS

void WebAppBrowserController::OnWebAppUninstalled(const AppId& app_id) {
  if (HasAppId() && app_id == GetAppId())
    chrome::CloseWindow(browser());
}

void WebAppBrowserController::OnAppRegistrarDestroyed() {
  registrar_observer_.RemoveAll();
}

void WebAppBrowserController::SetReadIconCallbackForTesting(
    base::OnceClosure callback) {
  callback_for_testing_ = std::move(callback);
}

gfx::ImageSkia WebAppBrowserController::GetWindowAppIcon() const {
  if (app_icon_)
    return *app_icon_;
  app_icon_ = GetFallbackAppIcon();

  if (provider_.icon_manager().HasSmallestIcon(GetAppId(),
                                               web_app::kWebAppIconSmall)) {
    provider_.icon_manager().ReadSmallestIcon(
        GetAppId(), web_app::kWebAppIconSmall,
        base::BindOnce(&WebAppBrowserController::OnReadIcon,
                       weak_ptr_factory_.GetWeakPtr()));
  }

  return *app_icon_;
}

gfx::ImageSkia WebAppBrowserController::GetWindowIcon() const {
  return GetWindowAppIcon();
}

base::Optional<SkColor> WebAppBrowserController::GetThemeColor() const {
  // System App popups (settings pages) always use default theme.
  if (is_for_system_web_app() && browser()->is_type_app_popup())
    return base::nullopt;

  base::Optional<SkColor> web_theme_color =
      AppBrowserController::GetThemeColor();
  if (web_theme_color)
    return web_theme_color;

  return registrar().GetAppThemeColor(GetAppId());
}

GURL WebAppBrowserController::GetAppLaunchURL() const {
  return registrar().GetAppLaunchURL(GetAppId());
}

bool WebAppBrowserController::IsUrlInAppScope(const GURL& url) const {
  GURL app_scope = registrar().GetAppScope(GetAppId());
  if (!app_scope.is_valid())
    return false;

  // https://w3c.github.io/manifest/#navigation-scope
  // If url is same origin as scope and url path starts with scope path, return
  // true. Otherwise, return false.
  if (app_scope.GetOrigin() != url.GetOrigin()) {
    // We allow an upgrade from http |app_scope| to https |url|.
    if (app_scope.scheme() != url::kHttpScheme)
      return false;

    GURL::Replacements rep;
    rep.SetSchemeStr(url::kHttpsScheme);
    GURL secure_app_scope = app_scope.ReplaceComponents(rep);
    if (secure_app_scope.GetOrigin() != url.GetOrigin())
      return false;
  }

  std::string scope_path = app_scope.path();
  std::string url_path = url.path();
  return base::StartsWith(url_path, scope_path, base::CompareCase::SENSITIVE);
}

WebAppBrowserController* WebAppBrowserController::AsWebAppBrowserController() {
  return this;
}

base::string16 WebAppBrowserController::GetTitle() const {
  // When showing the toolbar, display the name of the app, instead of the
  // current page as the title.
  if (ShouldShowCustomTabBar()) {
    // TODO(crbug.com/1051379): Use name instead of short_name.
    return base::UTF8ToUTF16(registrar().GetAppShortName(GetAppId()));
  }

  return AppBrowserController::GetTitle();
}

std::string WebAppBrowserController::GetAppShortName() const {
  return registrar().GetAppShortName(GetAppId());
}

base::string16 WebAppBrowserController::GetFormattedUrlOrigin() const {
  return FormatUrlOrigin(GetAppLaunchURL());
}

bool WebAppBrowserController::CanUninstall() const {
  return WebAppUiManagerImpl::Get(browser()->profile())
      ->dialog_manager()
      .CanUninstallWebApp(GetAppId());
}

void WebAppBrowserController::Uninstall() {
  WebAppUiManagerImpl::Get(browser()->profile())
      ->dialog_manager()
      .UninstallWebApp(GetAppId(),
                       WebAppDialogManager::UninstallSource::kAppMenu,
                       browser()->window(), base::DoNothing());
}

bool WebAppBrowserController::IsInstalled() const {
  return registrar().IsInstalled(GetAppId());
}

void WebAppBrowserController::OnTabInserted(content::WebContents* contents) {
  AppBrowserController::OnTabInserted(contents);
  web_app::SetAppPrefsForWebContents(contents);
}

void WebAppBrowserController::OnTabRemoved(content::WebContents* contents) {
  AppBrowserController::OnTabRemoved(contents);
  web_app::ClearAppPrefsForWebContents(contents);
}

const AppRegistrar& WebAppBrowserController::registrar() const {
  return provider_.registrar();
}

void WebAppBrowserController::OnReadIcon(const SkBitmap& bitmap) {
  if (bitmap.empty()) {
    DLOG(ERROR) << "Failed to read icon for web app";
    return;
  }

  app_icon_ = gfx::ImageSkia::CreateFrom1xBitmap(bitmap);
  if (auto* contents = web_contents())
    contents->NotifyNavigationStateChanged(content::INVALIDATE_TYPE_TAB);
  if (callback_for_testing_)
    std::move(callback_for_testing_).Run();
}

void WebAppBrowserController::PerformDigitalAssetLinkVerification(
    Browser* browser) {
#if defined(OS_CHROMEOS)
  asset_link_handler_ =
      std::make_unique<digital_asset_links::DigitalAssetLinksHandler>(
          browser->profile()->GetURLLoaderFactory());
  is_verified_ = base::nullopt;

  if (!HasAppId())
    return;

  chromeos::ApkWebAppService* apk_web_app_service =
      chromeos::ApkWebAppService::Get(browser->profile());
  if (!apk_web_app_service || !apk_web_app_service->IsWebOnlyTwa(GetAppId()))
    return;

  const std::string origin = GetAppLaunchURL().GetOrigin().spec();
  const base::Optional<std::string> package_name =
      apk_web_app_service->GetPackageNameForWebApp(GetAppId());
  const base::Optional<std::string> fingerprint =
      apk_web_app_service->GetCertificateSha256Fingerprint(GetAppId());

  // Any web-only TWA should have an associated package name and fingerprint.
  DCHECK(package_name.has_value());
  DCHECK(fingerprint.has_value());

  // base::Unretained is safe as |asset_link_handler_| is owned by this object
  // and will be destroyed if this object is destroyed.
  asset_link_handler_->CheckDigitalAssetLinkRelationshipForAndroidApp(
      origin, kRelationship, fingerprint.value(), package_name.value(),
      base::BindOnce(&WebAppBrowserController::OnRelationshipCheckComplete,
                     base::Unretained(this)));
#endif
}
}  // namespace web_app
