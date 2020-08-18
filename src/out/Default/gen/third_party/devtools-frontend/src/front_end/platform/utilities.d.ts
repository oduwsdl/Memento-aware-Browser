/**
 * @template K, V
 */
export class Multimap<K, V> {
    /** @type {!Map.<K, !Set.<!V>>} */
    _map: Map<K, Set<V>>;
    /**
     * @param {K} key
     * @param {V} value
     */
    set(key: K, value: V): void;
    /**
     * @param {K} key
     * @return {!Set<!V>}
     */
    get(key: K): Set<V>;
    /**
     * @param {K} key
     * @return {boolean}
     */
    has(key: K): boolean;
    /**
     * @param {K} key
     * @param {V} value
     * @return {boolean}
     */
    hasValue(key: K, value: V): boolean;
    /**
     * @return {number}
     */
    get size(): number;
    /**
     * @param {K} key
     * @param {V} value
     * @return {boolean}
     */
    delete(key: K, value: V): boolean;
    /**
     * @param {K} key
     */
    deleteAll(key: K): void;
    /**
     * @return {!Array.<K>}
     */
    keysArray(): K[];
    /**
     * @return {!Array.<!V>}
     */
    valuesArray(): V[];
    clear(): void;
}
