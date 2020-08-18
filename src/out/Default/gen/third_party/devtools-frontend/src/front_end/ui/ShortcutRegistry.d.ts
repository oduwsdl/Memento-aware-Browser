export class ShortcutRegistry {
    /**
     * @param {!ActionRegistry} actionRegistry
     */
    constructor(actionRegistry: ActionRegistry);
    _actionRegistry: ActionRegistry;
    /** @type {!Platform.Multimap.<number, !KeyboardShortcut>} */
    _keyToShortcut: Platform.Multimap<number, KeyboardShortcut>;
    /** @type {!Platform.Multimap.<string, !KeyboardShortcut>} */
    _actionToShortcut: Platform.Multimap<string, KeyboardShortcut>;
    _keyMap: ShortcutTreeNode;
    /** @type {?ShortcutTreeNode} */
    _activePrefixKey: ShortcutTreeNode | null;
    /** @type {?number} */
    _activePrefixTimeout: number | null;
    /** @type {?function():Promise<void>} */
    _consumePrefix: (() => Promise<void>) | null;
    /**
     * @param {number} key
     * @param {!Object.<string, function():Promise.<boolean>>=} handlers
     * @return {!Array.<!Action>}
     */
    _applicableActions(key: number, handlers?: {
        [x: string]: () => Promise<boolean>;
    } | undefined): Array<Action>;
    /**
     * @param {string} action
     * @return {!Array.<!KeyboardShortcut>}
     */
    shortcutsForAction(action: string): Array<KeyboardShortcut>;
    /**
     * @return {!Array<number>}
     */
    globalShortcutKeys(): Array<number>;
    /**
     * @deprecated this function is obsolete and will be removed in the
     * future along with the legacy shortcuts settings tab
     * crbug.com/174309
     *
     * @param {string} actionId
     * @return {!Array.<!Descriptor>}
     */
    shortcutDescriptorsForAction(actionId: string): Array<Descriptor>;
    /**
     * @param {!Array.<string>} actionIds
     * @return {!Array.<number>}
     */
    keysForActions(actionIds: Array<string>): Array<number>;
    /**
     * @param {string} actionId
     * @return {string|undefined}
     */
    shortcutTitleForAction(actionId: string): string | undefined;
    /**
     * @param {!KeyboardEvent} event
     * @param {!Object.<string, function():Promise.<boolean>>=} handlers
     */
    handleShortcut(event: KeyboardEvent, handlers?: {
        [x: string]: () => Promise<boolean>;
    } | undefined): void;
    /**
     * @param {!Element} element
     * @param {!Object.<string, function():Promise.<boolean>>} handlers
     */
    addShortcutListener(element: Element, handlers: {
        [x: string]: () => Promise<boolean>;
    }): void;
    /**
     * @param {number} key
     * @param {string} domKey
     * @param {!KeyboardEvent=} event
     * @param {!Object.<string, function():Promise.<boolean>>=} handlers
     */
    handleKey(key: number, domKey: string, event?: KeyboardEvent | undefined, handlers?: {
        [x: string]: () => Promise<boolean>;
    } | undefined): Promise<void>;
    /**
     * @param {!KeyboardShortcut} shortcut
     */
    _registerShortcut(shortcut: KeyboardShortcut): void;
    _registerBindings(): void;
}
export class ShortcutTreeNode {
    /**
     * @param {number} key
     * @param {number=} depth
     */
    constructor(key: number, depth?: number | undefined);
    _key: number;
    /** @type {!Array.<string>} */
    _actions: Array<string>;
    _chords: Map<any, any>;
    _depth: number;
    /**
     * @param {string} action
     */
    addAction(action: string): void;
    /**
     * @return {number}
     */
    key(): number;
    /**
     * @return {!Map.<number, !ShortcutTreeNode>}
     */
    chords(): Map<number, ShortcutTreeNode>;
    /**
     * @return {boolean}
     */
    hasChords(): boolean;
    /**
     * @param {!Array.<number>} keys
     * @param {string} action
     */
    addKeyMapping(keys: Array<number>, action: string): void;
    /**
     * @param {number} key
     * @return {?ShortcutTreeNode}
     */
    getNode(key: number): ShortcutTreeNode | null;
    /**
     * @return {!Array.<string>}
     */
    actions(): Array<string>;
    clear(): void;
}
export class ForwardedShortcut {
}
export namespace ForwardedShortcut {
    export const instance: ForwardedShortcut;
}
export const ForwardedActions: Set<string>;
export const KeyTimeout: 1000;
export const DefaultShortcutSetting: "devToolsDefault";
import { ActionRegistry } from "./ActionRegistry.js";
import * as Platform from "../platform/platform.js";
import { KeyboardShortcut } from "./KeyboardShortcut.js";
import { Action } from "./Action.js";
import { Descriptor } from "./KeyboardShortcut.js";
