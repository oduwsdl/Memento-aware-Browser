// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/internal_runtime_flags.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TESTING_INTERNAL_RUNTIME_FLAGS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TESTING_INTERNAL_RUNTIME_FLAGS_H_

#include "third_party/blink/renderer/platform/bindings/script_wrappable.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/platform/wtf/ref_counted.h"

namespace blink {

class InternalRuntimeFlags : public ScriptWrappable {
  DEFINE_WRAPPERTYPEINFO();
 public:
  static InternalRuntimeFlags* create() {
    return MakeGarbageCollected<InternalRuntimeFlags>();
  }

  InternalRuntimeFlags() {}

  // These are reset between web tests from Internals::resetToConsistentState
  // using RuntimeEnabledFeatures::Backup.
  void setAccelerated2dCanvasEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetAccelerated2dCanvasEnabled(isEnabled);
  }
  void setAutomationControlledEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetAutomationControlledEnabled(isEnabled);
  }
  void setAutoplayIgnoresWebAudioEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetAutoplayIgnoresWebAudioEnabled(isEnabled);
  }
  void setCSSLogicalEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetCSSLogicalEnabled(isEnabled);
  }
  void setDisplayCutoutAPIEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetDisplayCutoutAPIEnabled(isEnabled);
  }
  void setEditContextEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetEditContextEnabled(isEnabled);
  }
  void setFocuslessSpatialNavigationEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetFocuslessSpatialNavigationEnabled(isEnabled);
  }
  void setImplicitRootScrollerEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetImplicitRootScrollerEnabled(isEnabled);
  }
  void setMediaControlsOverlayPlayButtonEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetMediaControlsOverlayPlayButtonEnabled(isEnabled);
  }
  void setNavigatorLanguageInInsecureContextEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetNavigatorLanguageInInsecureContextEnabled(isEnabled);
  }
  void setOverscrollCustomizationEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetOverscrollCustomizationEnabled(isEnabled);
  }
  void setPaintUnderInvalidationCheckingEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetPaintUnderInvalidationCheckingEnabled(isEnabled);
  }
  void setPercentBasedScrollingEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetPercentBasedScrollingEnabled(isEnabled);
  }
  void setPictureInPictureEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetPictureInPictureEnabled(isEnabled);
  }
  void setPictureInPictureV2Enabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetPictureInPictureV2Enabled(isEnabled);
  }
  void setPreferNonCompositedScrollingEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetPreferNonCompositedScrollingEnabled(isEnabled);
  }
  void setRemotePlaybackBackendEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetRemotePlaybackBackendEnabled(isEnabled);
  }
  void setSkipTouchEventFilterEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetSkipTouchEventFilterEnabled(isEnabled);
  }
  void setVideoAutoFullscreenEnabled(bool isEnabled) {
    RuntimeEnabledFeatures::SetVideoAutoFullscreenEnabled(isEnabled);
  }

  bool accelerated2dCanvasEnabled() {
    return RuntimeEnabledFeatures::Accelerated2dCanvasEnabled();
  }
  bool acceleratedSmallCanvasesEnabled() {
    return RuntimeEnabledFeatures::AcceleratedSmallCanvasesEnabled();
  }
  bool accessibilityExposeARIAAnnotationsEnabled() {
    return RuntimeEnabledFeatures::AccessibilityExposeARIAAnnotationsEnabled();
  }
  bool accessibilityExposeDisplayNoneEnabled() {
    return RuntimeEnabledFeatures::AccessibilityExposeDisplayNoneEnabled();
  }
  bool accessibilityExposeHTMLElementEnabled() {
    return RuntimeEnabledFeatures::AccessibilityExposeHTMLElementEnabled();
  }
  bool accessibilityObjectModelEnabled() {
    return RuntimeEnabledFeatures::AccessibilityObjectModelEnabled();
  }
  bool addressSpaceEnabled() {
    return RuntimeEnabledFeatures::AddressSpaceEnabled();
  }
  bool adTaggingEnabled() {
    return RuntimeEnabledFeatures::AdTaggingEnabled();
  }
  bool allowActivationDelegationAttrEnabled() {
    return RuntimeEnabledFeatures::AllowActivationDelegationAttrEnabled();
  }
  bool allowContentInitiatedDataUrlNavigationsEnabled() {
    return RuntimeEnabledFeatures::AllowContentInitiatedDataUrlNavigationsEnabled();
  }
  bool allowSyncXHRInPageDismissalEnabled() {
    return RuntimeEnabledFeatures::AllowSyncXHRInPageDismissalEnabledByRuntimeFlag();
  }
  bool animationWorkletEnabled() {
    return RuntimeEnabledFeatures::AnimationWorkletEnabled();
  }
  bool aomAriaPropertiesEnabled() {
    return RuntimeEnabledFeatures::AOMAriaPropertiesEnabled();
  }
  bool aomAriaRelationshipPropertiesEnabled() {
    return RuntimeEnabledFeatures::AOMAriaRelationshipPropertiesEnabled();
  }
  bool appCacheEnabled() {
    return RuntimeEnabledFeatures::AppCacheEnabledByRuntimeFlag();
  }
  bool audioOutputDevicesEnabled() {
    return RuntimeEnabledFeatures::AudioOutputDevicesEnabled();
  }
  bool audioVideoTracksEnabled() {
    return RuntimeEnabledFeatures::AudioVideoTracksEnabled();
  }
  bool audioWorkletRealtimeThreadEnabled() {
    return RuntimeEnabledFeatures::AudioWorkletRealtimeThreadEnabled();
  }
  bool autoLazyLoadOnReloadsEnabled() {
    return RuntimeEnabledFeatures::AutoLazyLoadOnReloadsEnabled();
  }
  bool automaticLazyFrameLoadingEnabled() {
    return RuntimeEnabledFeatures::AutomaticLazyFrameLoadingEnabled();
  }
  bool automaticLazyImageLoadingEnabled() {
    return RuntimeEnabledFeatures::AutomaticLazyImageLoadingEnabled();
  }
  bool automationControlledEnabled() {
    return RuntimeEnabledFeatures::AutomationControlledEnabled();
  }
  bool autoPictureInPictureEnabled() {
    return RuntimeEnabledFeatures::AutoPictureInPictureEnabledByRuntimeFlag();
  }
  bool autoplayIgnoresWebAudioEnabled() {
    return RuntimeEnabledFeatures::AutoplayIgnoresWebAudioEnabled();
  }
  bool backForwardCacheEnabled() {
    return RuntimeEnabledFeatures::BackForwardCacheEnabled();
  }
  bool backgroundFetchEnabled() {
    return RuntimeEnabledFeatures::BackgroundFetchEnabled();
  }
  bool backgroundVideoTrackOptimizationEnabled() {
    return RuntimeEnabledFeatures::BackgroundVideoTrackOptimizationEnabled();
  }
  bool badgingEnabled() {
    return RuntimeEnabledFeatures::BadgingEnabled();
  }
  bool barcodeDetectorEnabled() {
    return RuntimeEnabledFeatures::BarcodeDetectorEnabled();
  }
  bool beforeMatchEventEnabled() {
    return RuntimeEnabledFeatures::BeforeMatchEventEnabled();
  }
  bool bidiCaretAffinityEnabled() {
    return RuntimeEnabledFeatures::BidiCaretAffinityEnabled();
  }
  bool blinkRuntimeCallStatsEnabled() {
    return RuntimeEnabledFeatures::BlinkRuntimeCallStatsEnabled();
  }
  bool blockCredentialedSubresourcesEnabled() {
    return RuntimeEnabledFeatures::BlockCredentialedSubresourcesEnabled();
  }
  bool blockFlowHandlesWebkitLineClampEnabled() {
    return RuntimeEnabledFeatures::BlockFlowHandlesWebkitLineClampEnabled();
  }
  bool blockHTMLParserOnStyleSheetsEnabled() {
    return RuntimeEnabledFeatures::BlockHTMLParserOnStyleSheetsEnabled();
  }
  bool blockingDownloadsInSandboxEnabled() {
    return RuntimeEnabledFeatures::BlockingDownloadsInSandboxEnabled();
  }
  bool blockingFocusWithoutUserActivationEnabled() {
    return RuntimeEnabledFeatures::BlockingFocusWithoutUserActivationEnabled();
  }
  bool browserVerifiedUserActivationKeyboardEnabled() {
    return RuntimeEnabledFeatures::BrowserVerifiedUserActivationKeyboardEnabled();
  }
  bool browserVerifiedUserActivationMouseEnabled() {
    return RuntimeEnabledFeatures::BrowserVerifiedUserActivationMouseEnabled();
  }
  bool cacheInlineScriptCodeEnabled() {
    return RuntimeEnabledFeatures::CacheInlineScriptCodeEnabled();
  }
  bool cacheStorageCodeCacheHintEnabled() {
    return RuntimeEnabledFeatures::CacheStorageCodeCacheHintEnabledByRuntimeFlag();
  }
  bool canvas2dContextLostRestoredEnabled() {
    return RuntimeEnabledFeatures::Canvas2dContextLostRestoredEnabled();
  }
  bool canvas2dImageChromiumEnabled() {
    return RuntimeEnabledFeatures::Canvas2dImageChromiumEnabled();
  }
  bool canvas2dScrollPathIntoViewEnabled() {
    return RuntimeEnabledFeatures::Canvas2dScrollPathIntoViewEnabled();
  }
  bool canvasColorManagementEnabled() {
    return RuntimeEnabledFeatures::CanvasColorManagementEnabled();
  }
  bool canvasHitRegionEnabled() {
    return RuntimeEnabledFeatures::CanvasHitRegionEnabled();
  }
  bool canvasImageSmoothingEnabled() {
    return RuntimeEnabledFeatures::CanvasImageSmoothingEnabled();
  }
  bool captureTimeInCsrcEnabled() {
    return RuntimeEnabledFeatures::CaptureTimeInCsrcEnabled();
  }
  bool clickPointerEventEnabled() {
    return RuntimeEnabledFeatures::ClickPointerEventEnabled();
  }
  bool clickRetargettingEnabled() {
    return RuntimeEnabledFeatures::ClickRetargettingEnabled();
  }
  bool compositeAfterPaintEnabled() {
    return RuntimeEnabledFeatures::CompositeAfterPaintEnabled();
  }
  bool compositedSelectionUpdateEnabled() {
    return RuntimeEnabledFeatures::CompositedSelectionUpdateEnabled();
  }
  bool computedAccessibilityInfoEnabled() {
    return RuntimeEnabledFeatures::ComputedAccessibilityInfoEnabled();
  }
  bool consolidatedMovementXYEnabled() {
    return RuntimeEnabledFeatures::ConsolidatedMovementXYEnabled();
  }
  bool contactsManagerEnabled() {
    return RuntimeEnabledFeatures::ContactsManagerEnabled();
  }
  bool contactsManagerExtraPropertiesEnabled() {
    return RuntimeEnabledFeatures::ContactsManagerExtraPropertiesEnabled();
  }
  bool contentIndexEnabled() {
    return RuntimeEnabledFeatures::ContentIndexEnabled();
  }
  bool contextMenuEnabled() {
    return RuntimeEnabledFeatures::ContextMenuEnabled();
  }
  bool conversionMeasurementEnabled() {
    return RuntimeEnabledFeatures::ConversionMeasurementEnabled();
  }
  bool cookieDeprecationMessagesEnabled() {
    return RuntimeEnabledFeatures::CookieDeprecationMessagesEnabled();
  }
  bool cookieStoreDocumentEnabled() {
    return RuntimeEnabledFeatures::CookieStoreDocumentEnabledByRuntimeFlag();
  }
  bool cookieStoreWorkerEnabled() {
    return RuntimeEnabledFeatures::CookieStoreWorkerEnabledByRuntimeFlag();
  }
  bool cookiesWithoutSameSiteMustBeSecureEnabled() {
    return RuntimeEnabledFeatures::CookiesWithoutSameSiteMustBeSecureEnabled();
  }
  bool cooperativeSchedulingEnabled() {
    return RuntimeEnabledFeatures::CooperativeSchedulingEnabled();
  }
  bool corsRFC1918Enabled() {
    return RuntimeEnabledFeatures::CorsRFC1918Enabled();
  }
  bool crossOriginIsolationEnabled() {
    return RuntimeEnabledFeatures::CrossOriginIsolationEnabled();
  }
  bool css3TextEnabled() {
    return RuntimeEnabledFeatures::CSS3TextEnabled();
  }
  bool cssAspectRatioPropertyEnabled() {
    return RuntimeEnabledFeatures::CSSAspectRatioPropertyEnabled();
  }
  bool cssCalcAsIntEnabled() {
    return RuntimeEnabledFeatures::CSSCalcAsIntEnabled();
  }
  bool cssCascadeEnabled() {
    return RuntimeEnabledFeatures::CSSCascadeEnabled();
  }
  bool cssColorSchemeEnabled() {
    return RuntimeEnabledFeatures::CSSColorSchemeEnabled();
  }
  bool cssColorSchemeUARenderingEnabled() {
    return RuntimeEnabledFeatures::CSSColorSchemeUARenderingEnabled();
  }
  bool cssContentVisibilityEnabled() {
    return RuntimeEnabledFeatures::CSSContentVisibilityEnabled();
  }
  bool cssContentVisibilityHiddenMatchableEnabled() {
    return RuntimeEnabledFeatures::CSSContentVisibilityHiddenMatchableEnabled();
  }
  bool cssFocusVisibleEnabled() {
    return RuntimeEnabledFeatures::CSSFocusVisibleEnabled();
  }
  bool cssFoldablesEnabled() {
    return RuntimeEnabledFeatures::CSSFoldablesEnabled();
  }
  bool cssFontSizeAdjustEnabled() {
    return RuntimeEnabledFeatures::CSSFontSizeAdjustEnabled();
  }
  bool cssHexAlphaColorEnabled() {
    return RuntimeEnabledFeatures::CSSHexAlphaColorEnabled();
  }
  bool cssIndependentTransformPropertiesEnabled() {
    return RuntimeEnabledFeatures::CSSIndependentTransformPropertiesEnabled();
  }
  bool cssLayoutAPIEnabled() {
    return RuntimeEnabledFeatures::CSSLayoutAPIEnabled();
  }
  bool cssLogicalEnabled() {
    return RuntimeEnabledFeatures::CSSLogicalEnabled();
  }
  bool cssLogicalOverflowEnabled() {
    return RuntimeEnabledFeatures::CSSLogicalOverflowEnabled();
  }
  bool cssMarkerNestedPseudoElementEnabled() {
    return RuntimeEnabledFeatures::CSSMarkerNestedPseudoElementEnabled();
  }
  bool cssMarkerPseudoElementEnabled() {
    return RuntimeEnabledFeatures::CSSMarkerPseudoElementEnabled();
  }
  bool cssMatchedPropertiesCacheDependenciesEnabled() {
    return RuntimeEnabledFeatures::CSSMatchedPropertiesCacheDependenciesEnabled();
  }
  bool cssMathStyleEnabled() {
    return RuntimeEnabledFeatures::CSSMathStyleEnabled();
  }
  bool cssMathSuperscriptShiftStyleEnabled() {
    return RuntimeEnabledFeatures::CSSMathSuperscriptShiftStyleEnabled();
  }
  bool cssMathVariantEnabled() {
    return RuntimeEnabledFeatures::CSSMathVariantEnabled();
  }
  bool cssModulesEnabled() {
    return RuntimeEnabledFeatures::CSSModulesEnabled();
  }
  bool cssOffsetPathRayEnabled() {
    return RuntimeEnabledFeatures::CSSOffsetPathRayEnabled();
  }
  bool cssOffsetPathRayContainEnabled() {
    return RuntimeEnabledFeatures::CSSOffsetPathRayContainEnabled();
  }
  bool cssOffsetPositionAnchorEnabled() {
    return RuntimeEnabledFeatures::CSSOffsetPositionAnchorEnabled();
  }
  bool cssomViewScrollCoordinatesEnabled() {
    return RuntimeEnabledFeatures::CSSOMViewScrollCoordinatesEnabled();
  }
  bool cssPaintAPIArgumentsEnabled() {
    return RuntimeEnabledFeatures::CSSPaintAPIArgumentsEnabled();
  }
  bool cssPictureInPictureEnabled() {
    return RuntimeEnabledFeatures::CSSPictureInPictureEnabled();
  }
  bool cssPseudoIsEnabled() {
    return RuntimeEnabledFeatures::CSSPseudoIsEnabled();
  }
  bool cssPseudoWhereEnabled() {
    return RuntimeEnabledFeatures::CSSPseudoWhereEnabled();
  }
  bool cssReducedFontLoadingInvalidationsEnabled() {
    return RuntimeEnabledFeatures::CSSReducedFontLoadingInvalidationsEnabled();
  }
  bool cssReducedFontLoadingLayoutInvalidationsEnabled() {
    return RuntimeEnabledFeatures::CSSReducedFontLoadingLayoutInvalidationsEnabled();
  }
  bool cssRevertEnabled() {
    return RuntimeEnabledFeatures::CSSRevertEnabled();
  }
  bool cssScrollTimelineEnabled() {
    return RuntimeEnabledFeatures::CSSScrollTimelineEnabled();
  }
  bool cssSnapSizeEnabled() {
    return RuntimeEnabledFeatures::CSSSnapSizeEnabled();
  }
  bool cssSupportsSelectorEnabled() {
    return RuntimeEnabledFeatures::CSSSupportsSelectorEnabled();
  }
  bool cssVariables2AtPropertyEnabled() {
    return RuntimeEnabledFeatures::CSSVariables2AtPropertyEnabled();
  }
  bool cssVariables2ImageValuesEnabled() {
    return RuntimeEnabledFeatures::CSSVariables2ImageValuesEnabled();
  }
  bool cssVariables2TransformValuesEnabled() {
    return RuntimeEnabledFeatures::CSSVariables2TransformValuesEnabled();
  }
  bool customElementDefaultStyleEnabled() {
    return RuntimeEnabledFeatures::CustomElementDefaultStyleEnabled();
  }
  bool customElementsV0Enabled() {
    return RuntimeEnabledFeatures::CustomElementsV0EnabledByRuntimeFlag();
  }
  bool customStatePseudoClassEnabled() {
    return RuntimeEnabledFeatures::CustomStatePseudoClassEnabled();
  }
  bool databaseEnabled() {
    return RuntimeEnabledFeatures::DatabaseEnabled();
  }
  bool declarativeShadowDOMEnabled() {
    return RuntimeEnabledFeatures::DeclarativeShadowDOMEnabled();
  }
  bool decodeJpeg420ImagesToYUVEnabled() {
    return RuntimeEnabledFeatures::DecodeJpeg420ImagesToYUVEnabled();
  }
  bool decodeLossyWebPImagesToYUVEnabled() {
    return RuntimeEnabledFeatures::DecodeLossyWebPImagesToYUVEnabled();
  }
  bool delayAsyncScriptExecutionUntilFinishedParsingEnabled() {
    return RuntimeEnabledFeatures::DelayAsyncScriptExecutionUntilFinishedParsingEnabled();
  }
  bool delayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabled() {
    return RuntimeEnabledFeatures::DelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabled();
  }
  bool delegatedInkTrailsEnabled() {
    return RuntimeEnabledFeatures::DelegatedInkTrailsEnabled();
  }
  bool desktopCaptureDisableLocalEchoControlEnabled() {
    return RuntimeEnabledFeatures::DesktopCaptureDisableLocalEchoControlEnabled();
  }
  bool digitalGoodsEnabled() {
    return RuntimeEnabledFeatures::DigitalGoodsEnabled();
  }
  bool disableHardwareNoiseSuppressionEnabled() {
    return RuntimeEnabledFeatures::DisableHardwareNoiseSuppressionEnabledByRuntimeFlag();
  }
  bool disableLayerSquashingEnabled() {
    return RuntimeEnabledFeatures::DisableLayerSquashingEnabled();
  }
  bool disallowDocumentAccessEnabled() {
    return RuntimeEnabledFeatures::DisallowDocumentAccessEnabled();
  }
  bool displayCutoutAPIEnabled() {
    return RuntimeEnabledFeatures::DisplayCutoutAPIEnabled();
  }
  bool documentCookieEnabled() {
    return RuntimeEnabledFeatures::DocumentCookieEnabled();
  }
  bool documentDomainEnabled() {
    return RuntimeEnabledFeatures::DocumentDomainEnabled();
  }
  bool documentPolicyEnabled() {
    return RuntimeEnabledFeatures::DocumentPolicyEnabledByRuntimeFlag();
  }
  bool documentWriteEnabled() {
    return RuntimeEnabledFeatures::DocumentWriteEnabled();
  }
  bool editContextEnabled() {
    return RuntimeEnabledFeatures::EditContextEnabled();
  }
  bool editingNGEnabled() {
    return RuntimeEnabledFeatures::EditingNGEnabled();
  }
  bool encryptedMediaEncryptionSchemeQueryEnabled() {
    return RuntimeEnabledFeatures::EncryptedMediaEncryptionSchemeQueryEnabled();
  }
  bool encryptedMediaHdcpPolicyCheckEnabled() {
    return RuntimeEnabledFeatures::EncryptedMediaHdcpPolicyCheckEnabled();
  }
  bool encryptedMediaPersistentUsageRecordSessionEnabled() {
    return RuntimeEnabledFeatures::EncryptedMediaPersistentUsageRecordSessionEnabled();
  }
  bool enterKeyHintAttributeEnabled() {
    return RuntimeEnabledFeatures::EnterKeyHintAttributeEnabled();
  }
  bool eventTimingEnabled() {
    return RuntimeEnabledFeatures::EventTimingEnabled();
  }
  bool execCommandInJavaScriptEnabled() {
    return RuntimeEnabledFeatures::ExecCommandInJavaScriptEnabled();
  }
  bool expensiveBackgroundTimerThrottlingEnabled() {
    return RuntimeEnabledFeatures::ExpensiveBackgroundTimerThrottlingEnabled();
  }
  bool experimentalAutoplayDynamicDelegationEnabled() {
    return RuntimeEnabledFeatures::ExperimentalAutoplayDynamicDelegationEnabledByRuntimeFlag();
  }
  bool experimentalContentSecurityPolicyFeaturesEnabled() {
    return RuntimeEnabledFeatures::ExperimentalContentSecurityPolicyFeaturesEnabled();
  }
  bool experimentalIsInputPendingEnabled() {
    return RuntimeEnabledFeatures::ExperimentalIsInputPendingEnabledByRuntimeFlag();
  }
  bool experimentalJSProfilerEnabled() {
    return RuntimeEnabledFeatures::ExperimentalJSProfilerEnabledByRuntimeFlag();
  }
  bool experimentalProductivityFeaturesEnabled() {
    return RuntimeEnabledFeatures::ExperimentalProductivityFeaturesEnabled();
  }
  bool extendedTextMetricsEnabled() {
    return RuntimeEnabledFeatures::ExtendedTextMetricsEnabled();
  }
  bool extraWebGLVideoTextureMetadataEnabled() {
    return RuntimeEnabledFeatures::ExtraWebGLVideoTextureMetadataEnabled();
  }
  bool faceDetectorEnabled() {
    return RuntimeEnabledFeatures::FaceDetectorEnabled();
  }
  bool featurePolicyForClientHintsEnabled() {
    return RuntimeEnabledFeatures::FeaturePolicyForClientHintsEnabled();
  }
  bool featurePolicyForSandboxEnabled() {
    return RuntimeEnabledFeatures::FeaturePolicyForSandboxEnabled();
  }
  bool featurePolicyReportingEnabled() {
    return RuntimeEnabledFeatures::FeaturePolicyReportingEnabledByRuntimeFlag();
  }
  bool featurePolicyVibrateFeatureEnabled() {
    return RuntimeEnabledFeatures::FeaturePolicyVibrateFeatureEnabled();
  }
  bool fetchUploadStreamingEnabled() {
    return RuntimeEnabledFeatures::FetchUploadStreamingEnabled();
  }
  bool fileHandlingEnabled() {
    return RuntimeEnabledFeatures::FileHandlingEnabledByRuntimeFlag();
  }
  bool fileSystemEnabled() {
    return RuntimeEnabledFeatures::FileSystemEnabled();
  }
  bool flexGapsEnabled() {
    return RuntimeEnabledFeatures::FlexGapsEnabled();
  }
  bool focuslessSpatialNavigationEnabled() {
    return RuntimeEnabledFeatures::FocuslessSpatialNavigationEnabled();
  }
  bool fontAccessEnabled() {
    return RuntimeEnabledFeatures::FontAccessEnabled();
  }
  bool fontSrcLocalMatchingEnabled() {
    return RuntimeEnabledFeatures::FontSrcLocalMatchingEnabled();
  }
  bool forcedColorsEnabled() {
    return RuntimeEnabledFeatures::ForcedColorsEnabled();
  }
  bool forceDeferScriptInterventionEnabled() {
    return RuntimeEnabledFeatures::ForceDeferScriptInterventionEnabled();
  }
  bool forceEagerMeasureMemoryEnabled() {
    return RuntimeEnabledFeatures::ForceEagerMeasureMemoryEnabled();
  }
  bool forceLoadAtTopEnabled() {
    return RuntimeEnabledFeatures::ForceLoadAtTopEnabledByRuntimeFlag();
  }
  bool forceOverlayFullscreenVideoEnabled() {
    return RuntimeEnabledFeatures::ForceOverlayFullscreenVideoEnabled();
  }
  bool forceSynchronousHTMLParsingEnabled() {
    return RuntimeEnabledFeatures::ForceSynchronousHTMLParsingEnabled();
  }
  bool forceTallerSelectPopupEnabled() {
    return RuntimeEnabledFeatures::ForceTallerSelectPopupEnabled();
  }
  bool fractionalScrollOffsetsEnabled() {
    return RuntimeEnabledFeatures::FractionalScrollOffsetsEnabled();
  }
  bool freezeFramesOnVisibilityEnabled() {
    return RuntimeEnabledFeatures::FreezeFramesOnVisibilityEnabled();
  }
  bool gamepadButtonAxisEventsEnabled() {
    return RuntimeEnabledFeatures::GamepadButtonAxisEventsEnabled();
  }
  bool getDisplayMediaEnabled() {
    return RuntimeEnabledFeatures::GetDisplayMediaEnabled();
  }
  bool groupEffectEnabled() {
    return RuntimeEnabledFeatures::GroupEffectEnabled();
  }
  bool hrefTranslateEnabled() {
    return RuntimeEnabledFeatures::HrefTranslateEnabledByRuntimeFlag();
  }
  bool htmlImportsEnabled() {
    return RuntimeEnabledFeatures::HTMLImportsEnabledByRuntimeFlag();
  }
  bool idbObserverEnabled() {
    return RuntimeEnabledFeatures::IDBObserverEnabled();
  }
  bool idbRelaxedDurabilityEnabled() {
    return RuntimeEnabledFeatures::IDBRelaxedDurabilityEnabled();
  }
  bool idleDetectionEnabled() {
    return RuntimeEnabledFeatures::IdleDetectionEnabledByRuntimeFlag();
  }
  bool ignoreCrossOriginWindowWhenNamedAccessOnWindowEnabled() {
    return RuntimeEnabledFeatures::IgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabled();
  }
  bool imageOrientationEnabled() {
    return RuntimeEnabledFeatures::ImageOrientationEnabled();
  }
  bool implicitRootScrollerEnabled() {
    return RuntimeEnabledFeatures::ImplicitRootScrollerEnabled();
  }
  bool importMapsEnabled() {
    return RuntimeEnabledFeatures::ImportMapsEnabled();
  }
  bool inertAttributeEnabled() {
    return RuntimeEnabledFeatures::InertAttributeEnabled();
  }
  bool inputElementRawValueEnabled() {
    return RuntimeEnabledFeatures::InputElementRawValueEnabled();
  }
  bool inputMultipleFieldsUIEnabled() {
    return RuntimeEnabledFeatures::InputMultipleFieldsUIEnabled();
  }
  bool installedAppEnabled() {
    return RuntimeEnabledFeatures::InstalledAppEnabled();
  }
  bool intersectionObserverDocumentScrollingElementRootEnabled() {
    return RuntimeEnabledFeatures::IntersectionObserverDocumentScrollingElementRootEnabled();
  }
  bool isolatedCodeCacheEnabled() {
    return RuntimeEnabledFeatures::IsolatedCodeCacheEnabled();
  }
  bool isolatedWorldCSPEnabled() {
    return RuntimeEnabledFeatures::IsolatedWorldCSPEnabled();
  }
  bool keyboardFocusableScrollersEnabled() {
    return RuntimeEnabledFeatures::KeyboardFocusableScrollersEnabled();
  }
  bool langAttributeAwareFormControlUIEnabled() {
    return RuntimeEnabledFeatures::LangAttributeAwareFormControlUIEnabled();
  }
  bool langClientHintHeaderEnabled() {
    return RuntimeEnabledFeatures::LangClientHintHeaderEnabled();
  }
  bool layoutNGEnabled() {
    return RuntimeEnabledFeatures::LayoutNGEnabled();
  }
  bool layoutNGBlockFragmentationEnabled() {
    return RuntimeEnabledFeatures::LayoutNGBlockFragmentationEnabled();
  }
  bool layoutNGFieldsetEnabled() {
    return RuntimeEnabledFeatures::LayoutNGFieldsetEnabled();
  }
  bool layoutNGFlexBoxEnabled() {
    return RuntimeEnabledFeatures::LayoutNGFlexBoxEnabled();
  }
  bool layoutNGForControlsEnabled() {
    return RuntimeEnabledFeatures::LayoutNGForControlsEnabled();
  }
  bool layoutNGFragmentItemEnabled() {
    return RuntimeEnabledFeatures::LayoutNGFragmentItemEnabled();
  }
  bool layoutNGFragmentTraversalEnabled() {
    return RuntimeEnabledFeatures::LayoutNGFragmentTraversalEnabled();
  }
  bool layoutNGGridEnabled() {
    return RuntimeEnabledFeatures::LayoutNGGridEnabled();
  }
  bool layoutNGRubyEnabled() {
    return RuntimeEnabledFeatures::LayoutNGRubyEnabled();
  }
  bool layoutNGTableEnabled() {
    return RuntimeEnabledFeatures::LayoutNGTableEnabled();
  }
  bool layoutShiftAttributionEnabled() {
    return RuntimeEnabledFeatures::LayoutShiftAttributionEnabled();
  }
  bool lazyFrameLoadingEnabled() {
    return RuntimeEnabledFeatures::LazyFrameLoadingEnabled();
  }
  bool lazyFrameVisibleLoadTimeMetricsEnabled() {
    return RuntimeEnabledFeatures::LazyFrameVisibleLoadTimeMetricsEnabled();
  }
  bool lazyImageLoadingEnabled() {
    return RuntimeEnabledFeatures::LazyImageLoadingEnabled();
  }
  bool lazyImageVisibleLoadTimeMetricsEnabled() {
    return RuntimeEnabledFeatures::LazyImageVisibleLoadTimeMetricsEnabled();
  }
  bool lazyInitializeMediaControlsEnabled() {
    return RuntimeEnabledFeatures::LazyInitializeMediaControlsEnabled();
  }
  bool legacyNativeFileSystemEnabled() {
    return RuntimeEnabledFeatures::LegacyNativeFileSystemEnabledByRuntimeFlag();
  }
  bool legacyWindowsDWriteFontFallbackEnabled() {
    return RuntimeEnabledFeatures::LegacyWindowsDWriteFontFallbackEnabled();
  }
  bool linkDisabledNewSpecBehaviorEnabled() {
    return RuntimeEnabledFeatures::LinkDisabledNewSpecBehaviorEnabled();
  }
  bool manualSlottingEnabled() {
    return RuntimeEnabledFeatures::ManualSlottingEnabled();
  }
  bool mathmlCoreEnabled() {
    return RuntimeEnabledFeatures::MathMLCoreEnabled();
  }
  bool measureMemoryEnabled() {
    return RuntimeEnabledFeatures::MeasureMemoryEnabledByRuntimeFlag();
  }
  bool mediaCapabilitiesDynamicRangeEnabled() {
    return RuntimeEnabledFeatures::MediaCapabilitiesDynamicRangeEnabled();
  }
  bool mediaCapabilitiesEncodingInfoEnabled() {
    return RuntimeEnabledFeatures::MediaCapabilitiesEncodingInfoEnabled();
  }
  bool mediaCapabilitiesEncryptedMediaEnabled() {
    return RuntimeEnabledFeatures::MediaCapabilitiesEncryptedMediaEnabled();
  }
  bool mediaCapabilitiesSpatialAudioEnabled() {
    return RuntimeEnabledFeatures::MediaCapabilitiesSpatialAudioEnabled();
  }
  bool mediaCaptureEnabled() {
    return RuntimeEnabledFeatures::MediaCaptureEnabled();
  }
  bool mediaCaptureDepthVideoKindEnabled() {
    return RuntimeEnabledFeatures::MediaCaptureDepthVideoKindEnabled();
  }
  bool mediaCapturePanTiltEnabled() {
    return RuntimeEnabledFeatures::MediaCapturePanTiltEnabled();
  }
  bool mediaCastOverlayButtonEnabled() {
    return RuntimeEnabledFeatures::MediaCastOverlayButtonEnabled();
  }
  bool mediaControlsExpandGestureEnabled() {
    return RuntimeEnabledFeatures::MediaControlsExpandGestureEnabled();
  }
  bool mediaControlsOverlayPlayButtonEnabled() {
    return RuntimeEnabledFeatures::MediaControlsOverlayPlayButtonEnabled();
  }
  bool mediaControlsUseCutOutByDefaultEnabled() {
    return RuntimeEnabledFeatures::MediaControlsUseCutOutByDefaultEnabled();
  }
  bool mediaDocumentDownloadButtonEnabled() {
    return RuntimeEnabledFeatures::MediaDocumentDownloadButtonEnabled();
  }
  bool mediaElementVolumeGreaterThanOneEnabled() {
    return RuntimeEnabledFeatures::MediaElementVolumeGreaterThanOneEnabled();
  }
  bool mediaEngagementBypassAutoplayPoliciesEnabled() {
    return RuntimeEnabledFeatures::MediaEngagementBypassAutoplayPoliciesEnabled();
  }
  bool mediaFeedsEnabled() {
    return RuntimeEnabledFeatures::MediaFeedsEnabled();
  }
  bool mediaLatencyHintEnabled() {
    return RuntimeEnabledFeatures::MediaLatencyHintEnabled();
  }
  bool mediaQueryNavigationControlsEnabled() {
    return RuntimeEnabledFeatures::MediaQueryNavigationControlsEnabled();
  }
  bool mediaSessionEnabled() {
    return RuntimeEnabledFeatures::MediaSessionEnabled();
  }
  bool mediaSessionPositionEnabled() {
    return RuntimeEnabledFeatures::MediaSessionPositionEnabled();
  }
  bool mediaSourceExperimentalEnabled() {
    return RuntimeEnabledFeatures::MediaSourceExperimentalEnabled();
  }
  bool mediaSourceInWorkersEnabled() {
    return RuntimeEnabledFeatures::MediaSourceInWorkersEnabled();
  }
  bool mediaSourceNewAbortAndDurationEnabled() {
    return RuntimeEnabledFeatures::MediaSourceNewAbortAndDurationEnabled();
  }
  bool mediaSourceStableEnabled() {
    return RuntimeEnabledFeatures::MediaSourceStableEnabled();
  }
  bool metaColorSchemeEnabled() {
    return RuntimeEnabledFeatures::MetaColorSchemeEnabled();
  }
  bool middleClickAutoscrollEnabled() {
    return RuntimeEnabledFeatures::MiddleClickAutoscrollEnabled();
  }
  bool mobileLayoutThemeEnabled() {
    return RuntimeEnabledFeatures::MobileLayoutThemeEnabled();
  }
  bool moduleServiceWorkerEnabled() {
    return RuntimeEnabledFeatures::ModuleServiceWorkerEnabled();
  }
  bool moduleSharedWorkerEnabled() {
    return RuntimeEnabledFeatures::ModuleSharedWorkerEnabled();
  }
  bool mojoJSEnabled() {
    return RuntimeEnabledFeatures::MojoJSEnabled();
  }
  bool mojoJSTestEnabled() {
    return RuntimeEnabledFeatures::MojoJSTestEnabled();
  }
  bool mouseSubframeNoImplicitCaptureEnabled() {
    return RuntimeEnabledFeatures::MouseSubframeNoImplicitCaptureEnabled();
  }
  bool namedPagesEnabled() {
    return RuntimeEnabledFeatures::NamedPagesEnabled();
  }
  bool nativeFileSystemEnabled() {
    return RuntimeEnabledFeatures::NativeFileSystemEnabledByRuntimeFlag();
  }
  bool nativeIOEnabled() {
    return RuntimeEnabledFeatures::NativeIOEnabled();
  }
  bool navigatorContentUtilsEnabled() {
    return RuntimeEnabledFeatures::NavigatorContentUtilsEnabled();
  }
  bool navigatorLanguageInInsecureContextEnabled() {
    return RuntimeEnabledFeatures::NavigatorLanguageInInsecureContextEnabled();
  }
  bool netInfoDownlinkMaxEnabled() {
    return RuntimeEnabledFeatures::NetInfoDownlinkMaxEnabled();
  }
  bool neverSlowModeEnabled() {
    return RuntimeEnabledFeatures::NeverSlowModeEnabled();
  }
  bool newCanvas2DAPIEnabled() {
    return RuntimeEnabledFeatures::NewCanvas2DAPIEnabled();
  }
  bool newRemotePlaybackPipelineEnabled() {
    return RuntimeEnabledFeatures::NewRemotePlaybackPipelineEnabled();
  }
  bool noIdleEncodingForWebTestsEnabled() {
    return RuntimeEnabledFeatures::NoIdleEncodingForWebTestsEnabled();
  }
  bool notificationConstructorEnabled() {
    return RuntimeEnabledFeatures::NotificationConstructorEnabled();
  }
  bool notificationContentImageEnabled() {
    return RuntimeEnabledFeatures::NotificationContentImageEnabled();
  }
  bool notificationsEnabled() {
    return RuntimeEnabledFeatures::NotificationsEnabled();
  }
  bool notificationTriggersEnabled() {
    return RuntimeEnabledFeatures::NotificationTriggersEnabledByRuntimeFlag();
  }
  bool offMainThreadCSSPaintEnabled() {
    return RuntimeEnabledFeatures::OffMainThreadCSSPaintEnabled();
  }
  bool offscreenCanvasCommitEnabled() {
    return RuntimeEnabledFeatures::OffscreenCanvasCommitEnabled();
  }
  bool onDeviceChangeEnabled() {
    return RuntimeEnabledFeatures::OnDeviceChangeEnabled();
  }
  bool orientationEventEnabled() {
    return RuntimeEnabledFeatures::OrientationEventEnabled();
  }
  bool originIsolationHeaderEnabled() {
    return RuntimeEnabledFeatures::OriginIsolationHeaderEnabledByRuntimeFlag();
  }
  bool originPolicyEnabled() {
    return RuntimeEnabledFeatures::OriginPolicyEnabled();
  }
  bool originTrialsSampleAPIEnabled() {
    return RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabledByRuntimeFlag();
  }
  bool originTrialsSampleAPIDependentEnabled() {
    return RuntimeEnabledFeatures::OriginTrialsSampleAPIDependentEnabledByRuntimeFlag();
  }
  bool originTrialsSampleAPIDeprecationEnabled() {
    return RuntimeEnabledFeatures::OriginTrialsSampleAPIDeprecationEnabledByRuntimeFlag();
  }
  bool originTrialsSampleAPIImpliedEnabled() {
    return RuntimeEnabledFeatures::OriginTrialsSampleAPIImpliedEnabledByRuntimeFlag();
  }
  bool originTrialsSampleAPIInvalidOSEnabled() {
    return RuntimeEnabledFeatures::OriginTrialsSampleAPIInvalidOSEnabledByRuntimeFlag();
  }
  bool originTrialsSampleAPINavigationEnabled() {
    return RuntimeEnabledFeatures::OriginTrialsSampleAPINavigationEnabledByRuntimeFlag();
  }
  bool originTrialsSampleAPIThirdPartyEnabled() {
    return RuntimeEnabledFeatures::OriginTrialsSampleAPIThirdPartyEnabledByRuntimeFlag();
  }
  bool outOfBlinkCorsEnabled() {
    return RuntimeEnabledFeatures::OutOfBlinkCorsEnabled();
  }
  bool overflowIconsForMediaControlsEnabled() {
    return RuntimeEnabledFeatures::OverflowIconsForMediaControlsEnabled();
  }
  bool overscrollCustomizationEnabled() {
    return RuntimeEnabledFeatures::OverscrollCustomizationEnabled();
  }
  bool pageFreezeOptInEnabled() {
    return RuntimeEnabledFeatures::PageFreezeOptInEnabledByRuntimeFlag();
  }
  bool pageFreezeOptOutEnabled() {
    return RuntimeEnabledFeatures::PageFreezeOptOutEnabledByRuntimeFlag();
  }
  bool pagePopupEnabled() {
    return RuntimeEnabledFeatures::PagePopupEnabled();
  }
  bool paintUnderInvalidationCheckingEnabled() {
    return RuntimeEnabledFeatures::PaintUnderInvalidationCheckingEnabled();
  }
  bool parseUrlProtocolHandlerEnabled() {
    return RuntimeEnabledFeatures::ParseUrlProtocolHandlerEnabled();
  }
  bool passPaintVisualRectToCompositorEnabled() {
    return RuntimeEnabledFeatures::PassPaintVisualRectToCompositorEnabled();
  }
  bool passwordRevealEnabled() {
    return RuntimeEnabledFeatures::PasswordRevealEnabled();
  }
  bool paymentAppEnabled() {
    return RuntimeEnabledFeatures::PaymentAppEnabled();
  }
  bool paymentHandlerChangePaymentMethodEnabled() {
    return RuntimeEnabledFeatures::PaymentHandlerChangePaymentMethodEnabled();
  }
  bool paymentHandlerHandlesShippingAndContactEnabled() {
    return RuntimeEnabledFeatures::PaymentHandlerHandlesShippingAndContactEnabled();
  }
  bool paymentHandlerMinimalUIEnabled() {
    return RuntimeEnabledFeatures::PaymentHandlerMinimalUIEnabled();
  }
  bool paymentMethodChangeEventEnabled() {
    return RuntimeEnabledFeatures::PaymentMethodChangeEventEnabled();
  }
  bool paymentRequestEnabled() {
    return RuntimeEnabledFeatures::PaymentRequestEnabled();
  }
  bool paymentRequestMerchantValidationEventEnabled() {
    return RuntimeEnabledFeatures::PaymentRequestMerchantValidationEventEnabled();
  }
  bool paymentRetryEnabled() {
    return RuntimeEnabledFeatures::PaymentRetryEnabled();
  }
  bool percentBasedScrollingEnabled() {
    return RuntimeEnabledFeatures::PercentBasedScrollingEnabled();
  }
  bool performanceManagerInstrumentationEnabled() {
    return RuntimeEnabledFeatures::PerformanceManagerInstrumentationEnabled();
  }
  bool periodicBackgroundSyncEnabled() {
    return RuntimeEnabledFeatures::PeriodicBackgroundSyncEnabled();
  }
  bool perMethodCanMakePaymentQuotaEnabled() {
    return RuntimeEnabledFeatures::PerMethodCanMakePaymentQuotaEnabledByRuntimeFlag();
  }
  bool permissionDelegationEnabled() {
    return RuntimeEnabledFeatures::PermissionDelegationEnabled();
  }
  bool permissionsEnabled() {
    return RuntimeEnabledFeatures::PermissionsEnabled();
  }
  bool permissionsRequestRevokeEnabled() {
    return RuntimeEnabledFeatures::PermissionsRequestRevokeEnabled();
  }
  bool pictureInPictureEnabled() {
    return RuntimeEnabledFeatures::PictureInPictureEnabled();
  }
  bool pictureInPictureAPIEnabled() {
    return RuntimeEnabledFeatures::PictureInPictureAPIEnabled();
  }
  bool pictureInPictureV2Enabled() {
    return RuntimeEnabledFeatures::PictureInPictureV2Enabled();
  }
  bool pNaClEnabled() {
    return RuntimeEnabledFeatures::PNaClEnabledByRuntimeFlag();
  }
  bool pointerLockOptionsEnabled() {
    return RuntimeEnabledFeatures::PointerLockOptionsEnabledByRuntimeFlag();
  }
  bool pointerRawUpdateEnabled() {
    return RuntimeEnabledFeatures::PointerRawUpdateEnabled();
  }
  bool portalsEnabled() {
    return RuntimeEnabledFeatures::PortalsEnabledByRuntimeFlag();
  }
  bool postAnimationFrameEnabled() {
    return RuntimeEnabledFeatures::PostAnimationFrameEnabled();
  }
  bool preciseMemoryInfoEnabled() {
    return RuntimeEnabledFeatures::PreciseMemoryInfoEnabled();
  }
  bool preferNonCompositedScrollingEnabled() {
    return RuntimeEnabledFeatures::PreferNonCompositedScrollingEnabled();
  }
  bool prefersReducedDataEnabled() {
    return RuntimeEnabledFeatures::PrefersReducedDataEnabled();
  }
  bool prefixedVideoFullscreenEnabled() {
    return RuntimeEnabledFeatures::PrefixedVideoFullscreenEnabled();
  }
  bool presentationEnabled() {
    return RuntimeEnabledFeatures::PresentationEnabled();
  }
  bool priorityHintsEnabled() {
    return RuntimeEnabledFeatures::PriorityHintsEnabledByRuntimeFlag();
  }
  bool pushMessagingEnabled() {
    return RuntimeEnabledFeatures::PushMessagingEnabled();
  }
  bool pushMessagingSubscriptionChangeEnabled() {
    return RuntimeEnabledFeatures::PushMessagingSubscriptionChangeEnabled();
  }
  bool quicTransportEnabled() {
    return RuntimeEnabledFeatures::QuicTransportEnabledByRuntimeFlag();
  }
  bool rawClipboardEnabled() {
    return RuntimeEnabledFeatures::RawClipboardEnabled();
  }
  bool reducedReferrerGranularityEnabled() {
    return RuntimeEnabledFeatures::ReducedReferrerGranularityEnabled();
  }
  bool remotePlaybackEnabled() {
    return RuntimeEnabledFeatures::RemotePlaybackEnabled();
  }
  bool remotePlaybackBackendEnabled() {
    return RuntimeEnabledFeatures::RemotePlaybackBackendEnabled();
  }
  bool requestVideoFrameCallbackEnabled() {
    return RuntimeEnabledFeatures::RequestVideoFrameCallbackEnabled();
  }
  bool resizeObserverUpdatesEnabled() {
    return RuntimeEnabledFeatures::ResizeObserverUpdatesEnabled();
  }
  bool restrictAppCacheToSecureContextsEnabled() {
    return RuntimeEnabledFeatures::RestrictAppCacheToSecureContextsEnabled();
  }
  bool restrictAutomaticLazyFrameLoadingToDataSaverEnabled() {
    return RuntimeEnabledFeatures::RestrictAutomaticLazyFrameLoadingToDataSaverEnabled();
  }
  bool restrictAutomaticLazyImageLoadingToDataSaverEnabled() {
    return RuntimeEnabledFeatures::RestrictAutomaticLazyImageLoadingToDataSaverEnabled();
  }
  bool rtcAudioJitterBufferMaxPacketsEnabled() {
    return RuntimeEnabledFeatures::RtcAudioJitterBufferMaxPacketsEnabledByRuntimeFlag();
  }
  bool rtcAudioJitterBufferRtxHandlingEnabled() {
    return RuntimeEnabledFeatures::RtcAudioJitterBufferRtxHandlingEnabledByRuntimeFlag();
  }
  bool rtcIceTransportExtensionEnabled() {
    return RuntimeEnabledFeatures::RTCIceTransportExtensionEnabledByRuntimeFlag();
  }
  bool rtcInsertableStreamsEnabled() {
    return RuntimeEnabledFeatures::RTCInsertableStreamsEnabledByRuntimeFlag();
  }
  bool rtcQuicTransportEnabled() {
    return RuntimeEnabledFeatures::RTCQuicTransportEnabledByRuntimeFlag();
  }
  bool rtcStatsRelativePacketArrivalDelayEnabled() {
    return RuntimeEnabledFeatures::RTCStatsRelativePacketArrivalDelayEnabledByRuntimeFlag();
  }
  bool rtcSvcScalabilityModeEnabled() {
    return RuntimeEnabledFeatures::RTCSvcScalabilityModeEnabled();
  }
  bool rtcUnifiedPlanEnabled() {
    return RuntimeEnabledFeatures::RTCUnifiedPlanEnabled();
  }
  bool rtcUnifiedPlanByDefaultEnabled() {
    return RuntimeEnabledFeatures::RTCUnifiedPlanByDefaultEnabled();
  }
  bool sameSiteByDefaultCookiesEnabled() {
    return RuntimeEnabledFeatures::SameSiteByDefaultCookiesEnabled();
  }
  bool screenWakeLockEnabled() {
    return RuntimeEnabledFeatures::ScreenWakeLockEnabled();
  }
  bool scriptedSpeechRecognitionEnabled() {
    return RuntimeEnabledFeatures::ScriptedSpeechRecognitionEnabled();
  }
  bool scriptedSpeechSynthesisEnabled() {
    return RuntimeEnabledFeatures::ScriptedSpeechSynthesisEnabled();
  }
  bool scrollCustomizationEnabled() {
    return RuntimeEnabledFeatures::ScrollCustomizationEnabled();
  }
  bool scrollSnapAfterLayoutEnabled() {
    return RuntimeEnabledFeatures::ScrollSnapAfterLayoutEnabled();
  }
  bool scrollTimelineEnabled() {
    return RuntimeEnabledFeatures::ScrollTimelineEnabled();
  }
  bool scrollTopLeftInteropEnabled() {
    return RuntimeEnabledFeatures::ScrollTopLeftInteropEnabled();
  }
  bool scrollUnificationEnabled() {
    return RuntimeEnabledFeatures::ScrollUnificationEnabled();
  }
  bool sendBeaconThrowForBlobWithNonSimpleTypeEnabled() {
    return RuntimeEnabledFeatures::SendBeaconThrowForBlobWithNonSimpleTypeEnabled();
  }
  bool sendMouseEventsDisabledFormControlsEnabled() {
    return RuntimeEnabledFeatures::SendMouseEventsDisabledFormControlsEnabled();
  }
  bool sensorExtraClassesEnabled() {
    return RuntimeEnabledFeatures::SensorExtraClassesEnabled();
  }
  bool serialEnabled() {
    return RuntimeEnabledFeatures::SerialEnabledByRuntimeFlag();
  }
  bool serviceWorkerClientLifecycleStateEnabled() {
    return RuntimeEnabledFeatures::ServiceWorkerClientLifecycleStateEnabled();
  }
  bool serviceWorkerFetchEventWorkerTimingEnabled() {
    return RuntimeEnabledFeatures::ServiceWorkerFetchEventWorkerTimingEnabled();
  }
  bool shadowDOMV0Enabled() {
    return RuntimeEnabledFeatures::ShadowDOMV0EnabledByRuntimeFlag();
  }
  bool sharedArrayBufferEnabled() {
    return RuntimeEnabledFeatures::SharedArrayBufferEnabled();
  }
  bool sharedWorkerEnabled() {
    return RuntimeEnabledFeatures::SharedWorkerEnabled();
  }
  bool signatureBasedIntegrityEnabled() {
    return RuntimeEnabledFeatures::SignatureBasedIntegrityEnabledByRuntimeFlag();
  }
  bool signedExchangePrefetchCacheForNavigationsEnabled() {
    return RuntimeEnabledFeatures::SignedExchangePrefetchCacheForNavigationsEnabled();
  }
  bool signedExchangeSubresourcePrefetchEnabled() {
    return RuntimeEnabledFeatures::SignedExchangeSubresourcePrefetchEnabledByRuntimeFlag();
  }
  bool skipAdEnabled() {
    return RuntimeEnabledFeatures::SkipAdEnabledByRuntimeFlag();
  }
  bool skipTouchEventFilterEnabled() {
    return RuntimeEnabledFeatures::SkipTouchEventFilterEnabled();
  }
  bool smsReceiverEnabled() {
    return RuntimeEnabledFeatures::SmsReceiverEnabled();
  }
  bool squashAfterPaintEnabled() {
    return RuntimeEnabledFeatures::SquashAfterPaintEnabled();
  }
  bool stableBlinkFeaturesEnabled() {
    return RuntimeEnabledFeatures::StableBlinkFeaturesEnabled();
  }
  bool storageAccessAPIEnabled() {
    return RuntimeEnabledFeatures::StorageAccessAPIEnabled();
  }
  bool strictMimeTypesForWorkersEnabled() {
    return RuntimeEnabledFeatures::StrictMimeTypesForWorkersEnabled();
  }
  bool subresourceWebBundlesEnabled() {
    return RuntimeEnabledFeatures::SubresourceWebBundlesEnabled();
  }
  bool surfaceEmbeddingFeaturesEnabled() {
    return RuntimeEnabledFeatures::SurfaceEmbeddingFeaturesEnabled();
  }
  bool systemWakeLockEnabled() {
    return RuntimeEnabledFeatures::SystemWakeLockEnabled();
  }
  bool testFeatureEnabled() {
    return RuntimeEnabledFeatures::TestFeatureEnabled();
  }
  bool testFeatureDependentEnabled() {
    return RuntimeEnabledFeatures::TestFeatureDependentEnabled();
  }
  bool testFeatureImpliedEnabled() {
    return RuntimeEnabledFeatures::TestFeatureImpliedEnabled();
  }
  bool textDetectorEnabled() {
    return RuntimeEnabledFeatures::TextDetectorEnabled();
  }
  bool textFragmentIdentifiersEnabled() {
    return RuntimeEnabledFeatures::TextFragmentIdentifiersEnabledByRuntimeFlag();
  }
  bool thirdPartyOriginTrialsEnabled() {
    return RuntimeEnabledFeatures::ThirdPartyOriginTrialsEnabled();
  }
  bool timerThrottlingForBackgroundTabsEnabled() {
    return RuntimeEnabledFeatures::TimerThrottlingForBackgroundTabsEnabled();
  }
  bool timerThrottlingForHiddenFramesEnabled() {
    return RuntimeEnabledFeatures::TimerThrottlingForHiddenFramesEnabled();
  }
  bool timeZoneChangeEventEnabled() {
    return RuntimeEnabledFeatures::TimeZoneChangeEventEnabled();
  }
  bool touchEventFeatureDetectionEnabled() {
    return RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabledByRuntimeFlag();
  }
  bool trackLayoutPassesPerBlockEnabled() {
    return RuntimeEnabledFeatures::TrackLayoutPassesPerBlockEnabled();
  }
  bool transferableStreamsEnabled() {
    return RuntimeEnabledFeatures::TransferableStreamsEnabledByRuntimeFlag();
  }
  bool transformInteropEnabled() {
    return RuntimeEnabledFeatures::TransformInteropEnabled();
  }
  bool translateServiceEnabled() {
    return RuntimeEnabledFeatures::TranslateServiceEnabled();
  }
  bool trustedDOMTypesEnabled() {
    return RuntimeEnabledFeatures::TrustedDOMTypesEnabled();
  }
  bool trustTokensEnabled() {
    return RuntimeEnabledFeatures::TrustTokensEnabledByRuntimeFlag();
  }
  bool trustTokensAlwaysAllowIssuanceEnabled() {
    return RuntimeEnabledFeatures::TrustTokensAlwaysAllowIssuanceEnabled();
  }
  bool unclosedFormControlIsInvalidEnabled() {
    return RuntimeEnabledFeatures::UnclosedFormControlIsInvalidEnabled();
  }
  bool underlineOffsetThicknessEnabled() {
    return RuntimeEnabledFeatures::UnderlineOffsetThicknessEnabled();
  }
  bool unoptimizedImagePoliciesEnabled() {
    return RuntimeEnabledFeatures::UnoptimizedImagePoliciesEnabledByRuntimeFlag();
  }
  bool unsizedMediaPolicyEnabled() {
    return RuntimeEnabledFeatures::UnsizedMediaPolicyEnabledByRuntimeFlag();
  }
  bool userActivationPostMessageTransferEnabled() {
    return RuntimeEnabledFeatures::UserActivationPostMessageTransferEnabled();
  }
  bool userActivationSameOriginVisibilityEnabled() {
    return RuntimeEnabledFeatures::UserActivationSameOriginVisibilityEnabled();
  }
  bool userAgentClientHintEnabled() {
    return RuntimeEnabledFeatures::UserAgentClientHintEnabled();
  }
  bool v8IdleTasksEnabled() {
    return RuntimeEnabledFeatures::V8IdleTasksEnabled();
  }
  bool videoAutoFullscreenEnabled() {
    return RuntimeEnabledFeatures::VideoAutoFullscreenEnabled();
  }
  bool videoFullscreenOrientationLockEnabled() {
    return RuntimeEnabledFeatures::VideoFullscreenOrientationLockEnabled();
  }
  bool videoPlaybackQualityEnabled() {
    return RuntimeEnabledFeatures::VideoPlaybackQualityEnabled();
  }
  bool videoRotateToFullscreenEnabled() {
    return RuntimeEnabledFeatures::VideoRotateToFullscreenEnabled();
  }
  bool videoWakeLockOptimisationHiddenMutedEnabled() {
    return RuntimeEnabledFeatures::VideoWakeLockOptimisationHiddenMutedEnabled();
  }
  bool virtualKeyboardEnabled() {
    return RuntimeEnabledFeatures::VirtualKeyboardEnabled();
  }
  bool visibilityCollapseColumnEnabled() {
    return RuntimeEnabledFeatures::VisibilityCollapseColumnEnabled();
  }
  bool wakeLockEnabled() {
    return RuntimeEnabledFeatures::WakeLockEnabledByRuntimeFlag();
  }
  bool webAnimationsAPIEnabled() {
    return RuntimeEnabledFeatures::WebAnimationsAPIEnabled();
  }
  bool webAnimationsSVGEnabled() {
    return RuntimeEnabledFeatures::WebAnimationsSVGEnabled();
  }
  bool webAssemblySimdEnabled() {
    return RuntimeEnabledFeatures::WebAssemblySimdEnabledByRuntimeFlag();
  }
  bool webAssemblyThreadsEnabled() {
    return RuntimeEnabledFeatures::WebAssemblyThreadsEnabledByRuntimeFlag();
  }
  bool webAuthEnabled() {
    return RuntimeEnabledFeatures::WebAuthEnabled();
  }
  bool webAuthenticationGetAssertionFeaturePolicyEnabled() {
    return RuntimeEnabledFeatures::WebAuthenticationGetAssertionFeaturePolicyEnabled();
  }
  bool webBluetoothEnabled() {
    return RuntimeEnabledFeatures::WebBluetoothEnabled();
  }
  bool webBluetoothGetDevicesEnabled() {
    return RuntimeEnabledFeatures::WebBluetoothGetDevicesEnabled();
  }
  bool webBluetoothRemoteCharacteristicNewWriteValueEnabled() {
    return RuntimeEnabledFeatures::WebBluetoothRemoteCharacteristicNewWriteValueEnabled();
  }
  bool webBluetoothScanningEnabled() {
    return RuntimeEnabledFeatures::WebBluetoothScanningEnabled();
  }
  bool webBluetoothWatchAdvertisementsEnabled() {
    return RuntimeEnabledFeatures::WebBluetoothWatchAdvertisementsEnabled();
  }
  bool webCodecsEnabled() {
    return RuntimeEnabledFeatures::WebCodecsEnabled();
  }
  bool webCryptoCurve25519Enabled() {
    return RuntimeEnabledFeatures::WebCryptoCurve25519Enabled();
  }
  bool webgl2ComputeContextEnabled() {
    return RuntimeEnabledFeatures::WebGL2ComputeContextEnabled();
  }
  bool webglDraftExtensionsEnabled() {
    return RuntimeEnabledFeatures::WebGLDraftExtensionsEnabled();
  }
  bool webglImageChromiumEnabled() {
    return RuntimeEnabledFeatures::WebGLImageChromiumEnabled();
  }
  bool webgpuEnabled() {
    return RuntimeEnabledFeatures::WebGPUEnabled();
  }
  bool webHIDEnabled() {
    return RuntimeEnabledFeatures::WebHIDEnabled();
  }
  bool webNFCEnabled() {
    return RuntimeEnabledFeatures::WebNFCEnabledByRuntimeFlag();
  }
  bool webSchedulerEnabled() {
    return RuntimeEnabledFeatures::WebSchedulerEnabledByRuntimeFlag();
  }
  bool webShareEnabled() {
    return RuntimeEnabledFeatures::WebShareEnabled();
  }
  bool webShareV2Enabled() {
    return RuntimeEnabledFeatures::WebShareV2Enabled();
  }
  bool websocketStreamEnabled() {
    return RuntimeEnabledFeatures::WebSocketStreamEnabled();
  }
  bool webUSBEnabled() {
    return RuntimeEnabledFeatures::WebUSBEnabled();
  }
  bool webUSBOnDedicatedWorkersEnabled() {
    return RuntimeEnabledFeatures::WebUSBOnDedicatedWorkersEnabled();
  }
  bool webVTTRegionsEnabled() {
    return RuntimeEnabledFeatures::WebVTTRegionsEnabled();
  }
  bool webXREnabled() {
    return RuntimeEnabledFeatures::WebXREnabled();
  }
  bool webXRAnchorsEnabled() {
    return RuntimeEnabledFeatures::WebXRAnchorsEnabled();
  }
  bool webXRARModuleEnabled() {
    return RuntimeEnabledFeatures::WebXRARModuleEnabled();
  }
  bool webXRCameraAccessEnabled() {
    return RuntimeEnabledFeatures::WebXRCameraAccessEnabled();
  }
  bool webXRHitTestEnabled() {
    return RuntimeEnabledFeatures::WebXRHitTestEnabled();
  }
  bool webXRHitTestEntityTypesEnabled() {
    return RuntimeEnabledFeatures::WebXRHitTestEntityTypesEnabled();
  }
  bool webXRLightEstimationEnabled() {
    return RuntimeEnabledFeatures::WebXRLightEstimationEnabled();
  }
  bool webXRPlaneDetectionEnabled() {
    return RuntimeEnabledFeatures::WebXRPlaneDetectionEnabled();
  }
  bool windowPlacementEnabled() {
    return RuntimeEnabledFeatures::WindowPlacementEnabled();
  }
  bool windowSegmentsEnabled() {
    return RuntimeEnabledFeatures::WindowSegmentsEnabled();
  }
  bool xsltEnabled() {
    return RuntimeEnabledFeatures::XSLTEnabled();
  }
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TESTING_INTERNAL_RUNTIME_FLAGS_H_
