// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_NETWORK_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_NETWORK_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {

template <>
struct FromValue<network::ResourceType> {
  static network::ResourceType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::ResourceType::DOCUMENT;
    }
    if (value.GetString() == "Document")
      return network::ResourceType::DOCUMENT;
    if (value.GetString() == "Stylesheet")
      return network::ResourceType::STYLESHEET;
    if (value.GetString() == "Image")
      return network::ResourceType::IMAGE;
    if (value.GetString() == "Media")
      return network::ResourceType::MEDIA;
    if (value.GetString() == "Font")
      return network::ResourceType::FONT;
    if (value.GetString() == "Script")
      return network::ResourceType::SCRIPT;
    if (value.GetString() == "TextTrack")
      return network::ResourceType::TEXT_TRACK;
    if (value.GetString() == "XHR")
      return network::ResourceType::XHR;
    if (value.GetString() == "Fetch")
      return network::ResourceType::FETCH;
    if (value.GetString() == "EventSource")
      return network::ResourceType::EVENT_SOURCE;
    if (value.GetString() == "WebSocket")
      return network::ResourceType::WEB_SOCKET;
    if (value.GetString() == "Manifest")
      return network::ResourceType::MANIFEST;
    if (value.GetString() == "SignedExchange")
      return network::ResourceType::SIGNED_EXCHANGE;
    if (value.GetString() == "Ping")
      return network::ResourceType::PING;
    if (value.GetString() == "CSPViolationReport")
      return network::ResourceType::CSP_VIOLATION_REPORT;
    if (value.GetString() == "Other")
      return network::ResourceType::OTHER;
    errors->AddError("invalid enum value");
    return network::ResourceType::DOCUMENT;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ResourceType& value) {
  switch (value) {
    case network::ResourceType::DOCUMENT:
      return std::make_unique<base::Value>("Document");
    case network::ResourceType::STYLESHEET:
      return std::make_unique<base::Value>("Stylesheet");
    case network::ResourceType::IMAGE:
      return std::make_unique<base::Value>("Image");
    case network::ResourceType::MEDIA:
      return std::make_unique<base::Value>("Media");
    case network::ResourceType::FONT:
      return std::make_unique<base::Value>("Font");
    case network::ResourceType::SCRIPT:
      return std::make_unique<base::Value>("Script");
    case network::ResourceType::TEXT_TRACK:
      return std::make_unique<base::Value>("TextTrack");
    case network::ResourceType::XHR:
      return std::make_unique<base::Value>("XHR");
    case network::ResourceType::FETCH:
      return std::make_unique<base::Value>("Fetch");
    case network::ResourceType::EVENT_SOURCE:
      return std::make_unique<base::Value>("EventSource");
    case network::ResourceType::WEB_SOCKET:
      return std::make_unique<base::Value>("WebSocket");
    case network::ResourceType::MANIFEST:
      return std::make_unique<base::Value>("Manifest");
    case network::ResourceType::SIGNED_EXCHANGE:
      return std::make_unique<base::Value>("SignedExchange");
    case network::ResourceType::PING:
      return std::make_unique<base::Value>("Ping");
    case network::ResourceType::CSP_VIOLATION_REPORT:
      return std::make_unique<base::Value>("CSPViolationReport");
    case network::ResourceType::OTHER:
      return std::make_unique<base::Value>("Other");
  };
  NOTREACHED();
  return nullptr;
}



template <>
struct FromValue<network::ErrorReason> {
  static network::ErrorReason Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::ErrorReason::FAILED;
    }
    if (value.GetString() == "Failed")
      return network::ErrorReason::FAILED;
    if (value.GetString() == "Aborted")
      return network::ErrorReason::ABORTED;
    if (value.GetString() == "TimedOut")
      return network::ErrorReason::TIMED_OUT;
    if (value.GetString() == "AccessDenied")
      return network::ErrorReason::ACCESS_DENIED;
    if (value.GetString() == "ConnectionClosed")
      return network::ErrorReason::CONNECTION_CLOSED;
    if (value.GetString() == "ConnectionReset")
      return network::ErrorReason::CONNECTION_RESET;
    if (value.GetString() == "ConnectionRefused")
      return network::ErrorReason::CONNECTION_REFUSED;
    if (value.GetString() == "ConnectionAborted")
      return network::ErrorReason::CONNECTION_ABORTED;
    if (value.GetString() == "ConnectionFailed")
      return network::ErrorReason::CONNECTION_FAILED;
    if (value.GetString() == "NameNotResolved")
      return network::ErrorReason::NAME_NOT_RESOLVED;
    if (value.GetString() == "InternetDisconnected")
      return network::ErrorReason::INTERNET_DISCONNECTED;
    if (value.GetString() == "AddressUnreachable")
      return network::ErrorReason::ADDRESS_UNREACHABLE;
    if (value.GetString() == "BlockedByClient")
      return network::ErrorReason::BLOCKED_BY_CLIENT;
    if (value.GetString() == "BlockedByResponse")
      return network::ErrorReason::BLOCKED_BY_RESPONSE;
    errors->AddError("invalid enum value");
    return network::ErrorReason::FAILED;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ErrorReason& value) {
  switch (value) {
    case network::ErrorReason::FAILED:
      return std::make_unique<base::Value>("Failed");
    case network::ErrorReason::ABORTED:
      return std::make_unique<base::Value>("Aborted");
    case network::ErrorReason::TIMED_OUT:
      return std::make_unique<base::Value>("TimedOut");
    case network::ErrorReason::ACCESS_DENIED:
      return std::make_unique<base::Value>("AccessDenied");
    case network::ErrorReason::CONNECTION_CLOSED:
      return std::make_unique<base::Value>("ConnectionClosed");
    case network::ErrorReason::CONNECTION_RESET:
      return std::make_unique<base::Value>("ConnectionReset");
    case network::ErrorReason::CONNECTION_REFUSED:
      return std::make_unique<base::Value>("ConnectionRefused");
    case network::ErrorReason::CONNECTION_ABORTED:
      return std::make_unique<base::Value>("ConnectionAborted");
    case network::ErrorReason::CONNECTION_FAILED:
      return std::make_unique<base::Value>("ConnectionFailed");
    case network::ErrorReason::NAME_NOT_RESOLVED:
      return std::make_unique<base::Value>("NameNotResolved");
    case network::ErrorReason::INTERNET_DISCONNECTED:
      return std::make_unique<base::Value>("InternetDisconnected");
    case network::ErrorReason::ADDRESS_UNREACHABLE:
      return std::make_unique<base::Value>("AddressUnreachable");
    case network::ErrorReason::BLOCKED_BY_CLIENT:
      return std::make_unique<base::Value>("BlockedByClient");
    case network::ErrorReason::BLOCKED_BY_RESPONSE:
      return std::make_unique<base::Value>("BlockedByResponse");
  };
  NOTREACHED();
  return nullptr;
}



template <>
struct FromValue<network::ConnectionType> {
  static network::ConnectionType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::ConnectionType::NONE;
    }
    if (value.GetString() == "none")
      return network::ConnectionType::NONE;
    if (value.GetString() == "cellular2g")
      return network::ConnectionType::CELLULAR2G;
    if (value.GetString() == "cellular3g")
      return network::ConnectionType::CELLULAR3G;
    if (value.GetString() == "cellular4g")
      return network::ConnectionType::CELLULAR4G;
    if (value.GetString() == "bluetooth")
      return network::ConnectionType::BLUETOOTH;
    if (value.GetString() == "ethernet")
      return network::ConnectionType::ETHERNET;
    if (value.GetString() == "wifi")
      return network::ConnectionType::WIFI;
    if (value.GetString() == "wimax")
      return network::ConnectionType::WIMAX;
    if (value.GetString() == "other")
      return network::ConnectionType::OTHER;
    errors->AddError("invalid enum value");
    return network::ConnectionType::NONE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ConnectionType& value) {
  switch (value) {
    case network::ConnectionType::NONE:
      return std::make_unique<base::Value>("none");
    case network::ConnectionType::CELLULAR2G:
      return std::make_unique<base::Value>("cellular2g");
    case network::ConnectionType::CELLULAR3G:
      return std::make_unique<base::Value>("cellular3g");
    case network::ConnectionType::CELLULAR4G:
      return std::make_unique<base::Value>("cellular4g");
    case network::ConnectionType::BLUETOOTH:
      return std::make_unique<base::Value>("bluetooth");
    case network::ConnectionType::ETHERNET:
      return std::make_unique<base::Value>("ethernet");
    case network::ConnectionType::WIFI:
      return std::make_unique<base::Value>("wifi");
    case network::ConnectionType::WIMAX:
      return std::make_unique<base::Value>("wimax");
    case network::ConnectionType::OTHER:
      return std::make_unique<base::Value>("other");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<network::CookieSameSite> {
  static network::CookieSameSite Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::CookieSameSite::EXACT;
    }
    if (value.GetString() == "Strict")
      return network::CookieSameSite::EXACT;
    if (value.GetString() == "Lax")
      return network::CookieSameSite::LAX;
    if (value.GetString() == "None")
      return network::CookieSameSite::NONE;
    errors->AddError("invalid enum value");
    return network::CookieSameSite::EXACT;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CookieSameSite& value) {
  switch (value) {
    case network::CookieSameSite::EXACT:
      return std::make_unique<base::Value>("Strict");
    case network::CookieSameSite::LAX:
      return std::make_unique<base::Value>("Lax");
    case network::CookieSameSite::NONE:
      return std::make_unique<base::Value>("None");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<network::CookiePriority> {
  static network::CookiePriority Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::CookiePriority::LOW;
    }
    if (value.GetString() == "Low")
      return network::CookiePriority::LOW;
    if (value.GetString() == "Medium")
      return network::CookiePriority::MEDIUM;
    if (value.GetString() == "High")
      return network::CookiePriority::HIGH;
    errors->AddError("invalid enum value");
    return network::CookiePriority::LOW;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CookiePriority& value) {
  switch (value) {
    case network::CookiePriority::LOW:
      return std::make_unique<base::Value>("Low");
    case network::CookiePriority::MEDIUM:
      return std::make_unique<base::Value>("Medium");
    case network::CookiePriority::HIGH:
      return std::make_unique<base::Value>("High");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<network::ResourceTiming> {
  static std::unique_ptr<network::ResourceTiming> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ResourceTiming::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ResourceTiming& value) {
  return value.Serialize();
}

template <>
struct FromValue<network::ResourcePriority> {
  static network::ResourcePriority Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::ResourcePriority::VERY_LOW;
    }
    if (value.GetString() == "VeryLow")
      return network::ResourcePriority::VERY_LOW;
    if (value.GetString() == "Low")
      return network::ResourcePriority::LOW;
    if (value.GetString() == "Medium")
      return network::ResourcePriority::MEDIUM;
    if (value.GetString() == "High")
      return network::ResourcePriority::HIGH;
    if (value.GetString() == "VeryHigh")
      return network::ResourcePriority::VERY_HIGH;
    errors->AddError("invalid enum value");
    return network::ResourcePriority::VERY_LOW;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ResourcePriority& value) {
  switch (value) {
    case network::ResourcePriority::VERY_LOW:
      return std::make_unique<base::Value>("VeryLow");
    case network::ResourcePriority::LOW:
      return std::make_unique<base::Value>("Low");
    case network::ResourcePriority::MEDIUM:
      return std::make_unique<base::Value>("Medium");
    case network::ResourcePriority::HIGH:
      return std::make_unique<base::Value>("High");
    case network::ResourcePriority::VERY_HIGH:
      return std::make_unique<base::Value>("VeryHigh");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<network::Request> {
  static std::unique_ptr<network::Request> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::Request::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::Request& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SignedCertificateTimestamp> {
  static std::unique_ptr<network::SignedCertificateTimestamp> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SignedCertificateTimestamp::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SignedCertificateTimestamp& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SecurityDetails> {
  static std::unique_ptr<network::SecurityDetails> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SecurityDetails::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SecurityDetails& value) {
  return value.Serialize();
}

template <>
struct FromValue<network::CertificateTransparencyCompliance> {
  static network::CertificateTransparencyCompliance Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::CertificateTransparencyCompliance::UNKNOWN;
    }
    if (value.GetString() == "unknown")
      return network::CertificateTransparencyCompliance::UNKNOWN;
    if (value.GetString() == "not-compliant")
      return network::CertificateTransparencyCompliance::NOT_COMPLIANT;
    if (value.GetString() == "compliant")
      return network::CertificateTransparencyCompliance::COMPLIANT;
    errors->AddError("invalid enum value");
    return network::CertificateTransparencyCompliance::UNKNOWN;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CertificateTransparencyCompliance& value) {
  switch (value) {
    case network::CertificateTransparencyCompliance::UNKNOWN:
      return std::make_unique<base::Value>("unknown");
    case network::CertificateTransparencyCompliance::NOT_COMPLIANT:
      return std::make_unique<base::Value>("not-compliant");
    case network::CertificateTransparencyCompliance::COMPLIANT:
      return std::make_unique<base::Value>("compliant");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<network::BlockedReason> {
  static network::BlockedReason Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::BlockedReason::OTHER;
    }
    if (value.GetString() == "other")
      return network::BlockedReason::OTHER;
    if (value.GetString() == "csp")
      return network::BlockedReason::CSP;
    if (value.GetString() == "mixed-content")
      return network::BlockedReason::MIXED_CONTENT;
    if (value.GetString() == "origin")
      return network::BlockedReason::ORIGIN;
    if (value.GetString() == "inspector")
      return network::BlockedReason::INSPECTOR;
    if (value.GetString() == "subresource-filter")
      return network::BlockedReason::SUBRESOURCE_FILTER;
    if (value.GetString() == "content-type")
      return network::BlockedReason::CONTENT_TYPE;
    if (value.GetString() == "collapsed-by-client")
      return network::BlockedReason::COLLAPSED_BY_CLIENT;
    if (value.GetString() == "coep-frame-resource-needs-coep-header")
      return network::BlockedReason::COEP_FRAME_RESOURCE_NEEDS_COEP_HEADER;
    if (value.GetString() == "coop-sandboxed-iframe-cannot-navigate-to-coop-page")
      return network::BlockedReason::COOP_SANDBOXED_IFRAME_CANNOT_NAVIGATE_TO_COOP_PAGE;
    if (value.GetString() == "corp-not-same-origin")
      return network::BlockedReason::CORP_NOT_SAME_ORIGIN;
    if (value.GetString() == "corp-not-same-origin-after-defaulted-to-same-origin-by-coep")
      return network::BlockedReason::CORP_NOT_SAME_ORIGIN_AFTER_DEFAULTED_TO_SAME_ORIGIN_BY_COEP;
    if (value.GetString() == "corp-not-same-site")
      return network::BlockedReason::CORP_NOT_SAME_SITE;
    errors->AddError("invalid enum value");
    return network::BlockedReason::OTHER;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::BlockedReason& value) {
  switch (value) {
    case network::BlockedReason::OTHER:
      return std::make_unique<base::Value>("other");
    case network::BlockedReason::CSP:
      return std::make_unique<base::Value>("csp");
    case network::BlockedReason::MIXED_CONTENT:
      return std::make_unique<base::Value>("mixed-content");
    case network::BlockedReason::ORIGIN:
      return std::make_unique<base::Value>("origin");
    case network::BlockedReason::INSPECTOR:
      return std::make_unique<base::Value>("inspector");
    case network::BlockedReason::SUBRESOURCE_FILTER:
      return std::make_unique<base::Value>("subresource-filter");
    case network::BlockedReason::CONTENT_TYPE:
      return std::make_unique<base::Value>("content-type");
    case network::BlockedReason::COLLAPSED_BY_CLIENT:
      return std::make_unique<base::Value>("collapsed-by-client");
    case network::BlockedReason::COEP_FRAME_RESOURCE_NEEDS_COEP_HEADER:
      return std::make_unique<base::Value>("coep-frame-resource-needs-coep-header");
    case network::BlockedReason::COOP_SANDBOXED_IFRAME_CANNOT_NAVIGATE_TO_COOP_PAGE:
      return std::make_unique<base::Value>("coop-sandboxed-iframe-cannot-navigate-to-coop-page");
    case network::BlockedReason::CORP_NOT_SAME_ORIGIN:
      return std::make_unique<base::Value>("corp-not-same-origin");
    case network::BlockedReason::CORP_NOT_SAME_ORIGIN_AFTER_DEFAULTED_TO_SAME_ORIGIN_BY_COEP:
      return std::make_unique<base::Value>("corp-not-same-origin-after-defaulted-to-same-origin-by-coep");
    case network::BlockedReason::CORP_NOT_SAME_SITE:
      return std::make_unique<base::Value>("corp-not-same-site");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<network::ServiceWorkerResponseSource> {
  static network::ServiceWorkerResponseSource Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::ServiceWorkerResponseSource::CACHE_STORAGE;
    }
    if (value.GetString() == "cache-storage")
      return network::ServiceWorkerResponseSource::CACHE_STORAGE;
    if (value.GetString() == "http-cache")
      return network::ServiceWorkerResponseSource::HTTP_CACHE;
    if (value.GetString() == "fallback-code")
      return network::ServiceWorkerResponseSource::FALLBACK_CODE;
    if (value.GetString() == "network")
      return network::ServiceWorkerResponseSource::NETWORK;
    errors->AddError("invalid enum value");
    return network::ServiceWorkerResponseSource::CACHE_STORAGE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ServiceWorkerResponseSource& value) {
  switch (value) {
    case network::ServiceWorkerResponseSource::CACHE_STORAGE:
      return std::make_unique<base::Value>("cache-storage");
    case network::ServiceWorkerResponseSource::HTTP_CACHE:
      return std::make_unique<base::Value>("http-cache");
    case network::ServiceWorkerResponseSource::FALLBACK_CODE:
      return std::make_unique<base::Value>("fallback-code");
    case network::ServiceWorkerResponseSource::NETWORK:
      return std::make_unique<base::Value>("network");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<network::Response> {
  static std::unique_ptr<network::Response> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::Response::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::Response& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::WebSocketRequest> {
  static std::unique_ptr<network::WebSocketRequest> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::WebSocketRequest::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::WebSocketRequest& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::WebSocketResponse> {
  static std::unique_ptr<network::WebSocketResponse> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::WebSocketResponse::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::WebSocketResponse& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::WebSocketFrame> {
  static std::unique_ptr<network::WebSocketFrame> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::WebSocketFrame::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::WebSocketFrame& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::CachedResource> {
  static std::unique_ptr<network::CachedResource> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::CachedResource::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CachedResource& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::Initiator> {
  static std::unique_ptr<network::Initiator> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::Initiator::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::Initiator& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::Cookie> {
  static std::unique_ptr<network::Cookie> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::Cookie::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::Cookie& value) {
  return value.Serialize();
}

template <>
struct FromValue<network::SetCookieBlockedReason> {
  static network::SetCookieBlockedReason Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::SetCookieBlockedReason::SECURE_ONLY;
    }
    if (value.GetString() == "SecureOnly")
      return network::SetCookieBlockedReason::SECURE_ONLY;
    if (value.GetString() == "SameSiteStrict")
      return network::SetCookieBlockedReason::SAME_SITE_STRICT;
    if (value.GetString() == "SameSiteLax")
      return network::SetCookieBlockedReason::SAME_SITE_LAX;
    if (value.GetString() == "SameSiteUnspecifiedTreatedAsLax")
      return network::SetCookieBlockedReason::SAME_SITE_UNSPECIFIED_TREATED_AS_LAX;
    if (value.GetString() == "SameSiteNoneInsecure")
      return network::SetCookieBlockedReason::SAME_SITE_NONE_INSECURE;
    if (value.GetString() == "UserPreferences")
      return network::SetCookieBlockedReason::USER_PREFERENCES;
    if (value.GetString() == "SyntaxError")
      return network::SetCookieBlockedReason::SYNTAX_ERROR;
    if (value.GetString() == "SchemeNotSupported")
      return network::SetCookieBlockedReason::SCHEME_NOT_SUPPORTED;
    if (value.GetString() == "OverwriteSecure")
      return network::SetCookieBlockedReason::OVERWRITE_SECURE;
    if (value.GetString() == "InvalidDomain")
      return network::SetCookieBlockedReason::INVALID_DOMAIN;
    if (value.GetString() == "InvalidPrefix")
      return network::SetCookieBlockedReason::INVALID_PREFIX;
    if (value.GetString() == "UnknownError")
      return network::SetCookieBlockedReason::UNKNOWN_ERROR;
    errors->AddError("invalid enum value");
    return network::SetCookieBlockedReason::SECURE_ONLY;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetCookieBlockedReason& value) {
  switch (value) {
    case network::SetCookieBlockedReason::SECURE_ONLY:
      return std::make_unique<base::Value>("SecureOnly");
    case network::SetCookieBlockedReason::SAME_SITE_STRICT:
      return std::make_unique<base::Value>("SameSiteStrict");
    case network::SetCookieBlockedReason::SAME_SITE_LAX:
      return std::make_unique<base::Value>("SameSiteLax");
    case network::SetCookieBlockedReason::SAME_SITE_UNSPECIFIED_TREATED_AS_LAX:
      return std::make_unique<base::Value>("SameSiteUnspecifiedTreatedAsLax");
    case network::SetCookieBlockedReason::SAME_SITE_NONE_INSECURE:
      return std::make_unique<base::Value>("SameSiteNoneInsecure");
    case network::SetCookieBlockedReason::USER_PREFERENCES:
      return std::make_unique<base::Value>("UserPreferences");
    case network::SetCookieBlockedReason::SYNTAX_ERROR:
      return std::make_unique<base::Value>("SyntaxError");
    case network::SetCookieBlockedReason::SCHEME_NOT_SUPPORTED:
      return std::make_unique<base::Value>("SchemeNotSupported");
    case network::SetCookieBlockedReason::OVERWRITE_SECURE:
      return std::make_unique<base::Value>("OverwriteSecure");
    case network::SetCookieBlockedReason::INVALID_DOMAIN:
      return std::make_unique<base::Value>("InvalidDomain");
    case network::SetCookieBlockedReason::INVALID_PREFIX:
      return std::make_unique<base::Value>("InvalidPrefix");
    case network::SetCookieBlockedReason::UNKNOWN_ERROR:
      return std::make_unique<base::Value>("UnknownError");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<network::CookieBlockedReason> {
  static network::CookieBlockedReason Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::CookieBlockedReason::SECURE_ONLY;
    }
    if (value.GetString() == "SecureOnly")
      return network::CookieBlockedReason::SECURE_ONLY;
    if (value.GetString() == "NotOnPath")
      return network::CookieBlockedReason::NOT_ON_PATH;
    if (value.GetString() == "DomainMismatch")
      return network::CookieBlockedReason::DOMAIN_MISMATCH;
    if (value.GetString() == "SameSiteStrict")
      return network::CookieBlockedReason::SAME_SITE_STRICT;
    if (value.GetString() == "SameSiteLax")
      return network::CookieBlockedReason::SAME_SITE_LAX;
    if (value.GetString() == "SameSiteUnspecifiedTreatedAsLax")
      return network::CookieBlockedReason::SAME_SITE_UNSPECIFIED_TREATED_AS_LAX;
    if (value.GetString() == "SameSiteNoneInsecure")
      return network::CookieBlockedReason::SAME_SITE_NONE_INSECURE;
    if (value.GetString() == "UserPreferences")
      return network::CookieBlockedReason::USER_PREFERENCES;
    if (value.GetString() == "UnknownError")
      return network::CookieBlockedReason::UNKNOWN_ERROR;
    errors->AddError("invalid enum value");
    return network::CookieBlockedReason::SECURE_ONLY;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CookieBlockedReason& value) {
  switch (value) {
    case network::CookieBlockedReason::SECURE_ONLY:
      return std::make_unique<base::Value>("SecureOnly");
    case network::CookieBlockedReason::NOT_ON_PATH:
      return std::make_unique<base::Value>("NotOnPath");
    case network::CookieBlockedReason::DOMAIN_MISMATCH:
      return std::make_unique<base::Value>("DomainMismatch");
    case network::CookieBlockedReason::SAME_SITE_STRICT:
      return std::make_unique<base::Value>("SameSiteStrict");
    case network::CookieBlockedReason::SAME_SITE_LAX:
      return std::make_unique<base::Value>("SameSiteLax");
    case network::CookieBlockedReason::SAME_SITE_UNSPECIFIED_TREATED_AS_LAX:
      return std::make_unique<base::Value>("SameSiteUnspecifiedTreatedAsLax");
    case network::CookieBlockedReason::SAME_SITE_NONE_INSECURE:
      return std::make_unique<base::Value>("SameSiteNoneInsecure");
    case network::CookieBlockedReason::USER_PREFERENCES:
      return std::make_unique<base::Value>("UserPreferences");
    case network::CookieBlockedReason::UNKNOWN_ERROR:
      return std::make_unique<base::Value>("UnknownError");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<network::BlockedSetCookieWithReason> {
  static std::unique_ptr<network::BlockedSetCookieWithReason> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::BlockedSetCookieWithReason::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::BlockedSetCookieWithReason& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::BlockedCookieWithReason> {
  static std::unique_ptr<network::BlockedCookieWithReason> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::BlockedCookieWithReason::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::BlockedCookieWithReason& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::CookieParam> {
  static std::unique_ptr<network::CookieParam> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::CookieParam::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CookieParam& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::AuthChallenge> {
  static std::unique_ptr<network::AuthChallenge> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::AuthChallenge::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::AuthChallenge& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::AuthChallengeResponse> {
  static std::unique_ptr<network::AuthChallengeResponse> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::AuthChallengeResponse::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::AuthChallengeResponse& value) {
  return value.Serialize();
}

template <>
struct FromValue<network::InterceptionStage> {
  static network::InterceptionStage Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::InterceptionStage::REQUEST;
    }
    if (value.GetString() == "Request")
      return network::InterceptionStage::REQUEST;
    if (value.GetString() == "HeadersReceived")
      return network::InterceptionStage::HEADERS_RECEIVED;
    errors->AddError("invalid enum value");
    return network::InterceptionStage::REQUEST;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::InterceptionStage& value) {
  switch (value) {
    case network::InterceptionStage::REQUEST:
      return std::make_unique<base::Value>("Request");
    case network::InterceptionStage::HEADERS_RECEIVED:
      return std::make_unique<base::Value>("HeadersReceived");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<network::RequestPattern> {
  static std::unique_ptr<network::RequestPattern> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::RequestPattern::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::RequestPattern& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SignedExchangeSignature> {
  static std::unique_ptr<network::SignedExchangeSignature> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SignedExchangeSignature::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SignedExchangeSignature& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SignedExchangeHeader> {
  static std::unique_ptr<network::SignedExchangeHeader> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SignedExchangeHeader::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SignedExchangeHeader& value) {
  return value.Serialize();
}

template <>
struct FromValue<network::SignedExchangeErrorField> {
  static network::SignedExchangeErrorField Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::SignedExchangeErrorField::SIGNATURE_SIG;
    }
    if (value.GetString() == "signatureSig")
      return network::SignedExchangeErrorField::SIGNATURE_SIG;
    if (value.GetString() == "signatureIntegrity")
      return network::SignedExchangeErrorField::SIGNATURE_INTEGRITY;
    if (value.GetString() == "signatureCertUrl")
      return network::SignedExchangeErrorField::SIGNATURE_CERT_URL;
    if (value.GetString() == "signatureCertSha256")
      return network::SignedExchangeErrorField::SIGNATURE_CERT_SHA256;
    if (value.GetString() == "signatureValidityUrl")
      return network::SignedExchangeErrorField::SIGNATURE_VALIDITY_URL;
    if (value.GetString() == "signatureTimestamps")
      return network::SignedExchangeErrorField::SIGNATURE_TIMESTAMPS;
    errors->AddError("invalid enum value");
    return network::SignedExchangeErrorField::SIGNATURE_SIG;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SignedExchangeErrorField& value) {
  switch (value) {
    case network::SignedExchangeErrorField::SIGNATURE_SIG:
      return std::make_unique<base::Value>("signatureSig");
    case network::SignedExchangeErrorField::SIGNATURE_INTEGRITY:
      return std::make_unique<base::Value>("signatureIntegrity");
    case network::SignedExchangeErrorField::SIGNATURE_CERT_URL:
      return std::make_unique<base::Value>("signatureCertUrl");
    case network::SignedExchangeErrorField::SIGNATURE_CERT_SHA256:
      return std::make_unique<base::Value>("signatureCertSha256");
    case network::SignedExchangeErrorField::SIGNATURE_VALIDITY_URL:
      return std::make_unique<base::Value>("signatureValidityUrl");
    case network::SignedExchangeErrorField::SIGNATURE_TIMESTAMPS:
      return std::make_unique<base::Value>("signatureTimestamps");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<network::SignedExchangeError> {
  static std::unique_ptr<network::SignedExchangeError> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SignedExchangeError::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SignedExchangeError& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SignedExchangeInfo> {
  static std::unique_ptr<network::SignedExchangeInfo> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SignedExchangeInfo::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SignedExchangeInfo& value) {
  return value.Serialize();
}

template <>
struct FromValue<network::RequestReferrerPolicy> {
  static network::RequestReferrerPolicy Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::RequestReferrerPolicy::UNSAFE_URL;
    }
    if (value.GetString() == "unsafe-url")
      return network::RequestReferrerPolicy::UNSAFE_URL;
    if (value.GetString() == "no-referrer-when-downgrade")
      return network::RequestReferrerPolicy::NO_REFERRER_WHEN_DOWNGRADE;
    if (value.GetString() == "no-referrer")
      return network::RequestReferrerPolicy::NO_REFERRER;
    if (value.GetString() == "origin")
      return network::RequestReferrerPolicy::ORIGIN;
    if (value.GetString() == "origin-when-cross-origin")
      return network::RequestReferrerPolicy::ORIGIN_WHEN_CROSS_ORIGIN;
    if (value.GetString() == "same-origin")
      return network::RequestReferrerPolicy::SAME_ORIGIN;
    if (value.GetString() == "strict-origin")
      return network::RequestReferrerPolicy::STRICT_ORIGIN;
    if (value.GetString() == "strict-origin-when-cross-origin")
      return network::RequestReferrerPolicy::STRICT_ORIGIN_WHEN_CROSS_ORIGIN;
    errors->AddError("invalid enum value");
    return network::RequestReferrerPolicy::UNSAFE_URL;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::RequestReferrerPolicy& value) {
  switch (value) {
    case network::RequestReferrerPolicy::UNSAFE_URL:
      return std::make_unique<base::Value>("unsafe-url");
    case network::RequestReferrerPolicy::NO_REFERRER_WHEN_DOWNGRADE:
      return std::make_unique<base::Value>("no-referrer-when-downgrade");
    case network::RequestReferrerPolicy::NO_REFERRER:
      return std::make_unique<base::Value>("no-referrer");
    case network::RequestReferrerPolicy::ORIGIN:
      return std::make_unique<base::Value>("origin");
    case network::RequestReferrerPolicy::ORIGIN_WHEN_CROSS_ORIGIN:
      return std::make_unique<base::Value>("origin-when-cross-origin");
    case network::RequestReferrerPolicy::SAME_ORIGIN:
      return std::make_unique<base::Value>("same-origin");
    case network::RequestReferrerPolicy::STRICT_ORIGIN:
      return std::make_unique<base::Value>("strict-origin");
    case network::RequestReferrerPolicy::STRICT_ORIGIN_WHEN_CROSS_ORIGIN:
      return std::make_unique<base::Value>("strict-origin-when-cross-origin");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<network::InitiatorType> {
  static network::InitiatorType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::InitiatorType::PARSER;
    }
    if (value.GetString() == "parser")
      return network::InitiatorType::PARSER;
    if (value.GetString() == "script")
      return network::InitiatorType::SCRIPT;
    if (value.GetString() == "preload")
      return network::InitiatorType::PRELOAD;
    if (value.GetString() == "SignedExchange")
      return network::InitiatorType::SIGNED_EXCHANGE;
    if (value.GetString() == "other")
      return network::InitiatorType::OTHER;
    errors->AddError("invalid enum value");
    return network::InitiatorType::PARSER;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::InitiatorType& value) {
  switch (value) {
    case network::InitiatorType::PARSER:
      return std::make_unique<base::Value>("parser");
    case network::InitiatorType::SCRIPT:
      return std::make_unique<base::Value>("script");
    case network::InitiatorType::PRELOAD:
      return std::make_unique<base::Value>("preload");
    case network::InitiatorType::SIGNED_EXCHANGE:
      return std::make_unique<base::Value>("SignedExchange");
    case network::InitiatorType::OTHER:
      return std::make_unique<base::Value>("other");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<network::AuthChallengeSource> {
  static network::AuthChallengeSource Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::AuthChallengeSource::SERVER;
    }
    if (value.GetString() == "Server")
      return network::AuthChallengeSource::SERVER;
    if (value.GetString() == "Proxy")
      return network::AuthChallengeSource::PROXY;
    errors->AddError("invalid enum value");
    return network::AuthChallengeSource::SERVER;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::AuthChallengeSource& value) {
  switch (value) {
    case network::AuthChallengeSource::SERVER:
      return std::make_unique<base::Value>("Server");
    case network::AuthChallengeSource::PROXY:
      return std::make_unique<base::Value>("Proxy");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<network::AuthChallengeResponseResponse> {
  static network::AuthChallengeResponseResponse Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return network::AuthChallengeResponseResponse::DEFAULT;
    }
    if (value.GetString() == "Default")
      return network::AuthChallengeResponseResponse::DEFAULT;
    if (value.GetString() == "CancelAuth")
      return network::AuthChallengeResponseResponse::CANCEL_AUTH;
    if (value.GetString() == "ProvideCredentials")
      return network::AuthChallengeResponseResponse::PROVIDE_CREDENTIALS;
    errors->AddError("invalid enum value");
    return network::AuthChallengeResponseResponse::DEFAULT;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::AuthChallengeResponseResponse& value) {
  switch (value) {
    case network::AuthChallengeResponseResponse::DEFAULT:
      return std::make_unique<base::Value>("Default");
    case network::AuthChallengeResponseResponse::CANCEL_AUTH:
      return std::make_unique<base::Value>("CancelAuth");
    case network::AuthChallengeResponseResponse::PROVIDE_CREDENTIALS:
      return std::make_unique<base::Value>("ProvideCredentials");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<network::CanClearBrowserCacheParams> {
  static std::unique_ptr<network::CanClearBrowserCacheParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::CanClearBrowserCacheParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CanClearBrowserCacheParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::CanClearBrowserCacheResult> {
  static std::unique_ptr<network::CanClearBrowserCacheResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::CanClearBrowserCacheResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CanClearBrowserCacheResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::CanClearBrowserCookiesParams> {
  static std::unique_ptr<network::CanClearBrowserCookiesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::CanClearBrowserCookiesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CanClearBrowserCookiesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::CanClearBrowserCookiesResult> {
  static std::unique_ptr<network::CanClearBrowserCookiesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::CanClearBrowserCookiesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CanClearBrowserCookiesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::CanEmulateNetworkConditionsParams> {
  static std::unique_ptr<network::CanEmulateNetworkConditionsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::CanEmulateNetworkConditionsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CanEmulateNetworkConditionsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::CanEmulateNetworkConditionsResult> {
  static std::unique_ptr<network::CanEmulateNetworkConditionsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::CanEmulateNetworkConditionsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::CanEmulateNetworkConditionsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::ClearBrowserCacheParams> {
  static std::unique_ptr<network::ClearBrowserCacheParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ClearBrowserCacheParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ClearBrowserCacheParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::ClearBrowserCacheResult> {
  static std::unique_ptr<network::ClearBrowserCacheResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ClearBrowserCacheResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ClearBrowserCacheResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::ClearBrowserCookiesParams> {
  static std::unique_ptr<network::ClearBrowserCookiesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ClearBrowserCookiesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ClearBrowserCookiesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::ClearBrowserCookiesResult> {
  static std::unique_ptr<network::ClearBrowserCookiesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ClearBrowserCookiesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ClearBrowserCookiesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::ContinueInterceptedRequestParams> {
  static std::unique_ptr<network::ContinueInterceptedRequestParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ContinueInterceptedRequestParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ContinueInterceptedRequestParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::ContinueInterceptedRequestResult> {
  static std::unique_ptr<network::ContinueInterceptedRequestResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ContinueInterceptedRequestResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ContinueInterceptedRequestResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::DeleteCookiesParams> {
  static std::unique_ptr<network::DeleteCookiesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::DeleteCookiesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::DeleteCookiesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::DeleteCookiesResult> {
  static std::unique_ptr<network::DeleteCookiesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::DeleteCookiesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::DeleteCookiesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::DisableParams> {
  static std::unique_ptr<network::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::DisableResult> {
  static std::unique_ptr<network::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::EmulateNetworkConditionsParams> {
  static std::unique_ptr<network::EmulateNetworkConditionsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::EmulateNetworkConditionsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::EmulateNetworkConditionsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::EmulateNetworkConditionsResult> {
  static std::unique_ptr<network::EmulateNetworkConditionsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::EmulateNetworkConditionsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::EmulateNetworkConditionsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::EnableParams> {
  static std::unique_ptr<network::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::EnableResult> {
  static std::unique_ptr<network::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetAllCookiesParams> {
  static std::unique_ptr<network::GetAllCookiesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetAllCookiesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetAllCookiesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetAllCookiesResult> {
  static std::unique_ptr<network::GetAllCookiesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetAllCookiesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetAllCookiesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetCertificateParams> {
  static std::unique_ptr<network::GetCertificateParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetCertificateParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetCertificateParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetCertificateResult> {
  static std::unique_ptr<network::GetCertificateResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetCertificateResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetCertificateResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetCookiesParams> {
  static std::unique_ptr<network::GetCookiesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetCookiesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetCookiesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetCookiesResult> {
  static std::unique_ptr<network::GetCookiesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetCookiesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetCookiesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetResponseBodyParams> {
  static std::unique_ptr<network::GetResponseBodyParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetResponseBodyParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetResponseBodyParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetResponseBodyResult> {
  static std::unique_ptr<network::GetResponseBodyResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetResponseBodyResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetResponseBodyResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetRequestPostDataParams> {
  static std::unique_ptr<network::GetRequestPostDataParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetRequestPostDataParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetRequestPostDataParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetRequestPostDataResult> {
  static std::unique_ptr<network::GetRequestPostDataResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetRequestPostDataResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetRequestPostDataResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetResponseBodyForInterceptionParams> {
  static std::unique_ptr<network::GetResponseBodyForInterceptionParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetResponseBodyForInterceptionParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetResponseBodyForInterceptionParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::GetResponseBodyForInterceptionResult> {
  static std::unique_ptr<network::GetResponseBodyForInterceptionResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::GetResponseBodyForInterceptionResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::GetResponseBodyForInterceptionResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::TakeResponseBodyForInterceptionAsStreamParams> {
  static std::unique_ptr<network::TakeResponseBodyForInterceptionAsStreamParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::TakeResponseBodyForInterceptionAsStreamParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::TakeResponseBodyForInterceptionAsStreamParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::TakeResponseBodyForInterceptionAsStreamResult> {
  static std::unique_ptr<network::TakeResponseBodyForInterceptionAsStreamResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::TakeResponseBodyForInterceptionAsStreamResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::TakeResponseBodyForInterceptionAsStreamResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::ReplayXHRParams> {
  static std::unique_ptr<network::ReplayXHRParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ReplayXHRParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ReplayXHRParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::ReplayXHRResult> {
  static std::unique_ptr<network::ReplayXHRResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ReplayXHRResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ReplayXHRResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SearchInResponseBodyParams> {
  static std::unique_ptr<network::SearchInResponseBodyParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SearchInResponseBodyParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SearchInResponseBodyParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SearchInResponseBodyResult> {
  static std::unique_ptr<network::SearchInResponseBodyResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SearchInResponseBodyResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SearchInResponseBodyResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetBlockedURLsParams> {
  static std::unique_ptr<network::SetBlockedURLsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetBlockedURLsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetBlockedURLsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetBlockedURLsResult> {
  static std::unique_ptr<network::SetBlockedURLsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetBlockedURLsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetBlockedURLsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetBypassServiceWorkerParams> {
  static std::unique_ptr<network::SetBypassServiceWorkerParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetBypassServiceWorkerParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetBypassServiceWorkerParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetBypassServiceWorkerResult> {
  static std::unique_ptr<network::SetBypassServiceWorkerResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetBypassServiceWorkerResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetBypassServiceWorkerResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetCacheDisabledParams> {
  static std::unique_ptr<network::SetCacheDisabledParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetCacheDisabledParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetCacheDisabledParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetCacheDisabledResult> {
  static std::unique_ptr<network::SetCacheDisabledResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetCacheDisabledResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetCacheDisabledResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetCookieParams> {
  static std::unique_ptr<network::SetCookieParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetCookieParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetCookieParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetCookieResult> {
  static std::unique_ptr<network::SetCookieResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetCookieResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetCookieResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetCookiesParams> {
  static std::unique_ptr<network::SetCookiesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetCookiesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetCookiesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetCookiesResult> {
  static std::unique_ptr<network::SetCookiesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetCookiesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetCookiesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetDataSizeLimitsForTestParams> {
  static std::unique_ptr<network::SetDataSizeLimitsForTestParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetDataSizeLimitsForTestParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetDataSizeLimitsForTestParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetDataSizeLimitsForTestResult> {
  static std::unique_ptr<network::SetDataSizeLimitsForTestResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetDataSizeLimitsForTestResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetDataSizeLimitsForTestResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetExtraHTTPHeadersParams> {
  static std::unique_ptr<network::SetExtraHTTPHeadersParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetExtraHTTPHeadersParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetExtraHTTPHeadersParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetExtraHTTPHeadersResult> {
  static std::unique_ptr<network::SetExtraHTTPHeadersResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetExtraHTTPHeadersResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetExtraHTTPHeadersResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetRequestInterceptionParams> {
  static std::unique_ptr<network::SetRequestInterceptionParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetRequestInterceptionParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetRequestInterceptionParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetRequestInterceptionResult> {
  static std::unique_ptr<network::SetRequestInterceptionResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetRequestInterceptionResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetRequestInterceptionResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetUserAgentOverrideParams> {
  static std::unique_ptr<network::SetUserAgentOverrideParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetUserAgentOverrideParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetUserAgentOverrideParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SetUserAgentOverrideResult> {
  static std::unique_ptr<network::SetUserAgentOverrideResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SetUserAgentOverrideResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SetUserAgentOverrideResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::DataReceivedParams> {
  static std::unique_ptr<network::DataReceivedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::DataReceivedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::DataReceivedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::EventSourceMessageReceivedParams> {
  static std::unique_ptr<network::EventSourceMessageReceivedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::EventSourceMessageReceivedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::EventSourceMessageReceivedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::LoadingFailedParams> {
  static std::unique_ptr<network::LoadingFailedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::LoadingFailedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::LoadingFailedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::LoadingFinishedParams> {
  static std::unique_ptr<network::LoadingFinishedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::LoadingFinishedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::LoadingFinishedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::RequestInterceptedParams> {
  static std::unique_ptr<network::RequestInterceptedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::RequestInterceptedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::RequestInterceptedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::RequestServedFromCacheParams> {
  static std::unique_ptr<network::RequestServedFromCacheParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::RequestServedFromCacheParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::RequestServedFromCacheParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::RequestWillBeSentParams> {
  static std::unique_ptr<network::RequestWillBeSentParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::RequestWillBeSentParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::RequestWillBeSentParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::ResourceChangedPriorityParams> {
  static std::unique_ptr<network::ResourceChangedPriorityParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ResourceChangedPriorityParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ResourceChangedPriorityParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::SignedExchangeReceivedParams> {
  static std::unique_ptr<network::SignedExchangeReceivedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::SignedExchangeReceivedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::SignedExchangeReceivedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::ResponseReceivedParams> {
  static std::unique_ptr<network::ResponseReceivedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ResponseReceivedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ResponseReceivedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::WebSocketClosedParams> {
  static std::unique_ptr<network::WebSocketClosedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::WebSocketClosedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::WebSocketClosedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::WebSocketCreatedParams> {
  static std::unique_ptr<network::WebSocketCreatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::WebSocketCreatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::WebSocketCreatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::WebSocketFrameErrorParams> {
  static std::unique_ptr<network::WebSocketFrameErrorParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::WebSocketFrameErrorParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::WebSocketFrameErrorParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::WebSocketFrameReceivedParams> {
  static std::unique_ptr<network::WebSocketFrameReceivedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::WebSocketFrameReceivedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::WebSocketFrameReceivedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::WebSocketFrameSentParams> {
  static std::unique_ptr<network::WebSocketFrameSentParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::WebSocketFrameSentParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::WebSocketFrameSentParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::WebSocketHandshakeResponseReceivedParams> {
  static std::unique_ptr<network::WebSocketHandshakeResponseReceivedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::WebSocketHandshakeResponseReceivedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::WebSocketHandshakeResponseReceivedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::WebSocketWillSendHandshakeRequestParams> {
  static std::unique_ptr<network::WebSocketWillSendHandshakeRequestParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::WebSocketWillSendHandshakeRequestParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::WebSocketWillSendHandshakeRequestParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::RequestWillBeSentExtraInfoParams> {
  static std::unique_ptr<network::RequestWillBeSentExtraInfoParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::RequestWillBeSentExtraInfoParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::RequestWillBeSentExtraInfoParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<network::ResponseReceivedExtraInfoParams> {
  static std::unique_ptr<network::ResponseReceivedExtraInfoParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return network::ResponseReceivedExtraInfoParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const network::ResponseReceivedExtraInfoParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_NETWORK_H_
