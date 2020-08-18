/**
 * @implements {ProtocolProxyApiWorkaround_TargetDispatcher}
 */
export class ChildTargetManager extends SDKModel implements ProtocolProxyApiWorkaround_TargetDispatcher {
    /**
     * @param {function({target: !Target, waitingForDebugger: boolean}):!Promise<?>=} attachCallback
     */
    static install(attachCallback?: ((arg0: {
        target: Target;
        waitingForDebugger: boolean;
    }) => Promise<unknown>) | undefined): void;
    /**
     * @param {!Target} parentTarget
     */
    constructor(parentTarget: Target);
    _targetManager: TargetManager;
    _parentTarget: Target;
    _targetAgent: ProtocolProxyApi.TargetApi;
    /** @type {!Map<string, !Protocol.Target.TargetInfo>} */
    _targetInfos: Map<string, Protocol.Target.TargetInfo>;
    /** @type {!Map<string, !Target>} */
    _childTargets: Map<string, Target>;
    /** @type {!Map<string, !ProtocolClient.InspectorBackend.Connection>} */
    _parallelConnections: Map<string, ProtocolClient.InspectorBackend.Connection>;
    /** @type {string | null} */
    _parentTargetId: string | null;
    /**
     * @return {!Protocol.UsesObjectNotation}
     */
    usesObjectNotation(): Protocol.UsesObjectNotation;
    /**
     * @override
     * @param {!Protocol.Target.TargetCreatedEvent} event
     */
    targetCreated({ targetInfo }: Protocol.Target.TargetCreatedEvent): void;
    /**
     * @override
     * @param {!Protocol.Target.TargetInfoChangedEvent} event
     */
    targetInfoChanged({ targetInfo }: Protocol.Target.TargetInfoChangedEvent): void;
    /**
     * @override
     * @param {!Protocol.Target.TargetDestroyedEvent} event
     */
    targetDestroyed({ targetId }: Protocol.Target.TargetDestroyedEvent): void;
    /**
     * @override
     * @param {!Protocol.Target.TargetCrashedEvent} event
     */
    targetCrashed({ targetId, status, errorCode }: Protocol.Target.TargetCrashedEvent): void;
    _fireAvailableTargetsChanged(): void;
    /**
     * @return {!Promise<string>}
     */
    _getParentTargetId(): Promise<string>;
    /**
     * @override
     * @param {!Protocol.Target.AttachedToTargetEvent} event
     */
    attachedToTarget({ sessionId, targetInfo, waitingForDebugger }: Protocol.Target.AttachedToTargetEvent): void;
    /**
     * @override
     * @param {!Protocol.Target.DetachedFromTargetEvent} event
     */
    detachedFromTarget({ sessionId }: Protocol.Target.DetachedFromTargetEvent): void;
    /**
     * @override
     * @param {!Protocol.Target.ReceivedMessageFromTargetEvent} event
     */
    receivedMessageFromTarget({}: Protocol.Target.ReceivedMessageFromTargetEvent): void;
    /**
     * @param {function((!Object|string)):void} onMessage
     * @return {!Promise<!ProtocolClient.InspectorBackend.Connection>}
     */
    createParallelConnection(onMessage: (arg0: (Object | string)) => void): Promise<ProtocolClient.InspectorBackend.Connection>;
    /**
     * @param {!Target} target
     * @param {string} targetId
     * @return {!Promise<!{connection: !ProtocolClient.InspectorBackend.Connection, sessionId: string}>}
     */
    _createParallelConnectionAndSessionForTarget(target: Target, targetId: string): Promise<{
        connection: ProtocolClient.InspectorBackend.Connection;
        sessionId: string;
    }>;
}
import { SDKModel } from "./SDKModel.js";
import { TargetManager } from "./SDKModel.js";
import { Target } from "./SDKModel.js";
import * as ProtocolClient from "../protocol_client/protocol_client.js";
