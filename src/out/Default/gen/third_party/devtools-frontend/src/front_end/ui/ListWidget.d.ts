/**
 * @template T
 */
export class ListWidget<T> extends VBox {
    /**
     * @param {!Delegate<T>} delegate
     * @param {boolean=} delegatesFocus
     */
    constructor(delegate: Delegate<T>, delegatesFocus?: boolean | undefined);
    _delegate: Delegate<T>;
    _list: HTMLElement;
    _lastSeparator: boolean;
    /** @type {?ElementFocusRestorer} */
    _focusRestorer: ElementFocusRestorer | null;
    /** @type {!Array<T>} */
    _items: T[];
    /** @type {!Array<boolean>} */
    _editable: Array<boolean>;
    /** @type {!Array<!Element>} */
    _elements: Array<Element>;
    /** @type {?Editor<T>} */
    _editor: Editor<T> | null;
    /** @type {?T} */
    _editItem: T | null;
    /** @type {?Element} */
    _editElement: Element | null;
    /** @type {?Element} */
    _emptyPlaceholder: Element | null;
    clear(): void;
    /**
     * @param {!T} item
     * @param {boolean} editable
     */
    appendItem(item: T, editable: boolean): void;
    appendSeparator(): void;
    /**
     * @param {number} index
     */
    removeItem(index: number): void;
    /**
     * @param {number} index
     * @param {!T} item
     */
    addNewItem(index: number, item: T): void;
    /**
     * @param {?Element} element
     */
    setEmptyPlaceholder(element: Element | null): void;
    /**
     * @param {!T} item
     * @param {!Element} element
     * @return {!Element}
     */
    _createControls(item: T, element: Element): Element;
    _updatePlaceholder(): void;
    /**
     * @param {!T} item
     * @param {?Element} element
     * @param {?Element} insertionPoint
     */
    _startEditing(item: T, element: Element | null, insertionPoint: Element | null): void;
    _commitEditing(): void;
    _stopEditing(): void;
}
/**
 * @template T
 * @interface
 */
export class Delegate<T> {
    /**
     * @param {!T} item
     * @param {boolean} editable
     * @return {!Element}
     */
    renderItem(item: T, editable: boolean): Element;
    /**
     * @param {!T} item
     * @param {number} index
     */
    removeItemRequested(item: T, index: number): void;
    /**
     * @param {!T} item
     * @return {!Editor<T>}
     */
    beginEdit(item: T): Editor<T>;
    /**
     * @param {!T} item
     * @param {!Editor<T>} editor
     * @param {boolean} isNew
     */
    commitEdit(item: T, editor: Editor<T>, isNew: boolean): void;
}
/**
 * @template T
 */
export class Editor<T> {
    element: HTMLDivElement;
    _contentElement: HTMLElement;
    _commitButton: Element;
    _cancelButton: Element;
    _errorMessageContainer: HTMLElement;
    /** @type {!Array<!HTMLInputElement|!HTMLSelectElement>} */
    _controls: Array<HTMLInputElement | HTMLSelectElement>;
    /** @type {!Map<string, !HTMLInputElement|!HTMLSelectElement>} */
    _controlByName: Map<string, HTMLInputElement | HTMLSelectElement>;
    /** @type {!Array<function(!T, number, (!HTMLInputElement|!HTMLSelectElement)): !ValidatorResult>} */
    _validators: ((arg0: T, arg1: number, arg2: (HTMLInputElement | HTMLSelectElement)) => ValidatorResult)[];
    /** @type {?function():void} */
    _commit: (() => void) | null;
    /** @type {?function():void} */
    _cancel: (() => void) | null;
    /** @type {?T} */
    _item: T | null;
    /** @type {number} */
    _index: number;
    /**
     * @return {!Element}
     */
    contentElement(): Element;
    /**
     * @param {string} name
     * @param {string} type
     * @param {string} title
     * @param {function(!T, number, (!HTMLInputElement|!HTMLSelectElement)): !ValidatorResult} validator
     * @return {!HTMLInputElement}
     */
    createInput(name: string, type: string, title: string, validator: (arg0: T, arg1: number, arg2: (HTMLInputElement | HTMLSelectElement)) => ValidatorResult): HTMLInputElement;
    /**
     * @param {string} name
     * @param {!Array<string>} options
     * @param {function(!T, number, (!HTMLInputElement|!HTMLSelectElement)): !ValidatorResult} validator
     * @param {string=} title
     * @return {!HTMLSelectElement}
     */
    createSelect(name: string, options: Array<string>, validator: (arg0: T, arg1: number, arg2: (HTMLInputElement | HTMLSelectElement)) => ValidatorResult, title?: string | undefined): HTMLSelectElement;
    /**
     * @param {string} name
     * @return {!HTMLInputElement|!HTMLSelectElement}
     */
    control(name: string): HTMLInputElement | HTMLSelectElement;
    /**
     * @param {boolean} forceValid
     */
    _validateControls(forceValid: boolean): void;
    /**
     * @param {!T} item
     * @param {number} index
     * @param {string} commitButtonTitle
     * @param {function():void} commit
     * @param {function():void} cancel
     */
    beginEdit(item: T, index: number, commitButtonTitle: string, commit: () => void, cancel: () => void): void;
    _commitClicked(): void;
    _cancelClicked(): void;
}
export type ValidatorResult = {
    valid: boolean;
    errorMessage: (string | undefined);
};
/** @typedef {{valid: boolean, errorMessage: (string|undefined)}} */
export let ValidatorResult: any;
import { VBox } from "./Widget.js";
import { ElementFocusRestorer } from "./UIUtils.js";
