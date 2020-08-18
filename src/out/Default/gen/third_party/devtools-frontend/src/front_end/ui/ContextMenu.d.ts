/**
 * @unrestricted
 */
export class Item {
    /**
     * @param {?ContextMenu} contextMenu
     * @param {string} type
     * @param {string=} label
     * @param {boolean=} disabled
     * @param {boolean=} checked
     */
    constructor(contextMenu: ContextMenu | null, type: string, label?: string | undefined, disabled?: boolean | undefined, checked?: boolean | undefined);
    _type: string;
    _label: string | undefined;
    _disabled: boolean | undefined;
    _checked: boolean | undefined;
    _contextMenu: ContextMenu | null;
    _id: number;
    /**
     * @return {number}
     */
    id(): number;
    /**
     * @return {string}
     */
    type(): string;
    /**
     * @return {boolean}
     */
    isEnabled(): boolean;
    /**
     * @param {boolean} enabled
     */
    setEnabled(enabled: boolean): void;
    /**
     * @return {!InspectorFrontendHostAPI.ContextMenuDescriptor}
     */
    _buildDescriptor(): any;
    /**
     * @param {string} shortcut
     */
    setShortcut(shortcut: string): void;
    _shortcut: string | undefined;
}
export namespace Item {
    export const _uniqueSectionName: number;
}
export class Section {
    /**
     * @param {?ContextMenu} contextMenu
     */
    constructor(contextMenu: ContextMenu | null);
    _contextMenu: ContextMenu | null;
    /** @type {!Array<!Item>} */
    _items: Array<Item>;
    /**
     * @param {string} label
     * @param {function(?):*} handler
     * @param {boolean=} disabled
     * @return {!Item}
     */
    appendItem(label: string, handler: (arg0: unknown) => any, disabled?: boolean | undefined): Item;
    /**
     * @param {!Element} element
     * @return {!Item}
     */
    appendCustomItem(element: Element): Item;
    /**
     * @return {!Item}
     */
    appendSeparator(): Item;
    /**
     * @param {string} actionId
     * @param {string=} label
     * @param {boolean=} optional
     */
    appendAction(actionId: string, label?: string | undefined, optional?: boolean | undefined): void;
    /**
     * @param {string} label
     * @param {boolean=} disabled
     * @return {!SubMenu}
     */
    appendSubMenuItem(label: string, disabled?: boolean | undefined): SubMenu;
    /**
     * @param {string} label
     * @param {function():*} handler
     * @param {boolean=} checked
     * @param {boolean=} disabled
     * @return {!Item}
     */
    appendCheckboxItem(label: string, handler: () => any, checked?: boolean | undefined, disabled?: boolean | undefined): Item;
}
export class SubMenu extends Item {
    /**
     * @param {?ContextMenu} contextMenu
     * @param {string=} label
     * @param {boolean=} disabled
     */
    constructor(contextMenu: ContextMenu | null, label?: string | undefined, disabled?: boolean | undefined);
    /** @type {!Map<string, !Section>} */
    _sections: Map<string, Section>;
    /** @type {!Array<!Section>} */
    _sectionList: Array<Section>;
    _init(): void;
    /**
     * @param {string=} name
     * @return {!Section}
     */
    section(name?: string | undefined): Section;
    /**
     * @return {!Section}
     */
    headerSection(): Section;
    /**
     * @return {!Section}
     */
    newSection(): Section;
    /**
     * @return {!Section}
     */
    revealSection(): Section;
    /**
     * @return {!Section}
     */
    clipboardSection(): Section;
    /**
     * @return {!Section}
     */
    editSection(): Section;
    /**
     * @return {!Section}
     */
    debugSection(): Section;
    /**
     * @return {!Section}
     */
    viewSection(): Section;
    /**
     * @return {!Section}
     */
    defaultSection(): Section;
    /**
     * @return {!Section}
     */
    saveSection(): Section;
    /**
     * @return {!Section}
     */
    footerSection(): Section;
    /**
     * @param {string} location
     */
    appendItemsAtLocation(location: string): void;
}
/**
 * @unrestricted
 */
export class ContextMenu extends SubMenu {
    static initialize(): void;
    /**
     * @param {!Document} doc
     */
    static installHandler(doc: Document): void;
    /**
     * @param {!Event} event
     * @param {boolean=} useSoftMenu
     * @param {number=} x
     * @param {number=} y
     */
    constructor(event: Event, useSoftMenu?: boolean | undefined, x?: number | undefined, y?: number | undefined);
    _defaultSection: Section;
    /** @type {!Array.<!Promise.<!Array.<!Provider>>>} */
    _pendingPromises: Array<Promise<Array<Provider>>>;
    /** @type {!Array<!Object>} */
    _pendingTargets: Array<Object>;
    _event: Event;
    _useSoftMenu: boolean;
    _x: any;
    _y: any;
    _handlers: {};
    /**
     * @return {number}
     */
    _nextId(): number;
    show(): void;
    discard(): void;
    _innerShow(): void;
    _softMenu: SoftContextMenu | undefined;
    /**
     * @param {number} x
     */
    setX(x: number): void;
    /**
     * @param {number} y
     */
    setY(y: number): void;
    /**
     * @param {number} id
     * @param {function(?):*} handler
     */
    _setHandler(id: number, handler: (arg0: unknown) => any): void;
    /**
     * @return {!Array.<!InspectorFrontendHostAPI.ContextMenuDescriptor>}
     */
    _buildMenuDescriptors(): Array<any>;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onItemSelected(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {string} id
     */
    _itemSelected(id: string): void;
    _menuCleared(): void;
    /**
     * @param {!Object} target
     * @return {boolean}
     */
    containsTarget(target: Object): boolean;
    /**
     * @param {!Object} target
     */
    appendApplicableItems(target: Object): void;
}
export namespace ContextMenu {
    export { _groupWeights };
}
export const _groupWeights: string[];
/**
 * @interface
 */
export class Provider {
    /**
     * @param {!Event} event
     * @param {!ContextMenu} contextMenu
     * @param {!Object} target
     */
    appendApplicableItems(event: Event, contextMenu: ContextMenu, target: Object): void;
}
import { SoftContextMenu } from "./SoftContextMenu.js";
import * as Common from "../common/common.js";
