// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_AUDITS_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_AUDITS_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_audits.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<audits::AffectedCookie> {
  static std::unique_ptr<audits::AffectedCookie> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::AffectedCookie::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::AffectedCookie& value) {
  return value.Serialize();
}


template <>
struct FromValue<audits::AffectedRequest> {
  static std::unique_ptr<audits::AffectedRequest> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::AffectedRequest::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::AffectedRequest& value) {
  return value.Serialize();
}


template <>
struct FromValue<audits::AffectedFrame> {
  static std::unique_ptr<audits::AffectedFrame> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::AffectedFrame::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::AffectedFrame& value) {
  return value.Serialize();
}

template <>
struct FromValue<audits::SameSiteCookieExclusionReason> {
  static audits::SameSiteCookieExclusionReason Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return audits::SameSiteCookieExclusionReason::EXCLUDE_SAME_SITE_UNSPECIFIED_TREATED_AS_LAX;
    }
    if (value.GetString() == "ExcludeSameSiteUnspecifiedTreatedAsLax")
      return audits::SameSiteCookieExclusionReason::EXCLUDE_SAME_SITE_UNSPECIFIED_TREATED_AS_LAX;
    if (value.GetString() == "ExcludeSameSiteNoneInsecure")
      return audits::SameSiteCookieExclusionReason::EXCLUDE_SAME_SITE_NONE_INSECURE;
    errors->AddError("invalid enum value");
    return audits::SameSiteCookieExclusionReason::EXCLUDE_SAME_SITE_UNSPECIFIED_TREATED_AS_LAX;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::SameSiteCookieExclusionReason& value) {
  switch (value) {
    case audits::SameSiteCookieExclusionReason::EXCLUDE_SAME_SITE_UNSPECIFIED_TREATED_AS_LAX:
      return std::make_unique<base::Value>("ExcludeSameSiteUnspecifiedTreatedAsLax");
    case audits::SameSiteCookieExclusionReason::EXCLUDE_SAME_SITE_NONE_INSECURE:
      return std::make_unique<base::Value>("ExcludeSameSiteNoneInsecure");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<audits::SameSiteCookieWarningReason> {
  static audits::SameSiteCookieWarningReason Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return audits::SameSiteCookieWarningReason::WARN_SAME_SITE_UNSPECIFIED_CROSS_SITE_CONTEXT;
    }
    if (value.GetString() == "WarnSameSiteUnspecifiedCrossSiteContext")
      return audits::SameSiteCookieWarningReason::WARN_SAME_SITE_UNSPECIFIED_CROSS_SITE_CONTEXT;
    if (value.GetString() == "WarnSameSiteNoneInsecure")
      return audits::SameSiteCookieWarningReason::WARN_SAME_SITE_NONE_INSECURE;
    if (value.GetString() == "WarnSameSiteUnspecifiedLaxAllowUnsafe")
      return audits::SameSiteCookieWarningReason::WARN_SAME_SITE_UNSPECIFIED_LAX_ALLOW_UNSAFE;
    if (value.GetString() == "WarnSameSiteStrictLaxDowngradeStrict")
      return audits::SameSiteCookieWarningReason::WARN_SAME_SITE_STRICT_LAX_DOWNGRADE_STRICT;
    if (value.GetString() == "WarnSameSiteStrictCrossDowngradeStrict")
      return audits::SameSiteCookieWarningReason::WARN_SAME_SITE_STRICT_CROSS_DOWNGRADE_STRICT;
    if (value.GetString() == "WarnSameSiteStrictCrossDowngradeLax")
      return audits::SameSiteCookieWarningReason::WARN_SAME_SITE_STRICT_CROSS_DOWNGRADE_LAX;
    if (value.GetString() == "WarnSameSiteLaxCrossDowngradeStrict")
      return audits::SameSiteCookieWarningReason::WARN_SAME_SITE_LAX_CROSS_DOWNGRADE_STRICT;
    if (value.GetString() == "WarnSameSiteLaxCrossDowngradeLax")
      return audits::SameSiteCookieWarningReason::WARN_SAME_SITE_LAX_CROSS_DOWNGRADE_LAX;
    errors->AddError("invalid enum value");
    return audits::SameSiteCookieWarningReason::WARN_SAME_SITE_UNSPECIFIED_CROSS_SITE_CONTEXT;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::SameSiteCookieWarningReason& value) {
  switch (value) {
    case audits::SameSiteCookieWarningReason::WARN_SAME_SITE_UNSPECIFIED_CROSS_SITE_CONTEXT:
      return std::make_unique<base::Value>("WarnSameSiteUnspecifiedCrossSiteContext");
    case audits::SameSiteCookieWarningReason::WARN_SAME_SITE_NONE_INSECURE:
      return std::make_unique<base::Value>("WarnSameSiteNoneInsecure");
    case audits::SameSiteCookieWarningReason::WARN_SAME_SITE_UNSPECIFIED_LAX_ALLOW_UNSAFE:
      return std::make_unique<base::Value>("WarnSameSiteUnspecifiedLaxAllowUnsafe");
    case audits::SameSiteCookieWarningReason::WARN_SAME_SITE_STRICT_LAX_DOWNGRADE_STRICT:
      return std::make_unique<base::Value>("WarnSameSiteStrictLaxDowngradeStrict");
    case audits::SameSiteCookieWarningReason::WARN_SAME_SITE_STRICT_CROSS_DOWNGRADE_STRICT:
      return std::make_unique<base::Value>("WarnSameSiteStrictCrossDowngradeStrict");
    case audits::SameSiteCookieWarningReason::WARN_SAME_SITE_STRICT_CROSS_DOWNGRADE_LAX:
      return std::make_unique<base::Value>("WarnSameSiteStrictCrossDowngradeLax");
    case audits::SameSiteCookieWarningReason::WARN_SAME_SITE_LAX_CROSS_DOWNGRADE_STRICT:
      return std::make_unique<base::Value>("WarnSameSiteLaxCrossDowngradeStrict");
    case audits::SameSiteCookieWarningReason::WARN_SAME_SITE_LAX_CROSS_DOWNGRADE_LAX:
      return std::make_unique<base::Value>("WarnSameSiteLaxCrossDowngradeLax");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<audits::SameSiteCookieOperation> {
  static audits::SameSiteCookieOperation Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return audits::SameSiteCookieOperation::SET_COOKIE;
    }
    if (value.GetString() == "SetCookie")
      return audits::SameSiteCookieOperation::SET_COOKIE;
    if (value.GetString() == "ReadCookie")
      return audits::SameSiteCookieOperation::READ_COOKIE;
    errors->AddError("invalid enum value");
    return audits::SameSiteCookieOperation::SET_COOKIE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::SameSiteCookieOperation& value) {
  switch (value) {
    case audits::SameSiteCookieOperation::SET_COOKIE:
      return std::make_unique<base::Value>("SetCookie");
    case audits::SameSiteCookieOperation::READ_COOKIE:
      return std::make_unique<base::Value>("ReadCookie");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<audits::SameSiteCookieIssueDetails> {
  static std::unique_ptr<audits::SameSiteCookieIssueDetails> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::SameSiteCookieIssueDetails::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::SameSiteCookieIssueDetails& value) {
  return value.Serialize();
}

template <>
struct FromValue<audits::MixedContentResolutionStatus> {
  static audits::MixedContentResolutionStatus Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return audits::MixedContentResolutionStatus::MIXED_CONTENT_BLOCKED;
    }
    if (value.GetString() == "MixedContentBlocked")
      return audits::MixedContentResolutionStatus::MIXED_CONTENT_BLOCKED;
    if (value.GetString() == "MixedContentAutomaticallyUpgraded")
      return audits::MixedContentResolutionStatus::MIXED_CONTENT_AUTOMATICALLY_UPGRADED;
    if (value.GetString() == "MixedContentWarning")
      return audits::MixedContentResolutionStatus::MIXED_CONTENT_WARNING;
    errors->AddError("invalid enum value");
    return audits::MixedContentResolutionStatus::MIXED_CONTENT_BLOCKED;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::MixedContentResolutionStatus& value) {
  switch (value) {
    case audits::MixedContentResolutionStatus::MIXED_CONTENT_BLOCKED:
      return std::make_unique<base::Value>("MixedContentBlocked");
    case audits::MixedContentResolutionStatus::MIXED_CONTENT_AUTOMATICALLY_UPGRADED:
      return std::make_unique<base::Value>("MixedContentAutomaticallyUpgraded");
    case audits::MixedContentResolutionStatus::MIXED_CONTENT_WARNING:
      return std::make_unique<base::Value>("MixedContentWarning");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<audits::MixedContentResourceType> {
  static audits::MixedContentResourceType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return audits::MixedContentResourceType::AUDIO;
    }
    if (value.GetString() == "Audio")
      return audits::MixedContentResourceType::AUDIO;
    if (value.GetString() == "Beacon")
      return audits::MixedContentResourceType::BEACON;
    if (value.GetString() == "CSPReport")
      return audits::MixedContentResourceType::CSP_REPORT;
    if (value.GetString() == "Download")
      return audits::MixedContentResourceType::DOWNLOAD;
    if (value.GetString() == "EventSource")
      return audits::MixedContentResourceType::EVENT_SOURCE;
    if (value.GetString() == "Favicon")
      return audits::MixedContentResourceType::FAVICON;
    if (value.GetString() == "Font")
      return audits::MixedContentResourceType::FONT;
    if (value.GetString() == "Form")
      return audits::MixedContentResourceType::FORM;
    if (value.GetString() == "Frame")
      return audits::MixedContentResourceType::FRAME;
    if (value.GetString() == "Image")
      return audits::MixedContentResourceType::IMAGE;
    if (value.GetString() == "Import")
      return audits::MixedContentResourceType::IMPORT;
    if (value.GetString() == "Manifest")
      return audits::MixedContentResourceType::MANIFEST;
    if (value.GetString() == "Ping")
      return audits::MixedContentResourceType::PING;
    if (value.GetString() == "PluginData")
      return audits::MixedContentResourceType::PLUGIN_DATA;
    if (value.GetString() == "PluginResource")
      return audits::MixedContentResourceType::PLUGIN_RESOURCE;
    if (value.GetString() == "Prefetch")
      return audits::MixedContentResourceType::PREFETCH;
    if (value.GetString() == "Resource")
      return audits::MixedContentResourceType::RESOURCE;
    if (value.GetString() == "Script")
      return audits::MixedContentResourceType::SCRIPT;
    if (value.GetString() == "ServiceWorker")
      return audits::MixedContentResourceType::SERVICE_WORKER;
    if (value.GetString() == "SharedWorker")
      return audits::MixedContentResourceType::SHARED_WORKER;
    if (value.GetString() == "Stylesheet")
      return audits::MixedContentResourceType::STYLESHEET;
    if (value.GetString() == "Track")
      return audits::MixedContentResourceType::TRACK;
    if (value.GetString() == "Video")
      return audits::MixedContentResourceType::VIDEO;
    if (value.GetString() == "Worker")
      return audits::MixedContentResourceType::WORKER;
    if (value.GetString() == "XMLHttpRequest")
      return audits::MixedContentResourceType::XML_HTTP_REQUEST;
    if (value.GetString() == "XSLT")
      return audits::MixedContentResourceType::XSLT;
    errors->AddError("invalid enum value");
    return audits::MixedContentResourceType::AUDIO;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::MixedContentResourceType& value) {
  switch (value) {
    case audits::MixedContentResourceType::AUDIO:
      return std::make_unique<base::Value>("Audio");
    case audits::MixedContentResourceType::BEACON:
      return std::make_unique<base::Value>("Beacon");
    case audits::MixedContentResourceType::CSP_REPORT:
      return std::make_unique<base::Value>("CSPReport");
    case audits::MixedContentResourceType::DOWNLOAD:
      return std::make_unique<base::Value>("Download");
    case audits::MixedContentResourceType::EVENT_SOURCE:
      return std::make_unique<base::Value>("EventSource");
    case audits::MixedContentResourceType::FAVICON:
      return std::make_unique<base::Value>("Favicon");
    case audits::MixedContentResourceType::FONT:
      return std::make_unique<base::Value>("Font");
    case audits::MixedContentResourceType::FORM:
      return std::make_unique<base::Value>("Form");
    case audits::MixedContentResourceType::FRAME:
      return std::make_unique<base::Value>("Frame");
    case audits::MixedContentResourceType::IMAGE:
      return std::make_unique<base::Value>("Image");
    case audits::MixedContentResourceType::IMPORT:
      return std::make_unique<base::Value>("Import");
    case audits::MixedContentResourceType::MANIFEST:
      return std::make_unique<base::Value>("Manifest");
    case audits::MixedContentResourceType::PING:
      return std::make_unique<base::Value>("Ping");
    case audits::MixedContentResourceType::PLUGIN_DATA:
      return std::make_unique<base::Value>("PluginData");
    case audits::MixedContentResourceType::PLUGIN_RESOURCE:
      return std::make_unique<base::Value>("PluginResource");
    case audits::MixedContentResourceType::PREFETCH:
      return std::make_unique<base::Value>("Prefetch");
    case audits::MixedContentResourceType::RESOURCE:
      return std::make_unique<base::Value>("Resource");
    case audits::MixedContentResourceType::SCRIPT:
      return std::make_unique<base::Value>("Script");
    case audits::MixedContentResourceType::SERVICE_WORKER:
      return std::make_unique<base::Value>("ServiceWorker");
    case audits::MixedContentResourceType::SHARED_WORKER:
      return std::make_unique<base::Value>("SharedWorker");
    case audits::MixedContentResourceType::STYLESHEET:
      return std::make_unique<base::Value>("Stylesheet");
    case audits::MixedContentResourceType::TRACK:
      return std::make_unique<base::Value>("Track");
    case audits::MixedContentResourceType::VIDEO:
      return std::make_unique<base::Value>("Video");
    case audits::MixedContentResourceType::WORKER:
      return std::make_unique<base::Value>("Worker");
    case audits::MixedContentResourceType::XML_HTTP_REQUEST:
      return std::make_unique<base::Value>("XMLHttpRequest");
    case audits::MixedContentResourceType::XSLT:
      return std::make_unique<base::Value>("XSLT");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<audits::MixedContentIssueDetails> {
  static std::unique_ptr<audits::MixedContentIssueDetails> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::MixedContentIssueDetails::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::MixedContentIssueDetails& value) {
  return value.Serialize();
}

template <>
struct FromValue<audits::BlockedByResponseReason> {
  static audits::BlockedByResponseReason Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return audits::BlockedByResponseReason::COEP_FRAME_RESOURCE_NEEDS_COEP_HEADER;
    }
    if (value.GetString() == "CoepFrameResourceNeedsCoepHeader")
      return audits::BlockedByResponseReason::COEP_FRAME_RESOURCE_NEEDS_COEP_HEADER;
    if (value.GetString() == "CoopSandboxedIFrameCannotNavigateToCoopPage")
      return audits::BlockedByResponseReason::COOP_SANDBOXEDI_FRAME_CANNOT_NAVIGATE_TO_COOP_PAGE;
    if (value.GetString() == "CorpNotSameOrigin")
      return audits::BlockedByResponseReason::CORP_NOT_SAME_ORIGIN;
    if (value.GetString() == "CorpNotSameOriginAfterDefaultedToSameOriginByCoep")
      return audits::BlockedByResponseReason::CORP_NOT_SAME_ORIGIN_AFTER_DEFAULTED_TO_SAME_ORIGIN_BY_COEP;
    if (value.GetString() == "CorpNotSameSite")
      return audits::BlockedByResponseReason::CORP_NOT_SAME_SITE;
    errors->AddError("invalid enum value");
    return audits::BlockedByResponseReason::COEP_FRAME_RESOURCE_NEEDS_COEP_HEADER;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::BlockedByResponseReason& value) {
  switch (value) {
    case audits::BlockedByResponseReason::COEP_FRAME_RESOURCE_NEEDS_COEP_HEADER:
      return std::make_unique<base::Value>("CoepFrameResourceNeedsCoepHeader");
    case audits::BlockedByResponseReason::COOP_SANDBOXEDI_FRAME_CANNOT_NAVIGATE_TO_COOP_PAGE:
      return std::make_unique<base::Value>("CoopSandboxedIFrameCannotNavigateToCoopPage");
    case audits::BlockedByResponseReason::CORP_NOT_SAME_ORIGIN:
      return std::make_unique<base::Value>("CorpNotSameOrigin");
    case audits::BlockedByResponseReason::CORP_NOT_SAME_ORIGIN_AFTER_DEFAULTED_TO_SAME_ORIGIN_BY_COEP:
      return std::make_unique<base::Value>("CorpNotSameOriginAfterDefaultedToSameOriginByCoep");
    case audits::BlockedByResponseReason::CORP_NOT_SAME_SITE:
      return std::make_unique<base::Value>("CorpNotSameSite");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<audits::BlockedByResponseIssueDetails> {
  static std::unique_ptr<audits::BlockedByResponseIssueDetails> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::BlockedByResponseIssueDetails::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::BlockedByResponseIssueDetails& value) {
  return value.Serialize();
}

template <>
struct FromValue<audits::InspectorIssueCode> {
  static audits::InspectorIssueCode Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return audits::InspectorIssueCode::SAME_SITE_COOKIE_ISSUE;
    }
    if (value.GetString() == "SameSiteCookieIssue")
      return audits::InspectorIssueCode::SAME_SITE_COOKIE_ISSUE;
    if (value.GetString() == "MixedContentIssue")
      return audits::InspectorIssueCode::MIXED_CONTENT_ISSUE;
    if (value.GetString() == "BlockedByResponseIssue")
      return audits::InspectorIssueCode::BLOCKED_BY_RESPONSE_ISSUE;
    errors->AddError("invalid enum value");
    return audits::InspectorIssueCode::SAME_SITE_COOKIE_ISSUE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::InspectorIssueCode& value) {
  switch (value) {
    case audits::InspectorIssueCode::SAME_SITE_COOKIE_ISSUE:
      return std::make_unique<base::Value>("SameSiteCookieIssue");
    case audits::InspectorIssueCode::MIXED_CONTENT_ISSUE:
      return std::make_unique<base::Value>("MixedContentIssue");
    case audits::InspectorIssueCode::BLOCKED_BY_RESPONSE_ISSUE:
      return std::make_unique<base::Value>("BlockedByResponseIssue");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<audits::InspectorIssueDetails> {
  static std::unique_ptr<audits::InspectorIssueDetails> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::InspectorIssueDetails::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::InspectorIssueDetails& value) {
  return value.Serialize();
}


template <>
struct FromValue<audits::InspectorIssue> {
  static std::unique_ptr<audits::InspectorIssue> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::InspectorIssue::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::InspectorIssue& value) {
  return value.Serialize();
}

template <>
struct FromValue<audits::GetEncodedResponseEncoding> {
  static audits::GetEncodedResponseEncoding Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return audits::GetEncodedResponseEncoding::WEBP;
    }
    if (value.GetString() == "webp")
      return audits::GetEncodedResponseEncoding::WEBP;
    if (value.GetString() == "jpeg")
      return audits::GetEncodedResponseEncoding::JPEG;
    if (value.GetString() == "png")
      return audits::GetEncodedResponseEncoding::PNG;
    errors->AddError("invalid enum value");
    return audits::GetEncodedResponseEncoding::WEBP;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::GetEncodedResponseEncoding& value) {
  switch (value) {
    case audits::GetEncodedResponseEncoding::WEBP:
      return std::make_unique<base::Value>("webp");
    case audits::GetEncodedResponseEncoding::JPEG:
      return std::make_unique<base::Value>("jpeg");
    case audits::GetEncodedResponseEncoding::PNG:
      return std::make_unique<base::Value>("png");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<audits::GetEncodedResponseParams> {
  static std::unique_ptr<audits::GetEncodedResponseParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::GetEncodedResponseParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::GetEncodedResponseParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<audits::GetEncodedResponseResult> {
  static std::unique_ptr<audits::GetEncodedResponseResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::GetEncodedResponseResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::GetEncodedResponseResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<audits::DisableParams> {
  static std::unique_ptr<audits::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<audits::DisableResult> {
  static std::unique_ptr<audits::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<audits::EnableParams> {
  static std::unique_ptr<audits::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<audits::EnableResult> {
  static std::unique_ptr<audits::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<audits::IssueAddedParams> {
  static std::unique_ptr<audits::IssueAddedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return audits::IssueAddedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const audits::IssueAddedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_AUDITS_H_
