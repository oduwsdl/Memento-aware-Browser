/**
 * @unrestricted
 */
export class TextDictionary {
    /** @type {!Map<string, number>} */
    _words: Map<string, number>;
    _index: Trie;
    /**
     * @param {string} word
     */
    addWord(word: string): void;
    /**
     * @param {string} word
     */
    removeWord(word: string): void;
    /**
     * @param {string} prefix
     * @return {!Array.<string>}
     */
    wordsWithPrefix(prefix: string): Array<string>;
    /**
     * @param {string} word
     * @return {boolean}
     */
    hasWord(word: string): boolean;
    /**
     * @param {string} word
     * @return {number}
     */
    wordCount(word: string): number;
    reset(): void;
}
import { Trie } from "./Trie.js";
