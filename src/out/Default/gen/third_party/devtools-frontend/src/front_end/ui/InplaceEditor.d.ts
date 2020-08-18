/**
 * @unrestricted
 */
export class InplaceEditor {
    /**
     * @param {!Element} element
     * @param {!Config<?>=} config
     * @return {?Controller}
     */
    static startEditing(element: Element, config?: Config<unknown> | undefined): Controller | null;
    /**
     * @return {string}
     */
    editorContent(editingContext: any): string;
    setUpEditor(editingContext: any): void;
    _focusRestorer: ElementFocusRestorer | undefined;
    closeEditor(editingContext: any): void;
    cancelEditing(editingContext: any): void;
    augmentEditingHandle(editingContext: any, handle: any): void;
    /**
     * @param {!Element} element
     * @param {!Config<*>=} config
     * @return {?Controller}
     */
    startEditing(element: Element, config?: Config<any> | undefined): Controller | null;
}
/**
 * @template T
 * @unrestricted
 */
export class Config<T> {
    /**
     * @param {function(!Element,string,string,T,string):void} commitHandler
     * @param {function(!Element,T):void} cancelHandler
     * @param {T=} context
     * @param {function(!Element,!Event):boolean=} blurHandler
     */
    constructor(commitHandler: (arg0: Element, arg1: string, arg2: string, arg3: T, arg4: string) => void, cancelHandler: (arg0: Element, arg1: T) => void, context?: T | undefined, blurHandler?: ((arg0: Element, arg1: Event) => boolean) | undefined);
    commitHandler: (arg0: Element, arg1: string, arg2: string, arg3: T, arg4: string) => void;
    cancelHandler: (arg0: Element, arg1: T) => void;
    context: T | undefined;
    blurHandler: ((arg0: Element, arg1: Event) => boolean) | undefined;
    /**
     * @type {function(!Event):string|undefined}
     */
    pasteHandler: (arg0: Event) => string | undefined;
    /**
     * @type {function(!Event):string|undefined}
     */
    postKeydownFinishHandler: (arg0: Event) => string | undefined;
    setPasteHandler(pasteHandler: any): void;
    /**
     * @param {function(!Event):string} postKeydownFinishHandler
     */
    setPostKeydownFinishHandler(postKeydownFinishHandler: (arg0: Event) => string): void;
}
export type Controller = {
    cancel: () => void;
    commit: () => void;
};
/**
 * @typedef {{cancel: function():void, commit: function():void}}
 */
export let Controller: any;
import { ElementFocusRestorer } from "./UIUtils.js";
