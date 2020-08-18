// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_FETCH_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_FETCH_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_fetch.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace fetch {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Issued when the domain is enabled and the request URL matches the
  // specified filter. The request is paused until the client responds
  // with one of continueRequest, failRequest or fulfillRequest.
  // The stage of the request can be determined by presence of responseErrorReason
  // and responseStatusCode -- the request is at the response stage if either
  // of these fields is present and in the request stage otherwise.
  virtual void OnRequestPaused(const RequestPausedParams& params) {}
  // Issued when the domain is enabled with handleAuthRequests set to true.
  // The request is paused until client responds with continueWithAuth.
  virtual void OnAuthRequired(const AuthRequiredParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Experimental: Issued when the domain is enabled and the request URL matches the
  // specified filter. The request is paused until the client responds
  // with one of continueRequest, failRequest or fulfillRequest.
  // The stage of the request can be determined by presence of responseErrorReason
  // and responseStatusCode -- the request is at the response stage if either
  // of these fields is present and in the request stage otherwise.
  virtual void OnRequestPaused(const RequestPausedParams& params) final {}
  // Experimental: Issued when the domain is enabled with handleAuthRequests set to true.
  // The request is paused until client responds with continueWithAuth.
  virtual void OnAuthRequired(const AuthRequiredParams& params) final {}
};

// A domain for letting clients substitute browser's network layer with client code.
class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleFailRequestResponse(base::OnceCallback<void(std::unique_ptr<FailRequestResult>)> callback, const base::Value& response);
  static void HandleFulfillRequestResponse(base::OnceCallback<void(std::unique_ptr<FulfillRequestResult>)> callback, const base::Value& response);
  static void HandleContinueRequestResponse(base::OnceCallback<void(std::unique_ptr<ContinueRequestResult>)> callback, const base::Value& response);
  static void HandleContinueWithAuthResponse(base::OnceCallback<void(std::unique_ptr<ContinueWithAuthResult>)> callback, const base::Value& response);
  static void HandleGetResponseBodyResponse(base::OnceCallback<void(std::unique_ptr<GetResponseBodyResult>)> callback, const base::Value& response);
  static void HandleTakeResponseBodyAsStreamResponse(base::OnceCallback<void(std::unique_ptr<TakeResponseBodyAsStreamResult>)> callback, const base::Value& response);

  void DispatchRequestPausedEvent(const base::Value& params);
  void DispatchAuthRequiredEvent(const base::Value& params);

  internal::MessageDispatcher* dispatcher_;  // Not owned.
  base::ObserverList<ExperimentalObserver>::Unchecked observers_;

 protected:
  void RegisterEventHandlersIfNeeded();

 private:
  bool event_handlers_registered_ = false;

  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();

  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(ExperimentalObserver* observer);
  void RemoveObserver(ExperimentalObserver* observer);

  // Disables the fetch domain.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Enables issuing of requestPaused events. A request will be paused until client
  // calls one of failRequest, fulfillRequest or continueRequest/continueWithAuth.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Causes the request to fail with specified reason.
  void FailRequest(std::unique_ptr<FailRequestParams> params, base::OnceCallback<void(std::unique_ptr<FailRequestResult>)> callback = base::OnceCallback<void(std::unique_ptr<FailRequestResult>)>());

  // Provides response to the request.
  void FulfillRequest(std::unique_ptr<FulfillRequestParams> params, base::OnceCallback<void(std::unique_ptr<FulfillRequestResult>)> callback = base::OnceCallback<void(std::unique_ptr<FulfillRequestResult>)>());

  // Continues the request, optionally modifying some of its parameters.
  void ContinueRequest(std::unique_ptr<ContinueRequestParams> params, base::OnceCallback<void(std::unique_ptr<ContinueRequestResult>)> callback = base::OnceCallback<void(std::unique_ptr<ContinueRequestResult>)>());

  // Continues a request supplying authChallengeResponse following authRequired event.
  void ContinueWithAuth(std::unique_ptr<ContinueWithAuthParams> params, base::OnceCallback<void(std::unique_ptr<ContinueWithAuthResult>)> callback = base::OnceCallback<void(std::unique_ptr<ContinueWithAuthResult>)>());

  // Causes the body of the response to be received from the server and
  // returned as a single string. May only be issued for a request that
  // is paused in the Response stage and is mutually exclusive with
  // takeResponseBodyForInterceptionAsStream. Calling other methods that
  // affect the request or disabling fetch domain before body is received
  // results in an undefined behavior.
  void GetResponseBody(std::unique_ptr<GetResponseBodyParams> params, base::OnceCallback<void(std::unique_ptr<GetResponseBodyResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetResponseBodyResult>)>());

  // Returns a handle to the stream representing the response body.
  // The request must be paused in the HeadersReceived stage.
  // Note that after this command the request can't be continued
  // as is -- client either needs to cancel it or to provide the
  // response body.
  // The stream only supports sequential read, IO.read will fail if the position
  // is specified.
  // This method is mutually exclusive with getResponseBody.
  // Calling other methods that affect the request or disabling fetch
  // domain before body is received results in an undefined behavior.
  void TakeResponseBodyAsStream(std::unique_ptr<TakeResponseBodyAsStreamParams> params, base::OnceCallback<void(std::unique_ptr<TakeResponseBodyAsStreamResult>)> callback = base::OnceCallback<void(std::unique_ptr<TakeResponseBodyAsStreamResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace fetch
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_FETCH_H_
