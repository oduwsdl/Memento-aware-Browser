// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_NETWORK_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_NETWORK_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace network {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Fired when data chunk was received over the network.
  virtual void OnDataReceived(const DataReceivedParams& params) {}
  // Fired when EventSource message is received.
  virtual void OnEventSourceMessageReceived(const EventSourceMessageReceivedParams& params) {}
  // Fired when HTTP request has failed to load.
  virtual void OnLoadingFailed(const LoadingFailedParams& params) {}
  // Fired when HTTP request has finished loading.
  virtual void OnLoadingFinished(const LoadingFinishedParams& params) {}
  // Details of an intercepted HTTP request, which must be either allowed, blocked, modified or
  // mocked.
  // Deprecated, use Fetch.requestPaused instead.
  virtual void OnRequestIntercepted(const RequestInterceptedParams& params) {}
  // Fired if request ended up loading from cache.
  virtual void OnRequestServedFromCache(const RequestServedFromCacheParams& params) {}
  // Fired when page is about to send HTTP request.
  virtual void OnRequestWillBeSent(const RequestWillBeSentParams& params) {}
  // Fired when resource loading priority is changed
  virtual void OnResourceChangedPriority(const ResourceChangedPriorityParams& params) {}
  // Fired when a signed exchange was received over the network
  virtual void OnSignedExchangeReceived(const SignedExchangeReceivedParams& params) {}
  // Fired when HTTP response is available.
  virtual void OnResponseReceived(const ResponseReceivedParams& params) {}
  // Fired when WebSocket is closed.
  virtual void OnWebSocketClosed(const WebSocketClosedParams& params) {}
  // Fired upon WebSocket creation.
  virtual void OnWebSocketCreated(const WebSocketCreatedParams& params) {}
  // Fired when WebSocket message error occurs.
  virtual void OnWebSocketFrameError(const WebSocketFrameErrorParams& params) {}
  // Fired when WebSocket message is received.
  virtual void OnWebSocketFrameReceived(const WebSocketFrameReceivedParams& params) {}
  // Fired when WebSocket message is sent.
  virtual void OnWebSocketFrameSent(const WebSocketFrameSentParams& params) {}
  // Fired when WebSocket handshake response becomes available.
  virtual void OnWebSocketHandshakeResponseReceived(const WebSocketHandshakeResponseReceivedParams& params) {}
  // Fired when WebSocket is about to initiate handshake.
  virtual void OnWebSocketWillSendHandshakeRequest(const WebSocketWillSendHandshakeRequestParams& params) {}
  // Fired when additional information about a requestWillBeSent event is available from the
  // network stack. Not every requestWillBeSent event will have an additional
  // requestWillBeSentExtraInfo fired for it, and there is no guarantee whether requestWillBeSent
  // or requestWillBeSentExtraInfo will be fired first for the same request.
  virtual void OnRequestWillBeSentExtraInfo(const RequestWillBeSentExtraInfoParams& params) {}
  // Fired when additional information about a responseReceived event is available from the network
  // stack. Not every responseReceived event will have an additional responseReceivedExtraInfo for
  // it, and responseReceivedExtraInfo may be fired before or after responseReceived.
  virtual void OnResponseReceivedExtraInfo(const ResponseReceivedExtraInfoParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Fired when data chunk was received over the network.
  virtual void OnDataReceived(const DataReceivedParams& params) {}
  // Fired when EventSource message is received.
  virtual void OnEventSourceMessageReceived(const EventSourceMessageReceivedParams& params) {}
  // Fired when HTTP request has failed to load.
  virtual void OnLoadingFailed(const LoadingFailedParams& params) {}
  // Fired when HTTP request has finished loading.
  virtual void OnLoadingFinished(const LoadingFinishedParams& params) {}
  // Experimental: Details of an intercepted HTTP request, which must be either allowed, blocked, modified or
  // mocked.
  // Deprecated, use Fetch.requestPaused instead.
  virtual void OnRequestIntercepted(const RequestInterceptedParams& params) final {}
  // Fired if request ended up loading from cache.
  virtual void OnRequestServedFromCache(const RequestServedFromCacheParams& params) {}
  // Fired when page is about to send HTTP request.
  virtual void OnRequestWillBeSent(const RequestWillBeSentParams& params) {}
  // Experimental: Fired when resource loading priority is changed
  virtual void OnResourceChangedPriority(const ResourceChangedPriorityParams& params) final {}
  // Experimental: Fired when a signed exchange was received over the network
  virtual void OnSignedExchangeReceived(const SignedExchangeReceivedParams& params) final {}
  // Fired when HTTP response is available.
  virtual void OnResponseReceived(const ResponseReceivedParams& params) {}
  // Fired when WebSocket is closed.
  virtual void OnWebSocketClosed(const WebSocketClosedParams& params) {}
  // Fired upon WebSocket creation.
  virtual void OnWebSocketCreated(const WebSocketCreatedParams& params) {}
  // Fired when WebSocket message error occurs.
  virtual void OnWebSocketFrameError(const WebSocketFrameErrorParams& params) {}
  // Fired when WebSocket message is received.
  virtual void OnWebSocketFrameReceived(const WebSocketFrameReceivedParams& params) {}
  // Fired when WebSocket message is sent.
  virtual void OnWebSocketFrameSent(const WebSocketFrameSentParams& params) {}
  // Fired when WebSocket handshake response becomes available.
  virtual void OnWebSocketHandshakeResponseReceived(const WebSocketHandshakeResponseReceivedParams& params) {}
  // Fired when WebSocket is about to initiate handshake.
  virtual void OnWebSocketWillSendHandshakeRequest(const WebSocketWillSendHandshakeRequestParams& params) {}
  // Experimental: Fired when additional information about a requestWillBeSent event is available from the
  // network stack. Not every requestWillBeSent event will have an additional
  // requestWillBeSentExtraInfo fired for it, and there is no guarantee whether requestWillBeSent
  // or requestWillBeSentExtraInfo will be fired first for the same request.
  virtual void OnRequestWillBeSentExtraInfo(const RequestWillBeSentExtraInfoParams& params) final {}
  // Experimental: Fired when additional information about a responseReceived event is available from the network
  // stack. Not every responseReceived event will have an additional responseReceivedExtraInfo for
  // it, and responseReceivedExtraInfo may be fired before or after responseReceived.
  virtual void OnResponseReceivedExtraInfo(const ResponseReceivedExtraInfoParams& params) final {}
};

// Network domain allows tracking network activities of the page. It exposes information about http,
// file, data and other requests and responses, their headers, bodies, timing, etc.
class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

  // Tells whether clearing browser cache is supported.
  void CanClearBrowserCache(std::unique_ptr<CanClearBrowserCacheParams> params, base::OnceCallback<void(std::unique_ptr<CanClearBrowserCacheResult>)> callback = base::OnceCallback<void(std::unique_ptr<CanClearBrowserCacheResult>)>());
  void CanClearBrowserCache(base::OnceCallback<void(std::unique_ptr<CanClearBrowserCacheResult>)> callback = base::OnceCallback<void(std::unique_ptr<CanClearBrowserCacheResult>)>());

  // Tells whether clearing browser cookies is supported.
  void CanClearBrowserCookies(std::unique_ptr<CanClearBrowserCookiesParams> params, base::OnceCallback<void(std::unique_ptr<CanClearBrowserCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<CanClearBrowserCookiesResult>)>());
  void CanClearBrowserCookies(base::OnceCallback<void(std::unique_ptr<CanClearBrowserCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<CanClearBrowserCookiesResult>)>());

  // Tells whether emulation of network conditions is supported.
  void CanEmulateNetworkConditions(std::unique_ptr<CanEmulateNetworkConditionsParams> params, base::OnceCallback<void(std::unique_ptr<CanEmulateNetworkConditionsResult>)> callback = base::OnceCallback<void(std::unique_ptr<CanEmulateNetworkConditionsResult>)>());
  void CanEmulateNetworkConditions(base::OnceCallback<void(std::unique_ptr<CanEmulateNetworkConditionsResult>)> callback = base::OnceCallback<void(std::unique_ptr<CanEmulateNetworkConditionsResult>)>());

  // Clears browser cache.
  void ClearBrowserCache(std::unique_ptr<ClearBrowserCacheParams> params, base::OnceCallback<void(std::unique_ptr<ClearBrowserCacheResult>)> callback = base::OnceCallback<void(std::unique_ptr<ClearBrowserCacheResult>)>());
  void ClearBrowserCache(base::OnceClosure callback = base::OnceClosure());
  void ClearBrowserCache(std::unique_ptr<ClearBrowserCacheParams> params, base::OnceClosure callback);

  // Clears browser cookies.
  void ClearBrowserCookies(std::unique_ptr<ClearBrowserCookiesParams> params, base::OnceCallback<void(std::unique_ptr<ClearBrowserCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<ClearBrowserCookiesResult>)>());
  void ClearBrowserCookies(base::OnceClosure callback = base::OnceClosure());
  void ClearBrowserCookies(std::unique_ptr<ClearBrowserCookiesParams> params, base::OnceClosure callback);

  // Deletes browser cookies with matching name and url or domain/path pair.
  void DeleteCookies(std::unique_ptr<DeleteCookiesParams> params, base::OnceCallback<void(std::unique_ptr<DeleteCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<DeleteCookiesResult>)>());
  void DeleteCookies(const std::string& name, base::OnceClosure callback = base::OnceClosure());
  void DeleteCookies(std::unique_ptr<DeleteCookiesParams> params, base::OnceClosure callback);

  // Disables network tracking, prevents network events from being sent to the client.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());
  void Disable(base::OnceClosure callback = base::OnceClosure());
  void Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback);

  // Activates emulation of network conditions.
  void EmulateNetworkConditions(std::unique_ptr<EmulateNetworkConditionsParams> params, base::OnceCallback<void(std::unique_ptr<EmulateNetworkConditionsResult>)> callback = base::OnceCallback<void(std::unique_ptr<EmulateNetworkConditionsResult>)>());
  void EmulateNetworkConditions(bool offline, double latency, double download_throughput, double upload_throughput, base::OnceClosure callback = base::OnceClosure());
  void EmulateNetworkConditions(std::unique_ptr<EmulateNetworkConditionsParams> params, base::OnceClosure callback);

  // Enables network tracking, network events will now be delivered to the client.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());
  void Enable(base::OnceClosure callback = base::OnceClosure());
  void Enable(std::unique_ptr<EnableParams> params, base::OnceClosure callback);

  // Returns all browser cookies. Depending on the backend support, will return detailed cookie
  // information in the `cookies` field.
  void GetAllCookies(std::unique_ptr<GetAllCookiesParams> params, base::OnceCallback<void(std::unique_ptr<GetAllCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetAllCookiesResult>)>());
  void GetAllCookies(base::OnceCallback<void(std::unique_ptr<GetAllCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetAllCookiesResult>)>());

  // Returns all browser cookies for the current URL. Depending on the backend support, will return
  // detailed cookie information in the `cookies` field.
  void GetCookies(std::unique_ptr<GetCookiesParams> params, base::OnceCallback<void(std::unique_ptr<GetCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetCookiesResult>)>());
  void GetCookies(base::OnceCallback<void(std::unique_ptr<GetCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetCookiesResult>)>());

  // Returns content served for the given request.
  void GetResponseBody(std::unique_ptr<GetResponseBodyParams> params, base::OnceCallback<void(std::unique_ptr<GetResponseBodyResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetResponseBodyResult>)>());
  void GetResponseBody(const std::string& request_id, base::OnceCallback<void(std::unique_ptr<GetResponseBodyResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetResponseBodyResult>)>());

  // Returns post data sent with the request. Returns an error when no data was sent with the request.
  void GetRequestPostData(std::unique_ptr<GetRequestPostDataParams> params, base::OnceCallback<void(std::unique_ptr<GetRequestPostDataResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetRequestPostDataResult>)>());
  void GetRequestPostData(const std::string& request_id, base::OnceCallback<void(std::unique_ptr<GetRequestPostDataResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetRequestPostDataResult>)>());

  // Toggles ignoring cache for each request. If `true`, cache will not be used.
  void SetCacheDisabled(std::unique_ptr<SetCacheDisabledParams> params, base::OnceCallback<void(std::unique_ptr<SetCacheDisabledResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetCacheDisabledResult>)>());
  void SetCacheDisabled(bool cache_disabled, base::OnceClosure callback = base::OnceClosure());
  void SetCacheDisabled(std::unique_ptr<SetCacheDisabledParams> params, base::OnceClosure callback);

  // Sets a cookie with the given cookie data; may overwrite equivalent cookies if they exist.
  void SetCookie(std::unique_ptr<SetCookieParams> params, base::OnceCallback<void(std::unique_ptr<SetCookieResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetCookieResult>)>());
  void SetCookie(const std::string& name, const std::string& value, base::OnceCallback<void(std::unique_ptr<SetCookieResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetCookieResult>)>());

  // Sets given cookies.
  void SetCookies(std::unique_ptr<SetCookiesParams> params, base::OnceCallback<void(std::unique_ptr<SetCookiesResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetCookiesResult>)>());
  void SetCookies(std::vector<std::unique_ptr<::headless::network::CookieParam>> cookies, base::OnceClosure callback = base::OnceClosure());
  void SetCookies(std::unique_ptr<SetCookiesParams> params, base::OnceClosure callback);

  // Specifies whether to always send extra HTTP headers with the requests from this page.
  void SetExtraHTTPHeaders(std::unique_ptr<SetExtraHTTPHeadersParams> params, base::OnceCallback<void(std::unique_ptr<SetExtraHTTPHeadersResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetExtraHTTPHeadersResult>)>());
  void SetExtraHTTPHeaders(std::unique_ptr<base::DictionaryValue> headers, base::OnceClosure callback = base::OnceClosure());
  void SetExtraHTTPHeaders(std::unique_ptr<SetExtraHTTPHeadersParams> params, base::OnceClosure callback);

  // Allows overriding user agent with the given string.
  void SetUserAgentOverride(std::unique_ptr<SetUserAgentOverrideParams> params, base::OnceCallback<void(std::unique_ptr<SetUserAgentOverrideResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetUserAgentOverrideResult>)>());
  void SetUserAgentOverride(const std::string& user_agent, base::OnceClosure callback = base::OnceClosure());
  void SetUserAgentOverride(std::unique_ptr<SetUserAgentOverrideParams> params, base::OnceClosure callback);

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleCanClearBrowserCacheResponse(base::OnceCallback<void(std::unique_ptr<CanClearBrowserCacheResult>)> callback, const base::Value& response);
  static void HandleCanClearBrowserCookiesResponse(base::OnceCallback<void(std::unique_ptr<CanClearBrowserCookiesResult>)> callback, const base::Value& response);
  static void HandleCanEmulateNetworkConditionsResponse(base::OnceCallback<void(std::unique_ptr<CanEmulateNetworkConditionsResult>)> callback, const base::Value& response);
  static void HandleClearBrowserCacheResponse(base::OnceCallback<void(std::unique_ptr<ClearBrowserCacheResult>)> callback, const base::Value& response);
  static void HandleClearBrowserCookiesResponse(base::OnceCallback<void(std::unique_ptr<ClearBrowserCookiesResult>)> callback, const base::Value& response);
  static void HandleContinueInterceptedRequestResponse(base::OnceCallback<void(std::unique_ptr<ContinueInterceptedRequestResult>)> callback, const base::Value& response);
  static void HandleDeleteCookiesResponse(base::OnceCallback<void(std::unique_ptr<DeleteCookiesResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEmulateNetworkConditionsResponse(base::OnceCallback<void(std::unique_ptr<EmulateNetworkConditionsResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleGetAllCookiesResponse(base::OnceCallback<void(std::unique_ptr<GetAllCookiesResult>)> callback, const base::Value& response);
  static void HandleGetCertificateResponse(base::OnceCallback<void(std::unique_ptr<GetCertificateResult>)> callback, const base::Value& response);
  static void HandleGetCookiesResponse(base::OnceCallback<void(std::unique_ptr<GetCookiesResult>)> callback, const base::Value& response);
  static void HandleGetResponseBodyResponse(base::OnceCallback<void(std::unique_ptr<GetResponseBodyResult>)> callback, const base::Value& response);
  static void HandleGetRequestPostDataResponse(base::OnceCallback<void(std::unique_ptr<GetRequestPostDataResult>)> callback, const base::Value& response);
  static void HandleGetResponseBodyForInterceptionResponse(base::OnceCallback<void(std::unique_ptr<GetResponseBodyForInterceptionResult>)> callback, const base::Value& response);
  static void HandleTakeResponseBodyForInterceptionAsStreamResponse(base::OnceCallback<void(std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult>)> callback, const base::Value& response);
  static void HandleReplayXHRResponse(base::OnceCallback<void(std::unique_ptr<ReplayXHRResult>)> callback, const base::Value& response);
  static void HandleSearchInResponseBodyResponse(base::OnceCallback<void(std::unique_ptr<SearchInResponseBodyResult>)> callback, const base::Value& response);
  static void HandleSetBlockedURLsResponse(base::OnceCallback<void(std::unique_ptr<SetBlockedURLsResult>)> callback, const base::Value& response);
  static void HandleSetBypassServiceWorkerResponse(base::OnceCallback<void(std::unique_ptr<SetBypassServiceWorkerResult>)> callback, const base::Value& response);
  static void HandleSetCacheDisabledResponse(base::OnceCallback<void(std::unique_ptr<SetCacheDisabledResult>)> callback, const base::Value& response);
  static void HandleSetCookieResponse(base::OnceCallback<void(std::unique_ptr<SetCookieResult>)> callback, const base::Value& response);
  static void HandleSetCookiesResponse(base::OnceCallback<void(std::unique_ptr<SetCookiesResult>)> callback, const base::Value& response);
  static void HandleSetDataSizeLimitsForTestResponse(base::OnceCallback<void(std::unique_ptr<SetDataSizeLimitsForTestResult>)> callback, const base::Value& response);
  static void HandleSetExtraHTTPHeadersResponse(base::OnceCallback<void(std::unique_ptr<SetExtraHTTPHeadersResult>)> callback, const base::Value& response);
  static void HandleSetRequestInterceptionResponse(base::OnceCallback<void(std::unique_ptr<SetRequestInterceptionResult>)> callback, const base::Value& response);
  static void HandleSetUserAgentOverrideResponse(base::OnceCallback<void(std::unique_ptr<SetUserAgentOverrideResult>)> callback, const base::Value& response);

  void DispatchDataReceivedEvent(const base::Value& params);
  void DispatchEventSourceMessageReceivedEvent(const base::Value& params);
  void DispatchLoadingFailedEvent(const base::Value& params);
  void DispatchLoadingFinishedEvent(const base::Value& params);
  void DispatchRequestInterceptedEvent(const base::Value& params);
  void DispatchRequestServedFromCacheEvent(const base::Value& params);
  void DispatchRequestWillBeSentEvent(const base::Value& params);
  void DispatchResourceChangedPriorityEvent(const base::Value& params);
  void DispatchSignedExchangeReceivedEvent(const base::Value& params);
  void DispatchResponseReceivedEvent(const base::Value& params);
  void DispatchWebSocketClosedEvent(const base::Value& params);
  void DispatchWebSocketCreatedEvent(const base::Value& params);
  void DispatchWebSocketFrameErrorEvent(const base::Value& params);
  void DispatchWebSocketFrameReceivedEvent(const base::Value& params);
  void DispatchWebSocketFrameSentEvent(const base::Value& params);
  void DispatchWebSocketHandshakeResponseReceivedEvent(const base::Value& params);
  void DispatchWebSocketWillSendHandshakeRequestEvent(const base::Value& params);
  void DispatchRequestWillBeSentExtraInfoEvent(const base::Value& params);
  void DispatchResponseReceivedExtraInfoEvent(const base::Value& params);

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

  // Response to Network.requestIntercepted which either modifies the request to continue with any
  // modifications, or blocks it, or completes it with the provided response bytes. If a network
  // fetch occurs as a result which encounters a redirect an additional Network.requestIntercepted
  // event will be sent with the same InterceptionId.
  // Deprecated, use Fetch.continueRequest, Fetch.fulfillRequest and Fetch.failRequest instead.
  void ContinueInterceptedRequest(std::unique_ptr<ContinueInterceptedRequestParams> params, base::OnceCallback<void(std::unique_ptr<ContinueInterceptedRequestResult>)> callback = base::OnceCallback<void(std::unique_ptr<ContinueInterceptedRequestResult>)>());

  // Returns the DER-encoded certificate.
  void GetCertificate(std::unique_ptr<GetCertificateParams> params, base::OnceCallback<void(std::unique_ptr<GetCertificateResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetCertificateResult>)>());

  // Returns content served for the given currently intercepted request.
  void GetResponseBodyForInterception(std::unique_ptr<GetResponseBodyForInterceptionParams> params, base::OnceCallback<void(std::unique_ptr<GetResponseBodyForInterceptionResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetResponseBodyForInterceptionResult>)>());

  // Returns a handle to the stream representing the response body. Note that after this command,
  // the intercepted request can't be continued as is -- you either need to cancel it or to provide
  // the response body. The stream only supports sequential read, IO.read will fail if the position
  // is specified.
  void TakeResponseBodyForInterceptionAsStream(std::unique_ptr<TakeResponseBodyForInterceptionAsStreamParams> params, base::OnceCallback<void(std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult>)> callback = base::OnceCallback<void(std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult>)>());

  // This method sends a new XMLHttpRequest which is identical to the original one. The following
  // parameters should be identical: method, url, async, request body, extra headers, withCredentials
  // attribute, user, password.
  void ReplayXHR(std::unique_ptr<ReplayXHRParams> params, base::OnceCallback<void(std::unique_ptr<ReplayXHRResult>)> callback = base::OnceCallback<void(std::unique_ptr<ReplayXHRResult>)>());

  // Searches for given string in response content.
  void SearchInResponseBody(std::unique_ptr<SearchInResponseBodyParams> params, base::OnceCallback<void(std::unique_ptr<SearchInResponseBodyResult>)> callback = base::OnceCallback<void(std::unique_ptr<SearchInResponseBodyResult>)>());

  // Blocks URLs from loading.
  void SetBlockedURLs(std::unique_ptr<SetBlockedURLsParams> params, base::OnceCallback<void(std::unique_ptr<SetBlockedURLsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetBlockedURLsResult>)>());

  // Toggles ignoring of service worker for each request.
  void SetBypassServiceWorker(std::unique_ptr<SetBypassServiceWorkerParams> params, base::OnceCallback<void(std::unique_ptr<SetBypassServiceWorkerResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetBypassServiceWorkerResult>)>());

  // For testing.
  void SetDataSizeLimitsForTest(std::unique_ptr<SetDataSizeLimitsForTestParams> params, base::OnceCallback<void(std::unique_ptr<SetDataSizeLimitsForTestResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetDataSizeLimitsForTestResult>)>());

  // Sets the requests to intercept that match the provided patterns and optionally resource types.
  // Deprecated, please use Fetch.enable instead.
  void SetRequestInterception(std::unique_ptr<SetRequestInterceptionParams> params, base::OnceCallback<void(std::unique_ptr<SetRequestInterceptionResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetRequestInterceptionResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace network
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_NETWORK_H_
