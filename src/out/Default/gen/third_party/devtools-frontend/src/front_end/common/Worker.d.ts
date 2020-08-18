/**
 * @unrestricted
 */
export class WorkerWrapper {
    /**
     * @param {string} appName
     */
    constructor(appName: string);
    /** @type {!Promise<!Worker>} */
    _workerPromise: Promise<Worker>;
    /**
     * @param {*} message
     */
    postMessage(message: any): void;
    dispose(): void;
    _disposed: boolean | undefined;
    terminate(): void;
    /**
     * @param {?function(!MessageEvent):void} listener
     */
    set onmessage(arg: ((arg0: MessageEvent) => void) | null);
    /**
     * @param {?function(!Event):void} listener
     */
    set onerror(arg: ((arg0: Event) => void) | null);
}
