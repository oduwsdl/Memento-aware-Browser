export type HighlightColor = {
    r: number;
    g: number;
    b: number;
    a: number;
};
/**
 * @typedef {{r: number, g: number, b: number, a: number}}
 */
export let HighlightColor: any;
export type HighlightRect = {
    x: number;
    y: number;
    width: number;
    height: number;
    color: HighlightColor;
    outlineColor: HighlightColor;
};
/**
 * @typedef {{x: number, y: number, width: number, height: number, color: HighlightColor, outlineColor: HighlightColor}}
 */
export let HighlightRect: any;
export type Hinge = {
    width: number;
    height: number;
    x: number;
    y: number;
    contentColor: HighlightColor;
    outlineColor: HighlightColor;
};
/** @typedef {!{width: number, height: number, x: number, y: number, contentColor:HighlightColor, outlineColor: HighlightColor}} */
export let Hinge: any;
/**
 * @implements {Protocol.OverlayDispatcher}
 */
export class OverlayModel extends SDKModel {
    /**
     * @param {!RemoteObject} object
     */
    static highlightObjectAsDOMNode(object: RemoteObject): void;
    static hideDOMNodeHighlight(): void;
    static muteHighlight(): Promise<any[]>;
    static unmuteHighlight(): Promise<any[]>;
    /**
     * @param {!HighlightRect} rect
     */
    static highlightRect(rect: HighlightRect): void;
    static clearHighlight(): void;
    /**
     * @param {function(!DOMNode):void} handler
     */
    static setInspectNodeHandler(handler: (arg0: DOMNode) => void): void;
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _domModel: DOMModel;
    _overlayAgent: any;
    _debuggerModel: any;
    _inspectModeEnabled: boolean;
    _gridFeaturesExperimentEnabled: any;
    _hideHighlightTimeout: number | null;
    _defaultHighlighter: DefaultHighlighter;
    _highlighter: DefaultHighlighter;
    _showPaintRectsSetting: Common.Settings.Setting<any>;
    _showLayoutShiftRegionsSetting: Common.Settings.Setting<any>;
    _showAdHighlightsSetting: Common.Settings.Setting<any>;
    _showDebugBordersSetting: Common.Settings.Setting<any>;
    _showFPSCounterSetting: Common.Settings.Setting<any>;
    _showScrollBottleneckRectsSetting: Common.Settings.Setting<any>;
    _showHitTestBordersSetting: Common.Settings.Setting<any>;
    _registeredListeners: any[];
    _showViewportSizeOnResize: boolean;
    /**
     * @param {!HighlightRect} rect
     * @return {!Promise<*>}
     */
    highlightRect({ x, y, width, height, color, outlineColor }: HighlightRect): Promise<any>;
    /**
     * @return {!Promise<*>}
     */
    clearHighlight(): Promise<any>;
    /**
     * @return {!Promise<void>}
     */
    _wireAgentToSettings(): Promise<void>;
    /**
     * @param {boolean} show
     */
    setShowViewportSizeOnResize(show: boolean): void;
    _updatePausedInDebuggerMessage(): void;
    /**
     * @param {?Highlighter} highlighter
     */
    setHighlighter(highlighter: Highlighter | null): void;
    /**
     * @param {!Protocol.Overlay.InspectMode} mode
     * @param {boolean=} showDetailedTooltip
     * @return {!Promise<void>}
     */
    setInspectMode(mode: Protocol.Overlay.InspectMode, showDetailedTooltip?: boolean | undefined): Promise<void>;
    /**
     * @return {boolean}
     */
    inspectModeEnabled(): boolean;
    /**
     * @param {!HighlightData} data
     * @param {string=} mode
     * @param {boolean=} showInfo
     */
    highlightInOverlay(data: HighlightData, mode?: string | undefined, showInfo?: boolean | undefined): void;
    /**
     * @param {!HighlightData} data
     */
    highlightInOverlayForTwoSeconds(data: HighlightData): void;
    /**
     * @param {number} delay
     */
    _delayedHideHighlight(delay: number): void;
    /**
     * @param {!Protocol.Page.FrameId} frameId
     */
    highlightFrame(frameId: Protocol.Page.FrameId): void;
    /**
     * @param {boolean} show
     * @param {?Hinge} hinge
     */
    showHingeForDualScreen(show: boolean, hinge?: Hinge | null): void;
    /**
     * @return {!Protocol.Overlay.GridHighlightConfig}
     */
    _buildGridHighlightConfig(): Protocol.Overlay.GridHighlightConfig;
    /**
     * @param {string=} mode
     * @param {boolean=} showDetailedToolip
     * @return {!Protocol.Overlay.HighlightConfig}
     */
    _buildHighlightConfig(mode?: string | undefined, showDetailedToolip?: boolean | undefined): Protocol.Overlay.HighlightConfig;
    /**
     * @override
     * @param {!Protocol.DOM.NodeId} nodeId
     */
    nodeHighlightRequested(nodeId: Protocol.DOM.NodeId): void;
    /**
     * @override
     * @param {!Protocol.DOM.BackendNodeId} backendNodeId
     */
    inspectNodeRequested(backendNodeId: Protocol.DOM.BackendNodeId): void;
    /**
     * @override
     * @param {!Protocol.Page.Viewport} viewport
     */
    screenshotRequested(viewport: Protocol.Page.Viewport): void;
    /**
     * @override
     */
    inspectModeCanceled(): void;
}
export type Events = symbol;
export namespace Events {
    export const InspectModeWillBeToggled: symbol;
    export const ExitedInspectMode: symbol;
    export const HighlightNodeRequested: symbol;
    export const ScreenshotRequested: symbol;
}
/**
 * @interface
 */
export class Highlighter {
    /**
     * @param {!HighlightData} data
     * @param {!Protocol.Overlay.HighlightConfig} config
     */
    highlightInOverlay(data: HighlightData, config: Protocol.Overlay.HighlightConfig): void;
    /**
     * @param {!Protocol.Overlay.InspectMode} mode
     * @param {!Protocol.Overlay.HighlightConfig} config
     * @return {!Promise<void>}
     */
    setInspectMode(mode: Protocol.Overlay.InspectMode, config: Protocol.Overlay.HighlightConfig): Promise<void>;
    /**
     * @param {!Protocol.Page.FrameId} frameId
     */
    highlightFrame(frameId: Protocol.Page.FrameId): void;
}
export type HighlightData = {
    node: (DOMNode | undefined);
    deferredNode: (DeferredDOMNode | undefined);
    selectorList: (string | undefined);
    object: (RemoteObject | undefined);
};
/** @typedef {{node: (!DOMNode|undefined),
 deferredNode: (!DeferredDOMNode|undefined),
 selectorList: (string|undefined),
 object:(!RemoteObject|undefined)}} */
export let HighlightData: any;
import { SDKModel } from "./SDKModel.js";
import { DOMModel } from "./DOMModel.js";
/**
 * @implements {Highlighter}
 */
declare class DefaultHighlighter implements Highlighter {
    /**
     * @param {!OverlayModel} model
     */
    constructor(model: OverlayModel);
    _model: OverlayModel;
    /**
     * @override
     * @param {!HighlightData} data
     * @param {!Protocol.Overlay.HighlightConfig} config
     */
    highlightInOverlay(data: HighlightData, config: Protocol.Overlay.HighlightConfig): void;
    /**
     * @override
     * @param {!Protocol.Overlay.InspectMode} mode
     * @param {!Protocol.Overlay.HighlightConfig} config
     * @return {!Promise<void>}
     */
    setInspectMode(mode: Protocol.Overlay.InspectMode, config: Protocol.Overlay.HighlightConfig): Promise<void>;
    /**
     * @override
     * @param {!Protocol.Page.FrameId} frameId
     */
    highlightFrame(frameId: Protocol.Page.FrameId): void;
}
import * as Common from "../common/common.js";
import { RemoteObject } from "./RemoteObject.js";
import { DOMNode } from "./DOMModel.js";
import { Target } from "./SDKModel.js";
import { DeferredDOMNode } from "./DOMModel.js";
export {};
