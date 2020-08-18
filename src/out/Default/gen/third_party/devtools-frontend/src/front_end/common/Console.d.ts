/**
 * @unrestricted
 */
export class Console extends ObjectWrapper {
    /**
     * @param {{forceNew: boolean}} opts
     */
    static instance({ forceNew }?: {
        forceNew: boolean;
    }): Console;
    /** @type {!Array.<!Message>} */
    _messages: Array<Message>;
    /**
     * @param {string} text
     * @param {!MessageLevel} level
     * @param {boolean=} show
     */
    addMessage(text: string, level: MessageLevel, show?: boolean | undefined): void;
    /**
     * @param {string} text
     */
    log(text: string): void;
    /**
     * @param {string} text
     */
    warn(text: string): void;
    /**
     * @param {string} text
     */
    error(text: string): void;
    /**
     * @return {!Array.<!Message>}
     */
    messages(): Array<Message>;
    show(): void;
    /**
     * @return {!Promise.<undefined>}
     */
    showPromise(): Promise<undefined>;
}
export type Events = symbol;
export namespace Events {
    export const MessageAdded: symbol;
}
export type MessageLevel = string;
export namespace MessageLevel {
    export const Info: string;
    export const Warning: string;
    export const Error: string;
}
/**
 * @unrestricted
 */
export class Message {
    /**
     * @param {string} text
     * @param {!MessageLevel} level
     * @param {number} timestamp
     * @param {boolean} show
     */
    constructor(text: string, level: MessageLevel, timestamp: number, show: boolean);
    text: string;
    level: string;
    timestamp: number;
    show: boolean;
}
import { ObjectWrapper } from "./Object.js";
