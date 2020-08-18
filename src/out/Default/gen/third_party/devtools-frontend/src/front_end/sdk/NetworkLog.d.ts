/**
 * @implements {SDKModelObserver<!NetworkManager>}
 */
export class NetworkLog extends Common.ObjectWrapper.ObjectWrapper implements SDKModelObserver<NetworkManager> {
    /**
     * @return {!NetworkLog}
     */
    static instance(): NetworkLog;
    /**
     * @param {!ConsoleMessage} consoleMessage
     * @return {?NetworkRequest}
     */
    static requestForConsoleMessage(consoleMessage: ConsoleMessage): NetworkRequest | null;
    /** @type {!Array<!NetworkRequest>} */
    _requests: Array<NetworkRequest>;
    /** @type {!Array<!Protocol.Network.Request>} */
    _sentNetworkRequests: Array<Protocol.Network.Request>;
    /** @type {!Array<!Protocol.Network.Response>} */
    _receivedNetworkResponses: Array<Protocol.Network.Response>;
    /** @type {!Set<!NetworkRequest>} */
    _requestsSet: Set<NetworkRequest>;
    /** @type {!Map<string, !Array<!NetworkRequest>>} */
    _requestsMap: Map<string, Array<NetworkRequest>>;
    /** @type {!Map<!NetworkManager, !PageLoad>} */
    _pageLoadForManager: Map<NetworkManager, PageLoad>;
    /** @type {boolean} */
    _isRecording: boolean;
    /** @type {!WeakMap<!NetworkManager, !Array<!Common.EventTarget.EventDescriptor>>} */
    _modelListeners: WeakMap<NetworkManager, Array<Common.EventTarget.EventDescriptor>>;
    /** @type {!WeakMap<!NetworkRequest, !InitiatorData>} */
    _initiatorData: WeakMap<NetworkRequest, InitiatorData>;
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
     * @param {!NetworkManager} networkManager
     */
    _removeNetworkManagerListeners(networkManager: NetworkManager): void;
    /**
     * @param {boolean} enabled
     */
    setIsRecording(enabled: boolean): void;
    /**
     * @param {string} url
     * @return {?NetworkRequest}
     */
    requestForURL(url: string): NetworkRequest | null;
    /**
     * @param {string} url
     * @return {?Protocol.Network.Request}
     */
    originalRequestForURL(url: string): Protocol.Network.Request | null;
    /**
     * @param {string} url
     * @return {?Protocol.Network.Response}
     */
    originalResponseForURL(url: string): Protocol.Network.Response | null;
    /**
     * @return {!Array<!NetworkRequest>}
     */
    requests(): Array<NetworkRequest>;
    /**
     * @param {!NetworkManager} networkManager
     * @param {!Protocol.Network.RequestId} requestId
     * @return {?NetworkRequest}
     */
    requestByManagerAndId(networkManager: NetworkManager, requestId: Protocol.Network.RequestId): NetworkRequest | null;
    /**
     * @param {!NetworkManager} networkManager
     * @param {string} url
     * @return {?NetworkRequest}
     */
    _requestByManagerAndURL(networkManager: NetworkManager, url: string): NetworkRequest | null;
    /**
     * @param {!NetworkRequest} request
     * @return {!InitiatorData}
     */
    _initializeInitiatorSymbolIfNeeded(request: NetworkRequest): InitiatorData;
    /**
     * @param {!NetworkRequest} request
     * @return {!_InitiatorInfo}
     */
    initiatorInfoForRequest(request: NetworkRequest): _InitiatorInfo;
    /**
     * @param {!NetworkRequest} request
     * @return {!InitiatorGraph}
     */
    initiatorGraphForRequest(request: NetworkRequest): InitiatorGraph;
    /**
     * @param {!NetworkRequest} request
     * @return {!Set<!NetworkRequest>}
     */
    _initiatorChain(request: NetworkRequest): Set<NetworkRequest>;
    /**
     * @param {!NetworkRequest} request
     * @return {?NetworkRequest}
     */
    _initiatorRequest(request: NetworkRequest): NetworkRequest | null;
    _willReloadPage(): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onMainFrameNavigated(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!NetworkRequest} request
     */
    _addRequest(request: NetworkRequest): void;
    /**
     * @param {!Array<!NetworkRequest>} requests
     */
    importRequests(requests: Array<NetworkRequest>): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onRequestStarted(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onResponseReceived(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onRequestUpdated(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onRequestRedirect(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!ResourceTreeModel} resourceTreeModel
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onDOMContentLoaded(resourceTreeModel: ResourceTreeModel, event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onLoad(event: Common.EventTarget.EventTargetEvent): void;
    reset(): void;
    /**
     * @param {!NetworkManager} networkManager
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _networkMessageGenerated(networkManager: NetworkManager, event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!ConsoleMessage} consoleMessage
     * @param {!Protocol.Network.RequestId} requestId
     */
    associateConsoleMessageWithRequest(consoleMessage: ConsoleMessage, requestId: Protocol.Network.RequestId): void;
    /**
     * @param {string} requestId
     * @return {!Array<!NetworkRequest>}
     */
    requestsForId(requestId: string): Array<NetworkRequest>;
}
export class PageLoad {
    /**
     * @param {!NetworkRequest} request
     * @return {?PageLoad}
     */
    static forRequest(request: NetworkRequest): PageLoad | null;
    /**
     * @param {!NetworkRequest} mainRequest
     */
    constructor(mainRequest: NetworkRequest);
    id: number;
    url: string;
    startTime: number;
    /** @type {number} */
    loadTime: number;
    /** @type {number} */
    contentLoadTime: number;
    mainRequest: NetworkRequest;
    _showDataSaverWarningIfNeeded(): Promise<void>;
    /**
     * @param {!NetworkRequest} request
     */
    bindRequest(request: NetworkRequest): void;
}
export namespace PageLoad {
    export const _lastIdentifier: number;
    export const _dataSaverMessageWasShown: boolean;
}
export namespace Events {
    export const Reset: symbol;
    export const RequestAdded: symbol;
    export const RequestUpdated: symbol;
}
export type InitiatorGraph = {
    initiators: Set<NetworkRequest>;
    initiated: Map<NetworkRequest, NetworkRequest>;
};
/** @typedef {!{initiators: !Set<!NetworkRequest>, initiated: !Map<!NetworkRequest, !NetworkRequest>}} */
export let InitiatorGraph: any;
export type _InitiatorInfo = {
    type: InitiatorType;
    url: string;
    lineNumber: number;
    columnNumber: number;
    scriptId: string | null;
    stack: Protocol.Runtime.StackTrace | null;
};
/** @typedef {!{type: !InitiatorType, url: string, lineNumber: number, columnNumber: number, scriptId: ?string, stack: ?Protocol.Runtime.StackTrace}} */
export let _InitiatorInfo: any;
export type InitiatorData = {
    info: _InitiatorInfo | null;
    chain: Set<NetworkRequest> | null;
    request: ((NetworkRequest | undefined) | null);
};
import * as Common from "../common/common.js";
import { NetworkManager } from "./NetworkManager.js";
import { SDKModelObserver } from "./SDKModel.js";
import { NetworkRequest } from "./NetworkRequest.js";
/**
 * @typedef {!{info: ?_InitiatorInfo, chain: ?Set<!NetworkRequest>, request: (?NetworkRequest|undefined)}}
 */
declare let InitiatorData: any;
import { ResourceTreeModel } from "./ResourceTreeModel.js";
import { ConsoleMessage } from "./ConsoleModel.js";
import { InitiatorType } from "./NetworkRequest.js";
export {};
