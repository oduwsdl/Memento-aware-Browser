/**
 * @unrestricted
 */
export class Tooltip {
    /**
     * @param {!Document} doc
     */
    static installHandler(doc: Document): void;
    /**
     * @param {!Element} element
     * @param {?Element|string} tooltipContent
     * @param {string=} actionId
     * @param {?TooltipOptions=} options
     */
    static install(element: Element, tooltipContent: (Element | string) | null, actionId?: string | undefined, options?: (TooltipOptions | null) | undefined): void;
    /**
     * @param {!Element} element
     */
    static addNativeOverrideContainer(element: Element): void;
    /**
     * @param {!Document} doc
     */
    constructor(doc: Document);
    element: HTMLElement;
    _shadowRoot: DocumentFragment;
    _tooltipElement: any;
    /**
     * @param {!Event} event
     */
    _mouseMove(event: Event): void;
    /**
     * @param {!Element} anchorElement
     * @param {!Event} event
     */
    _reposition(anchorElement: Element, event: Event): void;
    /**
     * @returns {boolean}
     */
    _anchorTooltipAtElement(): boolean;
    /**
     * @param {!Element} anchorElement
     * @param {!Event} event
     */
    _show(anchorElement: Element, event: Event): void;
    _anchorElement: Element | undefined;
    _tooltipLastOpened: number | undefined;
    /**
     * @return {boolean}
     */
    _shouldUseNativeTooltips(): boolean;
    /**
     * @param {boolean} removeInstant
     */
    _hide(removeInstant: boolean): void;
    _tooltipLastClosed: number | undefined;
    _reset(): void;
}
export type TooltipOptions = {
    anchorTooltipAtElement: (boolean | undefined);
};
/**
 * @typedef {{
 * anchorTooltipAtElement: (boolean|undefined)
 * }}
 */
export let TooltipOptions: any;
export const TooltipSymbol: symbol;
