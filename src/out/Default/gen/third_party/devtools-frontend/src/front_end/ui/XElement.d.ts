export class XElement extends HTMLElement {
    /**
     * @override
     */
    static get observedAttributes(): string[];
    /**
     * @param {string} attr
     * @param {?string} oldValue
     * @param {?string} newValue
     * @override
     */
    attributeChangedCallback(attr: string, oldValue: string | null, newValue: string | null): void;
}
