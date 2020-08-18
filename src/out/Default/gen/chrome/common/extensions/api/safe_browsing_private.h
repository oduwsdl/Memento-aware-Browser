// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/safe_browsing_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_SAFE_BROWSING_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_SAFE_BROWSING_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace safe_browsing_private {

//
// Types
//

enum URLType {
  URL_TYPE_NONE,
  URL_TYPE_EVENT_URL,
  URL_TYPE_LANDING_PAGE,
  URL_TYPE_LANDING_REFERRER,
  URL_TYPE_CLIENT_REDIRECT,
  URL_TYPE_RECENT_NAVIGATION,
  URL_TYPE_REFERRER,
  URL_TYPE_LAST = URL_TYPE_REFERRER,
};


const char* ToString(URLType as_enum);
URLType ParseURLType(const std::string& as_string);

enum NavigationInitiation {
  NAVIGATION_INITIATION_NONE,
  NAVIGATION_INITIATION_BROWSER_INITIATED,
  NAVIGATION_INITIATION_RENDERER_INITIATED_WITHOUT_USER_GESTURE,
  NAVIGATION_INITIATION_RENDERER_INITIATED_WITH_USER_GESTURE,
  NAVIGATION_INITIATION_LAST = NAVIGATION_INITIATION_RENDERER_INITIATED_WITH_USER_GESTURE,
};


const char* ToString(NavigationInitiation as_enum);
NavigationInitiation ParseNavigationInitiation(const std::string& as_string);

struct PolicySpecifiedPasswordReuse {
  PolicySpecifiedPasswordReuse();
  ~PolicySpecifiedPasswordReuse();
  PolicySpecifiedPasswordReuse(PolicySpecifiedPasswordReuse&& rhs);
  PolicySpecifiedPasswordReuse& operator=(PolicySpecifiedPasswordReuse&& rhs);

  // Populates a PolicySpecifiedPasswordReuse object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, PolicySpecifiedPasswordReuse* out);

  // Creates a PolicySpecifiedPasswordReuse object from a base::Value, or NULL
  // on failure.
  static std::unique_ptr<PolicySpecifiedPasswordReuse> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PolicySpecifiedPasswordReuse object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // URL where this reuse happened.
  std::string url;

  // The user name of the policy specified password.
  std::string user_name;

  // If this a phishing url.
  bool is_phishing_url;


 private:
  DISALLOW_COPY_AND_ASSIGN(PolicySpecifiedPasswordReuse);
};

struct DangerousDownloadInfo {
  DangerousDownloadInfo();
  ~DangerousDownloadInfo();
  DangerousDownloadInfo(DangerousDownloadInfo&& rhs);
  DangerousDownloadInfo& operator=(DangerousDownloadInfo&& rhs);

  // Populates a DangerousDownloadInfo object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, DangerousDownloadInfo* out);

  // Creates a DangerousDownloadInfo object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<DangerousDownloadInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DangerousDownloadInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // URL of the download.
  std::string url;

  // File name and path of the download on user's machine.
  std::string file_name;

  // SHA256 digest of this download.
  std::string download_digest_sha256;

  // User name of the profile. Empty string if user name not available.
  std::string user_name;


 private:
  DISALLOW_COPY_AND_ASSIGN(DangerousDownloadInfo);
};

struct InterstitialInfo {
  InterstitialInfo();
  ~InterstitialInfo();
  InterstitialInfo(InterstitialInfo&& rhs);
  InterstitialInfo& operator=(InterstitialInfo&& rhs);

  // Populates a InterstitialInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, InterstitialInfo* out);

  // Creates a InterstitialInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<InterstitialInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this InterstitialInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Top level URL that triggers this interstitial.
  std::string url;

  // Human-readable string indicate why this interstitial is shown.
  std::string reason;

  // Net error code.
  std::unique_ptr<std::string> net_error_code;

  // User name of the profile. Empty string if user name not available.
  std::string user_name;


 private:
  DISALLOW_COPY_AND_ASSIGN(InterstitialInfo);
};

struct ServerRedirect {
  ServerRedirect();
  ~ServerRedirect();
  ServerRedirect(ServerRedirect&& rhs);
  ServerRedirect& operator=(ServerRedirect&& rhs);

  // Populates a ServerRedirect object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ServerRedirect* out);

  // Creates a ServerRedirect object from a base::Value, or NULL on failure.
  static std::unique_ptr<ServerRedirect> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ServerRedirect object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Server redirect URL.
  std::unique_ptr<std::string> url;


 private:
  DISALLOW_COPY_AND_ASSIGN(ServerRedirect);
};

struct ReferrerChainEntry {
  ReferrerChainEntry();
  ~ReferrerChainEntry();
  ReferrerChainEntry(ReferrerChainEntry&& rhs);
  ReferrerChainEntry& operator=(ReferrerChainEntry&& rhs);

  // Populates a ReferrerChainEntry object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ReferrerChainEntry* out);

  // Creates a ReferrerChainEntry object from a base::Value, or NULL on failure.
  static std::unique_ptr<ReferrerChainEntry> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ReferrerChainEntry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // URL of this entry.
  std::string url;

  // Only set if different from |url|.
  std::unique_ptr<std::string> main_frame_url;

  // Types of URLs, such as event url, landing page, etc.
  URLType url_type;

  // IP addresses corresponding to this host.
  std::unique_ptr<std::vector<std::string>> ip_addresses;

  // Referrer URL of this entry.
  std::unique_ptr<std::string> referrer_url;

  // Main frame URL of referrer. Only set if different from |referrer_url|.
  std::unique_ptr<std::string> referrer_main_frame_url;

  // If this URL loads in a different tab/frame from previous one.
  std::unique_ptr<bool> is_retargeting;

  std::unique_ptr<double> navigation_time_ms;

  // Set only if server redirects happened in navigation.
  std::unique_ptr<std::vector<ServerRedirect>> server_redirect_chain;

  // How this navigation is initiated.
  NavigationInitiation navigation_initiation;

  // Whether this entry may have been launched by an external application.
  std::unique_ptr<bool> maybe_launched_by_external_app;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReferrerChainEntry);
};


//
// Functions
//

namespace GetReferrerChain {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Id of the tab from which to retrieve the referrer.
  int tab_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<ReferrerChainEntry>& entries);
}  // namespace Results

}  // namespace GetReferrerChain

//
// Events
//

namespace OnPolicySpecifiedPasswordReuseDetected {

extern const char kEventName[];  // "safeBrowsingPrivate.onPolicySpecifiedPasswordReuseDetected"

// Details about where the password reuse occurred.
std::unique_ptr<base::ListValue> Create(const PolicySpecifiedPasswordReuse& reuse_details);
}  // namespace OnPolicySpecifiedPasswordReuseDetected

namespace OnPolicySpecifiedPasswordChanged {

extern const char kEventName[];  // "safeBrowsingPrivate.onPolicySpecifiedPasswordChanged"

// The user name of the policy specified password.
std::unique_ptr<base::ListValue> Create(const std::string& user_name);
}  // namespace OnPolicySpecifiedPasswordChanged

namespace OnDangerousDownloadOpened {

extern const char kEventName[];  // "safeBrowsingPrivate.onDangerousDownloadOpened"

std::unique_ptr<base::ListValue> Create(const DangerousDownloadInfo& dict);
}  // namespace OnDangerousDownloadOpened

namespace OnSecurityInterstitialShown {

extern const char kEventName[];  // "safeBrowsingPrivate.onSecurityInterstitialShown"

std::unique_ptr<base::ListValue> Create(const InterstitialInfo& dict);
}  // namespace OnSecurityInterstitialShown

namespace OnSecurityInterstitialProceeded {

extern const char kEventName[];  // "safeBrowsingPrivate.onSecurityInterstitialProceeded"

std::unique_ptr<base::ListValue> Create(const InterstitialInfo& dict);
}  // namespace OnSecurityInterstitialProceeded

}  // namespace safe_browsing_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_SAFE_BROWSING_PRIVATE_H__
