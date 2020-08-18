export class SyntaxHighlighter {
    /**
     * @param {string} mimeType
     * @param {boolean} stripExtraWhitespace
     */
    constructor(mimeType: string, stripExtraWhitespace: boolean);
    _mimeType: string;
    _stripExtraWhitespace: boolean;
    /**
     * @param {string} content
     * @param {string} className
     * @return {!Element}
     */
    createSpan(content: string, className: string): Element;
    /**
     * @param {!Element} node
     * @return {!Promise.<undefined>}
     */
    syntaxHighlightNode(node: Element): Promise<undefined>;
}
