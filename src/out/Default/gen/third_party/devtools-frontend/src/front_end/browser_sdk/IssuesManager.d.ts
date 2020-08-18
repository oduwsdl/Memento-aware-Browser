/**
 * The `IssuesManager` is the central storage for issues. It collects issues from all the
 * `IssuesModel` instances in the page, and deduplicates them wrt their primary key.
 * It also takes care of clearing the issues when it sees a main-frame navigated event.
 * Any client can subscribe to the events provided, and/or query the issues via the public
 * interface.
 *
 * @implements {SDK.SDKModel.SDKModelObserver<!SDK.IssuesModel.IssuesModel>}
 */
export class IssuesManager extends Common.ObjectWrapper.ObjectWrapper implements SDK.SDKModel.SDKModelObserver<SDK.IssuesModel.IssuesModel> {
    /**
     * @param {{forceNew: boolean}} opts
     * @return {!IssuesManager}
     */
    static instance({ forceNew }?: {
        forceNew: boolean;
    }): IssuesManager;
    /** @type {!WeakMap<!SDK.IssuesModel.IssuesModel, !Common.EventTarget.EventDescriptor>} */
    _eventListeners: WeakMap<SDK.IssuesModel.IssuesModel, Common.EventTarget.EventDescriptor>;
    /** @type {!Map<string, !SDK.Issue.Issue>} */
    _issues: Map<string, SDK.Issue.Issue>;
    _hasSeenMainFrameNavigated: boolean;
    /**
     * Once we have seen at least one `MainFrameNavigated` event, we can be reasonably sure
     * that we also collected issues that were reported during the navigation to the current
     * page. If we haven't seen a main frame navigated, we might have missed issues that arose
     * during navigation.
     *
     * @return {boolean}
     */
    reloadForAccurateInformationRequired(): boolean;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onMainFrameNavigated(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @override
     * @param {!SDK.IssuesModel.IssuesModel} issuesModel
     */
    modelAdded(issuesModel: SDK.IssuesModel.IssuesModel): void;
    /**
     * @override
     * @param {!SDK.IssuesModel.IssuesModel} issuesModel
     */
    modelRemoved(issuesModel: SDK.IssuesModel.IssuesModel): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _issueAdded(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @return {!Iterable<!SDK.Issue.Issue>}
     */
    issues(): Iterable<SDK.Issue.Issue>;
    /**
     * @return {number}
     */
    numberOfIssues(): number;
}
export type Events = symbol;
export namespace Events {
    export const IssuesCountUpdated: symbol;
    export const IssueAdded: symbol;
    export const FullUpdateRequired: symbol;
}
import * as Common from "../common/common.js";
import * as SDK from "../sdk/sdk.js";
