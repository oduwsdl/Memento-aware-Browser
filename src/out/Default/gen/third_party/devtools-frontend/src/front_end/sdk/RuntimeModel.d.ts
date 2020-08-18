export class RuntimeModel extends SDKModel {
    /**
     * @param {!EvaluationResult} response
     * @return {boolean}
     */
    static isSideEffectFailure(response: EvaluationResult): boolean;
    /**
     * @param {!Protocol.Runtime.ExceptionDetails} exceptionDetails
     * @return {string}
     */
    static simpleTextFromException(exceptionDetails: Protocol.Runtime.ExceptionDetails): string;
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _agent: ProtocolProxyApi.RuntimeApi;
    /** @type {!Map<number, !ExecutionContext>} */
    _executionContextById: Map<number, ExecutionContext>;
    /** @type {function(!ExecutionContext,!ExecutionContext):number} */
    _executionContextComparator: (arg0: ExecutionContext, arg1: ExecutionContext) => number;
    /** @type {?boolean} */
    _hasSideEffectSupport: boolean | null;
    /**
     * @return {!DebuggerModel}
     */
    debuggerModel(): DebuggerModel;
    /**
     * @return {!HeapProfilerModel}
     */
    heapProfilerModel(): HeapProfilerModel;
    /**
     * @return {!Array.<!ExecutionContext>}
     */
    executionContexts(): Array<ExecutionContext>;
    /**
     * @param {function(!ExecutionContext,!ExecutionContext):number} comparator
     */
    setExecutionContextComparator(comparator: (arg0: ExecutionContext, arg1: ExecutionContext) => number): void;
    /**
     * @return {function(!ExecutionContext,!ExecutionContext):number} comparator
     */
    executionContextComparator(): (arg0: ExecutionContext, arg1: ExecutionContext) => number;
    /**
     * @return {?ExecutionContext}
     */
    defaultExecutionContext(): ExecutionContext | null;
    /**
     * @param {!Protocol.Runtime.ExecutionContextId} id
     * @return {?ExecutionContext}
     */
    executionContext(id: Protocol.Runtime.ExecutionContextId): ExecutionContext | null;
    /**
     * @param {!Protocol.Runtime.ExecutionContextDescription} context
     */
    _executionContextCreated(context: Protocol.Runtime.ExecutionContextDescription): void;
    /**
     * @param {number} executionContextId
     */
    _executionContextDestroyed(executionContextId: number): void;
    fireExecutionContextOrderChanged(): void;
    _executionContextsCleared(): void;
    /**
     * @param {!Protocol.Runtime.RemoteObject} payload
     * @return {!RemoteObject}
     */
    createRemoteObject(payload: Protocol.Runtime.RemoteObject): RemoteObject;
    /**
     * @param {!Protocol.Runtime.RemoteObject} payload
     * @param {!ScopeRef} scopeRef
     * @return {!RemoteObject}
     */
    createScopeRemoteObject(payload: Protocol.Runtime.RemoteObject, scopeRef: ScopeRef): RemoteObject;
    /**
     * @param {number|string|boolean|undefined|bigint} value
     * @return {!RemoteObject}
     */
    createRemoteObjectFromPrimitiveValue(value: number | string | boolean | undefined | bigint): RemoteObject;
    /**
     * @param {string} name
     * @param {number|string|boolean} value
     * @return {!RemoteObjectProperty}
     */
    createRemotePropertyFromPrimitiveValue(name: string, value: number | string | boolean): RemoteObjectProperty;
    discardConsoleEntries(): void;
    /**
     * @param {string} objectGroupName
     */
    releaseObjectGroup(objectGroupName: string): void;
    /**
     * @param {!EvaluationResult} result
     */
    releaseEvaluationResult(result: EvaluationResult): void;
    runIfWaitingForDebugger(): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _customFormattersStateChanged(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {string} expression
     * @param {string} sourceURL
     * @param {boolean} persistScript
     * @param {number} executionContextId
     * @return {!Promise<?CompileScriptResult>}
     */
    compileScript(expression: string, sourceURL: string, persistScript: boolean, executionContextId: number): Promise<CompileScriptResult | null>;
    /**
     * @param {!Protocol.Runtime.ScriptId} scriptId
     * @param {number} executionContextId
     * @param {string=} objectGroup
     * @param {boolean=} silent
     * @param {boolean=} includeCommandLineAPI
     * @param {boolean=} returnByValue
     * @param {boolean=} generatePreview
     * @param {boolean=} awaitPromise
     * @return {!Promise<!EvaluationResult>}
     */
    runScript(scriptId: Protocol.Runtime.ScriptId, executionContextId: number, objectGroup?: string | undefined, silent?: boolean | undefined, includeCommandLineAPI?: boolean | undefined, returnByValue?: boolean | undefined, generatePreview?: boolean | undefined, awaitPromise?: boolean | undefined): Promise<EvaluationResult>;
    /**
     * @param {!RemoteObject} prototype
     * @return {!Promise<!QueryObjectResult>}
     */
    queryObjects(prototype: RemoteObject): Promise<QueryObjectResult>;
    /**
     * @return {!Promise<string>}
     */
    isolateId(): Promise<string>;
    /**
     * @return {!Promise<?{usedSize: number, totalSize: number}>}
     */
    heapUsage(): Promise<{
        usedSize: number;
        totalSize: number;
    } | null>;
    /**
     * @param {!Protocol.Runtime.RemoteObject} payload
     * @param {!Object=} hints
     */
    _inspectRequested(payload: Protocol.Runtime.RemoteObject, hints?: Object | undefined): void;
    /**
     * @param {!RemoteObject} object
     */
    _copyRequested(object: RemoteObject): void;
    /**
     * @param {!RemoteObject} object
     */
    _queryObjectsRequested(object: RemoteObject): Promise<void>;
    /**
     * @param {number} timestamp
     * @param {!Protocol.Runtime.ExceptionDetails} exceptionDetails
     */
    exceptionThrown(timestamp: number, exceptionDetails: Protocol.Runtime.ExceptionDetails): void;
    /**
     * @param {number} exceptionId
     */
    _exceptionRevoked(exceptionId: number): void;
    /**
     * @param {string} type
     * @param {!Array.<!Protocol.Runtime.RemoteObject>} args
     * @param {number} executionContextId
     * @param {number} timestamp
     * @param {!Protocol.Runtime.StackTrace=} stackTrace
     * @param {string=} context
     */
    _consoleAPICalled(type: string, args: Array<Protocol.Runtime.RemoteObject>, executionContextId: number, timestamp: number, stackTrace?: Protocol.Runtime.StackTrace | undefined, context?: string | undefined): void;
    /**
     * @param {!Protocol.Runtime.ScriptId} scriptId
     * @return {number}
     */
    executionContextIdForScriptId(scriptId: Protocol.Runtime.ScriptId): number;
    /**
     * @param {!Protocol.Runtime.StackTrace} stackTrace
     * @return {number}
     */
    executionContextForStackTrace(stackTrace: Protocol.Runtime.StackTrace): number;
    /**
     * @return {?boolean}
     */
    hasSideEffectSupport(): boolean | null;
    /**
     * @return {!Promise<boolean>}
     */
    checkSideEffectSupport(): Promise<boolean>;
    /**
     * @return {!Promise<*>}
     */
    terminateExecution(): Promise<any>;
}
export type Events = symbol;
export namespace Events {
    export const ExecutionContextCreated: symbol;
    export const ExecutionContextDestroyed: symbol;
    export const ExecutionContextChanged: symbol;
    export const ExecutionContextOrderChanged: symbol;
    export const ExceptionThrown: symbol;
    export const ExceptionRevoked: symbol;
    export const ConsoleAPICalled: symbol;
    export const QueryObjectRequested: symbol;
}
/**
 * @unrestricted
 */
export class ExecutionContext {
    /**
     * @param {!ExecutionContext} a
     * @param {!ExecutionContext} b
     * @return {number}
     */
    static comparator(a: ExecutionContext, b: ExecutionContext): number;
    /**
     * @param {!RuntimeModel} runtimeModel
     * @param {number} id
     * @param {string} name
     * @param {string} origin
     * @param {boolean} isDefault
     * @param {string=} frameId
     */
    constructor(runtimeModel: RuntimeModel, id: number, name: string, origin: string, isDefault: boolean, frameId?: string | undefined);
    id: number;
    name: string;
    origin: string;
    isDefault: boolean;
    runtimeModel: RuntimeModel;
    debuggerModel: DebuggerModel;
    frameId: string | undefined;
    /**
     * @return {!Target}
     */
    target(): Target;
    /**
     * @param {!EvaluationOptions} options
     * @param {boolean} userGesture
     * @param {boolean} awaitPromise
     * @return {!Promise<!EvaluationResult>}
     */
    evaluate(options: EvaluationOptions, userGesture: boolean, awaitPromise: boolean): Promise<EvaluationResult>;
    /**
     * @param {string} objectGroup
     * @param {boolean} generatePreview
     * @return {!Promise<!EvaluationResult>}
     */
    globalObject(objectGroup: string, generatePreview: boolean): Promise<EvaluationResult>;
    /**
     * @param {!EvaluationOptions} options
     * @param {boolean} userGesture
     * @param {boolean} awaitPromise
     * @return {!Promise<!EvaluationResult>}
     */
    _evaluateGlobal(options: EvaluationOptions, userGesture: boolean, awaitPromise: boolean): Promise<EvaluationResult>;
    /**
     * @return {!Promise<?Array<string>>}
     */
    globalLexicalScopeNames(): Promise<Array<string> | null>;
    /**
     * @return {string}
     */
    label(): string;
    /**
     * @param {string} label
     */
    setLabel(label: string): void;
    /**
     * @param {string} label
     */
    _setLabel(label: string): void;
    _label: string | undefined;
}
/**
 * }
 */
export type EvaluationResult = {
    object: RemoteObject;
    exceptionDetails: (Protocol.Runtime.ExceptionDetails | undefined);
} | {
    error: (ProtocolClient.InspectorBackend.ProtocolError | undefined);
};
/** @typedef {{
 *    object: !RemoteObject,
 *    exceptionDetails: (!Protocol.Runtime.ExceptionDetails|undefined)}|{
 *    error: (!ProtocolClient.InspectorBackend.ProtocolError|undefined)}
 *  }}
 */
export let EvaluationResult: any;
export type CompileScriptResult = {
    scriptId: (Protocol.Runtime.ScriptId | undefined);
    exceptionDetails: (Protocol.Runtime.ExceptionDetails | undefined);
};
/** @typedef {{
 *    scriptId: (Protocol.Runtime.ScriptId|undefined),
 *    exceptionDetails: (!Protocol.Runtime.ExceptionDetails|undefined)
 *  }}
 */
export let CompileScriptResult: any;
export type EvaluationOptions = {
    expression: string;
    objectGroup: (string | undefined);
    includeCommandLineAPI: (boolean | undefined);
    silent: (boolean | undefined);
    returnByValue: (boolean | undefined);
    generatePreview: (boolean | undefined);
    throwOnSideEffect: (boolean | undefined);
    timeout: (number | undefined);
    disableBreaks: (boolean | undefined);
    replMode: (boolean | undefined);
};
/** @typedef {{
 *    expression: string,
 *    objectGroup: (string|undefined),
 *    includeCommandLineAPI: (boolean|undefined),
 *    silent: (boolean|undefined),
 *    returnByValue: (boolean|undefined),
 *    generatePreview: (boolean|undefined),
 *    throwOnSideEffect: (boolean|undefined),
 *    timeout: (number|undefined),
 *    disableBreaks: (boolean|undefined),
 *    replMode: (boolean|undefined)
 *  }}
 */
export let EvaluationOptions: any;
/**
 * }
 */
export type QueryObjectResult = {
    objects: (RemoteObject | undefined);
    error: (ProtocolClient.InspectorBackend.ProtocolError | undefined);
};
/** @typedef {{
 *    objects: (!RemoteObject|undefined),
 *    error: (!ProtocolClient.InspectorBackend.ProtocolError|undefined)}
 *  }}
 */
export let QueryObjectResult: any;
import { SDKModel } from "./SDKModel.js";
import { DebuggerModel } from "./DebuggerModel.js";
import { HeapProfilerModel } from "./HeapProfilerModel.js";
import { RemoteObject } from "./RemoteObject.js";
import { ScopeRef } from "./RemoteObject.js";
import { RemoteObjectProperty } from "./RemoteObject.js";
import * as Common from "../common/common.js";
import { Target } from "./SDKModel.js";
import * as ProtocolClient from "../protocol_client/protocol_client.js";
