/**
 * @unrestricted
 */
export class Color {
    /**
     * @param {string} text
     * @return {?Color}
     */
    static parse(text: string): Color | null;
    /**
     * @param {!Array.<number>} rgba
     * @return {!Color}
     */
    static fromRGBA(rgba: Array<number>): Color;
    /**
     * @param {!Array.<number>} hsva
     * @return {!Color}
     */
    static fromHSVA(hsva: Array<number>): Color;
    /**
     * @param {string} value
     * @return {number|null}
     */
    static _parsePercentOrNumber(value: string): number | null;
    /**
     * @param {string} value
     * @return {number|null}
     */
    static _parseRgbNumeric(value: string): number | null;
    /**
     * @param {string} value
     * @return {number|null}
     */
    static _parseHueNumeric(value: string): number | null;
    /**
     * @param {string} value
     * @return {number|null}
     */
    static _parseSatLightNumeric(value: string): number | null;
    /**
     * @param {string} value
     * @return {number|null}
     */
    static _parseAlphaNumeric(value: string): number | null;
    /**
     * @param {!Array.<number>} hsva
     * @param {!Array.<number>} out_hsla
     */
    static _hsva2hsla(hsva: Array<number>, out_hsla: Array<number>): void;
    /**
     * @param {!Array.<number>} hsl
     * @param {!Array.<number>} out_rgb
     */
    static hsl2rgb(hsl: Array<number>, out_rgb: Array<number>): void;
    /**
     * @param {!Array<number>} hsva
     * @param {!Array<number>} out_rgba
     */
    static hsva2rgba(hsva: Array<number>, out_rgba: Array<number>): void;
    /**
     * Compute a desired luminance given a given luminance and a desired contrast
     * ratio.
     * @param {number} luminance The given luminance.
     * @param {number} contrast The desired contrast ratio.
     * @param {boolean} lighter Whether the desired luminance is lighter or darker
     * than the given luminance. If no luminance can be found which meets this
     * requirement, a luminance which meets the inverse requirement will be
     * returned.
     * @return {number} The desired luminance.
     */
    static desiredLuminance(luminance: number, contrast: number, lighter: boolean): number;
    /**
     * @param {!Array.<number>} rgba
     * @param {!Format} format
     * @param {string=} originalText
     */
    constructor(rgba: Array<number>, format: Format, originalText?: string | undefined);
    _hsla: number[] | undefined;
    _rgba: number[];
    _originalText: string | null;
    _originalTextIsValid: boolean;
    _format: string;
    /**
     * @return {!Format}
     */
    format(): Format;
    /**
     * @return {!Array.<number>} HSLA with components within [0..1]
     */
    hsla(): Array<number>;
    /**
     * @return {!Array.<number>}
     */
    canonicalHSLA(): Array<number>;
    /**
     * @return {!Array.<number>} HSVA with components within [0..1]
     */
    hsva(): Array<number>;
    /**
     * @return {boolean}
     */
    hasAlpha(): boolean;
    /**
     * @return {!Format}
     */
    detectHEXFormat(): Format;
    /**
     * @param {?string=} format
     * @return {?string}
     */
    asString(format?: (string | null) | undefined): string | null;
    /**
     * @return {!Array<number>}
     */
    rgba(): Array<number>;
    /**
     * @return {!Array.<number>}
     */
    canonicalRGBA(): Array<number>;
    /**
     * @return {?string} nickname
     */
    nickname(): string | null;
    /**
     * @return {!{r: number, g: number, b: number, a: (number|undefined)}}
     */
    toProtocolRGBA(): {
        r: number;
        g: number;
        b: number;
        a: (number | undefined);
    };
    /**
     * @return {!Color}
     */
    invert(): Color;
    /**
     * @param {number} alpha
     * @return {!Color}
     */
    setAlpha(alpha: number): Color;
    /**
     * @param {!Color} fgColor
     * @return {!Color}
     */
    blendWith(fgColor: Color): Color;
    /**
     * @param {!Format} format
     */
    setFormat(format: Format): void;
}
/** @type {!RegExp} */
export const Regex: RegExp;
export type Format = string;
export namespace Format {
    export const Original: string;
    export const Nickname: string;
    export const HEX: string;
    export const ShortHEX: string;
    export const HEXA: string;
    export const ShortHEXA: string;
    export const RGB: string;
    export const RGBA: string;
    export const HSL: string;
    export const HSLA: string;
}
/** @type {!Object<string, !Array.<number>>} */
export const Nicknames: {
    [x: string]: Array<number>;
};
export namespace PageHighlight {
    export const Content: Color;
    export const ContentLight: Color;
    export const ContentOutline: Color;
    export const Padding: Color;
    export const PaddingLight: Color;
    export const Border: Color;
    export const BorderLight: Color;
    export const Margin: Color;
    export const MarginLight: Color;
    export const EventTarget: Color;
    export const Shape: Color;
    export const ShapeMargin: Color;
    export const CssGrid: Color;
    export const GridCellBorder: Color;
    export const GridBorder: Color;
    export const GridRowGapBackground: Color;
    export const GridColumnGapBackground: Color;
    export const GridRowGapHatch: Color;
    export const GridColumnGapHatch: Color;
}
export class Generator {
    /**
     * @param {!{min: number, max: number, count: (number|undefined)}|number=} hueSpace
     * @param {!{min: number, max: number, count: (number|undefined)}|number=} satSpace
     * @param {!{min: number, max: number, count: (number|undefined)}|number=} lightnessSpace
     * @param {!{min: number, max: number, count: (number|undefined)}|number=} alphaSpace
     */
    constructor(hueSpace?: ({
        min: number;
        max: number;
        count: (number | undefined);
    } | number) | undefined, satSpace?: ({
        min: number;
        max: number;
        count: (number | undefined);
    } | number) | undefined, lightnessSpace?: ({
        min: number;
        max: number;
        count: (number | undefined);
    } | number) | undefined, alphaSpace?: ({
        min: number;
        max: number;
        count: (number | undefined);
    } | number) | undefined);
    _hueSpace: number | {
        min: number;
        max: number;
        count: (number | undefined);
    };
    _satSpace: number | {
        min: number;
        max: number;
        count: (number | undefined);
    };
    _lightnessSpace: number | {
        min: number;
        max: number;
        count: (number | undefined);
    };
    _alphaSpace: number | {
        min: number;
        max: number;
        count: (number | undefined);
    };
    /** @type {!Map<string, string>} */
    _colors: Map<string, string>;
    /**
     * @param {string} id
     * @param {string} color
     */
    setColorForID(id: string, color: string): void;
    /**
     * @param {string} id
     * @return {string}
     */
    colorForID(id: string): string;
    /**
     * @param {string} id
     * @return {string}
     */
    _generateColorForID(id: string): string;
    /**
     * @param {number} index
     * @param {!{min: number, max: number, count: (number|undefined)}|number} space
     * @return {number}
     */
    _indexToValueInSpace(index: number, space: number | {
        min: number;
        max: number;
        count: (number | undefined);
    }): number;
}
