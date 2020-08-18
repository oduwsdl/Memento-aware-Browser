/**
 * @unrestricted
 */
export class ViewManager {
    /**
     * @param {{forceNew: ?boolean}} opts
     */
    static instance(opts?: {
        forceNew: boolean | null;
    }): ViewManager;
    /**
     * @param {!Array<!ToolbarItem>} toolbarItems
     * @return {?Element}
     */
    static _createToolbar(toolbarItems: Array<ToolbarItem>): Element | null;
    /** @type {!Map<string, !View>} */
    _views: Map<string, View>;
    /** @type {!Map<string, string>} */
    _locationNameByViewId: Map<string, string>;
    _locationOverrideSetting: Common.Settings.Setting<any>;
    /**
     * @param {string} viewId
     * @returns {string}
     */
    locationNameForViewId(viewId: string): string;
    /**
     * Moves a view to a new location
     * @param {string} viewId
     * @param {string} locationName
     */
    moveView(viewId: string, locationName: string): void;
    /**
     * @param {!View} view
     * @return {!Promise<void>}
     */
    revealView(view: View): Promise<void>;
    /**
     * @param {string} viewId
     * @return {?View}
     */
    view(viewId: string): View | null;
    /**
     * @param {string} viewId
     * @return {?Widget}
     */
    materializedWidget(viewId: string): Widget | null;
    /**
     * @param {string} viewId
     * @param {boolean=} userGesture
     * @param {boolean=} omitFocus
     * @return {!Promise<void>}
     */
    showView(viewId: string, userGesture?: boolean | undefined, omitFocus?: boolean | undefined): Promise<void>;
    /**
     * @param {string=} location
     * @return {!Promise<?_Location>}
     */
    resolveLocation(location?: string | undefined): Promise<_Location | null>;
    /**
     * @param {function():void=} revealCallback
     * @param {string=} location
     * @param {boolean=} restoreSelection
     * @param {boolean=} allowReorder
     * @param {?string=} defaultTab
     * @return {!TabbedViewLocation}
     */
    createTabbedLocation(revealCallback?: (() => void) | undefined, location?: string | undefined, restoreSelection?: boolean | undefined, allowReorder?: boolean | undefined, defaultTab?: (string | null) | undefined): TabbedViewLocation;
    /**
     * @param {function():void=} revealCallback
     * @param {string=} location
     * @return {!ViewLocation}
     */
    createStackLocation(revealCallback?: (() => void) | undefined, location?: string | undefined): ViewLocation;
    /**
     * @param {string} location
     * @return {boolean}
     */
    hasViewsForLocation(location: string): boolean;
    /**
     * @param {string} location
     * @return {!Array<!View>}
     */
    _viewsForLocation(location: string): Array<View>;
}
/**
 * @unrestricted
 */
export class ContainerWidget extends VBox {
    /**
     * @param {!View} view
     */
    constructor(view: View);
    _view: View;
    /**
     * @return {!Promise<*>}
     */
    _materialize(): Promise<any>;
    _materializePromise: Promise<void[]> | undefined;
    _wasShownForTest(): void;
}
/**
 * @unrestricted
 */
export class _ExpandableContainerWidget extends VBox {
    /**
     * @param {!View} view
     */
    constructor(view: View);
    _titleElement: HTMLDivElement;
    _titleExpandIcon: Icon;
    _view: View;
    /**
     * @return {!Promise<*>}
     */
    _materialize(): Promise<any>;
    _widget: Widget | undefined;
    _materializePromise: Promise<void[]> | undefined;
    /**
     * @return {!Promise<*>}
     */
    _expand(): Promise<any>;
    _collapse(): void;
    /**
     * @param {!Event} event
     */
    _toggleExpanded(event: Event): void;
    /**
     * @param {!Event} event
     */
    _onTitleKeyDown(event: Event): void;
}
export namespace _ExpandableContainerWidget {
    export const _symbol: symbol;
}
/**
 * @implements {TabbedViewLocation}
 * @unrestricted
 */
export class _TabbedLocation extends _Location implements TabbedViewLocation {
    /**
     * @param {!ViewManager} manager
     * @param {function():void=} revealCallback
     * @param {string=} location
     * @param {boolean=} restoreSelection
     * @param {boolean=} allowReorder
     * @param {?string=} defaultTab
     */
    constructor(manager: ViewManager, revealCallback?: (() => void) | undefined, location?: string | undefined, restoreSelection?: boolean | undefined, allowReorder?: boolean | undefined, defaultTab?: (string | null) | undefined);
    _tabbedPane: TabbedPane;
    _allowReorder: boolean | undefined;
    _closeableTabSetting: Common.Settings.Setting<any>;
    _tabOrderSetting: Common.Settings.Setting<any>;
    _lastSelectedTabSetting: Common.Settings.Setting<any>;
    _defaultTab: string | null | undefined;
    /** @type {!Map.<string, !View>} */
    _views: Map<string, View>;
    _setOrUpdateCloseableTabsSetting(): void;
    /**
     * @override
     * @return {!TabbedPane}
     */
    tabbedPane(): TabbedPane;
    /**
     * @override
     * @return {!ToolbarMenuButton}
     */
    enableMoreTabsButton(): ToolbarMenuButton;
    /**
     * @override
     * @param {string} locationName
     */
    appendApplicableItems(locationName: string): void;
    /**
     * @param {!ContextMenu} contextMenu
     */
    _appendTabsToMenu(contextMenu: ContextMenu): void;
    /**
     * @param {!View} view
     * @param {number=} index
     */
    _appendTab(view: View, index?: number | undefined): void;
    /**
     * @override
     * @param {!View} view
     * @param {?View=} insertBefore
     */
    appendView(view: View, insertBefore?: (View | null) | undefined): void;
    /**
     * @override
     * @param {!View} view
     * @param {?View=} insertBefore
     * @param {boolean=} userGesture
     * @param {boolean=} omitFocus
     * @return {!Promise<*>}
     */
    showView(view: View, insertBefore?: (View | null) | undefined, userGesture?: boolean | undefined, omitFocus?: boolean | undefined): Promise<any>;
    /**
     * @param {!View} view
     * @override
     */
    removeView(view: View): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _tabSelected(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _tabClosed(event: Common.EventTarget.EventTargetEvent): void;
    _persistTabOrder(): void;
}
export namespace _TabbedLocation {
    export const orderStep: number;
}
import { View } from "./View.js";
import * as Common from "../common/common.js";
import { Widget } from "./Widget.js";
/**
 * @unrestricted
 */
declare class _Location {
    /**
     * @param {!ViewManager} manager
     * @param {!Widget} widget
     * @param {function():void=} revealCallback
     */
    constructor(manager: ViewManager, widget: Widget, revealCallback?: (() => void) | undefined);
    _manager: ViewManager;
    _revealCallback: (() => void) | undefined;
    _widget: Widget;
    /**
     * @return {!Widget}
     */
    widget(): Widget;
    _reveal(): void;
}
declare namespace _Location {
    export const symbol: symbol;
}
import { TabbedViewLocation } from "./View.js";
import { ViewLocation } from "./View.js";
import { ToolbarItem } from "./Toolbar.js";
import { VBox } from "./Widget.js";
import { Icon } from "./Icon.js";
import { TabbedPane } from "./TabbedPane.js";
import { ToolbarMenuButton } from "./Toolbar.js";
import { ContextMenu } from "./ContextMenu.js";
export {};
