/**
 * @unrestricted
 */
export class Infobar {
    /**
     * @param {!Type} type
     * @param {string} text
     * @param {!Array<!InfobarAction>=} actions
     * @param {!Common.Settings.Setting<*>=} disableSetting
     * @return {?Infobar}
     */
    static create(type: Type, text: string, actions?: Array<InfobarAction> | undefined, disableSetting?: Common.Settings.Setting<any> | undefined): Infobar | null;
    /**
     * @param {!Type} type
     * @param {string} text
     * @param {!Array<!InfobarAction>=} actions
     * @param {!Common.Settings.Setting<*>=} disableSetting
     */
    constructor(type: Type, text: string, actions?: Array<InfobarAction> | undefined, disableSetting?: Common.Settings.Setting<any> | undefined);
    element: HTMLDivElement;
    _shadowRoot: DocumentFragment;
    _contentElement: any;
    _mainRow: any;
    _detailsRows: any;
    _infoContainer: any;
    _infoMessage: any;
    _infoText: any;
    _actionContainer: any;
    /** @type {?Common.Settings.Setting<*>} */
    _disableSetting: Common.Settings.Setting<any> | null;
    _closeContainer: any;
    _toggleElement: Element;
    _closeButton: any;
    /** @type {?function():*} */
    _closeCallback: (() => any) | null;
    dispose(): void;
    /**
     * @param {string} text
     */
    setText(text: string): void;
    /**
     * @param {?function():*} callback
     */
    setCloseCallback(callback: (() => any) | null): void;
    /**
     * @param {!Widget} parentView
     */
    setParentView(parentView: Widget): void;
    _parentView: Widget | undefined;
    /**
     * @param {!InfobarAction} action
     * @returns {!function():void}
     */
    _actionCallbackFactory(action: InfobarAction): () => void;
    _onResize(): void;
    _onDisable(): void;
    _onToggleDetails(): void;
    /**
     * @param {string=} message
     * @return {!Element}
     */
    createDetailsRowMessage(message?: string | undefined): Element;
}
export type InfobarAction = {
    text: string;
    highlight: boolean;
    delegate: (() => void) | null;
    dismiss: boolean;
};
/** @typedef {{
 *        text: !string,
 *        highlight: !boolean,
 *        delegate: ?function():void,
 *        dismiss: !boolean
 * }}
 */
export let InfobarAction: any;
export type Type = string;
export namespace Type {
    export const Warning: string;
    export const Info: string;
}
import * as Common from "../common/common.js";
import { Widget } from "./Widget.js";
