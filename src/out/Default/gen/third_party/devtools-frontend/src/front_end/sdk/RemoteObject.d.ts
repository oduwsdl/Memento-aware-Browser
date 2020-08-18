export class RemoteObject {
    /**
     * This may not be an interface due to "instanceof RemoteObject" checks in the code.
     */
    /**
     * @param {*} value
     * @return {!RemoteObject}
     */
    static fromLocalObject(value: any): RemoteObject;
    /**
     * @param {!RemoteObject} remoteObject
     * @return {string}
     */
    static type(remoteObject: RemoteObject): string;
    /**
     * @param {string} description
     * @return {string}
     */
    static arrayNameFromDescription(description: string): string;
    /**
     * @param {!RemoteObject|!Protocol.Runtime.RemoteObject|!Protocol.Runtime.ObjectPreview} object
     * @return {number}
     */
    static arrayLength(object: RemoteObject | Protocol.Runtime.RemoteObject | Protocol.Runtime.ObjectPreview): number;
    /**
     * @param {*} object
     * @return {?string}
     */
    static unserializableDescription(object: any): string | null;
    /**
     * @param {!Protocol.Runtime.RemoteObject|!RemoteObject|number|string|boolean|undefined|null|bigint} object
     * @return {!Protocol.Runtime.CallArgument}
     */
    static toCallArgument(object: Protocol.Runtime.RemoteObject | RemoteObject | number | string | boolean | undefined | null | bigint): Protocol.Runtime.CallArgument;
    /**
     * @param {!RemoteObject} object
     * @param {boolean} generatePreview
     * @return {!Promise<!GetPropertiesResult>}
     */
    static loadFromObjectPerProto(object: RemoteObject, generatePreview: boolean): Promise<GetPropertiesResult>;
    /**
     * @return {?Protocol.Runtime.CustomPreview}
     */
    customPreview(): Protocol.Runtime.CustomPreview | null;
    /** @return {!Protocol.Runtime.RemoteObjectId|undefined} */
    get objectId(): string | undefined;
    /** @return {string} */
    get type(): string;
    /** @return {string|undefined} */
    get subtype(): string | undefined;
    /** @return {*} */
    get value(): any;
    /** @return {string|undefined} */
    unserializableValue(): string | undefined;
    /** @return {string|undefined} */
    get description(): string | undefined;
    /** @return {boolean} */
    get hasChildren(): boolean;
    /**
     * @return {!Protocol.Runtime.ObjectPreview|undefined}
     */
    get preview(): Protocol.Runtime.ObjectPreview | undefined;
    /**
     * @return {?string}
     */
    get className(): string | null;
    /**
     * @return {number}
     */
    arrayLength(): number;
    /**
     * @param {boolean} generatePreview
     * @return {!Promise<!GetPropertiesResult>}
     */
    getOwnProperties(generatePreview: boolean): Promise<GetPropertiesResult>;
    /**
     * @param {boolean} accessorPropertiesOnly
     * @param {boolean} generatePreview
     * @return {!Promise<!GetPropertiesResult>}
     */
    getAllProperties(accessorPropertiesOnly: boolean, generatePreview: boolean): Promise<GetPropertiesResult>;
    /**
     * @param {!Protocol.Runtime.CallArgument} name
     * @return {!Promise<string|undefined>}
     */
    deleteProperty(name: Protocol.Runtime.CallArgument): Promise<string | undefined>;
    /**
     * @param {string|!Protocol.Runtime.CallArgument} name
     * @param {string} value
     * @return {!Promise<string|undefined>}
     */
    setPropertyValue(name: string | Protocol.Runtime.CallArgument, value: string): Promise<string | undefined>;
    /**
     * @param {function(this:Object, ...):T} functionDeclaration
     * @param {!Array<!Protocol.Runtime.CallArgument>=} args
     * @return {!Promise<!CallFunctionResult>}
     * @template T
     */
    callFunction<T>(functionDeclaration: (this: Object, ...arg1: any[]) => T, args?: Array<Protocol.Runtime.CallArgument> | undefined): Promise<CallFunctionResult>;
    /**
     * @param {function(this:Object, ...):T} functionDeclaration
     * @param {!Array<!Protocol.Runtime.CallArgument>|undefined} args
     * @return {!Promise<T>}
     * @template T
     */
    callFunctionJSON<T_2>(functionDeclaration: (this: Object, ...arg1: any[]) => T_2, args: Array<Protocol.Runtime.CallArgument> | undefined): Promise<T_2>;
    release(): void;
    /**
     * @return {!DebuggerModel}
     */
    debuggerModel(): DebuggerModel;
    /**
     * @return {!RuntimeModel}
     */
    runtimeModel(): RuntimeModel;
    /**
     * @return {boolean}
     */
    isNode(): boolean;
}
export class RemoteObjectImpl extends RemoteObject {
    /**
     * @param {!RuntimeModel} runtimeModel
     * @param {string|undefined} objectId
     * @param {string} type
     * @param {string|undefined} subtype
     * @param {*} value
     * @param {!Protocol.Runtime.UnserializableValue=} unserializableValue
     * @param {string=} description
     * @param {!Protocol.Runtime.ObjectPreview=} preview
     * @param {!Protocol.Runtime.CustomPreview=} customPreview
     * @param {string=} className
     */
    constructor(runtimeModel: RuntimeModel, objectId: string | undefined, type: string, subtype: string | undefined, value: any, unserializableValue?: Protocol.Runtime.UnserializableValue | undefined, description?: string | undefined, preview?: Protocol.Runtime.ObjectPreview | undefined, customPreview?: Protocol.Runtime.CustomPreview | undefined, className?: string | undefined);
    _runtimeModel: RuntimeModel;
    _runtimeAgent: ProtocolProxyApi.RuntimeApi;
    _type: string;
    _subtype: string | undefined;
    _objectId: string;
    _description: string | undefined;
    _hasChildren: boolean;
    _preview: Protocol.Runtime.ObjectPreview | undefined;
    _unserializableValue: string;
    _value: any;
    _customPreview: Protocol.Runtime.CustomPreview | null;
    _className: string | null;
    /**
     * @param {boolean} ownProperties
     * @param {boolean} accessorPropertiesOnly
     * @param {boolean} generatePreview
     * @return {!Promise<!GetPropertiesResult>}
     */
    doGetProperties(ownProperties: boolean, accessorPropertiesOnly: boolean, generatePreview: boolean): Promise<GetPropertiesResult>;
    /**
     * @param {!Protocol.Runtime.RemoteObject} result
     * @param {!Protocol.Runtime.CallArgument} name
     * @return {!Promise<string|undefined>}
     */
    doSetObjectPropertyValue(result: Protocol.Runtime.RemoteObject, name: Protocol.Runtime.CallArgument): Promise<string | undefined>;
}
export class ScopeRemoteObject extends RemoteObjectImpl {
    /**
     * @param {!RuntimeModel} runtimeModel
     * @param {string|undefined} objectId
     * @param {!ScopeRef} scopeRef
     * @param {string} type
     * @param {string|undefined} subtype
     * @param {*} value
     * @param {!Protocol.Runtime.UnserializableValue=} unserializableValue
     * @param {string=} description
     * @param {!Protocol.Runtime.ObjectPreview=} preview
     */
    constructor(runtimeModel: RuntimeModel, objectId: string | undefined, scopeRef: ScopeRef, type: string, subtype: string | undefined, value: any, unserializableValue?: Protocol.Runtime.UnserializableValue | undefined, description?: string | undefined, preview?: Protocol.Runtime.ObjectPreview | undefined);
    _scopeRef: ScopeRef;
    _savedScopeProperties: RemoteObjectProperty[] | undefined;
}
export class ScopeRef {
    /**
     * @param {number} number
     * @param {string=} callFrameId
     */
    constructor(number: number, callFrameId?: string | undefined);
    number: number;
    callFrameId: string | undefined;
}
/**
 * @unrestricted
 */
export class RemoteObjectProperty {
    /**
     * @param {string} name
     * @param {?RemoteObject} value
     * @param {boolean=} enumerable
     * @param {boolean=} writable
     * @param {boolean=} isOwn
     * @param {boolean=} wasThrown
     * @param {?RemoteObject=} symbol
     * @param {boolean=} synthetic
     * @param {function(string):!Promise<?RemoteObject>=} syntheticSetter
     * @param {boolean=} isPrivate
     */
    constructor(name: string, value: RemoteObject | null, enumerable?: boolean | undefined, writable?: boolean | undefined, isOwn?: boolean | undefined, wasThrown?: boolean | undefined, symbol?: (RemoteObject | null) | undefined, synthetic?: boolean | undefined, syntheticSetter?: ((arg0: string) => Promise<RemoteObject | null>) | undefined, isPrivate?: boolean | undefined);
    name: string;
    value: RemoteObject;
    enumerable: boolean;
    writable: boolean;
    isOwn: boolean;
    wasThrown: boolean;
    symbol: RemoteObject;
    synthetic: boolean;
    syntheticSetter: (arg0: string) => Promise<RemoteObject | null>;
    private: boolean;
    /**
     * @param {string} expression
     * @return {!Promise<boolean>}
     */
    setSyntheticValue(expression: string): Promise<boolean>;
    /**
     * @return {boolean}
     */
    isAccessorProperty(): boolean;
}
export class LocalJSONObject extends RemoteObject {
    /**
     * @param {*} value
     */
    constructor(value: any);
    _value: any;
    /** @type {string} */
    _cachedDescription: string;
    /** @type {!Array<!RemoteObjectProperty>} */
    _cachedChildren: Array<RemoteObjectProperty>;
    /**
     * @param {?RemoteObject} value
     * @return {string}
     */
    _formatValue(value: RemoteObject | null): string;
    /**
     * @param {string} prefix
     * @param {string} suffix
     * @param {function(!RemoteObjectProperty):string} formatProperty
     * @return {string}
     */
    _concatenate(prefix: string, suffix: string, formatProperty: (arg0: RemoteObjectProperty) => string): string;
    /**
     * @return {!Array.<!RemoteObjectProperty>}
     */
    _children(): Array<RemoteObjectProperty>;
}
export class RemoteArray {
    /**
     * @param {?RemoteObject} object
     * @return {!RemoteArray}
     */
    static objectAsArray(object: RemoteObject | null): RemoteArray;
    /**
     * @param {!Array<!RemoteObject>} objects
     * @return {!Promise<!RemoteArray>}
     */
    static createFromRemoteObjects(objects: Array<RemoteObject>): Promise<RemoteArray>;
    /**
     * @param {!RemoteObject} object
     */
    constructor(object: RemoteObject);
    _object: RemoteObject;
    /**
     * @param {number} index
     * @return {!Promise<!RemoteObject>}
     */
    at(index: number): Promise<RemoteObject>;
    /**
     * @return {number}
     */
    length(): number;
    /**
     * @param {function(!RemoteObject):!Promise<T>} func
     * @return {!Promise<!Array<T>>}
     * @template T
     */
    map<T>(func: (arg0: RemoteObject) => Promise<T>): Promise<T[]>;
    /**
     * @return {!RemoteObject}
     */
    object(): RemoteObject;
}
export class RemoteFunction {
    /**
     * @param {?RemoteObject} object
     * @return {!RemoteFunction}
     */
    static objectAsFunction(object: RemoteObject | null): RemoteFunction;
    /**
     * @param {!RemoteObject} object
     */
    constructor(object: RemoteObject);
    _object: RemoteObject;
    /**
     * @return {!Promise<!RemoteObject>}
     */
    targetFunction(): Promise<RemoteObject>;
    /**
     * @return {!Promise<?FunctionDetails>}
     */
    targetFunctionDetails(): Promise<FunctionDetails | null>;
    /**
     * @return {!RemoteObject}
     */
    object(): RemoteObject;
}
export type CallFunctionResult = {
    object: RemoteObject | null;
    wasThrown: (boolean | undefined);
};
/**
 * @typedef {{object: ?RemoteObject, wasThrown: (boolean|undefined)}}
 */
export let CallFunctionResult: any;
export type GetPropertiesResult = {
    properties: Array<RemoteObjectProperty> | null;
    internalProperties: Array<RemoteObjectProperty> | null;
};
/**
 * @typedef {{properties: ?Array<!RemoteObjectProperty>, internalProperties: ?Array<!RemoteObjectProperty>}}
 */
export let GetPropertiesResult: any;
export type UnserializableNumber = string;
import { DebuggerModel } from "./DebuggerModel.js";
import { RuntimeModel } from "./RuntimeModel.js";
import { FunctionDetails } from "./DebuggerModel.js";
