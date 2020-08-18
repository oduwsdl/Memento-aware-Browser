/**
 * @param {!Array<!SDK.Issue.Issue>} issues
 * @param {!IssuesAssociatable} obj
 * @return {!Array<!SDK.Issue.Issue>}
 * @throws In case obj has an unsupported type (i.e. not part of the IssuesAssociatble union).
 */
export function issuesAssociatedWith(issues: Array<SDK.Issue.Issue>, obj: IssuesAssociatable): Array<SDK.Issue.Issue>;
/**
 * @param {!IssuesAssociatable} obj
 * @return {boolean}
 */
export function hasIssues(obj: IssuesAssociatable): boolean;
/**
 * @param {!IssuesAssociatable} obj
 * @param {!SDK.Issue.IssueCategory} category
 * @return {boolean}
 */
export function hasIssueOfCategory(obj: IssuesAssociatable, category: SDK.Issue.IssueCategory): boolean;
/**
 * @param {!IssuesAssociatable} obj
 * @param {!SDK.Issue.IssueCategory=} category
 * @return {!Promise<undefined | void>}
 */
export function reveal(obj: IssuesAssociatable, category?: SDK.Issue.IssueCategory | undefined): Promise<undefined | void>;
export type IssuesAssociatable = SDK.NetworkRequest.NetworkRequest | SDK.Cookie.Cookie;
/**
 * @typedef {!SDK.NetworkRequest.NetworkRequest | !SDK.Cookie.Cookie}
 */
export let IssuesAssociatable: any;
import * as SDK from "../sdk/sdk.js";
