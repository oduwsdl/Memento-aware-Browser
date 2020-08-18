/**
 * @unrestricted
 */
export class ParsedURL {
    /**
     * @param {string} string
     * @return {?ParsedURL}
     */
    static fromString(string: string): ParsedURL | null;
    /**
     * @param {string} fileSystemPath
     * @return {string}
     */
    static platformPathToURL(fileSystemPath: string): string;
    /**
     * @param {string} fileURL
     * @param {boolean=} isWindows
     * @return {string}
     */
    static urlToPlatformPath(fileURL: string, isWindows?: boolean | undefined): string;
    /**
     * @param {string} url
     * @return {string}
     */
    static urlWithoutHash(url: string): string;
    /**
     * @return {!RegExp}
     */
    static _urlRegex(): RegExp;
    /**
     * @param {string} url
     * @return {string}
     */
    static extractPath(url: string): string;
    /**
     * @param {string} url
     * @return {string}
     */
    static extractOrigin(url: string): string;
    /**
     * @param {string} url
     * @return {string}
     */
    static extractExtension(url: string): string;
    /**
     * @param {string} url
     * @return {string}
     */
    static extractName(url: string): string;
    /**
     * @param {string} baseURL
     * @param {string} href
     * @return {?string}
     */
    static completeURL(baseURL: string, href: string): string | null;
    /**
     * @param {string} string
     * @return {!{url: string, lineNumber: (number|undefined), columnNumber: (number|undefined)}}
     */
    static splitLineAndColumn(string: string): {
        url: string;
        lineNumber: (number | undefined);
        columnNumber: (number | undefined);
    };
    /**
     * @param {string} url
     * @return {string}
     */
    static removeWasmFunctionInfoFromURL(url: string): string;
    /**
     * @param {string} url
     * @return {boolean}
     */
    static isRelativeURL(url: string): boolean;
    /**
     * @param {string} url
     */
    constructor(url: string);
    isValid: boolean;
    url: string;
    scheme: string;
    user: string;
    host: string;
    port: string;
    path: string;
    queryParams: string;
    fragment: string;
    folderPathComponents: string;
    lastPathComponent: string;
    _blobInnerScheme: string;
    get displayName(): string;
    _displayName: string | undefined;
    /**
     * @return {string}
     */
    dataURLDisplayName(): string;
    _dataURLDisplayName: string | undefined;
    /**
     * @return {boolean}
     */
    isAboutBlank(): boolean;
    /**
     * @return {boolean}
     */
    isDataURL(): boolean;
    /**
     * @return {boolean}
     */
    isBlobURL(): boolean;
    /**
     * @return {string}
     */
    lastPathComponentWithFragment(): string;
    /**
     * @return {string}
     */
    domain(): string;
    /**
     * @return {string}
     */
    securityOrigin(): string;
    /**
     * @return {string}
     */
    urlWithoutScheme(): string;
}
export namespace ParsedURL {
    export const _urlRegexInstance: RegExp | null;
}
