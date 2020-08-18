/**
 * @param {string} text
 * @return {boolean}
 */
export function isMinified(text: string): boolean;
export namespace Utils {
    export function isStopChar(char: string): boolean;
    export function isWordChar(char: string): boolean;
    export function isSpaceChar(char: string): boolean;
    export function isWord(word: string): boolean;
    export function isOpeningBraceChar(char: string): boolean;
    export function isClosingBraceChar(char: string): boolean;
    export function isBraceChar(char: string): boolean;
    export function textToWords(text: string, isWordChar: (arg0: string) => boolean, wordCallback: (arg0: string) => any): void;
    export function lineIndent(line: string): string;
    export function isUpperCase(text: string): boolean;
    export function isLowerCase(text: string): boolean;
    /**
     * @param {string} text
     * @param {!Array<!RegExp>} regexes
     * @return {!Array<{value: string, position: number, regexIndex: number, captureGroups: !Array<string|undefined>}>}
     */
    export function splitStringByRegexes(text: string, regexes: RegExp[]): {
        value: string;
        position: number;
        regexIndex: number;
        captureGroups: (string | undefined)[];
    }[];
    /**
     * @param {string} text
     * @param {!Array<!RegExp>} regexes
     * @return {!Array<{value: string, position: number, regexIndex: number, captureGroups: !Array<string|undefined>}>}
     */
    export function splitStringByRegexes(text: string, regexes: RegExp[]): {
        value: string;
        position: number;
        regexIndex: number;
        captureGroups: (string | undefined)[];
    }[];
}
export class FilterParser {
    /**
     * @param {!ParsedFilter} filter
     * @return {!ParsedFilter}
     */
    static cloneFilter(filter: ParsedFilter): ParsedFilter;
    /**
     * @param {!Array<string>} keys
     */
    constructor(keys: Array<string>);
    _keys: string[];
    /**
     * @param {string} query
     * @return {!Array<!ParsedFilter>}
     */
    parse(query: string): Array<ParsedFilter>;
}
/**
 * @unrestricted
 */
export class BalancedJSONTokenizer {
    /**
     * @param {function(string):void} callback
     * @param {boolean=} findMultiple
     */
    constructor(callback: (arg0: string) => void, findMultiple?: boolean | undefined);
    _callback: (arg0: string) => void;
    /** @type {number} */
    _index: number;
    _balance: number;
    /** @type {string} */
    _buffer: string;
    _findMultiple: boolean;
    _closingDoubleQuoteRegex: RegExp;
    /**
     * @param {string} chunk
     * @return {boolean}
     */
    write(chunk: string): boolean;
    _lastBalancedIndex: number | undefined;
    _reportBalanced(): void;
    /**
     * @return {string}
     */
    remainder(): string;
}
/**
 * @interface
 */
export class TokenizerFactory {
    /**
     * @param {string} mimeType
     * @return {function(string, function(string, ?string, number, number):void):void}
     */
    createTokenizer(mimeType: string): (arg0: string, arg1: (arg0: string, arg1: string | null, arg2: number, arg3: number) => void) => void;
}
export function performSearchInContent(content: string, query: string, caseSensitive: boolean, isRegex: boolean): Array<SearchMatch>;
export type ParsedFilter = {
    key: (string | undefined);
    text: ((string | undefined) | null);
    regex: (RegExp | undefined);
    negative: boolean;
};
/** @typedef {{key:(string|undefined), text:(?string|undefined), regex:(!RegExp|undefined), negative:boolean}} */
export let ParsedFilter: any;
import { SearchMatch } from "./ContentProvider.js";
