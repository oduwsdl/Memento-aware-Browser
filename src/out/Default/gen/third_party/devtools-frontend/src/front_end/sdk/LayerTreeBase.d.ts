/**
 * @interface
 */
export class Layer {
    /**
     * @return {string}
     */
    id(): string;
    /**
     * @return {?string}
     */
    parentId(): string | null;
    /**
     * @return {?Layer}
     */
    parent(): Layer | null;
    /**
     * @return {boolean}
     */
    isRoot(): boolean;
    /**
     * @return {!Array.<!Layer>}
     */
    children(): Array<Layer>;
    /**
     * @param {!Layer} child
     */
    addChild(child: Layer): void;
    /**
     * @return {?DOMNode}
     */
    node(): DOMNode | null;
    /**
     * @return {?DOMNode}
     */
    nodeForSelfOrAncestor(): DOMNode | null;
    /**
     * @return {number}
     */
    offsetX(): number;
    /**
     * @return {number}
     */
    offsetY(): number;
    /**
     * @return {number}
     */
    width(): number;
    /**
     * @return {number}
     */
    height(): number;
    /**
     * @return {?Array.<number>}
     */
    transform(): Array<number> | null;
    /**
     * @return {!Array.<number>}
     */
    quad(): Array<number>;
    /**
     * @return {!Array.<number>}
     */
    anchorPoint(): Array<number>;
    /**
     * @return {boolean}
     */
    invisible(): boolean;
    /**
     * @return {number}
     */
    paintCount(): number;
    /**
     * @return {?Protocol.DOM.Rect}
     */
    lastPaintRect(): Protocol.DOM.Rect | null;
    /**
     * @return {!Array.<!Protocol.LayerTree.ScrollRect>}
     */
    scrollRects(): Array<Protocol.LayerTree.ScrollRect>;
    /**
     * @return {?StickyPositionConstraint}
     */
    stickyPositionConstraint(): StickyPositionConstraint | null;
    /**
     * @return {number}
     */
    gpuMemoryUsage(): number;
    /**
     * @return {!Promise<!Array<string>>}
     */
    requestCompositingReasonIds(): Promise<Array<string>>;
    /**
     * @return {boolean}
     */
    drawsContent(): boolean;
    /**
     * @return {!Array<!Promise<?SnapshotWithRect>>}
     */
    snapshots(): Array<Promise<SnapshotWithRect | null>>;
}
export namespace Layer {
    export namespace ScrollRectType {
        export const NonFastScrollable: string;
        export const TouchEventHandler: string;
        export const WheelEventHandler: string;
        export const RepaintsOnScroll: string;
        export const MainThreadScrollingReason: string;
    }
}
export class StickyPositionConstraint {
    /**
     * @param {?LayerTreeBase} layerTree
     * @param {!Protocol.LayerTree.StickyPositionConstraint} constraint
     * @struct
     */
    constructor(layerTree: LayerTreeBase | null, constraint: Protocol.LayerTree.StickyPositionConstraint);
    /** @type {!Protocol.DOM.Rect} */
    _stickyBoxRect: Protocol.DOM.Rect;
    /** @type {!Protocol.DOM.Rect} */
    _containingBlockRect: Protocol.DOM.Rect;
    /** @type {?Layer} */
    _nearestLayerShiftingStickyBox: Layer | null;
    /** @type {?Layer} */
    _nearestLayerShiftingContainingBlock: Layer | null;
    /**
     * @return {!Protocol.DOM.Rect}
     */
    stickyBoxRect(): Protocol.DOM.Rect;
    /**
     * @return {!Protocol.DOM.Rect}
     */
    containingBlockRect(): Protocol.DOM.Rect;
    /**
     * @return {?Layer}
     */
    nearestLayerShiftingStickyBox(): Layer | null;
    /**
     * @return {?Layer}
     */
    nearestLayerShiftingContainingBlock(): Layer | null;
}
/**
 * @unrestricted
 */
export class LayerTreeBase {
    /**
     * @param {?Target} target
     */
    constructor(target: Target | null);
    _target: Target | null;
    _domModel: any;
    /** @type {!Map<(string|number), !Layer>} */
    layersById: Map<(string | number), Layer>;
    _root: Layer | null;
    _contentRoot: Layer | null;
    /** @type {!Map<number, ?DOMNode>} */
    _backendNodeIdToNode: Map<number, DOMNode | null>;
    /**
     * @return {?Target}
     */
    target(): Target | null;
    /**
     * @return {?Layer}
     */
    root(): Layer | null;
    /**
     * @param {?Layer} root
     * @protected
     */
    protected setRoot(root: Layer | null): void;
    /**
     * @return {?Layer}
     */
    contentRoot(): Layer | null;
    /**
     * @param {?Layer} contentRoot
     * @protected
     */
    protected setContentRoot(contentRoot: Layer | null): void;
    /**
     * @param {function(!Layer):*} callback
     * @param {?Layer=} root
     * @return {*}
     */
    forEachLayer(callback: (arg0: Layer) => any, root?: (Layer | null) | undefined): any;
    /**
     * @param {string} id
     * @return {?Layer}
     */
    layerById(id: string): Layer | null;
    /**
     * @param {!Set<number>} requestedNodeIds
     * @return {!Promise<void>}
     */
    resolveBackendNodeIds(requestedNodeIds: Set<number>): Promise<void>;
    /**
     * @return {!Map<number, ?DOMNode>}
     */
    backendNodeIdToNode(): Map<number, DOMNode | null>;
    /**
     * @param {!{width: number, height: number}} viewportSize
     */
    setViewportSize(viewportSize: {
        width: number;
        height: number;
    }): void;
    _viewportSize: {
        width: number;
        height: number;
    } | undefined;
    /**
     * @return {!{width: number, height: number}|undefined}
     */
    viewportSize(): {
        width: number;
        height: number;
    } | undefined;
    /**
     * @param {number} id
     * @return {?DOMNode}
     */
    _nodeForId(id: number): DOMNode | null;
}
import { DOMNode } from "./DOMModel.js";
import { SnapshotWithRect } from "./PaintProfiler.js";
import { Target } from "./SDKModel.js";
