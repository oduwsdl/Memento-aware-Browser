export class SecurityOriginManager extends SDKModel {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _mainSecurityOrigin: string;
    /** @type {?string} */
    _unreachableMainSecurityOrigin: string | null;
    /** @type {!Set<string>} */
    _securityOrigins: Set<string>;
    /**
     * @param {!Set<string>} securityOrigins
     */
    updateSecurityOrigins(securityOrigins: Set<string>): void;
    /**
     * @return {!Array<string>}
     */
    securityOrigins(): Array<string>;
    /**
     * @return {string}
     */
    mainSecurityOrigin(): string;
    /**
     * @return {?string}
     */
    unreachableMainSecurityOrigin(): string | null;
    /**
     * @param {string} securityOrigin
     * @param {string} unreachableSecurityOrigin
     */
    setMainSecurityOrigin(securityOrigin: string, unreachableSecurityOrigin: string): void;
}
export type Events = symbol;
export namespace Events {
    export const SecurityOriginAdded: symbol;
    export const SecurityOriginRemoved: symbol;
    export const MainSecurityOriginChanged: symbol;
}
import { SDKModel } from "./SDKModel.js";
import { Target } from "./SDKModel.js";
