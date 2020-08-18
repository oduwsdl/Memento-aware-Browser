/**
 * @param {string} string
 * @param {...*} vararg
 * @return {string}
 */
export function UIString(string: string, ...vararg: any[]): string;
/**
 * @param {string} string
 * @param {?ArrayLike<*>} values
 * @return {string}
 */
export function serializeUIString(string: string, values?: ArrayLike<any> | null): string;
/**
 * @param {string=} serializedMessage
 * @return {*}
 */
export function deserializeUIString(serializedMessage?: string | undefined): any;
/**
 * @param {string} string
 * @return {string}
 */
export function localize(string: string): string;
/**
 * @param {!ITemplateArray|string} strings
 * @param {...*} vararg
 * @return {string}
 */
export function ls(strings: ITemplateArray | string, ...vararg: any[]): string;
/**
 * @unrestricted
 */
export class UIStringFormat {
    /**
     * @param {string} a
     * @param {*} b
     * @return {string}
     */
    static _append(a: string, b: any): string;
    /**
     * @param {string} format
     */
    constructor(format: string);
    /** @type {string} */
    _localizedFormat: string;
    /** @type {!Array.<!StringUtilities.FORMATTER_TOKEN>} */
    _tokenizedFormat: Array<StringUtilities.FORMATTER_TOKEN>;
    /**
     * @param {...*} vararg
     * @return {string}
     */
    format(...args: any[]): string;
}
import * as StringUtilities from "./string-utilities.js";
