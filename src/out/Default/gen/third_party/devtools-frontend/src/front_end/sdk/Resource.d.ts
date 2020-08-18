/**
 * @implements {TextUtils.ContentProvider.ContentProvider}
 * @unrestricted
 */
export class Resource implements TextUtils.ContentProvider.ContentProvider {
    /**
     * @param {!ResourceTreeModel} resourceTreeModel
     * @param {?NetworkRequest} request
     * @param {string} url
     * @param {string} documentURL
     * @param {!Protocol.Page.FrameId} frameId
     * @param {!Protocol.Network.LoaderId} loaderId
     * @param {!Common.ResourceType.ResourceType} type
     * @param {string} mimeType
     * @param {?Date} lastModified
     * @param {?number} contentSize
     */
    constructor(resourceTreeModel: ResourceTreeModel, request: NetworkRequest | null, url: string, documentURL: string, frameId: Protocol.Page.FrameId, loaderId: Protocol.Network.LoaderId, type: Common.ResourceType.ResourceType, mimeType: string, lastModified: Date | null, contentSize: number | null);
    _resourceTreeModel: ResourceTreeModel;
    _request: NetworkRequest | null;
    /**
     * @param {string} x
     */
    set url(arg: string);
    /**
     * @return {string}
     */
    get url(): string;
    /** @type {string} */
    _url: string;
    _documentURL: string;
    _frameId: string;
    _loaderId: string;
    _type: Common.ResourceType.ResourceType;
    _mimeType: string;
    _lastModified: Date | null;
    _contentSize: number | null;
    /** @type {?string} */ _content: string | null;
    /** @type {?string} */ _contentLoadError: string | null;
    /** @type {boolean} */ _contentEncoded: boolean;
    /** @type {!Array<function(?Object):void>} */
    _pendingContentCallbacks: ((arg0: Object | null) => void)[];
    /**
     * @return {?Date}
     */
    lastModified(): Date | null;
    /**
     * @return {?number}
     */
    contentSize(): number | null;
    /**
     * @return {?NetworkRequest}
     */
    get request(): NetworkRequest | null;
    _parsedURL: Common.ParsedURL.ParsedURL | undefined;
    get parsedURL(): Common.ParsedURL.ParsedURL | undefined;
    /**
     * @return {string}
     */
    get documentURL(): string;
    /**
     * @return {!Protocol.Page.FrameId}
     */
    get frameId(): string;
    /**
     * @return {!Protocol.Network.LoaderId}
     */
    get loaderId(): string;
    /**
     * @return {string}
     */
    get displayName(): string;
    /**
     * @return {!Common.ResourceType.ResourceType}
     */
    resourceType(): Common.ResourceType.ResourceType;
    /**
     * @return {string}
     */
    get mimeType(): string;
    /**
     * @return {?string}
     */
    get content(): string | null;
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
     * @return {string}
     */
    canonicalMimeType(): string;
    /**
     * @override
     * @param {string} query
     * @param {boolean} caseSensitive
     * @param {boolean} isRegex
     * @return {!Promise<!Array<!TextUtils.ContentProvider.SearchMatch>>}
     */
    searchInContent(query: string, caseSensitive: boolean, isRegex: boolean): Promise<Array<TextUtils.ContentProvider.SearchMatch>>;
    /**
     * @param {!HTMLImageElement} image
     */
    populateImageSource(image: HTMLImageElement): Promise<void>;
    _requestFinished(): void;
    _innerRequestContent(): Promise<void>;
    _contentRequested: boolean | undefined;
    /**
     * @return {boolean}
     */
    hasTextContent(): boolean;
    /**
     * @return {!ResourceTreeFrame}
     */
    frame(): ResourceTreeFrame;
}
import * as TextUtils from "../text_utils/text_utils.js";
import { ResourceTreeModel } from "./ResourceTreeModel.js";
import { NetworkRequest } from "./NetworkRequest.js";
import * as Common from "../common/common.js";
import { ResourceTreeFrame } from "./ResourceTreeModel.js";
