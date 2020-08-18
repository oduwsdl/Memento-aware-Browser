export class SegmentedButton extends HBox {
    /** @type {!Map<string, !Element>} */
    _buttons: Map<string, Element>;
    /** @type {?string} */
    _selected: string | null;
    /**
     * @param {string} label
     * @param {string} value
     * @param {string=} tooltip
     */
    addSegment(label: string, value: string, tooltip?: string | undefined): void;
    /**
     * @param {string} value
     */
    select(value: string): void;
    /**
     * @return {?string}
     */
    selected(): string | null;
}
import { HBox } from "./Widget.js";
