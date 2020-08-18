/**
 * @unrestricted
 */
export class ResizerWidget extends Common.ObjectWrapper.ObjectWrapper {
    _isEnabled: boolean;
    /** @type {!Set<!Element>} */
    _elements: Set<Element>;
    _installDragOnMouseDownBound: (event: Event) => false | undefined;
    _cursor: string;
    /**
     * @return {boolean}
     */
    isEnabled(): boolean;
    /**
     * @param {boolean} enabled
     */
    setEnabled(enabled: boolean): void;
    /**
     * @return {!Array.<!Element>}
     */
    elements(): Array<Element>;
    /**
     * @param {!Element} element
     */
    addElement(element: Element): void;
    /**
     * @param {!Element} element
     */
    removeElement(element: Element): void;
    updateElementCursors(): void;
    /**
     * @param {!Element} element
     */
    _updateElementCursor(element: Element): void;
    /**
     * @return {string}
     */
    cursor(): string;
    /**
     * @param {string} cursor
     */
    setCursor(cursor: string): void;
    /**
     * @param {!Event} event
     */
    _installDragOnMouseDown(event: Event): false | undefined;
    /**
     * @param {!MouseEvent} event
     * @return {boolean}
     */
    _dragStart(event: MouseEvent): boolean;
    _startX: number | undefined;
    _startY: number | undefined;
    /**
     * @param {number} x
     * @param {number} y
     */
    sendDragStart(x: number, y: number): void;
    /**
     * @param {!MouseEvent} event
     * @return {boolean}
     */
    _drag(event: MouseEvent): boolean;
    /**
     * @param {number} startX
     * @param {number} currentX
     * @param {number} startY
     * @param {number} currentY
     * @param {boolean} shiftKey
     */
    sendDragMove(startX: number, currentX: number, startY: number, currentY: number, shiftKey: boolean): void;
    /**
     * @param {!MouseEvent} event
     */
    _dragEnd(event: MouseEvent): void;
}
export type Events = symbol;
export namespace Events {
    export const ResizeStart: symbol;
    export const ResizeUpdate: symbol;
    export const ResizeEnd: symbol;
}
export class SimpleResizerWidget extends ResizerWidget {
    _isVertical: boolean;
    /**
     * @return {boolean}
     */
    isVertical(): boolean;
    /**
     * Vertical widget resizes height (along y-axis).
     * @param {boolean} vertical
     */
    setVertical(vertical: boolean): void;
}
import * as Common from "../common/common.js";
