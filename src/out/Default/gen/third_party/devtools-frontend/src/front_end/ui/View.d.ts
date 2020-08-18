/**
 * @interface
 */
export class View {
    /**
     * @return {string}
     */
    viewId(): string;
    /**
     * @return {string}
     */
    title(): string;
    /**
     * @return {boolean}
     */
    isCloseable(): boolean;
    /**
     * @return {boolean}
     */
    isTransient(): boolean;
    /**
     * @return {!Promise<!Array<!ToolbarItem>>}
     */
    toolbarItems(): Promise<Array<ToolbarItem>>;
    /**
     * @return {!Promise<!Widget>}
     */
    widget(): Promise<Widget>;
    /**
     * @return {!Promise<void>|void}
     */
    disposeView(): Promise<void> | void;
}
export const _symbol: unique symbol;
export const _widgetSymbol: unique symbol;
export const widgetSymbol: symbol;
/**
 * @implements {View}
 * @unrestricted
 */
export class SimpleView extends VBox implements View {
    /**
     * @param {string} title
     * @param {boolean=} isWebComponent
     */
    constructor(title: string, isWebComponent?: boolean | undefined);
    _title: string;
    /**
     * @override
     * @return {string}
     */
    viewId(): string;
    /**
     * @override
     * @return {string}
     */
    title(): string;
    /**
     * @override
     * @return {boolean}
     */
    isCloseable(): boolean;
    /**
     * @override
     * @return {boolean}
     */
    isTransient(): boolean;
    /**
     * @override
     * @return {!Promise<!Array<!ToolbarItem>>}
     */
    toolbarItems(): Promise<Array<ToolbarItem>>;
    /**
     * @override
     * @return {!Promise<!Widget>}
     */
    widget(): Promise<Widget>;
    /**
     * @return {!Promise<void>}
     */
    revealView(): Promise<void>;
    /**
     * @override
     */
    disposeView(): void;
    [_symbol]: SimpleView;
}
/**
 * @implements {View}
 * @unrestricted
 */
export class ProvidedView implements View {
    /**
     * @param {!Root.Runtime.Extension} extension
     */
    constructor(extension: any);
    _extension: any;
    /**
     * @override
     * @return {string}
     */
    viewId(): string;
    /**
     * @override
     * @return {string}
     */
    title(): string;
    /**
     * @override
     * @return {boolean}
     */
    isCloseable(): boolean;
    /**
     * @override
     * @return {boolean}
     */
    isTransient(): boolean;
    /**
     * @override
     * @return {!Promise<!Array<!ToolbarItem>>}
     */
    toolbarItems(): Promise<Array<ToolbarItem>>;
    /**
     * @override
     * @return {!Promise<!Widget>}
     */
    widget(): Promise<Widget>;
    _widgetRequested: boolean | undefined;
    /**
     * @override
     */
    disposeView(): Promise<void>;
}
/**
 * @interface
 */
export class ViewLocation {
    /**
     * @param {string} locationName
     */
    appendApplicableItems(locationName: string): void;
    /**
     * @param {!View} view
     * @param {?View=} insertBefore
     */
    appendView(view: View, insertBefore?: (View | null) | undefined): void;
    /**
     * @param {!View} view
     * @param {?View=} insertBefore
     * @param {boolean=} userGesture
     * @return {!Promise<*>}
     */
    showView(view: View, insertBefore?: (View | null) | undefined, userGesture?: boolean | undefined): Promise<any>;
    /**
     * @param {!View} view
     */
    removeView(view: View): void;
    /**
     * @return {!Widget}
     */
    widget(): Widget;
}
/**
 * @interface
 */
export class TabbedViewLocation extends ViewLocation {
    /**
     * @return {!TabbedPane}
     */
    tabbedPane(): TabbedPane;
    /**
     * @return {!ToolbarMenuButton}
     */
    enableMoreTabsButton(): ToolbarMenuButton;
}
/**
 * @interface
 */
export class ViewLocationResolver {
    /**
     * @param {string} location
     * @return {?ViewLocation}
     */
    resolveLocation(location: string): ViewLocation | null;
}
import { ToolbarItem } from "./Toolbar.js";
import { Widget } from "./Widget.js";
import { VBox } from "./Widget.js";
import { TabbedPane } from "./TabbedPane.js";
import { ToolbarMenuButton } from "./Toolbar.js";
