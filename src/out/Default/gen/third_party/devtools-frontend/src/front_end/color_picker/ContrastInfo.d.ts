export class ContrastInfo extends Common.ObjectWrapper.ObjectWrapper {
    /**
     * @param {string} fontSize
     * @param {string} fontWeight
     * @return {boolean}
     */
    static computeIsLargeFont(fontSize: string, fontWeight: string): boolean;
    /**
     * @param {?ContrastInfoType} contrastInfo
     */
    constructor(contrastInfo: ContrastInfoType | null);
    _isNull: boolean;
    /** @type {?number} */
    _contrastRatio: number | null;
    /** @type {?Object<string, number>} */
    _contrastRatioThresholds: {
        [x: string]: number;
    } | null;
    /** @type {?Common.Color.Color} */
    _fgColor: Common.Color.Color | null;
    /** @type {?Common.Color.Color} */
    _bgColor: Common.Color.Color | null;
    /**
     * @return {boolean}
     */
    isNull(): boolean;
    /**
     * @param {!Common.Color.Color} fgColor
     */
    setColor(fgColor: Common.Color.Color): void;
    /**
     * @return {?Common.Color.Color}
     */
    color(): Common.Color.Color | null;
    /**
     * @return {?number}
     */
    contrastRatio(): number | null;
    /**
     * @param {!Common.Color.Color} bgColor
     */
    setBgColor(bgColor: Common.Color.Color): void;
    /**
     * @param {!Common.Color.Color} bgColor
     */
    _setBgColorInternal(bgColor: Common.Color.Color): void;
    /**
     * @return {?Common.Color.Color}
     */
    bgColor(): Common.Color.Color | null;
    _updateContrastRatio(): void;
    /**
     * @param {string} level
     * @return {?number}
     */
    contrastRatioThreshold(level: string): number | null;
}
export type Events = symbol;
export namespace Events {
    export const ContrastInfoUpdated: symbol;
}
export type ContrastInfoType = {
    backgroundColors: Array<string> | null;
    computedFontSize: string;
    computedFontWeight: string;
};
/** @typedef {{backgroundColors: ?Array<string>, computedFontSize: string, computedFontWeight: string}} */
export let ContrastInfoType: any;
import * as Common from "../common/common.js";
