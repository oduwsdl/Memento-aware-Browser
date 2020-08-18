export class Panel extends VBox {
    /**
     * @param {string} name
     */
    constructor(name: string);
    _panelName: string;
    get name(): string;
    /**
     * @return {?SearchableView}
     */
    searchableView(): SearchableView | null;
}
/**
 * @unrestricted
 */
export class PanelWithSidebar extends Panel {
    /**
     * @param {string} name
     * @param {number=} defaultWidth
     */
    constructor(name: string, defaultWidth?: number | undefined);
    _panelSplitWidget: SplitWidget;
    _mainWidget: VBox;
    _sidebarWidget: VBox;
    /**
     * @return {!Element}
     */
    panelSidebarElement(): Element;
    /**
     * @return {!Element}
     */
    mainElement(): Element;
    /**
     * @return {!SplitWidget}
     */
    splitWidget(): SplitWidget;
}
import { VBox } from "./Widget.js";
import { SearchableView } from "./SearchableView.js";
import { SplitWidget } from "./SplitWidget.js";
