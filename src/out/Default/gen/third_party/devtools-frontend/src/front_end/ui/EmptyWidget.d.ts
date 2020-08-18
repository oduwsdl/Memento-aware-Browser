export class EmptyWidget extends VBox {
    /**
     * @param {string} text
     */
    constructor(text: string);
    _contentElement: HTMLElement;
    _textElement: HTMLElement;
    /**
     * @return {!Element}
     */
    appendParagraph(): Element;
    /**
     * @param {string} link
     * @return {!Node}
     */
    appendLink(link: string): Node;
    /**
     * @param {string} text
     */
    set text(arg: string);
}
import { VBox } from "./Widget.js";
