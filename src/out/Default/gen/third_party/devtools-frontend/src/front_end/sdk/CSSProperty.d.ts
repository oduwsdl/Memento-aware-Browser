export class CSSProperty {
    /**
     * @param {!CSSStyleDeclaration} ownerStyle
     * @param {number} index
     * @param {!Protocol.CSS.CSSProperty} payload
     * @return {!CSSProperty}
     */
    static parsePayload(ownerStyle: CSSStyleDeclaration, index: number, payload: Protocol.CSS.CSSProperty): CSSProperty;
    /**
     * @param {string} styleText
     * @param {string} indentation
     * @param {string} endIndentation
     * @param {!TextUtils.TextUtils.TokenizerFactory} tokenizerFactory
     * @return {string}
     */
    static _formatStyle(styleText: string, indentation: string, endIndentation: string, tokenizerFactory: TextUtils.TextUtils.TokenizerFactory): string;
    /**
     * @param {!CSSStyleDeclaration} ownerStyle
     * @param {number} index
     * @param {string} name
     * @param {string} value
     * @param {boolean} important
     * @param {boolean} disabled
     * @param {boolean} parsedOk
     * @param {boolean} implicit
     * @param {?string=} text
     * @param {!Protocol.CSS.SourceRange=} range
     */
    constructor(ownerStyle: CSSStyleDeclaration, index: number, name: string, value: string, important: boolean, disabled: boolean, parsedOk: boolean, implicit: boolean, text?: (string | null) | undefined, range?: Protocol.CSS.SourceRange | undefined);
    ownerStyle: CSSStyleDeclaration;
    index: number;
    name: string;
    value: string;
    important: boolean;
    disabled: boolean;
    parsedOk: boolean;
    implicit: boolean;
    text: string | null | undefined;
    /** @type {?TextUtils.TextRange.TextRange} */
    range: TextUtils.TextRange.TextRange | null;
    _active: boolean;
    _nameRange: TextUtils.TextRange.TextRange | null;
    _valueRange: TextUtils.TextRange.TextRange | null;
    _ensureRanges(): void;
    /**
     * @return {?TextUtils.TextRange.TextRange}
     */
    nameRange(): TextUtils.TextRange.TextRange | null;
    /**
     * @return {?TextUtils.TextRange.TextRange}
     */
    valueRange(): TextUtils.TextRange.TextRange | null;
    /**
     * @param {!Edit} edit
     */
    rebase(edit: Edit): void;
    /**
     * @param {boolean} active
     */
    setActive(active: boolean): void;
    get propertyText(): string | null;
    /**
     * @return {boolean}
     */
    activeInStyle(): boolean;
    /**
     * @param {string} propertyText
     * @param {boolean} majorChange
     * @param {boolean=} overwrite
     * @return {!Promise.<boolean>}
     */
    setText(propertyText: string, majorChange: boolean, overwrite?: boolean | undefined): Promise<boolean>;
    /**
     * @param {string} text
     * @return {string}
     */
    _detectIndentation(text: string): string;
    /**
     * @param {string} newValue
     * @param {boolean} majorChange
     * @param {boolean} overwrite
     * @param {function(boolean):void=} userCallback
     */
    setValue(newValue: string, majorChange: boolean, overwrite: boolean, userCallback?: ((arg0: boolean) => void) | undefined): void;
    /**
     * @param {boolean} disabled
     * @return {!Promise.<boolean>}
     */
    setDisabled(disabled: boolean): Promise<boolean>;
}
import { CSSStyleDeclaration } from "./CSSStyleDeclaration.js";
import * as TextUtils from "../text_utils/text_utils.js";
import { Edit } from "./CSSModel.js";
