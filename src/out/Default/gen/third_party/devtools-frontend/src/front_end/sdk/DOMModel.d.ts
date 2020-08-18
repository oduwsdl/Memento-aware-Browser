/**
 * @unrestricted
 */
export class DOMNode {
    /**
     * @param {!DOMModel} domModel
     * @param {?DOMDocument} doc
     * @param {boolean} isInShadowTree
     * @param {!Protocol.DOM.Node} payload
     * @return {!DOMNode}
     */
    static create(domModel: DOMModel, doc: DOMDocument | null, isInShadowTree: boolean, payload: Protocol.DOM.Node): DOMNode;
    /**
     * @param {!DOMModel} domModel
     */
    constructor(domModel: DOMModel);
    _domModel: DOMModel;
    /**
     * @param {?DOMDocument} doc
     * @param {boolean} isInShadowTree
     * @param {!Protocol.DOM.Node} payload
     */
    _init(doc: DOMDocument | null, isInShadowTree: boolean, payload: Protocol.DOM.Node): void;
    _agent: any;
    ownerDocument: DOMDocument | null | undefined;
    _isInShadowTree: boolean | undefined;
    id: number | undefined;
    _backendNodeId: number | undefined;
    _nodeType: number | undefined;
    _nodeName: string | undefined;
    _localName: string | undefined;
    _nodeValue: string | undefined;
    _pseudoType: Protocol.DOM.PseudoType | undefined;
    _shadowRootType: Protocol.DOM.ShadowRootType | undefined;
    _frameOwnerFrameId: string | null | undefined;
    _xmlVersion: string | undefined;
    _isSVGNode: boolean | undefined;
    _creationStackTrace: any;
    _shadowRoots: any[] | undefined;
    /** @type {!Map<string, !Attribute>} */
    _attributes: Map<string, {
        name: string;
        value: string;
        _node: DOMNode;
    }> | undefined;
    /** @type {!Map<string, ?>} */
    _markers: Map<string, any> | undefined;
    _subtreeMarkerCount: number | undefined;
    _childNodeCount: number | undefined;
    _children: any[] | null | undefined;
    nextSibling: any;
    previousSibling: any;
    firstChild: any;
    lastChild: any;
    parentNode: any;
    _templateContent: DOMNode | undefined;
    _contentDocument: DOMDocument | undefined;
    _childDocumentPromiseForTesting: any;
    _importedDocument: DOMNode | undefined;
    publicId: string | undefined;
    systemId: string | undefined;
    internalSubset: string | undefined;
    name: string | undefined;
    value: string | undefined;
    /**
     * @return {boolean}
     */
    isSVGNode(): boolean;
    /**
     * @return {!Promise<?Protocol.Runtime.StackTrace>}
     */
    creationStackTrace(): Promise<Protocol.Runtime.StackTrace | null>;
    /**
     * @return {!DOMModel}
     */
    domModel(): DOMModel;
    /**
     * @return {number}
     */
    backendNodeId(): number;
    /**
     * @return {?Array.<!DOMNode>}
     */
    children(): Array<DOMNode> | null;
    /**
     * @return {boolean}
     */
    hasAttributes(): boolean;
    /**
     * @return {number}
     */
    childNodeCount(): number;
    /**
     * @return {boolean}
     */
    hasShadowRoots(): boolean;
    /**
     * @return {!Array.<!DOMNode>}
     */
    shadowRoots(): Array<DOMNode>;
    /**
     * @return {?DOMNode}
     */
    templateContent(): DOMNode | null;
    /**
     * @return {?DOMNode}
     */
    contentDocument(): DOMNode | null;
    /**
     * @return {boolean}
     */
    isIframe(): boolean;
    /**
     * @return {boolean}
     */
    isPortal(): boolean;
    /**
     * @return {?DOMNode}
     */
    importedDocument(): DOMNode | null;
    /**
     * @return {number}
     */
    nodeType(): number;
    /**
     * @return {string}
     */
    nodeName(): string;
    /**
     * @return {string|undefined}
     */
    pseudoType(): string | undefined;
    /**
     * @return {boolean}
     */
    hasPseudoElements(): boolean;
    /**
     * @return {!Map<string, !DOMNode>}
     */
    pseudoElements(): Map<string, DOMNode>;
    /**
     * @return {?DOMNode}
     */
    beforePseudoElement(): DOMNode | null;
    /**
     * @return {?DOMNode}
     */
    afterPseudoElement(): DOMNode | null;
    /**
     * @return {?DOMNode}
     */
    markerPseudoElement(): DOMNode | null;
    /**
     * @return {boolean}
     */
    isInsertionPoint(): boolean;
    /**
     * @return {!Array.<!DOMNodeShortcut>}
     */
    distributedNodes(): Array<DOMNodeShortcut>;
    /**
     * @return {boolean}
     */
    isInShadowTree(): boolean;
    /**
     * @return {?DOMNode}
     */
    ancestorShadowHost(): DOMNode | null;
    /**
     * @return {?DOMNode}
     */
    ancestorShadowRoot(): DOMNode | null;
    /**
     * @return {?DOMNode}
     */
    ancestorUserAgentShadowRoot(): DOMNode | null;
    /**
     * @return {boolean}
     */
    isShadowRoot(): boolean;
    /**
     * @return {?string}
     */
    shadowRootType(): string | null;
    /**
     * @return {string}
     */
    nodeNameInCorrectCase(): string;
    /**
     * @param {string} name
     * @param {function(?ProtocolClient.InspectorBackend.ProtocolError, ?DOMNode)=} callback
     */
    setNodeName(name: string, callback?: ((arg0: ProtocolClient.InspectorBackend.ProtocolError | null, arg1: DOMNode | null) => any) | undefined): void;
    /**
     * @return {string}
     */
    localName(): string;
    /**
     * @return {string}
     */
    nodeValue(): string;
    /**
     * @param {string} value
     * @param {function(?ProtocolClient.InspectorBackend.ProtocolError)=} callback
     */
    setNodeValue(value: string, callback?: ((arg0: ProtocolClient.InspectorBackend.ProtocolError | null) => any) | undefined): void;
    /**
     * @param {string} name
     * @return {string|undefined}
     */
    getAttribute(name: string): string | undefined;
    /**
     * @param {string} name
     * @param {string} text
     * @param {function(?ProtocolClient.InspectorBackend.ProtocolError)=} callback
     */
    setAttribute(name: string, text: string, callback?: ((arg0: ProtocolClient.InspectorBackend.ProtocolError | null) => any) | undefined): void;
    /**
     * @param {string} name
     * @param {string} value
     * @param {function(?ProtocolClient.InspectorBackend.ProtocolError)=} callback
     */
    setAttributeValue(name: string, value: string, callback?: ((arg0: ProtocolClient.InspectorBackend.ProtocolError | null) => any) | undefined): void;
    /**
    * @param {string} name
    * @param {string} value
    * @return {!Promise<?ProtocolClient.InspectorBackend.ProtocolError>}
    */
    setAttributeValuePromise(name: string, value: string): Promise<ProtocolClient.InspectorBackend.ProtocolError | null>;
    /**
     * @return {!Array<!Attribute>}
     */
    attributes(): Array<Attribute>;
    /**
     * @param {string} name
     * @return {!Promise<void>}
     */
    removeAttribute(name: string): Promise<void>;
    /**
     * @param {function(?Array<!DOMNode>):void} callback
     */
    getChildNodes(callback: (arg0: Array<DOMNode> | null) => void): void;
    /**
     * @param {number} depth
     * @param {boolean} pierce
     * @return {!Promise<?Array<!DOMNode>>}
     */
    getSubtree(depth: number, pierce: boolean): Promise<Array<DOMNode> | null>;
    /**
     * @return {!Promise<?string>}
     */
    getOuterHTML(): Promise<string | null>;
    /**
     * @param {string} html
     * @param {function(?ProtocolClient.InspectorBackend.ProtocolError)=} callback
     */
    setOuterHTML(html: string, callback?: ((arg0: ProtocolClient.InspectorBackend.ProtocolError | null) => any) | undefined): void;
    /**
     * @param {function(?ProtocolClient.InspectorBackend.ProtocolError, !Protocol.DOM.NodeId=)=} callback
     */
    removeNode(callback?: ((arg0: ProtocolClient.InspectorBackend.ProtocolError | null, arg1?: Protocol.DOM.NodeId | undefined) => any) | undefined): void;
    /**
     * @return {!Promise<?string>}
     */
    copyNode(): Promise<string | null>;
    /**
     * @return {string}
     */
    path(): string;
    /**
     * @param {!DOMNode} node
     * @return {boolean}
     */
    isAncestor(node: DOMNode): boolean;
    /**
     * @param {!DOMNode} descendant
     * @return {boolean}
     */
    isDescendant(descendant: DOMNode): boolean;
    /**
     * @return {?Protocol.Page.FrameId}
     */
    frameId(): Protocol.Page.FrameId | null;
    /**
     * @param {!Array.<string>} attrs
     * @return {boolean}
     */
    _setAttributesPayload(attrs: Array<string>): boolean;
    /**
     * @param {!DOMNode} prev
     * @param {!Protocol.DOM.Node} payload
     * @return {!DOMNode}
     */
    _insertChild(prev: DOMNode, payload: Protocol.DOM.Node): DOMNode;
    /**
     * @param {!DOMNode} node
     */
    _removeChild(node: DOMNode): void;
    /**
     * @param {!Array.<!Protocol.DOM.Node>} payloads
     */
    _setChildrenPayload(payloads: Array<Protocol.DOM.Node>): void;
    /**
     * @param {!Array.<!Protocol.DOM.Node>|undefined} payloads
     */
    _setPseudoElements(payloads: Array<Protocol.DOM.Node> | undefined): void;
    _pseudoElements: Map<any, any> | undefined;
    /**
     * @param {!Array.<!Protocol.DOM.BackendNode>} payloads
     */
    _setDistributedNodePayloads(payloads: Array<Protocol.DOM.BackendNode>): void;
    _distributedNodes: any[] | undefined;
    _renumber(): void;
    /**
     * @param {string} name
     * @param {string} value
     */
    _addAttribute(name: string, value: string): void;
    /**
     * @param {string} name
     * @param {string} value
     */
    _setAttribute(name: string, value: string): void;
    /**
     * @param {string} name
     */
    _removeAttribute(name: string): void;
    /**
     * @param {!DOMNode} targetNode
     * @param {?DOMNode} anchorNode
     * @param {function(?ProtocolClient.InspectorBackend.ProtocolError, !Protocol.DOM.NodeId=)=} callback
     */
    copyTo(targetNode: DOMNode, anchorNode: DOMNode | null, callback?: ((arg0: ProtocolClient.InspectorBackend.ProtocolError | null, arg1?: Protocol.DOM.NodeId | undefined) => any) | undefined): void;
    /**
     * @param {!DOMNode} targetNode
     * @param {?DOMNode} anchorNode
     * @param {function(?ProtocolClient.InspectorBackend.ProtocolError, ?SDK.DOMNode)=} callback
     */
    moveTo(targetNode: DOMNode, anchorNode: DOMNode | null, callback?: ((arg0: ProtocolClient.InspectorBackend.ProtocolError | null, arg1: any | null) => any) | undefined): void;
    /**
     * @return {boolean}
     */
    isXMLNode(): boolean;
    /**
     * @param {string} name
     * @param {?*} value
     */
    setMarker(name: string, value: any | null): void;
    /**
     * @param {string} name
     * @return {?T}
     * @template T
     */
    marker<T>(name: string): T | null;
    /**
     * @param {function(!DOMNode, string):void} visitor
     */
    traverseMarkers(visitor: (arg0: DOMNode, arg1: string) => void): void;
    /**
     * @param {string} url
     * @return {?string}
     */
    resolveURL(url: string): string | null;
    /**
     * @param {string=} mode
     */
    highlight(mode?: string | undefined): void;
    highlightForTwoSeconds(): void;
    /**
     * @param {string=} objectGroup
     * @return {!Promise<?RemoteObject>}
     */
    resolveToObject(objectGroup?: string | undefined): Promise<RemoteObject | null>;
    /**
     * @return {!Promise<?Protocol.DOM.BoxModel>}
     */
    boxModel(): Promise<Protocol.DOM.BoxModel | null>;
    setAsInspectedNode(): void;
    /**
     *  @return {?DOMNode}
     */
    enclosingElementOrSelf(): DOMNode | null;
    scrollIntoView(): Promise<void>;
    focus(): Promise<void>;
    /**
     * @return {string}
     */
    simpleSelector(): string;
}
export namespace DOMNode {
    export namespace PseudoElementNames {
        export const Before: string;
        export const After: string;
        export const Marker: string;
    }
    export type PseudoElementNames = string;
    export namespace ShadowRootTypes {
        export const UserAgent: string;
        export const Open: string;
        export const Closed: string;
    }
    export type ShadowRootTypes = string;
}
export class DeferredDOMNode {
    /**
     * @param {!Target} target
     * @param {number} backendNodeId
     */
    constructor(target: Target, backendNodeId: number);
    _domModel: DOMModel;
    _backendNodeId: number;
    /**
     * @param {function(?DOMNode):void} callback
     */
    resolve(callback: (arg0: DOMNode | null) => void): void;
    /**
     * @return {!Promise<?DOMNode>}
     */
    resolvePromise(): Promise<DOMNode | null>;
    /**
     * @return {number}
     */
    backendNodeId(): number;
    /**
     * @return {!DOMModel}
     */
    domModel(): DOMModel;
    highlight(): void;
}
export class DOMNodeShortcut {
    /**
     * @param {!Target} target
     * @param {number} backendNodeId
     * @param {number} nodeType
     * @param {string} nodeName
     */
    constructor(target: Target, backendNodeId: number, nodeType: number, nodeName: string);
    nodeType: number;
    nodeName: string;
    deferredNode: DeferredDOMNode;
}
/**
 * @unrestricted
 */
export class DOMDocument extends DOMNode {
    /**
     * @param {!DOMModel} domModel
     * @param {!Protocol.DOM.Node} payload
     */
    constructor(domModel: DOMModel, payload: Protocol.DOM.Node);
    documentURL: string;
    baseURL: string;
}
/**
 * @unrestricted
 */
export class DOMModel extends SDKModel {
    static cancelSearch(): void;
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _agent: any;
    /** @type {!Object.<number, !DOMNode>} */
    _idToDOMNode: {
        [x: number]: DOMNode;
    };
    /** @type {?DOMDocument} */
    _document: DOMDocument | null;
    /** @type {!Set<number>} */
    _attributeLoadNodeIds: Set<number>;
    _runtimeModel: RuntimeModel;
    /** @type {number} */
    _lastMutationId: number;
    /** @type {?Promise<?DOMDocument>} */
    _pendingDocumentRequestPromise: Promise<DOMDocument | null> | null;
    /**
     * @return {!RuntimeModel}
     */
    runtimeModel(): RuntimeModel;
    /**
     * @return {!CSSModel}
     */
    cssModel(): CSSModel;
    /**
     * @return {!OverlayModel}
     */
    overlayModel(): OverlayModel;
    /**
     * @param {!DOMNode} node
     */
    _scheduleMutationEvent(node: DOMNode): void;
    /**
     * @return {!Promise<?DOMDocument>}
     */
    requestDocument(): Promise<DOMDocument | null>;
    /**
     * @return {!Promise<?DOMDocument>}
     */
    _requestDocument(): Promise<DOMDocument | null>;
    _frameOwnerNode: DOMNode | null | undefined;
    /**
     * @return {?DOMDocument}
     */
    existingDocument(): DOMDocument | null;
    /**
     * @param {!Protocol.Runtime.RemoteObjectId} objectId
     * @return {!Promise<?DOMNode>}
     */
    pushNodeToFrontend(objectId: Protocol.Runtime.RemoteObjectId): Promise<DOMNode | null>;
    /**
     * @param {string} path
     * @return {!Promise<?Protocol.DOM.NodeId>}
     */
    pushNodeByPathToFrontend(path: string): Promise<Protocol.DOM.NodeId | null>;
    /**
     * @param {!Set<number>} backendNodeIds
     * @return {!Promise<?Map<number, ?DOMNode>>}
     */
    pushNodesByBackendIdsToFrontend(backendNodeIds: Set<number>): Promise<Map<number, DOMNode | null> | null>;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @param {string} name
     * @param {string} value
     */
    _attributeModified(nodeId: Protocol.DOM.NodeId, name: string, value: string): void;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @param {string} name
     */
    _attributeRemoved(nodeId: Protocol.DOM.NodeId, name: string): void;
    /**
     * @param {!Array<!Protocol.DOM.NodeId>} nodeIds
     */
    _inlineStyleInvalidated(nodeIds: Array<Protocol.DOM.NodeId>): void;
    _loadNodeAttributesTimeout: number | undefined;
    _loadNodeAttributes(): void;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @param {string} newValue
     */
    _characterDataModified(nodeId: Protocol.DOM.NodeId, newValue: string): void;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @return {?DOMNode}
     */
    nodeForId(nodeId: Protocol.DOM.NodeId): DOMNode | null;
    _documentUpdated(): void;
    /**
     * @param {?Protocol.DOM.Node} payload
     */
    _setDocument(payload: Protocol.DOM.Node | null): void;
    /**
     * @param {!Protocol.DOM.Node} payload
     */
    _setDetachedRoot(payload: Protocol.DOM.Node): void;
    /**
     * @param {!Protocol.DOM.NodeId} parentId
     * @param {!Array.<!Protocol.DOM.Node>} payloads
     */
    _setChildNodes(parentId: Protocol.DOM.NodeId, payloads: Array<Protocol.DOM.Node>): void;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @param {number} newValue
     */
    _childNodeCountUpdated(nodeId: Protocol.DOM.NodeId, newValue: number): void;
    /**
     * @param {!Protocol.DOM.NodeId} parentId
     * @param {!Protocol.DOM.NodeId} prevId
     * @param {!Protocol.DOM.Node} payload
     */
    _childNodeInserted(parentId: Protocol.DOM.NodeId, prevId: Protocol.DOM.NodeId, payload: Protocol.DOM.Node): void;
    /**
     * @param {!Protocol.DOM.NodeId} parentId
     * @param {!Protocol.DOM.NodeId} nodeId
     */
    _childNodeRemoved(parentId: Protocol.DOM.NodeId, nodeId: Protocol.DOM.NodeId): void;
    /**
     * @param {!Protocol.DOM.NodeId} hostId
     * @param {!Protocol.DOM.Node} root
     */
    _shadowRootPushed(hostId: Protocol.DOM.NodeId, root: Protocol.DOM.Node): void;
    /**
     * @param {!Protocol.DOM.NodeId} hostId
     * @param {!Protocol.DOM.NodeId} rootId
     */
    _shadowRootPopped(hostId: Protocol.DOM.NodeId, rootId: Protocol.DOM.NodeId): void;
    /**
     * @param {!Protocol.DOM.NodeId} parentId
     * @param {!Protocol.DOM.Node} pseudoElement
     */
    _pseudoElementAdded(parentId: Protocol.DOM.NodeId, pseudoElement: Protocol.DOM.Node): void;
    /**
     * @param {!Protocol.DOM.NodeId} parentId
     * @param {!Protocol.DOM.NodeId} pseudoElementId
     */
    _pseudoElementRemoved(parentId: Protocol.DOM.NodeId, pseudoElementId: Protocol.DOM.NodeId): void;
    /**
     * @param {!Protocol.DOM.NodeId} insertionPointId
     * @param {!Array.<!Protocol.DOM.BackendNode>} distributedNodes
     */
    _distributedNodesUpdated(insertionPointId: Protocol.DOM.NodeId, distributedNodes: Array<Protocol.DOM.BackendNode>): void;
    /**
     * @param {!DOMNode} node
     */
    _unbind(node: DOMNode): void;
    /**
     * @param {string} query
     * @param {boolean} includeUserAgentShadowDOM
     * @return {!Promise<number>}
     */
    performSearch(query: string, includeUserAgentShadowDOM: boolean): Promise<number>;
    _searchId: any;
    /**
     * @param {number} index
     * @return {!Promise<?DOMNode>}
     */
    searchResult(index: number): Promise<DOMNode | null>;
    _cancelSearch(): void;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @return {!Promise<!Array<string>>}
     */
    classNamesPromise(nodeId: Protocol.DOM.NodeId): Promise<Array<string>>;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @param {string} selector
     * @return {!Promise<?Protocol.DOM.NodeId>}
     */
    querySelector(nodeId: Protocol.DOM.NodeId, selector: string): Promise<Protocol.DOM.NodeId | null>;
    /**
     * @param {!Protocol.DOM.NodeId} nodeId
     * @param {string} selector
     * @return {!Promise<?Array<!Protocol.DOM.NodeId>>}
     */
    querySelectorAll(nodeId: Protocol.DOM.NodeId, selector: string): Promise<Array<Protocol.DOM.NodeId> | null>;
    /**
     * @param {boolean=} minorChange
     */
    markUndoableState(minorChange?: boolean | undefined): void;
    /**
     * @param {number} x
     * @param {number} y
     * @param {boolean} includeUserAgentShadowDOM
     * @return {!Promise<?DOMNode>}
     */
    nodeForLocation(x: number, y: number, includeUserAgentShadowDOM: boolean): Promise<DOMNode | null>;
    /**
     * @param {!RemoteObject} object
     * @return {!Promise<?DOMNode>}
     */
    pushObjectAsNodeToFrontend(object: RemoteObject): Promise<DOMNode | null>;
    /**
     * @return {?DOMModel}
     */
    parentModel(): DOMModel | null;
}
export type Events = symbol;
export namespace Events {
    export const AttrModified: symbol;
    export const AttrRemoved: symbol;
    export const CharacterDataModified: symbol;
    export const DOMMutated: symbol;
    export const NodeInserted: symbol;
    export const NodeRemoved: symbol;
    export const DocumentUpdated: symbol;
    export const ChildNodeCountUpdated: symbol;
    export const DistributedNodesChanged: symbol;
    export const MarkersChanged: symbol;
}
export class DOMModelUndoStack {
    /**
     * @param {{forceNew: ?boolean}} opts
     * @return {!DOMModelUndoStack}
     */
    static instance(opts?: {
        forceNew: boolean | null;
    }): DOMModelUndoStack;
    /** @type {!Array<!DOMModel>} */
    _stack: Array<DOMModel>;
    _index: number;
    /** @type {?DOMModel} */
    _lastModelWithMinorChange: DOMModel | null;
    /**
     * @param {!DOMModel} model
     * @param {boolean} minorChange
     */
    _markUndoableState(model: DOMModel, minorChange: boolean): void;
    /**
     * @return {!Promise<void>}
     */
    undo(): Promise<void>;
    /**
     * @return {!Promise<void>}
     */
    redo(): Promise<void>;
    /**
     * @param {!DOMModel} model
     */
    _dispose(model: DOMModel): void;
}
export type Attribute = {
    name: string;
    value: string;
    _node: DOMNode;
};
/** @typedef {{name: string, value: string, _node: DOMNode}} */
export let Attribute: any;
import * as ProtocolClient from "../protocol_client/protocol_client.js";
import { RemoteObject } from "./RemoteObject.js";
import { Target } from "./SDKModel.js";
import { SDKModel } from "./SDKModel.js";
import { RuntimeModel } from "./RuntimeModel.js";
import { CSSModel } from "./CSSModel.js";
import { OverlayModel } from "./OverlayModel.js";
