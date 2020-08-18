export class Context {
    _flavors: Map<any, any>;
    _eventDispatchers: Map<any, any>;
    /**
     * @param {function(new:T, ...):void} flavorType
     * @param {?T} flavorValue
     * @template T
     */
    setFlavor<T>(flavorType: new (...arg1: any[]) => T, flavorValue: T | null): void;
    /**
     * @param {function(new:T, ...):void} flavorType
     * @param {?T} flavorValue
     * @template T
     */
    _dispatchFlavorChange<T_1>(flavorType: new (...arg1: any[]) => T_1, flavorValue: T_1 | null): void;
    /**
     * @param {function(new:Object, ...):void} flavorType
     * @param {function(!Common.EventTarget.EventTargetEvent):*} listener
     * @param {!Object=} thisObject
     */
    addFlavorChangeListener(flavorType: new (...args: any[]) => Object, listener: (arg0: Common.EventTarget.EventTargetEvent) => any, thisObject?: Object | undefined): void;
    /**
     * @param {function(new:Object, ...):void} flavorType
     * @param {function(!Common.EventTarget.EventTargetEvent):*} listener
     * @param {!Object=} thisObject
     */
    removeFlavorChangeListener(flavorType: new (...args: any[]) => Object, listener: (arg0: Common.EventTarget.EventTargetEvent) => any, thisObject?: Object | undefined): void;
    /**
     * @param {function(new:T, ...):void} flavorType
     * @return {?T}
     * @template T
     */
    flavor<T_2>(flavorType: new (...arg1: any[]) => T_2): T_2 | null;
    /**
     * @return {!Set.<function(new:Object, ...)>}
     */
    flavors(): Set<new (...args: any[]) => Object>;
    /**
     * @param {!Array.<!Root.Runtime.Extension>} extensions
     * @return {!Set.<!Root.Runtime.Extension>}
     */
    applicableExtensions(extensions: Array<any>): Set<any>;
}
export type Events = symbol;
import * as Common from "../common/common.js";
