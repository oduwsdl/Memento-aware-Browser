export class FilmStripModel {
    /**
     * @param {!TracingModel} tracingModel
     * @param {number=} zeroTime
     */
    constructor(tracingModel: TracingModel, zeroTime?: number | undefined);
    /** @type {!Array<!Frame>} */
    _frames: Array<Frame>;
    /** @type {number} */
    _zeroTime: number;
    /** @type {number} */
    _spanTime: number;
    /**
     * @param {!TracingModel} tracingModel
     * @param {number=} zeroTime
     */
    reset(tracingModel: TracingModel, zeroTime?: number | undefined): void;
    /**
     * @return {!Array<!Frame>}
     */
    frames(): Array<Frame>;
    /**
     * @return {number}
     */
    zeroTime(): number;
    /**
     * @return {number}
     */
    spanTime(): number;
    /**
     * @param {number} timestamp
     * @return {?Frame}
     */
    frameByTimestamp(timestamp: number): Frame | null;
}
/**
 * @unrestricted
 */
export class Frame {
    /**
     * @param {!FilmStripModel} model
     * @param {!Event} event
     * @param {number} index
     * @return {!Frame}
     */
    static _fromEvent(model: FilmStripModel, event: Event, index: number): Frame;
    /**
     * @param {!FilmStripModel} model
     * @param {!ObjectSnapshot} snapshot
     * @param {number} index
     * @return {!Frame}
     */
    static _fromSnapshot(model: FilmStripModel, snapshot: ObjectSnapshot, index: number): Frame;
    /**
     * @param {!FilmStripModel} model
     * @param {number} timestamp
     * @param {number} index
     */
    constructor(model: FilmStripModel, timestamp: number, index: number);
    _model: FilmStripModel;
    timestamp: number;
    index: number;
    /** @type {?string} */
    _imageData: string | null;
    /** @type {?ObjectSnapshot} */
    _snapshot: ObjectSnapshot | null;
    /**
     * @return {!FilmStripModel}
     */
    model(): FilmStripModel;
    /**
     * @return {!Promise<?string>}
     */
    imageDataPromise(): Promise<string | null>;
}
import { TracingModel } from "./TracingModel.js";
import { ObjectSnapshot } from "./TracingModel.js";
import { Event } from "./TracingModel.js";
