export class CookieModel extends SDKModel {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    /** Array<!Cookie> */
    _blockedCookies: Map<any, any>;
    _cookieToBlockedReasons: Map<any, any>;
    /**
     * @param {!Cookie} cookie
     * @param {?Array<!BlockedReason>} blockedReasons
     */
    addBlockedCookie(cookie: Cookie, blockedReasons: Array<BlockedReason> | null): void;
    getCookieToBlockedReasonsMap(): Map<any, any>;
    /**
     * @param {!Array<string>} urls
     * @return {!Promise<!Array<!Cookie>>}
     */
    getCookies(urls: Array<string>): Promise<Array<Cookie>>;
    /**
     * @param {!Cookie} cookie
     * @return {!Promise<void>}
     */
    deleteCookie(cookie: Cookie): Promise<void>;
    /**
     * @param {string=} domain
     * @return {!Promise<void>}
     */
    clear(domain?: string | undefined): Promise<void>;
    /**
     * @param {!Cookie} cookie
     * @return {!Promise<boolean>}
     */
    saveCookie(cookie: Cookie): Promise<boolean>;
    /**
     * Returns cookies needed by current page's frames whose security origins are |domain|.
     * @param {?string} domain
     * @return {!Promise<!Array<!Cookie>>}
     */
    getCookiesForDomain(domain: string | null): Promise<Array<Cookie>>;
    /**
     * @param {!Array<!Cookie>} cookies
     * @return {!Promise<void>}
     */
    _deleteAll(cookies: Array<Cookie>): Promise<void>;
}
export type BlockedReason = {
    uiString: string;
    attribute: Attributes | null;
};
/** @typedef {!{uiString: string, attribute: ?Attributes}} */
export let BlockedReason: any;
import { SDKModel } from "./SDKModel.js";
import { Cookie } from "./Cookie.js";
import { Target } from "./SDKModel.js";
import { Attributes } from "./Cookie.js";
