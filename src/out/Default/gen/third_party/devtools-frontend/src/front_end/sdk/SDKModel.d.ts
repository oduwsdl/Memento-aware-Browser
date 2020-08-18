export class SDKModel extends Common.ObjectWrapper.ObjectWrapper {
    /**
     * @param {function(new:SDKModel, !Target)} modelClass
     * @param {number} capabilities
     * @param {boolean} autostart
     */
    static register(modelClass: new (arg1: Target) => SDKModel, capabilities: number, autostart: boolean): void;
    static get registeredModels(): Map<new (arg1: Target) => SDKModel, {
        capabilities: number;
        autostart: boolean;
    }>;
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _target: Target;
    /**
     * @return {!Target}
     */
    target(): Target;
    /**
     * Override this method to perform tasks that are required to suspend the
     * model and that still need other models in an unsuspended state.
     * @param {string=} reason - optionally provide a reason, the model can respond accordingly
     * @return {!Promise<void>}
     */
    preSuspendModel(reason?: string | undefined): Promise<void>;
    /**
     * @param {string=} reason - optionally provide a reason, the model can respond accordingly
     * @return {!Promise<void>}
     */
    suspendModel(reason?: string | undefined): Promise<void>;
    /**
     * @return {!Promise<void>}
     */
    resumeModel(): Promise<void>;
    /**
     * Override this method to perform tasks that are required to after resuming
     * the model and that require all models already in an unsuspended state.
     * @return {!Promise<void>}
     */
    postResumeModel(): Promise<void>;
    dispose(): void;
}
/**
 * @unrestricted
 */
export class Target extends ProtocolClient.InspectorBackend.TargetBase {
    /**
     * @param {!TargetManager} targetManager
     * @param {string} id
     * @param {string} name
     * @param {!Type} type
     * @param {?Target} parentTarget
     * @param {string} sessionId
     * @param {boolean} suspended
     * @param {?ProtocolClient.InspectorBackend.Connection} connection
     */
    constructor(targetManager: TargetManager, id: string, name: string, type: Type, parentTarget: Target | null, sessionId: string, suspended: boolean, connection: ProtocolClient.InspectorBackend.Connection | null);
    _targetManager: TargetManager;
    _name: string;
    _inspectedURL: string;
    _inspectedURLName: string;
    _capabilitiesMask: number;
    _type: string;
    _parentTarget: Target | null;
    _id: string;
    _modelByConstructor: Map<any, any>;
    _isSuspended: boolean;
    /**
     * TODO(1011811): Replace type with !Set<function(new:SDKModel, !Target)> once we no longer type-check with closure.
     * @param {*} required
     */
    createModels(required: any): void;
    _creatingModels: boolean | undefined;
    /**
     * @return {string}
     */
    id(): string;
    /**
     * @return {string}
     */
    name(): string;
    /**
     * @return {!Type}
     */
    type(): Type;
    /**
     * @return {!TargetManager}
     */
    targetManager(): TargetManager;
    /**
     * @param {number} capabilitiesMask
     * @return {boolean}
     */
    hasAllCapabilities(capabilitiesMask: number): boolean;
    /**
     * @param {string} label
     * @return {string}
     */
    decorateLabel(label: string): string;
    /**
     * @return {?Target}
     */
    parentTarget(): Target | null;
    /**
     * @param {function(new:SDKModel, !Target)} modelClass
     * @return {?T}
     * @template T
     */
    model<T>(modelClass: new (arg1: Target) => SDKModel): T | null;
    /**
     * @return {!Map<function(new:SDKModel, !Target), !SDKModel>}
     */
    models(): Map<new (arg1: Target) => SDKModel, SDKModel>;
    /**
     * @return {string}
     */
    inspectedURL(): string;
    /**
     * @param {string} inspectedURL
     */
    setInspectedURL(inspectedURL: string): void;
    /**
     * @param {string=} reason - optionally provide a reason, so models can respond accordingly
     * @return {!Promise<void>}
     */
    suspend(reason?: string | undefined): Promise<void>;
    /**
     * @return {!Promise<void>}
     */
    resume(): Promise<void>;
    /**
     * @return {boolean}
     */
    suspended(): boolean;
}
export type Capability = number;
export namespace Capability {
    export const Browser: number;
    export const DOM: number;
    export const JS: number;
    export const Log: number;
    export const Network: number;
    const Target_1: number;
    export { Target_1 as Target };
    export const ScreenCapture: number;
    export const Tracing: number;
    export const Emulation: number;
    export const Security: number;
    export const Input: number;
    export const Inspector: number;
    export const DeviceEmulation: number;
    export const Storage: number;
    export const ServiceWorker: number;
    export const Audits: number;
    export const None: number;
}
export type Type = string;
export namespace Type {
    export const Frame: string;
    const ServiceWorker_1: string;
    export { ServiceWorker_1 as ServiceWorker };
    export const Worker: string;
    export const Node: string;
    const Browser_1: string;
    export { Browser_1 as Browser };
}
export class TargetManager extends Common.ObjectWrapper.ObjectWrapper {
    /**
     * @param {{forceNew: boolean}} opts
     */
    static instance({ forceNew }?: {
        forceNew: boolean;
    }): TargetManager;
    /** @type {!Set.<!Target>} */
    _targets: Set<Target>;
    /** @type {!Set.<!Observer>} */
    _observers: Set<Observer>;
    /** @type {!Platform.Multimap<symbol, !{modelClass: function(new:SDKModel, !Target), thisObject: (!Object|undefined), listener: function(!Common.EventTarget.EventTargetEvent):void}>} */
    _modelListeners: Platform.Multimap<symbol, {
        modelClass: new (arg1: Target) => SDKModel;
        thisObject: (Object | undefined);
        listener: (arg0: Common.EventTarget.EventTargetEvent) => void;
    }>;
    /** @type {!Platform.Multimap<function(new:SDKModel, !Target), !SDKModelObserver<*>>} */
    _modelObservers: Platform.Multimap<new (arg1: Target) => SDKModel, SDKModelObserver<any>>;
    _isSuspended: boolean;
    /**
     * @param {string=} reason - optionally provide a reason, so targets can respond accordingly
     * @return {!Promise<void>}
     */
    suspendAllTargets(reason?: string | undefined): Promise<void>;
    /**
     * @return {!Promise<void>}
     */
    resumeAllTargets(): Promise<void>;
    /**
     * @return {boolean}
     */
    allTargetsSuspended(): boolean;
    /**
     * @param {function(new:SDKModel,!Target)} modelClass
     * @return {!Array<!T>}
     * @template T
     */
    models<T>(modelClass: new (arg1: Target) => SDKModel): T[];
    /**
     * @return {string}
     */
    inspectedURL(): string;
    /**
     * @param {function(new:SDKModel,!Target)} modelClass
     * @param {!SDKModelObserver<T>} observer
     * @template T
     */
    observeModels<T_2>(modelClass: new (arg1: Target) => SDKModel, observer: SDKModelObserver<T_2>): void;
    /**
     * @param {function(new:SDKModel,!Target)} modelClass
     * @param {!SDKModelObserver<T>} observer
     * @template T
     */
    unobserveModels<T_3>(modelClass: new (arg1: Target) => SDKModel, observer: SDKModelObserver<T_3>): void;
    /**
     * @param {!Target} target
     * @param {function(new:SDKModel,!Target)} modelClass
     * @param {!SDKModel} model
     */
    modelAdded(target: Target, modelClass: new (arg1: Target) => SDKModel, model: SDKModel): void;
    /**
     * @param {!Target} target
     * @param {function(new:SDKModel,!Target)} modelClass
     * @param {!SDKModel} model
     */
    _modelRemoved(target: Target, modelClass: new (arg1: Target) => SDKModel, model: SDKModel): void;
    /**
     * @param {function(new:SDKModel,!Target)} modelClass
     * @param {symbol} eventType
     * @param {function(!Common.EventTarget.EventTargetEvent):void} listener
     * @param {!Object=} thisObject
     */
    addModelListener(modelClass: new (arg1: Target) => SDKModel, eventType: symbol, listener: (arg0: Common.EventTarget.EventTargetEvent) => void, thisObject?: Object | undefined): void;
    /**
     * @param {function(new:SDKModel,!Target)} modelClass
     * @param {symbol} eventType
     * @param {function(!Common.EventTarget.EventTargetEvent):void} listener
     * @param {!Object=} thisObject
     */
    removeModelListener(modelClass: new (arg1: Target) => SDKModel, eventType: symbol, listener: (arg0: Common.EventTarget.EventTargetEvent) => void, thisObject?: Object | undefined): void;
    /**
     * @param {!Observer} targetObserver
     */
    observeTargets(targetObserver: Observer): void;
    /**
     * @param {!Observer} targetObserver
     */
    unobserveTargets(targetObserver: Observer): void;
    /**
     * @param {string} id
     * @param {string} name
     * @param {!Type} type
     * @param {?Target} parentTarget
     * @param {string=} sessionId
     * @param {boolean=} waitForDebuggerInPage
     * @param {!ProtocolClient.InspectorBackend.Connection=} connection
     * @return {!Target}
     */
    createTarget(id: string, name: string, type: Type, parentTarget: Target | null, sessionId?: string | undefined, waitForDebuggerInPage?: boolean | undefined, connection?: ProtocolClient.InspectorBackend.Connection | undefined): Target;
    /**
     * @param {!Target} target
     */
    removeTarget(target: Target): void;
    /**
     * @return {!Array.<!Target>}
     */
    targets(): Array<Target>;
    /**
     * @param {string} id
     * @return {?Target}
     */
    targetById(id: string): Target | null;
    /**
     * @return {?Target}
     */
    mainTarget(): Target | null;
}
export type Events = symbol;
export namespace Events {
    export const AvailableTargetsChanged: symbol;
    export const InspectedURLChanged: symbol;
    export const NameChanged: symbol;
    export const SuspendStateChanged: symbol;
}
/**
 * @interface
 */
export class Observer {
    /**
     * @param {!Target} target
     */
    targetAdded(target: Target): void;
    /**
     * @param {!Target} target
     */
    targetRemoved(target: Target): void;
}
/**
 * @interface
 * @template T
 */
export class SDKModelObserver<T> {
    /**
     * @param {!T} model
     */
    modelAdded(model: T): void;
    /**
     * @param {!T} model
     */
    modelRemoved(model: T): void;
}
import * as Common from "../common/common.js";
import * as ProtocolClient from "../protocol_client/protocol_client.js";
import * as Platform from "../platform/platform.js";
