/**
 * @unrestricted
 */
export class ProfileNode {
    /**
     * @param {!Protocol.Runtime.CallFrame} callFrame
     */
    constructor(callFrame: Protocol.Runtime.CallFrame);
    /** @type {!Protocol.Runtime.CallFrame} */
    callFrame: Protocol.Runtime.CallFrame;
    /** @type {string} */
    callUID: string;
    /** @type {number} */
    self: number;
    /** @type {number} */
    total: number;
    /** @type {number} */
    id: number;
    /** @type {?ProfileNode} */
    parent: ProfileNode | null;
    /** @type {!Array<!ProfileNode>} */
    children: Array<ProfileNode>;
    /**
     * @return {string}
     */
    get functionName(): string;
    /**
     * @return {string}
     */
    get scriptId(): string;
    /**
     * @return {string}
     */
    get url(): string;
    /**
     * @return {number}
     */
    get lineNumber(): number;
    /**
     * @return {number}
     */
    get columnNumber(): number;
}
/**
 * @unrestricted
 */
export class ProfileTreeModel {
    /**
     * @param {?Target=} target
     */
    constructor(target?: (Target | null) | undefined);
    _target: Target | null;
    /**
     * @param {!ProfileNode} root
     * @protected
     */
    protected initialize(root: ProfileNode): void;
    root: ProfileNode | undefined;
    total: number | undefined;
    _assignDepthsAndParents(): void;
    maxDepth: any;
    /**
     * @param {!ProfileNode} root
     * @return {number}
     */
    _calculateTotals(root: ProfileNode): number;
    /**
     * @return {?Target}
     */
    target(): Target | null;
}
import { Target } from "./SDKModel.js";
