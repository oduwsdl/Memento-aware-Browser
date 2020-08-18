// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_AUDITS_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_AUDITS_H_

#include "base/values.h"

namespace headless {

namespace audits {
class AffectedCookie;
class AffectedRequest;
class AffectedFrame;
class SameSiteCookieIssueDetails;
class MixedContentIssueDetails;
class BlockedByResponseIssueDetails;
class InspectorIssueDetails;
class InspectorIssue;
class GetEncodedResponseParams;
class GetEncodedResponseResult;
class DisableParams;
class DisableResult;
class EnableParams;
class EnableResult;
class IssueAddedParams;

enum class SameSiteCookieExclusionReason {
  EXCLUDE_SAME_SITE_UNSPECIFIED_TREATED_AS_LAX,
  EXCLUDE_SAME_SITE_NONE_INSECURE
};

enum class SameSiteCookieWarningReason {
  WARN_SAME_SITE_UNSPECIFIED_CROSS_SITE_CONTEXT,
  WARN_SAME_SITE_NONE_INSECURE,
  WARN_SAME_SITE_UNSPECIFIED_LAX_ALLOW_UNSAFE,
  WARN_SAME_SITE_STRICT_LAX_DOWNGRADE_STRICT,
  WARN_SAME_SITE_STRICT_CROSS_DOWNGRADE_STRICT,
  WARN_SAME_SITE_STRICT_CROSS_DOWNGRADE_LAX,
  WARN_SAME_SITE_LAX_CROSS_DOWNGRADE_STRICT,
  WARN_SAME_SITE_LAX_CROSS_DOWNGRADE_LAX
};

enum class SameSiteCookieOperation {
  SET_COOKIE,
  READ_COOKIE
};

enum class MixedContentResolutionStatus {
  MIXED_CONTENT_BLOCKED,
  MIXED_CONTENT_AUTOMATICALLY_UPGRADED,
  MIXED_CONTENT_WARNING
};

enum class MixedContentResourceType {
  AUDIO,
  BEACON,
  CSP_REPORT,
  DOWNLOAD,
  EVENT_SOURCE,
  FAVICON,
  FONT,
  FORM,
  FRAME,
  IMAGE,
  IMPORT,
  MANIFEST,
  PING,
  PLUGIN_DATA,
  PLUGIN_RESOURCE,
  PREFETCH,
  RESOURCE,
  SCRIPT,
  SERVICE_WORKER,
  SHARED_WORKER,
  STYLESHEET,
  TRACK,
  VIDEO,
  WORKER,
  XML_HTTP_REQUEST,
  XSLT
};

enum class BlockedByResponseReason {
  COEP_FRAME_RESOURCE_NEEDS_COEP_HEADER,
  COOP_SANDBOXEDI_FRAME_CANNOT_NAVIGATE_TO_COOP_PAGE,
  CORP_NOT_SAME_ORIGIN,
  CORP_NOT_SAME_ORIGIN_AFTER_DEFAULTED_TO_SAME_ORIGIN_BY_COEP,
  CORP_NOT_SAME_SITE
};

enum class InspectorIssueCode {
  SAME_SITE_COOKIE_ISSUE,
  MIXED_CONTENT_ISSUE,
  BLOCKED_BY_RESPONSE_ISSUE
};

enum class GetEncodedResponseEncoding {
  WEBP,
  JPEG,
  PNG
};

}  // namespace audits

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_AUDITS_H_
