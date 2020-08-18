/**
 * @unrestricted
 */
export class FilterBar extends HBox {
    /**
     * @param {string} name
     * @param {boolean=} visibleByDefault
     */
    constructor(name: string, visibleByDefault?: boolean | undefined);
    _enabled: boolean;
    _stateSetting: Common.Settings.Setting<any>;
    _filterButton: ToolbarSettingToggle;
    _filters: any[];
    /**
     * @return {!ToolbarButton}
     */
    filterButton(): ToolbarButton;
    /**
     * @param {!FilterUI} filter
     */
    addFilter(filter: FilterUI): void;
    setEnabled(enabled: any): void;
    forceShowFilterBar(): void;
    _alwaysShowFilters: boolean | undefined;
    showOnce(): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _filterChanged(event: Common.EventTarget.EventTargetEvent): void;
    _updateFilterBar(): void;
    _showingWidget: boolean | undefined;
    _updateFilterButton(): void;
    clear(): void;
    setting(): Common.Settings.Setting<any>;
    visible(): boolean;
}
export namespace FilterBar {
    export namespace Events {
        export const Changed: symbol;
    }
}
/**
 * @interface
 */
export class FilterUI extends Common.EventTarget.EventTarget {
    /**
     * @return {boolean}
     */
    isActive(): boolean;
    /**
     * @return {!Element}
     */
    element(): Element;
}
export namespace FilterUI {
    export namespace Events {
        export const FilterChanged: symbol;
    }
    export type Events = symbol;
}
/**
 * @implements {FilterUI}
 * @unrestricted
 */
export class TextFilterUI extends Common.ObjectWrapper.ObjectWrapper implements FilterUI {
    _filterElement: any;
    _filterInputElement: any;
    _prompt: TextPrompt;
    _proxyElement: Element;
    /** @type {?function(string, string, boolean=):!Promise<!Suggestions>} */
    _suggestionProvider: ((arg0: string, arg1: string, arg2?: boolean | undefined) => Promise<Suggestions>) | null;
    /**
     * @param {string} expression
     * @param {string} prefix
     * @param {boolean=} force
     * @return {!Promise<!Suggestions>}
     */
    _completions(expression: string, prefix: string, force?: boolean | undefined): Promise<Suggestions>;
    /**
     * @override
     * @return {boolean}
     */
    isActive(): boolean;
    /**
     * @override
     * @return {!Element}
     */
    element(): Element;
    /**
     * @return {string}
     */
    value(): string;
    /**
     * @param {string} value
     */
    setValue(value: string): void;
    focus(): void;
    /**
     * @param {(function(string, string, boolean=):!Promise<!Suggestions>)} suggestionProvider
     */
    setSuggestionProvider(suggestionProvider: ((arg0: string, arg1: string, arg2: boolean | undefined) => Promise<Suggestions>)): void;
    _valueChanged(): void;
    _updateEmptyStyles(): void;
    clear(): void;
}
/**
 * @implements {FilterUI}
 * @unrestricted
 */
export class NamedBitSetFilterUI extends Common.ObjectWrapper.ObjectWrapper implements FilterUI {
    /**
     * @param {!Array.<!Item>} items
     * @param {!Common.Settings.Setting<*>=} setting
     */
    constructor(items: Array<Item>, setting?: Common.Settings.Setting<any> | undefined);
    _filtersElement: HTMLDivElement;
    _allowedTypes: {};
    /** @type {!Array.<!Element>} */
    _typeFilterElements: Array<Element>;
    _setting: Common.Settings.Setting<any>;
    reset(): void;
    /**
     * @override
     * @return {boolean}
     */
    isActive(): boolean;
    /**
     * @override
     * @return {!Element}
     */
    element(): Element;
    /**
     * @param {string} typeName
     * @return {boolean}
     */
    accept(typeName: string): boolean;
    _settingChanged(): void;
    _update(): void;
    /**
     * @param {string} name
     * @param {string} label
     * @param {string=} title
     */
    _addBit(name: string, label: string, title?: string | undefined): void;
    /**
     * @param {!Event} e
     */
    _onTypeFilterClicked(e: Event): void;
    /**
     * @param {!Event} event
     */
    _onTypeFilterKeydown(event: Event): void;
    /**
     * @param {!Element} target
     * @param {boolean} selectPrevious
     * @returns {!boolean}
     */
    _keyFocusNextBit(target: Element, selectPrevious: boolean): boolean;
    /**
     * @param {string} typeName
     * @param {boolean} allowMultiSelect
     */
    _toggleTypeFilter(typeName: string, allowMultiSelect: boolean): void;
}
export namespace NamedBitSetFilterUI {
    export const ALL_TYPES: string;
}
/**
 * @implements {FilterUI}
 * @unrestricted
 */
export class CheckboxFilterUI extends Common.ObjectWrapper.ObjectWrapper implements FilterUI {
    /**
     * @param {string} className
     * @param {string} title
     * @param {boolean=} activeWhenChecked
     * @param {!Common.Settings.Setting<*>=} setting
     */
    constructor(className: string, title: string, activeWhenChecked?: boolean | undefined, setting?: Common.Settings.Setting<any> | undefined);
    _filterElement: HTMLDivElement;
    _activeWhenChecked: boolean;
    _label: CheckboxLabel;
    _checkboxElement: HTMLInputElement;
    /**
     * @override
     * @return {boolean}
     */
    isActive(): boolean;
    /**
     * @return {boolean}
     */
    checked(): boolean;
    /**
     * @param {boolean} checked
     */
    setChecked(checked: boolean): void;
    /**
     * @override
     * @return {!Element}
     */
    element(): Element;
    /**
     * @return {!Element}
     */
    labelElement(): Element;
    _fireUpdated(): void;
    /**
     * @param {string} backgroundColor
     * @param {string} borderColor
     */
    setColor(backgroundColor: string, borderColor: string): void;
}
export type Item = {
    name: string;
    label: string;
    title: (string | undefined);
};
/** @typedef {{name: string, label: string, title: (string|undefined)}} */
export let Item: any;
import { HBox } from "./Widget.js";
import * as Common from "../common/common.js";
import { ToolbarSettingToggle } from "./Toolbar.js";
import { ToolbarButton } from "./Toolbar.js";
import { TextPrompt } from "./TextPrompt.js";
import { Suggestions } from "./SuggestBox.js";
import { CheckboxLabel } from "./UIUtils.js";
