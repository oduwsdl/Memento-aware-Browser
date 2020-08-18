/** @interface */
export class LiveLocation {
    /**
     * @return {!Promise<void>}
     */
    update(): Promise<void>;
    /**
     * @return {!Promise<?Workspace.UISourceCode.UILocation>}
     */
    uiLocation(): Promise<Workspace.UISourceCode.UILocation | null>;
    dispose(): void;
    /**
     * @return {!Promise<boolean>}
     */
    isBlackboxed(): Promise<boolean>;
}
/**
 * @implements {LiveLocation}
 * @unrestricted
 */
export class LiveLocationWithPool implements LiveLocation {
    /**
     * @param {function(!LiveLocation):!Promise<void>} updateDelegate
     * @param {!LiveLocationPool} locationPool
     */
    constructor(updateDelegate: (arg0: LiveLocation) => Promise<void>, locationPool: LiveLocationPool);
    /** @type {?function(!LiveLocation):!Promise<void>} */
    _updateDelegate: ((arg0: LiveLocation) => Promise<void>) | null;
    _locationPool: LiveLocationPool;
    /** @type {?Promise<void>} */
    _updatePromise: Promise<void> | null;
    /**
     * @override
     */
    update(): Promise<void>;
    /**
     * @override
     * @return {!Promise<?Workspace.UISourceCode.UILocation>}
     */
    uiLocation(): Promise<Workspace.UISourceCode.UILocation | null>;
    /**
     * @override
     */
    dispose(): void;
    /**
     * @override
     * @return {!Promise<boolean>}
     */
    isBlackboxed(): Promise<boolean>;
}
/**
 * @unrestricted
 */
export class LiveLocationPool {
    _locations: Set<any>;
    /**
     * @param {!LiveLocation} location
     */
    _add(location: LiveLocation): void;
    /**
     * @param {!LiveLocation} location
     */
    _delete(location: LiveLocation): void;
    disposeAll(): void;
}
import * as Workspace from "../workspace/workspace.js";
