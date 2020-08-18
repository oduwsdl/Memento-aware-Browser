/**
 * @template {!FrameAssociated} T
 */
export class SourceMapManager<T extends {
    frameId: string;
}> extends Common.ObjectWrapper.ObjectWrapper {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _target: Target;
    /** @type {boolean} */
    _isEnabled: boolean;
    /** @type {!Map<!T, string>} */
    _relativeSourceURL: Map<T, string>;
    /** @type {!Map<!T, string>} */
    _relativeSourceMapURL: Map<T, string>;
    /** @type {!Map<!T, string>} */
    _resolvedSourceMapId: Map<T, string>;
    /** @type {!Map<string, !SourceMap>} */
    _sourceMapById: Map<string, SourceMap>;
    /** @type {!Platform.Multimap<string, !T>} */
    _sourceMapIdToLoadingClients: Platform.Multimap<string, T>;
    /** @type {!Platform.Multimap<string, !T>} */
    _sourceMapIdToClients: Platform.Multimap<string, T>;
    /**
     * @param {boolean} isEnabled
     */
    setEnabled(isEnabled: boolean): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _inspectedURLChanged(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!T} client
     * @return {?SourceMap}
     */
    sourceMapForClient(client: T): SourceMap | null;
    /**
     * @param {!SourceMap} sourceMap
     * @return {!Array<!T>}
     */
    clientsForSourceMap(sourceMap: SourceMap): T[];
    /**
     * @param {string} sourceURL
     * @param {string} sourceMapURL
     */
    _getSourceMapId(sourceURL: string, sourceMapURL: string): string;
    /**
     * @param {string} sourceURL
     * @param {string} sourceMapURL
     * @return {?{sourceURL: string, sourceMapURL: string, sourceMapId: string}}
     */
    _resolveRelativeURLs(sourceURL: string, sourceMapURL: string): {
        sourceURL: string;
        sourceMapURL: string;
        sourceMapId: string;
    } | null;
    /**
     * @param {!T} client
     * @param {string|undefined} relativeSourceURL
     * @param {string|undefined} relativeSourceMapURL
     */
    attachSourceMap(client: T, relativeSourceURL: string | undefined, relativeSourceMapURL: string | undefined): void;
    /**
     * @param {!T} client
     */
    detachSourceMap(client: T): void;
    _sourceMapLoadedForTest(): void;
    dispose(): void;
}
export namespace Events {
    export const SourceMapWillAttach: symbol;
    export const SourceMapFailedToAttach: symbol;
    export const SourceMapAttached: symbol;
    export const SourceMapDetached: symbol;
    export const SourceMapChanged: symbol;
}
import * as Common from "../common/common.js";
import { Target } from "./SDKModel.js";
import { SourceMap } from "./SourceMap.js";
import * as Platform from "../platform/platform.js";
