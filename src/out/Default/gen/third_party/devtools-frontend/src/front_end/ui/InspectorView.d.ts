/**
 * @implements {ViewLocationResolver}
 * @unrestricted
 */
export class InspectorView extends VBox implements ViewLocationResolver {
    /**
     * @return {!InspectorView}
     */
    static instance(): InspectorView;
    _drawerSplitWidget: SplitWidget;
    _tabDelegate: InspectorViewTabDelegate;
    _drawerTabbedLocation: import("./View.js").TabbedViewLocation;
    _drawerTabbedPane: TabbedPane;
    _tabbedLocation: import("./View.js").TabbedViewLocation;
    _tabbedPane: TabbedPane;
    _keyDownBound: (event: Event) => void;
    /**
     * @override
     * @param {string} locationName
     * @return {?ViewLocation}
     */
    resolveLocation(locationName: string): ViewLocation | null;
    createToolbars(): void;
    /**
     * @param {!View} view
     */
    addPanel(view: View): void;
    /**
     * @param {string} panelName
     * @return {boolean}
     */
    hasPanel(panelName: string): boolean;
    /**
     * @param {string} panelName
     * @return {!Promise.<!Panel>}
     */
    panel(panelName: string): Promise<Panel>;
    /**
     * @param {boolean} allTargetsSuspended
     */
    onSuspendStateChanged(allTargetsSuspended: boolean): void;
    _currentPanelLocked: boolean | undefined;
    /**
     * @param {string} panelName
     * @return {boolean}
     */
    canSelectPanel(panelName: string): boolean;
    /**
     * @param {string} panelName
     * @return {!Promise.<?Panel>}
     */
    showPanel(panelName: string): Promise<Panel | null>;
    /**
     * @param {string} tabId
     * @param {?Icon} icon
     */
    setPanelIcon(tabId: string, icon: Icon | null): void;
    /**
     * @param {string} tabId
     * @return {?TabbedPane}
     */
    _getTabbedPaneForTabId(tabId: string): TabbedPane | null;
    /**
     * @return {?Panel}
     */
    currentPanelDeprecated(): Panel | null;
    /**
     * @param {boolean} focus
     */
    _showDrawer(focus: boolean): void;
    _focusRestorer: WidgetFocusRestorer | null | undefined;
    /**
     * @return {boolean}
     */
    drawerVisible(): boolean;
    _closeDrawer(): void;
    /**
     * @param {boolean} minimized
     */
    setDrawerMinimized(minimized: boolean): void;
    /**
     * @return {boolean}
     */
    isDrawerMinimized(): boolean;
    /**
     * @param {string} id
     * @param {boolean=} userGesture
     */
    closeDrawerTab(id: string, userGesture?: boolean | undefined): void;
    /**
     * @param {!Event} event
     */
    _keyDown(event: Event): void;
    /**
     * @return {!Element}
     */
    topResizerElement(): Element;
    toolbarItemResized(): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _tabSelected(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _drawerTabSelected(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!SplitWidget} splitWidget
     */
    setOwnerSplit(splitWidget: SplitWidget): void;
    _ownerSplitWidget: SplitWidget | undefined;
    /**
     * @return {?SplitWidget}
     */
    ownerSplit(): SplitWidget | null;
    minimize(): void;
    restore(): void;
}
/**
 * @implements {ActionDelegateInterface}
 * @unrestricted
 */
export class ActionDelegate implements ActionDelegateInterface {
    /**
     * @override
     * @param {!Context} context
     * @param {string} actionId
     * @return {boolean}
     */
    handleAction(context: Context, actionId: string): boolean;
}
/**
 * @implements {TabbedPaneTabDelegate}
 */
export class InspectorViewTabDelegate implements TabbedPaneTabDelegate {
    /**
     * @override
     * @param {!TabbedPane} tabbedPane
     * @param {!Array.<string>} ids
     */
    closeTabs(tabbedPane: TabbedPane, ids: Array<string>): void;
    /**
     * @param {string} tabId
     */
    moveToDrawer(tabId: string): void;
    /**
     * @param {string} tabId
     */
    moveToMainPanel(tabId: string): void;
    /**
     * @override
     * @param {string} tabId
     * @param {!ContextMenu} contextMenu
     */
    onContextMenu(tabId: string, contextMenu: ContextMenu): void;
}
import { VBox } from "./Widget.js";
import { ViewLocationResolver } from "./View.js";
import { SplitWidget } from "./SplitWidget.js";
import { TabbedPane } from "./TabbedPane.js";
import { ViewLocation } from "./View.js";
import { View } from "./View.js";
import { Panel } from "./Panel.js";
import { Icon } from "./Icon.js";
import { WidgetFocusRestorer } from "./Widget.js";
import * as Common from "../common/common.js";
import { ActionDelegate as ActionDelegateInterface } from "./ActionDelegate.js";
import { Context } from "./Context.js";
import { TabbedPaneTabDelegate } from "./TabbedPane.js";
import { ContextMenu } from "./ContextMenu.js";
