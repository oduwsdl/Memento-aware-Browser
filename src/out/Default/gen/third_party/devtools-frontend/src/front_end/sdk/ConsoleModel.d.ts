/**
 * @implements {Observer}
 */
export class ConsoleModel extends Common.ObjectWrapper.ObjectWrapper implements Observer {
    /**
     * @param {{forceNew: ?boolean}} opts
     */
    static instance(opts?: {
        forceNew: boolean | null;
    }): ConsoleModel;
    /** @type {!Array.<!ConsoleMessage>} */
    _messages: Array<ConsoleMessage>;
    /** @type {!Map<!RuntimeModel, !Map<number, !ConsoleMessage>>} */
    _messageByExceptionId: Map<RuntimeModel, Map<number, ConsoleMessage>>;
    _warnings: number;
    _errors: number;
    _violations: number;
    _pageLoadSequenceNumber: number;
    /**
     * @override
     * @param {!Target} target
     */
    targetAdded(target: Target): void;
    /**
     * @param {!Target} target
     */
    _initTarget(target: Target): void;
    /**
     * @override
     * @param {!Target} target
     */
    targetRemoved(target: Target): void;
    /**
     * @param {!ExecutionContext} executionContext
     * @param {!ConsoleMessage} originatingMessage
     * @param {string} expression
     * @param {boolean} useCommandLineAPI
     */
    evaluateCommandInConsole(executionContext: ExecutionContext, originatingMessage: ConsoleMessage, expression: string, useCommandLineAPI: boolean): Promise<void>;
    /**
     * @param {!ExecutionContext} executionContext
     * @param {string} text
     * @return {!ConsoleMessage}
     */
    addCommandMessage(executionContext: ExecutionContext, text: string): ConsoleMessage;
    /**
     * @param {!ConsoleMessage} msg
     */
    addMessage(msg: ConsoleMessage): void;
    /**
     * @param {!RuntimeModel} runtimeModel
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _exceptionThrown(runtimeModel: RuntimeModel, event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!RuntimeModel} runtimeModel
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _exceptionRevoked(runtimeModel: RuntimeModel, event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!RuntimeModel} runtimeModel
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _consoleAPICalled(runtimeModel: RuntimeModel, event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!RuntimeModel} runtimeModel
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _queryObjectRequested(runtimeModel: RuntimeModel, event: Common.EventTarget.EventTargetEvent): void;
    _clearIfNecessary(): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _mainFrameNavigated(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!CPUProfilerModel} cpuProfilerModel
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _consoleProfileStarted(cpuProfilerModel: CPUProfilerModel, event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!CPUProfilerModel} cpuProfilerModel
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _consoleProfileFinished(cpuProfilerModel: CPUProfilerModel, event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!CPUProfilerModel} cpuProfilerModel
     * @param {string} type
     * @param {!Location} scriptLocation
     * @param {string} messageText
     */
    _addConsoleProfileMessage(cpuProfilerModel: CPUProfilerModel, type: string, scriptLocation: Location, messageText: string): void;
    /**
     * @param {!ConsoleMessage} msg
     */
    _incrementErrorWarningCount(msg: ConsoleMessage): void;
    /**
     * @return {!Array.<!ConsoleMessage>}
     */
    messages(): Array<ConsoleMessage>;
    requestClearMessages(): void;
    _clear(): void;
    /**
     * @return {number}
     */
    errors(): number;
    /**
     * @return {number}
     */
    warnings(): number;
    /**
     * @return {number}
     */
    violations(): number;
    /**
     * @param {?ExecutionContext} currentExecutionContext
     * @param {?RemoteObject} remoteObject
     */
    saveToTempVariable(currentExecutionContext: ExecutionContext | null, remoteObject: RemoteObject | null): Promise<void>;
}
export type Events = symbol;
export namespace Events {
    export const ConsoleCleared: symbol;
    export const MessageAdded: symbol;
    export const MessageUpdated: symbol;
    export const CommandEvaluated: symbol;
}
/**
 * @unrestricted
 */
export class ConsoleMessage {
    /**
     * @param {!RuntimeModel} runtimeModel
     * @param {!Protocol.Runtime.ExceptionDetails} exceptionDetails
     * @param {string=} messageType
     * @param {number=} timestamp
     * @param {string=} forceUrl
     * @return {!ConsoleMessage}
     */
    static fromException(runtimeModel: RuntimeModel, exceptionDetails: Protocol.Runtime.ExceptionDetails, messageType?: string | undefined, timestamp?: number | undefined, forceUrl?: string | undefined): ConsoleMessage;
    /**
     * @param {?RuntimeModel} runtimeModel
     * @param {string} source
     * @param {?string} level
     * @param {string} messageText
     * @param {string=} type
     * @param {?string=} url
     * @param {number=} line
     * @param {number=} column
     * @param {!Array.<!Protocol.Runtime.RemoteObject|string>=} parameters
     * @param {!Protocol.Runtime.StackTrace=} stackTrace
     * @param {number=} timestamp
     * @param {!Protocol.Runtime.ExecutionContextId=} executionContextId
     * @param {?string=} scriptId
     * @param {?string=} workerId
     * @param {string=} context
     */
    constructor(runtimeModel: RuntimeModel | null, source: string, level: string | null, messageText: string, type?: string | undefined, url?: (string | null) | undefined, line?: number | undefined, column?: number | undefined, parameters?: Array<Protocol.Runtime.RemoteObject | string> | undefined, stackTrace?: Protocol.Runtime.StackTrace | undefined, timestamp?: number | undefined, executionContextId?: Protocol.Runtime.ExecutionContextId | undefined, scriptId?: (string | null) | undefined, workerId?: (string | null) | undefined, context?: string | undefined);
    _runtimeModel: RuntimeModel | null;
    source: string;
    level: string | null;
    messageText: string;
    type: string;
    /** @type {string|undefined} */
    url: string | undefined;
    /** @type {number} */
    line: number;
    /** @type {number} */
    column: number;
    parameters: (string | Protocol.Runtime.RemoteObject)[] | undefined;
    /** @type {!Protocol.Runtime.StackTrace|undefined} */
    stackTrace: Protocol.Runtime.StackTrace | undefined;
    timestamp: number;
    executionContextId: any;
    scriptId: string | null;
    workerId: string | null;
    context: string;
    /**
     * @return {?RuntimeModel}
     */
    runtimeModel(): RuntimeModel | null;
    /**
     * @return {?Target}
     */
    target(): Target | null;
    /**
     * @param {!ConsoleMessage} originatingMessage
     */
    setOriginatingMessage(originatingMessage: ConsoleMessage): void;
    _originatingConsoleMessage: ConsoleMessage | undefined;
    /**
     * @param {!Protocol.Runtime.ExecutionContextId} executionContextId
     */
    setExecutionContextId(executionContextId: Protocol.Runtime.ExecutionContextId): void;
    /**
     * @param {number} exceptionId
     */
    setExceptionId(exceptionId: number): void;
    _exceptionId: number | undefined;
    /**
     * @return {?ConsoleMessage}
     */
    originatingMessage(): ConsoleMessage | null;
    /**
     * @return {boolean}
     */
    isGroupMessage(): boolean;
    /**
     * @return {boolean}
     */
    isGroupStartMessage(): boolean;
    /**
     * @return {boolean}
     */
    isErrorOrWarning(): boolean;
    /**
     * @return {boolean}
     */
    isGroupable(): boolean;
    /**
     * @return {string}
     */
    groupCategoryKey(): string;
    /**
     * @param {?ConsoleMessage} msg
     * @return {boolean}
     */
    isEqual(msg: ConsoleMessage | null): boolean;
    /**
     * @param {!Protocol.Runtime.StackTrace|undefined} stackTrace1
     * @param {!Protocol.Runtime.StackTrace|undefined} stackTrace2
     * @return {boolean}
     */
    _isEqualStackTraces(stackTrace1: Protocol.Runtime.StackTrace | undefined, stackTrace2: Protocol.Runtime.StackTrace | undefined): boolean;
}
export type MessageSource = string;
export namespace MessageSource {
    export const XML: string;
    export const JS: string;
    export const Network: string;
    export const ConsoleAPI: string;
    export const Storage: string;
    export const AppCache: string;
    export const Rendering: string;
    export const CSS: string;
    export const Security: string;
    export const Deprecation: string;
    export const Worker: string;
    export const Violation: string;
    export const Intervention: string;
    export const Recommendation: string;
    export const Other: string;
}
export type MessageType = string;
export namespace MessageType {
    export const Log: string;
    export const Debug: string;
    export const Info: string;
    export const Error: string;
    export const Warning: string;
    export const Dir: string;
    export const DirXML: string;
    export const Table: string;
    export const Trace: string;
    export const Clear: string;
    export const StartGroup: string;
    export const StartGroupCollapsed: string;
    export const EndGroup: string;
    export const Assert: string;
    export const Result: string;
    export const Profile: string;
    export const ProfileEnd: string;
    export const Command: string;
    export const System: string;
    export const QueryObjectResult: string;
}
export type MessageLevel = string;
export namespace MessageLevel {
    export const Verbose: string;
    const Info_1: string;
    export { Info_1 as Info };
    const Warning_1: string;
    export { Warning_1 as Warning };
    const Error_1: string;
    export { Error_1 as Error };
}
/** @type {!Map<!MessageSource, string>} */
export const MessageSourceDisplayName: Map<MessageSource, string>;
export type ConsoleAPICall = {
    type: string;
    args: Array<Protocol.Runtime.RemoteObject>;
    executionContextId: number;
    timestamp: number;
    stackTrace: (Protocol.Runtime.StackTrace | undefined);
};
/**
 * @typedef {{
  *    type: string,
  *    args: !Array<!Protocol.Runtime.RemoteObject>,
  *    executionContextId: number,
  *    timestamp: number,
  *    stackTrace: (!Protocol.Runtime.StackTrace|undefined)
  * }}
  */
export let ConsoleAPICall: any;
export type ExceptionWithTimestamp = {
    timestamp: number;
    details: Protocol.Runtime.ExceptionDetails;
};
/** @typedef {{timestamp: number, details: !Protocol.Runtime.ExceptionDetails}} */
export let ExceptionWithTimestamp: any;
import * as Common from "../common/common.js";
import { Observer } from "./SDKModel.js";
import { RuntimeModel } from "./RuntimeModel.js";
import { Target } from "./SDKModel.js";
import { ExecutionContext } from "./RuntimeModel.js";
import { CPUProfilerModel } from "./CPUProfilerModel.js";
import { Location } from "./DebuggerModel.js";
import { RemoteObject } from "./RemoteObject.js";
