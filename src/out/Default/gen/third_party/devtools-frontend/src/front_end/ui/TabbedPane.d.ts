/**
 * @unrestricted
 */
export class TabbedPane extends VBox {
    _headerElement: HTMLElement;
    _headerContentsElement: HTMLElement;
    _tabSlider: HTMLDivElement;
    _tabsElement: HTMLElement;
    _contentElement: HTMLElement;
    /** @type {!Array.<!TabbedPaneTab>} */
    _tabs: Array<TabbedPaneTab>;
    /** @type {!Array.<!TabbedPaneTab>} */
    _tabsHistory: Array<TabbedPaneTab>;
    /** @type {!Map<string, !TabbedPaneTab>} */
    _tabsById: Map<string, TabbedPaneTab>;
    _currentTabLocked: boolean;
    _autoSelectFirstItemOnShow: boolean;
    _triggerDropDownTimeout: number | null;
    _dropDownButton: HTMLDivElement;
    /**
     * @param {string} name
     */
    setAccessibleName(name: string): void;
    /**
     * @param {boolean} locked
     */
    setCurrentTabLocked(locked: boolean): void;
    /**
     * @param {boolean} autoSelect
     */
    setAutoSelectFirstItemOnShow(autoSelect: boolean): void;
    /**
     * @return {?Widget}
     */
    get visibleView(): Widget | null;
    /**
     * @return {!Array.<string>}
     */
    tabIds(): Array<string>;
    /**
     * @param {string} tabId
     * @return {number}
     */
    tabIndex(tabId: string): number;
    /**
     * @return {!Array.<!Widget>}
     */
    tabViews(): Array<Widget>;
    /**
     * @param {string} tabId
     * @return {?Widget}
     */
    tabView(tabId: string): Widget | null;
    /**
     * @return {?string}
     */
    get selectedTabId(): string | null;
    /**
     * @param {boolean} shrinkableTabs
     */
    setShrinkableTabs(shrinkableTabs: boolean): void;
    _shrinkableTabs: boolean | undefined;
    makeVerticalTabLayout(): void;
    _verticalTabLayout: boolean | undefined;
    /**
     * @param {boolean} closeableTabs
     */
    setCloseableTabs(closeableTabs: boolean): void;
    _closeableTabs: boolean | undefined;
    focusSelectedTabHeader(): void;
    /**
     * @return {!Element}
     */
    headerElement(): Element;
    /**
     * @param {string} id
     * @return {boolean}
     */
    isTabCloseable(id: string): boolean;
    /**
     * @param {!TabbedPaneTabDelegate} delegate
     */
    setTabDelegate(delegate: TabbedPaneTabDelegate): void;
    _delegate: TabbedPaneTabDelegate | undefined;
    /**
     * @param {string} id
     * @param {string} tabTitle
     * @param {!Widget} view
     * @param {string=} tabTooltip
     * @param {boolean=} userGesture
     * @param {boolean=} isCloseable
     * @param {number=} index
     */
    appendTab(id: string, tabTitle: string, view: Widget, tabTooltip?: string | undefined, userGesture?: boolean | undefined, isCloseable?: boolean | undefined, index?: number | undefined): void;
    /**
     * @param {string} id
     * @param {boolean=} userGesture
     */
    closeTab(id: string, userGesture?: boolean | undefined): void;
    /**
     * @param {!Array.<string>} ids
     * @param {boolean=} userGesture
     */
    closeTabs(ids: Array<string>, userGesture?: boolean | undefined): void;
    /**
     * @param {string} id
     * @param {boolean=} userGesture
     */
    _innerCloseTab(id: string, userGesture?: boolean | undefined): true | undefined;
    /**
     * @param {string} tabId
     * @return {boolean}
     */
    hasTab(tabId: string): boolean;
    /**
     * @param {string} id
     * @return {!Array.<string>}
     */
    otherTabs(id: string): Array<string>;
    /**
     * @param {string} id
     * @return {!Array.<string>}
     */
    _tabsToTheRight(id: string): Array<string>;
    _viewHasFocus(): boolean;
    /**
     * @param {string} id
     * @param {boolean=} userGesture
     * @param {boolean=} forceFocus
     * @return {boolean}
     */
    selectTab(id: string, userGesture?: boolean | undefined, forceFocus?: boolean | undefined): boolean;
    _currentTab: TabbedPaneTab | undefined;
    selectNextTab(): void;
    selectPrevTab(): void;
    /**
     * @param {number} tabsCount
     * @return {!Array.<string>}
     */
    lastOpenedTabIds(tabsCount: number): Array<string>;
    /**
     * @param {string} id
     * @param {?Icon} icon
     */
    setTabIcon(id: string, icon: Icon | null): void;
    /**
     * @param {string} id
     * @param {boolean} enabled
     */
    setTabEnabled(id: string, enabled: boolean): void;
    /**
     * @param {string} id
     * @param {string} className
     * @param {boolean=} force
     */
    toggleTabClass(id: string, className: string, force?: boolean | undefined): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _zoomChanged(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {string} id
     * @param {string} tabTitle
     * @param {string=} tabTooltip
     */
    changeTabTitle(id: string, tabTitle: string, tabTooltip?: string | undefined): void;
    /**
     * @param {string} id
     * @param {!Widget} view
     */
    changeTabView(id: string, view: Widget): void;
    headerResized(): void;
    makeTabSlider(): void;
    /**
     * @param {boolean} enable
     */
    _setTabSlider(enable: boolean): void;
    _sliderEnabled: boolean | undefined;
    _updateTabElements(): void;
    /**
     * @param {!Element} element
     * @param {!Element=} focusedElement
     */
    setPlaceholderElement(element: Element, focusedElement?: Element | undefined): void;
    _placeholderElement: Element | undefined;
    _focusedPlaceholderElement: Element | undefined;
    waitForTabElementUpdate(): Promise<void>;
    _innerUpdateTabElements(): void;
    _placeholderContainerElement: HTMLElement | undefined;
    /**
     * @param {number} index
     * @param {!TabbedPaneTab} tab
     */
    _showTabElement(index: number, tab: TabbedPaneTab): void;
    /**
     * @param {!TabbedPaneTab} tab
     */
    _hideTabElement(tab: TabbedPaneTab): void;
    _createDropDownButton(): HTMLDivElement;
    /**
     * @param {!Event} event
     */
    _dropDownClicked(event: Event): void;
    /**
     * @param {!Event} event
     */
    _dropDownKeydown(event: Event): void;
    /**
     * @param {!TabbedPaneTab} tab
     */
    _dropDownMenuItemSelected(tab: TabbedPaneTab): void;
    _lastSelectedOverflowTab: TabbedPaneTab | undefined;
    _totalWidth(): number;
    /**
     * @return {number}
     */
    _numberOfTabsShown(): number;
    disableOverflowMenu(): void;
    _overflowDisabled: boolean | undefined;
    _updateTabsDropDown(): void;
    /**
     * @param {boolean} hasMoreTabs
     */
    _maybeShowDropDown(hasMoreTabs: boolean): void;
    _measureDropDownButton(): void;
    _measuredDropDownButtonWidth: number | undefined;
    _updateWidths(): void;
    _measureWidths(): number[];
    /**
     * @param {!Array.<number>} measuredWidths
     * @param {number} totalWidth
     */
    _calculateMaxWidth(measuredWidths: Array<number>, totalWidth: number): number;
    /**
     * @param {!Array.<!TabbedPaneTab>} tabsOrdered
     * @param {!Array.<!TabbedPaneTab>} tabsHistory
     * @param {number} totalWidth
     * @param {number} measuredDropDownButtonWidth
     * @return {!Array.<number>}
     */
    _tabsToShowIndexes(tabsOrdered: Array<TabbedPaneTab>, tabsHistory: Array<TabbedPaneTab>, totalWidth: number, measuredDropDownButtonWidth: number): Array<number>;
    _hideCurrentTab(): void;
    /**
     * @param {!TabbedPaneTab} tab
     */
    _showTab(tab: TabbedPaneTab): void;
    _updateTabSlider(): void;
    /**
     * @param {!TabbedPaneTab} tab
     */
    _hideTab(tab: TabbedPaneTab): void;
    /**
     * @param {!TabbedPaneTab} tab
     * @param {number} index
     */
    _insertBefore(tab: TabbedPaneTab, index: number): void;
    /**
     * @return {!Toolbar}
     */
    leftToolbar(): Toolbar;
    _leftToolbar: Toolbar | undefined;
    /**
     * @return {!Toolbar}
     */
    rightToolbar(): Toolbar;
    _rightToolbar: Toolbar | undefined;
    /**
     * @param {boolean} allow
     * @param {boolean=} automatic
     */
    setAllowTabReorder(allow: boolean, automatic?: boolean | undefined): void;
    _allowTabReorder: boolean | undefined;
    _automaticReorder: boolean | undefined;
    /**
     * @param {!Event} event
     */
    _keyDown(event: Event): void;
}
export type EventData = {
    prevTabId: (string | undefined);
    tabId: string;
    view: (Widget | undefined);
    isUserGesture: (boolean | undefined);
};
/** @typedef {{
 *    prevTabId: (string|undefined),
 *    tabId: string,
 *    view: (!Widget|undefined),
 *    isUserGesture: (boolean|undefined)
 * }}
 */
export let EventData: any;
export type Events = symbol;
export namespace Events {
    export const TabInvoked: symbol;
    export const TabSelected: symbol;
    export const TabClosed: symbol;
    export const TabOrderChanged: symbol;
}
/**
 * @unrestricted
 */
export class TabbedPaneTab {
    /**
     * @param {!TabbedPane} tabbedPane
     * @param {string} id
     * @param {string} title
     * @param {boolean} closeable
     * @param {!Widget} view
     * @param {string=} tooltip
     */
    constructor(tabbedPane: TabbedPane, id: string, title: string, closeable: boolean, view: Widget, tooltip?: string | undefined);
    _closeable: boolean;
    _tabbedPane: TabbedPane;
    _id: string;
    _title: any;
    _tooltip: string | undefined;
    _view: Widget;
    _shown: boolean;
    /** @type {number} */
    _measuredWidth: number;
    /** @type {!Element|undefined} */
    _tabElement: Element | undefined;
    /** @type {?Element} */
    _iconContainer: Element | null;
    /**
     * @return {string}
     */
    get id(): string;
    /**
     * @param {string} title
     */
    set title(arg: string);
    /**
     * @return {string}
     */
    get title(): string;
    /**
     * @return {boolean}
     */
    isCloseable(): boolean;
    /**
     * @param {?Icon} icon
     */
    _setIcon(icon: Icon | null): void;
    _icon: Icon | null | undefined;
    /**
     * @param {string} className
     * @param {boolean=} force
     * @return {boolean}
     */
    _toggleClass(className: string, force?: boolean | undefined): boolean;
    /**
     * @param {!Widget} view
     */
    set view(arg: Widget);
    /**
     * @return {!Widget}
     */
    get view(): Widget;
    /**
     * @param {string|undefined} tooltip
     */
    set tooltip(arg: string | undefined);
    /**
     * @return {string|undefined}
     */
    get tooltip(): string | undefined;
    /**
     * @return {!Element}
     */
    get tabElement(): Element;
    /**
     * @return {number}
     */
    width(): number;
    /**
     * @param {number} width
     */
    setWidth(width: number): void;
    _width: number | undefined;
    /**
     * @param {!TabbedPaneTabDelegate} delegate
     */
    setDelegate(delegate: TabbedPaneTabDelegate): void;
    _delegate: TabbedPaneTabDelegate | undefined;
    /**
     * @param {!Element} tabElement
     * @param {!Element} titleElement
     * @param {boolean} measuring
     */
    _createIconElement(tabElement: Element, titleElement: Element, measuring: boolean): void;
    /**
     * @param {boolean} measuring
     * @return {!Element}
     */
    _createTabElement(measuring: boolean): Element;
    _titleElement: HTMLElement | undefined;
    /**
     * @param {!Event} event
     */
    _tabClicked(event: Event): void;
    /**
     * @param {!Event} event
     */
    _tabMouseDown(event: Event): void;
    /**
     * @param {!Event} event
     */
    _tabMouseUp(event: Event): void;
    /**
     * @param {!Array.<string>} ids
     */
    _closeTabs(ids: Array<string>): void;
    _tabContextMenu(event: any): void;
    /**
     * @param {!Event} event
     * @return {boolean}
     */
    _startTabDragging(event: Event): boolean;
    _dragStartX: any;
    /**
     * @param {!Event} event
     */
    _tabDragging(event: Event): void;
    /**
     * @param {!Event} event
     */
    _endTabDragging(event: Event): void;
}
/**
 * @interface
 */
export class TabbedPaneTabDelegate {
    /**
     * @param {!TabbedPane} tabbedPane
     * @param {!Array.<string>} ids
     */
    closeTabs(tabbedPane: TabbedPane, ids: Array<string>): void;
    /**
     * @param {string} tabId
     * @param {!ContextMenu} contextMenu
     */
    onContextMenu(tabId: string, contextMenu: ContextMenu): void;
}
import { VBox } from "./Widget.js";
import { Widget } from "./Widget.js";
import { Icon } from "./Icon.js";
import * as Common from "../common/common.js";
import { Toolbar } from "./Toolbar.js";
import { ContextMenu } from "./ContextMenu.js";
