export class NetworkManager extends SDKModel {
    /**
     * @param {!NetworkRequest} request
     * @return {?NetworkManager}
     */
    static forRequest(request: NetworkRequest): NetworkManager | null;
    /**
     * @param {!NetworkRequest} request
     * @return {boolean}
     */
    static canReplayRequest(request: NetworkRequest): boolean;
    /**
     * @param {!NetworkRequest} request
     */
    static replayRequest(request: NetworkRequest): void;
    /**
     * @param {!NetworkRequest} request
     * @param {string} query
     * @param {boolean} caseSensitive
     * @param {boolean} isRegex
     * @return {!Promise<!Array<!TextUtils.ContentProvider.SearchMatch>>}
     */
    static searchInRequest(request: NetworkRequest, query: string, caseSensitive: boolean, isRegex: boolean): Promise<Array<TextUtils.ContentProvider.SearchMatch>>;
    /**
     * @param {!NetworkRequest} request
     * @return {!Promise<!ContentData>}
     */
    static requestContentData(request: NetworkRequest): Promise<ContentData>;
    /**
     * @param {!NetworkRequest} request
     * @return {!Promise<?string>}
     */
    static requestPostData(request: NetworkRequest): Promise<string | null>;
    /**
     * @param {!Conditions} conditions
     * @return {!Protocol.Network.ConnectionType}
     * TODO(allada): this belongs to NetworkConditionsSelector, which should hardcode/guess it.
     */
    static _connectionType(conditions: Conditions): Protocol.Network.ConnectionType;
    /**
     * @param {!Object<string,string>} headers
     * @return {!Object<string, string>}
     */
    static lowercaseHeaders(headers: {
        [x: string]: string;
    }): {
        [x: string]: string;
    };
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _dispatcher: NetworkDispatcher;
    _networkAgent: ProtocolProxyApi.NetworkApi;
    _bypassServiceWorkerSetting: Common.Settings.Setting<any>;
    /**
     * @param {string} url
     * @return {!NetworkRequest}
     */
    inflightRequestForURL(url: string): NetworkRequest;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _cacheDisabledSettingChanged(event: Common.EventTarget.EventTargetEvent): void;
    _bypassServiceWorkerChanged(): void;
}
export type Events = symbol;
export namespace Events {
    export const RequestStarted: symbol;
    export const RequestUpdated: symbol;
    export const RequestFinished: symbol;
    export const RequestUpdateDropped: symbol;
    export const ResponseReceived: symbol;
    export const MessageGenerated: symbol;
    export const RequestRedirected: symbol;
    export const LoadingFinished: symbol;
}
/** @type {!Conditions} */
export const NoThrottlingConditions: Conditions;
/** @type {!Conditions} */
export const OfflineConditions: Conditions;
/** @type {!Conditions} */
export const Slow3GConditions: Conditions;
/** @type {!Conditions} */
export const Fast3GConditions: Conditions;
/**
 * @implements {ProtocolProxyApiWorkaround_NetworkDispatcher}
 * @unrestricted
 */
export class NetworkDispatcher implements ProtocolProxyApiWorkaround_NetworkDispatcher {
    /**
     * @param {!NetworkManager} manager
     */
    constructor(manager: NetworkManager);
    _manager: NetworkManager;
    /** @type {!Map<!Protocol.Network.RequestId, !NetworkRequest>} */
    _inflightRequestsById: Map<Protocol.Network.RequestId, NetworkRequest>;
    /** @type {!Object<string, !NetworkRequest>} */
    _inflightRequestsByURL: {
        [x: string]: NetworkRequest;
    };
    /** @type {!Map<string, !RedirectExtraInfoBuilder>} */
    _requestIdToRedirectExtraInfoBuilder: Map<string, RedirectExtraInfoBuilder>;
    /**
     * @return {!Protocol.UsesObjectNotation}
     */
    usesObjectNotation(): Protocol.UsesObjectNotation;
    /**
     * @param {!Protocol.Network.Headers} headersMap
     * @return {!Array.<!NameValue>}
     */
    _headersMapToHeadersArray(headersMap: Protocol.Network.Headers): Array<NameValue>;
    /**
     * @param {!NetworkRequest} networkRequest
     * @param {!Protocol.Network.Request} request
     */
    _updateNetworkRequestWithRequest(networkRequest: NetworkRequest, request: Protocol.Network.Request): void;
    /**
     * @param {!NetworkRequest} networkRequest
     * @param {!Protocol.Network.Response} response
     */
    _updateNetworkRequestWithResponse(networkRequest: NetworkRequest, response: Protocol.Network.Response): void;
    /**
     * @param {!NetworkRequest} networkRequest
     * @return {boolean}
     */
    _mimeTypeIsConsistentWithType(networkRequest: NetworkRequest): boolean;
    /**
     * @override
     * @param {!Protocol.Network.ResourceChangedPriorityEvent} request
     */
    resourceChangedPriority({ requestId, newPriority, timestamp }: Protocol.Network.ResourceChangedPriorityEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.SignedExchangeReceivedEvent} request
     */
    signedExchangeReceived({ requestId, info }: Protocol.Network.SignedExchangeReceivedEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.RequestWillBeSentEvent} request
     */
    requestWillBeSent({ requestId, loaderId, documentURL, request, timestamp, wallTime, initiator, redirectResponse, type, frameId }: Protocol.Network.RequestWillBeSentEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.RequestServedFromCacheEvent} request
     */
    requestServedFromCache({ requestId }: Protocol.Network.RequestServedFromCacheEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.ResponseReceivedEvent} request
     */
    responseReceived({ requestId, loaderId, timestamp, type, response, frameId }: Protocol.Network.ResponseReceivedEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.DataReceivedEvent} request
     */
    dataReceived({ requestId, timestamp, dataLength, encodedDataLength }: Protocol.Network.DataReceivedEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.LoadingFinishedEvent} request
     */
    loadingFinished({ requestId, timestamp: finishTime, encodedDataLength, shouldReportCorbBlocking }: Protocol.Network.LoadingFinishedEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.LoadingFailedEvent} request
     */
    loadingFailed({ requestId, timestamp: time, type: resourceType, errorText: localizedDescription, canceled, blockedReason }: Protocol.Network.LoadingFailedEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.WebSocketCreatedEvent} request
     */
    webSocketCreated({ requestId, url: requestURL, initiator }: Protocol.Network.WebSocketCreatedEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.WebSocketWillSendHandshakeRequestEvent} request
     */
    webSocketWillSendHandshakeRequest({ requestId, timestamp: time, wallTime, request }: Protocol.Network.WebSocketWillSendHandshakeRequestEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.WebSocketHandshakeResponseReceivedEvent} request
     */
    webSocketHandshakeResponseReceived({ requestId, timestamp: time, response }: Protocol.Network.WebSocketHandshakeResponseReceivedEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.WebSocketFrameReceivedEvent} request
     */
    webSocketFrameReceived({ requestId, timestamp: time, response }: Protocol.Network.WebSocketFrameReceivedEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.WebSocketFrameSentEvent} request
     */
    webSocketFrameSent({ requestId, timestamp: time, response }: Protocol.Network.WebSocketFrameSentEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.WebSocketFrameErrorEvent} request
     */
    webSocketFrameError({ requestId, timestamp: time, errorMessage }: Protocol.Network.WebSocketFrameErrorEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.WebSocketClosedEvent} request
     */
    webSocketClosed({ requestId, timestamp: time }: Protocol.Network.WebSocketClosedEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.EventSourceMessageReceivedEvent} request
     */
    eventSourceMessageReceived({ requestId, timestamp: time, eventName, eventId, data }: Protocol.Network.EventSourceMessageReceivedEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.RequestInterceptedEvent} request
     */
    requestIntercepted({ interceptionId, request, frameId, resourceType, isNavigationRequest, isDownload, redirectUrl, authChallenge, responseErrorReason, responseStatusCode, responseHeaders, requestId }: Protocol.Network.RequestInterceptedEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.RequestWillBeSentExtraInfoEvent} request
     */
    requestWillBeSentExtraInfo({ requestId, associatedCookies, headers }: Protocol.Network.RequestWillBeSentExtraInfoEvent): void;
    /**
     * @override
     * @param {!Protocol.Network.ResponseReceivedExtraInfoEvent} request
     */
    responseReceivedExtraInfo({ requestId, blockedCookies, headers, headersText }: Protocol.Network.ResponseReceivedExtraInfoEvent): void;
    /**
     * @param {string} requestId
     * @return {!RedirectExtraInfoBuilder}
     */
    _getExtraInfoBuilder(requestId: string): RedirectExtraInfoBuilder;
    /**
     * @param {!Protocol.Network.RequestId} requestId
     * @param {!Protocol.Network.MonotonicTime} time
     * @param {string} redirectURL
     * @return {!NetworkRequest}
     */
    _appendRedirect(requestId: Protocol.Network.RequestId, time: Protocol.Network.MonotonicTime, redirectURL: string): NetworkRequest;
    /**
     * @param {string} requestId
     * @return {?NetworkRequest}
     */
    _maybeAdoptMainResourceRequest(requestId: string): NetworkRequest | null;
    /**
     * @param {!NetworkRequest} networkRequest
     * @param {?Protocol.Network.Request} originalRequest
     */
    _startNetworkRequest(networkRequest: NetworkRequest, originalRequest: Protocol.Network.Request | null): void;
    /**
     * @param {!NetworkRequest} networkRequest
     */
    _updateNetworkRequest(networkRequest: NetworkRequest): void;
    /**
     * @param {!NetworkRequest} networkRequest
     * @param {!Protocol.Network.MonotonicTime} finishTime
     * @param {number} encodedDataLength
     * @param {boolean=} shouldReportCorbBlocking
     */
    _finishNetworkRequest(networkRequest: NetworkRequest, finishTime: Protocol.Network.MonotonicTime, encodedDataLength: number, shouldReportCorbBlocking?: boolean | undefined): void;
    /**
     * @param {!Protocol.Network.RequestId} requestId
     * @param {string} frameId
     * @param {!Protocol.Network.LoaderId} loaderId
     * @param {string} url
     * @param {string} documentURL
     * @param {?Protocol.Network.Initiator} initiator
     */
    _createNetworkRequest(requestId: Protocol.Network.RequestId, frameId: string, loaderId: Protocol.Network.LoaderId, url: string, documentURL: string, initiator: Protocol.Network.Initiator | null): NetworkRequest;
}
/**
 * @implements {SDKModelObserver<!NetworkManager>}
 * @unrestricted
 */
export class MultitargetNetworkManager extends Common.ObjectWrapper.ObjectWrapper implements SDKModelObserver<NetworkManager> {
    /**
     * @param {{forceNew: ?boolean}} opts
     * @return {!MultitargetNetworkManager}
     */
    static instance(opts?: {
        forceNew: boolean | null;
    }): MultitargetNetworkManager;
    /**
     * @return {string}
     */
    static getChromeVersion(): string;
    /**
      * Generate a brand version list for Chrome, including some randomization
      * to try to ensure proper parsing behavior. See
      *
      * https://wicg.github.io/ua-client-hints/#grease
      *
      * This implementation matches GenerateBrandVersionList() in
      * chrome_content_browser_client.cc
      * @param {number} seed
      * @param {string} brand
      * @param {string} majorVersion
      *
      * @return {!Array<!Protocol.Emulation.UserAgentBrandVersion>}
      */
    static _generateBrandVersionList(seed: number, brand: string, majorVersion: string): Array<Protocol.Emulation.UserAgentBrandVersion>;
    /**
     * @return {!Array<!Protocol.Emulation.UserAgentBrandVersion>}
     */
    static getChromeBrands(): Array<Protocol.Emulation.UserAgentBrandVersion>;
    /**
     * @param {string} uaString
     * @return {string}
     */
    static patchUserAgentWithChromeVersion(uaString: string): string;
    /** @type {string} */
    _userAgentOverride: string;
    /** @type {?Protocol.Emulation.UserAgentMetadata} */
    _userAgentMetadataOverride: Protocol.Emulation.UserAgentMetadata | null;
    /** @type {!Set<!ProtocolProxyApi.NetworkApi>} */
    _agents: Set<ProtocolProxyApi.NetworkApi>;
    /** @type {!Map<string, !NetworkRequest>} */
    _inflightMainResourceRequests: Map<string, NetworkRequest>;
    /** @type {!Conditions} */
    _networkConditions: Conditions;
    /** @type {?Promise<void>} */
    _updatingInterceptionPatternsPromise: Promise<void> | null;
    _blockingEnabledSetting: Common.Settings.Setting<any>;
    _blockedPatternsSetting: Common.Settings.Setting<any>;
    /** @type {!Array<string>} */
    _effectiveBlockedURLs: Array<string>;
    /** @type {!Platform.Multimap<!RequestInterceptor, !InterceptionPattern>} */
    _urlsForRequestInterceptor: Platform.Multimap<RequestInterceptor, InterceptionPattern>;
    /**
     * @override
     * @param {!NetworkManager} networkManager
     */
    modelAdded(networkManager: NetworkManager): void;
    /**
     * @override
     * @param {!NetworkManager} networkManager
     */
    modelRemoved(networkManager: NetworkManager): void;
    /**
     * @return {boolean}
     */
    isThrottling(): boolean;
    /**
     * @return {boolean}
     */
    isOffline(): boolean;
    /**
     * @param {!Conditions} conditions
     */
    setNetworkConditions(conditions: Conditions): void;
    /**
     * @return {!Conditions}
     */
    networkConditions(): Conditions;
    /**
     * @param {!ProtocolProxyApi.NetworkApi} networkAgent
     */
    _updateNetworkConditions(networkAgent: ProtocolProxyApi.NetworkApi): void;
    /**
     * @param {!Protocol.Network.Headers} headers
     */
    setExtraHTTPHeaders(headers: Protocol.Network.Headers): void;
    _extraHeaders: Protocol.Network.Headers | undefined;
    /**
     * @return {string}
     */
    currentUserAgent(): string;
    _updateUserAgentOverride(): void;
    /**
     * @param {string} userAgent
     * @param {?Protocol.Emulation.UserAgentMetadata} userAgentMetadataOverride
     */
    setUserAgentOverride(userAgent: string, userAgentMetadataOverride: Protocol.Emulation.UserAgentMetadata | null): void;
    /**
     * @return {string}
     */
    userAgentOverride(): string;
    /**
     * @param {string} userAgent
     */
    setCustomUserAgentOverride(userAgent: string): void;
    _customUserAgent: string | undefined;
    /**
     * @return {!Array<!BlockedPattern>}
     */
    blockedPatterns(): Array<BlockedPattern>;
    /**
     * @return {boolean}
     */
    blockingEnabled(): boolean;
    /**
     * @return {boolean}
     */
    isBlocking(): boolean;
    /**
     * @param {!Array<!BlockedPattern>} patterns
     */
    setBlockedPatterns(patterns: Array<BlockedPattern>): void;
    /**
     * @param {boolean} enabled
     */
    setBlockingEnabled(enabled: boolean): void;
    _updateBlockedPatterns(): void;
    /**
     * @return {boolean}
     */
    isIntercepting(): boolean;
    /**
     * @param {!Array<!InterceptionPattern>} patterns
     * @param {!RequestInterceptor} requestInterceptor
     * @return {!Promise<void>}
     */
    setInterceptionHandlerForPatterns(patterns: Array<InterceptionPattern>, requestInterceptor: RequestInterceptor): Promise<void>;
    /**
     * @return {!Promise<void>}
     */
    _updateInterceptionPatternsOnNextTick(): Promise<void>;
    /**
     * @return {!Promise<void>}
     */
    _updateInterceptionPatterns(): Promise<void>;
    /**
     * @param {!InterceptedRequest} interceptedRequest
     */
    _requestIntercepted(interceptedRequest: InterceptedRequest): Promise<void>;
    clearBrowserCache(): void;
    clearBrowserCookies(): void;
    /**
     * @param {string} origin
     * @return {!Promise<!Array<string>>}
     */
    getCertificate(origin: string): Promise<Array<string>>;
    /**
     * @param {string} url
     * @return {!Promise<!{success: boolean, content: string, errorDescription: !Host.ResourceLoader.LoadErrorDescription}>}
     */
    loadResource(url: string): Promise<{
        success: boolean;
        content: string;
        errorDescription: Host.ResourceLoader.LoadErrorDescription;
    }>;
}
export namespace MultitargetNetworkManager {
    export namespace Events {
        export const BlockedPatternsChanged: symbol;
        export const ConditionsChanged: symbol;
        export const UserAgentChanged: symbol;
        export const InterceptorsChanged: symbol;
    }
    export type Events = symbol;
}
export class InterceptedRequest {
    /**
     * @param {!ProtocolProxyApi.NetworkApi} networkAgent
     * @param {!Protocol.Network.InterceptionId} interceptionId
     * @param {!Protocol.Network.Request} request
     * @param {!Protocol.Page.FrameId} frameId
     * @param {!Protocol.Network.ResourceType} resourceType
     * @param {boolean} isNavigationRequest
     * @param {boolean=} isDownload
     * @param {string=} redirectUrl
     * @param {!Protocol.Network.AuthChallenge=} authChallenge
     * @param {!Protocol.Network.ErrorReason=} responseErrorReason
     * @param {number=} responseStatusCode
     * @param {!Protocol.Network.Headers=} responseHeaders
     * @param {!Protocol.Network.RequestId=} requestId
     */
    constructor(networkAgent: ProtocolProxyApi.NetworkApi, interceptionId: Protocol.Network.InterceptionId, request: Protocol.Network.Request, frameId: Protocol.Page.FrameId, resourceType: Protocol.Network.ResourceType, isNavigationRequest: boolean, isDownload?: boolean | undefined, redirectUrl?: string | undefined, authChallenge?: Protocol.Network.AuthChallenge | undefined, responseErrorReason?: Protocol.Network.ErrorReason | undefined, responseStatusCode?: number | undefined, responseHeaders?: Protocol.Network.Headers | undefined, requestId?: Protocol.Network.RequestId | undefined);
    _networkAgent: ProtocolProxyApi.NetworkApi;
    _interceptionId: string;
    _hasResponded: boolean;
    request: Protocol.Network.Request;
    frameId: string;
    resourceType: Protocol.Network.ResourceType;
    isNavigationRequest: boolean;
    isDownload: boolean;
    redirectUrl: string | undefined;
    authChallenge: Protocol.Network.AuthChallenge | undefined;
    responseErrorReason: Protocol.Network.ErrorReason | undefined;
    responseStatusCode: number | undefined;
    responseHeaders: Protocol.Network.Headers | undefined;
    requestId: string | undefined;
    /**
     * @return {boolean}
     */
    hasResponded(): boolean;
    /**
     * @param {!Blob} contentBlob
     */
    continueRequestWithContent(contentBlob: Blob): Promise<void>;
    continueRequestWithoutChange(): void;
    /**
     * @param {!Protocol.Network.ErrorReason} errorReason
     */
    continueRequestWithError(errorReason: Protocol.Network.ErrorReason): void;
    /**
     * @return {!Promise<!ContentData>}
     */
    responseBody(): Promise<ContentData>;
}
export type Conditions = {
    download: number;
    upload: number;
    latency: number;
    title: string;
};
/**
 * @typedef {{
  *   download: number,
  *   upload: number,
  *   latency: number,
  *   title: string,
  * }}
  */
export let Conditions: any;
export type BlockedPattern = {
    url: string;
    enabled: boolean;
};
/** @typedef {{url: string, enabled: boolean}} */
export let BlockedPattern: any;
export type Message = {
    message: string;
    requestId: string;
    warning: boolean;
};
/** @typedef {{message: string, requestId: string, warning: boolean}} */
export let Message: any;
export type InterceptionPattern = {
    urlPattern: string;
    interceptionStage: Protocol.Network.InterceptionStage;
};
/** @typedef {!{urlPattern: string, interceptionStage: !Protocol.Network.InterceptionStage}} */
export let InterceptionPattern: any;
export type RequestInterceptor = (arg0: InterceptedRequest) => Promise<void>;
/** @typedef {!function(!InterceptedRequest):!Promise<void>} */
export let RequestInterceptor: any;
import { SDKModel } from "./SDKModel.js";
import * as Common from "../common/common.js";
import { NetworkRequest } from "./NetworkRequest.js";
import * as TextUtils from "../text_utils/text_utils.js";
import { ContentData } from "./NetworkRequest.js";
import { Target } from "./SDKModel.js";
/**
 * Helper class to match requests created from requestWillBeSent with
 * requestWillBeSentExtraInfo and responseReceivedExtraInfo when they have the
 * same requestId due to redirects.
 */
declare class RedirectExtraInfoBuilder {
    /**
     * @param {function():void} deleteCallback
     */
    constructor(deleteCallback: () => void);
    /** @type {!Array<!NetworkRequest>} */
    _requests: Array<NetworkRequest>;
    /** @type {!Array<?ExtraRequestInfo>} */
    _requestExtraInfos: Array<ExtraRequestInfo | null>;
    /** @type {!Array<?ExtraResponseInfo>} */
    _responseExtraInfos: Array<ExtraResponseInfo | null>;
    /** @type {boolean} */
    _finished: boolean;
    /** @type {boolean} */
    _hasExtraInfo: boolean;
    /** @type {function():void} */
    _deleteCallback: () => void;
    /**
     * @param {!NetworkRequest} req
     */
    addRequest(req: NetworkRequest): void;
    /**
     * @param {!ExtraRequestInfo} info
     */
    addRequestExtraInfo(info: ExtraRequestInfo): void;
    /**
     * @param {!ExtraResponseInfo} info
     */
    addResponseExtraInfo(info: ExtraResponseInfo): void;
    finished(): void;
    /**
     * @param {number} index
     */
    _sync(index: number): void;
    _deleteIfComplete(): void;
}
import { NameValue } from "./NetworkRequest.js";
import { SDKModelObserver } from "./SDKModel.js";
import * as Platform from "../platform/platform.js";
import * as Host from "../host/host.js";
import { ExtraRequestInfo } from "./NetworkRequest.js";
import { ExtraResponseInfo } from "./NetworkRequest.js";
export {};
