/**
 * @implements {Protocol.ProfilerDispatcher}
 */
export class CPUProfilerModel extends SDKModel {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _isRecording: boolean;
    _nextAnonymousConsoleProfileNumber: number;
    _anonymousConsoleProfileIdToTitle: Map<any, any>;
    _profilerAgent: any;
    /** @type {?function(number, string, !Array<!Protocol.Profiler.ScriptCoverage>):void} */
    _preciseCoverageDeltaUpdateCallback: ((arg0: number, arg1: string, arg2: Array<Protocol.Profiler.ScriptCoverage>) => void) | null;
    _debuggerModel: DebuggerModel;
    /**
     * @return {!RuntimeModel}
     */
    runtimeModel(): RuntimeModel;
    /**
     * @return {!DebuggerModel}
     */
    debuggerModel(): DebuggerModel;
    /**
     * @override
     * @param {string} id
     * @param {!Protocol.Debugger.Location} scriptLocation
     * @param {string=} title
     */
    consoleProfileStarted(id: string, scriptLocation: Protocol.Debugger.Location, title?: string | undefined): void;
    /**
     * @override
     * @param {string} id
     * @param {!Protocol.Debugger.Location} scriptLocation
     * @param {!Protocol.Profiler.Profile} cpuProfile
     * @param {string=} title
     */
    consoleProfileFinished(id: string, scriptLocation: Protocol.Debugger.Location, cpuProfile: Protocol.Profiler.Profile, title?: string | undefined): void;
    /**
     * @param {symbol} eventName
     * @param {string} id
     * @param {!Protocol.Debugger.Location} scriptLocation
     * @param {string=} title
     * @param {!Protocol.Profiler.Profile=} cpuProfile
     */
    _dispatchProfileEvent(eventName: symbol, id: string, scriptLocation: Protocol.Debugger.Location, title?: string | undefined, cpuProfile?: Protocol.Profiler.Profile | undefined): void;
    /**
     * @return {boolean}
     */
    isRecordingProfile(): boolean;
    /**
     * @return {!Promise<?>}
     */
    startRecording(): Promise<unknown>;
    /**
     * @return {!Promise<?Protocol.Profiler.Profile>}
     */
    stopRecording(): Promise<Protocol.Profiler.Profile | null>;
    /**
     * @param {boolean} jsCoveragePerBlock - Collect per Block coverage if `true`, per function coverage otherwise.
     * @param {?function(number, string, !Array<!Protocol.Profiler.ScriptCoverage>):void} preciseCoverageDeltaUpdateCallback - Callback for coverage updates initiated from the back-end
     * @return {!Promise<?>}
     */
    startPreciseCoverage(jsCoveragePerBlock: boolean, preciseCoverageDeltaUpdateCallback: ((arg0: number, arg1: string, arg2: Array<Protocol.Profiler.ScriptCoverage>) => void) | null): Promise<unknown>;
    /**
     * @return {!Promise<{timestamp:number, coverage:!Array<!Protocol.Profiler.ScriptCoverage>}>}
     */
    takePreciseCoverage(): Promise<{
        timestamp: number;
        coverage: Array<Protocol.Profiler.ScriptCoverage>;
    }>;
    /**
     * @return {!Promise<?>}
     */
    stopPreciseCoverage(): Promise<unknown>;
    /**
     * @suppress {missingOverride}
     * @param {number} timestampInSeconds
     * @param {string} occassion
     * @param {!Array<!Protocol.Profiler.ScriptCoverage>} coverageData
     */
    preciseCoverageDeltaUpdate(timestampInSeconds: number, occassion: string, coverageData: Array<Protocol.Profiler.ScriptCoverage>): void;
}
export type Events = symbol;
export namespace Events {
    export const ConsoleProfileStarted: symbol;
    export const ConsoleProfileFinished: symbol;
}
export type EventData = {
    id: string;
    scriptLocation: any;
    title: string;
    cpuProfile: (Protocol.Profiler.Profile | undefined);
    cpuProfilerModel: CPUProfilerModel;
};
/** @typedef {!{id: string, scriptLocation: !DebuggerModel.Location, title: string, cpuProfile: (!Protocol.Profiler.Profile|undefined), cpuProfilerModel: !CPUProfilerModel}} */
export let EventData: any;
import { SDKModel } from "./SDKModel.js";
import { DebuggerModel } from "./DebuggerModel.js";
import { RuntimeModel } from "./RuntimeModel.js";
import { Location } from "./DebuggerModel.js";
import { Target } from "./SDKModel.js";
