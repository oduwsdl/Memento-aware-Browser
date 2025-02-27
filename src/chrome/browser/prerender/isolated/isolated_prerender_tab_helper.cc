// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/prerender/isolated/isolated_prerender_tab_helper.h"

#include <string>

#include "base/bind.h"
#include "base/feature_list.h"
#include "base/metrics/histogram.h"
#include "base/metrics/histogram_functions.h"
#include "base/metrics/histogram_macros.h"
#include "base/optional.h"
#include "base/time/time.h"
#include "chrome/browser/chrome_content_browser_client.h"
#include "chrome/browser/navigation_predictor/navigation_predictor_keyed_service_factory.h"
#include "chrome/browser/net/prediction_options.h"
#include "chrome/browser/prerender/isolated/isolated_prerender_features.h"
#include "chrome/browser/prerender/isolated/isolated_prerender_params.h"
#include "chrome/browser/prerender/isolated/isolated_prerender_proxy_configurator.h"
#include "chrome/browser/prerender/isolated/isolated_prerender_service.h"
#include "chrome/browser/prerender/isolated/isolated_prerender_service_factory.h"
#include "chrome/browser/prerender/isolated/isolated_prerender_service_workers_observer.h"
#include "chrome/browser/prerender/isolated/isolated_prerender_subresource_manager.h"
#include "chrome/browser/prerender/prerender_manager.h"
#include "chrome/browser/prerender/prerender_manager_factory.h"
#include "chrome/browser/profiles/profile.h"
#include "components/data_reduction_proxy/core/browser/data_reduction_proxy_settings.h"
#include "components/google/core/common/google_util.h"
#include "components/language/core/browser/pref_names.h"
#include "components/page_load_metrics/browser/metrics_web_contents_observer.h"
#include "components/prefs/pref_service.h"
#include "components/search_engines/template_url_service.h"
#include "content/public/browser/browser_context.h"
#include "content/public/browser/navigation_handle.h"
#include "content/public/browser/network_service_instance.h"
#include "content/public/browser/render_frame_host.h"
#include "content/public/browser/storage_partition.h"
#include "content/public/browser/web_contents.h"
#include "content/public/common/content_constants.h"
#include "net/base/isolation_info.h"
#include "net/base/load_flags.h"
#include "net/base/net_errors.h"
#include "net/cookies/cookie_store.h"
#include "net/http/http_status_code.h"
#include "net/http/http_util.h"
#include "net/traffic_annotation/network_traffic_annotation.h"
#include "services/network/public/cpp/resource_request.h"
#include "services/network/public/cpp/shared_url_loader_factory.h"
#include "services/network/public/cpp/simple_url_loader.h"
#include "services/network/public/cpp/wrapper_shared_url_loader_factory.h"
#include "services/network/public/mojom/cookie_manager.mojom.h"
#include "services/network/public/mojom/network_context.mojom.h"
#include "services/network/public/mojom/network_service.mojom.h"
#include "url/origin.h"

namespace {

const void* const kPrefetchingLikelyEventKey = 0;

base::Optional<base::TimeDelta> GetTotalPrefetchTime(
    network::mojom::URLResponseHead* head) {
  DCHECK(head);

  base::Time start = head->request_time;
  base::Time end = head->response_time;

  if (start.is_null() || end.is_null())
    return base::nullopt;

  return end - start;
}

base::Optional<base::TimeDelta> GetPrefetchConnectTime(
    network::mojom::URLResponseHead* head) {
  DCHECK(head);

  base::TimeTicks start = head->load_timing.connect_timing.connect_start;
  base::TimeTicks end = head->load_timing.connect_timing.connect_end;

  if (start.is_null() || end.is_null())
    return base::nullopt;

  return end - start;
}

void InformPLMOfLikelyPrefetching(content::WebContents* web_contents) {
  page_load_metrics::MetricsWebContentsObserver* metrics_web_contents_observer =
      page_load_metrics::MetricsWebContentsObserver::FromWebContents(
          web_contents);
  if (!metrics_web_contents_observer)
    return;

  metrics_web_contents_observer->BroadcastEventToObservers(
      IsolatedPrerenderTabHelper::PrefetchingLikelyEventKey());
}

void OnGotCookieList(
    const GURL& url,
    IsolatedPrerenderTabHelper::OnEligibilityResultCallback result_callback,
    const net::CookieAccessResultList& cookie_list,
    const net::CookieAccessResultList& excluded_cookies) {
  if (!cookie_list.empty()) {
    std::move(result_callback)
        .Run(url, false,
             IsolatedPrerenderTabHelper::PrefetchStatus::
                 kPrefetchNotEligibleUserHasCookies);
    return;
  }
  std::move(result_callback).Run(url, true, base::nullopt);
}

}  // namespace

IsolatedPrerenderTabHelper::PrefetchMetrics::PrefetchMetrics() = default;
IsolatedPrerenderTabHelper::PrefetchMetrics::~PrefetchMetrics() = default;

IsolatedPrerenderTabHelper::AfterSRPMetrics::AfterSRPMetrics() = default;
IsolatedPrerenderTabHelper::AfterSRPMetrics::AfterSRPMetrics(
    const AfterSRPMetrics& other) = default;
IsolatedPrerenderTabHelper::AfterSRPMetrics::~AfterSRPMetrics() = default;

IsolatedPrerenderTabHelper::CurrentPageLoad::CurrentPageLoad(
    content::NavigationHandle* handle)
    : profile_(handle ? Profile::FromBrowserContext(
                            handle->GetWebContents()->GetBrowserContext())
                      : nullptr),
      navigation_start_(handle ? handle->NavigationStart() : base::TimeTicks()),
      srp_metrics_(
          base::MakeRefCounted<IsolatedPrerenderTabHelper::PrefetchMetrics>()) {
}

IsolatedPrerenderTabHelper::CurrentPageLoad::~CurrentPageLoad() {
  if (!profile_)
    return;

  IsolatedPrerenderService* service =
      IsolatedPrerenderServiceFactory::GetForProfile(profile_);
  if (!service) {
    return;
  }

  for (const GURL& url : no_state_prefetched_urls_) {
    service->DestroySubresourceManagerForURL(url);
  }
  for (const GURL& url : urls_to_no_state_prefetch_) {
    service->DestroySubresourceManagerForURL(url);
  }
}

// static
const void* IsolatedPrerenderTabHelper::PrefetchingLikelyEventKey() {
  return &kPrefetchingLikelyEventKey;
}

IsolatedPrerenderTabHelper::IsolatedPrerenderTabHelper(
    content::WebContents* web_contents)
    : content::WebContentsObserver(web_contents) {
  page_ = std::make_unique<CurrentPageLoad>(nullptr);
  profile_ = Profile::FromBrowserContext(web_contents->GetBrowserContext());

  NavigationPredictorKeyedService* navigation_predictor_service =
      NavigationPredictorKeyedServiceFactory::GetForProfile(profile_);
  if (navigation_predictor_service) {
    navigation_predictor_service->AddObserver(this);
  }

  // Make sure the global service is up and running so that the service worker
  // registrations can be queried before the first navigation prediction.
  IsolatedPrerenderServiceFactory::GetForProfile(profile_);
}

IsolatedPrerenderTabHelper::~IsolatedPrerenderTabHelper() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  NavigationPredictorKeyedService* navigation_predictor_service =
      NavigationPredictorKeyedServiceFactory::GetForProfile(profile_);
  if (navigation_predictor_service) {
    navigation_predictor_service->RemoveObserver(this);
  }
}

void IsolatedPrerenderTabHelper::AddObserverForTesting(Observer* observer) {
  observer_list_.AddObserver(observer);
}

void IsolatedPrerenderTabHelper::RemoveObserverForTesting(Observer* observer) {
  observer_list_.RemoveObserver(observer);
}

network::mojom::NetworkContext*
IsolatedPrerenderTabHelper::GetIsolatedContextForTesting() const {
  return page_->isolated_network_context_.get();
}

base::Optional<IsolatedPrerenderTabHelper::AfterSRPMetrics>
IsolatedPrerenderTabHelper::after_srp_metrics() const {
  if (page_->after_srp_metrics_) {
    return *(page_->after_srp_metrics_);
  }
  return base::nullopt;
}

void IsolatedPrerenderTabHelper::DidStartNavigation(
    content::NavigationHandle* navigation_handle) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  if (!navigation_handle->IsInMainFrame()) {
    return;
  }

  // Don't take any actions during a prerender since it was probably triggered
  // by another instance of this class and we don't want to interfere.
  prerender::PrerenderManager* prerender_manager =
      prerender::PrerenderManagerFactory::GetForBrowserContext(profile_);
  if (prerender_manager &&
      prerender_manager->IsWebContentsPrerendering(web_contents(), nullptr)) {
    return;
  }

  // User is navigating, don't bother prefetching further.
  page_->url_loader_.reset();

  if (page_->srp_metrics_->prefetch_attempted_count_ > 0) {
    UMA_HISTOGRAM_COUNTS_100(
        "IsolatedPrerender.Prefetch.Mainframe.TotalRedirects",
        page_->srp_metrics_->prefetch_total_redirect_count_);
  }

  // Notify the subresource manager (if applicable)  that its page is being
  // navigated to so that the prefetched subresources can be used from cache.
  IsolatedPrerenderService* service =
      IsolatedPrerenderServiceFactory::GetForProfile(profile_);
  if (!service)
    return;

  IsolatedPrerenderSubresourceManager* subresource_manager =
      service->GetSubresourceManagerForURL(navigation_handle->GetURL());
  if (!subresource_manager)
    return;

  subresource_manager->NotifyPageNavigatedToAfterSRP();
}

void IsolatedPrerenderTabHelper::NotifyPrefetchProbeLatency(
    base::TimeDelta probe_latency) {
  page_->probe_latency_ = probe_latency;
}

void IsolatedPrerenderTabHelper::OnPrefetchStatusUpdate(const GURL& url,
                                                        PrefetchStatus usage) {
  page_->prefetch_status_by_url_[url] = usage;
}

void IsolatedPrerenderTabHelper::DidFinishNavigation(
    content::NavigationHandle* navigation_handle) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  if (!navigation_handle->IsInMainFrame()) {
    return;
  }
  if (!navigation_handle->HasCommitted()) {
    return;
  }

  // Don't take any actions during a prerender since it was probably triggered
  // by another instance of this class and we don't want to interfere.
  prerender::PrerenderManager* prerender_manager =
      prerender::PrerenderManagerFactory::GetForBrowserContext(profile_);
  if (prerender_manager &&
      prerender_manager->IsWebContentsPrerendering(web_contents(), nullptr)) {
    return;
  }

  DCHECK(!PrefetchingActive());

  GURL url = navigation_handle->GetURL();

  std::unique_ptr<CurrentPageLoad> new_page =
      std::make_unique<CurrentPageLoad>(navigation_handle);

  if (page_->srp_metrics_->predicted_urls_count_ > 0) {
    // If the previous page load was a Google SRP, the AfterSRPMetrics class
    // needs to be created now from the SRP's |page_| and then set on the new
    // one when we set it at the end of this method.
    new_page->after_srp_metrics_ = std::make_unique<AfterSRPMetrics>();
    new_page->after_srp_metrics_->url_ = url;
    new_page->after_srp_metrics_->prefetch_eligible_count_ =
        page_->srp_metrics_->prefetch_eligible_count_;

    new_page->after_srp_metrics_->probe_latency_ = page_->probe_latency_;

    auto status_iter = page_->prefetch_status_by_url_.find(url);
    if (status_iter != page_->prefetch_status_by_url_.end()) {
      new_page->after_srp_metrics_->prefetch_status_ = status_iter->second;
    } else {
      new_page->after_srp_metrics_->prefetch_status_ =
          PrefetchStatus::kNavigatedToLinkNotOnSRP;
    }

    // Whenever probe latency is set, the status should reflect that a probe
    // was attempted and vise versa.
    DCHECK_EQ(new_page->after_srp_metrics_->probe_latency_.has_value(),
              new_page->after_srp_metrics_->prefetch_status_ ==
                      PrefetchStatus::kPrefetchUsedProbeSuccess ||
                  new_page->after_srp_metrics_->prefetch_status_ ==
                      PrefetchStatus::kPrefetchNotUsedProbeFailed);

    auto position_iter = page_->original_prediction_ordering_.find(url);
    if (position_iter != page_->original_prediction_ordering_.end()) {
      new_page->after_srp_metrics_->clicked_link_srp_position_ =
          position_iter->second;
    }

    // See if the page being navigated to was prerendered. If so, copy over its
    // subresource manager and networking pipes.
    IsolatedPrerenderService* service =
        IsolatedPrerenderServiceFactory::GetForProfile(profile_);
    std::unique_ptr<IsolatedPrerenderSubresourceManager> manager =
        service->TakeSubresourceManagerForURL(url);
    if (manager) {
      new_page->subresource_manager_ = std::move(manager);
      new_page->isolated_url_loader_factory_ =
          std::move(page_->isolated_url_loader_factory_);
      new_page->isolated_network_context_ =
          std::move(page_->isolated_network_context_);
    }
  }

  // |page_| is reset on commit so that any available cached prefetches that
  // result from a redirect get used.
  page_ = std::move(new_page);
}

void IsolatedPrerenderTabHelper::OnVisibilityChanged(
    content::Visibility visibility) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);

  if (!IsolatedPrerenderIsEnabled()) {
    return;
  }

  // Start prefetching if the tab has become visible and prefetching is
  // inactive. Hidden and occluded visibility is ignored here so that pending
  // prefetches can finish.
  if (visibility == content::Visibility::VISIBLE && !PrefetchingActive())
    Prefetch();
}

std::unique_ptr<PrefetchedMainframeResponseContainer>
IsolatedPrerenderTabHelper::TakePrefetchResponse(const GURL& url) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  auto it = page_->prefetched_responses_.find(url);
  if (it == page_->prefetched_responses_.end())
    return nullptr;

  std::unique_ptr<PrefetchedMainframeResponseContainer> response =
      std::move(it->second);
  page_->prefetched_responses_.erase(it);
  return response;
}

std::unique_ptr<PrefetchedMainframeResponseContainer>
IsolatedPrerenderTabHelper::CopyPrefetchResponseForNSP(const GURL& url) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  auto it = page_->prefetched_responses_.find(url);
  if (it == page_->prefetched_responses_.end())
    return nullptr;

  return it->second->Clone();
}

bool IsolatedPrerenderTabHelper::PrefetchingActive() const {
  return page_ && page_->url_loader_;
}

void IsolatedPrerenderTabHelper::Prefetch() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  DCHECK(IsolatedPrerenderIsEnabled());

  page_->url_loader_.reset();

  if (!page_->srp_metrics_->navigation_to_prefetch_start_.has_value()) {
    page_->srp_metrics_->navigation_to_prefetch_start_ =
        base::TimeTicks::Now() - page_->navigation_start_;
    DCHECK_GT(page_->srp_metrics_->navigation_to_prefetch_start_.value(),
              base::TimeDelta());
  }

  if (IsolatedPrerenderCloseIdleSockets() && page_->isolated_network_context_) {
    page_->isolated_network_context_->CloseIdleConnections(base::DoNothing());
  }

  if (page_->urls_to_prefetch_.empty()) {
    return;
  }

  if (IsolatedPrerenderMaximumNumberOfPrefetches().has_value() &&
      page_->srp_metrics_->prefetch_attempted_count_ >=
          IsolatedPrerenderMaximumNumberOfPrefetches().value()) {
    return;
  }

  if (web_contents()->GetVisibility() != content::Visibility::VISIBLE) {
    // |OnVisibilityChanged| will restart prefetching when the tab becomes
    // visible again.
    return;
  }

  page_->srp_metrics_->prefetch_attempted_count_++;

  GURL url = page_->urls_to_prefetch_[0];
  page_->urls_to_prefetch_.erase(page_->urls_to_prefetch_.begin());

  // The status is updated to be successful or failed when it finishes.
  OnPrefetchStatusUpdate(url, PrefetchStatus::kPrefetchNotFinishedInTime);

  net::IsolationInfo isolation_info =
      net::IsolationInfo::CreateOpaqueAndNonTransient();
  network::ResourceRequest::TrustedParams trusted_params;
  trusted_params.isolation_info = isolation_info;

  std::unique_ptr<network::ResourceRequest> request =
      std::make_unique<network::ResourceRequest>();
  request->url = url;
  request->method = "GET";
  request->load_flags = net::LOAD_DISABLE_CACHE | net::LOAD_PREFETCH;
  request->credentials_mode = network::mojom::CredentialsMode::kOmit;
  request->headers.SetHeader(content::kCorsExemptPurposeHeaderName, "prefetch");
  request->trusted_params = trusted_params;

  net::NetworkTrafficAnnotationTag traffic_annotation =
      net::DefineNetworkTrafficAnnotation("navigation_predictor_srp_prefetch",
                                          R"(
          semantics {
            sender: "Navigation Predictor SRP Prefetch Loader"
            description:
              "Prefetches the mainframe HTML of a page linked from a Google "
              "Search Result Page (SRP). This is done out-of-band of normal "
              "prefetches to allow total isolation of this request from the "
              "rest of browser traffic and user state like cookies and cache."
            trigger:
              "Used for sites off of Google SRPs (Search Result Pages) only "
              "for Lite mode users when the feature is enabled."
            data: "None."
            destination: WEBSITE
          }
          policy {
            cookies_allowed: NO
            setting:
              "Users can control Lite mode on Android via the settings menu. "
              "Lite mode is not available on iOS, and on desktop only for "
              "developer testing."
            policy_exception_justification: "Not implemented."
        })");

  page_->url_loader_ =
      network::SimpleURLLoader::Create(std::move(request), traffic_annotation);

  // base::Unretained is safe because |page_->url_loader_| is owned by |this|.
  page_->url_loader_->SetOnRedirectCallback(
      base::BindRepeating(&IsolatedPrerenderTabHelper::OnPrefetchRedirect,
                          base::Unretained(this), url));
  page_->url_loader_->SetAllowHttpErrorResults(true);
  page_->url_loader_->SetTimeoutDuration(IsolatedPrefetchTimeoutDuration());
  page_->url_loader_->DownloadToString(
      GetURLLoaderFactory(),
      base::BindOnce(&IsolatedPrerenderTabHelper::OnPrefetchComplete,
                     base::Unretained(this), url, isolation_info),
      1024 * 1024 * 5 /* 5MB */);
}

void IsolatedPrerenderTabHelper::OnPrefetchRedirect(
    const GURL& original_url,
    const net::RedirectInfo& redirect_info,
    const network::mojom::URLResponseHead& response_head,
    std::vector<std::string>* removed_headers) {
  DCHECK(PrefetchingActive());

  page_->srp_metrics_->prefetch_total_redirect_count_++;

  // Copy the position ordering when there is a redirect so the metrics don't
  // miss out on redirects.
  auto position_iter = page_->original_prediction_ordering_.find(original_url);
  if (position_iter != page_->original_prediction_ordering_.end()) {
    page_->original_prediction_ordering_.emplace(redirect_info.new_url,
                                                 position_iter->second);
  }

  // Run the new URL through all the eligibility checks. In the mean time,
  // continue on with other Prefetches.
  CheckEligibilityOfURL(
      profile_, redirect_info.new_url,
      base::BindOnce(&IsolatedPrerenderTabHelper::OnGotEligibilityResult,
                     weak_factory_.GetWeakPtr()));

  // Cancels the current request.
  Prefetch();
}

void IsolatedPrerenderTabHelper::OnPrefetchComplete(
    const GURL& url,
    const net::IsolationInfo& isolation_info,
    std::unique_ptr<std::string> body) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  DCHECK(PrefetchingActive());

  base::UmaHistogramSparse("IsolatedPrerender.Prefetch.Mainframe.NetError",
                           std::abs(page_->url_loader_->NetError()));

  if (page_->url_loader_->NetError() != net::OK) {
    OnPrefetchStatusUpdate(url, PrefetchStatus::kPrefetchFailedNetError);
  }

  if (page_->url_loader_->NetError() == net::OK && body &&
      page_->url_loader_->ResponseInfo()) {
    network::mojom::URLResponseHeadPtr head =
        page_->url_loader_->ResponseInfo()->Clone();

    DCHECK(!head->proxy_server.is_direct());

    HandlePrefetchResponse(url, isolation_info, std::move(head),
                           std::move(body));
  }
  Prefetch();
}

void IsolatedPrerenderTabHelper::HandlePrefetchResponse(
    const GURL& url,
    const net::IsolationInfo& isolation_info,
    network::mojom::URLResponseHeadPtr head,
    std::unique_ptr<std::string> body) {
  DCHECK(!head->was_fetched_via_cache);

  if (!head->headers)
    return;

  UMA_HISTOGRAM_COUNTS_10M("IsolatedPrerender.Prefetch.Mainframe.BodyLength",
                           body->size());

  base::Optional<base::TimeDelta> total_time = GetTotalPrefetchTime(head.get());
  if (total_time) {
    UMA_HISTOGRAM_CUSTOM_TIMES("IsolatedPrerender.Prefetch.Mainframe.TotalTime",
                               *total_time,
                               base::TimeDelta::FromMilliseconds(10),
                               base::TimeDelta::FromSeconds(30), 100);
  }

  base::Optional<base::TimeDelta> connect_time =
      GetPrefetchConnectTime(head.get());
  if (connect_time) {
    UMA_HISTOGRAM_TIMES("IsolatedPrerender.Prefetch.Mainframe.ConnectTime",
                        *connect_time);
  }

  int response_code = head->headers->response_code();

  base::UmaHistogramSparse("IsolatedPrerender.Prefetch.Mainframe.RespCode",
                           response_code);

  if (response_code < 200 || response_code >= 300) {
    OnPrefetchStatusUpdate(url, PrefetchStatus::kPrefetchFailedNon2XX);
    for (auto& observer : observer_list_) {
      observer.OnPrefetchCompletedWithError(url, response_code);
    }
    return;
  }

  if (head->mime_type != "text/html") {
    OnPrefetchStatusUpdate(url, PrefetchStatus::kPrefetchFailedNotHTML);
    return;
  }

  std::unique_ptr<PrefetchedMainframeResponseContainer> response =
      std::make_unique<PrefetchedMainframeResponseContainer>(
          isolation_info, std::move(head), std::move(body));
  page_->prefetched_responses_.emplace(url, std::move(response));
  page_->srp_metrics_->prefetch_successful_count_++;

  OnPrefetchStatusUpdate(url, PrefetchStatus::kPrefetchSuccessful);

  MaybeDoNoStatePrefetch(url);

  for (auto& observer : observer_list_) {
    observer.OnPrefetchCompletedSuccessfully(url);
  }
}

void IsolatedPrerenderTabHelper::MaybeDoNoStatePrefetch(const GURL& url) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);

  if (!IsolatedPrerenderNoStatePrefetchSubresources()) {
    return;
  }

  page_->urls_to_no_state_prefetch_.push_back(url);
  DoNoStatePrefetch();
}

void IsolatedPrerenderTabHelper::DoNoStatePrefetch() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);

  if (page_->urls_to_no_state_prefetch_.empty()) {
    return;
  }

  // Ensure there is not an active navigation.
  if (web_contents()->GetController().GetPendingEntry()) {
    return;
  }

  base::Optional<size_t> max_attempts =
      IsolatedPrerenderMaximumNumberOfNoStatePrefetchAttempts();
  if (max_attempts.has_value() &&
      page_->number_of_no_state_prefetch_attempts_ >= max_attempts.value()) {
    return;
  }

  prerender::PrerenderManager* prerender_manager =
      prerender::PrerenderManagerFactory::GetForBrowserContext(profile_);
  if (!prerender_manager) {
    return;
  }

  IsolatedPrerenderService* service =
      IsolatedPrerenderServiceFactory::GetForProfile(profile_);
  if (!service) {
    return;
  }

  GURL url = page_->urls_to_no_state_prefetch_[0];

  // Don't start another NSP until the previous one finishes.
  {
    IsolatedPrerenderSubresourceManager* manager =
        service->GetSubresourceManagerForURL(url);
    if (manager && manager->has_nsp_handle()) {
      return;
    }
  }

  // The manager must be created here so that the mainframe response can be
  // given to the URLLoaderInterceptor in this call stack, but may be destroyed
  // before the end of the method if the handle is not created.
  IsolatedPrerenderSubresourceManager* manager =
      service->OnAboutToNoStatePrefetch(url, CopyPrefetchResponseForNSP(url));
  manager->SetCreateIsolatedLoaderFactoryCallback(base::BindRepeating(
      &IsolatedPrerenderTabHelper::CreateNewURLLoaderFactory,
      weak_factory_.GetWeakPtr()));

  content::SessionStorageNamespace* session_storage_namespace =
      web_contents()->GetController().GetDefaultSessionStorageNamespace();
  gfx::Size size = web_contents()->GetContainerBounds().size();

  std::unique_ptr<prerender::PrerenderHandle> handle =
      prerender_manager->AddIsolatedPrerender(url, session_storage_namespace,
                                              size);

  if (!handle) {
    // Clean up the prefetch response in |service| since it wasn't used.
    service->DestroySubresourceManagerForURL(url);
    // Don't use |manager| again!

    // Try the next URL.
    page_->urls_to_no_state_prefetch_.erase(
        page_->urls_to_no_state_prefetch_.begin());
    DoNoStatePrefetch();
    return;
  }

  manager->ManageNoStatePrefetch(
      std::move(handle),
      base::BindOnce(&IsolatedPrerenderTabHelper::OnPrerenderDone,
                     weak_factory_.GetWeakPtr(), url));

  page_->number_of_no_state_prefetch_attempts_++;
}

void IsolatedPrerenderTabHelper::OnPrerenderDone(const GURL& url) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  DCHECK(!page_->urls_to_no_state_prefetch_.empty());
  DCHECK_EQ(url, page_->urls_to_no_state_prefetch_[0]);

  page_->no_state_prefetched_urls_.push_back(
      page_->urls_to_no_state_prefetch_[0]);

  for (auto& observer : observer_list_) {
    observer.OnNoStatePrefetchFinished();
  }

  page_->urls_to_no_state_prefetch_.erase(
      page_->urls_to_no_state_prefetch_.begin());

  DoNoStatePrefetch();
}

void IsolatedPrerenderTabHelper::OnPredictionUpdated(
    const base::Optional<NavigationPredictorKeyedService::Prediction>
        prediction) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  if (!IsolatedPrerenderIsEnabled()) {
    return;
  }

  // DataSaver must be enabled by the user to use this feature.
  if (!data_reduction_proxy::DataReductionProxySettings::
          IsDataSaverEnabledByUser(profile_->IsOffTheRecord(),
                                   profile_->GetPrefs())) {
    return;
  }

  // This checks whether the user has enabled pre* actions in the settings UI.
  if (!chrome_browser_net::CanPreresolveAndPreconnectUI(profile_->GetPrefs())) {
    return;
  }

  if (!prediction.has_value()) {
    return;
  }

  if (prediction->prediction_source() !=
      NavigationPredictorKeyedService::PredictionSource::
          kAnchorElementsParsedFromWebPage) {
    return;
  }

  if (prediction.value().web_contents() != web_contents()) {
    // We only care about predictions in this tab.
    return;
  }

  const base::Optional<GURL>& source_document_url =
      prediction->source_document_url();

  if (!source_document_url || source_document_url->is_empty())
    return;

  if (!google_util::IsGoogleSearchUrl(source_document_url.value())) {
    return;
  }

  // It's very likely we'll prefetch something at this point, so inform PLM to
  // start tracking metrics.
  InformPLMOfLikelyPrefetching(web_contents());

  page_->srp_metrics_->predicted_urls_count_ +=
      prediction.value().sorted_predicted_urls().size();

  // It is possible, since it is not stipulated by the API contract, that the
  // navigation predictor will issue multiple predictions during a single page
  // load. Additional predictions should be treated as appending to the ordering
  // of previous predictions.
  size_t original_prediction_ordering_starting_size =
      page_->original_prediction_ordering_.size();

  for (size_t i = 0; i < prediction.value().sorted_predicted_urls().size();
       ++i) {
    GURL url = prediction.value().sorted_predicted_urls()[i];

    size_t url_index = original_prediction_ordering_starting_size + i;
    page_->original_prediction_ordering_.emplace(url, url_index);

    CheckEligibilityOfURL(
        profile_, url,
        base::BindOnce(&IsolatedPrerenderTabHelper::OnGotEligibilityResult,
                       weak_factory_.GetWeakPtr()));
  }
}

// static
void IsolatedPrerenderTabHelper::CheckEligibilityOfURL(
    Profile* profile,
    const GURL& url,
    OnEligibilityResultCallback result_callback) {
  if (!data_reduction_proxy::DataReductionProxySettings::
          IsDataSaverEnabledByUser(profile->IsOffTheRecord(),
                                   profile->GetPrefs())) {
    std::move(result_callback).Run(url, false, base::nullopt);
    return;
  }

  if (google_util::IsGoogleAssociatedDomainUrl(url)) {
    std::move(result_callback)
        .Run(url, false, PrefetchStatus::kPrefetchNotEligibleGoogleDomain);
    return;
  }

  if (url.HostIsIPAddress()) {
    std::move(result_callback)
        .Run(url, false, PrefetchStatus::kPrefetchNotEligibleHostIsIPAddress);
    return;
  }

  if (!url.SchemeIs(url::kHttpsScheme)) {
    std::move(result_callback)
        .Run(url, false, PrefetchStatus::kPrefetchNotEligibleSchemeIsNotHttps);
    return;
  }

  content::StoragePartition* default_storage_partition =
      content::BrowserContext::GetDefaultStoragePartition(profile);

  // Only the default storage partition is supported since that is the only
  // place where service workers are observed by
  // |IsolatedPrerenderServiceWorkersObserver|.
  if (default_storage_partition !=
      content::BrowserContext::GetStoragePartitionForSite(
          profile, url,
          /*can_create=*/false)) {
    std::move(result_callback)
        .Run(url, false,
             PrefetchStatus::kPrefetchNotEligibleNonDefaultStoragePartition);
    return;
  }

  IsolatedPrerenderService* isolated_prerender_service =
      IsolatedPrerenderServiceFactory::GetForProfile(profile);
  if (!isolated_prerender_service) {
    std::move(result_callback).Run(url, false, base::nullopt);
    return;
  }

  base::Optional<bool> site_has_service_worker =
      isolated_prerender_service->service_workers_observer()
          ->IsServiceWorkerRegisteredForOrigin(url::Origin::Create(url));
  if (!site_has_service_worker.has_value() || site_has_service_worker.value()) {
    std::move(result_callback)
        .Run(url, false,
             PrefetchStatus::kPrefetchNotEligibleUserHasServiceWorker);
    return;
  }

  net::CookieOptions options = net::CookieOptions::MakeAllInclusive();
  default_storage_partition->GetCookieManagerForBrowserProcess()->GetCookieList(
      url, options,
      base::BindOnce(&OnGotCookieList, url, std::move(result_callback)));
}

void IsolatedPrerenderTabHelper::OnGotEligibilityResult(
    const GURL& url,
    bool eligible,
    base::Optional<IsolatedPrerenderTabHelper::PrefetchStatus> status) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);

  if (!eligible) {
    if (status) {
      OnPrefetchStatusUpdate(url, status.value());
    }
    return;
  }

  // TODO(robertogden): Consider adding redirect URLs to the front of the list.
  page_->urls_to_prefetch_.push_back(url);
  page_->srp_metrics_->prefetch_eligible_count_++;
  OnPrefetchStatusUpdate(url, PrefetchStatus::kPrefetchNotStarted);

  if (page_->original_prediction_ordering_.find(url) !=
      page_->original_prediction_ordering_.end()) {
    size_t original_prediction_index =
        page_->original_prediction_ordering_.find(url)->second;
    // Check that we won't go above the allowable size.
    if (original_prediction_index <
        sizeof(page_->srp_metrics_->ordered_eligible_pages_bitmask_) * 8) {
      page_->srp_metrics_->ordered_eligible_pages_bitmask_ |=
          1 << original_prediction_index;
    }
  }

  if (!PrefetchingActive()) {
    Prefetch();
  }
}

network::mojom::URLLoaderFactory*
IsolatedPrerenderTabHelper::GetURLLoaderFactory() {
  if (!page_->isolated_url_loader_factory_) {
    CreateIsolatedURLLoaderFactory();
  }
  DCHECK(page_->isolated_url_loader_factory_);
  return page_->isolated_url_loader_factory_.get();
}

void IsolatedPrerenderTabHelper::CreateNewURLLoaderFactory(
    mojo::PendingReceiver<network::mojom::URLLoaderFactory> pending_receiver,
    base::Optional<net::IsolationInfo> isolation_info) {
  DCHECK(page_->isolated_network_context_);

  auto factory_params = network::mojom::URLLoaderFactoryParams::New();
  factory_params->process_id = network::mojom::kBrowserProcessId;
  factory_params->is_trusted = true;
  factory_params->is_corb_enabled = false;
  if (isolation_info) {
    factory_params->isolation_info = *isolation_info;
  }

  page_->isolated_network_context_->CreateURLLoaderFactory(
      std::move(pending_receiver), std::move(factory_params));
}

void IsolatedPrerenderTabHelper::CreateIsolatedURLLoaderFactory() {
  page_->isolated_network_context_.reset();
  page_->isolated_url_loader_factory_.reset();

  IsolatedPrerenderService* isolated_prerender_service =
      IsolatedPrerenderServiceFactory::GetForProfile(profile_);

  auto context_params = network::mojom::NetworkContextParams::New();
  context_params->context_name = "IsolatedPrerender";
  context_params->user_agent = ::GetUserAgent();
  context_params->accept_language = net::HttpUtil::GenerateAcceptLanguageHeader(
      profile_->GetPrefs()->GetString(language::prefs::kAcceptLanguages));
  context_params->initial_custom_proxy_config =
      isolated_prerender_service->proxy_configurator()
          ->CreateCustomProxyConfig();
  context_params->cert_verifier_params = content::GetCertVerifierParams(
      network::mojom::CertVerifierCreationParams::New());
  context_params->cors_exempt_header_list = {
      content::kCorsExemptPurposeHeaderName};

  context_params->http_cache_enabled = true;
  DCHECK(!context_params->http_cache_path);

  // Also register a client config receiver so that updates to the set of proxy
  // hosts or proxy headers will be updated.
  mojo::Remote<network::mojom::CustomProxyConfigClient> config_client;
  context_params->custom_proxy_config_client_receiver =
      config_client.BindNewPipeAndPassReceiver();
  isolated_prerender_service->proxy_configurator()->AddCustomProxyConfigClient(
      std::move(config_client));

  content::GetNetworkService()->CreateNetworkContext(
      page_->isolated_network_context_.BindNewPipeAndPassReceiver(),
      std::move(context_params));

  mojo::PendingRemote<network::mojom::URLLoaderFactory> isolated_factory_remote;

  CreateNewURLLoaderFactory(
      isolated_factory_remote.InitWithNewPipeAndPassReceiver(), base::nullopt);

  page_->isolated_url_loader_factory_ = network::SharedURLLoaderFactory::Create(
      std::make_unique<network::WrapperPendingSharedURLLoaderFactory>(
          std::move(isolated_factory_remote)));
}

WEB_CONTENTS_USER_DATA_KEY_IMPL(IsolatedPrerenderTabHelper)
