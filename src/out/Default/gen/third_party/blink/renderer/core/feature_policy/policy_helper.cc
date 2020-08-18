// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/policy_helper.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/feature_policy/document_policy_features.json5
//   ../../third_party/blink/renderer/core/feature_policy/feature_policy_features.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#include "third_party/blink/renderer/core/feature_policy/policy_helper.h"

#include "third_party/blink/public/mojom/feature_policy/document_policy_feature.mojom-blink.h"
#include "third_party/blink/public/mojom/feature_policy/feature_policy.mojom-blink.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/origin_trials/origin_trials.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {
  
namespace {

const char kAccelerometerPolicyName[] = "accelerometer";
const char kAmbientLightSensorPolicyName[] = "ambient-light-sensor";
const char kAutoplayPolicyName[] = "autoplay";
const char kCameraPolicyName[] = "camera";
const char kClientHintDPRPolicyName[] = "ch-dpr";
const char kClientHintDeviceMemoryPolicyName[] = "ch-device-memory";
const char kClientHintDownlinkPolicyName[] = "ch-downlink";
const char kClientHintECTPolicyName[] = "ch-ect";
const char kClientHintLangPolicyName[] = "ch-lang";
const char kClientHintRTTPolicyName[] = "ch-rtt";
const char kClientHintUAPolicyName[] = "ch-ua";
const char kClientHintUAArchPolicyName[] = "ch-ua-arch";
const char kClientHintUAPlatformPolicyName[] = "ch-ua-platform";
const char kClientHintUAModelPolicyName[] = "ch-ua-model";
const char kClientHintUAMobilePolicyName[] = "ch-ua-mobile";
const char kClientHintUAFullVersionPolicyName[] = "ch-ua-full-version";
const char kClientHintUAPlatformVersionPolicyName[] = "ch-ua-platform-version";
const char kClientHintViewportWidthPolicyName[] = "ch-viewport-width";
const char kClientHintWidthPolicyName[] = "ch-width";
const char kConversionMeasurementPolicyName[] = "conversion-measurement";
const char kDocumentDomainPolicyName[] = "document-domain";
const char kDocumentWritePolicyName[] = "document-write";
const char kDownloadsPolicyName[] = "downloads";
const char kEncryptedMediaPolicyName[] = "encrypted-media";
const char kExecutionWhileOutOfViewportPolicyName[] = "execution-while-out-of-viewport";
const char kExecutionWhileNotRenderedPolicyName[] = "execution-while-not-rendered";
const char kFocusWithoutUserActivationPolicyName[] = "focus-without-user-activation";
const char kFormSubmissionPolicyName[] = "forms";
const char kFullscreenPolicyName[] = "fullscreen";
const char kFrobulatePolicyName[] = "frobulate";
const char kGeolocationPolicyName[] = "geolocation";
const char kGyroscopePolicyName[] = "gyroscope";
const char kHidPolicyName[] = "hid";
const char kIdleDetectionPolicyName[] = "idle-detection";
const char kMagnetometerPolicyName[] = "magnetometer";
const char kMicrophonePolicyName[] = "microphone";
const char kMidiFeaturePolicyName[] = "midi";
const char kModalsPolicyName[] = "modals";
const char kOrientationLockPolicyName[] = "orientation-lock";
const char kPaymentPolicyName[] = "payment";
const char kPictureInPicturePolicyName[] = "picture-in-picture";
const char kPointerLockPolicyName[] = "pointer-lock";
const char kPopupsPolicyName[] = "popups";
const char kPresentationPolicyName[] = "presentation";
const char kPublicKeyCredentialsGetPolicyName[] = "publickey-credentials-get";
const char kScreenWakeLockPolicyName[] = "screen-wake-lock";
const char kScriptPolicyName[] = "scripts";
const char kSerialPolicyName[] = "serial";
const char kStorageAccessAPIPolicyName[] = "storage-access-api";
const char kSyncScriptPolicyName[] = "sync-script";
const char kSyncXHRPolicyName[] = "sync-xhr";
const char kTopNavigationPolicyName[] = "top-navigation";
const char kTrustTokenRedemptionPolicyName[] = "trust-token-redemption";
const char kUsbPolicyName[] = "usb";
const char kVerticalScrollPolicyName[] = "vertical-scroll";
const char kWebXrPolicyName[] = "xr-spatial-tracking";

}  // namespace

// Features which depend on a flag also have the same flag controlling whether
// they are in this map. Features which are shipping as part of an origin trial
// add their feature names to this map unconditionally, as the trial token could
// be added after the HTTP header needs to be parsed. This also means that
// top-level documents which simply want to embed another page which uses an
// origin trial feature, without using the feature themselves, can use feature
// policy to allow use of the feature in subframes (The framed document will
// still require a valid origin trial token to use the feature in this scenario).
const FeatureNameMap& GetDefaultFeatureNameMap() {
  DEFINE_STATIC_LOCAL(FeatureNameMap, default_feature_name_map, ());
  if (default_feature_name_map.IsEmpty()) {
    default_feature_name_map.Set(kAccelerometerPolicyName,
                                 mojom::FeaturePolicyFeature::kAccelerometer);
    default_feature_name_map.Set(kAutoplayPolicyName,
                                 mojom::FeaturePolicyFeature::kAutoplay);
    default_feature_name_map.Set(kCameraPolicyName,
                                 mojom::FeaturePolicyFeature::kCamera);
    default_feature_name_map.Set(kDocumentDomainPolicyName,
                                 mojom::FeaturePolicyFeature::kDocumentDomain);
    default_feature_name_map.Set(kEncryptedMediaPolicyName,
                                 mojom::FeaturePolicyFeature::kEncryptedMedia);
    default_feature_name_map.Set(kFullscreenPolicyName,
                                 mojom::FeaturePolicyFeature::kFullscreen);
    default_feature_name_map.Set(kFrobulatePolicyName,
                                 mojom::FeaturePolicyFeature::kFrobulate);
    default_feature_name_map.Set(kGeolocationPolicyName,
                                 mojom::FeaturePolicyFeature::kGeolocation);
    default_feature_name_map.Set(kGyroscopePolicyName,
                                 mojom::FeaturePolicyFeature::kGyroscope);
    default_feature_name_map.Set(kIdleDetectionPolicyName,
                                 mojom::FeaturePolicyFeature::kIdleDetection);
    default_feature_name_map.Set(kMagnetometerPolicyName,
                                 mojom::FeaturePolicyFeature::kMagnetometer);
    default_feature_name_map.Set(kMicrophonePolicyName,
                                 mojom::FeaturePolicyFeature::kMicrophone);
    default_feature_name_map.Set(kMidiFeaturePolicyName,
                                 mojom::FeaturePolicyFeature::kMidiFeature);
    default_feature_name_map.Set(kScreenWakeLockPolicyName,
                                 mojom::FeaturePolicyFeature::kScreenWakeLock);
    default_feature_name_map.Set(kSerialPolicyName,
                                 mojom::FeaturePolicyFeature::kSerial);
    default_feature_name_map.Set(kSyncXHRPolicyName,
                                 mojom::FeaturePolicyFeature::kSyncXHR);
    default_feature_name_map.Set(kTrustTokenRedemptionPolicyName,
                                 mojom::FeaturePolicyFeature::kTrustTokenRedemption);
    if (RuntimeEnabledFeatures::BlockingFocusWithoutUserActivationEnabled()) {
      default_feature_name_map.Set(kFocusWithoutUserActivationPolicyName,
                                   mojom::FeaturePolicyFeature::kFocusWithoutUserActivation);
    }
    if (RuntimeEnabledFeatures::ConversionMeasurementEnabled()) {
      default_feature_name_map.Set(kConversionMeasurementPolicyName,
                                   mojom::FeaturePolicyFeature::kConversionMeasurement);
    }
    if (RuntimeEnabledFeatures::ExperimentalProductivityFeaturesEnabled()) {
      default_feature_name_map.Set(kDocumentWritePolicyName,
                                   mojom::FeaturePolicyFeature::kDocumentWrite);
      default_feature_name_map.Set(kSyncScriptPolicyName,
                                   mojom::FeaturePolicyFeature::kSyncScript);
      default_feature_name_map.Set(kVerticalScrollPolicyName,
                                   mojom::FeaturePolicyFeature::kVerticalScroll);
    }
    if (RuntimeEnabledFeatures::FeaturePolicyForClientHintsEnabled()) {
      default_feature_name_map.Set(kClientHintDPRPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintDPR);
      default_feature_name_map.Set(kClientHintDeviceMemoryPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintDeviceMemory);
      default_feature_name_map.Set(kClientHintDownlinkPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintDownlink);
      default_feature_name_map.Set(kClientHintECTPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintECT);
      default_feature_name_map.Set(kClientHintLangPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintLang);
      default_feature_name_map.Set(kClientHintRTTPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintRTT);
      default_feature_name_map.Set(kClientHintUAPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintUA);
      default_feature_name_map.Set(kClientHintUAArchPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintUAArch);
      default_feature_name_map.Set(kClientHintUAPlatformPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintUAPlatform);
      default_feature_name_map.Set(kClientHintUAModelPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintUAModel);
      default_feature_name_map.Set(kClientHintUAMobilePolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintUAMobile);
      default_feature_name_map.Set(kClientHintUAFullVersionPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintUAFullVersion);
      default_feature_name_map.Set(kClientHintUAPlatformVersionPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintUAPlatformVersion);
      default_feature_name_map.Set(kClientHintViewportWidthPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintViewportWidth);
      default_feature_name_map.Set(kClientHintWidthPolicyName,
                                   mojom::FeaturePolicyFeature::kClientHintWidth);
    }
    if (RuntimeEnabledFeatures::FeaturePolicyForSandboxEnabled()) {
      default_feature_name_map.Set(kDownloadsPolicyName,
                                   mojom::FeaturePolicyFeature::kDownloads);
      default_feature_name_map.Set(kFormSubmissionPolicyName,
                                   mojom::FeaturePolicyFeature::kFormSubmission);
      default_feature_name_map.Set(kModalsPolicyName,
                                   mojom::FeaturePolicyFeature::kModals);
      default_feature_name_map.Set(kOrientationLockPolicyName,
                                   mojom::FeaturePolicyFeature::kOrientationLock);
      default_feature_name_map.Set(kPointerLockPolicyName,
                                   mojom::FeaturePolicyFeature::kPointerLock);
      default_feature_name_map.Set(kPopupsPolicyName,
                                   mojom::FeaturePolicyFeature::kPopups);
      default_feature_name_map.Set(kPresentationPolicyName,
                                   mojom::FeaturePolicyFeature::kPresentation);
      default_feature_name_map.Set(kScriptPolicyName,
                                   mojom::FeaturePolicyFeature::kScript);
      default_feature_name_map.Set(kTopNavigationPolicyName,
                                   mojom::FeaturePolicyFeature::kTopNavigation);
    }
    if (RuntimeEnabledFeatures::FreezeFramesOnVisibilityEnabled()) {
      default_feature_name_map.Set(kExecutionWhileOutOfViewportPolicyName,
                                   mojom::FeaturePolicyFeature::kExecutionWhileOutOfViewport);
      default_feature_name_map.Set(kExecutionWhileNotRenderedPolicyName,
                                   mojom::FeaturePolicyFeature::kExecutionWhileNotRendered);
    }
    if (RuntimeEnabledFeatures::PaymentRequestEnabled()) {
      default_feature_name_map.Set(kPaymentPolicyName,
                                   mojom::FeaturePolicyFeature::kPayment);
    }
    if (RuntimeEnabledFeatures::PictureInPictureAPIEnabled()) {
      default_feature_name_map.Set(kPictureInPicturePolicyName,
                                   mojom::FeaturePolicyFeature::kPictureInPicture);
    }
    if (RuntimeEnabledFeatures::SensorExtraClassesEnabled()) {
      default_feature_name_map.Set(kAmbientLightSensorPolicyName,
                                   mojom::FeaturePolicyFeature::kAmbientLightSensor);
    }
    if (RuntimeEnabledFeatures::StorageAccessAPIEnabled()) {
      default_feature_name_map.Set(kStorageAccessAPIPolicyName,
                                   mojom::FeaturePolicyFeature::kStorageAccessAPI);
    }
    if (RuntimeEnabledFeatures::WebAuthenticationGetAssertionFeaturePolicyEnabled()) {
      default_feature_name_map.Set(kPublicKeyCredentialsGetPolicyName,
                                   mojom::FeaturePolicyFeature::kPublicKeyCredentialsGet);
    }
    if (RuntimeEnabledFeatures::WebHIDEnabled()) {
      default_feature_name_map.Set(kHidPolicyName,
                                   mojom::FeaturePolicyFeature::kHid);
    }
    if (RuntimeEnabledFeatures::WebUSBEnabled()) {
      default_feature_name_map.Set(kUsbPolicyName,
                                   mojom::FeaturePolicyFeature::kUsb);
    }
    if (RuntimeEnabledFeatures::WebXREnabled()) {
      default_feature_name_map.Set(kWebXrPolicyName,
                                   mojom::FeaturePolicyFeature::kWebXr);
    }
  }
  return default_feature_name_map;
}

const DocumentPolicyFeatureSet& GetAvailableDocumentPolicyFeatures() {
  DEFINE_STATIC_LOCAL(DocumentPolicyFeatureSet, features, ());
  if (features.IsEmpty()) {
    features.insert(mojom::DocumentPolicyFeature::kUnoptimizedLosslessImages);
    features.insert(mojom::DocumentPolicyFeature::kForceLoadAtTop);
    features.insert(mojom::DocumentPolicyFeature::kUnoptimizedLosslessImagesStrict);
    features.insert(mojom::DocumentPolicyFeature::kUnoptimizedLossyImages);
    features.insert(mojom::DocumentPolicyFeature::kOversizedImages);
    features.insert(mojom::DocumentPolicyFeature::kUnsizedMedia);
    if (RuntimeEnabledFeatures::ExperimentalProductivityFeaturesEnabled()) {
      features.insert(mojom::DocumentPolicyFeature::kFontDisplay);
      features.insert(mojom::DocumentPolicyFeature::kLayoutAnimations);
    }
  }
  return features;
}

// If any of the origin trial runtime feature is enabled, returns false,
// i.e. the feature is considered enabled by origin trial.
bool DisabledByOriginTrial(const String& feature_name,
                           FeatureContext* feature_context) {
  if (feature_name == kFrobulatePolicyName) {
    return !RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabled(feature_context);
  }
  if (feature_name == kIdleDetectionPolicyName) {
    return !RuntimeEnabledFeatures::IdleDetectionEnabled(feature_context);
  }
  if (feature_name == kScreenWakeLockPolicyName) {
    return !RuntimeEnabledFeatures::WakeLockEnabled(feature_context);
  }
  if (feature_name == kSerialPolicyName) {
    return !RuntimeEnabledFeatures::SerialEnabled(feature_context);
  }
  if (feature_name == kTrustTokenRedemptionPolicyName) {
    return !RuntimeEnabledFeatures::TrustTokensEnabled(feature_context);
  }
  return false;
}

bool DisabledByOriginTrial(mojom::blink::DocumentPolicyFeature feature,
                           FeatureContext* feature_context) {
  if (feature == mojom::DocumentPolicyFeature::kOversizedImages) {
    return !RuntimeEnabledFeatures::UnoptimizedImagePoliciesEnabled(feature_context);
  }
  if (feature == mojom::DocumentPolicyFeature::kUnoptimizedLosslessImages) {
    return !RuntimeEnabledFeatures::UnoptimizedImagePoliciesEnabled(feature_context);
  }
  if (feature == mojom::DocumentPolicyFeature::kUnoptimizedLosslessImagesStrict) {
    return !RuntimeEnabledFeatures::UnoptimizedImagePoliciesEnabled(feature_context);
  }
  if (feature == mojom::DocumentPolicyFeature::kUnoptimizedLossyImages) {
    return !RuntimeEnabledFeatures::UnoptimizedImagePoliciesEnabled(feature_context);
  }
  if (feature == mojom::DocumentPolicyFeature::kUnsizedMedia) {
    return !RuntimeEnabledFeatures::UnsizedMediaPolicyEnabled(feature_context);
  }
  return false;
}

}  // namespace blink
