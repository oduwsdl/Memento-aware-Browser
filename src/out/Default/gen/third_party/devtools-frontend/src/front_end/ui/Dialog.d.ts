export class Dialog extends GlassPane {
    /**
     * @return {boolean}
     */
    static hasInstance(): boolean;
    /** @type {!OutsideTabIndexBehavior} */
    _tabIndexBehavior: OutsideTabIndexBehavior;
    /** @type {!Map<!HTMLElement, number>} */
    _tabIndexMap: Map<HTMLElement, number>;
    /** @type {?WidgetFocusRestorer} */
    _focusRestorer: WidgetFocusRestorer | null;
    _closeOnEscape: boolean;
    /** @type {?Document} */
    _targetDocument: Document | null;
    _targetDocumentKeyDownHandler: (event: Event) => void;
    /**
     * @param {boolean} close
     */
    setCloseOnEscape(close: boolean): void;
    addCloseButton(): void;
    /**
     * @param {!OutsideTabIndexBehavior} tabIndexBehavior
     */
    setOutsideTabIndexBehavior(tabIndexBehavior: OutsideTabIndexBehavior): void;
    /**
     * @param {!Document} document
     */
    _disableTabIndexOnElements(document: Document): void;
    /**
     * @param {?SplitWidget} splitWidget
     * @return {!Set.<!HTMLElement>}
     */
    _getMainWidgetTabIndexElements(splitWidget: SplitWidget | null): Set<HTMLElement>;
    _restoreTabIndexOnElements(): void;
    /**
     * @param {!Event} event
     */
    _onKeyDown(event: Event): void;
}
export type OutsideTabIndexBehavior = symbol;
export namespace OutsideTabIndexBehavior {
    export const DisableAllOutsideTabIndex: symbol;
    export const PreserveMainViewTabIndex: symbol;
    export const PreserveTabIndex: symbol;
}
import { GlassPane } from "./GlassPane.js";
import { WidgetFocusRestorer } from "./Widget.js";
import { SplitWidget } from "./SplitWidget.js";
