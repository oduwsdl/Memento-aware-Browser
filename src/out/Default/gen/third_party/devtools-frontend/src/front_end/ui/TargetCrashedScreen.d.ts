export class TargetCrashedScreen extends VBox {
    /**
     * @param {function():*} hideCallback
     */
    constructor(hideCallback: () => any);
    _hideCallback: () => any;
}
import { VBox } from "./Widget.js";
