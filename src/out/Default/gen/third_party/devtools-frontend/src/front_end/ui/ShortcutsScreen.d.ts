export class ShortcutsScreen {
    static registerShortcuts(): void;
    /** @type {!Object.<string, !ShortcutsSection>} */
    _sections: {
        [x: string]: ShortcutsSection;
    };
    /**
     * @param {string} name
     * @return {!ShortcutsSection}
     */
    section(name: string): ShortcutsSection;
    /**
     * @return {!Widget}
     */
    createShortcutsTabView(): Widget;
}
export namespace SourcesPanelShortcuts {
    export const SelectNextOccurrence: {
        key: number;
        name: string;
    }[];
    export const SoftUndo: {
        key: number;
        name: string;
    }[];
    export const GotoMatchingBracket: {
        key: number;
        name: string;
    }[];
    export const ToggleAutocompletion: {
        key: number;
        name: string;
    }[];
    export const IncreaseCSSUnitByOne: {
        key: number;
        name: string;
    }[];
    export const DecreaseCSSUnitByOne: {
        key: number;
        name: string;
    }[];
    export const IncreaseCSSUnitByTen: {
        key: number;
        name: string;
    }[];
    export const DecreaseCSSUnitByTen: {
        key: number;
        name: string;
    }[];
    export const EvaluateSelectionInConsole: {
        key: number;
        name: string;
    }[];
    export const AddSelectionToWatch: {
        key: number;
        name: string;
    }[];
    export const ToggleComment: {
        key: number;
        name: string;
    }[];
}
export namespace LayersPanelShortcuts {
    export const ResetView: {
        key: number;
        name: string;
    }[];
    export const PanMode: {
        key: number;
        name: string;
    }[];
    export const RotateMode: {
        key: number;
        name: string;
    }[];
    export const TogglePanRotate: {
        key: number;
        name: string;
    }[];
    export const ZoomIn: {
        key: number;
        name: string;
    }[];
    export const ZoomOut: {
        key: number;
        name: string;
    }[];
    export const Up: {
        key: number;
        name: string;
    }[];
    export const Down: {
        key: number;
        name: string;
    }[];
    export const Left: {
        key: number;
        name: string;
    }[];
    export const Right: {
        key: number;
        name: string;
    }[];
}
declare class ShortcutsSection {
    /**
     * @param {string} name
     */
    constructor(name: string);
    name: string;
    _lines: {
        key: Node;
        text: string;
    }[];
    order: number;
    /**
     * @param {!Descriptor} key
     * @param {string} description
     */
    addKey(key: Descriptor, description: string): void;
    /**
     * @param {!Array.<!Descriptor>} keys
     * @param {string} description
     */
    addRelatedKeys(keys: Array<Descriptor>, description: string): void;
    /**
     * @param {!Array.<!Descriptor>} keys
     * @param {string} description
     */
    addAlternateKeys(keys: Array<Descriptor>, description: string): void;
    /**
     * @param {!Node} keyElement
     * @param {string} description
     */
    _addLine(keyElement: Node, description: string): void;
    /**
     * @param {!Element} container
     */
    renderSection(container: Element): void;
    /**
     * @param {!Array.<!Descriptor>} sequence
     * @param {string} delimiter
     * @return {!Node}
     */
    _renderSequence(sequence: Array<Descriptor>, delimiter: string): Node;
    /**
     * @param {!Descriptor} key
     * @return {!Node}
     */
    _renderKey(key: Descriptor): Node;
    /**
     * @param {string} className
     * @param {string} textContent
     * @return {!Element}
     */
    _createSpan(className: string, textContent: string): Element;
    /**
     * @param {!Array.<!Element>} nodes
     * @param {!Element} delimiter
     * @return {!Node}
     */
    _joinNodes(nodes: Array<Element>, delimiter: Element): Node;
}
declare namespace ShortcutsSection {
    export const _sequenceNumber: number;
}
import { Widget } from "./Widget.js";
import { Descriptor } from "./KeyboardShortcut.js";
export {};
