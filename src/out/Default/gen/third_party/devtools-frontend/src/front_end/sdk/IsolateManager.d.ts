/**
 * @implements {SDKModelObserver}
 */
export class IsolateManager extends Common.ObjectWrapper.ObjectWrapper implements SDKModelObserver<any> {
    /** @type {!Map<string, !Isolate>} */
    _isolates: Map<string, Isolate>;
    /** @type {!Map<!RuntimeModel, ?string>} */
    _isolateIdByModel: Map<RuntimeModel, string | null>;
    /** @type {!Set<!Observer>} */
    _observers: Set<Observer>;
    _pollId: number;
    /**
     * @param {!Observer} observer
     */
    observeIsolates(observer: Observer): void;
    /**
     * @param {!Observer} observer
     */
    unobserveIsolates(observer: Observer): void;
    /**
     * @override
     * @param {!RuntimeModel} model
     */
    modelAdded(model: RuntimeModel): void;
    /**
     * @param {!RuntimeModel} model
     */
    _modelAdded(model: RuntimeModel): Promise<void>;
    /**
     * @override
     * @param {!RuntimeModel} model
     */
    modelRemoved(model: RuntimeModel): void;
    /**
     * @param {!RuntimeModel} model
     * @return {?Isolate}
     */
    isolateByModel(model: RuntimeModel): Isolate | null;
    /**
     * @return {!IteratorIterable<!Isolate>}
     */
    isolates(): any;
    _poll(): Promise<void>;
}
/**
 * @interface
 */
export class Observer {
    /**
     * @param {!Isolate} isolate
     */
    isolateAdded(isolate: Isolate): void;
    /**
     * @param {!Isolate} isolate
     */
    isolateRemoved(isolate: Isolate): void;
    /**
     * @param {!Isolate} isolate
     */
    isolateChanged(isolate: Isolate): void;
}
export type Events = symbol;
export namespace Events {
    export const MemoryChanged: symbol;
}
export const MemoryTrendWindowMs: 120000;
export class Isolate {
    /**
     * @param {string} id
     */
    constructor(id: string);
    _id: string;
    /** @type {!Set<!RuntimeModel>} */
    _models: Set<RuntimeModel>;
    _usedHeapSize: number;
    _memoryTrend: MemoryTrend;
    /**
     * @return {string}
     */
    id(): string;
    /**
     * @return {!Set<!RuntimeModel>}
     */
    models(): Set<RuntimeModel>;
    /**
     * @return {?RuntimeModel}
     */
    runtimeModel(): RuntimeModel | null;
    /**
     * @return {?HeapProfilerModel}
     */
    heapProfilerModel(): HeapProfilerModel | null;
    _update(): Promise<void>;
    /**
     * @return {number}
     */
    samplesCount(): number;
    /**
     * @return {number}
     */
    usedHeapSize(): number;
    /**
     * @return {number} bytes per millisecond
     */
    usedHeapSizeGrowRate(): number;
    /**
     * @return {boolean}
     */
    isMainThread(): boolean;
}
/**
 * @unrestricted
 */
export class MemoryTrend {
    /**
     * @param {number} maxCount
     */
    constructor(maxCount: number);
    _maxCount: number;
    reset(): void;
    _base: number | undefined;
    _index: any;
    /** @type {!Array<number>} */
    _x: number[] | undefined;
    /** @type {!Array<number>} */
    _y: number[] | undefined;
    _sx: number | undefined;
    _sy: number | undefined;
    _sxx: number | undefined;
    _sxy: number | undefined;
    /**
     * @return {number}
     */
    count(): number;
    /**
     * @param {number} heapSize
     * @param {number=} timestamp
     */
    add(heapSize: number, timestamp?: number | undefined): void;
    /**
     * @return {number}
     */
    fitSlope(): number;
}
import * as Common from "../common/common.js";
import { SDKModelObserver } from "./SDKModel.js";
import { RuntimeModel } from "./RuntimeModel.js";
import { HeapProfilerModel } from "./HeapProfilerModel.js";
