export class MixedContentIssue extends Issue {
    /**
     * @param {string} resolutionStatus
     * @returns {!string}
     */
    static translateStatus(resolutionStatus: string): string;
    /**
     * @param {!Protocol.Audits.MixedContentIssueDetails} issueDetails
     */
    constructor(issueDetails: Protocol.Audits.MixedContentIssueDetails);
    _issueDetails: Protocol.Audits.MixedContentIssueDetails;
}
import { Issue } from "./Issue.js";
