// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/prerender/isolated/isolated_prerender_proxying_url_loader_factory.h"

#include "base/barrier_closure.h"
#include "base/bind.h"
#include "chrome/browser/prerender/isolated/isolated_prerender_tab_helper.h"
#include "chrome/browser/profiles/profile.h"
#include "content/public/browser/browser_context.h"
#include "content/public/browser/web_contents.h"
#include "content/public/common/content_constants.h"
#include "mojo/public/cpp/bindings/receiver.h"
#include "net/base/load_flags.h"
#include "third_party/blink/public/common/client_hints/client_hints.h"

namespace {

const char kAllowedUAClientHint[] = "sec-ch-ua";
const char kAllowedUAMobileClientHint[] = "sec-ch-ua-mobile";

}  // namespace

IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::InProgressRequest(
    IsolatedPrerenderProxyingURLLoaderFactory* parent_factory,
    network::mojom::URLLoaderFactory* target_factory,
    ResourceLoadSuccessfulCallback on_resource_load_successful,
    mojo::PendingReceiver<network::mojom::URLLoader> loader_receiver,
    int32_t routing_id,
    int32_t request_id,
    uint32_t options,
    const network::ResourceRequest& request,
    mojo::PendingRemote<network::mojom::URLLoaderClient> client,
    const net::MutableNetworkTrafficAnnotationTag& traffic_annotation)
    : parent_factory_(parent_factory),
      on_resource_load_successful_(on_resource_load_successful),
      target_client_(std::move(client)),
      loader_receiver_(this, std::move(loader_receiver)) {
  redirect_chain_.push_back(request.url);

  mojo::PendingRemote<network::mojom::URLLoaderClient> proxy_client =
      client_receiver_.BindNewPipeAndPassRemote();

  target_factory->CreateLoaderAndStart(
      target_loader_.BindNewPipeAndPassReceiver(), routing_id, request_id,
      options, request, std::move(proxy_client), traffic_annotation);

  // Calls |OnBindingsClosed| only after both disconnect handlers have been run.
  base::RepeatingClosure closure = base::BarrierClosure(
      2, base::BindOnce(&InProgressRequest::OnBindingsClosed,
                        base::Unretained(this)));
  loader_receiver_.set_disconnect_handler(closure);
  client_receiver_.set_disconnect_handler(closure);
}

IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    ~InProgressRequest() {
  if (destruction_callback_) {
    std::move(destruction_callback_).Run();
  }
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    FollowRedirect(const std::vector<std::string>& removed_headers,
                   const net::HttpRequestHeaders& modified_headers,
                   const net::HttpRequestHeaders& modified_cors_exempt_headers,
                   const base::Optional<GURL>& new_url) {
  target_loader_->FollowRedirect(removed_headers, modified_headers,
                                 modified_cors_exempt_headers, new_url);
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::SetPriority(
    net::RequestPriority priority,
    int32_t intra_priority_value) {
  target_loader_->SetPriority(priority, intra_priority_value);
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    PauseReadingBodyFromNet() {
  target_loader_->PauseReadingBodyFromNet();
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    ResumeReadingBodyFromNet() {
  target_loader_->ResumeReadingBodyFromNet();
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    OnReceiveResponse(network::mojom::URLResponseHeadPtr head) {
  if (head && head->headers) {
    http_response_code_ = head->headers->response_code();
  }
  target_client_->OnReceiveResponse(std::move(head));
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    OnReceiveRedirect(const net::RedirectInfo& redirect_info,
                      network::mojom::URLResponseHeadPtr head) {
  redirect_chain_.push_back(redirect_info.new_url);
  target_client_->OnReceiveRedirect(redirect_info, std::move(head));
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    OnUploadProgress(int64_t current_position,
                     int64_t total_size,
                     OnUploadProgressCallback callback) {
  target_client_->OnUploadProgress(current_position, total_size,
                                   std::move(callback));
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    OnReceiveCachedMetadata(mojo_base::BigBuffer data) {
  target_client_->OnReceiveCachedMetadata(std::move(data));
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    OnTransferSizeUpdated(int32_t transfer_size_diff) {
  target_client_->OnTransferSizeUpdated(transfer_size_diff);
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    OnStartLoadingResponseBody(mojo::ScopedDataPipeConsumerHandle body) {
  target_client_->OnStartLoadingResponseBody(std::move(body));
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::OnComplete(
    const network::URLLoaderCompletionStatus& status) {
  MaybeReportResourceLoadSuccess(status);
  target_client_->OnComplete(status);
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    OnBindingsClosed() {
  // Destroys |this|.
  parent_factory_->RemoveRequest(this);
}

void IsolatedPrerenderProxyingURLLoaderFactory::InProgressRequest::
    MaybeReportResourceLoadSuccess(
        const network::URLLoaderCompletionStatus& status) {
  if (status.error_code != net::OK) {
    return;
  }

  if (!http_response_code_) {
    return;
  }

  if (*http_response_code_ >= 300) {
    return;
  }

  if (*http_response_code_ < 200) {
    return;
  }

  DCHECK_GT(redirect_chain_.size(), 0U);
  for (const GURL& url : redirect_chain_) {
    on_resource_load_successful_.Run(url);
  }
}

IsolatedPrerenderProxyingURLLoaderFactory::
    IsolatedPrerenderProxyingURLLoaderFactory(
        int frame_tree_node_id,
        mojo::PendingReceiver<network::mojom::URLLoaderFactory> loader_receiver,
        mojo::PendingRemote<network::mojom::URLLoaderFactory>
            network_process_factory,
        mojo::PendingRemote<network::mojom::URLLoaderFactory> isolated_factory,
        DisconnectCallback on_disconnect,
        ResourceLoadSuccessfulCallback on_resource_load_successful)
    : frame_tree_node_id_(frame_tree_node_id),
      on_resource_load_successful_(std::move(on_resource_load_successful)),
      on_disconnect_(std::move(on_disconnect)) {
  network_process_factory_.Bind(std::move(network_process_factory));
  network_process_factory_.set_disconnect_handler(base::BindOnce(
      &IsolatedPrerenderProxyingURLLoaderFactory::OnNetworkProcessFactoryError,
      base::Unretained(this)));

  isolated_factory_.Bind(std::move(isolated_factory));
  isolated_factory_.set_disconnect_handler(base::BindOnce(
      &IsolatedPrerenderProxyingURLLoaderFactory::OnIsolatedFactoryError,
      base::Unretained(this)));

  proxy_receivers_.Add(this, std::move(loader_receiver));
  proxy_receivers_.set_disconnect_handler(base::BindRepeating(
      &IsolatedPrerenderProxyingURLLoaderFactory::OnProxyBindingError,
      base::Unretained(this)));
}

IsolatedPrerenderProxyingURLLoaderFactory::
    ~IsolatedPrerenderProxyingURLLoaderFactory() = default;

void IsolatedPrerenderProxyingURLLoaderFactory::NotifyPageNavigatedToAfterSRP(
    const std::set<GURL>& cached_subresources) {
  previously_cached_subresources_ = cached_subresources;
}

bool IsolatedPrerenderProxyingURLLoaderFactory::
    ShouldHandleRequestForPrerender() const {
  return !previously_cached_subresources_.has_value();
}

void IsolatedPrerenderProxyingURLLoaderFactory::CreateLoaderAndStart(
    mojo::PendingReceiver<network::mojom::URLLoader> loader_receiver,
    int32_t routing_id,
    int32_t request_id,
    uint32_t options,
    const network::ResourceRequest& request,
    mojo::PendingRemote<network::mojom::URLLoaderClient> client,
    const net::MutableNetworkTrafficAnnotationTag& traffic_annotation) {
  // If this request is happening during a prerender then check if it is
  // eligible for caching before putting it on the network.
  if (ShouldHandleRequestForPrerender()) {
    // We must check if the request can be cached and set the appropriate load
    // flag if so.
    content::WebContents* web_contents =
        content::WebContents::FromFrameTreeNodeId(frame_tree_node_id_);
    if (!web_contents) {
      return;
    }

    Profile* profile =
        Profile::FromBrowserContext(web_contents->GetBrowserContext());
    IsolatedPrerenderTabHelper::CheckEligibilityOfURL(
        profile, request.url,
        base::BindOnce(
            &IsolatedPrerenderProxyingURLLoaderFactory::OnEligibilityResult,
            weak_factory_.GetWeakPtr(), std::move(loader_receiver), routing_id,
            request_id, options, request, std::move(client),
            traffic_annotation));
    return;
  }

  // This request is happening after the user clicked to a prerendered page.
  DCHECK(previously_cached_subresources_.has_value());
  const std::set<GURL>& cached_subresources = *previously_cached_subresources_;
  if (cached_subresources.find(request.url) != cached_subresources.end()) {
    // Load this resource from |isolated_factory_|'s cache.
    requests_.insert(std::make_unique<InProgressRequest>(
        this, isolated_factory_.get(), base::DoNothing(),
        std::move(loader_receiver), routing_id, request_id, options, request,
        std::move(client), traffic_annotation));
  } else {
    // Resource was not cached during the NSP, so load it normally.
    requests_.insert(std::make_unique<InProgressRequest>(
        this, network_process_factory_.get(), base::DoNothing(),
        std::move(loader_receiver), routing_id, request_id, options, request,
        std::move(client), traffic_annotation));
  }
}

void IsolatedPrerenderProxyingURLLoaderFactory::OnEligibilityResult(
    mojo::PendingReceiver<network::mojom::URLLoader> loader_receiver,
    int32_t routing_id,
    int32_t request_id,
    uint32_t options,
    const network::ResourceRequest& request,
    mojo::PendingRemote<network::mojom::URLLoaderClient> client,
    const net::MutableNetworkTrafficAnnotationTag& traffic_annotation,
    const GURL& url,
    bool eligible,
    base::Optional<IsolatedPrerenderTabHelper::PrefetchStatus> not_used) {
  DCHECK_EQ(request.url, url);
  DCHECK(!previously_cached_subresources_.has_value());
  DCHECK(request.cors_exempt_headers.HasHeader(
      content::kCorsExemptPurposeHeaderName));
  DCHECK(request.load_flags & net::LOAD_PREFETCH);
  DCHECK(!request.trusted_params.has_value());

  network::ResourceRequest isolated_request = request;

  // Ensures that the U-A string is set to the Isolated Network Context's
  // default.
  isolated_request.headers.RemoveHeader("User-Agent");

  // Ensures that the Accept-Language string is set to the Isolated Network
  // Context's default.
  isolated_request.headers.RemoveHeader("Accept-Language");

  // Strip out all Client Hints.
  for (size_t i = 0; i < blink::kClientHintsMappingsCount; ++i) {
    // UA Client Hint and UA Mobile are ok to send.
    if (std::string(blink::kClientHintsHeaderMapping[i]) ==
            kAllowedUAClientHint ||
        std::string(blink::kClientHintsHeaderMapping[i]) ==
            kAllowedUAMobileClientHint) {
      continue;
    }
    isolated_request.headers.RemoveHeader(blink::kClientHintsHeaderMapping[i]);
  }

  ResourceLoadSuccessfulCallback resource_load_successful_callback =
      on_resource_load_successful_;

  // If this subresource is eligible for prefetching then it can be cached. If
  // not, it must still be put on the wire to avoid privacy attacks but should
  // not be cached.
  if (!eligible) {
    isolated_request.load_flags |= net::LOAD_DISABLE_CACHE;

    // Don't report loaded resources that won't go in the cache.
    resource_load_successful_callback = base::DoNothing();
  }

  requests_.insert(std::make_unique<InProgressRequest>(
      this, isolated_factory_.get(), resource_load_successful_callback,
      std::move(loader_receiver), routing_id, request_id, options,
      isolated_request, std::move(client), traffic_annotation));
}

void IsolatedPrerenderProxyingURLLoaderFactory::Clone(
    mojo::PendingReceiver<network::mojom::URLLoaderFactory> loader_receiver) {
  proxy_receivers_.Add(this, std::move(loader_receiver));
}

void IsolatedPrerenderProxyingURLLoaderFactory::OnNetworkProcessFactoryError() {
  // Stop calls to CreateLoaderAndStart() when |network_process_factory_| is
  // invalid.
  network_process_factory_.reset();
  proxy_receivers_.Clear();

  MaybeDestroySelf();
}

void IsolatedPrerenderProxyingURLLoaderFactory::OnIsolatedFactoryError() {
  // Stop calls to CreateLoaderAndStart() when |isolated_factory_| is
  // invalid.
  isolated_factory_.reset();
  proxy_receivers_.Clear();

  MaybeDestroySelf();
}

void IsolatedPrerenderProxyingURLLoaderFactory::OnProxyBindingError() {
  if (proxy_receivers_.empty()) {
    network_process_factory_.reset();
  }

  MaybeDestroySelf();
}

void IsolatedPrerenderProxyingURLLoaderFactory::RemoveRequest(
    InProgressRequest* request) {
  auto it = requests_.find(request);
  DCHECK(it != requests_.end());
  requests_.erase(it);

  MaybeDestroySelf();
}

void IsolatedPrerenderProxyingURLLoaderFactory::MaybeDestroySelf() {
  // Even if all URLLoaderFactory pipes connected to this object have been
  // closed it has to stay alive until all active requests have completed.
  if (network_process_factory_.is_bound() || isolated_factory_.is_bound() ||
      !requests_.empty()) {
    return;
  }

  // Deletes |this|.
  std::move(on_disconnect_).Run(this);
}
