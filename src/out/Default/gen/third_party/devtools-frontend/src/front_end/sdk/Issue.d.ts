export type IssueCategory = symbol;
export namespace IssueCategory {
    export const CrossOriginEmbedderPolicy: symbol;
    export const MixedContent: symbol;
    export const SameSiteCookie: symbol;
    export const Other: symbol;
}
export type IssueKind = symbol;
export namespace IssueKind {
    export const BreakingChange: symbol;
}
export type IssueDescription = {
    title: string;
    message: (() => Element);
    issueKind: IssueKind;
    links: Array<{
        link: string;
        linkTitle: string;
    }>;
};
/**
 * @typedef {{
  *            title:string,
  *            message: (function():!Element),
  *            issueKind: !IssueKind,
  *            links: !Array<!{link: string, linkTitle: string}>
  *          }}
  */
export let IssueDescription: any;
export type AffectedElement = {
    backendNodeId: number;
    nodeName: string;
};
/**
 * @typedef {{
  *            backendNodeId: number,
  *            nodeName: string
  *          }}
  */
export let AffectedElement: any;
export type AffectedSource = {
    columnNumber: (number | undefined);
    lineNumber: number;
    url: string;
};
/**
 * @typedef {{
 *            columnNumber: (number|undefined),
 *            lineNumber: number,
 *            url: string
 *          }}
 */
export let AffectedSource: any;
/**
 * @abstract
 */
export class Issue extends Common.ObjectWrapper.ObjectWrapper {
    /**
     * @param {string} code
     */
    constructor(code: string);
    /** @type {string} */
    _code: string;
    /**
     * @return {string}
     */
    code(): string;
    /**
     * @return {string}
     */
    primaryKey(): string;
    /**
     * @return {!Iterable<!Protocol.Audits.AffectedCookie>}
     */
    cookies(): Iterable<Protocol.Audits.AffectedCookie>;
    /**
     * @return {!Iterable<!AffectedElement>}
     */
    elements(): Iterable<AffectedElement>;
    /**
     * @returns {!Iterable<!Protocol.Audits.MixedContentIssueDetails>}
     */
    mixedContents(): Iterable<Protocol.Audits.MixedContentIssueDetails>;
    /**
     * @return {!Iterable<!Protocol.Audits.AffectedRequest>}
     */
    requests(): Iterable<Protocol.Audits.AffectedRequest>;
    /**
     * @returns {!Iterable<!AffectedSource>}
     */
    sources(): Iterable<AffectedSource>;
    /**
     * @param {string} requestId
     * @return {boolean}
     */
    isAssociatedWithRequestId(requestId: string): boolean;
    /**
     * @return {?IssueDescription}
     */
    getDescription(): IssueDescription | null;
    /**
     * @return {!IssueCategory}
     */
    getCategory(): IssueCategory;
}
import * as Common from "../common/common.js";
