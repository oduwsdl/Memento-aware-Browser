/**
 * @unrestricted
 */
export class SearchableView extends VBox {
    /**
     * @param {?Element} element
     * @return {?SearchableView}
     */
    static fromElement(element: Element | null): SearchableView | null;
    /**
     * @param {!Searchable} searchable
     * @param {string=} settingName
     */
    constructor(searchable: Searchable, settingName?: string | undefined);
    _searchProvider: Searchable;
    _setting: Common.Settings.Setting<any> | null;
    _replaceable: boolean;
    _footerElementContainer: HTMLElement;
    _footerElement: HTMLElement;
    _replaceToggleButton: ToolbarToggle;
    _searchInputElement: HistoryInput;
    _matchesElement: HTMLElement;
    _searchNavigationPrevElement: HTMLElement;
    _searchNavigationNextElement: HTMLElement;
    _replaceInputElement: HTMLElement;
    _buttonsContainer: HTMLElement;
    _caseSensitiveButton: ToolbarToggle;
    _regexButton: ToolbarToggle;
    _secondRowButtons: HTMLElement;
    _replaceButtonElement: Element;
    _replaceAllButtonElement: Element;
    _minimalSearchQuerySize: number;
    _toggleCaseSensitiveSearch(): void;
    _toggleRegexSearch(): void;
    _toggleReplace(): void;
    _saveSetting(): void;
    _loadSetting(): void;
    /**
     * @param {number} minimalSearchQuerySize
     */
    setMinimalSearchQuerySize(minimalSearchQuerySize: number): void;
    /**
     * @param {string} placeholder
     */
    setPlaceholder(placeholder: string): void;
    /**
     * @param {boolean} replaceable
     */
    setReplaceable(replaceable: boolean): void;
    /**
     * @param {number} matches
     * @suppress {checkTypes}
     */
    updateSearchMatchesCount(matches: number): void;
    /**
     * @param {number} currentMatchIndex
     * @suppress {checkTypes}
     */
    updateCurrentMatchIndex(currentMatchIndex: number): void;
    /**
     * @return {boolean}
     */
    isSearchVisible(): boolean;
    closeSearch(): void;
    _toggleSearchBar(toggled: any): void;
    cancelSearch(): void;
    resetSearch(): void;
    refreshSearch(): void;
    /**
     * @return {boolean}
     */
    handleFindNextShortcut(): boolean;
    /**
     * @return {boolean}
     */
    handleFindPreviousShortcut(): boolean;
    /**
     * @return {boolean}
     */
    handleFindShortcut(): boolean;
    /**
     * @return {boolean}
     */
    handleCancelSearchShortcut(): boolean;
    /**
     * @param {boolean} enabled
     */
    _updateSearchNavigationButtonState(enabled: boolean): void;
    /**
     * @param {number} matches
     * @param {number} currentMatchIndex
     */
    _updateSearchMatchesCountAndCurrentMatchIndex(matches: number, currentMatchIndex: number): void;
    showSearchField(): void;
    _searchIsVisible: boolean | undefined;
    _updateReplaceVisibility(): void;
    /**
     * @param {!Event} event
     */
    _onSearchKeyDown(event: Event): void;
    /**
     * @param {!Event} event
     */
    _onReplaceKeyDown(event: Event): void;
    /**
     * @param {boolean=} isBackwardSearch
     */
    _jumpToNextSearchResult(isBackwardSearch?: boolean | undefined): void;
    _onNextButtonSearch(event: any): void;
    _onPrevButtonSearch(event: any): void;
    _onFindClick(event: any): void;
    _onPreviousClick(event: any): void;
    /** @suppress {checkTypes} */
    _clearSearch(): void;
    /**
     * @param {boolean} forceSearch
     * @param {boolean} shouldJump
     * @param {boolean=} jumpBackwards
     * @suppress {checkTypes}
     */
    _performSearch(forceSearch: boolean, shouldJump: boolean, jumpBackwards?: boolean | undefined): void;
    _currentQuery: string | undefined;
    /**
     * @return {!SearchConfig}
     */
    _currentSearchConfig(): SearchConfig;
    _updateSecondRowVisibility(): void;
    _replace(): void;
    _replaceAll(): void;
    /**
     * @param {!Event} event
     */
    _onInput(event: Event): void;
    _valueChangedTimeoutId: number | undefined;
    _onValueChanged(): void;
}
export const _symbol: unique symbol;
/**
 * @interface
 */
export class Searchable {
    searchCanceled(): void;
    /**
     * @param {!SearchConfig} searchConfig
     * @param {boolean} shouldJump
     * @param {boolean=} jumpBackwards
     */
    performSearch(searchConfig: SearchConfig, shouldJump: boolean, jumpBackwards?: boolean | undefined): void;
    jumpToNextSearchResult(): void;
    jumpToPreviousSearchResult(): void;
    /**
     * @return {boolean}
     */
    supportsCaseSensitiveSearch(): boolean;
    /**
     * @return {boolean}
     */
    supportsRegexSearch(): boolean;
}
/**
 * @interface
 */
export class Replaceable {
    /**
     * @param {!SearchConfig} searchConfig
     * @param {string} replacement
     */
    replaceSelectionWith(searchConfig: SearchConfig, replacement: string): void;
    /**
     * @param {!SearchConfig} searchConfig
     * @param {string} replacement
     */
    replaceAllWith(searchConfig: SearchConfig, replacement: string): void;
}
/**
 * @unrestricted
 */
export class SearchConfig {
    /**
     * @param {string} query
     * @param {boolean} caseSensitive
     * @param {boolean} isRegex
     */
    constructor(query: string, caseSensitive: boolean, isRegex: boolean);
    query: string;
    caseSensitive: boolean;
    isRegex: boolean;
    /**
     * @param {boolean=} global
     * @return {!RegExp}
     */
    toSearchRegex(global?: boolean | undefined): RegExp;
}
import { VBox } from "./Widget.js";
import * as Common from "../common/common.js";
import { ToolbarToggle } from "./Toolbar.js";
import { HistoryInput } from "./HistoryInput.js";
