/**
 * * Use a normal object instead of making it null-prototyped because
 * Closure requires enum initialization to be an object literal.
 * Will be a proper enum class once this file becomes TypeScript.
 */
export type AdornerCategories = string;
export namespace AdornerCategories {
    export const Security: string;
    export const Layout: string;
    export const Default: string;
}
export class Adorner extends HTMLElement {
    /**
     *
     * @param {!HTMLElement} content
     * @param {string} name
     * @param {!{category: (!AdornerCategories|undefined)}} options
     * @return {!Adorner}
     */
    static create(content: HTMLElement, name: string, options?: {
        category: (AdornerCategories | undefined);
    }): Adorner;
    name: string;
    category: string;
    _isToggle: boolean;
    _ariaLabelDefault: string;
    _ariaLabelActive: string;
    /**
     * @override
     */
    connectedCallback(): void;
    toggle(): void;
    show(): void;
    hide(): void;
    /**
     * Make adorner interactive by responding to click events with the provided action
     * and simulating ARIA-capable toggle button behavior.
     * @param {!EventListener} action
     * @param {!{isToggle: (boolean|undefined), shouldPropagateOnKeydown: (boolean|undefined), ariaLabelDefault: (string|undefined), ariaLabelActive: (string|undefined)}} options
     */
    addInteraction(action: EventListener, options?: {
        isToggle: (boolean | undefined);
        shouldPropagateOnKeydown: (boolean | undefined);
        ariaLabelDefault: (string | undefined);
        ariaLabelActive: (string | undefined);
    }): void;
}
