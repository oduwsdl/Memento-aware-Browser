export class ZoomManager extends Common.ObjectWrapper.ObjectWrapper {
    /**
     * @param {{forceNew: ?boolean, win: ?Window, frontendHost: ?Host.InspectorFrontendHostAPI.InspectorFrontendHostAPI}} opts
     */
    static instance(opts?: {
        forceNew: boolean | null;
        win: Window | null;
        frontendHost: Host.InspectorFrontendHostAPI.InspectorFrontendHostAPI | null;
    }): ZoomManager;
    /**
     * @private
     * @param {!Window} window
     * @param {!Host.InspectorFrontendHostAPI.InspectorFrontendHostAPI} frontendHost
     */
    private constructor();
    _frontendHost: Host.InspectorFrontendHostAPI.InspectorFrontendHostAPI;
    _zoomFactor: number;
    /**
     * @return {number}
     */
    zoomFactor(): number;
    /**
     * @param {number} value
     * @return {number}
     */
    cssToDIP(value: number): number;
    /**
     * @param {number} valueDIP
     * @return {number}
     */
    dipToCSS(valueDIP: number): number;
    _onWindowResize(): void;
}
export type Events = symbol;
export namespace Events {
    export const ZoomChanged: symbol;
}
import * as Common from "../common/common.js";
import * as Host from "../host/host.js";
