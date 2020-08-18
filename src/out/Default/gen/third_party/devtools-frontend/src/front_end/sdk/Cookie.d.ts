/**
 *  @unrestricted
 */
export class Cookie {
    /**
       * @param {!Protocol.Network.Cookie} protocolCookie
       * @return {!Cookie}
       */
    static fromProtocolCookie(protocolCookie: Protocol.Network.Cookie): Cookie;
    /**
       * @param {string} name
       * @param {string} value
       * @param {?Type=} type
       * @param {!Protocol.Network.CookiePriority=} priority
       */
    constructor(name: string, value: string, type?: (Type | null) | undefined, priority?: Protocol.Network.CookiePriority | undefined);
    _name: string;
    _value: string;
    _type: number | null | undefined;
    /** @type {!Object<string, *>} */
    _attributes: {
        [x: string]: any;
    };
    _size: number;
    _priority: Protocol.Network.CookiePriority;
    /** @type {string|null} */
    _cookieLine: string | null;
    /**
     * @returns {string}
     */
    key(): string;
    /**
       * @return {string}
       */
    name(): string;
    /**
       * @return {string}
       */
    value(): string;
    /**
       * @return {?Type|undefined}
       */
    type(): (Type | undefined) | null;
    /**
       * @return {boolean}
       */
    httpOnly(): boolean;
    /**
       * @return {boolean}
       */
    secure(): boolean;
    /**
       * @return {!Protocol.Network.CookieSameSite}
       */
    sameSite(): Protocol.Network.CookieSameSite;
    /**
     * @return {!Protocol.Network.CookiePriority}
     */
    priority(): Protocol.Network.CookiePriority;
    /**
       * @return {boolean}
       */
    session(): boolean;
    /**
       * @return {string}
       */
    path(): string;
    /**
       * @return {string}
       */
    port(): string;
    /**
       * @return {string}
       */
    domain(): string;
    /**
       * @return {number}
       */
    expires(): number;
    /**
       * @return {number}
       */
    maxAge(): number;
    /**
       * @return {number}
       */
    size(): number;
    /**
       * @return {string|null}
       */
    url(): string | null;
    /**
       * @param {number} size
       */
    setSize(size: number): void;
    /**
     * @param {!Date} requestDate
     * @return {!Date|null}
     */
    expiresDate(requestDate: Date): Date | null;
    /**
     * @param {string} key
     * @param {string|number=} value
     */
    addAttribute(key: string, value?: (string | number) | undefined): void;
    /**
       * @param {string} cookieLine
       */
    setCookieLine(cookieLine: string): void;
    /**
       * @return {string|null}
       */
    getCookieLine(): string | null;
}
export type Type = number;
export namespace Type {
    export const Request: number;
    export const Response: number;
}
export type Attributes = string;
export namespace Attributes {
    export const Name: string;
    export const Value: string;
    export const Size: string;
    export const Domain: string;
    export const Path: string;
    export const Expires: string;
    export const HttpOnly: string;
    export const Secure: string;
    export const SameSite: string;
    export const Priority: string;
}
/**
 * A `CookieReference` uniquely identifies a cookie by the triple (name,domain,path). Additionally, a context may be
 * included to make it clear which site under Application>Cookies should be opened when revealing a `CookieReference`.
 */
export class CookieReference {
    /**
     * @param {string} name
     * @param {string} domain
     * @param {string} path
     * @param {string|undefined} contextUrl - Context in which to reveal the cookie.
     */
    constructor(name: string, domain: string, path: string, contextUrl: string | undefined);
    _name: string;
    _domain: string;
    _path: string;
    _contextUrl: string | undefined;
    /**
     * @returns {string}
     */
    domain(): string;
    /**
     * @returns {string|undefined}
     */
    contextUrl(): string | undefined;
}
