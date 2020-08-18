/**
 * The FrameManager is a central storage for all frames. It collects frames from all
 * ResourceTreeModel-instances (one per target), so that frames can be found by id
 * without needing to know their target.
 * @implements {SDK.SDKModel.SDKModelObserver<!SDK.ResourceTreeModel.ResourceTreeModel>}
 */
export class FrameManager extends Common.ObjectWrapper.ObjectWrapper implements SDK.SDKModel.SDKModelObserver<SDK.ResourceTreeModel.ResourceTreeModel> {
    /**
     * @param {{forceNew: boolean}} opts
     * @return {!FrameManager}
     */
    static instance({ forceNew }?: {
        forceNew: boolean;
    }): FrameManager;
    /** @type {!WeakMap<!SDK.ResourceTreeModel.ResourceTreeModel, !Array<!Common.EventTarget.EventDescriptor>>} */
    _eventListeners: WeakMap<SDK.ResourceTreeModel.ResourceTreeModel, Array<Common.EventTarget.EventDescriptor>>;
    /** @type {!Map<string, {frame: !SDK.ResourceTreeModel.ResourceTreeFrame, count: number}>} */
    _frames: Map<string, {
        frame: SDK.ResourceTreeModel.ResourceTreeFrame;
        count: number;
    }>;
    /** @type {!Map<string, !Set<string>>} */
    _framesForTarget: Map<string, Set<string>>;
    /**
     * @override
     * @param {!SDK.ResourceTreeModel.ResourceTreeModel} resourceTreeModel
     */
    modelAdded(resourceTreeModel: SDK.ResourceTreeModel.ResourceTreeModel): void;
    /**
     * @override
     * @param {!SDK.ResourceTreeModel.ResourceTreeModel} resourceTreeModel
     */
    modelRemoved(resourceTreeModel: SDK.ResourceTreeModel.ResourceTreeModel): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _frameAdded(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _frameDetached(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {string} frameId
     */
    decreaseOrRemoveFrame(frameId: string): void;
    /**
     * Returns the ResourceTreeFrame with a given frameId.
     * When a frame is being detached a new ResourceTreeFrame but with the same
     * frameId is created. Consequently getFrame() will return a different
     * ResourceTreeFrame after detachment. Callers of getFrame() should therefore
     * immediately use the function return value and not store it for later use.
     * @param {string} frameId
     * @return {?SDK.ResourceTreeModel.ResourceTreeFrame}
     */
    getFrame(frameId: string): SDK.ResourceTreeModel.ResourceTreeFrame | null;
}
export type Events = symbol;
export namespace Events {
    export const FrameAddedToTarget: symbol;
    export const FrameRemoved: symbol;
}
import * as Common from "../common/common.js";
import * as SDK from "../sdk/sdk.js";
