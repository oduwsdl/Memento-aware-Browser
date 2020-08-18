// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_PAGE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_PAGE_H_

#include "base/values.h"

namespace headless {

namespace page {
class Frame;
class FrameResource;
class FrameResourceTree;
class FrameTree;
class NavigationEntry;
class ScreencastFrameMetadata;
class AppManifestError;
class AppManifestParsedProperties;
class LayoutViewport;
class VisualViewport;
class Viewport;
class FontFamilies;
class FontSizes;
class InstallabilityErrorArgument;
class InstallabilityError;
class AddScriptToEvaluateOnLoadParams;
class AddScriptToEvaluateOnLoadResult;
class AddScriptToEvaluateOnNewDocumentParams;
class AddScriptToEvaluateOnNewDocumentResult;
class BringToFrontParams;
class BringToFrontResult;
class CaptureScreenshotParams;
class CaptureScreenshotResult;
class CaptureSnapshotParams;
class CaptureSnapshotResult;
class ClearDeviceMetricsOverrideParams;
class ClearDeviceMetricsOverrideResult;
class ClearDeviceOrientationOverrideParams;
class ClearDeviceOrientationOverrideResult;
class ClearGeolocationOverrideParams;
class ClearGeolocationOverrideResult;
class CreateIsolatedWorldParams;
class CreateIsolatedWorldResult;
class DeleteCookieParams;
class DeleteCookieResult;
class DisableParams;
class DisableResult;
class EnableParams;
class EnableResult;
class GetAppManifestParams;
class GetAppManifestResult;
class GetInstallabilityErrorsParams;
class GetInstallabilityErrorsResult;
class GetManifestIconsParams;
class GetManifestIconsResult;
class GetCookiesParams;
class GetCookiesResult;
class GetFrameTreeParams;
class GetFrameTreeResult;
class GetLayoutMetricsParams;
class GetLayoutMetricsResult;
class GetNavigationHistoryParams;
class GetNavigationHistoryResult;
class ResetNavigationHistoryParams;
class ResetNavigationHistoryResult;
class GetResourceContentParams;
class GetResourceContentResult;
class GetResourceTreeParams;
class GetResourceTreeResult;
class HandleJavaScriptDialogParams;
class HandleJavaScriptDialogResult;
class NavigateParams;
class NavigateResult;
class NavigateToHistoryEntryParams;
class NavigateToHistoryEntryResult;
class PrintToPDFParams;
class PrintToPDFResult;
class ReloadParams;
class ReloadResult;
class RemoveScriptToEvaluateOnLoadParams;
class RemoveScriptToEvaluateOnLoadResult;
class RemoveScriptToEvaluateOnNewDocumentParams;
class RemoveScriptToEvaluateOnNewDocumentResult;
class ScreencastFrameAckParams;
class ScreencastFrameAckResult;
class SearchInResourceParams;
class SearchInResourceResult;
class SetAdBlockingEnabledParams;
class SetAdBlockingEnabledResult;
class SetBypassCSPParams;
class SetBypassCSPResult;
class SetDeviceMetricsOverrideParams;
class SetDeviceMetricsOverrideResult;
class SetDeviceOrientationOverrideParams;
class SetDeviceOrientationOverrideResult;
class SetFontFamiliesParams;
class SetFontFamiliesResult;
class SetFontSizesParams;
class SetFontSizesResult;
class SetDocumentContentParams;
class SetDocumentContentResult;
class SetDownloadBehaviorParams;
class SetDownloadBehaviorResult;
class SetGeolocationOverrideParams;
class SetGeolocationOverrideResult;
class SetLifecycleEventsEnabledParams;
class SetLifecycleEventsEnabledResult;
class SetTouchEmulationEnabledParams;
class SetTouchEmulationEnabledResult;
class StartScreencastParams;
class StartScreencastResult;
class StopLoadingParams;
class StopLoadingResult;
class CrashParams;
class CrashResult;
class CloseParams;
class CloseResult;
class SetWebLifecycleStateParams;
class SetWebLifecycleStateResult;
class StopScreencastParams;
class StopScreencastResult;
class SetProduceCompilationCacheParams;
class SetProduceCompilationCacheResult;
class AddCompilationCacheParams;
class AddCompilationCacheResult;
class ClearCompilationCacheParams;
class ClearCompilationCacheResult;
class GenerateTestReportParams;
class GenerateTestReportResult;
class WaitForDebuggerParams;
class WaitForDebuggerResult;
class SetInterceptFileChooserDialogParams;
class SetInterceptFileChooserDialogResult;
class DomContentEventFiredParams;
class FileChooserOpenedParams;
class FrameAttachedParams;
class FrameClearedScheduledNavigationParams;
class FrameDetachedParams;
class FrameNavigatedParams;
class FrameResizedParams;
class FrameRequestedNavigationParams;
class FrameScheduledNavigationParams;
class FrameStartedLoadingParams;
class FrameStoppedLoadingParams;
class DownloadWillBeginParams;
class DownloadProgressParams;
class InterstitialHiddenParams;
class InterstitialShownParams;
class JavascriptDialogClosedParams;
class JavascriptDialogOpeningParams;
class LifecycleEventParams;
class LoadEventFiredParams;
class NavigatedWithinDocumentParams;
class ScreencastFrameParams;
class ScreencastVisibilityChangedParams;
class WindowOpenParams;
class CompilationCacheProducedParams;

enum class TransitionType {
  LINK,
  TYPED,
  ADDRESS_BAR,
  AUTO_BOOKMARK,
  AUTO_SUBFRAME,
  MANUAL_SUBFRAME,
  GENERATED,
  AUTO_TOPLEVEL,
  FORM_SUBMIT,
  RELOAD,
  KEYWORD,
  KEYWORD_GENERATED,
  OTHER
};

enum class DialogType {
  ALERT,
  CONFIRM,
  PROMPT,
  BEFOREUNLOAD
};

enum class ClientNavigationReason {
  FORM_SUBMISSION_GET,
  FORM_SUBMISSION_POST,
  HTTP_HEADER_REFRESH,
  SCRIPT_INITIATED,
  META_TAG_REFRESH,
  PAGE_BLOCK_INTERSTITIAL,
  RELOAD,
  ANCHOR_CLICK
};

enum class ClientNavigationDisposition {
  CURRENT_TAB,
  NEW_TAB,
  NEW_WINDOW,
  DOWNLOAD
};

enum class ReferrerPolicy {
  NO_REFERRER,
  NO_REFERRER_WHEN_DOWNGRADE,
  ORIGIN,
  ORIGIN_WHEN_CROSS_ORIGIN,
  SAME_ORIGIN,
  STRICT_ORIGIN,
  STRICT_ORIGIN_WHEN_CROSS_ORIGIN,
  UNSAFE_URL
};

enum class CaptureScreenshotFormat {
  JPEG,
  PNG
};

enum class CaptureSnapshotFormat {
  MHTML
};

enum class PrintToPDFTransferMode {
  RETURN_AS_BASE64,
  RETURN_AS_STREAM
};

enum class SetDownloadBehaviorBehavior {
  DENY,
  ALLOW,
  DEFAULT
};

enum class SetTouchEmulationEnabledConfiguration {
  MOBILE,
  DESKTOP
};

enum class StartScreencastFormat {
  JPEG,
  PNG
};

enum class SetWebLifecycleStateState {
  FROZEN,
  ACTIVE
};

enum class FileChooserOpenedMode {
  SELECT_SINGLE,
  SELECT_MULTIPLE
};

enum class DownloadProgressState {
  IN_PROGRESS,
  COMPLETED,
  CANCELED
};

}  // namespace page

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_PAGE_H_
