/**
 * @implements {TextUtils.ContentProvider.ContentProvider}
 * TODO(chromium:1011811): make `implements {FrameAssociated}` annotation work here.
 * @unrestricted
 */
export class Script implements TextUtils.ContentProvider.ContentProvider {
    /**
     * @param {string} source
     * @return {string}
     */
    static _trimSourceURLComment(source: string): string;
    /**
     * @param {!DebuggerModel} debuggerModel
     * @param {string} scriptId
     * @param {string} sourceURL
     * @param {number} startLine
     * @param {number} startColumn
     * @param {number} endLine
     * @param {number} endColumn
     * @param {!Protocol.Runtime.ExecutionContextId} executionContextId
     * @param {string} hash
     * @param {boolean} isContentScript
     * @param {boolean} isLiveEdit
     * @param {string|undefined} sourceMapURL
     * @param {boolean} hasSourceURL
     * @param {number} length
     * @param {?Protocol.Runtime.StackTrace} originStackTrace
     * @param {?number} codeOffset
     * @param {?string} scriptLanguage
     * @param {?Protocol.Debugger.DebugSymbols} debugSymbols
     */
    constructor(debuggerModel: DebuggerModel, scriptId: string, sourceURL: string, startLine: number, startColumn: number, endLine: number, endColumn: number, executionContextId: Protocol.Runtime.ExecutionContextId, hash: string, isContentScript: boolean, isLiveEdit: boolean, sourceMapURL: string | undefined, hasSourceURL: boolean, length: number, originStackTrace: Protocol.Runtime.StackTrace | null, codeOffset: number | null, scriptLanguage: string | null, debugSymbols: Protocol.Debugger.DebugSymbols | null);
    debuggerModel: DebuggerModel;
    scriptId: string;
    sourceURL: string;
    lineOffset: number;
    columnOffset: number;
    endLine: number;
    endColumn: number;
    executionContextId: number;
    hash: string;
    _isContentScript: boolean;
    _isLiveEdit: boolean;
    sourceMapURL: string | undefined;
    debugSymbols: Protocol.Debugger.DebugSymbols | null;
    hasSourceURL: boolean;
    contentLength: number;
    /** @type {?TextUtils.ContentProvider.ContentProvider} */
    _originalContentProvider: TextUtils.ContentProvider.ContentProvider | null;
    originStackTrace: Protocol.Runtime.StackTrace | null;
    _codeOffset: number | null;
    _language: string | null;
    /** @type {?Promise<!TextUtils.ContentProvider.DeferredContent>} */
    _contentPromise: Promise<TextUtils.ContentProvider.DeferredContent> | null;
    /**
     * @return {boolean}
     */
    isContentScript(): boolean;
    /**
     * @return {?number}
     */
    codeOffset(): number | null;
    /**
     * @return {boolean}
     */
    isWasm(): boolean;
    /**
     * @return {?ExecutionContext}
     */
    executionContext(): ExecutionContext | null;
    /**
     * @return {boolean}
     */
    isLiveEdit(): boolean;
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
     * @return {!Promise<!ArrayBuffer>}
     */
    getWasmBytecode(): Promise<ArrayBuffer>;
    /**
     * @return {!TextUtils.ContentProvider.ContentProvider}
     */
    originalContentProvider(): TextUtils.ContentProvider.ContentProvider;
    /**
     * @override
     * @param {string} query
     * @param {boolean} caseSensitive
     * @param {boolean} isRegex
     * @return {!Promise<!Array<!TextUtils.ContentProvider.SearchMatch>>}
     */
    searchInContent(query: string, caseSensitive: boolean, isRegex: boolean): Promise<Array<TextUtils.ContentProvider.SearchMatch>>;
    /**
     * @param {string} source
     * @return {string}
     */
    _appendSourceURLCommentIfNeeded(source: string): string;
    /**
     * @param {string} newSource
     * @param {function(?ProtocolClient.InspectorBackend.ProtocolError, !Protocol.Runtime.ExceptionDetails=, !Array.<!Protocol.Debugger.CallFrame>=, !Protocol.Runtime.StackTrace=, !Protocol.Runtime.StackTraceId=, boolean=):void} callback
     */
    editSource(newSource: string, callback: (arg0: ProtocolClient.InspectorBackend.ProtocolError | null, arg1: Protocol.Runtime.ExceptionDetails | undefined, arg2: Array<Protocol.Debugger.CallFrame> | undefined, arg3: Protocol.Runtime.StackTrace | undefined, arg4: Protocol.Runtime.StackTraceId | undefined, arg5: boolean | undefined) => void): Promise<void>;
    /**
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {?Location}
     */
    rawLocation(lineNumber: number, columnNumber: number): Location | null;
    /**
     *
     * @param {!Location} location
     * @return {!Array.<number>}
     */
    toRelativeLocation(location: Location): Array<number>;
    /**
     * @return {boolean}
     */
    isInlineScript(): boolean;
    /**
     * @return {boolean}
     */
    isAnonymousScript(): boolean;
    /**
     * @return {boolean}
     */
    isInlineScriptWithSourceURL(): boolean;
    /**
     * @param {!Array<!Protocol.Debugger.ScriptPosition>} positions
     * @return {!Promise<boolean>}
     */
    setBlackboxedRanges(positions: Array<Protocol.Debugger.ScriptPosition>): Promise<boolean>;
    /**
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {boolean}
     */
    containsLocation(lineNumber: number, columnNumber: number): boolean;
    /**
     * @return {string}
     */
    get frameId(): string;
    [frameIdSymbol]: string | undefined;
}
export const sourceURLRegex: RegExp;
import * as TextUtils from "../text_utils/text_utils.js";
import { DebuggerModel } from "./DebuggerModel.js";
import { ExecutionContext } from "./RuntimeModel.js";
import * as Common from "../common/common.js";
import * as ProtocolClient from "../protocol_client/protocol_client.js";
import { Location } from "./DebuggerModel.js";
declare const frameIdSymbol: unique symbol;
export {};
