/**
 * @unrestricted
 */
export class Trie {
    /** @type {number} */
    _size: number;
    /** @type {number} */
    _root: number;
    /** @type {!Array<!Object<string, number>>} */
    _edges: Array<{
        [x: string]: number;
    }>;
    /** @type {!Array<boolean>} */
    _isWord: Array<boolean>;
    /** @type {!Array<number>} */
    _wordsInSubtree: Array<number>;
    /** @type {!Array<number>} */
    _freeNodes: Array<number>;
    /**
     * @param {string} word
     */
    add(word: string): void;
    /**
     * @param {string} word
     * @return {boolean}
     */
    remove(word: string): boolean;
    /**
     * @param {string} word
     * @return {boolean}
     */
    has(word: string): boolean;
    /**
     * @param {string=} prefix
     * @return {!Array<string>}
     */
    words(prefix?: string | undefined): Array<string>;
    /**
     * @param {number} node
     * @param {string} prefix
     * @param {!Array<string>} results
     */
    _dfs(node: number, prefix: string, results: Array<string>): void;
    /**
     * @param {string} word
     * @param {boolean} fullWordOnly
     * @return {string}
     */
    longestPrefix(word: string, fullWordOnly: boolean): string;
    clear(): void;
}
