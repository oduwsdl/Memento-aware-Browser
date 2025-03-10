// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/frame_host/mixed_content_navigation_throttle.h"

#include "base/memory/ptr_util.h"
#include "base/metrics/histogram_macros.h"
#include "base/stl_util.h"
#include "content/browser/frame_host/frame_tree.h"
#include "content/browser/frame_host/frame_tree_node.h"
#include "content/browser/frame_host/navigation_request.h"
#include "content/browser/frame_host/render_frame_host_delegate.h"
#include "content/browser/frame_host/render_frame_host_impl.h"
#include "content/browser/renderer_host/render_view_host_impl.h"
#include "content/common/frame_messages.h"
#include "content/public/browser/content_browser_client.h"
#include "content/public/common/content_client.h"
#include "content/public/common/navigation_policy.h"
#include "content/public/common/origin_util.h"
#include "content/public/common/web_preferences.h"
#include "net/base/url_util.h"
#include "third_party/blink/public/common/security_context/insecure_request_policy.h"
#include "third_party/blink/public/mojom/fetch/fetch_api_request.mojom.h"
#include "third_party/blink/public/mojom/security_context/insecure_request_policy.mojom.h"

#include "url/gurl.h"
#include "url/origin.h"
#include "url/url_constants.h"
#include "url/url_util.h"

namespace content {

namespace {

// Should return the same value as SchemeRegistry::shouldTreatURLSchemeAsSecure.
bool IsSecureScheme(const std::string& scheme) {
  return base::Contains(url::GetSecureSchemes(), scheme);
}

// Should return the same value as SecurityOrigin::isLocal and
// SchemeRegistry::shouldTreatURLSchemeAsCorsEnabled.
bool ShouldTreatURLSchemeAsCorsEnabled(const GURL& url) {
  return base::Contains(url::GetCorsEnabledSchemes(), url.scheme());
}

// Should return the same value as the resource URL checks assigned to
// |isAllowed| made inside MixedContentChecker::isMixedContent.
bool IsUrlPotentiallySecure(const GURL& url) {
  // blob: and filesystem: URLs never hit the network, and access is restricted
  // to same-origin contexts, so they are not blocked.
  return url.SchemeIs(url::kBlobScheme) ||
         url.SchemeIs(url::kFileSystemScheme) || IsOriginSecure(url) ||
         IsPotentiallyTrustworthyOrigin(url::Origin::Create(url));
}

// This method should return the same results as
// SchemeRegistry::shouldTreatURLSchemeAsRestrictingMixedContent.
bool DoesOriginSchemeRestrictMixedContent(const url::Origin& origin) {
  return origin.scheme() == url::kHttpsScheme;
}

void UpdateRendererOnMixedContentFound(NavigationRequest* navigation_request,
                                       const GURL& mixed_content_url,
                                       bool was_allowed,
                                       bool for_redirect) {
  // TODO(carlosk): the root node should never be considered as being/having
  // mixed content for now. Once/if the browser should also check form submits
  // for mixed content than this will be allowed to happen and this DCHECK
  // should be updated.
  DCHECK(navigation_request->frame_tree_node()->parent());
  RenderFrameHost* rfh =
      navigation_request->frame_tree_node()->current_frame_host();
  FrameMsg_MixedContentFound_Params params;
  params.main_resource_url = mixed_content_url;
  params.mixed_content_url = navigation_request->GetURL();
  params.request_context_type = navigation_request->request_context_type();
  params.request_destination = navigation_request->request_destination();
  params.was_allowed = was_allowed;
  DCHECK(!navigation_request->GetRedirectChain().empty());
  params.url_before_redirects = navigation_request->GetRedirectChain()[0];
  params.had_redirect = for_redirect;
  params.source_location =
      *(navigation_request->common_params().source_location.get());

  rfh->Send(new FrameMsg_MixedContentFound(rfh->GetRoutingID(), params));
}

}  // namespace

// static
std::unique_ptr<NavigationThrottle>
MixedContentNavigationThrottle::CreateThrottleForNavigation(
    NavigationHandle* navigation_handle) {
  return std::make_unique<MixedContentNavigationThrottle>(navigation_handle);
}

MixedContentNavigationThrottle::MixedContentNavigationThrottle(
    NavigationHandle* navigation_handle)
    : NavigationThrottle(navigation_handle) {}

MixedContentNavigationThrottle::~MixedContentNavigationThrottle() {}

NavigationThrottle::ThrottleCheckResult
MixedContentNavigationThrottle::WillStartRequest() {
  bool should_block = ShouldBlockNavigation(false);
  return should_block ? CANCEL : PROCEED;
}

NavigationThrottle::ThrottleCheckResult
MixedContentNavigationThrottle::WillRedirectRequest() {
  // Upon redirects the same checks are to be executed as for requests.
  bool should_block = ShouldBlockNavigation(true);
  return should_block ? CANCEL : PROCEED;
}

NavigationThrottle::ThrottleCheckResult
MixedContentNavigationThrottle::WillProcessResponse() {
  // TODO(carlosk): At this point we are about to process the request response.
  // So if we ever need to, here/now it is a good moment to check for the final
  // attained security level of the connection. For instance, does it use an
  // outdated protocol? The implementation should be based off
  // MixedContentChecker::handleCertificateError. See https://crbug.com/576270.
  return PROCEED;
}

const char* MixedContentNavigationThrottle::GetNameForLogging() {
  return "MixedContentNavigationThrottle";
}

// Based off of MixedContentChecker::shouldBlockFetch.
bool MixedContentNavigationThrottle::ShouldBlockNavigation(bool for_redirect) {

  NavigationRequest* request = NavigationRequest::From(navigation_handle());
  FrameTreeNode* node = request->frame_tree_node();

  // Find the parent frame where mixed content is characterized, if any.
  RenderFrameHostImpl* mixed_content_frame =
      InWhichFrameIsContentMixed(node, request->GetURL());


  if (!mixed_content_frame) {
    MaybeSendBlinkFeatureUsageReport();
    return false;
  }

  // From this point on we know this is not a main frame navigation and that
  // there is mixed content. Now let's decide if it's OK to proceed with it.

  ReportBasicMixedContentFeatures(request->request_context_type(),
                                  request->mixed_content_context_type());

  // If we're in strict mode, we'll automagically fail everything, and
  // intentionally skip the client/embedder checks in order to prevent degrading
  // the site's security UI.
  bool block_all_mixed_content =
      (mixed_content_frame->frame_tree_node()
           ->current_replication_state()
           .insecure_request_policy &
       blink::mojom::InsecureRequestPolicy::kBlockAllMixedContent) !=
      blink::mojom::InsecureRequestPolicy::kLeaveInsecureRequestsAlone;
  const WebPreferences& prefs =
      mixed_content_frame->render_view_host()->GetWebkitPreferences();
  bool strict_mode =
      prefs.strict_mixed_content_checking || block_all_mixed_content;

  blink::WebMixedContentContextType mixed_context_type =
      request->mixed_content_context_type();

  // Do not treat non-webby schemes as mixed content when loaded in subframes.
  // Navigations to non-webby schemes cannot return data to the browser, so
  // insecure content will not be run or displayed to the user as a result of
  // loading a non-webby scheme. It is potentially dangerous to navigate to a
  // non-webby scheme (e.g., the page could deliver a malicious payload to a
  // vulnerable native application), but loading a non-webby scheme is no more
  // dangerous in this respect than navigating the main frame to the non-webby
  // scheme directly. See https://crbug.com/621131.
  //
  // TODO(https://crbug.com/1030307): decide whether CORS-enabled is really the
  // right way to draw this distinction.
  if (!ShouldTreatURLSchemeAsCorsEnabled(request->GetURL())) {
    // Record non-webby mixed content to see if it is rare enough that it can be
    // gated behind an enterprise policy. This excludes URLs that are considered
    // potentially-secure such as blob: and filesystem:, which are special-cased
    // in IsUrlPotentiallySecure() and cause an early-return because of the
    // InWhichFrameIsContentMixed() check above.
    UMA_HISTOGRAM_BOOLEAN("SSL.NonWebbyMixedContentLoaded", true);
    return false;
  }

  bool allowed = false;
  RenderFrameHostDelegate* frame_host_delegate =
      node->current_frame_host()->delegate();
  switch (mixed_context_type) {
    case blink::WebMixedContentContextType::kOptionallyBlockable:
      allowed = !strict_mode;
      if (allowed) {
        frame_host_delegate->PassiveInsecureContentFound(request->GetURL());
        frame_host_delegate->DidDisplayInsecureContent();
      }
      break;

    case blink::WebMixedContentContextType::kBlockable: {
      // Note: from the renderer side implementation it seems like we don't need
      // to care about reporting
      // blink::UseCounter::BlockableMixedContentInSubframeBlocked because it is
      // only triggered for sub-resources which are not checked for in the
      // browser.
      bool should_ask_delegate =
          !strict_mode && (!prefs.strictly_block_blockable_mixed_content ||
                           prefs.allow_running_insecure_content);
      allowed =
          should_ask_delegate &&
          frame_host_delegate->ShouldAllowRunningInsecureContent(
              prefs.allow_running_insecure_content,
              mixed_content_frame->GetLastCommittedOrigin(), request->GetURL());
      if (allowed) {
        const GURL& origin_url =
            mixed_content_frame->GetLastCommittedOrigin().GetURL();
        frame_host_delegate->DidRunInsecureContent(origin_url,
                                                   request->GetURL());
        mixed_content_features_.insert(
            blink::mojom::WebFeature::kMixedContentBlockableAllowed);
      }
      break;
    }

    case blink::WebMixedContentContextType::kShouldBeBlockable:
      allowed = !strict_mode;
      if (allowed)
        frame_host_delegate->DidDisplayInsecureContent();
      break;

    case blink::WebMixedContentContextType::kNotMixedContent:
      NOTREACHED();
      break;
  };

  UpdateRendererOnMixedContentFound(request,
                                    mixed_content_frame->GetLastCommittedURL(),
                                    allowed, for_redirect);
  MaybeSendBlinkFeatureUsageReport();

  return !allowed;
}

// This method mirrors MixedContentChecker::inWhichFrameIsContentMixed but is
// implemented in a different form that seems more appropriate here.
RenderFrameHostImpl* MixedContentNavigationThrottle::InWhichFrameIsContentMixed(
    FrameTreeNode* node,
    const GURL& url) {
  // Main frame navigations cannot be mixed content.
  // TODO(carlosk): except for form submissions which might be supported in the
  // future.
  if (node->IsMainFrame())
    return nullptr;

  // There's no mixed content if any of these are true:
  // - The navigated URL is potentially secure.
  // - Neither the root nor parent frames have secure origins.
  // This next section diverges in how the Blink version is implemented but
  // should get to the same results. Especially where isMixedContent calls
  // exist, here they are partially fulfilled here  and partially replaced by
  // DoesOriginSchemeRestrictMixedContent.
  RenderFrameHostImpl* mixed_content_frame = nullptr;
  RenderFrameHostImpl* root = node->parent()->GetMainFrame();
  RenderFrameHostImpl* parent = node->parent();
  if (!IsUrlPotentiallySecure(url)) {
    // TODO(carlosk): we might need to check more than just the immediate parent
    // and the root. See https://crbug.com/623486.

    // Checks if the root and then the immediate parent frames' origins are
    // secure.
    if (DoesOriginSchemeRestrictMixedContent(root->GetLastCommittedOrigin()))
      mixed_content_frame = root;
    else if (DoesOriginSchemeRestrictMixedContent(
                 parent->GetLastCommittedOrigin())) {
      mixed_content_frame = parent;
    }
  }

  // Note: The code below should behave the same way as the two calls to
  // measureStricterVersionOfIsMixedContent from inside
  // MixedContentChecker::inWhichFrameIs.
  if (mixed_content_frame) {
    // We're currently only checking for mixed content in `https://*` contexts.
    // What about other "secure" contexts the SchemeRegistry knows about? We'll
    // use this method to measure the occurrence of non-webby mixed content to
    // make sure we're not breaking the world without realizing it.
    if (mixed_content_frame->GetLastCommittedOrigin().scheme() !=
        url::kHttpsScheme) {
      mixed_content_features_.insert(
          blink::mojom::WebFeature::
              kMixedContentInNonHTTPSFrameThatRestrictsMixedContent);
    }
  } else if (!IsOriginSecure(url) &&
             (IsSecureScheme(root->GetLastCommittedOrigin().scheme()) ||
              IsSecureScheme(parent->GetLastCommittedOrigin().scheme()))) {
    mixed_content_features_.insert(
        blink::mojom::WebFeature::
            kMixedContentInSecureFrameThatDoesNotRestrictMixedContent);
  }

  return mixed_content_frame;
}

void MixedContentNavigationThrottle::MaybeSendBlinkFeatureUsageReport() {
  if (!mixed_content_features_.empty()) {
    NavigationRequest* request = NavigationRequest::From(navigation_handle());
    RenderFrameHostImpl* rfh = request->frame_tree_node()->current_frame_host();
    rfh->GetAssociatedLocalFrame()->ReportBlinkFeatureUsage(
        std::vector<blink::mojom::WebFeature>(mixed_content_features_.begin(),
                                              mixed_content_features_.end()));
    mixed_content_features_.clear();
  }
}

// Based off of MixedContentChecker::count.
void MixedContentNavigationThrottle::ReportBasicMixedContentFeatures(
    blink::mojom::RequestContextType request_context_type,
    blink::WebMixedContentContextType mixed_content_context_type) {
  mixed_content_features_.insert(
      blink::mojom::WebFeature::kMixedContentPresent);

  // Report any blockable content.
  if (mixed_content_context_type ==
      blink::WebMixedContentContextType::kBlockable) {
    mixed_content_features_.insert(
        blink::mojom::WebFeature::kMixedContentBlockable);
    return;
  }

  // Note: as there's no mixed content checks for sub-resources on the browser
  // side there should only be a subset of RequestContextType values that could
  // ever be found here.
  blink::mojom::WebFeature feature;
  switch (request_context_type) {
    case blink::mojom::RequestContextType::INTERNAL:
      feature = blink::mojom::WebFeature::kMixedContentInternal;
      break;
    case blink::mojom::RequestContextType::PREFETCH:
      feature = blink::mojom::WebFeature::kMixedContentPrefetch;
      break;

    case blink::mojom::RequestContextType::AUDIO:
    case blink::mojom::RequestContextType::DOWNLOAD:
    case blink::mojom::RequestContextType::FAVICON:
    case blink::mojom::RequestContextType::IMAGE:
    case blink::mojom::RequestContextType::PLUGIN:
    case blink::mojom::RequestContextType::VIDEO:
    default:
      NOTREACHED() << "RequestContextType has value " << request_context_type
                   << " and has WebMixedContentContextType of "
                   << static_cast<int>(mixed_content_context_type);
      return;
  }
  mixed_content_features_.insert(feature);
}

// static
bool MixedContentNavigationThrottle::IsMixedContentForTesting(
    const GURL& origin_url,
    const GURL& url) {
  const url::Origin origin = url::Origin::Create(origin_url);
  return !IsUrlPotentiallySecure(url) &&
         DoesOriginSchemeRestrictMixedContent(origin);
}

}  // namespace content
