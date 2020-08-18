/**
 * @interface
 */
export class ActionDelegate {
    /**
     * @param {!Context} context
     * @param {string} actionId
     * @return {boolean}
     */
    handleAction(context: Context, actionId: string): boolean;
}
import { Context } from "./Context.js";
