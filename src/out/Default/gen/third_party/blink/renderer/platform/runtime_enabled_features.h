// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_enabled_features.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_

#include <string>

#include "third_party/blink/renderer/platform/platform_export.h"
#include "third_party/blink/renderer/platform/wtf/allocator/allocator.h"

#define ASSERT_ORIGIN_TRIAL(feature) \
  static_assert(std::is_same<decltype(::blink::RuntimeEnabledFeatures::     \
                                          feature##EnabledByRuntimeFlag()), \
                             bool>(),                                       \
                #feature " must be part of an origin trial");

namespace blink {

enum class OriginTrialFeature : int32_t {
  // For testing
  kNonExisting = 0,

  kAllowSyncXHRInPageDismissal,
  kAppCache,
  kAutoPictureInPicture,
  kCacheStorageCodeCacheHint,
  kCookieStoreDocument,
  kCookieStoreWorker,
  kCustomElementsV0,
  kDisableHardwareNoiseSuppression,
  kDocumentPolicy,
  kExperimentalAutoplayDynamicDelegation,
  kExperimentalIsInputPending,
  kExperimentalJSProfiler,
  kFeaturePolicyReporting,
  kFileHandling,
  kForceLoadAtTop,
  kHrefTranslate,
  kHTMLImports,
  kIdleDetection,
  kLegacyNativeFileSystem,
  kMeasureMemory,
  kNativeFileSystem,
  kNotificationTriggers,
  kOriginIsolationHeader,
  kOriginTrialsSampleAPI,
  kOriginTrialsSampleAPIDeprecation,
  kOriginTrialsSampleAPIImplied,
  kOriginTrialsSampleAPIInvalidOS,
  kOriginTrialsSampleAPINavigation,
  kOriginTrialsSampleAPIThirdParty,
  kPageFreezeOptIn,
  kPageFreezeOptOut,
  kPerMethodCanMakePaymentQuota,
  kPNaCl,
  kPointerLockOptions,
  kPortals,
  kPriorityHints,
  kQuicTransport,
  kRtcAudioJitterBufferMaxPackets,
  kRtcAudioJitterBufferRtxHandling,
  kRTCIceTransportExtension,
  kRTCInsertableStreams,
  kRTCQuicTransport,
  kRTCStatsRelativePacketArrivalDelay,
  kSerial,
  kShadowDOMV0,
  kSignatureBasedIntegrity,
  kSignedExchangeSubresourcePrefetch,
  kSkipAd,
  kTextFragmentIdentifiers,
  kTouchEventFeatureDetection,
  kTransferableStreams,
  kTrustTokens,
  kUnoptimizedImagePolicies,
  kUnsizedMediaPolicy,
  kWakeLock,
  kWebAssemblySimd,
  kWebAssemblyThreads,
  kWebNFC,
  kWebScheduler,
};

// A pure virtual interface for checking the availability of origin trial
// features in a context.
class PLATFORM_EXPORT FeatureContext {
 public:
  virtual bool FeatureEnabled(OriginTrialFeature) const = 0;
};

// A class that stores static enablers for all experimental features.

class PLATFORM_EXPORT RuntimeEnabledFeatures {
  STATIC_ONLY(RuntimeEnabledFeatures);
 public:
  class PLATFORM_EXPORT Backup {
   public:
    explicit Backup();
    void Restore();

   private:
    bool is_accelerated_2d_canvas_enabled_;
    bool is_accelerated_small_canvases_enabled_;
    bool is_accessibility_expose_aria_annotations_enabled_;
    bool is_accessibility_expose_display_none_enabled_;
    bool is_accessibility_expose_html_element_enabled_;
    bool is_accessibility_object_model_enabled_;
    bool is_address_space_enabled_;
    bool is_ad_tagging_enabled_;
    bool is_allow_activation_delegation_attr_enabled_;
    bool is_allow_content_initiated_data_url_navigations_enabled_;
    bool is_allow_sync_xhr_in_page_dismissal_enabled_;
    bool is_animation_worklet_enabled_;
    bool is_aom_aria_properties_enabled_;
    bool is_aom_aria_relationship_properties_enabled_;
    bool is_app_cache_enabled_;
    bool is_audio_output_devices_enabled_;
    bool is_audio_video_tracks_enabled_;
    bool is_audio_worklet_realtime_thread_enabled_;
    bool is_auto_lazy_load_on_reloads_enabled_;
    bool is_automatic_lazy_frame_loading_enabled_;
    bool is_automatic_lazy_image_loading_enabled_;
    bool is_automation_controlled_enabled_;
    bool is_auto_picture_in_picture_enabled_;
    bool is_autoplay_ignores_web_audio_enabled_;
    bool is_back_forward_cache_enabled_;
    bool is_background_fetch_enabled_;
    bool is_background_video_track_optimization_enabled_;
    bool is_badging_enabled_;
    bool is_barcode_detector_enabled_;
    bool is_before_match_event_enabled_;
    bool is_bidi_caret_affinity_enabled_;
    bool is_blink_runtime_call_stats_enabled_;
    bool is_block_credentialed_subresources_enabled_;
    bool is_block_flow_handles_webkit_line_clamp_enabled_;
    bool is_block_html_parser_on_style_sheets_enabled_;
    bool is_blocking_downloads_in_sandbox_enabled_;
    bool is_blocking_focus_without_user_activation_enabled_;
    bool is_browser_verified_user_activation_keyboard_enabled_;
    bool is_browser_verified_user_activation_mouse_enabled_;
    bool is_cache_inline_script_code_enabled_;
    bool is_cache_storage_code_cache_hint_enabled_;
    bool is_canvas_2d_context_lost_restored_enabled_;
    bool is_canvas_2d_image_chromium_enabled_;
    bool is_canvas_2d_scroll_path_into_view_enabled_;
    bool is_canvas_color_management_enabled_;
    bool is_canvas_hit_region_enabled_;
    bool is_canvas_image_smoothing_enabled_;
    bool is_capture_time_in_csrc_enabled_;
    bool is_click_pointer_event_enabled_;
    bool is_click_retargetting_enabled_;
    bool is_composite_after_paint_enabled_;
    bool is_composited_selection_update_enabled_;
    bool is_computed_accessibility_info_enabled_;
    bool is_consolidated_movement_xy_enabled_;
    bool is_contacts_manager_enabled_;
    bool is_contacts_manager_extra_properties_enabled_;
    bool is_content_index_enabled_;
    bool is_context_menu_enabled_;
    bool is_conversion_measurement_enabled_;
    bool is_cookie_deprecation_messages_enabled_;
    bool is_cookie_store_document_enabled_;
    bool is_cookie_store_worker_enabled_;
    bool is_cookies_without_same_site_must_be_secure_enabled_;
    bool is_cooperative_scheduling_enabled_;
    bool is_cors_rfc_1918_enabled_;
    bool is_cross_origin_isolation_enabled_;
    bool is_css_3_text_enabled_;
    bool is_css_aspect_ratio_property_enabled_;
    bool is_css_calc_as_int_enabled_;
    bool is_css_cascade_enabled_;
    bool is_css_color_scheme_enabled_;
    bool is_css_color_scheme_ua_rendering_enabled_;
    bool is_css_content_visibility_enabled_;
    bool is_css_content_visibility_hidden_matchable_enabled_;
    bool is_css_focus_visible_enabled_;
    bool is_css_foldables_enabled_;
    bool is_css_font_size_adjust_enabled_;
    bool is_css_hex_alpha_color_enabled_;
    bool is_css_independent_transform_properties_enabled_;
    bool is_css_layout_api_enabled_;
    bool is_css_logical_enabled_;
    bool is_css_logical_overflow_enabled_;
    bool is_css_marker_nested_pseudo_element_enabled_;
    bool is_css_marker_pseudo_element_enabled_;
    bool is_css_matched_properties_cache_dependencies_enabled_;
    bool is_css_math_style_enabled_;
    bool is_css_math_superscript_shift_style_enabled_;
    bool is_css_math_variant_enabled_;
    bool is_css_modules_enabled_;
    bool is_css_offset_path_ray_enabled_;
    bool is_css_offset_path_ray_contain_enabled_;
    bool is_css_offset_position_anchor_enabled_;
    bool is_cssom_view_scroll_coordinates_enabled_;
    bool is_css_paint_api_arguments_enabled_;
    bool is_css_picture_in_picture_enabled_;
    bool is_css_pseudo_is_enabled_;
    bool is_css_pseudo_where_enabled_;
    bool is_css_reduced_font_loading_invalidations_enabled_;
    bool is_css_reduced_font_loading_layout_invalidations_enabled_;
    bool is_css_revert_enabled_;
    bool is_css_scroll_timeline_enabled_;
    bool is_css_snap_size_enabled_;
    bool is_css_supports_selector_enabled_;
    bool is_css_variables_2_at_property_enabled_;
    bool is_css_variables_2_image_values_enabled_;
    bool is_css_variables_2_transform_values_enabled_;
    bool is_custom_element_default_style_enabled_;
    bool is_custom_elements_v0_enabled_;
    bool is_custom_state_pseudo_class_enabled_;
    bool is_database_enabled_;
    bool is_declarative_shadow_dom_enabled_;
    bool is_decode_jpeg_420_images_to_yuv_enabled_;
    bool is_decode_lossy_web_p_images_to_yuv_enabled_;
    bool is_delay_async_script_execution_until_finished_parsing_enabled_;
    bool is_delay_async_script_execution_until_first_paint_or_finished_parsing_enabled_;
    bool is_delegated_ink_trails_enabled_;
    bool is_desktop_capture_disable_local_echo_control_enabled_;
    bool is_digital_goods_enabled_;
    bool is_disable_hardware_noise_suppression_enabled_;
    bool is_disable_layer_squashing_enabled_;
    bool is_disallow_document_access_enabled_;
    bool is_display_cutout_api_enabled_;
    bool is_document_cookie_enabled_;
    bool is_document_domain_enabled_;
    bool is_document_policy_enabled_;
    bool is_document_write_enabled_;
    bool is_edit_context_enabled_;
    bool is_editing_ng_enabled_;
    bool is_encrypted_media_encryption_scheme_query_enabled_;
    bool is_encrypted_media_hdcp_policy_check_enabled_;
    bool is_encrypted_media_persistent_usage_record_session_enabled_;
    bool is_enter_key_hint_attribute_enabled_;
    bool is_event_timing_enabled_;
    bool is_exec_command_in_java_script_enabled_;
    bool is_expensive_background_timer_throttling_enabled_;
    bool is_experimental_autoplay_dynamic_delegation_enabled_;
    bool is_experimental_content_security_policy_features_enabled_;
    bool is_experimental_is_input_pending_enabled_;
    bool is_experimental_js_profiler_enabled_;
    bool is_experimental_productivity_features_enabled_;
    bool is_extended_text_metrics_enabled_;
    bool is_extra_webgl_video_texture_metadata_enabled_;
    bool is_face_detector_enabled_;
    bool is_feature_policy_for_client_hints_enabled_;
    bool is_feature_policy_for_sandbox_enabled_;
    bool is_feature_policy_reporting_enabled_;
    bool is_feature_policy_vibrate_feature_enabled_;
    bool is_fetch_upload_streaming_enabled_;
    bool is_file_handling_enabled_;
    bool is_file_system_enabled_;
    bool is_flex_gaps_enabled_;
    bool is_focusless_spatial_navigation_enabled_;
    bool is_font_access_enabled_;
    bool is_font_src_local_matching_enabled_;
    bool is_forced_colors_enabled_;
    bool is_force_defer_script_intervention_enabled_;
    bool is_force_eager_measure_memory_enabled_;
    bool is_force_load_at_top_enabled_;
    bool is_force_overlay_fullscreen_video_enabled_;
    bool is_force_synchronous_html_parsing_enabled_;
    bool is_force_taller_select_popup_enabled_;
    bool is_fractional_scroll_offsets_enabled_;
    bool is_freeze_frames_on_visibility_enabled_;
    bool is_gamepad_button_axis_events_enabled_;
    bool is_get_display_media_enabled_;
    bool is_group_effect_enabled_;
    bool is_href_translate_enabled_;
    bool is_html_imports_enabled_;
    bool is_idb_observer_enabled_;
    bool is_idb_relaxed_durability_enabled_;
    bool is_idle_detection_enabled_;
    bool is_ignore_cross_origin_window_when_named_access_on_window_enabled_;
    bool is_image_orientation_enabled_;
    bool is_implicit_root_scroller_enabled_;
    bool is_import_maps_enabled_;
    bool is_inert_attribute_enabled_;
    bool is_input_element_raw_value_enabled_;
    bool is_input_multiple_fields_ui_enabled_;
    bool is_installed_app_enabled_;
    bool is_intersection_observer_document_scrolling_element_root_enabled_;
    bool is_isolated_code_cache_enabled_;
    bool is_isolated_world_csp_enabled_;
    bool is_keyboard_focusable_scrollers_enabled_;
    bool is_lang_attribute_aware_form_control_ui_enabled_;
    bool is_lang_client_hint_header_enabled_;
    bool is_layout_ng_enabled_;
    bool is_layout_ng_block_fragmentation_enabled_;
    bool is_layout_ng_fieldset_enabled_;
    bool is_layout_ng_flex_box_enabled_;
    bool is_layout_ng_for_controls_enabled_;
    bool is_layout_ng_fragment_item_enabled_;
    bool is_layout_ng_fragment_traversal_enabled_;
    bool is_layout_ng_grid_enabled_;
    bool is_layout_ng_ruby_enabled_;
    bool is_layout_ng_table_enabled_;
    bool is_layout_shift_attribution_enabled_;
    bool is_lazy_frame_loading_enabled_;
    bool is_lazy_frame_visible_load_time_metrics_enabled_;
    bool is_lazy_image_loading_enabled_;
    bool is_lazy_image_visible_load_time_metrics_enabled_;
    bool is_lazy_initialize_media_controls_enabled_;
    bool is_legacy_native_file_system_enabled_;
    bool is_legacy_windows_d_write_font_fallback_enabled_;
    bool is_link_disabled_new_spec_behavior_enabled_;
    bool is_manual_slotting_enabled_;
    bool is_mathml_core_enabled_;
    bool is_measure_memory_enabled_;
    bool is_media_capabilities_dynamic_range_enabled_;
    bool is_media_capabilities_encoding_info_enabled_;
    bool is_media_capabilities_encrypted_media_enabled_;
    bool is_media_capabilities_spatial_audio_enabled_;
    bool is_media_capture_enabled_;
    bool is_media_capture_depth_video_kind_enabled_;
    bool is_media_capture_pan_tilt_enabled_;
    bool is_media_cast_overlay_button_enabled_;
    bool is_media_controls_expand_gesture_enabled_;
    bool is_media_controls_overlay_play_button_enabled_;
    bool is_media_controls_use_cut_out_by_default_enabled_;
    bool is_media_document_download_button_enabled_;
    bool is_media_element_volume_greater_than_one_enabled_;
    bool is_media_engagement_bypass_autoplay_policies_enabled_;
    bool is_media_feeds_enabled_;
    bool is_media_latency_hint_enabled_;
    bool is_media_query_navigation_controls_enabled_;
    bool is_media_session_enabled_;
    bool is_media_session_position_enabled_;
    bool is_media_source_experimental_enabled_;
    bool is_media_source_in_workers_enabled_;
    bool is_media_source_new_abort_and_duration_enabled_;
    bool is_media_source_stable_enabled_;
    bool is_meta_color_scheme_enabled_;
    bool is_middle_click_autoscroll_enabled_;
    bool is_mobile_layout_theme_enabled_;
    bool is_module_service_worker_enabled_;
    bool is_module_shared_worker_enabled_;
    bool is_mojo_js_enabled_;
    bool is_mojo_js_test_enabled_;
    bool is_mouse_subframe_no_implicit_capture_enabled_;
    bool is_named_pages_enabled_;
    bool is_native_file_system_enabled_;
    bool is_native_io_enabled_;
    bool is_navigator_content_utils_enabled_;
    bool is_navigator_language_in_insecure_context_enabled_;
    bool is_net_info_downlink_max_enabled_;
    bool is_never_slow_mode_enabled_;
    bool is_new_canvas_2d_api_enabled_;
    bool is_new_remote_playback_pipeline_enabled_;
    bool is_no_idle_encoding_for_web_tests_enabled_;
    bool is_notification_constructor_enabled_;
    bool is_notification_content_image_enabled_;
    bool is_notifications_enabled_;
    bool is_notification_triggers_enabled_;
    bool is_off_main_thread_css_paint_enabled_;
    bool is_offscreen_canvas_commit_enabled_;
    bool is_on_device_change_enabled_;
    bool is_orientation_event_enabled_;
    bool is_origin_isolation_header_enabled_;
    bool is_origin_policy_enabled_;
    bool is_origin_trials_sample_api_enabled_;
    bool is_origin_trials_sample_api_dependent_enabled_;
    bool is_origin_trials_sample_api_deprecation_enabled_;
    bool is_origin_trials_sample_api_implied_enabled_;
    bool is_origin_trials_sample_api_invalid_os_enabled_;
    bool is_origin_trials_sample_api_navigation_enabled_;
    bool is_origin_trials_sample_api_third_party_enabled_;
    bool is_out_of_blink_cors_enabled_;
    bool is_overflow_icons_for_media_controls_enabled_;
    bool is_overscroll_customization_enabled_;
    bool is_page_freeze_opt_in_enabled_;
    bool is_page_freeze_opt_out_enabled_;
    bool is_page_popup_enabled_;
    bool is_paint_under_invalidation_checking_enabled_;
    bool is_parse_url_protocol_handler_enabled_;
    bool is_pass_paint_visual_rect_to_compositor_enabled_;
    bool is_password_reveal_enabled_;
    bool is_payment_app_enabled_;
    bool is_payment_handler_change_payment_method_enabled_;
    bool is_payment_handler_handles_shipping_and_contact_enabled_;
    bool is_payment_handler_minimal_ui_enabled_;
    bool is_payment_method_change_event_enabled_;
    bool is_payment_request_enabled_;
    bool is_payment_request_merchant_validation_event_enabled_;
    bool is_payment_retry_enabled_;
    bool is_percent_based_scrolling_enabled_;
    bool is_performance_manager_instrumentation_enabled_;
    bool is_periodic_background_sync_enabled_;
    bool is_per_method_can_make_payment_quota_enabled_;
    bool is_permission_delegation_enabled_;
    bool is_permissions_enabled_;
    bool is_permissions_request_revoke_enabled_;
    bool is_picture_in_picture_enabled_;
    bool is_picture_in_picture_api_enabled_;
    bool is_picture_in_picture_v_2_enabled_;
    bool is_p_na_cl_enabled_;
    bool is_pointer_lock_options_enabled_;
    bool is_pointer_raw_update_enabled_;
    bool is_portals_enabled_;
    bool is_post_animation_frame_enabled_;
    bool is_precise_memory_info_enabled_;
    bool is_prefer_non_composited_scrolling_enabled_;
    bool is_prefers_reduced_data_enabled_;
    bool is_prefixed_video_fullscreen_enabled_;
    bool is_presentation_enabled_;
    bool is_priority_hints_enabled_;
    bool is_push_messaging_enabled_;
    bool is_push_messaging_subscription_change_enabled_;
    bool is_quic_transport_enabled_;
    bool is_raw_clipboard_enabled_;
    bool is_reduced_referrer_granularity_enabled_;
    bool is_remote_playback_enabled_;
    bool is_remote_playback_backend_enabled_;
    bool is_request_video_frame_callback_enabled_;
    bool is_resize_observer_updates_enabled_;
    bool is_restrict_app_cache_to_secure_contexts_enabled_;
    bool is_restrict_automatic_lazy_frame_loading_to_data_saver_enabled_;
    bool is_restrict_automatic_lazy_image_loading_to_data_saver_enabled_;
    bool is_rtc_audio_jitter_buffer_max_packets_enabled_;
    bool is_rtc_audio_jitter_buffer_rtx_handling_enabled_;
    bool is_rtc_ice_transport_extension_enabled_;
    bool is_rtc_insertable_streams_enabled_;
    bool is_rtc_quic_transport_enabled_;
    bool is_rtc_stats_relative_packet_arrival_delay_enabled_;
    bool is_rtc_svc_scalability_mode_enabled_;
    bool is_rtc_unified_plan_enabled_;
    bool is_rtc_unified_plan_by_default_enabled_;
    bool is_same_site_by_default_cookies_enabled_;
    bool is_screen_wake_lock_enabled_;
    bool is_scripted_speech_recognition_enabled_;
    bool is_scripted_speech_synthesis_enabled_;
    bool is_scroll_customization_enabled_;
    bool is_scroll_snap_after_layout_enabled_;
    bool is_scroll_timeline_enabled_;
    bool is_scroll_top_left_interop_enabled_;
    bool is_scroll_unification_enabled_;
    bool is_send_beacon_throw_for_blob_with_non_simple_type_enabled_;
    bool is_send_mouse_events_disabled_form_controls_enabled_;
    bool is_sensor_extra_classes_enabled_;
    bool is_serial_enabled_;
    bool is_service_worker_client_lifecycle_state_enabled_;
    bool is_service_worker_fetch_event_worker_timing_enabled_;
    bool is_shadow_dom_v0_enabled_;
    bool is_shared_array_buffer_enabled_;
    bool is_shared_worker_enabled_;
    bool is_signature_based_integrity_enabled_;
    bool is_signed_exchange_prefetch_cache_for_navigations_enabled_;
    bool is_signed_exchange_subresource_prefetch_enabled_;
    bool is_skip_ad_enabled_;
    bool is_skip_touch_event_filter_enabled_;
    bool is_sms_receiver_enabled_;
    bool is_squash_after_paint_enabled_;
    bool is_stable_blink_features_enabled_;
    bool is_storage_access_api_enabled_;
    bool is_strict_mime_types_for_workers_enabled_;
    bool is_subresource_web_bundles_enabled_;
    bool is_surface_embedding_features_enabled_;
    bool is_system_wake_lock_enabled_;
    bool is_test_feature_enabled_;
    bool is_test_feature_dependent_enabled_;
    bool is_test_feature_implied_enabled_;
    bool is_text_detector_enabled_;
    bool is_text_fragment_identifiers_enabled_;
    bool is_third_party_origin_trials_enabled_;
    bool is_timer_throttling_for_background_tabs_enabled_;
    bool is_timer_throttling_for_hidden_frames_enabled_;
    bool is_time_zone_change_event_enabled_;
    bool is_touch_event_feature_detection_enabled_;
    bool is_track_layout_passes_per_block_enabled_;
    bool is_transferable_streams_enabled_;
    bool is_transform_interop_enabled_;
    bool is_translate_service_enabled_;
    bool is_trusted_dom_types_enabled_;
    bool is_trust_tokens_enabled_;
    bool is_trust_tokens_always_allow_issuance_enabled_;
    bool is_unclosed_form_control_is_invalid_enabled_;
    bool is_underline_offset_thickness_enabled_;
    bool is_unoptimized_image_policies_enabled_;
    bool is_unsized_media_policy_enabled_;
    bool is_user_activation_post_message_transfer_enabled_;
    bool is_user_activation_same_origin_visibility_enabled_;
    bool is_user_agent_client_hint_enabled_;
    bool is_v8_idle_tasks_enabled_;
    bool is_video_auto_fullscreen_enabled_;
    bool is_video_fullscreen_orientation_lock_enabled_;
    bool is_video_playback_quality_enabled_;
    bool is_video_rotate_to_fullscreen_enabled_;
    bool is_video_wake_lock_optimisation_hidden_muted_enabled_;
    bool is_virtual_keyboard_enabled_;
    bool is_visibility_collapse_column_enabled_;
    bool is_wake_lock_enabled_;
    bool is_web_animations_api_enabled_;
    bool is_web_animations_svg_enabled_;
    bool is_web_assembly_simd_enabled_;
    bool is_web_assembly_threads_enabled_;
    bool is_web_auth_enabled_;
    bool is_web_authentication_get_assertion_feature_policy_enabled_;
    bool is_web_bluetooth_enabled_;
    bool is_web_bluetooth_get_devices_enabled_;
    bool is_web_bluetooth_remote_characteristic_new_write_value_enabled_;
    bool is_web_bluetooth_scanning_enabled_;
    bool is_web_bluetooth_watch_advertisements_enabled_;
    bool is_web_codecs_enabled_;
    bool is_web_crypto_curve_25519_enabled_;
    bool is_webgl2_compute_context_enabled_;
    bool is_webgl_draft_extensions_enabled_;
    bool is_webgl_image_chromium_enabled_;
    bool is_webgpu_enabled_;
    bool is_web_hid_enabled_;
    bool is_web_nfc_enabled_;
    bool is_web_scheduler_enabled_;
    bool is_web_share_enabled_;
    bool is_web_share_v_2_enabled_;
    bool is_websocket_stream_enabled_;
    bool is_web_usb_enabled_;
    bool is_web_usb_on_dedicated_workers_enabled_;
    bool is_web_vtt_regions_enabled_;
    bool is_web_xr_enabled_;
    bool is_web_xr_anchors_enabled_;
    bool is_web_xr_ar_module_enabled_;
    bool is_web_xr_camera_access_enabled_;
    bool is_web_xr_hit_test_enabled_;
    bool is_web_xr_hit_test_entity_types_enabled_;
    bool is_web_xr_light_estimation_enabled_;
    bool is_web_xr_plane_detection_enabled_;
    bool is_window_placement_enabled_;
    bool is_window_segments_enabled_;
    bool is_xslt_enabled_;
  };

  static void SetStableFeaturesEnabled(bool);
  static void SetExperimentalFeaturesEnabled(bool);
  static void SetTestFeaturesEnabled(bool);
  static void SetOriginTrialControlledFeaturesEnabled(bool);

  static void SetFeatureEnabledFromString(const std::string& name, bool enabled);

  static void SetAccelerated2dCanvasEnabled(bool enabled) { is_accelerated_2d_canvas_enabled_ = enabled; }
  static bool Accelerated2dCanvasEnabled() {
    return is_accelerated_2d_canvas_enabled_;
  }
  static bool Accelerated2dCanvasEnabled(const FeatureContext*) { return Accelerated2dCanvasEnabled(); }

  static void SetAcceleratedSmallCanvasesEnabled(bool enabled) { is_accelerated_small_canvases_enabled_ = enabled; }
  static bool AcceleratedSmallCanvasesEnabled() {
    return is_accelerated_small_canvases_enabled_;
  }
  static bool AcceleratedSmallCanvasesEnabled(const FeatureContext*) { return AcceleratedSmallCanvasesEnabled(); }

  static void SetAccessibilityExposeARIAAnnotationsEnabled(bool enabled) { is_accessibility_expose_aria_annotations_enabled_ = enabled; }
  static bool AccessibilityExposeARIAAnnotationsEnabled() {
    return is_accessibility_expose_aria_annotations_enabled_;
  }
  static bool AccessibilityExposeARIAAnnotationsEnabled(const FeatureContext*) { return AccessibilityExposeARIAAnnotationsEnabled(); }

  static void SetAccessibilityExposeDisplayNoneEnabled(bool enabled) { is_accessibility_expose_display_none_enabled_ = enabled; }
  static bool AccessibilityExposeDisplayNoneEnabled() {
    return is_accessibility_expose_display_none_enabled_;
  }
  static bool AccessibilityExposeDisplayNoneEnabled(const FeatureContext*) { return AccessibilityExposeDisplayNoneEnabled(); }

  static void SetAccessibilityExposeHTMLElementEnabled(bool enabled) { is_accessibility_expose_html_element_enabled_ = enabled; }
  static bool AccessibilityExposeHTMLElementEnabled() {
    return is_accessibility_expose_html_element_enabled_;
  }
  static bool AccessibilityExposeHTMLElementEnabled(const FeatureContext*) { return AccessibilityExposeHTMLElementEnabled(); }

  static void SetAccessibilityObjectModelEnabled(bool enabled) { is_accessibility_object_model_enabled_ = enabled; }
  static bool AccessibilityObjectModelEnabled() {
    return is_accessibility_object_model_enabled_;
  }
  static bool AccessibilityObjectModelEnabled(const FeatureContext*) { return AccessibilityObjectModelEnabled(); }

  static void SetAddressSpaceEnabled(bool enabled) { is_address_space_enabled_ = enabled; }
  static bool AddressSpaceEnabled() {
    if (CorsRFC1918Enabled())
      return true;
    return is_address_space_enabled_;
  }
  static bool AddressSpaceEnabled(const FeatureContext*) { return AddressSpaceEnabled(); }

  static void SetAdTaggingEnabled(bool enabled) { is_ad_tagging_enabled_ = enabled; }
  static bool AdTaggingEnabled() {
    return is_ad_tagging_enabled_;
  }
  static bool AdTaggingEnabled(const FeatureContext*) { return AdTaggingEnabled(); }

  static void SetAllowActivationDelegationAttrEnabled(bool enabled) { is_allow_activation_delegation_attr_enabled_ = enabled; }
  static bool AllowActivationDelegationAttrEnabled() {
    return is_allow_activation_delegation_attr_enabled_;
  }
  static bool AllowActivationDelegationAttrEnabled(const FeatureContext*) { return AllowActivationDelegationAttrEnabled(); }

  static void SetAllowContentInitiatedDataUrlNavigationsEnabled(bool enabled) { is_allow_content_initiated_data_url_navigations_enabled_ = enabled; }
  static bool AllowContentInitiatedDataUrlNavigationsEnabled() {
    return is_allow_content_initiated_data_url_navigations_enabled_;
  }
  static bool AllowContentInitiatedDataUrlNavigationsEnabled(const FeatureContext*) { return AllowContentInitiatedDataUrlNavigationsEnabled(); }

  static void SetAnimationWorkletEnabled(bool enabled) { is_animation_worklet_enabled_ = enabled; }
  static bool AnimationWorkletEnabled() {
    return is_animation_worklet_enabled_;
  }
  static bool AnimationWorkletEnabled(const FeatureContext*) { return AnimationWorkletEnabled(); }

  static void SetAOMAriaPropertiesEnabled(bool enabled) { is_aom_aria_properties_enabled_ = enabled; }
  static bool AOMAriaPropertiesEnabled() {
    return is_aom_aria_properties_enabled_;
  }
  static bool AOMAriaPropertiesEnabled(const FeatureContext*) { return AOMAriaPropertiesEnabled(); }

  static void SetAOMAriaRelationshipPropertiesEnabled(bool enabled) { is_aom_aria_relationship_properties_enabled_ = enabled; }
  static bool AOMAriaRelationshipPropertiesEnabled() {
    return is_aom_aria_relationship_properties_enabled_;
  }
  static bool AOMAriaRelationshipPropertiesEnabled(const FeatureContext*) { return AOMAriaRelationshipPropertiesEnabled(); }

  static void SetAudioOutputDevicesEnabled(bool enabled) { is_audio_output_devices_enabled_ = enabled; }
  static bool AudioOutputDevicesEnabled() {
    return is_audio_output_devices_enabled_;
  }
  static bool AudioOutputDevicesEnabled(const FeatureContext*) { return AudioOutputDevicesEnabled(); }

  static void SetAudioVideoTracksEnabled(bool enabled) { is_audio_video_tracks_enabled_ = enabled; }
  static bool AudioVideoTracksEnabled() {
    return is_audio_video_tracks_enabled_;
  }
  static bool AudioVideoTracksEnabled(const FeatureContext*) { return AudioVideoTracksEnabled(); }

  static void SetAudioWorkletRealtimeThreadEnabled(bool enabled) { is_audio_worklet_realtime_thread_enabled_ = enabled; }
  static bool AudioWorkletRealtimeThreadEnabled() {
    return is_audio_worklet_realtime_thread_enabled_;
  }
  static bool AudioWorkletRealtimeThreadEnabled(const FeatureContext*) { return AudioWorkletRealtimeThreadEnabled(); }

  static void SetAutoLazyLoadOnReloadsEnabled(bool enabled) { is_auto_lazy_load_on_reloads_enabled_ = enabled; }
  static bool AutoLazyLoadOnReloadsEnabled() {
    if (!LazyFrameLoadingEnabled())
      return false;
    return is_auto_lazy_load_on_reloads_enabled_;
  }
  static bool AutoLazyLoadOnReloadsEnabled(const FeatureContext*) { return AutoLazyLoadOnReloadsEnabled(); }

  static void SetAutomaticLazyFrameLoadingEnabled(bool enabled) { is_automatic_lazy_frame_loading_enabled_ = enabled; }
  static bool AutomaticLazyFrameLoadingEnabled() {
    if (!LazyFrameLoadingEnabled())
      return false;
    return is_automatic_lazy_frame_loading_enabled_;
  }
  static bool AutomaticLazyFrameLoadingEnabled(const FeatureContext*) { return AutomaticLazyFrameLoadingEnabled(); }

  static void SetAutomaticLazyImageLoadingEnabled(bool enabled) { is_automatic_lazy_image_loading_enabled_ = enabled; }
  static bool AutomaticLazyImageLoadingEnabled() {
    if (!LazyImageLoadingEnabled())
      return false;
    return is_automatic_lazy_image_loading_enabled_;
  }
  static bool AutomaticLazyImageLoadingEnabled(const FeatureContext*) { return AutomaticLazyImageLoadingEnabled(); }

  static void SetAutomationControlledEnabled(bool enabled) { is_automation_controlled_enabled_ = enabled; }
  static bool AutomationControlledEnabled() {
    return is_automation_controlled_enabled_;
  }
  static bool AutomationControlledEnabled(const FeatureContext*) { return AutomationControlledEnabled(); }

  static void SetAutoplayIgnoresWebAudioEnabled(bool enabled) { is_autoplay_ignores_web_audio_enabled_ = enabled; }
  static bool AutoplayIgnoresWebAudioEnabled() {
    return is_autoplay_ignores_web_audio_enabled_;
  }
  static bool AutoplayIgnoresWebAudioEnabled(const FeatureContext*) { return AutoplayIgnoresWebAudioEnabled(); }

  static void SetBackForwardCacheEnabled(bool enabled) { is_back_forward_cache_enabled_ = enabled; }
  static bool BackForwardCacheEnabled() {
    return is_back_forward_cache_enabled_;
  }
  static bool BackForwardCacheEnabled(const FeatureContext*) { return BackForwardCacheEnabled(); }

  static void SetBackgroundFetchEnabled(bool enabled) { is_background_fetch_enabled_ = enabled; }
  static bool BackgroundFetchEnabled() {
    return is_background_fetch_enabled_;
  }
  static bool BackgroundFetchEnabled(const FeatureContext*) { return BackgroundFetchEnabled(); }

  static void SetBackgroundVideoTrackOptimizationEnabled(bool enabled) { is_background_video_track_optimization_enabled_ = enabled; }
  static bool BackgroundVideoTrackOptimizationEnabled() {
    return is_background_video_track_optimization_enabled_;
  }
  static bool BackgroundVideoTrackOptimizationEnabled(const FeatureContext*) { return BackgroundVideoTrackOptimizationEnabled(); }

  static void SetBadgingEnabled(bool enabled) { is_badging_enabled_ = enabled; }
  static bool BadgingEnabled() {
    return is_badging_enabled_;
  }
  static bool BadgingEnabled(const FeatureContext*) { return BadgingEnabled(); }

  static void SetBarcodeDetectorEnabled(bool enabled) { is_barcode_detector_enabled_ = enabled; }
  static bool BarcodeDetectorEnabled() {
    return is_barcode_detector_enabled_;
  }
  static bool BarcodeDetectorEnabled(const FeatureContext*) { return BarcodeDetectorEnabled(); }

  static void SetBeforeMatchEventEnabled(bool enabled) { is_before_match_event_enabled_ = enabled; }
  static bool BeforeMatchEventEnabled() {
    return is_before_match_event_enabled_;
  }
  static bool BeforeMatchEventEnabled(const FeatureContext*) { return BeforeMatchEventEnabled(); }

  static void SetBidiCaretAffinityEnabled(bool enabled) { is_bidi_caret_affinity_enabled_ = enabled; }
  static bool BidiCaretAffinityEnabled() {
    return is_bidi_caret_affinity_enabled_;
  }
  static bool BidiCaretAffinityEnabled(const FeatureContext*) { return BidiCaretAffinityEnabled(); }

  static void SetBlinkRuntimeCallStatsEnabled(bool enabled) { is_blink_runtime_call_stats_enabled_ = enabled; }
  static bool BlinkRuntimeCallStatsEnabled() {
    return is_blink_runtime_call_stats_enabled_;
  }
  static bool BlinkRuntimeCallStatsEnabled(const FeatureContext*) { return BlinkRuntimeCallStatsEnabled(); }

  static void SetBlockCredentialedSubresourcesEnabled(bool enabled) { is_block_credentialed_subresources_enabled_ = enabled; }
  static bool BlockCredentialedSubresourcesEnabled() {
    return is_block_credentialed_subresources_enabled_;
  }
  static bool BlockCredentialedSubresourcesEnabled(const FeatureContext*) { return BlockCredentialedSubresourcesEnabled(); }

  static void SetBlockFlowHandlesWebkitLineClampEnabled(bool enabled) { is_block_flow_handles_webkit_line_clamp_enabled_ = enabled; }
  static bool BlockFlowHandlesWebkitLineClampEnabled() {
    return is_block_flow_handles_webkit_line_clamp_enabled_;
  }
  static bool BlockFlowHandlesWebkitLineClampEnabled(const FeatureContext*) { return BlockFlowHandlesWebkitLineClampEnabled(); }

  static void SetBlockHTMLParserOnStyleSheetsEnabled(bool enabled) { is_block_html_parser_on_style_sheets_enabled_ = enabled; }
  static bool BlockHTMLParserOnStyleSheetsEnabled() {
    return is_block_html_parser_on_style_sheets_enabled_;
  }
  static bool BlockHTMLParserOnStyleSheetsEnabled(const FeatureContext*) { return BlockHTMLParserOnStyleSheetsEnabled(); }

  static void SetBlockingDownloadsInSandboxEnabled(bool enabled) { is_blocking_downloads_in_sandbox_enabled_ = enabled; }
  static bool BlockingDownloadsInSandboxEnabled() {
    return is_blocking_downloads_in_sandbox_enabled_;
  }
  static bool BlockingDownloadsInSandboxEnabled(const FeatureContext*) { return BlockingDownloadsInSandboxEnabled(); }

  static void SetBlockingFocusWithoutUserActivationEnabled(bool enabled) { is_blocking_focus_without_user_activation_enabled_ = enabled; }
  static bool BlockingFocusWithoutUserActivationEnabled() {
    return is_blocking_focus_without_user_activation_enabled_;
  }
  static bool BlockingFocusWithoutUserActivationEnabled(const FeatureContext*) { return BlockingFocusWithoutUserActivationEnabled(); }

  static void SetBrowserVerifiedUserActivationKeyboardEnabled(bool enabled) { is_browser_verified_user_activation_keyboard_enabled_ = enabled; }
  static bool BrowserVerifiedUserActivationKeyboardEnabled() {
    return is_browser_verified_user_activation_keyboard_enabled_;
  }
  static bool BrowserVerifiedUserActivationKeyboardEnabled(const FeatureContext*) { return BrowserVerifiedUserActivationKeyboardEnabled(); }

  static void SetBrowserVerifiedUserActivationMouseEnabled(bool enabled) { is_browser_verified_user_activation_mouse_enabled_ = enabled; }
  static bool BrowserVerifiedUserActivationMouseEnabled() {
    return is_browser_verified_user_activation_mouse_enabled_;
  }
  static bool BrowserVerifiedUserActivationMouseEnabled(const FeatureContext*) { return BrowserVerifiedUserActivationMouseEnabled(); }

  static void SetCacheInlineScriptCodeEnabled(bool enabled) { is_cache_inline_script_code_enabled_ = enabled; }
  static bool CacheInlineScriptCodeEnabled() {
    return is_cache_inline_script_code_enabled_;
  }
  static bool CacheInlineScriptCodeEnabled(const FeatureContext*) { return CacheInlineScriptCodeEnabled(); }

  static void SetCanvas2dContextLostRestoredEnabled(bool enabled) { is_canvas_2d_context_lost_restored_enabled_ = enabled; }
  static bool Canvas2dContextLostRestoredEnabled() {
    return is_canvas_2d_context_lost_restored_enabled_;
  }
  static bool Canvas2dContextLostRestoredEnabled(const FeatureContext*) { return Canvas2dContextLostRestoredEnabled(); }

  static void SetCanvas2dImageChromiumEnabled(bool enabled) { is_canvas_2d_image_chromium_enabled_ = enabled; }
  static bool Canvas2dImageChromiumEnabled() {
    return is_canvas_2d_image_chromium_enabled_;
  }
  static bool Canvas2dImageChromiumEnabled(const FeatureContext*) { return Canvas2dImageChromiumEnabled(); }

  static void SetCanvas2dScrollPathIntoViewEnabled(bool enabled) { is_canvas_2d_scroll_path_into_view_enabled_ = enabled; }
  static bool Canvas2dScrollPathIntoViewEnabled() {
    return is_canvas_2d_scroll_path_into_view_enabled_;
  }
  static bool Canvas2dScrollPathIntoViewEnabled(const FeatureContext*) { return Canvas2dScrollPathIntoViewEnabled(); }

  static void SetCanvasColorManagementEnabled(bool enabled) { is_canvas_color_management_enabled_ = enabled; }
  static bool CanvasColorManagementEnabled() {
    return is_canvas_color_management_enabled_;
  }
  static bool CanvasColorManagementEnabled(const FeatureContext*) { return CanvasColorManagementEnabled(); }

  static void SetCanvasHitRegionEnabled(bool enabled) { is_canvas_hit_region_enabled_ = enabled; }
  static bool CanvasHitRegionEnabled() {
    return is_canvas_hit_region_enabled_;
  }
  static bool CanvasHitRegionEnabled(const FeatureContext*) { return CanvasHitRegionEnabled(); }

  static void SetCanvasImageSmoothingEnabled(bool enabled) { is_canvas_image_smoothing_enabled_ = enabled; }
  static bool CanvasImageSmoothingEnabled() {
    return is_canvas_image_smoothing_enabled_;
  }
  static bool CanvasImageSmoothingEnabled(const FeatureContext*) { return CanvasImageSmoothingEnabled(); }

  static void SetCaptureTimeInCsrcEnabled(bool enabled) { is_capture_time_in_csrc_enabled_ = enabled; }
  static bool CaptureTimeInCsrcEnabled() {
    return is_capture_time_in_csrc_enabled_;
  }
  static bool CaptureTimeInCsrcEnabled(const FeatureContext*) { return CaptureTimeInCsrcEnabled(); }

  static void SetClickPointerEventEnabled(bool enabled) { is_click_pointer_event_enabled_ = enabled; }
  static bool ClickPointerEventEnabled() {
    return is_click_pointer_event_enabled_;
  }
  static bool ClickPointerEventEnabled(const FeatureContext*) { return ClickPointerEventEnabled(); }

  static void SetClickRetargettingEnabled(bool enabled) { is_click_retargetting_enabled_ = enabled; }
  static bool ClickRetargettingEnabled() {
    return is_click_retargetting_enabled_;
  }
  static bool ClickRetargettingEnabled(const FeatureContext*) { return ClickRetargettingEnabled(); }

  static void SetCompositeAfterPaintEnabled(bool enabled) { is_composite_after_paint_enabled_ = enabled; }
  static bool CompositeAfterPaintEnabled() {
    return is_composite_after_paint_enabled_;
  }
  static bool CompositeAfterPaintEnabled(const FeatureContext*) { return CompositeAfterPaintEnabled(); }

  static void SetCompositedSelectionUpdateEnabled(bool enabled) { is_composited_selection_update_enabled_ = enabled; }
  static bool CompositedSelectionUpdateEnabled() {
    return is_composited_selection_update_enabled_;
  }
  static bool CompositedSelectionUpdateEnabled(const FeatureContext*) { return CompositedSelectionUpdateEnabled(); }

  static void SetComputedAccessibilityInfoEnabled(bool enabled) { is_computed_accessibility_info_enabled_ = enabled; }
  static bool ComputedAccessibilityInfoEnabled() {
    return is_computed_accessibility_info_enabled_;
  }
  static bool ComputedAccessibilityInfoEnabled(const FeatureContext*) { return ComputedAccessibilityInfoEnabled(); }

  static void SetConsolidatedMovementXYEnabled(bool enabled) { is_consolidated_movement_xy_enabled_ = enabled; }
  static bool ConsolidatedMovementXYEnabled() {
    return is_consolidated_movement_xy_enabled_;
  }
  static bool ConsolidatedMovementXYEnabled(const FeatureContext*) { return ConsolidatedMovementXYEnabled(); }

  static void SetContactsManagerEnabled(bool enabled) { is_contacts_manager_enabled_ = enabled; }
  static bool ContactsManagerEnabled() {
    return is_contacts_manager_enabled_;
  }
  static bool ContactsManagerEnabled(const FeatureContext*) { return ContactsManagerEnabled(); }

  static void SetContactsManagerExtraPropertiesEnabled(bool enabled) { is_contacts_manager_extra_properties_enabled_ = enabled; }
  static bool ContactsManagerExtraPropertiesEnabled() {
    return is_contacts_manager_extra_properties_enabled_;
  }
  static bool ContactsManagerExtraPropertiesEnabled(const FeatureContext*) { return ContactsManagerExtraPropertiesEnabled(); }

  static void SetContentIndexEnabled(bool enabled) { is_content_index_enabled_ = enabled; }
  static bool ContentIndexEnabled() {
    return is_content_index_enabled_;
  }
  static bool ContentIndexEnabled(const FeatureContext*) { return ContentIndexEnabled(); }

  static void SetContextMenuEnabled(bool enabled) { is_context_menu_enabled_ = enabled; }
  static bool ContextMenuEnabled() {
    return is_context_menu_enabled_;
  }
  static bool ContextMenuEnabled(const FeatureContext*) { return ContextMenuEnabled(); }

  static void SetConversionMeasurementEnabled(bool enabled) { is_conversion_measurement_enabled_ = enabled; }
  static bool ConversionMeasurementEnabled() {
    return is_conversion_measurement_enabled_;
  }
  static bool ConversionMeasurementEnabled(const FeatureContext*) { return ConversionMeasurementEnabled(); }

  static void SetCookieDeprecationMessagesEnabled(bool enabled) { is_cookie_deprecation_messages_enabled_ = enabled; }
  static bool CookieDeprecationMessagesEnabled() {
    return is_cookie_deprecation_messages_enabled_;
  }
  static bool CookieDeprecationMessagesEnabled(const FeatureContext*) { return CookieDeprecationMessagesEnabled(); }

  static void SetCookiesWithoutSameSiteMustBeSecureEnabled(bool enabled) { is_cookies_without_same_site_must_be_secure_enabled_ = enabled; }
  static bool CookiesWithoutSameSiteMustBeSecureEnabled() {
    return is_cookies_without_same_site_must_be_secure_enabled_;
  }
  static bool CookiesWithoutSameSiteMustBeSecureEnabled(const FeatureContext*) { return CookiesWithoutSameSiteMustBeSecureEnabled(); }

  static void SetCooperativeSchedulingEnabled(bool enabled) { is_cooperative_scheduling_enabled_ = enabled; }
  static bool CooperativeSchedulingEnabled() {
    return is_cooperative_scheduling_enabled_;
  }
  static bool CooperativeSchedulingEnabled(const FeatureContext*) { return CooperativeSchedulingEnabled(); }

  static void SetCorsRFC1918Enabled(bool enabled) { is_cors_rfc_1918_enabled_ = enabled; }
  static bool CorsRFC1918Enabled() {
    return is_cors_rfc_1918_enabled_;
  }
  static bool CorsRFC1918Enabled(const FeatureContext*) { return CorsRFC1918Enabled(); }

  static void SetCrossOriginIsolationEnabled(bool enabled) { is_cross_origin_isolation_enabled_ = enabled; }
  static bool CrossOriginIsolationEnabled() {
    return is_cross_origin_isolation_enabled_;
  }
  static bool CrossOriginIsolationEnabled(const FeatureContext*) { return CrossOriginIsolationEnabled(); }

  static void SetCSS3TextEnabled(bool enabled) { is_css_3_text_enabled_ = enabled; }
  static bool CSS3TextEnabled() {
    return is_css_3_text_enabled_;
  }
  static bool CSS3TextEnabled(const FeatureContext*) { return CSS3TextEnabled(); }

  static void SetCSSAspectRatioPropertyEnabled(bool enabled) { is_css_aspect_ratio_property_enabled_ = enabled; }
  static bool CSSAspectRatioPropertyEnabled() {
    return is_css_aspect_ratio_property_enabled_;
  }
  static bool CSSAspectRatioPropertyEnabled(const FeatureContext*) { return CSSAspectRatioPropertyEnabled(); }

  static void SetCSSCalcAsIntEnabled(bool enabled) { is_css_calc_as_int_enabled_ = enabled; }
  static bool CSSCalcAsIntEnabled() {
    return is_css_calc_as_int_enabled_;
  }
  static bool CSSCalcAsIntEnabled(const FeatureContext*) { return CSSCalcAsIntEnabled(); }

  static void SetCSSCascadeEnabled(bool enabled) { is_css_cascade_enabled_ = enabled; }
  static bool CSSCascadeEnabled() {
    return is_css_cascade_enabled_;
  }
  static bool CSSCascadeEnabled(const FeatureContext*) { return CSSCascadeEnabled(); }

  static void SetCSSColorSchemeEnabled(bool enabled) { is_css_color_scheme_enabled_ = enabled; }
  static bool CSSColorSchemeEnabled() {
    return is_css_color_scheme_enabled_;
  }
  static bool CSSColorSchemeEnabled(const FeatureContext*) { return CSSColorSchemeEnabled(); }

  static void SetCSSColorSchemeUARenderingEnabled(bool enabled) { is_css_color_scheme_ua_rendering_enabled_ = enabled; }
  static bool CSSColorSchemeUARenderingEnabled() {
    return is_css_color_scheme_ua_rendering_enabled_;
  }
  static bool CSSColorSchemeUARenderingEnabled(const FeatureContext*) { return CSSColorSchemeUARenderingEnabled(); }

  static void SetCSSContentVisibilityEnabled(bool enabled) { is_css_content_visibility_enabled_ = enabled; }
  static bool CSSContentVisibilityEnabled() {
    return is_css_content_visibility_enabled_;
  }
  static bool CSSContentVisibilityEnabled(const FeatureContext*) { return CSSContentVisibilityEnabled(); }

  static void SetCSSContentVisibilityHiddenMatchableEnabled(bool enabled) { is_css_content_visibility_hidden_matchable_enabled_ = enabled; }
  static bool CSSContentVisibilityHiddenMatchableEnabled() {
    return is_css_content_visibility_hidden_matchable_enabled_;
  }
  static bool CSSContentVisibilityHiddenMatchableEnabled(const FeatureContext*) { return CSSContentVisibilityHiddenMatchableEnabled(); }

  static void SetCSSFocusVisibleEnabled(bool enabled) { is_css_focus_visible_enabled_ = enabled; }
  static bool CSSFocusVisibleEnabled() {
    return is_css_focus_visible_enabled_;
  }
  static bool CSSFocusVisibleEnabled(const FeatureContext*) { return CSSFocusVisibleEnabled(); }

  static void SetCSSFoldablesEnabled(bool enabled) { is_css_foldables_enabled_ = enabled; }
  static bool CSSFoldablesEnabled() {
    return is_css_foldables_enabled_;
  }
  static bool CSSFoldablesEnabled(const FeatureContext*) { return CSSFoldablesEnabled(); }

  static void SetCSSFontSizeAdjustEnabled(bool enabled) { is_css_font_size_adjust_enabled_ = enabled; }
  static bool CSSFontSizeAdjustEnabled() {
    return is_css_font_size_adjust_enabled_;
  }
  static bool CSSFontSizeAdjustEnabled(const FeatureContext*) { return CSSFontSizeAdjustEnabled(); }

  static void SetCSSHexAlphaColorEnabled(bool enabled) { is_css_hex_alpha_color_enabled_ = enabled; }
  static bool CSSHexAlphaColorEnabled() {
    return is_css_hex_alpha_color_enabled_;
  }
  static bool CSSHexAlphaColorEnabled(const FeatureContext*) { return CSSHexAlphaColorEnabled(); }

  static void SetCSSIndependentTransformPropertiesEnabled(bool enabled) { is_css_independent_transform_properties_enabled_ = enabled; }
  static bool CSSIndependentTransformPropertiesEnabled() {
    return is_css_independent_transform_properties_enabled_;
  }
  static bool CSSIndependentTransformPropertiesEnabled(const FeatureContext*) { return CSSIndependentTransformPropertiesEnabled(); }

  static void SetCSSLayoutAPIEnabled(bool enabled) { is_css_layout_api_enabled_ = enabled; }
  static bool CSSLayoutAPIEnabled() {
    return is_css_layout_api_enabled_;
  }
  static bool CSSLayoutAPIEnabled(const FeatureContext*) { return CSSLayoutAPIEnabled(); }

  static void SetCSSLogicalEnabled(bool enabled) { is_css_logical_enabled_ = enabled; }
  static bool CSSLogicalEnabled() {
    return is_css_logical_enabled_;
  }
  static bool CSSLogicalEnabled(const FeatureContext*) { return CSSLogicalEnabled(); }

  static void SetCSSLogicalOverflowEnabled(bool enabled) { is_css_logical_overflow_enabled_ = enabled; }
  static bool CSSLogicalOverflowEnabled() {
    return is_css_logical_overflow_enabled_;
  }
  static bool CSSLogicalOverflowEnabled(const FeatureContext*) { return CSSLogicalOverflowEnabled(); }

  static void SetCSSMarkerNestedPseudoElementEnabled(bool enabled) { is_css_marker_nested_pseudo_element_enabled_ = enabled; }
  static bool CSSMarkerNestedPseudoElementEnabled() {
    return is_css_marker_nested_pseudo_element_enabled_;
  }
  static bool CSSMarkerNestedPseudoElementEnabled(const FeatureContext*) { return CSSMarkerNestedPseudoElementEnabled(); }

  static void SetCSSMarkerPseudoElementEnabled(bool enabled) { is_css_marker_pseudo_element_enabled_ = enabled; }
  static bool CSSMarkerPseudoElementEnabled() {
    if (CSSMarkerNestedPseudoElementEnabled())
      return true;
    return is_css_marker_pseudo_element_enabled_;
  }
  static bool CSSMarkerPseudoElementEnabled(const FeatureContext*) { return CSSMarkerPseudoElementEnabled(); }

  static void SetCSSMatchedPropertiesCacheDependenciesEnabled(bool enabled) { is_css_matched_properties_cache_dependencies_enabled_ = enabled; }
  static bool CSSMatchedPropertiesCacheDependenciesEnabled() {
    if (!CSSCascadeEnabled())
      return false;
    return is_css_matched_properties_cache_dependencies_enabled_;
  }
  static bool CSSMatchedPropertiesCacheDependenciesEnabled(const FeatureContext*) { return CSSMatchedPropertiesCacheDependenciesEnabled(); }

  static void SetCSSMathStyleEnabled(bool enabled) { is_css_math_style_enabled_ = enabled; }
  static bool CSSMathStyleEnabled() {
    if (MathMLCoreEnabled())
      return true;
    return is_css_math_style_enabled_;
  }
  static bool CSSMathStyleEnabled(const FeatureContext*) { return CSSMathStyleEnabled(); }

  static void SetCSSMathSuperscriptShiftStyleEnabled(bool enabled) { is_css_math_superscript_shift_style_enabled_ = enabled; }
  static bool CSSMathSuperscriptShiftStyleEnabled() {
    if (MathMLCoreEnabled())
      return true;
    return is_css_math_superscript_shift_style_enabled_;
  }
  static bool CSSMathSuperscriptShiftStyleEnabled(const FeatureContext*) { return CSSMathSuperscriptShiftStyleEnabled(); }

  static void SetCSSMathVariantEnabled(bool enabled) { is_css_math_variant_enabled_ = enabled; }
  static bool CSSMathVariantEnabled() {
    if (MathMLCoreEnabled())
      return true;
    return is_css_math_variant_enabled_;
  }
  static bool CSSMathVariantEnabled(const FeatureContext*) { return CSSMathVariantEnabled(); }

  static void SetCSSModulesEnabled(bool enabled) { is_css_modules_enabled_ = enabled; }
  static bool CSSModulesEnabled() {
    return is_css_modules_enabled_;
  }
  static bool CSSModulesEnabled(const FeatureContext*) { return CSSModulesEnabled(); }

  static void SetCSSOffsetPathRayEnabled(bool enabled) { is_css_offset_path_ray_enabled_ = enabled; }
  static bool CSSOffsetPathRayEnabled() {
    return is_css_offset_path_ray_enabled_;
  }
  static bool CSSOffsetPathRayEnabled(const FeatureContext*) { return CSSOffsetPathRayEnabled(); }

  static void SetCSSOffsetPathRayContainEnabled(bool enabled) { is_css_offset_path_ray_contain_enabled_ = enabled; }
  static bool CSSOffsetPathRayContainEnabled() {
    return is_css_offset_path_ray_contain_enabled_;
  }
  static bool CSSOffsetPathRayContainEnabled(const FeatureContext*) { return CSSOffsetPathRayContainEnabled(); }

  static void SetCSSOffsetPositionAnchorEnabled(bool enabled) { is_css_offset_position_anchor_enabled_ = enabled; }
  static bool CSSOffsetPositionAnchorEnabled() {
    return is_css_offset_position_anchor_enabled_;
  }
  static bool CSSOffsetPositionAnchorEnabled(const FeatureContext*) { return CSSOffsetPositionAnchorEnabled(); }

  static void SetCSSOMViewScrollCoordinatesEnabled(bool enabled) { is_cssom_view_scroll_coordinates_enabled_ = enabled; }
  static bool CSSOMViewScrollCoordinatesEnabled() {
    return is_cssom_view_scroll_coordinates_enabled_;
  }
  static bool CSSOMViewScrollCoordinatesEnabled(const FeatureContext*) { return CSSOMViewScrollCoordinatesEnabled(); }

  static void SetCSSPaintAPIArgumentsEnabled(bool enabled) { is_css_paint_api_arguments_enabled_ = enabled; }
  static bool CSSPaintAPIArgumentsEnabled() {
    return is_css_paint_api_arguments_enabled_;
  }
  static bool CSSPaintAPIArgumentsEnabled(const FeatureContext*) { return CSSPaintAPIArgumentsEnabled(); }

  static void SetCSSPictureInPictureEnabled(bool enabled) { is_css_picture_in_picture_enabled_ = enabled; }
  static bool CSSPictureInPictureEnabled() {
    if (!PictureInPictureAPIEnabled())
      return false;
    return is_css_picture_in_picture_enabled_;
  }
  static bool CSSPictureInPictureEnabled(const FeatureContext*) { return CSSPictureInPictureEnabled(); }

  static void SetCSSPseudoIsEnabled(bool enabled) { is_css_pseudo_is_enabled_ = enabled; }
  static bool CSSPseudoIsEnabled() {
    return is_css_pseudo_is_enabled_;
  }
  static bool CSSPseudoIsEnabled(const FeatureContext*) { return CSSPseudoIsEnabled(); }

  static void SetCSSPseudoWhereEnabled(bool enabled) { is_css_pseudo_where_enabled_ = enabled; }
  static bool CSSPseudoWhereEnabled() {
    return is_css_pseudo_where_enabled_;
  }
  static bool CSSPseudoWhereEnabled(const FeatureContext*) { return CSSPseudoWhereEnabled(); }

  static void SetCSSReducedFontLoadingInvalidationsEnabled(bool enabled) { is_css_reduced_font_loading_invalidations_enabled_ = enabled; }
  static bool CSSReducedFontLoadingInvalidationsEnabled() {
    if (CSSReducedFontLoadingLayoutInvalidationsEnabled())
      return true;
    return is_css_reduced_font_loading_invalidations_enabled_;
  }
  static bool CSSReducedFontLoadingInvalidationsEnabled(const FeatureContext*) { return CSSReducedFontLoadingInvalidationsEnabled(); }

  static void SetCSSReducedFontLoadingLayoutInvalidationsEnabled(bool enabled) { is_css_reduced_font_loading_layout_invalidations_enabled_ = enabled; }
  static bool CSSReducedFontLoadingLayoutInvalidationsEnabled() {
    return is_css_reduced_font_loading_layout_invalidations_enabled_;
  }
  static bool CSSReducedFontLoadingLayoutInvalidationsEnabled(const FeatureContext*) { return CSSReducedFontLoadingLayoutInvalidationsEnabled(); }

  static void SetCSSRevertEnabled(bool enabled) { is_css_revert_enabled_ = enabled; }
  static bool CSSRevertEnabled() {
    if (!CSSCascadeEnabled())
      return false;
    return is_css_revert_enabled_;
  }
  static bool CSSRevertEnabled(const FeatureContext*) { return CSSRevertEnabled(); }

  static void SetCSSScrollTimelineEnabled(bool enabled) { is_css_scroll_timeline_enabled_ = enabled; }
  static bool CSSScrollTimelineEnabled() {
    return is_css_scroll_timeline_enabled_;
  }
  static bool CSSScrollTimelineEnabled(const FeatureContext*) { return CSSScrollTimelineEnabled(); }

  static void SetCSSSnapSizeEnabled(bool enabled) { is_css_snap_size_enabled_ = enabled; }
  static bool CSSSnapSizeEnabled() {
    return is_css_snap_size_enabled_;
  }
  static bool CSSSnapSizeEnabled(const FeatureContext*) { return CSSSnapSizeEnabled(); }

  static void SetCSSSupportsSelectorEnabled(bool enabled) { is_css_supports_selector_enabled_ = enabled; }
  static bool CSSSupportsSelectorEnabled() {
    return is_css_supports_selector_enabled_;
  }
  static bool CSSSupportsSelectorEnabled(const FeatureContext*) { return CSSSupportsSelectorEnabled(); }

  static void SetCSSVariables2AtPropertyEnabled(bool enabled) { is_css_variables_2_at_property_enabled_ = enabled; }
  static bool CSSVariables2AtPropertyEnabled() {
    return is_css_variables_2_at_property_enabled_;
  }
  static bool CSSVariables2AtPropertyEnabled(const FeatureContext*) { return CSSVariables2AtPropertyEnabled(); }

  static void SetCSSVariables2ImageValuesEnabled(bool enabled) { is_css_variables_2_image_values_enabled_ = enabled; }
  static bool CSSVariables2ImageValuesEnabled() {
    return is_css_variables_2_image_values_enabled_;
  }
  static bool CSSVariables2ImageValuesEnabled(const FeatureContext*) { return CSSVariables2ImageValuesEnabled(); }

  static void SetCSSVariables2TransformValuesEnabled(bool enabled) { is_css_variables_2_transform_values_enabled_ = enabled; }
  static bool CSSVariables2TransformValuesEnabled() {
    return is_css_variables_2_transform_values_enabled_;
  }
  static bool CSSVariables2TransformValuesEnabled(const FeatureContext*) { return CSSVariables2TransformValuesEnabled(); }

  static void SetCustomElementDefaultStyleEnabled(bool enabled) { is_custom_element_default_style_enabled_ = enabled; }
  static bool CustomElementDefaultStyleEnabled() {
    return is_custom_element_default_style_enabled_;
  }
  static bool CustomElementDefaultStyleEnabled(const FeatureContext*) { return CustomElementDefaultStyleEnabled(); }

  static void SetCustomStatePseudoClassEnabled(bool enabled) { is_custom_state_pseudo_class_enabled_ = enabled; }
  static bool CustomStatePseudoClassEnabled() {
    return is_custom_state_pseudo_class_enabled_;
  }
  static bool CustomStatePseudoClassEnabled(const FeatureContext*) { return CustomStatePseudoClassEnabled(); }

  static void SetDatabaseEnabled(bool enabled) { is_database_enabled_ = enabled; }
  static bool DatabaseEnabled() {
    return is_database_enabled_;
  }
  static bool DatabaseEnabled(const FeatureContext*) { return DatabaseEnabled(); }

  static void SetDeclarativeShadowDOMEnabled(bool enabled) { is_declarative_shadow_dom_enabled_ = enabled; }
  static bool DeclarativeShadowDOMEnabled() {
    return is_declarative_shadow_dom_enabled_;
  }
  static bool DeclarativeShadowDOMEnabled(const FeatureContext*) { return DeclarativeShadowDOMEnabled(); }

  static void SetDecodeJpeg420ImagesToYUVEnabled(bool enabled) { is_decode_jpeg_420_images_to_yuv_enabled_ = enabled; }
  static bool DecodeJpeg420ImagesToYUVEnabled() {
    return is_decode_jpeg_420_images_to_yuv_enabled_;
  }
  static bool DecodeJpeg420ImagesToYUVEnabled(const FeatureContext*) { return DecodeJpeg420ImagesToYUVEnabled(); }

  static void SetDecodeLossyWebPImagesToYUVEnabled(bool enabled) { is_decode_lossy_web_p_images_to_yuv_enabled_ = enabled; }
  static bool DecodeLossyWebPImagesToYUVEnabled() {
    return is_decode_lossy_web_p_images_to_yuv_enabled_;
  }
  static bool DecodeLossyWebPImagesToYUVEnabled(const FeatureContext*) { return DecodeLossyWebPImagesToYUVEnabled(); }

  static void SetDelayAsyncScriptExecutionUntilFinishedParsingEnabled(bool enabled) { is_delay_async_script_execution_until_finished_parsing_enabled_ = enabled; }
  static bool DelayAsyncScriptExecutionUntilFinishedParsingEnabled() {
    return is_delay_async_script_execution_until_finished_parsing_enabled_;
  }
  static bool DelayAsyncScriptExecutionUntilFinishedParsingEnabled(const FeatureContext*) { return DelayAsyncScriptExecutionUntilFinishedParsingEnabled(); }

  static void SetDelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabled(bool enabled) { is_delay_async_script_execution_until_first_paint_or_finished_parsing_enabled_ = enabled; }
  static bool DelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabled() {
    return is_delay_async_script_execution_until_first_paint_or_finished_parsing_enabled_;
  }
  static bool DelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabled(const FeatureContext*) { return DelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabled(); }

  static void SetDelegatedInkTrailsEnabled(bool enabled) { is_delegated_ink_trails_enabled_ = enabled; }
  static bool DelegatedInkTrailsEnabled() {
    return is_delegated_ink_trails_enabled_;
  }
  static bool DelegatedInkTrailsEnabled(const FeatureContext*) { return DelegatedInkTrailsEnabled(); }

  static void SetDesktopCaptureDisableLocalEchoControlEnabled(bool enabled) { is_desktop_capture_disable_local_echo_control_enabled_ = enabled; }
  static bool DesktopCaptureDisableLocalEchoControlEnabled() {
    return is_desktop_capture_disable_local_echo_control_enabled_;
  }
  static bool DesktopCaptureDisableLocalEchoControlEnabled(const FeatureContext*) { return DesktopCaptureDisableLocalEchoControlEnabled(); }

  static void SetDigitalGoodsEnabled(bool enabled) { is_digital_goods_enabled_ = enabled; }
  static bool DigitalGoodsEnabled() {
    return is_digital_goods_enabled_;
  }
  static bool DigitalGoodsEnabled(const FeatureContext*) { return DigitalGoodsEnabled(); }

  static void SetDisableLayerSquashingEnabled(bool enabled) { is_disable_layer_squashing_enabled_ = enabled; }
  static bool DisableLayerSquashingEnabled() {
    return is_disable_layer_squashing_enabled_;
  }
  static bool DisableLayerSquashingEnabled(const FeatureContext*) { return DisableLayerSquashingEnabled(); }

  static void SetDisallowDocumentAccessEnabled(bool enabled) { is_disallow_document_access_enabled_ = enabled; }
  static bool DisallowDocumentAccessEnabled() {
    return is_disallow_document_access_enabled_;
  }
  static bool DisallowDocumentAccessEnabled(const FeatureContext*) { return DisallowDocumentAccessEnabled(); }

  static void SetDisplayCutoutAPIEnabled(bool enabled) { is_display_cutout_api_enabled_ = enabled; }
  static bool DisplayCutoutAPIEnabled() {
    return is_display_cutout_api_enabled_;
  }
  static bool DisplayCutoutAPIEnabled(const FeatureContext*) { return DisplayCutoutAPIEnabled(); }

  static void SetDocumentCookieEnabled(bool enabled) { is_document_cookie_enabled_ = enabled; }
  static bool DocumentCookieEnabled() {
    return is_document_cookie_enabled_;
  }
  static bool DocumentCookieEnabled(const FeatureContext*) { return DocumentCookieEnabled(); }

  static void SetDocumentDomainEnabled(bool enabled) { is_document_domain_enabled_ = enabled; }
  static bool DocumentDomainEnabled() {
    return is_document_domain_enabled_;
  }
  static bool DocumentDomainEnabled(const FeatureContext*) { return DocumentDomainEnabled(); }

  static void SetDocumentWriteEnabled(bool enabled) { is_document_write_enabled_ = enabled; }
  static bool DocumentWriteEnabled() {
    return is_document_write_enabled_;
  }
  static bool DocumentWriteEnabled(const FeatureContext*) { return DocumentWriteEnabled(); }

  static void SetEditContextEnabled(bool enabled) { is_edit_context_enabled_ = enabled; }
  static bool EditContextEnabled() {
    return is_edit_context_enabled_;
  }
  static bool EditContextEnabled(const FeatureContext*) { return EditContextEnabled(); }

  static void SetEditingNGEnabled(bool enabled) { is_editing_ng_enabled_ = enabled; }
  static bool EditingNGEnabled() {
    return is_editing_ng_enabled_;
  }
  static bool EditingNGEnabled(const FeatureContext*) { return EditingNGEnabled(); }

  static void SetEncryptedMediaEncryptionSchemeQueryEnabled(bool enabled) { is_encrypted_media_encryption_scheme_query_enabled_ = enabled; }
  static bool EncryptedMediaEncryptionSchemeQueryEnabled() {
    return is_encrypted_media_encryption_scheme_query_enabled_;
  }
  static bool EncryptedMediaEncryptionSchemeQueryEnabled(const FeatureContext*) { return EncryptedMediaEncryptionSchemeQueryEnabled(); }

  static void SetEncryptedMediaHdcpPolicyCheckEnabled(bool enabled) { is_encrypted_media_hdcp_policy_check_enabled_ = enabled; }
  static bool EncryptedMediaHdcpPolicyCheckEnabled() {
    return is_encrypted_media_hdcp_policy_check_enabled_;
  }
  static bool EncryptedMediaHdcpPolicyCheckEnabled(const FeatureContext*) { return EncryptedMediaHdcpPolicyCheckEnabled(); }

  static void SetEncryptedMediaPersistentUsageRecordSessionEnabled(bool enabled) { is_encrypted_media_persistent_usage_record_session_enabled_ = enabled; }
  static bool EncryptedMediaPersistentUsageRecordSessionEnabled() {
    return is_encrypted_media_persistent_usage_record_session_enabled_;
  }
  static bool EncryptedMediaPersistentUsageRecordSessionEnabled(const FeatureContext*) { return EncryptedMediaPersistentUsageRecordSessionEnabled(); }

  static void SetEnterKeyHintAttributeEnabled(bool enabled) { is_enter_key_hint_attribute_enabled_ = enabled; }
  static bool EnterKeyHintAttributeEnabled() {
    return is_enter_key_hint_attribute_enabled_;
  }
  static bool EnterKeyHintAttributeEnabled(const FeatureContext*) { return EnterKeyHintAttributeEnabled(); }

  static void SetEventTimingEnabled(bool enabled) { is_event_timing_enabled_ = enabled; }
  static bool EventTimingEnabled() {
    return is_event_timing_enabled_;
  }
  static bool EventTimingEnabled(const FeatureContext*) { return EventTimingEnabled(); }

  static void SetExecCommandInJavaScriptEnabled(bool enabled) { is_exec_command_in_java_script_enabled_ = enabled; }
  static bool ExecCommandInJavaScriptEnabled() {
    return is_exec_command_in_java_script_enabled_;
  }
  static bool ExecCommandInJavaScriptEnabled(const FeatureContext*) { return ExecCommandInJavaScriptEnabled(); }

  static void SetExpensiveBackgroundTimerThrottlingEnabled(bool enabled) { is_expensive_background_timer_throttling_enabled_ = enabled; }
  static bool ExpensiveBackgroundTimerThrottlingEnabled() {
    return is_expensive_background_timer_throttling_enabled_;
  }
  static bool ExpensiveBackgroundTimerThrottlingEnabled(const FeatureContext*) { return ExpensiveBackgroundTimerThrottlingEnabled(); }

  static void SetExperimentalContentSecurityPolicyFeaturesEnabled(bool enabled) { is_experimental_content_security_policy_features_enabled_ = enabled; }
  static bool ExperimentalContentSecurityPolicyFeaturesEnabled() {
    return is_experimental_content_security_policy_features_enabled_;
  }
  static bool ExperimentalContentSecurityPolicyFeaturesEnabled(const FeatureContext*) { return ExperimentalContentSecurityPolicyFeaturesEnabled(); }

  static void SetExperimentalProductivityFeaturesEnabled(bool enabled) { is_experimental_productivity_features_enabled_ = enabled; }
  static bool ExperimentalProductivityFeaturesEnabled() {
    return is_experimental_productivity_features_enabled_;
  }
  static bool ExperimentalProductivityFeaturesEnabled(const FeatureContext*) { return ExperimentalProductivityFeaturesEnabled(); }

  static void SetExtendedTextMetricsEnabled(bool enabled) { is_extended_text_metrics_enabled_ = enabled; }
  static bool ExtendedTextMetricsEnabled() {
    return is_extended_text_metrics_enabled_;
  }
  static bool ExtendedTextMetricsEnabled(const FeatureContext*) { return ExtendedTextMetricsEnabled(); }

  static void SetExtraWebGLVideoTextureMetadataEnabled(bool enabled) { is_extra_webgl_video_texture_metadata_enabled_ = enabled; }
  static bool ExtraWebGLVideoTextureMetadataEnabled() {
    return is_extra_webgl_video_texture_metadata_enabled_;
  }
  static bool ExtraWebGLVideoTextureMetadataEnabled(const FeatureContext*) { return ExtraWebGLVideoTextureMetadataEnabled(); }

  static void SetFaceDetectorEnabled(bool enabled) { is_face_detector_enabled_ = enabled; }
  static bool FaceDetectorEnabled() {
    return is_face_detector_enabled_;
  }
  static bool FaceDetectorEnabled(const FeatureContext*) { return FaceDetectorEnabled(); }

  static void SetFeaturePolicyForClientHintsEnabled(bool enabled) { is_feature_policy_for_client_hints_enabled_ = enabled; }
  static bool FeaturePolicyForClientHintsEnabled() {
    return is_feature_policy_for_client_hints_enabled_;
  }
  static bool FeaturePolicyForClientHintsEnabled(const FeatureContext*) { return FeaturePolicyForClientHintsEnabled(); }

  static void SetFeaturePolicyForSandboxEnabled(bool enabled) { is_feature_policy_for_sandbox_enabled_ = enabled; }
  static bool FeaturePolicyForSandboxEnabled() {
    return is_feature_policy_for_sandbox_enabled_;
  }
  static bool FeaturePolicyForSandboxEnabled(const FeatureContext*) { return FeaturePolicyForSandboxEnabled(); }

  static void SetFeaturePolicyVibrateFeatureEnabled(bool enabled) { is_feature_policy_vibrate_feature_enabled_ = enabled; }
  static bool FeaturePolicyVibrateFeatureEnabled() {
    return is_feature_policy_vibrate_feature_enabled_;
  }
  static bool FeaturePolicyVibrateFeatureEnabled(const FeatureContext*) { return FeaturePolicyVibrateFeatureEnabled(); }

  static void SetFetchUploadStreamingEnabled(bool enabled) { is_fetch_upload_streaming_enabled_ = enabled; }
  static bool FetchUploadStreamingEnabled() {
    return is_fetch_upload_streaming_enabled_;
  }
  static bool FetchUploadStreamingEnabled(const FeatureContext*) { return FetchUploadStreamingEnabled(); }

  static void SetFileSystemEnabled(bool enabled) { is_file_system_enabled_ = enabled; }
  static bool FileSystemEnabled() {
    return is_file_system_enabled_;
  }
  static bool FileSystemEnabled(const FeatureContext*) { return FileSystemEnabled(); }

  static void SetFlexGapsEnabled(bool enabled) { is_flex_gaps_enabled_ = enabled; }
  static bool FlexGapsEnabled() {
    return is_flex_gaps_enabled_;
  }
  static bool FlexGapsEnabled(const FeatureContext*) { return FlexGapsEnabled(); }

  static void SetFocuslessSpatialNavigationEnabled(bool enabled) { is_focusless_spatial_navigation_enabled_ = enabled; }
  static bool FocuslessSpatialNavigationEnabled() {
    return is_focusless_spatial_navigation_enabled_;
  }
  static bool FocuslessSpatialNavigationEnabled(const FeatureContext*) { return FocuslessSpatialNavigationEnabled(); }

  static void SetFontAccessEnabled(bool enabled) { is_font_access_enabled_ = enabled; }
  static bool FontAccessEnabled() {
    return is_font_access_enabled_;
  }
  static bool FontAccessEnabled(const FeatureContext*) { return FontAccessEnabled(); }

  static void SetFontSrcLocalMatchingEnabled(bool enabled) { is_font_src_local_matching_enabled_ = enabled; }
  static bool FontSrcLocalMatchingEnabled() {
    return is_font_src_local_matching_enabled_;
  }
  static bool FontSrcLocalMatchingEnabled(const FeatureContext*) { return FontSrcLocalMatchingEnabled(); }

  static void SetForcedColorsEnabled(bool enabled) { is_forced_colors_enabled_ = enabled; }
  static bool ForcedColorsEnabled() {
    return is_forced_colors_enabled_;
  }
  static bool ForcedColorsEnabled(const FeatureContext*) { return ForcedColorsEnabled(); }

  static void SetForceDeferScriptInterventionEnabled(bool enabled) { is_force_defer_script_intervention_enabled_ = enabled; }
  static bool ForceDeferScriptInterventionEnabled() {
    return is_force_defer_script_intervention_enabled_;
  }
  static bool ForceDeferScriptInterventionEnabled(const FeatureContext*) { return ForceDeferScriptInterventionEnabled(); }

  static void SetForceEagerMeasureMemoryEnabled(bool enabled) { is_force_eager_measure_memory_enabled_ = enabled; }
  static bool ForceEagerMeasureMemoryEnabled() {
    return is_force_eager_measure_memory_enabled_;
  }
  static bool ForceEagerMeasureMemoryEnabled(const FeatureContext*) { return ForceEagerMeasureMemoryEnabled(); }

  static void SetForceOverlayFullscreenVideoEnabled(bool enabled) { is_force_overlay_fullscreen_video_enabled_ = enabled; }
  static bool ForceOverlayFullscreenVideoEnabled() {
    return is_force_overlay_fullscreen_video_enabled_;
  }
  static bool ForceOverlayFullscreenVideoEnabled(const FeatureContext*) { return ForceOverlayFullscreenVideoEnabled(); }

  static void SetForceSynchronousHTMLParsingEnabled(bool enabled) { is_force_synchronous_html_parsing_enabled_ = enabled; }
  static bool ForceSynchronousHTMLParsingEnabled() {
    return is_force_synchronous_html_parsing_enabled_;
  }
  static bool ForceSynchronousHTMLParsingEnabled(const FeatureContext*) { return ForceSynchronousHTMLParsingEnabled(); }

  static void SetForceTallerSelectPopupEnabled(bool enabled) { is_force_taller_select_popup_enabled_ = enabled; }
  static bool ForceTallerSelectPopupEnabled() {
    return is_force_taller_select_popup_enabled_;
  }
  static bool ForceTallerSelectPopupEnabled(const FeatureContext*) { return ForceTallerSelectPopupEnabled(); }

  static void SetFractionalScrollOffsetsEnabled(bool enabled) { is_fractional_scroll_offsets_enabled_ = enabled; }
  static bool FractionalScrollOffsetsEnabled() {
    return is_fractional_scroll_offsets_enabled_;
  }
  static bool FractionalScrollOffsetsEnabled(const FeatureContext*) { return FractionalScrollOffsetsEnabled(); }

  static void SetFreezeFramesOnVisibilityEnabled(bool enabled) { is_freeze_frames_on_visibility_enabled_ = enabled; }
  static bool FreezeFramesOnVisibilityEnabled() {
    return is_freeze_frames_on_visibility_enabled_;
  }
  static bool FreezeFramesOnVisibilityEnabled(const FeatureContext*) { return FreezeFramesOnVisibilityEnabled(); }

  static void SetGamepadButtonAxisEventsEnabled(bool enabled) { is_gamepad_button_axis_events_enabled_ = enabled; }
  static bool GamepadButtonAxisEventsEnabled() {
    return is_gamepad_button_axis_events_enabled_;
  }
  static bool GamepadButtonAxisEventsEnabled(const FeatureContext*) { return GamepadButtonAxisEventsEnabled(); }

  static void SetGetDisplayMediaEnabled(bool enabled) { is_get_display_media_enabled_ = enabled; }
  static bool GetDisplayMediaEnabled() {
    return is_get_display_media_enabled_;
  }
  static bool GetDisplayMediaEnabled(const FeatureContext*) { return GetDisplayMediaEnabled(); }

  static void SetGroupEffectEnabled(bool enabled) { is_group_effect_enabled_ = enabled; }
  static bool GroupEffectEnabled() {
    return is_group_effect_enabled_;
  }
  static bool GroupEffectEnabled(const FeatureContext*) { return GroupEffectEnabled(); }

  static void SetIDBObserverEnabled(bool enabled) { is_idb_observer_enabled_ = enabled; }
  static bool IDBObserverEnabled() {
    return is_idb_observer_enabled_;
  }
  static bool IDBObserverEnabled(const FeatureContext*) { return IDBObserverEnabled(); }

  static void SetIDBRelaxedDurabilityEnabled(bool enabled) { is_idb_relaxed_durability_enabled_ = enabled; }
  static bool IDBRelaxedDurabilityEnabled() {
    return is_idb_relaxed_durability_enabled_;
  }
  static bool IDBRelaxedDurabilityEnabled(const FeatureContext*) { return IDBRelaxedDurabilityEnabled(); }

  static void SetIgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabled(bool enabled) { is_ignore_cross_origin_window_when_named_access_on_window_enabled_ = enabled; }
  static bool IgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabled() {
    return is_ignore_cross_origin_window_when_named_access_on_window_enabled_;
  }
  static bool IgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabled(const FeatureContext*) { return IgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabled(); }

  static void SetImageOrientationEnabled(bool enabled) { is_image_orientation_enabled_ = enabled; }
  static bool ImageOrientationEnabled() {
    return is_image_orientation_enabled_;
  }
  static bool ImageOrientationEnabled(const FeatureContext*) { return ImageOrientationEnabled(); }

  static void SetImplicitRootScrollerEnabled(bool enabled) { is_implicit_root_scroller_enabled_ = enabled; }
  static bool ImplicitRootScrollerEnabled() {
    return is_implicit_root_scroller_enabled_;
  }
  static bool ImplicitRootScrollerEnabled(const FeatureContext*) { return ImplicitRootScrollerEnabled(); }

  static void SetImportMapsEnabled(bool enabled) { is_import_maps_enabled_ = enabled; }
  static bool ImportMapsEnabled() {
    if (ExperimentalProductivityFeaturesEnabled())
      return true;
    return is_import_maps_enabled_;
  }
  static bool ImportMapsEnabled(const FeatureContext*) { return ImportMapsEnabled(); }

  static void SetInertAttributeEnabled(bool enabled) { is_inert_attribute_enabled_ = enabled; }
  static bool InertAttributeEnabled() {
    return is_inert_attribute_enabled_;
  }
  static bool InertAttributeEnabled(const FeatureContext*) { return InertAttributeEnabled(); }

  static void SetInputElementRawValueEnabled(bool enabled) { is_input_element_raw_value_enabled_ = enabled; }
  static bool InputElementRawValueEnabled() {
    return is_input_element_raw_value_enabled_;
  }
  static bool InputElementRawValueEnabled(const FeatureContext*) { return InputElementRawValueEnabled(); }

  static void SetInputMultipleFieldsUIEnabled(bool enabled) { is_input_multiple_fields_ui_enabled_ = enabled; }
  static bool InputMultipleFieldsUIEnabled() {
    return is_input_multiple_fields_ui_enabled_;
  }
  static bool InputMultipleFieldsUIEnabled(const FeatureContext*) { return InputMultipleFieldsUIEnabled(); }

  static void SetInstalledAppEnabled(bool enabled) { is_installed_app_enabled_ = enabled; }
  static bool InstalledAppEnabled() {
    return is_installed_app_enabled_;
  }
  static bool InstalledAppEnabled(const FeatureContext*) { return InstalledAppEnabled(); }

  static void SetIntersectionObserverDocumentScrollingElementRootEnabled(bool enabled) { is_intersection_observer_document_scrolling_element_root_enabled_ = enabled; }
  static bool IntersectionObserverDocumentScrollingElementRootEnabled() {
    return is_intersection_observer_document_scrolling_element_root_enabled_;
  }
  static bool IntersectionObserverDocumentScrollingElementRootEnabled(const FeatureContext*) { return IntersectionObserverDocumentScrollingElementRootEnabled(); }

  static void SetIsolatedCodeCacheEnabled(bool enabled) { is_isolated_code_cache_enabled_ = enabled; }
  static bool IsolatedCodeCacheEnabled() {
    return is_isolated_code_cache_enabled_;
  }
  static bool IsolatedCodeCacheEnabled(const FeatureContext*) { return IsolatedCodeCacheEnabled(); }

  static void SetIsolatedWorldCSPEnabled(bool enabled) { is_isolated_world_csp_enabled_ = enabled; }
  static bool IsolatedWorldCSPEnabled() {
    return is_isolated_world_csp_enabled_;
  }
  static bool IsolatedWorldCSPEnabled(const FeatureContext*) { return IsolatedWorldCSPEnabled(); }

  static void SetKeyboardFocusableScrollersEnabled(bool enabled) { is_keyboard_focusable_scrollers_enabled_ = enabled; }
  static bool KeyboardFocusableScrollersEnabled() {
    return is_keyboard_focusable_scrollers_enabled_;
  }
  static bool KeyboardFocusableScrollersEnabled(const FeatureContext*) { return KeyboardFocusableScrollersEnabled(); }

  static void SetLangAttributeAwareFormControlUIEnabled(bool enabled) { is_lang_attribute_aware_form_control_ui_enabled_ = enabled; }
  static bool LangAttributeAwareFormControlUIEnabled() {
    return is_lang_attribute_aware_form_control_ui_enabled_;
  }
  static bool LangAttributeAwareFormControlUIEnabled(const FeatureContext*) { return LangAttributeAwareFormControlUIEnabled(); }

  static void SetLangClientHintHeaderEnabled(bool enabled) { is_lang_client_hint_header_enabled_ = enabled; }
  static bool LangClientHintHeaderEnabled() {
    return is_lang_client_hint_header_enabled_;
  }
  static bool LangClientHintHeaderEnabled(const FeatureContext*) { return LangClientHintHeaderEnabled(); }

  static void SetLayoutNGEnabled(bool enabled) { is_layout_ng_enabled_ = enabled; }
  static bool LayoutNGEnabled() {
    if (LayoutNGBlockFragmentationEnabled())
      return true;
    if (LayoutNGFieldsetEnabled())
      return true;
    if (LayoutNGFragmentItemEnabled())
      return true;
    if (LayoutNGGridEnabled())
      return true;
    if (EditingNGEnabled())
      return true;
    if (BidiCaretAffinityEnabled())
      return true;
    if (LayoutNGTableEnabled())
      return true;
    if (LayoutNGFragmentTraversalEnabled())
      return true;
    return is_layout_ng_enabled_;
  }
  static bool LayoutNGEnabled(const FeatureContext*) { return LayoutNGEnabled(); }

  static void SetLayoutNGBlockFragmentationEnabled(bool enabled) { is_layout_ng_block_fragmentation_enabled_ = enabled; }
  static bool LayoutNGBlockFragmentationEnabled() {
    return is_layout_ng_block_fragmentation_enabled_;
  }
  static bool LayoutNGBlockFragmentationEnabled(const FeatureContext*) { return LayoutNGBlockFragmentationEnabled(); }

  static void SetLayoutNGFieldsetEnabled(bool enabled) { is_layout_ng_fieldset_enabled_ = enabled; }
  static bool LayoutNGFieldsetEnabled() {
    return is_layout_ng_fieldset_enabled_;
  }
  static bool LayoutNGFieldsetEnabled(const FeatureContext*) { return LayoutNGFieldsetEnabled(); }

  static void SetLayoutNGFlexBoxEnabled(bool enabled) { is_layout_ng_flex_box_enabled_ = enabled; }
  static bool LayoutNGFlexBoxEnabled() {
    return is_layout_ng_flex_box_enabled_;
  }
  static bool LayoutNGFlexBoxEnabled(const FeatureContext*) { return LayoutNGFlexBoxEnabled(); }

  static void SetLayoutNGForControlsEnabled(bool enabled) { is_layout_ng_for_controls_enabled_ = enabled; }
  static bool LayoutNGForControlsEnabled() {
    if (!LayoutNGEnabled())
      return false;
    return is_layout_ng_for_controls_enabled_;
  }
  static bool LayoutNGForControlsEnabled(const FeatureContext*) { return LayoutNGForControlsEnabled(); }

  static void SetLayoutNGFragmentItemEnabled(bool enabled) { is_layout_ng_fragment_item_enabled_ = enabled; }
  static bool LayoutNGFragmentItemEnabled() {
    if (LayoutNGBlockFragmentationEnabled())
      return true;
    if (LayoutNGFragmentTraversalEnabled())
      return true;
    return is_layout_ng_fragment_item_enabled_;
  }
  static bool LayoutNGFragmentItemEnabled(const FeatureContext*) { return LayoutNGFragmentItemEnabled(); }

  static void SetLayoutNGFragmentTraversalEnabled(bool enabled) { is_layout_ng_fragment_traversal_enabled_ = enabled; }
  static bool LayoutNGFragmentTraversalEnabled() {
    if (LayoutNGBlockFragmentationEnabled())
      return true;
    return is_layout_ng_fragment_traversal_enabled_;
  }
  static bool LayoutNGFragmentTraversalEnabled(const FeatureContext*) { return LayoutNGFragmentTraversalEnabled(); }

  static void SetLayoutNGGridEnabled(bool enabled) { is_layout_ng_grid_enabled_ = enabled; }
  static bool LayoutNGGridEnabled() {
    return is_layout_ng_grid_enabled_;
  }
  static bool LayoutNGGridEnabled(const FeatureContext*) { return LayoutNGGridEnabled(); }

  static void SetLayoutNGRubyEnabled(bool enabled) { is_layout_ng_ruby_enabled_ = enabled; }
  static bool LayoutNGRubyEnabled() {
    if (!LayoutNGEnabled())
      return false;
    return is_layout_ng_ruby_enabled_;
  }
  static bool LayoutNGRubyEnabled(const FeatureContext*) { return LayoutNGRubyEnabled(); }

  static void SetLayoutNGTableEnabled(bool enabled) { is_layout_ng_table_enabled_ = enabled; }
  static bool LayoutNGTableEnabled() {
    return is_layout_ng_table_enabled_;
  }
  static bool LayoutNGTableEnabled(const FeatureContext*) { return LayoutNGTableEnabled(); }

  static void SetLayoutShiftAttributionEnabled(bool enabled) { is_layout_shift_attribution_enabled_ = enabled; }
  static bool LayoutShiftAttributionEnabled() {
    return is_layout_shift_attribution_enabled_;
  }
  static bool LayoutShiftAttributionEnabled(const FeatureContext*) { return LayoutShiftAttributionEnabled(); }

  static void SetLazyFrameLoadingEnabled(bool enabled) { is_lazy_frame_loading_enabled_ = enabled; }
  static bool LazyFrameLoadingEnabled() {
    return is_lazy_frame_loading_enabled_;
  }
  static bool LazyFrameLoadingEnabled(const FeatureContext*) { return LazyFrameLoadingEnabled(); }

  static void SetLazyFrameVisibleLoadTimeMetricsEnabled(bool enabled) { is_lazy_frame_visible_load_time_metrics_enabled_ = enabled; }
  static bool LazyFrameVisibleLoadTimeMetricsEnabled() {
    return is_lazy_frame_visible_load_time_metrics_enabled_;
  }
  static bool LazyFrameVisibleLoadTimeMetricsEnabled(const FeatureContext*) { return LazyFrameVisibleLoadTimeMetricsEnabled(); }

  static void SetLazyImageLoadingEnabled(bool enabled) { is_lazy_image_loading_enabled_ = enabled; }
  static bool LazyImageLoadingEnabled() {
    return is_lazy_image_loading_enabled_;
  }
  static bool LazyImageLoadingEnabled(const FeatureContext*) { return LazyImageLoadingEnabled(); }

  static void SetLazyImageVisibleLoadTimeMetricsEnabled(bool enabled) { is_lazy_image_visible_load_time_metrics_enabled_ = enabled; }
  static bool LazyImageVisibleLoadTimeMetricsEnabled() {
    return is_lazy_image_visible_load_time_metrics_enabled_;
  }
  static bool LazyImageVisibleLoadTimeMetricsEnabled(const FeatureContext*) { return LazyImageVisibleLoadTimeMetricsEnabled(); }

  static void SetLazyInitializeMediaControlsEnabled(bool enabled) { is_lazy_initialize_media_controls_enabled_ = enabled; }
  static bool LazyInitializeMediaControlsEnabled() {
    return is_lazy_initialize_media_controls_enabled_;
  }
  static bool LazyInitializeMediaControlsEnabled(const FeatureContext*) { return LazyInitializeMediaControlsEnabled(); }

  static void SetLegacyWindowsDWriteFontFallbackEnabled(bool enabled) { is_legacy_windows_d_write_font_fallback_enabled_ = enabled; }
  static bool LegacyWindowsDWriteFontFallbackEnabled() {
    return is_legacy_windows_d_write_font_fallback_enabled_;
  }
  static bool LegacyWindowsDWriteFontFallbackEnabled(const FeatureContext*) { return LegacyWindowsDWriteFontFallbackEnabled(); }

  static void SetLinkDisabledNewSpecBehaviorEnabled(bool enabled) { is_link_disabled_new_spec_behavior_enabled_ = enabled; }
  static bool LinkDisabledNewSpecBehaviorEnabled() {
    return is_link_disabled_new_spec_behavior_enabled_;
  }
  static bool LinkDisabledNewSpecBehaviorEnabled(const FeatureContext*) { return LinkDisabledNewSpecBehaviorEnabled(); }

  static void SetManualSlottingEnabled(bool enabled) { is_manual_slotting_enabled_ = enabled; }
  static bool ManualSlottingEnabled() {
    return is_manual_slotting_enabled_;
  }
  static bool ManualSlottingEnabled(const FeatureContext*) { return ManualSlottingEnabled(); }

  static void SetMathMLCoreEnabled(bool enabled) { is_mathml_core_enabled_ = enabled; }
  static bool MathMLCoreEnabled() {
    if (!LayoutNGEnabled())
      return false;
    return is_mathml_core_enabled_;
  }
  static bool MathMLCoreEnabled(const FeatureContext*) { return MathMLCoreEnabled(); }

  static void SetMediaCapabilitiesDynamicRangeEnabled(bool enabled) { is_media_capabilities_dynamic_range_enabled_ = enabled; }
  static bool MediaCapabilitiesDynamicRangeEnabled() {
    return is_media_capabilities_dynamic_range_enabled_;
  }
  static bool MediaCapabilitiesDynamicRangeEnabled(const FeatureContext*) { return MediaCapabilitiesDynamicRangeEnabled(); }

  static void SetMediaCapabilitiesEncodingInfoEnabled(bool enabled) { is_media_capabilities_encoding_info_enabled_ = enabled; }
  static bool MediaCapabilitiesEncodingInfoEnabled() {
    return is_media_capabilities_encoding_info_enabled_;
  }
  static bool MediaCapabilitiesEncodingInfoEnabled(const FeatureContext*) { return MediaCapabilitiesEncodingInfoEnabled(); }

  static void SetMediaCapabilitiesEncryptedMediaEnabled(bool enabled) { is_media_capabilities_encrypted_media_enabled_ = enabled; }
  static bool MediaCapabilitiesEncryptedMediaEnabled() {
    return is_media_capabilities_encrypted_media_enabled_;
  }
  static bool MediaCapabilitiesEncryptedMediaEnabled(const FeatureContext*) { return MediaCapabilitiesEncryptedMediaEnabled(); }

  static void SetMediaCapabilitiesSpatialAudioEnabled(bool enabled) { is_media_capabilities_spatial_audio_enabled_ = enabled; }
  static bool MediaCapabilitiesSpatialAudioEnabled() {
    return is_media_capabilities_spatial_audio_enabled_;
  }
  static bool MediaCapabilitiesSpatialAudioEnabled(const FeatureContext*) { return MediaCapabilitiesSpatialAudioEnabled(); }

  static void SetMediaCaptureEnabled(bool enabled) { is_media_capture_enabled_ = enabled; }
  static bool MediaCaptureEnabled() {
    return is_media_capture_enabled_;
  }
  static bool MediaCaptureEnabled(const FeatureContext*) { return MediaCaptureEnabled(); }

  static void SetMediaCaptureDepthVideoKindEnabled(bool enabled) { is_media_capture_depth_video_kind_enabled_ = enabled; }
  static bool MediaCaptureDepthVideoKindEnabled() {
    return is_media_capture_depth_video_kind_enabled_;
  }
  static bool MediaCaptureDepthVideoKindEnabled(const FeatureContext*) { return MediaCaptureDepthVideoKindEnabled(); }

  static void SetMediaCapturePanTiltEnabled(bool enabled) { is_media_capture_pan_tilt_enabled_ = enabled; }
  static bool MediaCapturePanTiltEnabled() {
    return is_media_capture_pan_tilt_enabled_;
  }
  static bool MediaCapturePanTiltEnabled(const FeatureContext*) { return MediaCapturePanTiltEnabled(); }

  static void SetMediaCastOverlayButtonEnabled(bool enabled) { is_media_cast_overlay_button_enabled_ = enabled; }
  static bool MediaCastOverlayButtonEnabled() {
    return is_media_cast_overlay_button_enabled_;
  }
  static bool MediaCastOverlayButtonEnabled(const FeatureContext*) { return MediaCastOverlayButtonEnabled(); }

  static void SetMediaControlsExpandGestureEnabled(bool enabled) { is_media_controls_expand_gesture_enabled_ = enabled; }
  static bool MediaControlsExpandGestureEnabled() {
    return is_media_controls_expand_gesture_enabled_;
  }
  static bool MediaControlsExpandGestureEnabled(const FeatureContext*) { return MediaControlsExpandGestureEnabled(); }

  static void SetMediaControlsOverlayPlayButtonEnabled(bool enabled) { is_media_controls_overlay_play_button_enabled_ = enabled; }
  static bool MediaControlsOverlayPlayButtonEnabled() {
    return is_media_controls_overlay_play_button_enabled_;
  }
  static bool MediaControlsOverlayPlayButtonEnabled(const FeatureContext*) { return MediaControlsOverlayPlayButtonEnabled(); }

  static void SetMediaControlsUseCutOutByDefaultEnabled(bool enabled) { is_media_controls_use_cut_out_by_default_enabled_ = enabled; }
  static bool MediaControlsUseCutOutByDefaultEnabled() {
    return is_media_controls_use_cut_out_by_default_enabled_;
  }
  static bool MediaControlsUseCutOutByDefaultEnabled(const FeatureContext*) { return MediaControlsUseCutOutByDefaultEnabled(); }

  static void SetMediaDocumentDownloadButtonEnabled(bool enabled) { is_media_document_download_button_enabled_ = enabled; }
  static bool MediaDocumentDownloadButtonEnabled() {
    return is_media_document_download_button_enabled_;
  }
  static bool MediaDocumentDownloadButtonEnabled(const FeatureContext*) { return MediaDocumentDownloadButtonEnabled(); }

  static void SetMediaElementVolumeGreaterThanOneEnabled(bool enabled) { is_media_element_volume_greater_than_one_enabled_ = enabled; }
  static bool MediaElementVolumeGreaterThanOneEnabled() {
    return is_media_element_volume_greater_than_one_enabled_;
  }
  static bool MediaElementVolumeGreaterThanOneEnabled(const FeatureContext*) { return MediaElementVolumeGreaterThanOneEnabled(); }

  static void SetMediaEngagementBypassAutoplayPoliciesEnabled(bool enabled) { is_media_engagement_bypass_autoplay_policies_enabled_ = enabled; }
  static bool MediaEngagementBypassAutoplayPoliciesEnabled() {
    return is_media_engagement_bypass_autoplay_policies_enabled_;
  }
  static bool MediaEngagementBypassAutoplayPoliciesEnabled(const FeatureContext*) { return MediaEngagementBypassAutoplayPoliciesEnabled(); }

  static void SetMediaFeedsEnabled(bool enabled) { is_media_feeds_enabled_ = enabled; }
  static bool MediaFeedsEnabled() {
    return is_media_feeds_enabled_;
  }
  static bool MediaFeedsEnabled(const FeatureContext*) { return MediaFeedsEnabled(); }

  static void SetMediaLatencyHintEnabled(bool enabled) { is_media_latency_hint_enabled_ = enabled; }
  static bool MediaLatencyHintEnabled() {
    return is_media_latency_hint_enabled_;
  }
  static bool MediaLatencyHintEnabled(const FeatureContext*) { return MediaLatencyHintEnabled(); }

  static void SetMediaQueryNavigationControlsEnabled(bool enabled) { is_media_query_navigation_controls_enabled_ = enabled; }
  static bool MediaQueryNavigationControlsEnabled() {
    return is_media_query_navigation_controls_enabled_;
  }
  static bool MediaQueryNavigationControlsEnabled(const FeatureContext*) { return MediaQueryNavigationControlsEnabled(); }

  static void SetMediaSessionEnabled(bool enabled) { is_media_session_enabled_ = enabled; }
  static bool MediaSessionEnabled() {
    return is_media_session_enabled_;
  }
  static bool MediaSessionEnabled(const FeatureContext*) { return MediaSessionEnabled(); }

  static void SetMediaSessionPositionEnabled(bool enabled) { is_media_session_position_enabled_ = enabled; }
  static bool MediaSessionPositionEnabled() {
    return is_media_session_position_enabled_;
  }
  static bool MediaSessionPositionEnabled(const FeatureContext*) { return MediaSessionPositionEnabled(); }

  static void SetMediaSourceExperimentalEnabled(bool enabled) { is_media_source_experimental_enabled_ = enabled; }
  static bool MediaSourceExperimentalEnabled() {
    return is_media_source_experimental_enabled_;
  }
  static bool MediaSourceExperimentalEnabled(const FeatureContext*) { return MediaSourceExperimentalEnabled(); }

  static void SetMediaSourceInWorkersEnabled(bool enabled) { is_media_source_in_workers_enabled_ = enabled; }
  static bool MediaSourceInWorkersEnabled() {
    return is_media_source_in_workers_enabled_;
  }
  static bool MediaSourceInWorkersEnabled(const FeatureContext*) { return MediaSourceInWorkersEnabled(); }

  static void SetMediaSourceNewAbortAndDurationEnabled(bool enabled) { is_media_source_new_abort_and_duration_enabled_ = enabled; }
  static bool MediaSourceNewAbortAndDurationEnabled() {
    return is_media_source_new_abort_and_duration_enabled_;
  }
  static bool MediaSourceNewAbortAndDurationEnabled(const FeatureContext*) { return MediaSourceNewAbortAndDurationEnabled(); }

  static void SetMediaSourceStableEnabled(bool enabled) { is_media_source_stable_enabled_ = enabled; }
  static bool MediaSourceStableEnabled() {
    return is_media_source_stable_enabled_;
  }
  static bool MediaSourceStableEnabled(const FeatureContext*) { return MediaSourceStableEnabled(); }

  static void SetMetaColorSchemeEnabled(bool enabled) { is_meta_color_scheme_enabled_ = enabled; }
  static bool MetaColorSchemeEnabled() {
    return is_meta_color_scheme_enabled_;
  }
  static bool MetaColorSchemeEnabled(const FeatureContext*) { return MetaColorSchemeEnabled(); }

  static void SetMiddleClickAutoscrollEnabled(bool enabled) { is_middle_click_autoscroll_enabled_ = enabled; }
  static bool MiddleClickAutoscrollEnabled() {
    return is_middle_click_autoscroll_enabled_;
  }
  static bool MiddleClickAutoscrollEnabled(const FeatureContext*) { return MiddleClickAutoscrollEnabled(); }

  static void SetMobileLayoutThemeEnabled(bool enabled) { is_mobile_layout_theme_enabled_ = enabled; }
  static bool MobileLayoutThemeEnabled() {
    return is_mobile_layout_theme_enabled_;
  }
  static bool MobileLayoutThemeEnabled(const FeatureContext*) { return MobileLayoutThemeEnabled(); }

  static void SetModuleServiceWorkerEnabled(bool enabled) { is_module_service_worker_enabled_ = enabled; }
  static bool ModuleServiceWorkerEnabled() {
    return is_module_service_worker_enabled_;
  }
  static bool ModuleServiceWorkerEnabled(const FeatureContext*) { return ModuleServiceWorkerEnabled(); }

  static void SetModuleSharedWorkerEnabled(bool enabled) { is_module_shared_worker_enabled_ = enabled; }
  static bool ModuleSharedWorkerEnabled() {
    return is_module_shared_worker_enabled_;
  }
  static bool ModuleSharedWorkerEnabled(const FeatureContext*) { return ModuleSharedWorkerEnabled(); }

  static void SetMojoJSEnabled(bool enabled) { is_mojo_js_enabled_ = enabled; }
  static bool MojoJSEnabled() {
    return is_mojo_js_enabled_;
  }
  static bool MojoJSEnabled(const FeatureContext*) { return MojoJSEnabled(); }

  static void SetMojoJSTestEnabled(bool enabled) { is_mojo_js_test_enabled_ = enabled; }
  static bool MojoJSTestEnabled() {
    return is_mojo_js_test_enabled_;
  }
  static bool MojoJSTestEnabled(const FeatureContext*) { return MojoJSTestEnabled(); }

  static void SetMouseSubframeNoImplicitCaptureEnabled(bool enabled) { is_mouse_subframe_no_implicit_capture_enabled_ = enabled; }
  static bool MouseSubframeNoImplicitCaptureEnabled() {
    return is_mouse_subframe_no_implicit_capture_enabled_;
  }
  static bool MouseSubframeNoImplicitCaptureEnabled(const FeatureContext*) { return MouseSubframeNoImplicitCaptureEnabled(); }

  static void SetNamedPagesEnabled(bool enabled) { is_named_pages_enabled_ = enabled; }
  static bool NamedPagesEnabled() {
    return is_named_pages_enabled_;
  }
  static bool NamedPagesEnabled(const FeatureContext*) { return NamedPagesEnabled(); }

  static void SetNativeIOEnabled(bool enabled) { is_native_io_enabled_ = enabled; }
  static bool NativeIOEnabled() {
    return is_native_io_enabled_;
  }
  static bool NativeIOEnabled(const FeatureContext*) { return NativeIOEnabled(); }

  static void SetNavigatorContentUtilsEnabled(bool enabled) { is_navigator_content_utils_enabled_ = enabled; }
  static bool NavigatorContentUtilsEnabled() {
    return is_navigator_content_utils_enabled_;
  }
  static bool NavigatorContentUtilsEnabled(const FeatureContext*) { return NavigatorContentUtilsEnabled(); }

  static void SetNavigatorLanguageInInsecureContextEnabled(bool enabled) { is_navigator_language_in_insecure_context_enabled_ = enabled; }
  static bool NavigatorLanguageInInsecureContextEnabled() {
    return is_navigator_language_in_insecure_context_enabled_;
  }
  static bool NavigatorLanguageInInsecureContextEnabled(const FeatureContext*) { return NavigatorLanguageInInsecureContextEnabled(); }

  static void SetNetInfoDownlinkMaxEnabled(bool enabled) { is_net_info_downlink_max_enabled_ = enabled; }
  static bool NetInfoDownlinkMaxEnabled() {
    return is_net_info_downlink_max_enabled_;
  }
  static bool NetInfoDownlinkMaxEnabled(const FeatureContext*) { return NetInfoDownlinkMaxEnabled(); }

  static void SetNeverSlowModeEnabled(bool enabled) { is_never_slow_mode_enabled_ = enabled; }
  static bool NeverSlowModeEnabled() {
    return is_never_slow_mode_enabled_;
  }
  static bool NeverSlowModeEnabled(const FeatureContext*) { return NeverSlowModeEnabled(); }

  static void SetNewCanvas2DAPIEnabled(bool enabled) { is_new_canvas_2d_api_enabled_ = enabled; }
  static bool NewCanvas2DAPIEnabled() {
    return is_new_canvas_2d_api_enabled_;
  }
  static bool NewCanvas2DAPIEnabled(const FeatureContext*) { return NewCanvas2DAPIEnabled(); }

  static void SetNewRemotePlaybackPipelineEnabled(bool enabled) { is_new_remote_playback_pipeline_enabled_ = enabled; }
  static bool NewRemotePlaybackPipelineEnabled() {
    return is_new_remote_playback_pipeline_enabled_;
  }
  static bool NewRemotePlaybackPipelineEnabled(const FeatureContext*) { return NewRemotePlaybackPipelineEnabled(); }

  static void SetNoIdleEncodingForWebTestsEnabled(bool enabled) { is_no_idle_encoding_for_web_tests_enabled_ = enabled; }
  static bool NoIdleEncodingForWebTestsEnabled() {
    return is_no_idle_encoding_for_web_tests_enabled_;
  }
  static bool NoIdleEncodingForWebTestsEnabled(const FeatureContext*) { return NoIdleEncodingForWebTestsEnabled(); }

  static void SetNotificationConstructorEnabled(bool enabled) { is_notification_constructor_enabled_ = enabled; }
  static bool NotificationConstructorEnabled() {
    return is_notification_constructor_enabled_;
  }
  static bool NotificationConstructorEnabled(const FeatureContext*) { return NotificationConstructorEnabled(); }

  static void SetNotificationContentImageEnabled(bool enabled) { is_notification_content_image_enabled_ = enabled; }
  static bool NotificationContentImageEnabled() {
    return is_notification_content_image_enabled_;
  }
  static bool NotificationContentImageEnabled(const FeatureContext*) { return NotificationContentImageEnabled(); }

  static void SetNotificationsEnabled(bool enabled) { is_notifications_enabled_ = enabled; }
  static bool NotificationsEnabled() {
    return is_notifications_enabled_;
  }
  static bool NotificationsEnabled(const FeatureContext*) { return NotificationsEnabled(); }

  static void SetOffMainThreadCSSPaintEnabled(bool enabled) { is_off_main_thread_css_paint_enabled_ = enabled; }
  static bool OffMainThreadCSSPaintEnabled() {
    return is_off_main_thread_css_paint_enabled_;
  }
  static bool OffMainThreadCSSPaintEnabled(const FeatureContext*) { return OffMainThreadCSSPaintEnabled(); }

  static void SetOffscreenCanvasCommitEnabled(bool enabled) { is_offscreen_canvas_commit_enabled_ = enabled; }
  static bool OffscreenCanvasCommitEnabled() {
    return is_offscreen_canvas_commit_enabled_;
  }
  static bool OffscreenCanvasCommitEnabled(const FeatureContext*) { return OffscreenCanvasCommitEnabled(); }

  static void SetOnDeviceChangeEnabled(bool enabled) { is_on_device_change_enabled_ = enabled; }
  static bool OnDeviceChangeEnabled() {
    return is_on_device_change_enabled_;
  }
  static bool OnDeviceChangeEnabled(const FeatureContext*) { return OnDeviceChangeEnabled(); }

  static void SetOrientationEventEnabled(bool enabled) { is_orientation_event_enabled_ = enabled; }
  static bool OrientationEventEnabled() {
    return is_orientation_event_enabled_;
  }
  static bool OrientationEventEnabled(const FeatureContext*) { return OrientationEventEnabled(); }

  static void SetOriginPolicyEnabled(bool enabled) { is_origin_policy_enabled_ = enabled; }
  static bool OriginPolicyEnabled() {
    return is_origin_policy_enabled_;
  }
  static bool OriginPolicyEnabled(const FeatureContext*) { return OriginPolicyEnabled(); }

  static void SetOutOfBlinkCorsEnabled(bool enabled) { is_out_of_blink_cors_enabled_ = enabled; }
  static bool OutOfBlinkCorsEnabled() {
    return is_out_of_blink_cors_enabled_;
  }
  static bool OutOfBlinkCorsEnabled(const FeatureContext*) { return OutOfBlinkCorsEnabled(); }

  static void SetOverflowIconsForMediaControlsEnabled(bool enabled) { is_overflow_icons_for_media_controls_enabled_ = enabled; }
  static bool OverflowIconsForMediaControlsEnabled() {
    return is_overflow_icons_for_media_controls_enabled_;
  }
  static bool OverflowIconsForMediaControlsEnabled(const FeatureContext*) { return OverflowIconsForMediaControlsEnabled(); }

  static void SetOverscrollCustomizationEnabled(bool enabled) { is_overscroll_customization_enabled_ = enabled; }
  static bool OverscrollCustomizationEnabled() {
    return is_overscroll_customization_enabled_;
  }
  static bool OverscrollCustomizationEnabled(const FeatureContext*) { return OverscrollCustomizationEnabled(); }

  static void SetPagePopupEnabled(bool enabled) { is_page_popup_enabled_ = enabled; }
  static bool PagePopupEnabled() {
    return is_page_popup_enabled_;
  }
  static bool PagePopupEnabled(const FeatureContext*) { return PagePopupEnabled(); }

  static void SetPaintUnderInvalidationCheckingEnabled(bool enabled) { is_paint_under_invalidation_checking_enabled_ = enabled; }
  static bool PaintUnderInvalidationCheckingEnabled() {
    return is_paint_under_invalidation_checking_enabled_;
  }
  static bool PaintUnderInvalidationCheckingEnabled(const FeatureContext*) { return PaintUnderInvalidationCheckingEnabled(); }

  static void SetParseUrlProtocolHandlerEnabled(bool enabled) { is_parse_url_protocol_handler_enabled_ = enabled; }
  static bool ParseUrlProtocolHandlerEnabled() {
    return is_parse_url_protocol_handler_enabled_;
  }
  static bool ParseUrlProtocolHandlerEnabled(const FeatureContext*) { return ParseUrlProtocolHandlerEnabled(); }

  static void SetPassPaintVisualRectToCompositorEnabled(bool enabled) { is_pass_paint_visual_rect_to_compositor_enabled_ = enabled; }
  static bool PassPaintVisualRectToCompositorEnabled() {
    return is_pass_paint_visual_rect_to_compositor_enabled_;
  }
  static bool PassPaintVisualRectToCompositorEnabled(const FeatureContext*) { return PassPaintVisualRectToCompositorEnabled(); }

  static void SetPasswordRevealEnabled(bool enabled) { is_password_reveal_enabled_ = enabled; }
  static bool PasswordRevealEnabled() {
    return is_password_reveal_enabled_;
  }
  static bool PasswordRevealEnabled(const FeatureContext*) { return PasswordRevealEnabled(); }

  static void SetPaymentAppEnabled(bool enabled) { is_payment_app_enabled_ = enabled; }
  static bool PaymentAppEnabled() {
    return is_payment_app_enabled_;
  }
  static bool PaymentAppEnabled(const FeatureContext*) { return PaymentAppEnabled(); }

  static void SetPaymentHandlerChangePaymentMethodEnabled(bool enabled) { is_payment_handler_change_payment_method_enabled_ = enabled; }
  static bool PaymentHandlerChangePaymentMethodEnabled() {
    return is_payment_handler_change_payment_method_enabled_;
  }
  static bool PaymentHandlerChangePaymentMethodEnabled(const FeatureContext*) { return PaymentHandlerChangePaymentMethodEnabled(); }

  static void SetPaymentHandlerHandlesShippingAndContactEnabled(bool enabled) { is_payment_handler_handles_shipping_and_contact_enabled_ = enabled; }
  static bool PaymentHandlerHandlesShippingAndContactEnabled() {
    return is_payment_handler_handles_shipping_and_contact_enabled_;
  }
  static bool PaymentHandlerHandlesShippingAndContactEnabled(const FeatureContext*) { return PaymentHandlerHandlesShippingAndContactEnabled(); }

  static void SetPaymentHandlerMinimalUIEnabled(bool enabled) { is_payment_handler_minimal_ui_enabled_ = enabled; }
  static bool PaymentHandlerMinimalUIEnabled() {
    return is_payment_handler_minimal_ui_enabled_;
  }
  static bool PaymentHandlerMinimalUIEnabled(const FeatureContext*) { return PaymentHandlerMinimalUIEnabled(); }

  static void SetPaymentMethodChangeEventEnabled(bool enabled) { is_payment_method_change_event_enabled_ = enabled; }
  static bool PaymentMethodChangeEventEnabled() {
    return is_payment_method_change_event_enabled_;
  }
  static bool PaymentMethodChangeEventEnabled(const FeatureContext*) { return PaymentMethodChangeEventEnabled(); }

  static void SetPaymentRequestEnabled(bool enabled) { is_payment_request_enabled_ = enabled; }
  static bool PaymentRequestEnabled() {
    return is_payment_request_enabled_;
  }
  static bool PaymentRequestEnabled(const FeatureContext*) { return PaymentRequestEnabled(); }

  static void SetPaymentRequestMerchantValidationEventEnabled(bool enabled) { is_payment_request_merchant_validation_event_enabled_ = enabled; }
  static bool PaymentRequestMerchantValidationEventEnabled() {
    return is_payment_request_merchant_validation_event_enabled_;
  }
  static bool PaymentRequestMerchantValidationEventEnabled(const FeatureContext*) { return PaymentRequestMerchantValidationEventEnabled(); }

  static void SetPaymentRetryEnabled(bool enabled) { is_payment_retry_enabled_ = enabled; }
  static bool PaymentRetryEnabled() {
    return is_payment_retry_enabled_;
  }
  static bool PaymentRetryEnabled(const FeatureContext*) { return PaymentRetryEnabled(); }

  static void SetPercentBasedScrollingEnabled(bool enabled) { is_percent_based_scrolling_enabled_ = enabled; }
  static bool PercentBasedScrollingEnabled() {
    return is_percent_based_scrolling_enabled_;
  }
  static bool PercentBasedScrollingEnabled(const FeatureContext*) { return PercentBasedScrollingEnabled(); }

  static void SetPerformanceManagerInstrumentationEnabled(bool enabled) { is_performance_manager_instrumentation_enabled_ = enabled; }
  static bool PerformanceManagerInstrumentationEnabled() {
    return is_performance_manager_instrumentation_enabled_;
  }
  static bool PerformanceManagerInstrumentationEnabled(const FeatureContext*) { return PerformanceManagerInstrumentationEnabled(); }

  static void SetPeriodicBackgroundSyncEnabled(bool enabled) { is_periodic_background_sync_enabled_ = enabled; }
  static bool PeriodicBackgroundSyncEnabled() {
    return is_periodic_background_sync_enabled_;
  }
  static bool PeriodicBackgroundSyncEnabled(const FeatureContext*) { return PeriodicBackgroundSyncEnabled(); }

  static void SetPermissionDelegationEnabled(bool enabled) { is_permission_delegation_enabled_ = enabled; }
  static bool PermissionDelegationEnabled() {
    return is_permission_delegation_enabled_;
  }
  static bool PermissionDelegationEnabled(const FeatureContext*) { return PermissionDelegationEnabled(); }

  static void SetPermissionsEnabled(bool enabled) { is_permissions_enabled_ = enabled; }
  static bool PermissionsEnabled() {
    return is_permissions_enabled_;
  }
  static bool PermissionsEnabled(const FeatureContext*) { return PermissionsEnabled(); }

  static void SetPermissionsRequestRevokeEnabled(bool enabled) { is_permissions_request_revoke_enabled_ = enabled; }
  static bool PermissionsRequestRevokeEnabled() {
    return is_permissions_request_revoke_enabled_;
  }
  static bool PermissionsRequestRevokeEnabled(const FeatureContext*) { return PermissionsRequestRevokeEnabled(); }

  static void SetPictureInPictureEnabled(bool enabled) { is_picture_in_picture_enabled_ = enabled; }
  static bool PictureInPictureEnabled() {
    return is_picture_in_picture_enabled_;
  }
  static bool PictureInPictureEnabled(const FeatureContext*) { return PictureInPictureEnabled(); }

  static void SetPictureInPictureAPIEnabled(bool enabled) { is_picture_in_picture_api_enabled_ = enabled; }
  static bool PictureInPictureAPIEnabled() {
    return is_picture_in_picture_api_enabled_;
  }
  static bool PictureInPictureAPIEnabled(const FeatureContext*) { return PictureInPictureAPIEnabled(); }

  static void SetPictureInPictureV2Enabled(bool enabled) { is_picture_in_picture_v_2_enabled_ = enabled; }
  static bool PictureInPictureV2Enabled() {
    if (!PictureInPictureAPIEnabled())
      return false;
    return is_picture_in_picture_v_2_enabled_;
  }
  static bool PictureInPictureV2Enabled(const FeatureContext*) { return PictureInPictureV2Enabled(); }

  static void SetPointerRawUpdateEnabled(bool enabled) { is_pointer_raw_update_enabled_ = enabled; }
  static bool PointerRawUpdateEnabled() {
    return is_pointer_raw_update_enabled_;
  }
  static bool PointerRawUpdateEnabled(const FeatureContext*) { return PointerRawUpdateEnabled(); }

  static void SetPostAnimationFrameEnabled(bool enabled) { is_post_animation_frame_enabled_ = enabled; }
  static bool PostAnimationFrameEnabled() {
    return is_post_animation_frame_enabled_;
  }
  static bool PostAnimationFrameEnabled(const FeatureContext*) { return PostAnimationFrameEnabled(); }

  static void SetPreciseMemoryInfoEnabled(bool enabled) { is_precise_memory_info_enabled_ = enabled; }
  static bool PreciseMemoryInfoEnabled() {
    return is_precise_memory_info_enabled_;
  }
  static bool PreciseMemoryInfoEnabled(const FeatureContext*) { return PreciseMemoryInfoEnabled(); }

  static void SetPreferNonCompositedScrollingEnabled(bool enabled) { is_prefer_non_composited_scrolling_enabled_ = enabled; }
  static bool PreferNonCompositedScrollingEnabled() {
    return is_prefer_non_composited_scrolling_enabled_;
  }
  static bool PreferNonCompositedScrollingEnabled(const FeatureContext*) { return PreferNonCompositedScrollingEnabled(); }

  static void SetPrefersReducedDataEnabled(bool enabled) { is_prefers_reduced_data_enabled_ = enabled; }
  static bool PrefersReducedDataEnabled() {
    return is_prefers_reduced_data_enabled_;
  }
  static bool PrefersReducedDataEnabled(const FeatureContext*) { return PrefersReducedDataEnabled(); }

  static void SetPrefixedVideoFullscreenEnabled(bool enabled) { is_prefixed_video_fullscreen_enabled_ = enabled; }
  static bool PrefixedVideoFullscreenEnabled() {
    return is_prefixed_video_fullscreen_enabled_;
  }
  static bool PrefixedVideoFullscreenEnabled(const FeatureContext*) { return PrefixedVideoFullscreenEnabled(); }

  static void SetPresentationEnabled(bool enabled) { is_presentation_enabled_ = enabled; }
  static bool PresentationEnabled() {
    return is_presentation_enabled_;
  }
  static bool PresentationEnabled(const FeatureContext*) { return PresentationEnabled(); }

  static void SetPushMessagingEnabled(bool enabled) { is_push_messaging_enabled_ = enabled; }
  static bool PushMessagingEnabled() {
    return is_push_messaging_enabled_;
  }
  static bool PushMessagingEnabled(const FeatureContext*) { return PushMessagingEnabled(); }

  static void SetPushMessagingSubscriptionChangeEnabled(bool enabled) { is_push_messaging_subscription_change_enabled_ = enabled; }
  static bool PushMessagingSubscriptionChangeEnabled() {
    return is_push_messaging_subscription_change_enabled_;
  }
  static bool PushMessagingSubscriptionChangeEnabled(const FeatureContext*) { return PushMessagingSubscriptionChangeEnabled(); }

  static void SetRawClipboardEnabled(bool enabled) { is_raw_clipboard_enabled_ = enabled; }
  static bool RawClipboardEnabled() {
    return is_raw_clipboard_enabled_;
  }
  static bool RawClipboardEnabled(const FeatureContext*) { return RawClipboardEnabled(); }

  static void SetReducedReferrerGranularityEnabled(bool enabled) { is_reduced_referrer_granularity_enabled_ = enabled; }
  static bool ReducedReferrerGranularityEnabled() {
    return is_reduced_referrer_granularity_enabled_;
  }
  static bool ReducedReferrerGranularityEnabled(const FeatureContext*) { return ReducedReferrerGranularityEnabled(); }

  static void SetRemotePlaybackEnabled(bool enabled) { is_remote_playback_enabled_ = enabled; }
  static bool RemotePlaybackEnabled() {
    return is_remote_playback_enabled_;
  }
  static bool RemotePlaybackEnabled(const FeatureContext*) { return RemotePlaybackEnabled(); }

  static void SetRemotePlaybackBackendEnabled(bool enabled) { is_remote_playback_backend_enabled_ = enabled; }
  static bool RemotePlaybackBackendEnabled() {
    return is_remote_playback_backend_enabled_;
  }
  static bool RemotePlaybackBackendEnabled(const FeatureContext*) { return RemotePlaybackBackendEnabled(); }

  static void SetRequestVideoFrameCallbackEnabled(bool enabled) { is_request_video_frame_callback_enabled_ = enabled; }
  static bool RequestVideoFrameCallbackEnabled() {
    return is_request_video_frame_callback_enabled_;
  }
  static bool RequestVideoFrameCallbackEnabled(const FeatureContext*) { return RequestVideoFrameCallbackEnabled(); }

  static void SetResizeObserverUpdatesEnabled(bool enabled) { is_resize_observer_updates_enabled_ = enabled; }
  static bool ResizeObserverUpdatesEnabled() {
    return is_resize_observer_updates_enabled_;
  }
  static bool ResizeObserverUpdatesEnabled(const FeatureContext*) { return ResizeObserverUpdatesEnabled(); }

  static void SetRestrictAppCacheToSecureContextsEnabled(bool enabled) { is_restrict_app_cache_to_secure_contexts_enabled_ = enabled; }
  static bool RestrictAppCacheToSecureContextsEnabled() {
    return is_restrict_app_cache_to_secure_contexts_enabled_;
  }
  static bool RestrictAppCacheToSecureContextsEnabled(const FeatureContext*) { return RestrictAppCacheToSecureContextsEnabled(); }

  static void SetRestrictAutomaticLazyFrameLoadingToDataSaverEnabled(bool enabled) { is_restrict_automatic_lazy_frame_loading_to_data_saver_enabled_ = enabled; }
  static bool RestrictAutomaticLazyFrameLoadingToDataSaverEnabled() {
    if (!AutomaticLazyFrameLoadingEnabled())
      return false;
    return is_restrict_automatic_lazy_frame_loading_to_data_saver_enabled_;
  }
  static bool RestrictAutomaticLazyFrameLoadingToDataSaverEnabled(const FeatureContext*) { return RestrictAutomaticLazyFrameLoadingToDataSaverEnabled(); }

  static void SetRestrictAutomaticLazyImageLoadingToDataSaverEnabled(bool enabled) { is_restrict_automatic_lazy_image_loading_to_data_saver_enabled_ = enabled; }
  static bool RestrictAutomaticLazyImageLoadingToDataSaverEnabled() {
    if (!AutomaticLazyImageLoadingEnabled())
      return false;
    return is_restrict_automatic_lazy_image_loading_to_data_saver_enabled_;
  }
  static bool RestrictAutomaticLazyImageLoadingToDataSaverEnabled(const FeatureContext*) { return RestrictAutomaticLazyImageLoadingToDataSaverEnabled(); }

  static void SetRTCSvcScalabilityModeEnabled(bool enabled) { is_rtc_svc_scalability_mode_enabled_ = enabled; }
  static bool RTCSvcScalabilityModeEnabled() {
    return is_rtc_svc_scalability_mode_enabled_;
  }
  static bool RTCSvcScalabilityModeEnabled(const FeatureContext*) { return RTCSvcScalabilityModeEnabled(); }

  static void SetRTCUnifiedPlanEnabled(bool enabled) { is_rtc_unified_plan_enabled_ = enabled; }
  static bool RTCUnifiedPlanEnabled() {
    return is_rtc_unified_plan_enabled_;
  }
  static bool RTCUnifiedPlanEnabled(const FeatureContext*) { return RTCUnifiedPlanEnabled(); }

  static void SetRTCUnifiedPlanByDefaultEnabled(bool enabled) { is_rtc_unified_plan_by_default_enabled_ = enabled; }
  static bool RTCUnifiedPlanByDefaultEnabled() {
    return is_rtc_unified_plan_by_default_enabled_;
  }
  static bool RTCUnifiedPlanByDefaultEnabled(const FeatureContext*) { return RTCUnifiedPlanByDefaultEnabled(); }

  static void SetSameSiteByDefaultCookiesEnabled(bool enabled) { is_same_site_by_default_cookies_enabled_ = enabled; }
  static bool SameSiteByDefaultCookiesEnabled() {
    return is_same_site_by_default_cookies_enabled_;
  }
  static bool SameSiteByDefaultCookiesEnabled(const FeatureContext*) { return SameSiteByDefaultCookiesEnabled(); }

  static void SetScreenWakeLockEnabled(bool enabled) { is_screen_wake_lock_enabled_ = enabled; }
  static bool ScreenWakeLockEnabled() {
    return is_screen_wake_lock_enabled_;
  }
  static bool ScreenWakeLockEnabled(const FeatureContext*) { return ScreenWakeLockEnabled(); }

  static void SetScriptedSpeechRecognitionEnabled(bool enabled) { is_scripted_speech_recognition_enabled_ = enabled; }
  static bool ScriptedSpeechRecognitionEnabled() {
    return is_scripted_speech_recognition_enabled_;
  }
  static bool ScriptedSpeechRecognitionEnabled(const FeatureContext*) { return ScriptedSpeechRecognitionEnabled(); }

  static void SetScriptedSpeechSynthesisEnabled(bool enabled) { is_scripted_speech_synthesis_enabled_ = enabled; }
  static bool ScriptedSpeechSynthesisEnabled() {
    return is_scripted_speech_synthesis_enabled_;
  }
  static bool ScriptedSpeechSynthesisEnabled(const FeatureContext*) { return ScriptedSpeechSynthesisEnabled(); }

  static void SetScrollCustomizationEnabled(bool enabled) { is_scroll_customization_enabled_ = enabled; }
  static bool ScrollCustomizationEnabled() {
    return is_scroll_customization_enabled_;
  }
  static bool ScrollCustomizationEnabled(const FeatureContext*) { return ScrollCustomizationEnabled(); }

  static void SetScrollSnapAfterLayoutEnabled(bool enabled) { is_scroll_snap_after_layout_enabled_ = enabled; }
  static bool ScrollSnapAfterLayoutEnabled() {
    return is_scroll_snap_after_layout_enabled_;
  }
  static bool ScrollSnapAfterLayoutEnabled(const FeatureContext*) { return ScrollSnapAfterLayoutEnabled(); }

  static void SetScrollTimelineEnabled(bool enabled) { is_scroll_timeline_enabled_ = enabled; }
  static bool ScrollTimelineEnabled() {
    if (AnimationWorkletEnabled())
      return true;
    if (CSSScrollTimelineEnabled())
      return true;
    return is_scroll_timeline_enabled_;
  }
  static bool ScrollTimelineEnabled(const FeatureContext*) { return ScrollTimelineEnabled(); }

  static void SetScrollTopLeftInteropEnabled(bool enabled) { is_scroll_top_left_interop_enabled_ = enabled; }
  static bool ScrollTopLeftInteropEnabled() {
    return is_scroll_top_left_interop_enabled_;
  }
  static bool ScrollTopLeftInteropEnabled(const FeatureContext*) { return ScrollTopLeftInteropEnabled(); }

  static void SetScrollUnificationEnabled(bool enabled) { is_scroll_unification_enabled_ = enabled; }
  static bool ScrollUnificationEnabled() {
    return is_scroll_unification_enabled_;
  }
  static bool ScrollUnificationEnabled(const FeatureContext*) { return ScrollUnificationEnabled(); }

  static void SetSendBeaconThrowForBlobWithNonSimpleTypeEnabled(bool enabled) { is_send_beacon_throw_for_blob_with_non_simple_type_enabled_ = enabled; }
  static bool SendBeaconThrowForBlobWithNonSimpleTypeEnabled() {
    return is_send_beacon_throw_for_blob_with_non_simple_type_enabled_;
  }
  static bool SendBeaconThrowForBlobWithNonSimpleTypeEnabled(const FeatureContext*) { return SendBeaconThrowForBlobWithNonSimpleTypeEnabled(); }

  static void SetSendMouseEventsDisabledFormControlsEnabled(bool enabled) { is_send_mouse_events_disabled_form_controls_enabled_ = enabled; }
  static bool SendMouseEventsDisabledFormControlsEnabled() {
    return is_send_mouse_events_disabled_form_controls_enabled_;
  }
  static bool SendMouseEventsDisabledFormControlsEnabled(const FeatureContext*) { return SendMouseEventsDisabledFormControlsEnabled(); }

  static void SetSensorExtraClassesEnabled(bool enabled) { is_sensor_extra_classes_enabled_ = enabled; }
  static bool SensorExtraClassesEnabled() {
    return is_sensor_extra_classes_enabled_;
  }
  static bool SensorExtraClassesEnabled(const FeatureContext*) { return SensorExtraClassesEnabled(); }

  static void SetServiceWorkerClientLifecycleStateEnabled(bool enabled) { is_service_worker_client_lifecycle_state_enabled_ = enabled; }
  static bool ServiceWorkerClientLifecycleStateEnabled() {
    return is_service_worker_client_lifecycle_state_enabled_;
  }
  static bool ServiceWorkerClientLifecycleStateEnabled(const FeatureContext*) { return ServiceWorkerClientLifecycleStateEnabled(); }

  static void SetServiceWorkerFetchEventWorkerTimingEnabled(bool enabled) { is_service_worker_fetch_event_worker_timing_enabled_ = enabled; }
  static bool ServiceWorkerFetchEventWorkerTimingEnabled() {
    return is_service_worker_fetch_event_worker_timing_enabled_;
  }
  static bool ServiceWorkerFetchEventWorkerTimingEnabled(const FeatureContext*) { return ServiceWorkerFetchEventWorkerTimingEnabled(); }

  static void SetSharedArrayBufferEnabled(bool enabled) { is_shared_array_buffer_enabled_ = enabled; }
  static bool SharedArrayBufferEnabled() {
    return is_shared_array_buffer_enabled_;
  }
  static bool SharedArrayBufferEnabled(const FeatureContext*) { return SharedArrayBufferEnabled(); }

  static void SetSharedWorkerEnabled(bool enabled) { is_shared_worker_enabled_ = enabled; }
  static bool SharedWorkerEnabled() {
    return is_shared_worker_enabled_;
  }
  static bool SharedWorkerEnabled(const FeatureContext*) { return SharedWorkerEnabled(); }

  static void SetSignedExchangePrefetchCacheForNavigationsEnabled(bool enabled) { is_signed_exchange_prefetch_cache_for_navigations_enabled_ = enabled; }
  static bool SignedExchangePrefetchCacheForNavigationsEnabled() {
    return is_signed_exchange_prefetch_cache_for_navigations_enabled_;
  }
  static bool SignedExchangePrefetchCacheForNavigationsEnabled(const FeatureContext*) { return SignedExchangePrefetchCacheForNavigationsEnabled(); }

  static void SetSkipTouchEventFilterEnabled(bool enabled) { is_skip_touch_event_filter_enabled_ = enabled; }
  static bool SkipTouchEventFilterEnabled() {
    return is_skip_touch_event_filter_enabled_;
  }
  static bool SkipTouchEventFilterEnabled(const FeatureContext*) { return SkipTouchEventFilterEnabled(); }

  static void SetSmsReceiverEnabled(bool enabled) { is_sms_receiver_enabled_ = enabled; }
  static bool SmsReceiverEnabled() {
    return is_sms_receiver_enabled_;
  }
  static bool SmsReceiverEnabled(const FeatureContext*) { return SmsReceiverEnabled(); }

  static void SetSquashAfterPaintEnabled(bool enabled) { is_squash_after_paint_enabled_ = enabled; }
  static bool SquashAfterPaintEnabled() {
    return is_squash_after_paint_enabled_;
  }
  static bool SquashAfterPaintEnabled(const FeatureContext*) { return SquashAfterPaintEnabled(); }

  static void SetStableBlinkFeaturesEnabled(bool enabled) { is_stable_blink_features_enabled_ = enabled; }
  static bool StableBlinkFeaturesEnabled() {
    return is_stable_blink_features_enabled_;
  }
  static bool StableBlinkFeaturesEnabled(const FeatureContext*) { return StableBlinkFeaturesEnabled(); }

  static void SetStorageAccessAPIEnabled(bool enabled) { is_storage_access_api_enabled_ = enabled; }
  static bool StorageAccessAPIEnabled() {
    return is_storage_access_api_enabled_;
  }
  static bool StorageAccessAPIEnabled(const FeatureContext*) { return StorageAccessAPIEnabled(); }

  static void SetStrictMimeTypesForWorkersEnabled(bool enabled) { is_strict_mime_types_for_workers_enabled_ = enabled; }
  static bool StrictMimeTypesForWorkersEnabled() {
    return is_strict_mime_types_for_workers_enabled_;
  }
  static bool StrictMimeTypesForWorkersEnabled(const FeatureContext*) { return StrictMimeTypesForWorkersEnabled(); }

  static void SetSubresourceWebBundlesEnabled(bool enabled) { is_subresource_web_bundles_enabled_ = enabled; }
  static bool SubresourceWebBundlesEnabled() {
    return is_subresource_web_bundles_enabled_;
  }
  static bool SubresourceWebBundlesEnabled(const FeatureContext*) { return SubresourceWebBundlesEnabled(); }

  static void SetSurfaceEmbeddingFeaturesEnabled(bool enabled) { is_surface_embedding_features_enabled_ = enabled; }
  static bool SurfaceEmbeddingFeaturesEnabled() {
    return is_surface_embedding_features_enabled_;
  }
  static bool SurfaceEmbeddingFeaturesEnabled(const FeatureContext*) { return SurfaceEmbeddingFeaturesEnabled(); }

  static void SetSystemWakeLockEnabled(bool enabled) { is_system_wake_lock_enabled_ = enabled; }
  static bool SystemWakeLockEnabled() {
    return is_system_wake_lock_enabled_;
  }
  static bool SystemWakeLockEnabled(const FeatureContext*) { return SystemWakeLockEnabled(); }

  static void SetTestFeatureEnabled(bool enabled) { is_test_feature_enabled_ = enabled; }
  static bool TestFeatureEnabled() {
    return is_test_feature_enabled_;
  }
  static bool TestFeatureEnabled(const FeatureContext*) { return TestFeatureEnabled(); }

  static void SetTestFeatureDependentEnabled(bool enabled) { is_test_feature_dependent_enabled_ = enabled; }
  static bool TestFeatureDependentEnabled() {
    if (!TestFeatureImpliedEnabled())
      return false;
    return is_test_feature_dependent_enabled_;
  }
  static bool TestFeatureDependentEnabled(const FeatureContext*) { return TestFeatureDependentEnabled(); }

  static void SetTestFeatureImpliedEnabled(bool enabled) { is_test_feature_implied_enabled_ = enabled; }
  static bool TestFeatureImpliedEnabled() {
    if (TestFeatureEnabled())
      return true;
    return is_test_feature_implied_enabled_;
  }
  static bool TestFeatureImpliedEnabled(const FeatureContext*) { return TestFeatureImpliedEnabled(); }

  static void SetTextDetectorEnabled(bool enabled) { is_text_detector_enabled_ = enabled; }
  static bool TextDetectorEnabled() {
    return is_text_detector_enabled_;
  }
  static bool TextDetectorEnabled(const FeatureContext*) { return TextDetectorEnabled(); }

  static void SetThirdPartyOriginTrialsEnabled(bool enabled) { is_third_party_origin_trials_enabled_ = enabled; }
  static bool ThirdPartyOriginTrialsEnabled() {
    return is_third_party_origin_trials_enabled_;
  }
  static bool ThirdPartyOriginTrialsEnabled(const FeatureContext*) { return ThirdPartyOriginTrialsEnabled(); }

  static void SetTimerThrottlingForBackgroundTabsEnabled(bool enabled) { is_timer_throttling_for_background_tabs_enabled_ = enabled; }
  static bool TimerThrottlingForBackgroundTabsEnabled() {
    return is_timer_throttling_for_background_tabs_enabled_;
  }
  static bool TimerThrottlingForBackgroundTabsEnabled(const FeatureContext*) { return TimerThrottlingForBackgroundTabsEnabled(); }

  static void SetTimerThrottlingForHiddenFramesEnabled(bool enabled) { is_timer_throttling_for_hidden_frames_enabled_ = enabled; }
  static bool TimerThrottlingForHiddenFramesEnabled() {
    return is_timer_throttling_for_hidden_frames_enabled_;
  }
  static bool TimerThrottlingForHiddenFramesEnabled(const FeatureContext*) { return TimerThrottlingForHiddenFramesEnabled(); }

  static void SetTimeZoneChangeEventEnabled(bool enabled) { is_time_zone_change_event_enabled_ = enabled; }
  static bool TimeZoneChangeEventEnabled() {
    return is_time_zone_change_event_enabled_;
  }
  static bool TimeZoneChangeEventEnabled(const FeatureContext*) { return TimeZoneChangeEventEnabled(); }

  static void SetTrackLayoutPassesPerBlockEnabled(bool enabled) { is_track_layout_passes_per_block_enabled_ = enabled; }
  static bool TrackLayoutPassesPerBlockEnabled() {
    return is_track_layout_passes_per_block_enabled_;
  }
  static bool TrackLayoutPassesPerBlockEnabled(const FeatureContext*) { return TrackLayoutPassesPerBlockEnabled(); }

  static void SetTransformInteropEnabled(bool enabled) { is_transform_interop_enabled_ = enabled; }
  static bool TransformInteropEnabled() {
    return is_transform_interop_enabled_;
  }
  static bool TransformInteropEnabled(const FeatureContext*) { return TransformInteropEnabled(); }

  static void SetTranslateServiceEnabled(bool enabled) { is_translate_service_enabled_ = enabled; }
  static bool TranslateServiceEnabled() {
    return is_translate_service_enabled_;
  }
  static bool TranslateServiceEnabled(const FeatureContext*) { return TranslateServiceEnabled(); }

  static void SetTrustedDOMTypesEnabled(bool enabled) { is_trusted_dom_types_enabled_ = enabled; }
  static bool TrustedDOMTypesEnabled() {
    return is_trusted_dom_types_enabled_;
  }
  static bool TrustedDOMTypesEnabled(const FeatureContext*) { return TrustedDOMTypesEnabled(); }

  static void SetTrustTokensAlwaysAllowIssuanceEnabled(bool enabled) { is_trust_tokens_always_allow_issuance_enabled_ = enabled; }
  static bool TrustTokensAlwaysAllowIssuanceEnabled() {
    return is_trust_tokens_always_allow_issuance_enabled_;
  }
  static bool TrustTokensAlwaysAllowIssuanceEnabled(const FeatureContext*) { return TrustTokensAlwaysAllowIssuanceEnabled(); }

  static void SetUnclosedFormControlIsInvalidEnabled(bool enabled) { is_unclosed_form_control_is_invalid_enabled_ = enabled; }
  static bool UnclosedFormControlIsInvalidEnabled() {
    return is_unclosed_form_control_is_invalid_enabled_;
  }
  static bool UnclosedFormControlIsInvalidEnabled(const FeatureContext*) { return UnclosedFormControlIsInvalidEnabled(); }

  static void SetUnderlineOffsetThicknessEnabled(bool enabled) { is_underline_offset_thickness_enabled_ = enabled; }
  static bool UnderlineOffsetThicknessEnabled() {
    return is_underline_offset_thickness_enabled_;
  }
  static bool UnderlineOffsetThicknessEnabled(const FeatureContext*) { return UnderlineOffsetThicknessEnabled(); }

  static void SetUserActivationPostMessageTransferEnabled(bool enabled) { is_user_activation_post_message_transfer_enabled_ = enabled; }
  static bool UserActivationPostMessageTransferEnabled() {
    return is_user_activation_post_message_transfer_enabled_;
  }
  static bool UserActivationPostMessageTransferEnabled(const FeatureContext*) { return UserActivationPostMessageTransferEnabled(); }

  static void SetUserActivationSameOriginVisibilityEnabled(bool enabled) { is_user_activation_same_origin_visibility_enabled_ = enabled; }
  static bool UserActivationSameOriginVisibilityEnabled() {
    return is_user_activation_same_origin_visibility_enabled_;
  }
  static bool UserActivationSameOriginVisibilityEnabled(const FeatureContext*) { return UserActivationSameOriginVisibilityEnabled(); }

  static void SetUserAgentClientHintEnabled(bool enabled) { is_user_agent_client_hint_enabled_ = enabled; }
  static bool UserAgentClientHintEnabled() {
    return is_user_agent_client_hint_enabled_;
  }
  static bool UserAgentClientHintEnabled(const FeatureContext*) { return UserAgentClientHintEnabled(); }

  static void SetV8IdleTasksEnabled(bool enabled) { is_v8_idle_tasks_enabled_ = enabled; }
  static bool V8IdleTasksEnabled() {
    return is_v8_idle_tasks_enabled_;
  }
  static bool V8IdleTasksEnabled(const FeatureContext*) { return V8IdleTasksEnabled(); }

  static void SetVideoAutoFullscreenEnabled(bool enabled) { is_video_auto_fullscreen_enabled_ = enabled; }
  static bool VideoAutoFullscreenEnabled() {
    return is_video_auto_fullscreen_enabled_;
  }
  static bool VideoAutoFullscreenEnabled(const FeatureContext*) { return VideoAutoFullscreenEnabled(); }

  static void SetVideoFullscreenOrientationLockEnabled(bool enabled) { is_video_fullscreen_orientation_lock_enabled_ = enabled; }
  static bool VideoFullscreenOrientationLockEnabled() {
    return is_video_fullscreen_orientation_lock_enabled_;
  }
  static bool VideoFullscreenOrientationLockEnabled(const FeatureContext*) { return VideoFullscreenOrientationLockEnabled(); }

  static void SetVideoPlaybackQualityEnabled(bool enabled) { is_video_playback_quality_enabled_ = enabled; }
  static bool VideoPlaybackQualityEnabled() {
    return is_video_playback_quality_enabled_;
  }
  static bool VideoPlaybackQualityEnabled(const FeatureContext*) { return VideoPlaybackQualityEnabled(); }

  static void SetVideoRotateToFullscreenEnabled(bool enabled) { is_video_rotate_to_fullscreen_enabled_ = enabled; }
  static bool VideoRotateToFullscreenEnabled() {
    return is_video_rotate_to_fullscreen_enabled_;
  }
  static bool VideoRotateToFullscreenEnabled(const FeatureContext*) { return VideoRotateToFullscreenEnabled(); }

  static void SetVideoWakeLockOptimisationHiddenMutedEnabled(bool enabled) { is_video_wake_lock_optimisation_hidden_muted_enabled_ = enabled; }
  static bool VideoWakeLockOptimisationHiddenMutedEnabled() {
    return is_video_wake_lock_optimisation_hidden_muted_enabled_;
  }
  static bool VideoWakeLockOptimisationHiddenMutedEnabled(const FeatureContext*) { return VideoWakeLockOptimisationHiddenMutedEnabled(); }

  static void SetVirtualKeyboardEnabled(bool enabled) { is_virtual_keyboard_enabled_ = enabled; }
  static bool VirtualKeyboardEnabled() {
    return is_virtual_keyboard_enabled_;
  }
  static bool VirtualKeyboardEnabled(const FeatureContext*) { return VirtualKeyboardEnabled(); }

  static void SetVisibilityCollapseColumnEnabled(bool enabled) { is_visibility_collapse_column_enabled_ = enabled; }
  static bool VisibilityCollapseColumnEnabled() {
    return is_visibility_collapse_column_enabled_;
  }
  static bool VisibilityCollapseColumnEnabled(const FeatureContext*) { return VisibilityCollapseColumnEnabled(); }

  static void SetWebAnimationsAPIEnabled(bool enabled) { is_web_animations_api_enabled_ = enabled; }
  static bool WebAnimationsAPIEnabled() {
    if (AnimationWorkletEnabled())
      return true;
    return is_web_animations_api_enabled_;
  }
  static bool WebAnimationsAPIEnabled(const FeatureContext*) { return WebAnimationsAPIEnabled(); }

  static void SetWebAnimationsSVGEnabled(bool enabled) { is_web_animations_svg_enabled_ = enabled; }
  static bool WebAnimationsSVGEnabled() {
    return is_web_animations_svg_enabled_;
  }
  static bool WebAnimationsSVGEnabled(const FeatureContext*) { return WebAnimationsSVGEnabled(); }

  static void SetWebAuthEnabled(bool enabled) { is_web_auth_enabled_ = enabled; }
  static bool WebAuthEnabled() {
    return is_web_auth_enabled_;
  }
  static bool WebAuthEnabled(const FeatureContext*) { return WebAuthEnabled(); }

  static void SetWebAuthenticationGetAssertionFeaturePolicyEnabled(bool enabled) { is_web_authentication_get_assertion_feature_policy_enabled_ = enabled; }
  static bool WebAuthenticationGetAssertionFeaturePolicyEnabled() {
    return is_web_authentication_get_assertion_feature_policy_enabled_;
  }
  static bool WebAuthenticationGetAssertionFeaturePolicyEnabled(const FeatureContext*) { return WebAuthenticationGetAssertionFeaturePolicyEnabled(); }

  static void SetWebBluetoothEnabled(bool enabled) { is_web_bluetooth_enabled_ = enabled; }
  static bool WebBluetoothEnabled() {
    return is_web_bluetooth_enabled_;
  }
  static bool WebBluetoothEnabled(const FeatureContext*) { return WebBluetoothEnabled(); }

  static void SetWebBluetoothGetDevicesEnabled(bool enabled) { is_web_bluetooth_get_devices_enabled_ = enabled; }
  static bool WebBluetoothGetDevicesEnabled() {
    return is_web_bluetooth_get_devices_enabled_;
  }
  static bool WebBluetoothGetDevicesEnabled(const FeatureContext*) { return WebBluetoothGetDevicesEnabled(); }

  static void SetWebBluetoothRemoteCharacteristicNewWriteValueEnabled(bool enabled) { is_web_bluetooth_remote_characteristic_new_write_value_enabled_ = enabled; }
  static bool WebBluetoothRemoteCharacteristicNewWriteValueEnabled() {
    return is_web_bluetooth_remote_characteristic_new_write_value_enabled_;
  }
  static bool WebBluetoothRemoteCharacteristicNewWriteValueEnabled(const FeatureContext*) { return WebBluetoothRemoteCharacteristicNewWriteValueEnabled(); }

  static void SetWebBluetoothScanningEnabled(bool enabled) { is_web_bluetooth_scanning_enabled_ = enabled; }
  static bool WebBluetoothScanningEnabled() {
    return is_web_bluetooth_scanning_enabled_;
  }
  static bool WebBluetoothScanningEnabled(const FeatureContext*) { return WebBluetoothScanningEnabled(); }

  static void SetWebBluetoothWatchAdvertisementsEnabled(bool enabled) { is_web_bluetooth_watch_advertisements_enabled_ = enabled; }
  static bool WebBluetoothWatchAdvertisementsEnabled() {
    return is_web_bluetooth_watch_advertisements_enabled_;
  }
  static bool WebBluetoothWatchAdvertisementsEnabled(const FeatureContext*) { return WebBluetoothWatchAdvertisementsEnabled(); }

  static void SetWebCodecsEnabled(bool enabled) { is_web_codecs_enabled_ = enabled; }
  static bool WebCodecsEnabled() {
    return is_web_codecs_enabled_;
  }
  static bool WebCodecsEnabled(const FeatureContext*) { return WebCodecsEnabled(); }

  static void SetWebCryptoCurve25519Enabled(bool enabled) { is_web_crypto_curve_25519_enabled_ = enabled; }
  static bool WebCryptoCurve25519Enabled() {
    return is_web_crypto_curve_25519_enabled_;
  }
  static bool WebCryptoCurve25519Enabled(const FeatureContext*) { return WebCryptoCurve25519Enabled(); }

  static void SetWebGL2ComputeContextEnabled(bool enabled) { is_webgl2_compute_context_enabled_ = enabled; }
  static bool WebGL2ComputeContextEnabled() {
    return is_webgl2_compute_context_enabled_;
  }
  static bool WebGL2ComputeContextEnabled(const FeatureContext*) { return WebGL2ComputeContextEnabled(); }

  static void SetWebGLDraftExtensionsEnabled(bool enabled) { is_webgl_draft_extensions_enabled_ = enabled; }
  static bool WebGLDraftExtensionsEnabled() {
    return is_webgl_draft_extensions_enabled_;
  }
  static bool WebGLDraftExtensionsEnabled(const FeatureContext*) { return WebGLDraftExtensionsEnabled(); }

  static void SetWebGLImageChromiumEnabled(bool enabled) { is_webgl_image_chromium_enabled_ = enabled; }
  static bool WebGLImageChromiumEnabled() {
    return is_webgl_image_chromium_enabled_;
  }
  static bool WebGLImageChromiumEnabled(const FeatureContext*) { return WebGLImageChromiumEnabled(); }

  static void SetWebGPUEnabled(bool enabled) { is_webgpu_enabled_ = enabled; }
  static bool WebGPUEnabled() {
    return is_webgpu_enabled_;
  }
  static bool WebGPUEnabled(const FeatureContext*) { return WebGPUEnabled(); }

  static void SetWebHIDEnabled(bool enabled) { is_web_hid_enabled_ = enabled; }
  static bool WebHIDEnabled() {
    return is_web_hid_enabled_;
  }
  static bool WebHIDEnabled(const FeatureContext*) { return WebHIDEnabled(); }

  static void SetWebShareEnabled(bool enabled) { is_web_share_enabled_ = enabled; }
  static bool WebShareEnabled() {
    return is_web_share_enabled_;
  }
  static bool WebShareEnabled(const FeatureContext*) { return WebShareEnabled(); }

  static void SetWebShareV2Enabled(bool enabled) { is_web_share_v_2_enabled_ = enabled; }
  static bool WebShareV2Enabled() {
    if (!WebShareEnabled())
      return false;
    return is_web_share_v_2_enabled_;
  }
  static bool WebShareV2Enabled(const FeatureContext*) { return WebShareV2Enabled(); }

  static void SetWebSocketStreamEnabled(bool enabled) { is_websocket_stream_enabled_ = enabled; }
  static bool WebSocketStreamEnabled() {
    return is_websocket_stream_enabled_;
  }
  static bool WebSocketStreamEnabled(const FeatureContext*) { return WebSocketStreamEnabled(); }

  static void SetWebUSBEnabled(bool enabled) { is_web_usb_enabled_ = enabled; }
  static bool WebUSBEnabled() {
    return is_web_usb_enabled_;
  }
  static bool WebUSBEnabled(const FeatureContext*) { return WebUSBEnabled(); }

  static void SetWebUSBOnDedicatedWorkersEnabled(bool enabled) { is_web_usb_on_dedicated_workers_enabled_ = enabled; }
  static bool WebUSBOnDedicatedWorkersEnabled() {
    if (!WebUSBEnabled())
      return false;
    return is_web_usb_on_dedicated_workers_enabled_;
  }
  static bool WebUSBOnDedicatedWorkersEnabled(const FeatureContext*) { return WebUSBOnDedicatedWorkersEnabled(); }

  static void SetWebVTTRegionsEnabled(bool enabled) { is_web_vtt_regions_enabled_ = enabled; }
  static bool WebVTTRegionsEnabled() {
    return is_web_vtt_regions_enabled_;
  }
  static bool WebVTTRegionsEnabled(const FeatureContext*) { return WebVTTRegionsEnabled(); }

  static void SetWebXREnabled(bool enabled) { is_web_xr_enabled_ = enabled; }
  static bool WebXREnabled() {
    return is_web_xr_enabled_;
  }
  static bool WebXREnabled(const FeatureContext*) { return WebXREnabled(); }

  static void SetWebXRAnchorsEnabled(bool enabled) { is_web_xr_anchors_enabled_ = enabled; }
  static bool WebXRAnchorsEnabled() {
    if (!WebXRARModuleEnabled())
      return false;
    if (!WebXRHitTestEnabled())
      return false;
    return is_web_xr_anchors_enabled_;
  }
  static bool WebXRAnchorsEnabled(const FeatureContext*) { return WebXRAnchorsEnabled(); }

  static void SetWebXRARModuleEnabled(bool enabled) { is_web_xr_ar_module_enabled_ = enabled; }
  static bool WebXRARModuleEnabled() {
    if (!WebXREnabled())
      return false;
    return is_web_xr_ar_module_enabled_;
  }
  static bool WebXRARModuleEnabled(const FeatureContext*) { return WebXRARModuleEnabled(); }

  static void SetWebXRCameraAccessEnabled(bool enabled) { is_web_xr_camera_access_enabled_ = enabled; }
  static bool WebXRCameraAccessEnabled() {
    if (!WebXRARModuleEnabled())
      return false;
    return is_web_xr_camera_access_enabled_;
  }
  static bool WebXRCameraAccessEnabled(const FeatureContext*) { return WebXRCameraAccessEnabled(); }

  static void SetWebXRHitTestEnabled(bool enabled) { is_web_xr_hit_test_enabled_ = enabled; }
  static bool WebXRHitTestEnabled() {
    if (!WebXRARModuleEnabled())
      return false;
    return is_web_xr_hit_test_enabled_;
  }
  static bool WebXRHitTestEnabled(const FeatureContext*) { return WebXRHitTestEnabled(); }

  static void SetWebXRHitTestEntityTypesEnabled(bool enabled) { is_web_xr_hit_test_entity_types_enabled_ = enabled; }
  static bool WebXRHitTestEntityTypesEnabled() {
    if (!WebXRHitTestEnabled())
      return false;
    return is_web_xr_hit_test_entity_types_enabled_;
  }
  static bool WebXRHitTestEntityTypesEnabled(const FeatureContext*) { return WebXRHitTestEntityTypesEnabled(); }

  static void SetWebXRLightEstimationEnabled(bool enabled) { is_web_xr_light_estimation_enabled_ = enabled; }
  static bool WebXRLightEstimationEnabled() {
    if (!WebXRARModuleEnabled())
      return false;
    return is_web_xr_light_estimation_enabled_;
  }
  static bool WebXRLightEstimationEnabled(const FeatureContext*) { return WebXRLightEstimationEnabled(); }

  static void SetWebXRPlaneDetectionEnabled(bool enabled) { is_web_xr_plane_detection_enabled_ = enabled; }
  static bool WebXRPlaneDetectionEnabled() {
    if (!WebXRARModuleEnabled())
      return false;
    return is_web_xr_plane_detection_enabled_;
  }
  static bool WebXRPlaneDetectionEnabled(const FeatureContext*) { return WebXRPlaneDetectionEnabled(); }

  static void SetWindowPlacementEnabled(bool enabled) { is_window_placement_enabled_ = enabled; }
  static bool WindowPlacementEnabled() {
    return is_window_placement_enabled_;
  }
  static bool WindowPlacementEnabled(const FeatureContext*) { return WindowPlacementEnabled(); }

  static void SetWindowSegmentsEnabled(bool enabled) { is_window_segments_enabled_ = enabled; }
  static bool WindowSegmentsEnabled() {
    return is_window_segments_enabled_;
  }
  static bool WindowSegmentsEnabled(const FeatureContext*) { return WindowSegmentsEnabled(); }

  static void SetXSLTEnabled(bool enabled) { is_xslt_enabled_ = enabled; }
  static bool XSLTEnabled() {
    return is_xslt_enabled_;
  }
  static bool XSLTEnabled(const FeatureContext*) { return XSLTEnabled(); }


  // Origin-trial-enabled features:
  //
  // These features are currently part of an origin trial (see
  // https://www.chromium.org/blink/origin-trials). <feature>EnabledByRuntimeFlag()
  // can be used to test whether the feature is unconditionally enabled
  // (for example, by starting the browser with the appropriate command-line flag).
  // However, that is almost always the incorrect check. Most renderer code should
  // be calling <feature>Enabled(const FeatureContext*) instead, to test if the
  // feature is enabled in a given context.

  static void SetAllowSyncXHRInPageDismissalEnabled(bool enabled) { is_allow_sync_xhr_in_page_dismissal_enabled_ = enabled; }
  static bool AllowSyncXHRInPageDismissalEnabledByRuntimeFlag() { return AllowSyncXHRInPageDismissalEnabled(nullptr); }
  static bool AllowSyncXHRInPageDismissalEnabled(const FeatureContext*);

  static void SetAppCacheEnabled(bool enabled) { is_app_cache_enabled_ = enabled; }
  static bool AppCacheEnabledByRuntimeFlag() { return AppCacheEnabled(nullptr); }
  static bool AppCacheEnabled(const FeatureContext*);

  static void SetAutoPictureInPictureEnabled(bool enabled) { is_auto_picture_in_picture_enabled_ = enabled; }
  static bool AutoPictureInPictureEnabledByRuntimeFlag() { return AutoPictureInPictureEnabled(nullptr); }
  static bool AutoPictureInPictureEnabled(const FeatureContext*);

  static void SetCacheStorageCodeCacheHintEnabled(bool enabled) { is_cache_storage_code_cache_hint_enabled_ = enabled; }
  static bool CacheStorageCodeCacheHintEnabledByRuntimeFlag() { return CacheStorageCodeCacheHintEnabled(nullptr); }
  static bool CacheStorageCodeCacheHintEnabled(const FeatureContext*);

  static void SetCookieStoreDocumentEnabled(bool enabled) { is_cookie_store_document_enabled_ = enabled; }
  static bool CookieStoreDocumentEnabledByRuntimeFlag() { return CookieStoreDocumentEnabled(nullptr); }
  static bool CookieStoreDocumentEnabled(const FeatureContext*);

  static void SetCookieStoreWorkerEnabled(bool enabled) { is_cookie_store_worker_enabled_ = enabled; }
  static bool CookieStoreWorkerEnabledByRuntimeFlag() { return CookieStoreWorkerEnabled(nullptr); }
  static bool CookieStoreWorkerEnabled(const FeatureContext*);

  static void SetCustomElementsV0Enabled(bool enabled) { is_custom_elements_v0_enabled_ = enabled; }
  static bool CustomElementsV0EnabledByRuntimeFlag() { return CustomElementsV0Enabled(nullptr); }
  static bool CustomElementsV0Enabled(const FeatureContext*);

  static void SetDisableHardwareNoiseSuppressionEnabled(bool enabled) { is_disable_hardware_noise_suppression_enabled_ = enabled; }
  static bool DisableHardwareNoiseSuppressionEnabledByRuntimeFlag() { return DisableHardwareNoiseSuppressionEnabled(nullptr); }
  static bool DisableHardwareNoiseSuppressionEnabled(const FeatureContext*);

  static void SetDocumentPolicyEnabled(bool enabled) { is_document_policy_enabled_ = enabled; }
  static bool DocumentPolicyEnabledByRuntimeFlag() { return DocumentPolicyEnabled(nullptr); }
  static bool DocumentPolicyEnabled(const FeatureContext*);

  static void SetExperimentalAutoplayDynamicDelegationEnabled(bool enabled) { is_experimental_autoplay_dynamic_delegation_enabled_ = enabled; }
  static bool ExperimentalAutoplayDynamicDelegationEnabledByRuntimeFlag() { return ExperimentalAutoplayDynamicDelegationEnabled(nullptr); }
  static bool ExperimentalAutoplayDynamicDelegationEnabled(const FeatureContext*);

  static void SetExperimentalIsInputPendingEnabled(bool enabled) { is_experimental_is_input_pending_enabled_ = enabled; }
  static bool ExperimentalIsInputPendingEnabledByRuntimeFlag() { return ExperimentalIsInputPendingEnabled(nullptr); }
  static bool ExperimentalIsInputPendingEnabled(const FeatureContext*);

  static void SetExperimentalJSProfilerEnabled(bool enabled) { is_experimental_js_profiler_enabled_ = enabled; }
  static bool ExperimentalJSProfilerEnabledByRuntimeFlag() { return ExperimentalJSProfilerEnabled(nullptr); }
  static bool ExperimentalJSProfilerEnabled(const FeatureContext*);

  static void SetFeaturePolicyReportingEnabled(bool enabled) { is_feature_policy_reporting_enabled_ = enabled; }
  static bool FeaturePolicyReportingEnabledByRuntimeFlag() { return FeaturePolicyReportingEnabled(nullptr); }
  static bool FeaturePolicyReportingEnabled(const FeatureContext*);

  static void SetFileHandlingEnabled(bool enabled) { is_file_handling_enabled_ = enabled; }
  static bool FileHandlingEnabledByRuntimeFlag() { return FileHandlingEnabled(nullptr); }
  static bool FileHandlingEnabled(const FeatureContext*);

  static void SetForceLoadAtTopEnabled(bool enabled) { is_force_load_at_top_enabled_ = enabled; }
  static bool ForceLoadAtTopEnabledByRuntimeFlag() { return ForceLoadAtTopEnabled(nullptr); }
  static bool ForceLoadAtTopEnabled(const FeatureContext*);

  static void SetHrefTranslateEnabled(bool enabled) { is_href_translate_enabled_ = enabled; }
  static bool HrefTranslateEnabledByRuntimeFlag() { return HrefTranslateEnabled(nullptr); }
  static bool HrefTranslateEnabled(const FeatureContext*);

  static void SetHTMLImportsEnabled(bool enabled) { is_html_imports_enabled_ = enabled; }
  static bool HTMLImportsEnabledByRuntimeFlag() { return HTMLImportsEnabled(nullptr); }
  static bool HTMLImportsEnabled(const FeatureContext*);

  static void SetIdleDetectionEnabled(bool enabled) { is_idle_detection_enabled_ = enabled; }
  static bool IdleDetectionEnabledByRuntimeFlag() { return IdleDetectionEnabled(nullptr); }
  static bool IdleDetectionEnabled(const FeatureContext*);

  static void SetLegacyNativeFileSystemEnabled(bool enabled) { is_legacy_native_file_system_enabled_ = enabled; }
  static bool LegacyNativeFileSystemEnabledByRuntimeFlag() { return LegacyNativeFileSystemEnabled(nullptr); }
  static bool LegacyNativeFileSystemEnabled(const FeatureContext*);

  static void SetMeasureMemoryEnabled(bool enabled) { is_measure_memory_enabled_ = enabled; }
  static bool MeasureMemoryEnabledByRuntimeFlag() { return MeasureMemoryEnabled(nullptr); }
  static bool MeasureMemoryEnabled(const FeatureContext*);

  static void SetNativeFileSystemEnabled(bool enabled) { is_native_file_system_enabled_ = enabled; }
  static bool NativeFileSystemEnabledByRuntimeFlag() { return NativeFileSystemEnabled(nullptr); }
  static bool NativeFileSystemEnabled(const FeatureContext*);

  static void SetNotificationTriggersEnabled(bool enabled) { is_notification_triggers_enabled_ = enabled; }
  static bool NotificationTriggersEnabledByRuntimeFlag() { return NotificationTriggersEnabled(nullptr); }
  static bool NotificationTriggersEnabled(const FeatureContext*);

  static void SetOriginIsolationHeaderEnabled(bool enabled) { is_origin_isolation_header_enabled_ = enabled; }
  static bool OriginIsolationHeaderEnabledByRuntimeFlag() { return OriginIsolationHeaderEnabled(nullptr); }
  static bool OriginIsolationHeaderEnabled(const FeatureContext*);

  static void SetOriginTrialsSampleAPIEnabled(bool enabled) { is_origin_trials_sample_api_enabled_ = enabled; }
  static bool OriginTrialsSampleAPIEnabledByRuntimeFlag() { return OriginTrialsSampleAPIEnabled(nullptr); }
  static bool OriginTrialsSampleAPIEnabled(const FeatureContext*);

  static void SetOriginTrialsSampleAPIDependentEnabled(bool enabled) { is_origin_trials_sample_api_dependent_enabled_ = enabled; }
  static bool OriginTrialsSampleAPIDependentEnabledByRuntimeFlag() { return OriginTrialsSampleAPIDependentEnabled(nullptr); }
  static bool OriginTrialsSampleAPIDependentEnabled(const FeatureContext*);

  static void SetOriginTrialsSampleAPIDeprecationEnabled(bool enabled) { is_origin_trials_sample_api_deprecation_enabled_ = enabled; }
  static bool OriginTrialsSampleAPIDeprecationEnabledByRuntimeFlag() { return OriginTrialsSampleAPIDeprecationEnabled(nullptr); }
  static bool OriginTrialsSampleAPIDeprecationEnabled(const FeatureContext*);

  static void SetOriginTrialsSampleAPIImpliedEnabled(bool enabled) { is_origin_trials_sample_api_implied_enabled_ = enabled; }
  static bool OriginTrialsSampleAPIImpliedEnabledByRuntimeFlag() { return OriginTrialsSampleAPIImpliedEnabled(nullptr); }
  static bool OriginTrialsSampleAPIImpliedEnabled(const FeatureContext*);

  static void SetOriginTrialsSampleAPIInvalidOSEnabled(bool enabled) { is_origin_trials_sample_api_invalid_os_enabled_ = enabled; }
  static bool OriginTrialsSampleAPIInvalidOSEnabledByRuntimeFlag() { return OriginTrialsSampleAPIInvalidOSEnabled(nullptr); }
  static bool OriginTrialsSampleAPIInvalidOSEnabled(const FeatureContext*);

  static void SetOriginTrialsSampleAPINavigationEnabled(bool enabled) { is_origin_trials_sample_api_navigation_enabled_ = enabled; }
  static bool OriginTrialsSampleAPINavigationEnabledByRuntimeFlag() { return OriginTrialsSampleAPINavigationEnabled(nullptr); }
  static bool OriginTrialsSampleAPINavigationEnabled(const FeatureContext*);

  static void SetOriginTrialsSampleAPIThirdPartyEnabled(bool enabled) { is_origin_trials_sample_api_third_party_enabled_ = enabled; }
  static bool OriginTrialsSampleAPIThirdPartyEnabledByRuntimeFlag() { return OriginTrialsSampleAPIThirdPartyEnabled(nullptr); }
  static bool OriginTrialsSampleAPIThirdPartyEnabled(const FeatureContext*);

  static void SetPageFreezeOptInEnabled(bool enabled) { is_page_freeze_opt_in_enabled_ = enabled; }
  static bool PageFreezeOptInEnabledByRuntimeFlag() { return PageFreezeOptInEnabled(nullptr); }
  static bool PageFreezeOptInEnabled(const FeatureContext*);

  static void SetPageFreezeOptOutEnabled(bool enabled) { is_page_freeze_opt_out_enabled_ = enabled; }
  static bool PageFreezeOptOutEnabledByRuntimeFlag() { return PageFreezeOptOutEnabled(nullptr); }
  static bool PageFreezeOptOutEnabled(const FeatureContext*);

  static void SetPerMethodCanMakePaymentQuotaEnabled(bool enabled) { is_per_method_can_make_payment_quota_enabled_ = enabled; }
  static bool PerMethodCanMakePaymentQuotaEnabledByRuntimeFlag() { return PerMethodCanMakePaymentQuotaEnabled(nullptr); }
  static bool PerMethodCanMakePaymentQuotaEnabled(const FeatureContext*);

  static void SetPNaClEnabled(bool enabled) { is_p_na_cl_enabled_ = enabled; }
  static bool PNaClEnabledByRuntimeFlag() { return PNaClEnabled(nullptr); }
  static bool PNaClEnabled(const FeatureContext*);

  static void SetPointerLockOptionsEnabled(bool enabled) { is_pointer_lock_options_enabled_ = enabled; }
  static bool PointerLockOptionsEnabledByRuntimeFlag() { return PointerLockOptionsEnabled(nullptr); }
  static bool PointerLockOptionsEnabled(const FeatureContext*);

  static void SetPortalsEnabled(bool enabled) { is_portals_enabled_ = enabled; }
  static bool PortalsEnabledByRuntimeFlag() { return PortalsEnabled(nullptr); }
  static bool PortalsEnabled(const FeatureContext*);

  static void SetPriorityHintsEnabled(bool enabled) { is_priority_hints_enabled_ = enabled; }
  static bool PriorityHintsEnabledByRuntimeFlag() { return PriorityHintsEnabled(nullptr); }
  static bool PriorityHintsEnabled(const FeatureContext*);

  static void SetQuicTransportEnabled(bool enabled) { is_quic_transport_enabled_ = enabled; }
  static bool QuicTransportEnabledByRuntimeFlag() { return QuicTransportEnabled(nullptr); }
  static bool QuicTransportEnabled(const FeatureContext*);

  static void SetRtcAudioJitterBufferMaxPacketsEnabled(bool enabled) { is_rtc_audio_jitter_buffer_max_packets_enabled_ = enabled; }
  static bool RtcAudioJitterBufferMaxPacketsEnabledByRuntimeFlag() { return RtcAudioJitterBufferMaxPacketsEnabled(nullptr); }
  static bool RtcAudioJitterBufferMaxPacketsEnabled(const FeatureContext*);

  static void SetRtcAudioJitterBufferRtxHandlingEnabled(bool enabled) { is_rtc_audio_jitter_buffer_rtx_handling_enabled_ = enabled; }
  static bool RtcAudioJitterBufferRtxHandlingEnabledByRuntimeFlag() { return RtcAudioJitterBufferRtxHandlingEnabled(nullptr); }
  static bool RtcAudioJitterBufferRtxHandlingEnabled(const FeatureContext*);

  static void SetRTCIceTransportExtensionEnabled(bool enabled) { is_rtc_ice_transport_extension_enabled_ = enabled; }
  static bool RTCIceTransportExtensionEnabledByRuntimeFlag() { return RTCIceTransportExtensionEnabled(nullptr); }
  static bool RTCIceTransportExtensionEnabled(const FeatureContext*);

  static void SetRTCInsertableStreamsEnabled(bool enabled) { is_rtc_insertable_streams_enabled_ = enabled; }
  static bool RTCInsertableStreamsEnabledByRuntimeFlag() { return RTCInsertableStreamsEnabled(nullptr); }
  static bool RTCInsertableStreamsEnabled(const FeatureContext*);

  static void SetRTCQuicTransportEnabled(bool enabled) { is_rtc_quic_transport_enabled_ = enabled; }
  static bool RTCQuicTransportEnabledByRuntimeFlag() { return RTCQuicTransportEnabled(nullptr); }
  static bool RTCQuicTransportEnabled(const FeatureContext*);

  static void SetRTCStatsRelativePacketArrivalDelayEnabled(bool enabled) { is_rtc_stats_relative_packet_arrival_delay_enabled_ = enabled; }
  static bool RTCStatsRelativePacketArrivalDelayEnabledByRuntimeFlag() { return RTCStatsRelativePacketArrivalDelayEnabled(nullptr); }
  static bool RTCStatsRelativePacketArrivalDelayEnabled(const FeatureContext*);

  static void SetSerialEnabled(bool enabled) { is_serial_enabled_ = enabled; }
  static bool SerialEnabledByRuntimeFlag() { return SerialEnabled(nullptr); }
  static bool SerialEnabled(const FeatureContext*);

  static void SetShadowDOMV0Enabled(bool enabled) { is_shadow_dom_v0_enabled_ = enabled; }
  static bool ShadowDOMV0EnabledByRuntimeFlag() { return ShadowDOMV0Enabled(nullptr); }
  static bool ShadowDOMV0Enabled(const FeatureContext*);

  static void SetSignatureBasedIntegrityEnabled(bool enabled) { is_signature_based_integrity_enabled_ = enabled; }
  static bool SignatureBasedIntegrityEnabledByRuntimeFlag() { return SignatureBasedIntegrityEnabled(nullptr); }
  static bool SignatureBasedIntegrityEnabled(const FeatureContext*);

  static void SetSignedExchangeSubresourcePrefetchEnabled(bool enabled) { is_signed_exchange_subresource_prefetch_enabled_ = enabled; }
  static bool SignedExchangeSubresourcePrefetchEnabledByRuntimeFlag() { return SignedExchangeSubresourcePrefetchEnabled(nullptr); }
  static bool SignedExchangeSubresourcePrefetchEnabled(const FeatureContext*);

  static void SetSkipAdEnabled(bool enabled) { is_skip_ad_enabled_ = enabled; }
  static bool SkipAdEnabledByRuntimeFlag() { return SkipAdEnabled(nullptr); }
  static bool SkipAdEnabled(const FeatureContext*);

  static void SetTextFragmentIdentifiersEnabled(bool enabled) { is_text_fragment_identifiers_enabled_ = enabled; }
  static bool TextFragmentIdentifiersEnabledByRuntimeFlag() { return TextFragmentIdentifiersEnabled(nullptr); }
  static bool TextFragmentIdentifiersEnabled(const FeatureContext*);

  static void SetTouchEventFeatureDetectionEnabled(bool enabled) { is_touch_event_feature_detection_enabled_ = enabled; }
  static bool TouchEventFeatureDetectionEnabledByRuntimeFlag() { return TouchEventFeatureDetectionEnabled(nullptr); }
  static bool TouchEventFeatureDetectionEnabled(const FeatureContext*);

  static void SetTransferableStreamsEnabled(bool enabled) { is_transferable_streams_enabled_ = enabled; }
  static bool TransferableStreamsEnabledByRuntimeFlag() { return TransferableStreamsEnabled(nullptr); }
  static bool TransferableStreamsEnabled(const FeatureContext*);

  static void SetTrustTokensEnabled(bool enabled) { is_trust_tokens_enabled_ = enabled; }
  static bool TrustTokensEnabledByRuntimeFlag() { return TrustTokensEnabled(nullptr); }
  static bool TrustTokensEnabled(const FeatureContext*);

  static void SetUnoptimizedImagePoliciesEnabled(bool enabled) { is_unoptimized_image_policies_enabled_ = enabled; }
  static bool UnoptimizedImagePoliciesEnabledByRuntimeFlag() { return UnoptimizedImagePoliciesEnabled(nullptr); }
  static bool UnoptimizedImagePoliciesEnabled(const FeatureContext*);

  static void SetUnsizedMediaPolicyEnabled(bool enabled) { is_unsized_media_policy_enabled_ = enabled; }
  static bool UnsizedMediaPolicyEnabledByRuntimeFlag() { return UnsizedMediaPolicyEnabled(nullptr); }
  static bool UnsizedMediaPolicyEnabled(const FeatureContext*);

  static void SetWakeLockEnabled(bool enabled) { is_wake_lock_enabled_ = enabled; }
  static bool WakeLockEnabledByRuntimeFlag() { return WakeLockEnabled(nullptr); }
  static bool WakeLockEnabled(const FeatureContext*);

  static void SetWebAssemblySimdEnabled(bool enabled) { is_web_assembly_simd_enabled_ = enabled; }
  static bool WebAssemblySimdEnabledByRuntimeFlag() { return WebAssemblySimdEnabled(nullptr); }
  static bool WebAssemblySimdEnabled(const FeatureContext*);

  static void SetWebAssemblyThreadsEnabled(bool enabled) { is_web_assembly_threads_enabled_ = enabled; }
  static bool WebAssemblyThreadsEnabledByRuntimeFlag() { return WebAssemblyThreadsEnabled(nullptr); }
  static bool WebAssemblyThreadsEnabled(const FeatureContext*);

  static void SetWebNFCEnabled(bool enabled) { is_web_nfc_enabled_ = enabled; }
  static bool WebNFCEnabledByRuntimeFlag() { return WebNFCEnabled(nullptr); }
  static bool WebNFCEnabled(const FeatureContext*);

  static void SetWebSchedulerEnabled(bool enabled) { is_web_scheduler_enabled_ = enabled; }
  static bool WebSchedulerEnabledByRuntimeFlag() { return WebSchedulerEnabled(nullptr); }
  static bool WebSchedulerEnabled(const FeatureContext*);


 private:
  friend class RuntimeEnabledFeaturesTestHelpers;

  static bool is_accelerated_2d_canvas_enabled_;
  static bool is_accelerated_small_canvases_enabled_;
  static bool is_accessibility_expose_aria_annotations_enabled_;
  static bool is_accessibility_expose_display_none_enabled_;
  static bool is_accessibility_expose_html_element_enabled_;
  static bool is_accessibility_object_model_enabled_;
  static bool is_address_space_enabled_;
  static bool is_ad_tagging_enabled_;
  static bool is_allow_activation_delegation_attr_enabled_;
  static bool is_allow_content_initiated_data_url_navigations_enabled_;
  static bool is_allow_sync_xhr_in_page_dismissal_enabled_;
  static bool is_animation_worklet_enabled_;
  static bool is_aom_aria_properties_enabled_;
  static bool is_aom_aria_relationship_properties_enabled_;
  static bool is_app_cache_enabled_;
  static bool is_audio_output_devices_enabled_;
  static bool is_audio_video_tracks_enabled_;
  static bool is_audio_worklet_realtime_thread_enabled_;
  static bool is_auto_lazy_load_on_reloads_enabled_;
  static bool is_automatic_lazy_frame_loading_enabled_;
  static bool is_automatic_lazy_image_loading_enabled_;
  static bool is_automation_controlled_enabled_;
  static bool is_auto_picture_in_picture_enabled_;
  static bool is_autoplay_ignores_web_audio_enabled_;
  static bool is_back_forward_cache_enabled_;
  static bool is_background_fetch_enabled_;
  static bool is_background_video_track_optimization_enabled_;
  static bool is_badging_enabled_;
  static bool is_barcode_detector_enabled_;
  static bool is_before_match_event_enabled_;
  static bool is_bidi_caret_affinity_enabled_;
  static bool is_blink_runtime_call_stats_enabled_;
  static bool is_block_credentialed_subresources_enabled_;
  static bool is_block_flow_handles_webkit_line_clamp_enabled_;
  static bool is_block_html_parser_on_style_sheets_enabled_;
  static bool is_blocking_downloads_in_sandbox_enabled_;
  static bool is_blocking_focus_without_user_activation_enabled_;
  static bool is_browser_verified_user_activation_keyboard_enabled_;
  static bool is_browser_verified_user_activation_mouse_enabled_;
  static bool is_cache_inline_script_code_enabled_;
  static bool is_cache_storage_code_cache_hint_enabled_;
  static bool is_canvas_2d_context_lost_restored_enabled_;
  static bool is_canvas_2d_image_chromium_enabled_;
  static bool is_canvas_2d_scroll_path_into_view_enabled_;
  static bool is_canvas_color_management_enabled_;
  static bool is_canvas_hit_region_enabled_;
  static bool is_canvas_image_smoothing_enabled_;
  static bool is_capture_time_in_csrc_enabled_;
  static bool is_click_pointer_event_enabled_;
  static bool is_click_retargetting_enabled_;
  static bool is_composite_after_paint_enabled_;
  static bool is_composited_selection_update_enabled_;
  static bool is_computed_accessibility_info_enabled_;
  static bool is_consolidated_movement_xy_enabled_;
  static bool is_contacts_manager_enabled_;
  static bool is_contacts_manager_extra_properties_enabled_;
  static bool is_content_index_enabled_;
  static bool is_context_menu_enabled_;
  static bool is_conversion_measurement_enabled_;
  static bool is_cookie_deprecation_messages_enabled_;
  static bool is_cookie_store_document_enabled_;
  static bool is_cookie_store_worker_enabled_;
  static bool is_cookies_without_same_site_must_be_secure_enabled_;
  static bool is_cooperative_scheduling_enabled_;
  static bool is_cors_rfc_1918_enabled_;
  static bool is_cross_origin_isolation_enabled_;
  static bool is_css_3_text_enabled_;
  static bool is_css_aspect_ratio_property_enabled_;
  static bool is_css_calc_as_int_enabled_;
  static bool is_css_cascade_enabled_;
  static bool is_css_color_scheme_enabled_;
  static bool is_css_color_scheme_ua_rendering_enabled_;
  static bool is_css_content_visibility_enabled_;
  static bool is_css_content_visibility_hidden_matchable_enabled_;
  static bool is_css_focus_visible_enabled_;
  static bool is_css_foldables_enabled_;
  static bool is_css_font_size_adjust_enabled_;
  static bool is_css_hex_alpha_color_enabled_;
  static bool is_css_independent_transform_properties_enabled_;
  static bool is_css_layout_api_enabled_;
  static bool is_css_logical_enabled_;
  static bool is_css_logical_overflow_enabled_;
  static bool is_css_marker_nested_pseudo_element_enabled_;
  static bool is_css_marker_pseudo_element_enabled_;
  static bool is_css_matched_properties_cache_dependencies_enabled_;
  static bool is_css_math_style_enabled_;
  static bool is_css_math_superscript_shift_style_enabled_;
  static bool is_css_math_variant_enabled_;
  static bool is_css_modules_enabled_;
  static bool is_css_offset_path_ray_enabled_;
  static bool is_css_offset_path_ray_contain_enabled_;
  static bool is_css_offset_position_anchor_enabled_;
  static bool is_cssom_view_scroll_coordinates_enabled_;
  static bool is_css_paint_api_arguments_enabled_;
  static bool is_css_picture_in_picture_enabled_;
  static bool is_css_pseudo_is_enabled_;
  static bool is_css_pseudo_where_enabled_;
  static bool is_css_reduced_font_loading_invalidations_enabled_;
  static bool is_css_reduced_font_loading_layout_invalidations_enabled_;
  static bool is_css_revert_enabled_;
  static bool is_css_scroll_timeline_enabled_;
  static bool is_css_snap_size_enabled_;
  static bool is_css_supports_selector_enabled_;
  static bool is_css_variables_2_at_property_enabled_;
  static bool is_css_variables_2_image_values_enabled_;
  static bool is_css_variables_2_transform_values_enabled_;
  static bool is_custom_element_default_style_enabled_;
  static bool is_custom_elements_v0_enabled_;
  static bool is_custom_state_pseudo_class_enabled_;
  static bool is_database_enabled_;
  static bool is_declarative_shadow_dom_enabled_;
  static bool is_decode_jpeg_420_images_to_yuv_enabled_;
  static bool is_decode_lossy_web_p_images_to_yuv_enabled_;
  static bool is_delay_async_script_execution_until_finished_parsing_enabled_;
  static bool is_delay_async_script_execution_until_first_paint_or_finished_parsing_enabled_;
  static bool is_delegated_ink_trails_enabled_;
  static bool is_desktop_capture_disable_local_echo_control_enabled_;
  static bool is_digital_goods_enabled_;
  static bool is_disable_hardware_noise_suppression_enabled_;
  static bool is_disable_layer_squashing_enabled_;
  static bool is_disallow_document_access_enabled_;
  static bool is_display_cutout_api_enabled_;
  static bool is_document_cookie_enabled_;
  static bool is_document_domain_enabled_;
  static bool is_document_policy_enabled_;
  static bool is_document_write_enabled_;
  static bool is_edit_context_enabled_;
  static bool is_editing_ng_enabled_;
  static bool is_encrypted_media_encryption_scheme_query_enabled_;
  static bool is_encrypted_media_hdcp_policy_check_enabled_;
  static bool is_encrypted_media_persistent_usage_record_session_enabled_;
  static bool is_enter_key_hint_attribute_enabled_;
  static bool is_event_timing_enabled_;
  static bool is_exec_command_in_java_script_enabled_;
  static bool is_expensive_background_timer_throttling_enabled_;
  static bool is_experimental_autoplay_dynamic_delegation_enabled_;
  static bool is_experimental_content_security_policy_features_enabled_;
  static bool is_experimental_is_input_pending_enabled_;
  static bool is_experimental_js_profiler_enabled_;
  static bool is_experimental_productivity_features_enabled_;
  static bool is_extended_text_metrics_enabled_;
  static bool is_extra_webgl_video_texture_metadata_enabled_;
  static bool is_face_detector_enabled_;
  static bool is_feature_policy_for_client_hints_enabled_;
  static bool is_feature_policy_for_sandbox_enabled_;
  static bool is_feature_policy_reporting_enabled_;
  static bool is_feature_policy_vibrate_feature_enabled_;
  static bool is_fetch_upload_streaming_enabled_;
  static bool is_file_handling_enabled_;
  static bool is_file_system_enabled_;
  static bool is_flex_gaps_enabled_;
  static bool is_focusless_spatial_navigation_enabled_;
  static bool is_font_access_enabled_;
  static bool is_font_src_local_matching_enabled_;
  static bool is_forced_colors_enabled_;
  static bool is_force_defer_script_intervention_enabled_;
  static bool is_force_eager_measure_memory_enabled_;
  static bool is_force_load_at_top_enabled_;
  static bool is_force_overlay_fullscreen_video_enabled_;
  static bool is_force_synchronous_html_parsing_enabled_;
  static bool is_force_taller_select_popup_enabled_;
  static bool is_fractional_scroll_offsets_enabled_;
  static bool is_freeze_frames_on_visibility_enabled_;
  static bool is_gamepad_button_axis_events_enabled_;
  static bool is_get_display_media_enabled_;
  static bool is_group_effect_enabled_;
  static bool is_href_translate_enabled_;
  static bool is_html_imports_enabled_;
  static bool is_idb_observer_enabled_;
  static bool is_idb_relaxed_durability_enabled_;
  static bool is_idle_detection_enabled_;
  static bool is_ignore_cross_origin_window_when_named_access_on_window_enabled_;
  static bool is_image_orientation_enabled_;
  static bool is_implicit_root_scroller_enabled_;
  static bool is_import_maps_enabled_;
  static bool is_inert_attribute_enabled_;
  static bool is_input_element_raw_value_enabled_;
  static bool is_input_multiple_fields_ui_enabled_;
  static bool is_installed_app_enabled_;
  static bool is_intersection_observer_document_scrolling_element_root_enabled_;
  static bool is_isolated_code_cache_enabled_;
  static bool is_isolated_world_csp_enabled_;
  static bool is_keyboard_focusable_scrollers_enabled_;
  static bool is_lang_attribute_aware_form_control_ui_enabled_;
  static bool is_lang_client_hint_header_enabled_;
  static bool is_layout_ng_enabled_;
  static bool is_layout_ng_block_fragmentation_enabled_;
  static bool is_layout_ng_fieldset_enabled_;
  static bool is_layout_ng_flex_box_enabled_;
  static bool is_layout_ng_for_controls_enabled_;
  static bool is_layout_ng_fragment_item_enabled_;
  static bool is_layout_ng_fragment_traversal_enabled_;
  static bool is_layout_ng_grid_enabled_;
  static bool is_layout_ng_ruby_enabled_;
  static bool is_layout_ng_table_enabled_;
  static bool is_layout_shift_attribution_enabled_;
  static bool is_lazy_frame_loading_enabled_;
  static bool is_lazy_frame_visible_load_time_metrics_enabled_;
  static bool is_lazy_image_loading_enabled_;
  static bool is_lazy_image_visible_load_time_metrics_enabled_;
  static bool is_lazy_initialize_media_controls_enabled_;
  static bool is_legacy_native_file_system_enabled_;
  static bool is_legacy_windows_d_write_font_fallback_enabled_;
  static bool is_link_disabled_new_spec_behavior_enabled_;
  static bool is_manual_slotting_enabled_;
  static bool is_mathml_core_enabled_;
  static bool is_measure_memory_enabled_;
  static bool is_media_capabilities_dynamic_range_enabled_;
  static bool is_media_capabilities_encoding_info_enabled_;
  static bool is_media_capabilities_encrypted_media_enabled_;
  static bool is_media_capabilities_spatial_audio_enabled_;
  static bool is_media_capture_enabled_;
  static bool is_media_capture_depth_video_kind_enabled_;
  static bool is_media_capture_pan_tilt_enabled_;
  static bool is_media_cast_overlay_button_enabled_;
  static bool is_media_controls_expand_gesture_enabled_;
  static bool is_media_controls_overlay_play_button_enabled_;
  static bool is_media_controls_use_cut_out_by_default_enabled_;
  static bool is_media_document_download_button_enabled_;
  static bool is_media_element_volume_greater_than_one_enabled_;
  static bool is_media_engagement_bypass_autoplay_policies_enabled_;
  static bool is_media_feeds_enabled_;
  static bool is_media_latency_hint_enabled_;
  static bool is_media_query_navigation_controls_enabled_;
  static bool is_media_session_enabled_;
  static bool is_media_session_position_enabled_;
  static bool is_media_source_experimental_enabled_;
  static bool is_media_source_in_workers_enabled_;
  static bool is_media_source_new_abort_and_duration_enabled_;
  static bool is_media_source_stable_enabled_;
  static bool is_meta_color_scheme_enabled_;
  static bool is_middle_click_autoscroll_enabled_;
  static bool is_mobile_layout_theme_enabled_;
  static bool is_module_service_worker_enabled_;
  static bool is_module_shared_worker_enabled_;
  static bool is_mojo_js_enabled_;
  static bool is_mojo_js_test_enabled_;
  static bool is_mouse_subframe_no_implicit_capture_enabled_;
  static bool is_named_pages_enabled_;
  static bool is_native_file_system_enabled_;
  static bool is_native_io_enabled_;
  static bool is_navigator_content_utils_enabled_;
  static bool is_navigator_language_in_insecure_context_enabled_;
  static bool is_net_info_downlink_max_enabled_;
  static bool is_never_slow_mode_enabled_;
  static bool is_new_canvas_2d_api_enabled_;
  static bool is_new_remote_playback_pipeline_enabled_;
  static bool is_no_idle_encoding_for_web_tests_enabled_;
  static bool is_notification_constructor_enabled_;
  static bool is_notification_content_image_enabled_;
  static bool is_notifications_enabled_;
  static bool is_notification_triggers_enabled_;
  static bool is_off_main_thread_css_paint_enabled_;
  static bool is_offscreen_canvas_commit_enabled_;
  static bool is_on_device_change_enabled_;
  static bool is_orientation_event_enabled_;
  static bool is_origin_isolation_header_enabled_;
  static bool is_origin_policy_enabled_;
  static bool is_origin_trials_sample_api_enabled_;
  static bool is_origin_trials_sample_api_dependent_enabled_;
  static bool is_origin_trials_sample_api_deprecation_enabled_;
  static bool is_origin_trials_sample_api_implied_enabled_;
  static bool is_origin_trials_sample_api_invalid_os_enabled_;
  static bool is_origin_trials_sample_api_navigation_enabled_;
  static bool is_origin_trials_sample_api_third_party_enabled_;
  static bool is_out_of_blink_cors_enabled_;
  static bool is_overflow_icons_for_media_controls_enabled_;
  static bool is_overscroll_customization_enabled_;
  static bool is_page_freeze_opt_in_enabled_;
  static bool is_page_freeze_opt_out_enabled_;
  static bool is_page_popup_enabled_;
  static bool is_paint_under_invalidation_checking_enabled_;
  static bool is_parse_url_protocol_handler_enabled_;
  static bool is_pass_paint_visual_rect_to_compositor_enabled_;
  static bool is_password_reveal_enabled_;
  static bool is_payment_app_enabled_;
  static bool is_payment_handler_change_payment_method_enabled_;
  static bool is_payment_handler_handles_shipping_and_contact_enabled_;
  static bool is_payment_handler_minimal_ui_enabled_;
  static bool is_payment_method_change_event_enabled_;
  static bool is_payment_request_enabled_;
  static bool is_payment_request_merchant_validation_event_enabled_;
  static bool is_payment_retry_enabled_;
  static bool is_percent_based_scrolling_enabled_;
  static bool is_performance_manager_instrumentation_enabled_;
  static bool is_periodic_background_sync_enabled_;
  static bool is_per_method_can_make_payment_quota_enabled_;
  static bool is_permission_delegation_enabled_;
  static bool is_permissions_enabled_;
  static bool is_permissions_request_revoke_enabled_;
  static bool is_picture_in_picture_enabled_;
  static bool is_picture_in_picture_api_enabled_;
  static bool is_picture_in_picture_v_2_enabled_;
  static bool is_p_na_cl_enabled_;
  static bool is_pointer_lock_options_enabled_;
  static bool is_pointer_raw_update_enabled_;
  static bool is_portals_enabled_;
  static bool is_post_animation_frame_enabled_;
  static bool is_precise_memory_info_enabled_;
  static bool is_prefer_non_composited_scrolling_enabled_;
  static bool is_prefers_reduced_data_enabled_;
  static bool is_prefixed_video_fullscreen_enabled_;
  static bool is_presentation_enabled_;
  static bool is_priority_hints_enabled_;
  static bool is_push_messaging_enabled_;
  static bool is_push_messaging_subscription_change_enabled_;
  static bool is_quic_transport_enabled_;
  static bool is_raw_clipboard_enabled_;
  static bool is_reduced_referrer_granularity_enabled_;
  static bool is_remote_playback_enabled_;
  static bool is_remote_playback_backend_enabled_;
  static bool is_request_video_frame_callback_enabled_;
  static bool is_resize_observer_updates_enabled_;
  static bool is_restrict_app_cache_to_secure_contexts_enabled_;
  static bool is_restrict_automatic_lazy_frame_loading_to_data_saver_enabled_;
  static bool is_restrict_automatic_lazy_image_loading_to_data_saver_enabled_;
  static bool is_rtc_audio_jitter_buffer_max_packets_enabled_;
  static bool is_rtc_audio_jitter_buffer_rtx_handling_enabled_;
  static bool is_rtc_ice_transport_extension_enabled_;
  static bool is_rtc_insertable_streams_enabled_;
  static bool is_rtc_quic_transport_enabled_;
  static bool is_rtc_stats_relative_packet_arrival_delay_enabled_;
  static bool is_rtc_svc_scalability_mode_enabled_;
  static bool is_rtc_unified_plan_enabled_;
  static bool is_rtc_unified_plan_by_default_enabled_;
  static bool is_same_site_by_default_cookies_enabled_;
  static bool is_screen_wake_lock_enabled_;
  static bool is_scripted_speech_recognition_enabled_;
  static bool is_scripted_speech_synthesis_enabled_;
  static bool is_scroll_customization_enabled_;
  static bool is_scroll_snap_after_layout_enabled_;
  static bool is_scroll_timeline_enabled_;
  static bool is_scroll_top_left_interop_enabled_;
  static bool is_scroll_unification_enabled_;
  static bool is_send_beacon_throw_for_blob_with_non_simple_type_enabled_;
  static bool is_send_mouse_events_disabled_form_controls_enabled_;
  static bool is_sensor_extra_classes_enabled_;
  static bool is_serial_enabled_;
  static bool is_service_worker_client_lifecycle_state_enabled_;
  static bool is_service_worker_fetch_event_worker_timing_enabled_;
  static bool is_shadow_dom_v0_enabled_;
  static bool is_shared_array_buffer_enabled_;
  static bool is_shared_worker_enabled_;
  static bool is_signature_based_integrity_enabled_;
  static bool is_signed_exchange_prefetch_cache_for_navigations_enabled_;
  static bool is_signed_exchange_subresource_prefetch_enabled_;
  static bool is_skip_ad_enabled_;
  static bool is_skip_touch_event_filter_enabled_;
  static bool is_sms_receiver_enabled_;
  static bool is_squash_after_paint_enabled_;
  static bool is_stable_blink_features_enabled_;
  static bool is_storage_access_api_enabled_;
  static bool is_strict_mime_types_for_workers_enabled_;
  static bool is_subresource_web_bundles_enabled_;
  static bool is_surface_embedding_features_enabled_;
  static bool is_system_wake_lock_enabled_;
  static bool is_test_feature_enabled_;
  static bool is_test_feature_dependent_enabled_;
  static bool is_test_feature_implied_enabled_;
  static bool is_text_detector_enabled_;
  static bool is_text_fragment_identifiers_enabled_;
  static bool is_third_party_origin_trials_enabled_;
  static bool is_timer_throttling_for_background_tabs_enabled_;
  static bool is_timer_throttling_for_hidden_frames_enabled_;
  static bool is_time_zone_change_event_enabled_;
  static bool is_touch_event_feature_detection_enabled_;
  static bool is_track_layout_passes_per_block_enabled_;
  static bool is_transferable_streams_enabled_;
  static bool is_transform_interop_enabled_;
  static bool is_translate_service_enabled_;
  static bool is_trusted_dom_types_enabled_;
  static bool is_trust_tokens_enabled_;
  static bool is_trust_tokens_always_allow_issuance_enabled_;
  static bool is_unclosed_form_control_is_invalid_enabled_;
  static bool is_underline_offset_thickness_enabled_;
  static bool is_unoptimized_image_policies_enabled_;
  static bool is_unsized_media_policy_enabled_;
  static bool is_user_activation_post_message_transfer_enabled_;
  static bool is_user_activation_same_origin_visibility_enabled_;
  static bool is_user_agent_client_hint_enabled_;
  static bool is_v8_idle_tasks_enabled_;
  static bool is_video_auto_fullscreen_enabled_;
  static bool is_video_fullscreen_orientation_lock_enabled_;
  static bool is_video_playback_quality_enabled_;
  static bool is_video_rotate_to_fullscreen_enabled_;
  static bool is_video_wake_lock_optimisation_hidden_muted_enabled_;
  static bool is_virtual_keyboard_enabled_;
  static bool is_visibility_collapse_column_enabled_;
  static bool is_wake_lock_enabled_;
  static bool is_web_animations_api_enabled_;
  static bool is_web_animations_svg_enabled_;
  static bool is_web_assembly_simd_enabled_;
  static bool is_web_assembly_threads_enabled_;
  static bool is_web_auth_enabled_;
  static bool is_web_authentication_get_assertion_feature_policy_enabled_;
  static bool is_web_bluetooth_enabled_;
  static bool is_web_bluetooth_get_devices_enabled_;
  static bool is_web_bluetooth_remote_characteristic_new_write_value_enabled_;
  static bool is_web_bluetooth_scanning_enabled_;
  static bool is_web_bluetooth_watch_advertisements_enabled_;
  static bool is_web_codecs_enabled_;
  static bool is_web_crypto_curve_25519_enabled_;
  static bool is_webgl2_compute_context_enabled_;
  static bool is_webgl_draft_extensions_enabled_;
  static bool is_webgl_image_chromium_enabled_;
  static bool is_webgpu_enabled_;
  static bool is_web_hid_enabled_;
  static bool is_web_nfc_enabled_;
  static bool is_web_scheduler_enabled_;
  static bool is_web_share_enabled_;
  static bool is_web_share_v_2_enabled_;
  static bool is_websocket_stream_enabled_;
  static bool is_web_usb_enabled_;
  static bool is_web_usb_on_dedicated_workers_enabled_;
  static bool is_web_vtt_regions_enabled_;
  static bool is_web_xr_enabled_;
  static bool is_web_xr_anchors_enabled_;
  static bool is_web_xr_ar_module_enabled_;
  static bool is_web_xr_camera_access_enabled_;
  static bool is_web_xr_hit_test_enabled_;
  static bool is_web_xr_hit_test_entity_types_enabled_;
  static bool is_web_xr_light_estimation_enabled_;
  static bool is_web_xr_plane_detection_enabled_;
  static bool is_window_placement_enabled_;
  static bool is_window_segments_enabled_;
  static bool is_xslt_enabled_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_
