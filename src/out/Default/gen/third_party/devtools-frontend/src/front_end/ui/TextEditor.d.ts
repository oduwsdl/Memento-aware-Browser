/**
 * @interface
 */
export class TextEditorFactory {
    /**
     * @param {!Options} options
     * @return {!TextEditor}
     */
    createEditor(options: Options): TextEditor;
}
/**
 * @interface
 */
export class TextEditor extends Common.EventTarget.EventTarget {
    /**
     * @return {!Widget}
     */
    widget(): Widget;
    /**
     * @return {!TextUtils.TextRange.TextRange}
     */
    fullRange(): TextUtils.TextRange.TextRange;
    /**
     * @return {!TextUtils.TextRange.TextRange}
     */
    selection(): TextUtils.TextRange.TextRange;
    /**
     * @param {!TextUtils.TextRange.TextRange} selection
     */
    setSelection(selection: TextUtils.TextRange.TextRange): void;
    /**
     * @param {!TextUtils.TextRange.TextRange=} textRange
     * @return {string}
     */
    text(textRange?: TextUtils.TextRange.TextRange | undefined): string;
    /**
     * @return {string}
     */
    textWithCurrentSuggestion(): string;
    /**
     * @param {string} text
     */
    setText(text: string): void;
    /**
     * @param {number} lineNumber
     * @return {string}
     */
    line(lineNumber: number): string;
    newlineAndIndent(): void;
    /**
     * @param {function(!KeyboardEvent):void} handler
     */
    addKeyDownHandler(handler: (arg0: KeyboardEvent) => void): void;
    /**
     * @param {?AutocompleteConfig} config
     */
    configureAutocomplete(config: AutocompleteConfig | null): void;
    clearAutocomplete(): void;
    /**
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {!{x: number, y: number}}
     */
    visualCoordinates(lineNumber: number, columnNumber: number): {
        x: number;
        y: number;
    };
    /**
     * @param {number} lineNumber
     * @param {number} columnNumber
     * @return {?{startColumn: number, endColumn: number, type: string}}
     */
    tokenAtTextPosition(lineNumber: number, columnNumber: number): {
        startColumn: number;
        endColumn: number;
        type: string;
    } | null;
    /**
     * @param {string} placeholder
     */
    setPlaceholder(placeholder: string): void;
}
export type Events = symbol;
export namespace Events {
    export const CursorChanged: symbol;
    export const TextChanged: symbol;
    export const SuggestionChanged: symbol;
}
export type Options = {
    bracketMatchingSetting: (Common.Settings.Setting<any> | undefined);
    devtoolsAccessibleName: (string | undefined);
    lineNumbers: boolean;
    lineWrapping: boolean;
    mimeType: (string | undefined);
    autoHeight: (boolean | undefined);
    padBottom: (boolean | undefined);
    maxHighlightLength: (number | undefined);
    placeholder: (string | undefined);
    lineWiseCopyCut: (boolean | undefined);
};
/**
 * @typedef {{
  *  bracketMatchingSetting: (!Common.Settings.Setting<*>|undefined),
  *  devtoolsAccessibleName: (string|undefined),
  *  lineNumbers: boolean,
  *  lineWrapping: boolean,
  *  mimeType: (string|undefined),
  *  autoHeight: (boolean|undefined),
  *  padBottom: (boolean|undefined),
  *  maxHighlightLength: (number|undefined),
  *  placeholder: (string|undefined),
  *  lineWiseCopyCut: (boolean|undefined)
  * }}
  */
export let Options: any;
export type AutocompleteConfig = {
    substituteRangeCallback: (((arg0: number, arg1: number) => TextUtils.TextRange.TextRange | null) | undefined);
    tooltipCallback: (((arg0: number, arg1: number) => Promise<Element | null>) | undefined);
    suggestionsCallback: (((arg0: TextUtils.TextRange.TextRange, arg1: TextUtils.TextRange.TextRange, arg2: boolean | undefined) => Promise<Suggestions> | null) | undefined);
    isWordChar: (((arg0: string) => boolean) | undefined);
    anchorBehavior: (AnchorBehavior | undefined);
};
/**
  * @typedef {{
  *     substituteRangeCallback: ((function(number, number):?TextUtils.TextRange.TextRange)|undefined),
  *     tooltipCallback: ((function(number, number):!Promise<?Element>)|undefined),
  *     suggestionsCallback: ((function(!TextUtils.TextRange.TextRange, !TextUtils.TextRange.TextRange, boolean=):?Promise.<!Suggestions>)|undefined),
  *     isWordChar: ((function(string):boolean)|undefined),
  *     anchorBehavior: (AnchorBehavior|undefined)
  * }}
  */
export let AutocompleteConfig: any;
import * as Common from "../common/common.js";
import { Widget } from "./Widget.js";
import * as TextUtils from "../text_utils/text_utils.js";
import { Suggestions } from "./SuggestBox.js";
import { AnchorBehavior } from "./GlassPane.js";
