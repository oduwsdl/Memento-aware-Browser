/**
 * @unrestricted
 */
export class FormattedContentBuilder {
    /**
     * @param {string} indentString
     */
    constructor(indentString: string);
    _lastOriginalPosition: number;
    /** @type {!Array.<string>} */
    _formattedContent: Array<string>;
    _formattedContentLength: number;
    _lastFormattedPosition: number;
    /** @type {!{original: !Array.<number>, formatted: !Array.<number>}} */
    _mapping: {
        original: Array<number>;
        formatted: Array<number>;
    };
    _nestingLevel: number;
    _indentString: string;
    /** @type {!Map<number, string>} */
    _cachedIndents: Map<number, string>;
    /** @type {number} */
    _newLines: number;
    _softSpace: boolean;
    _hardSpaces: number;
    _enforceSpaceBetweenWords: boolean;
    /**
     * @param {boolean} value
     * @return {boolean}
     */
    setEnforceSpaceBetweenWords(value: boolean): boolean;
    /**
     * @param {string} token
     * @param {number} offset
     */
    addToken(token: string, offset: number): void;
    addSoftSpace(): void;
    addHardSpace(): void;
    /**
     * @param {boolean=} noSquash
     */
    addNewLine(noSquash?: boolean | undefined): void;
    increaseNestingLevel(): void;
    decreaseNestingLevel(): void;
    _appendFormatting(): void;
    /**
     * @return {string}
     */
    content(): string;
    /**
     * @return {!{original: !Array.<number>, formatted: !Array.<number>}}
     */
    mapping(): {
        original: Array<number>;
        formatted: Array<number>;
    };
    /**
     * @return {string}
     */
    _indent(): string;
    /**
     * @param {string} text
     */
    _addText(text: string): void;
    /**
     * @param {number} originalPosition
     */
    _addMappingIfNeeded(originalPosition: number): void;
}
