export class HeapProfilerModel extends SDKModel {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _enabled: boolean;
    _heapProfilerAgent: ProtocolProxyApi.HeapProfilerApi;
    _memoryAgent: ProtocolProxyApi.MemoryApi;
    _runtimeModel: RuntimeModel;
    _samplingProfilerDepth: number;
    /**
     * @return {!DebuggerModel}
     */
    debuggerModel(): DebuggerModel;
    /**
     * @return {!RuntimeModel}
     */
    runtimeModel(): RuntimeModel;
    enable(): Promise<void>;
    /**
     * @param {number=} samplingRateInBytes
     * @returns {!Promise<boolean>}
     */
    startSampling(samplingRateInBytes?: number | undefined): Promise<boolean>;
    /**
     * @return {!Promise<?Protocol.HeapProfiler.SamplingHeapProfile>}
     */
    stopSampling(): Promise<Protocol.HeapProfiler.SamplingHeapProfile | null>;
    /**
     * @return {!Promise<?Protocol.HeapProfiler.SamplingHeapProfile>}
     */
    getSamplingProfile(): Promise<Protocol.HeapProfiler.SamplingHeapProfile | null>;
    /**
     * @returns {!Promise<boolean>}
     */
    startNativeSampling(): Promise<boolean>;
    /**
     * @return {!Promise<?NativeHeapProfile>}
     */
    stopNativeSampling(): Promise<NativeHeapProfile | null>;
    /**
     * @return {!Promise<?NativeHeapProfile>}
     */
    takeNativeSnapshot(): Promise<NativeHeapProfile | null>;
    /**
     * @return {!Promise<?NativeHeapProfile>}
     */
    takeNativeBrowserSnapshot(): Promise<NativeHeapProfile | null>;
    /**
     * @param {!Protocol.Memory.SamplingProfile} rawProfile
     * @return {!NativeHeapProfile}
     */
    _convertNativeProfile(rawProfile: Protocol.Memory.SamplingProfile): NativeHeapProfile;
    /**
     * @return {!Promise<boolean>}
     */
    collectGarbage(): Promise<boolean>;
    /**
     * @param {string} objectId
     * @return {!Promise<?string>}
     */
    snapshotObjectIdForObjectId(objectId: string): Promise<string | null>;
    /**
     * @param {string} snapshotObjectId
     * @param {string} objectGroupName
     * @return {!Promise<?RemoteObject>}
     */
    objectForSnapshotObjectId(snapshotObjectId: string, objectGroupName: string): Promise<RemoteObject | null>;
    /**
     * @param {string} snapshotObjectId
     * @return {!Promise<boolean>}
     */
    addInspectedHeapObject(snapshotObjectId: string): Promise<boolean>;
    /**
     * @param {boolean} reportProgress
     * @param {boolean} treatGlobalObjectsAsRoots
     * @return {!Promise<void>}
     */
    takeHeapSnapshot(reportProgress: boolean, treatGlobalObjectsAsRoots: boolean): Promise<void>;
    /**
     * @param {boolean} recordAllocationStacks
     * @return {!Promise<boolean>}
     */
    startTrackingHeapObjects(recordAllocationStacks: boolean): Promise<boolean>;
    /**
     * @param {boolean} reportProgress
     * @return {!Promise<boolean>}
     */
    stopTrackingHeapObjects(reportProgress: boolean): Promise<boolean>;
    /**
     * @param {!Array<number>} samples
     */
    heapStatsUpdate(samples: Array<number>): void;
    /**
     * @param {number} lastSeenObjectId
     * @param {number} timestamp
     */
    lastSeenObjectId(lastSeenObjectId: number, timestamp: number): void;
    /**
     * @param {string} chunk
     */
    addHeapSnapshotChunk(chunk: string): void;
    /**
     * @param {number} done
     * @param {number} total
     * @param {boolean=} finished
     */
    reportHeapSnapshotProgress(done: number, total: number, finished?: boolean | undefined): void;
    resetProfiles(): void;
}
export type Events = symbol;
export namespace Events {
    export const HeapStatsUpdate: symbol;
    export const LastSeenObjectId: symbol;
    export const AddHeapSnapshotChunk: symbol;
    export const ReportHeapSnapshotProgress: symbol;
    export const ResetProfiles: symbol;
}
export type NativeProfilerCallFrame = {
    functionName: string;
    url: string;
    scriptId: (Protocol.Runtime.ScriptId | undefined);
    lineNumber: (number | undefined);
    columnNumber: (number | undefined);
};
/** @typedef {!{functionName: string, url: string, scriptId: (Protocol.Runtime.ScriptId|undefined), lineNumber: (number|undefined), columnNumber: (number|undefined)}} */
export let NativeProfilerCallFrame: any;
export type CommonHeapProfileNode = {
    callFrame: NativeProfilerCallFrame;
    selfSize: number;
    id: (number | undefined);
    children: Array<CommonHeapProfileNode>;
};
/** @typedef {!{callFrame: !NativeProfilerCallFrame, selfSize: number, id: (number|undefined), children: Array<!CommonHeapProfileNode>}} */
export let CommonHeapProfileNode: any;
export type CommonHeapProfile = {
    head: CommonHeapProfileNode;
    modules: Array<Protocol.Memory.Module>;
};
/** @typedef {!{head:!CommonHeapProfileNode, modules:!Array<!Protocol.Memory.Module>}} */
export let CommonHeapProfile: any;
export type NodeForConstruction = {
    callFrame: NativeProfilerCallFrame;
    selfSize: number;
    childMap: Map<string, NodeForConstruction>;
};
import { SDKModel } from "./SDKModel.js";
import { RuntimeModel } from "./RuntimeModel.js";
import { DebuggerModel } from "./DebuggerModel.js";
/**
 * TODO(chromium:1011811): Change this to implements once we are TypeScript-only.
 * @extends {CommonHeapProfile}
 */
declare class NativeHeapProfile {
    /**
     * @param {!CommonHeapProfileNode} head
     * @param {!Array<!Protocol.Memory.Module>} modules
     */
    constructor(head: CommonHeapProfileNode, modules: Array<Protocol.Memory.Module>);
    head: {
        callFrame: NativeProfilerCallFrame;
        selfSize: number;
        id: (number | undefined);
        children: Array<CommonHeapProfileNode>;
    };
    modules: Protocol.Memory.Module[];
}
import { RemoteObject } from "./RemoteObject.js";
import { Target } from "./SDKModel.js";
/** @typedef {!{callFrame: !NativeProfilerCallFrame, selfSize: number, childMap: !Map<string, !NodeForConstruction>}} */
declare let NodeForConstruction: any;
export {};
