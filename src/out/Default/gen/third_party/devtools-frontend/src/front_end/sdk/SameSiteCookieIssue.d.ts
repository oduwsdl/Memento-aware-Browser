export class SameSiteCookieIssue extends Issue {
    /**
     * Calculates an issue code from a reason and an operation. All these together
     * can uniquely identify a specific SameSite cookie issue.
     *
     * @param {!Protocol.Audits.SameSiteCookieExclusionReason|!Protocol.Audits.SameSiteCookieWarningReason} reason
     * @param {!Protocol.Audits.SameSiteCookieOperation} operation
     * @param {string|undefined} cookieUrl
     */
    static codeForSameSiteDetails(reason: Protocol.Audits.SameSiteCookieExclusionReason | Protocol.Audits.SameSiteCookieWarningReason, operation: Protocol.Audits.SameSiteCookieOperation, cookieUrl: string | undefined): string;
    /**
     * @param {string} code
     * @param {!Protocol.Audits.SameSiteCookieIssueDetails} issueDetails
     */
    constructor(code: string, issueDetails: Protocol.Audits.SameSiteCookieIssueDetails);
    _issueDetails: Protocol.Audits.SameSiteCookieIssueDetails;
}
import { Issue } from "./Issue.js";
