// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_SAFE_BROWSING_CLOUD_CONTENT_SCANNING_DEEP_SCANNING_UTILS_H_
#define CHROME_BROWSER_SAFE_BROWSING_CLOUD_CONTENT_SCANNING_DEEP_SCANNING_UTILS_H_

#include <string>
#include <vector>

#include "base/time/time.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.h"
#include "components/enterprise/common/proto/connectors.pb.h"
#include "components/safe_browsing/core/proto/webprotect.pb.h"
#include "url/gurl.h"

class Profile;

namespace enterprise_connectors {
class ContentAnalysisResponse;
}  // namespace enterprise_connectors

namespace safe_browsing {

// Represents a trigger that caused a a content analysis request to report a
// violation.  This is a structure that abstracts the old and new protobufs,
// to diminish dependencies on them.
struct ContentAnalysisTrigger {
  ContentAnalysisTrigger();
  ContentAnalysisTrigger(const ContentAnalysisTrigger& other);
  ContentAnalysisTrigger(ContentAnalysisTrigger&& other);
  ~ContentAnalysisTrigger();
  ContentAnalysisTrigger& operator=(const ContentAnalysisTrigger& other);

  int action;        // The action taken by chrome.
  std::string id;    // The id of the trigger.
  std::string name;  // A friendly name for the trigger.
};

// Represents the result of a sensitive data scan.  This is a structure that
// abstracts the old and new protobugs, to diminish dependencies on them.
struct ContentAnalysisScanResult {
  ContentAnalysisScanResult();
  ContentAnalysisScanResult(const ContentAnalysisScanResult& other);
  ContentAnalysisScanResult(ContentAnalysisScanResult&& other);
  ~ContentAnalysisScanResult();
  ContentAnalysisScanResult& operator=(const ContentAnalysisScanResult& other);

  std::string tag;  // The tag associated with the scan.
  int status;       // The status of scan for the given tag.
  std::vector<ContentAnalysisTrigger> triggers;  // Triggers, if any.
};

// Access points used to record UMA metrics and specify which code location is
// initiating a deep scan. Any new caller of
// DeepScanningDialogDelegate::ShowForWebContents should add an access point
// here instead of re-using an existing value. histograms.xml should also be
// updated by adding histograms with names
//   "SafeBrowsing.DeepScan.<access-point>.BytesPerSeconds"
//   "SafeBrowsing.DeepScan.<access-point>.Duration"
//   "SafeBrowsing.DeepScan.<access-point>.<result>.Duration"
// for the new access point and every possible result.
enum class DeepScanAccessPoint {
  // A deep scan was initiated from downloading 1+ file(s).
  DOWNLOAD,

  // A deep scan was initiated from uploading 1+ file(s) via a system dialog.
  UPLOAD,

  // A deep scan was initiated from drag-and-dropping text or 1+ file(s).
  DRAG_AND_DROP,

  // A deep scan was initiated from pasting text.
  PASTE,
};
std::string DeepScanAccessPointToString(DeepScanAccessPoint access_point);

// Helper function to examine a DeepScanningClientResponse and report the
// appropriate events to the enterprise admin. |download_digest_sha256| must be
// encoded using base::HexEncode.
void MaybeReportDeepScanningVerdict(Profile* profile,
                                    const GURL& url,
                                    const std::string& file_name,
                                    const std::string& download_digest_sha256,
                                    const std::string& mime_type,
                                    const std::string& trigger,
                                    DeepScanAccessPoint access_point,
                                    const int64_t content_size,
                                    BinaryUploadService::Result result,
                                    const DeepScanningClientResponse& response);

// Helper function to examine a ContentAnalysisResponse and report the
// appropriate events to the enterprise admin. |download_digest_sha256| must be
// encoded using base::HexEncode.
void MaybeReportDeepScanningVerdict(
    Profile* profile,
    const GURL& url,
    const std::string& file_name,
    const std::string& download_digest_sha256,
    const std::string& mime_type,
    const std::string& trigger,
    DeepScanAccessPoint access_point,
    const int64_t content_size,
    BinaryUploadService::Result result,
    const enterprise_connectors::ContentAnalysisResponse& response);

// Helper function to report the user bypassed a warning to the enterprise
// admin. This is split from MaybeReportDeepScanningVerdict since it happens
// after getting a response. |download_digest_sha256| must be encoded using
// base::HexEncode.
void ReportAnalysisConnectorWarningBypass(
    Profile* profile,
    const GURL& url,
    const std::string& file_name,
    const std::string& download_digest_sha256,
    const std::string& mime_type,
    const std::string& trigger,
    DeepScanAccessPoint access_point,
    const int64_t content_size,
    const DlpDeepScanningVerdict& verdict);
void ReportAnalysisConnectorWarningBypass(
    Profile* profile,
    const GURL& url,
    const std::string& file_name,
    const std::string& download_digest_sha256,
    const std::string& mime_type,
    const std::string& trigger,
    DeepScanAccessPoint access_point,
    const int64_t content_size,
    const enterprise_connectors::ContentAnalysisResponse& response);

// Helper functions to record DeepScanning UMA metrics for the duration of the
// request split by its result and bytes/sec for successful requests.
void RecordDeepScanMetrics(DeepScanAccessPoint access_point,
                           base::TimeDelta duration,
                           int64_t total_bytes,
                           const BinaryUploadService::Result& result,
                           const DeepScanningClientResponse& response);
void RecordDeepScanMetrics(DeepScanAccessPoint access_point,
                           base::TimeDelta duration,
                           int64_t total_bytes,
                           const std::string& result,
                           bool success);

// Returns an array of the file types supported for DLP scanning.
std::array<const base::FilePath::CharType*, 24> SupportedDlpFileTypes();

// Returns true if the given file type is supported for DLP scanning.
bool FileTypeSupportedForDlp(const base::FilePath& path);

// Helper function to make DeepScanningClientResponses for tests.
DeepScanningClientResponse SimpleDeepScanningClientResponseForTesting(
    base::Optional<bool> dlp_success,
    base::Optional<bool> malware_success);

// Helper function to convert a BinaryUploadService::Result to a CamelCase
// string.
std::string BinaryUploadServiceResultToString(
    const BinaryUploadService::Result& result,
    bool success);

// Converts legacy DeepScanningResponse protos or an enterprise connectors
// ContentAnalysisResponse proto to ContentAnalysisScanResult used by the
// reporting layer.  This indirection is used during the conversion to
// connectors and possibly could be removed once the conversion is done.
ContentAnalysisScanResult SensitiveDataVerdictToResult(
    const safe_browsing::DlpDeepScanningVerdict& verdict);
ContentAnalysisScanResult ContentAnalysisResultToResult(
    const enterprise_connectors::ContentAnalysisResponse::Result& result);
ContentAnalysisScanResult MalwareVerdictToResult(
    const safe_browsing::MalwareDeepScanningVerdict& verdict);
std::vector<ContentAnalysisScanResult> ContentAnalysisResponseToResults(
    const enterprise_connectors::ContentAnalysisResponse& response);

}  // namespace safe_browsing

#endif  // CHROME_BROWSER_SAFE_BROWSING_CLOUD_CONTENT_SCANNING_DEEP_SCANNING_UTILS_H_
