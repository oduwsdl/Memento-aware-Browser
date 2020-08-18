export class ActionRegistry {
    /** @type {!Map.<string, !Action>} */
    _actionsById: Map<string, Action>;
    _registerActions(): void;
    /**
     * @return {!Array.<!Action>}
     */
    availableActions(): Array<Action>;
    /**
     * @return {!Array.<!Action>}
     */
    actions(): Array<Action>;
    /**
     * @param {!Array.<string>} actionIds
     * @param {!Context} context
     * @return {!Array.<!Action>}
     */
    applicableActions(actionIds: Array<string>, context: Context): Array<Action>;
    /**
     * @param {string} actionId
     * @return {?Action}
     */
    action(actionId: string): Action | null;
}
import { Action } from "./Action.js";
import { Context } from "./Context.js";
