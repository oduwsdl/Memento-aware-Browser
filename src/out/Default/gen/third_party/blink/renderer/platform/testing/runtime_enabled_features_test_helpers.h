// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_enabled_features_test_helpers.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_TEST_HELPERS_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_TEST_HELPERS_H_

#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/wtf/assertions.h"

namespace blink {

// Don't use this class directly. Use Scoped*ForTest instead.
class RuntimeEnabledFeaturesTestHelpers {
 public:
  template <bool& data_member>
  class ScopedRuntimeEnabledFeature {
   public:
    ScopedRuntimeEnabledFeature(bool enabled)
        : enabled_(enabled), original_(data_member) { data_member = enabled; }
    ~ScopedRuntimeEnabledFeature() {
      CHECK_EQ(enabled_, data_member);
      data_member = original_;
    }
   private:
    bool enabled_;
    bool original_;
  };

  using ScopedAccelerated2dCanvas = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_accelerated_2d_canvas_enabled_>;
  using ScopedAcceleratedSmallCanvases = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_accelerated_small_canvases_enabled_>;
  using ScopedAccessibilityExposeARIAAnnotations = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_accessibility_expose_aria_annotations_enabled_>;
  using ScopedAccessibilityExposeDisplayNone = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_accessibility_expose_display_none_enabled_>;
  using ScopedAccessibilityExposeHTMLElement = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_accessibility_expose_html_element_enabled_>;
  using ScopedAccessibilityObjectModel = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_accessibility_object_model_enabled_>;
  using ScopedAddressSpace = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_address_space_enabled_>;
  using ScopedAdTagging = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_ad_tagging_enabled_>;
  using ScopedAllowActivationDelegationAttr = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_allow_activation_delegation_attr_enabled_>;
  using ScopedAllowContentInitiatedDataUrlNavigations = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_allow_content_initiated_data_url_navigations_enabled_>;
  using ScopedAllowSyncXHRInPageDismissal = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_allow_sync_xhr_in_page_dismissal_enabled_>;
  using ScopedAnimationWorklet = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_animation_worklet_enabled_>;
  using ScopedAOMAriaProperties = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_aom_aria_properties_enabled_>;
  using ScopedAOMAriaRelationshipProperties = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_aom_aria_relationship_properties_enabled_>;
  using ScopedAppCache = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_app_cache_enabled_>;
  using ScopedAudioOutputDevices = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_audio_output_devices_enabled_>;
  using ScopedAudioVideoTracks = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_audio_video_tracks_enabled_>;
  using ScopedAudioWorkletRealtimeThread = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_audio_worklet_realtime_thread_enabled_>;
  using ScopedAutoLazyLoadOnReloads = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_auto_lazy_load_on_reloads_enabled_>;
  using ScopedAutomaticLazyFrameLoading = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_automatic_lazy_frame_loading_enabled_>;
  using ScopedAutomaticLazyImageLoading = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_automatic_lazy_image_loading_enabled_>;
  using ScopedAutomationControlled = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_automation_controlled_enabled_>;
  using ScopedAutoPictureInPicture = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_auto_picture_in_picture_enabled_>;
  using ScopedAutoplayIgnoresWebAudio = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_autoplay_ignores_web_audio_enabled_>;
  using ScopedBackForwardCache = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_back_forward_cache_enabled_>;
  using ScopedBackgroundFetch = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_background_fetch_enabled_>;
  using ScopedBackgroundVideoTrackOptimization = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_background_video_track_optimization_enabled_>;
  using ScopedBadging = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_badging_enabled_>;
  using ScopedBarcodeDetector = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_barcode_detector_enabled_>;
  using ScopedBeforeMatchEvent = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_before_match_event_enabled_>;
  using ScopedBidiCaretAffinity = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_bidi_caret_affinity_enabled_>;
  using ScopedBlinkRuntimeCallStats = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_blink_runtime_call_stats_enabled_>;
  using ScopedBlockCredentialedSubresources = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_block_credentialed_subresources_enabled_>;
  using ScopedBlockFlowHandlesWebkitLineClamp = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_block_flow_handles_webkit_line_clamp_enabled_>;
  using ScopedBlockHTMLParserOnStyleSheets = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_block_html_parser_on_style_sheets_enabled_>;
  using ScopedBlockingDownloadsInSandbox = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_blocking_downloads_in_sandbox_enabled_>;
  using ScopedBlockingFocusWithoutUserActivation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_blocking_focus_without_user_activation_enabled_>;
  using ScopedBrowserVerifiedUserActivationKeyboard = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_browser_verified_user_activation_keyboard_enabled_>;
  using ScopedBrowserVerifiedUserActivationMouse = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_browser_verified_user_activation_mouse_enabled_>;
  using ScopedCacheInlineScriptCode = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_cache_inline_script_code_enabled_>;
  using ScopedCacheStorageCodeCacheHint = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_cache_storage_code_cache_hint_enabled_>;
  using ScopedCanvas2dContextLostRestored = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_canvas_2d_context_lost_restored_enabled_>;
  using ScopedCanvas2dImageChromium = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_canvas_2d_image_chromium_enabled_>;
  using ScopedCanvas2dScrollPathIntoView = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_canvas_2d_scroll_path_into_view_enabled_>;
  using ScopedCanvasColorManagement = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_canvas_color_management_enabled_>;
  using ScopedCanvasHitRegion = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_canvas_hit_region_enabled_>;
  using ScopedCanvasImageSmoothing = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_canvas_image_smoothing_enabled_>;
  using ScopedCaptureTimeInCsrc = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_capture_time_in_csrc_enabled_>;
  using ScopedClickPointerEvent = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_click_pointer_event_enabled_>;
  using ScopedClickRetargetting = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_click_retargetting_enabled_>;
  using ScopedCompositeAfterPaint = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_composite_after_paint_enabled_>;
  using ScopedCompositedSelectionUpdate = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_composited_selection_update_enabled_>;
  using ScopedComputedAccessibilityInfo = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_computed_accessibility_info_enabled_>;
  using ScopedConsolidatedMovementXY = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_consolidated_movement_xy_enabled_>;
  using ScopedContactsManager = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_contacts_manager_enabled_>;
  using ScopedContactsManagerExtraProperties = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_contacts_manager_extra_properties_enabled_>;
  using ScopedContentIndex = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_content_index_enabled_>;
  using ScopedContextMenu = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_context_menu_enabled_>;
  using ScopedConversionMeasurement = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_conversion_measurement_enabled_>;
  using ScopedCookieDeprecationMessages = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_cookie_deprecation_messages_enabled_>;
  using ScopedCookieStoreDocument = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_cookie_store_document_enabled_>;
  using ScopedCookieStoreWorker = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_cookie_store_worker_enabled_>;
  using ScopedCookiesWithoutSameSiteMustBeSecure = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_cookies_without_same_site_must_be_secure_enabled_>;
  using ScopedCooperativeScheduling = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_cooperative_scheduling_enabled_>;
  using ScopedCorsRFC1918 = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_cors_rfc_1918_enabled_>;
  using ScopedCrossOriginIsolation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_cross_origin_isolation_enabled_>;
  using ScopedCSS3Text = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_3_text_enabled_>;
  using ScopedCSSAspectRatioProperty = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_aspect_ratio_property_enabled_>;
  using ScopedCSSCalcAsInt = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_calc_as_int_enabled_>;
  using ScopedCSSCascade = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_cascade_enabled_>;
  using ScopedCSSColorScheme = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_color_scheme_enabled_>;
  using ScopedCSSColorSchemeUARendering = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_color_scheme_ua_rendering_enabled_>;
  using ScopedCSSContentVisibility = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_content_visibility_enabled_>;
  using ScopedCSSContentVisibilityHiddenMatchable = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_content_visibility_hidden_matchable_enabled_>;
  using ScopedCSSFocusVisible = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_focus_visible_enabled_>;
  using ScopedCSSFoldables = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_foldables_enabled_>;
  using ScopedCSSFontSizeAdjust = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_font_size_adjust_enabled_>;
  using ScopedCSSHexAlphaColor = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_hex_alpha_color_enabled_>;
  using ScopedCSSIndependentTransformProperties = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_independent_transform_properties_enabled_>;
  using ScopedCSSLayoutAPI = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_layout_api_enabled_>;
  using ScopedCSSLogical = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_logical_enabled_>;
  using ScopedCSSLogicalOverflow = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_logical_overflow_enabled_>;
  using ScopedCSSMarkerNestedPseudoElement = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_marker_nested_pseudo_element_enabled_>;
  using ScopedCSSMarkerPseudoElement = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_marker_pseudo_element_enabled_>;
  using ScopedCSSMatchedPropertiesCacheDependencies = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_matched_properties_cache_dependencies_enabled_>;
  using ScopedCSSMathStyle = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_math_style_enabled_>;
  using ScopedCSSMathSuperscriptShiftStyle = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_math_superscript_shift_style_enabled_>;
  using ScopedCSSMathVariant = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_math_variant_enabled_>;
  using ScopedCSSModules = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_modules_enabled_>;
  using ScopedCSSOffsetPathRay = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_offset_path_ray_enabled_>;
  using ScopedCSSOffsetPathRayContain = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_offset_path_ray_contain_enabled_>;
  using ScopedCSSOffsetPositionAnchor = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_offset_position_anchor_enabled_>;
  using ScopedCSSOMViewScrollCoordinates = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_cssom_view_scroll_coordinates_enabled_>;
  using ScopedCSSPaintAPIArguments = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_paint_api_arguments_enabled_>;
  using ScopedCSSPictureInPicture = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_picture_in_picture_enabled_>;
  using ScopedCSSPseudoIs = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_pseudo_is_enabled_>;
  using ScopedCSSPseudoWhere = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_pseudo_where_enabled_>;
  using ScopedCSSReducedFontLoadingInvalidations = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_reduced_font_loading_invalidations_enabled_>;
  using ScopedCSSReducedFontLoadingLayoutInvalidations = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_reduced_font_loading_layout_invalidations_enabled_>;
  using ScopedCSSRevert = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_revert_enabled_>;
  using ScopedCSSScrollTimeline = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_scroll_timeline_enabled_>;
  using ScopedCSSSnapSize = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_snap_size_enabled_>;
  using ScopedCSSSupportsSelector = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_supports_selector_enabled_>;
  using ScopedCSSVariables2AtProperty = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_variables_2_at_property_enabled_>;
  using ScopedCSSVariables2ImageValues = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_variables_2_image_values_enabled_>;
  using ScopedCSSVariables2TransformValues = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_css_variables_2_transform_values_enabled_>;
  using ScopedCustomElementDefaultStyle = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_custom_element_default_style_enabled_>;
  using ScopedCustomElementsV0 = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_custom_elements_v0_enabled_>;
  using ScopedCustomStatePseudoClass = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_custom_state_pseudo_class_enabled_>;
  using ScopedDatabase = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_database_enabled_>;
  using ScopedDeclarativeShadowDOM = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_declarative_shadow_dom_enabled_>;
  using ScopedDecodeJpeg420ImagesToYUV = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_decode_jpeg_420_images_to_yuv_enabled_>;
  using ScopedDecodeLossyWebPImagesToYUV = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_decode_lossy_web_p_images_to_yuv_enabled_>;
  using ScopedDelayAsyncScriptExecutionUntilFinishedParsing = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_delay_async_script_execution_until_finished_parsing_enabled_>;
  using ScopedDelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsing = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_delay_async_script_execution_until_first_paint_or_finished_parsing_enabled_>;
  using ScopedDelegatedInkTrails = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_delegated_ink_trails_enabled_>;
  using ScopedDesktopCaptureDisableLocalEchoControl = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_desktop_capture_disable_local_echo_control_enabled_>;
  using ScopedDigitalGoods = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_digital_goods_enabled_>;
  using ScopedDisableHardwareNoiseSuppression = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_disable_hardware_noise_suppression_enabled_>;
  using ScopedDisableLayerSquashing = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_disable_layer_squashing_enabled_>;
  using ScopedDisallowDocumentAccess = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_disallow_document_access_enabled_>;
  using ScopedDisplayCutoutAPI = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_display_cutout_api_enabled_>;
  using ScopedDocumentCookie = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_document_cookie_enabled_>;
  using ScopedDocumentDomain = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_document_domain_enabled_>;
  using ScopedDocumentPolicy = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_document_policy_enabled_>;
  using ScopedDocumentWrite = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_document_write_enabled_>;
  using ScopedEditContext = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_edit_context_enabled_>;
  using ScopedEditingNG = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_editing_ng_enabled_>;
  using ScopedEncryptedMediaEncryptionSchemeQuery = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_encrypted_media_encryption_scheme_query_enabled_>;
  using ScopedEncryptedMediaHdcpPolicyCheck = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_encrypted_media_hdcp_policy_check_enabled_>;
  using ScopedEncryptedMediaPersistentUsageRecordSession = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_encrypted_media_persistent_usage_record_session_enabled_>;
  using ScopedEnterKeyHintAttribute = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_enter_key_hint_attribute_enabled_>;
  using ScopedEventTiming = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_event_timing_enabled_>;
  using ScopedExecCommandInJavaScript = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_exec_command_in_java_script_enabled_>;
  using ScopedExpensiveBackgroundTimerThrottling = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_expensive_background_timer_throttling_enabled_>;
  using ScopedExperimentalAutoplayDynamicDelegation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_experimental_autoplay_dynamic_delegation_enabled_>;
  using ScopedExperimentalContentSecurityPolicyFeatures = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_experimental_content_security_policy_features_enabled_>;
  using ScopedExperimentalIsInputPending = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_experimental_is_input_pending_enabled_>;
  using ScopedExperimentalJSProfiler = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_experimental_js_profiler_enabled_>;
  using ScopedExperimentalProductivityFeatures = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_experimental_productivity_features_enabled_>;
  using ScopedExtendedTextMetrics = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_extended_text_metrics_enabled_>;
  using ScopedExtraWebGLVideoTextureMetadata = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_extra_webgl_video_texture_metadata_enabled_>;
  using ScopedFaceDetector = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_face_detector_enabled_>;
  using ScopedFeaturePolicyForClientHints = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_feature_policy_for_client_hints_enabled_>;
  using ScopedFeaturePolicyForSandbox = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_feature_policy_for_sandbox_enabled_>;
  using ScopedFeaturePolicyReporting = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_feature_policy_reporting_enabled_>;
  using ScopedFeaturePolicyVibrateFeature = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_feature_policy_vibrate_feature_enabled_>;
  using ScopedFetchUploadStreaming = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_fetch_upload_streaming_enabled_>;
  using ScopedFileHandling = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_file_handling_enabled_>;
  using ScopedFileSystem = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_file_system_enabled_>;
  using ScopedFlexGaps = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_flex_gaps_enabled_>;
  using ScopedFocuslessSpatialNavigation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_focusless_spatial_navigation_enabled_>;
  using ScopedFontAccess = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_font_access_enabled_>;
  using ScopedFontSrcLocalMatching = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_font_src_local_matching_enabled_>;
  using ScopedForcedColors = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_forced_colors_enabled_>;
  using ScopedForceDeferScriptIntervention = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_force_defer_script_intervention_enabled_>;
  using ScopedForceEagerMeasureMemory = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_force_eager_measure_memory_enabled_>;
  using ScopedForceLoadAtTop = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_force_load_at_top_enabled_>;
  using ScopedForceOverlayFullscreenVideo = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_force_overlay_fullscreen_video_enabled_>;
  using ScopedForceSynchronousHTMLParsing = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_force_synchronous_html_parsing_enabled_>;
  using ScopedForceTallerSelectPopup = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_force_taller_select_popup_enabled_>;
  using ScopedFractionalScrollOffsets = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_fractional_scroll_offsets_enabled_>;
  using ScopedFreezeFramesOnVisibility = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_freeze_frames_on_visibility_enabled_>;
  using ScopedGamepadButtonAxisEvents = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_gamepad_button_axis_events_enabled_>;
  using ScopedGetDisplayMedia = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_get_display_media_enabled_>;
  using ScopedGroupEffect = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_group_effect_enabled_>;
  using ScopedHrefTranslate = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_href_translate_enabled_>;
  using ScopedHTMLImports = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_html_imports_enabled_>;
  using ScopedIDBObserver = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_idb_observer_enabled_>;
  using ScopedIDBRelaxedDurability = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_idb_relaxed_durability_enabled_>;
  using ScopedIdleDetection = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_idle_detection_enabled_>;
  using ScopedIgnoreCrossOriginWindowWhenNamedAccessOnWindow = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_ignore_cross_origin_window_when_named_access_on_window_enabled_>;
  using ScopedImageOrientation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_image_orientation_enabled_>;
  using ScopedImplicitRootScroller = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_implicit_root_scroller_enabled_>;
  using ScopedImportMaps = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_import_maps_enabled_>;
  using ScopedInertAttribute = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_inert_attribute_enabled_>;
  using ScopedInputElementRawValue = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_input_element_raw_value_enabled_>;
  using ScopedInputMultipleFieldsUI = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_input_multiple_fields_ui_enabled_>;
  using ScopedInstalledApp = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_installed_app_enabled_>;
  using ScopedIntersectionObserverDocumentScrollingElementRoot = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_intersection_observer_document_scrolling_element_root_enabled_>;
  using ScopedIsolatedCodeCache = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_isolated_code_cache_enabled_>;
  using ScopedIsolatedWorldCSP = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_isolated_world_csp_enabled_>;
  using ScopedKeyboardFocusableScrollers = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_keyboard_focusable_scrollers_enabled_>;
  using ScopedLangAttributeAwareFormControlUI = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_lang_attribute_aware_form_control_ui_enabled_>;
  using ScopedLangClientHintHeader = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_lang_client_hint_header_enabled_>;
  using ScopedLayoutNG = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_layout_ng_enabled_>;
  using ScopedLayoutNGBlockFragmentation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_layout_ng_block_fragmentation_enabled_>;
  using ScopedLayoutNGFieldset = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_layout_ng_fieldset_enabled_>;
  using ScopedLayoutNGFlexBox = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_layout_ng_flex_box_enabled_>;
  using ScopedLayoutNGForControls = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_layout_ng_for_controls_enabled_>;
  using ScopedLayoutNGFragmentItem = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_layout_ng_fragment_item_enabled_>;
  using ScopedLayoutNGFragmentTraversal = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_layout_ng_fragment_traversal_enabled_>;
  using ScopedLayoutNGGrid = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_layout_ng_grid_enabled_>;
  using ScopedLayoutNGRuby = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_layout_ng_ruby_enabled_>;
  using ScopedLayoutNGTable = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_layout_ng_table_enabled_>;
  using ScopedLayoutShiftAttribution = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_layout_shift_attribution_enabled_>;
  using ScopedLazyFrameLoading = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_lazy_frame_loading_enabled_>;
  using ScopedLazyFrameVisibleLoadTimeMetrics = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_lazy_frame_visible_load_time_metrics_enabled_>;
  using ScopedLazyImageLoading = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_lazy_image_loading_enabled_>;
  using ScopedLazyImageVisibleLoadTimeMetrics = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_lazy_image_visible_load_time_metrics_enabled_>;
  using ScopedLazyInitializeMediaControls = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_lazy_initialize_media_controls_enabled_>;
  using ScopedLegacyNativeFileSystem = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_legacy_native_file_system_enabled_>;
  using ScopedLegacyWindowsDWriteFontFallback = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_legacy_windows_d_write_font_fallback_enabled_>;
  using ScopedLinkDisabledNewSpecBehavior = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_link_disabled_new_spec_behavior_enabled_>;
  using ScopedManualSlotting = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_manual_slotting_enabled_>;
  using ScopedMathMLCore = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_mathml_core_enabled_>;
  using ScopedMeasureMemory = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_measure_memory_enabled_>;
  using ScopedMediaCapabilitiesDynamicRange = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_capabilities_dynamic_range_enabled_>;
  using ScopedMediaCapabilitiesEncodingInfo = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_capabilities_encoding_info_enabled_>;
  using ScopedMediaCapabilitiesEncryptedMedia = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_capabilities_encrypted_media_enabled_>;
  using ScopedMediaCapabilitiesSpatialAudio = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_capabilities_spatial_audio_enabled_>;
  using ScopedMediaCapture = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_capture_enabled_>;
  using ScopedMediaCaptureDepthVideoKind = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_capture_depth_video_kind_enabled_>;
  using ScopedMediaCapturePanTilt = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_capture_pan_tilt_enabled_>;
  using ScopedMediaCastOverlayButton = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_cast_overlay_button_enabled_>;
  using ScopedMediaControlsExpandGesture = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_controls_expand_gesture_enabled_>;
  using ScopedMediaControlsOverlayPlayButton = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_controls_overlay_play_button_enabled_>;
  using ScopedMediaControlsUseCutOutByDefault = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_controls_use_cut_out_by_default_enabled_>;
  using ScopedMediaDocumentDownloadButton = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_document_download_button_enabled_>;
  using ScopedMediaElementVolumeGreaterThanOne = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_element_volume_greater_than_one_enabled_>;
  using ScopedMediaEngagementBypassAutoplayPolicies = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_engagement_bypass_autoplay_policies_enabled_>;
  using ScopedMediaFeeds = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_feeds_enabled_>;
  using ScopedMediaLatencyHint = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_latency_hint_enabled_>;
  using ScopedMediaQueryNavigationControls = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_query_navigation_controls_enabled_>;
  using ScopedMediaSession = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_session_enabled_>;
  using ScopedMediaSessionPosition = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_session_position_enabled_>;
  using ScopedMediaSourceExperimental = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_source_experimental_enabled_>;
  using ScopedMediaSourceInWorkers = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_source_in_workers_enabled_>;
  using ScopedMediaSourceNewAbortAndDuration = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_source_new_abort_and_duration_enabled_>;
  using ScopedMediaSourceStable = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_media_source_stable_enabled_>;
  using ScopedMetaColorScheme = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_meta_color_scheme_enabled_>;
  using ScopedMiddleClickAutoscroll = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_middle_click_autoscroll_enabled_>;
  using ScopedMobileLayoutTheme = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_mobile_layout_theme_enabled_>;
  using ScopedModuleServiceWorker = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_module_service_worker_enabled_>;
  using ScopedModuleSharedWorker = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_module_shared_worker_enabled_>;
  using ScopedMojoJS = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_mojo_js_enabled_>;
  using ScopedMojoJSTest = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_mojo_js_test_enabled_>;
  using ScopedMouseSubframeNoImplicitCapture = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_mouse_subframe_no_implicit_capture_enabled_>;
  using ScopedNamedPages = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_named_pages_enabled_>;
  using ScopedNativeFileSystem = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_native_file_system_enabled_>;
  using ScopedNativeIO = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_native_io_enabled_>;
  using ScopedNavigatorContentUtils = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_navigator_content_utils_enabled_>;
  using ScopedNavigatorLanguageInInsecureContext = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_navigator_language_in_insecure_context_enabled_>;
  using ScopedNetInfoDownlinkMax = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_net_info_downlink_max_enabled_>;
  using ScopedNeverSlowMode = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_never_slow_mode_enabled_>;
  using ScopedNewCanvas2DAPI = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_new_canvas_2d_api_enabled_>;
  using ScopedNewRemotePlaybackPipeline = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_new_remote_playback_pipeline_enabled_>;
  using ScopedNoIdleEncodingForWebTests = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_no_idle_encoding_for_web_tests_enabled_>;
  using ScopedNotificationConstructor = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_notification_constructor_enabled_>;
  using ScopedNotificationContentImage = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_notification_content_image_enabled_>;
  using ScopedNotifications = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_notifications_enabled_>;
  using ScopedNotificationTriggers = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_notification_triggers_enabled_>;
  using ScopedOffMainThreadCSSPaint = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_off_main_thread_css_paint_enabled_>;
  using ScopedOffscreenCanvasCommit = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_offscreen_canvas_commit_enabled_>;
  using ScopedOnDeviceChange = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_on_device_change_enabled_>;
  using ScopedOrientationEvent = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_orientation_event_enabled_>;
  using ScopedOriginIsolationHeader = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_origin_isolation_header_enabled_>;
  using ScopedOriginPolicy = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_origin_policy_enabled_>;
  using ScopedOriginTrialsSampleAPI = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_origin_trials_sample_api_enabled_>;
  using ScopedOriginTrialsSampleAPIDependent = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_origin_trials_sample_api_dependent_enabled_>;
  using ScopedOriginTrialsSampleAPIDeprecation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_origin_trials_sample_api_deprecation_enabled_>;
  using ScopedOriginTrialsSampleAPIImplied = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_origin_trials_sample_api_implied_enabled_>;
  using ScopedOriginTrialsSampleAPIInvalidOS = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_origin_trials_sample_api_invalid_os_enabled_>;
  using ScopedOriginTrialsSampleAPINavigation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_origin_trials_sample_api_navigation_enabled_>;
  using ScopedOriginTrialsSampleAPIThirdParty = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_origin_trials_sample_api_third_party_enabled_>;
  using ScopedOutOfBlinkCors = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_out_of_blink_cors_enabled_>;
  using ScopedOverflowIconsForMediaControls = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_overflow_icons_for_media_controls_enabled_>;
  using ScopedOverscrollCustomization = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_overscroll_customization_enabled_>;
  using ScopedPageFreezeOptIn = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_page_freeze_opt_in_enabled_>;
  using ScopedPageFreezeOptOut = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_page_freeze_opt_out_enabled_>;
  using ScopedPagePopup = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_page_popup_enabled_>;
  using ScopedPaintUnderInvalidationChecking = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_paint_under_invalidation_checking_enabled_>;
  using ScopedParseUrlProtocolHandler = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_parse_url_protocol_handler_enabled_>;
  using ScopedPassPaintVisualRectToCompositor = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_pass_paint_visual_rect_to_compositor_enabled_>;
  using ScopedPasswordReveal = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_password_reveal_enabled_>;
  using ScopedPaymentApp = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_payment_app_enabled_>;
  using ScopedPaymentHandlerChangePaymentMethod = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_payment_handler_change_payment_method_enabled_>;
  using ScopedPaymentHandlerHandlesShippingAndContact = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_payment_handler_handles_shipping_and_contact_enabled_>;
  using ScopedPaymentHandlerMinimalUI = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_payment_handler_minimal_ui_enabled_>;
  using ScopedPaymentMethodChangeEvent = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_payment_method_change_event_enabled_>;
  using ScopedPaymentRequest = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_payment_request_enabled_>;
  using ScopedPaymentRequestMerchantValidationEvent = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_payment_request_merchant_validation_event_enabled_>;
  using ScopedPaymentRetry = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_payment_retry_enabled_>;
  using ScopedPercentBasedScrolling = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_percent_based_scrolling_enabled_>;
  using ScopedPerformanceManagerInstrumentation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_performance_manager_instrumentation_enabled_>;
  using ScopedPeriodicBackgroundSync = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_periodic_background_sync_enabled_>;
  using ScopedPerMethodCanMakePaymentQuota = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_per_method_can_make_payment_quota_enabled_>;
  using ScopedPermissionDelegation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_permission_delegation_enabled_>;
  using ScopedPermissions = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_permissions_enabled_>;
  using ScopedPermissionsRequestRevoke = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_permissions_request_revoke_enabled_>;
  using ScopedPictureInPicture = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_picture_in_picture_enabled_>;
  using ScopedPictureInPictureAPI = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_picture_in_picture_api_enabled_>;
  using ScopedPictureInPictureV2 = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_picture_in_picture_v_2_enabled_>;
  using ScopedPNaCl = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_p_na_cl_enabled_>;
  using ScopedPointerLockOptions = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_pointer_lock_options_enabled_>;
  using ScopedPointerRawUpdate = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_pointer_raw_update_enabled_>;
  using ScopedPortals = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_portals_enabled_>;
  using ScopedPostAnimationFrame = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_post_animation_frame_enabled_>;
  using ScopedPreciseMemoryInfo = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_precise_memory_info_enabled_>;
  using ScopedPreferNonCompositedScrolling = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_prefer_non_composited_scrolling_enabled_>;
  using ScopedPrefersReducedData = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_prefers_reduced_data_enabled_>;
  using ScopedPrefixedVideoFullscreen = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_prefixed_video_fullscreen_enabled_>;
  using ScopedPresentation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_presentation_enabled_>;
  using ScopedPriorityHints = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_priority_hints_enabled_>;
  using ScopedPushMessaging = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_push_messaging_enabled_>;
  using ScopedPushMessagingSubscriptionChange = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_push_messaging_subscription_change_enabled_>;
  using ScopedQuicTransport = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_quic_transport_enabled_>;
  using ScopedRawClipboard = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_raw_clipboard_enabled_>;
  using ScopedReducedReferrerGranularity = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_reduced_referrer_granularity_enabled_>;
  using ScopedRemotePlayback = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_remote_playback_enabled_>;
  using ScopedRemotePlaybackBackend = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_remote_playback_backend_enabled_>;
  using ScopedRequestVideoFrameCallback = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_request_video_frame_callback_enabled_>;
  using ScopedResizeObserverUpdates = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_resize_observer_updates_enabled_>;
  using ScopedRestrictAppCacheToSecureContexts = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_restrict_app_cache_to_secure_contexts_enabled_>;
  using ScopedRestrictAutomaticLazyFrameLoadingToDataSaver = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_restrict_automatic_lazy_frame_loading_to_data_saver_enabled_>;
  using ScopedRestrictAutomaticLazyImageLoadingToDataSaver = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_restrict_automatic_lazy_image_loading_to_data_saver_enabled_>;
  using ScopedRtcAudioJitterBufferMaxPackets = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_rtc_audio_jitter_buffer_max_packets_enabled_>;
  using ScopedRtcAudioJitterBufferRtxHandling = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_rtc_audio_jitter_buffer_rtx_handling_enabled_>;
  using ScopedRTCIceTransportExtension = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_rtc_ice_transport_extension_enabled_>;
  using ScopedRTCInsertableStreams = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_rtc_insertable_streams_enabled_>;
  using ScopedRTCQuicTransport = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_rtc_quic_transport_enabled_>;
  using ScopedRTCStatsRelativePacketArrivalDelay = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_rtc_stats_relative_packet_arrival_delay_enabled_>;
  using ScopedRTCSvcScalabilityMode = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_rtc_svc_scalability_mode_enabled_>;
  using ScopedRTCUnifiedPlan = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_rtc_unified_plan_enabled_>;
  using ScopedRTCUnifiedPlanByDefault = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_rtc_unified_plan_by_default_enabled_>;
  using ScopedSameSiteByDefaultCookies = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_same_site_by_default_cookies_enabled_>;
  using ScopedScreenWakeLock = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_screen_wake_lock_enabled_>;
  using ScopedScriptedSpeechRecognition = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_scripted_speech_recognition_enabled_>;
  using ScopedScriptedSpeechSynthesis = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_scripted_speech_synthesis_enabled_>;
  using ScopedScrollCustomization = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_scroll_customization_enabled_>;
  using ScopedScrollSnapAfterLayout = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_scroll_snap_after_layout_enabled_>;
  using ScopedScrollTimeline = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_scroll_timeline_enabled_>;
  using ScopedScrollTopLeftInterop = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_scroll_top_left_interop_enabled_>;
  using ScopedScrollUnification = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_scroll_unification_enabled_>;
  using ScopedSendBeaconThrowForBlobWithNonSimpleType = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_send_beacon_throw_for_blob_with_non_simple_type_enabled_>;
  using ScopedSendMouseEventsDisabledFormControls = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_send_mouse_events_disabled_form_controls_enabled_>;
  using ScopedSensorExtraClasses = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_sensor_extra_classes_enabled_>;
  using ScopedSerial = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_serial_enabled_>;
  using ScopedServiceWorkerClientLifecycleState = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_service_worker_client_lifecycle_state_enabled_>;
  using ScopedServiceWorkerFetchEventWorkerTiming = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_service_worker_fetch_event_worker_timing_enabled_>;
  using ScopedShadowDOMV0 = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_shadow_dom_v0_enabled_>;
  using ScopedSharedArrayBuffer = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_shared_array_buffer_enabled_>;
  using ScopedSharedWorker = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_shared_worker_enabled_>;
  using ScopedSignatureBasedIntegrity = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_signature_based_integrity_enabled_>;
  using ScopedSignedExchangePrefetchCacheForNavigations = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_signed_exchange_prefetch_cache_for_navigations_enabled_>;
  using ScopedSignedExchangeSubresourcePrefetch = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_signed_exchange_subresource_prefetch_enabled_>;
  using ScopedSkipAd = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_skip_ad_enabled_>;
  using ScopedSkipTouchEventFilter = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_skip_touch_event_filter_enabled_>;
  using ScopedSmsReceiver = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_sms_receiver_enabled_>;
  using ScopedSquashAfterPaint = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_squash_after_paint_enabled_>;
  using ScopedStableBlinkFeatures = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_stable_blink_features_enabled_>;
  using ScopedStorageAccessAPI = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_storage_access_api_enabled_>;
  using ScopedStrictMimeTypesForWorkers = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_strict_mime_types_for_workers_enabled_>;
  using ScopedSubresourceWebBundles = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_subresource_web_bundles_enabled_>;
  using ScopedSurfaceEmbeddingFeatures = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_surface_embedding_features_enabled_>;
  using ScopedSystemWakeLock = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_system_wake_lock_enabled_>;
  using ScopedTestFeature = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_test_feature_enabled_>;
  using ScopedTestFeatureDependent = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_test_feature_dependent_enabled_>;
  using ScopedTestFeatureImplied = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_test_feature_implied_enabled_>;
  using ScopedTextDetector = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_text_detector_enabled_>;
  using ScopedTextFragmentIdentifiers = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_text_fragment_identifiers_enabled_>;
  using ScopedThirdPartyOriginTrials = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_third_party_origin_trials_enabled_>;
  using ScopedTimerThrottlingForBackgroundTabs = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_timer_throttling_for_background_tabs_enabled_>;
  using ScopedTimerThrottlingForHiddenFrames = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_timer_throttling_for_hidden_frames_enabled_>;
  using ScopedTimeZoneChangeEvent = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_time_zone_change_event_enabled_>;
  using ScopedTouchEventFeatureDetection = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_touch_event_feature_detection_enabled_>;
  using ScopedTrackLayoutPassesPerBlock = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_track_layout_passes_per_block_enabled_>;
  using ScopedTransferableStreams = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_transferable_streams_enabled_>;
  using ScopedTransformInterop = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_transform_interop_enabled_>;
  using ScopedTranslateService = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_translate_service_enabled_>;
  using ScopedTrustedDOMTypes = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_trusted_dom_types_enabled_>;
  using ScopedTrustTokens = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_trust_tokens_enabled_>;
  using ScopedTrustTokensAlwaysAllowIssuance = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_trust_tokens_always_allow_issuance_enabled_>;
  using ScopedUnclosedFormControlIsInvalid = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_unclosed_form_control_is_invalid_enabled_>;
  using ScopedUnderlineOffsetThickness = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_underline_offset_thickness_enabled_>;
  using ScopedUnoptimizedImagePolicies = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_unoptimized_image_policies_enabled_>;
  using ScopedUnsizedMediaPolicy = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_unsized_media_policy_enabled_>;
  using ScopedUserActivationPostMessageTransfer = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_user_activation_post_message_transfer_enabled_>;
  using ScopedUserActivationSameOriginVisibility = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_user_activation_same_origin_visibility_enabled_>;
  using ScopedUserAgentClientHint = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_user_agent_client_hint_enabled_>;
  using ScopedV8IdleTasks = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_v8_idle_tasks_enabled_>;
  using ScopedVideoAutoFullscreen = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_video_auto_fullscreen_enabled_>;
  using ScopedVideoFullscreenOrientationLock = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_video_fullscreen_orientation_lock_enabled_>;
  using ScopedVideoPlaybackQuality = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_video_playback_quality_enabled_>;
  using ScopedVideoRotateToFullscreen = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_video_rotate_to_fullscreen_enabled_>;
  using ScopedVideoWakeLockOptimisationHiddenMuted = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_video_wake_lock_optimisation_hidden_muted_enabled_>;
  using ScopedVirtualKeyboard = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_virtual_keyboard_enabled_>;
  using ScopedVisibilityCollapseColumn = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_visibility_collapse_column_enabled_>;
  using ScopedWakeLock = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_wake_lock_enabled_>;
  using ScopedWebAnimationsAPI = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_animations_api_enabled_>;
  using ScopedWebAnimationsSVG = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_animations_svg_enabled_>;
  using ScopedWebAssemblySimd = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_assembly_simd_enabled_>;
  using ScopedWebAssemblyThreads = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_assembly_threads_enabled_>;
  using ScopedWebAuth = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_auth_enabled_>;
  using ScopedWebAuthenticationGetAssertionFeaturePolicy = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_authentication_get_assertion_feature_policy_enabled_>;
  using ScopedWebBluetooth = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_bluetooth_enabled_>;
  using ScopedWebBluetoothGetDevices = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_bluetooth_get_devices_enabled_>;
  using ScopedWebBluetoothRemoteCharacteristicNewWriteValue = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_bluetooth_remote_characteristic_new_write_value_enabled_>;
  using ScopedWebBluetoothScanning = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_bluetooth_scanning_enabled_>;
  using ScopedWebBluetoothWatchAdvertisements = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_bluetooth_watch_advertisements_enabled_>;
  using ScopedWebCodecs = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_codecs_enabled_>;
  using ScopedWebCryptoCurve25519 = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_crypto_curve_25519_enabled_>;
  using ScopedWebGL2ComputeContext = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_webgl2_compute_context_enabled_>;
  using ScopedWebGLDraftExtensions = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_webgl_draft_extensions_enabled_>;
  using ScopedWebGLImageChromium = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_webgl_image_chromium_enabled_>;
  using ScopedWebGPU = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_webgpu_enabled_>;
  using ScopedWebHID = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_hid_enabled_>;
  using ScopedWebNFC = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_nfc_enabled_>;
  using ScopedWebScheduler = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_scheduler_enabled_>;
  using ScopedWebShare = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_share_enabled_>;
  using ScopedWebShareV2 = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_share_v_2_enabled_>;
  using ScopedWebSocketStream = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_websocket_stream_enabled_>;
  using ScopedWebUSB = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_usb_enabled_>;
  using ScopedWebUSBOnDedicatedWorkers = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_usb_on_dedicated_workers_enabled_>;
  using ScopedWebVTTRegions = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_vtt_regions_enabled_>;
  using ScopedWebXR = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_xr_enabled_>;
  using ScopedWebXRAnchors = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_xr_anchors_enabled_>;
  using ScopedWebXRARModule = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_xr_ar_module_enabled_>;
  using ScopedWebXRCameraAccess = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_xr_camera_access_enabled_>;
  using ScopedWebXRHitTest = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_xr_hit_test_enabled_>;
  using ScopedWebXRHitTestEntityTypes = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_xr_hit_test_entity_types_enabled_>;
  using ScopedWebXRLightEstimation = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_xr_light_estimation_enabled_>;
  using ScopedWebXRPlaneDetection = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_web_xr_plane_detection_enabled_>;
  using ScopedWindowPlacement = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_window_placement_enabled_>;
  using ScopedWindowSegments = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_window_segments_enabled_>;
  using ScopedXSLT = ScopedRuntimeEnabledFeature<
      RuntimeEnabledFeatures::is_xslt_enabled_>;
};

using ScopedAccelerated2dCanvasForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAccelerated2dCanvas;
using ScopedAcceleratedSmallCanvasesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAcceleratedSmallCanvases;
using ScopedAccessibilityExposeARIAAnnotationsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAccessibilityExposeARIAAnnotations;
using ScopedAccessibilityExposeDisplayNoneForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAccessibilityExposeDisplayNone;
using ScopedAccessibilityExposeHTMLElementForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAccessibilityExposeHTMLElement;
using ScopedAccessibilityObjectModelForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAccessibilityObjectModel;
using ScopedAddressSpaceForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAddressSpace;
using ScopedAdTaggingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAdTagging;
using ScopedAllowActivationDelegationAttrForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAllowActivationDelegationAttr;
using ScopedAllowContentInitiatedDataUrlNavigationsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAllowContentInitiatedDataUrlNavigations;
using ScopedAllowSyncXHRInPageDismissalForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAllowSyncXHRInPageDismissal;
using ScopedAnimationWorkletForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAnimationWorklet;
using ScopedAOMAriaPropertiesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAOMAriaProperties;
using ScopedAOMAriaRelationshipPropertiesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAOMAriaRelationshipProperties;
using ScopedAppCacheForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAppCache;
using ScopedAudioOutputDevicesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAudioOutputDevices;
using ScopedAudioVideoTracksForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAudioVideoTracks;
using ScopedAudioWorkletRealtimeThreadForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAudioWorkletRealtimeThread;
using ScopedAutoLazyLoadOnReloadsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAutoLazyLoadOnReloads;
using ScopedAutomaticLazyFrameLoadingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAutomaticLazyFrameLoading;
using ScopedAutomaticLazyImageLoadingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAutomaticLazyImageLoading;
using ScopedAutomationControlledForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAutomationControlled;
using ScopedAutoPictureInPictureForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAutoPictureInPicture;
using ScopedAutoplayIgnoresWebAudioForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedAutoplayIgnoresWebAudio;
using ScopedBackForwardCacheForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBackForwardCache;
using ScopedBackgroundFetchForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBackgroundFetch;
using ScopedBackgroundVideoTrackOptimizationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBackgroundVideoTrackOptimization;
using ScopedBadgingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBadging;
using ScopedBarcodeDetectorForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBarcodeDetector;
using ScopedBeforeMatchEventForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBeforeMatchEvent;
using ScopedBidiCaretAffinityForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBidiCaretAffinity;
using ScopedBlinkRuntimeCallStatsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBlinkRuntimeCallStats;
using ScopedBlockCredentialedSubresourcesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBlockCredentialedSubresources;
using ScopedBlockFlowHandlesWebkitLineClampForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBlockFlowHandlesWebkitLineClamp;
using ScopedBlockHTMLParserOnStyleSheetsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBlockHTMLParserOnStyleSheets;
using ScopedBlockingDownloadsInSandboxForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBlockingDownloadsInSandbox;
using ScopedBlockingFocusWithoutUserActivationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBlockingFocusWithoutUserActivation;
using ScopedBrowserVerifiedUserActivationKeyboardForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBrowserVerifiedUserActivationKeyboard;
using ScopedBrowserVerifiedUserActivationMouseForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedBrowserVerifiedUserActivationMouse;
using ScopedCacheInlineScriptCodeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCacheInlineScriptCode;
using ScopedCacheStorageCodeCacheHintForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCacheStorageCodeCacheHint;
using ScopedCanvas2dContextLostRestoredForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCanvas2dContextLostRestored;
using ScopedCanvas2dImageChromiumForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCanvas2dImageChromium;
using ScopedCanvas2dScrollPathIntoViewForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCanvas2dScrollPathIntoView;
using ScopedCanvasColorManagementForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCanvasColorManagement;
using ScopedCanvasHitRegionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCanvasHitRegion;
using ScopedCanvasImageSmoothingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCanvasImageSmoothing;
using ScopedCaptureTimeInCsrcForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCaptureTimeInCsrc;
using ScopedClickPointerEventForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedClickPointerEvent;
using ScopedClickRetargettingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedClickRetargetting;
using ScopedCompositeAfterPaintForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCompositeAfterPaint;
using ScopedCompositedSelectionUpdateForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCompositedSelectionUpdate;
using ScopedComputedAccessibilityInfoForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedComputedAccessibilityInfo;
using ScopedConsolidatedMovementXYForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedConsolidatedMovementXY;
using ScopedContactsManagerForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedContactsManager;
using ScopedContactsManagerExtraPropertiesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedContactsManagerExtraProperties;
using ScopedContentIndexForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedContentIndex;
using ScopedContextMenuForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedContextMenu;
using ScopedConversionMeasurementForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedConversionMeasurement;
using ScopedCookieDeprecationMessagesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCookieDeprecationMessages;
using ScopedCookieStoreDocumentForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCookieStoreDocument;
using ScopedCookieStoreWorkerForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCookieStoreWorker;
using ScopedCookiesWithoutSameSiteMustBeSecureForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCookiesWithoutSameSiteMustBeSecure;
using ScopedCooperativeSchedulingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCooperativeScheduling;
using ScopedCorsRFC1918ForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCorsRFC1918;
using ScopedCrossOriginIsolationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCrossOriginIsolation;
using ScopedCSS3TextForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSS3Text;
using ScopedCSSAspectRatioPropertyForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSAspectRatioProperty;
using ScopedCSSCalcAsIntForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSCalcAsInt;
using ScopedCSSCascadeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSCascade;
using ScopedCSSColorSchemeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSColorScheme;
using ScopedCSSColorSchemeUARenderingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSColorSchemeUARendering;
using ScopedCSSContentVisibilityForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSContentVisibility;
using ScopedCSSContentVisibilityHiddenMatchableForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSContentVisibilityHiddenMatchable;
using ScopedCSSFocusVisibleForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSFocusVisible;
using ScopedCSSFoldablesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSFoldables;
using ScopedCSSFontSizeAdjustForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSFontSizeAdjust;
using ScopedCSSHexAlphaColorForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSHexAlphaColor;
using ScopedCSSIndependentTransformPropertiesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSIndependentTransformProperties;
using ScopedCSSLayoutAPIForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSLayoutAPI;
using ScopedCSSLogicalForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSLogical;
using ScopedCSSLogicalOverflowForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSLogicalOverflow;
using ScopedCSSMarkerNestedPseudoElementForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSMarkerNestedPseudoElement;
using ScopedCSSMarkerPseudoElementForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSMarkerPseudoElement;
using ScopedCSSMatchedPropertiesCacheDependenciesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSMatchedPropertiesCacheDependencies;
using ScopedCSSMathStyleForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSMathStyle;
using ScopedCSSMathSuperscriptShiftStyleForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSMathSuperscriptShiftStyle;
using ScopedCSSMathVariantForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSMathVariant;
using ScopedCSSModulesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSModules;
using ScopedCSSOffsetPathRayForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSOffsetPathRay;
using ScopedCSSOffsetPathRayContainForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSOffsetPathRayContain;
using ScopedCSSOffsetPositionAnchorForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSOffsetPositionAnchor;
using ScopedCSSOMViewScrollCoordinatesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSOMViewScrollCoordinates;
using ScopedCSSPaintAPIArgumentsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSPaintAPIArguments;
using ScopedCSSPictureInPictureForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSPictureInPicture;
using ScopedCSSPseudoIsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSPseudoIs;
using ScopedCSSPseudoWhereForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSPseudoWhere;
using ScopedCSSReducedFontLoadingInvalidationsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSReducedFontLoadingInvalidations;
using ScopedCSSReducedFontLoadingLayoutInvalidationsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSReducedFontLoadingLayoutInvalidations;
using ScopedCSSRevertForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSRevert;
using ScopedCSSScrollTimelineForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSScrollTimeline;
using ScopedCSSSnapSizeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSSnapSize;
using ScopedCSSSupportsSelectorForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSSupportsSelector;
using ScopedCSSVariables2AtPropertyForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSVariables2AtProperty;
using ScopedCSSVariables2ImageValuesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSVariables2ImageValues;
using ScopedCSSVariables2TransformValuesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCSSVariables2TransformValues;
using ScopedCustomElementDefaultStyleForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCustomElementDefaultStyle;
using ScopedCustomElementsV0ForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCustomElementsV0;
using ScopedCustomStatePseudoClassForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedCustomStatePseudoClass;
using ScopedDatabaseForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDatabase;
using ScopedDeclarativeShadowDOMForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDeclarativeShadowDOM;
using ScopedDecodeJpeg420ImagesToYUVForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDecodeJpeg420ImagesToYUV;
using ScopedDecodeLossyWebPImagesToYUVForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDecodeLossyWebPImagesToYUV;
using ScopedDelayAsyncScriptExecutionUntilFinishedParsingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDelayAsyncScriptExecutionUntilFinishedParsing;
using ScopedDelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsing;
using ScopedDelegatedInkTrailsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDelegatedInkTrails;
using ScopedDesktopCaptureDisableLocalEchoControlForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDesktopCaptureDisableLocalEchoControl;
using ScopedDigitalGoodsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDigitalGoods;
using ScopedDisableHardwareNoiseSuppressionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDisableHardwareNoiseSuppression;
using ScopedDisableLayerSquashingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDisableLayerSquashing;
using ScopedDisallowDocumentAccessForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDisallowDocumentAccess;
using ScopedDisplayCutoutAPIForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDisplayCutoutAPI;
using ScopedDocumentCookieForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDocumentCookie;
using ScopedDocumentDomainForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDocumentDomain;
using ScopedDocumentPolicyForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDocumentPolicy;
using ScopedDocumentWriteForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedDocumentWrite;
using ScopedEditContextForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedEditContext;
using ScopedEditingNGForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedEditingNG;
using ScopedEncryptedMediaEncryptionSchemeQueryForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedEncryptedMediaEncryptionSchemeQuery;
using ScopedEncryptedMediaHdcpPolicyCheckForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedEncryptedMediaHdcpPolicyCheck;
using ScopedEncryptedMediaPersistentUsageRecordSessionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedEncryptedMediaPersistentUsageRecordSession;
using ScopedEnterKeyHintAttributeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedEnterKeyHintAttribute;
using ScopedEventTimingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedEventTiming;
using ScopedExecCommandInJavaScriptForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedExecCommandInJavaScript;
using ScopedExpensiveBackgroundTimerThrottlingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedExpensiveBackgroundTimerThrottling;
using ScopedExperimentalAutoplayDynamicDelegationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedExperimentalAutoplayDynamicDelegation;
using ScopedExperimentalContentSecurityPolicyFeaturesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedExperimentalContentSecurityPolicyFeatures;
using ScopedExperimentalIsInputPendingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedExperimentalIsInputPending;
using ScopedExperimentalJSProfilerForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedExperimentalJSProfiler;
using ScopedExperimentalProductivityFeaturesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedExperimentalProductivityFeatures;
using ScopedExtendedTextMetricsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedExtendedTextMetrics;
using ScopedExtraWebGLVideoTextureMetadataForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedExtraWebGLVideoTextureMetadata;
using ScopedFaceDetectorForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFaceDetector;
using ScopedFeaturePolicyForClientHintsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFeaturePolicyForClientHints;
using ScopedFeaturePolicyForSandboxForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFeaturePolicyForSandbox;
using ScopedFeaturePolicyReportingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFeaturePolicyReporting;
using ScopedFeaturePolicyVibrateFeatureForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFeaturePolicyVibrateFeature;
using ScopedFetchUploadStreamingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFetchUploadStreaming;
using ScopedFileHandlingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFileHandling;
using ScopedFileSystemForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFileSystem;
using ScopedFlexGapsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFlexGaps;
using ScopedFocuslessSpatialNavigationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFocuslessSpatialNavigation;
using ScopedFontAccessForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFontAccess;
using ScopedFontSrcLocalMatchingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFontSrcLocalMatching;
using ScopedForcedColorsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedForcedColors;
using ScopedForceDeferScriptInterventionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedForceDeferScriptIntervention;
using ScopedForceEagerMeasureMemoryForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedForceEagerMeasureMemory;
using ScopedForceLoadAtTopForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedForceLoadAtTop;
using ScopedForceOverlayFullscreenVideoForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedForceOverlayFullscreenVideo;
using ScopedForceSynchronousHTMLParsingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedForceSynchronousHTMLParsing;
using ScopedForceTallerSelectPopupForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedForceTallerSelectPopup;
using ScopedFractionalScrollOffsetsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFractionalScrollOffsets;
using ScopedFreezeFramesOnVisibilityForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedFreezeFramesOnVisibility;
using ScopedGamepadButtonAxisEventsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedGamepadButtonAxisEvents;
using ScopedGetDisplayMediaForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedGetDisplayMedia;
using ScopedGroupEffectForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedGroupEffect;
using ScopedHrefTranslateForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedHrefTranslate;
using ScopedHTMLImportsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedHTMLImports;
using ScopedIDBObserverForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedIDBObserver;
using ScopedIDBRelaxedDurabilityForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedIDBRelaxedDurability;
using ScopedIdleDetectionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedIdleDetection;
using ScopedIgnoreCrossOriginWindowWhenNamedAccessOnWindowForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedIgnoreCrossOriginWindowWhenNamedAccessOnWindow;
using ScopedImageOrientationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedImageOrientation;
using ScopedImplicitRootScrollerForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedImplicitRootScroller;
using ScopedImportMapsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedImportMaps;
using ScopedInertAttributeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedInertAttribute;
using ScopedInputElementRawValueForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedInputElementRawValue;
using ScopedInputMultipleFieldsUIForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedInputMultipleFieldsUI;
using ScopedInstalledAppForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedInstalledApp;
using ScopedIntersectionObserverDocumentScrollingElementRootForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedIntersectionObserverDocumentScrollingElementRoot;
using ScopedIsolatedCodeCacheForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedIsolatedCodeCache;
using ScopedIsolatedWorldCSPForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedIsolatedWorldCSP;
using ScopedKeyboardFocusableScrollersForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedKeyboardFocusableScrollers;
using ScopedLangAttributeAwareFormControlUIForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLangAttributeAwareFormControlUI;
using ScopedLangClientHintHeaderForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLangClientHintHeader;
using ScopedLayoutNGForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLayoutNG;
using ScopedLayoutNGBlockFragmentationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLayoutNGBlockFragmentation;
using ScopedLayoutNGFieldsetForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLayoutNGFieldset;
using ScopedLayoutNGFlexBoxForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLayoutNGFlexBox;
using ScopedLayoutNGForControlsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLayoutNGForControls;
using ScopedLayoutNGFragmentItemForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLayoutNGFragmentItem;
using ScopedLayoutNGFragmentTraversalForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLayoutNGFragmentTraversal;
using ScopedLayoutNGGridForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLayoutNGGrid;
using ScopedLayoutNGRubyForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLayoutNGRuby;
using ScopedLayoutNGTableForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLayoutNGTable;
using ScopedLayoutShiftAttributionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLayoutShiftAttribution;
using ScopedLazyFrameLoadingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLazyFrameLoading;
using ScopedLazyFrameVisibleLoadTimeMetricsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLazyFrameVisibleLoadTimeMetrics;
using ScopedLazyImageLoadingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLazyImageLoading;
using ScopedLazyImageVisibleLoadTimeMetricsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLazyImageVisibleLoadTimeMetrics;
using ScopedLazyInitializeMediaControlsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLazyInitializeMediaControls;
using ScopedLegacyNativeFileSystemForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLegacyNativeFileSystem;
using ScopedLegacyWindowsDWriteFontFallbackForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLegacyWindowsDWriteFontFallback;
using ScopedLinkDisabledNewSpecBehaviorForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedLinkDisabledNewSpecBehavior;
using ScopedManualSlottingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedManualSlotting;
using ScopedMathMLCoreForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMathMLCore;
using ScopedMeasureMemoryForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMeasureMemory;
using ScopedMediaCapabilitiesDynamicRangeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaCapabilitiesDynamicRange;
using ScopedMediaCapabilitiesEncodingInfoForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaCapabilitiesEncodingInfo;
using ScopedMediaCapabilitiesEncryptedMediaForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaCapabilitiesEncryptedMedia;
using ScopedMediaCapabilitiesSpatialAudioForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaCapabilitiesSpatialAudio;
using ScopedMediaCaptureForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaCapture;
using ScopedMediaCaptureDepthVideoKindForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaCaptureDepthVideoKind;
using ScopedMediaCapturePanTiltForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaCapturePanTilt;
using ScopedMediaCastOverlayButtonForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaCastOverlayButton;
using ScopedMediaControlsExpandGestureForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaControlsExpandGesture;
using ScopedMediaControlsOverlayPlayButtonForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaControlsOverlayPlayButton;
using ScopedMediaControlsUseCutOutByDefaultForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaControlsUseCutOutByDefault;
using ScopedMediaDocumentDownloadButtonForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaDocumentDownloadButton;
using ScopedMediaElementVolumeGreaterThanOneForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaElementVolumeGreaterThanOne;
using ScopedMediaEngagementBypassAutoplayPoliciesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaEngagementBypassAutoplayPolicies;
using ScopedMediaFeedsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaFeeds;
using ScopedMediaLatencyHintForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaLatencyHint;
using ScopedMediaQueryNavigationControlsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaQueryNavigationControls;
using ScopedMediaSessionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaSession;
using ScopedMediaSessionPositionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaSessionPosition;
using ScopedMediaSourceExperimentalForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaSourceExperimental;
using ScopedMediaSourceInWorkersForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaSourceInWorkers;
using ScopedMediaSourceNewAbortAndDurationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaSourceNewAbortAndDuration;
using ScopedMediaSourceStableForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMediaSourceStable;
using ScopedMetaColorSchemeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMetaColorScheme;
using ScopedMiddleClickAutoscrollForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMiddleClickAutoscroll;
using ScopedMobileLayoutThemeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMobileLayoutTheme;
using ScopedModuleServiceWorkerForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedModuleServiceWorker;
using ScopedModuleSharedWorkerForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedModuleSharedWorker;
using ScopedMojoJSForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMojoJS;
using ScopedMojoJSTestForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMojoJSTest;
using ScopedMouseSubframeNoImplicitCaptureForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedMouseSubframeNoImplicitCapture;
using ScopedNamedPagesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNamedPages;
using ScopedNativeFileSystemForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNativeFileSystem;
using ScopedNativeIOForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNativeIO;
using ScopedNavigatorContentUtilsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNavigatorContentUtils;
using ScopedNavigatorLanguageInInsecureContextForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNavigatorLanguageInInsecureContext;
using ScopedNetInfoDownlinkMaxForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNetInfoDownlinkMax;
using ScopedNeverSlowModeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNeverSlowMode;
using ScopedNewCanvas2DAPIForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNewCanvas2DAPI;
using ScopedNewRemotePlaybackPipelineForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNewRemotePlaybackPipeline;
using ScopedNoIdleEncodingForWebTestsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNoIdleEncodingForWebTests;
using ScopedNotificationConstructorForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNotificationConstructor;
using ScopedNotificationContentImageForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNotificationContentImage;
using ScopedNotificationsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNotifications;
using ScopedNotificationTriggersForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedNotificationTriggers;
using ScopedOffMainThreadCSSPaintForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOffMainThreadCSSPaint;
using ScopedOffscreenCanvasCommitForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOffscreenCanvasCommit;
using ScopedOnDeviceChangeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOnDeviceChange;
using ScopedOrientationEventForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOrientationEvent;
using ScopedOriginIsolationHeaderForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOriginIsolationHeader;
using ScopedOriginPolicyForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOriginPolicy;
using ScopedOriginTrialsSampleAPIForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPI;
using ScopedOriginTrialsSampleAPIDependentForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIDependent;
using ScopedOriginTrialsSampleAPIDeprecationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIDeprecation;
using ScopedOriginTrialsSampleAPIImpliedForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIImplied;
using ScopedOriginTrialsSampleAPIInvalidOSForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIInvalidOS;
using ScopedOriginTrialsSampleAPINavigationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPINavigation;
using ScopedOriginTrialsSampleAPIThirdPartyForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIThirdParty;
using ScopedOutOfBlinkCorsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOutOfBlinkCors;
using ScopedOverflowIconsForMediaControlsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOverflowIconsForMediaControls;
using ScopedOverscrollCustomizationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedOverscrollCustomization;
using ScopedPageFreezeOptInForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPageFreezeOptIn;
using ScopedPageFreezeOptOutForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPageFreezeOptOut;
using ScopedPagePopupForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPagePopup;
using ScopedPaintUnderInvalidationCheckingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPaintUnderInvalidationChecking;
using ScopedParseUrlProtocolHandlerForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedParseUrlProtocolHandler;
using ScopedPassPaintVisualRectToCompositorForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPassPaintVisualRectToCompositor;
using ScopedPasswordRevealForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPasswordReveal;
using ScopedPaymentAppForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPaymentApp;
using ScopedPaymentHandlerChangePaymentMethodForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPaymentHandlerChangePaymentMethod;
using ScopedPaymentHandlerHandlesShippingAndContactForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPaymentHandlerHandlesShippingAndContact;
using ScopedPaymentHandlerMinimalUIForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPaymentHandlerMinimalUI;
using ScopedPaymentMethodChangeEventForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPaymentMethodChangeEvent;
using ScopedPaymentRequestForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPaymentRequest;
using ScopedPaymentRequestMerchantValidationEventForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPaymentRequestMerchantValidationEvent;
using ScopedPaymentRetryForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPaymentRetry;
using ScopedPercentBasedScrollingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPercentBasedScrolling;
using ScopedPerformanceManagerInstrumentationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPerformanceManagerInstrumentation;
using ScopedPeriodicBackgroundSyncForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPeriodicBackgroundSync;
using ScopedPerMethodCanMakePaymentQuotaForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPerMethodCanMakePaymentQuota;
using ScopedPermissionDelegationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPermissionDelegation;
using ScopedPermissionsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPermissions;
using ScopedPermissionsRequestRevokeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPermissionsRequestRevoke;
using ScopedPictureInPictureForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPictureInPicture;
using ScopedPictureInPictureAPIForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPictureInPictureAPI;
using ScopedPictureInPictureV2ForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPictureInPictureV2;
using ScopedPNaClForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPNaCl;
using ScopedPointerLockOptionsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPointerLockOptions;
using ScopedPointerRawUpdateForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPointerRawUpdate;
using ScopedPortalsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPortals;
using ScopedPostAnimationFrameForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPostAnimationFrame;
using ScopedPreciseMemoryInfoForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPreciseMemoryInfo;
using ScopedPreferNonCompositedScrollingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPreferNonCompositedScrolling;
using ScopedPrefersReducedDataForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPrefersReducedData;
using ScopedPrefixedVideoFullscreenForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPrefixedVideoFullscreen;
using ScopedPresentationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPresentation;
using ScopedPriorityHintsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPriorityHints;
using ScopedPushMessagingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPushMessaging;
using ScopedPushMessagingSubscriptionChangeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedPushMessagingSubscriptionChange;
using ScopedQuicTransportForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedQuicTransport;
using ScopedRawClipboardForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRawClipboard;
using ScopedReducedReferrerGranularityForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedReducedReferrerGranularity;
using ScopedRemotePlaybackForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRemotePlayback;
using ScopedRemotePlaybackBackendForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRemotePlaybackBackend;
using ScopedRequestVideoFrameCallbackForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRequestVideoFrameCallback;
using ScopedResizeObserverUpdatesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedResizeObserverUpdates;
using ScopedRestrictAppCacheToSecureContextsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRestrictAppCacheToSecureContexts;
using ScopedRestrictAutomaticLazyFrameLoadingToDataSaverForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRestrictAutomaticLazyFrameLoadingToDataSaver;
using ScopedRestrictAutomaticLazyImageLoadingToDataSaverForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRestrictAutomaticLazyImageLoadingToDataSaver;
using ScopedRtcAudioJitterBufferMaxPacketsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRtcAudioJitterBufferMaxPackets;
using ScopedRtcAudioJitterBufferRtxHandlingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRtcAudioJitterBufferRtxHandling;
using ScopedRTCIceTransportExtensionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRTCIceTransportExtension;
using ScopedRTCInsertableStreamsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRTCInsertableStreams;
using ScopedRTCQuicTransportForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRTCQuicTransport;
using ScopedRTCStatsRelativePacketArrivalDelayForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRTCStatsRelativePacketArrivalDelay;
using ScopedRTCSvcScalabilityModeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRTCSvcScalabilityMode;
using ScopedRTCUnifiedPlanForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRTCUnifiedPlan;
using ScopedRTCUnifiedPlanByDefaultForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedRTCUnifiedPlanByDefault;
using ScopedSameSiteByDefaultCookiesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSameSiteByDefaultCookies;
using ScopedScreenWakeLockForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedScreenWakeLock;
using ScopedScriptedSpeechRecognitionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedScriptedSpeechRecognition;
using ScopedScriptedSpeechSynthesisForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedScriptedSpeechSynthesis;
using ScopedScrollCustomizationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedScrollCustomization;
using ScopedScrollSnapAfterLayoutForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedScrollSnapAfterLayout;
using ScopedScrollTimelineForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedScrollTimeline;
using ScopedScrollTopLeftInteropForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedScrollTopLeftInterop;
using ScopedScrollUnificationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedScrollUnification;
using ScopedSendBeaconThrowForBlobWithNonSimpleTypeForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSendBeaconThrowForBlobWithNonSimpleType;
using ScopedSendMouseEventsDisabledFormControlsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSendMouseEventsDisabledFormControls;
using ScopedSensorExtraClassesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSensorExtraClasses;
using ScopedSerialForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSerial;
using ScopedServiceWorkerClientLifecycleStateForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedServiceWorkerClientLifecycleState;
using ScopedServiceWorkerFetchEventWorkerTimingForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedServiceWorkerFetchEventWorkerTiming;
using ScopedShadowDOMV0ForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedShadowDOMV0;
using ScopedSharedArrayBufferForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSharedArrayBuffer;
using ScopedSharedWorkerForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSharedWorker;
using ScopedSignatureBasedIntegrityForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSignatureBasedIntegrity;
using ScopedSignedExchangePrefetchCacheForNavigationsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSignedExchangePrefetchCacheForNavigations;
using ScopedSignedExchangeSubresourcePrefetchForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSignedExchangeSubresourcePrefetch;
using ScopedSkipAdForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSkipAd;
using ScopedSkipTouchEventFilterForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSkipTouchEventFilter;
using ScopedSmsReceiverForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSmsReceiver;
using ScopedSquashAfterPaintForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSquashAfterPaint;
using ScopedStableBlinkFeaturesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedStableBlinkFeatures;
using ScopedStorageAccessAPIForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedStorageAccessAPI;
using ScopedStrictMimeTypesForWorkersForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedStrictMimeTypesForWorkers;
using ScopedSubresourceWebBundlesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSubresourceWebBundles;
using ScopedSurfaceEmbeddingFeaturesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSurfaceEmbeddingFeatures;
using ScopedSystemWakeLockForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedSystemWakeLock;
using ScopedTestFeatureForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTestFeature;
using ScopedTestFeatureDependentForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTestFeatureDependent;
using ScopedTestFeatureImpliedForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTestFeatureImplied;
using ScopedTextDetectorForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTextDetector;
using ScopedTextFragmentIdentifiersForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTextFragmentIdentifiers;
using ScopedThirdPartyOriginTrialsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedThirdPartyOriginTrials;
using ScopedTimerThrottlingForBackgroundTabsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTimerThrottlingForBackgroundTabs;
using ScopedTimerThrottlingForHiddenFramesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTimerThrottlingForHiddenFrames;
using ScopedTimeZoneChangeEventForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTimeZoneChangeEvent;
using ScopedTouchEventFeatureDetectionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTouchEventFeatureDetection;
using ScopedTrackLayoutPassesPerBlockForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTrackLayoutPassesPerBlock;
using ScopedTransferableStreamsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTransferableStreams;
using ScopedTransformInteropForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTransformInterop;
using ScopedTranslateServiceForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTranslateService;
using ScopedTrustedDOMTypesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTrustedDOMTypes;
using ScopedTrustTokensForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTrustTokens;
using ScopedTrustTokensAlwaysAllowIssuanceForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedTrustTokensAlwaysAllowIssuance;
using ScopedUnclosedFormControlIsInvalidForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedUnclosedFormControlIsInvalid;
using ScopedUnderlineOffsetThicknessForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedUnderlineOffsetThickness;
using ScopedUnoptimizedImagePoliciesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedUnoptimizedImagePolicies;
using ScopedUnsizedMediaPolicyForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedUnsizedMediaPolicy;
using ScopedUserActivationPostMessageTransferForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedUserActivationPostMessageTransfer;
using ScopedUserActivationSameOriginVisibilityForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedUserActivationSameOriginVisibility;
using ScopedUserAgentClientHintForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedUserAgentClientHint;
using ScopedV8IdleTasksForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedV8IdleTasks;
using ScopedVideoAutoFullscreenForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedVideoAutoFullscreen;
using ScopedVideoFullscreenOrientationLockForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedVideoFullscreenOrientationLock;
using ScopedVideoPlaybackQualityForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedVideoPlaybackQuality;
using ScopedVideoRotateToFullscreenForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedVideoRotateToFullscreen;
using ScopedVideoWakeLockOptimisationHiddenMutedForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedVideoWakeLockOptimisationHiddenMuted;
using ScopedVirtualKeyboardForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedVirtualKeyboard;
using ScopedVisibilityCollapseColumnForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedVisibilityCollapseColumn;
using ScopedWakeLockForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWakeLock;
using ScopedWebAnimationsAPIForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebAnimationsAPI;
using ScopedWebAnimationsSVGForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebAnimationsSVG;
using ScopedWebAssemblySimdForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebAssemblySimd;
using ScopedWebAssemblyThreadsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebAssemblyThreads;
using ScopedWebAuthForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebAuth;
using ScopedWebAuthenticationGetAssertionFeaturePolicyForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebAuthenticationGetAssertionFeaturePolicy;
using ScopedWebBluetoothForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebBluetooth;
using ScopedWebBluetoothGetDevicesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebBluetoothGetDevices;
using ScopedWebBluetoothRemoteCharacteristicNewWriteValueForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebBluetoothRemoteCharacteristicNewWriteValue;
using ScopedWebBluetoothScanningForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebBluetoothScanning;
using ScopedWebBluetoothWatchAdvertisementsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebBluetoothWatchAdvertisements;
using ScopedWebCodecsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebCodecs;
using ScopedWebCryptoCurve25519ForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebCryptoCurve25519;
using ScopedWebGL2ComputeContextForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebGL2ComputeContext;
using ScopedWebGLDraftExtensionsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebGLDraftExtensions;
using ScopedWebGLImageChromiumForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebGLImageChromium;
using ScopedWebGPUForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebGPU;
using ScopedWebHIDForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebHID;
using ScopedWebNFCForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebNFC;
using ScopedWebSchedulerForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebScheduler;
using ScopedWebShareForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebShare;
using ScopedWebShareV2ForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebShareV2;
using ScopedWebSocketStreamForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebSocketStream;
using ScopedWebUSBForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebUSB;
using ScopedWebUSBOnDedicatedWorkersForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebUSBOnDedicatedWorkers;
using ScopedWebVTTRegionsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebVTTRegions;
using ScopedWebXRForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebXR;
using ScopedWebXRAnchorsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebXRAnchors;
using ScopedWebXRARModuleForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebXRARModule;
using ScopedWebXRCameraAccessForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebXRCameraAccess;
using ScopedWebXRHitTestForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebXRHitTest;
using ScopedWebXRHitTestEntityTypesForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebXRHitTestEntityTypes;
using ScopedWebXRLightEstimationForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebXRLightEstimation;
using ScopedWebXRPlaneDetectionForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWebXRPlaneDetection;
using ScopedWindowPlacementForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWindowPlacement;
using ScopedWindowSegmentsForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedWindowSegments;
using ScopedXSLTForTest =
    RuntimeEnabledFeaturesTestHelpers::ScopedXSLT;
}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_TEST_HELPERS_H_
