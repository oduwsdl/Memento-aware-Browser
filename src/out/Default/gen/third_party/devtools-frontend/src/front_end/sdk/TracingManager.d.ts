/**
 * @unrestricted
 */
export class TracingManager extends SDKModel {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _tracingAgent: any;
    /** @type {?TracingManagerClient} */
    _activeClient: TracingManagerClient | null;
    /** @type {?number} */
    _eventBufferSize: number | null;
    _eventsRetrieved: number;
    /**
     * @param {number=} usage
     * @param {number=} eventCount
     * @param {number=} percentFull
     */
    _bufferUsage(usage?: number | undefined, eventCount?: number | undefined, percentFull?: number | undefined): void;
    /**
     * @param {!Array.<!EventPayload>} events
     */
    _eventsCollected(events: Array<EventPayload>): void;
    _tracingComplete(): void;
    _finishing: boolean | undefined;
    /**
     * @param {!TracingManagerClient} client
     * @param {string} categoryFilter
     * @param {string} options
     * @return {!Promise<!Object>}
     */
    start(client: TracingManagerClient, categoryFilter: string, options: string): Promise<Object>;
    stop(): void;
}
/**
 * @interface
 */
export class TracingManagerClient {
    /**
     * @param {!Array.<!EventPayload>} events
     */
    traceEventsCollected(events: Array<EventPayload>): void;
    tracingComplete(): void;
    /**
     * @param {number} usage
     */
    tracingBufferUsage(usage: number): void;
    /**
     * @param {number} progress
     */
    eventsRetrievalProgress(progress: number): void;
}
export type EventPayload = {
    cat: (string | undefined);
    pid: number;
    tid: number;
    ts: number;
    ph: string;
    name: string;
    args: {
        sort_index: number;
        name: string;
        snapshot: ObjectSnapshot;
    };
    dur: number;
    id: string;
    id2: ({
        global: (string | undefined);
        local: (string | undefined);
    } | undefined);
    scope: string;
    bind_id: string;
    s: string;
};
/** @typedef {!{
        cat: (string|undefined),
        pid: number,
        tid: number,
        ts: number,
        ph: string,
        name: string,
        args: !{
          sort_index: number,
          name: string,
          snapshot: ObjectSnapshot,
        },
        dur: number,
        id: string,
        id2: (!{global: (string|undefined), local: (string|undefined)}|undefined),
        scope: string,
        bind_id: string,
        s: string
    }}
 */
export let EventPayload: any;
import { SDKModel } from "./SDKModel.js";
import { Target } from "./SDKModel.js";
import { ObjectSnapshot } from "./TracingModel.js";
