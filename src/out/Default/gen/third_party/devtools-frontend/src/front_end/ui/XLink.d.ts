/**
 * @extends {XElement}
 */
export class XLink extends XElement {
    /**
     * @param {string} url
     * @param {string=} linkText
     * @param {string=} className
     * @param {boolean=} preventClick
     * @return {!Element}
     */
    static create(url: string, linkText?: string | undefined, className?: string | undefined, preventClick?: boolean | undefined): Element;
    target: string;
    rel: string;
    /** @type {?string} */
    _href: string | null;
    _clickable: boolean;
    _onClick: (event: any) => void;
    _onKeyDown: (event: any) => void;
    _updateClick(): void;
}
/**
 * @implements {Provider}
 */
export class ContextMenuProvider implements Provider {
    /**
     * @override
     * @param {!Event} event
     * @param {!ContextMenu} contextMenu
     * @param {!Object} target
     */
    appendApplicableItems(event: Event, contextMenu: ContextMenu, target: Object): void;
}
import { XElement } from "./XElement.js";
import { Provider } from "./ContextMenu.js";
import { ContextMenu } from "./ContextMenu.js";
