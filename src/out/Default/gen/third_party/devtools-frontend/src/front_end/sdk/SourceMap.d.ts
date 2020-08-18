/**
 * @interface
 */
export class SourceMap {
    /**
     * @return {string}
     */
    compiledURL(): string;
    /**
     * @return {string}
     */
    url(): string;
    /**
     * @return {!Array<string>}
     */
    sourceURLs(): Array<string>;
    /**
     * @param {string} sourceURL
     * @param {!Common.ResourceType.ResourceType} contentType
     * @return {!TextUtils.ContentProvider.ContentProvider}
     */
    sourceContentProvider(sourceURL: string, contentType: Common.ResourceType.ResourceType): TextUtils.ContentProvider.ContentProvider;
    /**
     * @param {string} sourceURL
     * @return {?string}
     */
    embeddedContentByURL(sourceURL: string): string | null;
    /**
     * @param {number} lineNumber in compiled resource
     * @param {number} columnNumber in compiled resource
     * @return {?SourceMapEntry}
     */
    findEntry(lineNumber: number, columnNumber: number): SourceMapEntry | null;
    /**
     * @param {string} sourceURL
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {?SourceMapEntry}
     */
    sourceLineMapping(sourceURL: string, lineNumber: number, columnNumber: number): SourceMapEntry | null;
    /**
     * @return {!Array<!SourceMapEntry>}
     */
    mappings(): Array<SourceMapEntry>;
    dispose(): void;
}
export class SourceMapEntry {
    /**
     * @param {!SourceMapEntry} entry1
     * @param {!SourceMapEntry} entry2
     * @return {number}
     */
    static compare(entry1: SourceMapEntry, entry2: SourceMapEntry): number;
    /**
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @param {string=} sourceURL
     * @param {number=} sourceLineNumber
     * @param {number=} sourceColumnNumber
     * @param {string=} name
     */
    constructor(lineNumber: number, columnNumber: number, sourceURL?: string | undefined, sourceLineNumber?: number | undefined, sourceColumnNumber?: number | undefined, name?: string | undefined);
    lineNumber: number;
    columnNumber: number;
    sourceURL: string | undefined;
    sourceLineNumber: number | undefined;
    sourceColumnNumber: number | undefined;
    name: string | undefined;
}
export class EditResult {
    /**
     * @param {!SourceMap} map
     * @param {!Array<!TextUtils.TextRange.SourceEdit>} compiledEdits
     * @param {!Map<string, string>} newSources
     */
    constructor(map: SourceMap, compiledEdits: Array<TextUtils.TextRange.SourceEdit>, newSources: Map<string, string>);
    map: SourceMap;
    compiledEdits: TextUtils.TextRange.SourceEdit[];
    newSources: Map<string, string>;
}
/**
 * @implements {SourceMap}
 * @unrestricted
 */
export class TextSourceMap implements SourceMap {
    /**
     * @param {string} sourceMapURL
     * @param {string} compiledURL
     * @param {string} frameId
     * @return {!Promise<!TextSourceMap>}
     * @throws {!Error}
     * @this {TextSourceMap}
     */
    static load(sourceMapURL: string, compiledURL: string, frameId: string): Promise<TextSourceMap>;
    /**
     * Implements Source Map V3 model. See https://github.com/google/closure-compiler/wiki/Source-Maps
     * for format description.
     * @param {string} compiledURL
     * @param {string} sourceMappingURL
     * @param {!SourceMapV3} payload
     * @param {string} frameId
     */
    constructor(compiledURL: string, sourceMappingURL: string, payload: SourceMapV3, frameId: string);
    _frameId: string;
    _json: SourceMapV3;
    _compiledURL: string;
    _sourceMappingURL: string;
    _baseURL: string;
    /** @type {?Array<!SourceMapEntry>} */
    _mappings: Array<SourceMapEntry> | null;
    /** @type {!Map<string, !TextSourceMap.SourceInfo>} */
    _sourceInfos: Map<string, {
        content: string | null;
        reverseMappings: SourceMapEntry[] | null;
    }>;
    /**
     * @override
     * @return {string}
     */
    compiledURL(): string;
    /**
     * @override
     * @return {string}
     */
    url(): string;
    /**
     * @override
     * @return {!Array.<string>}
     */
    sourceURLs(): Array<string>;
    /**
     * @override
     * @param {string} sourceURL
     * @param {!Common.ResourceType.ResourceType} contentType
     * @return {!TextUtils.ContentProvider.ContentProvider}
     */
    sourceContentProvider(sourceURL: string, contentType: Common.ResourceType.ResourceType): TextUtils.ContentProvider.ContentProvider;
    /**
     * @override
     * @param {string} sourceURL
     * @return {?string}
     */
    embeddedContentByURL(sourceURL: string): string | null;
    /**
     * @override
     * @param {number} lineNumber in compiled resource
     * @param {number} columnNumber in compiled resource
     * @return {?SourceMapEntry}
     */
    findEntry(lineNumber: number, columnNumber: number): SourceMapEntry | null;
    /**
     * @override
     * @param {string} sourceURL
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {?SourceMapEntry}
     */
    sourceLineMapping(sourceURL: string, lineNumber: number, columnNumber: number): SourceMapEntry | null;
    /**
     * @param {string} sourceURL
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {!Array<!SourceMapEntry>}
     */
    findReverseEntries(sourceURL: string, lineNumber: number, columnNumber: number): Array<SourceMapEntry>;
    /**
     * @override
     * @return {!Array<!SourceMapEntry>}
     */
    mappings(): Array<SourceMapEntry>;
    /**
     * @param {string} sourceURL
     * @return {!Array.<!SourceMapEntry>}
     */
    _reversedMappings(sourceURL: string): Array<SourceMapEntry>;
    /**
     * @param {function(!SourceMapV3, number, number)} callback
     */
    _eachSection(callback: (arg0: SourceMapV3, arg1: number, arg2: number) => any): void;
    /**
     * @param {!SourceMapV3} sourceMap
     */
    _parseSources(sourceMap: SourceMapV3): void;
    /**
     * @param {!SourceMapV3} map
     * @param {number} lineNumber
     * @param {number} columnNumber
     */
    _parseMap(map: SourceMapV3, lineNumber: number, columnNumber: number): void;
    /**
     * @param {string} char
     * @return {boolean}
     */
    _isSeparator(char: string): boolean;
    /**
     * @param {!TextSourceMap.StringCharIterator} stringCharIterator
     * @return {number}
     */
    _decodeVLQ(stringCharIterator: {
        _string: string;
        _position: number;
        /**
         * @return {string}
         */
        next(): string;
        /**
         * @return {string}
         */
        peek(): string;
        /**
         * @return {boolean}
         */
        hasNext(): boolean;
    }): number;
    /**
     * @param {string} url
     * @param {!TextUtils.TextRange.TextRange} textRange
     * @return {?TextUtils.TextRange.TextRange}
     */
    reverseMapTextRange(url: string, textRange: TextUtils.TextRange.TextRange): TextUtils.TextRange.TextRange | null;
    /**
     * @override
     */
    dispose(): void;
}
export namespace TextSourceMap {
    export const _VLQ_BASE_SHIFT: number;
    export const _VLQ_BASE_MASK: number;
    export const _VLQ_CONTINUATION_MASK: number;
    export { StringCharIterator };
    export { SourceInfo };
    export const _sourcesListSymbol: symbol;
}
/**
 * @implements {SourceMap}
 * @unrestricted
 */
export class WasmSourceMap implements SourceMap {
    /**
     * @private
     */
    private static _loadBindings;
    /**
     * @private
     */
    private static _loadBindingsOnce;
    /**
     *
     * @param {!Script} script
     * @param {string} wasmUrl
     * @returns {!Promise<!WasmSourceMap>}
     */
    static load(script: Script, wasmUrl: string): Promise<WasmSourceMap>;
    /**
     * Implements SourceMap interface for DWARF information in Wasm.
     * @param {string} wasmUrl
     * @param {!WasmResolver} resolver
     * @param {!Protocol.Page.FrameId} frameId
     */
    constructor(wasmUrl: string, resolver: WasmResolver, frameId: Protocol.Page.FrameId);
    _wasmUrl: string;
    _resolver: WasmResolver;
    _frameId: string;
    /**
     * @override
     * @return {string}
     */
    compiledURL(): string;
    /**
     * @override
     * @return {string}
     */
    url(): string;
    /**
     * @override
     * @return {!Array.<string>}
     */
    sourceURLs(): Array<string>;
    /**
     * @override
     * @param {string} sourceURL
     * @param {!Common.ResourceType.ResourceType} contentType
     * @return {!TextUtils.ContentProvider.ContentProvider}
     */
    sourceContentProvider(sourceURL: string, contentType: Common.ResourceType.ResourceType): TextUtils.ContentProvider.ContentProvider;
    /**
     * @override
     * @param {string} sourceURL
     * @return {?string}
     */
    embeddedContentByURL(sourceURL: string): string | null;
    /**
     * @override
     * @param {number} lineNumber in compiled resource
     * @param {number} columnNumber in compiled resource
     * @return {?SourceMapEntry}
     */
    findEntry(lineNumber: number, columnNumber: number): SourceMapEntry | null;
    /**
     * @override
     * @param {string} sourceURL
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {?SourceMapEntry}
     */
    sourceLineMapping(sourceURL: string, lineNumber: number, columnNumber: number): SourceMapEntry | null;
    /**
     * @override
     * @return {!Array<!SourceMapEntry>}
     */
    mappings(): Array<SourceMapEntry>;
    /**
     * @override
     */
    dispose(): void;
}
export namespace WasmSourceMap {
    export const FAKE_URL: string;
}
import * as Common from "../common/common.js";
import * as TextUtils from "../text_utils/text_utils.js";
/**
 * @unrestricted
 */
declare class SourceMapV3 {
    /** @type {number} */ version: number;
    /** @type {string|undefined} */ file: string | undefined;
    /** @type {!Array.<string>} */ sources: Array<string>;
    /** @type {!Array.<!SourceMapV3.Section>|undefined} */ sections: Array<{
        /** @type {!SourceMapV3} */ map: SourceMapV3;
        /** @type {!SourceMapV3.Offset} */ offset: {
            /** @type {number} */ line: number;
            /** @type {number} */ column: number;
        };
    }> | undefined;
    /** @type {string} */ mappings: string;
    /** @type {string|undefined} */ sourceRoot: string | undefined;
    /** @type {!Array.<string>|undefined} */ names: Array<string> | undefined;
}
declare namespace SourceMapV3 {
    export { Section };
    export { Offset };
}
declare class StringCharIterator {
    /**
     * @param {string} string
     */
    constructor(string: string);
    _string: string;
    _position: number;
    /**
     * @return {string}
     */
    next(): string;
    /**
     * @return {string}
     */
    peek(): string;
    /**
     * @return {boolean}
     */
    hasNext(): boolean;
}
declare class SourceInfo {
    /**
     * @param {?string} content
     * @param {?Array<!SourceMapEntry>} reverseMappings
     */
    constructor(content: string | null, reverseMappings: Array<SourceMapEntry> | null);
    content: string | null;
    reverseMappings: SourceMapEntry[] | null;
}
import { Resolver as WasmResolver } from "./wasm_source_map/pkg/wasm_source_map.js";
import { Script } from "./Script.js";
declare class Section {
    /** @type {!SourceMapV3} */ map: SourceMapV3;
    /** @type {!SourceMapV3.Offset} */ offset: {
        /** @type {number} */ line: number;
        /** @type {number} */ column: number;
    };
}
declare class Offset {
    /** @type {number} */ line: number;
    /** @type {number} */ column: number;
}
export {};
