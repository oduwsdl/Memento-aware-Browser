// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_DOM_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_DOM_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_dom.h"
#include "headless/public/devtools/internal/types_forward_declarations_debugger.h"
#include "headless/public/devtools/internal/types_forward_declarations_emulation.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_network.h"
#include "headless/public/devtools/internal/types_forward_declarations_page.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/devtools/internal/types_forward_declarations_security.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace dom {

// Backend node with a friendly name.
class HEADLESS_EXPORT BackendNode {
 public:
  static std::unique_ptr<BackendNode> Parse(const base::Value& value, ErrorReporter* errors);
  ~BackendNode() { }

  // `Node`'s nodeType.
  int GetNodeType() const { return node_type_; }
  void SetNodeType(int value) { node_type_ = value; }

  // `Node`'s nodeName.
  std::string GetNodeName() const { return node_name_; }
  void SetNodeName(const std::string& value) { node_name_ = value; }

  int GetBackendNodeId() const { return backend_node_id_; }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BackendNode> Clone() const;

  template<int STATE>
  class BackendNodeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeTypeSet = 1 << 1,
    kNodeNameSet = 1 << 2,
    kBackendNodeIdSet = 1 << 3,
      kAllRequiredFieldsSet = (kNodeTypeSet | kNodeNameSet | kBackendNodeIdSet | 0)
    };

    BackendNodeBuilder<STATE | kNodeTypeSet>& SetNodeType(int value) {
      static_assert(!(STATE & kNodeTypeSet), "property nodeType should not have already been set");
      result_->SetNodeType(value);
      return CastState<kNodeTypeSet>();
    }

    BackendNodeBuilder<STATE | kNodeNameSet>& SetNodeName(const std::string& value) {
      static_assert(!(STATE & kNodeNameSet), "property nodeName should not have already been set");
      result_->SetNodeName(value);
      return CastState<kNodeNameSet>();
    }

    BackendNodeBuilder<STATE | kBackendNodeIdSet>& SetBackendNodeId(int value) {
      static_assert(!(STATE & kBackendNodeIdSet), "property backendNodeId should not have already been set");
      result_->SetBackendNodeId(value);
      return CastState<kBackendNodeIdSet>();
    }

    std::unique_ptr<BackendNode> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BackendNode;
    BackendNodeBuilder() : result_(new BackendNode()) { }

    template<int STEP> BackendNodeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BackendNodeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BackendNode> result_;
  };

  static BackendNodeBuilder<0> Builder() {
    return BackendNodeBuilder<0>();
  }

 private:
  BackendNode() { }

  int node_type_;
  std::string node_name_;
  int backend_node_id_;

  DISALLOW_COPY_AND_ASSIGN(BackendNode);
};


// DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes.
// DOMNode is a base node mirror type.
class HEADLESS_EXPORT Node {
 public:
  static std::unique_ptr<Node> Parse(const base::Value& value, ErrorReporter* errors);
  ~Node() { }

  // Node identifier that is passed into the rest of the DOM messages as the `nodeId`. Backend
  // will only push node with given `id` once. It is aware of all requested nodes and will only
  // fire DOM events for nodes known to the client.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // The id of the parent node if any.
  bool HasParentId() const { return !!parent_id_; }
  int GetParentId() const { DCHECK(HasParentId()); return parent_id_.value(); }
  void SetParentId(int value) { parent_id_ = value; }

  // The BackendNodeId for this node.
  int GetBackendNodeId() const { return backend_node_id_; }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // `Node`'s nodeType.
  int GetNodeType() const { return node_type_; }
  void SetNodeType(int value) { node_type_ = value; }

  // `Node`'s nodeName.
  std::string GetNodeName() const { return node_name_; }
  void SetNodeName(const std::string& value) { node_name_ = value; }

  // `Node`'s localName.
  std::string GetLocalName() const { return local_name_; }
  void SetLocalName(const std::string& value) { local_name_ = value; }

  // `Node`'s nodeValue.
  std::string GetNodeValue() const { return node_value_; }
  void SetNodeValue(const std::string& value) { node_value_ = value; }

  // Child count for `Container` nodes.
  bool HasChildNodeCount() const { return !!child_node_count_; }
  int GetChildNodeCount() const { DCHECK(HasChildNodeCount()); return child_node_count_.value(); }
  void SetChildNodeCount(int value) { child_node_count_ = value; }

  // Child nodes of this node when requested with children.
  bool HasChildren() const { return !!children_; }
  const std::vector<std::unique_ptr<::headless::dom::Node>>* GetChildren() const { DCHECK(HasChildren()); return &children_.value(); }
  void SetChildren(std::vector<std::unique_ptr<::headless::dom::Node>> value) { children_ = std::move(value); }

  // Attributes of the `Element` node in the form of flat array `[name1, value1, name2, value2]`.
  bool HasAttributes() const { return !!attributes_; }
  const std::vector<std::string>* GetAttributes() const { DCHECK(HasAttributes()); return &attributes_.value(); }
  void SetAttributes(std::vector<std::string> value) { attributes_ = std::move(value); }

  // Document URL that `Document` or `FrameOwner` node points to.
  bool HasDocumentURL() const { return !!documenturl_; }
  std::string GetDocumentURL() const { DCHECK(HasDocumentURL()); return documenturl_.value(); }
  void SetDocumentURL(const std::string& value) { documenturl_ = value; }

  // Base URL that `Document` or `FrameOwner` node uses for URL completion.
  bool HasBaseURL() const { return !!baseurl_; }
  std::string GetBaseURL() const { DCHECK(HasBaseURL()); return baseurl_.value(); }
  void SetBaseURL(const std::string& value) { baseurl_ = value; }

  // `DocumentType`'s publicId.
  bool HasPublicId() const { return !!public_id_; }
  std::string GetPublicId() const { DCHECK(HasPublicId()); return public_id_.value(); }
  void SetPublicId(const std::string& value) { public_id_ = value; }

  // `DocumentType`'s systemId.
  bool HasSystemId() const { return !!system_id_; }
  std::string GetSystemId() const { DCHECK(HasSystemId()); return system_id_.value(); }
  void SetSystemId(const std::string& value) { system_id_ = value; }

  // `DocumentType`'s internalSubset.
  bool HasInternalSubset() const { return !!internal_subset_; }
  std::string GetInternalSubset() const { DCHECK(HasInternalSubset()); return internal_subset_.value(); }
  void SetInternalSubset(const std::string& value) { internal_subset_ = value; }

  // `Document`'s XML version in case of XML documents.
  bool HasXmlVersion() const { return !!xml_version_; }
  std::string GetXmlVersion() const { DCHECK(HasXmlVersion()); return xml_version_.value(); }
  void SetXmlVersion(const std::string& value) { xml_version_ = value; }

  // `Attr`'s name.
  bool HasName() const { return !!name_; }
  std::string GetName() const { DCHECK(HasName()); return name_.value(); }
  void SetName(const std::string& value) { name_ = value; }

  // `Attr`'s value.
  bool HasValue() const { return !!value_; }
  std::string GetValue() const { DCHECK(HasValue()); return value_.value(); }
  void SetValue(const std::string& value) { value_ = value; }

  // Pseudo element type for this node.
  bool HasPseudoType() const { return !!pseudo_type_; }
  ::headless::dom::PseudoType GetPseudoType() const { DCHECK(HasPseudoType()); return pseudo_type_.value(); }
  void SetPseudoType(::headless::dom::PseudoType value) { pseudo_type_ = value; }

  // Shadow root type.
  bool HasShadowRootType() const { return !!shadow_root_type_; }
  ::headless::dom::ShadowRootType GetShadowRootType() const { DCHECK(HasShadowRootType()); return shadow_root_type_.value(); }
  void SetShadowRootType(::headless::dom::ShadowRootType value) { shadow_root_type_ = value; }

  // Frame ID for frame owner elements.
  bool HasFrameId() const { return !!frame_id_; }
  std::string GetFrameId() const { DCHECK(HasFrameId()); return frame_id_.value(); }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Content document for frame owner elements.
  bool HasContentDocument() const { return !!content_document_; }
  const ::headless::dom::Node* GetContentDocument() const { DCHECK(HasContentDocument()); return content_document_.value().get(); }
  void SetContentDocument(std::unique_ptr<::headless::dom::Node> value) { content_document_ = std::move(value); }

  // Shadow root list for given element host.
  bool HasShadowRoots() const { return !!shadow_roots_; }
  const std::vector<std::unique_ptr<::headless::dom::Node>>* GetShadowRoots() const { DCHECK(HasShadowRoots()); return &shadow_roots_.value(); }
  void SetShadowRoots(std::vector<std::unique_ptr<::headless::dom::Node>> value) { shadow_roots_ = std::move(value); }

  // Content document fragment for template elements.
  bool HasTemplateContent() const { return !!template_content_; }
  const ::headless::dom::Node* GetTemplateContent() const { DCHECK(HasTemplateContent()); return template_content_.value().get(); }
  void SetTemplateContent(std::unique_ptr<::headless::dom::Node> value) { template_content_ = std::move(value); }

  // Pseudo elements associated with this node.
  bool HasPseudoElements() const { return !!pseudo_elements_; }
  const std::vector<std::unique_ptr<::headless::dom::Node>>* GetPseudoElements() const { DCHECK(HasPseudoElements()); return &pseudo_elements_.value(); }
  void SetPseudoElements(std::vector<std::unique_ptr<::headless::dom::Node>> value) { pseudo_elements_ = std::move(value); }

  // Import document for the HTMLImport links.
  bool HasImportedDocument() const { return !!imported_document_; }
  const ::headless::dom::Node* GetImportedDocument() const { DCHECK(HasImportedDocument()); return imported_document_.value().get(); }
  void SetImportedDocument(std::unique_ptr<::headless::dom::Node> value) { imported_document_ = std::move(value); }

  // Distributed nodes for given insertion point.
  bool HasDistributedNodes() const { return !!distributed_nodes_; }
  const std::vector<std::unique_ptr<::headless::dom::BackendNode>>* GetDistributedNodes() const { DCHECK(HasDistributedNodes()); return &distributed_nodes_.value(); }
  void SetDistributedNodes(std::vector<std::unique_ptr<::headless::dom::BackendNode>> value) { distributed_nodes_ = std::move(value); }

  // Whether the node is SVG.
  bool HasIsSVG() const { return !!issvg_; }
  bool GetIsSVG() const { DCHECK(HasIsSVG()); return issvg_.value(); }
  void SetIsSVG(bool value) { issvg_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Node> Clone() const;

  template<int STATE>
  class NodeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kBackendNodeIdSet = 1 << 2,
    kNodeTypeSet = 1 << 3,
    kNodeNameSet = 1 << 4,
    kLocalNameSet = 1 << 5,
    kNodeValueSet = 1 << 6,
      kAllRequiredFieldsSet = (kNodeIdSet | kBackendNodeIdSet | kNodeTypeSet | kNodeNameSet | kLocalNameSet | kNodeValueSet | 0)
    };

    NodeBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    NodeBuilder<STATE>& SetParentId(int value) {
      result_->SetParentId(value);
      return *this;
    }

    NodeBuilder<STATE | kBackendNodeIdSet>& SetBackendNodeId(int value) {
      static_assert(!(STATE & kBackendNodeIdSet), "property backendNodeId should not have already been set");
      result_->SetBackendNodeId(value);
      return CastState<kBackendNodeIdSet>();
    }

    NodeBuilder<STATE | kNodeTypeSet>& SetNodeType(int value) {
      static_assert(!(STATE & kNodeTypeSet), "property nodeType should not have already been set");
      result_->SetNodeType(value);
      return CastState<kNodeTypeSet>();
    }

    NodeBuilder<STATE | kNodeNameSet>& SetNodeName(const std::string& value) {
      static_assert(!(STATE & kNodeNameSet), "property nodeName should not have already been set");
      result_->SetNodeName(value);
      return CastState<kNodeNameSet>();
    }

    NodeBuilder<STATE | kLocalNameSet>& SetLocalName(const std::string& value) {
      static_assert(!(STATE & kLocalNameSet), "property localName should not have already been set");
      result_->SetLocalName(value);
      return CastState<kLocalNameSet>();
    }

    NodeBuilder<STATE | kNodeValueSet>& SetNodeValue(const std::string& value) {
      static_assert(!(STATE & kNodeValueSet), "property nodeValue should not have already been set");
      result_->SetNodeValue(value);
      return CastState<kNodeValueSet>();
    }

    NodeBuilder<STATE>& SetChildNodeCount(int value) {
      result_->SetChildNodeCount(value);
      return *this;
    }

    NodeBuilder<STATE>& SetChildren(std::vector<std::unique_ptr<::headless::dom::Node>> value) {
      result_->SetChildren(std::move(value));
      return *this;
    }

    NodeBuilder<STATE>& SetAttributes(std::vector<std::string> value) {
      result_->SetAttributes(std::move(value));
      return *this;
    }

    NodeBuilder<STATE>& SetDocumentURL(const std::string& value) {
      result_->SetDocumentURL(value);
      return *this;
    }

    NodeBuilder<STATE>& SetBaseURL(const std::string& value) {
      result_->SetBaseURL(value);
      return *this;
    }

    NodeBuilder<STATE>& SetPublicId(const std::string& value) {
      result_->SetPublicId(value);
      return *this;
    }

    NodeBuilder<STATE>& SetSystemId(const std::string& value) {
      result_->SetSystemId(value);
      return *this;
    }

    NodeBuilder<STATE>& SetInternalSubset(const std::string& value) {
      result_->SetInternalSubset(value);
      return *this;
    }

    NodeBuilder<STATE>& SetXmlVersion(const std::string& value) {
      result_->SetXmlVersion(value);
      return *this;
    }

    NodeBuilder<STATE>& SetName(const std::string& value) {
      result_->SetName(value);
      return *this;
    }

    NodeBuilder<STATE>& SetValue(const std::string& value) {
      result_->SetValue(value);
      return *this;
    }

    NodeBuilder<STATE>& SetPseudoType(::headless::dom::PseudoType value) {
      result_->SetPseudoType(value);
      return *this;
    }

    NodeBuilder<STATE>& SetShadowRootType(::headless::dom::ShadowRootType value) {
      result_->SetShadowRootType(value);
      return *this;
    }

    NodeBuilder<STATE>& SetFrameId(const std::string& value) {
      result_->SetFrameId(value);
      return *this;
    }

    NodeBuilder<STATE>& SetContentDocument(std::unique_ptr<::headless::dom::Node> value) {
      result_->SetContentDocument(std::move(value));
      return *this;
    }

    NodeBuilder<STATE>& SetShadowRoots(std::vector<std::unique_ptr<::headless::dom::Node>> value) {
      result_->SetShadowRoots(std::move(value));
      return *this;
    }

    NodeBuilder<STATE>& SetTemplateContent(std::unique_ptr<::headless::dom::Node> value) {
      result_->SetTemplateContent(std::move(value));
      return *this;
    }

    NodeBuilder<STATE>& SetPseudoElements(std::vector<std::unique_ptr<::headless::dom::Node>> value) {
      result_->SetPseudoElements(std::move(value));
      return *this;
    }

    NodeBuilder<STATE>& SetImportedDocument(std::unique_ptr<::headless::dom::Node> value) {
      result_->SetImportedDocument(std::move(value));
      return *this;
    }

    NodeBuilder<STATE>& SetDistributedNodes(std::vector<std::unique_ptr<::headless::dom::BackendNode>> value) {
      result_->SetDistributedNodes(std::move(value));
      return *this;
    }

    NodeBuilder<STATE>& SetIsSVG(bool value) {
      result_->SetIsSVG(value);
      return *this;
    }

    std::unique_ptr<Node> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Node;
    NodeBuilder() : result_(new Node()) { }

    template<int STEP> NodeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NodeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Node> result_;
  };

  static NodeBuilder<0> Builder() {
    return NodeBuilder<0>();
  }

 private:
  Node() { }

  int node_id_;
  base::Optional<int> parent_id_;
  int backend_node_id_;
  int node_type_;
  std::string node_name_;
  std::string local_name_;
  std::string node_value_;
  base::Optional<int> child_node_count_;
  base::Optional<std::vector<std::unique_ptr<::headless::dom::Node>>> children_;
  base::Optional<std::vector<std::string>> attributes_;
  base::Optional<std::string> documenturl_;
  base::Optional<std::string> baseurl_;
  base::Optional<std::string> public_id_;
  base::Optional<std::string> system_id_;
  base::Optional<std::string> internal_subset_;
  base::Optional<std::string> xml_version_;
  base::Optional<std::string> name_;
  base::Optional<std::string> value_;
  base::Optional<::headless::dom::PseudoType> pseudo_type_;
  base::Optional<::headless::dom::ShadowRootType> shadow_root_type_;
  base::Optional<std::string> frame_id_;
  base::Optional<std::unique_ptr<::headless::dom::Node>> content_document_;
  base::Optional<std::vector<std::unique_ptr<::headless::dom::Node>>> shadow_roots_;
  base::Optional<std::unique_ptr<::headless::dom::Node>> template_content_;
  base::Optional<std::vector<std::unique_ptr<::headless::dom::Node>>> pseudo_elements_;
  base::Optional<std::unique_ptr<::headless::dom::Node>> imported_document_;
  base::Optional<std::vector<std::unique_ptr<::headless::dom::BackendNode>>> distributed_nodes_;
  base::Optional<bool> issvg_;

  DISALLOW_COPY_AND_ASSIGN(Node);
};


// A structure holding an RGBA color.
class HEADLESS_EXPORT RGBA {
 public:
  static std::unique_ptr<RGBA> Parse(const base::Value& value, ErrorReporter* errors);
  ~RGBA() { }

  // The red component, in the [0-255] range.
  int GetR() const { return r_; }
  void SetR(int value) { r_ = value; }

  // The green component, in the [0-255] range.
  int GetG() const { return g_; }
  void SetG(int value) { g_ = value; }

  // The blue component, in the [0-255] range.
  int GetB() const { return b_; }
  void SetB(int value) { b_ = value; }

  // The alpha component, in the [0-1] range (default: 1).
  bool HasA() const { return !!a_; }
  double GetA() const { DCHECK(HasA()); return a_.value(); }
  void SetA(double value) { a_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RGBA> Clone() const;

  template<int STATE>
  class RGBABuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRSet = 1 << 1,
    kGSet = 1 << 2,
    kBSet = 1 << 3,
      kAllRequiredFieldsSet = (kRSet | kGSet | kBSet | 0)
    };

    RGBABuilder<STATE | kRSet>& SetR(int value) {
      static_assert(!(STATE & kRSet), "property r should not have already been set");
      result_->SetR(value);
      return CastState<kRSet>();
    }

    RGBABuilder<STATE | kGSet>& SetG(int value) {
      static_assert(!(STATE & kGSet), "property g should not have already been set");
      result_->SetG(value);
      return CastState<kGSet>();
    }

    RGBABuilder<STATE | kBSet>& SetB(int value) {
      static_assert(!(STATE & kBSet), "property b should not have already been set");
      result_->SetB(value);
      return CastState<kBSet>();
    }

    RGBABuilder<STATE>& SetA(double value) {
      result_->SetA(value);
      return *this;
    }

    std::unique_ptr<RGBA> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RGBA;
    RGBABuilder() : result_(new RGBA()) { }

    template<int STEP> RGBABuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RGBABuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RGBA> result_;
  };

  static RGBABuilder<0> Builder() {
    return RGBABuilder<0>();
  }

 private:
  RGBA() { }

  int r_;
  int g_;
  int b_;
  base::Optional<double> a_;

  DISALLOW_COPY_AND_ASSIGN(RGBA);
};


// Box model.
class HEADLESS_EXPORT BoxModel {
 public:
  static std::unique_ptr<BoxModel> Parse(const base::Value& value, ErrorReporter* errors);
  ~BoxModel() { }

  // Content box
  const std::vector<double>* GetContent() const { return &content_; }
  void SetContent(std::vector<double> value) { content_ = std::move(value); }

  // Padding box
  const std::vector<double>* GetPadding() const { return &padding_; }
  void SetPadding(std::vector<double> value) { padding_ = std::move(value); }

  // Border box
  const std::vector<double>* GetBorder() const { return &border_; }
  void SetBorder(std::vector<double> value) { border_ = std::move(value); }

  // Margin box
  const std::vector<double>* GetMargin() const { return &margin_; }
  void SetMargin(std::vector<double> value) { margin_ = std::move(value); }

  // Node width
  int GetWidth() const { return width_; }
  void SetWidth(int value) { width_ = value; }

  // Node height
  int GetHeight() const { return height_; }
  void SetHeight(int value) { height_ = value; }

  // Shape outside coordinates
  bool HasShapeOutside() const { return !!shape_outside_; }
  const ::headless::dom::ShapeOutsideInfo* GetShapeOutside() const { DCHECK(HasShapeOutside()); return shape_outside_.value().get(); }
  void SetShapeOutside(std::unique_ptr<::headless::dom::ShapeOutsideInfo> value) { shape_outside_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BoxModel> Clone() const;

  template<int STATE>
  class BoxModelBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContentSet = 1 << 1,
    kPaddingSet = 1 << 2,
    kBorderSet = 1 << 3,
    kMarginSet = 1 << 4,
    kWidthSet = 1 << 5,
    kHeightSet = 1 << 6,
      kAllRequiredFieldsSet = (kContentSet | kPaddingSet | kBorderSet | kMarginSet | kWidthSet | kHeightSet | 0)
    };

    BoxModelBuilder<STATE | kContentSet>& SetContent(std::vector<double> value) {
      static_assert(!(STATE & kContentSet), "property content should not have already been set");
      result_->SetContent(std::move(value));
      return CastState<kContentSet>();
    }

    BoxModelBuilder<STATE | kPaddingSet>& SetPadding(std::vector<double> value) {
      static_assert(!(STATE & kPaddingSet), "property padding should not have already been set");
      result_->SetPadding(std::move(value));
      return CastState<kPaddingSet>();
    }

    BoxModelBuilder<STATE | kBorderSet>& SetBorder(std::vector<double> value) {
      static_assert(!(STATE & kBorderSet), "property border should not have already been set");
      result_->SetBorder(std::move(value));
      return CastState<kBorderSet>();
    }

    BoxModelBuilder<STATE | kMarginSet>& SetMargin(std::vector<double> value) {
      static_assert(!(STATE & kMarginSet), "property margin should not have already been set");
      result_->SetMargin(std::move(value));
      return CastState<kMarginSet>();
    }

    BoxModelBuilder<STATE | kWidthSet>& SetWidth(int value) {
      static_assert(!(STATE & kWidthSet), "property width should not have already been set");
      result_->SetWidth(value);
      return CastState<kWidthSet>();
    }

    BoxModelBuilder<STATE | kHeightSet>& SetHeight(int value) {
      static_assert(!(STATE & kHeightSet), "property height should not have already been set");
      result_->SetHeight(value);
      return CastState<kHeightSet>();
    }

    BoxModelBuilder<STATE>& SetShapeOutside(std::unique_ptr<::headless::dom::ShapeOutsideInfo> value) {
      result_->SetShapeOutside(std::move(value));
      return *this;
    }

    std::unique_ptr<BoxModel> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BoxModel;
    BoxModelBuilder() : result_(new BoxModel()) { }

    template<int STEP> BoxModelBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BoxModelBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BoxModel> result_;
  };

  static BoxModelBuilder<0> Builder() {
    return BoxModelBuilder<0>();
  }

 private:
  BoxModel() { }

  std::vector<double> content_;
  std::vector<double> padding_;
  std::vector<double> border_;
  std::vector<double> margin_;
  int width_;
  int height_;
  base::Optional<std::unique_ptr<::headless::dom::ShapeOutsideInfo>> shape_outside_;

  DISALLOW_COPY_AND_ASSIGN(BoxModel);
};


// CSS Shape Outside details.
class HEADLESS_EXPORT ShapeOutsideInfo {
 public:
  static std::unique_ptr<ShapeOutsideInfo> Parse(const base::Value& value, ErrorReporter* errors);
  ~ShapeOutsideInfo() { }

  // Shape bounds
  const std::vector<double>* GetBounds() const { return &bounds_; }
  void SetBounds(std::vector<double> value) { bounds_ = std::move(value); }

  // Shape coordinate details
  const std::vector<std::unique_ptr<base::Value>>* GetShape() const { return &shape_; }
  void SetShape(std::vector<std::unique_ptr<base::Value>> value) { shape_ = std::move(value); }

  // Margin shape bounds
  const std::vector<std::unique_ptr<base::Value>>* GetMarginShape() const { return &margin_shape_; }
  void SetMarginShape(std::vector<std::unique_ptr<base::Value>> value) { margin_shape_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ShapeOutsideInfo> Clone() const;

  template<int STATE>
  class ShapeOutsideInfoBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBoundsSet = 1 << 1,
    kShapeSet = 1 << 2,
    kMarginShapeSet = 1 << 3,
      kAllRequiredFieldsSet = (kBoundsSet | kShapeSet | kMarginShapeSet | 0)
    };

    ShapeOutsideInfoBuilder<STATE | kBoundsSet>& SetBounds(std::vector<double> value) {
      static_assert(!(STATE & kBoundsSet), "property bounds should not have already been set");
      result_->SetBounds(std::move(value));
      return CastState<kBoundsSet>();
    }

    ShapeOutsideInfoBuilder<STATE | kShapeSet>& SetShape(std::vector<std::unique_ptr<base::Value>> value) {
      static_assert(!(STATE & kShapeSet), "property shape should not have already been set");
      result_->SetShape(std::move(value));
      return CastState<kShapeSet>();
    }

    ShapeOutsideInfoBuilder<STATE | kMarginShapeSet>& SetMarginShape(std::vector<std::unique_ptr<base::Value>> value) {
      static_assert(!(STATE & kMarginShapeSet), "property marginShape should not have already been set");
      result_->SetMarginShape(std::move(value));
      return CastState<kMarginShapeSet>();
    }

    std::unique_ptr<ShapeOutsideInfo> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ShapeOutsideInfo;
    ShapeOutsideInfoBuilder() : result_(new ShapeOutsideInfo()) { }

    template<int STEP> ShapeOutsideInfoBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ShapeOutsideInfoBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ShapeOutsideInfo> result_;
  };

  static ShapeOutsideInfoBuilder<0> Builder() {
    return ShapeOutsideInfoBuilder<0>();
  }

 private:
  ShapeOutsideInfo() { }

  std::vector<double> bounds_;
  std::vector<std::unique_ptr<base::Value>> shape_;
  std::vector<std::unique_ptr<base::Value>> margin_shape_;

  DISALLOW_COPY_AND_ASSIGN(ShapeOutsideInfo);
};


// Rectangle.
class HEADLESS_EXPORT Rect {
 public:
  static std::unique_ptr<Rect> Parse(const base::Value& value, ErrorReporter* errors);
  ~Rect() { }

  // X coordinate
  double GetX() const { return x_; }
  void SetX(double value) { x_ = value; }

  // Y coordinate
  double GetY() const { return y_; }
  void SetY(double value) { y_ = value; }

  // Rectangle width
  double GetWidth() const { return width_; }
  void SetWidth(double value) { width_ = value; }

  // Rectangle height
  double GetHeight() const { return height_; }
  void SetHeight(double value) { height_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Rect> Clone() const;

  template<int STATE>
  class RectBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kXSet = 1 << 1,
    kYSet = 1 << 2,
    kWidthSet = 1 << 3,
    kHeightSet = 1 << 4,
      kAllRequiredFieldsSet = (kXSet | kYSet | kWidthSet | kHeightSet | 0)
    };

    RectBuilder<STATE | kXSet>& SetX(double value) {
      static_assert(!(STATE & kXSet), "property x should not have already been set");
      result_->SetX(value);
      return CastState<kXSet>();
    }

    RectBuilder<STATE | kYSet>& SetY(double value) {
      static_assert(!(STATE & kYSet), "property y should not have already been set");
      result_->SetY(value);
      return CastState<kYSet>();
    }

    RectBuilder<STATE | kWidthSet>& SetWidth(double value) {
      static_assert(!(STATE & kWidthSet), "property width should not have already been set");
      result_->SetWidth(value);
      return CastState<kWidthSet>();
    }

    RectBuilder<STATE | kHeightSet>& SetHeight(double value) {
      static_assert(!(STATE & kHeightSet), "property height should not have already been set");
      result_->SetHeight(value);
      return CastState<kHeightSet>();
    }

    std::unique_ptr<Rect> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Rect;
    RectBuilder() : result_(new Rect()) { }

    template<int STEP> RectBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RectBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Rect> result_;
  };

  static RectBuilder<0> Builder() {
    return RectBuilder<0>();
  }

 private:
  Rect() { }

  double x_;
  double y_;
  double width_;
  double height_;

  DISALLOW_COPY_AND_ASSIGN(Rect);
};


// Parameters for the CollectClassNamesFromSubtree command.
class HEADLESS_EXPORT CollectClassNamesFromSubtreeParams {
 public:
  static std::unique_ptr<CollectClassNamesFromSubtreeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CollectClassNamesFromSubtreeParams() { }

  // Id of the node to collect class names.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CollectClassNamesFromSubtreeParams> Clone() const;

  template<int STATE>
  class CollectClassNamesFromSubtreeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    CollectClassNamesFromSubtreeParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<CollectClassNamesFromSubtreeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CollectClassNamesFromSubtreeParams;
    CollectClassNamesFromSubtreeParamsBuilder() : result_(new CollectClassNamesFromSubtreeParams()) { }

    template<int STEP> CollectClassNamesFromSubtreeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CollectClassNamesFromSubtreeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CollectClassNamesFromSubtreeParams> result_;
  };

  static CollectClassNamesFromSubtreeParamsBuilder<0> Builder() {
    return CollectClassNamesFromSubtreeParamsBuilder<0>();
  }

 private:
  CollectClassNamesFromSubtreeParams() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(CollectClassNamesFromSubtreeParams);
};


// Result for the CollectClassNamesFromSubtree command.
class HEADLESS_EXPORT CollectClassNamesFromSubtreeResult {
 public:
  static std::unique_ptr<CollectClassNamesFromSubtreeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CollectClassNamesFromSubtreeResult() { }

  // Class name list.
  const std::vector<std::string>* GetClassNames() const { return &class_names_; }
  void SetClassNames(std::vector<std::string> value) { class_names_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CollectClassNamesFromSubtreeResult> Clone() const;

  template<int STATE>
  class CollectClassNamesFromSubtreeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kClassNamesSet = 1 << 1,
      kAllRequiredFieldsSet = (kClassNamesSet | 0)
    };

    CollectClassNamesFromSubtreeResultBuilder<STATE | kClassNamesSet>& SetClassNames(std::vector<std::string> value) {
      static_assert(!(STATE & kClassNamesSet), "property classNames should not have already been set");
      result_->SetClassNames(std::move(value));
      return CastState<kClassNamesSet>();
    }

    std::unique_ptr<CollectClassNamesFromSubtreeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CollectClassNamesFromSubtreeResult;
    CollectClassNamesFromSubtreeResultBuilder() : result_(new CollectClassNamesFromSubtreeResult()) { }

    template<int STEP> CollectClassNamesFromSubtreeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CollectClassNamesFromSubtreeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CollectClassNamesFromSubtreeResult> result_;
  };

  static CollectClassNamesFromSubtreeResultBuilder<0> Builder() {
    return CollectClassNamesFromSubtreeResultBuilder<0>();
  }

 private:
  CollectClassNamesFromSubtreeResult() { }

  std::vector<std::string> class_names_;

  DISALLOW_COPY_AND_ASSIGN(CollectClassNamesFromSubtreeResult);
};


// Parameters for the CopyTo command.
class HEADLESS_EXPORT CopyToParams {
 public:
  static std::unique_ptr<CopyToParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CopyToParams() { }

  // Id of the node to copy.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // Id of the element to drop the copy into.
  int GetTargetNodeId() const { return target_node_id_; }
  void SetTargetNodeId(int value) { target_node_id_ = value; }

  // Drop the copy before this node (if absent, the copy becomes the last child of
  // `targetNodeId`).
  bool HasInsertBeforeNodeId() const { return !!insert_before_node_id_; }
  int GetInsertBeforeNodeId() const { DCHECK(HasInsertBeforeNodeId()); return insert_before_node_id_.value(); }
  void SetInsertBeforeNodeId(int value) { insert_before_node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CopyToParams> Clone() const;

  template<int STATE>
  class CopyToParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kTargetNodeIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kTargetNodeIdSet | 0)
    };

    CopyToParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    CopyToParamsBuilder<STATE | kTargetNodeIdSet>& SetTargetNodeId(int value) {
      static_assert(!(STATE & kTargetNodeIdSet), "property targetNodeId should not have already been set");
      result_->SetTargetNodeId(value);
      return CastState<kTargetNodeIdSet>();
    }

    CopyToParamsBuilder<STATE>& SetInsertBeforeNodeId(int value) {
      result_->SetInsertBeforeNodeId(value);
      return *this;
    }

    std::unique_ptr<CopyToParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CopyToParams;
    CopyToParamsBuilder() : result_(new CopyToParams()) { }

    template<int STEP> CopyToParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CopyToParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CopyToParams> result_;
  };

  static CopyToParamsBuilder<0> Builder() {
    return CopyToParamsBuilder<0>();
  }

 private:
  CopyToParams() { }

  int node_id_;
  int target_node_id_;
  base::Optional<int> insert_before_node_id_;

  DISALLOW_COPY_AND_ASSIGN(CopyToParams);
};


// Result for the CopyTo command.
class HEADLESS_EXPORT CopyToResult {
 public:
  static std::unique_ptr<CopyToResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CopyToResult() { }

  // Id of the node clone.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CopyToResult> Clone() const;

  template<int STATE>
  class CopyToResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    CopyToResultBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<CopyToResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CopyToResult;
    CopyToResultBuilder() : result_(new CopyToResult()) { }

    template<int STEP> CopyToResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CopyToResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CopyToResult> result_;
  };

  static CopyToResultBuilder<0> Builder() {
    return CopyToResultBuilder<0>();
  }

 private:
  CopyToResult() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(CopyToResult);
};


// Parameters for the DescribeNode command.
class HEADLESS_EXPORT DescribeNodeParams {
 public:
  static std::unique_ptr<DescribeNodeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DescribeNodeParams() { }

  // Identifier of the node.
  bool HasNodeId() const { return !!node_id_; }
  int GetNodeId() const { DCHECK(HasNodeId()); return node_id_.value(); }
  void SetNodeId(int value) { node_id_ = value; }

  // Identifier of the backend node.
  bool HasBackendNodeId() const { return !!backend_node_id_; }
  int GetBackendNodeId() const { DCHECK(HasBackendNodeId()); return backend_node_id_.value(); }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // JavaScript object id of the node wrapper.
  bool HasObjectId() const { return !!object_id_; }
  std::string GetObjectId() const { DCHECK(HasObjectId()); return object_id_.value(); }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  // The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
  // entire subtree or provide an integer larger than 0.
  bool HasDepth() const { return !!depth_; }
  int GetDepth() const { DCHECK(HasDepth()); return depth_.value(); }
  void SetDepth(int value) { depth_ = value; }

  // Whether or not iframes and shadow roots should be traversed when returning the subtree
  // (default is false).
  bool HasPierce() const { return !!pierce_; }
  bool GetPierce() const { DCHECK(HasPierce()); return pierce_.value(); }
  void SetPierce(bool value) { pierce_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DescribeNodeParams> Clone() const;

  template<int STATE>
  class DescribeNodeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    DescribeNodeParamsBuilder<STATE>& SetNodeId(int value) {
      result_->SetNodeId(value);
      return *this;
    }

    DescribeNodeParamsBuilder<STATE>& SetBackendNodeId(int value) {
      result_->SetBackendNodeId(value);
      return *this;
    }

    DescribeNodeParamsBuilder<STATE>& SetObjectId(const std::string& value) {
      result_->SetObjectId(value);
      return *this;
    }

    DescribeNodeParamsBuilder<STATE>& SetDepth(int value) {
      result_->SetDepth(value);
      return *this;
    }

    DescribeNodeParamsBuilder<STATE>& SetPierce(bool value) {
      result_->SetPierce(value);
      return *this;
    }

    std::unique_ptr<DescribeNodeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DescribeNodeParams;
    DescribeNodeParamsBuilder() : result_(new DescribeNodeParams()) { }

    template<int STEP> DescribeNodeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DescribeNodeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DescribeNodeParams> result_;
  };

  static DescribeNodeParamsBuilder<0> Builder() {
    return DescribeNodeParamsBuilder<0>();
  }

 private:
  DescribeNodeParams() { }

  base::Optional<int> node_id_;
  base::Optional<int> backend_node_id_;
  base::Optional<std::string> object_id_;
  base::Optional<int> depth_;
  base::Optional<bool> pierce_;

  DISALLOW_COPY_AND_ASSIGN(DescribeNodeParams);
};


// Result for the DescribeNode command.
class HEADLESS_EXPORT DescribeNodeResult {
 public:
  static std::unique_ptr<DescribeNodeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DescribeNodeResult() { }

  // Node description.
  const ::headless::dom::Node* GetNode() const { return node_.get(); }
  void SetNode(std::unique_ptr<::headless::dom::Node> value) { node_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DescribeNodeResult> Clone() const;

  template<int STATE>
  class DescribeNodeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeSet | 0)
    };

    DescribeNodeResultBuilder<STATE | kNodeSet>& SetNode(std::unique_ptr<::headless::dom::Node> value) {
      static_assert(!(STATE & kNodeSet), "property node should not have already been set");
      result_->SetNode(std::move(value));
      return CastState<kNodeSet>();
    }

    std::unique_ptr<DescribeNodeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DescribeNodeResult;
    DescribeNodeResultBuilder() : result_(new DescribeNodeResult()) { }

    template<int STEP> DescribeNodeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DescribeNodeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DescribeNodeResult> result_;
  };

  static DescribeNodeResultBuilder<0> Builder() {
    return DescribeNodeResultBuilder<0>();
  }

 private:
  DescribeNodeResult() { }

  std::unique_ptr<::headless::dom::Node> node_;

  DISALLOW_COPY_AND_ASSIGN(DescribeNodeResult);
};


// Parameters for the ScrollIntoViewIfNeeded command.
class HEADLESS_EXPORT ScrollIntoViewIfNeededParams {
 public:
  static std::unique_ptr<ScrollIntoViewIfNeededParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ScrollIntoViewIfNeededParams() { }

  // Identifier of the node.
  bool HasNodeId() const { return !!node_id_; }
  int GetNodeId() const { DCHECK(HasNodeId()); return node_id_.value(); }
  void SetNodeId(int value) { node_id_ = value; }

  // Identifier of the backend node.
  bool HasBackendNodeId() const { return !!backend_node_id_; }
  int GetBackendNodeId() const { DCHECK(HasBackendNodeId()); return backend_node_id_.value(); }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // JavaScript object id of the node wrapper.
  bool HasObjectId() const { return !!object_id_; }
  std::string GetObjectId() const { DCHECK(HasObjectId()); return object_id_.value(); }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  // The rect to be scrolled into view, relative to the node's border box, in CSS pixels.
  // When omitted, center of the node will be used, similar to Element.scrollIntoView.
  bool HasRect() const { return !!rect_; }
  const ::headless::dom::Rect* GetRect() const { DCHECK(HasRect()); return rect_.value().get(); }
  void SetRect(std::unique_ptr<::headless::dom::Rect> value) { rect_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ScrollIntoViewIfNeededParams> Clone() const;

  template<int STATE>
  class ScrollIntoViewIfNeededParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    ScrollIntoViewIfNeededParamsBuilder<STATE>& SetNodeId(int value) {
      result_->SetNodeId(value);
      return *this;
    }

    ScrollIntoViewIfNeededParamsBuilder<STATE>& SetBackendNodeId(int value) {
      result_->SetBackendNodeId(value);
      return *this;
    }

    ScrollIntoViewIfNeededParamsBuilder<STATE>& SetObjectId(const std::string& value) {
      result_->SetObjectId(value);
      return *this;
    }

    ScrollIntoViewIfNeededParamsBuilder<STATE>& SetRect(std::unique_ptr<::headless::dom::Rect> value) {
      result_->SetRect(std::move(value));
      return *this;
    }

    std::unique_ptr<ScrollIntoViewIfNeededParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ScrollIntoViewIfNeededParams;
    ScrollIntoViewIfNeededParamsBuilder() : result_(new ScrollIntoViewIfNeededParams()) { }

    template<int STEP> ScrollIntoViewIfNeededParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ScrollIntoViewIfNeededParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ScrollIntoViewIfNeededParams> result_;
  };

  static ScrollIntoViewIfNeededParamsBuilder<0> Builder() {
    return ScrollIntoViewIfNeededParamsBuilder<0>();
  }

 private:
  ScrollIntoViewIfNeededParams() { }

  base::Optional<int> node_id_;
  base::Optional<int> backend_node_id_;
  base::Optional<std::string> object_id_;
  base::Optional<std::unique_ptr<::headless::dom::Rect>> rect_;

  DISALLOW_COPY_AND_ASSIGN(ScrollIntoViewIfNeededParams);
};


// Result for the ScrollIntoViewIfNeeded command.
class HEADLESS_EXPORT ScrollIntoViewIfNeededResult {
 public:
  static std::unique_ptr<ScrollIntoViewIfNeededResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ScrollIntoViewIfNeededResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ScrollIntoViewIfNeededResult> Clone() const;

  template<int STATE>
  class ScrollIntoViewIfNeededResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ScrollIntoViewIfNeededResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ScrollIntoViewIfNeededResult;
    ScrollIntoViewIfNeededResultBuilder() : result_(new ScrollIntoViewIfNeededResult()) { }

    template<int STEP> ScrollIntoViewIfNeededResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ScrollIntoViewIfNeededResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ScrollIntoViewIfNeededResult> result_;
  };

  static ScrollIntoViewIfNeededResultBuilder<0> Builder() {
    return ScrollIntoViewIfNeededResultBuilder<0>();
  }

 private:
  ScrollIntoViewIfNeededResult() { }


  DISALLOW_COPY_AND_ASSIGN(ScrollIntoViewIfNeededResult);
};


// Parameters for the Disable command.
class HEADLESS_EXPORT DisableParams {
 public:
  static std::unique_ptr<DisableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableParams> Clone() const;

  template<int STATE>
  class DisableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableParams;
    DisableParamsBuilder() : result_(new DisableParams()) { }

    template<int STEP> DisableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableParams> result_;
  };

  static DisableParamsBuilder<0> Builder() {
    return DisableParamsBuilder<0>();
  }

 private:
  DisableParams() { }


  DISALLOW_COPY_AND_ASSIGN(DisableParams);
};


// Result for the Disable command.
class HEADLESS_EXPORT DisableResult {
 public:
  static std::unique_ptr<DisableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableResult> Clone() const;

  template<int STATE>
  class DisableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableResult;
    DisableResultBuilder() : result_(new DisableResult()) { }

    template<int STEP> DisableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableResult> result_;
  };

  static DisableResultBuilder<0> Builder() {
    return DisableResultBuilder<0>();
  }

 private:
  DisableResult() { }


  DISALLOW_COPY_AND_ASSIGN(DisableResult);
};


// Parameters for the DiscardSearchResults command.
class HEADLESS_EXPORT DiscardSearchResultsParams {
 public:
  static std::unique_ptr<DiscardSearchResultsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DiscardSearchResultsParams() { }

  // Unique search session identifier.
  std::string GetSearchId() const { return search_id_; }
  void SetSearchId(const std::string& value) { search_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DiscardSearchResultsParams> Clone() const;

  template<int STATE>
  class DiscardSearchResultsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSearchIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSearchIdSet | 0)
    };

    DiscardSearchResultsParamsBuilder<STATE | kSearchIdSet>& SetSearchId(const std::string& value) {
      static_assert(!(STATE & kSearchIdSet), "property searchId should not have already been set");
      result_->SetSearchId(value);
      return CastState<kSearchIdSet>();
    }

    std::unique_ptr<DiscardSearchResultsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DiscardSearchResultsParams;
    DiscardSearchResultsParamsBuilder() : result_(new DiscardSearchResultsParams()) { }

    template<int STEP> DiscardSearchResultsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DiscardSearchResultsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DiscardSearchResultsParams> result_;
  };

  static DiscardSearchResultsParamsBuilder<0> Builder() {
    return DiscardSearchResultsParamsBuilder<0>();
  }

 private:
  DiscardSearchResultsParams() { }

  std::string search_id_;

  DISALLOW_COPY_AND_ASSIGN(DiscardSearchResultsParams);
};


// Result for the DiscardSearchResults command.
class HEADLESS_EXPORT DiscardSearchResultsResult {
 public:
  static std::unique_ptr<DiscardSearchResultsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DiscardSearchResultsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DiscardSearchResultsResult> Clone() const;

  template<int STATE>
  class DiscardSearchResultsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DiscardSearchResultsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DiscardSearchResultsResult;
    DiscardSearchResultsResultBuilder() : result_(new DiscardSearchResultsResult()) { }

    template<int STEP> DiscardSearchResultsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DiscardSearchResultsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DiscardSearchResultsResult> result_;
  };

  static DiscardSearchResultsResultBuilder<0> Builder() {
    return DiscardSearchResultsResultBuilder<0>();
  }

 private:
  DiscardSearchResultsResult() { }


  DISALLOW_COPY_AND_ASSIGN(DiscardSearchResultsResult);
};


// Parameters for the Enable command.
class HEADLESS_EXPORT EnableParams {
 public:
  static std::unique_ptr<EnableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableParams;
    EnableParamsBuilder() : result_(new EnableParams()) { }

    template<int STEP> EnableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableParams> result_;
  };

  static EnableParamsBuilder<0> Builder() {
    return EnableParamsBuilder<0>();
  }

 private:
  EnableParams() { }


  DISALLOW_COPY_AND_ASSIGN(EnableParams);
};


// Result for the Enable command.
class HEADLESS_EXPORT EnableResult {
 public:
  static std::unique_ptr<EnableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableResult> Clone() const;

  template<int STATE>
  class EnableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableResult;
    EnableResultBuilder() : result_(new EnableResult()) { }

    template<int STEP> EnableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableResult> result_;
  };

  static EnableResultBuilder<0> Builder() {
    return EnableResultBuilder<0>();
  }

 private:
  EnableResult() { }


  DISALLOW_COPY_AND_ASSIGN(EnableResult);
};


// Parameters for the Focus command.
class HEADLESS_EXPORT FocusParams {
 public:
  static std::unique_ptr<FocusParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FocusParams() { }

  // Identifier of the node.
  bool HasNodeId() const { return !!node_id_; }
  int GetNodeId() const { DCHECK(HasNodeId()); return node_id_.value(); }
  void SetNodeId(int value) { node_id_ = value; }

  // Identifier of the backend node.
  bool HasBackendNodeId() const { return !!backend_node_id_; }
  int GetBackendNodeId() const { DCHECK(HasBackendNodeId()); return backend_node_id_.value(); }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // JavaScript object id of the node wrapper.
  bool HasObjectId() const { return !!object_id_; }
  std::string GetObjectId() const { DCHECK(HasObjectId()); return object_id_.value(); }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FocusParams> Clone() const;

  template<int STATE>
  class FocusParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    FocusParamsBuilder<STATE>& SetNodeId(int value) {
      result_->SetNodeId(value);
      return *this;
    }

    FocusParamsBuilder<STATE>& SetBackendNodeId(int value) {
      result_->SetBackendNodeId(value);
      return *this;
    }

    FocusParamsBuilder<STATE>& SetObjectId(const std::string& value) {
      result_->SetObjectId(value);
      return *this;
    }

    std::unique_ptr<FocusParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FocusParams;
    FocusParamsBuilder() : result_(new FocusParams()) { }

    template<int STEP> FocusParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FocusParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FocusParams> result_;
  };

  static FocusParamsBuilder<0> Builder() {
    return FocusParamsBuilder<0>();
  }

 private:
  FocusParams() { }

  base::Optional<int> node_id_;
  base::Optional<int> backend_node_id_;
  base::Optional<std::string> object_id_;

  DISALLOW_COPY_AND_ASSIGN(FocusParams);
};


// Result for the Focus command.
class HEADLESS_EXPORT FocusResult {
 public:
  static std::unique_ptr<FocusResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~FocusResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FocusResult> Clone() const;

  template<int STATE>
  class FocusResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<FocusResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FocusResult;
    FocusResultBuilder() : result_(new FocusResult()) { }

    template<int STEP> FocusResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FocusResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FocusResult> result_;
  };

  static FocusResultBuilder<0> Builder() {
    return FocusResultBuilder<0>();
  }

 private:
  FocusResult() { }


  DISALLOW_COPY_AND_ASSIGN(FocusResult);
};


// Parameters for the GetAttributes command.
class HEADLESS_EXPORT GetAttributesParams {
 public:
  static std::unique_ptr<GetAttributesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetAttributesParams() { }

  // Id of the node to retrieve attibutes for.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetAttributesParams> Clone() const;

  template<int STATE>
  class GetAttributesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    GetAttributesParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<GetAttributesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetAttributesParams;
    GetAttributesParamsBuilder() : result_(new GetAttributesParams()) { }

    template<int STEP> GetAttributesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetAttributesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetAttributesParams> result_;
  };

  static GetAttributesParamsBuilder<0> Builder() {
    return GetAttributesParamsBuilder<0>();
  }

 private:
  GetAttributesParams() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(GetAttributesParams);
};


// Result for the GetAttributes command.
class HEADLESS_EXPORT GetAttributesResult {
 public:
  static std::unique_ptr<GetAttributesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetAttributesResult() { }

  // An interleaved array of node attribute names and values.
  const std::vector<std::string>* GetAttributes() const { return &attributes_; }
  void SetAttributes(std::vector<std::string> value) { attributes_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetAttributesResult> Clone() const;

  template<int STATE>
  class GetAttributesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAttributesSet = 1 << 1,
      kAllRequiredFieldsSet = (kAttributesSet | 0)
    };

    GetAttributesResultBuilder<STATE | kAttributesSet>& SetAttributes(std::vector<std::string> value) {
      static_assert(!(STATE & kAttributesSet), "property attributes should not have already been set");
      result_->SetAttributes(std::move(value));
      return CastState<kAttributesSet>();
    }

    std::unique_ptr<GetAttributesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetAttributesResult;
    GetAttributesResultBuilder() : result_(new GetAttributesResult()) { }

    template<int STEP> GetAttributesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetAttributesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetAttributesResult> result_;
  };

  static GetAttributesResultBuilder<0> Builder() {
    return GetAttributesResultBuilder<0>();
  }

 private:
  GetAttributesResult() { }

  std::vector<std::string> attributes_;

  DISALLOW_COPY_AND_ASSIGN(GetAttributesResult);
};


// Parameters for the GetBoxModel command.
class HEADLESS_EXPORT GetBoxModelParams {
 public:
  static std::unique_ptr<GetBoxModelParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetBoxModelParams() { }

  // Identifier of the node.
  bool HasNodeId() const { return !!node_id_; }
  int GetNodeId() const { DCHECK(HasNodeId()); return node_id_.value(); }
  void SetNodeId(int value) { node_id_ = value; }

  // Identifier of the backend node.
  bool HasBackendNodeId() const { return !!backend_node_id_; }
  int GetBackendNodeId() const { DCHECK(HasBackendNodeId()); return backend_node_id_.value(); }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // JavaScript object id of the node wrapper.
  bool HasObjectId() const { return !!object_id_; }
  std::string GetObjectId() const { DCHECK(HasObjectId()); return object_id_.value(); }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetBoxModelParams> Clone() const;

  template<int STATE>
  class GetBoxModelParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GetBoxModelParamsBuilder<STATE>& SetNodeId(int value) {
      result_->SetNodeId(value);
      return *this;
    }

    GetBoxModelParamsBuilder<STATE>& SetBackendNodeId(int value) {
      result_->SetBackendNodeId(value);
      return *this;
    }

    GetBoxModelParamsBuilder<STATE>& SetObjectId(const std::string& value) {
      result_->SetObjectId(value);
      return *this;
    }

    std::unique_ptr<GetBoxModelParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetBoxModelParams;
    GetBoxModelParamsBuilder() : result_(new GetBoxModelParams()) { }

    template<int STEP> GetBoxModelParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetBoxModelParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetBoxModelParams> result_;
  };

  static GetBoxModelParamsBuilder<0> Builder() {
    return GetBoxModelParamsBuilder<0>();
  }

 private:
  GetBoxModelParams() { }

  base::Optional<int> node_id_;
  base::Optional<int> backend_node_id_;
  base::Optional<std::string> object_id_;

  DISALLOW_COPY_AND_ASSIGN(GetBoxModelParams);
};


// Result for the GetBoxModel command.
class HEADLESS_EXPORT GetBoxModelResult {
 public:
  static std::unique_ptr<GetBoxModelResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetBoxModelResult() { }

  // Box model for the node.
  const ::headless::dom::BoxModel* GetModel() const { return model_.get(); }
  void SetModel(std::unique_ptr<::headless::dom::BoxModel> value) { model_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetBoxModelResult> Clone() const;

  template<int STATE>
  class GetBoxModelResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kModelSet = 1 << 1,
      kAllRequiredFieldsSet = (kModelSet | 0)
    };

    GetBoxModelResultBuilder<STATE | kModelSet>& SetModel(std::unique_ptr<::headless::dom::BoxModel> value) {
      static_assert(!(STATE & kModelSet), "property model should not have already been set");
      result_->SetModel(std::move(value));
      return CastState<kModelSet>();
    }

    std::unique_ptr<GetBoxModelResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetBoxModelResult;
    GetBoxModelResultBuilder() : result_(new GetBoxModelResult()) { }

    template<int STEP> GetBoxModelResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetBoxModelResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetBoxModelResult> result_;
  };

  static GetBoxModelResultBuilder<0> Builder() {
    return GetBoxModelResultBuilder<0>();
  }

 private:
  GetBoxModelResult() { }

  std::unique_ptr<::headless::dom::BoxModel> model_;

  DISALLOW_COPY_AND_ASSIGN(GetBoxModelResult);
};


// Parameters for the GetContentQuads command.
class HEADLESS_EXPORT GetContentQuadsParams {
 public:
  static std::unique_ptr<GetContentQuadsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetContentQuadsParams() { }

  // Identifier of the node.
  bool HasNodeId() const { return !!node_id_; }
  int GetNodeId() const { DCHECK(HasNodeId()); return node_id_.value(); }
  void SetNodeId(int value) { node_id_ = value; }

  // Identifier of the backend node.
  bool HasBackendNodeId() const { return !!backend_node_id_; }
  int GetBackendNodeId() const { DCHECK(HasBackendNodeId()); return backend_node_id_.value(); }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // JavaScript object id of the node wrapper.
  bool HasObjectId() const { return !!object_id_; }
  std::string GetObjectId() const { DCHECK(HasObjectId()); return object_id_.value(); }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetContentQuadsParams> Clone() const;

  template<int STATE>
  class GetContentQuadsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GetContentQuadsParamsBuilder<STATE>& SetNodeId(int value) {
      result_->SetNodeId(value);
      return *this;
    }

    GetContentQuadsParamsBuilder<STATE>& SetBackendNodeId(int value) {
      result_->SetBackendNodeId(value);
      return *this;
    }

    GetContentQuadsParamsBuilder<STATE>& SetObjectId(const std::string& value) {
      result_->SetObjectId(value);
      return *this;
    }

    std::unique_ptr<GetContentQuadsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetContentQuadsParams;
    GetContentQuadsParamsBuilder() : result_(new GetContentQuadsParams()) { }

    template<int STEP> GetContentQuadsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetContentQuadsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetContentQuadsParams> result_;
  };

  static GetContentQuadsParamsBuilder<0> Builder() {
    return GetContentQuadsParamsBuilder<0>();
  }

 private:
  GetContentQuadsParams() { }

  base::Optional<int> node_id_;
  base::Optional<int> backend_node_id_;
  base::Optional<std::string> object_id_;

  DISALLOW_COPY_AND_ASSIGN(GetContentQuadsParams);
};


// Result for the GetContentQuads command.
class HEADLESS_EXPORT GetContentQuadsResult {
 public:
  static std::unique_ptr<GetContentQuadsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetContentQuadsResult() { }

  // Quads that describe node layout relative to viewport.
  const std::vector<std::vector<double>>* GetQuads() const { return &quads_; }
  void SetQuads(std::vector<std::vector<double>> value) { quads_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetContentQuadsResult> Clone() const;

  template<int STATE>
  class GetContentQuadsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kQuadsSet = 1 << 1,
      kAllRequiredFieldsSet = (kQuadsSet | 0)
    };

    GetContentQuadsResultBuilder<STATE | kQuadsSet>& SetQuads(std::vector<std::vector<double>> value) {
      static_assert(!(STATE & kQuadsSet), "property quads should not have already been set");
      result_->SetQuads(std::move(value));
      return CastState<kQuadsSet>();
    }

    std::unique_ptr<GetContentQuadsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetContentQuadsResult;
    GetContentQuadsResultBuilder() : result_(new GetContentQuadsResult()) { }

    template<int STEP> GetContentQuadsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetContentQuadsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetContentQuadsResult> result_;
  };

  static GetContentQuadsResultBuilder<0> Builder() {
    return GetContentQuadsResultBuilder<0>();
  }

 private:
  GetContentQuadsResult() { }

  std::vector<std::vector<double>> quads_;

  DISALLOW_COPY_AND_ASSIGN(GetContentQuadsResult);
};


// Parameters for the GetDocument command.
class HEADLESS_EXPORT GetDocumentParams {
 public:
  static std::unique_ptr<GetDocumentParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetDocumentParams() { }

  // The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
  // entire subtree or provide an integer larger than 0.
  bool HasDepth() const { return !!depth_; }
  int GetDepth() const { DCHECK(HasDepth()); return depth_.value(); }
  void SetDepth(int value) { depth_ = value; }

  // Whether or not iframes and shadow roots should be traversed when returning the subtree
  // (default is false).
  bool HasPierce() const { return !!pierce_; }
  bool GetPierce() const { DCHECK(HasPierce()); return pierce_.value(); }
  void SetPierce(bool value) { pierce_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetDocumentParams> Clone() const;

  template<int STATE>
  class GetDocumentParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GetDocumentParamsBuilder<STATE>& SetDepth(int value) {
      result_->SetDepth(value);
      return *this;
    }

    GetDocumentParamsBuilder<STATE>& SetPierce(bool value) {
      result_->SetPierce(value);
      return *this;
    }

    std::unique_ptr<GetDocumentParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetDocumentParams;
    GetDocumentParamsBuilder() : result_(new GetDocumentParams()) { }

    template<int STEP> GetDocumentParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetDocumentParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetDocumentParams> result_;
  };

  static GetDocumentParamsBuilder<0> Builder() {
    return GetDocumentParamsBuilder<0>();
  }

 private:
  GetDocumentParams() { }

  base::Optional<int> depth_;
  base::Optional<bool> pierce_;

  DISALLOW_COPY_AND_ASSIGN(GetDocumentParams);
};


// Result for the GetDocument command.
class HEADLESS_EXPORT GetDocumentResult {
 public:
  static std::unique_ptr<GetDocumentResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetDocumentResult() { }

  // Resulting node.
  const ::headless::dom::Node* GetRoot() const { return root_.get(); }
  void SetRoot(std::unique_ptr<::headless::dom::Node> value) { root_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetDocumentResult> Clone() const;

  template<int STATE>
  class GetDocumentResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRootSet = 1 << 1,
      kAllRequiredFieldsSet = (kRootSet | 0)
    };

    GetDocumentResultBuilder<STATE | kRootSet>& SetRoot(std::unique_ptr<::headless::dom::Node> value) {
      static_assert(!(STATE & kRootSet), "property root should not have already been set");
      result_->SetRoot(std::move(value));
      return CastState<kRootSet>();
    }

    std::unique_ptr<GetDocumentResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetDocumentResult;
    GetDocumentResultBuilder() : result_(new GetDocumentResult()) { }

    template<int STEP> GetDocumentResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetDocumentResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetDocumentResult> result_;
  };

  static GetDocumentResultBuilder<0> Builder() {
    return GetDocumentResultBuilder<0>();
  }

 private:
  GetDocumentResult() { }

  std::unique_ptr<::headless::dom::Node> root_;

  DISALLOW_COPY_AND_ASSIGN(GetDocumentResult);
};


// Parameters for the GetFlattenedDocument command.
class HEADLESS_EXPORT GetFlattenedDocumentParams {
 public:
  static std::unique_ptr<GetFlattenedDocumentParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFlattenedDocumentParams() { }

  // The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
  // entire subtree or provide an integer larger than 0.
  bool HasDepth() const { return !!depth_; }
  int GetDepth() const { DCHECK(HasDepth()); return depth_.value(); }
  void SetDepth(int value) { depth_ = value; }

  // Whether or not iframes and shadow roots should be traversed when returning the subtree
  // (default is false).
  bool HasPierce() const { return !!pierce_; }
  bool GetPierce() const { DCHECK(HasPierce()); return pierce_.value(); }
  void SetPierce(bool value) { pierce_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFlattenedDocumentParams> Clone() const;

  template<int STATE>
  class GetFlattenedDocumentParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GetFlattenedDocumentParamsBuilder<STATE>& SetDepth(int value) {
      result_->SetDepth(value);
      return *this;
    }

    GetFlattenedDocumentParamsBuilder<STATE>& SetPierce(bool value) {
      result_->SetPierce(value);
      return *this;
    }

    std::unique_ptr<GetFlattenedDocumentParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFlattenedDocumentParams;
    GetFlattenedDocumentParamsBuilder() : result_(new GetFlattenedDocumentParams()) { }

    template<int STEP> GetFlattenedDocumentParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFlattenedDocumentParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFlattenedDocumentParams> result_;
  };

  static GetFlattenedDocumentParamsBuilder<0> Builder() {
    return GetFlattenedDocumentParamsBuilder<0>();
  }

 private:
  GetFlattenedDocumentParams() { }

  base::Optional<int> depth_;
  base::Optional<bool> pierce_;

  DISALLOW_COPY_AND_ASSIGN(GetFlattenedDocumentParams);
};


// Result for the GetFlattenedDocument command.
class HEADLESS_EXPORT GetFlattenedDocumentResult {
 public:
  static std::unique_ptr<GetFlattenedDocumentResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFlattenedDocumentResult() { }

  // Resulting node.
  const std::vector<std::unique_ptr<::headless::dom::Node>>* GetNodes() const { return &nodes_; }
  void SetNodes(std::vector<std::unique_ptr<::headless::dom::Node>> value) { nodes_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFlattenedDocumentResult> Clone() const;

  template<int STATE>
  class GetFlattenedDocumentResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodesSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodesSet | 0)
    };

    GetFlattenedDocumentResultBuilder<STATE | kNodesSet>& SetNodes(std::vector<std::unique_ptr<::headless::dom::Node>> value) {
      static_assert(!(STATE & kNodesSet), "property nodes should not have already been set");
      result_->SetNodes(std::move(value));
      return CastState<kNodesSet>();
    }

    std::unique_ptr<GetFlattenedDocumentResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFlattenedDocumentResult;
    GetFlattenedDocumentResultBuilder() : result_(new GetFlattenedDocumentResult()) { }

    template<int STEP> GetFlattenedDocumentResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFlattenedDocumentResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFlattenedDocumentResult> result_;
  };

  static GetFlattenedDocumentResultBuilder<0> Builder() {
    return GetFlattenedDocumentResultBuilder<0>();
  }

 private:
  GetFlattenedDocumentResult() { }

  std::vector<std::unique_ptr<::headless::dom::Node>> nodes_;

  DISALLOW_COPY_AND_ASSIGN(GetFlattenedDocumentResult);
};


// Parameters for the GetNodeForLocation command.
class HEADLESS_EXPORT GetNodeForLocationParams {
 public:
  static std::unique_ptr<GetNodeForLocationParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetNodeForLocationParams() { }

  // X coordinate.
  int GetX() const { return x_; }
  void SetX(int value) { x_ = value; }

  // Y coordinate.
  int GetY() const { return y_; }
  void SetY(int value) { y_ = value; }

  // False to skip to the nearest non-UA shadow root ancestor (default: false).
  bool HasIncludeUserAgentShadowDOM() const { return !!include_user_agent_shadowdom_; }
  bool GetIncludeUserAgentShadowDOM() const { DCHECK(HasIncludeUserAgentShadowDOM()); return include_user_agent_shadowdom_.value(); }
  void SetIncludeUserAgentShadowDOM(bool value) { include_user_agent_shadowdom_ = value; }

  // Whether to ignore pointer-events: none on elements and hit test them.
  bool HasIgnorePointerEventsNone() const { return !!ignore_pointer_events_none_; }
  bool GetIgnorePointerEventsNone() const { DCHECK(HasIgnorePointerEventsNone()); return ignore_pointer_events_none_.value(); }
  void SetIgnorePointerEventsNone(bool value) { ignore_pointer_events_none_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetNodeForLocationParams> Clone() const;

  template<int STATE>
  class GetNodeForLocationParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kXSet = 1 << 1,
    kYSet = 1 << 2,
      kAllRequiredFieldsSet = (kXSet | kYSet | 0)
    };

    GetNodeForLocationParamsBuilder<STATE | kXSet>& SetX(int value) {
      static_assert(!(STATE & kXSet), "property x should not have already been set");
      result_->SetX(value);
      return CastState<kXSet>();
    }

    GetNodeForLocationParamsBuilder<STATE | kYSet>& SetY(int value) {
      static_assert(!(STATE & kYSet), "property y should not have already been set");
      result_->SetY(value);
      return CastState<kYSet>();
    }

    GetNodeForLocationParamsBuilder<STATE>& SetIncludeUserAgentShadowDOM(bool value) {
      result_->SetIncludeUserAgentShadowDOM(value);
      return *this;
    }

    GetNodeForLocationParamsBuilder<STATE>& SetIgnorePointerEventsNone(bool value) {
      result_->SetIgnorePointerEventsNone(value);
      return *this;
    }

    std::unique_ptr<GetNodeForLocationParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetNodeForLocationParams;
    GetNodeForLocationParamsBuilder() : result_(new GetNodeForLocationParams()) { }

    template<int STEP> GetNodeForLocationParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetNodeForLocationParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetNodeForLocationParams> result_;
  };

  static GetNodeForLocationParamsBuilder<0> Builder() {
    return GetNodeForLocationParamsBuilder<0>();
  }

 private:
  GetNodeForLocationParams() { }

  int x_;
  int y_;
  base::Optional<bool> include_user_agent_shadowdom_;
  base::Optional<bool> ignore_pointer_events_none_;

  DISALLOW_COPY_AND_ASSIGN(GetNodeForLocationParams);
};


// Result for the GetNodeForLocation command.
class HEADLESS_EXPORT GetNodeForLocationResult {
 public:
  static std::unique_ptr<GetNodeForLocationResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetNodeForLocationResult() { }

  // Resulting node.
  int GetBackendNodeId() const { return backend_node_id_; }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // Frame this node belongs to.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Id of the node at given coordinates, only when enabled and requested document.
  bool HasNodeId() const { return !!node_id_; }
  int GetNodeId() const { DCHECK(HasNodeId()); return node_id_.value(); }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetNodeForLocationResult> Clone() const;

  template<int STATE>
  class GetNodeForLocationResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBackendNodeIdSet = 1 << 1,
    kFrameIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kBackendNodeIdSet | kFrameIdSet | 0)
    };

    GetNodeForLocationResultBuilder<STATE | kBackendNodeIdSet>& SetBackendNodeId(int value) {
      static_assert(!(STATE & kBackendNodeIdSet), "property backendNodeId should not have already been set");
      result_->SetBackendNodeId(value);
      return CastState<kBackendNodeIdSet>();
    }

    GetNodeForLocationResultBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    GetNodeForLocationResultBuilder<STATE>& SetNodeId(int value) {
      result_->SetNodeId(value);
      return *this;
    }

    std::unique_ptr<GetNodeForLocationResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetNodeForLocationResult;
    GetNodeForLocationResultBuilder() : result_(new GetNodeForLocationResult()) { }

    template<int STEP> GetNodeForLocationResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetNodeForLocationResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetNodeForLocationResult> result_;
  };

  static GetNodeForLocationResultBuilder<0> Builder() {
    return GetNodeForLocationResultBuilder<0>();
  }

 private:
  GetNodeForLocationResult() { }

  int backend_node_id_;
  std::string frame_id_;
  base::Optional<int> node_id_;

  DISALLOW_COPY_AND_ASSIGN(GetNodeForLocationResult);
};


// Parameters for the GetOuterHTML command.
class HEADLESS_EXPORT GetOuterHTMLParams {
 public:
  static std::unique_ptr<GetOuterHTMLParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetOuterHTMLParams() { }

  // Identifier of the node.
  bool HasNodeId() const { return !!node_id_; }
  int GetNodeId() const { DCHECK(HasNodeId()); return node_id_.value(); }
  void SetNodeId(int value) { node_id_ = value; }

  // Identifier of the backend node.
  bool HasBackendNodeId() const { return !!backend_node_id_; }
  int GetBackendNodeId() const { DCHECK(HasBackendNodeId()); return backend_node_id_.value(); }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // JavaScript object id of the node wrapper.
  bool HasObjectId() const { return !!object_id_; }
  std::string GetObjectId() const { DCHECK(HasObjectId()); return object_id_.value(); }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetOuterHTMLParams> Clone() const;

  template<int STATE>
  class GetOuterHTMLParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GetOuterHTMLParamsBuilder<STATE>& SetNodeId(int value) {
      result_->SetNodeId(value);
      return *this;
    }

    GetOuterHTMLParamsBuilder<STATE>& SetBackendNodeId(int value) {
      result_->SetBackendNodeId(value);
      return *this;
    }

    GetOuterHTMLParamsBuilder<STATE>& SetObjectId(const std::string& value) {
      result_->SetObjectId(value);
      return *this;
    }

    std::unique_ptr<GetOuterHTMLParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetOuterHTMLParams;
    GetOuterHTMLParamsBuilder() : result_(new GetOuterHTMLParams()) { }

    template<int STEP> GetOuterHTMLParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetOuterHTMLParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetOuterHTMLParams> result_;
  };

  static GetOuterHTMLParamsBuilder<0> Builder() {
    return GetOuterHTMLParamsBuilder<0>();
  }

 private:
  GetOuterHTMLParams() { }

  base::Optional<int> node_id_;
  base::Optional<int> backend_node_id_;
  base::Optional<std::string> object_id_;

  DISALLOW_COPY_AND_ASSIGN(GetOuterHTMLParams);
};


// Result for the GetOuterHTML command.
class HEADLESS_EXPORT GetOuterHTMLResult {
 public:
  static std::unique_ptr<GetOuterHTMLResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetOuterHTMLResult() { }

  // Outer HTML markup.
  std::string GetOuterHTML() const { return outerhtml_; }
  void SetOuterHTML(const std::string& value) { outerhtml_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetOuterHTMLResult> Clone() const;

  template<int STATE>
  class GetOuterHTMLResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOuterHTMLSet = 1 << 1,
      kAllRequiredFieldsSet = (kOuterHTMLSet | 0)
    };

    GetOuterHTMLResultBuilder<STATE | kOuterHTMLSet>& SetOuterHTML(const std::string& value) {
      static_assert(!(STATE & kOuterHTMLSet), "property outerHTML should not have already been set");
      result_->SetOuterHTML(value);
      return CastState<kOuterHTMLSet>();
    }

    std::unique_ptr<GetOuterHTMLResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetOuterHTMLResult;
    GetOuterHTMLResultBuilder() : result_(new GetOuterHTMLResult()) { }

    template<int STEP> GetOuterHTMLResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetOuterHTMLResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetOuterHTMLResult> result_;
  };

  static GetOuterHTMLResultBuilder<0> Builder() {
    return GetOuterHTMLResultBuilder<0>();
  }

 private:
  GetOuterHTMLResult() { }

  std::string outerhtml_;

  DISALLOW_COPY_AND_ASSIGN(GetOuterHTMLResult);
};


// Parameters for the GetRelayoutBoundary command.
class HEADLESS_EXPORT GetRelayoutBoundaryParams {
 public:
  static std::unique_ptr<GetRelayoutBoundaryParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetRelayoutBoundaryParams() { }

  // Id of the node.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetRelayoutBoundaryParams> Clone() const;

  template<int STATE>
  class GetRelayoutBoundaryParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    GetRelayoutBoundaryParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<GetRelayoutBoundaryParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetRelayoutBoundaryParams;
    GetRelayoutBoundaryParamsBuilder() : result_(new GetRelayoutBoundaryParams()) { }

    template<int STEP> GetRelayoutBoundaryParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetRelayoutBoundaryParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetRelayoutBoundaryParams> result_;
  };

  static GetRelayoutBoundaryParamsBuilder<0> Builder() {
    return GetRelayoutBoundaryParamsBuilder<0>();
  }

 private:
  GetRelayoutBoundaryParams() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(GetRelayoutBoundaryParams);
};


// Result for the GetRelayoutBoundary command.
class HEADLESS_EXPORT GetRelayoutBoundaryResult {
 public:
  static std::unique_ptr<GetRelayoutBoundaryResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetRelayoutBoundaryResult() { }

  // Relayout boundary node id for the given node.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetRelayoutBoundaryResult> Clone() const;

  template<int STATE>
  class GetRelayoutBoundaryResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    GetRelayoutBoundaryResultBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<GetRelayoutBoundaryResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetRelayoutBoundaryResult;
    GetRelayoutBoundaryResultBuilder() : result_(new GetRelayoutBoundaryResult()) { }

    template<int STEP> GetRelayoutBoundaryResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetRelayoutBoundaryResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetRelayoutBoundaryResult> result_;
  };

  static GetRelayoutBoundaryResultBuilder<0> Builder() {
    return GetRelayoutBoundaryResultBuilder<0>();
  }

 private:
  GetRelayoutBoundaryResult() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(GetRelayoutBoundaryResult);
};


// Parameters for the GetSearchResults command.
class HEADLESS_EXPORT GetSearchResultsParams {
 public:
  static std::unique_ptr<GetSearchResultsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetSearchResultsParams() { }

  // Unique search session identifier.
  std::string GetSearchId() const { return search_id_; }
  void SetSearchId(const std::string& value) { search_id_ = value; }

  // Start index of the search result to be returned.
  int GetFromIndex() const { return from_index_; }
  void SetFromIndex(int value) { from_index_ = value; }

  // End index of the search result to be returned.
  int GetToIndex() const { return to_index_; }
  void SetToIndex(int value) { to_index_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetSearchResultsParams> Clone() const;

  template<int STATE>
  class GetSearchResultsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSearchIdSet = 1 << 1,
    kFromIndexSet = 1 << 2,
    kToIndexSet = 1 << 3,
      kAllRequiredFieldsSet = (kSearchIdSet | kFromIndexSet | kToIndexSet | 0)
    };

    GetSearchResultsParamsBuilder<STATE | kSearchIdSet>& SetSearchId(const std::string& value) {
      static_assert(!(STATE & kSearchIdSet), "property searchId should not have already been set");
      result_->SetSearchId(value);
      return CastState<kSearchIdSet>();
    }

    GetSearchResultsParamsBuilder<STATE | kFromIndexSet>& SetFromIndex(int value) {
      static_assert(!(STATE & kFromIndexSet), "property fromIndex should not have already been set");
      result_->SetFromIndex(value);
      return CastState<kFromIndexSet>();
    }

    GetSearchResultsParamsBuilder<STATE | kToIndexSet>& SetToIndex(int value) {
      static_assert(!(STATE & kToIndexSet), "property toIndex should not have already been set");
      result_->SetToIndex(value);
      return CastState<kToIndexSet>();
    }

    std::unique_ptr<GetSearchResultsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetSearchResultsParams;
    GetSearchResultsParamsBuilder() : result_(new GetSearchResultsParams()) { }

    template<int STEP> GetSearchResultsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetSearchResultsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetSearchResultsParams> result_;
  };

  static GetSearchResultsParamsBuilder<0> Builder() {
    return GetSearchResultsParamsBuilder<0>();
  }

 private:
  GetSearchResultsParams() { }

  std::string search_id_;
  int from_index_;
  int to_index_;

  DISALLOW_COPY_AND_ASSIGN(GetSearchResultsParams);
};


// Result for the GetSearchResults command.
class HEADLESS_EXPORT GetSearchResultsResult {
 public:
  static std::unique_ptr<GetSearchResultsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetSearchResultsResult() { }

  // Ids of the search result nodes.
  const std::vector<int>* GetNodeIds() const { return &node_ids_; }
  void SetNodeIds(std::vector<int> value) { node_ids_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetSearchResultsResult> Clone() const;

  template<int STATE>
  class GetSearchResultsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdsSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdsSet | 0)
    };

    GetSearchResultsResultBuilder<STATE | kNodeIdsSet>& SetNodeIds(std::vector<int> value) {
      static_assert(!(STATE & kNodeIdsSet), "property nodeIds should not have already been set");
      result_->SetNodeIds(std::move(value));
      return CastState<kNodeIdsSet>();
    }

    std::unique_ptr<GetSearchResultsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetSearchResultsResult;
    GetSearchResultsResultBuilder() : result_(new GetSearchResultsResult()) { }

    template<int STEP> GetSearchResultsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetSearchResultsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetSearchResultsResult> result_;
  };

  static GetSearchResultsResultBuilder<0> Builder() {
    return GetSearchResultsResultBuilder<0>();
  }

 private:
  GetSearchResultsResult() { }

  std::vector<int> node_ids_;

  DISALLOW_COPY_AND_ASSIGN(GetSearchResultsResult);
};


// Parameters for the HideHighlight command.
class HEADLESS_EXPORT HideHighlightParams {
 public:
  static std::unique_ptr<HideHighlightParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~HideHighlightParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<HideHighlightParams> Clone() const;

  template<int STATE>
  class HideHighlightParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<HideHighlightParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class HideHighlightParams;
    HideHighlightParamsBuilder() : result_(new HideHighlightParams()) { }

    template<int STEP> HideHighlightParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<HideHighlightParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<HideHighlightParams> result_;
  };

  static HideHighlightParamsBuilder<0> Builder() {
    return HideHighlightParamsBuilder<0>();
  }

 private:
  HideHighlightParams() { }


  DISALLOW_COPY_AND_ASSIGN(HideHighlightParams);
};


// Result for the HideHighlight command.
class HEADLESS_EXPORT HideHighlightResult {
 public:
  static std::unique_ptr<HideHighlightResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~HideHighlightResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<HideHighlightResult> Clone() const;

  template<int STATE>
  class HideHighlightResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<HideHighlightResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class HideHighlightResult;
    HideHighlightResultBuilder() : result_(new HideHighlightResult()) { }

    template<int STEP> HideHighlightResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<HideHighlightResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<HideHighlightResult> result_;
  };

  static HideHighlightResultBuilder<0> Builder() {
    return HideHighlightResultBuilder<0>();
  }

 private:
  HideHighlightResult() { }


  DISALLOW_COPY_AND_ASSIGN(HideHighlightResult);
};


// Parameters for the HighlightNode command.
class HEADLESS_EXPORT HighlightNodeParams {
 public:
  static std::unique_ptr<HighlightNodeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~HighlightNodeParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<HighlightNodeParams> Clone() const;

  template<int STATE>
  class HighlightNodeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<HighlightNodeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class HighlightNodeParams;
    HighlightNodeParamsBuilder() : result_(new HighlightNodeParams()) { }

    template<int STEP> HighlightNodeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<HighlightNodeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<HighlightNodeParams> result_;
  };

  static HighlightNodeParamsBuilder<0> Builder() {
    return HighlightNodeParamsBuilder<0>();
  }

 private:
  HighlightNodeParams() { }


  DISALLOW_COPY_AND_ASSIGN(HighlightNodeParams);
};


// Result for the HighlightNode command.
class HEADLESS_EXPORT HighlightNodeResult {
 public:
  static std::unique_ptr<HighlightNodeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~HighlightNodeResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<HighlightNodeResult> Clone() const;

  template<int STATE>
  class HighlightNodeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<HighlightNodeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class HighlightNodeResult;
    HighlightNodeResultBuilder() : result_(new HighlightNodeResult()) { }

    template<int STEP> HighlightNodeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<HighlightNodeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<HighlightNodeResult> result_;
  };

  static HighlightNodeResultBuilder<0> Builder() {
    return HighlightNodeResultBuilder<0>();
  }

 private:
  HighlightNodeResult() { }


  DISALLOW_COPY_AND_ASSIGN(HighlightNodeResult);
};


// Parameters for the HighlightRect command.
class HEADLESS_EXPORT HighlightRectParams {
 public:
  static std::unique_ptr<HighlightRectParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~HighlightRectParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<HighlightRectParams> Clone() const;

  template<int STATE>
  class HighlightRectParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<HighlightRectParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class HighlightRectParams;
    HighlightRectParamsBuilder() : result_(new HighlightRectParams()) { }

    template<int STEP> HighlightRectParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<HighlightRectParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<HighlightRectParams> result_;
  };

  static HighlightRectParamsBuilder<0> Builder() {
    return HighlightRectParamsBuilder<0>();
  }

 private:
  HighlightRectParams() { }


  DISALLOW_COPY_AND_ASSIGN(HighlightRectParams);
};


// Result for the HighlightRect command.
class HEADLESS_EXPORT HighlightRectResult {
 public:
  static std::unique_ptr<HighlightRectResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~HighlightRectResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<HighlightRectResult> Clone() const;

  template<int STATE>
  class HighlightRectResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<HighlightRectResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class HighlightRectResult;
    HighlightRectResultBuilder() : result_(new HighlightRectResult()) { }

    template<int STEP> HighlightRectResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<HighlightRectResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<HighlightRectResult> result_;
  };

  static HighlightRectResultBuilder<0> Builder() {
    return HighlightRectResultBuilder<0>();
  }

 private:
  HighlightRectResult() { }


  DISALLOW_COPY_AND_ASSIGN(HighlightRectResult);
};


// Parameters for the MarkUndoableState command.
class HEADLESS_EXPORT MarkUndoableStateParams {
 public:
  static std::unique_ptr<MarkUndoableStateParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~MarkUndoableStateParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<MarkUndoableStateParams> Clone() const;

  template<int STATE>
  class MarkUndoableStateParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<MarkUndoableStateParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class MarkUndoableStateParams;
    MarkUndoableStateParamsBuilder() : result_(new MarkUndoableStateParams()) { }

    template<int STEP> MarkUndoableStateParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<MarkUndoableStateParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<MarkUndoableStateParams> result_;
  };

  static MarkUndoableStateParamsBuilder<0> Builder() {
    return MarkUndoableStateParamsBuilder<0>();
  }

 private:
  MarkUndoableStateParams() { }


  DISALLOW_COPY_AND_ASSIGN(MarkUndoableStateParams);
};


// Result for the MarkUndoableState command.
class HEADLESS_EXPORT MarkUndoableStateResult {
 public:
  static std::unique_ptr<MarkUndoableStateResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~MarkUndoableStateResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<MarkUndoableStateResult> Clone() const;

  template<int STATE>
  class MarkUndoableStateResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<MarkUndoableStateResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class MarkUndoableStateResult;
    MarkUndoableStateResultBuilder() : result_(new MarkUndoableStateResult()) { }

    template<int STEP> MarkUndoableStateResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<MarkUndoableStateResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<MarkUndoableStateResult> result_;
  };

  static MarkUndoableStateResultBuilder<0> Builder() {
    return MarkUndoableStateResultBuilder<0>();
  }

 private:
  MarkUndoableStateResult() { }


  DISALLOW_COPY_AND_ASSIGN(MarkUndoableStateResult);
};


// Parameters for the MoveTo command.
class HEADLESS_EXPORT MoveToParams {
 public:
  static std::unique_ptr<MoveToParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~MoveToParams() { }

  // Id of the node to move.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // Id of the element to drop the moved node into.
  int GetTargetNodeId() const { return target_node_id_; }
  void SetTargetNodeId(int value) { target_node_id_ = value; }

  // Drop node before this one (if absent, the moved node becomes the last child of
  // `targetNodeId`).
  bool HasInsertBeforeNodeId() const { return !!insert_before_node_id_; }
  int GetInsertBeforeNodeId() const { DCHECK(HasInsertBeforeNodeId()); return insert_before_node_id_.value(); }
  void SetInsertBeforeNodeId(int value) { insert_before_node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<MoveToParams> Clone() const;

  template<int STATE>
  class MoveToParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kTargetNodeIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kTargetNodeIdSet | 0)
    };

    MoveToParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    MoveToParamsBuilder<STATE | kTargetNodeIdSet>& SetTargetNodeId(int value) {
      static_assert(!(STATE & kTargetNodeIdSet), "property targetNodeId should not have already been set");
      result_->SetTargetNodeId(value);
      return CastState<kTargetNodeIdSet>();
    }

    MoveToParamsBuilder<STATE>& SetInsertBeforeNodeId(int value) {
      result_->SetInsertBeforeNodeId(value);
      return *this;
    }

    std::unique_ptr<MoveToParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class MoveToParams;
    MoveToParamsBuilder() : result_(new MoveToParams()) { }

    template<int STEP> MoveToParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<MoveToParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<MoveToParams> result_;
  };

  static MoveToParamsBuilder<0> Builder() {
    return MoveToParamsBuilder<0>();
  }

 private:
  MoveToParams() { }

  int node_id_;
  int target_node_id_;
  base::Optional<int> insert_before_node_id_;

  DISALLOW_COPY_AND_ASSIGN(MoveToParams);
};


// Result for the MoveTo command.
class HEADLESS_EXPORT MoveToResult {
 public:
  static std::unique_ptr<MoveToResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~MoveToResult() { }

  // New id of the moved node.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<MoveToResult> Clone() const;

  template<int STATE>
  class MoveToResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    MoveToResultBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<MoveToResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class MoveToResult;
    MoveToResultBuilder() : result_(new MoveToResult()) { }

    template<int STEP> MoveToResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<MoveToResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<MoveToResult> result_;
  };

  static MoveToResultBuilder<0> Builder() {
    return MoveToResultBuilder<0>();
  }

 private:
  MoveToResult() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(MoveToResult);
};


// Parameters for the PerformSearch command.
class HEADLESS_EXPORT PerformSearchParams {
 public:
  static std::unique_ptr<PerformSearchParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PerformSearchParams() { }

  // Plain text or query selector or XPath search query.
  std::string GetQuery() const { return query_; }
  void SetQuery(const std::string& value) { query_ = value; }

  // True to search in user agent shadow DOM.
  bool HasIncludeUserAgentShadowDOM() const { return !!include_user_agent_shadowdom_; }
  bool GetIncludeUserAgentShadowDOM() const { DCHECK(HasIncludeUserAgentShadowDOM()); return include_user_agent_shadowdom_.value(); }
  void SetIncludeUserAgentShadowDOM(bool value) { include_user_agent_shadowdom_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PerformSearchParams> Clone() const;

  template<int STATE>
  class PerformSearchParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kQuerySet = 1 << 1,
      kAllRequiredFieldsSet = (kQuerySet | 0)
    };

    PerformSearchParamsBuilder<STATE | kQuerySet>& SetQuery(const std::string& value) {
      static_assert(!(STATE & kQuerySet), "property query should not have already been set");
      result_->SetQuery(value);
      return CastState<kQuerySet>();
    }

    PerformSearchParamsBuilder<STATE>& SetIncludeUserAgentShadowDOM(bool value) {
      result_->SetIncludeUserAgentShadowDOM(value);
      return *this;
    }

    std::unique_ptr<PerformSearchParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PerformSearchParams;
    PerformSearchParamsBuilder() : result_(new PerformSearchParams()) { }

    template<int STEP> PerformSearchParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PerformSearchParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PerformSearchParams> result_;
  };

  static PerformSearchParamsBuilder<0> Builder() {
    return PerformSearchParamsBuilder<0>();
  }

 private:
  PerformSearchParams() { }

  std::string query_;
  base::Optional<bool> include_user_agent_shadowdom_;

  DISALLOW_COPY_AND_ASSIGN(PerformSearchParams);
};


// Result for the PerformSearch command.
class HEADLESS_EXPORT PerformSearchResult {
 public:
  static std::unique_ptr<PerformSearchResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~PerformSearchResult() { }

  // Unique search session identifier.
  std::string GetSearchId() const { return search_id_; }
  void SetSearchId(const std::string& value) { search_id_ = value; }

  // Number of search results.
  int GetResultCount() const { return result_count_; }
  void SetResultCount(int value) { result_count_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PerformSearchResult> Clone() const;

  template<int STATE>
  class PerformSearchResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSearchIdSet = 1 << 1,
    kResultCountSet = 1 << 2,
      kAllRequiredFieldsSet = (kSearchIdSet | kResultCountSet | 0)
    };

    PerformSearchResultBuilder<STATE | kSearchIdSet>& SetSearchId(const std::string& value) {
      static_assert(!(STATE & kSearchIdSet), "property searchId should not have already been set");
      result_->SetSearchId(value);
      return CastState<kSearchIdSet>();
    }

    PerformSearchResultBuilder<STATE | kResultCountSet>& SetResultCount(int value) {
      static_assert(!(STATE & kResultCountSet), "property resultCount should not have already been set");
      result_->SetResultCount(value);
      return CastState<kResultCountSet>();
    }

    std::unique_ptr<PerformSearchResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PerformSearchResult;
    PerformSearchResultBuilder() : result_(new PerformSearchResult()) { }

    template<int STEP> PerformSearchResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PerformSearchResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PerformSearchResult> result_;
  };

  static PerformSearchResultBuilder<0> Builder() {
    return PerformSearchResultBuilder<0>();
  }

 private:
  PerformSearchResult() { }

  std::string search_id_;
  int result_count_;

  DISALLOW_COPY_AND_ASSIGN(PerformSearchResult);
};


// Parameters for the PushNodeByPathToFrontend command.
class HEADLESS_EXPORT PushNodeByPathToFrontendParams {
 public:
  static std::unique_ptr<PushNodeByPathToFrontendParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PushNodeByPathToFrontendParams() { }

  // Path to node in the proprietary format.
  std::string GetPath() const { return path_; }
  void SetPath(const std::string& value) { path_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PushNodeByPathToFrontendParams> Clone() const;

  template<int STATE>
  class PushNodeByPathToFrontendParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPathSet = 1 << 1,
      kAllRequiredFieldsSet = (kPathSet | 0)
    };

    PushNodeByPathToFrontendParamsBuilder<STATE | kPathSet>& SetPath(const std::string& value) {
      static_assert(!(STATE & kPathSet), "property path should not have already been set");
      result_->SetPath(value);
      return CastState<kPathSet>();
    }

    std::unique_ptr<PushNodeByPathToFrontendParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PushNodeByPathToFrontendParams;
    PushNodeByPathToFrontendParamsBuilder() : result_(new PushNodeByPathToFrontendParams()) { }

    template<int STEP> PushNodeByPathToFrontendParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PushNodeByPathToFrontendParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PushNodeByPathToFrontendParams> result_;
  };

  static PushNodeByPathToFrontendParamsBuilder<0> Builder() {
    return PushNodeByPathToFrontendParamsBuilder<0>();
  }

 private:
  PushNodeByPathToFrontendParams() { }

  std::string path_;

  DISALLOW_COPY_AND_ASSIGN(PushNodeByPathToFrontendParams);
};


// Result for the PushNodeByPathToFrontend command.
class HEADLESS_EXPORT PushNodeByPathToFrontendResult {
 public:
  static std::unique_ptr<PushNodeByPathToFrontendResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~PushNodeByPathToFrontendResult() { }

  // Id of the node for given path.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PushNodeByPathToFrontendResult> Clone() const;

  template<int STATE>
  class PushNodeByPathToFrontendResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    PushNodeByPathToFrontendResultBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<PushNodeByPathToFrontendResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PushNodeByPathToFrontendResult;
    PushNodeByPathToFrontendResultBuilder() : result_(new PushNodeByPathToFrontendResult()) { }

    template<int STEP> PushNodeByPathToFrontendResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PushNodeByPathToFrontendResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PushNodeByPathToFrontendResult> result_;
  };

  static PushNodeByPathToFrontendResultBuilder<0> Builder() {
    return PushNodeByPathToFrontendResultBuilder<0>();
  }

 private:
  PushNodeByPathToFrontendResult() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(PushNodeByPathToFrontendResult);
};


// Parameters for the PushNodesByBackendIdsToFrontend command.
class HEADLESS_EXPORT PushNodesByBackendIdsToFrontendParams {
 public:
  static std::unique_ptr<PushNodesByBackendIdsToFrontendParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PushNodesByBackendIdsToFrontendParams() { }

  // The array of backend node ids.
  const std::vector<int>* GetBackendNodeIds() const { return &backend_node_ids_; }
  void SetBackendNodeIds(std::vector<int> value) { backend_node_ids_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PushNodesByBackendIdsToFrontendParams> Clone() const;

  template<int STATE>
  class PushNodesByBackendIdsToFrontendParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBackendNodeIdsSet = 1 << 1,
      kAllRequiredFieldsSet = (kBackendNodeIdsSet | 0)
    };

    PushNodesByBackendIdsToFrontendParamsBuilder<STATE | kBackendNodeIdsSet>& SetBackendNodeIds(std::vector<int> value) {
      static_assert(!(STATE & kBackendNodeIdsSet), "property backendNodeIds should not have already been set");
      result_->SetBackendNodeIds(std::move(value));
      return CastState<kBackendNodeIdsSet>();
    }

    std::unique_ptr<PushNodesByBackendIdsToFrontendParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PushNodesByBackendIdsToFrontendParams;
    PushNodesByBackendIdsToFrontendParamsBuilder() : result_(new PushNodesByBackendIdsToFrontendParams()) { }

    template<int STEP> PushNodesByBackendIdsToFrontendParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PushNodesByBackendIdsToFrontendParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PushNodesByBackendIdsToFrontendParams> result_;
  };

  static PushNodesByBackendIdsToFrontendParamsBuilder<0> Builder() {
    return PushNodesByBackendIdsToFrontendParamsBuilder<0>();
  }

 private:
  PushNodesByBackendIdsToFrontendParams() { }

  std::vector<int> backend_node_ids_;

  DISALLOW_COPY_AND_ASSIGN(PushNodesByBackendIdsToFrontendParams);
};


// Result for the PushNodesByBackendIdsToFrontend command.
class HEADLESS_EXPORT PushNodesByBackendIdsToFrontendResult {
 public:
  static std::unique_ptr<PushNodesByBackendIdsToFrontendResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~PushNodesByBackendIdsToFrontendResult() { }

  // The array of ids of pushed nodes that correspond to the backend ids specified in
  // backendNodeIds.
  const std::vector<int>* GetNodeIds() const { return &node_ids_; }
  void SetNodeIds(std::vector<int> value) { node_ids_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PushNodesByBackendIdsToFrontendResult> Clone() const;

  template<int STATE>
  class PushNodesByBackendIdsToFrontendResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdsSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdsSet | 0)
    };

    PushNodesByBackendIdsToFrontendResultBuilder<STATE | kNodeIdsSet>& SetNodeIds(std::vector<int> value) {
      static_assert(!(STATE & kNodeIdsSet), "property nodeIds should not have already been set");
      result_->SetNodeIds(std::move(value));
      return CastState<kNodeIdsSet>();
    }

    std::unique_ptr<PushNodesByBackendIdsToFrontendResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PushNodesByBackendIdsToFrontendResult;
    PushNodesByBackendIdsToFrontendResultBuilder() : result_(new PushNodesByBackendIdsToFrontendResult()) { }

    template<int STEP> PushNodesByBackendIdsToFrontendResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PushNodesByBackendIdsToFrontendResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PushNodesByBackendIdsToFrontendResult> result_;
  };

  static PushNodesByBackendIdsToFrontendResultBuilder<0> Builder() {
    return PushNodesByBackendIdsToFrontendResultBuilder<0>();
  }

 private:
  PushNodesByBackendIdsToFrontendResult() { }

  std::vector<int> node_ids_;

  DISALLOW_COPY_AND_ASSIGN(PushNodesByBackendIdsToFrontendResult);
};


// Parameters for the QuerySelector command.
class HEADLESS_EXPORT QuerySelectorParams {
 public:
  static std::unique_ptr<QuerySelectorParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~QuerySelectorParams() { }

  // Id of the node to query upon.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // Selector string.
  std::string GetSelector() const { return selector_; }
  void SetSelector(const std::string& value) { selector_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<QuerySelectorParams> Clone() const;

  template<int STATE>
  class QuerySelectorParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kSelectorSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kSelectorSet | 0)
    };

    QuerySelectorParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    QuerySelectorParamsBuilder<STATE | kSelectorSet>& SetSelector(const std::string& value) {
      static_assert(!(STATE & kSelectorSet), "property selector should not have already been set");
      result_->SetSelector(value);
      return CastState<kSelectorSet>();
    }

    std::unique_ptr<QuerySelectorParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class QuerySelectorParams;
    QuerySelectorParamsBuilder() : result_(new QuerySelectorParams()) { }

    template<int STEP> QuerySelectorParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<QuerySelectorParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<QuerySelectorParams> result_;
  };

  static QuerySelectorParamsBuilder<0> Builder() {
    return QuerySelectorParamsBuilder<0>();
  }

 private:
  QuerySelectorParams() { }

  int node_id_;
  std::string selector_;

  DISALLOW_COPY_AND_ASSIGN(QuerySelectorParams);
};


// Result for the QuerySelector command.
class HEADLESS_EXPORT QuerySelectorResult {
 public:
  static std::unique_ptr<QuerySelectorResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~QuerySelectorResult() { }

  // Query selector result.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<QuerySelectorResult> Clone() const;

  template<int STATE>
  class QuerySelectorResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    QuerySelectorResultBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<QuerySelectorResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class QuerySelectorResult;
    QuerySelectorResultBuilder() : result_(new QuerySelectorResult()) { }

    template<int STEP> QuerySelectorResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<QuerySelectorResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<QuerySelectorResult> result_;
  };

  static QuerySelectorResultBuilder<0> Builder() {
    return QuerySelectorResultBuilder<0>();
  }

 private:
  QuerySelectorResult() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(QuerySelectorResult);
};


// Parameters for the QuerySelectorAll command.
class HEADLESS_EXPORT QuerySelectorAllParams {
 public:
  static std::unique_ptr<QuerySelectorAllParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~QuerySelectorAllParams() { }

  // Id of the node to query upon.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // Selector string.
  std::string GetSelector() const { return selector_; }
  void SetSelector(const std::string& value) { selector_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<QuerySelectorAllParams> Clone() const;

  template<int STATE>
  class QuerySelectorAllParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kSelectorSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kSelectorSet | 0)
    };

    QuerySelectorAllParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    QuerySelectorAllParamsBuilder<STATE | kSelectorSet>& SetSelector(const std::string& value) {
      static_assert(!(STATE & kSelectorSet), "property selector should not have already been set");
      result_->SetSelector(value);
      return CastState<kSelectorSet>();
    }

    std::unique_ptr<QuerySelectorAllParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class QuerySelectorAllParams;
    QuerySelectorAllParamsBuilder() : result_(new QuerySelectorAllParams()) { }

    template<int STEP> QuerySelectorAllParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<QuerySelectorAllParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<QuerySelectorAllParams> result_;
  };

  static QuerySelectorAllParamsBuilder<0> Builder() {
    return QuerySelectorAllParamsBuilder<0>();
  }

 private:
  QuerySelectorAllParams() { }

  int node_id_;
  std::string selector_;

  DISALLOW_COPY_AND_ASSIGN(QuerySelectorAllParams);
};


// Result for the QuerySelectorAll command.
class HEADLESS_EXPORT QuerySelectorAllResult {
 public:
  static std::unique_ptr<QuerySelectorAllResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~QuerySelectorAllResult() { }

  // Query selector result.
  const std::vector<int>* GetNodeIds() const { return &node_ids_; }
  void SetNodeIds(std::vector<int> value) { node_ids_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<QuerySelectorAllResult> Clone() const;

  template<int STATE>
  class QuerySelectorAllResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdsSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdsSet | 0)
    };

    QuerySelectorAllResultBuilder<STATE | kNodeIdsSet>& SetNodeIds(std::vector<int> value) {
      static_assert(!(STATE & kNodeIdsSet), "property nodeIds should not have already been set");
      result_->SetNodeIds(std::move(value));
      return CastState<kNodeIdsSet>();
    }

    std::unique_ptr<QuerySelectorAllResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class QuerySelectorAllResult;
    QuerySelectorAllResultBuilder() : result_(new QuerySelectorAllResult()) { }

    template<int STEP> QuerySelectorAllResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<QuerySelectorAllResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<QuerySelectorAllResult> result_;
  };

  static QuerySelectorAllResultBuilder<0> Builder() {
    return QuerySelectorAllResultBuilder<0>();
  }

 private:
  QuerySelectorAllResult() { }

  std::vector<int> node_ids_;

  DISALLOW_COPY_AND_ASSIGN(QuerySelectorAllResult);
};


// Parameters for the Redo command.
class HEADLESS_EXPORT RedoParams {
 public:
  static std::unique_ptr<RedoParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RedoParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RedoParams> Clone() const;

  template<int STATE>
  class RedoParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RedoParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RedoParams;
    RedoParamsBuilder() : result_(new RedoParams()) { }

    template<int STEP> RedoParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RedoParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RedoParams> result_;
  };

  static RedoParamsBuilder<0> Builder() {
    return RedoParamsBuilder<0>();
  }

 private:
  RedoParams() { }


  DISALLOW_COPY_AND_ASSIGN(RedoParams);
};


// Result for the Redo command.
class HEADLESS_EXPORT RedoResult {
 public:
  static std::unique_ptr<RedoResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RedoResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RedoResult> Clone() const;

  template<int STATE>
  class RedoResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RedoResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RedoResult;
    RedoResultBuilder() : result_(new RedoResult()) { }

    template<int STEP> RedoResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RedoResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RedoResult> result_;
  };

  static RedoResultBuilder<0> Builder() {
    return RedoResultBuilder<0>();
  }

 private:
  RedoResult() { }


  DISALLOW_COPY_AND_ASSIGN(RedoResult);
};


// Parameters for the RemoveAttribute command.
class HEADLESS_EXPORT RemoveAttributeParams {
 public:
  static std::unique_ptr<RemoveAttributeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveAttributeParams() { }

  // Id of the element to remove attribute from.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // Name of the attribute to remove.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveAttributeParams> Clone() const;

  template<int STATE>
  class RemoveAttributeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kNameSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kNameSet | 0)
    };

    RemoveAttributeParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    RemoveAttributeParamsBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    std::unique_ptr<RemoveAttributeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveAttributeParams;
    RemoveAttributeParamsBuilder() : result_(new RemoveAttributeParams()) { }

    template<int STEP> RemoveAttributeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveAttributeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveAttributeParams> result_;
  };

  static RemoveAttributeParamsBuilder<0> Builder() {
    return RemoveAttributeParamsBuilder<0>();
  }

 private:
  RemoveAttributeParams() { }

  int node_id_;
  std::string name_;

  DISALLOW_COPY_AND_ASSIGN(RemoveAttributeParams);
};


// Result for the RemoveAttribute command.
class HEADLESS_EXPORT RemoveAttributeResult {
 public:
  static std::unique_ptr<RemoveAttributeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveAttributeResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveAttributeResult> Clone() const;

  template<int STATE>
  class RemoveAttributeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RemoveAttributeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveAttributeResult;
    RemoveAttributeResultBuilder() : result_(new RemoveAttributeResult()) { }

    template<int STEP> RemoveAttributeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveAttributeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveAttributeResult> result_;
  };

  static RemoveAttributeResultBuilder<0> Builder() {
    return RemoveAttributeResultBuilder<0>();
  }

 private:
  RemoveAttributeResult() { }


  DISALLOW_COPY_AND_ASSIGN(RemoveAttributeResult);
};


// Parameters for the RemoveNode command.
class HEADLESS_EXPORT RemoveNodeParams {
 public:
  static std::unique_ptr<RemoveNodeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveNodeParams() { }

  // Id of the node to remove.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveNodeParams> Clone() const;

  template<int STATE>
  class RemoveNodeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    RemoveNodeParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<RemoveNodeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveNodeParams;
    RemoveNodeParamsBuilder() : result_(new RemoveNodeParams()) { }

    template<int STEP> RemoveNodeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveNodeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveNodeParams> result_;
  };

  static RemoveNodeParamsBuilder<0> Builder() {
    return RemoveNodeParamsBuilder<0>();
  }

 private:
  RemoveNodeParams() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(RemoveNodeParams);
};


// Result for the RemoveNode command.
class HEADLESS_EXPORT RemoveNodeResult {
 public:
  static std::unique_ptr<RemoveNodeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveNodeResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveNodeResult> Clone() const;

  template<int STATE>
  class RemoveNodeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RemoveNodeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveNodeResult;
    RemoveNodeResultBuilder() : result_(new RemoveNodeResult()) { }

    template<int STEP> RemoveNodeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveNodeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveNodeResult> result_;
  };

  static RemoveNodeResultBuilder<0> Builder() {
    return RemoveNodeResultBuilder<0>();
  }

 private:
  RemoveNodeResult() { }


  DISALLOW_COPY_AND_ASSIGN(RemoveNodeResult);
};


// Parameters for the RequestChildNodes command.
class HEADLESS_EXPORT RequestChildNodesParams {
 public:
  static std::unique_ptr<RequestChildNodesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestChildNodesParams() { }

  // Id of the node to get children for.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
  // entire subtree or provide an integer larger than 0.
  bool HasDepth() const { return !!depth_; }
  int GetDepth() const { DCHECK(HasDepth()); return depth_.value(); }
  void SetDepth(int value) { depth_ = value; }

  // Whether or not iframes and shadow roots should be traversed when returning the sub-tree
  // (default is false).
  bool HasPierce() const { return !!pierce_; }
  bool GetPierce() const { DCHECK(HasPierce()); return pierce_.value(); }
  void SetPierce(bool value) { pierce_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestChildNodesParams> Clone() const;

  template<int STATE>
  class RequestChildNodesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    RequestChildNodesParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    RequestChildNodesParamsBuilder<STATE>& SetDepth(int value) {
      result_->SetDepth(value);
      return *this;
    }

    RequestChildNodesParamsBuilder<STATE>& SetPierce(bool value) {
      result_->SetPierce(value);
      return *this;
    }

    std::unique_ptr<RequestChildNodesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestChildNodesParams;
    RequestChildNodesParamsBuilder() : result_(new RequestChildNodesParams()) { }

    template<int STEP> RequestChildNodesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestChildNodesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestChildNodesParams> result_;
  };

  static RequestChildNodesParamsBuilder<0> Builder() {
    return RequestChildNodesParamsBuilder<0>();
  }

 private:
  RequestChildNodesParams() { }

  int node_id_;
  base::Optional<int> depth_;
  base::Optional<bool> pierce_;

  DISALLOW_COPY_AND_ASSIGN(RequestChildNodesParams);
};


// Result for the RequestChildNodes command.
class HEADLESS_EXPORT RequestChildNodesResult {
 public:
  static std::unique_ptr<RequestChildNodesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestChildNodesResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestChildNodesResult> Clone() const;

  template<int STATE>
  class RequestChildNodesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RequestChildNodesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestChildNodesResult;
    RequestChildNodesResultBuilder() : result_(new RequestChildNodesResult()) { }

    template<int STEP> RequestChildNodesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestChildNodesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestChildNodesResult> result_;
  };

  static RequestChildNodesResultBuilder<0> Builder() {
    return RequestChildNodesResultBuilder<0>();
  }

 private:
  RequestChildNodesResult() { }


  DISALLOW_COPY_AND_ASSIGN(RequestChildNodesResult);
};


// Parameters for the RequestNode command.
class HEADLESS_EXPORT RequestNodeParams {
 public:
  static std::unique_ptr<RequestNodeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestNodeParams() { }

  // JavaScript object id to convert into node.
  std::string GetObjectId() const { return object_id_; }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestNodeParams> Clone() const;

  template<int STATE>
  class RequestNodeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kObjectIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kObjectIdSet | 0)
    };

    RequestNodeParamsBuilder<STATE | kObjectIdSet>& SetObjectId(const std::string& value) {
      static_assert(!(STATE & kObjectIdSet), "property objectId should not have already been set");
      result_->SetObjectId(value);
      return CastState<kObjectIdSet>();
    }

    std::unique_ptr<RequestNodeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestNodeParams;
    RequestNodeParamsBuilder() : result_(new RequestNodeParams()) { }

    template<int STEP> RequestNodeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestNodeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestNodeParams> result_;
  };

  static RequestNodeParamsBuilder<0> Builder() {
    return RequestNodeParamsBuilder<0>();
  }

 private:
  RequestNodeParams() { }

  std::string object_id_;

  DISALLOW_COPY_AND_ASSIGN(RequestNodeParams);
};


// Result for the RequestNode command.
class HEADLESS_EXPORT RequestNodeResult {
 public:
  static std::unique_ptr<RequestNodeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestNodeResult() { }

  // Node id for given object.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestNodeResult> Clone() const;

  template<int STATE>
  class RequestNodeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    RequestNodeResultBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<RequestNodeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestNodeResult;
    RequestNodeResultBuilder() : result_(new RequestNodeResult()) { }

    template<int STEP> RequestNodeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestNodeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestNodeResult> result_;
  };

  static RequestNodeResultBuilder<0> Builder() {
    return RequestNodeResultBuilder<0>();
  }

 private:
  RequestNodeResult() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(RequestNodeResult);
};


// Parameters for the ResolveNode command.
class HEADLESS_EXPORT ResolveNodeParams {
 public:
  static std::unique_ptr<ResolveNodeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResolveNodeParams() { }

  // Id of the node to resolve.
  bool HasNodeId() const { return !!node_id_; }
  int GetNodeId() const { DCHECK(HasNodeId()); return node_id_.value(); }
  void SetNodeId(int value) { node_id_ = value; }

  // Backend identifier of the node to resolve.
  bool HasBackendNodeId() const { return !!backend_node_id_; }
  int GetBackendNodeId() const { DCHECK(HasBackendNodeId()); return backend_node_id_.value(); }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // Symbolic group name that can be used to release multiple objects.
  bool HasObjectGroup() const { return !!object_group_; }
  std::string GetObjectGroup() const { DCHECK(HasObjectGroup()); return object_group_.value(); }
  void SetObjectGroup(const std::string& value) { object_group_ = value; }

  // Execution context in which to resolve the node.
  bool HasExecutionContextId() const { return !!execution_context_id_; }
  int GetExecutionContextId() const { DCHECK(HasExecutionContextId()); return execution_context_id_.value(); }
  void SetExecutionContextId(int value) { execution_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResolveNodeParams> Clone() const;

  template<int STATE>
  class ResolveNodeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    ResolveNodeParamsBuilder<STATE>& SetNodeId(int value) {
      result_->SetNodeId(value);
      return *this;
    }

    ResolveNodeParamsBuilder<STATE>& SetBackendNodeId(int value) {
      result_->SetBackendNodeId(value);
      return *this;
    }

    ResolveNodeParamsBuilder<STATE>& SetObjectGroup(const std::string& value) {
      result_->SetObjectGroup(value);
      return *this;
    }

    ResolveNodeParamsBuilder<STATE>& SetExecutionContextId(int value) {
      result_->SetExecutionContextId(value);
      return *this;
    }

    std::unique_ptr<ResolveNodeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResolveNodeParams;
    ResolveNodeParamsBuilder() : result_(new ResolveNodeParams()) { }

    template<int STEP> ResolveNodeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResolveNodeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResolveNodeParams> result_;
  };

  static ResolveNodeParamsBuilder<0> Builder() {
    return ResolveNodeParamsBuilder<0>();
  }

 private:
  ResolveNodeParams() { }

  base::Optional<int> node_id_;
  base::Optional<int> backend_node_id_;
  base::Optional<std::string> object_group_;
  base::Optional<int> execution_context_id_;

  DISALLOW_COPY_AND_ASSIGN(ResolveNodeParams);
};


// Result for the ResolveNode command.
class HEADLESS_EXPORT ResolveNodeResult {
 public:
  static std::unique_ptr<ResolveNodeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResolveNodeResult() { }

  // JavaScript object wrapper for given node.
  const ::headless::runtime::RemoteObject* GetObject() const { return object_.get(); }
  void SetObject(std::unique_ptr<::headless::runtime::RemoteObject> value) { object_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResolveNodeResult> Clone() const;

  template<int STATE>
  class ResolveNodeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kObjectSet = 1 << 1,
      kAllRequiredFieldsSet = (kObjectSet | 0)
    };

    ResolveNodeResultBuilder<STATE | kObjectSet>& SetObject(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      static_assert(!(STATE & kObjectSet), "property object should not have already been set");
      result_->SetObject(std::move(value));
      return CastState<kObjectSet>();
    }

    std::unique_ptr<ResolveNodeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResolveNodeResult;
    ResolveNodeResultBuilder() : result_(new ResolveNodeResult()) { }

    template<int STEP> ResolveNodeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResolveNodeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResolveNodeResult> result_;
  };

  static ResolveNodeResultBuilder<0> Builder() {
    return ResolveNodeResultBuilder<0>();
  }

 private:
  ResolveNodeResult() { }

  std::unique_ptr<::headless::runtime::RemoteObject> object_;

  DISALLOW_COPY_AND_ASSIGN(ResolveNodeResult);
};


// Parameters for the SetAttributeValue command.
class HEADLESS_EXPORT SetAttributeValueParams {
 public:
  static std::unique_ptr<SetAttributeValueParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetAttributeValueParams() { }

  // Id of the element to set attribute for.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // Attribute name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Attribute value.
  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetAttributeValueParams> Clone() const;

  template<int STATE>
  class SetAttributeValueParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kNameSet = 1 << 2,
    kValueSet = 1 << 3,
      kAllRequiredFieldsSet = (kNodeIdSet | kNameSet | kValueSet | 0)
    };

    SetAttributeValueParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    SetAttributeValueParamsBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    SetAttributeValueParamsBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<SetAttributeValueParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetAttributeValueParams;
    SetAttributeValueParamsBuilder() : result_(new SetAttributeValueParams()) { }

    template<int STEP> SetAttributeValueParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetAttributeValueParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetAttributeValueParams> result_;
  };

  static SetAttributeValueParamsBuilder<0> Builder() {
    return SetAttributeValueParamsBuilder<0>();
  }

 private:
  SetAttributeValueParams() { }

  int node_id_;
  std::string name_;
  std::string value_;

  DISALLOW_COPY_AND_ASSIGN(SetAttributeValueParams);
};


// Result for the SetAttributeValue command.
class HEADLESS_EXPORT SetAttributeValueResult {
 public:
  static std::unique_ptr<SetAttributeValueResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetAttributeValueResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetAttributeValueResult> Clone() const;

  template<int STATE>
  class SetAttributeValueResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetAttributeValueResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetAttributeValueResult;
    SetAttributeValueResultBuilder() : result_(new SetAttributeValueResult()) { }

    template<int STEP> SetAttributeValueResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetAttributeValueResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetAttributeValueResult> result_;
  };

  static SetAttributeValueResultBuilder<0> Builder() {
    return SetAttributeValueResultBuilder<0>();
  }

 private:
  SetAttributeValueResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetAttributeValueResult);
};


// Parameters for the SetAttributesAsText command.
class HEADLESS_EXPORT SetAttributesAsTextParams {
 public:
  static std::unique_ptr<SetAttributesAsTextParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetAttributesAsTextParams() { }

  // Id of the element to set attributes for.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // Text with a number of attributes. Will parse this text using HTML parser.
  std::string GetText() const { return text_; }
  void SetText(const std::string& value) { text_ = value; }

  // Attribute name to replace with new attributes derived from text in case text parsed
  // successfully.
  bool HasName() const { return !!name_; }
  std::string GetName() const { DCHECK(HasName()); return name_.value(); }
  void SetName(const std::string& value) { name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetAttributesAsTextParams> Clone() const;

  template<int STATE>
  class SetAttributesAsTextParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kTextSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kTextSet | 0)
    };

    SetAttributesAsTextParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    SetAttributesAsTextParamsBuilder<STATE | kTextSet>& SetText(const std::string& value) {
      static_assert(!(STATE & kTextSet), "property text should not have already been set");
      result_->SetText(value);
      return CastState<kTextSet>();
    }

    SetAttributesAsTextParamsBuilder<STATE>& SetName(const std::string& value) {
      result_->SetName(value);
      return *this;
    }

    std::unique_ptr<SetAttributesAsTextParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetAttributesAsTextParams;
    SetAttributesAsTextParamsBuilder() : result_(new SetAttributesAsTextParams()) { }

    template<int STEP> SetAttributesAsTextParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetAttributesAsTextParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetAttributesAsTextParams> result_;
  };

  static SetAttributesAsTextParamsBuilder<0> Builder() {
    return SetAttributesAsTextParamsBuilder<0>();
  }

 private:
  SetAttributesAsTextParams() { }

  int node_id_;
  std::string text_;
  base::Optional<std::string> name_;

  DISALLOW_COPY_AND_ASSIGN(SetAttributesAsTextParams);
};


// Result for the SetAttributesAsText command.
class HEADLESS_EXPORT SetAttributesAsTextResult {
 public:
  static std::unique_ptr<SetAttributesAsTextResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetAttributesAsTextResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetAttributesAsTextResult> Clone() const;

  template<int STATE>
  class SetAttributesAsTextResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetAttributesAsTextResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetAttributesAsTextResult;
    SetAttributesAsTextResultBuilder() : result_(new SetAttributesAsTextResult()) { }

    template<int STEP> SetAttributesAsTextResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetAttributesAsTextResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetAttributesAsTextResult> result_;
  };

  static SetAttributesAsTextResultBuilder<0> Builder() {
    return SetAttributesAsTextResultBuilder<0>();
  }

 private:
  SetAttributesAsTextResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetAttributesAsTextResult);
};


// Parameters for the SetFileInputFiles command.
class HEADLESS_EXPORT SetFileInputFilesParams {
 public:
  static std::unique_ptr<SetFileInputFilesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetFileInputFilesParams() { }

  // Array of file paths to set.
  const std::vector<std::string>* GetFiles() const { return &files_; }
  void SetFiles(std::vector<std::string> value) { files_ = std::move(value); }

  // Identifier of the node.
  bool HasNodeId() const { return !!node_id_; }
  int GetNodeId() const { DCHECK(HasNodeId()); return node_id_.value(); }
  void SetNodeId(int value) { node_id_ = value; }

  // Identifier of the backend node.
  bool HasBackendNodeId() const { return !!backend_node_id_; }
  int GetBackendNodeId() const { DCHECK(HasBackendNodeId()); return backend_node_id_.value(); }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // JavaScript object id of the node wrapper.
  bool HasObjectId() const { return !!object_id_; }
  std::string GetObjectId() const { DCHECK(HasObjectId()); return object_id_.value(); }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetFileInputFilesParams> Clone() const;

  template<int STATE>
  class SetFileInputFilesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFilesSet = 1 << 1,
      kAllRequiredFieldsSet = (kFilesSet | 0)
    };

    SetFileInputFilesParamsBuilder<STATE | kFilesSet>& SetFiles(std::vector<std::string> value) {
      static_assert(!(STATE & kFilesSet), "property files should not have already been set");
      result_->SetFiles(std::move(value));
      return CastState<kFilesSet>();
    }

    SetFileInputFilesParamsBuilder<STATE>& SetNodeId(int value) {
      result_->SetNodeId(value);
      return *this;
    }

    SetFileInputFilesParamsBuilder<STATE>& SetBackendNodeId(int value) {
      result_->SetBackendNodeId(value);
      return *this;
    }

    SetFileInputFilesParamsBuilder<STATE>& SetObjectId(const std::string& value) {
      result_->SetObjectId(value);
      return *this;
    }

    std::unique_ptr<SetFileInputFilesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetFileInputFilesParams;
    SetFileInputFilesParamsBuilder() : result_(new SetFileInputFilesParams()) { }

    template<int STEP> SetFileInputFilesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetFileInputFilesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetFileInputFilesParams> result_;
  };

  static SetFileInputFilesParamsBuilder<0> Builder() {
    return SetFileInputFilesParamsBuilder<0>();
  }

 private:
  SetFileInputFilesParams() { }

  std::vector<std::string> files_;
  base::Optional<int> node_id_;
  base::Optional<int> backend_node_id_;
  base::Optional<std::string> object_id_;

  DISALLOW_COPY_AND_ASSIGN(SetFileInputFilesParams);
};


// Result for the SetFileInputFiles command.
class HEADLESS_EXPORT SetFileInputFilesResult {
 public:
  static std::unique_ptr<SetFileInputFilesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetFileInputFilesResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetFileInputFilesResult> Clone() const;

  template<int STATE>
  class SetFileInputFilesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetFileInputFilesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetFileInputFilesResult;
    SetFileInputFilesResultBuilder() : result_(new SetFileInputFilesResult()) { }

    template<int STEP> SetFileInputFilesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetFileInputFilesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetFileInputFilesResult> result_;
  };

  static SetFileInputFilesResultBuilder<0> Builder() {
    return SetFileInputFilesResultBuilder<0>();
  }

 private:
  SetFileInputFilesResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetFileInputFilesResult);
};


// Parameters for the SetNodeStackTracesEnabled command.
class HEADLESS_EXPORT SetNodeStackTracesEnabledParams {
 public:
  static std::unique_ptr<SetNodeStackTracesEnabledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetNodeStackTracesEnabledParams() { }

  // Enable or disable.
  bool GetEnable() const { return enable_; }
  void SetEnable(bool value) { enable_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetNodeStackTracesEnabledParams> Clone() const;

  template<int STATE>
  class SetNodeStackTracesEnabledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEnableSet = 1 << 1,
      kAllRequiredFieldsSet = (kEnableSet | 0)
    };

    SetNodeStackTracesEnabledParamsBuilder<STATE | kEnableSet>& SetEnable(bool value) {
      static_assert(!(STATE & kEnableSet), "property enable should not have already been set");
      result_->SetEnable(value);
      return CastState<kEnableSet>();
    }

    std::unique_ptr<SetNodeStackTracesEnabledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetNodeStackTracesEnabledParams;
    SetNodeStackTracesEnabledParamsBuilder() : result_(new SetNodeStackTracesEnabledParams()) { }

    template<int STEP> SetNodeStackTracesEnabledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetNodeStackTracesEnabledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetNodeStackTracesEnabledParams> result_;
  };

  static SetNodeStackTracesEnabledParamsBuilder<0> Builder() {
    return SetNodeStackTracesEnabledParamsBuilder<0>();
  }

 private:
  SetNodeStackTracesEnabledParams() { }

  bool enable_;

  DISALLOW_COPY_AND_ASSIGN(SetNodeStackTracesEnabledParams);
};


// Result for the SetNodeStackTracesEnabled command.
class HEADLESS_EXPORT SetNodeStackTracesEnabledResult {
 public:
  static std::unique_ptr<SetNodeStackTracesEnabledResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetNodeStackTracesEnabledResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetNodeStackTracesEnabledResult> Clone() const;

  template<int STATE>
  class SetNodeStackTracesEnabledResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetNodeStackTracesEnabledResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetNodeStackTracesEnabledResult;
    SetNodeStackTracesEnabledResultBuilder() : result_(new SetNodeStackTracesEnabledResult()) { }

    template<int STEP> SetNodeStackTracesEnabledResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetNodeStackTracesEnabledResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetNodeStackTracesEnabledResult> result_;
  };

  static SetNodeStackTracesEnabledResultBuilder<0> Builder() {
    return SetNodeStackTracesEnabledResultBuilder<0>();
  }

 private:
  SetNodeStackTracesEnabledResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetNodeStackTracesEnabledResult);
};


// Parameters for the GetNodeStackTraces command.
class HEADLESS_EXPORT GetNodeStackTracesParams {
 public:
  static std::unique_ptr<GetNodeStackTracesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetNodeStackTracesParams() { }

  // Id of the node to get stack traces for.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetNodeStackTracesParams> Clone() const;

  template<int STATE>
  class GetNodeStackTracesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    GetNodeStackTracesParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<GetNodeStackTracesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetNodeStackTracesParams;
    GetNodeStackTracesParamsBuilder() : result_(new GetNodeStackTracesParams()) { }

    template<int STEP> GetNodeStackTracesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetNodeStackTracesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetNodeStackTracesParams> result_;
  };

  static GetNodeStackTracesParamsBuilder<0> Builder() {
    return GetNodeStackTracesParamsBuilder<0>();
  }

 private:
  GetNodeStackTracesParams() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(GetNodeStackTracesParams);
};


// Result for the GetNodeStackTraces command.
class HEADLESS_EXPORT GetNodeStackTracesResult {
 public:
  static std::unique_ptr<GetNodeStackTracesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetNodeStackTracesResult() { }

  // Creation stack trace, if available.
  bool HasCreation() const { return !!creation_; }
  const ::headless::runtime::StackTrace* GetCreation() const { DCHECK(HasCreation()); return creation_.value().get(); }
  void SetCreation(std::unique_ptr<::headless::runtime::StackTrace> value) { creation_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetNodeStackTracesResult> Clone() const;

  template<int STATE>
  class GetNodeStackTracesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GetNodeStackTracesResultBuilder<STATE>& SetCreation(std::unique_ptr<::headless::runtime::StackTrace> value) {
      result_->SetCreation(std::move(value));
      return *this;
    }

    std::unique_ptr<GetNodeStackTracesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetNodeStackTracesResult;
    GetNodeStackTracesResultBuilder() : result_(new GetNodeStackTracesResult()) { }

    template<int STEP> GetNodeStackTracesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetNodeStackTracesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetNodeStackTracesResult> result_;
  };

  static GetNodeStackTracesResultBuilder<0> Builder() {
    return GetNodeStackTracesResultBuilder<0>();
  }

 private:
  GetNodeStackTracesResult() { }

  base::Optional<std::unique_ptr<::headless::runtime::StackTrace>> creation_;

  DISALLOW_COPY_AND_ASSIGN(GetNodeStackTracesResult);
};


// Parameters for the GetFileInfo command.
class HEADLESS_EXPORT GetFileInfoParams {
 public:
  static std::unique_ptr<GetFileInfoParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFileInfoParams() { }

  // JavaScript object id of the node wrapper.
  std::string GetObjectId() const { return object_id_; }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFileInfoParams> Clone() const;

  template<int STATE>
  class GetFileInfoParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kObjectIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kObjectIdSet | 0)
    };

    GetFileInfoParamsBuilder<STATE | kObjectIdSet>& SetObjectId(const std::string& value) {
      static_assert(!(STATE & kObjectIdSet), "property objectId should not have already been set");
      result_->SetObjectId(value);
      return CastState<kObjectIdSet>();
    }

    std::unique_ptr<GetFileInfoParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFileInfoParams;
    GetFileInfoParamsBuilder() : result_(new GetFileInfoParams()) { }

    template<int STEP> GetFileInfoParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFileInfoParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFileInfoParams> result_;
  };

  static GetFileInfoParamsBuilder<0> Builder() {
    return GetFileInfoParamsBuilder<0>();
  }

 private:
  GetFileInfoParams() { }

  std::string object_id_;

  DISALLOW_COPY_AND_ASSIGN(GetFileInfoParams);
};


// Result for the GetFileInfo command.
class HEADLESS_EXPORT GetFileInfoResult {
 public:
  static std::unique_ptr<GetFileInfoResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFileInfoResult() { }

  std::string GetPath() const { return path_; }
  void SetPath(const std::string& value) { path_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFileInfoResult> Clone() const;

  template<int STATE>
  class GetFileInfoResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPathSet = 1 << 1,
      kAllRequiredFieldsSet = (kPathSet | 0)
    };

    GetFileInfoResultBuilder<STATE | kPathSet>& SetPath(const std::string& value) {
      static_assert(!(STATE & kPathSet), "property path should not have already been set");
      result_->SetPath(value);
      return CastState<kPathSet>();
    }

    std::unique_ptr<GetFileInfoResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFileInfoResult;
    GetFileInfoResultBuilder() : result_(new GetFileInfoResult()) { }

    template<int STEP> GetFileInfoResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFileInfoResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFileInfoResult> result_;
  };

  static GetFileInfoResultBuilder<0> Builder() {
    return GetFileInfoResultBuilder<0>();
  }

 private:
  GetFileInfoResult() { }

  std::string path_;

  DISALLOW_COPY_AND_ASSIGN(GetFileInfoResult);
};


// Parameters for the SetInspectedNode command.
class HEADLESS_EXPORT SetInspectedNodeParams {
 public:
  static std::unique_ptr<SetInspectedNodeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetInspectedNodeParams() { }

  // DOM node id to be accessible by means of $x command line API.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetInspectedNodeParams> Clone() const;

  template<int STATE>
  class SetInspectedNodeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    SetInspectedNodeParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<SetInspectedNodeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetInspectedNodeParams;
    SetInspectedNodeParamsBuilder() : result_(new SetInspectedNodeParams()) { }

    template<int STEP> SetInspectedNodeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetInspectedNodeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetInspectedNodeParams> result_;
  };

  static SetInspectedNodeParamsBuilder<0> Builder() {
    return SetInspectedNodeParamsBuilder<0>();
  }

 private:
  SetInspectedNodeParams() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(SetInspectedNodeParams);
};


// Result for the SetInspectedNode command.
class HEADLESS_EXPORT SetInspectedNodeResult {
 public:
  static std::unique_ptr<SetInspectedNodeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetInspectedNodeResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetInspectedNodeResult> Clone() const;

  template<int STATE>
  class SetInspectedNodeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetInspectedNodeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetInspectedNodeResult;
    SetInspectedNodeResultBuilder() : result_(new SetInspectedNodeResult()) { }

    template<int STEP> SetInspectedNodeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetInspectedNodeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetInspectedNodeResult> result_;
  };

  static SetInspectedNodeResultBuilder<0> Builder() {
    return SetInspectedNodeResultBuilder<0>();
  }

 private:
  SetInspectedNodeResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetInspectedNodeResult);
};


// Parameters for the SetNodeName command.
class HEADLESS_EXPORT SetNodeNameParams {
 public:
  static std::unique_ptr<SetNodeNameParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetNodeNameParams() { }

  // Id of the node to set name for.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // New node's name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetNodeNameParams> Clone() const;

  template<int STATE>
  class SetNodeNameParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kNameSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kNameSet | 0)
    };

    SetNodeNameParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    SetNodeNameParamsBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    std::unique_ptr<SetNodeNameParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetNodeNameParams;
    SetNodeNameParamsBuilder() : result_(new SetNodeNameParams()) { }

    template<int STEP> SetNodeNameParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetNodeNameParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetNodeNameParams> result_;
  };

  static SetNodeNameParamsBuilder<0> Builder() {
    return SetNodeNameParamsBuilder<0>();
  }

 private:
  SetNodeNameParams() { }

  int node_id_;
  std::string name_;

  DISALLOW_COPY_AND_ASSIGN(SetNodeNameParams);
};


// Result for the SetNodeName command.
class HEADLESS_EXPORT SetNodeNameResult {
 public:
  static std::unique_ptr<SetNodeNameResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetNodeNameResult() { }

  // New node's id.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetNodeNameResult> Clone() const;

  template<int STATE>
  class SetNodeNameResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdSet | 0)
    };

    SetNodeNameResultBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<SetNodeNameResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetNodeNameResult;
    SetNodeNameResultBuilder() : result_(new SetNodeNameResult()) { }

    template<int STEP> SetNodeNameResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetNodeNameResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetNodeNameResult> result_;
  };

  static SetNodeNameResultBuilder<0> Builder() {
    return SetNodeNameResultBuilder<0>();
  }

 private:
  SetNodeNameResult() { }

  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(SetNodeNameResult);
};


// Parameters for the SetNodeValue command.
class HEADLESS_EXPORT SetNodeValueParams {
 public:
  static std::unique_ptr<SetNodeValueParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetNodeValueParams() { }

  // Id of the node to set value for.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // New node's value.
  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetNodeValueParams> Clone() const;

  template<int STATE>
  class SetNodeValueParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kValueSet | 0)
    };

    SetNodeValueParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    SetNodeValueParamsBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<SetNodeValueParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetNodeValueParams;
    SetNodeValueParamsBuilder() : result_(new SetNodeValueParams()) { }

    template<int STEP> SetNodeValueParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetNodeValueParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetNodeValueParams> result_;
  };

  static SetNodeValueParamsBuilder<0> Builder() {
    return SetNodeValueParamsBuilder<0>();
  }

 private:
  SetNodeValueParams() { }

  int node_id_;
  std::string value_;

  DISALLOW_COPY_AND_ASSIGN(SetNodeValueParams);
};


// Result for the SetNodeValue command.
class HEADLESS_EXPORT SetNodeValueResult {
 public:
  static std::unique_ptr<SetNodeValueResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetNodeValueResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetNodeValueResult> Clone() const;

  template<int STATE>
  class SetNodeValueResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetNodeValueResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetNodeValueResult;
    SetNodeValueResultBuilder() : result_(new SetNodeValueResult()) { }

    template<int STEP> SetNodeValueResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetNodeValueResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetNodeValueResult> result_;
  };

  static SetNodeValueResultBuilder<0> Builder() {
    return SetNodeValueResultBuilder<0>();
  }

 private:
  SetNodeValueResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetNodeValueResult);
};


// Parameters for the SetOuterHTML command.
class HEADLESS_EXPORT SetOuterHTMLParams {
 public:
  static std::unique_ptr<SetOuterHTMLParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetOuterHTMLParams() { }

  // Id of the node to set markup for.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // Outer HTML markup to set.
  std::string GetOuterHTML() const { return outerhtml_; }
  void SetOuterHTML(const std::string& value) { outerhtml_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetOuterHTMLParams> Clone() const;

  template<int STATE>
  class SetOuterHTMLParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kOuterHTMLSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kOuterHTMLSet | 0)
    };

    SetOuterHTMLParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    SetOuterHTMLParamsBuilder<STATE | kOuterHTMLSet>& SetOuterHTML(const std::string& value) {
      static_assert(!(STATE & kOuterHTMLSet), "property outerHTML should not have already been set");
      result_->SetOuterHTML(value);
      return CastState<kOuterHTMLSet>();
    }

    std::unique_ptr<SetOuterHTMLParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetOuterHTMLParams;
    SetOuterHTMLParamsBuilder() : result_(new SetOuterHTMLParams()) { }

    template<int STEP> SetOuterHTMLParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetOuterHTMLParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetOuterHTMLParams> result_;
  };

  static SetOuterHTMLParamsBuilder<0> Builder() {
    return SetOuterHTMLParamsBuilder<0>();
  }

 private:
  SetOuterHTMLParams() { }

  int node_id_;
  std::string outerhtml_;

  DISALLOW_COPY_AND_ASSIGN(SetOuterHTMLParams);
};


// Result for the SetOuterHTML command.
class HEADLESS_EXPORT SetOuterHTMLResult {
 public:
  static std::unique_ptr<SetOuterHTMLResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetOuterHTMLResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetOuterHTMLResult> Clone() const;

  template<int STATE>
  class SetOuterHTMLResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetOuterHTMLResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetOuterHTMLResult;
    SetOuterHTMLResultBuilder() : result_(new SetOuterHTMLResult()) { }

    template<int STEP> SetOuterHTMLResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetOuterHTMLResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetOuterHTMLResult> result_;
  };

  static SetOuterHTMLResultBuilder<0> Builder() {
    return SetOuterHTMLResultBuilder<0>();
  }

 private:
  SetOuterHTMLResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetOuterHTMLResult);
};


// Parameters for the Undo command.
class HEADLESS_EXPORT UndoParams {
 public:
  static std::unique_ptr<UndoParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~UndoParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<UndoParams> Clone() const;

  template<int STATE>
  class UndoParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<UndoParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class UndoParams;
    UndoParamsBuilder() : result_(new UndoParams()) { }

    template<int STEP> UndoParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<UndoParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<UndoParams> result_;
  };

  static UndoParamsBuilder<0> Builder() {
    return UndoParamsBuilder<0>();
  }

 private:
  UndoParams() { }


  DISALLOW_COPY_AND_ASSIGN(UndoParams);
};


// Result for the Undo command.
class HEADLESS_EXPORT UndoResult {
 public:
  static std::unique_ptr<UndoResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~UndoResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<UndoResult> Clone() const;

  template<int STATE>
  class UndoResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<UndoResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class UndoResult;
    UndoResultBuilder() : result_(new UndoResult()) { }

    template<int STEP> UndoResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<UndoResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<UndoResult> result_;
  };

  static UndoResultBuilder<0> Builder() {
    return UndoResultBuilder<0>();
  }

 private:
  UndoResult() { }


  DISALLOW_COPY_AND_ASSIGN(UndoResult);
};


// Parameters for the GetFrameOwner command.
class HEADLESS_EXPORT GetFrameOwnerParams {
 public:
  static std::unique_ptr<GetFrameOwnerParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFrameOwnerParams() { }

  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFrameOwnerParams> Clone() const;

  template<int STATE>
  class GetFrameOwnerParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameIdSet | 0)
    };

    GetFrameOwnerParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    std::unique_ptr<GetFrameOwnerParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFrameOwnerParams;
    GetFrameOwnerParamsBuilder() : result_(new GetFrameOwnerParams()) { }

    template<int STEP> GetFrameOwnerParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFrameOwnerParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFrameOwnerParams> result_;
  };

  static GetFrameOwnerParamsBuilder<0> Builder() {
    return GetFrameOwnerParamsBuilder<0>();
  }

 private:
  GetFrameOwnerParams() { }

  std::string frame_id_;

  DISALLOW_COPY_AND_ASSIGN(GetFrameOwnerParams);
};


// Result for the GetFrameOwner command.
class HEADLESS_EXPORT GetFrameOwnerResult {
 public:
  static std::unique_ptr<GetFrameOwnerResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFrameOwnerResult() { }

  // Resulting node.
  int GetBackendNodeId() const { return backend_node_id_; }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // Id of the node at given coordinates, only when enabled and requested document.
  bool HasNodeId() const { return !!node_id_; }
  int GetNodeId() const { DCHECK(HasNodeId()); return node_id_.value(); }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFrameOwnerResult> Clone() const;

  template<int STATE>
  class GetFrameOwnerResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBackendNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kBackendNodeIdSet | 0)
    };

    GetFrameOwnerResultBuilder<STATE | kBackendNodeIdSet>& SetBackendNodeId(int value) {
      static_assert(!(STATE & kBackendNodeIdSet), "property backendNodeId should not have already been set");
      result_->SetBackendNodeId(value);
      return CastState<kBackendNodeIdSet>();
    }

    GetFrameOwnerResultBuilder<STATE>& SetNodeId(int value) {
      result_->SetNodeId(value);
      return *this;
    }

    std::unique_ptr<GetFrameOwnerResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFrameOwnerResult;
    GetFrameOwnerResultBuilder() : result_(new GetFrameOwnerResult()) { }

    template<int STEP> GetFrameOwnerResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFrameOwnerResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFrameOwnerResult> result_;
  };

  static GetFrameOwnerResultBuilder<0> Builder() {
    return GetFrameOwnerResultBuilder<0>();
  }

 private:
  GetFrameOwnerResult() { }

  int backend_node_id_;
  base::Optional<int> node_id_;

  DISALLOW_COPY_AND_ASSIGN(GetFrameOwnerResult);
};


// Parameters for the AttributeModified event.
class HEADLESS_EXPORT AttributeModifiedParams {
 public:
  static std::unique_ptr<AttributeModifiedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AttributeModifiedParams() { }

  // Id of the node that has changed.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // Attribute name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Attribute value.
  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AttributeModifiedParams> Clone() const;

  template<int STATE>
  class AttributeModifiedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kNameSet = 1 << 2,
    kValueSet = 1 << 3,
      kAllRequiredFieldsSet = (kNodeIdSet | kNameSet | kValueSet | 0)
    };

    AttributeModifiedParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    AttributeModifiedParamsBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    AttributeModifiedParamsBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<AttributeModifiedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AttributeModifiedParams;
    AttributeModifiedParamsBuilder() : result_(new AttributeModifiedParams()) { }

    template<int STEP> AttributeModifiedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AttributeModifiedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AttributeModifiedParams> result_;
  };

  static AttributeModifiedParamsBuilder<0> Builder() {
    return AttributeModifiedParamsBuilder<0>();
  }

 private:
  AttributeModifiedParams() { }

  int node_id_;
  std::string name_;
  std::string value_;

  DISALLOW_COPY_AND_ASSIGN(AttributeModifiedParams);
};


// Parameters for the AttributeRemoved event.
class HEADLESS_EXPORT AttributeRemovedParams {
 public:
  static std::unique_ptr<AttributeRemovedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AttributeRemovedParams() { }

  // Id of the node that has changed.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // A ttribute name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AttributeRemovedParams> Clone() const;

  template<int STATE>
  class AttributeRemovedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kNameSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kNameSet | 0)
    };

    AttributeRemovedParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    AttributeRemovedParamsBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    std::unique_ptr<AttributeRemovedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AttributeRemovedParams;
    AttributeRemovedParamsBuilder() : result_(new AttributeRemovedParams()) { }

    template<int STEP> AttributeRemovedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AttributeRemovedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AttributeRemovedParams> result_;
  };

  static AttributeRemovedParamsBuilder<0> Builder() {
    return AttributeRemovedParamsBuilder<0>();
  }

 private:
  AttributeRemovedParams() { }

  int node_id_;
  std::string name_;

  DISALLOW_COPY_AND_ASSIGN(AttributeRemovedParams);
};


// Parameters for the CharacterDataModified event.
class HEADLESS_EXPORT CharacterDataModifiedParams {
 public:
  static std::unique_ptr<CharacterDataModifiedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CharacterDataModifiedParams() { }

  // Id of the node that has changed.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // New text value.
  std::string GetCharacterData() const { return character_data_; }
  void SetCharacterData(const std::string& value) { character_data_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CharacterDataModifiedParams> Clone() const;

  template<int STATE>
  class CharacterDataModifiedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kCharacterDataSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kCharacterDataSet | 0)
    };

    CharacterDataModifiedParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    CharacterDataModifiedParamsBuilder<STATE | kCharacterDataSet>& SetCharacterData(const std::string& value) {
      static_assert(!(STATE & kCharacterDataSet), "property characterData should not have already been set");
      result_->SetCharacterData(value);
      return CastState<kCharacterDataSet>();
    }

    std::unique_ptr<CharacterDataModifiedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CharacterDataModifiedParams;
    CharacterDataModifiedParamsBuilder() : result_(new CharacterDataModifiedParams()) { }

    template<int STEP> CharacterDataModifiedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CharacterDataModifiedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CharacterDataModifiedParams> result_;
  };

  static CharacterDataModifiedParamsBuilder<0> Builder() {
    return CharacterDataModifiedParamsBuilder<0>();
  }

 private:
  CharacterDataModifiedParams() { }

  int node_id_;
  std::string character_data_;

  DISALLOW_COPY_AND_ASSIGN(CharacterDataModifiedParams);
};


// Parameters for the ChildNodeCountUpdated event.
class HEADLESS_EXPORT ChildNodeCountUpdatedParams {
 public:
  static std::unique_ptr<ChildNodeCountUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ChildNodeCountUpdatedParams() { }

  // Id of the node that has changed.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  // New node count.
  int GetChildNodeCount() const { return child_node_count_; }
  void SetChildNodeCount(int value) { child_node_count_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ChildNodeCountUpdatedParams> Clone() const;

  template<int STATE>
  class ChildNodeCountUpdatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kChildNodeCountSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kChildNodeCountSet | 0)
    };

    ChildNodeCountUpdatedParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    ChildNodeCountUpdatedParamsBuilder<STATE | kChildNodeCountSet>& SetChildNodeCount(int value) {
      static_assert(!(STATE & kChildNodeCountSet), "property childNodeCount should not have already been set");
      result_->SetChildNodeCount(value);
      return CastState<kChildNodeCountSet>();
    }

    std::unique_ptr<ChildNodeCountUpdatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ChildNodeCountUpdatedParams;
    ChildNodeCountUpdatedParamsBuilder() : result_(new ChildNodeCountUpdatedParams()) { }

    template<int STEP> ChildNodeCountUpdatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ChildNodeCountUpdatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ChildNodeCountUpdatedParams> result_;
  };

  static ChildNodeCountUpdatedParamsBuilder<0> Builder() {
    return ChildNodeCountUpdatedParamsBuilder<0>();
  }

 private:
  ChildNodeCountUpdatedParams() { }

  int node_id_;
  int child_node_count_;

  DISALLOW_COPY_AND_ASSIGN(ChildNodeCountUpdatedParams);
};


// Parameters for the ChildNodeInserted event.
class HEADLESS_EXPORT ChildNodeInsertedParams {
 public:
  static std::unique_ptr<ChildNodeInsertedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ChildNodeInsertedParams() { }

  // Id of the node that has changed.
  int GetParentNodeId() const { return parent_node_id_; }
  void SetParentNodeId(int value) { parent_node_id_ = value; }

  // If of the previous siblint.
  int GetPreviousNodeId() const { return previous_node_id_; }
  void SetPreviousNodeId(int value) { previous_node_id_ = value; }

  // Inserted node data.
  const ::headless::dom::Node* GetNode() const { return node_.get(); }
  void SetNode(std::unique_ptr<::headless::dom::Node> value) { node_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ChildNodeInsertedParams> Clone() const;

  template<int STATE>
  class ChildNodeInsertedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kParentNodeIdSet = 1 << 1,
    kPreviousNodeIdSet = 1 << 2,
    kNodeSet = 1 << 3,
      kAllRequiredFieldsSet = (kParentNodeIdSet | kPreviousNodeIdSet | kNodeSet | 0)
    };

    ChildNodeInsertedParamsBuilder<STATE | kParentNodeIdSet>& SetParentNodeId(int value) {
      static_assert(!(STATE & kParentNodeIdSet), "property parentNodeId should not have already been set");
      result_->SetParentNodeId(value);
      return CastState<kParentNodeIdSet>();
    }

    ChildNodeInsertedParamsBuilder<STATE | kPreviousNodeIdSet>& SetPreviousNodeId(int value) {
      static_assert(!(STATE & kPreviousNodeIdSet), "property previousNodeId should not have already been set");
      result_->SetPreviousNodeId(value);
      return CastState<kPreviousNodeIdSet>();
    }

    ChildNodeInsertedParamsBuilder<STATE | kNodeSet>& SetNode(std::unique_ptr<::headless::dom::Node> value) {
      static_assert(!(STATE & kNodeSet), "property node should not have already been set");
      result_->SetNode(std::move(value));
      return CastState<kNodeSet>();
    }

    std::unique_ptr<ChildNodeInsertedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ChildNodeInsertedParams;
    ChildNodeInsertedParamsBuilder() : result_(new ChildNodeInsertedParams()) { }

    template<int STEP> ChildNodeInsertedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ChildNodeInsertedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ChildNodeInsertedParams> result_;
  };

  static ChildNodeInsertedParamsBuilder<0> Builder() {
    return ChildNodeInsertedParamsBuilder<0>();
  }

 private:
  ChildNodeInsertedParams() { }

  int parent_node_id_;
  int previous_node_id_;
  std::unique_ptr<::headless::dom::Node> node_;

  DISALLOW_COPY_AND_ASSIGN(ChildNodeInsertedParams);
};


// Parameters for the ChildNodeRemoved event.
class HEADLESS_EXPORT ChildNodeRemovedParams {
 public:
  static std::unique_ptr<ChildNodeRemovedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ChildNodeRemovedParams() { }

  // Parent id.
  int GetParentNodeId() const { return parent_node_id_; }
  void SetParentNodeId(int value) { parent_node_id_ = value; }

  // Id of the node that has been removed.
  int GetNodeId() const { return node_id_; }
  void SetNodeId(int value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ChildNodeRemovedParams> Clone() const;

  template<int STATE>
  class ChildNodeRemovedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kParentNodeIdSet = 1 << 1,
    kNodeIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kParentNodeIdSet | kNodeIdSet | 0)
    };

    ChildNodeRemovedParamsBuilder<STATE | kParentNodeIdSet>& SetParentNodeId(int value) {
      static_assert(!(STATE & kParentNodeIdSet), "property parentNodeId should not have already been set");
      result_->SetParentNodeId(value);
      return CastState<kParentNodeIdSet>();
    }

    ChildNodeRemovedParamsBuilder<STATE | kNodeIdSet>& SetNodeId(int value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<ChildNodeRemovedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ChildNodeRemovedParams;
    ChildNodeRemovedParamsBuilder() : result_(new ChildNodeRemovedParams()) { }

    template<int STEP> ChildNodeRemovedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ChildNodeRemovedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ChildNodeRemovedParams> result_;
  };

  static ChildNodeRemovedParamsBuilder<0> Builder() {
    return ChildNodeRemovedParamsBuilder<0>();
  }

 private:
  ChildNodeRemovedParams() { }

  int parent_node_id_;
  int node_id_;

  DISALLOW_COPY_AND_ASSIGN(ChildNodeRemovedParams);
};


// Parameters for the DistributedNodesUpdated event.
class HEADLESS_EXPORT DistributedNodesUpdatedParams {
 public:
  static std::unique_ptr<DistributedNodesUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DistributedNodesUpdatedParams() { }

  // Insertion point where distrubuted nodes were updated.
  int GetInsertionPointId() const { return insertion_point_id_; }
  void SetInsertionPointId(int value) { insertion_point_id_ = value; }

  // Distributed nodes for given insertion point.
  const std::vector<std::unique_ptr<::headless::dom::BackendNode>>* GetDistributedNodes() const { return &distributed_nodes_; }
  void SetDistributedNodes(std::vector<std::unique_ptr<::headless::dom::BackendNode>> value) { distributed_nodes_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DistributedNodesUpdatedParams> Clone() const;

  template<int STATE>
  class DistributedNodesUpdatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kInsertionPointIdSet = 1 << 1,
    kDistributedNodesSet = 1 << 2,
      kAllRequiredFieldsSet = (kInsertionPointIdSet | kDistributedNodesSet | 0)
    };

    DistributedNodesUpdatedParamsBuilder<STATE | kInsertionPointIdSet>& SetInsertionPointId(int value) {
      static_assert(!(STATE & kInsertionPointIdSet), "property insertionPointId should not have already been set");
      result_->SetInsertionPointId(value);
      return CastState<kInsertionPointIdSet>();
    }

    DistributedNodesUpdatedParamsBuilder<STATE | kDistributedNodesSet>& SetDistributedNodes(std::vector<std::unique_ptr<::headless::dom::BackendNode>> value) {
      static_assert(!(STATE & kDistributedNodesSet), "property distributedNodes should not have already been set");
      result_->SetDistributedNodes(std::move(value));
      return CastState<kDistributedNodesSet>();
    }

    std::unique_ptr<DistributedNodesUpdatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DistributedNodesUpdatedParams;
    DistributedNodesUpdatedParamsBuilder() : result_(new DistributedNodesUpdatedParams()) { }

    template<int STEP> DistributedNodesUpdatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DistributedNodesUpdatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DistributedNodesUpdatedParams> result_;
  };

  static DistributedNodesUpdatedParamsBuilder<0> Builder() {
    return DistributedNodesUpdatedParamsBuilder<0>();
  }

 private:
  DistributedNodesUpdatedParams() { }

  int insertion_point_id_;
  std::vector<std::unique_ptr<::headless::dom::BackendNode>> distributed_nodes_;

  DISALLOW_COPY_AND_ASSIGN(DistributedNodesUpdatedParams);
};


// Parameters for the DocumentUpdated event.
class HEADLESS_EXPORT DocumentUpdatedParams {
 public:
  static std::unique_ptr<DocumentUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DocumentUpdatedParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DocumentUpdatedParams> Clone() const;

  template<int STATE>
  class DocumentUpdatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DocumentUpdatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DocumentUpdatedParams;
    DocumentUpdatedParamsBuilder() : result_(new DocumentUpdatedParams()) { }

    template<int STEP> DocumentUpdatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DocumentUpdatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DocumentUpdatedParams> result_;
  };

  static DocumentUpdatedParamsBuilder<0> Builder() {
    return DocumentUpdatedParamsBuilder<0>();
  }

 private:
  DocumentUpdatedParams() { }


  DISALLOW_COPY_AND_ASSIGN(DocumentUpdatedParams);
};


// Parameters for the InlineStyleInvalidated event.
class HEADLESS_EXPORT InlineStyleInvalidatedParams {
 public:
  static std::unique_ptr<InlineStyleInvalidatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~InlineStyleInvalidatedParams() { }

  // Ids of the nodes for which the inline styles have been invalidated.
  const std::vector<int>* GetNodeIds() const { return &node_ids_; }
  void SetNodeIds(std::vector<int> value) { node_ids_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InlineStyleInvalidatedParams> Clone() const;

  template<int STATE>
  class InlineStyleInvalidatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdsSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeIdsSet | 0)
    };

    InlineStyleInvalidatedParamsBuilder<STATE | kNodeIdsSet>& SetNodeIds(std::vector<int> value) {
      static_assert(!(STATE & kNodeIdsSet), "property nodeIds should not have already been set");
      result_->SetNodeIds(std::move(value));
      return CastState<kNodeIdsSet>();
    }

    std::unique_ptr<InlineStyleInvalidatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InlineStyleInvalidatedParams;
    InlineStyleInvalidatedParamsBuilder() : result_(new InlineStyleInvalidatedParams()) { }

    template<int STEP> InlineStyleInvalidatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InlineStyleInvalidatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InlineStyleInvalidatedParams> result_;
  };

  static InlineStyleInvalidatedParamsBuilder<0> Builder() {
    return InlineStyleInvalidatedParamsBuilder<0>();
  }

 private:
  InlineStyleInvalidatedParams() { }

  std::vector<int> node_ids_;

  DISALLOW_COPY_AND_ASSIGN(InlineStyleInvalidatedParams);
};


// Parameters for the PseudoElementAdded event.
class HEADLESS_EXPORT PseudoElementAddedParams {
 public:
  static std::unique_ptr<PseudoElementAddedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PseudoElementAddedParams() { }

  // Pseudo element's parent element id.
  int GetParentId() const { return parent_id_; }
  void SetParentId(int value) { parent_id_ = value; }

  // The added pseudo element.
  const ::headless::dom::Node* GetPseudoElement() const { return pseudo_element_.get(); }
  void SetPseudoElement(std::unique_ptr<::headless::dom::Node> value) { pseudo_element_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PseudoElementAddedParams> Clone() const;

  template<int STATE>
  class PseudoElementAddedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kParentIdSet = 1 << 1,
    kPseudoElementSet = 1 << 2,
      kAllRequiredFieldsSet = (kParentIdSet | kPseudoElementSet | 0)
    };

    PseudoElementAddedParamsBuilder<STATE | kParentIdSet>& SetParentId(int value) {
      static_assert(!(STATE & kParentIdSet), "property parentId should not have already been set");
      result_->SetParentId(value);
      return CastState<kParentIdSet>();
    }

    PseudoElementAddedParamsBuilder<STATE | kPseudoElementSet>& SetPseudoElement(std::unique_ptr<::headless::dom::Node> value) {
      static_assert(!(STATE & kPseudoElementSet), "property pseudoElement should not have already been set");
      result_->SetPseudoElement(std::move(value));
      return CastState<kPseudoElementSet>();
    }

    std::unique_ptr<PseudoElementAddedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PseudoElementAddedParams;
    PseudoElementAddedParamsBuilder() : result_(new PseudoElementAddedParams()) { }

    template<int STEP> PseudoElementAddedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PseudoElementAddedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PseudoElementAddedParams> result_;
  };

  static PseudoElementAddedParamsBuilder<0> Builder() {
    return PseudoElementAddedParamsBuilder<0>();
  }

 private:
  PseudoElementAddedParams() { }

  int parent_id_;
  std::unique_ptr<::headless::dom::Node> pseudo_element_;

  DISALLOW_COPY_AND_ASSIGN(PseudoElementAddedParams);
};


// Parameters for the PseudoElementRemoved event.
class HEADLESS_EXPORT PseudoElementRemovedParams {
 public:
  static std::unique_ptr<PseudoElementRemovedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PseudoElementRemovedParams() { }

  // Pseudo element's parent element id.
  int GetParentId() const { return parent_id_; }
  void SetParentId(int value) { parent_id_ = value; }

  // The removed pseudo element id.
  int GetPseudoElementId() const { return pseudo_element_id_; }
  void SetPseudoElementId(int value) { pseudo_element_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PseudoElementRemovedParams> Clone() const;

  template<int STATE>
  class PseudoElementRemovedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kParentIdSet = 1 << 1,
    kPseudoElementIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kParentIdSet | kPseudoElementIdSet | 0)
    };

    PseudoElementRemovedParamsBuilder<STATE | kParentIdSet>& SetParentId(int value) {
      static_assert(!(STATE & kParentIdSet), "property parentId should not have already been set");
      result_->SetParentId(value);
      return CastState<kParentIdSet>();
    }

    PseudoElementRemovedParamsBuilder<STATE | kPseudoElementIdSet>& SetPseudoElementId(int value) {
      static_assert(!(STATE & kPseudoElementIdSet), "property pseudoElementId should not have already been set");
      result_->SetPseudoElementId(value);
      return CastState<kPseudoElementIdSet>();
    }

    std::unique_ptr<PseudoElementRemovedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PseudoElementRemovedParams;
    PseudoElementRemovedParamsBuilder() : result_(new PseudoElementRemovedParams()) { }

    template<int STEP> PseudoElementRemovedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PseudoElementRemovedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PseudoElementRemovedParams> result_;
  };

  static PseudoElementRemovedParamsBuilder<0> Builder() {
    return PseudoElementRemovedParamsBuilder<0>();
  }

 private:
  PseudoElementRemovedParams() { }

  int parent_id_;
  int pseudo_element_id_;

  DISALLOW_COPY_AND_ASSIGN(PseudoElementRemovedParams);
};


// Parameters for the SetChildNodes event.
class HEADLESS_EXPORT SetChildNodesParams {
 public:
  static std::unique_ptr<SetChildNodesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetChildNodesParams() { }

  // Parent node id to populate with children.
  int GetParentId() const { return parent_id_; }
  void SetParentId(int value) { parent_id_ = value; }

  // Child nodes array.
  const std::vector<std::unique_ptr<::headless::dom::Node>>* GetNodes() const { return &nodes_; }
  void SetNodes(std::vector<std::unique_ptr<::headless::dom::Node>> value) { nodes_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetChildNodesParams> Clone() const;

  template<int STATE>
  class SetChildNodesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kParentIdSet = 1 << 1,
    kNodesSet = 1 << 2,
      kAllRequiredFieldsSet = (kParentIdSet | kNodesSet | 0)
    };

    SetChildNodesParamsBuilder<STATE | kParentIdSet>& SetParentId(int value) {
      static_assert(!(STATE & kParentIdSet), "property parentId should not have already been set");
      result_->SetParentId(value);
      return CastState<kParentIdSet>();
    }

    SetChildNodesParamsBuilder<STATE | kNodesSet>& SetNodes(std::vector<std::unique_ptr<::headless::dom::Node>> value) {
      static_assert(!(STATE & kNodesSet), "property nodes should not have already been set");
      result_->SetNodes(std::move(value));
      return CastState<kNodesSet>();
    }

    std::unique_ptr<SetChildNodesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetChildNodesParams;
    SetChildNodesParamsBuilder() : result_(new SetChildNodesParams()) { }

    template<int STEP> SetChildNodesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetChildNodesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetChildNodesParams> result_;
  };

  static SetChildNodesParamsBuilder<0> Builder() {
    return SetChildNodesParamsBuilder<0>();
  }

 private:
  SetChildNodesParams() { }

  int parent_id_;
  std::vector<std::unique_ptr<::headless::dom::Node>> nodes_;

  DISALLOW_COPY_AND_ASSIGN(SetChildNodesParams);
};


// Parameters for the ShadowRootPopped event.
class HEADLESS_EXPORT ShadowRootPoppedParams {
 public:
  static std::unique_ptr<ShadowRootPoppedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ShadowRootPoppedParams() { }

  // Host element id.
  int GetHostId() const { return host_id_; }
  void SetHostId(int value) { host_id_ = value; }

  // Shadow root id.
  int GetRootId() const { return root_id_; }
  void SetRootId(int value) { root_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ShadowRootPoppedParams> Clone() const;

  template<int STATE>
  class ShadowRootPoppedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kHostIdSet = 1 << 1,
    kRootIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kHostIdSet | kRootIdSet | 0)
    };

    ShadowRootPoppedParamsBuilder<STATE | kHostIdSet>& SetHostId(int value) {
      static_assert(!(STATE & kHostIdSet), "property hostId should not have already been set");
      result_->SetHostId(value);
      return CastState<kHostIdSet>();
    }

    ShadowRootPoppedParamsBuilder<STATE | kRootIdSet>& SetRootId(int value) {
      static_assert(!(STATE & kRootIdSet), "property rootId should not have already been set");
      result_->SetRootId(value);
      return CastState<kRootIdSet>();
    }

    std::unique_ptr<ShadowRootPoppedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ShadowRootPoppedParams;
    ShadowRootPoppedParamsBuilder() : result_(new ShadowRootPoppedParams()) { }

    template<int STEP> ShadowRootPoppedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ShadowRootPoppedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ShadowRootPoppedParams> result_;
  };

  static ShadowRootPoppedParamsBuilder<0> Builder() {
    return ShadowRootPoppedParamsBuilder<0>();
  }

 private:
  ShadowRootPoppedParams() { }

  int host_id_;
  int root_id_;

  DISALLOW_COPY_AND_ASSIGN(ShadowRootPoppedParams);
};


// Parameters for the ShadowRootPushed event.
class HEADLESS_EXPORT ShadowRootPushedParams {
 public:
  static std::unique_ptr<ShadowRootPushedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ShadowRootPushedParams() { }

  // Host element id.
  int GetHostId() const { return host_id_; }
  void SetHostId(int value) { host_id_ = value; }

  // Shadow root.
  const ::headless::dom::Node* GetRoot() const { return root_.get(); }
  void SetRoot(std::unique_ptr<::headless::dom::Node> value) { root_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ShadowRootPushedParams> Clone() const;

  template<int STATE>
  class ShadowRootPushedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kHostIdSet = 1 << 1,
    kRootSet = 1 << 2,
      kAllRequiredFieldsSet = (kHostIdSet | kRootSet | 0)
    };

    ShadowRootPushedParamsBuilder<STATE | kHostIdSet>& SetHostId(int value) {
      static_assert(!(STATE & kHostIdSet), "property hostId should not have already been set");
      result_->SetHostId(value);
      return CastState<kHostIdSet>();
    }

    ShadowRootPushedParamsBuilder<STATE | kRootSet>& SetRoot(std::unique_ptr<::headless::dom::Node> value) {
      static_assert(!(STATE & kRootSet), "property root should not have already been set");
      result_->SetRoot(std::move(value));
      return CastState<kRootSet>();
    }

    std::unique_ptr<ShadowRootPushedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ShadowRootPushedParams;
    ShadowRootPushedParamsBuilder() : result_(new ShadowRootPushedParams()) { }

    template<int STEP> ShadowRootPushedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ShadowRootPushedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ShadowRootPushedParams> result_;
  };

  static ShadowRootPushedParamsBuilder<0> Builder() {
    return ShadowRootPushedParamsBuilder<0>();
  }

 private:
  ShadowRootPushedParams() { }

  int host_id_;
  std::unique_ptr<::headless::dom::Node> root_;

  DISALLOW_COPY_AND_ASSIGN(ShadowRootPushedParams);
};


}  // namespace dom

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_DOM_H_
