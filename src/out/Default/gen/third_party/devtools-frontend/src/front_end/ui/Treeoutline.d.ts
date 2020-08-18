/**
 * @unrestricted
 */
export class TreeOutline extends Common.ObjectWrapper.ObjectWrapper {
    /** @type {?TreeElement} */
    selectedTreeElement: TreeElement | null;
    expandTreeElementsWhenArrowing: boolean;
    /** @type {?function(!TreeElement, !TreeElement):number} */
    _comparator: ((arg0: TreeElement, arg1: TreeElement) => number) | null;
    contentElement: any;
    _preventTabOrder: boolean;
    _showSelectionOnKeyboardFocus: boolean;
    element: any;
    /**
     * @param {boolean} show
     * @param {boolean=} preventTabOrder
     */
    setShowSelectionOnKeyboardFocus(show: boolean, preventTabOrder?: boolean | undefined): void;
    _createRootElement(): void;
    _rootElement: TreeElement | undefined;
    /**
     * @return {!TreeElement}
     */
    rootElement(): TreeElement;
    /**
     * @return {?TreeElement}
     */
    firstChild(): TreeElement | null;
    /**
     * @return {?TreeElement}
     */
    _lastDescendent(): TreeElement | null;
    /**
     * @param {!TreeElement} child
     */
    appendChild(child: TreeElement): void;
    /**
     * @param {!TreeElement} child
     * @param {number} index
     */
    insertChild(child: TreeElement, index: number): void;
    /**
     * @param {!TreeElement} child
     */
    removeChild(child: TreeElement): void;
    removeChildren(): void;
    /**
     * @param {number} x
     * @param {number} y
     * @return {?TreeElement}
     */
    treeElementFromPoint(x: number, y: number): TreeElement | null;
    /**
     * @param {?Event} event
     * @return {?TreeElement}
     */
    treeElementFromEvent(event: Event | null): TreeElement | null;
    /**
     * @param {?function(!TreeElement, !TreeElement):number} comparator
     */
    setComparator(comparator: ((arg0: TreeElement, arg1: TreeElement) => number) | null): void;
    /**
     * @param {boolean} focusable
     */
    setFocusable(focusable: boolean): void;
    _focusable: boolean | undefined;
    updateFocusable(): void;
    focus(): void;
    useLightSelectionColor(): void;
    _useLightSelectionColor: boolean | undefined;
    /**
     * @param {!TreeElement} element
     */
    _bindTreeElement(element: TreeElement): void;
    /**
     * @param {!TreeElement} element
     */
    _unbindTreeElement(element: TreeElement): void;
    /**
     * @return {boolean}
     */
    selectPrevious(): boolean;
    /**
     * @return {boolean}
     */
    selectNext(): boolean;
    /**
     * @param {boolean=} omitFocus
     * @param {boolean=} selectedByUser
     */
    forceSelect(omitFocus?: boolean | undefined, selectedByUser?: boolean | undefined): void;
    /**
     * @param {boolean=} omitFocus
     * @param {boolean=} selectedByUser
     * @return {boolean}
     */
    _selectFirst(omitFocus?: boolean | undefined, selectedByUser?: boolean | undefined): boolean;
    /**
     * @return {boolean}
     */
    _selectLast(): boolean;
    /**
     * @param {!Event} event
     */
    _treeKeyDown(event: Event): void;
    /**
     * @param {!TreeElement} treeElement
     * @param {boolean} center
     */
    _deferredScrollIntoView(treeElement: TreeElement, center: boolean): void;
    _treeElementToScrollIntoView: TreeElement | undefined;
    _centerUponScrollIntoView: boolean | undefined;
}
export type Events = symbol;
export namespace Events {
    export const ElementAttached: symbol;
    export const ElementsDetached: symbol;
    export const ElementExpanded: symbol;
    export const ElementCollapsed: symbol;
    export const ElementSelected: symbol;
}
/**
 * @unrestricted
 */
export class TreeOutlineInShadow extends TreeOutline {
    _shadowRoot: DocumentFragment;
    _disclosureElement: any;
    _renderSelection: boolean;
    /**
     * @param {string} cssFile
     */
    registerRequiredCSS(cssFile: string): void;
    hideOverflow(): void;
    makeDense(): void;
}
/**
 * @unrestricted
 */
export class TreeElement {
    /**
     * @param {(string|!Node)=} title
     * @param {boolean=} expandable
     */
    constructor(title?: (string | Node) | undefined, expandable?: boolean | undefined);
    /** @type {?TreeOutline} */
    treeOutline: TreeOutline | null;
    parent: any;
    previousSibling: any;
    nextSibling: any;
    _boundOnFocus: () => void;
    _boundOnBlur: () => void;
    _listItemNode: any;
    /** @protected */
    protected titleElement: any;
    /**
     * @param {string|!Node} x
     */
    set title(arg: string | Node);
    /**
     * @return {string|!Node}
     */
    get title(): string | Node;
    _childrenListNode: any;
    _hidden: any;
    _selectable: any;
    expanded: boolean;
    selected: boolean;
    _collapsible: any;
    /**
     * @param {?TreeElement} ancestor
     * @return {boolean}
     */
    hasAncestor(ancestor: TreeElement | null): boolean;
    /**
     * @param {?TreeElement} ancestor
     * @return {boolean}
     */
    hasAncestorOrSelf(ancestor: TreeElement | null): boolean;
    /**
     * @return {boolean}
     */
    isHidden(): boolean;
    /**
     * @return {!Array.<!TreeElement>}
     */
    children(): Array<TreeElement>;
    /**
     * @return {number}
     */
    childCount(): number;
    /**
     * @return {?TreeElement}
     */
    firstChild(): TreeElement | null;
    /**
     * @return {?TreeElement}
     */
    lastChild(): TreeElement | null;
    /**
     * @param {number} index
     * @return {?TreeElement}
     */
    childAt(index: number): TreeElement | null;
    /**
     * @param {!TreeElement} child
     * @return {number}
     */
    indexOfChild(child: TreeElement): number;
    /**
     * @param {!TreeElement} child
     */
    appendChild(child: TreeElement): void;
    _children: any[] | null | undefined;
    /**
     * @param {!TreeElement} child
     * @param {number} index
     */
    insertChild(child: TreeElement, index: number): void;
    /**
     * @param {number} childIndex
     */
    removeChildAtIndex(childIndex: number): void;
    /**
     * @param {!TreeElement} child
     */
    removeChild(child: TreeElement): void;
    removeChildren(): void;
    set selectable(arg: any);
    get selectable(): any;
    get listItemElement(): any;
    get childrenListElement(): any;
    _title: any;
    /**
     * @param {string} x
     */
    set tooltip(arg: string);
    /**
     * @return {string}
     */
    get tooltip(): string;
    /**
     * @return {string}
     */
    titleAsText(): string;
    /**
     * @param {!Config<*>} editingConfig
     */
    startEditingTitle(editingConfig: Config<any>): void;
    /**
     * @param {!Array<!Icon>} icons
     */
    setLeadingIcons(icons: Array<Icon>): void;
    _leadingIconsElement: HTMLDivElement | undefined;
    /**
     * @param {!Array<!Icon>} icons
     */
    setTrailingIcons(icons: Array<Icon>): void;
    _trailingIconsElement: HTMLDivElement | undefined;
    _tooltip: any;
    /**
     * @return {boolean}
     */
    isExpandable(): boolean;
    /**
     * @param {boolean} expandable
     */
    setExpandable(expandable: boolean): void;
    _expandable: any;
    /**
     * @param {boolean} collapsible
     */
    setCollapsible(collapsible: boolean): void;
    set hidden(arg: any);
    get hidden(): any;
    invalidateChildren(): void;
    _ensureSelection(): void;
    _selectionElement: HTMLDivElement | undefined;
    /**
     * @param {!Event} event
     */
    _treeElementToggled(event: Event): void;
    /**
     * @param {!Event} event
     */
    _handleMouseDown(event: Event): void;
    /**
     * @param {!Event} event
     */
    _handleDoubleClick(event: Event): void;
    _detach(): void;
    collapse(): void;
    collapseRecursively(): void;
    collapseChildren(): void;
    expand(): void;
    /**
     * @param {number=} maxDepth
     * @returns {!Promise<void>}
     */
    expandRecursively(maxDepth?: number | undefined): Promise<void>;
    /**
     * @param {boolean} altKey
     * @return {boolean}
     */
    collapseOrAscend(altKey: boolean): boolean;
    /**
     * @param {boolean} altKey
     * @return {boolean}
     */
    descendOrExpand(altKey: boolean): boolean;
    /**
     * @param {boolean=} center
     */
    reveal(center?: boolean | undefined): void;
    /**
     * @return {boolean}
     */
    revealed(): boolean;
    selectOnMouseDown(event: any): void;
    /**
     * @param {boolean=} omitFocus
     * @param {boolean=} selectedByUser
     * @return {boolean}
     */
    select(omitFocus?: boolean | undefined, selectedByUser?: boolean | undefined): boolean;
    /**
     * @param {boolean} focusable
     */
    _setFocusable(focusable: boolean): void;
    _onFocus(): void;
    _onBlur(): void;
    /**
     * @param {boolean=} omitFocus
     */
    revealAndSelect(omitFocus?: boolean | undefined): void;
    deselect(): void;
    /**
     * @returns {!Promise<void>}
     */
    _populateIfNeeded(): Promise<void>;
    /**
     * @return {!Promise<void>}
     */
    onpopulate(): Promise<void>;
    /**
     * @return {boolean}
     */
    onenter(): boolean;
    /**
     * @return {boolean}
     */
    ondelete(): boolean;
    /**
     * @return {boolean}
     */
    onspace(): boolean;
    onbind(): void;
    onunbind(): void;
    onattach(): void;
    onexpand(): void;
    oncollapse(): void;
    /**
     * @param {!Event} e
     * @return {boolean}
     */
    ondblclick(e: Event): boolean;
    /**
     * @param {boolean=} selectedByUser
     * @return {boolean}
     */
    onselect(selectedByUser?: boolean | undefined): boolean;
    /**
     * @param {boolean} skipUnrevealed
     * @param {?TreeElement=} stayWithin
     * @param {boolean=} dontPopulate
     * @param {!Object=} info
     * @return {?TreeElement}
     */
    traverseNextTreeElement(skipUnrevealed: boolean, stayWithin?: (TreeElement | null) | undefined, dontPopulate?: boolean | undefined, info?: Object | undefined): TreeElement | null;
    /**
     * @param {boolean} skipUnrevealed
     * @param {boolean=} dontPopulate
     * @return {?TreeElement}
     */
    traversePreviousTreeElement(skipUnrevealed: boolean, dontPopulate?: boolean | undefined): TreeElement | null;
    /**
     * @return {boolean}
     */
    isEventWithinDisclosureTriangle(event: any): boolean;
}
export namespace TreeElement {
    export const _ArrowToggleWidth: number;
}
import * as Common from "../common/common.js";
import { Config } from "./InplaceEditor.js";
import { Icon } from "./Icon.js";
