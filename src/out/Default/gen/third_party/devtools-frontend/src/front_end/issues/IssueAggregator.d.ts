/**
 * An `AggregatedIssue` representes a number of `SDK.Issue.Issue` objects that are displayed together.
 * Currently only grouping by issue code, is supported. The class provides helpers to support displaying
 * of all resources that are affected by the aggregated issues.
 */
export class AggregatedIssue extends SDK.Issue.Issue {
    /**
     * @param {string} code
     */
    constructor(code: string);
    /** @type {!Map<string, !{cookie: !Protocol.Audits.AffectedCookie, hasRequest: boolean}>} */
    _cookies: Map<string, {
        cookie: Protocol.Audits.AffectedCookie;
        hasRequest: boolean;
    }>;
    /** @type {!Map<string, !Protocol.Audits.AffectedRequest>} */
    _requests: Map<string, Protocol.Audits.AffectedRequest>;
    /** @type {?SDK.Issue.Issue} */
    _representative: SDK.Issue.Issue | null;
    /** @type {!Map<string, !Protocol.Audits.MixedContentIssueDetails>} */
    _mixedContents: Map<string, Protocol.Audits.MixedContentIssueDetails>;
    _aggregatedIssuesCount: number;
    /**
     * @returns {!Iterable<!{cookie: !Protocol.Audits.AffectedCookie, hasRequest: boolean}>}
     */
    cookiesWithRequestIndicator(): Iterable<{
        cookie: Protocol.Audits.AffectedCookie;
        hasRequest: boolean;
    }>;
    /**
     * @return {number}
    */
    getAggregatedIssuesCount(): number;
    /**
     * Produces a primary key for a cookie. Use this instead of `JSON.stringify` in
     * case new fields are added to `AffectedCookie`.
     * @param {!Protocol.Audits.AffectedCookie} cookie
     */
    _keyForCookie(cookie: Protocol.Audits.AffectedCookie): string;
    /**
     * @param {!SDK.Issue.Issue} issue
     */
    addInstance(issue: SDK.Issue.Issue): void;
}
export class IssueAggregator extends Common.ObjectWrapper.ObjectWrapper {
    /**
     * @param {!BrowserSDK.IssuesManager.IssuesManager} issuesManager
     */
    constructor(issuesManager: BrowserSDK.IssuesManager.IssuesManager);
    /** @type {!Map<string, !AggregatedIssue>} */
    _aggregatedIssuesByCode: Map<string, AggregatedIssue>;
    /** @type {!BrowserSDK.IssuesManager.IssuesManager} */
    _issuesManager: BrowserSDK.IssuesManager.IssuesManager;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onIssueAdded(event: Common.EventTarget.EventTargetEvent): void;
    _onFullUpdateRequired(): void;
    /**
     * @param {!SDK.Issue.Issue} issue
     * @returns {!AggregatedIssue}
     */
    _aggregateIssue(issue: SDK.Issue.Issue): AggregatedIssue;
    /**
     * @returns {!Iterable<!AggregatedIssue>}
     */
    aggregatedIssues(): Iterable<AggregatedIssue>;
    /**
     * @return {number}
     */
    numberOfAggregatedIssues(): number;
}
export type Events = symbol;
export namespace Events {
    export const AggregatedIssueUpdated: symbol;
    export const FullUpdateRequired: symbol;
}
import * as SDK from "../sdk/sdk.js";
import * as Common from "../common/common.js";
import * as BrowserSDK from "../browser_sdk/browser_sdk.js";
