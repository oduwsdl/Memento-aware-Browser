/**
 * @implements {ProtocolProxyApiWorkaround_PageDispatcher}
 */
export class ScreenCaptureModel extends SDKModel implements ProtocolProxyApiWorkaround_PageDispatcher {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _agent: ProtocolProxyApi.PageApi;
    /** @type {?function(!Protocol.binary, !Protocol.Page.ScreencastFrameMetadata):void} */
    _onScreencastFrame: ((arg0: Protocol.binary, arg1: Protocol.Page.ScreencastFrameMetadata) => void) | null;
    /** @type {?function(boolean):void} */
    _onScreencastVisibilityChanged: ((arg0: boolean) => void) | null;
    /**
     * @return {!Protocol.UsesObjectNotation}
     */
    usesObjectNotation(): Protocol.UsesObjectNotation;
    /**
     * @param {!Protocol.Page.StartScreencastRequestFormat} format
     * @param {number} quality
     * @param {number|undefined} maxWidth
     * @param {number|undefined} maxHeight
     * @param {number|undefined} everyNthFrame
     * @param {function(!Protocol.binary, !Protocol.Page.ScreencastFrameMetadata): void} onFrame
     * @param {function(boolean): void} onVisibilityChanged
     */
    startScreencast(format: Protocol.Page.StartScreencastRequestFormat, quality: number, maxWidth: number | undefined, maxHeight: number | undefined, everyNthFrame: number | undefined, onFrame: (arg0: Protocol.binary, arg1: Protocol.Page.ScreencastFrameMetadata) => void, onVisibilityChanged: (arg0: boolean) => void): void;
    stopScreencast(): void;
    /**
     * @param {!Protocol.Page.CaptureScreenshotRequestFormat} format
     * @param {number} quality
     * @param {!Protocol.Page.Viewport=} clip
     * @return {!Promise<?Protocol.binary>}
     */
    captureScreenshot(format: Protocol.Page.CaptureScreenshotRequestFormat, quality: number, clip?: Protocol.Page.Viewport | undefined): Promise<Protocol.binary | null>;
    /**
     * @return {!Promise<?{viewportX: number, viewportY: number, viewportScale: number, contentWidth: number, contentHeight: number}>}
     */
    fetchLayoutMetrics(): Promise<{
        viewportX: number;
        viewportY: number;
        viewportScale: number;
        contentWidth: number;
        contentHeight: number;
    } | null>;
    /**
     * @override
     * @param {!Protocol.Page.ScreencastFrameEvent} _
     */
    screencastFrame({ data, metadata, sessionId }: Protocol.Page.ScreencastFrameEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.ScreencastVisibilityChangedEvent} _
     */
    screencastVisibilityChanged({ visible }: Protocol.Page.ScreencastVisibilityChangedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.DomContentEventFiredEvent} params
     */
    domContentEventFired(params: Protocol.Page.DomContentEventFiredEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.LoadEventFiredEvent} params
     */
    loadEventFired(params: Protocol.Page.LoadEventFiredEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.LifecycleEventEvent} params
     */
    lifecycleEvent(params: Protocol.Page.LifecycleEventEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.NavigatedWithinDocumentEvent} params
     */
    navigatedWithinDocument(params: Protocol.Page.NavigatedWithinDocumentEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameAttachedEvent} params
     */
    frameAttached(params: Protocol.Page.FrameAttachedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameNavigatedEvent} params
     */
    frameNavigated(params: Protocol.Page.FrameNavigatedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameDetachedEvent} params
     */
    frameDetached(params: Protocol.Page.FrameDetachedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameStartedLoadingEvent} params
     */
    frameStartedLoading(params: Protocol.Page.FrameStartedLoadingEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameStoppedLoadingEvent} params
     */
    frameStoppedLoading(params: Protocol.Page.FrameStoppedLoadingEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameRequestedNavigationEvent} params
     */
    frameRequestedNavigation(params: Protocol.Page.FrameRequestedNavigationEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameScheduledNavigationEvent} params
     */
    frameScheduledNavigation(params: Protocol.Page.FrameScheduledNavigationEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameClearedScheduledNavigationEvent} params
     */
    frameClearedScheduledNavigation(params: Protocol.Page.FrameClearedScheduledNavigationEvent): void;
    /**
     * @override
     */
    frameResized(): void;
    /**
     * @override
     * @param {!Protocol.Page.JavascriptDialogOpeningEvent} params
     */
    javascriptDialogOpening(params: Protocol.Page.JavascriptDialogOpeningEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.JavascriptDialogClosedEvent} params
     */
    javascriptDialogClosed(params: Protocol.Page.JavascriptDialogClosedEvent): void;
    /**
     * @override
     */
    interstitialShown(): void;
    /**
     * @override
     */
    interstitialHidden(): void;
    /**
     * @override
     * @param {!Protocol.Page.WindowOpenEvent} params
     */
    windowOpen(params: Protocol.Page.WindowOpenEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FileChooserOpenedEvent} params
     */
    fileChooserOpened(params: Protocol.Page.FileChooserOpenedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.CompilationCacheProducedEvent} params
     */
    compilationCacheProduced(params: Protocol.Page.CompilationCacheProducedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.DownloadWillBeginEvent} params
     */
    downloadWillBegin(params: Protocol.Page.DownloadWillBeginEvent): void;
    /**
     * @override
     */
    downloadProgress(): void;
}
import { SDKModel } from "./SDKModel.js";
import { Target } from "./SDKModel.js";
