export class Action extends Common.ObjectWrapper.ObjectWrapper {
    /**
     * @param {!Root.Runtime.Extension} extension
     */
    constructor(extension: any);
    _extension: any;
    _enabled: any;
    _toggled: any;
    /**
     * @return {string}
     */
    id(): string;
    /**
     * @return {!Root.Runtime.Extension}
     */
    extension(): any;
    /**
     * @return {!Promise.<boolean>}
     */
    execute(): Promise<boolean>;
    /**
     * @return {string}
     */
    icon(): string;
    /**
     * @return {string}
     */
    toggledIcon(): string;
    /**
     * @return {boolean}
     */
    toggleWithRedColor(): boolean;
    /**
     * @param {boolean} enabled
     */
    setEnabled(enabled: boolean): void;
    /**
     * @return {boolean}
     */
    enabled(): boolean;
    /**
     * @return {string}
     */
    category(): string;
    /**
     * @return {string}
     */
    tags(): string;
    /**
     * @return {boolean}
     */
    toggleable(): boolean;
    /**
     * @return {string}
     */
    title(): string;
    /**
     * @return {boolean}
     */
    toggled(): boolean;
    /**
     * @param {boolean} toggled
     */
    setToggled(toggled: boolean): void;
}
export type Events = symbol;
export namespace Events {
    export const Enabled: symbol;
    export const Toggled: symbol;
}
import * as Common from "../common/common.js";
