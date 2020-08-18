export class ServiceWorkerManager extends SDKModel {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _lastAnonymousTargetId: number;
    _agent: ProtocolProxyApi.ServiceWorkerApi;
    /** @type {!Map.<string, !ServiceWorkerRegistration>} */
    _registrations: Map<string, ServiceWorkerRegistration>;
    /** @type {boolean} */
    _enabled: boolean;
    /** @type {!Common.Settings.Setting<boolean>} */
    _forceUpdateSetting: Common.Settings.Setting<boolean>;
    enable(): Promise<void>;
    disable(): Promise<void>;
    /**
     * @return {!Map.<string, !ServiceWorkerRegistration>}
     */
    registrations(): Map<string, ServiceWorkerRegistration>;
    /**
     * @param {!Array<string>} urls
     * @return {boolean}
     */
    hasRegistrationForURLs(urls: Array<string>): boolean;
    /**
     * @param {string} versionId
     * @return {?ServiceWorkerVersion}
     */
    findVersion(versionId: string): ServiceWorkerVersion | null;
    /**
     * @param {string} registrationId
     */
    deleteRegistration(registrationId: string): void;
    /**
     * @param {string} registrationId
     */
    updateRegistration(registrationId: string): Promise<void>;
    /**
     * @param {string} registrationId
     * @param {string} data
     */
    deliverPushMessage(registrationId: string, data: string): Promise<void>;
    /**
     * @param {string} registrationId
     * @param {string} tag
     * @param {boolean} lastChance
     */
    dispatchSyncEvent(registrationId: string, tag: string, lastChance: boolean): Promise<void>;
    /**
     * @param {string} registrationId
     * @param {string} tag
     */
    dispatchPeriodicSyncEvent(registrationId: string, tag: string): Promise<void>;
    /**
     * @param {string} scopeURL
     */
    _unregister(scopeURL: string): Promise<void>;
    /**
     * @param {string} scopeURL
     */
    startWorker(scopeURL: string): Promise<void>;
    /**
     * @param {string} scopeURL
     */
    skipWaiting(scopeURL: string): Promise<void>;
    /**
     * @param {string} versionId
     */
    stopWorker(versionId: string): Promise<void>;
    /**
     * @param {string} versionId
     */
    inspectWorker(versionId: string): Promise<void>;
    /**
     * @param {!Array.<!Protocol.ServiceWorker.ServiceWorkerRegistration>} registrations
     */
    _workerRegistrationUpdated(registrations: Array<Protocol.ServiceWorker.ServiceWorkerRegistration>): void;
    /**
     * @param {!Array.<!Protocol.ServiceWorker.ServiceWorkerVersion>} versions
     */
    _workerVersionUpdated(versions: Array<Protocol.ServiceWorker.ServiceWorkerVersion>): void;
    /**
     * @param {!Protocol.ServiceWorker.ServiceWorkerErrorMessage} payload
     */
    _workerErrorReported(payload: Protocol.ServiceWorker.ServiceWorkerErrorMessage): void;
    /**
     * @return {!Common.Settings.Setting<boolean>}
     */
    forceUpdateOnReloadSetting(): Common.Settings.Setting<boolean>;
    _forceUpdateSettingChanged(): void;
}
export type Events = symbol;
export namespace Events {
    export const RegistrationUpdated: symbol;
    export const RegistrationErrorAdded: symbol;
    export const RegistrationDeleted: symbol;
}
export class ServiceWorkerVersion {
    /**
     * @param {!ServiceWorkerRegistration} registration
     * @param {!Protocol.ServiceWorker.ServiceWorkerVersion} payload
     */
    constructor(registration: ServiceWorkerRegistration, payload: Protocol.ServiceWorker.ServiceWorkerVersion);
    /** @type {string} */ id: string;
    /** @type {string} */ scriptURL: string;
    /** @type {!Common.ParsedURL.ParsedURL} */ parsedURL: Common.ParsedURL.ParsedURL;
    /** @type {string} */ securityOrigin: string;
    /** @type {!Protocol.ServiceWorker.ServiceWorkerVersionRunningStatus} */ runningStatus: Protocol.ServiceWorker.ServiceWorkerVersionRunningStatus;
    /** @type {!Protocol.ServiceWorker.ServiceWorkerVersionStatus} */ status: Protocol.ServiceWorker.ServiceWorkerVersionStatus;
    /** @type {number|undefined} */ scriptLastModified: number | undefined;
    /** @type {number|undefined} */ scriptResponseTime: number | undefined;
    /** @type {!Array<!Protocol.Target.TargetID>} */ controlledClients: Array<Protocol.Target.TargetID>;
    /** @type {?Protocol.Target.TargetID} */ targetId: Protocol.Target.TargetID | null;
    registration: ServiceWorkerRegistration;
    /**
     * @param {!Protocol.ServiceWorker.ServiceWorkerVersion} payload
     */
    _update(payload: Protocol.ServiceWorker.ServiceWorkerVersion): void;
    /**
     * @return {boolean}
     */
    isStartable(): boolean;
    /**
     * @return {boolean}
     */
    isStoppedAndRedundant(): boolean;
    /**
     * @return {boolean}
     */
    isStopped(): boolean;
    /**
     * @return {boolean}
     */
    isStarting(): boolean;
    /**
     * @return {boolean}
     */
    isRunning(): boolean;
    /**
     * @return {boolean}
     */
    isStopping(): boolean;
    /**
     * @return {boolean}
     */
    isNew(): boolean;
    /**
     * @return {boolean}
     */
    isInstalling(): boolean;
    /**
     * @return {boolean}
     */
    isInstalled(): boolean;
    /**
     * @return {boolean}
     */
    isActivating(): boolean;
    /**
     * @return {boolean}
     */
    isActivated(): boolean;
    /**
     * @return {boolean}
     */
    isRedundant(): boolean;
    /**
     * @return {string}
     */
    mode(): string;
}
export namespace ServiceWorkerVersion {
    export const RunningStatus: {
        [x: string]: string;
    };
    export const Status: {
        [x: string]: string;
    };
    export namespace Modes {
        export const Installing: string;
        export const Waiting: string;
        export const Active: string;
        export const Redundant: string;
    }
    export type Modes = string;
}
export class ServiceWorkerRegistration {
    /**
     * @param {!Protocol.ServiceWorker.ServiceWorkerRegistration} payload
     */
    constructor(payload: Protocol.ServiceWorker.ServiceWorkerRegistration);
    /** @type {symbol} */ _fingerprint: symbol;
    /** @type {string} */ id: string;
    /** @type {string} */ scopeURL: string;
    /** @type {string} */ securityOrigin: string;
    /** @type {boolean} */ isDeleted: boolean;
    /** @type {!Map.<string, !ServiceWorkerVersion>} */
    versions: Map<string, ServiceWorkerVersion>;
    _deleting: boolean;
    /** @type {!Array<!Protocol.ServiceWorker.ServiceWorkerErrorMessage>} */
    errors: Array<Protocol.ServiceWorker.ServiceWorkerErrorMessage>;
    /**
     * @param {!Protocol.ServiceWorker.ServiceWorkerRegistration} payload
     */
    _update(payload: Protocol.ServiceWorker.ServiceWorkerRegistration): void;
    /**
     * @return {symbol}
     */
    fingerprint(): symbol;
    /**
     * @return {!Map<string, !ServiceWorkerVersion>}
     */
    versionsByMode(): Map<string, ServiceWorkerVersion>;
    /**
     * @param {!Protocol.ServiceWorker.ServiceWorkerVersion} payload
     * @return {!ServiceWorkerVersion}
     */
    _updateVersion(payload: Protocol.ServiceWorker.ServiceWorkerVersion): ServiceWorkerVersion;
    /**
     * @return {boolean}
     */
    _isRedundant(): boolean;
    /**
     * @return {boolean}
     */
    _shouldBeRemoved(): boolean;
    /**
     * @return {boolean}
     */
    canBeRemoved(): boolean;
    clearErrors(): void;
}
import { SDKModel } from "./SDKModel.js";
import * as Common from "../common/common.js";
import { Target } from "./SDKModel.js";
