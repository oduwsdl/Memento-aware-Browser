export class GlassPane {
    /**
     * @param {!Element} element
     */
    static setContainer(element: Element): void;
    /**
     * @param {!Document} document
     * @return {!Element}
     */
    static container(document: Document): Element;
    /**
     * @param {!Element} element
     */
    static containerMoved(element: Element): void;
    _widget: Widget;
    element: HTMLDivElement;
    contentElement: HTMLDivElement;
    _arrowElement: Icon;
    _onMouseDownBound: (event: Event) => void;
    /** @type {?function(!Event):void} */
    _onClickOutsideCallback: ((arg0: Event) => void) | null;
    /** @type {?Size} */
    _maxSize: Size | null;
    /** @type {?number} */
    _positionX: number | null;
    /** @type {?number} */
    _positionY: number | null;
    /** @type {?AnchorBox} */
    _anchorBox: AnchorBox | null;
    _anchorBehavior: symbol;
    _sizeBehavior: symbol;
    _marginBehavior: symbol;
    /**
     * @return {boolean}
     */
    isShowing(): boolean;
    /**
     * @param {string} cssFile
     */
    registerRequiredCSS(cssFile: string): void;
    /**
     * @param {?Element} element
     */
    setDefaultFocusedElement(element: Element | null): void;
    /**
     * @param {boolean} dimmed
     */
    setDimmed(dimmed: boolean): void;
    /**
     * @param {!PointerEventsBehavior} pointerEventsBehavior
     */
    setPointerEventsBehavior(pointerEventsBehavior: PointerEventsBehavior): void;
    /**
     * @param {?function(!Event):void} callback
     */
    setOutsideClickCallback(callback: ((arg0: Event) => void) | null): void;
    /**
     * @param {?Size} size
     */
    setMaxContentSize(size: Size | null): void;
    /**
     * @param {!SizeBehavior} sizeBehavior
     */
    setSizeBehavior(sizeBehavior: SizeBehavior): void;
    /**
     * @param {?number} x
     * @param {?number} y
     * Position is relative to root element.
     */
    setContentPosition(x: number | null, y: number | null): void;
    /**
     * @param {?AnchorBox} anchorBox
     * Anchor box is relative to the document.
     */
    setContentAnchorBox(anchorBox: AnchorBox | null): void;
    /**
     * @param {!AnchorBehavior} behavior
     */
    setAnchorBehavior(behavior: AnchorBehavior): void;
    /**
     * @param {!MarginBehavior} behavior
     */
    setMarginBehavior(behavior: MarginBehavior): void;
    /**
     * @param {!Document} document
     */
    show(document: Document): void;
    hide(): void;
    /**
     * @param {!Event} event
     */
    _onMouseDown(event: Event): void;
    positionContent(): void;
    /**
     * @protected
     * @return {!Widget}
     */
    protected widget(): Widget;
}
export type PointerEventsBehavior = symbol;
export namespace PointerEventsBehavior {
    export const BlockedByGlassPane: symbol;
    export const PierceGlassPane: symbol;
    export const PierceContents: symbol;
}
export type AnchorBehavior = symbol;
export namespace AnchorBehavior {
    export const PreferTop: symbol;
    export const PreferBottom: symbol;
    export const PreferLeft: symbol;
    export const PreferRight: symbol;
}
export type SizeBehavior = symbol;
export namespace SizeBehavior {
    export const SetExactSize: symbol;
    export const SetExactWidthMaxHeight: symbol;
    export const MeasureContent: symbol;
}
export type MarginBehavior = symbol;
export namespace MarginBehavior {
    export const Arrow: symbol;
    export const DefaultMargin: symbol;
    export const NoMargin: symbol;
}
export const GlassPanePanes: Set<GlassPane>;
import { Widget } from "./Widget.js";
import { Icon } from "./Icon.js";
import { Size } from "./Geometry.js";
