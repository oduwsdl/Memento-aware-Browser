export type ProtocolError = string;
/**
 * @typedef {string}
 * @suppress {checkTypes}
 */
export const ProtocolError: unique symbol;
export const DevToolsStubErrorCode: -32015;
/**
 * @unrestricted
 */
export class InspectorBackend {
    /**
     * @param {string} error
     * @param {!Object} messageObject
     */
    static reportProtocolError(error: string, messageObject: Object): void;
    /** @type {!Map<string, !_AgentPrototype>} */
    _agentPrototypes: Map<string, _AgentPrototype>;
    /** @type {!Map<string, !_DispatcherPrototype>} */
    _dispatcherPrototypes: Map<string, _DispatcherPrototype>;
    _initialized: boolean;
    /**
     * @return {boolean}
     */
    isInitialized(): boolean;
    /**
     * @param {string} domain
     */
    _addAgentGetterMethodToProtocolTargetPrototype(domain: string): void;
    /**
     * @param {string} domain
     * @return {!_AgentPrototype}
     */
    _agentPrototype(domain: string): _AgentPrototype;
    /**
     * @param {string} domain
     * @return {!_DispatcherPrototype}
     */
    _dispatcherPrototype(domain: string): _DispatcherPrototype;
    /**
     * @param {string} method
     * @param {!Array.<!{name: string, type: string, optional: boolean}>} signature
     * @param {!Array.<string>} replyArgs
     */
    registerCommand(method: string, signature: Array<{
        name: string;
        type: string;
        optional: boolean;
    }>, replyArgs: Array<string>): void;
    /**
     * @param {string} type
     * @param {!Object} values
     */
    registerEnum(type: string, values: Object): void;
    /**
     * @param {string} eventName
     * @param {!Object} params
     */
    registerEvent(eventName: string, params: Object): void;
    /**
     * @param {function((T|undefined)):void} clientCallback
     * @param {string} errorPrefix
     * @param {function(new:T,S):void=} constructor
     * @param {T=} defaultValue
     * @return {function(?string, S):void}
     * @template T,S
     */
    wrapClientCallback<T, S>(clientCallback: (arg0: T | undefined) => void, errorPrefix: string, constructor?: (new (arg1: S) => T) | undefined, defaultValue?: T | undefined): (arg0: string | null, arg1: S) => void;
}
/**
 * @interface
 */
export class Connection {
    /**
     * @param {function():!Connection} factory
     */
    static setFactory(factory: () => Connection): void;
    /**
     * @return {function():!Connection}
     */
    static getFactory(): () => Connection;
    /** @type {?function(!Object):void} */
    _onMessage: ((arg0: Object) => void) | null;
    /**
     * @param {function((!Object|string)):void} onMessage
     */
    setOnMessage(onMessage: (arg0: (Object | string)) => void): void;
    /**
     * @param {function(string):void} onDisconnect
     */
    setOnDisconnect(onDisconnect: (arg0: string) => void): void;
    /**
     * @param {string} message
     */
    sendRawMessage(message: string): void;
    /**
     * @return {!Promise<void>}
     */
    disconnect(): Promise<void>;
}
export namespace test {
    export const dumpProtocol: ((arg0: string) => void) | null;
    export const deprecatedRunAfterPendingDispatches: ((arg0: (() => void) | undefined) => void) | null;
    export const sendRawMessage: ((arg0: string, arg1: Object | null, arg2: SendRawMessageCallback | null) => void) | null;
    export const suppressRequestErrors: boolean;
    export const onMessageSent: ((arg0: {
        domain: string;
        method: string;
        params: Object;
        id: number;
    }, arg1: TargetBase | null) => void) | null;
    export const onMessageReceived: ((arg0: Object, arg1: TargetBase | null) => void) | null;
}
export class SessionRouter {
    /**
     * @param {!_Callback} callback
     */
    static dispatchConnectionError(callback: _Callback): void;
    /**
     * @param {!Connection} connection
     */
    constructor(connection: Connection);
    _connection: Connection;
    _lastMessageId: number;
    _pendingResponsesCount: number;
    _domainToLogger: Map<any, any>;
    /** @type {!Map<string, {target: !TargetBase, callbacks: !Map<number, !_Callback>, proxyConnection: (?Connection|undefined)}>} */
    _sessions: Map<string, {
        target: TargetBase;
        callbacks: Map<number, _Callback>;
        proxyConnection: ((Connection | undefined) | null);
    }>;
    /** @type {!Array<function():void>} */
    _pendingScripts: (() => void)[];
    /**
     * @param {!TargetBase} target
     * @param {string} sessionId
     * @param {?Connection=} proxyConnection
     */
    registerSession(target: TargetBase, sessionId: string, proxyConnection?: (Connection | null) | undefined): void;
    /**
     * @param {string} sessionId
     */
    unregisterSession(sessionId: string): void;
    /**
     * @param {string} sessionId
     * @return {?TargetBase}
     */
    _getTargetBySessionId(sessionId: string): TargetBase | null;
    /**
     * @return {number}
     */
    _nextMessageId(): number;
    /**
     * @return {!Connection}
     */
    connection(): Connection;
    /**
     * @param {string} sessionId
     * @param {string} domain
     * @param {string} method
     * @param {?Object} params
     * @param {!_Callback} callback
     */
    sendMessage(sessionId: string, domain: string, method: string, params: Object | null, callback: _Callback): void;
    /**
     * @param {string} method
     * @param {?Object} params
     * @param {?function(...*):void} callback
     */
    _sendRawMessageForTesting(method: string, params: Object | null, callback: ((...args: any[]) => void) | null): void;
    /**
     * @param {!Object|string} message
     */
    _onMessage(message: Object | string): void;
    /**
     * @param {function():void=} script
     */
    _deprecatedRunAfterPendingDispatches(script?: (() => void) | undefined): void;
    _executeAfterPendingDispatches(): void;
}
/**
 * @unrestricted
 */
export class TargetBase {
    /**
     * @param {boolean} needsNodeJSPatching
     * @param {?TargetBase} parentTarget
     * @param {string} sessionId
     * @param {?Connection} connection
     */
    constructor(needsNodeJSPatching: boolean, parentTarget: TargetBase | null, sessionId: string, connection: Connection | null);
    _needsNodeJSPatching: boolean;
    _sessionId: string;
    /** @type {?SessionRouter} */
    _router: SessionRouter | null;
    /** @type {!Object<string,!_AgentPrototype>} */
    _agents: {
        [x: string]: _AgentPrototype;
    };
    /** @type {!Object<string,_DispatcherPrototype>} */
    _dispatchers: {
        [x: string]: _DispatcherPrototype;
    };
    /**
     * @param {string} domain
     * @param {!Object} dispatcher
     */
    registerDispatcher(domain: string, dispatcher: Object): void;
    /**
     * @param {string} reason
     */
    dispose(reason: string): void;
    /**
     * @return {boolean}
     */
    isDisposed(): boolean;
    markAsNodeJSForTest(): void;
    /**
     * @return {?SessionRouter}
     */
    router(): SessionRouter | null;
    /**
     * @return {!ProtocolProxyApi.AuditsApi}
     */
    auditsAgent(): ProtocolProxyApi.AuditsApi;
    /**
     * @return {!ProtocolProxyApi.CacheStorageApi}
     */
    cacheStorageAgent(): ProtocolProxyApi.CacheStorageApi;
    /**
     * @return {!ProtocolProxyApi.DebuggerApi}
     */
    debuggerAgent(): ProtocolProxyApi.DebuggerApi;
    /**
     * @return {!ProtocolProxyApi.DOMDebuggerApi}
     */
    domdebuggerAgent(): ProtocolProxyApi.DOMDebuggerApi;
    /**
     * @return {!ProtocolProxyApi.HeapProfilerApi}
     */
    heapProfilerAgent(): ProtocolProxyApi.HeapProfilerApi;
    /**
     * @return {!ProtocolProxyApi.LayerTreeApi}
     */
    layerTreeAgent(): ProtocolProxyApi.LayerTreeApi;
    /**
     * @return {!ProtocolProxyApi.MemoryApi}
     */
    memoryAgent(): ProtocolProxyApi.MemoryApi;
    /**
     * @return {!ProtocolProxyApi.NetworkApi}
     */
    networkAgent(): ProtocolProxyApi.NetworkApi;
    /**
     * @return {!ProtocolProxyApi.PageApi}
     */
    pageAgent(): ProtocolProxyApi.PageApi;
    /**
     * @return {!ProtocolProxyApi.PerformanceApi}
     */
    performanceAgent(): ProtocolProxyApi.PerformanceApi;
    /**
     * @return {!ProtocolProxyApi.RuntimeApi}
     */
    runtimeAgent(): ProtocolProxyApi.RuntimeApi;
    /**
     * @return {!ProtocolProxyApi.ServiceWorkerApi}
     */
    serviceWorkerAgent(): ProtocolProxyApi.ServiceWorkerApi;
    /**
     * @return {!ProtocolProxyApi.StorageApi}
     */
    storageAgent(): ProtocolProxyApi.StorageApi;
    /**
     * @return {!ProtocolProxyApi.TargetApi}
     */
    targetAgent(): ProtocolProxyApi.TargetApi;
    /**
     * @param {!ProtocolProxyApi.AuditsDispatcher} dispatcher
     */
    registerAuditsDispatcher(dispatcher: ProtocolProxyApi.AuditsDispatcher): void;
    /**
     * @param {!ProtocolProxyApi.DebuggerDispatcher} dispatcher
     */
    registerDebuggerDispatcher(dispatcher: ProtocolProxyApi.DebuggerDispatcher): void;
    /**
     * @param {!ProtocolProxyApi.DOMDispatcher} dispatcher
     */
    registerDOMDispatcher(dispatcher: ProtocolProxyApi.DOMDispatcher): void;
    /**
     * @param {!ProtocolProxyApi.HeapProfilerDispatcher} dispatcher
     */
    registerHeapProfilerDispatcher(dispatcher: ProtocolProxyApi.HeapProfilerDispatcher): void;
    /**
     * @param {!ProtocolProxyApi.NetworkDispatcher} dispatcher
     */
    registerNetworkDispatcher(dispatcher: ProtocolProxyApi.NetworkDispatcher): void;
    /**
     * @param {!ProtocolProxyApi.PageDispatcher} dispatcher
     */
    registerPageDispatcher(dispatcher: ProtocolProxyApi.PageDispatcher): void;
    /**
     * @param {!ProtocolProxyApi.StorageDispatcher} dispatcher
     */
    registerStorageDispatcher(dispatcher: ProtocolProxyApi.StorageDispatcher): void;
    /**
     * @param {!ProtocolProxyApi.ServiceWorkerDispatcher} dispatcher
     */
    registerServiceWorkerDispatcher(dispatcher: ProtocolProxyApi.ServiceWorkerDispatcher): void;
    /**
     * @param {!ProtocolProxyApi.TargetDispatcher} dispatcher
     */
    registerTargetDispatcher(dispatcher: ProtocolProxyApi.TargetDispatcher): void;
}
/**
 * Takes error and result.
 */
export type _Callback = (arg0: Object | null, arg1: Object | null) => void;
/**
 * Takes error and result.
 * @typedef {function(?Object, ?Object):void}
 */
export let _Callback: any;
export const inspectorBackend: InspectorBackend;
export type SendRawMessageCallback = (...arg0: any[]) => void;
/**
 * @unrestricted
 */
declare class _AgentPrototype {
    /**
     * @param {string} domain
     */
    constructor(domain: string);
    /** @type {!Object<string, !Array<string>>} */
    _replyArgs: {
        [x: string]: Array<string>;
    };
    _domain: string;
    /** @type {!TargetBase} */
    _target: TargetBase;
    /**
     * @param {string} methodName
     * @param {!Array.<!{name: string, type: string, optional: boolean}>} signature
     * @param {!Array.<string>} replyArgs
     */
    registerCommand(methodName: string, signature: Array<{
        name: string;
        type: string;
        optional: boolean;
    }>, replyArgs: Array<string>): void;
    /**
     * @param {string} method
     * @param {!Array.<!{name: string, type: string, optional: boolean}>} signature
     * @param {!Array.<*>} args
     * @param {function(string):void} errorCallback
     * @return {?Object}
     */
    _prepareParameters(method: string, signature: Array<{
        name: string;
        type: string;
        optional: boolean;
    }>, args: Array<any>, errorCallback: (arg0: string) => void): Object | null;
    /**
     * @param {string} method
     * @param {!Array<!{name: string, type: string, optional: boolean}>} signature
     * @param {!Array<*>} args
     * @return {!Promise<?>}
     */
    _sendMessageToBackendPromise(method: string, signature: Array<{
        name: string;
        type: string;
        optional: boolean;
    }>, args: Array<any>): Promise<unknown>;
    /**
     * @param {string} method
     * @param {?Object} request
     * @return {!Promise<!Object>}
     */
    _invoke(method: string, request: Object | null): Promise<Object>;
}
/**
 * @unrestricted
 */
declare class _DispatcherPrototype {
    /** @type {!Object<string, *>} */
    _eventArgs: {
        [x: string]: any;
    };
    /** @type {!Array<*>} */
    _dispatchers: Array<any>;
    /**
     * @param {string} eventName
     * @param {!Object} params
     */
    registerEvent(eventName: string, params: Object): void;
    /**
     * @param {!Object} dispatcher
     */
    addDomainDispatcher(dispatcher: Object): void;
    /**
     * @param {string} functionName
     * @param {!{method: string, params: ?Array<string>}} messageObject
     */
    dispatch(functionName: string, messageObject: {
        method: string;
        params: Array<string> | null;
    }): void;
}
/** @typedef {function(...*):void} */
declare let SendRawMessageCallback: any;
export {};
