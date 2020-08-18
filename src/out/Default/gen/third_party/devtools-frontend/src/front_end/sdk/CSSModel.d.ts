/**
 * @unrestricted
 */
export class CSSModel extends SDKModel {
    /**
     * @param {string} text
     * @return {string}
     */
    static trimSourceURL(text: string): string;
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _domModel: DOMModel;
    /** @type {!SourceMapManager<!CSSStyleSheetHeader>} */
    _sourceMapManager: SourceMapManager<CSSStyleSheetHeader>;
    _agent: any;
    _styleLoader: ComputedStyleLoader;
    _resourceTreeModel: any;
    /** @type {!Map.<string, !CSSStyleSheetHeader>} */
    _styleSheetIdToHeader: Map<string, CSSStyleSheetHeader>;
    /** @type {!Map.<string, !Map.<!Protocol.Page.FrameId, !Set.<!Protocol.CSS.StyleSheetId>>>} */
    _styleSheetIdsForURL: Map<string, Map<Protocol.Page.FrameId, Set<Protocol.CSS.StyleSheetId>>>;
    /** @type {!Map.<!CSSStyleSheetHeader, !Promise<?string>>} */
    _originalStyleSheetText: Map<CSSStyleSheetHeader, Promise<string | null>>;
    /** @type {boolean} */
    _isRuleUsageTrackingEnabled: boolean;
    /**
     * @param {string} sourceURL
     * @return {!Array<!CSSStyleSheetHeader>}
     */
    headersForSourceURL(sourceURL: string): Array<CSSStyleSheetHeader>;
    /**
     * @param {string} sourceURL
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {!Array<!CSSLocation>}
     */
    createRawLocationsByURL(sourceURL: string, lineNumber: number, columnNumber: number): Array<CSSLocation>;
    /**
     * @return {!SourceMapManager<!CSSStyleSheetHeader>}
     */
    sourceMapManager(): SourceMapManager<CSSStyleSheetHeader>;
    /**
     * @return {!DOMModel}
     */
    domModel(): DOMModel;
    /**
     * @param {!Protocol.CSS.StyleSheetId} styleSheetId
     * @param {!TextUtils.TextRange} range
     * @param {string} text
     * @param {boolean} majorChange
     * @return {!Promise<boolean>}
     */
    setStyleText(styleSheetId: Protocol.CSS.StyleSheetId, range: any, text: string, majorChange: boolean): Promise<boolean>;
    /**
     * @param {!Protocol.CSS.StyleSheetId} styleSheetId
     * @param {!TextUtils.TextRange} range
     * @param {string} text
     * @return {!Promise<boolean>}
     */
    setSelectorText(styleSheetId: Protocol.CSS.StyleSheetId, range: any, text: string): Promise<boolean>;
    /**
     * @param {!Protocol.CSS.StyleSheetId} styleSheetId
     * @param {!TextUtils.TextRange} range
     * @param {string} text
     * @return {!Promise<boolean>}
     */
    setKeyframeKey(styleSheetId: Protocol.CSS.StyleSheetId, range: any, text: string): Promise<boolean>;
    startCoverage(): any;
    /**
     * @return {!Promise<{timestamp: number, coverage:!Array<!Protocol.CSS.RuleUsage>}>}
     */
    takeCoverageDelta(): Promise<{
        timestamp: number;
        coverage: Array<Protocol.CSS.RuleUsage>;
    }>;
    /**
     * @return {!Promise<?>}
     */
    stopCoverage(): Promise<unknown>;
    /**
     * @return {!Promise<!Array<!CSSMedia>>}
     */
    mediaQueriesPromise(): Promise<Array<CSSMedia>>;
    /**
     * @return {boolean}
     */
    isEnabled(): boolean;
    /**
     * @return {!Promise<?>}
     */
    _enable(): Promise<unknown>;
    _isEnabled: boolean | undefined;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @return {!Promise<?CSSMatchedStyles>}
     */
    matchedStylesPromise(nodeId: Protocol.DOM.NodeId): Promise<CSSMatchedStyles | null>;
    /**
     * @param {!Protocol.CSS.StyleSheetId} styleSheetId
     * @return {!Promise<!Array<string>>}
     */
    classNamesPromise(styleSheetId: Protocol.CSS.StyleSheetId): Promise<Array<string>>;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @return {!Promise<?Map<string, string>>}
     */
    computedStylePromise(nodeId: Protocol.DOM.NodeId): Promise<Map<string, string> | null>;
    /**
     * @param {number} nodeId
     * @return {!Promise<?ContrastInfo>}
     */
    backgroundColorsPromise(nodeId: number): Promise<ContrastInfo | null>;
    /**
     * @param {number} nodeId
     * @return {!Promise<?Array<!Protocol.CSS.PlatformFontUsage>>}
     */
    platformFontsPromise(nodeId: number): Promise<Array<Protocol.CSS.PlatformFontUsage> | null>;
    /**
     * @return {!Array.<!CSSStyleSheetHeader>}
     */
    allStyleSheets(): Array<CSSStyleSheetHeader>;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @return {!Promise<?InlineStyleResult>}
     */
    inlineStylesPromise(nodeId: Protocol.DOM.NodeId): Promise<InlineStyleResult | null>;
    /**
     * @param {!DOMNode} node
     * @param {string} pseudoClass
     * @param {boolean} enable
     * @return {boolean}
     */
    forcePseudoState(node: DOMNode, pseudoClass: string, enable: boolean): boolean;
    /**
     * @param {!DOMNode} node
     * @return {?Array<string>} state
     */
    pseudoState(node: DOMNode): Array<string> | null;
    /**
     * @param {!Protocol.CSS.StyleSheetId} styleSheetId
     * @param {!TextUtils.TextRange} range
     * @param {string} newMediaText
     * @return {!Promise<boolean>}
     */
    setMediaText(styleSheetId: Protocol.CSS.StyleSheetId, range: any, newMediaText: string): Promise<boolean>;
    /**
     * @param {!Protocol.CSS.StyleSheetId} styleSheetId
     * @param {string} ruleText
     * @param {!TextUtils.TextRange} ruleLocation
     * @return {!Promise<?CSSStyleRule>}
     */
    addRule(styleSheetId: Protocol.CSS.StyleSheetId, ruleText: string, ruleLocation: any): Promise<CSSStyleRule | null>;
    /**
     * @param {!DOMNode} node
     * @return {!Promise<?CSSStyleSheetHeader>}
     */
    requestViaInspectorStylesheet(node: DOMNode): Promise<CSSStyleSheetHeader | null>;
    mediaQueryResultChanged(): void;
    fontsUpdated(): void;
    /**
     * @param {!Protocol.CSS.StyleSheetId} id
     * @return {?CSSStyleSheetHeader}
     */
    styleSheetHeaderForId(id: Protocol.CSS.StyleSheetId): CSSStyleSheetHeader | null;
    /**
     * @return {!Array.<!CSSStyleSheetHeader>}
     */
    styleSheetHeaders(): Array<CSSStyleSheetHeader>;
    /**
     * @param {!Protocol.CSS.StyleSheetId} styleSheetId
     * @param {!Edit=} edit
     */
    _fireStyleSheetChanged(styleSheetId: Protocol.CSS.StyleSheetId, edit?: Edit | undefined): void;
    /**
     * @param {!Protocol.CSS.StyleSheetId} styleSheetId
     * @return {!Promise<?string>}
     */
    _ensureOriginalStyleSheetText(styleSheetId: Protocol.CSS.StyleSheetId): Promise<string | null>;
    /**
     * @param {!CSSStyleSheetHeader} header
     */
    _originalContentRequestedForTest(header: CSSStyleSheetHeader): void;
    /**
     * @param {!CSSStyleSheetHeader} header
     * @return {!Promise<?string>}
     */
    originalStyleSheetText(header: CSSStyleSheetHeader): Promise<string | null>;
    /**
     *
     * @return {!Iterable<!CSSStyleSheetHeader>}
     */
    getAllStyleSheetHeaders(): Iterable<CSSStyleSheetHeader>;
    /**
     * @param {!Protocol.CSS.CSSStyleSheetHeader} header
     */
    _styleSheetAdded(header: Protocol.CSS.CSSStyleSheetHeader): void;
    /**
     * @param {!Protocol.CSS.StyleSheetId} id
     */
    _styleSheetRemoved(id: Protocol.CSS.StyleSheetId): void;
    /**
     * @param {string} url
     * @return {!Array.<!Protocol.CSS.StyleSheetId>}
     */
    styleSheetIdsForURL(url: string): Array<Protocol.CSS.StyleSheetId>;
    /**
     * @param {!Protocol.CSS.StyleSheetId} styleSheetId
     * @param {string} newText
     * @param {boolean} majorChange
     * @return {!Promise<?string>}
     */
    setStyleSheetText(styleSheetId: Protocol.CSS.StyleSheetId, newText: string, majorChange: boolean): Promise<string | null>;
    /**
     * @param {!Protocol.CSS.StyleSheetId} styleSheetId
     * @return {!Promise<?string>}
     */
    getStyleSheetText(styleSheetId: Protocol.CSS.StyleSheetId): Promise<string | null>;
    _resetStyleSheets(): void;
    /**
     * @param {number} nodeId
     * @param {string} name
     * @param {string} value
     */
    setEffectivePropertyValueForNode(nodeId: number, name: string, value: string): void;
    /**
     * @param {!DOMNode} node
     * @return {!Promise.<?CSSMatchedStyles>}
     */
    cachedMatchedCascadeForNode(node: DOMNode): Promise<CSSMatchedStyles | null>;
    _cachedMatchedCascadeNode: any;
    _cachedMatchedCascadePromise: Promise<CSSMatchedStyles | null> | undefined;
    discardCachedMatchedCascade(): void;
}
export type Events = symbol;
export namespace Events {
    export const FontsUpdated: symbol;
    export const MediaQueryResultChanged: symbol;
    export const ModelWasEnabled: symbol;
    export const PseudoStateForced: symbol;
    export const StyleSheetAdded: symbol;
    export const StyleSheetChanged: symbol;
    export const StyleSheetRemoved: symbol;
}
export class Edit {
    /**
     * @param {!Protocol.CSS.StyleSheetId} styleSheetId
     * @param {!TextUtils.TextRange} oldRange
     * @param {string} newText
     * @param {?Object} payload
     */
    constructor(styleSheetId: Protocol.CSS.StyleSheetId, oldRange: any, newText: string, payload: Object | null);
    styleSheetId: string;
    oldRange: any;
    newRange: any;
    newText: string;
    payload: Object | null;
}
export class CSSLocation {
    /**
     * @param {!CSSStyleSheetHeader} header
     * @param {number} lineNumber
     * @param {number=} columnNumber
     */
    constructor(header: CSSStyleSheetHeader, lineNumber: number, columnNumber?: number | undefined);
    _cssModel: CSSModel;
    styleSheetId: string;
    url: string;
    lineNumber: number;
    columnNumber: number;
    /**
     * @return {!CSSModel}
     */
    cssModel(): CSSModel;
    /**
     * @return {?CSSStyleSheetHeader}
     */
    header(): CSSStyleSheetHeader | null;
}
export class InlineStyleResult {
    /**
     * @param {?CSSStyleDeclaration} inlineStyle
     * @param {?CSSStyleDeclaration} attributesStyle
     */
    constructor(inlineStyle: CSSStyleDeclaration | null, attributesStyle: CSSStyleDeclaration | null);
    inlineStyle: CSSStyleDeclaration | null;
    attributesStyle: CSSStyleDeclaration | null;
}
export type ContrastInfo = {
    backgroundColors: Array<string> | null;
    computedFontSize: string;
    computedFontWeight: string;
};
/** @typedef {{backgroundColors: ?Array<string>, computedFontSize: string, computedFontWeight: string}} */
export let ContrastInfo: any;
import { SDKModel } from "./SDKModel.js";
import { DOMModel } from "./DOMModel.js";
import { SourceMapManager } from "./SourceMapManager.js";
import { CSSStyleSheetHeader } from "./CSSStyleSheetHeader.js";
declare class ComputedStyleLoader {
    /**
     * @param {!CSSModel} cssModel
     */
    constructor(cssModel: CSSModel);
    _cssModel: CSSModel;
    /** @type {!Map<!Protocol.DOM.NodeId, !Promise<?Map<string, string>>>} */
    _nodeIdToPromise: Map<Protocol.DOM.NodeId, Promise<Map<string, string> | null>>;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @return {!Promise<?Map<string, string>>}
     */
    computedStylePromise(nodeId: Protocol.DOM.NodeId): Promise<Map<string, string> | null>;
}
import { CSSMedia } from "./CSSMedia.js";
import { CSSMatchedStyles } from "./CSSMatchedStyles.js";
import { DOMNode } from "./DOMModel.js";
import { CSSStyleRule } from "./CSSRule.js";
import { Target } from "./SDKModel.js";
import { CSSStyleDeclaration } from "./CSSStyleDeclaration.js";
export {};
