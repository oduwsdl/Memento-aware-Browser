/**
 * @implements {ProtocolProxyApiWorkaround_StorageDispatcher}
 */
export class ServiceWorkerCacheModel extends SDKModel implements ProtocolProxyApiWorkaround_StorageDispatcher {
    /**
     * Invariant: This model can only be constructed on a ServiceWorker target.
     * @param {!Target} target
     */
    constructor(target: Target);
    /** @type {!Map<string, !Cache>} */
    _caches: Map<string, Cache>;
    _cacheAgent: ProtocolProxyApi.CacheStorageApi;
    _storageAgent: ProtocolProxyApi.StorageApi;
    _securityOriginManager: any;
    _originsUpdated: Set<any>;
    _throttler: Common.Throttler.Throttler;
    /** @type {boolean} */
    _enabled: boolean;
    /**
     * @return {!Protocol.UsesObjectNotation}
     */
    usesObjectNotation(): Protocol.UsesObjectNotation;
    enable(): void;
    /**
     * @param {string} origin
     */
    clearForOrigin(origin: string): void;
    refreshCacheNames(): void;
    /**
     * @param {!Cache} cache
     */
    deleteCache(cache: Cache): Promise<void>;
    /**
     * @param {!Cache} cache
     * @param {string} request
     * @return {!Promise<void>}
     */
    deleteCacheEntry(cache: Cache, request: string): Promise<void>;
    /**
     * @param {!Cache} cache
     * @param {number} skipCount
     * @param {number} pageSize
     * @param {string} pathFilter
     * @param {function(!Array.<!Protocol.CacheStorage.DataEntry>, number):void} callback
     */
    loadCacheData(cache: Cache, skipCount: number, pageSize: number, pathFilter: string, callback: (arg0: Array<Protocol.CacheStorage.DataEntry>, arg1: number) => void): void;
    /**
     * @param {!Cache} cache
     * @param {string} pathFilter
     * @param {function(!Array.<!Protocol.CacheStorage.DataEntry>, number):void} callback
     */
    loadAllCacheData(cache: Cache, pathFilter: string, callback: (arg0: Array<Protocol.CacheStorage.DataEntry>, arg1: number) => void): void;
    /**
     * @return {!Array.<!Cache>}
     */
    caches(): Array<Cache>;
    /**
     * @param {string} securityOrigin
     */
    _addOrigin(securityOrigin: string): void;
    /**
     * @param {string} securityOrigin
     */
    _removeOrigin(securityOrigin: string): void;
    /**
     * @param {string} securityOrigin
     * @return {boolean}
     */
    _isValidSecurityOrigin(securityOrigin: string): boolean;
    /**
     * @param {string} securityOrigin
     */
    _loadCacheNames(securityOrigin: string): Promise<void>;
    /**
     * @param {string} securityOrigin
     * @param {!Array<!Protocol.CacheStorage.Cache>} cachesJson
     */
    _updateCacheNames(securityOrigin: string, cachesJson: Array<Protocol.CacheStorage.Cache>): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _securityOriginAdded(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _securityOriginRemoved(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Cache} cache
     */
    _cacheAdded(cache: Cache): void;
    /**
     * @param {!Cache} cache
     */
    _cacheRemoved(cache: Cache): void;
    /**
     * @param {!Cache} cache
     * @param {number} skipCount
     * @param {number} pageSize
     * @param {string} pathFilter
     * @param {function(!Array<!Protocol.CacheStorage.DataEntry>, number):void} callback
     */
    _requestEntries(cache: Cache, skipCount: number, pageSize: number, pathFilter: string, callback: (arg0: Array<Protocol.CacheStorage.DataEntry>, arg1: number) => void): Promise<void>;
    /**
     * @param {!Cache} cache
     * @param {string} pathFilter
     * @param {function(!Array<!Protocol.CacheStorage.DataEntry>, number):void} callback
     */
    _requestAllEntries(cache: Cache, pathFilter: string, callback: (arg0: Array<Protocol.CacheStorage.DataEntry>, arg1: number) => void): Promise<void>;
    /**
     * @param {!Protocol.Storage.CacheStorageListUpdatedEvent} event
     * @override
     */
    cacheStorageListUpdated({ origin }: Protocol.Storage.CacheStorageListUpdatedEvent): void;
    /**
     * @param {!Protocol.Storage.CacheStorageContentUpdatedEvent} event
     * @override
     */
    cacheStorageContentUpdated({ origin, cacheName }: Protocol.Storage.CacheStorageContentUpdatedEvent): void;
    /**
     * @param {!Protocol.Storage.IndexedDBListUpdatedEvent} event
     * @override
     */
    indexedDBListUpdated(event: Protocol.Storage.IndexedDBListUpdatedEvent): void;
    /**
     * @param {!Protocol.Storage.IndexedDBContentUpdatedEvent} event
     * @override
     */
    indexedDBContentUpdated(event: Protocol.Storage.IndexedDBContentUpdatedEvent): void;
}
export type Events = symbol;
export namespace Events {
    export const CacheAdded: symbol;
    export const CacheRemoved: symbol;
    export const CacheStorageContentUpdated: symbol;
}
export class Cache {
    /**
     * @param {!ServiceWorkerCacheModel} model
     * @param {string} securityOrigin
     * @param {string} cacheName
     * @param {string} cacheId
     */
    constructor(model: ServiceWorkerCacheModel, securityOrigin: string, cacheName: string, cacheId: string);
    _model: ServiceWorkerCacheModel;
    securityOrigin: string;
    cacheName: string;
    cacheId: string;
    /**
     * @param {!Cache} cache
     * @return {boolean}
     */
    equals(cache: Cache): boolean;
    /**
     * @override
     * @return {string}
     */
    toString(): string;
    /**
     * @param {string} url
     * @param {!Array.<!NameValue>} requestHeaders
     * @return {!Promise<?Protocol.CacheStorage.CachedResponse>}
     */
    requestCachedResponse(url: string, requestHeaders: Array<NameValue>): Promise<Protocol.CacheStorage.CachedResponse | null>;
}
import { SDKModel } from "./SDKModel.js";
import * as Common from "../common/common.js";
import { Target } from "./SDKModel.js";
import { NameValue } from "./NetworkRequest.js";
