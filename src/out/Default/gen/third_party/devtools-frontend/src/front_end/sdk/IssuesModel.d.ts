/**
 * This class generates issues in the front-end based on information provided by the network panel. In the long
 * term, we might move this reporting to the back-end, but the current COVID-19 policy requires us to tone down
 * back-end changes until we are back at normal release cycle.
 */
export class NetworkIssueDetector {
    /**
     * @param {!Target} target
     * @param {!IssuesModel} issuesModel
     */
    constructor(target: Target, issuesModel: IssuesModel);
    _issuesModel: IssuesModel;
    _networkManager: any;
    /**
     * @param {!{data:*}} event
     */
    _handleRequestFinished(event: {
        data: any;
    }): void;
    detach(): void;
}
/**
 * The `IssuesModel` is a thin dispatch that does not store issues, but only creates the representation
 * class (usually derived from `Issue`) and passes the instances on via a dispatched event.
 * We chose this approach here because the lifetime of the Model is tied to the target, but DevTools
 * wants to preserve issues for targets (e.g. iframes) that are already gone as well.
 * @implements {ProtocolProxyApiWorkaround_AuditsDispatcher}
 */
export class IssuesModel extends SDKModel implements ProtocolProxyApiWorkaround_AuditsDispatcher {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _enabled: boolean;
    /** @type {*} */
    _auditsAgent: any;
    _networkIssueDetector: NetworkIssueDetector | null;
    /**
     * @return {!Protocol.UsesObjectNotation}
     */
    usesObjectNotation(): Protocol.UsesObjectNotation;
    ensureEnabled(): void;
    /**
     * @override
     * @param {!Protocol.Audits.IssueAddedEvent} issueAddedEvent
     */
    issueAdded(issueAddedEvent: Protocol.Audits.IssueAddedEvent): void;
    /**
     * @param {!Issue} issue
     */
    addIssue(issue: Issue): void;
    /**
     * Each issue reported by the backend can result in multiple {!Issue} instances.
     * Handlers are simple functions hard-coded into a map.
     * @param {!Protocol.Audits.InspectorIssue} inspectorIssue} inspectorIssue
     * @return {!Array<!Issue>}
     */
    _createIssuesFromProtocolIssue(inspectorIssue: Protocol.Audits.InspectorIssue): Array<Issue>;
}
export type Events = symbol;
export namespace Events {
    export const IssueAdded: symbol;
}
import { Target } from "./SDKModel.js";
import { SDKModel } from "./SDKModel.js";
import { Issue } from "./Issue.js";
