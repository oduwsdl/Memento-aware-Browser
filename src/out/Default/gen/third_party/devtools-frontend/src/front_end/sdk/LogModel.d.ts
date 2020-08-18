/**
 * @implements {Protocol.LogDispatcher}
 */
export class LogModel extends SDKModel {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _logAgent: any;
    /**
     * @override
     * @param {!Protocol.Log.LogEntry} payload
     */
    entryAdded(payload: Protocol.Log.LogEntry): void;
    requestClear(): void;
}
export type Events = symbol;
export namespace Events {
    export const EntryAdded: symbol;
}
import { SDKModel } from "./SDKModel.js";
import { Target } from "./SDKModel.js";
