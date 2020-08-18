export class FilterSuggestionBuilder {
    /**
     * @param {!Array<string>} keys
     * @param {function(string, !Array<string>):void=} valueSorter
     */
    constructor(keys: Array<string>, valueSorter?: ((arg0: string, arg1: Array<string>) => void) | undefined);
    _keys: string[];
    _valueSorter: ((arg0: string, arg1: Array<string>) => void) | ((key: string, result: string[]) => string[]);
    /** @type {!Map<string, !Set<string>>} */
    _valuesMap: Map<string, Set<string>>;
    /**
     * @param {string} expression
     * @param {string} prefix
     * @param {boolean=} force
     * @return {!Promise<!Suggestions>}
     */
    completions(expression: string, prefix: string, force?: boolean | undefined): Promise<Suggestions>;
    /**
     * @param {string} key
     * @param {?string=} value
     */
    addItem(key: string, value?: (string | null) | undefined): void;
    clear(): void;
}
import { Suggestions } from "./SuggestBox.js";
