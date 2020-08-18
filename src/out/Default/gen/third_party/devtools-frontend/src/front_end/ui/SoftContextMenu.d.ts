/**
 * @unrestricted
 */
export class SoftContextMenu {
    /**
     * @param {!Array.<!InspectorFrontendHostAPI.ContextMenuDescriptor>} items
     * @param {function(string):void} itemSelectedCallback
     * @param {!SoftContextMenu=} parentMenu
     */
    constructor(items: Array<any>, itemSelectedCallback: (arg0: string) => void, parentMenu?: SoftContextMenu | undefined);
    _items: any[];
    _itemSelectedCallback: (arg0: string) => void;
    _parentMenu: SoftContextMenu | undefined;
    /** @type {?Element} */
    _highlightedMenuItemElement: Element | null;
    /**
     * @param {!Document} document
     * @param {!AnchorBox} anchorBox
     */
    show(document: Document, anchorBox: AnchorBox): void;
    _document: Document | undefined;
    _glassPane: GlassPane | undefined;
    _contextMenuElement: HTMLElement | undefined;
    _focusRestorer: ElementFocusRestorer | undefined;
    _hideOnUserGesture: ((event: any) => void) | undefined;
    discard(): void;
    _createMenuItem(item: any): HTMLDivElement;
    _createSubMenu(item: any): HTMLDivElement;
    _createSeparator(): HTMLDivElement;
    _menuItemMouseDown(event: any): void;
    _menuItemMouseUp(event: any): void;
    /**
     * @return {!SoftContextMenu}
     */
    _root(): SoftContextMenu;
    _triggerAction(menuItemElement: any, event: any): void;
    _showSubMenu(menuItemElement: any): void;
    _activeSubMenuElement: any;
    _subMenu: SoftContextMenu | undefined;
    _menuItemMouseOver(event: any): void;
    _menuItemMouseLeave(event: any): void;
    /**
     * @param {?Element} menuItemElement
     * @param {boolean} scheduleSubMenu
     */
    _highlightMenuItem(menuItemElement: Element | null, scheduleSubMenu: boolean): void;
    _highlightPrevious(): void;
    _highlightNext(): void;
    _menuKeyDown(event: any): void;
}
import { GlassPane } from "./GlassPane.js";
import { ElementFocusRestorer } from "./UIUtils.js";
