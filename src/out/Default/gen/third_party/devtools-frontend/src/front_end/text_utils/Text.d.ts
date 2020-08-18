/**
 * @unrestricted
 */
export class Text {
    /**
     * @param {string} value
     */
    constructor(value: string);
    _value: string;
    /**
     * @return {!Array<number>}
     */
    lineEndings(): Array<number>;
    _lineEndings: number[] | undefined;
    /**
     * @return {string}
     */
    value(): string;
    /**
     * @return {number}
     */
    lineCount(): number;
    /**
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {number}
     */
    offsetFromPosition(lineNumber: number, columnNumber: number): number;
    /**
     * @param {number} offset
     * @return {!Position}
     */
    positionFromOffset(offset: number): Position;
    /**
     * @param {number} lineNumber
     * @return {string}
     */
    lineAt(lineNumber: number): string;
    /**
     * @param {!TextRange} range
     * @return {!SourceRange}
     */
    toSourceRange(range: TextRange): SourceRange;
    /**
     * @param {!SourceRange} sourceRange
     * @return {!TextRange}
     */
    toTextRange(sourceRange: SourceRange): TextRange;
    /**
     * @param {!TextRange} range
     * @param {string} replacement
     * @return {string}
     */
    replaceRange(range: TextRange, replacement: string): string;
    /**
     * @param {!TextRange} range
     * @return {string}
     */
    extract(range: TextRange): string;
}
export type Position = {
    lineNumber: number;
    columnNumber: number;
};
/** @typedef {{lineNumber: number, columnNumber: number}} */
export let Position: any;
import { TextRange } from "./TextRange.js";
import { SourceRange } from "./TextRange.js";
