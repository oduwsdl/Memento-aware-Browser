export type MIME_TYPE = string;
export namespace MIME_TYPE {
    export const HTML: string;
    export const XML: string;
    export const PLAIN: string;
    export const XHTML: string;
    export const SVG: string;
    export const CSS: string;
    export const XSL: string;
    export const VTT: string;
    export const PDF: string;
}
/** @type {!Map<!MIME_TYPE, *>} */
export const MIME_TYPE_TO_RESOURCE_TYPE: Map<MIME_TYPE, any>;
/**
 * @implements {TextUtils.ContentProvider.ContentProvider}
 * @unrestricted
 */
export class NetworkRequest extends Common.ObjectWrapper.ObjectWrapper implements TextUtils.ContentProvider.ContentProvider {
    /**
     * @param {!Protocol.Network.RequestId} requestId
     * @param {string} url
     * @param {string} documentURL
     * @param {!Protocol.Page.FrameId} frameId
     * @param {!Protocol.Network.LoaderId} loaderId
     * @param {?Protocol.Network.Initiator} initiator
     */
    constructor(requestId: Protocol.Network.RequestId, url: string, documentURL: string, frameId: Protocol.Page.FrameId, loaderId: Protocol.Network.LoaderId, initiator: Protocol.Network.Initiator | null);
    _requestId: string;
    _backendRequestId: string;
    _documentURL: string;
    _frameId: string;
    _loaderId: string;
    /** @type {?Protocol.Network.Initiator} */
    _initiator: Protocol.Network.Initiator | null;
    /** @type {?NetworkRequest} */
    _redirectSource: NetworkRequest | null;
    /** @type {?NetworkRequest} */
    _redirectDestination: NetworkRequest | null;
    _issueTime: number;
    _startTime: number;
    _endTime: number;
    /** @type {!Protocol.Network.BlockedReason|undefined} */
    _blockedReason: Protocol.Network.BlockedReason | undefined;
    statusCode: number;
    statusText: string;
    requestMethod: string;
    requestTime: number;
    /** @type {string} */
    protocol: string;
    /** @type {!Protocol.Security.MixedContentType} */
    mixedContentType: Protocol.Security.MixedContentType;
    /** @type {?Protocol.Network.ResourcePriority} */
    _initialPriority: Protocol.Network.ResourcePriority | null;
    /** @type {?Protocol.Network.ResourcePriority} */
    _currentPriority: Protocol.Network.ResourcePriority | null;
    /** @type {?Protocol.Network.SignedExchangeInfo} */
    _signedExchangeInfo: Protocol.Network.SignedExchangeInfo | null;
    /** @type {!Common.ResourceType.ResourceType} */
    _resourceType: Common.ResourceType.ResourceType;
    /** @type {?Promise<!ContentData>} */
    _contentData: Promise<ContentData> | null;
    /** @type {!Array.<!WebSocketFrame>} */
    _frames: Array<WebSocketFrame>;
    /** @type {!Array.<!EventSourceMessage>} */
    _eventSourceMessages: Array<EventSourceMessage>;
    /** @type {!Object<string, (string|undefined)>} */
    _responseHeaderValues: {
        [x: string]: (string | undefined);
    };
    _responseHeadersText: string;
    /** @type {!Array<!NameValue>} */
    _requestHeaders: Array<NameValue>;
    /** @type {!Object<string, (string|undefined)>} */
    _requestHeaderValues: {
        [x: string]: (string | undefined);
    };
    _remoteAddress: string;
    /** @type {?Protocol.Network.RequestReferrerPolicy} */
    _referrerPolicy: Protocol.Network.RequestReferrerPolicy | null;
    /** @type {!Protocol.Security.SecurityState} */
    _securityState: Protocol.Security.SecurityState;
    /** @type {?Protocol.Network.SecurityDetails} */
    _securityDetails: Protocol.Network.SecurityDetails | null;
    /** @type {string} */
    connectionId: string;
    /** @type {boolean} */
    connectionReused: boolean;
    /** @type {boolean} */
    hasNetworkData: boolean;
    /** @type {?Promise<?Array.<!NameValue>>} */
    _formParametersPromise: Promise<Array<NameValue> | null> | null;
    /** @type {?Promise<?string>} */
    _requestFormDataPromise: Promise<string | null> | null;
    /** @type {boolean} */
    _hasExtraRequestInfo: boolean;
    /** @type {boolean} */
    _hasExtraResponseInfo: boolean;
    /** @type {!Array<!BlockedCookieWithReason>} */
    _blockedRequestCookies: Array<BlockedCookieWithReason>;
    /** @type {!Array<!Cookie>} */
    _includedRequestCookies: Array<Cookie>;
    /** @type {!Array<!BlockedSetCookieWithReason>} */
    _blockedResponseCookies: Array<BlockedSetCookieWithReason>;
    /** @type {?string} */
    localizedFailDescription: string | null;
    /** @type {string} */
    _url: string;
    /** @type {number} */
    _responseReceivedTime: number;
    /** @type {number} */
    _transferSize: number;
    /** @type {boolean} */
    _finished: boolean;
    /** @type {boolean} */
    _failed: boolean;
    /** @type {boolean} */
    _canceled: boolean;
    /** @type {!MIME_TYPE} */
    _mimeType: MIME_TYPE;
    /** @type {!Common.ParsedURL.ParsedURL} */
    _parsedURL: Common.ParsedURL.ParsedURL;
    /** @type {string} */
    _name: string;
    /** @type {string} */
    _path: string;
    /**
     * @param {!NetworkRequest} other
     * @return {number}
     */
    indentityCompare(other: NetworkRequest): number;
    /**
     * @return {!Protocol.Network.RequestId}
     */
    requestId(): Protocol.Network.RequestId;
    /**
     * @return {!Protocol.Network.RequestId}
     */
    backendRequestId(): Protocol.Network.RequestId;
    /**
     * @return {string}
     */
    url(): string;
    /**
     * @return {boolean}
     */
    isBlobRequest(): boolean;
    /**
     * @param {string} x
     */
    setUrl(x: string): void;
    /**
     * @return {string}
     */
    get documentURL(): string;
    get parsedURL(): Common.ParsedURL.ParsedURL;
    /**
     * @return {!Protocol.Page.FrameId}
     */
    get frameId(): string;
    /**
     * @return {!Protocol.Network.LoaderId}
     */
    get loaderId(): string;
    /**
     * @param {string} ip
     * @param {number} port
     */
    setRemoteAddress(ip: string, port: number): void;
    /**
     * @return {string}
     */
    remoteAddress(): string;
    /**
     * @return {string | undefined}
     * The cache name of the CacheStorage from where the response is served via
     * the ServiceWorker.
     */
    getResponseCacheStorageCacheName(): string | undefined;
    /**
     * @param {string} x
     */
    setResponseCacheStorageCacheName(x: string): void;
    _responseCacheStorageCacheName: string | undefined;
    /**
     * @return {!Protocol.Network.ServiceWorkerResponseSource | undefined}
     */
    serviceWorkerResponseSource(): Protocol.Network.ServiceWorkerResponseSource | undefined;
    /**
     * @param {!Protocol.Network.ServiceWorkerResponseSource} serviceWorkerResponseSource
     */
    setServiceWorkerResponseSource(serviceWorkerResponseSource: Protocol.Network.ServiceWorkerResponseSource): void;
    _serviceWorkerResponseSource: Protocol.Network.ServiceWorkerResponseSource | undefined;
    /**
     * @param {!Protocol.Network.RequestReferrerPolicy} referrerPolicy
     */
    setReferrerPolicy(referrerPolicy: Protocol.Network.RequestReferrerPolicy): void;
    /**
     * @return {?Protocol.Network.RequestReferrerPolicy}
     */
    referrerPolicy(): Protocol.Network.RequestReferrerPolicy | null;
    /**
     * @return {!Protocol.Security.SecurityState}
     */
    securityState(): Protocol.Security.SecurityState;
    /**
     * @param {!Protocol.Security.SecurityState} securityState
     */
    setSecurityState(securityState: Protocol.Security.SecurityState): void;
    /**
     * @return {?Protocol.Network.SecurityDetails}
     */
    securityDetails(): Protocol.Network.SecurityDetails | null;
    /**
     * @param {!Protocol.Network.SecurityDetails} securityDetails
     */
    setSecurityDetails(securityDetails: Protocol.Network.SecurityDetails): void;
    /**
     * @return {number}
     */
    get startTime(): number;
    /**
     * @param {number} monotonicTime
     * @param {number} wallTime
     */
    setIssueTime(monotonicTime: number, wallTime: number): void;
    _wallIssueTime: number | undefined;
    /**
     * @return {number}
     */
    issueTime(): number;
    /**
     * @param {number} monotonicTime
     * @return {number}
     */
    pseudoWallTime(monotonicTime: number): number;
    /**
     * @param {number} x
     */
    set responseReceivedTime(arg: number);
    /**
     * @return {number}
     */
    get responseReceivedTime(): number;
    /**
     * @return {!Date | undefined}
     * The time at which the returned response was generated. For cached
     * responses, this is the last time the cache entry was validated.
     */
    getResponseRetrievalTime(): Date | undefined;
    /**
     * @param {!Date} x
     */
    setResponseRetrievalTime(x: Date): void;
    _responseRetrievalTime: Date | undefined;
    /**
     * @param {number} x
     */
    set endTime(arg: number);
    /**
     * @return {number}
     */
    get endTime(): number;
    /**
     * @return {number}
     */
    get duration(): number;
    /**
     * @return {number}
     */
    get latency(): number;
    /**
     * @param {number} x
     */
    set resourceSize(arg: number);
    /**
     * @return {number}
     */
    get resourceSize(): number;
    _resourceSize: number | undefined;
    /**
     * @return {number}
     */
    get transferSize(): number;
    /**
     * @param {number} x
     */
    increaseTransferSize(x: number): void;
    /**
     * @param {number} x
     */
    setTransferSize(x: number): void;
    /**
     * @param {boolean} x
     */
    set finished(arg: boolean);
    /**
     * @return {boolean}
     */
    get finished(): boolean;
    /**
     * @param {boolean} x
     */
    set failed(arg: boolean);
    /**
     * @return {boolean}
     */
    get failed(): boolean;
    /**
     * @param {boolean} x
     */
    set canceled(arg: boolean);
    /**
     * @return {boolean}
     */
    get canceled(): boolean;
    /**
     * @return {!Protocol.Network.BlockedReason|undefined}
     */
    blockedReason(): Protocol.Network.BlockedReason | undefined;
    /**
     * @param {!Protocol.Network.BlockedReason} reason
     */
    setBlockedReason(reason: Protocol.Network.BlockedReason): void;
    /**
     * @return {boolean}
     */
    wasBlocked(): boolean;
    /**
     * @return {boolean}
     */
    cached(): boolean;
    /**
     * @return {boolean}
     */
    cachedInMemory(): boolean;
    /**
     * @return {boolean}
     */
    fromPrefetchCache(): boolean;
    setFromMemoryCache(): void;
    _fromMemoryCache: boolean | undefined;
    setFromDiskCache(): void;
    _fromDiskCache: boolean | undefined;
    setFromPrefetchCache(): void;
    _fromPrefetchCache: boolean | undefined;
    /**
     * @param {boolean} x
     */
    set fetchedViaServiceWorker(arg: boolean);
    /**
     * Returns true if the request was intercepted by a service worker and it
     * provided its own response.
     * @return {boolean}
     */
    get fetchedViaServiceWorker(): boolean;
    _fetchedViaServiceWorker: boolean | undefined;
    /**
     * Returns true if the request was sent by a service worker.
     * @return {boolean}
     */
    initiatedByServiceWorker(): boolean;
    /**
     * @param {!Protocol.Network.ResourceTiming|undefined} timingInfo
     */
    set timing(arg: Protocol.Network.ResourceTiming | undefined);
    /**
     * @return {!Protocol.Network.ResourceTiming|undefined}
     */
    get timing(): Protocol.Network.ResourceTiming | undefined;
    _timing: Protocol.Network.ResourceTiming | undefined;
    /**
     * @param {!MIME_TYPE} x
     */
    set mimeType(arg: string);
    /**
     * @return {!MIME_TYPE}
     */
    get mimeType(): string;
    /**
     * @return {string}
     */
    get displayName(): string;
    /**
     * @return {string}
     */
    name(): string;
    /**
     * @return {string}
     */
    path(): string;
    _parseNameAndPathFromURL(): void;
    /**
     * @return {string}
     */
    get folder(): string;
    /**
     * @return {string}
     */
    get pathname(): string;
    /**
     * @return {!Common.ResourceType.ResourceType}
     */
    resourceType(): Common.ResourceType.ResourceType;
    /**
     * @param {!Common.ResourceType.ResourceType} resourceType
     */
    setResourceType(resourceType: Common.ResourceType.ResourceType): void;
    /**
     * @return {string}
     */
    get domain(): string;
    /**
     * @return {string}
     */
    get scheme(): string;
    /**
     * @return {?NetworkRequest}
     */
    redirectSource(): NetworkRequest | null;
    /**
     * @param {?NetworkRequest} originatingRequest
     */
    setRedirectSource(originatingRequest: NetworkRequest | null): void;
    /**
     * @return {?NetworkRequest}
     */
    redirectDestination(): NetworkRequest | null;
    /**
     * @param {?NetworkRequest} redirectDestination
     */
    setRedirectDestination(redirectDestination: NetworkRequest | null): void;
    /**
     * @return {!Array.<!NameValue>}
     */
    requestHeaders(): Array<NameValue>;
    /**
     * @param {!Array.<!NameValue>} headers
     */
    setRequestHeaders(headers: Array<NameValue>): void;
    /**
     * @return {string|undefined}
     */
    requestHeadersText(): string | undefined;
    /**
     * @param {string} text
     */
    setRequestHeadersText(text: string): void;
    _requestHeadersText: string | undefined;
    /**
     * @param {string} headerName
     * @return {string|undefined}
     */
    requestHeaderValue(headerName: string): string | undefined;
    /**
     * @return {!Array.<!Cookie>}
     */
    get requestCookies(): Cookie[];
    _requestCookies: Cookie[] | undefined;
    /**
     * @return {!Promise<?string>}
     */
    requestFormData(): Promise<string | null>;
    /**
     * @param {boolean} hasData
     * @param {?string} data
     */
    setRequestFormData(hasData: boolean, data: string | null): void;
    /**
     * @return {string}
     */
    _filteredProtocolName(): string;
    /**
     * @return {string}
     */
    requestHttpVersion(): string;
    /**
     * @param {!Array.<!NameValue>} x
     */
    set responseHeaders(arg: {
        name: string;
        value: string;
    }[]);
    /**
     * @return {!Array.<!NameValue>}
     */
    get responseHeaders(): {
        name: string;
        value: string;
    }[];
    _responseHeaders: {
        name: string;
        value: string;
    }[] | undefined;
    /**
     * @param {string} x
     */
    set responseHeadersText(arg: string);
    /**
     * @return {string}
     */
    get responseHeadersText(): string;
    /**
     * @return {!Array.<!NameValue>}
     */
    get sortedResponseHeaders(): {
        name: string;
        value: string;
    }[];
    _sortedResponseHeaders: {
        name: string;
        value: string;
    }[] | undefined;
    /**
     * @param {string} headerName
     * @return {string|undefined}
     */
    responseHeaderValue(headerName: string): string | undefined;
    /**
     * @return {!Array.<!Cookie>}
     */
    get responseCookies(): Cookie[];
    _responseCookies: Cookie[] | undefined;
    /**
     * @return {string|undefined}
     */
    responseLastModified(): string | undefined;
    /**
     * @return {!Array.<!Cookie>}
     */
    allCookiesIncludingBlockedOnes(): Array<Cookie>;
    /**
     * @return {?Array.<!ServerTiming>}
     */
    get serverTimings(): ServerTiming[] | null;
    _serverTimings: ServerTiming[] | null | undefined;
    /**
     * @return {?string}
     */
    queryString(): string | null;
    _queryString: string | null | undefined;
    /**
     * @return {?Array.<!NameValue>}
     */
    get queryParameters(): {
        name: string;
        value: string;
    }[] | null;
    _parsedQueryParameters: {
        name: string;
        value: string;
    }[] | undefined;
    /**
     * @return {!Promise<?Array<!NameValue>>}
     */
    _parseFormParameters(): Promise<Array<NameValue> | null>;
    /**
     * @return {!Promise<?Array<!NameValue>>}
     */
    formParameters(): Promise<Array<NameValue> | null>;
    /**
     * @return {string}
     */
    responseHttpVersion(): string;
    /**
     * @param {string} queryString
     * @return {!Array.<!NameValue>}
     */
    _parseParameters(queryString: string): Array<NameValue>;
    /**
     * Parses multipart/form-data; boundary=boundaryString request bodies -
     * --boundaryString
     * Content-Disposition: form-data; name="field-name"; filename="r.gif"
     * Content-Type: application/octet-stream
     *
     * optionalValue
     * --boundaryString
     * Content-Disposition: form-data; name="field-name-2"
     *
     * optionalValue2
     * --boundaryString--
     *
     * @param {string} data
     * @param {string} boundary
     * @return {!Array.<!NameValue>}
     */
    _parseMultipartFormDataParameters(data: string, boundary: string): Array<NameValue>;
    /**
     * @param {!Array.<!NameValue>} headers
     * @param {string} headerName
     * @return {string|undefined}
     */
    _computeHeaderValue(headers: Array<NameValue>, headerName: string): string | undefined;
    /**
     * @return {!Promise<!ContentData>}
     */
    contentData(): Promise<ContentData>;
    /**
     * @param {function():!Promise<!ContentData>} dataProvider
     */
    setContentDataProvider(dataProvider: () => Promise<ContentData>): void;
    _contentDataProvider: (() => Promise<ContentData>) | undefined;
    /**
     * @override
     * @return {string}
     */
    contentURL(): string;
    /**
     * @override
     * @return {!Common.ResourceType.ResourceType}
     */
    contentType(): Common.ResourceType.ResourceType;
    /**
     * @override
     * @return {!Promise<boolean>}
     */
    contentEncoded(): Promise<boolean>;
    /**
     * @override
     * @return {!Promise<!TextUtils.ContentProvider.DeferredContent>}
     */
    requestContent(): Promise<TextUtils.ContentProvider.DeferredContent>;
    /**
     * @override
     * @param {string} query
     * @param {boolean} caseSensitive
     * @param {boolean} isRegex
     * @return {!Promise<!Array<!TextUtils.ContentProvider.SearchMatch>>}
     */
    searchInContent(query: string, caseSensitive: boolean, isRegex: boolean): Promise<Array<TextUtils.ContentProvider.SearchMatch>>;
    /**
     * @return {boolean}
     */
    isHttpFamily(): boolean;
    /**
     * @return {string|undefined}
     */
    requestContentType(): string | undefined;
    /**
     * @return {boolean}
     */
    hasErrorStatusCode(): boolean;
    /**
     * @param {!Protocol.Network.ResourcePriority} priority
     */
    setInitialPriority(priority: Protocol.Network.ResourcePriority): void;
    /**
     * @return {?Protocol.Network.ResourcePriority}
     */
    initialPriority(): Protocol.Network.ResourcePriority | null;
    /**
     * @param {!Protocol.Network.ResourcePriority} priority
     */
    setPriority(priority: Protocol.Network.ResourcePriority): void;
    /**
     * @return {?Protocol.Network.ResourcePriority}
     */
    priority(): Protocol.Network.ResourcePriority | null;
    /**
     * @param {!Protocol.Network.SignedExchangeInfo} info
     */
    setSignedExchangeInfo(info: Protocol.Network.SignedExchangeInfo): void;
    /**
     * @return {?Protocol.Network.SignedExchangeInfo}
     */
    signedExchangeInfo(): Protocol.Network.SignedExchangeInfo | null;
    /**
     * @param {!HTMLImageElement} image
     */
    populateImageSource(image: HTMLImageElement): Promise<void>;
    /**
     * @return {?Protocol.Network.Initiator}
     */
    initiator(): Protocol.Network.Initiator | null;
    /**
     * @return {!Array.<!WebSocketFrame>}
     */
    frames(): Array<WebSocketFrame>;
    /**
     * @param {string} errorMessage
     * @param {number} time
     */
    addProtocolFrameError(errorMessage: string, time: number): void;
    /**
     * @param {!Protocol.Network.WebSocketFrame} response
     * @param {number} time
     * @param {boolean} sent
     */
    addProtocolFrame(response: Protocol.Network.WebSocketFrame, time: number, sent: boolean): void;
    /**
     * @param {!WebSocketFrame} frame
     */
    addFrame(frame: WebSocketFrame): void;
    /**
     * @return {!Array.<!EventSourceMessage>}
     */
    eventSourceMessages(): Array<EventSourceMessage>;
    /**
     * @param {number} time
     * @param {string} eventName
     * @param {string} eventId
     * @param {string} data
     */
    addEventSourceMessage(time: number, eventName: string, eventId: string, data: string): void;
    /**
     * @param {number} redirectCount
     */
    markAsRedirect(redirectCount: number): void;
    /**
     * @param {string} requestId
     */
    setRequestIdForTest(requestId: string): void;
    /**
     * @return {?string}
     */
    charset(): string | null;
    /**
     * @param {!ExtraRequestInfo} extraRequestInfo
     */
    addExtraRequestInfo(extraRequestInfo: ExtraRequestInfo): void;
    /**
     * @return {boolean}
     */
    hasExtraRequestInfo(): boolean;
    /**
     * @return {!Array<!BlockedCookieWithReason>}
     */
    blockedRequestCookies(): Array<BlockedCookieWithReason>;
    /**
     * @return {!Array<!Cookie>}
     */
    includedRequestCookies(): Array<Cookie>;
    /**
     * @return {boolean}
     */
    hasRequestCookies(): boolean;
    /**
     * @param {!ExtraResponseInfo} extraResponseInfo
     */
    addExtraResponseInfo(extraResponseInfo: ExtraResponseInfo): void;
    /**
     * @return {boolean}
     */
    hasExtraResponseInfo(): boolean;
    /**
     * @return {!Array<!BlockedSetCookieWithReason>}
     */
    blockedResponseCookies(): Array<BlockedSetCookieWithReason>;
}
export type Events = symbol;
export namespace Events {
    export const FinishedLoading: symbol;
    export const TimingChanged: symbol;
    export const RemoteAddressChanged: symbol;
    export const RequestHeadersChanged: symbol;
    export const ResponseHeadersChanged: symbol;
    export const WebsocketFrameAdded: symbol;
    export const EventSourceMessageAdded: symbol;
}
export type InitiatorType = string;
export namespace InitiatorType {
    export const Other: string;
    export const Parser: string;
    export const Redirect: string;
    export const Script: string;
    export const Preload: string;
    export const SignedExchange: string;
}
export type WebSocketFrameType = string;
export namespace WebSocketFrameType {
    export const Send: string;
    export const Receive: string;
    export const Error: string;
}
export function cookieBlockedReasonToUiString(blockedReason: Protocol.Network.CookieBlockedReason): string;
export function setCookieBlockedReasonToUiString(blockedReason: Protocol.Network.SetCookieBlockedReason): string;
export function cookieBlockedReasonToAttribute(blockedReason: Protocol.Network.CookieBlockedReason): Attributes | null;
export function setCookieBlockedReasonToAttribute(blockedReason: Protocol.Network.SetCookieBlockedReason): Attributes | null;
export type NameValue = {
    name: string;
    value: string;
};
/** @typedef {!{name: string, value: string}} */
export let NameValue: any;
export type WebSocketFrame = {
    type: WebSocketFrameType;
    time: number;
    text: string;
    opCode: number;
    mask: boolean;
};
/** @typedef {!{type: WebSocketFrameType, time: number, text: string, opCode: number, mask: boolean}} */
export let WebSocketFrame: any;
export type BlockedSetCookieWithReason = {
    blockedReasons: Array<Protocol.Network.SetCookieBlockedReason>;
    cookieLine: string;
    cookie: Cookie | null;
};
/**
  * @typedef {!{
  *   blockedReasons: !Array<!Protocol.Network.SetCookieBlockedReason>,
  *   cookieLine: string,
  *   cookie: ?Cookie
  * }}
  */
export let BlockedSetCookieWithReason: any;
export type BlockedCookieWithReason = {
    blockedReasons: Array<Protocol.Network.CookieBlockedReason>;
    cookie: Cookie;
};
/**
 * @typedef {!{
 *   blockedReasons: !Array<!Protocol.Network.CookieBlockedReason>,
 *   cookie: !Cookie
 * }}
 */
export let BlockedCookieWithReason: any;
export type ContentData = {
    error: string | null;
    content: string | null;
    encoded: boolean;
};
/** @typedef {!{error: ?string, content: ?string, encoded: boolean}} */
export let ContentData: any;
export type EventSourceMessage = {
    time: number;
    eventName: string;
    eventId: string;
    data: string;
};
/** @typedef {!{time: number, eventName: string, eventId: string, data: string}} */
export let EventSourceMessage: any;
export type ExtraRequestInfo = {
    blockedRequestCookies: Array<BlockedCookieWithReason>;
    requestHeaders: Array<NameValue>;
    includedRequestCookies: Array<Cookie>;
};
/**
  * @typedef {!{
  *   blockedRequestCookies: !Array<!BlockedCookieWithReason>,
  *   requestHeaders: !Array<!NameValue>,
  *   includedRequestCookies: !Array<!Cookie>
  * }}
  */
export let ExtraRequestInfo: any;
export type ExtraResponseInfo = {
    blockedResponseCookies: Array<BlockedSetCookieWithReason>;
    responseHeaders: Array<NameValue>;
    responseHeadersText: (string | undefined);
};
/**
  * @typedef {!{
  *   blockedResponseCookies: !Array<!BlockedSetCookieWithReason>,
  *   responseHeaders: !Array<!NameValue>,
  *   responseHeadersText: (string|undefined)
  * }}
  */
export let ExtraResponseInfo: any;
import * as Common from "../common/common.js";
import * as TextUtils from "../text_utils/text_utils.js";
import { Cookie } from "./Cookie.js";
import { ServerTiming } from "./ServerTiming.js";
import { Attributes } from "./Cookie.js";
