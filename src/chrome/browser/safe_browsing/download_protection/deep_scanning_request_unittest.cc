// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/safe_browsing/download_protection/deep_scanning_request.h"

#include "base/bind.h"
#include "base/bind_helpers.h"
#include "base/files/scoped_temp_dir.h"
#include "base/test/scoped_feature_list.h"
#include "chrome/browser/browser_process.h"
#include "chrome/browser/enterprise/connectors/common.h"
#include "chrome/browser/enterprise/connectors/connectors_manager.h"
#include "chrome/browser/enterprise/connectors/connectors_prefs.h"
#include "chrome/browser/extensions/api/safe_browsing_private/safe_browsing_private_event_router.h"
#include "chrome/browser/extensions/api/safe_browsing_private/safe_browsing_private_event_router_factory.h"
#include "chrome/browser/safe_browsing/cloud_content_scanning/binary_fcm_service.h"
#include "chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.h"
#include "chrome/browser/safe_browsing/cloud_content_scanning/deep_scanning_test_utils.h"
#include "chrome/browser/safe_browsing/cloud_content_scanning/deep_scanning_utils.h"
#include "chrome/browser/safe_browsing/dm_token_utils.h"
#include "chrome/browser/safe_browsing/download_protection/download_protection_service.h"
#include "chrome/browser/safe_browsing/download_protection/download_protection_util.h"
#include "chrome/browser/safe_browsing/test_extension_event_observer.h"
#include "chrome/test/base/testing_browser_process.h"
#include "chrome/test/base/testing_profile.h"
#include "chrome/test/base/testing_profile_manager.h"
#include "components/download/public/common/mock_download_item.h"
#include "components/policy/core/common/cloud/dm_token.h"
#include "components/policy/core/common/cloud/mock_cloud_policy_client.h"
#include "components/prefs/pref_service.h"
#include "components/prefs/scoped_user_pref_update.h"
#include "components/safe_browsing/core/common/safe_browsing_prefs.h"
#include "components/safe_browsing/core/features.h"
#include "components/safe_browsing/core/proto/webprotect.pb.h"
#include "content/public/browser/browser_task_traits.h"
#include "content/public/browser/download_item_utils.h"
#include "content/public/test/browser_task_environment.h"
#include "crypto/sha2.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace safe_browsing {

using ::testing::Return;
using ::testing::ReturnRef;

namespace {

const std::set<std::string>* ExeMimeTypes() {
  static std::set<std::string> set = {"application/x-msdownload",
                                      "application/x-ms-dos-executable",
                                      "application/octet-stream"};
  return &set;
}

}  // namespace

class FakeBinaryUploadService : public BinaryUploadService {
 public:
  FakeBinaryUploadService()
      : BinaryUploadService(/*url_loader_factory=*/nullptr,
                            /*profile=*/nullptr,
                            /*binary_fcm_service=*/nullptr),
        saved_result_(BinaryUploadService::Result::UNKNOWN),
        saved_response_(DeepScanningClientResponse()) {}

  void MaybeUploadForDeepScanning(std::unique_ptr<Request> request) override {
    last_request_ = request->deep_scanning_request();
    request->FinishLegacyRequest(saved_result_, saved_response_);
  }

  void SetResponse(BinaryUploadService::Result result,
                   DeepScanningClientResponse response) {
    saved_result_ = result;
    saved_response_ = response;
  }

  const DeepScanningClientRequest& last_request() { return last_request_; }

 private:
  BinaryUploadService::Result saved_result_;
  DeepScanningClientResponse saved_response_;
  DeepScanningClientRequest last_request_;
};

class FakeDownloadProtectionService : public DownloadProtectionService {
 public:
  FakeDownloadProtectionService() : DownloadProtectionService(nullptr) {}

  void RequestFinished(DeepScanningRequest* request) override {}

  BinaryUploadService* GetBinaryUploadService(Profile* profile) override {
    return &binary_upload_service_;
  }

  FakeBinaryUploadService* GetFakeBinaryUploadService() {
    return &binary_upload_service_;
  }

 private:
  FakeBinaryUploadService binary_upload_service_;
};

class DeepScanningRequestTest : public testing::TestWithParam<bool> {
 public:
  DeepScanningRequestTest()
      : profile_manager_(TestingBrowserProcess::GetGlobal()) {
    EXPECT_TRUE(profile_manager_.SetUp());
    profile_ = profile_manager_.CreateTestingProfile("test-user");
  }

  bool use_legacy_policies() { return GetParam(); }

  void SetUp() override {
    ASSERT_TRUE(temp_dir_.CreateUniqueTempDir());

    download_path_ = temp_dir_.GetPath().AppendASCII("download.exe");
    std::string download_contents = "download contents";
    download_hash_ = crypto::SHA256HashString(download_contents);
    tab_url_string_ = "https://example.com/";
    download_url_ = GURL("https://example.com/download.exe");
    tab_url_ = GURL(tab_url_string_);

    base::File download(download_path_,
                        base::File::FLAG_CREATE | base::File::FLAG_WRITE);
    download.WriteAtCurrentPos(download_contents.c_str(),
                               download_contents.size());
    download.Close();

    EXPECT_CALL(item_, GetFullPath()).WillRepeatedly(ReturnRef(download_path_));
    EXPECT_CALL(item_, GetTotalBytes())
        .WillRepeatedly(Return(download_contents.size()));
    EXPECT_CALL(item_, GetURL()).WillRepeatedly(ReturnRef(download_url_));
    EXPECT_CALL(item_, GetTabUrl()).WillRepeatedly(ReturnRef(tab_url_));
    EXPECT_CALL(item_, GetHash()).WillRepeatedly(ReturnRef(download_hash_));
    EXPECT_CALL(item_, GetTargetFilePath())
        .WillRepeatedly(ReturnRef(download_path_));
    EXPECT_CALL(item_, GetMimeType())
        .WillRepeatedly(Return("application/octet-stream"));
    content::DownloadItemUtils::AttachInfo(&item_, profile_, nullptr);

    SetDMTokenForTesting(
        policy::DMToken::CreateValidTokenForTesting("dm_token"));

    enterprise_connectors::ConnectorsManager::GetInstance()->SetUpForTesting();

    AddUrlToList(prefs::kURLsToCheckComplianceOfDownloadedContent, tab_url_);
  }

  void TearDown() override {
    SetDMTokenForTesting(policy::DMToken::CreateEmptyTokenForTesting());
    enterprise_connectors::ConnectorsManager::GetInstance()
        ->TearDownForTesting();
  }

  void SetDlpPolicy(CheckContentComplianceValues state) {
    if (use_legacy_policies()) {
      TestingBrowserProcess::GetGlobal()->local_state()->SetInteger(
          prefs::kCheckContentCompliance, state);
    } else {
      SetDlpPolicyForConnectors(state);
    }
  }

  void SetMalwarePolicy(SendFilesForMalwareCheckValues state) {
    if (use_legacy_policies()) {
      profile_->GetPrefs()->SetInteger(
          prefs::kSafeBrowsingSendFilesForMalwareCheck, state);
    } else {
      SetMalwarePolicyForConnectors(state);
    }
  }

  void AddUrlToList(const char* pref_name, const GURL& url) {
    if (use_legacy_policies()) {
      ListPrefUpdate(TestingBrowserProcess::GetGlobal()->local_state(),
                     pref_name)
          ->Append(url.host());
    } else {
      AddUrlToListForConnectors(pref_name, url.host());
    }
  }

  void AddUrlToProfilePrefList(const char* pref_name, const GURL& url) {
    ListPrefUpdate(profile_->GetPrefs(), pref_name)->Append(url.host());
  }

  void SetFeatures(const std::vector<base::Feature>& enabled,
                   const std::vector<base::Feature>& disabled) {
    scoped_feature_list_.Reset();
    scoped_feature_list_.InitWithFeatures(enabled, disabled);
  }

  const std::vector<base::Feature> AllFeatures() {
    if (use_legacy_policies()) {
      return {kMalwareScanEnabled, kContentComplianceEnabled};
    } else {
      return {kMalwareScanEnabled, kContentComplianceEnabled,
              enterprise_connectors::kEnterpriseConnectorsEnabled};
    }
  }

  const std::vector<base::Feature> DlpFeatures() {
    if (use_legacy_policies()) {
      return {kContentComplianceEnabled};
    } else {
      return {kContentComplianceEnabled,
              enterprise_connectors::kEnterpriseConnectorsEnabled};
    }
  }

  const std::vector<base::Feature> MalwareFeatures() {
    if (use_legacy_policies()) {
      return {kMalwareScanEnabled};
    } else {
      return {kMalwareScanEnabled,
              enterprise_connectors::kEnterpriseConnectorsEnabled};
    }
  }

  void ValidateDefaultSettings(
      const base::Optional<enterprise_connectors::AnalysisSettings>& settings) {
    ASSERT_TRUE(settings.has_value());

    enterprise_connectors::AnalysisSettings default_settings;
    default_settings.tags = {"malware"};
    if (!use_legacy_policies()) {
      default_settings.analysis_url =
          GURL("https://safebrowsing.google.com/safebrowsing/uploads/scan");
    }

    ASSERT_EQ(settings.value().tags, default_settings.tags);
    ASSERT_EQ(settings.value().block_large_files,
              default_settings.block_large_files);
    ASSERT_EQ(settings.value().block_password_protected_files,
              default_settings.block_password_protected_files);
    ASSERT_EQ(settings.value().block_unsupported_file_types,
              default_settings.block_unsupported_file_types);
    ASSERT_EQ(settings.value().block_until_verdict,
              default_settings.block_until_verdict);
    ASSERT_EQ(settings.value().analysis_url, default_settings.analysis_url);
  }

  void SetLastResult(DownloadCheckResult result) { last_result_ = result; }

  base::Optional<enterprise_connectors::AnalysisSettings> settings() {
    // Clear the cache before getting settings so there's no race with the pref
    // change and the cached values being updated.
    if (!use_legacy_policies()) {
      enterprise_connectors::ConnectorsManager::GetInstance()
          ->ClearCacheForTesting();
    }

    return DeepScanningRequest::ShouldUploadBinary(&item_);
  }

 protected:
  content::BrowserTaskEnvironment task_environment_;
  TestingProfileManager profile_manager_;
  TestingProfile* profile_;
  base::test::ScopedFeatureList scoped_feature_list_;

  FakeDownloadProtectionService download_protection_service_;
  download::MockDownloadItem item_;

  base::ScopedTempDir temp_dir_;
  base::FilePath download_path_;
  GURL download_url_;
  GURL tab_url_;
  std::string tab_url_string_;
  std::string download_hash_;

  DownloadCheckResult last_result_;
};

INSTANTIATE_TEST_SUITE_P(, DeepScanningRequestTest, testing::Bool());

TEST_P(DeepScanningRequestTest, ChecksFeatureFlags) {
  SetDlpPolicy(CHECK_UPLOADS_AND_DOWNLOADS);
  SetMalwarePolicy(SEND_UPLOADS_AND_DOWNLOADS);

  // Try each request with settings indicating both DLP and Malware requests
  // should be sent to show features work correctly.
  auto dlp_and_malware_settings = []() {
    enterprise_connectors::AnalysisSettings settings;
    settings.tags = {"dlp", "malware"};
    return settings;
  };

  {
    SetFeatures(/*enabled*/ AllFeatures(),
                /*disabled*/ {});
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::DoNothing(), &download_protection_service_,
        dlp_and_malware_settings());
    request.Start();
    EXPECT_TRUE(download_protection_service_.GetFakeBinaryUploadService()
                    ->last_request()
                    .has_malware_scan_request());
    EXPECT_TRUE(download_protection_service_.GetFakeBinaryUploadService()
                    ->last_request()
                    .has_dlp_scan_request());
  }
  {
    SetFeatures(/*enabled*/ {},
                /*disabled*/ AllFeatures());
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::DoNothing(), &download_protection_service_,
        dlp_and_malware_settings());
    request.Start();
    EXPECT_FALSE(download_protection_service_.GetFakeBinaryUploadService()
                     ->last_request()
                     .has_malware_scan_request());
    EXPECT_FALSE(download_protection_service_.GetFakeBinaryUploadService()
                     ->last_request()
                     .has_dlp_scan_request());
  }
  {
    SetFeatures(/*enabled*/ DlpFeatures(),
                /*disabled*/ {kMalwareScanEnabled});
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::DoNothing(), &download_protection_service_,
        dlp_and_malware_settings());
    request.Start();
    EXPECT_FALSE(download_protection_service_.GetFakeBinaryUploadService()
                     ->last_request()
                     .has_malware_scan_request());
    EXPECT_TRUE(download_protection_service_.GetFakeBinaryUploadService()
                    ->last_request()
                    .has_dlp_scan_request());
  }
  {
    SetFeatures(/*enabled*/ MalwareFeatures(),
                /*disabled*/ {kContentComplianceEnabled});
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::DoNothing(), &download_protection_service_,
        dlp_and_malware_settings());
    request.Start();
    EXPECT_TRUE(download_protection_service_.GetFakeBinaryUploadService()
                    ->last_request()
                    .has_malware_scan_request());
    EXPECT_FALSE(download_protection_service_.GetFakeBinaryUploadService()
                     ->last_request()
                     .has_dlp_scan_request());
  }
  if (!use_legacy_policies()) {
    // Validate that the Connector feature doesn't allow scanning if the other
    // two flags are off.
    SetFeatures(
        /*enabled*/ {enterprise_connectors::kEnterpriseConnectorsEnabled},
        /*disabled*/ {kMalwareScanEnabled, kContentComplianceEnabled});
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::DoNothing(), &download_protection_service_,
        dlp_and_malware_settings());
    request.Start();
    EXPECT_FALSE(download_protection_service_.GetFakeBinaryUploadService()
                     ->last_request()
                     .has_malware_scan_request());
    EXPECT_FALSE(download_protection_service_.GetFakeBinaryUploadService()
                     ->last_request()
                     .has_dlp_scan_request());
  }
}

TEST_P(DeepScanningRequestTest, GeneratesCorrectRequestFromPolicy) {
  SetFeatures(/*enabled*/ AllFeatures(),
              /*disabled*/ {});

  {
    SetDlpPolicy(CHECK_UPLOADS_AND_DOWNLOADS);
    SetMalwarePolicy(SEND_UPLOADS_AND_DOWNLOADS);
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::DoNothing(), &download_protection_service_, settings().value());
    request.Start();
    EXPECT_TRUE(download_protection_service_.GetFakeBinaryUploadService()
                    ->last_request()
                    .has_malware_scan_request());
    EXPECT_EQ(download_protection_service_.GetFakeBinaryUploadService()
                  ->last_request()
                  .malware_scan_request()
                  .population(),
              MalwareDeepScanningClientRequest::POPULATION_ENTERPRISE);
    EXPECT_TRUE(download_protection_service_.GetFakeBinaryUploadService()
                    ->last_request()
                    .has_dlp_scan_request());
    EXPECT_EQ(download_protection_service_.GetFakeBinaryUploadService()
                  ->last_request()
                  .dlp_scan_request()
                  .url(),
              download_url_.spec());
  }

  {
    SetDlpPolicy(CHECK_NONE);
    SetMalwarePolicy(SEND_UPLOADS_AND_DOWNLOADS);
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::DoNothing(), &download_protection_service_, settings().value());
    request.Start();
    EXPECT_TRUE(download_protection_service_.GetFakeBinaryUploadService()
                    ->last_request()
                    .has_malware_scan_request());
    EXPECT_EQ(download_protection_service_.GetFakeBinaryUploadService()
                  ->last_request()
                  .malware_scan_request()
                  .population(),
              MalwareDeepScanningClientRequest::POPULATION_ENTERPRISE);

    EXPECT_FALSE(download_protection_service_.GetFakeBinaryUploadService()
                     ->last_request()
                     .has_dlp_scan_request());
  }

  {
    SetDlpPolicy(CHECK_UPLOADS_AND_DOWNLOADS);
    // The Connector policies need at least 1 pattern to be enabled, so adding
    // this pattern is necessary to have equivalent behaviour.
    if (!use_legacy_policies())
      AddUrlToList(prefs::kURLsToCheckComplianceOfDownloadedContent, tab_url_);
    SetMalwarePolicy(DO_NOT_SCAN);
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::DoNothing(), &download_protection_service_, settings().value());
    request.Start();
    EXPECT_FALSE(download_protection_service_.GetFakeBinaryUploadService()
                     ->last_request()
                     .has_malware_scan_request());
    EXPECT_TRUE(download_protection_service_.GetFakeBinaryUploadService()
                    ->last_request()
                    .has_dlp_scan_request());
  }

  {
    SetDlpPolicy(CHECK_NONE);
    SetMalwarePolicy(DO_NOT_SCAN);
    EXPECT_FALSE(settings().has_value());
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::DoNothing(), &download_protection_service_,
        enterprise_connectors::AnalysisSettings());
    request.Start();
    EXPECT_FALSE(download_protection_service_.GetFakeBinaryUploadService()
                     ->last_request()
                     .has_malware_scan_request());
    EXPECT_FALSE(download_protection_service_.GetFakeBinaryUploadService()
                     ->last_request()
                     .has_dlp_scan_request());
  }
}

TEST_P(DeepScanningRequestTest, GeneratesCorrectRequestForAPP) {
  enterprise_connectors::AnalysisSettings settings;
  settings.tags = {"dlp"};
  DeepScanningRequest request(
      &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_APP_PROMPT,
      base::DoNothing(), &download_protection_service_, std::move(settings));
  request.Start();

  EXPECT_TRUE(download_protection_service_.GetFakeBinaryUploadService()
                  ->last_request()
                  .has_malware_scan_request());
  EXPECT_FALSE(download_protection_service_.GetFakeBinaryUploadService()
                   ->last_request()
                   .has_dlp_scan_request());
  EXPECT_EQ(download_protection_service_.GetFakeBinaryUploadService()
                ->last_request()
                .malware_scan_request()
                .population(),
            MalwareDeepScanningClientRequest::POPULATION_TITANIUM);
}

class DeepScanningReportingTest : public DeepScanningRequestTest {
 public:
  void SetUp() override {
    DeepScanningRequestTest::SetUp();

    client_ = std::make_unique<policy::MockCloudPolicyClient>();

    extensions::SafeBrowsingPrivateEventRouterFactory::GetInstance()
        ->SetTestingFactory(
            profile_,
            base::BindRepeating(&BuildSafeBrowsingPrivateEventRouter));
    extensions::SafeBrowsingPrivateEventRouterFactory::GetForProfile(profile_)
        ->SetCloudPolicyClientForTesting(client_.get());
    extensions::SafeBrowsingPrivateEventRouterFactory::GetForProfile(profile_)
        ->SetBinaryUploadServiceForTesting(
            download_protection_service_.GetFakeBinaryUploadService());
    download_protection_service_.GetFakeBinaryUploadService()
        ->SetAuthForTesting(true);

    TestingBrowserProcess::GetGlobal()->local_state()->SetBoolean(
        prefs::kUnsafeEventsReportingEnabled, true);
    SetFeatures(/*enabled*/ AllFeatures(),
                /*disabled*/ {});
  }

 protected:
  std::unique_ptr<policy::MockCloudPolicyClient> client_;
};

INSTANTIATE_TEST_SUITE_P(, DeepScanningReportingTest, testing::Bool());

TEST_P(DeepScanningReportingTest, ProcessesResponseCorrectly) {
  SetDlpPolicy(CHECK_UPLOADS_AND_DOWNLOADS);
  // The Connector policies need at least 1 pattern to be enabled, so adding
  // this pattern is necessary to have equivalent behaviour.
  if (!use_legacy_policies())
    AddUrlToList(prefs::kURLsToCheckComplianceOfDownloadedContent, tab_url_);
  SetMalwarePolicy(SEND_UPLOADS_AND_DOWNLOADS);

  {
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::BindRepeating(&DeepScanningRequestTest::SetLastResult,
                            base::Unretained(this)),
        &download_protection_service_, settings().value());

    DeepScanningClientResponse response;
    response.mutable_malware_scan_verdict()->set_verdict(
        MalwareDeepScanningVerdict::MALWARE);
    response.mutable_dlp_scan_verdict()->set_status(
        DlpDeepScanningVerdict::SUCCESS);
    response.mutable_dlp_scan_verdict()->add_triggered_rules()->set_action(
        DlpDeepScanningVerdict::TriggeredRule::BLOCK);
    download_protection_service_.GetFakeBinaryUploadService()->SetResponse(
        BinaryUploadService::Result::SUCCESS, response);

    EventReportValidator validator(client_.get());
    validator.ExpectDangerousDeepScanningResultAndSensitiveDataEvent(
        /*url*/ "https://example.com/download.exe",
        /*filename*/ download_path_.AsUTF8Unsafe(),
        // printf "download contents" | sha256sum |  tr '[:lower:]'
        // '[:upper:]'
        /*sha256*/
        "76E00EB33811F5778A5EE557512C30D9341D4FEB07646BCE3E4DB13F9428573C",
        /*threat_type*/ "DANGEROUS",
        /*trigger*/
        extensions::SafeBrowsingPrivateEventRouter::kTriggerFileDownload,
        /*dlp_verdict*/
        SensitiveDataVerdictToResult(response.dlp_scan_verdict()),
        /*mimetypes*/ ExeMimeTypes(),
        /*size*/ std::string("download contents").size());

    request.Start();

    EXPECT_EQ(DownloadCheckResult::DANGEROUS, last_result_);
  }

  {
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::BindRepeating(&DeepScanningRequestTest::SetLastResult,
                            base::Unretained(this)),
        &download_protection_service_, settings().value());

    DeepScanningClientResponse response;
    response.mutable_malware_scan_verdict()->set_verdict(
        MalwareDeepScanningVerdict::UWS);
    response.mutable_dlp_scan_verdict()->set_status(
        DlpDeepScanningVerdict::SUCCESS);
    response.mutable_dlp_scan_verdict()->add_triggered_rules()->set_action(
        DlpDeepScanningVerdict::TriggeredRule::BLOCK);
    download_protection_service_.GetFakeBinaryUploadService()->SetResponse(
        BinaryUploadService::Result::SUCCESS, response);

    EventReportValidator validator(client_.get());
    validator.ExpectDangerousDeepScanningResultAndSensitiveDataEvent(
        /*url*/ "https://example.com/download.exe",
        /*filename*/ download_path_.AsUTF8Unsafe(),
        // printf "download contents" | sha256sum |  tr '[:lower:]'
        // '[:upper:]'
        /*sha256*/
        "76E00EB33811F5778A5EE557512C30D9341D4FEB07646BCE3E4DB13F9428573C",
        /*threat_type*/ "POTENTIALLY_UNWANTED",
        /*trigger*/
        extensions::SafeBrowsingPrivateEventRouter::kTriggerFileDownload,
        /*dlp_verdict*/
        SensitiveDataVerdictToResult(response.dlp_scan_verdict()),
        /*mimetypes*/ ExeMimeTypes(),
        /*size*/ std::string("download contents").size());

    request.Start();

    EXPECT_EQ(DownloadCheckResult::POTENTIALLY_UNWANTED, last_result_);
  }

  {
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::BindRepeating(&DeepScanningRequestTest::SetLastResult,
                            base::Unretained(this)),
        &download_protection_service_, settings().value());

    DeepScanningClientResponse response;
    response.mutable_dlp_scan_verdict()->set_status(
        DlpDeepScanningVerdict::SUCCESS);
    response.mutable_dlp_scan_verdict()->add_triggered_rules()->set_action(
        DlpDeepScanningVerdict::TriggeredRule::BLOCK);
    download_protection_service_.GetFakeBinaryUploadService()->SetResponse(
        BinaryUploadService::Result::SUCCESS, response);

    EventReportValidator validator(client_.get());
    validator.ExpectSensitiveDataEvent(
        /*url*/ "https://example.com/download.exe",
        /*filename*/ download_path_.AsUTF8Unsafe(),
        // printf "download contents" | sha256sum |  tr '[:lower:]' '[:upper:]'
        /*sha256*/
        "76E00EB33811F5778A5EE557512C30D9341D4FEB07646BCE3E4DB13F9428573C",
        /*trigger*/
        extensions::SafeBrowsingPrivateEventRouter::kTriggerFileDownload,
        /*dlp_verdict*/
        SensitiveDataVerdictToResult(response.dlp_scan_verdict()),
        /*mimetypes*/ ExeMimeTypes(),
        /*size*/ std::string("download contents").size());

    request.Start();

    EXPECT_EQ(DownloadCheckResult::SENSITIVE_CONTENT_BLOCK, last_result_);
  }

  {
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::BindRepeating(&DeepScanningRequestTest::SetLastResult,
                            base::Unretained(this)),
        &download_protection_service_, settings().value());

    DeepScanningClientResponse response;
    response.mutable_dlp_scan_verdict()->set_status(
        DlpDeepScanningVerdict::SUCCESS);
    response.mutable_dlp_scan_verdict()->add_triggered_rules()->set_action(
        DlpDeepScanningVerdict::TriggeredRule::WARN);
    download_protection_service_.GetFakeBinaryUploadService()->SetResponse(
        BinaryUploadService::Result::SUCCESS, response);

    EventReportValidator validator(client_.get());
    validator.ExpectSensitiveDataEvent(
        /*url*/ "https://example.com/download.exe",
        /*filename*/ download_path_.AsUTF8Unsafe(),
        // printf "download contents" | sha256sum |  tr '[:lower:]' '[:upper:]'
        /*sha256*/
        "76E00EB33811F5778A5EE557512C30D9341D4FEB07646BCE3E4DB13F9428573C",
        /*trigger*/
        extensions::SafeBrowsingPrivateEventRouter::kTriggerFileDownload,
        /*dlp_verdict*/
        SensitiveDataVerdictToResult(response.dlp_scan_verdict()),
        /*mimetypes*/ ExeMimeTypes(),
        /*size*/ std::string("download contents").size());

    request.Start();

    EXPECT_EQ(DownloadCheckResult::SENSITIVE_CONTENT_WARNING, last_result_);
  }

  {
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::BindRepeating(&DeepScanningRequestTest::SetLastResult,
                            base::Unretained(this)),
        &download_protection_service_, settings().value());

    DeepScanningClientResponse response;
    response.mutable_dlp_scan_verdict()->set_status(
        DlpDeepScanningVerdict::SUCCESS);
    response.mutable_dlp_scan_verdict()->add_triggered_rules()->set_action(
        DlpDeepScanningVerdict::TriggeredRule::WARN);
    response.mutable_dlp_scan_verdict()->add_triggered_rules()->set_action(
        DlpDeepScanningVerdict::TriggeredRule::BLOCK);
    download_protection_service_.GetFakeBinaryUploadService()->SetResponse(
        BinaryUploadService::Result::SUCCESS, response);

    EventReportValidator validator(client_.get());
    validator.ExpectSensitiveDataEvent(
        /*url*/ "https://example.com/download.exe",
        /*filename*/ download_path_.AsUTF8Unsafe(),
        // printf "download contents" | sha256sum |  tr '[:lower:]' '[:upper:]'
        /*sha256*/
        "76E00EB33811F5778A5EE557512C30D9341D4FEB07646BCE3E4DB13F9428573C",
        /*trigger*/
        extensions::SafeBrowsingPrivateEventRouter::kTriggerFileDownload,
        /*dlp_verdict*/
        SensitiveDataVerdictToResult(response.dlp_scan_verdict()),
        /*mimetypes*/ ExeMimeTypes(),
        /*size*/ std::string("download contents").size());

    request.Start();

    EXPECT_EQ(DownloadCheckResult::SENSITIVE_CONTENT_BLOCK, last_result_);
  }

  {
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::BindRepeating(&DeepScanningRequestTest::SetLastResult,
                            base::Unretained(this)),
        &download_protection_service_, settings().value());

    DeepScanningClientResponse response;
    response.mutable_dlp_scan_verdict()->set_status(
        DlpDeepScanningVerdict::FAILURE);
    download_protection_service_.GetFakeBinaryUploadService()->SetResponse(
        BinaryUploadService::Result::SUCCESS, response);

    EventReportValidator validator(client_.get());
    validator.ExpectUnscannedFileEvent(
        /*url*/ "https://example.com/download.exe",
        /*filename*/ download_path_.AsUTF8Unsafe(),
        // printf "download contents" | sha256sum |  tr '[:lower:]' '[:upper:]'
        /*sha256*/
        "76E00EB33811F5778A5EE557512C30D9341D4FEB07646BCE3E4DB13F9428573C",
        /*trigger*/
        extensions::SafeBrowsingPrivateEventRouter::kTriggerFileDownload,
        /*reason*/ "DLP_SCAN_FAILED",
        /*mimetypes*/ ExeMimeTypes(),
        /*size*/ std::string("download contents").size());

    request.Start();

    EXPECT_EQ(DownloadCheckResult::UNKNOWN, last_result_);
  }

  {
    DeepScanningRequest request(
        &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
        base::BindRepeating(&DeepScanningRequestTest::SetLastResult,
                            base::Unretained(this)),
        &download_protection_service_, settings().value());

    DeepScanningClientResponse response;
    response.mutable_malware_scan_verdict()->set_verdict(
        MalwareDeepScanningVerdict::SCAN_FAILURE);
    download_protection_service_.GetFakeBinaryUploadService()->SetResponse(
        BinaryUploadService::Result::SUCCESS, response);

    EventReportValidator validator(client_.get());
    validator.ExpectUnscannedFileEvent(
        /*url*/ "https://example.com/download.exe",
        /*filename*/ download_path_.AsUTF8Unsafe(),
        // printf "download contents" | sha256sum |  tr '[:lower:]' '[:upper:]'
        /*sha256*/
        "76E00EB33811F5778A5EE557512C30D9341D4FEB07646BCE3E4DB13F9428573C",
        /*trigger*/
        extensions::SafeBrowsingPrivateEventRouter::kTriggerFileDownload,
        /*reason*/ "MALWARE_SCAN_FAILED",
        /*mimetypes*/ ExeMimeTypes(),
        /*size*/ std::string("download contents").size());

    request.Start();

    EXPECT_EQ(DownloadCheckResult::UNKNOWN, last_result_);
  }
}

TEST_P(DeepScanningRequestTest, ShouldUploadBinary_MalwareListPolicy) {
  SetFeatures(/*enabled*/ MalwareFeatures(),
              /*disabled*/ {kContentComplianceEnabled});
  SetMalwarePolicy(SEND_UPLOADS_AND_DOWNLOADS);

  content::DownloadItemUtils::AttachInfo(&item_, profile_, nullptr);
  EXPECT_CALL(item_, GetURL()).WillRepeatedly(ReturnRef(download_url_));

  // Without the malware policy list set, the item should be uploaded.
  ValidateDefaultSettings(settings());

  // With the old malware policy list set, the item should be uploaded since
  // DeepScanningRequest ignores that policy.
  AddUrlToProfilePrefList(prefs::kSafeBrowsingWhitelistDomains, download_url_);
  ValidateDefaultSettings(settings());

  // With the new malware policy list set, the item should not be uploaded since
  // DeepScanningRequest honours that policy.
  AddUrlToList(prefs::kURLsToNotCheckForMalwareOfDownloadedContent,
               download_url_);
  EXPECT_FALSE(settings().has_value());
}

TEST_P(DeepScanningRequestTest, PopulatesRequest) {
  SetDlpPolicy(CHECK_UPLOADS_AND_DOWNLOADS);
  SetMalwarePolicy(SEND_UPLOADS_AND_DOWNLOADS);

  SetFeatures(/*enabled*/ AllFeatures(),
              /*disabled*/ {});
  DeepScanningRequest request(
      &item_, DeepScanningRequest::DeepScanTrigger::TRIGGER_POLICY,
      base::DoNothing(), &download_protection_service_, settings().value());
  request.Start();
  EXPECT_EQ(download_protection_service_.GetFakeBinaryUploadService()
                ->last_request()
                .filename(),
            "download.exe");
  EXPECT_EQ(download_protection_service_.GetFakeBinaryUploadService()
                ->last_request()
                .digest(),
            // Hex-encoding of 'hash'
            "76E00EB33811F5778A5EE557512C30D9341D4FEB07646BCE3E4DB13F9428573C");
}

}  // namespace safe_browsing
