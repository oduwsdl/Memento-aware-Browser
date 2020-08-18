/**
 * @template T
 * @interface
 */
export class ListDelegate<T> {
    /**
     * @param {T} item
     * @return {!Element}
     */
    createElementForItem(item: T): Element;
    /**
     * This method is not called in NonViewport mode.
     * Return zero to make list measure the item (only works in SameHeight mode).
     * @param {T} item
     * @return {number}
     */
    heightForItem(item: T): number;
    /**
     * @param {T} item
     * @return {boolean}
     */
    isItemSelectable(item: T): boolean;
    /**
     * @param {?T} from
     * @param {?T} to
     * @param {?Element} fromElement
     * @param {?Element} toElement
     */
    selectedItemChanged(from: T | null, to: T | null, fromElement: Element | null, toElement: Element | null): void;
    /**
     * @param {?Element} fromElement
     * @param {?Element} toElement
     * @return {boolean}
     */
    updateSelectedItemARIA(fromElement: Element | null, toElement: Element | null): boolean;
}
export type ListMode = symbol;
export namespace ListMode {
    export const NonViewport: symbol;
    export const EqualHeightItems: symbol;
    export const VariousHeightItems: symbol;
}
/**
 * @template T
 */
export class ListControl<T> {
    /**
     * @param {!ListModel<T>} model
     * @param {!ListDelegate<T>} delegate
     * @param {!ListMode=} mode
     */
    constructor(model: ListModel<T>, delegate: ListDelegate<T>, mode?: ListMode | undefined);
    element: any;
    _topElement: any;
    _bottomElement: any;
    _firstIndex: number;
    _lastIndex: number;
    _renderedHeight: number;
    _topHeight: any;
    _bottomHeight: any;
    _model: ListModel<T>;
    /** @type {!Map<T, !Element>} */
    _itemToElement: Map<T, Element>;
    _selectedIndex: number;
    /** @type {?T} */
    _selectedItem: T | null;
    _delegate: ListDelegate<T>;
    _mode: symbol;
    _fixedHeight: number;
    _variableOffsets: any;
    /**
     * @param {!ListModel<T>} model
     */
    setModel(model: ListModel<T>): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _replacedItemsInRange(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {T} item
     */
    refreshItem(item: T): void;
    /**
     * @param {number} index
     */
    refreshItemByIndex(index: number): void;
    /**
     * @param {number} from
     * @param {number} to
     */
    invalidateRange(from: number, to: number): void;
    viewportResized(): void;
    invalidateItemHeight(): void;
    /**
     * @param {?Node} node
     * @return {?T}
     */
    itemForNode(node: Node | null): T | null;
    /**
     * @param {T} item
     * @param {boolean=} center
     */
    scrollItemIntoView(item: T, center?: boolean | undefined): void;
    /**
     * @return {?T}
     */
    selectedItem(): T | null;
    /**
     * @return {number}
     */
    selectedIndex(): number;
    /**
     * @param {?T} item
     * @param {boolean=} center
     * @param {boolean=} dontScroll
     */
    selectItem(item: T | null, center?: boolean | undefined, dontScroll?: boolean | undefined): void;
    /**
     * @param {boolean=} canWrap
     * @param {boolean=} center
     * @return {boolean}
     */
    selectPreviousItem(canWrap?: boolean | undefined, center?: boolean | undefined): boolean;
    /**
     * @param {boolean=} canWrap
     * @param {boolean=} center
     * @return {boolean}
     */
    selectNextItem(canWrap?: boolean | undefined, center?: boolean | undefined): boolean;
    /**
     * @param {boolean=} center
     * @return {boolean}
     */
    selectItemPreviousPage(center?: boolean | undefined): boolean;
    /**
     * @param {boolean=} center
     * @return {boolean}
     */
    selectItemNextPage(center?: boolean | undefined): boolean;
    /**
     * @param {number} index
     * @param {boolean=} center
     */
    _scrollIntoView(index: number, center?: boolean | undefined): void;
    /**
     * @param {!Event} event
     */
    _onClick(event: Event): void;
    /**
     * @param {!Event} event
     */
    _onKeyDown(event: Event): void;
    /**
     * @return {number}
     */
    _totalHeight(): number;
    /**
     * @param {number} offset
     * @return {number}
     */
    _indexAtOffset(offset: number): number;
    /**
     * @param {number} index
     * @return {!Element}
     */
    _elementAtIndex(index: number): Element;
    _refreshARIA(): void;
    /**
     * @param {!Element} element
     * @param {number} index
     */
    _updateElementARIA(element: Element, index: number): void;
    /**
     * @param {number} index
     * @return {number}
     */
    _offsetAtIndex(index: number): number;
    _measureHeight(): void;
    /**
     * @param {number} index
     * @param {?T=} oldItem
     * @param {?Element=} oldElement
     */
    _select(index: number, oldItem?: T | null | undefined, oldElement?: (Element | null) | undefined): void;
    /**
     * @param {number} index
     * @param {number} direction
     * @param {boolean} canWrap
     * @return {number}
     */
    _findFirstSelectable(index: number, direction: number, canWrap: boolean): number;
    /**
     * @param {number} index
     * @param {number} direction
     * @return {number}
     */
    _findPageSelectable(index: number, direction: number): number;
    /**
     * @param {number} length
     * @param {number} copyTo
     */
    _reallocateVariableOffsets(length: number, copyTo: number): void;
    /**
     * @param {number} from
     * @param {number} to
     * @param {number} inserted
     */
    _invalidate(from: number, to: number, inserted: number): void;
    /**
     * @param {number} start
     * @param {number} remove
     * @param {number} add
     */
    _invalidateNonViewportMode(start: number, remove: number, add: number): void;
    _clearViewport(): void;
    _clearContents(): void;
    /**
     * @param {number} scrollTop
     * @param {number} viewportHeight
     */
    _updateViewport(scrollTop: number, viewportHeight: number): void;
}
import { ListModel } from "./ListModel.js";
import * as Common from "../common/common.js";
