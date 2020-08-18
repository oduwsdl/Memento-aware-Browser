/**
 * @unrestricted
 */
export class TextCursor {
    /**
     * @param {!Array<number>} lineEndings
     */
    constructor(lineEndings: Array<number>);
    _lineEndings: number[];
    _offset: number;
    _lineNumber: number;
    _columnNumber: number;
    /**
     * @param {number} offset
     */
    advance(offset: number): void;
    /**
     * @return {number}
     */
    offset(): number;
    /**
     * @param {number} offset
     */
    resetTo(offset: number): void;
    /**
     * @return {number}
     */
    lineNumber(): number;
    /**
     * @return {number}
     */
    columnNumber(): number;
}
