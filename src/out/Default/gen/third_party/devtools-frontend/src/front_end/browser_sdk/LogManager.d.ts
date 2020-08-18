/**
 * @implements {SDK.SDKModel.SDKModelObserver<!SDK.LogModel.LogModel>}
 */
export class LogManager implements SDK.SDKModel.SDKModelObserver<SDK.LogModel.LogModel> {
    /**
     * @override
     * @param {!SDK.LogModel.LogModel} logModel
     */
    modelAdded(logModel: SDK.LogModel.LogModel): void;
    /**
     * @override
     * @param {!SDK.LogModel.LogModel} logModel
     */
    modelRemoved(logModel: SDK.LogModel.LogModel): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _logEntryAdded(event: Common.EventTarget.EventTargetEvent): void;
}
import * as SDK from "../sdk/sdk.js";
import * as Common from "../common/common.js";
