/**
 * @implements {TextUtils.ContentProvider.ContentProvider}
 * @unrestricted
 */
export class CompilerSourceMappingContentProvider implements TextUtils.ContentProvider.ContentProvider {
    /**
     * @param {string} sourceURL
     * @param {!Common.ResourceType.ResourceType} contentType
     * @param {!Protocol.Page.FrameId} frameId
     */
    constructor(sourceURL: string, contentType: Common.ResourceType.ResourceType, frameId: Protocol.Page.FrameId);
    _sourceURL: string;
    _contentType: Common.ResourceType.ResourceType;
    _frameId: string;
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
     * @return {!Promise<!TextUtils.ContentProvider.DeferredContent>}
     */
    requestContent(): Promise<TextUtils.ContentProvider.DeferredContent>;
    /**
     * @override
     * @param {string} query
     * @param {boolean} caseSensitive
     * @param {boolean} isRegex
     * @return {!Promise<!Array<!TextUtils.ContentProvider.SearchMatch>>}
     */
    searchInContent(query: string, caseSensitive: boolean, isRegex: boolean): Promise<Array<TextUtils.ContentProvider.SearchMatch>>;
}
import * as TextUtils from "../text_utils/text_utils.js";
import * as Common from "../common/common.js";
