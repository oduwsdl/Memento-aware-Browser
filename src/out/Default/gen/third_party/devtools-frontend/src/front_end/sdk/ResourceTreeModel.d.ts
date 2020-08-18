export class ResourceTreeModel extends SDKModel {
    /**
     * @param {!NetworkRequest} request
     * @return {?ResourceTreeFrame}
     */
    static frameForRequest(request: NetworkRequest): ResourceTreeFrame | null;
    /**
     * @return {!Array.<!ResourceTreeFrame>}
     */
    static frames(): Array<ResourceTreeFrame>;
    /**
     * @param {string} url
     * @return {?Resource}
     */
    static resourceForURL(url: string): Resource | null;
    /**
     * @param {boolean=} bypassCache
     * @param {string=} scriptToEvaluateOnLoad
     */
    static reloadAllPages(bypassCache?: boolean | undefined, scriptToEvaluateOnLoad?: string | undefined): void;
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _agent: ProtocolProxyApi.PageApi;
    _securityOriginManager: any;
    /** @type {!Map<string, !ResourceTreeFrame>} */
    _frames: Map<string, ResourceTreeFrame>;
    _cachedResourcesProcessed: boolean;
    _pendingReloadOptions: (string | boolean | undefined)[] | null;
    _reloadSuspensionCount: number;
    _isInterstitialShowing: boolean;
    /** @type {?ResourceTreeFrame} */
    mainFrame: ResourceTreeFrame | null;
    /**
     * @return {!DOMModel}
     */
    domModel(): DOMModel;
    /**
     * @param {?Protocol.Page.FrameResourceTree} mainFramePayload
     */
    _processCachedResources(mainFramePayload: Protocol.Page.FrameResourceTree | null): void;
    /**
     * @return {boolean}
     */
    cachedResourcesLoaded(): boolean;
    /**
     * @return {boolean}
     */
    isInterstitialShowing(): boolean;
    /**
     * @param {!ResourceTreeFrame} frame
     * @param {boolean=} aboutToNavigate
     */
    _addFrame(frame: ResourceTreeFrame, aboutToNavigate?: boolean | undefined): void;
    /**
     * @param {!Protocol.Page.FrameId} frameId
     * @param {?Protocol.Page.FrameId} parentFrameId
     * @param {!Protocol.Runtime.StackTrace=} stackTrace
     * @return {?ResourceTreeFrame}
     */
    _frameAttached(frameId: Protocol.Page.FrameId, parentFrameId: Protocol.Page.FrameId | null, stackTrace?: Protocol.Runtime.StackTrace | undefined): ResourceTreeFrame | null;
    /**
     * @param {!Protocol.Page.Frame} framePayload
     */
    _frameNavigated(framePayload: Protocol.Page.Frame): void;
    /**
     * @param {!Protocol.Page.FrameId} frameId
     */
    _frameDetached(frameId: Protocol.Page.FrameId): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onRequestFinished(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onRequestUpdateDropped(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Protocol.Page.FrameId} frameId
     * @return {!ResourceTreeFrame}
     */
    frameForId(frameId: Protocol.Page.FrameId): ResourceTreeFrame;
    /**
     * @param {function(!Resource):void} callback
     * @return {boolean}
     */
    forAllResources(callback: (arg0: Resource) => void): boolean;
    /**
     * @return {!Array<!ResourceTreeFrame>}
     */
    frames(): Array<ResourceTreeFrame>;
    /**
     * @param {string} url
     * @return {?Resource}
     */
    resourceForURL(url: string): Resource | null;
    /**
     * @param {?ResourceTreeFrame} parentFrame
     * @param {!Protocol.Page.FrameResourceTree} frameTreePayload
     */
    _addFramesRecursively(parentFrame: ResourceTreeFrame | null, frameTreePayload: Protocol.Page.FrameResourceTree): void;
    /**
     * @param {!Protocol.Page.Frame} frame
     * @param {string} url
     * @param {!Common.ResourceType.ResourceType} type
     * @param {string} mimeType
     * @param {?number} lastModifiedTime
     * @param {?number} contentSize
     * @return {!Resource}
     */
    _createResourceFromFramePayload(frame: Protocol.Page.Frame, url: string, type: Common.ResourceType.ResourceType, mimeType: string, lastModifiedTime: number | null, contentSize: number | null): Resource;
    suspendReload(): void;
    resumeReload(): void;
    /**
     * @param {boolean=} bypassCache
     * @param {string=} scriptToEvaluateOnLoad
     */
    reloadPage(bypassCache?: boolean | undefined, scriptToEvaluateOnLoad?: string | undefined): void;
    /**
     * @param {string} url
     * @return {!Promise<?>}
     */
    navigate(url: string): Promise<unknown>;
    /**
     * @return {!Promise<?{currentIndex: number, entries: !Array<!Protocol.Page.NavigationEntry>}>}
     */
    navigationHistory(): Promise<{
        currentIndex: number;
        entries: Array<Protocol.Page.NavigationEntry>;
    } | null>;
    /**
     * @param {!Protocol.Page.NavigationEntry} entry
     */
    navigateToHistoryEntry(entry: Protocol.Page.NavigationEntry): void;
    /**
     * @return {!Promise<{url: string, data: ?string, errors: !Array<!Protocol.Page.AppManifestError>}>}
     */
    fetchAppManifest(): Promise<{
        url: string;
        data: string | null;
        errors: Array<Protocol.Page.AppManifestError>;
    }>;
    /**
     * @return {!Promise<!Array<!Protocol.Page.InstallabilityError>>}
     */
    getInstallabilityErrors(): Promise<Array<Protocol.Page.InstallabilityError>>;
    /**
     * @return {!Promise<{primaryIcon: ?string}>}
     */
    getManifestIcons(): Promise<{
        primaryIcon: string | null;
    }>;
    /**
     * @param {!ExecutionContext} a
     * @param {!ExecutionContext} b
     * @return {number}
     */
    _executionContextComparator(a: ExecutionContext, b: ExecutionContext): number;
    /**
     * @return {!SecurityOriginData}
     */
    _getSecurityOriginData(): SecurityOriginData;
    _updateSecurityOrigins(): void;
    /**
     * @return {?string}
     */
    getMainSecurityOrigin(): string | null;
}
export type Events = symbol;
export namespace Events {
    export const FrameAdded: symbol;
    export const FrameNavigated: symbol;
    export const FrameDetached: symbol;
    export const FrameResized: symbol;
    export const FrameWillNavigate: symbol;
    export const MainFrameNavigated: symbol;
    export const ResourceAdded: symbol;
    export const WillLoadCachedResources: symbol;
    export const CachedResourcesLoaded: symbol;
    export const DOMContentLoaded: symbol;
    export const LifecycleEvent: symbol;
    export const Load: symbol;
    export const PageReloadRequested: symbol;
    export const WillReloadPage: symbol;
    export const InterstitialShown: symbol;
    export const InterstitialHidden: symbol;
}
/**
 * @unrestricted
 */
export class ResourceTreeFrame {
    /**
     * @param {!ResourceTreeModel} model
     * @param {?ResourceTreeFrame} parentFrame
     * @param {!Protocol.Page.FrameId} frameId
     * @param {?Protocol.Page.Frame} payload
     * @param {?Protocol.Runtime.StackTrace} creationStackTrace
     */
    constructor(model: ResourceTreeModel, parentFrame: ResourceTreeFrame | null, frameId: Protocol.Page.FrameId, payload: Protocol.Page.Frame | null, creationStackTrace: Protocol.Runtime.StackTrace | null);
    _model: ResourceTreeModel;
    _parentFrame: ResourceTreeFrame | null;
    _id: string;
    _url: string;
    _crossTargetParentFrameId: any;
    _loaderId: string;
    _name: string | undefined;
    _securityOrigin: string;
    _mimeType: string;
    _unreachableUrl: string;
    _creationStackTrace: Protocol.Runtime.StackTrace | null;
    /**
     * @type {!Set.<!ResourceTreeFrame>}
     */
    _childFrames: Set<ResourceTreeFrame>;
    /**
     * @type {!Object.<string, !Resource>}
     */
    _resourcesMap: {
        [x: string]: Resource;
    };
    /**
     * @param {!Protocol.Page.Frame} framePayload
     */
    _navigate(framePayload: Protocol.Page.Frame): void;
    /**
     * @return {!ResourceTreeModel}
     */
    resourceTreeModel(): ResourceTreeModel;
    /**
     * @return {string}
     */
    get id(): string;
    /**
     * @return {string}
     */
    get name(): string;
    /**
     * @return {string}
     */
    get url(): string;
    /**
     * @return {string}
     */
    get securityOrigin(): string;
    /**
     * @return {string}
     */
    unreachableUrl(): string;
    /**
     * @return {string}
     */
    get loaderId(): string;
    /**
     * @return {?ResourceTreeFrame}
     */
    get parentFrame(): ResourceTreeFrame | null;
    /**
     * @return {!Array.<!ResourceTreeFrame>}
     */
    get childFrames(): ResourceTreeFrame[];
    /**
     * @return {?ResourceTreeFrame}
     */
    crossTargetParentFrame(): ResourceTreeFrame | null;
    /**
     * @param {function(!Protocol.Runtime.CallFrame):boolean} searchFn
     * @return {?Protocol.Runtime.CallFrame}
     */
    findCreationCallFrame(searchFn: (arg0: Protocol.Runtime.CallFrame) => boolean): Protocol.Runtime.CallFrame | null;
    /**
     * @return {boolean}
     */
    isMainFrame(): boolean;
    isTopFrame(): boolean;
    /**
     * @return {!Resource}
     */
    get mainResource(): Resource;
    /**
     * @param {!ResourceTreeFrame} frame
     */
    _removeChildFrame(frame: ResourceTreeFrame): void;
    _removeChildFrames(): void;
    _remove(): void;
    /**
     * @param {!Resource} resource
     */
    addResource(resource: Resource): void;
    /**
     * @param {!NetworkRequest} request
     */
    _addRequest(request: NetworkRequest): void;
    /**
     * @return {!Array.<!Resource>}
     */
    resources(): Array<Resource>;
    /**
     * @param {string} url
     * @return {?Resource}
     */
    resourceForURL(url: string): Resource | null;
    /**
     * @param {function(!Resource):void} callback
     * @return {boolean}
     */
    _callForFrameResources(callback: (arg0: Resource) => void): boolean;
    /**
     * @return {string}
     */
    displayName(): string;
}
/**
 * @implements {ProtocolProxyApiWorkaround_PageDispatcher}
 * @unrestricted
 */
export class PageDispatcher implements ProtocolProxyApiWorkaround_PageDispatcher {
    /**
     * @param {!ResourceTreeModel} resourceTreeModel
     */
    constructor(resourceTreeModel: ResourceTreeModel);
    _resourceTreeModel: ResourceTreeModel;
    /**
     * @return {!Protocol.UsesObjectNotation}
     */
    usesObjectNotation(): Protocol.UsesObjectNotation;
    /**
     * @override
     * @param {!Protocol.Page.DomContentEventFiredEvent} event
     */
    domContentEventFired({ timestamp }: Protocol.Page.DomContentEventFiredEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.LoadEventFiredEvent} event
     */
    loadEventFired({ timestamp }: Protocol.Page.LoadEventFiredEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.LifecycleEventEvent} event
     */
    lifecycleEvent({ frameId, loaderId, name, timestamp }: Protocol.Page.LifecycleEventEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameAttachedEvent} event
     */
    frameAttached({ frameId, parentFrameId, stack }: Protocol.Page.FrameAttachedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameNavigatedEvent} event
     */
    frameNavigated({ frame }: Protocol.Page.FrameNavigatedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameDetachedEvent} event
     */
    frameDetached({ frameId }: Protocol.Page.FrameDetachedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameStartedLoadingEvent} event
     */
    frameStartedLoading({ frameId }: Protocol.Page.FrameStartedLoadingEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameStoppedLoadingEvent} event
     */
    frameStoppedLoading({ frameId }: Protocol.Page.FrameStoppedLoadingEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameRequestedNavigationEvent} event
     */
    frameRequestedNavigation({ frameId }: Protocol.Page.FrameRequestedNavigationEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameScheduledNavigationEvent} event
     */
    frameScheduledNavigation({ frameId, delay }: Protocol.Page.FrameScheduledNavigationEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FrameClearedScheduledNavigationEvent} event
     */
    frameClearedScheduledNavigation({ frameId }: Protocol.Page.FrameClearedScheduledNavigationEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.NavigatedWithinDocumentEvent} event
     */
    navigatedWithinDocument({ frameId, url }: Protocol.Page.NavigatedWithinDocumentEvent): void;
    /**
     * @override
     */
    frameResized(): void;
    /**
     * @override
     * @param {!Protocol.Page.JavascriptDialogOpeningEvent} event
     */
    javascriptDialogOpening({ url, message, type, hasBrowserHandler, defaultPrompt }: Protocol.Page.JavascriptDialogOpeningEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.JavascriptDialogClosedEvent} event
     */
    javascriptDialogClosed({ result, userInput }: Protocol.Page.JavascriptDialogClosedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.ScreencastFrameEvent} event
     */
    screencastFrame({ data, metadata, sessionId }: Protocol.Page.ScreencastFrameEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.ScreencastVisibilityChangedEvent} event
     */
    screencastVisibilityChanged({ visible }: Protocol.Page.ScreencastVisibilityChangedEvent): void;
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
     * @param {!Protocol.Page.WindowOpenEvent} event
     */
    windowOpen({ url, windowName, windowFeatures, userGesture }: Protocol.Page.WindowOpenEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.CompilationCacheProducedEvent} event
     */
    compilationCacheProduced({ url, data }: Protocol.Page.CompilationCacheProducedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.FileChooserOpenedEvent} event
     */
    fileChooserOpened({ mode }: Protocol.Page.FileChooserOpenedEvent): void;
    /**
     * @override
     * @param {!Protocol.Page.DownloadWillBeginEvent} event
     */
    downloadWillBegin({ frameId, url }: Protocol.Page.DownloadWillBeginEvent): void;
    /**
     * @override
     */
    downloadProgress(): void;
}
export type SecurityOriginData = {
    securityOrigins: Set<string>;
    mainSecurityOrigin: string | null;
    unreachableMainSecurityOrigin: string | null;
};
/**
 * @typedef {{
  *      securityOrigins: !Set<string>,
  *      mainSecurityOrigin: ?string,
  *      unreachableMainSecurityOrigin: ?string
  * }}
  */
export let SecurityOriginData: any;
import { SDKModel } from "./SDKModel.js";
import { DOMModel } from "./DOMModel.js";
import * as Common from "../common/common.js";
import { Resource } from "./Resource.js";
import { ExecutionContext } from "./RuntimeModel.js";
import { NetworkRequest } from "./NetworkRequest.js";
import { Target } from "./SDKModel.js";
