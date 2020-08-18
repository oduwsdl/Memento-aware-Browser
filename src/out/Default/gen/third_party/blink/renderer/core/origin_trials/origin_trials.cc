// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/origin_trials.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#include "third_party/blink/renderer/core/origin_trials/origin_trials.h"

#include <algorithm>
#include <array>
#include <iterator>
#include "base/stl_util.h"
#include "third_party/blink/renderer/core/origin_trials/origin_trial_context.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

namespace {

static constexpr size_t kMaxFeaturesPerTrial = 3;
static constexpr struct {
  const char* trial_name;
  unsigned feature_count;
  std::array<OriginTrialFeature, kMaxFeaturesPerTrial> features;
} kTrialToFeaturesMap[] = {
    { "FeaturePolicyReporting", 1, {OriginTrialFeature::kFeaturePolicyReporting, } },
    { "ForceTouchEventFeatureDetectionForInspector", 1, {OriginTrialFeature::kTouchEventFeatureDetection, } },
    { "TrustTokens", 1, {OriginTrialFeature::kTrustTokens, } },
    { "MeasureMemory", 1, {OriginTrialFeature::kMeasureMemory, } },
    { "PageFreezeOptIn", 1, {OriginTrialFeature::kPageFreezeOptIn, } },
    { "DocumentPolicy", 1, {OriginTrialFeature::kDocumentPolicy, } },
    { "PerMethodCanMakePaymentQuota", 1, {OriginTrialFeature::kPerMethodCanMakePaymentQuota, } },
    { "PointerLockOptions", 1, {OriginTrialFeature::kPointerLockOptions, } },
    { "WebComponentsV0", 3, {OriginTrialFeature::kCustomElementsV0,OriginTrialFeature::kHTMLImports,OriginTrialFeature::kShadowDOMV0, } },
    { "DisableHardwareNoiseSuppression", 1, {OriginTrialFeature::kDisableHardwareNoiseSuppression, } },
    { "Frobulate", 1, {OriginTrialFeature::kOriginTrialsSampleAPI, } },
    { "HrefTranslate", 1, {OriginTrialFeature::kHrefTranslate, } },
    { "RTCInsertableStreams", 2, {OriginTrialFeature::kRTCInsertableStreams,OriginTrialFeature::kTransferableStreams, } },
    { "PageFreezeOptOut", 1, {OriginTrialFeature::kPageFreezeOptOut, } },
    { "PriorityHints", 1, {OriginTrialFeature::kPriorityHints, } },
    { "FileHandling", 1, {OriginTrialFeature::kFileHandling, } },
    { "FrobulateDeprecation", 1, {OriginTrialFeature::kOriginTrialsSampleAPIDeprecation, } },
    { "RtcAudioJitterBufferMaxPackets", 1, {OriginTrialFeature::kRtcAudioJitterBufferMaxPackets, } },
    { "UnsizedMediaPolicy", 1, {OriginTrialFeature::kUnsizedMediaPolicy, } },
    { "SkipAd", 1, {OriginTrialFeature::kSkipAd, } },
    { "ForceLoadAtTop", 1, {OriginTrialFeature::kForceLoadAtTop, } },
    { "AutoPictureInPicture", 1, {OriginTrialFeature::kAutoPictureInPicture, } },
    { "SignatureBasedIntegrity", 1, {OriginTrialFeature::kSignatureBasedIntegrity, } },
    { "FrobulateImplied", 1, {OriginTrialFeature::kOriginTrialsSampleAPIImplied, } },
    { "ExperimentalJSProfiler", 1, {OriginTrialFeature::kExperimentalJSProfiler, } },
    { "WebNFC", 1, {OriginTrialFeature::kWebNFC, } },
    { "RTCQuicTransport", 2, {OriginTrialFeature::kRTCIceTransportExtension,OriginTrialFeature::kRTCQuicTransport, } },
    { "SignedExchangeSubresourcePrefetch", 1, {OriginTrialFeature::kSignedExchangeSubresourcePrefetch, } },
    { "ExperimentalAutoplayDynamicDelegation", 1, {OriginTrialFeature::kExperimentalAutoplayDynamicDelegation, } },
    { "NotificationTriggers", 1, {OriginTrialFeature::kNotificationTriggers, } },
    { "TextFragmentIdentifiers", 1, {OriginTrialFeature::kTextFragmentIdentifiers, } },
    { "QuicTransport", 1, {OriginTrialFeature::kQuicTransport, } },
    { "Portals", 1, {OriginTrialFeature::kPortals, } },
    { "CacheStorageCodeCacheHint", 1, {OriginTrialFeature::kCacheStorageCodeCacheHint, } },
    { "WebScheduler", 1, {OriginTrialFeature::kWebScheduler, } },
    { "AllowSyncXHRInPageDismissal", 1, {OriginTrialFeature::kAllowSyncXHRInPageDismissal, } },
    { "CookieStore", 2, {OriginTrialFeature::kCookieStoreDocument,OriginTrialFeature::kCookieStoreWorker, } },
    { "FrobulateInvalidOS", 1, {OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS, } },
    { "WebAssemblyThreads", 1, {OriginTrialFeature::kWebAssemblyThreads, } },
    { "FrobulateThirdParty", 1, {OriginTrialFeature::kOriginTrialsSampleAPIThirdParty, } },
    { "PNaCl", 1, {OriginTrialFeature::kPNaCl, } },
    { "OriginIsolationHeader", 1, {OriginTrialFeature::kOriginIsolationHeader, } },
    { "ExperimentalIsInputPending", 1, {OriginTrialFeature::kExperimentalIsInputPending, } },
    { "IdleDetection", 1, {OriginTrialFeature::kIdleDetection, } },
    { "RtcAudioJitterBufferRtxHandling", 1, {OriginTrialFeature::kRtcAudioJitterBufferRtxHandling, } },
    { "WakeLock", 1, {OriginTrialFeature::kWakeLock, } },
    { "AppCache", 1, {OriginTrialFeature::kAppCache, } },
    { "RTCStatsRelativePacketArrivalDelay", 1, {OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay, } },
    { "FrobulateNavigation", 1, {OriginTrialFeature::kOriginTrialsSampleAPINavigation, } },
    { "WebAssemblySimd", 1, {OriginTrialFeature::kWebAssemblySimd, } },
    { "Serial", 1, {OriginTrialFeature::kSerial, } },
    { "UnoptimizedImagePolicies", 1, {OriginTrialFeature::kUnoptimizedImagePolicies, } },
    { "NativeFileSystem2", 2, {OriginTrialFeature::kLegacyNativeFileSystem,OriginTrialFeature::kNativeFileSystem, } },
    // For testing
    { "This trial does not exist", 1, { OriginTrialFeature::kNonExisting } },
};

} // namespace

bool origin_trials::IsTrialValid(const StringView& trial_name) {
  return std::any_of(
      std::begin(kTrialToFeaturesMap), std::end(kTrialToFeaturesMap),
      [&](const auto& entry) { return entry.trial_name == trial_name; });
}

bool origin_trials::IsTrialEnabledForInsecureContext(const StringView& trial_name) {
  static const char* const kEnabledForInsecureContext[] = {
      "WebComponentsV0",
      "FrobulateDeprecation",
  };
  return base::Contains(kEnabledForInsecureContext, trial_name);
}

bool origin_trials::IsTrialEnabledForThirdPartyOrigins(const StringView& trial_name) {
  static const char* const kEnabledForThirdPartyOrigins[] = {
      "FrobulateThirdParty",
  };
  return base::Contains(kEnabledForThirdPartyOrigins, trial_name);
}

OriginTrialType origin_trials::GetTrialType(OriginTrialFeature feature) {
  switch (feature) {
    case OriginTrialFeature::kCustomElementsV0:
      return OriginTrialType::kDeprecation;
    case OriginTrialFeature::kHTMLImports:
      return OriginTrialType::kDeprecation;
    case OriginTrialFeature::kOriginTrialsSampleAPIDeprecation:
      return OriginTrialType::kDeprecation;
    case OriginTrialFeature::kShadowDOMV0:
      return OriginTrialType::kDeprecation;
    default:
      return OriginTrialType::kDefault;
  }
}


base::span<const OriginTrialFeature> origin_trials::FeaturesForTrial(
    const StringView& trial_name) {
  auto it = std::find_if(
      std::begin(kTrialToFeaturesMap), std::end(kTrialToFeaturesMap),
      [&](const auto& entry) { return entry.trial_name == trial_name; });
  DCHECK(it != std::end(kTrialToFeaturesMap));
  return {it->features.begin(), it->feature_count};
}

base::span<const OriginTrialFeature> origin_trials::GetImpliedFeatures(
    OriginTrialFeature feature) {
  if (feature == OriginTrialFeature::kOriginTrialsSampleAPI) {
    static constexpr OriginTrialFeature implied_features[] = {OriginTrialFeature::kOriginTrialsSampleAPIImplied,};
    return implied_features;
  }
  if (feature == OriginTrialFeature::kRTCInsertableStreams) {
    static constexpr OriginTrialFeature implied_features[] = {OriginTrialFeature::kTransferableStreams,};
    return implied_features;
  }
  if (feature == OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS) {
    static constexpr OriginTrialFeature implied_features[] = {OriginTrialFeature::kOriginTrialsSampleAPIImplied,};
    return implied_features;
  }
  return {};
}

bool origin_trials::FeatureEnabledForOS(OriginTrialFeature feature) {
  switch (feature) {
    case OriginTrialFeature::kAllowSyncXHRInPageDismissal:
      return true;
    case OriginTrialFeature::kAppCache:
      return true;
    case OriginTrialFeature::kAutoPictureInPicture:
      return true;
    case OriginTrialFeature::kCacheStorageCodeCacheHint:
      return true;
    case OriginTrialFeature::kCookieStoreDocument:
      return true;
    case OriginTrialFeature::kCookieStoreWorker:
      return true;
    case OriginTrialFeature::kCustomElementsV0:
      return true;
    case OriginTrialFeature::kDisableHardwareNoiseSuppression:
      return true;
    case OriginTrialFeature::kDocumentPolicy:
      return true;
    case OriginTrialFeature::kExperimentalAutoplayDynamicDelegation:
      return true;
    case OriginTrialFeature::kExperimentalIsInputPending:
      return true;
    case OriginTrialFeature::kExperimentalJSProfiler:
      return true;
    case OriginTrialFeature::kFeaturePolicyReporting:
      return true;
    case OriginTrialFeature::kFileHandling:
#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS)
      return true;
#else
      return false;
#endif
    case OriginTrialFeature::kForceLoadAtTop:
      return true;
    case OriginTrialFeature::kHrefTranslate:
      return true;
    case OriginTrialFeature::kHTMLImports:
      return true;
    case OriginTrialFeature::kIdleDetection:
      return true;
    case OriginTrialFeature::kLegacyNativeFileSystem:
#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS)
      return true;
#else
      return false;
#endif
    case OriginTrialFeature::kMeasureMemory:
      return true;
    case OriginTrialFeature::kNativeFileSystem:
#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS)
      return true;
#else
      return false;
#endif
    case OriginTrialFeature::kNotificationTriggers:
      return true;
    case OriginTrialFeature::kOriginIsolationHeader:
      return true;
    case OriginTrialFeature::kOriginTrialsSampleAPI:
      return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIDeprecation:
      return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIImplied:
      return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS:
#if defined(OS_INVALID)
      return true;
#else
      return false;
#endif
    case OriginTrialFeature::kOriginTrialsSampleAPINavigation:
      return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIThirdParty:
      return true;
    case OriginTrialFeature::kPageFreezeOptIn:
      return true;
    case OriginTrialFeature::kPageFreezeOptOut:
      return true;
    case OriginTrialFeature::kPerMethodCanMakePaymentQuota:
      return true;
    case OriginTrialFeature::kPNaCl:
      return true;
    case OriginTrialFeature::kPointerLockOptions:
      return true;
    case OriginTrialFeature::kPortals:
      return true;
    case OriginTrialFeature::kPriorityHints:
      return true;
    case OriginTrialFeature::kQuicTransport:
      return true;
    case OriginTrialFeature::kRtcAudioJitterBufferMaxPackets:
      return true;
    case OriginTrialFeature::kRtcAudioJitterBufferRtxHandling:
      return true;
    case OriginTrialFeature::kRTCIceTransportExtension:
      return true;
    case OriginTrialFeature::kRTCInsertableStreams:
      return true;
    case OriginTrialFeature::kRTCQuicTransport:
      return true;
    case OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay:
      return true;
    case OriginTrialFeature::kSerial:
      return true;
    case OriginTrialFeature::kShadowDOMV0:
      return true;
    case OriginTrialFeature::kSignatureBasedIntegrity:
      return true;
    case OriginTrialFeature::kSignedExchangeSubresourcePrefetch:
      return true;
    case OriginTrialFeature::kSkipAd:
      return true;
    case OriginTrialFeature::kTextFragmentIdentifiers:
      return true;
    case OriginTrialFeature::kTouchEventFeatureDetection:
      return true;
    case OriginTrialFeature::kTransferableStreams:
      return true;
    case OriginTrialFeature::kTrustTokens:
      return true;
    case OriginTrialFeature::kUnoptimizedImagePolicies:
      return true;
    case OriginTrialFeature::kUnsizedMediaPolicy:
      return true;
    case OriginTrialFeature::kWakeLock:
      return true;
    case OriginTrialFeature::kWebAssemblySimd:
      return true;
    case OriginTrialFeature::kWebAssemblyThreads:
      return true;
    case OriginTrialFeature::kWebNFC:
#if defined(OS_ANDROID)
      return true;
#else
      return false;
#endif
    case OriginTrialFeature::kWebScheduler:
      return true;
    // For testing
    case OriginTrialFeature::kNonExisting:
      return true;
  }
}

} // namespace blink
