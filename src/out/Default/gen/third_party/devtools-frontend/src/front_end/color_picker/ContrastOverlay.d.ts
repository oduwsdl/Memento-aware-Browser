export class ContrastOverlay {
    /**
     * @param {!ContrastInfo} contrastInfo
     * @param {!Element} colorElement
     */
    constructor(contrastInfo: ContrastInfo, colorElement: Element);
    /** @type {!ContrastInfo} */
    _contrastInfo: ContrastInfo;
    _visible: boolean;
    _contrastRatioSVG: HTMLElement;
    /** @type {!Map<string, !Element>} */
    _contrastRatioLines: Map<string, Element>;
    _width: number;
    _height: number;
    _contrastRatioLineBuilder: ContrastRatioLineBuilder;
    _contrastRatioLinesThrottler: Common.Throttler.Throttler;
    _drawContrastRatioLinesBound: () => Promise<void>;
    _update(): void;
    /**
     * @param {number} width
     * @param {number} height
     */
    setDimensions(width: number, height: number): void;
    /**
     * @param {boolean} visible
     */
    setVisible(visible: boolean): void;
    _drawContrastRatioLines(): Promise<void>;
}
export class ContrastRatioLineBuilder {
    /**
     * @param {!ContrastInfo} contrastInfo
     */
    constructor(contrastInfo: ContrastInfo);
    /** @type {!ContrastInfo} */
    _contrastInfo: ContrastInfo;
    /**
     * @param {number} width
     * @param {number} height
     * @param {string} level
     * @return {?string}
     */
    drawContrastRatioLine(width: number, height: number, level: string): string | null;
}
import { ContrastInfo } from "./ContrastInfo.js";
import * as Common from "../common/common.js";
