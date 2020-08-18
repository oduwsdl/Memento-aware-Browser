export class CSSStyleDeclaration {
    /**
     * @param {!CSSModel} cssModel
     * @param {?CSSRule} parentRule
     * @param {!Protocol.CSS.CSSStyle} payload
     * @param {!Type} type
     */
    constructor(cssModel: CSSModel, parentRule: CSSRule | null, payload: Protocol.CSS.CSSStyle, type: Type);
    _cssModel: CSSModel;
    parentRule: CSSRule | null;
    /** @type {!Array<!CSSProperty>} */
    _allProperties: Array<CSSProperty>;
    /** @type {string|undefined} */
    styleSheetId: string | undefined;
    /** @type {?TextUtils.TextRange.TextRange} */
    range: TextUtils.TextRange.TextRange | null;
    /** @type {string|undefined} */
    cssText: string | undefined;
    /** @type {!Map<string, string>} */
    _shorthandValues: Map<string, string>;
    /** @type {!Set<string>} */
    _shorthandIsImportant: Set<string>;
    /** @type {!Map<string, !CSSProperty>} */
    _activePropertyMap: Map<string, CSSProperty>;
    /** @type {?Array<!CSSProperty>} */
    _leadingProperties: Array<CSSProperty> | null;
    type: string;
    /**
     * @param {!Edit} edit
     */
    rebase(edit: Edit): void;
    /**
     * @param {!Protocol.CSS.CSSStyle} payload
     */
    _reinitialize(payload: Protocol.CSS.CSSStyle): void;
    _generateSyntheticPropertiesIfNeeded(): void;
    /**
     * @return {!Array.<!CSSProperty>}
     */
    _computeLeadingProperties(): Array<CSSProperty>;
    /**
     * @return {!Array.<!CSSProperty>}
     */
    leadingProperties(): Array<CSSProperty>;
    /**
     * @return {!Target}
     */
    target(): Target;
    /**
     * @return {!CSSModel}
     */
    cssModel(): CSSModel;
    _computeInactiveProperties(): void;
    /**
     * @return {!Array<!CSSProperty>}
     */
    allProperties(): Array<CSSProperty>;
    /**
     * @param {string} name
     * @return {string}
     */
    getPropertyValue(name: string): string;
    /**
     * @param {string} name
     * @return {boolean}
     */
    isPropertyImplicit(name: string): boolean;
    /**
     * @param {string} name
     * @return {!Array.<!CSSProperty>}
     */
    longhandProperties(name: string): Array<CSSProperty>;
    /**
     * @param {number} index
     * @return {?CSSProperty}
     */
    propertyAt(index: number): CSSProperty | null;
    /**
     * @return {number}
     */
    pastLastSourcePropertyIndex(): number;
    /**
     * @param {number} index
     * @return {!TextUtils.TextRange.TextRange}
     */
    _insertionRange(index: number): TextUtils.TextRange.TextRange;
    /**
     * @param {number=} index
     * @return {!CSSProperty}
     */
    newBlankProperty(index?: number | undefined): CSSProperty;
    /**
     * @param {string} text
     * @param {boolean} majorChange
     * @return {!Promise.<boolean>}
     */
    setText(text: string, majorChange: boolean): Promise<boolean>;
    /**
     * @param {number} index
     * @param {string} name
     * @param {string} value
     * @param {function(boolean):void=} userCallback
     */
    insertPropertyAt(index: number, name: string, value: string, userCallback?: ((arg0: boolean) => void) | undefined): void;
    /**
     * @param {string} name
     * @param {string} value
     * @param {function(boolean):void=} userCallback
     */
    appendProperty(name: string, value: string, userCallback?: ((arg0: boolean) => void) | undefined): void;
}
export type Type = string;
export namespace Type {
    export const Regular: string;
    export const Inline: string;
    export const Attributes: string;
}
import { CSSModel } from "./CSSModel.js";
import { CSSRule } from "./CSSRule.js";
import { CSSProperty } from "./CSSProperty.js";
import * as TextUtils from "../text_utils/text_utils.js";
import { Edit } from "./CSSModel.js";
import { Target } from "./SDKModel.js";
