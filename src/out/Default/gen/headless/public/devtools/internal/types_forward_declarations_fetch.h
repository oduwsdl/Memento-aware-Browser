// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_FETCH_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_FETCH_H_

#include "base/values.h"

namespace headless {

namespace fetch {
class RequestPattern;
class HeaderEntry;
class AuthChallenge;
class AuthChallengeResponse;
class DisableParams;
class DisableResult;
class EnableParams;
class EnableResult;
class FailRequestParams;
class FailRequestResult;
class FulfillRequestParams;
class FulfillRequestResult;
class ContinueRequestParams;
class ContinueRequestResult;
class ContinueWithAuthParams;
class ContinueWithAuthResult;
class GetResponseBodyParams;
class GetResponseBodyResult;
class TakeResponseBodyAsStreamParams;
class TakeResponseBodyAsStreamResult;
class RequestPausedParams;
class AuthRequiredParams;

enum class RequestStage {
  REQUEST,
  RESPONSE
};

enum class AuthChallengeSource {
  SERVER,
  PROXY
};

enum class AuthChallengeResponseResponse {
  DEFAULT,
  CANCEL_AUTH,
  PROVIDE_CREDENTIALS
};

}  // namespace fetch

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_FETCH_H_
