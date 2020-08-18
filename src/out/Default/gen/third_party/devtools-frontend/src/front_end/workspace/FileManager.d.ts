/**
 * @unrestricted
 */
export class FileManager extends Common.ObjectWrapper.ObjectWrapper {
    /** @type {!Map<string, function(?{fileSystemPath: (string|undefined)}):void>} */
    _saveCallbacks: Map<string, (arg0: {
        fileSystemPath: (string | undefined);
    } | null) => void>;
    /**
     * @param {string} url
     * @param {string} content
     * @param {boolean} forceSaveAs
     * @return {!Promise<?{fileSystemPath: (string|undefined)}>}
     */
    save(url: string, content: string, forceSaveAs: boolean): Promise<{
        fileSystemPath: (string | undefined);
    } | null>;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _savedURL(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _canceledSavedURL(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {string} url
     * @param {string} content
     */
    append(url: string, content: string): void;
    /**
     * @param {string} url
     */
    close(url: string): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _appendedToURL(event: Common.EventTarget.EventTargetEvent): void;
}
export type Events = symbol;
export namespace Events {
    export const AppendedToURL: symbol;
}
import * as Common from "../common/common.js";
