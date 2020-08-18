/**
 * @unrestricted
 */
export class Widget extends Common.ObjectWrapper.ObjectWrapper {
    static _incrementWidgetCounter(parentElement: any, childElement: any): void;
    static _decrementWidgetCounter(parentElement: any, childElement: any): void;
    static __assert(condition: any, message: any): void;
    /**
     * @param {boolean=} isWebComponent
     * @param {boolean=} delegatesFocus
     */
    constructor(isWebComponent?: boolean | undefined, delegatesFocus?: boolean | undefined);
    contentElement: HTMLDivElement;
    element: HTMLDivElement;
    _shadowRoot: DocumentFragment;
    _isWebComponent: boolean | undefined;
    _visible: boolean;
    _isRoot: boolean;
    _isShowing: boolean;
    _children: any[];
    _hideOnDetach: boolean;
    _notificationDepth: number;
    _invalidationsSuspended: number;
    _defaultFocusedChild: Widget | null;
    markAsRoot(): void;
    /**
     * @return {?Widget}
     */
    parentWidget(): Widget | null;
    /**
     * @return {!Array.<!Widget>}
     */
    children(): Array<Widget>;
    /**
     * @param {!Widget} widget
     * @protected
     */
    protected childWasDetached(widget: Widget): void;
    /**
     * @return {boolean}
     */
    isShowing(): boolean;
    /**
     * @return {boolean}
     */
    shouldHideOnDetach(): boolean;
    setHideOnDetach(): void;
    /**
     * @return {boolean}
     */
    _inNotification(): boolean;
    _parentIsShowing(): any;
    /**
     * @param {function(this:Widget):void} method
     */
    _callOnVisibleChildren(method: (this: Widget) => void): void;
    _processWillShow(): void;
    _processWasShown(): void;
    _processWillHide(): void;
    _processWasHidden(): void;
    _processOnResize(): void;
    /**
     * @param {function(this:Widget):void} notification
     */
    _notify(notification: (this: Widget) => void): void;
    wasShown(): void;
    willHide(): void;
    onResize(): void;
    onLayout(): void;
    ownerViewDisposed(): void;
    /**
     * @param {!Element} parentElement
     * @param {?Node=} insertBefore
     */
    show(parentElement: Element, insertBefore?: (Node | null) | undefined): void;
    /**
     * @param {!Widget} parentWidget
     */
    _attach(parentWidget: Widget): void;
    _parentWidget: any;
    showWidget(): void;
    /**
     * @param {!Element} parentElement
     * @param {?Node=} insertBefore
     */
    _showWidget(parentElement: Element, insertBefore?: (Node | null) | undefined): void;
    hideWidget(): void;
    /**
     * @param {boolean} removeFromDOM
     */
    _hideWidget(removeFromDOM: boolean): void;
    /**
     * @param {boolean=} overrideHideOnDetach remove element from DOM instead of hiding
     */
    detach(overrideHideOnDetach?: boolean | undefined): void;
    detachChildWidgets(): void;
    /**
     * @return {!Array.<!Element>}
     */
    elementsToRestoreScrollPositionsFor(): Array<Element>;
    storeScrollPositions(): void;
    restoreScrollPositions(): void;
    doResize(): void;
    doLayout(): void;
    /**
     * @param {string} cssFile
     */
    registerRequiredCSS(cssFile: string): void;
    printWidgetHierarchy(): void;
    _collectWidgetHierarchy(prefix: any, lines: any): void;
    /**
     * @param {?Element} element
     */
    setDefaultFocusedElement(element: Element | null): void;
    _defaultFocusedElement: Element | null | undefined;
    /**
     * @param {!Widget} child
     */
    setDefaultFocusedChild(child: Widget): void;
    focus(): void;
    /**
     * @return {boolean}
     */
    hasFocus(): boolean;
    /**
     * @return {!Constraints}
     */
    calculateConstraints(): Constraints;
    /**
     * @return {!Constraints}
     */
    constraints(): Constraints;
    _cachedConstraints: Constraints | undefined;
    /**
     * @param {number} width
     * @param {number} height
     * @param {number} preferredWidth
     * @param {number} preferredHeight
     */
    setMinimumAndPreferredSizes(width: number, height: number, preferredWidth: number, preferredHeight: number): void;
    _constraints: Constraints | undefined;
    /**
     * @param {number} width
     * @param {number} height
     */
    setMinimumSize(width: number, height: number): void;
    /**
     * @return {boolean}
     */
    _hasNonZeroConstraints(): boolean;
    suspendInvalidations(): void;
    resumeInvalidations(): void;
    invalidateConstraints(): void;
    _invalidationsRequested: boolean | undefined;
    markAsExternallyManaged(): void;
    _externallyManaged: boolean | undefined;
}
export namespace Widget {
    export { _originalAppendChild };
    export { _originalInsertBefore };
    export { _originalRemoveChild };
    export { _originalRemoveChildren };
}
export const _originalAppendChild: <T extends Node>(newChild: T) => T;
export const _originalInsertBefore: <T extends Node>(newChild: T, refChild: Node | null) => T;
export const _originalRemoveChild: <T extends Node>(oldChild: T) => T;
export const _originalRemoveChildren: () => void;
/**
 * @unrestricted
 */
export class VBox extends Widget {
    /**
     * @param {boolean=} isWebComponent
     * @param {boolean=} delegatesFocus
     */
    constructor(isWebComponent?: boolean | undefined, delegatesFocus?: boolean | undefined);
}
/**
 * @unrestricted
 */
export class HBox extends Widget {
    /**
     * @param {boolean=} isWebComponent
     */
    constructor(isWebComponent?: boolean | undefined);
}
/**
 * @unrestricted
 */
export class VBoxWithResizeCallback extends VBox {
    /**
     * @param {function():void} resizeCallback
     */
    constructor(resizeCallback: () => void);
    _resizeCallback: () => void;
}
/**
 * @unrestricted
 */
export class WidgetFocusRestorer {
    /**
     * @param {!Widget} widget
     */
    constructor(widget: Widget);
    _widget: Widget;
    _previous: any;
    restore(): void;
}
import * as Common from "../common/common.js";
import { Constraints } from "./Geometry.js";
