export function escapeCharacters(inputString: string, charsToEscape: string): string;
export type FORMATTER_TOKEN = {
    type: FORMATTER_TYPES;
    value: (string | {
        description: string;
    } | undefined);
    specifier: (string | undefined);
    precision: (number | undefined);
    substitutionIndex: (number | undefined);
};
/** @typedef {{type: !FORMATTER_TYPES, value: (string|{description: string}|undefined), specifier: (string|undefined), precision: (number|undefined), substitutionIndex: (number|undefined)}} */
export let FORMATTER_TOKEN: any;
export function tokenizeFormatString(formatString: string, formatters: {
    [x: string]: (arg0: string, ...args: any[]) => any;
}): Array<FORMATTER_TOKEN>;
export function format<T>(formatString: string, substitutions: ArrayLike<any> | null, formatters: {
    [x: string]: (arg0: string, ...args: any[]) => any;
}, initialValue: T, append: (arg0: T, arg1: any) => T, tokenizedFormat?: Array<Object> | undefined): {
    formattedResult: T;
    unusedSubstitutions: ArrayLike<any> | null;
};
export namespace standardFormatters {
    export function d(substitution: any): number;
    export function f(substitution: any, token: {
        type: string;
        value: string | {
            description: string;
        } | undefined;
        specifier: string | undefined;
        precision: number | undefined;
        substitutionIndex: number | undefined;
    }): number;
    export function s(substitution: any): string;
}
export function vsprintf(formatString: string, substitutions: Array<any>): string;
export function sprintf(format: string, ...args: any[]): string;
export function toBase64(inputString: string): string;
export function findIndexesOfSubString(inputString: string, searchString: string): Array<number>;
export function findLineEndingIndexes(inputString: string): Array<number>;
export function isWhitespace(inputString: string): boolean;
export function trimURL(url: string, baseURLDomain?: (string | null) | undefined): string;
export function collapseWhitespace(inputString: string): string;
export function reverse(inputString: string): string;
export function replaceControlCharacters(inputString: string): string;
export function countWtf8Bytes(inputString: string): number;
export function stripLineBreaks(inputStr: string): string;
export function toTitleCase(inputStr: string): string;
export function removeURLFragment(inputStr: string): string;
export type FORMATTER_TYPES = string;
declare namespace FORMATTER_TYPES {
    export const STRING: string;
    export const SPECIFIER: string;
}
export {};
