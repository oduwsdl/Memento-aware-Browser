export class RemoteDebuggingTerminatedScreen extends VBox {
    /**
     * @param {string} reason
     */
    static show(reason: string): void;
    /**
     * @param {string} reason
     */
    constructor(reason: string);
}
import { VBox } from "./Widget.js";
