export class PopoverHelper {
    /**
     * @param {!Element} container
     * @param {function(!MouseEvent):?PopoverRequest} getRequest
     */
    constructor(container: Element, getRequest: (arg0: MouseEvent) => PopoverRequest | null);
    _disableOnClick: boolean;
    _hasPadding: boolean;
    _getRequest: (arg0: MouseEvent) => PopoverRequest | null;
    _scheduledRequest: {
        box: AnchorBox;
        show: ((arg0: GlassPane) => Promise<boolean>);
        hide: (() => void | undefined);
    } | null;
    /** @type {?function():void} */
    _hidePopoverCallback: (() => void) | null;
    _container: Element;
    _showTimeout: number;
    _hideTimeout: number;
    /** @type {?number} */
    _hidePopoverTimer: number | null;
    /** @type {?number} */
    _showPopoverTimer: number | null;
    _boundMouseDown: (event: Event) => void;
    _boundMouseMove: (event: Event) => void;
    _boundMouseOut: (event: Event) => void;
    /**
     * @param {number} showTimeout
     * @param {number=} hideTimeout
     */
    setTimeout(showTimeout: number, hideTimeout?: number | undefined): void;
    /**
     * @param {boolean} hasPadding
     */
    setHasPadding(hasPadding: boolean): void;
    /**
     * @param {boolean} disableOnClick
     */
    setDisableOnClick(disableOnClick: boolean): void;
    /**
     * @param {!Event} event
     * @return {boolean}
     */
    _eventInScheduledContent(event: Event): boolean;
    /**
     * @param {!Event} event
     */
    _mouseDown(event: Event): void;
    /**
     * @param {!Event} event
     */
    _mouseMove(event: Event): void;
    /**
     * @param {!Event} event
     */
    _popoverMouseMove(event: Event): void;
    /**
     * @param {!GlassPane} popover
     * @param {!Event} event
     */
    _popoverMouseOut(popover: GlassPane, event: Event): void;
    /**
     * @param {!Event} event
     */
    _mouseOut(event: Event): void;
    /**
     * @param {number} timeout
     */
    _startHidePopoverTimer(timeout: number): void;
    /**
     * @param {!MouseEvent} event
     * @param {number} timeout
     */
    _startShowPopoverTimer(event: MouseEvent, timeout: number): void;
    _stopShowPopoverTimer(): void;
    /**
     * @return {boolean}
     */
    isPopoverVisible(): boolean;
    hidePopover(): void;
    _hidePopover(): void;
    /**
     * @param {!Document} document
     */
    _showPopover(document: Document): void;
    _stopHidePopoverTimer(): void;
    dispose(): void;
}
export type PopoverRequest = {
    box: AnchorBox;
    show: ((arg0: GlassPane) => Promise<boolean>);
    hide: (() => void | undefined);
};
/** @typedef {{box: !AnchorBox, show:(function(!GlassPane):!Promise<boolean>), hide:(function():void|undefined)}} */
export let PopoverRequest: any;
import { GlassPane } from "./GlassPane.js";
