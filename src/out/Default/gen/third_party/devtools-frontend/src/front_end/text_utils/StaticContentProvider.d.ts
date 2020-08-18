/**
 * @implements {ContentProvider}
 * @unrestricted
 */
export class StaticContentProvider implements ContentProvider {
    /**
     * @param {string} contentURL
     * @param {!Common.ResourceType.ResourceType} contentType
     * @param {string} content
     * @return {!StaticContentProvider}
     */
    static fromString(contentURL: string, contentType: Common.ResourceType.ResourceType, content: string): StaticContentProvider;
    /**
     * @param {string} contentURL
     * @param {!Common.ResourceType.ResourceType} contentType
     * @param {function():!Promise<!DeferredContent>} lazyContent
     */
    constructor(contentURL: string, contentType: Common.ResourceType.ResourceType, lazyContent: () => Promise<DeferredContent>);
    _contentURL: string;
    _contentType: Common.ResourceType.ResourceType;
    _lazyContent: () => Promise<DeferredContent>;
    /**
     * @override
     * @return {string}
     */
    contentURL(): string;
    /**
     * @override
     * @return {!Common.ResourceType.ResourceType}
     */
    contentType(): Common.ResourceType.ResourceType;
    /**
     * @override
     * @return {!Promise<boolean>}
     */
    contentEncoded(): Promise<boolean>;
    /**
     * @override
     * @return {!Promise<!DeferredContent>}
     */
    requestContent(): Promise<DeferredContent>;
    /**
     * @override
     * @param {string} query
     * @param {boolean} caseSensitive
     * @param {boolean} isRegex
     * @return {!Promise<!Array<!SearchMatch>>}
     */
    searchInContent(query: string, caseSensitive: boolean, isRegex: boolean): Promise<Array<SearchMatch>>;
}
import { ContentProvider } from "./ContentProvider.js";
import * as Common from "../common/common.js";
import { DeferredContent } from "./ContentProvider.js";
import { SearchMatch } from "./ContentProvider.js";
