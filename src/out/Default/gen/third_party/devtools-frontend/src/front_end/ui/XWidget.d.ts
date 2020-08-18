/**
 * @extends {XElement}
 */
export class XWidget extends XElement {
    /**
     * @param {!Event} event
     */
    static _storeScrollPosition(event: Event): void;
    _visible: boolean;
    /** @type {?DocumentFragment} */
    _shadowRoot: DocumentFragment | null;
    /** @type {?Element} */
    _defaultFocusedElement: Element | null;
    /** @type {!Array<!Element>} */
    _elementsToRestoreScrollPositionsFor: Array<Element>;
    /** @type {?function():void} */
    _onShownCallback: (() => void) | null;
    /** @type {?function():void} */
    _onHiddenCallback: (() => void) | null;
    /** @type {?function():void} */
    _onResizedCallback: (() => void) | null;
    /**
     * @return {boolean}
     */
    isShowing(): boolean;
    /**
     * @param {string} cssFile
     */
    registerRequiredCSS(cssFile: string): void;
    /**
     * @param {?function():void} callback
     */
    setOnShown(callback: (() => void) | null): void;
    /**
     * @param {?function():void} callback
     */
    setOnHidden(callback: (() => void) | null): void;
    /**
     * @param {?function():void} callback
     */
    setOnResized(callback: (() => void) | null): void;
    /**
     * @param {!Array<!Element>} elements
     */
    setElementsToRestoreScrollPositionsFor(elements: Array<Element>): void;
    restoreScrollPositions(): void;
    /**
     * @param {?Element} element
     */
    setDefaultFocusedElement(element: Element | null): void;
    /**
     * @override
     */
    connectedCallback(): void;
    /**
     * @override
     */
    disconnectedCallback(): void;
}
import { XElement } from "./XElement.js";
