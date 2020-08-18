/**
 * @unrestricted
 */
export class CookieParser {
    /**
     * @param {string|undefined} header
     * @return {?Array<!Cookie>}
     */
    static parseCookie(header: string | undefined): Array<Cookie> | null;
    /**
     * @param {string|undefined} header
     * @param {string=} domain
     * @return {?Array<!Cookie>}
     */
    static parseSetCookie(header: string | undefined, domain?: string | undefined): Array<Cookie> | null;
    /**
     * @param {string=} domain
     */
    constructor(domain?: string | undefined);
    _domain: string;
    /** @type {!Array<!Cookie>} */
    _cookies: Array<Cookie>;
    /** @type {string|undefined} */
    _input: string | undefined;
    _originalInputLength: number;
    /**
     * @return {!Array<!Cookie>}
     */
    cookies(): Array<Cookie>;
    /**
     * @param {string|undefined} cookieHeader
     * @return {?Array<!Cookie>}
     */
    parseCookie(cookieHeader: string | undefined): Array<Cookie> | null;
    /**
     * @param {string|undefined} setCookieHeader
     * @return {?Array<!Cookie>}
     */
    parseSetCookie(setCookieHeader: string | undefined): Array<Cookie> | null;
    /**
     * @param {string|undefined} headerValue
     * @return {boolean}
     */
    _initialize(headerValue: string | undefined): boolean;
    _lastCookie: Cookie | null | undefined;
    _lastCookieLine: string | undefined;
    _flushCookie(): void;
    /**
     * @return {?KeyValue}
     */
    _extractKeyValue(): KeyValue | null;
    /**
     * @return {boolean}
     */
    _advanceAndCheckCookieDelimiter(): boolean;
    /**
     * @param {!KeyValue} keyValue
     * @param {!Type} type
     */
    _addCookie(keyValue: KeyValue, type: Type): void;
    _lastCookiePosition: number | undefined;
}
import { Cookie } from "./Cookie.js";
declare class KeyValue {
    /**
     * @param {string} key
     * @param {string|undefined} value
     * @param {number} position
     */
    constructor(key: string, value: string | undefined, position: number);
    key: string;
    value: string | undefined;
    position: number;
}
import { Type } from "./Cookie.js";
export {};
