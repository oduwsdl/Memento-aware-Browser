/**
 * @interface
 */
export class ContentProvider {
    /**
     * @return {string}
     */
    contentURL(): string;
    /**
     * @return {!Common.ResourceType.ResourceType}
     */
    contentType(): Common.ResourceType.ResourceType;
    /**
     * @return {!Promise<boolean>}
     */
    contentEncoded(): Promise<boolean>;
    /**
     * @return {!Promise<!DeferredContent>}
     */
    requestContent(): Promise<DeferredContent>;
    /**
     * @param {string} query
     * @param {boolean} caseSensitive
     * @param {boolean} isRegex
     * @return {!Promise<!Array<!SearchMatch>>}
     */
    searchInContent(query: string, caseSensitive: boolean, isRegex: boolean): Promise<Array<SearchMatch>>;
}
/**
 * @unrestricted
 */
export class SearchMatch {
    /**
     * @param {number} lineNumber
     * @param {string} lineContent
     */
    constructor(lineNumber: number, lineContent: string);
    lineNumber: number;
    lineContent: string;
}
export function contentAsDataURL(content: string | null, mimeType: string, contentEncoded: boolean, charset?: (string | null) | undefined): string | null;
export type DeferredContent = {
    content: string;
    isEncoded: boolean;
} | {
    content: null;
    error: string;
    isEncoded: boolean;
};
/**
 * @typedef {{
 *    content: string,
 *    isEncoded: boolean,
 * }|{
 *    content: null,
 *    error: string,
 *    isEncoded: boolean,
 * }}
 */
export let DeferredContent: any;
import * as Common from "../common/common.js";
