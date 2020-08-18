/**
 * @unrestricted
 */
export class TextRange {
    /**
     * @param {number} line
     * @param {number} column
     * @return {!TextRange}
     */
    static createFromLocation(line: number, column: number): TextRange;
    /**
     * @param {{startLine: number, startColumn: number, endLine: number, endColumn: number}} serializedTextRange
     * @return {!TextRange}
     */
    static fromObject(serializedTextRange: {
        startLine: number;
        startColumn: number;
        endLine: number;
        endColumn: number;
    }): TextRange;
    /**
     * @param {!TextRange} range1
     * @param {!TextRange} range2
     * @return {number}
     */
    static comparator(range1: TextRange, range2: TextRange): number;
    /**
     * @param {!TextRange} oldRange
     * @param {string} newText
     * @return {!TextRange}
     */
    static fromEdit(oldRange: TextRange, newText: string): TextRange;
    /**
     * @param {number} startLine
     * @param {number} startColumn
     * @param {number} endLine
     * @param {number} endColumn
     */
    constructor(startLine: number, startColumn: number, endLine: number, endColumn: number);
    startLine: number;
    startColumn: number;
    endLine: number;
    endColumn: number;
    /**
     * @return {boolean}
     */
    isEmpty(): boolean;
    /**
     * @param {!TextRange=} range
     * @return {boolean}
     */
    immediatelyPrecedes(range?: TextRange | undefined): boolean;
    /**
     * @param {!TextRange=} range
     * @return {boolean}
     */
    immediatelyFollows(range?: TextRange | undefined): boolean;
    /**
     * @param {!TextRange} range
     * @return {boolean}
     */
    follows(range: TextRange): boolean;
    /**
     * @return {number}
     */
    get linesCount(): number;
    /**
     * @return {!TextRange}
     */
    collapseToEnd(): TextRange;
    /**
     * @return {!TextRange}
     */
    collapseToStart(): TextRange;
    /**
     * @return {!TextRange}
     */
    normalize(): TextRange;
    /**
     * @return {!TextRange}
     */
    clone(): TextRange;
    /**
     * @return {!{startLine: number, startColumn: number, endLine: number, endColumn: number}}
     */
    serializeToObject(): {
        startLine: number;
        startColumn: number;
        endLine: number;
        endColumn: number;
    };
    /**
     * @param {!TextRange} other
     * @return {number}
     */
    compareTo(other: TextRange): number;
    /**
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {number}
     */
    compareToPosition(lineNumber: number, columnNumber: number): number;
    /**
     * @param {!TextRange} other
     * @return {boolean}
     */
    equal(other: TextRange): boolean;
    /**
     * @param {number} line
     * @param {number} column
     * @return {!TextRange}
     */
    relativeTo(line: number, column: number): TextRange;
    /**
     * @param {number} line
     * @param {number} column
     * @return {!TextRange}
     */
    relativeFrom(line: number, column: number): TextRange;
    /**
     * @param {!TextRange} originalRange
     * @param {!TextRange} editedRange
     * @return {!TextRange}
     */
    rebaseAfterTextEdit(originalRange: TextRange, editedRange: TextRange): TextRange;
    /**
     * @override
     * @return {string}
     */
    toString(): string;
    /**
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {boolean}
     */
    containsLocation(lineNumber: number, columnNumber: number): boolean;
}
/**
 * @unrestricted
 */
export class SourceRange {
    /**
     * @param {number} offset
     * @param {number} length
     */
    constructor(offset: number, length: number);
    offset: number;
    length: number;
}
/**
 * @unrestricted
 */
export class SourceEdit {
    /**
     * @param {!SourceEdit} edit1
     * @param {!SourceEdit} edit2
     * @return {number}
     */
    static comparator(edit1: SourceEdit, edit2: SourceEdit): number;
    /**
     * @param {string} sourceURL
     * @param {!TextRange} oldRange
     * @param {string} newText
     */
    constructor(sourceURL: string, oldRange: TextRange, newText: string);
    sourceURL: string;
    oldRange: TextRange;
    newText: string;
    /**
     * @return {!TextRange}
     */
    newRange(): TextRange;
}
