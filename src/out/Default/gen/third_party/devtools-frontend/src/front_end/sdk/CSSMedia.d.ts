export class CSSMediaQuery {
    /**
     * @param {!Protocol.CSS.MediaQuery} payload
     * @return {!CSSMediaQuery}
     */
    static parsePayload(payload: Protocol.CSS.MediaQuery): CSSMediaQuery;
    /**
     * @param {!Protocol.CSS.MediaQuery} payload
     */
    constructor(payload: Protocol.CSS.MediaQuery);
    _active: boolean;
    /** @type {?Array<!CSSMediaQueryExpression>} */
    _expressions: Array<CSSMediaQueryExpression> | null;
    /**
     * @return {boolean}
     */
    active(): boolean;
    /**
     * @return {?Array<!CSSMediaQueryExpression>}
     */
    expressions(): Array<CSSMediaQueryExpression> | null;
}
export class CSSMediaQueryExpression {
    /**
     * @param {!Protocol.CSS.MediaQueryExpression} payload
     * @return {!CSSMediaQueryExpression}
     */
    static parsePayload(payload: Protocol.CSS.MediaQueryExpression): CSSMediaQueryExpression;
    /**
     * @param {!Protocol.CSS.MediaQueryExpression} payload
     */
    constructor(payload: Protocol.CSS.MediaQueryExpression);
    _value: number;
    _unit: string;
    _feature: string;
    /** @type {?TextUtils.TextRange.TextRange} */
    _valueRange: TextUtils.TextRange.TextRange | null;
    _computedLength: number | null;
    /**
     * @return {number}
     */
    value(): number;
    /**
     * @return {string}
     */
    unit(): string;
    /**
     * @return {string}
     */
    feature(): string;
    /**
     * @return {?TextUtils.TextRange.TextRange}
     */
    valueRange(): TextUtils.TextRange.TextRange | null;
    /**
     * @return {?number}
     */
    computedLength(): number | null;
}
/**
 * @unrestricted
 */
export class CSSMedia {
    /**
     * @param {!CSSModel} cssModel
     * @param {!Protocol.CSS.CSSMedia} payload
     * @return {!CSSMedia}
     */
    static parsePayload(cssModel: CSSModel, payload: Protocol.CSS.CSSMedia): CSSMedia;
    /**
     * @param {!CSSModel} cssModel
     * @param {!Array.<!Protocol.CSS.CSSMedia>} payload
     * @return {!Array.<!CSSMedia>}
     */
    static parseMediaArrayPayload(cssModel: CSSModel, payload: Array<Protocol.CSS.CSSMedia>): Array<CSSMedia>;
    /**
     * @param {!CSSModel} cssModel
     * @param {!Protocol.CSS.CSSMedia} payload
     */
    constructor(cssModel: CSSModel, payload: Protocol.CSS.CSSMedia);
    _cssModel: CSSModel;
    /**
     * @param {!Protocol.CSS.CSSMedia} payload
     */
    _reinitialize(payload: Protocol.CSS.CSSMedia): void;
    text: string | undefined;
    source: Protocol.CSS.CSSMediaSource | undefined;
    sourceURL: string | undefined;
    /** @type {?TextUtils.TextRange.TextRange} */
    range: TextUtils.TextRange.TextRange | null | undefined;
    styleSheetId: string | undefined;
    /** @type {?Array<!CSSMediaQuery>} */
    mediaList: CSSMediaQuery[] | null | undefined;
    /**
     * @param {!Edit} edit
     */
    rebase(edit: Edit): void;
    /**
     * @param {!CSSMedia} other
     * @return {boolean}
     */
    equal(other: CSSMedia): boolean;
    /**
     * @return {boolean}
     */
    active(): boolean;
    /**
     * @return {number|undefined}
     */
    lineNumberInSource(): number | undefined;
    /**
     * @return {number|undefined}
     */
    columnNumberInSource(): number | undefined;
    /**
     * @return {?CSSStyleSheetHeader}
     */
    header(): CSSStyleSheetHeader | null;
    /**
     * @return {?CSSLocation}
     */
    rawLocation(): CSSLocation | null;
}
export namespace Source {
    export const LINKED_SHEET: string;
    export const INLINE_SHEET: string;
    export const MEDIA_RULE: string;
    export const IMPORT_RULE: string;
}
import * as TextUtils from "../text_utils/text_utils.js";
import { CSSModel } from "./CSSModel.js";
import { Edit } from "./CSSModel.js";
import { CSSStyleSheetHeader } from "./CSSStyleSheetHeader.js";
import { CSSLocation } from "./CSSModel.js";
