/**
 * @unrestricted
 */
export class Segment {
    /**
     * @param {number} begin
     * @param {number} end
     * @param {*} data
     */
    constructor(begin: number, end: number, data: any);
    begin: number;
    end: number;
    data: any;
    /**
     * @param {!Segment} that
     * @return {boolean}
     */
    intersects(that: Segment): boolean;
}
/**
 * @unrestricted
 */
export class SegmentedRange {
    /**
     * @param {(function(!Segment, !Segment): ?Segment)=} mergeCallback
     */
    constructor(mergeCallback?: ((arg0: Segment, arg1: Segment) => Segment | null) | undefined);
    /** @type {!Array<!Segment>} */
    _segments: Array<Segment>;
    _mergeCallback: ((arg0: Segment, arg1: Segment) => Segment | null) | undefined;
    /**
     * @param {!Segment} newSegment
     */
    append(newSegment: Segment): void;
    /**
     * @param {!SegmentedRange} that
     */
    appendRange(that: SegmentedRange): void;
    /**
     * @return {!Array<!Segment>}
     */
    segments(): Array<Segment>;
    /**
     * @param {!Segment} first
     * @param {!Segment} second
     * @return {?Segment}
     */
    _tryMerge(first: Segment, second: Segment): Segment | null;
}
