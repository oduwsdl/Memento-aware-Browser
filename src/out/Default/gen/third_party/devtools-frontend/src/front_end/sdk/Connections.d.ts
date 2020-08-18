/**
 * @param {function():!Promise<undefined>} createMainTarget
 * @param {function():void} websocketConnectionLost
 * @return {!Promise<void>}
 */
export function initMainConnection(createMainTarget: () => Promise<undefined>, websocketConnectionLost: () => void): Promise<void>;
/**
 * @param {function():void} websocketConnectionLost
 * @return {!ProtocolClient.InspectorBackend.Connection}
 */
export function _createMainConnection(websocketConnectionLost: () => void): ProtocolClient.InspectorBackend.Connection;
/**
 * @implements {ProtocolClient.InspectorBackend.Connection}
 */
export class MainConnection implements ProtocolClient.InspectorBackend.Connection {
    _onMessage: ((arg0: (Object | string)) => void) | null;
    _onDisconnect: ((arg0: string) => void) | null;
    _messageBuffer: string;
    _messageSize: number;
    _eventListeners: Common.EventTarget.EventDescriptor[];
    /**
     * @override
     * @param {function((!Object|string)):void} onMessage
     */
    setOnMessage(onMessage: (arg0: (Object | string)) => void): void;
    /**
     * @override
     * @param {function(string):void} onDisconnect
     */
    setOnDisconnect(onDisconnect: (arg0: string) => void): void;
    /**
     * @override
     * @param {string} message
     */
    sendRawMessage(message: string): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _dispatchMessage(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _dispatchMessageChunk(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @override
     * @return {!Promise<void>}
     */
    disconnect(): Promise<void>;
}
/**
 * @implements {ProtocolClient.InspectorBackend.Connection}
 */
export class WebSocketConnection implements ProtocolClient.InspectorBackend.Connection {
    /**
     * @param {string} url
     * @param {function():void} onWebSocketDisconnect
     */
    constructor(url: string, onWebSocketDisconnect: () => void);
    /** @type {?WebSocket} */
    _socket: WebSocket | null;
    _onMessage: ((arg0: (Object | string)) => void) | null;
    _onDisconnect: ((arg0: string) => void) | null;
    /** @type {?function():void} */
    _onWebSocketDisconnect: (() => void) | null;
    _connected: boolean;
    /** @type {!Array<string>} */
    _messages: Array<string>;
    /**
     * @override
     * @param {function((!Object|string)):void} onMessage
     */
    setOnMessage(onMessage: (arg0: (Object | string)) => void): void;
    /**
     * @override
     * @param {function(string):void} onDisconnect
     */
    setOnDisconnect(onDisconnect: (arg0: string) => void): void;
    _onError(): void;
    _onOpen(): void;
    _onClose(): void;
    /**
     * @param {function():void=} callback
     */
    _close(callback?: (() => void) | undefined): void;
    /**
     * @override
     * @param {string} message
     */
    sendRawMessage(message: string): void;
    /**
     * @override
     * @return {!Promise<void>}
     */
    disconnect(): Promise<void>;
}
/**
 * @implements {ProtocolClient.InspectorBackend.Connection}
 */
export class StubConnection implements ProtocolClient.InspectorBackend.Connection {
    _onMessage: ((arg0: (Object | string)) => void) | null;
    _onDisconnect: ((arg0: string) => void) | null;
    /**
     * @override
     * @param {function((!Object|string)):void} onMessage
     */
    setOnMessage(onMessage: (arg0: (Object | string)) => void): void;
    /**
     * @override
     * @param {function(string):void} onDisconnect
     */
    setOnDisconnect(onDisconnect: (arg0: string) => void): void;
    /**
     * @override
     * @param {string} message
     */
    sendRawMessage(message: string): void;
    /**
     * @param {string} message
     */
    _respondWithError(message: string): void;
    /**
     * @override
     * @return {!Promise<void>}
     */
    disconnect(): Promise<void>;
}
/**
 * @implements {ProtocolClient.InspectorBackend.Connection}
 */
export class ParallelConnection implements ProtocolClient.InspectorBackend.Connection {
    /**
     * @param {!ProtocolClient.InspectorBackend.Connection} connection
     * @param {string} sessionId
     */
    constructor(connection: ProtocolClient.InspectorBackend.Connection, sessionId: string);
    _connection: ProtocolClient.InspectorBackend.Connection;
    _sessionId: string;
    _onMessage: ((arg0: Object) => void) | null;
    _onDisconnect: ((arg0: string) => void) | null;
    /**
     * @override
     * @param {function(!Object):void} onMessage
     */
    setOnMessage(onMessage: (arg0: Object) => void): void;
    /**
     * @override
     * @param {function(string):void} onDisconnect
     */
    setOnDisconnect(onDisconnect: (arg0: string) => void): void;
    /**
     * @override
     * @param {string} message
     */
    sendRawMessage(message: string): void;
    /**
     * @override
     * @return {!Promise<void>}
     */
    disconnect(): Promise<void>;
}
import * as ProtocolClient from "../protocol_client/protocol_client.js";
import * as Common from "../common/common.js";
