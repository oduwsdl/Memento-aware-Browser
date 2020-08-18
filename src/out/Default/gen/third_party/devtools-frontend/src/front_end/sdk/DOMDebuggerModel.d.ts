export class DOMDebuggerModel extends SDKModel {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _agent: ProtocolProxyApi.DOMDebuggerApi;
    _runtimeModel: RuntimeModel;
    _domModel: DOMModel;
    /** @type {!Array<!DOMBreakpoint>} */
    _domBreakpoints: Array<DOMBreakpoint>;
    _domBreakpointsSetting: Common.Settings.Setting<any>;
    /**
     * @return {!RuntimeModel}
     */
    runtimeModel(): RuntimeModel;
    /**
     * @param {!RemoteObject} remoteObject
     * @return {!Promise<!Array<!EventListener>>}
     */
    eventListeners(remoteObject: RemoteObject): Promise<Array<EventListener>>;
    retrieveDOMBreakpoints(): void;
    /**
     * @return {!Array<!DOMBreakpoint>}
     */
    domBreakpoints(): Array<DOMBreakpoint>;
    /**
     * @param {!DOMNode} node
     * @param {!Protocol.DOMDebugger.DOMBreakpointType} type
     * @return {boolean}
     */
    hasDOMBreakpoint(node: DOMNode, type: Protocol.DOMDebugger.DOMBreakpointType): boolean;
    /**
     * @param {!DOMNode} node
     * @param {!Protocol.DOMDebugger.DOMBreakpointType} type
     * @return {!DOMBreakpoint}
     */
    setDOMBreakpoint(node: DOMNode, type: Protocol.DOMDebugger.DOMBreakpointType): DOMBreakpoint;
    /**
     * @param {!DOMNode} node
     * @param {!Protocol.DOMDebugger.DOMBreakpointType} type
     */
    removeDOMBreakpoint(node: DOMNode, type: Protocol.DOMDebugger.DOMBreakpointType): void;
    removeAllDOMBreakpoints(): void;
    /**
     * @param {!DOMBreakpoint} breakpoint
     * @param {boolean} enabled
     */
    toggleDOMBreakpoint(breakpoint: DOMBreakpoint, enabled: boolean): void;
    /**
     * @param {!DOMBreakpoint} breakpoint
     */
    _enableDOMBreakpoint(breakpoint: DOMBreakpoint): void;
    /**
     * @param {!DOMBreakpoint} breakpoint
     */
    _disableDOMBreakpoint(breakpoint: DOMBreakpoint): void;
    /**
     * @param {!DOMNode} node
     * @return {boolean}
     */
    _nodeHasBreakpoints(node: DOMNode): boolean;
    /**
     * @param {{type: !Protocol.DOMDebugger.DOMBreakpointType, nodeId: !Protocol.DOM.NodeId, targetNodeId: !Protocol.DOM.NodeId, insertion: boolean}} auxData
     * @return {?{type: !Protocol.DOMDebugger.DOMBreakpointType, node: !DOMNode, targetNode: ?DOMNode, insertion: boolean}}
     */
    resolveDOMBreakpointData(auxData: {
        type: Protocol.DOMDebugger.DOMBreakpointType;
        nodeId: Protocol.DOM.NodeId;
        targetNodeId: Protocol.DOM.NodeId;
        insertion: boolean;
    }): {
        type: Protocol.DOMDebugger.DOMBreakpointType;
        node: DOMNode;
        targetNode: DOMNode | null;
        insertion: boolean;
    } | null;
    /**
     * @return {string}
     */
    _currentURL(): string;
    _documentUpdated(): void;
    /**
     * @param {function(!DOMBreakpoint):boolean} filter
     */
    _removeDOMBreakpoints(filter: (arg0: DOMBreakpoint) => boolean): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _nodeRemoved(event: Common.EventTarget.EventTargetEvent): void;
    _saveDOMBreakpoints(): void;
}
export type Events = symbol;
export namespace Events {
    export const DOMBreakpointAdded: symbol;
    export const DOMBreakpointToggled: symbol;
    export const DOMBreakpointsRemoved: symbol;
}
export class DOMBreakpoint {
    /**
     * @param {!DOMDebuggerModel} domDebuggerModel
     * @param {!DOMNode} node
     * @param {!Protocol.DOMDebugger.DOMBreakpointType} type
     * @param {boolean} enabled
     */
    constructor(domDebuggerModel: DOMDebuggerModel, node: DOMNode, type: Protocol.DOMDebugger.DOMBreakpointType, enabled: boolean);
    domDebuggerModel: DOMDebuggerModel;
    node: DOMNode;
    type: Protocol.DOMDebugger.DOMBreakpointType;
    enabled: boolean;
}
export class EventListener {
    /**
     * @param {!DOMDebuggerModel} domDebuggerModel
     * @param {!RemoteObject} eventTarget
     * @param {string} type
     * @param {boolean} useCapture
     * @param {boolean} passive
     * @param {boolean} once
     * @param {?RemoteObject} handler
     * @param {?RemoteObject} originalHandler
     * @param {!Location} location
     * @param {?RemoteObject} customRemoveFunction
     * @param {!EventListener.Origin=} origin
     */
    constructor(domDebuggerModel: DOMDebuggerModel, eventTarget: RemoteObject, type: string, useCapture: boolean, passive: boolean, once: boolean, handler: RemoteObject | null, originalHandler: RemoteObject | null, location: Location, customRemoveFunction: RemoteObject | null, origin?: EventListener.Origin | undefined);
    _domDebuggerModel: DOMDebuggerModel;
    _eventTarget: RemoteObject;
    _type: string;
    _useCapture: boolean;
    _passive: boolean;
    _once: boolean;
    _handler: RemoteObject | null;
    _originalHandler: RemoteObject | null;
    _location: Location;
    _sourceURL: string;
    _customRemoveFunction: RemoteObject | null;
    _origin: string;
    /**
     * @return {!DOMDebuggerModel}
     */
    domDebuggerModel(): DOMDebuggerModel;
    /**
     * @return {string}
     */
    type(): string;
    /**
     * @return {boolean}
     */
    useCapture(): boolean;
    /**
     * @return {boolean}
     */
    passive(): boolean;
    /**
     * @return {boolean}
     */
    once(): boolean;
    /**
     * @return {?RemoteObject}
     */
    handler(): RemoteObject | null;
    /**
     * @return {!Location}
     */
    location(): Location;
    /**
     * @return {string}
     */
    sourceURL(): string;
    /**
     * @return {?RemoteObject}
     */
    originalHandler(): RemoteObject | null;
    /**
     * @return {boolean}
     */
    canRemove(): boolean;
    /**
     * @return {!Promise<undefined>}
     */
    remove(): Promise<undefined>;
    /**
     * @return {boolean}
     */
    canTogglePassive(): boolean;
    /**
     * @return {!Promise<undefined>}
     */
    togglePassive(): Promise<undefined>;
    /**
     * @return {!EventListener.Origin}
     */
    origin(): EventListener.Origin;
    markAsFramework(): void;
    /**
     * @return {boolean}
     */
    isScrollBlockingType(): boolean;
}
export namespace EventListener {
    export namespace Origin {
        export const Raw: string;
        export const Framework: string;
        export const FrameworkUser: string;
    }
    export type Origin = string;
}
export class EventListenerBreakpoint {
    /**
     * @param {string} instrumentationName
     * @param {string} eventName
     * @param {!Array<string>} eventTargetNames
     * @param {string} category
     * @param {string} title
     */
    constructor(instrumentationName: string, eventName: string, eventTargetNames: Array<string>, category: string, title: string);
    _instrumentationName: string;
    _eventName: string;
    _eventTargetNames: string[];
    _category: string;
    _title: string;
    /** @type {boolean} */
    _enabled: boolean;
    /**
     * @return {string}
     */
    category(): string;
    /**
     * @return {boolean}
     */
    enabled(): boolean;
    /**
     * @param {boolean} enabled
     */
    setEnabled(enabled: boolean): void;
    /**
     * @param {!DOMDebuggerModel} model
     */
    _updateOnModel(model: DOMDebuggerModel): void;
    /**
     * @return {string}
     */
    title(): string;
}
export namespace EventListenerBreakpoint {
    export const _listener: string;
    export const _instrumentation: string;
}
/**
 * @implements {SDKModelObserver<!DOMDebuggerModel>}
 */
export class DOMDebuggerManager implements SDKModelObserver<DOMDebuggerModel> {
    _xhrBreakpointsSetting: Common.Settings.Setting<any>;
    /** @type {!Map<string, boolean>} */
    _xhrBreakpoints: Map<string, boolean>;
    /** @type {!Array<!EventListenerBreakpoint>} */
    _eventListenerBreakpoints: Array<EventListenerBreakpoint>;
    /**
     * @param {string} category
     * @param {!Array<string>} instrumentationNames
     */
    _createInstrumentationBreakpoints(category: string, instrumentationNames: Array<string>): void;
    /**
     * @param {string} category
     * @param {!Array<string>} eventNames
     * @param {!Array<string>} eventTargetNames
     */
    _createEventListenerBreakpoints(category: string, eventNames: Array<string>, eventTargetNames: Array<string>): void;
    /**
     * @param {string} eventName
     * @param {string=} eventTargetName
     * @return {?EventListenerBreakpoint}
     */
    _resolveEventListenerBreakpoint(eventName: string, eventTargetName?: string | undefined): EventListenerBreakpoint | null;
    /**
     * @return {!Array<!EventListenerBreakpoint>}
     */
    eventListenerBreakpoints(): Array<EventListenerBreakpoint>;
    /**
     * @param {!{eventName: string, webglErrorName: string, directiveText: string, targetName: string}} auxData
     * @return {string}
     */
    resolveEventListenerBreakpointTitle(auxData: {
        eventName: string;
        webglErrorName: string;
        directiveText: string;
        targetName: string;
    }): string;
    /**
     * @param {!{eventName: string, targetName: string}} auxData
     * @return {?EventListenerBreakpoint}
     */
    resolveEventListenerBreakpoint(auxData: {
        eventName: string;
        targetName: string;
    }): EventListenerBreakpoint | null;
    /**
     * @return {!Map<string, boolean>}
     */
    xhrBreakpoints(): Map<string, boolean>;
    _saveXHRBreakpoints(): void;
    /**
     * @param {string} url
     * @param {boolean} enabled
     */
    addXHRBreakpoint(url: string, enabled: boolean): void;
    /**
     * @param {string} url
     */
    removeXHRBreakpoint(url: string): void;
    /**
     * @param {string} url
     * @param {boolean} enabled
     */
    toggleXHRBreakpoint(url: string, enabled: boolean): void;
    /**
     * @override
     * @param {!DOMDebuggerModel} domDebuggerModel
     */
    modelAdded(domDebuggerModel: DOMDebuggerModel): void;
    /**
     * @override
     * @param {!DOMDebuggerModel} domDebuggerModel
     */
    modelRemoved(domDebuggerModel: DOMDebuggerModel): void;
}
import { SDKModel } from "./SDKModel.js";
import { RuntimeModel } from "./RuntimeModel.js";
import { DOMModel } from "./DOMModel.js";
import * as Common from "../common/common.js";
import { RemoteObject } from "./RemoteObject.js";
import { DOMNode } from "./DOMModel.js";
import { Target } from "./SDKModel.js";
import { Location } from "./DebuggerModel.js";
import { SDKModelObserver } from "./SDKModel.js";
