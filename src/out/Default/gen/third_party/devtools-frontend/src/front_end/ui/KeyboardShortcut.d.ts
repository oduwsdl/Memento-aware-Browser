export class KeyboardShortcut {
    /**
     * Creates a number encoding keyCode in the lower 8 bits and modifiers mask in the higher 8 bits.
     * It is useful for matching pressed keys.
     *
     * @param {number|string} keyCode The code of the key, or a character "a-z" which is converted to a keyCode value.
     * @param {number=} modifiers Optional list of modifiers passed as additional parameters.
     * @return {number}
     */
    static makeKey(keyCode: number | string, modifiers?: number | undefined): number;
    /**
     * @param {?KeyboardEvent} keyboardEvent
     * @return {number}
     */
    static makeKeyFromEvent(keyboardEvent: KeyboardEvent | null): number;
    /**
     * @param {?KeyboardEvent} keyboardEvent
     * @return {number}
     */
    static makeKeyFromEventIgnoringModifiers(keyboardEvent: KeyboardEvent | null): number;
    /**
     * @param {(?KeyboardEvent|?MouseEvent)} event
     * @return {boolean}
     */
    static eventHasCtrlOrMeta(event: ((KeyboardEvent | (MouseEvent | null)) | null)): boolean;
    /**
     * @param {!Event} event
     * @return {boolean}
     */
    static hasNoModifiers(event: Event): boolean;
    /**
     * @param {string|!Key} key
     * @param {number=} modifiers
     * @return {!Descriptor}
     */
    static makeDescriptor(key: string | Key, modifiers?: number | undefined): Descriptor;
    /**
     * @param {string} shortcut
     * @return {?Descriptor}
     */
    static makeDescriptorFromBindingShortcut(shortcut: string): Descriptor | null;
    /**
     * @param {string|!Key} key
     * @param {number=} modifiers
     * @return {string}
     */
    static shortcutToString(key: string | Key, modifiers?: number | undefined): string;
    /**
     * @param {string|!Key} key
     * @return {string}
     */
    static _keyName(key: string | Key): string;
    /**
     * @param {number} keyCode
     * @param {?number} modifiers
     * @return {number}
     */
    static _makeKeyFromCodeAndModifiers(keyCode: number, modifiers: number | null): number;
    /**
     * @param {number} key
     * @return {!{keyCode: number, modifiers: number}}
     */
    static keyCodeAndModifiersFromKey(key: number): {
        keyCode: number;
        modifiers: number;
    };
    /**
     * @param {number} key
     * @return {boolean}
     */
    static isModifier(key: number): boolean;
    /**
     * @param {number|undefined} modifiers
     * @return {string}
     */
    static _modifiersToString(modifiers: number | undefined): string;
    /**
     * @param {!Array.<!Descriptor>} descriptors
     * @param {string} action
     * @param {!Type} type
     * @param {string=} keybindSet
     */
    constructor(descriptors: Array<Descriptor>, action: string, type: Type, keybindSet?: string | undefined);
    descriptors: {
        key: number;
        name: string;
    }[];
    action: string;
    type: symbol;
    keybindSet: string | undefined;
    /**
     * @return {string}
     */
    title(): string;
}
export namespace Modifiers {
    export const None: number;
    export const Shift: number;
    export const Ctrl: number;
    export const Alt: number;
    export const Meta: number;
}
/** @type {!Object.<string, !Key>} */
export const Keys: {
    [x: string]: Key;
};
export type Type = symbol;
export namespace Type {
    export const UserShortcut: symbol;
    export const DefaultShortcut: symbol;
    export const DisabledDefault: symbol;
    export const UnsetShortcut: symbol;
    export const KeybindSetShortcut: symbol;
}
export const KeyBindings: {};
export type Key = {
    code: number;
    name: (string | {
        [x: string]: string;
    });
};
/** @typedef {!{code: number, name: (string|!Object.<string, string>)}} */
export let Key: any;
export type Descriptor = {
    key: number;
    name: string;
};
/** @typedef {!{key: number, name: string}} */
export let Descriptor: any;
