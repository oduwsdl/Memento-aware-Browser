/**
 * @unrestricted
 */
export class JavaScriptFormatter {
    /**
     * @param {!FormattedContentBuilder} builder
     */
    constructor(builder: FormattedContentBuilder);
    _builder: FormattedContentBuilder;
    /**
     * @param {string} text
     * @param {!Array<number>} lineEndings
     * @param {number} fromOffset
     * @param {number} toOffset
     */
    format(text: string, lineEndings: Array<number>, fromOffset: number, toOffset: number): void;
    _fromOffset: number | undefined;
    _toOffset: number | undefined;
    _content: string | undefined;
    _lastLineNumber: number | undefined;
    _tokenizer: AcornTokenizer | undefined;
    /**
     * @param {?TokenOrComment} token
     * @param {string} format
     */
    _push(token: TokenOrComment | null, format: string): void;
    /**
     * @param {!ESTree.Node} node
     */
    _beforeVisit(node: any): void;
    /**
     * @param {!ESTree.Node} node
     */
    _afterVisit(node: any): void;
    /**
     * @param {!ESTree.Node} node
     * @return {boolean}
     */
    _inForLoopHeader(node: any): boolean;
    /**
     * @param {!ESTree.Node} node
     * @param {!TokenOrComment} tokenOrComment
     * @return {string}
     */
    _formatToken(node: any, tokenOrComment: TokenOrComment): string;
    /**
     * @param {!ESTree.Node} node
     * @return {string}
     */
    _finishNode(node: any): string;
}
import { FormattedContentBuilder } from "./FormattedContentBuilder.js";
import { AcornTokenizer } from "./AcornTokenizer.js";
import { TokenOrComment } from "./AcornTokenizer.js";
