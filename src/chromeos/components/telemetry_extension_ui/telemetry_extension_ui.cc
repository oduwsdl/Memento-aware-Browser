// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chromeos/components/telemetry_extension_ui/telemetry_extension_ui.h"

#include <utility>

#include "base/memory/ptr_util.h"
#include "chromeos/components/telemetry_extension_ui/mojom/probe_service.mojom.h"
#include "chromeos/components/telemetry_extension_ui/probe_service.h"
#include "chromeos/components/telemetry_extension_ui/url_constants.h"
#include "chromeos/grit/chromeos_telemetry_extension_resources.h"
#include "content/public/browser/web_contents.h"
#include "content/public/browser/web_ui.h"
#include "content/public/browser/web_ui_data_source.h"
#include "content/public/common/url_constants.h"

namespace chromeos {
namespace {
content::WebUIDataSource* CreateUntrustedTelemetryExtensionDataSource() {
  content::WebUIDataSource* untrusted_source =
      content::WebUIDataSource::Create(kChromeUIUntrustedTelemetryExtensionURL);
  untrusted_source->AddResourcePath("untrusted.html",
                                    IDR_TELEMETRY_EXTENSION_UNTRUSTED_HTML);
  untrusted_source->AddResourcePath("untrusted.js",
                                    IDR_TELEMETRY_EXTENSION_UNTRUSTED_JS);
  untrusted_source->AddFrameAncestor(GURL(kChromeUITelemetryExtensionURL));

  // TODO(https://crbug.com/1085330): tighten CSP.
  untrusted_source->OverrideContentSecurityPolicyDefaultSrc(std::string());

  return untrusted_source;
}
}  // namespace

TelemetryExtensionUI::TelemetryExtensionUI(content::WebUI* web_ui)
    : ui::MojoWebUIController(web_ui) {
  auto trusted_source = base::WrapUnique(
      content::WebUIDataSource::Create(kChromeUITelemetryExtensionHost));

  trusted_source->AddResourcePath("", IDR_TELEMETRY_EXTENSION_INDEX_HTML);
  trusted_source->AddResourcePath("pwa.html", IDR_TELEMETRY_EXTENSION_PWA_HTML);
  trusted_source->AddResourcePath("manifest.json",
                                  IDR_TELEMETRY_EXTENSION_MANIFEST);
  trusted_source->AddResourcePath("app_icon_96.png",
                                  IDR_TELEMETRY_EXTENSION_ICON_96);
  trusted_source->AddResourcePath("trusted.js",
                                  IDR_TELEMETRY_EXTENSION_TRUSTED_JS);
  trusted_source->AddResourcePath(
      "probe_service.mojom-lite.js",
      IDR_TELEMETRY_EXTENSION_PROBE_SERVICE_MOJO_LITE_JS);

#if !DCHECK_IS_ON()
  // If a user goes to an invalid url and non-DCHECK mode (DHECK = debug mode)
  // is set, serve a default page so the user sees your default page instead
  // of an unexpected error. But if DCHECK is set, the user will be a
  // developer and be able to identify an error occurred.
  trusted_source->SetDefaultResource(IDR_TELEMETRY_EXTENSION_INDEX_HTML);
#endif  // !DCHECK_IS_ON()

  // We need a CSP override to use the chrome-untrusted:// scheme in the host.
  std::string csp =
      std::string("frame-src ") + kChromeUIUntrustedTelemetryExtensionURL + ";";
  trusted_source->OverrideContentSecurityPolicyChildSrc(csp);
  auto* browser_context = web_ui->GetWebContents()->GetBrowserContext();
  content::WebUIDataSource::Add(browser_context, trusted_source.release());
  content::WebUIDataSource::Add(browser_context,
                                CreateUntrustedTelemetryExtensionDataSource());

  // Add ability to request chrome-untrusted: URLs
  web_ui->AddRequestableScheme(content::kChromeUIUntrustedScheme);
}

TelemetryExtensionUI::~TelemetryExtensionUI() = default;

void TelemetryExtensionUI::BindInterface(
    mojo::PendingReceiver<health::mojom::ProbeService> receiver) {
  probe_service_ = std::make_unique<ProbeService>(std::move(receiver));
}

WEB_UI_CONTROLLER_TYPE_IMPL(TelemetryExtensionUI)

}  // namespace chromeos
