// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_FETCH_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_FETCH_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_fetch.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<fetch::RequestStage> {
  static fetch::RequestStage Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return fetch::RequestStage::REQUEST;
    }
    if (value.GetString() == "Request")
      return fetch::RequestStage::REQUEST;
    if (value.GetString() == "Response")
      return fetch::RequestStage::RESPONSE;
    errors->AddError("invalid enum value");
    return fetch::RequestStage::REQUEST;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::RequestStage& value) {
  switch (value) {
    case fetch::RequestStage::REQUEST:
      return std::make_unique<base::Value>("Request");
    case fetch::RequestStage::RESPONSE:
      return std::make_unique<base::Value>("Response");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<fetch::RequestPattern> {
  static std::unique_ptr<fetch::RequestPattern> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::RequestPattern::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::RequestPattern& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::HeaderEntry> {
  static std::unique_ptr<fetch::HeaderEntry> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::HeaderEntry::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::HeaderEntry& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::AuthChallenge> {
  static std::unique_ptr<fetch::AuthChallenge> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::AuthChallenge::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::AuthChallenge& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::AuthChallengeResponse> {
  static std::unique_ptr<fetch::AuthChallengeResponse> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::AuthChallengeResponse::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::AuthChallengeResponse& value) {
  return value.Serialize();
}

template <>
struct FromValue<fetch::AuthChallengeSource> {
  static fetch::AuthChallengeSource Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return fetch::AuthChallengeSource::SERVER;
    }
    if (value.GetString() == "Server")
      return fetch::AuthChallengeSource::SERVER;
    if (value.GetString() == "Proxy")
      return fetch::AuthChallengeSource::PROXY;
    errors->AddError("invalid enum value");
    return fetch::AuthChallengeSource::SERVER;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::AuthChallengeSource& value) {
  switch (value) {
    case fetch::AuthChallengeSource::SERVER:
      return std::make_unique<base::Value>("Server");
    case fetch::AuthChallengeSource::PROXY:
      return std::make_unique<base::Value>("Proxy");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<fetch::AuthChallengeResponseResponse> {
  static fetch::AuthChallengeResponseResponse Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return fetch::AuthChallengeResponseResponse::DEFAULT;
    }
    if (value.GetString() == "Default")
      return fetch::AuthChallengeResponseResponse::DEFAULT;
    if (value.GetString() == "CancelAuth")
      return fetch::AuthChallengeResponseResponse::CANCEL_AUTH;
    if (value.GetString() == "ProvideCredentials")
      return fetch::AuthChallengeResponseResponse::PROVIDE_CREDENTIALS;
    errors->AddError("invalid enum value");
    return fetch::AuthChallengeResponseResponse::DEFAULT;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::AuthChallengeResponseResponse& value) {
  switch (value) {
    case fetch::AuthChallengeResponseResponse::DEFAULT:
      return std::make_unique<base::Value>("Default");
    case fetch::AuthChallengeResponseResponse::CANCEL_AUTH:
      return std::make_unique<base::Value>("CancelAuth");
    case fetch::AuthChallengeResponseResponse::PROVIDE_CREDENTIALS:
      return std::make_unique<base::Value>("ProvideCredentials");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<fetch::DisableParams> {
  static std::unique_ptr<fetch::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::DisableResult> {
  static std::unique_ptr<fetch::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::EnableParams> {
  static std::unique_ptr<fetch::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::EnableResult> {
  static std::unique_ptr<fetch::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::FailRequestParams> {
  static std::unique_ptr<fetch::FailRequestParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::FailRequestParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::FailRequestParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::FailRequestResult> {
  static std::unique_ptr<fetch::FailRequestResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::FailRequestResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::FailRequestResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::FulfillRequestParams> {
  static std::unique_ptr<fetch::FulfillRequestParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::FulfillRequestParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::FulfillRequestParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::FulfillRequestResult> {
  static std::unique_ptr<fetch::FulfillRequestResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::FulfillRequestResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::FulfillRequestResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::ContinueRequestParams> {
  static std::unique_ptr<fetch::ContinueRequestParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::ContinueRequestParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::ContinueRequestParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::ContinueRequestResult> {
  static std::unique_ptr<fetch::ContinueRequestResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::ContinueRequestResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::ContinueRequestResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::ContinueWithAuthParams> {
  static std::unique_ptr<fetch::ContinueWithAuthParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::ContinueWithAuthParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::ContinueWithAuthParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::ContinueWithAuthResult> {
  static std::unique_ptr<fetch::ContinueWithAuthResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::ContinueWithAuthResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::ContinueWithAuthResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::GetResponseBodyParams> {
  static std::unique_ptr<fetch::GetResponseBodyParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::GetResponseBodyParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::GetResponseBodyParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::GetResponseBodyResult> {
  static std::unique_ptr<fetch::GetResponseBodyResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::GetResponseBodyResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::GetResponseBodyResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::TakeResponseBodyAsStreamParams> {
  static std::unique_ptr<fetch::TakeResponseBodyAsStreamParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::TakeResponseBodyAsStreamParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::TakeResponseBodyAsStreamParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::TakeResponseBodyAsStreamResult> {
  static std::unique_ptr<fetch::TakeResponseBodyAsStreamResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::TakeResponseBodyAsStreamResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::TakeResponseBodyAsStreamResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::RequestPausedParams> {
  static std::unique_ptr<fetch::RequestPausedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::RequestPausedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::RequestPausedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<fetch::AuthRequiredParams> {
  static std::unique_ptr<fetch::AuthRequiredParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return fetch::AuthRequiredParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const fetch::AuthRequiredParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_FETCH_H_
