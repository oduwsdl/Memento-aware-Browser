export type FinishCallback = (arg0?: Error | undefined) => void;
/** @typedef {function(!Error=):void} */
export let FinishCallback: any;
/**
 * @unrestricted
 */
export class Throttler {
    /**
     * @param {number} timeout
     */
    constructor(timeout: number);
    _timeout: number;
    _isRunningProcess: boolean;
    /** @type {boolean} */
    _asSoonAsPossible: boolean;
    /** @type {?function():(!Promise<void>)} */
    _process: (() => (Promise<void>)) | null;
    _lastCompleteTime: number;
    _schedulePromise: Promise<any>;
    _scheduleResolve: (value?: any) => void;
    _processCompleted(): void;
    _processCompletedForTests(): void;
    _onTimeout(): void;
    /**
     * @param {function():(!Promise<?>)} process
     * @param {boolean=} asSoonAsPossible
     * @return {!Promise<void>}
     */
    schedule(process: () => (Promise<unknown>), asSoonAsPossible?: boolean | undefined): Promise<void>;
    /**
     * @param {boolean} forceTimerUpdate
     */
    _innerSchedule(forceTimerUpdate: boolean): void;
    _processTimeout: number | undefined;
    /**
     *  @param {number} timeoutId
     */
    _clearTimeout(timeoutId: number): void;
    /**
     * @param {function():void} operation
     * @param {number} timeout
     * @return {number}
     */
    _setTimeout(operation: () => void, timeout: number): number;
    /**
     * @return {number}
     */
    _getTime(): number;
}
