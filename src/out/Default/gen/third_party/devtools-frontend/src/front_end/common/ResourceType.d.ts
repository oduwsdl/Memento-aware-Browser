/**
 * @unrestricted
 */
export class ResourceType {
    /**
     * @param {?string} mimeType
     * @return {!ResourceType}
     */
    static fromMimeType(mimeType: string | null): ResourceType;
    /**
     * @param {string} url
     * @return {?ResourceType}
     */
    static fromURL(url: string): ResourceType | null;
    /**
     * @param {string} name
     * @return {?ResourceType}
     */
    static fromName(name: string): ResourceType | null;
    /**
     * @param {string} url
     * @return {string|undefined}
     */
    static mimeFromURL(url: string): string | undefined;
    /**
     * @param {string} ext
     * @return {string|undefined}
     */
    static mimeFromExtension(ext: string): string | undefined;
    /**
     * @param {string} name
     * @param {string} title
     * @param {!ResourceCategory} category
     * @param {boolean} isTextType
     */
    constructor(name: string, title: string, category: ResourceCategory, isTextType: boolean);
    _name: string;
    _title: string;
    _category: ResourceCategory;
    _isTextType: boolean;
    /**
     * @return {string}
     */
    name(): string;
    /**
     * @return {string}
     */
    title(): string;
    /**
     * @return {!ResourceCategory}
     */
    category(): ResourceCategory;
    /**
     * @return {boolean}
     */
    isTextType(): boolean;
    /**
     * @return {boolean}
     */
    isScript(): boolean;
    /**
     * @return {boolean}
     */
    hasScripts(): boolean;
    /**
     * @return {boolean}
     */
    isStyleSheet(): boolean;
    /**
     * @return {boolean}
     */
    isDocument(): boolean;
    /**
     * @return {boolean}
     */
    isDocumentOrScriptOrStyleSheet(): boolean;
    /**
     * @return {boolean}
     */
    isFromSourceMap(): boolean;
    /**
     * @override
     * @return {string}
     */
    toString(): string;
    /**
     * @return {string}
     */
    canonicalMimeType(): string;
}
/**
 * @unrestricted
 */
export class ResourceCategory {
    /**
     * @param {string} title
     * @param {string} shortTitle
     */
    constructor(title: string, shortTitle: string);
    title: string;
    shortTitle: string;
}
export type resourceCategories = ResourceCategory;
export namespace resourceCategories {
    export const XHR: ResourceCategory;
    export const Script: ResourceCategory;
    export const Stylesheet: ResourceCategory;
    export const Image: ResourceCategory;
    export const Media: ResourceCategory;
    export const Font: ResourceCategory;
    export const Document: ResourceCategory;
    export const WebSocket: ResourceCategory;
    export const Manifest: ResourceCategory;
    export const Other: ResourceCategory;
}
/**
 * Keep these in sync with WebCore::InspectorPageAgent::resourceTypeJson
 */
export type resourceTypes = ResourceType;
export namespace resourceTypes {
    const Document_1: ResourceType;
    export { Document_1 as Document };
    const Stylesheet_1: ResourceType;
    export { Stylesheet_1 as Stylesheet };
    const Image_1: ResourceType;
    export { Image_1 as Image };
    const Media_1: ResourceType;
    export { Media_1 as Media };
    const Font_1: ResourceType;
    export { Font_1 as Font };
    const Script_1: ResourceType;
    export { Script_1 as Script };
    export const TextTrack: ResourceType;
    const XHR_1: ResourceType;
    export { XHR_1 as XHR };
    export const Fetch: ResourceType;
    export const EventSource: ResourceType;
    const WebSocket_1: ResourceType;
    export { WebSocket_1 as WebSocket };
    const Manifest_1: ResourceType;
    export { Manifest_1 as Manifest };
    export const SignedExchange: ResourceType;
    export const Ping: ResourceType;
    export const CSPViolationReport: ResourceType;
    const Other_1: ResourceType;
    export { Other_1 as Other };
    export const SourceMapScript: ResourceType;
    export const SourceMapStyleSheet: ResourceType;
}
export const _mimeTypeByName: Map<string, string>;
export const _resourceTypeByExtension: Map<string, ResourceType>;
export const _mimeTypeByExtension: Map<string, string>;
