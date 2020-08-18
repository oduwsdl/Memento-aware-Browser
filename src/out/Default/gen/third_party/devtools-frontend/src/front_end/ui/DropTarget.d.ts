/**
 * @unrestricted
 */
export class DropTarget {
    /**
     * @param {!Element} element
     * @param {!Array<{kind: string, type: !RegExp}>} transferTypes
     * @param {string} messageText
     * @param {function(!DataTransfer):*} handleDrop
     */
    constructor(element: Element, transferTypes: Array<{
        kind: string;
        type: RegExp;
    }>, messageText: string, handleDrop: (arg0: DataTransfer) => any);
    _element: Element;
    _transferTypes: {
        kind: string;
        type: RegExp;
    }[];
    _messageText: string;
    _handleDrop: (arg0: DataTransfer) => any;
    _enabled: boolean;
    /**
     * @param {boolean} enabled
     */
    setEnabled(enabled: boolean): void;
    /**
     * @param {!Event} event
     */
    _onDragEnter(event: Event): void;
    /**
     * @param {!Event} event
     * @return {boolean}
     */
    _hasMatchingType(event: Event): boolean;
    /**
     * @param {!Event} event
     */
    _onDragOver(event: Event): void;
    _dragMaskElement: Element | undefined;
    /**
     * @param {!Event} event
     */
    _onDrop(event: Event): void;
    /**
     * @param {!Event} event
     */
    _onDragLeave(event: Event): void;
    _removeMask(): void;
}
export namespace Type {
    export const URI: {
        kind: string;
        type: RegExp;
    };
    export const Folder: {
        kind: string;
        type: RegExp;
    };
    export const File: {
        kind: string;
        type: RegExp;
    };
    export const WebFile: {
        kind: string;
        type: RegExp;
    };
    export const ImageFile: {
        kind: string;
        type: RegExp;
    };
}
