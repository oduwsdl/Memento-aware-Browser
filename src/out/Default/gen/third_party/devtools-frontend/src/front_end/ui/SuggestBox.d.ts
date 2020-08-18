/**
 * @interface
 */
export class SuggestBoxDelegate {
    /**
     * @param {?Suggestion} suggestion
     * @param {boolean=} isIntermediateSuggestion
     */
    applySuggestion(suggestion: Suggestion | null, isIntermediateSuggestion?: boolean | undefined): void;
    /**
     * acceptSuggestion will be always called after call to applySuggestion with isIntermediateSuggestion being equal to false.
     */
    acceptSuggestion(): void;
}
/**
 * @implements {ListDelegate}
 */
export class SuggestBox implements ListDelegate<any> {
    /**
     * @param {!SuggestBoxDelegate} suggestBoxDelegate
     * @param {number=} maxItemsHeight
     */
    constructor(suggestBoxDelegate: SuggestBoxDelegate, maxItemsHeight?: number | undefined);
    _suggestBoxDelegate: SuggestBoxDelegate;
    _maxItemsHeight: number | undefined;
    _rowHeight: number;
    _userEnteredText: string;
    _defaultSelectionIsDimmed: boolean;
    /** @type {?Suggestion} */
    _onlyCompletion: Suggestion | null;
    /** @type {!ListModel<!Suggestion>} */
    _items: ListModel<Suggestion>;
    /** @type {!ListControl<!Suggestion>} */
    _list: ListControl<Suggestion>;
    _element: any;
    _glassPane: GlassPane;
    /**
     * @return {boolean}
     */
    visible(): boolean;
    /**
     * @param {!AnchorBox} anchorBox
     */
    setPosition(anchorBox: AnchorBox): void;
    /**
     * @param {!AnchorBehavior} behavior
     */
    setAnchorBehavior(behavior: AnchorBehavior): void;
    /**
     * @param {!Suggestions} items
     */
    _updateMaxSize(items: Suggestions): void;
    /**
     * @param {!Suggestions} items
     * @return {number}
     */
    _maxWidth(items: Suggestions): number;
    /**
     * @suppressGlobalPropertiesCheck
     */
    _show(): void;
    hide(): void;
    /**
     * @param {boolean=} isIntermediateSuggestion
     * @return {boolean}
     */
    _applySuggestion(isIntermediateSuggestion?: boolean | undefined): boolean;
    /**
     * @return {boolean}
     */
    acceptSuggestion(): boolean;
    /**
     * @override
     * @param {!Suggestion} item
     * @return {!Element}
     */
    createElementForItem(item: Suggestion): Element;
    /**
     * @override
     * @param {!Suggestion} item
     * @return {number}
     */
    heightForItem(item: Suggestion): number;
    /**
     * @override
     * @param {!Suggestion} item
     * @return {boolean}
     */
    isItemSelectable(item: Suggestion): boolean;
    /**
     * @override
     * @param {?Suggestion} from
     * @param {?Suggestion} to
     * @param {?Element} fromElement
     * @param {?Element} toElement
     */
    selectedItemChanged(from: Suggestion | null, to: Suggestion | null, fromElement: Element | null, toElement: Element | null): void;
    /**
     * @override
     * @param {?Element} fromElement
     * @param {?Element} toElement
     * @return {boolean}
     */
    updateSelectedItemARIA(fromElement: Element | null, toElement: Element | null): boolean;
    /**
     * @param {!Event} event
     */
    _onClick(event: Event): void;
    /**
     * @param {!Suggestions} completions
     * @param {?Suggestion} highestPriorityItem
     * @param {boolean} canShowForSingleItem
     * @param {string} userEnteredText
     * @return {boolean}
     */
    _canShowBox(completions: Suggestions, highestPriorityItem: Suggestion | null, canShowForSingleItem: boolean, userEnteredText: string): boolean;
    /**
     * @param {!AnchorBox} anchorBox
     * @param {!Suggestions} completions
     * @param {boolean} selectHighestPriority
     * @param {boolean} canShowForSingleItem
     * @param {string} userEnteredText
     */
    updateSuggestions(anchorBox: AnchorBox, completions: Suggestions, selectHighestPriority: boolean, canShowForSingleItem: boolean, userEnteredText: string): void;
    /**
     * @param {!KeyboardEvent} event
     * @return {boolean}
     */
    keyPressed(event: KeyboardEvent): boolean;
    /**
     * @return {boolean}
     */
    enterKeyPressed(): boolean;
}
export type Suggestion = {
    text: string;
    title: (string | undefined);
    subtitle: (string | undefined);
    iconType: (string | undefined);
    priority: (number | undefined);
    isSecondary: (boolean | undefined);
    subtitleRenderer: (() => Element | undefined);
    selectionRange: ({
        startColumn: number;
        endColumn: number;
    } | undefined);
    hideGhostText: (boolean | undefined);
};
/**
 * @typedef {{
  *      text: string,
  *      title: (string|undefined),
  *      subtitle: (string|undefined),
  *      iconType: (string|undefined),
  *      priority: (number|undefined),
  *      isSecondary: (boolean|undefined),
  *      subtitleRenderer: (function():!Element|undefined),
  *      selectionRange: ({startColumn: number, endColumn: number}|undefined),
  *      hideGhostText: (boolean|undefined)
  * }}
  */
export let Suggestion: any;
export type Suggestions = {
    text: string;
    title: (string | undefined);
    subtitle: (string | undefined);
    iconType: (string | undefined);
    priority: (number | undefined);
    isSecondary: (boolean | undefined);
    subtitleRenderer: (() => Element | undefined);
    selectionRange: ({
        startColumn: number;
        endColumn: number;
    } | undefined);
    hideGhostText: (boolean | undefined);
}[];
/**
  * @typedef {!Array<!Suggestion>}
  */
export let Suggestions: any;
export type AutocompleteConfig = {
    substituteRangeCallback: (((arg0: number, arg1: number) => any | null) | undefined);
    tooltipCallback: (((arg0: number, arg1: number) => Promise<Element | null>) | undefined);
    suggestionsCallback: (((arg0: any, arg1: any, arg2: boolean | undefined) => Promise<Suggestions> | null) | undefined);
    isWordChar: (((arg0: string) => boolean) | undefined);
    anchorBehavior: (AnchorBehavior | undefined);
};
/**
  * @typedef {{
    *     substituteRangeCallback: ((function(number, number):?TextUtils.TextRange)|undefined),
    *     tooltipCallback: ((function(number, number):!Promise<?Element>)|undefined),
    *     suggestionsCallback: ((function(!TextUtils.TextRange, !TextUtils.TextRange, boolean=):?Promise.<!Suggestions>)|undefined),
    *     isWordChar: ((function(string):boolean)|undefined),
    *     anchorBehavior: (AnchorBehavior|undefined)
    * }}
    */
export let AutocompleteConfig: any;
import { ListDelegate } from "./ListControl.js";
import { ListModel } from "./ListModel.js";
import { ListControl } from "./ListControl.js";
import { GlassPane } from "./GlassPane.js";
import { AnchorBehavior } from "./GlassPane.js";
