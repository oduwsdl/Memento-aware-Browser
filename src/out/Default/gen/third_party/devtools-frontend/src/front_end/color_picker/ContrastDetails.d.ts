export class ContrastDetails extends Common.ObjectWrapper.ObjectWrapper {
    static _showHelp(): void;
    /**
     * @param {!ContrastInfo} contrastInfo
     * @param {!Element} contentElement
     * @param {function(boolean=, !Common.EventTarget.EventTargetEvent=):void} toggleMainColorPickerCallback
     * @param {function():void} expandedChangedCallback
     */
    constructor(contrastInfo: ContrastInfo, contentElement: Element, toggleMainColorPickerCallback: (arg0: boolean | undefined, arg1: Common.EventTarget.EventTargetEvent | undefined) => void, expandedChangedCallback: () => void);
    /** @type {!ContrastInfo} */
    _contrastInfo: ContrastInfo;
    /** @type {!Element} */
    _element: Element;
    /** @type {function(boolean=, !Common.EventTarget.EventTargetEvent=):void} */
    _toggleMainColorPicker: (arg0?: boolean | undefined, arg1?: Common.EventTarget.EventTargetEvent | undefined) => void;
    /** @type {function():void} */
    _expandedChangedCallback: () => void;
    /** @type {boolean} */
    _expanded: boolean;
    /** @type {boolean} */
    _passesAA: boolean;
    /** @type {boolean} */
    _contrastUnknown: boolean;
    /** @type {boolean} */
    _visible: boolean;
    /** @type {!Element} */
    _noContrastInfoAvailable: Element;
    _contrastValueBubble: Element;
    _contrastValue: Element;
    /** @type {!Array<!Node>} */
    _contrastValueBubbleIcons: Array<Node>;
    _expandButton: UI.Toolbar.ToolbarButton;
    _expandedDetails: Element;
    _contrastThresholds: Element;
    _contrastAA: Element;
    _contrastPassFailAA: Element;
    _contrastAAA: Element;
    _contrastPassFailAAA: Element;
    _chooseBgColor: Element;
    _bgColorPickerButton: UI.Toolbar.ToolbarToggle;
    _bgColorPickedBound: (event: Common.EventTarget.EventTargetEvent) => void;
    _bgColorSwatch: Swatch;
    _showNoContrastInfoAvailableMessage(): void;
    _hideNoContrastInfoAvailableMessage(): void;
    _update(): void;
    /**
     * @param {boolean} visible
     */
    setVisible(visible: boolean): void;
    /**
     * @return {boolean}
     */
    visible(): boolean;
    /**
     * @return {!Element}
     */
    element(): Element;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _expandButtonClicked(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Event} event
     */
    _topRowClicked(event: Event): void;
    _toggleExpanded(): void;
    collapse(): void;
    /**
     * @return {boolean}
     */
    expanded(): boolean;
    /**
     * @returns {boolean}
     */
    backgroundColorPickerEnabled(): boolean;
    /**
     * @param {boolean} enabled
     */
    toggleBackgroundColorPicker(enabled: boolean): void;
    /**
     * @param {boolean=} enabled
     * @param {boolean=} shouldTriggerEvent
     */
    _toggleBackgroundColorPicker(enabled?: boolean | undefined, shouldTriggerEvent?: boolean | undefined): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _bgColorPicked(event: Common.EventTarget.EventTargetEvent): void;
}
export namespace Events {
    export const BackgroundColorPickerWillBeToggled: symbol;
}
export class Swatch {
    /**
     * @param {!Element} parentElement
     */
    constructor(parentElement: Element);
    _parentElement: Element;
    _swatchElement: Element;
    _swatchInnerElement: HTMLElement;
    _textPreview: HTMLElement;
    /**
     * @param {!Common.Color.Color} fgColor
     * @param {!Common.Color.Color} bgColor
     */
    setColors(fgColor: Common.Color.Color, bgColor: Common.Color.Color): void;
}
import * as Common from "../common/common.js";
import { ContrastInfo } from "./ContrastInfo.js";
import * as UI from "../ui/ui.js";
