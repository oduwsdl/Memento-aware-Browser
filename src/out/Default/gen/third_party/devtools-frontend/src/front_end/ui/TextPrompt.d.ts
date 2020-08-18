/**
 * @implements {SuggestBoxDelegate}
 * @unrestricted
 */
export class TextPrompt extends Common.ObjectWrapper.ObjectWrapper implements SuggestBoxDelegate {
    /**
     * @type {!Element|undefined}
     */
    _proxyElement: Element | undefined;
    _proxyElementDisplay: string;
    _autocompletionTimeout: number;
    _title: string;
    _queryRange: any;
    _previousText: any;
    _currentSuggestion: {
        text: string;
        title: string | undefined;
        subtitle: string | undefined;
        iconType: string | undefined;
        priority: number | undefined;
        isSecondary: boolean | undefined;
        subtitleRenderer: () => Element | undefined;
        selectionRange: {
            startColumn: number;
            endColumn: number;
        } | undefined;
        hideGhostText: boolean | undefined;
    } | null;
    _completionRequestId: number;
    _ghostTextElement: HTMLSpanElement;
    /**
     * @type {!Array<number>}
     */
    _leftParenthesesIndices: Array<number>;
    /**
     * @param {function(this:null, string, string, boolean=):!Promise<!Suggestions>} completions
     * @param {string=} stopCharacters
     */
    initialize(completions: (args: null, arg1: string, arg2: string, arg3: boolean | undefined) => Promise<Suggestions>, stopCharacters?: string | undefined): void;
    _loadCompletions: ((this: null, arg1: string, arg2: string, arg3?: boolean | undefined) => Promise<Suggestions>) | undefined;
    _completionStopCharacters: string | undefined;
    /**
     * @param {number} timeout
     */
    setAutocompletionTimeout(timeout: number): void;
    renderAsBlock(): void;
    /**
     * Clients should never attach any event listeners to the |element|. Instead,
     * they should use the result of this method to attach listeners for bubbling events.
     *
     * @param {!Element} element
     * @return {!Element}
     */
    attach(element: Element): Element;
    /**
     * Clients should never attach any event listeners to the |element|. Instead,
     * they should use the result of this method to attach listeners for bubbling events
     * or the |blurListener| parameter to register a "blur" event listener on the |element|
     * (since the "blur" event does not bubble.)
     *
     * @param {!Element} element
     * @param {function(!Event):*} blurListener
     * @return {!Element}
     */
    attachAndStartEditing(element: Element, blurListener: (arg0: Event) => any): Element;
    /**
     * @param {!Element} element
     * @return {!Element}
     */
    _attachInternal(element: Element): Element;
    _element: Element | undefined;
    _boundOnKeyDown: ((event: Event) => void) | undefined;
    _boundOnInput: ((event: Event) => void) | undefined;
    _boundOnMouseWheel: ((event: Event) => void) | undefined;
    _boundClearAutocomplete: (() => void) | undefined;
    _contentElement: Element | undefined;
    _suggestBox: SuggestBox | undefined;
    detach(): void;
    /**
     * @return {string}
     */
    textWithCurrentSuggestion(): string;
    /**
     * @return {string}
     */
    text(): string;
    /**
     * @param {string} text
     */
    setText(text: string): void;
    focus(): void;
    /**
     * @return {string}
     */
    title(): string;
    /**
     * @param {string} title
     */
    setTitle(title: string): void;
    /**
     * @param {string} placeholder
     * @param {string=} ariaPlaceholder
     */
    setPlaceholder(placeholder: string, ariaPlaceholder?: string | undefined): void;
    /**
     * @param {boolean} enabled
     */
    setEnabled(enabled: boolean): void;
    _removeFromElement(): void;
    /**
     * @param {function(!Event):*=} blurListener
     */
    _startEditing(blurListener: (arg0: Event) => any | undefined): void;
    _isEditing: boolean | undefined;
    _focusRestorer: ElementFocusRestorer | undefined;
    _blurListener: ((arg0: Event) => any | undefined) | undefined;
    _oldTabIndex: any;
    _stopEditing(): void;
    /**
     * @param {!Event} event
     */
    onMouseWheel(event: Event): void;
    /**
     * @param {!Event} event
     */
    onKeyDown(event: Event): void;
    /**
     * @param {string} key
     * @return {boolean}
     */
    _acceptSuggestionOnStopCharacters(key: string): boolean;
    /**
     * @param {!Event} event
     */
    onInput(event: Event): void;
    /**
     * @return {boolean}
     */
    acceptAutoComplete(): boolean;
    clearAutocomplete(): void;
    _refreshGhostText(): void;
    _clearAutocompleteTimeout(): void;
    /**
     * @param {boolean=} force
     */
    autoCompleteSoon(force?: boolean | undefined): void;
    _completeTimeout: number | undefined;
    /**
     * @param {boolean=} force
     */
    complete(force?: boolean | undefined): Promise<void>;
    disableDefaultSuggestionForEmptyInput(): void;
    _disableDefaultSuggestionForEmptyInput: boolean | undefined;
    /**
     * @param {!Selection} selection
     * @param {!Range} textRange
     */
    _boxForAnchorAtStart(selection: Selection, textRange: Range): any;
    /**
     * @return {?Range}
     * @suppressGlobalPropertiesCheck
     */
    _createRange(): Range | null;
    /**
     * @param {string} query
     * @return {!Suggestions}
     */
    additionalCompletions(query: string): Suggestions;
    /**
     * @param {number} completionRequestId
     * @param {!Selection} selection
     * @param {!Range} originalWordQueryRange
     * @param {boolean} force
     * @param {!Suggestions} completions
     */
    _completionsReady(completionRequestId: number, selection: Selection, originalWordQueryRange: Range, force: boolean, completions: Suggestions): void;
    /**
     * @override
     * @param {?Suggestion} suggestion
     * @param {boolean=} isIntermediateSuggestion
     */
    applySuggestion(suggestion: Suggestion | null, isIntermediateSuggestion?: boolean | undefined): void;
    /**
     * @override
     */
    acceptSuggestion(): void;
    /**
     * @return {boolean}
     */
    _acceptSuggestionInternal(): boolean;
    /**
     * @param {number} startColumn
     * @param {number} endColumn
     */
    setDOMSelection(startColumn: number, endColumn: number): void;
    /**
     * @protected
     * @return {boolean}
     */
    protected isSuggestBoxVisible(): boolean;
    /**
     * @return {boolean}
     */
    isCaretInsidePrompt(): boolean;
    /**
     * @return {boolean}
     */
    _isCaretAtEndOfPrompt(): boolean;
    moveCaretToEndOfPrompt(): void;
    /**
     * @return {number} -1 if no caret can be found in text prompt
     */
    _getCaretPosition(): number;
    /**
     * @param {!Event} event
     * @return {boolean}
     */
    tabKeyPressed(event: Event): boolean;
    /**
     * @return {?Element}
     */
    proxyElementForTests(): Element | null;
    /**
     * Try matching the most recent open parenthesis with the given right
     * parenthesis, and closes the matched left parenthesis if found.
     * Return the result of the matching.
     * @param {number} rightParenthesisIndex
     * @return {boolean}
     */
    _tryMatchingLeftParenthesis(rightParenthesisIndex: number): boolean;
    _updateLeftParenthesesIndices(): void;
}
export type Events = symbol;
export namespace Events {
    export const TextChanged: symbol;
}
import * as Common from "../common/common.js";
import { SuggestBoxDelegate } from "./SuggestBox.js";
import { Suggestions } from "./SuggestBox.js";
import { SuggestBox } from "./SuggestBox.js";
import { ElementFocusRestorer } from "./UIUtils.js";
import { Suggestion } from "./SuggestBox.js";
