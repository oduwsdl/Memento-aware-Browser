/**
 * @param {!Array<!EventDescriptor>} eventList
 */
export function removeEventListeners(eventList: Array<EventDescriptor>): void;
/**
 * @param {string} name
 * @param {*} detail
 * @param {!HTMLElement | !Window} target
 */
export function fireEvent(name: string, detail?: any, target?: HTMLElement | Window): void;
export type EventDescriptor = {
    eventTarget: EventTarget;
    eventType: (string | symbol);
    thisObject: (Object | undefined);
    listener: (arg0: EventTargetEvent) => void;
};
/**
 * @typedef {!{eventTarget: !EventTarget, eventType: (string|symbol), thisObject: (!Object|undefined), listener: function(!EventTargetEvent):void}}
 */
export let EventDescriptor: any;
/**
 * @interface
 */
export class EventTarget {
    /**
     * @param {symbol} eventType
     * @param {function(!EventTargetEvent):void} listener
     * @param {!Object=} thisObject
     * @return {!EventDescriptor}
     */
    addEventListener(eventType: symbol, listener: (arg0: EventTargetEvent) => void, thisObject?: Object | undefined): EventDescriptor;
    /**
     * @param {string|symbol} eventType
     * @return {!Promise<*>}
     */
    once(eventType: string | symbol): Promise<any>;
    /**
     * @param {string|symbol} eventType
     * @param {function(!EventTargetEvent):void} listener
     * @param {!Object=} thisObject
     */
    removeEventListener(eventType: string | symbol, listener: (arg0: EventTargetEvent) => void, thisObject?: Object | undefined): void;
    /**
     * @param {symbol} eventType
     * @return {boolean}
     */
    hasEventListeners(eventType: symbol): boolean;
    /**
     * @param {symbol} eventType
     * @param {*=} eventData
     */
    dispatchEventToListeners(eventType: symbol, eventData?: any | undefined): void;
}
export namespace EventTarget {
    export { removeEventListeners };
}
export type EventTargetEvent = {
    data: any;
};
/**
 * @typedef {!{data: *}}
 */
export let EventTargetEvent: any;
