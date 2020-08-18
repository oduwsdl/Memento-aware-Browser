export class PaintProfilerModel extends SDKModel {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _layerTreeAgent: ProtocolProxyApi.LayerTreeApi;
    /**
     * @param {!Array.<!Protocol.LayerTree.PictureTile>} tiles
     * @return {!Promise<?PaintProfilerSnapshot>}
     */
    loadSnapshotFromFragments(tiles: Array<Protocol.LayerTree.PictureTile>): Promise<PaintProfilerSnapshot | null>;
    /**
     * @param {!Protocol.binary} encodedPicture
     * @return {!Promise<?PaintProfilerSnapshot>}
     */
    loadSnapshot(encodedPicture: Protocol.binary): Promise<PaintProfilerSnapshot | null>;
    /**
     * @param {!Protocol.LayerTree.LayerId} layerId
     * @return {!Promise<?PaintProfilerSnapshot>}
     */
    makeSnapshot(layerId: Protocol.LayerTree.LayerId): Promise<PaintProfilerSnapshot | null>;
}
export class PaintProfilerSnapshot {
    /**
     * @param {!PaintProfilerModel} paintProfilerModel
     * @param {!Protocol.LayerTree.SnapshotId} snapshotId
     */
    constructor(paintProfilerModel: PaintProfilerModel, snapshotId: Protocol.LayerTree.SnapshotId);
    _paintProfilerModel: PaintProfilerModel;
    _id: string;
    _refCount: number;
    release(): void;
    addReference(): void;
    /**
     * @param {number=} scale
     * @param {number=} fromStep
     * @param {number=} toStep
     * @return {!Promise<?string>}
     */
    replay(scale?: number | undefined, fromStep?: number | undefined, toStep?: number | undefined): Promise<string | null>;
    /**
     * @param {?Protocol.DOM.Rect} clipRect
     * @return {!Promise<?Array<!Protocol.LayerTree.PaintProfile>>}
     */
    profile(clipRect: Protocol.DOM.Rect | null): Promise<Array<Protocol.LayerTree.PaintProfile> | null>;
    /**
     * @return {!Promise<?Array<!PaintProfilerLogItem>>}
     */
    commandLog(): Promise<Array<PaintProfilerLogItem> | null>;
}
export class PaintProfilerLogItem {
    /**
     * @param {!RawPaintProfilerLogItem} rawEntry
     * @param {number} commandIndex
     */
    constructor(rawEntry: RawPaintProfilerLogItem, commandIndex: number);
    method: string;
    params: {
        [x: string]: any;
    } | null;
    commandIndex: number;
}
export type SnapshotWithRect = {
    rect: Protocol.DOM.Rect;
    snapshot: PaintProfilerSnapshot;
};
/** @typedef {!{
        rect: !Protocol.DOM.Rect,
        snapshot: !PaintProfilerSnapshot
    }}
*/
export let SnapshotWithRect: any;
export type PictureFragment = {
    x: number;
    y: number;
    picture: string;
};
/**
 * @typedef {!{x: number, y: number, picture: string}}
 */
export let PictureFragment: any;
export type RawPaintProfilerLogItem = {
    method: string;
    params: {
        [x: string]: any;
    } | null;
};
/**
 * @typedef {!{method: string, params: ?Object<string, *>}}
 */
export let RawPaintProfilerLogItem: any;
import { SDKModel } from "./SDKModel.js";
import { Target } from "./SDKModel.js";
