// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/web_origin_trials.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#include "third_party/blink/public/web/web_origin_trials.h"

#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/origin_trials/origin_trials.h"
#include "third_party/blink/public/platform/web_string.h"
#include "third_party/blink/public/web/web_document.h"

namespace blink {

bool WebOriginTrials::isTrialEnabled(const WebDocument* web_document, const WebString& trial) {
  if (!web_document) return false;
  if (!origin_trials::IsTrialValid(trial))
    return false;
  for (OriginTrialFeature feature : origin_trials::FeaturesForTrial(trial)) {
    switch (feature) {
      case OriginTrialFeature::kAllowSyncXHRInPageDismissal:
        if (!RuntimeEnabledFeatures::AllowSyncXHRInPageDismissalEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kAppCache:
        if (!RuntimeEnabledFeatures::AppCacheEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kAutoPictureInPicture:
        if (!RuntimeEnabledFeatures::AutoPictureInPictureEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kCacheStorageCodeCacheHint:
        if (!RuntimeEnabledFeatures::CacheStorageCodeCacheHintEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kCookieStoreDocument:
        if (!RuntimeEnabledFeatures::CookieStoreDocumentEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kCookieStoreWorker:
        if (!RuntimeEnabledFeatures::CookieStoreWorkerEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kCustomElementsV0:
        if (!RuntimeEnabledFeatures::CustomElementsV0Enabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kDisableHardwareNoiseSuppression:
        if (!RuntimeEnabledFeatures::DisableHardwareNoiseSuppressionEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kDocumentPolicy:
        if (!RuntimeEnabledFeatures::DocumentPolicyEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kExperimentalAutoplayDynamicDelegation:
        if (!RuntimeEnabledFeatures::ExperimentalAutoplayDynamicDelegationEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kExperimentalIsInputPending:
        if (!RuntimeEnabledFeatures::ExperimentalIsInputPendingEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kExperimentalJSProfiler:
        if (!RuntimeEnabledFeatures::ExperimentalJSProfilerEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kFeaturePolicyReporting:
        if (!RuntimeEnabledFeatures::FeaturePolicyReportingEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kFileHandling:
        if (!RuntimeEnabledFeatures::FileHandlingEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kForceLoadAtTop:
        if (!RuntimeEnabledFeatures::ForceLoadAtTopEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kHrefTranslate:
        if (!RuntimeEnabledFeatures::HrefTranslateEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kHTMLImports:
        if (!RuntimeEnabledFeatures::HTMLImportsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kIdleDetection:
        if (!RuntimeEnabledFeatures::IdleDetectionEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kLegacyNativeFileSystem:
        if (!RuntimeEnabledFeatures::LegacyNativeFileSystemEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kMeasureMemory:
        if (!RuntimeEnabledFeatures::MeasureMemoryEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kNativeFileSystem:
        if (!RuntimeEnabledFeatures::NativeFileSystemEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kNotificationTriggers:
        if (!RuntimeEnabledFeatures::NotificationTriggersEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginIsolationHeader:
        if (!RuntimeEnabledFeatures::OriginIsolationHeaderEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginTrialsSampleAPI:
        if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginTrialsSampleAPIDeprecation:
        if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIDeprecationEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginTrialsSampleAPIImplied:
        if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIImpliedEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS:
        if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIInvalidOSEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginTrialsSampleAPINavigation:
        if (!RuntimeEnabledFeatures::OriginTrialsSampleAPINavigationEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginTrialsSampleAPIThirdParty:
        if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIThirdPartyEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPageFreezeOptIn:
        if (!RuntimeEnabledFeatures::PageFreezeOptInEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPageFreezeOptOut:
        if (!RuntimeEnabledFeatures::PageFreezeOptOutEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPerMethodCanMakePaymentQuota:
        if (!RuntimeEnabledFeatures::PerMethodCanMakePaymentQuotaEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPNaCl:
        if (!RuntimeEnabledFeatures::PNaClEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPointerLockOptions:
        if (!RuntimeEnabledFeatures::PointerLockOptionsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPortals:
        if (!RuntimeEnabledFeatures::PortalsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPriorityHints:
        if (!RuntimeEnabledFeatures::PriorityHintsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kQuicTransport:
        if (!RuntimeEnabledFeatures::QuicTransportEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kRtcAudioJitterBufferMaxPackets:
        if (!RuntimeEnabledFeatures::RtcAudioJitterBufferMaxPacketsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kRtcAudioJitterBufferRtxHandling:
        if (!RuntimeEnabledFeatures::RtcAudioJitterBufferRtxHandlingEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kRTCIceTransportExtension:
        if (!RuntimeEnabledFeatures::RTCIceTransportExtensionEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kRTCInsertableStreams:
        if (!RuntimeEnabledFeatures::RTCInsertableStreamsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kRTCQuicTransport:
        if (!RuntimeEnabledFeatures::RTCQuicTransportEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay:
        if (!RuntimeEnabledFeatures::RTCStatsRelativePacketArrivalDelayEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kSerial:
        if (!RuntimeEnabledFeatures::SerialEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kShadowDOMV0:
        if (!RuntimeEnabledFeatures::ShadowDOMV0Enabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kSignatureBasedIntegrity:
        if (!RuntimeEnabledFeatures::SignatureBasedIntegrityEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kSignedExchangeSubresourcePrefetch:
        if (!RuntimeEnabledFeatures::SignedExchangeSubresourcePrefetchEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kSkipAd:
        if (!RuntimeEnabledFeatures::SkipAdEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kTextFragmentIdentifiers:
        if (!RuntimeEnabledFeatures::TextFragmentIdentifiersEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kTouchEventFeatureDetection:
        if (!RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kTransferableStreams:
        if (!RuntimeEnabledFeatures::TransferableStreamsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kTrustTokens:
        if (!RuntimeEnabledFeatures::TrustTokensEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kUnoptimizedImagePolicies:
        if (!RuntimeEnabledFeatures::UnoptimizedImagePoliciesEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kUnsizedMediaPolicy:
        if (!RuntimeEnabledFeatures::UnsizedMediaPolicyEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kWakeLock:
        if (!RuntimeEnabledFeatures::WakeLockEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kWebAssemblySimd:
        if (!RuntimeEnabledFeatures::WebAssemblySimdEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kWebAssemblyThreads:
        if (!RuntimeEnabledFeatures::WebAssemblyThreadsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kWebNFC:
        if (!RuntimeEnabledFeatures::WebNFCEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kWebScheduler:
        if (!RuntimeEnabledFeatures::WebSchedulerEnabled(*web_document))
          return false;
        break;
      default:
        break;
    }
  }
  return true;
}


} // namespace blink
