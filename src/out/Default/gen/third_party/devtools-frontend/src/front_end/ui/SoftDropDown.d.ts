/**
 * @template T
 * @implements {ListDelegate<T>}
 */
export class SoftDropDown<T> implements ListDelegate<T> {
    /**
     * @param {!ListModel<T>} model
     * @param {!Delegate<T>} delegate
     */
    constructor(model: ListModel<T>, delegate: Delegate<T>);
    _delegate: Delegate<T>;
    _selectedItem: T | null;
    _model: ListModel<T>;
    _placeholderText: string;
    element: HTMLButtonElement;
    _titleElement: HTMLElement;
    _glassPane: GlassPane;
    _list: ListControl<T>;
    _rowHeight: number;
    _width: number;
    _listWasShowing200msAgo: boolean;
    /**
     * @param {!Event} event
     */
    _show(event: Event): void;
    _updateGlasspaneSize(): void;
    /**
     * @param {!Event} event
     */
    _hide(event: Event): void;
    /**
     * @param {!Event} event
     */
    _onKeyDownButton(event: Event): void;
    /**
     * @param {!Event} event
     */
    _onKeyDownList(event: Event): void;
    /**
     * @param {number} width
     */
    setWidth(width: number): void;
    /**
     * @param {number} rowHeight
     */
    setRowHeight(rowHeight: number): void;
    /**
     * @param {string} text
     */
    setPlaceholderText(text: string): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _itemsReplaced(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {?T} item
     */
    selectItem(item: T | null): void;
    /**
     * @override
     * @param {T} item
     * @return {!Element}
     */
    createElementForItem(item: T): Element;
    /**
     * @override
     * @param {T} item
     * @return {number}
     */
    heightForItem(item: T): number;
    /**
     * @override
     * @param {T} item
     * @return {boolean}
     */
    isItemSelectable(item: T): boolean;
    /**
     * @override
     * @param {?T} from
     * @param {?T} to
     * @param {?Element} fromElement
     * @param {?Element} toElement
     */
    selectedItemChanged(from: T | null, to: T | null, fromElement: Element | null, toElement: Element | null): void;
    /**
     * @override
     * @param {?Element} fromElement
     * @param {?Element} toElement
     * @return {boolean}
     */
    updateSelectedItemARIA(fromElement: Element | null, toElement: Element | null): boolean;
    _selectHighlightedItem(): void;
    /**
     * @param {T} item
     */
    refreshItem(item: T): void;
}
/**
 * @interface
 * @template T
 */
export class Delegate<T> {
    /**
     * @param {T} item
     * @return {string}
     */
    titleFor(item: T): string;
    /**
     * @param {T} item
     * @return {!Element}
     */
    createElementForItem(item: T): Element;
    /**
     * @param {T} item
     * @return {boolean}
     */
    isItemSelectable(item: T): boolean;
    /**
     * @param {?T} item
     */
    itemSelected(item: T | null): void;
    /**
     * @param {?T} from
     * @param {?T} to
     * @param {?Element} fromElement
     * @param {?Element} toElement
     */
    highlightedItemChanged(from: T | null, to: T | null, fromElement: Element | null, toElement: Element | null): void;
}
import { ListDelegate } from "./ListControl.js";
import { ListModel } from "./ListModel.js";
import { GlassPane } from "./GlassPane.js";
import { ListControl } from "./ListControl.js";
import * as Common from "../common/common.js";
