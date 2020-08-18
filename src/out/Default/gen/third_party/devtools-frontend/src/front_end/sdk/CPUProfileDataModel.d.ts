/**
 * @unrestricted
 */
export class CPUProfileNode extends ProfileNode {
    /**
     * @param {!Protocol.Profiler.ProfileNode} node
     * @param {number} sampleTime
     */
    constructor(node: Protocol.Profiler.ProfileNode, sampleTime: number);
    positionTicks: Protocol.Profiler.PositionTickInfo[] | undefined;
    deoptReason: string | null;
}
/**
 * @unrestricted
 */
export class CPUProfileDataModel extends ProfileTreeModel {
    /**
     * @param {!Protocol.Profiler.Profile} profile
     * @param {?Target} target
     */
    constructor(profile: Protocol.Profiler.Profile, target: Target | null);
    profileStartTime: number;
    profileEndTime: number;
    timestamps: any;
    samples: number[] | undefined;
    lines: any;
    totalHitCount: number;
    profileHead: CPUProfileNode;
    /**
     * @param {!Protocol.Profiler.Profile} profile
     */
    _compatibilityConversionHeadToNodes(profile: Protocol.Profiler.Profile): void;
    /**
     * @param {!Protocol.Profiler.Profile} profile
     * @return {?Array<number>}
     */
    _convertTimeDeltas(profile: Protocol.Profiler.Profile): Array<number> | null;
    /**
     * @param {!Array<!Protocol.Profiler.ProfileNode>} nodes
     * @return {!CPUProfileNode}
     */
    _translateProfileTree(nodes: Array<Protocol.Profiler.ProfileNode>): CPUProfileNode;
    _sortSamples(): void;
    _normalizeTimestamps(): void;
    _buildIdToNodeMap(): void;
    /** @type {!Map<number, !CPUProfileNode>} */
    _idToNode: Map<number, CPUProfileNode> | undefined;
    _extractMetaNodes(): void;
    gcNode: ProfileNode | undefined;
    programNode: ProfileNode | undefined;
    idleNode: ProfileNode | undefined;
    _fixMissingSamples(): void;
    /**
     * @param {function(number, !CPUProfileNode, number):void} openFrameCallback
     * @param {function(number, !CPUProfileNode, number, number, number):void} closeFrameCallback
     * @param {number=} startTime
     * @param {number=} stopTime
     */
    forEachFrame(openFrameCallback: (arg0: number, arg1: CPUProfileNode, arg2: number) => void, closeFrameCallback: (arg0: number, arg1: CPUProfileNode, arg2: number, arg3: number, arg4: number) => void, startTime?: number | undefined, stopTime?: number | undefined): void;
    _stackStartTimes: Float64Array | undefined;
    _stackChildrenDuration: Float64Array | undefined;
    /**
     * @param {number} index
     * @return {?CPUProfileNode}
     */
    nodeByIndex(index: number): CPUProfileNode | null;
}
import { ProfileNode } from "./ProfileTreeModel.js";
import { ProfileTreeModel } from "./ProfileTreeModel.js";
import { Target } from "./SDKModel.js";
