export class DebuggerModel extends SDKModel {
    /**
     * @param {!Protocol.Runtime.ExecutionContextId} executionContextId
     * @param {string} sourceURL
     * @param {string|undefined} sourceMapURL
     * @return {?string}
     */
    static _sourceMapId(executionContextId: Protocol.Runtime.ExecutionContextId, sourceURL: string, sourceMapURL: string | undefined): string | null;
    /**
     * @param {string} debuggerId
     * @return {?DebuggerModel}
     */
    static modelForDebuggerId(debuggerId: string): DebuggerModel | null;
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _agent: ProtocolProxyApi.DebuggerApi;
    _runtimeModel: RuntimeModel;
    /** @type {!SourceMapManager<!Script>} */
    _sourceMapManager: SourceMapManager<Script>;
    /** @type {!Map<string, !Script>} */
    _sourceMapIdToScript: Map<string, Script>;
    /** @type {?DebuggerPausedDetails} */
    _debuggerPausedDetails: DebuggerPausedDetails | null;
    /** @type {!Map<string, !Script>} */
    _scripts: Map<string, Script>;
    /** @type {!Map.<string, !Array.<!Script>>} */
    _scriptsBySourceURL: Map<string, Array<Script>>;
    /** @type {!Array.<!Script>} */
    _discardableScripts: Array<Script>;
    /** @type {(function(!DebuggerPausedDetails):boolean)|null} */
    _continueToLocationCallback: ((arg0: DebuggerPausedDetails) => boolean) | null;
    /** @type {?CallFrame} */
    _selectedCallFrame: CallFrame | null;
    /** @type {boolean} */
    _debuggerEnabled: boolean;
    /** @type {?string} */
    _debuggerId: string | null;
    /** @type {number} */
    _skipAllPausesTimeout: number;
    /** @type {(function(!DebuggerPausedDetails):boolean)|null} */
    _beforePausedCallback: ((arg0: DebuggerPausedDetails) => boolean) | null;
    /** @type {!Common.ObjectWrapper.ObjectWrapper} */
    _breakpointResolvedEventTarget: Common.ObjectWrapper.ObjectWrapper;
    /** @type {boolean} */
    _autoStepOver: boolean;
    _isPausing: boolean;
    /** @type {!Map<string, string>} */
    _stringMap: Map<string, string>;
    /**
     * @return {!SourceMapManager<!Script>}
     */
    sourceMapManager(): SourceMapManager<Script>;
    /**
     * @return {!RuntimeModel}
     */
    runtimeModel(): RuntimeModel;
    /**
     * @return {boolean}
     */
    debuggerEnabled(): boolean;
    /**
     * @return {!Promise<void>}
     */
    _enableDebugger(): Promise<void>;
    /**
     * @param {!Protocol.Debugger.EnableResponse} response
     */
    _registerDebugger(response: Protocol.Debugger.EnableResponse): void;
    /**
     * @return {boolean}
     */
    isReadyToPause(): boolean;
    /**
     * @return {!Promise<void>}
     */
    _disableDebugger(): Promise<void>;
    /**
     * @param {boolean} skip
     */
    _skipAllPauses(skip: boolean): void;
    /**
     * @param {number} timeout
     */
    skipAllPausesUntilReloadOrTimeout(timeout: number): void;
    _pauseOnExceptionStateChanged(): void;
    _asyncStackTracesStateChanged(): Promise<Protocol.ProtocolResponseWithError>;
    _breakpointsActiveChanged(): void;
    stepInto(): void;
    stepOver(): void;
    stepOut(): void;
    scheduleStepIntoAsync(): void;
    resume(): void;
    pause(): void;
    /**
     * @param {!Protocol.Runtime.StackTraceId} parentStackTraceId
     * @return {!Promise<!Object>}
     */
    _pauseOnAsyncCall(parentStackTraceId: Protocol.Runtime.StackTraceId): Promise<Object>;
    /**
     * @param {string} url
     * @param {number} lineNumber
     * @param {number=} columnNumber
     * @param {string=} condition
     * @return {!Promise<!SetBreakpointResult>}
     */
    setBreakpointByURL(url: string, lineNumber: number, columnNumber?: number | undefined, condition?: string | undefined): Promise<SetBreakpointResult>;
    /**
     * @param {string} scriptId
     * @param {string} scriptHash
     * @param {number} lineNumber
     * @param {number=} columnNumber
     * @param {string=} condition
     * @return {!Promise<!SetBreakpointResult>}
     */
    setBreakpointInAnonymousScript(scriptId: string, scriptHash: string, lineNumber: number, columnNumber?: number | undefined, condition?: string | undefined): Promise<SetBreakpointResult>;
    /**
     * @param {string} scriptId
     * @param {number} lineNumber
     * @param {number=} columnNumber
     * @param {string=} condition
     * @return {!Promise<!SetBreakpointResult>}
     */
    _setBreakpointBySourceId(scriptId: string, lineNumber: number, columnNumber?: number | undefined, condition?: string | undefined): Promise<SetBreakpointResult>;
    /**
     * @param {!Protocol.Debugger.BreakpointId} breakpointId
     * @return {!Promise<void>}
     */
    removeBreakpoint(breakpointId: Protocol.Debugger.BreakpointId): Promise<void>;
    /**
     * @param {!Location} startLocation
     * @param {?Location} endLocation
     * @param {boolean} restrictToFunction
     * @return {!Promise<!Array<!BreakLocation>>}
     */
    getPossibleBreakpoints(startLocation: Location, endLocation: Location | null, restrictToFunction: boolean): Promise<Array<BreakLocation>>;
    /**
     * @param {!Protocol.Runtime.StackTraceId} stackId
     * @return {!Promise<?Protocol.Runtime.StackTrace>}
     */
    fetchAsyncStackTrace(stackId: Protocol.Runtime.StackTraceId): Promise<Protocol.Runtime.StackTrace | null>;
    /**
     * @param {!Protocol.Debugger.BreakpointId} breakpointId
     * @param {!Protocol.Debugger.Location} location
     */
    _breakpointResolved(breakpointId: Protocol.Debugger.BreakpointId, location: Protocol.Debugger.Location): void;
    globalObjectCleared(): void;
    _reset(): void;
    /**
     * @return {!Array<!Script>}
     */
    scripts(): Array<Script>;
    /**
     * @param {!Protocol.Runtime.ScriptId} scriptId
     * @return {?Script}
     */
    scriptForId(scriptId: Protocol.Runtime.ScriptId): Script | null;
    /**
     * @param {?string} sourceURL
     * @return {!Array.<!Script>}
     */
    scriptsForSourceURL(sourceURL: string | null): Array<Script>;
    /**
     * @param {!ExecutionContext} executionContext
     * @return {!Array<!Script>}
     */
    scriptsForExecutionContext(executionContext: ExecutionContext): Array<Script>;
    /**
     * @param {!Protocol.Runtime.ScriptId} scriptId
     * @param {string} newSource
     * @param {function(?ProtocolClient.InspectorBackend.ProtocolError, !Protocol.Runtime.ExceptionDetails=):void} callback
     */
    setScriptSource(scriptId: Protocol.Runtime.ScriptId, newSource: string, callback: (arg0: ProtocolClient.InspectorBackend.ProtocolError | null, arg1: Protocol.Runtime.ExceptionDetails | undefined) => void): void;
    /**
     * @param {!Protocol.Runtime.ScriptId} scriptId
     * @param {string} newSource
     * @param {function(?ProtocolClient.InspectorBackend.ProtocolError, !Protocol.Runtime.ExceptionDetails=):void} callback
     * @param {?ProtocolClient.InspectorBackend.ProtocolError} error
     * @param {!Protocol.Runtime.ExceptionDetails=} exceptionDetails
     * @param {!Array.<!Protocol.Debugger.CallFrame>=} callFrames
     * @param {!Protocol.Runtime.StackTrace=} asyncStackTrace
     * @param {!Protocol.Runtime.StackTraceId=} asyncStackTraceId
     * @param {boolean=} needsStepIn
     */
    _didEditScriptSource(scriptId: Protocol.Runtime.ScriptId, newSource: string, callback: (arg0: ProtocolClient.InspectorBackend.ProtocolError | null, arg1: Protocol.Runtime.ExceptionDetails | undefined) => void, error: ProtocolClient.InspectorBackend.ProtocolError | null, exceptionDetails?: Protocol.Runtime.ExceptionDetails | undefined, callFrames?: Array<Protocol.Debugger.CallFrame> | undefined, asyncStackTrace?: Protocol.Runtime.StackTrace | undefined, asyncStackTraceId?: Protocol.Runtime.StackTraceId | undefined, needsStepIn?: boolean | undefined): void;
    /**
     * @return {?Array.<!CallFrame>}
     */
    get callFrames(): CallFrame[] | null;
    /**
     * @return {?DebuggerPausedDetails}
     */
    debuggerPausedDetails(): DebuggerPausedDetails | null;
    /**
     * @param {?DebuggerPausedDetails} debuggerPausedDetails
     * @return {boolean}
     */
    _setDebuggerPausedDetails(debuggerPausedDetails: DebuggerPausedDetails | null): boolean;
    /**
     * @param {?function(!DebuggerPausedDetails):boolean} callback
     */
    setBeforePausedCallback(callback: ((arg0: DebuggerPausedDetails) => boolean) | null): void;
    /**
     * @param {!Array.<!Protocol.Debugger.CallFrame>} callFrames
     * @param {string} reason
     * @param {!Object|undefined} auxData
     * @param {!Array.<string>} breakpointIds
     * @param {!Protocol.Runtime.StackTrace=} asyncStackTrace
     * @param {!Protocol.Runtime.StackTraceId=} asyncStackTraceId
     * @param {!Protocol.Runtime.StackTraceId=} asyncCallStackTraceId
     */
    _pausedScript(callFrames: Array<Protocol.Debugger.CallFrame>, reason: string, auxData: Object | undefined, breakpointIds: Array<string>, asyncStackTrace?: Protocol.Runtime.StackTrace | undefined, asyncStackTraceId?: Protocol.Runtime.StackTraceId | undefined, asyncCallStackTraceId?: Protocol.Runtime.StackTraceId | undefined): Promise<void>;
    _resumedScript(): void;
    /**
     * @param {!Protocol.Runtime.ScriptId} scriptId
     * @param {string} sourceURL
     * @param {number} startLine
     * @param {number} startColumn
     * @param {number} endLine
     * @param {number} endColumn
     * @param {!Protocol.Runtime.ExecutionContextId} executionContextId
     * @param {string} hash
     * @param {*|undefined} executionContextAuxData
     * @param {boolean} isLiveEdit
     * @param {string|undefined} sourceMapURL
     * @param {boolean} hasSourceURLComment
     * @param {boolean} hasSyntaxError
     * @param {number} length
     * @param {?Protocol.Runtime.StackTrace} originStackTrace
     * @param {?number} codeOffset
     * @param {?string} scriptLanguage
     * @param {?Protocol.Debugger.DebugSymbols} debugSymbols
     * @return {!Script}
     */
    _parsedScriptSource(scriptId: Protocol.Runtime.ScriptId, sourceURL: string, startLine: number, startColumn: number, endLine: number, endColumn: number, executionContextId: Protocol.Runtime.ExecutionContextId, hash: string, executionContextAuxData: any | undefined, isLiveEdit: boolean, sourceMapURL: string | undefined, hasSourceURLComment: boolean, hasSyntaxError: boolean, length: number, originStackTrace: Protocol.Runtime.StackTrace | null, codeOffset: number | null, scriptLanguage: string | null, debugSymbols: Protocol.Debugger.DebugSymbols | null): Script;
    /**
     * @param {!Script} script
     * @param {string} newSourceMapURL
     */
    setSourceMapURL(script: Script, newSourceMapURL: string): void;
    /**
     * @param {!ExecutionContext} executionContext
     */
    executionContextDestroyed(executionContext: ExecutionContext): void;
    /**
     * @param {!Script} script
     */
    _registerScript(script: Script): void;
    /**
     * @param {!Script} script
     */
    _unregisterScript(script: Script): void;
    _collectDiscardedScripts(): void;
    /**
     * @param {!Script} script
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {!Location}
     */
    createRawLocation(script: Script, lineNumber: number, columnNumber: number): Location;
    /**
     * @param {string} sourceURL
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {?Location}
     */
    createRawLocationByURL(sourceURL: string, lineNumber: number, columnNumber: number): Location | null;
    /**
     * @param {!Protocol.Runtime.ScriptId} scriptId
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {?Location}
     */
    createRawLocationByScriptId(scriptId: Protocol.Runtime.ScriptId, lineNumber: number, columnNumber: number): Location | null;
    /**
     * @param {!Protocol.Runtime.StackTrace} stackTrace
     * @return {!Array<!Location>}
     */
    createRawLocationsByStackTrace(stackTrace: Protocol.Runtime.StackTrace): Array<Location>;
    /**
     * @return {boolean}
     */
    isPaused(): boolean;
    /**
     * @return {boolean}
     */
    isPausing(): boolean;
    /**
     * @param {?CallFrame} callFrame
     */
    setSelectedCallFrame(callFrame: CallFrame | null): void;
    /**
     * @return {?CallFrame}
     */
    selectedCallFrame(): CallFrame | null;
    /**
     * @param {!EvaluationOptions} options
     * @return {!Promise<!EvaluationResult>}
     */
    evaluateOnSelectedCallFrame(options: EvaluationOptions): Promise<EvaluationResult>;
    /**
     * @param {!RemoteObject} remoteObject
     * @return {!Promise<?FunctionDetails>}
     */
    functionDetailsPromise(remoteObject: RemoteObject): Promise<FunctionDetails | null>;
    /**
     * @param {number} scopeNumber
     * @param {string} variableName
     * @param {!Protocol.Runtime.CallArgument} newValue
     * @param {string} callFrameId
     * @return {!Promise<string|undefined>}
     */
    setVariableValue(scopeNumber: number, variableName: string, newValue: Protocol.Runtime.CallArgument, callFrameId: string): Promise<string | undefined>;
    /**
     * @param {!Protocol.Debugger.BreakpointId} breakpointId
     * @param {function(!Common.EventTarget.EventTargetEvent):void} listener
     * @param {!Object=} thisObject
     */
    addBreakpointListener(breakpointId: Protocol.Debugger.BreakpointId, listener: (arg0: Common.EventTarget.EventTargetEvent) => void, thisObject?: Object | undefined): void;
    /**
     * @param {!Protocol.Debugger.BreakpointId} breakpointId
     * @param {function(!Common.EventTarget.EventTargetEvent):void} listener
     * @param {!Object=} thisObject
     */
    removeBreakpointListener(breakpointId: Protocol.Debugger.BreakpointId, listener: (arg0: Common.EventTarget.EventTargetEvent) => void, thisObject?: Object | undefined): void;
    /**
     * @param {!Array<string>} patterns
     * @return {!Promise<boolean>}
     */
    setBlackboxPatterns(patterns: Array<string>): Promise<boolean>;
    /**
     * @param {string} string
     * @return {string} string
     */
    _internString(string: string): string;
}
/** @type {!Map<string, !DebuggerModel>} */
export const _debuggerIdToModel: Map<string, DebuggerModel>;
/** @type {?Protocol.Runtime.StackTraceId} */
export let _scheduledPauseOnAsyncCall: Protocol.Runtime.StackTraceId | null;
/**
 * Keep these in sync with WebCore::V8Debugger
 */
export type PauseOnExceptionsState = string;
export namespace PauseOnExceptionsState {
    export const DontPauseOnExceptions: string;
    export const PauseOnAllExceptions: string;
    export const PauseOnUncaughtExceptions: string;
}
export type Events = symbol;
export namespace Events {
    export const DebuggerWasEnabled: symbol;
    export const DebuggerWasDisabled: symbol;
    export const DebuggerPaused: symbol;
    export const DebuggerResumed: symbol;
    export const ParsedScriptSource: symbol;
    export const FailedToParseScriptSource: symbol;
    export const DiscardedAnonymousScriptSource: symbol;
    export const GlobalObjectCleared: symbol;
    export const CallFrameSelected: symbol;
    export const ConsoleCommandEvaluatedInSelectedCallFrame: symbol;
    export const DebuggerIsReadyToPause: symbol;
}
export type BreakReason = string;
export namespace BreakReason {
    export const DOM: string;
    export const EventListener: string;
    export const XHR: string;
    export const Exception: string;
    export const PromiseRejection: string;
    export const Assert: string;
    export const DebugCommand: string;
    export const OOM: string;
    export const Other: string;
}
export class Location {
    /**
     * @param {!DebuggerModel} debuggerModel
     * @param {!Protocol.Debugger.Location} payload
     * @return {!Location}
     */
    static fromPayload(debuggerModel: DebuggerModel, payload: Protocol.Debugger.Location): Location;
    /**
     * @param {!DebuggerModel} debuggerModel
     * @param {string} scriptId
     * @param {number} lineNumber
     * @param {number=} columnNumber
     */
    constructor(debuggerModel: DebuggerModel, scriptId: string, lineNumber: number, columnNumber?: number | undefined);
    debuggerModel: DebuggerModel;
    scriptId: string;
    lineNumber: number;
    columnNumber: number;
    /**
     * @return {!Protocol.Debugger.Location}
     */
    payload(): Protocol.Debugger.Location;
    /**
     * @return {?Script}
     */
    script(): Script | null;
    /**
     * @param {function():void=} pausedCallback
     */
    continueToLocation(pausedCallback?: (() => void) | undefined): void;
    /**
     * @param {function():void|undefined} pausedCallback
     * @param {!DebuggerPausedDetails} debuggerPausedDetails
     * @return {boolean}
     */
    _paused(pausedCallback: () => void | undefined, debuggerPausedDetails: DebuggerPausedDetails): boolean;
    /**
     * @return {string}
     */
    id(): string;
}
export class BreakLocation extends Location {
    /**
     * @override
     * @param {!DebuggerModel} debuggerModel
     * @param {!Protocol.Debugger.BreakLocation} payload
     * @return {!BreakLocation}
     */
    static fromPayload(debuggerModel: DebuggerModel, payload: Protocol.Debugger.BreakLocation): BreakLocation;
    /**
     * @param {!DebuggerModel} debuggerModel
     * @param {string} scriptId
     * @param {number} lineNumber
     * @param {number=} columnNumber
     * @param {!Protocol.Debugger.BreakLocationType=} type
     */
    constructor(debuggerModel: DebuggerModel, scriptId: string, lineNumber: number, columnNumber?: number | undefined, type?: Protocol.Debugger.BreakLocationType | undefined);
    type: Protocol.Debugger.BreakLocationType;
}
export class CallFrame {
    /**
     * @param {!DebuggerModel} debuggerModel
     * @param {!Array.<!Protocol.Debugger.CallFrame>} callFrames
     * @return {!Array.<!CallFrame>}
     */
    static fromPayloadArray(debuggerModel: DebuggerModel, callFrames: Array<Protocol.Debugger.CallFrame>): Array<CallFrame>;
    /**
     * @param {!DebuggerModel} debuggerModel
     * @param {!Script} script
     * @param {!Protocol.Debugger.CallFrame} payload
     */
    constructor(debuggerModel: DebuggerModel, script: Script, payload: Protocol.Debugger.CallFrame);
    debuggerModel: DebuggerModel;
    /** @type {?Array<!RemoteObjectImpl>} */
    sourceScopeChain: Array<RemoteObjectImpl> | null;
    _script: Script;
    _payload: Protocol.Debugger.CallFrame;
    _location: Location;
    /** @type {!Array<!Scope>} */
    _scopeChain: Array<Scope>;
    _localScope: Scope | null;
    _functionLocation: Location;
    _returnValue: RemoteObject | null;
    /**
     * @return {!Script}
     */
    get script(): Script;
    /**
     * @return {string}
     */
    get id(): string;
    /**
     * @return {!Array.<!Scope>}
     */
    scopeChain(): Array<Scope>;
    /**
     * @return {?Scope}
     */
    localScope(): Scope | null;
    /**
     * @return {?RemoteObject}
     */
    thisObject(): RemoteObject | null;
    /**
     * @return {?RemoteObject}
     */
    returnValue(): RemoteObject | null;
    /**
     * @param {string} expression
     * @return {!Promise<?RemoteObject>}
     */
    setReturnValue(expression: string): Promise<RemoteObject | null>;
    /**
     * @return {string}
     */
    get functionName(): string;
    /**
     * @return {!Location}
     */
    location(): Location;
    /**
     * @return {?Location}
     */
    functionLocation(): Location | null;
    /**
     * @param {!EvaluationOptions} options
     * @return {!Promise<!EvaluationResult>}
     */
    evaluate(options: EvaluationOptions): Promise<EvaluationResult>;
    restart(): Promise<void>;
}
export class Scope {
    /**
     * @param {!CallFrame} callFrame
     * @param {number} ordinal
     */
    constructor(callFrame: CallFrame, ordinal: number);
    _callFrame: CallFrame;
    _payload: Protocol.Debugger.Scope;
    _type: Protocol.Debugger.ScopeType;
    _name: string | undefined;
    _ordinal: number;
    _startLocation: Location | null;
    _endLocation: Location | null;
    /** @type {?RemoteObject} */
    _object: RemoteObject | null;
    /**
     * @return {!CallFrame}
     */
    callFrame(): CallFrame;
    /**
     * @return {string}
     */
    type(): string;
    /**
     * @return {string}
     */
    typeName(): string;
    /**
     * @return {string|undefined}
     */
    name(): string | undefined;
    /**
     * @return {?Location}
     */
    startLocation(): Location | null;
    /**
     * @return {?Location}
     */
    endLocation(): Location | null;
    /**
     * @return {!RemoteObject}
     */
    object(): RemoteObject;
    /**
     * @return {string}
     */
    description(): string;
}
export class DebuggerPausedDetails {
    /**
     * @param {!DebuggerModel} debuggerModel
     * @param {!Array.<!Protocol.Debugger.CallFrame>} callFrames
     * @param {string} reason
     * @param {!Object|undefined} auxData
     * @param {!Array.<string>} breakpointIds
     * @param {!Protocol.Runtime.StackTrace=} asyncStackTrace
     * @param {!Protocol.Runtime.StackTraceId=} asyncStackTraceId
     */
    constructor(debuggerModel: DebuggerModel, callFrames: Array<Protocol.Debugger.CallFrame>, reason: string, auxData: Object | undefined, breakpointIds: Array<string>, asyncStackTrace?: Protocol.Runtime.StackTrace | undefined, asyncStackTraceId?: Protocol.Runtime.StackTraceId | undefined);
    debuggerModel: DebuggerModel;
    callFrames: CallFrame[];
    reason: string;
    auxData: Object | undefined;
    breakpointIds: string[];
    asyncStackTrace: Protocol.Runtime.StackTrace;
    asyncStackTraceId: Protocol.Runtime.StackTraceId | undefined;
    /**
     * @return {?RemoteObject}
     */
    exception(): RemoteObject | null;
    /**
     * @param {!Protocol.Runtime.StackTrace} asyncStackTrace
     * @return {!Protocol.Runtime.StackTrace}
     */
    _cleanRedundantFrames(asyncStackTrace: Protocol.Runtime.StackTrace): Protocol.Runtime.StackTrace;
}
export type FunctionDetails = {
    location: Location | null;
    functionName: string;
};
/** @typedef {{location: ?Location, functionName: string}} */
export let FunctionDetails: any;
export type SetBreakpointResult = {
    breakpointId: Protocol.Debugger.BreakpointId | null;
    locations: Array<Location>;
};
/** @typedef {{
 *    breakpointId: ?Protocol.Debugger.BreakpointId,
 *    locations: !Array<!Location>
 *  }}
 */
export let SetBreakpointResult: any;
import { SDKModel } from "./SDKModel.js";
import { RuntimeModel } from "./RuntimeModel.js";
import { SourceMapManager } from "./SourceMapManager.js";
import { Script } from "./Script.js";
import * as Common from "../common/common.js";
import { ExecutionContext } from "./RuntimeModel.js";
import * as ProtocolClient from "../protocol_client/protocol_client.js";
import { EvaluationOptions } from "./RuntimeModel.js";
import { EvaluationResult } from "./RuntimeModel.js";
import { RemoteObject } from "./RemoteObject.js";
import { Target } from "./SDKModel.js";
import { RemoteObjectImpl } from "./RemoteObject.js";
