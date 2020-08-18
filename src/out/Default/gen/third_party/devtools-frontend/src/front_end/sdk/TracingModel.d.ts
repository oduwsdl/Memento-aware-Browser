export class TracingModel {
    /**
     * @param {string} phase
     * @return {boolean}
     */
    static isNestableAsyncPhase(phase: string): boolean;
    /**
     * @param {string} phase
     * @return {boolean}
     */
    static isAsyncBeginPhase(phase: string): boolean;
    /**
     * @param {string} phase
     * @return {boolean}
     */
    static isAsyncPhase(phase: string): boolean;
    /**
     * @param {string} phase
     * @return {boolean}
     */
    static isFlowPhase(phase: string): boolean;
    /**
     * @param {!Event} event
     * @return {boolean}
     */
    static isTopLevelEvent(event: Event): boolean;
    /**
     * @param {!EventPayload} payload
     * @return {string|undefined}
     */
    static _extractId(payload: EventPayload): string | undefined;
    /**
     * @param {!TracingModel} tracingModel
     * @return {?Thread}
     *
     * TODO: Move this to a better place. This is here just for convenience o
     * re-use between modules. This really belongs to a higher level, since it
     * is specific to chrome's usage of tracing.
     */
    static browserMainThread(tracingModel: TracingModel): Thread | null;
    /**
     * @param {!BackingStorage} backingStorage
     */
    constructor(backingStorage: BackingStorage);
    _backingStorage: BackingStorage;
    _firstWritePending: boolean;
    /** @type {!Map<(number|string), !Process>} */
    _processById: Map<(number | string), Process>;
    _processByName: Map<any, any>;
    _minimumRecordTime: number;
    /** @type {number} */
    _maximumRecordTime: number;
    /** @type {!Array<!Event>} */
    _devToolsMetadataEvents: Array<Event>;
    /** @type {!Array<!AsyncEvent>} */
    _asyncEvents: Array<AsyncEvent>;
    /** @type {!Map<string, !AsyncEvent>} */
    _openAsyncEvents: Map<string, AsyncEvent>;
    /** @type {!Map<string, !Array<!AsyncEvent>>} */
    _openNestableAsyncEvents: Map<string, Array<AsyncEvent>>;
    /** @type {!Map<string, !ProfileEventsGroup>} */
    _profileGroups: Map<string, ProfileEventsGroup>;
    /** @type {!Map<string, !Set<string>>} */
    _parsedCategories: Map<string, Set<string>>;
    /**
     * @return {!Array<!Event>}
     */
    devToolsMetadataEvents(): Array<Event>;
    /**
     * @param {!Array<!EventPayload>} events
     */
    addEvents(events: Array<EventPayload>): void;
    tracingComplete(): void;
    dispose(): void;
    /**
     * @param {number} offset
     */
    adjustTime(offset: number): void;
    /**
     * @param {!EventPayload} payload
     */
    _addEvent(payload: EventPayload): void;
    /**
     * @param {!Event} event
     */
    _addSampleEvent(event: Event): void;
    /**
     * @param {!Event} event
     * @return {?ProfileEventsGroup}
     */
    profileGroup(event: Event): ProfileEventsGroup | null;
    /**
     * @return {number}
     */
    minimumRecordTime(): number;
    /**
     * @return {number}
     */
    maximumRecordTime(): number;
    /**
     * @return {!Array<!Process>}
     */
    sortedProcesses(): Array<Process>;
    /**
     * @param {string} name
     * @return {?Process}
     */
    processByName(name: string): Process | null;
    /**
     * @param {number} pid
     * @return {?Process}
     */
    processById(pid: number): Process | null;
    /**
     * @param {string} processName
     * @param {string} threadName
     * @return {?Thread}
     */
    threadByName(processName: string, threadName: string): Thread | null;
    /**
     * @param {string} processName
     * @param {string} threadName
     * @param {string} eventName
     * @return {!Array<!Event>}
     */
    extractEventsFromThreadByName(processName: string, threadName: string, eventName: string): Array<Event>;
    _processPendingAsyncEvents(): void;
    _closeOpenAsyncEvents(): void;
    /**
     * @param {!Event} event
     */
    _addNestableAsyncEvent(event: Event): void;
    /**
     * @param {!Event} event
     */
    _addAsyncEvent(event: Event): void;
    /**
     * @return {!BackingStorage}
     */
    backingStorage(): BackingStorage;
    /**
     * @param {string} str
     * @return {!Set<string>}
     */
    _parsedCategoriesForString(str: string): Set<string>;
}
export type Phase = string;
export namespace Phase {
    export const Begin: string;
    export const End: string;
    export const Complete: string;
    export const Instant: string;
    export const AsyncBegin: string;
    export const AsyncStepInto: string;
    export const AsyncStepPast: string;
    export const AsyncEnd: string;
    export const NestableAsyncBegin: string;
    export const NestableAsyncEnd: string;
    export const NestableAsyncInstant: string;
    export const FlowBegin: string;
    export const FlowStep: string;
    export const FlowEnd: string;
    export const Metadata: string;
    export const Counter: string;
    export const Sample: string;
    export const CreateObject: string;
    export const SnapshotObject: string;
    export const DeleteObject: string;
}
export namespace MetadataEvent {
    export const ProcessSortIndex: string;
    export const ProcessName: string;
    export const ThreadSortIndex: string;
    export const ThreadName: string;
}
export const LegacyTopLevelEventCategory: "toplevel";
export const DevToolsMetadataEventCategory: "disabled-by-default-devtools.timeline";
export const DevToolsTimelineEventCategory: "disabled-by-default-devtools.timeline";
/**
 * @interface
 */
export class BackingStorage {
    /**
     * @param {string} string
     */
    appendString(string: string): void;
    /**
     * @param {string} string
     * @return {function():!Promise<?string>}
     */
    appendAccessibleString(string: string): () => Promise<string | null>;
    finishWriting(): void;
    reset(): void;
}
/**
 * @unrestricted
 */
export class Event {
    /**
     * @this {null}
     * @param {!EventPayload} payload
     * @param {!Thread} thread
     * @return {!Event}
     */
    static fromPayload(payload: EventPayload, thread: Thread): Event;
    /**
     * @param {?Event} a
     * @param {?Event} b
     * @return {number}
     */
    static compareStartTime(a: Event | null, b: Event | null): number;
    /**
     * @param {!Event} a
     * @param {!Event} b
     * @return {number}
     */
    static orderedCompareStartTime(a: Event, b: Event): number;
    /**
     * @param {string|undefined} categories
     * @param {string} name
     * @param {!Phase} phase
     * @param {number} startTime
     * @param {!Thread} thread
     */
    constructor(categories: string | undefined, name: string, phase: Phase, startTime: number, thread: Thread);
    /** @type {string} */
    categoriesString: string;
    /** @type {!Set<string>} */
    _parsedCategories: Set<string>;
    /** @type {string} */
    name: string;
    /** @type {!Phase} */
    phase: Phase;
    /** @type {number} */
    startTime: number;
    /** @type {!Thread} */
    thread: Thread;
    /** @type {!Args} */
    args: Args;
    /** @type {?string} */
    id: string | null;
    /** @type {?string} */
    bind_id: string | null;
    /** @type {number} */
    ordinal: number;
    /** @type {number} */
    selfTime: number;
    /**
     * @param {string} categoryName
     * @return {boolean}
     */
    hasCategory(categoryName: string): boolean;
    /**
     * @param {number} endTime
     */
    setEndTime(endTime: number): void;
    endTime: number | undefined;
    duration: number | undefined;
    /**
     * @param {!Args} args
     */
    addArgs(args: Args): void;
    /**
     * @param {!Event} endEvent
     */
    _complete(endEvent: Event): void;
    /**
     * @param {?function():!Promise.<?string>} backingStorage
     */
    _setBackingStorage(backingStorage: (() => Promise<string | null>) | null): void;
}
export class ObjectSnapshot extends Event {
    /**
     * @override
     * @this {null}
     * @param {!EventPayload} payload
     * @param {!Thread} thread
     * @return {!ObjectSnapshot}
     */
    static fromPayload(payload: EventPayload, thread: Thread): ObjectSnapshot;
    /**
     * @param {string|undefined} category
     * @param {string} name
     * @param {number} startTime
     * @param {!Thread} thread
     */
    constructor(category: string | undefined, name: string, startTime: number, thread: Thread);
    /** @type {?function():!Promise<?string>} */
    _backingStorage: (() => Promise<string | null>) | null;
    /** @type {?Promise<?>} */
    _objectPromise: Promise<unknown> | null;
    /**
     * @param {function(?ObjectSnapshot):void} callback
     */
    requestObject(callback: (arg0: ObjectSnapshot | null) => void): void;
    /**
     * @return {!Promise<?>}
     */
    objectPromise(): Promise<unknown>;
}
/**
 * @unrestricted
 */
export class AsyncEvent extends Event {
    /**
     * @param {!Event} startEvent
     */
    constructor(startEvent: Event);
    steps: Event[];
    /**
     * @param {!Event} event
     */
    _addStep(event: Event): void;
}
export class Process extends NamedObject {
    /**
     * @param {!TracingModel} model
     * @param {number} id
     */
    constructor(model: TracingModel, id: number);
    /** @type {!Map<number, !Thread>} */
    _threads: Map<number, Thread>;
    _threadByName: Map<any, any>;
    /**
     * @return {number}
     */
    id(): number;
    /**
     * @param {number} id
     * @return {!Thread}
     */
    threadById(id: number): Thread;
    /**
     * @param {string} name
     * @return {?Thread}
     */
    threadByName(name: string): Thread | null;
    /**
     * @param {string} name
     * @param {!Thread} thread
     */
    _setThreadByName(name: string, thread: Thread): void;
    /**
     * @param {!EventPayload} payload
     * @return {?Event} event
     */
    _addEvent(payload: EventPayload): Event | null;
    /**
     * @return {!Array<!Thread>}
     */
    sortedThreads(): Array<Thread>;
}
export class Thread extends NamedObject {
    /**
     * @param {!Process} process
     * @param {number} id
     */
    constructor(process: Process, id: number);
    _process: Process;
    /**
     * @type {!Array<!Event>};
     */
    _events: Array<Event>;
    /**
     * @type {!Array<!AsyncEvent>};
     */
    _asyncEvents: Array<AsyncEvent>;
    _lastTopLevelEvent: Event | null;
    tracingComplete(): void;
    /**
     * @param {!EventPayload} payload
     * @return {?Event} event
     */
    _addEvent(payload: EventPayload): Event | null;
    /**
     * @param {!AsyncEvent} asyncEvent
     */
    _addAsyncEvent(asyncEvent: AsyncEvent): void;
    /**
     * @return {number}
     */
    id(): number;
    /**
     * @return {!Process}
     */
    process(): Process;
    /**
     * @return {!Array<!Event>}
     */
    events(): Array<Event>;
    /**
     * @return {!Array<!AsyncEvent>}
     */
    asyncEvents(): Array<AsyncEvent>;
    /**
     * @param {string} name
     */
    removeEventsByName(name: string): Event[];
}
export type Args = any;
export type Sortable = {
    _sortIndex: number;
    name: () => string;
};
declare class ProfileEventsGroup {
    /**
     * @param {!Event} event
     */
    constructor(event: Event);
    /** @type {!Array<!Event>} */
    children: Array<Event>;
    /**
     * @param {!Event} event
     */
    _addChild(event: Event): void;
}
import { EventPayload } from "./TracingManager.js";
/** @typedef {*} */
declare let Args: any;
declare class NamedObject {
    /**
     * @param {!TracingModel} model
     * @param {number} id
     */
    constructor(model: TracingModel, id: number);
    _model: TracingModel;
    _id: number;
    _name: string;
    _sortIndex: number;
    /**
     * @param {string} name
     */
    _setName(name: string): void;
    /**
     * @return {string}
     */
    name(): string;
    /**
     * @param {number} sortIndex
     */
    _setSortIndex(sortIndex: number): void;
}
export {};
