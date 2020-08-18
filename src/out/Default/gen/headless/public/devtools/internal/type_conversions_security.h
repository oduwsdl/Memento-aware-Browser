// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_SECURITY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_SECURITY_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<security::MixedContentType> {
  static security::MixedContentType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return security::MixedContentType::BLOCKABLE;
    }
    if (value.GetString() == "blockable")
      return security::MixedContentType::BLOCKABLE;
    if (value.GetString() == "optionally-blockable")
      return security::MixedContentType::OPTIONALLY_BLOCKABLE;
    if (value.GetString() == "none")
      return security::MixedContentType::NONE;
    errors->AddError("invalid enum value");
    return security::MixedContentType::BLOCKABLE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::MixedContentType& value) {
  switch (value) {
    case security::MixedContentType::BLOCKABLE:
      return std::make_unique<base::Value>("blockable");
    case security::MixedContentType::OPTIONALLY_BLOCKABLE:
      return std::make_unique<base::Value>("optionally-blockable");
    case security::MixedContentType::NONE:
      return std::make_unique<base::Value>("none");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<security::SecurityState> {
  static security::SecurityState Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return security::SecurityState::UNKNOWN;
    }
    if (value.GetString() == "unknown")
      return security::SecurityState::UNKNOWN;
    if (value.GetString() == "neutral")
      return security::SecurityState::NEUTRAL;
    if (value.GetString() == "insecure")
      return security::SecurityState::INSECURE;
    if (value.GetString() == "secure")
      return security::SecurityState::SECURE;
    if (value.GetString() == "info")
      return security::SecurityState::INFO;
    if (value.GetString() == "insecure-broken")
      return security::SecurityState::INSECURE_BROKEN;
    errors->AddError("invalid enum value");
    return security::SecurityState::UNKNOWN;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::SecurityState& value) {
  switch (value) {
    case security::SecurityState::UNKNOWN:
      return std::make_unique<base::Value>("unknown");
    case security::SecurityState::NEUTRAL:
      return std::make_unique<base::Value>("neutral");
    case security::SecurityState::INSECURE:
      return std::make_unique<base::Value>("insecure");
    case security::SecurityState::SECURE:
      return std::make_unique<base::Value>("secure");
    case security::SecurityState::INFO:
      return std::make_unique<base::Value>("info");
    case security::SecurityState::INSECURE_BROKEN:
      return std::make_unique<base::Value>("insecure-broken");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<security::CertificateSecurityState> {
  static std::unique_ptr<security::CertificateSecurityState> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::CertificateSecurityState::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::CertificateSecurityState& value) {
  return value.Serialize();
}

template <>
struct FromValue<security::SafetyTipStatus> {
  static security::SafetyTipStatus Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return security::SafetyTipStatus::BAD_REPUTATION;
    }
    if (value.GetString() == "badReputation")
      return security::SafetyTipStatus::BAD_REPUTATION;
    if (value.GetString() == "lookalike")
      return security::SafetyTipStatus::LOOKALIKE;
    errors->AddError("invalid enum value");
    return security::SafetyTipStatus::BAD_REPUTATION;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::SafetyTipStatus& value) {
  switch (value) {
    case security::SafetyTipStatus::BAD_REPUTATION:
      return std::make_unique<base::Value>("badReputation");
    case security::SafetyTipStatus::LOOKALIKE:
      return std::make_unique<base::Value>("lookalike");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<security::SafetyTipInfo> {
  static std::unique_ptr<security::SafetyTipInfo> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::SafetyTipInfo::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::SafetyTipInfo& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::VisibleSecurityState> {
  static std::unique_ptr<security::VisibleSecurityState> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::VisibleSecurityState::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::VisibleSecurityState& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::SecurityStateExplanation> {
  static std::unique_ptr<security::SecurityStateExplanation> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::SecurityStateExplanation::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::SecurityStateExplanation& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::InsecureContentStatus> {
  static std::unique_ptr<security::InsecureContentStatus> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::InsecureContentStatus::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::InsecureContentStatus& value) {
  return value.Serialize();
}

template <>
struct FromValue<security::CertificateErrorAction> {
  static security::CertificateErrorAction Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return security::CertificateErrorAction::CONTINUE;
    }
    if (value.GetString() == "continue")
      return security::CertificateErrorAction::CONTINUE;
    if (value.GetString() == "cancel")
      return security::CertificateErrorAction::CANCEL;
    errors->AddError("invalid enum value");
    return security::CertificateErrorAction::CONTINUE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::CertificateErrorAction& value) {
  switch (value) {
    case security::CertificateErrorAction::CONTINUE:
      return std::make_unique<base::Value>("continue");
    case security::CertificateErrorAction::CANCEL:
      return std::make_unique<base::Value>("cancel");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<security::DisableParams> {
  static std::unique_ptr<security::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::DisableResult> {
  static std::unique_ptr<security::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::EnableParams> {
  static std::unique_ptr<security::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::EnableResult> {
  static std::unique_ptr<security::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::SetIgnoreCertificateErrorsParams> {
  static std::unique_ptr<security::SetIgnoreCertificateErrorsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::SetIgnoreCertificateErrorsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::SetIgnoreCertificateErrorsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::SetIgnoreCertificateErrorsResult> {
  static std::unique_ptr<security::SetIgnoreCertificateErrorsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::SetIgnoreCertificateErrorsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::SetIgnoreCertificateErrorsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::HandleCertificateErrorParams> {
  static std::unique_ptr<security::HandleCertificateErrorParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::HandleCertificateErrorParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::HandleCertificateErrorParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::HandleCertificateErrorResult> {
  static std::unique_ptr<security::HandleCertificateErrorResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::HandleCertificateErrorResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::HandleCertificateErrorResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::SetOverrideCertificateErrorsParams> {
  static std::unique_ptr<security::SetOverrideCertificateErrorsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::SetOverrideCertificateErrorsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::SetOverrideCertificateErrorsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::SetOverrideCertificateErrorsResult> {
  static std::unique_ptr<security::SetOverrideCertificateErrorsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::SetOverrideCertificateErrorsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::SetOverrideCertificateErrorsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::CertificateErrorParams> {
  static std::unique_ptr<security::CertificateErrorParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::CertificateErrorParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::CertificateErrorParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::VisibleSecurityStateChangedParams> {
  static std::unique_ptr<security::VisibleSecurityStateChangedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::VisibleSecurityStateChangedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::VisibleSecurityStateChangedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<security::SecurityStateChangedParams> {
  static std::unique_ptr<security::SecurityStateChangedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return security::SecurityStateChangedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const security::SecurityStateChangedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_SECURITY_H_
