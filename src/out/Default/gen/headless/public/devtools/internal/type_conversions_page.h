// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_PAGE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_PAGE_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {



template <>
struct FromValue<page::Frame> {
  static std::unique_ptr<page::Frame> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::Frame::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::Frame& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameResource> {
  static std::unique_ptr<page::FrameResource> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameResource::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameResource& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameResourceTree> {
  static std::unique_ptr<page::FrameResourceTree> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameResourceTree::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameResourceTree& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameTree> {
  static std::unique_ptr<page::FrameTree> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameTree::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameTree& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::TransitionType> {
  static page::TransitionType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::TransitionType::LINK;
    }
    if (value.GetString() == "link")
      return page::TransitionType::LINK;
    if (value.GetString() == "typed")
      return page::TransitionType::TYPED;
    if (value.GetString() == "address_bar")
      return page::TransitionType::ADDRESS_BAR;
    if (value.GetString() == "auto_bookmark")
      return page::TransitionType::AUTO_BOOKMARK;
    if (value.GetString() == "auto_subframe")
      return page::TransitionType::AUTO_SUBFRAME;
    if (value.GetString() == "manual_subframe")
      return page::TransitionType::MANUAL_SUBFRAME;
    if (value.GetString() == "generated")
      return page::TransitionType::GENERATED;
    if (value.GetString() == "auto_toplevel")
      return page::TransitionType::AUTO_TOPLEVEL;
    if (value.GetString() == "form_submit")
      return page::TransitionType::FORM_SUBMIT;
    if (value.GetString() == "reload")
      return page::TransitionType::RELOAD;
    if (value.GetString() == "keyword")
      return page::TransitionType::KEYWORD;
    if (value.GetString() == "keyword_generated")
      return page::TransitionType::KEYWORD_GENERATED;
    if (value.GetString() == "other")
      return page::TransitionType::OTHER;
    errors->AddError("invalid enum value");
    return page::TransitionType::LINK;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::TransitionType& value) {
  switch (value) {
    case page::TransitionType::LINK:
      return std::make_unique<base::Value>("link");
    case page::TransitionType::TYPED:
      return std::make_unique<base::Value>("typed");
    case page::TransitionType::ADDRESS_BAR:
      return std::make_unique<base::Value>("address_bar");
    case page::TransitionType::AUTO_BOOKMARK:
      return std::make_unique<base::Value>("auto_bookmark");
    case page::TransitionType::AUTO_SUBFRAME:
      return std::make_unique<base::Value>("auto_subframe");
    case page::TransitionType::MANUAL_SUBFRAME:
      return std::make_unique<base::Value>("manual_subframe");
    case page::TransitionType::GENERATED:
      return std::make_unique<base::Value>("generated");
    case page::TransitionType::AUTO_TOPLEVEL:
      return std::make_unique<base::Value>("auto_toplevel");
    case page::TransitionType::FORM_SUBMIT:
      return std::make_unique<base::Value>("form_submit");
    case page::TransitionType::RELOAD:
      return std::make_unique<base::Value>("reload");
    case page::TransitionType::KEYWORD:
      return std::make_unique<base::Value>("keyword");
    case page::TransitionType::KEYWORD_GENERATED:
      return std::make_unique<base::Value>("keyword_generated");
    case page::TransitionType::OTHER:
      return std::make_unique<base::Value>("other");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::NavigationEntry> {
  static std::unique_ptr<page::NavigationEntry> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::NavigationEntry::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::NavigationEntry& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ScreencastFrameMetadata> {
  static std::unique_ptr<page::ScreencastFrameMetadata> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ScreencastFrameMetadata::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ScreencastFrameMetadata& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::DialogType> {
  static page::DialogType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::DialogType::ALERT;
    }
    if (value.GetString() == "alert")
      return page::DialogType::ALERT;
    if (value.GetString() == "confirm")
      return page::DialogType::CONFIRM;
    if (value.GetString() == "prompt")
      return page::DialogType::PROMPT;
    if (value.GetString() == "beforeunload")
      return page::DialogType::BEFOREUNLOAD;
    errors->AddError("invalid enum value");
    return page::DialogType::ALERT;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::DialogType& value) {
  switch (value) {
    case page::DialogType::ALERT:
      return std::make_unique<base::Value>("alert");
    case page::DialogType::CONFIRM:
      return std::make_unique<base::Value>("confirm");
    case page::DialogType::PROMPT:
      return std::make_unique<base::Value>("prompt");
    case page::DialogType::BEFOREUNLOAD:
      return std::make_unique<base::Value>("beforeunload");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::AppManifestError> {
  static std::unique_ptr<page::AppManifestError> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::AppManifestError::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::AppManifestError& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::AppManifestParsedProperties> {
  static std::unique_ptr<page::AppManifestParsedProperties> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::AppManifestParsedProperties::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::AppManifestParsedProperties& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::LayoutViewport> {
  static std::unique_ptr<page::LayoutViewport> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::LayoutViewport::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::LayoutViewport& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::VisualViewport> {
  static std::unique_ptr<page::VisualViewport> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::VisualViewport::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::VisualViewport& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::Viewport> {
  static std::unique_ptr<page::Viewport> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::Viewport::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::Viewport& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FontFamilies> {
  static std::unique_ptr<page::FontFamilies> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FontFamilies::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FontFamilies& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FontSizes> {
  static std::unique_ptr<page::FontSizes> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FontSizes::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FontSizes& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::ClientNavigationReason> {
  static page::ClientNavigationReason Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::ClientNavigationReason::FORM_SUBMISSION_GET;
    }
    if (value.GetString() == "formSubmissionGet")
      return page::ClientNavigationReason::FORM_SUBMISSION_GET;
    if (value.GetString() == "formSubmissionPost")
      return page::ClientNavigationReason::FORM_SUBMISSION_POST;
    if (value.GetString() == "httpHeaderRefresh")
      return page::ClientNavigationReason::HTTP_HEADER_REFRESH;
    if (value.GetString() == "scriptInitiated")
      return page::ClientNavigationReason::SCRIPT_INITIATED;
    if (value.GetString() == "metaTagRefresh")
      return page::ClientNavigationReason::META_TAG_REFRESH;
    if (value.GetString() == "pageBlockInterstitial")
      return page::ClientNavigationReason::PAGE_BLOCK_INTERSTITIAL;
    if (value.GetString() == "reload")
      return page::ClientNavigationReason::RELOAD;
    if (value.GetString() == "anchorClick")
      return page::ClientNavigationReason::ANCHOR_CLICK;
    errors->AddError("invalid enum value");
    return page::ClientNavigationReason::FORM_SUBMISSION_GET;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ClientNavigationReason& value) {
  switch (value) {
    case page::ClientNavigationReason::FORM_SUBMISSION_GET:
      return std::make_unique<base::Value>("formSubmissionGet");
    case page::ClientNavigationReason::FORM_SUBMISSION_POST:
      return std::make_unique<base::Value>("formSubmissionPost");
    case page::ClientNavigationReason::HTTP_HEADER_REFRESH:
      return std::make_unique<base::Value>("httpHeaderRefresh");
    case page::ClientNavigationReason::SCRIPT_INITIATED:
      return std::make_unique<base::Value>("scriptInitiated");
    case page::ClientNavigationReason::META_TAG_REFRESH:
      return std::make_unique<base::Value>("metaTagRefresh");
    case page::ClientNavigationReason::PAGE_BLOCK_INTERSTITIAL:
      return std::make_unique<base::Value>("pageBlockInterstitial");
    case page::ClientNavigationReason::RELOAD:
      return std::make_unique<base::Value>("reload");
    case page::ClientNavigationReason::ANCHOR_CLICK:
      return std::make_unique<base::Value>("anchorClick");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<page::ClientNavigationDisposition> {
  static page::ClientNavigationDisposition Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::ClientNavigationDisposition::CURRENT_TAB;
    }
    if (value.GetString() == "currentTab")
      return page::ClientNavigationDisposition::CURRENT_TAB;
    if (value.GetString() == "newTab")
      return page::ClientNavigationDisposition::NEW_TAB;
    if (value.GetString() == "newWindow")
      return page::ClientNavigationDisposition::NEW_WINDOW;
    if (value.GetString() == "download")
      return page::ClientNavigationDisposition::DOWNLOAD;
    errors->AddError("invalid enum value");
    return page::ClientNavigationDisposition::CURRENT_TAB;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ClientNavigationDisposition& value) {
  switch (value) {
    case page::ClientNavigationDisposition::CURRENT_TAB:
      return std::make_unique<base::Value>("currentTab");
    case page::ClientNavigationDisposition::NEW_TAB:
      return std::make_unique<base::Value>("newTab");
    case page::ClientNavigationDisposition::NEW_WINDOW:
      return std::make_unique<base::Value>("newWindow");
    case page::ClientNavigationDisposition::DOWNLOAD:
      return std::make_unique<base::Value>("download");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::InstallabilityErrorArgument> {
  static std::unique_ptr<page::InstallabilityErrorArgument> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::InstallabilityErrorArgument::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::InstallabilityErrorArgument& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::InstallabilityError> {
  static std::unique_ptr<page::InstallabilityError> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::InstallabilityError::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::InstallabilityError& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::ReferrerPolicy> {
  static page::ReferrerPolicy Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::ReferrerPolicy::NO_REFERRER;
    }
    if (value.GetString() == "noReferrer")
      return page::ReferrerPolicy::NO_REFERRER;
    if (value.GetString() == "noReferrerWhenDowngrade")
      return page::ReferrerPolicy::NO_REFERRER_WHEN_DOWNGRADE;
    if (value.GetString() == "origin")
      return page::ReferrerPolicy::ORIGIN;
    if (value.GetString() == "originWhenCrossOrigin")
      return page::ReferrerPolicy::ORIGIN_WHEN_CROSS_ORIGIN;
    if (value.GetString() == "sameOrigin")
      return page::ReferrerPolicy::SAME_ORIGIN;
    if (value.GetString() == "strictOrigin")
      return page::ReferrerPolicy::STRICT_ORIGIN;
    if (value.GetString() == "strictOriginWhenCrossOrigin")
      return page::ReferrerPolicy::STRICT_ORIGIN_WHEN_CROSS_ORIGIN;
    if (value.GetString() == "unsafeUrl")
      return page::ReferrerPolicy::UNSAFE_URL;
    errors->AddError("invalid enum value");
    return page::ReferrerPolicy::NO_REFERRER;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ReferrerPolicy& value) {
  switch (value) {
    case page::ReferrerPolicy::NO_REFERRER:
      return std::make_unique<base::Value>("noReferrer");
    case page::ReferrerPolicy::NO_REFERRER_WHEN_DOWNGRADE:
      return std::make_unique<base::Value>("noReferrerWhenDowngrade");
    case page::ReferrerPolicy::ORIGIN:
      return std::make_unique<base::Value>("origin");
    case page::ReferrerPolicy::ORIGIN_WHEN_CROSS_ORIGIN:
      return std::make_unique<base::Value>("originWhenCrossOrigin");
    case page::ReferrerPolicy::SAME_ORIGIN:
      return std::make_unique<base::Value>("sameOrigin");
    case page::ReferrerPolicy::STRICT_ORIGIN:
      return std::make_unique<base::Value>("strictOrigin");
    case page::ReferrerPolicy::STRICT_ORIGIN_WHEN_CROSS_ORIGIN:
      return std::make_unique<base::Value>("strictOriginWhenCrossOrigin");
    case page::ReferrerPolicy::UNSAFE_URL:
      return std::make_unique<base::Value>("unsafeUrl");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::AddScriptToEvaluateOnLoadParams> {
  static std::unique_ptr<page::AddScriptToEvaluateOnLoadParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::AddScriptToEvaluateOnLoadParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::AddScriptToEvaluateOnLoadParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::AddScriptToEvaluateOnLoadResult> {
  static std::unique_ptr<page::AddScriptToEvaluateOnLoadResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::AddScriptToEvaluateOnLoadResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::AddScriptToEvaluateOnLoadResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::AddScriptToEvaluateOnNewDocumentParams> {
  static std::unique_ptr<page::AddScriptToEvaluateOnNewDocumentParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::AddScriptToEvaluateOnNewDocumentParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::AddScriptToEvaluateOnNewDocumentParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::AddScriptToEvaluateOnNewDocumentResult> {
  static std::unique_ptr<page::AddScriptToEvaluateOnNewDocumentResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::AddScriptToEvaluateOnNewDocumentResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::AddScriptToEvaluateOnNewDocumentResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::BringToFrontParams> {
  static std::unique_ptr<page::BringToFrontParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::BringToFrontParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::BringToFrontParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::BringToFrontResult> {
  static std::unique_ptr<page::BringToFrontResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::BringToFrontResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::BringToFrontResult& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::CaptureScreenshotFormat> {
  static page::CaptureScreenshotFormat Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::CaptureScreenshotFormat::JPEG;
    }
    if (value.GetString() == "jpeg")
      return page::CaptureScreenshotFormat::JPEG;
    if (value.GetString() == "png")
      return page::CaptureScreenshotFormat::PNG;
    errors->AddError("invalid enum value");
    return page::CaptureScreenshotFormat::JPEG;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CaptureScreenshotFormat& value) {
  switch (value) {
    case page::CaptureScreenshotFormat::JPEG:
      return std::make_unique<base::Value>("jpeg");
    case page::CaptureScreenshotFormat::PNG:
      return std::make_unique<base::Value>("png");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::CaptureScreenshotParams> {
  static std::unique_ptr<page::CaptureScreenshotParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::CaptureScreenshotParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CaptureScreenshotParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::CaptureScreenshotResult> {
  static std::unique_ptr<page::CaptureScreenshotResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::CaptureScreenshotResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CaptureScreenshotResult& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::CaptureSnapshotFormat> {
  static page::CaptureSnapshotFormat Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::CaptureSnapshotFormat::MHTML;
    }
    if (value.GetString() == "mhtml")
      return page::CaptureSnapshotFormat::MHTML;
    errors->AddError("invalid enum value");
    return page::CaptureSnapshotFormat::MHTML;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CaptureSnapshotFormat& value) {
  switch (value) {
    case page::CaptureSnapshotFormat::MHTML:
      return std::make_unique<base::Value>("mhtml");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::CaptureSnapshotParams> {
  static std::unique_ptr<page::CaptureSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::CaptureSnapshotParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CaptureSnapshotParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::CaptureSnapshotResult> {
  static std::unique_ptr<page::CaptureSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::CaptureSnapshotResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CaptureSnapshotResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ClearDeviceMetricsOverrideParams> {
  static std::unique_ptr<page::ClearDeviceMetricsOverrideParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ClearDeviceMetricsOverrideParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ClearDeviceMetricsOverrideParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ClearDeviceMetricsOverrideResult> {
  static std::unique_ptr<page::ClearDeviceMetricsOverrideResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ClearDeviceMetricsOverrideResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ClearDeviceMetricsOverrideResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ClearDeviceOrientationOverrideParams> {
  static std::unique_ptr<page::ClearDeviceOrientationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ClearDeviceOrientationOverrideParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ClearDeviceOrientationOverrideParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ClearDeviceOrientationOverrideResult> {
  static std::unique_ptr<page::ClearDeviceOrientationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ClearDeviceOrientationOverrideResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ClearDeviceOrientationOverrideResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ClearGeolocationOverrideParams> {
  static std::unique_ptr<page::ClearGeolocationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ClearGeolocationOverrideParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ClearGeolocationOverrideParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ClearGeolocationOverrideResult> {
  static std::unique_ptr<page::ClearGeolocationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ClearGeolocationOverrideResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ClearGeolocationOverrideResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::CreateIsolatedWorldParams> {
  static std::unique_ptr<page::CreateIsolatedWorldParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::CreateIsolatedWorldParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CreateIsolatedWorldParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::CreateIsolatedWorldResult> {
  static std::unique_ptr<page::CreateIsolatedWorldResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::CreateIsolatedWorldResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CreateIsolatedWorldResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::DeleteCookieParams> {
  static std::unique_ptr<page::DeleteCookieParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::DeleteCookieParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::DeleteCookieParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::DeleteCookieResult> {
  static std::unique_ptr<page::DeleteCookieResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::DeleteCookieResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::DeleteCookieResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::DisableParams> {
  static std::unique_ptr<page::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::DisableResult> {
  static std::unique_ptr<page::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::EnableParams> {
  static std::unique_ptr<page::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::EnableResult> {
  static std::unique_ptr<page::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetAppManifestParams> {
  static std::unique_ptr<page::GetAppManifestParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetAppManifestParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetAppManifestParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetAppManifestResult> {
  static std::unique_ptr<page::GetAppManifestResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetAppManifestResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetAppManifestResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetInstallabilityErrorsParams> {
  static std::unique_ptr<page::GetInstallabilityErrorsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetInstallabilityErrorsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetInstallabilityErrorsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetInstallabilityErrorsResult> {
  static std::unique_ptr<page::GetInstallabilityErrorsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetInstallabilityErrorsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetInstallabilityErrorsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetManifestIconsParams> {
  static std::unique_ptr<page::GetManifestIconsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetManifestIconsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetManifestIconsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetManifestIconsResult> {
  static std::unique_ptr<page::GetManifestIconsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetManifestIconsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetManifestIconsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetCookiesParams> {
  static std::unique_ptr<page::GetCookiesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetCookiesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetCookiesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetCookiesResult> {
  static std::unique_ptr<page::GetCookiesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetCookiesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetCookiesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetFrameTreeParams> {
  static std::unique_ptr<page::GetFrameTreeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetFrameTreeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetFrameTreeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetFrameTreeResult> {
  static std::unique_ptr<page::GetFrameTreeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetFrameTreeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetFrameTreeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetLayoutMetricsParams> {
  static std::unique_ptr<page::GetLayoutMetricsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetLayoutMetricsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetLayoutMetricsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetLayoutMetricsResult> {
  static std::unique_ptr<page::GetLayoutMetricsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetLayoutMetricsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetLayoutMetricsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetNavigationHistoryParams> {
  static std::unique_ptr<page::GetNavigationHistoryParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetNavigationHistoryParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetNavigationHistoryParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetNavigationHistoryResult> {
  static std::unique_ptr<page::GetNavigationHistoryResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetNavigationHistoryResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetNavigationHistoryResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ResetNavigationHistoryParams> {
  static std::unique_ptr<page::ResetNavigationHistoryParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ResetNavigationHistoryParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ResetNavigationHistoryParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ResetNavigationHistoryResult> {
  static std::unique_ptr<page::ResetNavigationHistoryResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ResetNavigationHistoryResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ResetNavigationHistoryResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetResourceContentParams> {
  static std::unique_ptr<page::GetResourceContentParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetResourceContentParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetResourceContentParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetResourceContentResult> {
  static std::unique_ptr<page::GetResourceContentResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetResourceContentResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetResourceContentResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetResourceTreeParams> {
  static std::unique_ptr<page::GetResourceTreeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetResourceTreeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetResourceTreeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GetResourceTreeResult> {
  static std::unique_ptr<page::GetResourceTreeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GetResourceTreeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GetResourceTreeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::HandleJavaScriptDialogParams> {
  static std::unique_ptr<page::HandleJavaScriptDialogParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::HandleJavaScriptDialogParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::HandleJavaScriptDialogParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::HandleJavaScriptDialogResult> {
  static std::unique_ptr<page::HandleJavaScriptDialogResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::HandleJavaScriptDialogResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::HandleJavaScriptDialogResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::NavigateParams> {
  static std::unique_ptr<page::NavigateParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::NavigateParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::NavigateParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::NavigateResult> {
  static std::unique_ptr<page::NavigateResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::NavigateResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::NavigateResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::NavigateToHistoryEntryParams> {
  static std::unique_ptr<page::NavigateToHistoryEntryParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::NavigateToHistoryEntryParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::NavigateToHistoryEntryParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::NavigateToHistoryEntryResult> {
  static std::unique_ptr<page::NavigateToHistoryEntryResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::NavigateToHistoryEntryResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::NavigateToHistoryEntryResult& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::PrintToPDFTransferMode> {
  static page::PrintToPDFTransferMode Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::PrintToPDFTransferMode::RETURN_AS_BASE64;
    }
    if (value.GetString() == "ReturnAsBase64")
      return page::PrintToPDFTransferMode::RETURN_AS_BASE64;
    if (value.GetString() == "ReturnAsStream")
      return page::PrintToPDFTransferMode::RETURN_AS_STREAM;
    errors->AddError("invalid enum value");
    return page::PrintToPDFTransferMode::RETURN_AS_BASE64;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::PrintToPDFTransferMode& value) {
  switch (value) {
    case page::PrintToPDFTransferMode::RETURN_AS_BASE64:
      return std::make_unique<base::Value>("ReturnAsBase64");
    case page::PrintToPDFTransferMode::RETURN_AS_STREAM:
      return std::make_unique<base::Value>("ReturnAsStream");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::PrintToPDFParams> {
  static std::unique_ptr<page::PrintToPDFParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::PrintToPDFParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::PrintToPDFParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::PrintToPDFResult> {
  static std::unique_ptr<page::PrintToPDFResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::PrintToPDFResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::PrintToPDFResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ReloadParams> {
  static std::unique_ptr<page::ReloadParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ReloadParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ReloadParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ReloadResult> {
  static std::unique_ptr<page::ReloadResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ReloadResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ReloadResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::RemoveScriptToEvaluateOnLoadParams> {
  static std::unique_ptr<page::RemoveScriptToEvaluateOnLoadParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::RemoveScriptToEvaluateOnLoadParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::RemoveScriptToEvaluateOnLoadParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::RemoveScriptToEvaluateOnLoadResult> {
  static std::unique_ptr<page::RemoveScriptToEvaluateOnLoadResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::RemoveScriptToEvaluateOnLoadResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::RemoveScriptToEvaluateOnLoadResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::RemoveScriptToEvaluateOnNewDocumentParams> {
  static std::unique_ptr<page::RemoveScriptToEvaluateOnNewDocumentParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::RemoveScriptToEvaluateOnNewDocumentParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::RemoveScriptToEvaluateOnNewDocumentParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::RemoveScriptToEvaluateOnNewDocumentResult> {
  static std::unique_ptr<page::RemoveScriptToEvaluateOnNewDocumentResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::RemoveScriptToEvaluateOnNewDocumentResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::RemoveScriptToEvaluateOnNewDocumentResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ScreencastFrameAckParams> {
  static std::unique_ptr<page::ScreencastFrameAckParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ScreencastFrameAckParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ScreencastFrameAckParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ScreencastFrameAckResult> {
  static std::unique_ptr<page::ScreencastFrameAckResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ScreencastFrameAckResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ScreencastFrameAckResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SearchInResourceParams> {
  static std::unique_ptr<page::SearchInResourceParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SearchInResourceParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SearchInResourceParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SearchInResourceResult> {
  static std::unique_ptr<page::SearchInResourceResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SearchInResourceResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SearchInResourceResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetAdBlockingEnabledParams> {
  static std::unique_ptr<page::SetAdBlockingEnabledParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetAdBlockingEnabledParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetAdBlockingEnabledParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetAdBlockingEnabledResult> {
  static std::unique_ptr<page::SetAdBlockingEnabledResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetAdBlockingEnabledResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetAdBlockingEnabledResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetBypassCSPParams> {
  static std::unique_ptr<page::SetBypassCSPParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetBypassCSPParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetBypassCSPParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetBypassCSPResult> {
  static std::unique_ptr<page::SetBypassCSPResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetBypassCSPResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetBypassCSPResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetDeviceMetricsOverrideParams> {
  static std::unique_ptr<page::SetDeviceMetricsOverrideParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetDeviceMetricsOverrideParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetDeviceMetricsOverrideParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetDeviceMetricsOverrideResult> {
  static std::unique_ptr<page::SetDeviceMetricsOverrideResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetDeviceMetricsOverrideResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetDeviceMetricsOverrideResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetDeviceOrientationOverrideParams> {
  static std::unique_ptr<page::SetDeviceOrientationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetDeviceOrientationOverrideParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetDeviceOrientationOverrideParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetDeviceOrientationOverrideResult> {
  static std::unique_ptr<page::SetDeviceOrientationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetDeviceOrientationOverrideResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetDeviceOrientationOverrideResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetFontFamiliesParams> {
  static std::unique_ptr<page::SetFontFamiliesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetFontFamiliesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetFontFamiliesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetFontFamiliesResult> {
  static std::unique_ptr<page::SetFontFamiliesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetFontFamiliesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetFontFamiliesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetFontSizesParams> {
  static std::unique_ptr<page::SetFontSizesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetFontSizesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetFontSizesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetFontSizesResult> {
  static std::unique_ptr<page::SetFontSizesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetFontSizesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetFontSizesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetDocumentContentParams> {
  static std::unique_ptr<page::SetDocumentContentParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetDocumentContentParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetDocumentContentParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetDocumentContentResult> {
  static std::unique_ptr<page::SetDocumentContentResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetDocumentContentResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetDocumentContentResult& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::SetDownloadBehaviorBehavior> {
  static page::SetDownloadBehaviorBehavior Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::SetDownloadBehaviorBehavior::DENY;
    }
    if (value.GetString() == "deny")
      return page::SetDownloadBehaviorBehavior::DENY;
    if (value.GetString() == "allow")
      return page::SetDownloadBehaviorBehavior::ALLOW;
    if (value.GetString() == "default")
      return page::SetDownloadBehaviorBehavior::DEFAULT;
    errors->AddError("invalid enum value");
    return page::SetDownloadBehaviorBehavior::DENY;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetDownloadBehaviorBehavior& value) {
  switch (value) {
    case page::SetDownloadBehaviorBehavior::DENY:
      return std::make_unique<base::Value>("deny");
    case page::SetDownloadBehaviorBehavior::ALLOW:
      return std::make_unique<base::Value>("allow");
    case page::SetDownloadBehaviorBehavior::DEFAULT:
      return std::make_unique<base::Value>("default");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::SetDownloadBehaviorParams> {
  static std::unique_ptr<page::SetDownloadBehaviorParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetDownloadBehaviorParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetDownloadBehaviorParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetDownloadBehaviorResult> {
  static std::unique_ptr<page::SetDownloadBehaviorResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetDownloadBehaviorResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetDownloadBehaviorResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetGeolocationOverrideParams> {
  static std::unique_ptr<page::SetGeolocationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetGeolocationOverrideParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetGeolocationOverrideParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetGeolocationOverrideResult> {
  static std::unique_ptr<page::SetGeolocationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetGeolocationOverrideResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetGeolocationOverrideResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetLifecycleEventsEnabledParams> {
  static std::unique_ptr<page::SetLifecycleEventsEnabledParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetLifecycleEventsEnabledParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetLifecycleEventsEnabledParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetLifecycleEventsEnabledResult> {
  static std::unique_ptr<page::SetLifecycleEventsEnabledResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetLifecycleEventsEnabledResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetLifecycleEventsEnabledResult& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::SetTouchEmulationEnabledConfiguration> {
  static page::SetTouchEmulationEnabledConfiguration Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::SetTouchEmulationEnabledConfiguration::MOBILE;
    }
    if (value.GetString() == "mobile")
      return page::SetTouchEmulationEnabledConfiguration::MOBILE;
    if (value.GetString() == "desktop")
      return page::SetTouchEmulationEnabledConfiguration::DESKTOP;
    errors->AddError("invalid enum value");
    return page::SetTouchEmulationEnabledConfiguration::MOBILE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetTouchEmulationEnabledConfiguration& value) {
  switch (value) {
    case page::SetTouchEmulationEnabledConfiguration::MOBILE:
      return std::make_unique<base::Value>("mobile");
    case page::SetTouchEmulationEnabledConfiguration::DESKTOP:
      return std::make_unique<base::Value>("desktop");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::SetTouchEmulationEnabledParams> {
  static std::unique_ptr<page::SetTouchEmulationEnabledParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetTouchEmulationEnabledParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetTouchEmulationEnabledParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetTouchEmulationEnabledResult> {
  static std::unique_ptr<page::SetTouchEmulationEnabledResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetTouchEmulationEnabledResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetTouchEmulationEnabledResult& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::StartScreencastFormat> {
  static page::StartScreencastFormat Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::StartScreencastFormat::JPEG;
    }
    if (value.GetString() == "jpeg")
      return page::StartScreencastFormat::JPEG;
    if (value.GetString() == "png")
      return page::StartScreencastFormat::PNG;
    errors->AddError("invalid enum value");
    return page::StartScreencastFormat::JPEG;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::StartScreencastFormat& value) {
  switch (value) {
    case page::StartScreencastFormat::JPEG:
      return std::make_unique<base::Value>("jpeg");
    case page::StartScreencastFormat::PNG:
      return std::make_unique<base::Value>("png");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::StartScreencastParams> {
  static std::unique_ptr<page::StartScreencastParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::StartScreencastParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::StartScreencastParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::StartScreencastResult> {
  static std::unique_ptr<page::StartScreencastResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::StartScreencastResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::StartScreencastResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::StopLoadingParams> {
  static std::unique_ptr<page::StopLoadingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::StopLoadingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::StopLoadingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::StopLoadingResult> {
  static std::unique_ptr<page::StopLoadingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::StopLoadingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::StopLoadingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::CrashParams> {
  static std::unique_ptr<page::CrashParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::CrashParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CrashParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::CrashResult> {
  static std::unique_ptr<page::CrashResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::CrashResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CrashResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::CloseParams> {
  static std::unique_ptr<page::CloseParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::CloseParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CloseParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::CloseResult> {
  static std::unique_ptr<page::CloseResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::CloseResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CloseResult& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::SetWebLifecycleStateState> {
  static page::SetWebLifecycleStateState Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::SetWebLifecycleStateState::FROZEN;
    }
    if (value.GetString() == "frozen")
      return page::SetWebLifecycleStateState::FROZEN;
    if (value.GetString() == "active")
      return page::SetWebLifecycleStateState::ACTIVE;
    errors->AddError("invalid enum value");
    return page::SetWebLifecycleStateState::FROZEN;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetWebLifecycleStateState& value) {
  switch (value) {
    case page::SetWebLifecycleStateState::FROZEN:
      return std::make_unique<base::Value>("frozen");
    case page::SetWebLifecycleStateState::ACTIVE:
      return std::make_unique<base::Value>("active");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::SetWebLifecycleStateParams> {
  static std::unique_ptr<page::SetWebLifecycleStateParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetWebLifecycleStateParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetWebLifecycleStateParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetWebLifecycleStateResult> {
  static std::unique_ptr<page::SetWebLifecycleStateResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetWebLifecycleStateResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetWebLifecycleStateResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::StopScreencastParams> {
  static std::unique_ptr<page::StopScreencastParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::StopScreencastParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::StopScreencastParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::StopScreencastResult> {
  static std::unique_ptr<page::StopScreencastResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::StopScreencastResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::StopScreencastResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetProduceCompilationCacheParams> {
  static std::unique_ptr<page::SetProduceCompilationCacheParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetProduceCompilationCacheParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetProduceCompilationCacheParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetProduceCompilationCacheResult> {
  static std::unique_ptr<page::SetProduceCompilationCacheResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetProduceCompilationCacheResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetProduceCompilationCacheResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::AddCompilationCacheParams> {
  static std::unique_ptr<page::AddCompilationCacheParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::AddCompilationCacheParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::AddCompilationCacheParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::AddCompilationCacheResult> {
  static std::unique_ptr<page::AddCompilationCacheResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::AddCompilationCacheResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::AddCompilationCacheResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ClearCompilationCacheParams> {
  static std::unique_ptr<page::ClearCompilationCacheParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ClearCompilationCacheParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ClearCompilationCacheParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ClearCompilationCacheResult> {
  static std::unique_ptr<page::ClearCompilationCacheResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ClearCompilationCacheResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ClearCompilationCacheResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GenerateTestReportParams> {
  static std::unique_ptr<page::GenerateTestReportParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GenerateTestReportParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GenerateTestReportParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::GenerateTestReportResult> {
  static std::unique_ptr<page::GenerateTestReportResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::GenerateTestReportResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::GenerateTestReportResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::WaitForDebuggerParams> {
  static std::unique_ptr<page::WaitForDebuggerParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::WaitForDebuggerParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::WaitForDebuggerParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::WaitForDebuggerResult> {
  static std::unique_ptr<page::WaitForDebuggerResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::WaitForDebuggerResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::WaitForDebuggerResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetInterceptFileChooserDialogParams> {
  static std::unique_ptr<page::SetInterceptFileChooserDialogParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetInterceptFileChooserDialogParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetInterceptFileChooserDialogParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::SetInterceptFileChooserDialogResult> {
  static std::unique_ptr<page::SetInterceptFileChooserDialogResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::SetInterceptFileChooserDialogResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::SetInterceptFileChooserDialogResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::DomContentEventFiredParams> {
  static std::unique_ptr<page::DomContentEventFiredParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::DomContentEventFiredParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::DomContentEventFiredParams& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::FileChooserOpenedMode> {
  static page::FileChooserOpenedMode Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::FileChooserOpenedMode::SELECT_SINGLE;
    }
    if (value.GetString() == "selectSingle")
      return page::FileChooserOpenedMode::SELECT_SINGLE;
    if (value.GetString() == "selectMultiple")
      return page::FileChooserOpenedMode::SELECT_MULTIPLE;
    errors->AddError("invalid enum value");
    return page::FileChooserOpenedMode::SELECT_SINGLE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FileChooserOpenedMode& value) {
  switch (value) {
    case page::FileChooserOpenedMode::SELECT_SINGLE:
      return std::make_unique<base::Value>("selectSingle");
    case page::FileChooserOpenedMode::SELECT_MULTIPLE:
      return std::make_unique<base::Value>("selectMultiple");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::FileChooserOpenedParams> {
  static std::unique_ptr<page::FileChooserOpenedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FileChooserOpenedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FileChooserOpenedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameAttachedParams> {
  static std::unique_ptr<page::FrameAttachedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameAttachedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameAttachedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameClearedScheduledNavigationParams> {
  static std::unique_ptr<page::FrameClearedScheduledNavigationParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameClearedScheduledNavigationParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameClearedScheduledNavigationParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameDetachedParams> {
  static std::unique_ptr<page::FrameDetachedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameDetachedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameDetachedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameNavigatedParams> {
  static std::unique_ptr<page::FrameNavigatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameNavigatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameNavigatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameResizedParams> {
  static std::unique_ptr<page::FrameResizedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameResizedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameResizedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameRequestedNavigationParams> {
  static std::unique_ptr<page::FrameRequestedNavigationParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameRequestedNavigationParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameRequestedNavigationParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameScheduledNavigationParams> {
  static std::unique_ptr<page::FrameScheduledNavigationParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameScheduledNavigationParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameScheduledNavigationParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameStartedLoadingParams> {
  static std::unique_ptr<page::FrameStartedLoadingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameStartedLoadingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameStartedLoadingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::FrameStoppedLoadingParams> {
  static std::unique_ptr<page::FrameStoppedLoadingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::FrameStoppedLoadingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::FrameStoppedLoadingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::DownloadWillBeginParams> {
  static std::unique_ptr<page::DownloadWillBeginParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::DownloadWillBeginParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::DownloadWillBeginParams& value) {
  return value.Serialize();
}

template <>
struct FromValue<page::DownloadProgressState> {
  static page::DownloadProgressState Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return page::DownloadProgressState::IN_PROGRESS;
    }
    if (value.GetString() == "inProgress")
      return page::DownloadProgressState::IN_PROGRESS;
    if (value.GetString() == "completed")
      return page::DownloadProgressState::COMPLETED;
    if (value.GetString() == "canceled")
      return page::DownloadProgressState::CANCELED;
    errors->AddError("invalid enum value");
    return page::DownloadProgressState::IN_PROGRESS;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::DownloadProgressState& value) {
  switch (value) {
    case page::DownloadProgressState::IN_PROGRESS:
      return std::make_unique<base::Value>("inProgress");
    case page::DownloadProgressState::COMPLETED:
      return std::make_unique<base::Value>("completed");
    case page::DownloadProgressState::CANCELED:
      return std::make_unique<base::Value>("canceled");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<page::DownloadProgressParams> {
  static std::unique_ptr<page::DownloadProgressParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::DownloadProgressParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::DownloadProgressParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::InterstitialHiddenParams> {
  static std::unique_ptr<page::InterstitialHiddenParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::InterstitialHiddenParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::InterstitialHiddenParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::InterstitialShownParams> {
  static std::unique_ptr<page::InterstitialShownParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::InterstitialShownParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::InterstitialShownParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::JavascriptDialogClosedParams> {
  static std::unique_ptr<page::JavascriptDialogClosedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::JavascriptDialogClosedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::JavascriptDialogClosedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::JavascriptDialogOpeningParams> {
  static std::unique_ptr<page::JavascriptDialogOpeningParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::JavascriptDialogOpeningParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::JavascriptDialogOpeningParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::LifecycleEventParams> {
  static std::unique_ptr<page::LifecycleEventParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::LifecycleEventParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::LifecycleEventParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::LoadEventFiredParams> {
  static std::unique_ptr<page::LoadEventFiredParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::LoadEventFiredParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::LoadEventFiredParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::NavigatedWithinDocumentParams> {
  static std::unique_ptr<page::NavigatedWithinDocumentParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::NavigatedWithinDocumentParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::NavigatedWithinDocumentParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ScreencastFrameParams> {
  static std::unique_ptr<page::ScreencastFrameParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ScreencastFrameParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ScreencastFrameParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::ScreencastVisibilityChangedParams> {
  static std::unique_ptr<page::ScreencastVisibilityChangedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::ScreencastVisibilityChangedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::ScreencastVisibilityChangedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::WindowOpenParams> {
  static std::unique_ptr<page::WindowOpenParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::WindowOpenParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::WindowOpenParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<page::CompilationCacheProducedParams> {
  static std::unique_ptr<page::CompilationCacheProducedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return page::CompilationCacheProducedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const page::CompilationCacheProducedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_PAGE_H_
