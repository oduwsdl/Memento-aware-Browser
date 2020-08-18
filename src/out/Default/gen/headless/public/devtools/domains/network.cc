// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/network.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace network {

ExperimentalDomain* Domain::GetExperimental() {
  return static_cast<ExperimentalDomain*>(this);
}

void Domain::AddObserver(Observer* observer) {
  RegisterEventHandlersIfNeeded();
  observers_.AddObserver(observer);
}

void Domain::RemoveObserver(Observer* observer) {
  observers_.RemoveObserver(observer);
}

void Domain::RegisterEventHandlersIfNeeded() {
  if (event_handlers_registered_)
    return;
  event_handlers_registered_ = true;
  dispatcher_->RegisterEventHandler(
      "Network.dataReceived",
      base::BindRepeating(&Domain::DispatchDataReceivedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.eventSourceMessageReceived",
      base::BindRepeating(&Domain::DispatchEventSourceMessageReceivedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.loadingFailed",
      base::BindRepeating(&Domain::DispatchLoadingFailedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.loadingFinished",
      base::BindRepeating(&Domain::DispatchLoadingFinishedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.requestIntercepted",
      base::BindRepeating(&Domain::DispatchRequestInterceptedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.requestServedFromCache",
      base::BindRepeating(&Domain::DispatchRequestServedFromCacheEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.requestWillBeSent",
      base::BindRepeating(&Domain::DispatchRequestWillBeSentEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.resourceChangedPriority",
      base::BindRepeating(&Domain::DispatchResourceChangedPriorityEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.signedExchangeReceived",
      base::BindRepeating(&Domain::DispatchSignedExchangeReceivedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.responseReceived",
      base::BindRepeating(&Domain::DispatchResponseReceivedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.webSocketClosed",
      base::BindRepeating(&Domain::DispatchWebSocketClosedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.webSocketCreated",
      base::BindRepeating(&Domain::DispatchWebSocketCreatedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.webSocketFrameError",
      base::BindRepeating(&Domain::DispatchWebSocketFrameErrorEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.webSocketFrameReceived",
      base::BindRepeating(&Domain::DispatchWebSocketFrameReceivedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.webSocketFrameSent",
      base::BindRepeating(&Domain::DispatchWebSocketFrameSentEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.webSocketHandshakeResponseReceived",
      base::BindRepeating(&Domain::DispatchWebSocketHandshakeResponseReceivedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.webSocketWillSendHandshakeRequest",
      base::BindRepeating(&Domain::DispatchWebSocketWillSendHandshakeRequestEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.requestWillBeSentExtraInfo",
      base::BindRepeating(&Domain::DispatchRequestWillBeSentExtraInfoEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Network.responseReceivedExtraInfo",
      base::BindRepeating(&Domain::DispatchResponseReceivedExtraInfoEvent,
                          base::Unretained(this)));
}

void Domain::CanClearBrowserCache(std::unique_ptr<CanClearBrowserCacheParams> params, base::OnceCallback<void(std::unique_ptr<CanClearBrowserCacheResult>)> callback) {
  dispatcher_->SendMessage("Network.canClearBrowserCache", params->Serialize(), base::BindOnce(&Domain::HandleCanClearBrowserCacheResponse, std::move(callback)));
}

void Domain::CanClearBrowserCache(base::OnceCallback<void(std::unique_ptr<CanClearBrowserCacheResult>)> callback) {
  std::unique_ptr<CanClearBrowserCacheParams> params = CanClearBrowserCacheParams::Builder()
      .Build();
dispatcher_->SendMessage("Network.canClearBrowserCache", params->Serialize(), base::BindOnce(&Domain::HandleCanClearBrowserCacheResponse, std::move(callback)));
}
void Domain::CanClearBrowserCookies(std::unique_ptr<CanClearBrowserCookiesParams> params, base::OnceCallback<void(std::unique_ptr<CanClearBrowserCookiesResult>)> callback) {
  dispatcher_->SendMessage("Network.canClearBrowserCookies", params->Serialize(), base::BindOnce(&Domain::HandleCanClearBrowserCookiesResponse, std::move(callback)));
}

void Domain::CanClearBrowserCookies(base::OnceCallback<void(std::unique_ptr<CanClearBrowserCookiesResult>)> callback) {
  std::unique_ptr<CanClearBrowserCookiesParams> params = CanClearBrowserCookiesParams::Builder()
      .Build();
dispatcher_->SendMessage("Network.canClearBrowserCookies", params->Serialize(), base::BindOnce(&Domain::HandleCanClearBrowserCookiesResponse, std::move(callback)));
}
void Domain::CanEmulateNetworkConditions(std::unique_ptr<CanEmulateNetworkConditionsParams> params, base::OnceCallback<void(std::unique_ptr<CanEmulateNetworkConditionsResult>)> callback) {
  dispatcher_->SendMessage("Network.canEmulateNetworkConditions", params->Serialize(), base::BindOnce(&Domain::HandleCanEmulateNetworkConditionsResponse, std::move(callback)));
}

void Domain::CanEmulateNetworkConditions(base::OnceCallback<void(std::unique_ptr<CanEmulateNetworkConditionsResult>)> callback) {
  std::unique_ptr<CanEmulateNetworkConditionsParams> params = CanEmulateNetworkConditionsParams::Builder()
      .Build();
dispatcher_->SendMessage("Network.canEmulateNetworkConditions", params->Serialize(), base::BindOnce(&Domain::HandleCanEmulateNetworkConditionsResponse, std::move(callback)));
}
void Domain::ClearBrowserCache(std::unique_ptr<ClearBrowserCacheParams> params, base::OnceCallback<void(std::unique_ptr<ClearBrowserCacheResult>)> callback) {
  dispatcher_->SendMessage("Network.clearBrowserCache", params->Serialize(), base::BindOnce(&Domain::HandleClearBrowserCacheResponse, std::move(callback)));
}

void Domain::ClearBrowserCache(base::OnceClosure callback) {
  std::unique_ptr<ClearBrowserCacheParams> params = ClearBrowserCacheParams::Builder()
      .Build();
  dispatcher_->SendMessage("Network.clearBrowserCache", params->Serialize(), std::move(callback));
}
void Domain::ClearBrowserCache(std::unique_ptr<ClearBrowserCacheParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Network.clearBrowserCache", params->Serialize(), std::move(callback));
}
void Domain::ClearBrowserCookies(std::unique_ptr<ClearBrowserCookiesParams> params, base::OnceCallback<void(std::unique_ptr<ClearBrowserCookiesResult>)> callback) {
  dispatcher_->SendMessage("Network.clearBrowserCookies", params->Serialize(), base::BindOnce(&Domain::HandleClearBrowserCookiesResponse, std::move(callback)));
}

void Domain::ClearBrowserCookies(base::OnceClosure callback) {
  std::unique_ptr<ClearBrowserCookiesParams> params = ClearBrowserCookiesParams::Builder()
      .Build();
  dispatcher_->SendMessage("Network.clearBrowserCookies", params->Serialize(), std::move(callback));
}
void Domain::ClearBrowserCookies(std::unique_ptr<ClearBrowserCookiesParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Network.clearBrowserCookies", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::ContinueInterceptedRequest(std::unique_ptr<ContinueInterceptedRequestParams> params, base::OnceCallback<void(std::unique_ptr<ContinueInterceptedRequestResult>)> callback) {
  dispatcher_->SendMessage("Network.continueInterceptedRequest", params->Serialize(), base::BindOnce(&Domain::HandleContinueInterceptedRequestResponse, std::move(callback)));
}
void Domain::DeleteCookies(std::unique_ptr<DeleteCookiesParams> params, base::OnceCallback<void(std::unique_ptr<DeleteCookiesResult>)> callback) {
  dispatcher_->SendMessage("Network.deleteCookies", params->Serialize(), base::BindOnce(&Domain::HandleDeleteCookiesResponse, std::move(callback)));
}

void Domain::DeleteCookies(const std::string& name, base::OnceClosure callback) {
  std::unique_ptr<DeleteCookiesParams> params = DeleteCookiesParams::Builder()
      .SetName(std::move(name))
      .Build();
  dispatcher_->SendMessage("Network.deleteCookies", params->Serialize(), std::move(callback));
}
void Domain::DeleteCookies(std::unique_ptr<DeleteCookiesParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Network.deleteCookies", params->Serialize(), std::move(callback));
}
void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("Network.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}

void Domain::Disable(base::OnceClosure callback) {
  std::unique_ptr<DisableParams> params = DisableParams::Builder()
      .Build();
  dispatcher_->SendMessage("Network.disable", params->Serialize(), std::move(callback));
}
void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Network.disable", params->Serialize(), std::move(callback));
}
void Domain::EmulateNetworkConditions(std::unique_ptr<EmulateNetworkConditionsParams> params, base::OnceCallback<void(std::unique_ptr<EmulateNetworkConditionsResult>)> callback) {
  dispatcher_->SendMessage("Network.emulateNetworkConditions", params->Serialize(), base::BindOnce(&Domain::HandleEmulateNetworkConditionsResponse, std::move(callback)));
}

void Domain::EmulateNetworkConditions(bool offline, double latency, double download_throughput, double upload_throughput, base::OnceClosure callback) {
  std::unique_ptr<EmulateNetworkConditionsParams> params = EmulateNetworkConditionsParams::Builder()
      .SetOffline(std::move(offline))
      .SetLatency(std::move(latency))
      .SetDownloadThroughput(std::move(download_throughput))
      .SetUploadThroughput(std::move(upload_throughput))
      .Build();
  dispatcher_->SendMessage("Network.emulateNetworkConditions", params->Serialize(), std::move(callback));
}
void Domain::EmulateNetworkConditions(std::unique_ptr<EmulateNetworkConditionsParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Network.emulateNetworkConditions", params->Serialize(), std::move(callback));
}
void Domain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("Network.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}

void Domain::Enable(base::OnceClosure callback) {
  std::unique_ptr<EnableParams> params = EnableParams::Builder()
      .Build();
  dispatcher_->SendMessage("Network.enable", params->Serialize(), std::move(callback));
}
void Domain::Enable(std::unique_ptr<EnableParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Network.enable", params->Serialize(), std::move(callback));
}
void Domain::GetAllCookies(std::unique_ptr<GetAllCookiesParams> params, base::OnceCallback<void(std::unique_ptr<GetAllCookiesResult>)> callback) {
  dispatcher_->SendMessage("Network.getAllCookies", params->Serialize(), base::BindOnce(&Domain::HandleGetAllCookiesResponse, std::move(callback)));
}

void Domain::GetAllCookies(base::OnceCallback<void(std::unique_ptr<GetAllCookiesResult>)> callback) {
  std::unique_ptr<GetAllCookiesParams> params = GetAllCookiesParams::Builder()
      .Build();
dispatcher_->SendMessage("Network.getAllCookies", params->Serialize(), base::BindOnce(&Domain::HandleGetAllCookiesResponse, std::move(callback)));
}
void ExperimentalDomain::GetCertificate(std::unique_ptr<GetCertificateParams> params, base::OnceCallback<void(std::unique_ptr<GetCertificateResult>)> callback) {
  dispatcher_->SendMessage("Network.getCertificate", params->Serialize(), base::BindOnce(&Domain::HandleGetCertificateResponse, std::move(callback)));
}
void Domain::GetCookies(std::unique_ptr<GetCookiesParams> params, base::OnceCallback<void(std::unique_ptr<GetCookiesResult>)> callback) {
  dispatcher_->SendMessage("Network.getCookies", params->Serialize(), base::BindOnce(&Domain::HandleGetCookiesResponse, std::move(callback)));
}

void Domain::GetCookies(base::OnceCallback<void(std::unique_ptr<GetCookiesResult>)> callback) {
  std::unique_ptr<GetCookiesParams> params = GetCookiesParams::Builder()
      .Build();
dispatcher_->SendMessage("Network.getCookies", params->Serialize(), base::BindOnce(&Domain::HandleGetCookiesResponse, std::move(callback)));
}
void Domain::GetResponseBody(std::unique_ptr<GetResponseBodyParams> params, base::OnceCallback<void(std::unique_ptr<GetResponseBodyResult>)> callback) {
  dispatcher_->SendMessage("Network.getResponseBody", params->Serialize(), base::BindOnce(&Domain::HandleGetResponseBodyResponse, std::move(callback)));
}

void Domain::GetResponseBody(const std::string& request_id, base::OnceCallback<void(std::unique_ptr<GetResponseBodyResult>)> callback) {
  std::unique_ptr<GetResponseBodyParams> params = GetResponseBodyParams::Builder()
      .SetRequestId(std::move(request_id))
      .Build();
dispatcher_->SendMessage("Network.getResponseBody", params->Serialize(), base::BindOnce(&Domain::HandleGetResponseBodyResponse, std::move(callback)));
}
void Domain::GetRequestPostData(std::unique_ptr<GetRequestPostDataParams> params, base::OnceCallback<void(std::unique_ptr<GetRequestPostDataResult>)> callback) {
  dispatcher_->SendMessage("Network.getRequestPostData", params->Serialize(), base::BindOnce(&Domain::HandleGetRequestPostDataResponse, std::move(callback)));
}

void Domain::GetRequestPostData(const std::string& request_id, base::OnceCallback<void(std::unique_ptr<GetRequestPostDataResult>)> callback) {
  std::unique_ptr<GetRequestPostDataParams> params = GetRequestPostDataParams::Builder()
      .SetRequestId(std::move(request_id))
      .Build();
dispatcher_->SendMessage("Network.getRequestPostData", params->Serialize(), base::BindOnce(&Domain::HandleGetRequestPostDataResponse, std::move(callback)));
}
void ExperimentalDomain::GetResponseBodyForInterception(std::unique_ptr<GetResponseBodyForInterceptionParams> params, base::OnceCallback<void(std::unique_ptr<GetResponseBodyForInterceptionResult>)> callback) {
  dispatcher_->SendMessage("Network.getResponseBodyForInterception", params->Serialize(), base::BindOnce(&Domain::HandleGetResponseBodyForInterceptionResponse, std::move(callback)));
}
void ExperimentalDomain::TakeResponseBodyForInterceptionAsStream(std::unique_ptr<TakeResponseBodyForInterceptionAsStreamParams> params, base::OnceCallback<void(std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult>)> callback) {
  dispatcher_->SendMessage("Network.takeResponseBodyForInterceptionAsStream", params->Serialize(), base::BindOnce(&Domain::HandleTakeResponseBodyForInterceptionAsStreamResponse, std::move(callback)));
}
void ExperimentalDomain::ReplayXHR(std::unique_ptr<ReplayXHRParams> params, base::OnceCallback<void(std::unique_ptr<ReplayXHRResult>)> callback) {
  dispatcher_->SendMessage("Network.replayXHR", params->Serialize(), base::BindOnce(&Domain::HandleReplayXHRResponse, std::move(callback)));
}
void ExperimentalDomain::SearchInResponseBody(std::unique_ptr<SearchInResponseBodyParams> params, base::OnceCallback<void(std::unique_ptr<SearchInResponseBodyResult>)> callback) {
  dispatcher_->SendMessage("Network.searchInResponseBody", params->Serialize(), base::BindOnce(&Domain::HandleSearchInResponseBodyResponse, std::move(callback)));
}
void ExperimentalDomain::SetBlockedURLs(std::unique_ptr<SetBlockedURLsParams> params, base::OnceCallback<void(std::unique_ptr<SetBlockedURLsResult>)> callback) {
  dispatcher_->SendMessage("Network.setBlockedURLs", params->Serialize(), base::BindOnce(&Domain::HandleSetBlockedURLsResponse, std::move(callback)));
}
void ExperimentalDomain::SetBypassServiceWorker(std::unique_ptr<SetBypassServiceWorkerParams> params, base::OnceCallback<void(std::unique_ptr<SetBypassServiceWorkerResult>)> callback) {
  dispatcher_->SendMessage("Network.setBypassServiceWorker", params->Serialize(), base::BindOnce(&Domain::HandleSetBypassServiceWorkerResponse, std::move(callback)));
}
void Domain::SetCacheDisabled(std::unique_ptr<SetCacheDisabledParams> params, base::OnceCallback<void(std::unique_ptr<SetCacheDisabledResult>)> callback) {
  dispatcher_->SendMessage("Network.setCacheDisabled", params->Serialize(), base::BindOnce(&Domain::HandleSetCacheDisabledResponse, std::move(callback)));
}

void Domain::SetCacheDisabled(bool cache_disabled, base::OnceClosure callback) {
  std::unique_ptr<SetCacheDisabledParams> params = SetCacheDisabledParams::Builder()
      .SetCacheDisabled(std::move(cache_disabled))
      .Build();
  dispatcher_->SendMessage("Network.setCacheDisabled", params->Serialize(), std::move(callback));
}
void Domain::SetCacheDisabled(std::unique_ptr<SetCacheDisabledParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Network.setCacheDisabled", params->Serialize(), std::move(callback));
}
void Domain::SetCookie(std::unique_ptr<SetCookieParams> params, base::OnceCallback<void(std::unique_ptr<SetCookieResult>)> callback) {
  dispatcher_->SendMessage("Network.setCookie", params->Serialize(), base::BindOnce(&Domain::HandleSetCookieResponse, std::move(callback)));
}

void Domain::SetCookie(const std::string& name, const std::string& value, base::OnceCallback<void(std::unique_ptr<SetCookieResult>)> callback) {
  std::unique_ptr<SetCookieParams> params = SetCookieParams::Builder()
      .SetName(std::move(name))
      .SetValue(std::move(value))
      .Build();
dispatcher_->SendMessage("Network.setCookie", params->Serialize(), base::BindOnce(&Domain::HandleSetCookieResponse, std::move(callback)));
}
void Domain::SetCookies(std::unique_ptr<SetCookiesParams> params, base::OnceCallback<void(std::unique_ptr<SetCookiesResult>)> callback) {
  dispatcher_->SendMessage("Network.setCookies", params->Serialize(), base::BindOnce(&Domain::HandleSetCookiesResponse, std::move(callback)));
}

void Domain::SetCookies(std::vector<std::unique_ptr<::headless::network::CookieParam>> cookies, base::OnceClosure callback) {
  std::unique_ptr<SetCookiesParams> params = SetCookiesParams::Builder()
      .SetCookies(std::move(cookies))
      .Build();
  dispatcher_->SendMessage("Network.setCookies", params->Serialize(), std::move(callback));
}
void Domain::SetCookies(std::unique_ptr<SetCookiesParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Network.setCookies", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::SetDataSizeLimitsForTest(std::unique_ptr<SetDataSizeLimitsForTestParams> params, base::OnceCallback<void(std::unique_ptr<SetDataSizeLimitsForTestResult>)> callback) {
  dispatcher_->SendMessage("Network.setDataSizeLimitsForTest", params->Serialize(), base::BindOnce(&Domain::HandleSetDataSizeLimitsForTestResponse, std::move(callback)));
}
void Domain::SetExtraHTTPHeaders(std::unique_ptr<SetExtraHTTPHeadersParams> params, base::OnceCallback<void(std::unique_ptr<SetExtraHTTPHeadersResult>)> callback) {
  dispatcher_->SendMessage("Network.setExtraHTTPHeaders", params->Serialize(), base::BindOnce(&Domain::HandleSetExtraHTTPHeadersResponse, std::move(callback)));
}

void Domain::SetExtraHTTPHeaders(std::unique_ptr<base::DictionaryValue> headers, base::OnceClosure callback) {
  std::unique_ptr<SetExtraHTTPHeadersParams> params = SetExtraHTTPHeadersParams::Builder()
      .SetHeaders(std::move(headers))
      .Build();
  dispatcher_->SendMessage("Network.setExtraHTTPHeaders", params->Serialize(), std::move(callback));
}
void Domain::SetExtraHTTPHeaders(std::unique_ptr<SetExtraHTTPHeadersParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Network.setExtraHTTPHeaders", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::SetRequestInterception(std::unique_ptr<SetRequestInterceptionParams> params, base::OnceCallback<void(std::unique_ptr<SetRequestInterceptionResult>)> callback) {
  dispatcher_->SendMessage("Network.setRequestInterception", params->Serialize(), base::BindOnce(&Domain::HandleSetRequestInterceptionResponse, std::move(callback)));
}
void Domain::SetUserAgentOverride(std::unique_ptr<SetUserAgentOverrideParams> params, base::OnceCallback<void(std::unique_ptr<SetUserAgentOverrideResult>)> callback) {
  dispatcher_->SendMessage("Network.setUserAgentOverride", params->Serialize(), base::BindOnce(&Domain::HandleSetUserAgentOverrideResponse, std::move(callback)));
}

void Domain::SetUserAgentOverride(const std::string& user_agent, base::OnceClosure callback) {
  std::unique_ptr<SetUserAgentOverrideParams> params = SetUserAgentOverrideParams::Builder()
      .SetUserAgent(std::move(user_agent))
      .Build();
  dispatcher_->SendMessage("Network.setUserAgentOverride", params->Serialize(), std::move(callback));
}
void Domain::SetUserAgentOverride(std::unique_ptr<SetUserAgentOverrideParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Network.setUserAgentOverride", params->Serialize(), std::move(callback));
}


// static
void Domain::HandleCanClearBrowserCacheResponse(base::OnceCallback<void(std::unique_ptr<CanClearBrowserCacheResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<CanClearBrowserCacheResult> result = CanClearBrowserCacheResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleCanClearBrowserCookiesResponse(base::OnceCallback<void(std::unique_ptr<CanClearBrowserCookiesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<CanClearBrowserCookiesResult> result = CanClearBrowserCookiesResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleCanEmulateNetworkConditionsResponse(base::OnceCallback<void(std::unique_ptr<CanEmulateNetworkConditionsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<CanEmulateNetworkConditionsResult> result = CanEmulateNetworkConditionsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleClearBrowserCacheResponse(base::OnceCallback<void(std::unique_ptr<ClearBrowserCacheResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ClearBrowserCacheResult> result = ClearBrowserCacheResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleClearBrowserCookiesResponse(base::OnceCallback<void(std::unique_ptr<ClearBrowserCookiesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ClearBrowserCookiesResult> result = ClearBrowserCookiesResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleContinueInterceptedRequestResponse(base::OnceCallback<void(std::unique_ptr<ContinueInterceptedRequestResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ContinueInterceptedRequestResult> result = ContinueInterceptedRequestResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleDeleteCookiesResponse(base::OnceCallback<void(std::unique_ptr<DeleteCookiesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DeleteCookiesResult> result = DeleteCookiesResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = DisableResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleEmulateNetworkConditionsResponse(base::OnceCallback<void(std::unique_ptr<EmulateNetworkConditionsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<EmulateNetworkConditionsResult> result = EmulateNetworkConditionsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = EnableResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetAllCookiesResponse(base::OnceCallback<void(std::unique_ptr<GetAllCookiesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetAllCookiesResult> result = GetAllCookiesResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetCertificateResponse(base::OnceCallback<void(std::unique_ptr<GetCertificateResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetCertificateResult> result = GetCertificateResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetCookiesResponse(base::OnceCallback<void(std::unique_ptr<GetCookiesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetCookiesResult> result = GetCookiesResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetResponseBodyResponse(base::OnceCallback<void(std::unique_ptr<GetResponseBodyResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetResponseBodyResult> result = GetResponseBodyResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetRequestPostDataResponse(base::OnceCallback<void(std::unique_ptr<GetRequestPostDataResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetRequestPostDataResult> result = GetRequestPostDataResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetResponseBodyForInterceptionResponse(base::OnceCallback<void(std::unique_ptr<GetResponseBodyForInterceptionResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetResponseBodyForInterceptionResult> result = GetResponseBodyForInterceptionResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleTakeResponseBodyForInterceptionAsStreamResponse(base::OnceCallback<void(std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult> result = TakeResponseBodyForInterceptionAsStreamResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleReplayXHRResponse(base::OnceCallback<void(std::unique_ptr<ReplayXHRResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ReplayXHRResult> result = ReplayXHRResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSearchInResponseBodyResponse(base::OnceCallback<void(std::unique_ptr<SearchInResponseBodyResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SearchInResponseBodyResult> result = SearchInResponseBodyResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetBlockedURLsResponse(base::OnceCallback<void(std::unique_ptr<SetBlockedURLsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetBlockedURLsResult> result = SetBlockedURLsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetBypassServiceWorkerResponse(base::OnceCallback<void(std::unique_ptr<SetBypassServiceWorkerResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetBypassServiceWorkerResult> result = SetBypassServiceWorkerResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetCacheDisabledResponse(base::OnceCallback<void(std::unique_ptr<SetCacheDisabledResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetCacheDisabledResult> result = SetCacheDisabledResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetCookieResponse(base::OnceCallback<void(std::unique_ptr<SetCookieResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetCookieResult> result = SetCookieResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetCookiesResponse(base::OnceCallback<void(std::unique_ptr<SetCookiesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetCookiesResult> result = SetCookiesResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetDataSizeLimitsForTestResponse(base::OnceCallback<void(std::unique_ptr<SetDataSizeLimitsForTestResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetDataSizeLimitsForTestResult> result = SetDataSizeLimitsForTestResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetExtraHTTPHeadersResponse(base::OnceCallback<void(std::unique_ptr<SetExtraHTTPHeadersResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetExtraHTTPHeadersResult> result = SetExtraHTTPHeadersResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetRequestInterceptionResponse(base::OnceCallback<void(std::unique_ptr<SetRequestInterceptionResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetRequestInterceptionResult> result = SetRequestInterceptionResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetUserAgentOverrideResponse(base::OnceCallback<void(std::unique_ptr<SetUserAgentOverrideResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetUserAgentOverrideResult> result = SetUserAgentOverrideResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchDataReceivedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<DataReceivedParams> parsed_params(DataReceivedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnDataReceived(*parsed_params);
  }
}

void Domain::DispatchEventSourceMessageReceivedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<EventSourceMessageReceivedParams> parsed_params(EventSourceMessageReceivedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnEventSourceMessageReceived(*parsed_params);
  }
}

void Domain::DispatchLoadingFailedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<LoadingFailedParams> parsed_params(LoadingFailedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnLoadingFailed(*parsed_params);
  }
}

void Domain::DispatchLoadingFinishedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<LoadingFinishedParams> parsed_params(LoadingFinishedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnLoadingFinished(*parsed_params);
  }
}

void Domain::DispatchRequestInterceptedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<RequestInterceptedParams> parsed_params(RequestInterceptedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnRequestIntercepted(*parsed_params);
  }
}

void Domain::DispatchRequestServedFromCacheEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<RequestServedFromCacheParams> parsed_params(RequestServedFromCacheParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnRequestServedFromCache(*parsed_params);
  }
}

void Domain::DispatchRequestWillBeSentEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<RequestWillBeSentParams> parsed_params(RequestWillBeSentParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnRequestWillBeSent(*parsed_params);
  }
}

void Domain::DispatchResourceChangedPriorityEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ResourceChangedPriorityParams> parsed_params(ResourceChangedPriorityParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnResourceChangedPriority(*parsed_params);
  }
}

void Domain::DispatchSignedExchangeReceivedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<SignedExchangeReceivedParams> parsed_params(SignedExchangeReceivedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnSignedExchangeReceived(*parsed_params);
  }
}

void Domain::DispatchResponseReceivedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ResponseReceivedParams> parsed_params(ResponseReceivedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnResponseReceived(*parsed_params);
  }
}

void Domain::DispatchWebSocketClosedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<WebSocketClosedParams> parsed_params(WebSocketClosedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnWebSocketClosed(*parsed_params);
  }
}

void Domain::DispatchWebSocketCreatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<WebSocketCreatedParams> parsed_params(WebSocketCreatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnWebSocketCreated(*parsed_params);
  }
}

void Domain::DispatchWebSocketFrameErrorEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<WebSocketFrameErrorParams> parsed_params(WebSocketFrameErrorParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnWebSocketFrameError(*parsed_params);
  }
}

void Domain::DispatchWebSocketFrameReceivedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<WebSocketFrameReceivedParams> parsed_params(WebSocketFrameReceivedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnWebSocketFrameReceived(*parsed_params);
  }
}

void Domain::DispatchWebSocketFrameSentEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<WebSocketFrameSentParams> parsed_params(WebSocketFrameSentParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnWebSocketFrameSent(*parsed_params);
  }
}

void Domain::DispatchWebSocketHandshakeResponseReceivedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<WebSocketHandshakeResponseReceivedParams> parsed_params(WebSocketHandshakeResponseReceivedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnWebSocketHandshakeResponseReceived(*parsed_params);
  }
}

void Domain::DispatchWebSocketWillSendHandshakeRequestEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<WebSocketWillSendHandshakeRequestParams> parsed_params(WebSocketWillSendHandshakeRequestParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnWebSocketWillSendHandshakeRequest(*parsed_params);
  }
}

void Domain::DispatchRequestWillBeSentExtraInfoEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<RequestWillBeSentExtraInfoParams> parsed_params(RequestWillBeSentExtraInfoParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnRequestWillBeSentExtraInfo(*parsed_params);
  }
}

void Domain::DispatchResponseReceivedExtraInfoEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ResponseReceivedExtraInfoParams> parsed_params(ResponseReceivedExtraInfoParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnResponseReceivedExtraInfo(*parsed_params);
  }
}

Domain::Domain(internal::MessageDispatcher* dispatcher)
    : dispatcher_(dispatcher) {
}

Domain::~Domain() {}

ExperimentalDomain::ExperimentalDomain(internal::MessageDispatcher* dispatcher)
    : Domain(dispatcher) {}

ExperimentalDomain::~ExperimentalDomain() {}

void ExperimentalDomain::AddObserver(ExperimentalObserver* observer) {
  RegisterEventHandlersIfNeeded();
  observers_.AddObserver(observer);
}

void ExperimentalDomain::RemoveObserver(ExperimentalObserver* observer) {
  observers_.RemoveObserver(observer);
}

}  // namespace network

} // namespace headless
