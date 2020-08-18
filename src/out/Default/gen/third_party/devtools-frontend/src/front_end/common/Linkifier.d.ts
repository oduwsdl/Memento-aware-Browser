/**
 * @interface
 */
export class Linkifier {
    /**
     * @param {?Object} object
     * @param {!Options=} options
     * @return {!Promise<!Node>}
     */
    static linkify(object: Object | null, options?: Options | undefined): Promise<Node>;
    /**
     * @param {!Object} object
     * @param {!Options=} options
     * @return {!Node}
     */
    linkify(object: Object, options?: Options | undefined): Node;
}
export type Options = {
    tooltip: (string | undefined);
    preventKeyboardFocus: (boolean | undefined);
};
/** @typedef {{tooltip: (string|undefined), preventKeyboardFocus: (boolean|undefined)}} */
export let Options: any;
