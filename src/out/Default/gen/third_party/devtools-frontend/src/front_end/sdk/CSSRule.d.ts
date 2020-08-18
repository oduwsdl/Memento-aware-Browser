/**
 * @unrestricted
 */
export class CSSRule {
    /**
     * @param {!CSSModel} cssModel
     * @param {{style: !Protocol.CSS.CSSStyle, styleSheetId: (string|undefined), origin: !Protocol.CSS.StyleSheetOrigin}} payload
     */
    constructor(cssModel: CSSModel, payload: {
        style: Protocol.CSS.CSSStyle;
        styleSheetId: (string | undefined);
        origin: Protocol.CSS.StyleSheetOrigin;
    });
    _cssModel: CSSModel;
    styleSheetId: string | undefined;
    sourceURL: string;
    origin: Protocol.CSS.StyleSheetOrigin;
    style: CSSStyleDeclaration;
    /**
     * @param {!Edit} edit
     */
    rebase(edit: Edit): void;
    /**
     * @return {string}
     */
    resourceURL(): string;
    /**
     * @return {boolean}
     */
    isUserAgent(): boolean;
    /**
     * @return {boolean}
     */
    isInjected(): boolean;
    /**
     * @return {boolean}
     */
    isViaInspector(): boolean;
    /**
     * @return {boolean}
     */
    isRegular(): boolean;
    /**
     * @return {!CSSModel}
     */
    cssModel(): CSSModel;
}
export class CSSStyleRule extends CSSRule {
    /**
     * @param {!CSSModel} cssModel
     * @param {string} selectorText
     * @return {!CSSStyleRule}
     */
    static createDummyRule(cssModel: CSSModel, selectorText: string): CSSStyleRule;
    /**
     * @param {!CSSModel} cssModel
     * @param {!Protocol.CSS.CSSRule} payload
     * @param {boolean=} wasUsed
     */
    constructor(cssModel: CSSModel, payload: Protocol.CSS.CSSRule, wasUsed?: boolean | undefined);
    /** @type {!Array.<!CSSValue>} */
    selectors: Array<CSSValue>;
    media: CSSMedia[];
    wasUsed: boolean;
    /**
     * @param {!Protocol.CSS.SelectorList} selectorList
     */
    _reinitializeSelectors(selectorList: Protocol.CSS.SelectorList): void;
    /**
     * @param {string} newSelector
     * @return {!Promise.<boolean>}
     */
    setSelectorText(newSelector: string): Promise<boolean>;
    /**
     * @return {string}
     */
    selectorText(): string;
    /**
     * @return {?TextUtils.TextRange}
     */
    selectorRange(): any | null;
    /**
     * @param {number} selectorIndex
     * @return {number}
     */
    lineNumberInSource(selectorIndex: number): number;
    /**
     * @param {number} selectorIndex
     * @return {number|undefined}
     */
    columnNumberInSource(selectorIndex: number): number | undefined;
}
export class CSSKeyframesRule {
    /**
     * @param {!CSSModel} cssModel
     * @param {!Protocol.CSS.CSSKeyframesRule} payload
     */
    constructor(cssModel: CSSModel, payload: Protocol.CSS.CSSKeyframesRule);
    _cssModel: CSSModel;
    _animationName: CSSValue;
    _keyframes: CSSKeyframeRule[];
    /**
     * @return {!CSSValue}
     */
    name(): CSSValue;
    /**
     * @return {!Array.<!CSSKeyframeRule>}
     */
    keyframes(): Array<CSSKeyframeRule>;
}
/**
 * @unrestricted
 */
export class CSSKeyframeRule extends CSSRule {
    /**
     * @param {!CSSModel} cssModel
     * @param {!Protocol.CSS.CSSKeyframeRule} payload
     */
    constructor(cssModel: CSSModel, payload: Protocol.CSS.CSSKeyframeRule);
    /**
     * @return {!CSSValue}
     */
    key(): CSSValue;
    /**
     * @param {!Protocol.CSS.Value} payload
     */
    _reinitializeKey(payload: Protocol.CSS.Value): void;
    _keyText: CSSValue | undefined;
    /**
     * @param {string} newKeyText
     * @return {!Promise.<boolean>}
     */
    setKeyText(newKeyText: string): Promise<boolean>;
}
import { CSSModel } from "./CSSModel.js";
import { CSSStyleDeclaration } from "./CSSStyleDeclaration.js";
import { Edit } from "./CSSModel.js";
declare class CSSValue {
    /**
     * @param {!Protocol.CSS.Value} payload
     */
    constructor(payload: Protocol.CSS.Value);
    text: string;
    range: any;
    /**
     * @param {!Edit} edit
     */
    rebase(edit: Edit): void;
}
import { CSSMedia } from "./CSSMedia.js";
export {};
