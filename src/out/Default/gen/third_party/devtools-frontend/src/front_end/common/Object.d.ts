/**
 * @implements {EventTarget}
 * @unrestricted
 */
export class ObjectWrapper implements EventTarget {
    /** @type {(!Map<string|symbol, !Array<!_listenerCallbackTuple>>|undefined)} */
    _listeners: (Map<string | symbol, Array<_listenerCallbackTuple>> | undefined);
    /**
     * @override
     * @param {string|symbol} eventType
     * @param {function(!EventTargetEvent):void} listener
     * @param {!Object=} thisObject
     * @return {!EventDescriptor}
     */
    addEventListener(eventType: string | symbol, listener: (arg0: EventTargetEvent) => void, thisObject?: Object | undefined): EventDescriptor;
    /**
     * @override
     * @param {string|symbol} eventType
     * @return {!Promise<*>}
     */
    once(eventType: string | symbol): Promise<any>;
    /**
     * @override
     * @param {string|symbol} eventType
     * @param {function(!EventTargetEvent):void} listener
     * @param {!Object=} thisObject
     */
    removeEventListener(eventType: string | symbol, listener: (arg0: EventTargetEvent) => void, thisObject?: Object | undefined): void;
    /**
     * @override
     * @param {string|symbol} eventType
     * @return {boolean}
     */
    hasEventListeners(eventType: string | symbol): boolean;
    /**
     * @override
     * @param {string|symbol} eventType
     * @param {*=} eventData
     */
    dispatchEventToListeners(eventType: string | symbol, eventData?: any | undefined): void;
}
export type _listenerCallbackTuple = {
    thisObject: (Object | undefined);
    listener: (arg0: EventTargetEvent) => void;
    disposed: (boolean | undefined);
};
import { EventTarget } from "./EventTarget.js";
/**
 * @typedef {!{thisObject: (!Object|undefined), listener: function(!EventTargetEvent):void, disposed: (boolean|undefined)}}
 */
declare let _listenerCallbackTuple: any;
import { EventTargetEvent } from "./EventTarget.js";
import { EventDescriptor } from "./EventTarget.js";
export {};
