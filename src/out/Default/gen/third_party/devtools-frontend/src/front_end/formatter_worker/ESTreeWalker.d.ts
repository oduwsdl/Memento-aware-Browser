/**
 * @unrestricted
 */
export class ESTreeWalker {
    /**
     * @return {!Object}
     */
    static get SkipSubtree(): Object;
    /**
     * @param {function(!ESTree.Node):(!Object|undefined)} beforeVisit
     * @param {function(!ESTree.Node)=} afterVisit
     */
    constructor(beforeVisit: (arg0: any) => (Object | undefined), afterVisit?: ((arg0: any) => ) | undefined);
    _beforeVisit: (arg0: any) => (Object | undefined);
    _afterVisit: Function;
    _walkNulls: boolean;
    /**
     * @param {boolean} value
     */
    setWalkNulls(value: boolean): void;
    /**
     * @param {!ESTree.Node} ast
     */
    walk(ast: any): void;
    /**
     * @param {!ESTree.Node} node
     * @param {?ESTree.Node} parent
     */
    _innerWalk(node: any, parent: any | null): void;
    /**
     * @param {!Array.<!ESTree.Node>} nodeArray
     * @param {?ESTree.Node} parentNode
     */
    _walkArray(nodeArray: Array<any>, parentNode: any | null): void;
}
export type _walkOrder = string[];
