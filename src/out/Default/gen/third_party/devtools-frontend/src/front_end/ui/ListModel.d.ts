/**
 * @implements {Iterable<T>}
 * @template T
 */
export class ListModel<T> extends Common.ObjectWrapper.ObjectWrapper implements Iterable<T> {
    /**
     * @param {!Array<T>=} items
     */
    constructor(items?: T[] | undefined);
    _items: any;
    /**
     * @return {!Iterator<T>}
     */
    [Symbol.iterator](): Iterator<T, any, undefined>;
    /**
     * @return {number}
     */
    get length(): number;
    /**
     * @param {number} index
     * @return {T}
     */
    at(index: number): T;
    /**
     * @param {function(T):boolean} callback
     * @return {boolean}
     */
    every(callback: (arg0: T) => boolean): boolean;
    /**
     * @param {function(T):boolean} callback
     * @return {!Array<T>}
     */
    filter(callback: (arg0: T) => boolean): T[];
    /**
     * @param {function(T):boolean} callback
     * @return {T|undefined}
     */
    find(callback: (arg0: T) => boolean): T | undefined;
    /**
     * @param {function(T):boolean} callback
     * @return {number}
     */
    findIndex(callback: (arg0: T) => boolean): number;
    /**
     * @param {T} value
     * @param {number=} fromIndex
     * @return {number}
     */
    indexOf(value: T, fromIndex?: number | undefined): number;
    /**
     * @param {number} index
     * @param {T} value
     */
    insert(index: number, value: T): void;
    /**
     * @param {T} value
     * @param {function(T, T):number} comparator
     */
    insertWithComparator(value: T, comparator: (arg0: T, arg1: T) => number): void;
    /**
     * @param {string=} separator
     * @return {string}
     */
    join(separator?: string | undefined): string;
    /**
     * @param {number} index
     * @return {T}
     */
    remove(index: number): T;
    /**
     * @param {number} index
     * @param {T} value
     * @return {T}
     */
    replace(index: number, value: T): T;
    /**
     * @param {number} from
     * @param {number} to
     * @param {!Array<T>} items
     * @return {!Array<T>} removed
     */
    replaceRange(from: number, to: number, items: T[]): T[];
    /**
     * @param {!Array<T>} items
     * @return {!Array<T>}
     */
    replaceAll(items: T[]): T[];
    /**
     * @param {number=} from
     * @param {number=} to
     * @return {!Array<T>}
     */
    slice(from?: number | undefined, to?: number | undefined): T[];
    /**
     * @param {function(T):boolean} callback
     * @return {boolean}
     */
    some(callback: (arg0: T) => boolean): boolean;
    /**
     * @param {number} index
     * @param {!Array<T>} removed
     * @param {number} inserted
     */
    _replaced(index: number, removed: T[], inserted: number): void;
}
export type Events = symbol;
export namespace Events {
    export const ItemsReplaced: symbol;
}
import * as Common from "../common/common.js";
