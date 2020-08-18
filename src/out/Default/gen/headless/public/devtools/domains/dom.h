// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace dom {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Fired when `Element`'s attribute is modified.
  virtual void OnAttributeModified(const AttributeModifiedParams& params) {}
  // Fired when `Element`'s attribute is removed.
  virtual void OnAttributeRemoved(const AttributeRemovedParams& params) {}
  // Mirrors `DOMCharacterDataModified` event.
  virtual void OnCharacterDataModified(const CharacterDataModifiedParams& params) {}
  // Fired when `Container`'s child node count has changed.
  virtual void OnChildNodeCountUpdated(const ChildNodeCountUpdatedParams& params) {}
  // Mirrors `DOMNodeInserted` event.
  virtual void OnChildNodeInserted(const ChildNodeInsertedParams& params) {}
  // Mirrors `DOMNodeRemoved` event.
  virtual void OnChildNodeRemoved(const ChildNodeRemovedParams& params) {}
  // Called when distrubution is changed.
  virtual void OnDistributedNodesUpdated(const DistributedNodesUpdatedParams& params) {}
  // Fired when `Document` has been totally updated. Node ids are no longer valid.
  virtual void OnDocumentUpdated(const DocumentUpdatedParams& params) {}
  // Fired when `Element`'s inline style is modified via a CSS property modification.
  virtual void OnInlineStyleInvalidated(const InlineStyleInvalidatedParams& params) {}
  // Called when a pseudo element is added to an element.
  virtual void OnPseudoElementAdded(const PseudoElementAddedParams& params) {}
  // Called when a pseudo element is removed from an element.
  virtual void OnPseudoElementRemoved(const PseudoElementRemovedParams& params) {}
  // Fired when backend wants to provide client with the missing DOM structure. This happens upon
  // most of the calls requesting node ids.
  virtual void OnSetChildNodes(const SetChildNodesParams& params) {}
  // Called when shadow root is popped from the element.
  virtual void OnShadowRootPopped(const ShadowRootPoppedParams& params) {}
  // Called when shadow root is pushed into the element.
  virtual void OnShadowRootPushed(const ShadowRootPushedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Fired when `Element`'s attribute is modified.
  virtual void OnAttributeModified(const AttributeModifiedParams& params) {}
  // Fired when `Element`'s attribute is removed.
  virtual void OnAttributeRemoved(const AttributeRemovedParams& params) {}
  // Mirrors `DOMCharacterDataModified` event.
  virtual void OnCharacterDataModified(const CharacterDataModifiedParams& params) {}
  // Fired when `Container`'s child node count has changed.
  virtual void OnChildNodeCountUpdated(const ChildNodeCountUpdatedParams& params) {}
  // Mirrors `DOMNodeInserted` event.
  virtual void OnChildNodeInserted(const ChildNodeInsertedParams& params) {}
  // Mirrors `DOMNodeRemoved` event.
  virtual void OnChildNodeRemoved(const ChildNodeRemovedParams& params) {}
  // Experimental: Called when distrubution is changed.
  virtual void OnDistributedNodesUpdated(const DistributedNodesUpdatedParams& params) final {}
  // Fired when `Document` has been totally updated. Node ids are no longer valid.
  virtual void OnDocumentUpdated(const DocumentUpdatedParams& params) {}
  // Experimental: Fired when `Element`'s inline style is modified via a CSS property modification.
  virtual void OnInlineStyleInvalidated(const InlineStyleInvalidatedParams& params) final {}
  // Experimental: Called when a pseudo element is added to an element.
  virtual void OnPseudoElementAdded(const PseudoElementAddedParams& params) final {}
  // Experimental: Called when a pseudo element is removed from an element.
  virtual void OnPseudoElementRemoved(const PseudoElementRemovedParams& params) final {}
  // Fired when backend wants to provide client with the missing DOM structure. This happens upon
  // most of the calls requesting node ids.
  virtual void OnSetChildNodes(const SetChildNodesParams& params) {}
  // Experimental: Called when shadow root is popped from the element.
  virtual void OnShadowRootPopped(const ShadowRootPoppedParams& params) final {}
  // Experimental: Called when shadow root is pushed into the element.
  virtual void OnShadowRootPushed(const ShadowRootPushedParams& params) final {}
};

// This domain exposes DOM read/write operations. Each DOM Node is represented with its mirror object
// that has an `id`. This `id` can be used to get additional information on the Node, resolve it into
// the JavaScript object wrapper, etc. It is important that client receives DOM events only for the
// nodes that are known to the client. Backend keeps track of the nodes that were sent to the client
// and never sends the same node twice. It is client's responsibility to collect information about
// the nodes that were sent to the client.<p>Note that `iframe` owner elements will return
// corresponding document elements as their child nodes.</p>
class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

  // Describes node given its id, does not require domain to be enabled. Does not start tracking any
  // objects, can be used for automation.
  void DescribeNode(std::unique_ptr<DescribeNodeParams> params, base::OnceCallback<void(std::unique_ptr<DescribeNodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<DescribeNodeResult>)>());
  void DescribeNode(base::OnceCallback<void(std::unique_ptr<DescribeNodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<DescribeNodeResult>)>());

  // Disables DOM agent for the given page.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());
  void Disable(base::OnceClosure callback = base::OnceClosure());
  void Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback);

  // Enables DOM agent for the given page.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());
  void Enable(base::OnceClosure callback = base::OnceClosure());
  void Enable(std::unique_ptr<EnableParams> params, base::OnceClosure callback);

  // Focuses the given element.
  void Focus(std::unique_ptr<FocusParams> params, base::OnceCallback<void(std::unique_ptr<FocusResult>)> callback = base::OnceCallback<void(std::unique_ptr<FocusResult>)>());
  void Focus(base::OnceClosure callback = base::OnceClosure());
  void Focus(std::unique_ptr<FocusParams> params, base::OnceClosure callback);

  // Returns attributes for the specified node.
  void GetAttributes(std::unique_ptr<GetAttributesParams> params, base::OnceCallback<void(std::unique_ptr<GetAttributesResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetAttributesResult>)>());
  void GetAttributes(int node_id, base::OnceCallback<void(std::unique_ptr<GetAttributesResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetAttributesResult>)>());

  // Returns boxes for the given node.
  void GetBoxModel(std::unique_ptr<GetBoxModelParams> params, base::OnceCallback<void(std::unique_ptr<GetBoxModelResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetBoxModelResult>)>());
  void GetBoxModel(base::OnceCallback<void(std::unique_ptr<GetBoxModelResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetBoxModelResult>)>());

  // Returns the root DOM node (and optionally the subtree) to the caller.
  void GetDocument(std::unique_ptr<GetDocumentParams> params, base::OnceCallback<void(std::unique_ptr<GetDocumentResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetDocumentResult>)>());
  void GetDocument(base::OnceCallback<void(std::unique_ptr<GetDocumentResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetDocumentResult>)>());

  // Returns the root DOM node (and optionally the subtree) to the caller.
  void GetFlattenedDocument(std::unique_ptr<GetFlattenedDocumentParams> params, base::OnceCallback<void(std::unique_ptr<GetFlattenedDocumentResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetFlattenedDocumentResult>)>());
  void GetFlattenedDocument(base::OnceCallback<void(std::unique_ptr<GetFlattenedDocumentResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetFlattenedDocumentResult>)>());

  // Returns node id at given location. Depending on whether DOM domain is enabled, nodeId is
  // either returned or not.
  void GetNodeForLocation(std::unique_ptr<GetNodeForLocationParams> params, base::OnceCallback<void(std::unique_ptr<GetNodeForLocationResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetNodeForLocationResult>)>());
  void GetNodeForLocation(int x, int y, base::OnceCallback<void(std::unique_ptr<GetNodeForLocationResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetNodeForLocationResult>)>());

  // Returns node's HTML markup.
  void GetOuterHTML(std::unique_ptr<GetOuterHTMLParams> params, base::OnceCallback<void(std::unique_ptr<GetOuterHTMLResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetOuterHTMLResult>)>());
  void GetOuterHTML(base::OnceCallback<void(std::unique_ptr<GetOuterHTMLResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetOuterHTMLResult>)>());

  // Hides any highlight.
  void HideHighlight(std::unique_ptr<HideHighlightParams> params, base::OnceCallback<void(std::unique_ptr<HideHighlightResult>)> callback = base::OnceCallback<void(std::unique_ptr<HideHighlightResult>)>());
  void HideHighlight(base::OnceClosure callback = base::OnceClosure());
  void HideHighlight(std::unique_ptr<HideHighlightParams> params, base::OnceClosure callback);

  // Highlights DOM node.
  void HighlightNode(std::unique_ptr<HighlightNodeParams> params, base::OnceCallback<void(std::unique_ptr<HighlightNodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<HighlightNodeResult>)>());
  void HighlightNode(base::OnceClosure callback = base::OnceClosure());
  void HighlightNode(std::unique_ptr<HighlightNodeParams> params, base::OnceClosure callback);

  // Highlights given rectangle.
  void HighlightRect(std::unique_ptr<HighlightRectParams> params, base::OnceCallback<void(std::unique_ptr<HighlightRectResult>)> callback = base::OnceCallback<void(std::unique_ptr<HighlightRectResult>)>());
  void HighlightRect(base::OnceClosure callback = base::OnceClosure());
  void HighlightRect(std::unique_ptr<HighlightRectParams> params, base::OnceClosure callback);

  // Moves node into the new container, places it before the given anchor.
  void MoveTo(std::unique_ptr<MoveToParams> params, base::OnceCallback<void(std::unique_ptr<MoveToResult>)> callback = base::OnceCallback<void(std::unique_ptr<MoveToResult>)>());
  void MoveTo(int node_id, int target_node_id, base::OnceCallback<void(std::unique_ptr<MoveToResult>)> callback = base::OnceCallback<void(std::unique_ptr<MoveToResult>)>());

  // Executes `querySelector` on a given node.
  void QuerySelector(std::unique_ptr<QuerySelectorParams> params, base::OnceCallback<void(std::unique_ptr<QuerySelectorResult>)> callback = base::OnceCallback<void(std::unique_ptr<QuerySelectorResult>)>());
  void QuerySelector(int node_id, const std::string& selector, base::OnceCallback<void(std::unique_ptr<QuerySelectorResult>)> callback = base::OnceCallback<void(std::unique_ptr<QuerySelectorResult>)>());

  // Executes `querySelectorAll` on a given node.
  void QuerySelectorAll(std::unique_ptr<QuerySelectorAllParams> params, base::OnceCallback<void(std::unique_ptr<QuerySelectorAllResult>)> callback = base::OnceCallback<void(std::unique_ptr<QuerySelectorAllResult>)>());
  void QuerySelectorAll(int node_id, const std::string& selector, base::OnceCallback<void(std::unique_ptr<QuerySelectorAllResult>)> callback = base::OnceCallback<void(std::unique_ptr<QuerySelectorAllResult>)>());

  // Removes attribute with given name from an element with given id.
  void RemoveAttribute(std::unique_ptr<RemoveAttributeParams> params, base::OnceCallback<void(std::unique_ptr<RemoveAttributeResult>)> callback = base::OnceCallback<void(std::unique_ptr<RemoveAttributeResult>)>());
  void RemoveAttribute(int node_id, const std::string& name, base::OnceClosure callback = base::OnceClosure());
  void RemoveAttribute(std::unique_ptr<RemoveAttributeParams> params, base::OnceClosure callback);

  // Removes node with given id.
  void RemoveNode(std::unique_ptr<RemoveNodeParams> params, base::OnceCallback<void(std::unique_ptr<RemoveNodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<RemoveNodeResult>)>());
  void RemoveNode(int node_id, base::OnceClosure callback = base::OnceClosure());
  void RemoveNode(std::unique_ptr<RemoveNodeParams> params, base::OnceClosure callback);

  // Requests that children of the node with given id are returned to the caller in form of
  // `setChildNodes` events where not only immediate children are retrieved, but all children down to
  // the specified depth.
  void RequestChildNodes(std::unique_ptr<RequestChildNodesParams> params, base::OnceCallback<void(std::unique_ptr<RequestChildNodesResult>)> callback = base::OnceCallback<void(std::unique_ptr<RequestChildNodesResult>)>());
  void RequestChildNodes(int node_id, base::OnceClosure callback = base::OnceClosure());
  void RequestChildNodes(std::unique_ptr<RequestChildNodesParams> params, base::OnceClosure callback);

  // Requests that the node is sent to the caller given the JavaScript node object reference. All
  // nodes that form the path from the node to the root are also sent to the client as a series of
  // `setChildNodes` notifications.
  void RequestNode(std::unique_ptr<RequestNodeParams> params, base::OnceCallback<void(std::unique_ptr<RequestNodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<RequestNodeResult>)>());
  void RequestNode(const std::string& object_id, base::OnceCallback<void(std::unique_ptr<RequestNodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<RequestNodeResult>)>());

  // Resolves the JavaScript node object for a given NodeId or BackendNodeId.
  void ResolveNode(std::unique_ptr<ResolveNodeParams> params, base::OnceCallback<void(std::unique_ptr<ResolveNodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<ResolveNodeResult>)>());
  void ResolveNode(base::OnceCallback<void(std::unique_ptr<ResolveNodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<ResolveNodeResult>)>());

  // Sets attribute for an element with given id.
  void SetAttributeValue(std::unique_ptr<SetAttributeValueParams> params, base::OnceCallback<void(std::unique_ptr<SetAttributeValueResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetAttributeValueResult>)>());
  void SetAttributeValue(int node_id, const std::string& name, const std::string& value, base::OnceClosure callback = base::OnceClosure());
  void SetAttributeValue(std::unique_ptr<SetAttributeValueParams> params, base::OnceClosure callback);

  // Sets attributes on element with given id. This method is useful when user edits some existing
  // attribute value and types in several attribute name/value pairs.
  void SetAttributesAsText(std::unique_ptr<SetAttributesAsTextParams> params, base::OnceCallback<void(std::unique_ptr<SetAttributesAsTextResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetAttributesAsTextResult>)>());
  void SetAttributesAsText(int node_id, const std::string& text, base::OnceClosure callback = base::OnceClosure());
  void SetAttributesAsText(std::unique_ptr<SetAttributesAsTextParams> params, base::OnceClosure callback);

  // Sets files for the given file input element.
  void SetFileInputFiles(std::unique_ptr<SetFileInputFilesParams> params, base::OnceCallback<void(std::unique_ptr<SetFileInputFilesResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetFileInputFilesResult>)>());
  void SetFileInputFiles(std::vector<std::string> files, base::OnceClosure callback = base::OnceClosure());
  void SetFileInputFiles(std::unique_ptr<SetFileInputFilesParams> params, base::OnceClosure callback);

  // Sets node name for a node with given id.
  void SetNodeName(std::unique_ptr<SetNodeNameParams> params, base::OnceCallback<void(std::unique_ptr<SetNodeNameResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetNodeNameResult>)>());
  void SetNodeName(int node_id, const std::string& name, base::OnceCallback<void(std::unique_ptr<SetNodeNameResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetNodeNameResult>)>());

  // Sets node value for a node with given id.
  void SetNodeValue(std::unique_ptr<SetNodeValueParams> params, base::OnceCallback<void(std::unique_ptr<SetNodeValueResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetNodeValueResult>)>());
  void SetNodeValue(int node_id, const std::string& value, base::OnceClosure callback = base::OnceClosure());
  void SetNodeValue(std::unique_ptr<SetNodeValueParams> params, base::OnceClosure callback);

  // Sets node HTML markup, returns new node id.
  void SetOuterHTML(std::unique_ptr<SetOuterHTMLParams> params, base::OnceCallback<void(std::unique_ptr<SetOuterHTMLResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetOuterHTMLResult>)>());
  void SetOuterHTML(int node_id, const std::string& outerhtml, base::OnceClosure callback = base::OnceClosure());
  void SetOuterHTML(std::unique_ptr<SetOuterHTMLParams> params, base::OnceClosure callback);

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleCollectClassNamesFromSubtreeResponse(base::OnceCallback<void(std::unique_ptr<CollectClassNamesFromSubtreeResult>)> callback, const base::Value& response);
  static void HandleCopyToResponse(base::OnceCallback<void(std::unique_ptr<CopyToResult>)> callback, const base::Value& response);
  static void HandleDescribeNodeResponse(base::OnceCallback<void(std::unique_ptr<DescribeNodeResult>)> callback, const base::Value& response);
  static void HandleScrollIntoViewIfNeededResponse(base::OnceCallback<void(std::unique_ptr<ScrollIntoViewIfNeededResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleDiscardSearchResultsResponse(base::OnceCallback<void(std::unique_ptr<DiscardSearchResultsResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleFocusResponse(base::OnceCallback<void(std::unique_ptr<FocusResult>)> callback, const base::Value& response);
  static void HandleGetAttributesResponse(base::OnceCallback<void(std::unique_ptr<GetAttributesResult>)> callback, const base::Value& response);
  static void HandleGetBoxModelResponse(base::OnceCallback<void(std::unique_ptr<GetBoxModelResult>)> callback, const base::Value& response);
  static void HandleGetContentQuadsResponse(base::OnceCallback<void(std::unique_ptr<GetContentQuadsResult>)> callback, const base::Value& response);
  static void HandleGetDocumentResponse(base::OnceCallback<void(std::unique_ptr<GetDocumentResult>)> callback, const base::Value& response);
  static void HandleGetFlattenedDocumentResponse(base::OnceCallback<void(std::unique_ptr<GetFlattenedDocumentResult>)> callback, const base::Value& response);
  static void HandleGetNodeForLocationResponse(base::OnceCallback<void(std::unique_ptr<GetNodeForLocationResult>)> callback, const base::Value& response);
  static void HandleGetOuterHTMLResponse(base::OnceCallback<void(std::unique_ptr<GetOuterHTMLResult>)> callback, const base::Value& response);
  static void HandleGetRelayoutBoundaryResponse(base::OnceCallback<void(std::unique_ptr<GetRelayoutBoundaryResult>)> callback, const base::Value& response);
  static void HandleGetSearchResultsResponse(base::OnceCallback<void(std::unique_ptr<GetSearchResultsResult>)> callback, const base::Value& response);
  static void HandleHideHighlightResponse(base::OnceCallback<void(std::unique_ptr<HideHighlightResult>)> callback, const base::Value& response);
  static void HandleHighlightNodeResponse(base::OnceCallback<void(std::unique_ptr<HighlightNodeResult>)> callback, const base::Value& response);
  static void HandleHighlightRectResponse(base::OnceCallback<void(std::unique_ptr<HighlightRectResult>)> callback, const base::Value& response);
  static void HandleMarkUndoableStateResponse(base::OnceCallback<void(std::unique_ptr<MarkUndoableStateResult>)> callback, const base::Value& response);
  static void HandleMoveToResponse(base::OnceCallback<void(std::unique_ptr<MoveToResult>)> callback, const base::Value& response);
  static void HandlePerformSearchResponse(base::OnceCallback<void(std::unique_ptr<PerformSearchResult>)> callback, const base::Value& response);
  static void HandlePushNodeByPathToFrontendResponse(base::OnceCallback<void(std::unique_ptr<PushNodeByPathToFrontendResult>)> callback, const base::Value& response);
  static void HandlePushNodesByBackendIdsToFrontendResponse(base::OnceCallback<void(std::unique_ptr<PushNodesByBackendIdsToFrontendResult>)> callback, const base::Value& response);
  static void HandleQuerySelectorResponse(base::OnceCallback<void(std::unique_ptr<QuerySelectorResult>)> callback, const base::Value& response);
  static void HandleQuerySelectorAllResponse(base::OnceCallback<void(std::unique_ptr<QuerySelectorAllResult>)> callback, const base::Value& response);
  static void HandleRedoResponse(base::OnceCallback<void(std::unique_ptr<RedoResult>)> callback, const base::Value& response);
  static void HandleRemoveAttributeResponse(base::OnceCallback<void(std::unique_ptr<RemoveAttributeResult>)> callback, const base::Value& response);
  static void HandleRemoveNodeResponse(base::OnceCallback<void(std::unique_ptr<RemoveNodeResult>)> callback, const base::Value& response);
  static void HandleRequestChildNodesResponse(base::OnceCallback<void(std::unique_ptr<RequestChildNodesResult>)> callback, const base::Value& response);
  static void HandleRequestNodeResponse(base::OnceCallback<void(std::unique_ptr<RequestNodeResult>)> callback, const base::Value& response);
  static void HandleResolveNodeResponse(base::OnceCallback<void(std::unique_ptr<ResolveNodeResult>)> callback, const base::Value& response);
  static void HandleSetAttributeValueResponse(base::OnceCallback<void(std::unique_ptr<SetAttributeValueResult>)> callback, const base::Value& response);
  static void HandleSetAttributesAsTextResponse(base::OnceCallback<void(std::unique_ptr<SetAttributesAsTextResult>)> callback, const base::Value& response);
  static void HandleSetFileInputFilesResponse(base::OnceCallback<void(std::unique_ptr<SetFileInputFilesResult>)> callback, const base::Value& response);
  static void HandleSetNodeStackTracesEnabledResponse(base::OnceCallback<void(std::unique_ptr<SetNodeStackTracesEnabledResult>)> callback, const base::Value& response);
  static void HandleGetNodeStackTracesResponse(base::OnceCallback<void(std::unique_ptr<GetNodeStackTracesResult>)> callback, const base::Value& response);
  static void HandleGetFileInfoResponse(base::OnceCallback<void(std::unique_ptr<GetFileInfoResult>)> callback, const base::Value& response);
  static void HandleSetInspectedNodeResponse(base::OnceCallback<void(std::unique_ptr<SetInspectedNodeResult>)> callback, const base::Value& response);
  static void HandleSetNodeNameResponse(base::OnceCallback<void(std::unique_ptr<SetNodeNameResult>)> callback, const base::Value& response);
  static void HandleSetNodeValueResponse(base::OnceCallback<void(std::unique_ptr<SetNodeValueResult>)> callback, const base::Value& response);
  static void HandleSetOuterHTMLResponse(base::OnceCallback<void(std::unique_ptr<SetOuterHTMLResult>)> callback, const base::Value& response);
  static void HandleUndoResponse(base::OnceCallback<void(std::unique_ptr<UndoResult>)> callback, const base::Value& response);
  static void HandleGetFrameOwnerResponse(base::OnceCallback<void(std::unique_ptr<GetFrameOwnerResult>)> callback, const base::Value& response);

  void DispatchAttributeModifiedEvent(const base::Value& params);
  void DispatchAttributeRemovedEvent(const base::Value& params);
  void DispatchCharacterDataModifiedEvent(const base::Value& params);
  void DispatchChildNodeCountUpdatedEvent(const base::Value& params);
  void DispatchChildNodeInsertedEvent(const base::Value& params);
  void DispatchChildNodeRemovedEvent(const base::Value& params);
  void DispatchDistributedNodesUpdatedEvent(const base::Value& params);
  void DispatchDocumentUpdatedEvent(const base::Value& params);
  void DispatchInlineStyleInvalidatedEvent(const base::Value& params);
  void DispatchPseudoElementAddedEvent(const base::Value& params);
  void DispatchPseudoElementRemovedEvent(const base::Value& params);
  void DispatchSetChildNodesEvent(const base::Value& params);
  void DispatchShadowRootPoppedEvent(const base::Value& params);
  void DispatchShadowRootPushedEvent(const base::Value& params);

  internal::MessageDispatcher* dispatcher_;  // Not owned.
  base::ObserverList<ExperimentalObserver>::Unchecked observers_;

 protected:
  void RegisterEventHandlersIfNeeded();

 private:
  bool event_handlers_registered_ = false;

  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();

  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(ExperimentalObserver* observer);
  void RemoveObserver(ExperimentalObserver* observer);

  // Collects class names for the node with given id and all of it's child nodes.
  void CollectClassNamesFromSubtree(std::unique_ptr<CollectClassNamesFromSubtreeParams> params, base::OnceCallback<void(std::unique_ptr<CollectClassNamesFromSubtreeResult>)> callback = base::OnceCallback<void(std::unique_ptr<CollectClassNamesFromSubtreeResult>)>());

  // Creates a deep copy of the specified node and places it into the target container before the
  // given anchor.
  void CopyTo(std::unique_ptr<CopyToParams> params, base::OnceCallback<void(std::unique_ptr<CopyToResult>)> callback = base::OnceCallback<void(std::unique_ptr<CopyToResult>)>());

  // Scrolls the specified rect of the given node into view if not already visible.
  // Note: exactly one between nodeId, backendNodeId and objectId should be passed
  // to identify the node.
  void ScrollIntoViewIfNeeded(std::unique_ptr<ScrollIntoViewIfNeededParams> params, base::OnceCallback<void(std::unique_ptr<ScrollIntoViewIfNeededResult>)> callback = base::OnceCallback<void(std::unique_ptr<ScrollIntoViewIfNeededResult>)>());

  // Discards search results from the session with the given id. `getSearchResults` should no longer
  // be called for that search.
  void DiscardSearchResults(std::unique_ptr<DiscardSearchResultsParams> params, base::OnceCallback<void(std::unique_ptr<DiscardSearchResultsResult>)> callback = base::OnceCallback<void(std::unique_ptr<DiscardSearchResultsResult>)>());

  // Returns quads that describe node position on the page. This method
  // might return multiple quads for inline nodes.
  void GetContentQuads(std::unique_ptr<GetContentQuadsParams> params, base::OnceCallback<void(std::unique_ptr<GetContentQuadsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetContentQuadsResult>)>());

  // Returns the id of the nearest ancestor that is a relayout boundary.
  void GetRelayoutBoundary(std::unique_ptr<GetRelayoutBoundaryParams> params, base::OnceCallback<void(std::unique_ptr<GetRelayoutBoundaryResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetRelayoutBoundaryResult>)>());

  // Returns search results from given `fromIndex` to given `toIndex` from the search with the given
  // identifier.
  void GetSearchResults(std::unique_ptr<GetSearchResultsParams> params, base::OnceCallback<void(std::unique_ptr<GetSearchResultsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetSearchResultsResult>)>());

  // Marks last undoable state.
  void MarkUndoableState(std::unique_ptr<MarkUndoableStateParams> params, base::OnceCallback<void(std::unique_ptr<MarkUndoableStateResult>)> callback = base::OnceCallback<void(std::unique_ptr<MarkUndoableStateResult>)>());

  // Searches for a given string in the DOM tree. Use `getSearchResults` to access search results or
  // `cancelSearch` to end this search session.
  void PerformSearch(std::unique_ptr<PerformSearchParams> params, base::OnceCallback<void(std::unique_ptr<PerformSearchResult>)> callback = base::OnceCallback<void(std::unique_ptr<PerformSearchResult>)>());

  // Requests that the node is sent to the caller given its path. // FIXME, use XPath
  void PushNodeByPathToFrontend(std::unique_ptr<PushNodeByPathToFrontendParams> params, base::OnceCallback<void(std::unique_ptr<PushNodeByPathToFrontendResult>)> callback = base::OnceCallback<void(std::unique_ptr<PushNodeByPathToFrontendResult>)>());

  // Requests that a batch of nodes is sent to the caller given their backend node ids.
  void PushNodesByBackendIdsToFrontend(std::unique_ptr<PushNodesByBackendIdsToFrontendParams> params, base::OnceCallback<void(std::unique_ptr<PushNodesByBackendIdsToFrontendResult>)> callback = base::OnceCallback<void(std::unique_ptr<PushNodesByBackendIdsToFrontendResult>)>());

  // Re-does the last undone action.
  void Redo(std::unique_ptr<RedoParams> params, base::OnceCallback<void(std::unique_ptr<RedoResult>)> callback = base::OnceCallback<void(std::unique_ptr<RedoResult>)>());

  // Sets if stack traces should be captured for Nodes. See `Node.getNodeStackTraces`. Default is disabled.
  void SetNodeStackTracesEnabled(std::unique_ptr<SetNodeStackTracesEnabledParams> params, base::OnceCallback<void(std::unique_ptr<SetNodeStackTracesEnabledResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetNodeStackTracesEnabledResult>)>());

  // Gets stack traces associated with a Node. As of now, only provides stack trace for Node creation.
  void GetNodeStackTraces(std::unique_ptr<GetNodeStackTracesParams> params, base::OnceCallback<void(std::unique_ptr<GetNodeStackTracesResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetNodeStackTracesResult>)>());

  // Returns file information for the given
  // File wrapper.
  void GetFileInfo(std::unique_ptr<GetFileInfoParams> params, base::OnceCallback<void(std::unique_ptr<GetFileInfoResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetFileInfoResult>)>());

  // Enables console to refer to the node with given id via $x (see Command Line API for more details
  // $x functions).
  void SetInspectedNode(std::unique_ptr<SetInspectedNodeParams> params, base::OnceCallback<void(std::unique_ptr<SetInspectedNodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetInspectedNodeResult>)>());

  // Undoes the last performed action.
  void Undo(std::unique_ptr<UndoParams> params, base::OnceCallback<void(std::unique_ptr<UndoResult>)> callback = base::OnceCallback<void(std::unique_ptr<UndoResult>)>());

  // Returns iframe node that owns iframe with the given domain.
  void GetFrameOwner(std::unique_ptr<GetFrameOwnerParams> params, base::OnceCallback<void(std::unique_ptr<GetFrameOwnerResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetFrameOwnerResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace dom
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_H_
