export class PerformanceMetricsModel extends SDKModel {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _agent: ProtocolProxyApi.PerformanceApi;
    /** @type {!Map<string, !MetricMode>} */
    _metricModes: Map<string, MetricMode>;
    /** @type {!Map<string, !{lastValue: (number|undefined), lastTimestamp: (number|undefined)}>} */
    _metricData: Map<string, {
        lastValue: (number | undefined);
        lastTimestamp: (number | undefined);
    }>;
    /**
     * @return {!Promise<!Object>}
     */
    enable(): Promise<Object>;
    /**
     * @return {!Promise<!Object>}
     */
    disable(): Promise<Object>;
    /**
     * @return {!Promise<!{metrics: !Map<string, number>, timestamp: number}>}
     */
    requestMetrics(): Promise<{
        metrics: Map<string, number>;
        timestamp: number;
    }>;
}
export type MetricMode = symbol;
import { SDKModel } from "./SDKModel.js";
declare namespace MetricMode {
    export const CumulativeTime: symbol;
    export const CumulativeCount: symbol;
}
import { Target } from "./SDKModel.js";
export {};
