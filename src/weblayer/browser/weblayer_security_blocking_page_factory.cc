// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "weblayer/browser/weblayer_security_blocking_page_factory.h"

#include "components/captive_portal/core/buildflags.h"
#include "components/security_interstitials/content/content_metrics_helper.h"
#include "components/security_interstitials/content/ssl_blocking_page.h"
#include "components/security_interstitials/core/metrics_helper.h"
#include "content/public/browser/web_contents.h"
#include "weblayer/browser/captive_portal_service_factory.h"
#include "weblayer/browser/ssl_error_controller_client.h"

#if defined(OS_ANDROID)
#include "content/public/browser/page_navigator.h"
#include "content/public/browser/web_contents.h"
#include "content/public/common/referrer.h"
#include "ui/base/window_open_disposition.h"
#endif

namespace weblayer {

namespace {

#if defined(OS_ANDROID)
GURL GetCaptivePortalLoginPageUrlInternal() {
  // NOTE: This is taken from the default login URL in //chrome's
  // CaptivePortalHelper.java, which is used in the implementation referenced
  // in OpenLoginPage() below.
  return GURL("http://connectivitycheck.gstatic.com/generate_204");
}
#endif

void OpenLoginPage(content::WebContents* web_contents) {
  // TODO(https://crbug.com/1030692): Componentize and share the
  // Android implementation from //chrome's
  // ChromeSecurityBlockingPageFactory::OpenLoginPage(), from which this is
  // adapted.
#if defined(OS_ANDROID)
  // In Chrome this opens in a new tab, but WebLayer's TabImpl has no support
  // for opening new tabs (its OpenURLFromTab() method DCHECKs if the
  // disposition is not |CURRENT_TAB|).
  // TODO(crbug.com/1047130): Revisit if TabImpl gets support for opening URLs
  // in new tabs.
  content::OpenURLParams params(
      GetCaptivePortalLoginPageUrlInternal(), content::Referrer(),
      WindowOpenDisposition::CURRENT_TAB, ui::PAGE_TRANSITION_LINK, false);
  web_contents->OpenURL(params);
#else
  NOTIMPLEMENTED();
#endif
}

std::unique_ptr<security_interstitials::MetricsHelper>
CreateMetricsHelperAndStartRecording(content::WebContents* web_contents,
                                     const GURL& request_url,
                                     const std::string& metric_prefix,
                                     bool overridable) {
  security_interstitials::MetricsHelper::ReportDetails report_details;
  report_details.metric_prefix = metric_prefix;
  auto metrics_helper = std::make_unique<ContentMetricsHelper>(
      /*history_service=*/nullptr, request_url, report_details);
#if BUILDFLAG(ENABLE_CAPTIVE_PORTAL_DETECTION)
  metrics_helper.get()->StartRecordingCaptivePortalMetrics(
      CaptivePortalServiceFactory::GetForBrowserContext(
          web_contents->GetBrowserContext()),
      overridable);
#endif

  return metrics_helper;
}

}  // namespace

std::unique_ptr<SSLBlockingPage>
WebLayerSecurityBlockingPageFactory::CreateSSLPage(
    content::WebContents* web_contents,
    int cert_error,
    const net::SSLInfo& ssl_info,
    const GURL& request_url,
    int options_mask,
    const base::Time& time_triggered,
    const GURL& support_url,
    std::unique_ptr<SSLCertReporter> ssl_cert_reporter) {
  bool overridable = SSLBlockingPage::IsOverridable(options_mask);

  auto controller_client = std::make_unique<SSLErrorControllerClient>(
      web_contents, cert_error, ssl_info, request_url,
      CreateMetricsHelperAndStartRecording(
          web_contents, request_url,
          overridable ? "ssl_overridable" : "ssl_nonoverridable", overridable));

  auto interstitial_page = std::make_unique<SSLBlockingPage>(
      web_contents, cert_error, ssl_info, request_url, options_mask,
      base::Time::NowFromSystemTime(), /*support_url=*/GURL(),
      std::move(ssl_cert_reporter), overridable, std::move(controller_client));

  return interstitial_page;
}

std::unique_ptr<CaptivePortalBlockingPage>
WebLayerSecurityBlockingPageFactory::CreateCaptivePortalBlockingPage(
    content::WebContents* web_contents,
    const GURL& request_url,
    const GURL& login_url,
    std::unique_ptr<SSLCertReporter> ssl_cert_reporter,
    const net::SSLInfo& ssl_info,
    int cert_error) {
  auto controller_client = std::make_unique<SSLErrorControllerClient>(
      web_contents, cert_error, ssl_info, request_url,
      CreateMetricsHelperAndStartRecording(web_contents, request_url,
                                           "captive_portal", false));

  auto interstitial_page = std::make_unique<CaptivePortalBlockingPage>(
      web_contents, request_url, login_url, std::move(ssl_cert_reporter),
      ssl_info, std::move(controller_client),
      base::BindRepeating(&OpenLoginPage));

  return interstitial_page;
}

std::unique_ptr<BadClockBlockingPage>
WebLayerSecurityBlockingPageFactory::CreateBadClockBlockingPage(
    content::WebContents* web_contents,
    int cert_error,
    const net::SSLInfo& ssl_info,
    const GURL& request_url,
    const base::Time& time_triggered,
    ssl_errors::ClockState clock_state,
    std::unique_ptr<SSLCertReporter> ssl_cert_reporter) {
  auto controller_client = std::make_unique<SSLErrorControllerClient>(
      web_contents, cert_error, ssl_info, request_url,
      CreateMetricsHelperAndStartRecording(web_contents, request_url,
                                           "bad_clock", false));

  auto interstitial_page = std::make_unique<BadClockBlockingPage>(
      web_contents, cert_error, ssl_info, request_url,
      base::Time::NowFromSystemTime(), clock_state,
      std::move(ssl_cert_reporter), std::move(controller_client));

  return interstitial_page;
}

std::unique_ptr<LegacyTLSBlockingPage>
WebLayerSecurityBlockingPageFactory::CreateLegacyTLSBlockingPage(
    content::WebContents* web_contents,
    int cert_error,
    const GURL& request_url,
    std::unique_ptr<SSLCertReporter> ssl_cert_reporter,
    const net::SSLInfo& ssl_info) {
  auto controller_client = std::make_unique<SSLErrorControllerClient>(
      web_contents, cert_error, ssl_info, request_url,
      CreateMetricsHelperAndStartRecording(web_contents, request_url,
                                           "legacy_tls", false));

  auto interstitial_page = std::make_unique<LegacyTLSBlockingPage>(
      web_contents, cert_error, request_url, std::move(ssl_cert_reporter),
      ssl_info, std::move(controller_client));

  return interstitial_page;
}

std::unique_ptr<MITMSoftwareBlockingPage>
WebLayerSecurityBlockingPageFactory::CreateMITMSoftwareBlockingPage(
    content::WebContents* web_contents,
    int cert_error,
    const GURL& request_url,
    std::unique_ptr<SSLCertReporter> ssl_cert_reporter,
    const net::SSLInfo& ssl_info,
    const std::string& mitm_software_name) {
  auto controller_client = std::make_unique<SSLErrorControllerClient>(
      web_contents, cert_error, ssl_info, request_url,
      CreateMetricsHelperAndStartRecording(web_contents, request_url,
                                           "mitm_software", false));

  auto interstitial_page = std::make_unique<MITMSoftwareBlockingPage>(
      web_contents, cert_error, request_url, std::move(ssl_cert_reporter),
      ssl_info, mitm_software_name, /*is_enterprise_managed=*/false,
      std::move(controller_client));

  return interstitial_page;
}

std::unique_ptr<BlockedInterceptionBlockingPage>
WebLayerSecurityBlockingPageFactory::CreateBlockedInterceptionBlockingPage(
    content::WebContents* web_contents,
    int cert_error,
    const GURL& request_url,
    std::unique_ptr<SSLCertReporter> ssl_cert_reporter,
    const net::SSLInfo& ssl_info) {
  auto controller_client = std::make_unique<SSLErrorControllerClient>(
      web_contents, cert_error, ssl_info, request_url,
      CreateMetricsHelperAndStartRecording(web_contents, request_url,
                                           "blocked_interception", false));

  auto interstitial_page = std::make_unique<BlockedInterceptionBlockingPage>(
      web_contents, cert_error, request_url, std::move(ssl_cert_reporter),
      ssl_info, std::move(controller_client));

  return interstitial_page;
}

std::unique_ptr<security_interstitials::InsecureFormBlockingPage>
WebLayerSecurityBlockingPageFactory::CreateInsecureFormBlockingPage(
    content::WebContents* web_contents,
    const GURL& request_url) {
  // TODO(crbug.com/1093102): Insecure form warnings are not yet implemented in
  // Weblayer.
  NOTREACHED();
  return nullptr;
}

#if defined(OS_ANDROID)
// static
GURL WebLayerSecurityBlockingPageFactory::
    GetCaptivePortalLoginPageUrlForTesting() {
  return GetCaptivePortalLoginPageUrlInternal();
}
#endif

}  // namespace weblayer
