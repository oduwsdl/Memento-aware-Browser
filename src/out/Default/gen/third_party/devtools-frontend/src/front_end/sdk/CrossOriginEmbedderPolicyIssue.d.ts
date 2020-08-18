export class CrossOriginEmbedderPolicyIssue extends Issue {
    /**
     * @param {string} blockedReason
     * @param {string} requestId
     */
    constructor(blockedReason: string, requestId: string);
    /** @type {!Protocol.Audits.AffectedRequest} */
    _affectedRequest: Protocol.Audits.AffectedRequest;
}
import { Issue } from "./Issue.js";
