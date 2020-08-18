/**
 * @implements {TextUtils.ContentProvider.ContentProvider}
 * TODO(chromium:1011811): make `implements {FrameAssociated}` annotation work here.
 */
export class CSSStyleSheetHeader implements TextUtils.ContentProvider.ContentProvider {
    /**
     * @param {!CSSModel} cssModel
     * @param {!Protocol.CSS.CSSStyleSheetHeader} payload
     */
    constructor(cssModel: CSSModel, payload: Protocol.CSS.CSSStyleSheetHeader);
    _cssModel: CSSModel;
    id: string;
    frameId: string;
    sourceURL: string;
    hasSourceURL: boolean;
    origin: Protocol.CSS.StyleSheetOrigin;
    title: string;
    disabled: boolean;
    isInline: boolean;
    isMutable: boolean;
    startLine: number;
    startColumn: number;
    endLine: number;
    endColumn: number;
    contentLength: number;
    ownerNode: DeferredDOMNode;
    sourceMapURL: string | undefined;
    _originalContentProvider: TextUtils.StaticContentProvider.StaticContentProvider | null;
    /**
     * @return {!TextUtils.ContentProvider.ContentProvider}
     */
    originalContentProvider(): TextUtils.ContentProvider.ContentProvider;
    /**
     * @param {string=} sourceMapURL
     */
    setSourceMapURL(sourceMapURL?: string | undefined): void;
    /**
     * @return {!CSSModel}
     */
    cssModel(): CSSModel;
    /**
     * @return {boolean}
     */
    isAnonymousInlineStyleSheet(): boolean;
    /**
     * @return {string}
     */
    resourceURL(): string;
    /**
     * @return {string}
     */
    _viaInspectorResourceURL(): string;
    /**
     * @param {number} lineNumberInStyleSheet
     * @return {number}
     */
    lineNumberInSource(lineNumberInStyleSheet: number): number;
    /**
     * @param {number} lineNumberInStyleSheet
     * @param {number} columnNumberInStyleSheet
     * @return {number|undefined}
     */
    columnNumberInSource(lineNumberInStyleSheet: number, columnNumberInStyleSheet: number): number | undefined;
    /**
     * Checks whether the position is in this style sheet. Assumes that the
     * position's columnNumber is consistent with line endings.
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {boolean}
     */
    containsLocation(lineNumber: number, columnNumber: number): boolean;
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
     * @override
     * @param {string} query
     * @param {boolean} caseSensitive
     * @param {boolean} isRegex
     * @return {!Promise<!Array<!TextUtils.ContentProvider.SearchMatch>>}
     */
    searchInContent(query: string, caseSensitive: boolean, isRegex: boolean): Promise<Array<TextUtils.ContentProvider.SearchMatch>>;
    /**
     * @return {boolean}
     */
    isViaInspector(): boolean;
}
import * as TextUtils from "../text_utils/text_utils.js";
import { CSSModel } from "./CSSModel.js";
import { DeferredDOMNode } from "./DOMModel.js";
import * as Common from "../common/common.js";
