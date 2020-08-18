export class ThrottledWidget extends VBox {
    /**
     * @param {boolean=} isWebComponent
     * @param {number=} timeout
     */
    constructor(isWebComponent?: boolean | undefined, timeout?: number | undefined);
    _updateThrottler: Common.Throttler.Throttler;
    _updateWhenVisible: boolean;
    /**
     * @protected
     * @return {!Promise<?>}
     */
    protected doUpdate(): Promise<unknown>;
    update(): void;
}
import { VBox } from "./Widget.js";
import * as Common from "../common/common.js";
