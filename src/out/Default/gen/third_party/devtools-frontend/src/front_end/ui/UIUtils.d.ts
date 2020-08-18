/**
 * @param {!Element} element
 * @param {?function(!MouseEvent): boolean} elementDragStart
 * @param {function(!MouseEvent):void} elementDrag
 * @param {?function(!MouseEvent):void} elementDragEnd
 * @param {?string} cursor
 * @param {?string=} hoverCursor
 * @param {number=} startDelay
 */
export function installDragHandle(element: Element, elementDragStart: ((arg0: MouseEvent) => boolean) | null, elementDrag: (arg0: MouseEvent) => void, elementDragEnd: ((arg0: MouseEvent) => void) | null, cursor: string | null, hoverCursor?: (string | null) | undefined, startDelay?: number | undefined): void;
/**
 * @param {!Element} targetElement
 * @param {?function(!MouseEvent):boolean} elementDragStart
 * @param {function(!MouseEvent):void} elementDrag
 * @param {?function(!MouseEvent):void} elementDragEnd
 * @param {?string} cursor
 * @param {!Event} event
 */
export function elementDragStart(targetElement: Element, elementDragStart: ((arg0: MouseEvent) => boolean) | null, elementDrag: (arg0: MouseEvent) => void, elementDragEnd: ((arg0: MouseEvent) => void) | null, cursor: string | null, event: Event): void;
/**
 * @param {?Node=} node
 * @return {boolean}
 */
export function isBeingEdited(node?: (Node | null) | undefined): boolean;
/**
 * @return {boolean}
 * @suppressGlobalPropertiesCheck
 */
export function isEditing(): boolean;
/**
 * @param {!Element} element
 * @param {boolean} value
 * @return {boolean}
 */
export function markBeingEdited(element: Element, value: boolean): boolean;
/**
 * @param {string} wordString
 * @param {!Event} event
 * @param {function(string, number, string):string=} customNumberHandler
 * @return {?string}
 */
export function createReplacementString(wordString: string, event: Event, customNumberHandler?: ((arg0: string, arg1: number, arg2: string) => string) | undefined): string | null;
/**
 * @param {!Event} event
 * @param {!Element} element
 * @param {function(string,string):void=} finishHandler
 * @param {(function(string):*)=} suggestionHandler
 * @param {function(string, number, string):string=} customNumberHandler
 * @return {boolean}
 */
export function handleElementValueModifications(event: Event, element: Element, finishHandler?: ((arg0: string, arg1: string) => void) | undefined, suggestionHandler?: ((arg0: string) => any) | undefined, customNumberHandler?: ((arg0: string, arg1: number, arg2: string) => string) | undefined): boolean;
/**
 * @param {string} format
 * @param {?ArrayLike<*>} substitutions
 * @return {!Element}
 */
export function formatLocalized(format: string, substitutions: ArrayLike<any> | null): Element;
/**
 * @return {string}
 */
export function openLinkExternallyLabel(): string;
/**
 * @return {string}
 */
export function copyLinkAddressLabel(): string;
/**
 * @return {string}
 */
export function anotherProfilerActiveLabel(): string;
/**
 * @param {string|undefined} description
 * @return {string}
 */
export function asyncStackTraceLabel(description: string | undefined): string;
/**
 * @param {!Element} element
 */
export function installComponentRootStyles(element: Element): void;
/**
 * @param {!Element} element
 * @returns {boolean}
 */
export function elementIsFocusedByKeyboard(element: Element): boolean;
/**
 * @param {!Element} element
 * @param {number} offset
 * @param {number} length
 * @param {!Array.<!Object>=} domChanges
 * @return {?Element}
 */
export function highlightSearchResult(element: Element, offset: number, length: number, domChanges?: Array<Object> | undefined): Element | null;
/**
 * @param {!Element} element
 * @param {!Array.<!TextUtils.SourceRange>} resultRanges
 * @param {!Array.<!Object>=} changes
 * @return {!Array.<!Element>}
 */
export function highlightSearchResults(element: Element, resultRanges: Array<any>, changes?: Array<Object> | undefined): Array<Element>;
/**
 * @param {!Element} element
 * @param {string} className
 */
export function runCSSAnimationOnce(element: Element, className: string): void;
/**
 * @param {!Element} element
 * @param {!Array.<!TextUtils.SourceRange>} resultRanges
 * @param {string} styleClass
 * @param {!Array.<!Object>=} changes
 * @return {!Array.<!Element>}
 */
export function highlightRangesWithStyleClass(element: Element, resultRanges: Array<any>, styleClass: string, changes?: Array<Object> | undefined): Array<Element>;
export function applyDomChanges(domChanges: any): void;
export function revertDomChanges(domChanges: any): void;
/**
 * @param {!Element} element
 * @param {?Element=} containerElement
 * @return {!Size}
 */
export function measurePreferredSize(element: Element, containerElement?: (Element | null) | undefined): Size;
export function startBatchUpdate(): void;
export function endBatchUpdate(): void;
/**
 * @param {!Object} object
 * @param {function():void} method
 */
export function invokeOnceAfterBatchUpdate(object: Object, method: () => void): void;
/**
 * @param {!Window} window
 * @param {!Function} func
 * @param {!Array.<{from:number, to:number}>} params
 * @param {number} duration
 * @param {function():*=} animationComplete
 * @return {function():void}
 */
export function animateFunction(window: Window, func: Function, params: Array<{
    from: number;
    to: number;
}>, duration: number, animationComplete: () => any | undefined): () => void;
/**
 * @param {!Document} document
 * @param {!Common.Settings.Setting<string>} themeSetting
 */
export function initializeUIUtils(document: Document, themeSetting: Common.Settings.Setting<string>): void;
/**
 * @param {string} name
 * @return {string}
 */
export function beautifyFunctionName(name: string): string;
/**
 * @param {string} text
 * @param {function(!Event):*=} clickHandler
 * @param {string=} className
 * @param {boolean=} primary
 * @return {!Element}
 */
export function createTextButton(text: string, clickHandler: (arg0: Event) => any | undefined, className?: string | undefined, primary?: boolean | undefined): Element;
/**
 * @param {string=} className
 * @param {string=} type
 * @return {!Element}
 */
export function createInput(className?: string | undefined, type?: string | undefined): Element;
/**
 * @param {string} title
 * @param {string=} className
 * @param {!Element=} associatedControl
 * @return {!Element}
 */
export function createLabel(title: string, className?: string | undefined, associatedControl?: Element | undefined): Element;
/**
 * @param {string} name
 * @param {string} title
 * @param {boolean=} checked
 * @return {!Element}
 */
export function createRadioLabel(name: string, title: string, checked?: boolean | undefined): Element;
/**
 * @param {string} title
 * @param {string} iconClass
 * @return {!Element}
 */
export function createIconLabel(title: string, iconClass: string): Element;
/**
 * @return {!Element}
 * @param {number} min
 * @param {number} max
 * @param {number} tabIndex
 */
export function createSlider(min: number, max: number, tabIndex: number): Element;
/**
 * @param {!Element} input
 * @param {function(string):void} apply
 * @param {function(string):{valid: boolean, errorMessage: (string|undefined)}} validate
 * @param {boolean} numeric
 * @param {number=} modifierMultiplier
 * @return {function(string):void}
 */
export function bindInput(input: Element, apply: (arg0: string) => void, validate: (arg0: string) => {
    valid: boolean;
    errorMessage: (string | undefined);
}, numeric: boolean, modifierMultiplier?: number | undefined): (arg0: string) => void;
/**
 * @param {!CanvasRenderingContext2D} context
 * @param {string} text
 * @param {number} maxWidth
 * @param {function(string, number):string} trimFunction
 * @return {string}
 */
export function trimText(context: CanvasRenderingContext2D, text: string, maxWidth: number, trimFunction: (arg0: string, arg1: number) => string): string;
/**
 * @param {!CanvasRenderingContext2D} context
 * @param {string} text
 * @param {number} maxWidth
 * @return {string}
 */
export function trimTextMiddle(context: CanvasRenderingContext2D, text: string, maxWidth: number): string;
/**
 * @param {!CanvasRenderingContext2D} context
 * @param {string} text
 * @param {number} maxWidth
 * @return {string}
 */
export function trimTextEnd(context: CanvasRenderingContext2D, text: string, maxWidth: number): string;
/**
 * @param {!CanvasRenderingContext2D} context
 * @param {string} text
 * @return {number}
 */
export function measureTextWidth(context: CanvasRenderingContext2D, text: string): number;
/**
 * @param {string} article
 * @param {string} title
 * @return {!Element}
 */
export function createDocumentationLink(article: string, title: string): Element;
/**
 * @param {string} article
 * @param {string} title
 * @return {!Element}
 */
export function createWebDevLink(article: string, title: string): Element;
/**
 * Adds a 'utm_source=devtools' as query parameter to the url.
 * @param {string} url
 * @return {string}
 */
export function addReferrerToURL(url: string): string;
/**
 * We want to add a referrer query param to every request to
 * 'web.dev' or 'developers.google.com'.
 * @param {string} url
 * @return {string}
 */
export function addReferrerToURLIfNecessary(url: string): string;
/**
 * @param {string} url
 * @return {!Promise<?Image>}
 */
export function loadImage(url: string): Promise<(new (width?: number | undefined, height?: number | undefined) => HTMLImageElement) | null>;
/**
 * @param {?string} data
 * @return {!Promise<?Image>}
 */
export function loadImageFromData(data: string | null): Promise<(new (width?: number | undefined, height?: number | undefined) => HTMLImageElement) | null>;
/**
 * @param {function(!File):*} callback
 * @return {!Node}
 */
export function createFileSelectorElement(callback: (arg0: File) => any): Node;
/**
 * @param {!ToolbarButton} toolbarButton
 * @return {!Element}
 */
export function createInlineButton(toolbarButton: ToolbarButton): Element;
/**
 * @param {number} timestamp
 * @param {boolean} full
 * @return {string}
 */
export function formatTimestamp(timestamp: number, full: boolean): string;
export const highlightedSearchResultClassName: "highlighted-search-result";
export const highlightedCurrentSearchResultClassName: "current-search-result";
export { markAsFocusedByKeyboard } from "./utils/focus-changed.js";
export const StyleValueDelimiters: "  \t\n\"':;,/()";
/** @type {!Common.UIString.UIStringFormat} */
export const _microsFormat: Common.UIString.UIStringFormat;
/** @type {!Common.UIString.UIStringFormat} */
export const _subMillisFormat: Common.UIString.UIStringFormat;
/** @type {!Common.UIString.UIStringFormat} */
export const _millisFormat: Common.UIString.UIStringFormat;
/** @type {!Common.UIString.UIStringFormat} */
export const _secondsFormat: Common.UIString.UIStringFormat;
/** @type {!Common.UIString.UIStringFormat} */
export const _minutesFormat: Common.UIString.UIStringFormat;
/** @type {!Common.UIString.UIStringFormat} */
export const _hoursFormat: Common.UIString.UIStringFormat;
/** @type {!Common.UIString.UIStringFormat} */
export const _daysFormat: Common.UIString.UIStringFormat;
/**
 * @unrestricted
 */
export class ElementFocusRestorer {
    /**
     * @param {!Element} element
     */
    constructor(element: Element);
    _element: Element;
    _previous: any;
    restore(): void;
}
/**
 * @unrestricted
 */
export class LongClickController extends Common.ObjectWrapper.ObjectWrapper {
    /**
     * @param {!Element} element
     * @param {function(!Event):void} callback
     * @param {function(!Event):void} isEditKeyFunc
     */
    constructor(element: Element, callback: (arg0: Event) => void, isEditKeyFunc?: (arg0: Event) => void);
    _element: Element;
    _callback: (arg0: Event) => void;
    _editKey: (arg0: Event) => void;
    /** @type {{mouseUp: function(!Event):void, mouseDown: function(!Event):void, reset: function():void }} */
    _longClickData: {
        mouseUp: (arg0: Event) => void;
        mouseDown: (arg0: Event) => void;
        reset: () => void;
    };
    reset(): void;
    _enable(): void;
    dispose(): void;
}
export namespace LongClickController {
    export const TIME_MS: number;
}
export class CheckboxLabel extends HTMLSpanElement {
    /**
     * @param {string=} title
     * @param {boolean=} checked
     * @param {string=} subtitle
     * @return {!CheckboxLabel}
     */
    static create(title?: string | undefined, checked?: boolean | undefined, subtitle?: string | undefined): CheckboxLabel;
    /** @type {!DocumentFragment} */
    _shadowRoot: DocumentFragment;
    /** @type {!HTMLInputElement} */
    checkboxElement: HTMLInputElement;
    /** @type {!Element} */
    textElement: Element;
    /**
     * @param {string} color
     * @this {Element}
     */
    set backgroundColor(arg: string);
    /**
     * @param {string} color
     * @this {Element}
     */
    set checkColor(arg: string);
    /**
     * @param {string} color
     * @this {Element}
     */
    set borderColor(arg: string);
}
/**
 * @unrestricted
 */
export class ThemeSupport {
    /**
     * @param {!Common.Settings.Setting<string>} setting
     */
    constructor(setting: Common.Settings.Setting<string>);
    _themeName: string;
    _themableProperties: Set<string>;
    /** @type {!Map<string, string>} */
    _cachedThemePatches: Map<string, string>;
    _setting: Common.Settings.Setting<string>;
    _customSheets: Set<any>;
    _computedRoot: () => symbol | CSSStyleDeclaration;
    /**
     * @param {string} variableName
     * @returns {string}
     */
    getComputedValue(variableName: string): string;
    /**
     * @return {boolean}
     */
    hasTheme(): boolean;
    /**
     * @return {string}
     */
    themeName(): string;
    /**
     * @param {!Element|!ShadowRoot} element
     */
    injectHighlightStyleSheets(element: Element | ShadowRoot): void;
    _injectingStyleSheet: boolean | undefined;
    /**
     * @param {!Element|!ShadowRoot} element
     */
    injectCustomStyleSheets(element: Element | ShadowRoot): void;
    /**
     * @return {boolean}
     */
    isForcedColorsMode(): boolean;
    /**
     * @param {string} sheetText
     */
    addCustomStylesheet(sheetText: string): void;
    /**
     * @param {!Document} document
     */
    applyTheme(document: Document): void;
    /**
     * @param {string} id
     * @param {string} text
     * @return {string}
     * @suppressGlobalPropertiesCheck
     */
    themeStyleSheet(id: string, text: string): string;
    /**
     * @param {string} id
     * @param {!StyleSheet} styleSheet
     * @return {string}
     */
    _patchForTheme(id: string, styleSheet: StyleSheet): string;
    /**
     * @param {string} selectorText
     * @param {!CSSStyleDeclaration} style
     * @param {string} name
     * @param {!Array<string>} output
     *
     * Theming API is primarily targeted at making dark theme look good.
     * - If rule has ".-theme-preserve" in selector, it won't be affected.
     * - One can create specializations for dark themes via body.-theme-with-dark-background selector in host context.
     */
    _patchProperty(selectorText: string, style: CSSStyleDeclaration, name: string, output: Array<string>): void;
    /**
     * @param {string} text
     * @param {!ThemeSupport.ColorUsage} colorUsage
     * @return {string}
     */
    patchColorText(text: string, colorUsage: ThemeSupport.ColorUsage): string;
    /**
     * @param {!Common.Color.Color} color
     * @param {!ThemeSupport.ColorUsage} colorUsage
     * @return {!Common.Color.Color}
     */
    patchColor(color: Common.Color.Color, colorUsage: ThemeSupport.ColorUsage): Common.Color.Color;
    /**
     * @param {!Array<number>} hsla
     * @param {!ThemeSupport.ColorUsage} colorUsage
     */
    _patchHSLA(hsla: Array<number>, colorUsage: ThemeSupport.ColorUsage): void;
}
export namespace ThemeSupport {
    export namespace ColorUsage {
        export const Unknown: number;
        export const Foreground: number;
        export const Background: number;
    }
    export type ColorUsage = number;
}
/**
 * @const
 * @type {number}
 */
export const MaxLengthForDisplayedURLs: number;
export class MessageDialog {
    /**
     * @param {string} message
     * @param {!Document|!Element=} where
     * @return {!Promise<void>}
     */
    static show(message: string, where?: (Document | Element) | undefined): Promise<void>;
}
export class ConfirmDialog {
    /**
     * @param {string} message
     * @param {!Document|!Element=} where
     * @return {!Promise<boolean>}
     */
    static show(message: string, where?: (Document | Element) | undefined): Promise<boolean>;
}
/**
 * @interface
 */
export class Renderer {
    /**
     * @param {!Object} object
     * @param {!Options=} options
     * @return {!Promise<?{node: !Node, tree: ?TreeOutline}>}
     */
    render(object: Object, options?: Options | undefined): Promise<{
        node: Node;
        tree: TreeOutline | null;
    } | null>;
}
export namespace Renderer {
    export function render(object: Object, options?: {
        title: string | Element | undefined;
        editable: boolean | undefined;
    } | undefined): Promise<{
        node: Node;
        tree: TreeOutline | null;
    } | null>;
}
export type Options = {
    title: (string | Element | undefined);
    editable: (boolean | undefined);
};
/** @typedef {!{title: (string|!Element|undefined), editable: (boolean|undefined) }} */
export let Options: any;
import { Size } from "./Geometry.js";
import * as Common from "../common/common.js";
import { ToolbarButton } from "./Toolbar.js";
import { TreeOutline } from "./Treeoutline.js";
