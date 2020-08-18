// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace dom {

std::unique_ptr<BackendNode> BackendNode::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BackendNode");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BackendNode> result(new BackendNode());
  errors->Push();
  errors->SetName("BackendNode");
  const base::Value* node_type_value = value.FindKey("nodeType");
  if (node_type_value) {
    errors->SetName("nodeType");
    result->node_type_ = internal::FromValue<int>::Parse(*node_type_value, errors);
  } else {
    errors->AddError("required property missing: nodeType");
  }
  const base::Value* node_name_value = value.FindKey("nodeName");
  if (node_name_value) {
    errors->SetName("nodeName");
    result->node_name_ = internal::FromValue<std::string>::Parse(*node_name_value, errors);
  } else {
    errors->AddError("required property missing: nodeName");
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  } else {
    errors->AddError("required property missing: backendNodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BackendNode::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeType", internal::ToValue(node_type_));
  result->Set("nodeName", internal::ToValue(node_name_));
  result->Set("backendNodeId", internal::ToValue(backend_node_id_));
  return std::move(result);
}

std::unique_ptr<BackendNode> BackendNode::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BackendNode> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Node> Node::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Node");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Node> result(new Node());
  errors->Push();
  errors->SetName("Node");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* parent_id_value = value.FindKey("parentId");
  if (parent_id_value) {
    errors->SetName("parentId");
    result->parent_id_ = internal::FromValue<int>::Parse(*parent_id_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  } else {
    errors->AddError("required property missing: backendNodeId");
  }
  const base::Value* node_type_value = value.FindKey("nodeType");
  if (node_type_value) {
    errors->SetName("nodeType");
    result->node_type_ = internal::FromValue<int>::Parse(*node_type_value, errors);
  } else {
    errors->AddError("required property missing: nodeType");
  }
  const base::Value* node_name_value = value.FindKey("nodeName");
  if (node_name_value) {
    errors->SetName("nodeName");
    result->node_name_ = internal::FromValue<std::string>::Parse(*node_name_value, errors);
  } else {
    errors->AddError("required property missing: nodeName");
  }
  const base::Value* local_name_value = value.FindKey("localName");
  if (local_name_value) {
    errors->SetName("localName");
    result->local_name_ = internal::FromValue<std::string>::Parse(*local_name_value, errors);
  } else {
    errors->AddError("required property missing: localName");
  }
  const base::Value* node_value_value = value.FindKey("nodeValue");
  if (node_value_value) {
    errors->SetName("nodeValue");
    result->node_value_ = internal::FromValue<std::string>::Parse(*node_value_value, errors);
  } else {
    errors->AddError("required property missing: nodeValue");
  }
  const base::Value* child_node_count_value = value.FindKey("childNodeCount");
  if (child_node_count_value) {
    errors->SetName("childNodeCount");
    result->child_node_count_ = internal::FromValue<int>::Parse(*child_node_count_value, errors);
  }
  const base::Value* children_value = value.FindKey("children");
  if (children_value) {
    errors->SetName("children");
    result->children_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom::Node>>>::Parse(*children_value, errors);
  }
  const base::Value* attributes_value = value.FindKey("attributes");
  if (attributes_value) {
    errors->SetName("attributes");
    result->attributes_ = internal::FromValue<std::vector<std::string>>::Parse(*attributes_value, errors);
  }
  const base::Value* documenturl_value = value.FindKey("documentURL");
  if (documenturl_value) {
    errors->SetName("documentURL");
    result->documenturl_ = internal::FromValue<std::string>::Parse(*documenturl_value, errors);
  }
  const base::Value* baseurl_value = value.FindKey("baseURL");
  if (baseurl_value) {
    errors->SetName("baseURL");
    result->baseurl_ = internal::FromValue<std::string>::Parse(*baseurl_value, errors);
  }
  const base::Value* public_id_value = value.FindKey("publicId");
  if (public_id_value) {
    errors->SetName("publicId");
    result->public_id_ = internal::FromValue<std::string>::Parse(*public_id_value, errors);
  }
  const base::Value* system_id_value = value.FindKey("systemId");
  if (system_id_value) {
    errors->SetName("systemId");
    result->system_id_ = internal::FromValue<std::string>::Parse(*system_id_value, errors);
  }
  const base::Value* internal_subset_value = value.FindKey("internalSubset");
  if (internal_subset_value) {
    errors->SetName("internalSubset");
    result->internal_subset_ = internal::FromValue<std::string>::Parse(*internal_subset_value, errors);
  }
  const base::Value* xml_version_value = value.FindKey("xmlVersion");
  if (xml_version_value) {
    errors->SetName("xmlVersion");
    result->xml_version_ = internal::FromValue<std::string>::Parse(*xml_version_value, errors);
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  }
  const base::Value* pseudo_type_value = value.FindKey("pseudoType");
  if (pseudo_type_value) {
    errors->SetName("pseudoType");
    result->pseudo_type_ = internal::FromValue<::headless::dom::PseudoType>::Parse(*pseudo_type_value, errors);
  }
  const base::Value* shadow_root_type_value = value.FindKey("shadowRootType");
  if (shadow_root_type_value) {
    errors->SetName("shadowRootType");
    result->shadow_root_type_ = internal::FromValue<::headless::dom::ShadowRootType>::Parse(*shadow_root_type_value, errors);
  }
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  }
  const base::Value* content_document_value = value.FindKey("contentDocument");
  if (content_document_value) {
    errors->SetName("contentDocument");
    result->content_document_ = internal::FromValue<::headless::dom::Node>::Parse(*content_document_value, errors);
  }
  const base::Value* shadow_roots_value = value.FindKey("shadowRoots");
  if (shadow_roots_value) {
    errors->SetName("shadowRoots");
    result->shadow_roots_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom::Node>>>::Parse(*shadow_roots_value, errors);
  }
  const base::Value* template_content_value = value.FindKey("templateContent");
  if (template_content_value) {
    errors->SetName("templateContent");
    result->template_content_ = internal::FromValue<::headless::dom::Node>::Parse(*template_content_value, errors);
  }
  const base::Value* pseudo_elements_value = value.FindKey("pseudoElements");
  if (pseudo_elements_value) {
    errors->SetName("pseudoElements");
    result->pseudo_elements_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom::Node>>>::Parse(*pseudo_elements_value, errors);
  }
  const base::Value* imported_document_value = value.FindKey("importedDocument");
  if (imported_document_value) {
    errors->SetName("importedDocument");
    result->imported_document_ = internal::FromValue<::headless::dom::Node>::Parse(*imported_document_value, errors);
  }
  const base::Value* distributed_nodes_value = value.FindKey("distributedNodes");
  if (distributed_nodes_value) {
    errors->SetName("distributedNodes");
    result->distributed_nodes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom::BackendNode>>>::Parse(*distributed_nodes_value, errors);
  }
  const base::Value* issvg_value = value.FindKey("isSVG");
  if (issvg_value) {
    errors->SetName("isSVG");
    result->issvg_ = internal::FromValue<bool>::Parse(*issvg_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Node::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  if (parent_id_)
    result->Set("parentId", internal::ToValue(parent_id_.value()));
  result->Set("backendNodeId", internal::ToValue(backend_node_id_));
  result->Set("nodeType", internal::ToValue(node_type_));
  result->Set("nodeName", internal::ToValue(node_name_));
  result->Set("localName", internal::ToValue(local_name_));
  result->Set("nodeValue", internal::ToValue(node_value_));
  if (child_node_count_)
    result->Set("childNodeCount", internal::ToValue(child_node_count_.value()));
  if (children_)
    result->Set("children", internal::ToValue(children_.value()));
  if (attributes_)
    result->Set("attributes", internal::ToValue(attributes_.value()));
  if (documenturl_)
    result->Set("documentURL", internal::ToValue(documenturl_.value()));
  if (baseurl_)
    result->Set("baseURL", internal::ToValue(baseurl_.value()));
  if (public_id_)
    result->Set("publicId", internal::ToValue(public_id_.value()));
  if (system_id_)
    result->Set("systemId", internal::ToValue(system_id_.value()));
  if (internal_subset_)
    result->Set("internalSubset", internal::ToValue(internal_subset_.value()));
  if (xml_version_)
    result->Set("xmlVersion", internal::ToValue(xml_version_.value()));
  if (name_)
    result->Set("name", internal::ToValue(name_.value()));
  if (value_)
    result->Set("value", internal::ToValue(value_.value()));
  if (pseudo_type_)
    result->Set("pseudoType", internal::ToValue(pseudo_type_.value()));
  if (shadow_root_type_)
    result->Set("shadowRootType", internal::ToValue(shadow_root_type_.value()));
  if (frame_id_)
    result->Set("frameId", internal::ToValue(frame_id_.value()));
  if (content_document_)
    result->Set("contentDocument", internal::ToValue(*content_document_.value()));
  if (shadow_roots_)
    result->Set("shadowRoots", internal::ToValue(shadow_roots_.value()));
  if (template_content_)
    result->Set("templateContent", internal::ToValue(*template_content_.value()));
  if (pseudo_elements_)
    result->Set("pseudoElements", internal::ToValue(pseudo_elements_.value()));
  if (imported_document_)
    result->Set("importedDocument", internal::ToValue(*imported_document_.value()));
  if (distributed_nodes_)
    result->Set("distributedNodes", internal::ToValue(distributed_nodes_.value()));
  if (issvg_)
    result->Set("isSVG", internal::ToValue(issvg_.value()));
  return std::move(result);
}

std::unique_ptr<Node> Node::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Node> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RGBA> RGBA::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RGBA");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RGBA> result(new RGBA());
  errors->Push();
  errors->SetName("RGBA");
  const base::Value* r_value = value.FindKey("r");
  if (r_value) {
    errors->SetName("r");
    result->r_ = internal::FromValue<int>::Parse(*r_value, errors);
  } else {
    errors->AddError("required property missing: r");
  }
  const base::Value* g_value = value.FindKey("g");
  if (g_value) {
    errors->SetName("g");
    result->g_ = internal::FromValue<int>::Parse(*g_value, errors);
  } else {
    errors->AddError("required property missing: g");
  }
  const base::Value* b_value = value.FindKey("b");
  if (b_value) {
    errors->SetName("b");
    result->b_ = internal::FromValue<int>::Parse(*b_value, errors);
  } else {
    errors->AddError("required property missing: b");
  }
  const base::Value* a_value = value.FindKey("a");
  if (a_value) {
    errors->SetName("a");
    result->a_ = internal::FromValue<double>::Parse(*a_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RGBA::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("r", internal::ToValue(r_));
  result->Set("g", internal::ToValue(g_));
  result->Set("b", internal::ToValue(b_));
  if (a_)
    result->Set("a", internal::ToValue(a_.value()));
  return std::move(result);
}

std::unique_ptr<RGBA> RGBA::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RGBA> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BoxModel> BoxModel::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BoxModel");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BoxModel> result(new BoxModel());
  errors->Push();
  errors->SetName("BoxModel");
  const base::Value* content_value = value.FindKey("content");
  if (content_value) {
    errors->SetName("content");
    result->content_ = internal::FromValue<std::vector<double>>::Parse(*content_value, errors);
  } else {
    errors->AddError("required property missing: content");
  }
  const base::Value* padding_value = value.FindKey("padding");
  if (padding_value) {
    errors->SetName("padding");
    result->padding_ = internal::FromValue<std::vector<double>>::Parse(*padding_value, errors);
  } else {
    errors->AddError("required property missing: padding");
  }
  const base::Value* border_value = value.FindKey("border");
  if (border_value) {
    errors->SetName("border");
    result->border_ = internal::FromValue<std::vector<double>>::Parse(*border_value, errors);
  } else {
    errors->AddError("required property missing: border");
  }
  const base::Value* margin_value = value.FindKey("margin");
  if (margin_value) {
    errors->SetName("margin");
    result->margin_ = internal::FromValue<std::vector<double>>::Parse(*margin_value, errors);
  } else {
    errors->AddError("required property missing: margin");
  }
  const base::Value* width_value = value.FindKey("width");
  if (width_value) {
    errors->SetName("width");
    result->width_ = internal::FromValue<int>::Parse(*width_value, errors);
  } else {
    errors->AddError("required property missing: width");
  }
  const base::Value* height_value = value.FindKey("height");
  if (height_value) {
    errors->SetName("height");
    result->height_ = internal::FromValue<int>::Parse(*height_value, errors);
  } else {
    errors->AddError("required property missing: height");
  }
  const base::Value* shape_outside_value = value.FindKey("shapeOutside");
  if (shape_outside_value) {
    errors->SetName("shapeOutside");
    result->shape_outside_ = internal::FromValue<::headless::dom::ShapeOutsideInfo>::Parse(*shape_outside_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BoxModel::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("content", internal::ToValue(content_));
  result->Set("padding", internal::ToValue(padding_));
  result->Set("border", internal::ToValue(border_));
  result->Set("margin", internal::ToValue(margin_));
  result->Set("width", internal::ToValue(width_));
  result->Set("height", internal::ToValue(height_));
  if (shape_outside_)
    result->Set("shapeOutside", internal::ToValue(*shape_outside_.value()));
  return std::move(result);
}

std::unique_ptr<BoxModel> BoxModel::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BoxModel> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ShapeOutsideInfo> ShapeOutsideInfo::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ShapeOutsideInfo");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ShapeOutsideInfo> result(new ShapeOutsideInfo());
  errors->Push();
  errors->SetName("ShapeOutsideInfo");
  const base::Value* bounds_value = value.FindKey("bounds");
  if (bounds_value) {
    errors->SetName("bounds");
    result->bounds_ = internal::FromValue<std::vector<double>>::Parse(*bounds_value, errors);
  } else {
    errors->AddError("required property missing: bounds");
  }
  const base::Value* shape_value = value.FindKey("shape");
  if (shape_value) {
    errors->SetName("shape");
    result->shape_ = internal::FromValue<std::vector<std::unique_ptr<base::Value>>>::Parse(*shape_value, errors);
  } else {
    errors->AddError("required property missing: shape");
  }
  const base::Value* margin_shape_value = value.FindKey("marginShape");
  if (margin_shape_value) {
    errors->SetName("marginShape");
    result->margin_shape_ = internal::FromValue<std::vector<std::unique_ptr<base::Value>>>::Parse(*margin_shape_value, errors);
  } else {
    errors->AddError("required property missing: marginShape");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ShapeOutsideInfo::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("bounds", internal::ToValue(bounds_));
  result->Set("shape", internal::ToValue(shape_));
  result->Set("marginShape", internal::ToValue(margin_shape_));
  return std::move(result);
}

std::unique_ptr<ShapeOutsideInfo> ShapeOutsideInfo::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ShapeOutsideInfo> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Rect> Rect::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Rect");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Rect> result(new Rect());
  errors->Push();
  errors->SetName("Rect");
  const base::Value* x_value = value.FindKey("x");
  if (x_value) {
    errors->SetName("x");
    result->x_ = internal::FromValue<double>::Parse(*x_value, errors);
  } else {
    errors->AddError("required property missing: x");
  }
  const base::Value* y_value = value.FindKey("y");
  if (y_value) {
    errors->SetName("y");
    result->y_ = internal::FromValue<double>::Parse(*y_value, errors);
  } else {
    errors->AddError("required property missing: y");
  }
  const base::Value* width_value = value.FindKey("width");
  if (width_value) {
    errors->SetName("width");
    result->width_ = internal::FromValue<double>::Parse(*width_value, errors);
  } else {
    errors->AddError("required property missing: width");
  }
  const base::Value* height_value = value.FindKey("height");
  if (height_value) {
    errors->SetName("height");
    result->height_ = internal::FromValue<double>::Parse(*height_value, errors);
  } else {
    errors->AddError("required property missing: height");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Rect::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("x", internal::ToValue(x_));
  result->Set("y", internal::ToValue(y_));
  result->Set("width", internal::ToValue(width_));
  result->Set("height", internal::ToValue(height_));
  return std::move(result);
}

std::unique_ptr<Rect> Rect::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Rect> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CollectClassNamesFromSubtreeParams> CollectClassNamesFromSubtreeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CollectClassNamesFromSubtreeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CollectClassNamesFromSubtreeParams> result(new CollectClassNamesFromSubtreeParams());
  errors->Push();
  errors->SetName("CollectClassNamesFromSubtreeParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CollectClassNamesFromSubtreeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<CollectClassNamesFromSubtreeParams> CollectClassNamesFromSubtreeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CollectClassNamesFromSubtreeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CollectClassNamesFromSubtreeResult> CollectClassNamesFromSubtreeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CollectClassNamesFromSubtreeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CollectClassNamesFromSubtreeResult> result(new CollectClassNamesFromSubtreeResult());
  errors->Push();
  errors->SetName("CollectClassNamesFromSubtreeResult");
  const base::Value* class_names_value = value.FindKey("classNames");
  if (class_names_value) {
    errors->SetName("classNames");
    result->class_names_ = internal::FromValue<std::vector<std::string>>::Parse(*class_names_value, errors);
  } else {
    errors->AddError("required property missing: classNames");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CollectClassNamesFromSubtreeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("classNames", internal::ToValue(class_names_));
  return std::move(result);
}

std::unique_ptr<CollectClassNamesFromSubtreeResult> CollectClassNamesFromSubtreeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CollectClassNamesFromSubtreeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CopyToParams> CopyToParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CopyToParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CopyToParams> result(new CopyToParams());
  errors->Push();
  errors->SetName("CopyToParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* target_node_id_value = value.FindKey("targetNodeId");
  if (target_node_id_value) {
    errors->SetName("targetNodeId");
    result->target_node_id_ = internal::FromValue<int>::Parse(*target_node_id_value, errors);
  } else {
    errors->AddError("required property missing: targetNodeId");
  }
  const base::Value* insert_before_node_id_value = value.FindKey("insertBeforeNodeId");
  if (insert_before_node_id_value) {
    errors->SetName("insertBeforeNodeId");
    result->insert_before_node_id_ = internal::FromValue<int>::Parse(*insert_before_node_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CopyToParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("targetNodeId", internal::ToValue(target_node_id_));
  if (insert_before_node_id_)
    result->Set("insertBeforeNodeId", internal::ToValue(insert_before_node_id_.value()));
  return std::move(result);
}

std::unique_ptr<CopyToParams> CopyToParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CopyToParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CopyToResult> CopyToResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CopyToResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CopyToResult> result(new CopyToResult());
  errors->Push();
  errors->SetName("CopyToResult");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CopyToResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<CopyToResult> CopyToResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CopyToResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DescribeNodeParams> DescribeNodeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DescribeNodeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DescribeNodeParams> result(new DescribeNodeParams());
  errors->Push();
  errors->SetName("DescribeNodeParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  }
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  }
  const base::Value* depth_value = value.FindKey("depth");
  if (depth_value) {
    errors->SetName("depth");
    result->depth_ = internal::FromValue<int>::Parse(*depth_value, errors);
  }
  const base::Value* pierce_value = value.FindKey("pierce");
  if (pierce_value) {
    errors->SetName("pierce");
    result->pierce_ = internal::FromValue<bool>::Parse(*pierce_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DescribeNodeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (node_id_)
    result->Set("nodeId", internal::ToValue(node_id_.value()));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  if (object_id_)
    result->Set("objectId", internal::ToValue(object_id_.value()));
  if (depth_)
    result->Set("depth", internal::ToValue(depth_.value()));
  if (pierce_)
    result->Set("pierce", internal::ToValue(pierce_.value()));
  return std::move(result);
}

std::unique_ptr<DescribeNodeParams> DescribeNodeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DescribeNodeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DescribeNodeResult> DescribeNodeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DescribeNodeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DescribeNodeResult> result(new DescribeNodeResult());
  errors->Push();
  errors->SetName("DescribeNodeResult");
  const base::Value* node_value = value.FindKey("node");
  if (node_value) {
    errors->SetName("node");
    result->node_ = internal::FromValue<::headless::dom::Node>::Parse(*node_value, errors);
  } else {
    errors->AddError("required property missing: node");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DescribeNodeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("node", internal::ToValue(*node_));
  return std::move(result);
}

std::unique_ptr<DescribeNodeResult> DescribeNodeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DescribeNodeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ScrollIntoViewIfNeededParams> ScrollIntoViewIfNeededParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ScrollIntoViewIfNeededParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ScrollIntoViewIfNeededParams> result(new ScrollIntoViewIfNeededParams());
  errors->Push();
  errors->SetName("ScrollIntoViewIfNeededParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  }
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  }
  const base::Value* rect_value = value.FindKey("rect");
  if (rect_value) {
    errors->SetName("rect");
    result->rect_ = internal::FromValue<::headless::dom::Rect>::Parse(*rect_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ScrollIntoViewIfNeededParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (node_id_)
    result->Set("nodeId", internal::ToValue(node_id_.value()));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  if (object_id_)
    result->Set("objectId", internal::ToValue(object_id_.value()));
  if (rect_)
    result->Set("rect", internal::ToValue(*rect_.value()));
  return std::move(result);
}

std::unique_ptr<ScrollIntoViewIfNeededParams> ScrollIntoViewIfNeededParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ScrollIntoViewIfNeededParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ScrollIntoViewIfNeededResult> ScrollIntoViewIfNeededResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ScrollIntoViewIfNeededResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ScrollIntoViewIfNeededResult> result(new ScrollIntoViewIfNeededResult());
  errors->Push();
  errors->SetName("ScrollIntoViewIfNeededResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ScrollIntoViewIfNeededResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ScrollIntoViewIfNeededResult> ScrollIntoViewIfNeededResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ScrollIntoViewIfNeededResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableParams> DisableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableParams> result(new DisableParams());
  errors->Push();
  errors->SetName("DisableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableParams> DisableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableResult> DisableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableResult> result(new DisableResult());
  errors->Push();
  errors->SetName("DisableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableResult> DisableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DiscardSearchResultsParams> DiscardSearchResultsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DiscardSearchResultsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DiscardSearchResultsParams> result(new DiscardSearchResultsParams());
  errors->Push();
  errors->SetName("DiscardSearchResultsParams");
  const base::Value* search_id_value = value.FindKey("searchId");
  if (search_id_value) {
    errors->SetName("searchId");
    result->search_id_ = internal::FromValue<std::string>::Parse(*search_id_value, errors);
  } else {
    errors->AddError("required property missing: searchId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DiscardSearchResultsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("searchId", internal::ToValue(search_id_));
  return std::move(result);
}

std::unique_ptr<DiscardSearchResultsParams> DiscardSearchResultsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DiscardSearchResultsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DiscardSearchResultsResult> DiscardSearchResultsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DiscardSearchResultsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DiscardSearchResultsResult> result(new DiscardSearchResultsResult());
  errors->Push();
  errors->SetName("DiscardSearchResultsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DiscardSearchResultsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DiscardSearchResultsResult> DiscardSearchResultsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DiscardSearchResultsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableParams> EnableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableParams> result(new EnableParams());
  errors->Push();
  errors->SetName("EnableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableParams> EnableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableResult> EnableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableResult> result(new EnableResult());
  errors->Push();
  errors->SetName("EnableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableResult> EnableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FocusParams> FocusParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FocusParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FocusParams> result(new FocusParams());
  errors->Push();
  errors->SetName("FocusParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  }
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FocusParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (node_id_)
    result->Set("nodeId", internal::ToValue(node_id_.value()));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  if (object_id_)
    result->Set("objectId", internal::ToValue(object_id_.value()));
  return std::move(result);
}

std::unique_ptr<FocusParams> FocusParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FocusParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FocusResult> FocusResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FocusResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FocusResult> result(new FocusResult());
  errors->Push();
  errors->SetName("FocusResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FocusResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<FocusResult> FocusResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FocusResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetAttributesParams> GetAttributesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetAttributesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetAttributesParams> result(new GetAttributesParams());
  errors->Push();
  errors->SetName("GetAttributesParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetAttributesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<GetAttributesParams> GetAttributesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetAttributesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetAttributesResult> GetAttributesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetAttributesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetAttributesResult> result(new GetAttributesResult());
  errors->Push();
  errors->SetName("GetAttributesResult");
  const base::Value* attributes_value = value.FindKey("attributes");
  if (attributes_value) {
    errors->SetName("attributes");
    result->attributes_ = internal::FromValue<std::vector<std::string>>::Parse(*attributes_value, errors);
  } else {
    errors->AddError("required property missing: attributes");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetAttributesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("attributes", internal::ToValue(attributes_));
  return std::move(result);
}

std::unique_ptr<GetAttributesResult> GetAttributesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetAttributesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBoxModelParams> GetBoxModelParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBoxModelParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBoxModelParams> result(new GetBoxModelParams());
  errors->Push();
  errors->SetName("GetBoxModelParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  }
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBoxModelParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (node_id_)
    result->Set("nodeId", internal::ToValue(node_id_.value()));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  if (object_id_)
    result->Set("objectId", internal::ToValue(object_id_.value()));
  return std::move(result);
}

std::unique_ptr<GetBoxModelParams> GetBoxModelParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBoxModelParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBoxModelResult> GetBoxModelResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBoxModelResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBoxModelResult> result(new GetBoxModelResult());
  errors->Push();
  errors->SetName("GetBoxModelResult");
  const base::Value* model_value = value.FindKey("model");
  if (model_value) {
    errors->SetName("model");
    result->model_ = internal::FromValue<::headless::dom::BoxModel>::Parse(*model_value, errors);
  } else {
    errors->AddError("required property missing: model");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBoxModelResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("model", internal::ToValue(*model_));
  return std::move(result);
}

std::unique_ptr<GetBoxModelResult> GetBoxModelResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBoxModelResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetContentQuadsParams> GetContentQuadsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetContentQuadsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetContentQuadsParams> result(new GetContentQuadsParams());
  errors->Push();
  errors->SetName("GetContentQuadsParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  }
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetContentQuadsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (node_id_)
    result->Set("nodeId", internal::ToValue(node_id_.value()));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  if (object_id_)
    result->Set("objectId", internal::ToValue(object_id_.value()));
  return std::move(result);
}

std::unique_ptr<GetContentQuadsParams> GetContentQuadsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetContentQuadsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetContentQuadsResult> GetContentQuadsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetContentQuadsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetContentQuadsResult> result(new GetContentQuadsResult());
  errors->Push();
  errors->SetName("GetContentQuadsResult");
  const base::Value* quads_value = value.FindKey("quads");
  if (quads_value) {
    errors->SetName("quads");
    result->quads_ = internal::FromValue<std::vector<std::vector<double>>>::Parse(*quads_value, errors);
  } else {
    errors->AddError("required property missing: quads");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetContentQuadsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("quads", internal::ToValue(quads_));
  return std::move(result);
}

std::unique_ptr<GetContentQuadsResult> GetContentQuadsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetContentQuadsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetDocumentParams> GetDocumentParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetDocumentParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetDocumentParams> result(new GetDocumentParams());
  errors->Push();
  errors->SetName("GetDocumentParams");
  const base::Value* depth_value = value.FindKey("depth");
  if (depth_value) {
    errors->SetName("depth");
    result->depth_ = internal::FromValue<int>::Parse(*depth_value, errors);
  }
  const base::Value* pierce_value = value.FindKey("pierce");
  if (pierce_value) {
    errors->SetName("pierce");
    result->pierce_ = internal::FromValue<bool>::Parse(*pierce_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetDocumentParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (depth_)
    result->Set("depth", internal::ToValue(depth_.value()));
  if (pierce_)
    result->Set("pierce", internal::ToValue(pierce_.value()));
  return std::move(result);
}

std::unique_ptr<GetDocumentParams> GetDocumentParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetDocumentParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetDocumentResult> GetDocumentResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetDocumentResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetDocumentResult> result(new GetDocumentResult());
  errors->Push();
  errors->SetName("GetDocumentResult");
  const base::Value* root_value = value.FindKey("root");
  if (root_value) {
    errors->SetName("root");
    result->root_ = internal::FromValue<::headless::dom::Node>::Parse(*root_value, errors);
  } else {
    errors->AddError("required property missing: root");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetDocumentResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("root", internal::ToValue(*root_));
  return std::move(result);
}

std::unique_ptr<GetDocumentResult> GetDocumentResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetDocumentResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetFlattenedDocumentParams> GetFlattenedDocumentParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetFlattenedDocumentParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetFlattenedDocumentParams> result(new GetFlattenedDocumentParams());
  errors->Push();
  errors->SetName("GetFlattenedDocumentParams");
  const base::Value* depth_value = value.FindKey("depth");
  if (depth_value) {
    errors->SetName("depth");
    result->depth_ = internal::FromValue<int>::Parse(*depth_value, errors);
  }
  const base::Value* pierce_value = value.FindKey("pierce");
  if (pierce_value) {
    errors->SetName("pierce");
    result->pierce_ = internal::FromValue<bool>::Parse(*pierce_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetFlattenedDocumentParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (depth_)
    result->Set("depth", internal::ToValue(depth_.value()));
  if (pierce_)
    result->Set("pierce", internal::ToValue(pierce_.value()));
  return std::move(result);
}

std::unique_ptr<GetFlattenedDocumentParams> GetFlattenedDocumentParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetFlattenedDocumentParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetFlattenedDocumentResult> GetFlattenedDocumentResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetFlattenedDocumentResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetFlattenedDocumentResult> result(new GetFlattenedDocumentResult());
  errors->Push();
  errors->SetName("GetFlattenedDocumentResult");
  const base::Value* nodes_value = value.FindKey("nodes");
  if (nodes_value) {
    errors->SetName("nodes");
    result->nodes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom::Node>>>::Parse(*nodes_value, errors);
  } else {
    errors->AddError("required property missing: nodes");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetFlattenedDocumentResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodes", internal::ToValue(nodes_));
  return std::move(result);
}

std::unique_ptr<GetFlattenedDocumentResult> GetFlattenedDocumentResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetFlattenedDocumentResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetNodeForLocationParams> GetNodeForLocationParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetNodeForLocationParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetNodeForLocationParams> result(new GetNodeForLocationParams());
  errors->Push();
  errors->SetName("GetNodeForLocationParams");
  const base::Value* x_value = value.FindKey("x");
  if (x_value) {
    errors->SetName("x");
    result->x_ = internal::FromValue<int>::Parse(*x_value, errors);
  } else {
    errors->AddError("required property missing: x");
  }
  const base::Value* y_value = value.FindKey("y");
  if (y_value) {
    errors->SetName("y");
    result->y_ = internal::FromValue<int>::Parse(*y_value, errors);
  } else {
    errors->AddError("required property missing: y");
  }
  const base::Value* include_user_agent_shadowdom_value = value.FindKey("includeUserAgentShadowDOM");
  if (include_user_agent_shadowdom_value) {
    errors->SetName("includeUserAgentShadowDOM");
    result->include_user_agent_shadowdom_ = internal::FromValue<bool>::Parse(*include_user_agent_shadowdom_value, errors);
  }
  const base::Value* ignore_pointer_events_none_value = value.FindKey("ignorePointerEventsNone");
  if (ignore_pointer_events_none_value) {
    errors->SetName("ignorePointerEventsNone");
    result->ignore_pointer_events_none_ = internal::FromValue<bool>::Parse(*ignore_pointer_events_none_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetNodeForLocationParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("x", internal::ToValue(x_));
  result->Set("y", internal::ToValue(y_));
  if (include_user_agent_shadowdom_)
    result->Set("includeUserAgentShadowDOM", internal::ToValue(include_user_agent_shadowdom_.value()));
  if (ignore_pointer_events_none_)
    result->Set("ignorePointerEventsNone", internal::ToValue(ignore_pointer_events_none_.value()));
  return std::move(result);
}

std::unique_ptr<GetNodeForLocationParams> GetNodeForLocationParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetNodeForLocationParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetNodeForLocationResult> GetNodeForLocationResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetNodeForLocationResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetNodeForLocationResult> result(new GetNodeForLocationResult());
  errors->Push();
  errors->SetName("GetNodeForLocationResult");
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  } else {
    errors->AddError("required property missing: backendNodeId");
  }
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetNodeForLocationResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("backendNodeId", internal::ToValue(backend_node_id_));
  result->Set("frameId", internal::ToValue(frame_id_));
  if (node_id_)
    result->Set("nodeId", internal::ToValue(node_id_.value()));
  return std::move(result);
}

std::unique_ptr<GetNodeForLocationResult> GetNodeForLocationResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetNodeForLocationResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetOuterHTMLParams> GetOuterHTMLParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetOuterHTMLParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetOuterHTMLParams> result(new GetOuterHTMLParams());
  errors->Push();
  errors->SetName("GetOuterHTMLParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  }
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetOuterHTMLParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (node_id_)
    result->Set("nodeId", internal::ToValue(node_id_.value()));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  if (object_id_)
    result->Set("objectId", internal::ToValue(object_id_.value()));
  return std::move(result);
}

std::unique_ptr<GetOuterHTMLParams> GetOuterHTMLParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetOuterHTMLParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetOuterHTMLResult> GetOuterHTMLResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetOuterHTMLResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetOuterHTMLResult> result(new GetOuterHTMLResult());
  errors->Push();
  errors->SetName("GetOuterHTMLResult");
  const base::Value* outerhtml_value = value.FindKey("outerHTML");
  if (outerhtml_value) {
    errors->SetName("outerHTML");
    result->outerhtml_ = internal::FromValue<std::string>::Parse(*outerhtml_value, errors);
  } else {
    errors->AddError("required property missing: outerHTML");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetOuterHTMLResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("outerHTML", internal::ToValue(outerhtml_));
  return std::move(result);
}

std::unique_ptr<GetOuterHTMLResult> GetOuterHTMLResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetOuterHTMLResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetRelayoutBoundaryParams> GetRelayoutBoundaryParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetRelayoutBoundaryParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetRelayoutBoundaryParams> result(new GetRelayoutBoundaryParams());
  errors->Push();
  errors->SetName("GetRelayoutBoundaryParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetRelayoutBoundaryParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<GetRelayoutBoundaryParams> GetRelayoutBoundaryParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetRelayoutBoundaryParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetRelayoutBoundaryResult> GetRelayoutBoundaryResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetRelayoutBoundaryResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetRelayoutBoundaryResult> result(new GetRelayoutBoundaryResult());
  errors->Push();
  errors->SetName("GetRelayoutBoundaryResult");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetRelayoutBoundaryResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<GetRelayoutBoundaryResult> GetRelayoutBoundaryResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetRelayoutBoundaryResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetSearchResultsParams> GetSearchResultsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetSearchResultsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetSearchResultsParams> result(new GetSearchResultsParams());
  errors->Push();
  errors->SetName("GetSearchResultsParams");
  const base::Value* search_id_value = value.FindKey("searchId");
  if (search_id_value) {
    errors->SetName("searchId");
    result->search_id_ = internal::FromValue<std::string>::Parse(*search_id_value, errors);
  } else {
    errors->AddError("required property missing: searchId");
  }
  const base::Value* from_index_value = value.FindKey("fromIndex");
  if (from_index_value) {
    errors->SetName("fromIndex");
    result->from_index_ = internal::FromValue<int>::Parse(*from_index_value, errors);
  } else {
    errors->AddError("required property missing: fromIndex");
  }
  const base::Value* to_index_value = value.FindKey("toIndex");
  if (to_index_value) {
    errors->SetName("toIndex");
    result->to_index_ = internal::FromValue<int>::Parse(*to_index_value, errors);
  } else {
    errors->AddError("required property missing: toIndex");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetSearchResultsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("searchId", internal::ToValue(search_id_));
  result->Set("fromIndex", internal::ToValue(from_index_));
  result->Set("toIndex", internal::ToValue(to_index_));
  return std::move(result);
}

std::unique_ptr<GetSearchResultsParams> GetSearchResultsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetSearchResultsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetSearchResultsResult> GetSearchResultsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetSearchResultsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetSearchResultsResult> result(new GetSearchResultsResult());
  errors->Push();
  errors->SetName("GetSearchResultsResult");
  const base::Value* node_ids_value = value.FindKey("nodeIds");
  if (node_ids_value) {
    errors->SetName("nodeIds");
    result->node_ids_ = internal::FromValue<std::vector<int>>::Parse(*node_ids_value, errors);
  } else {
    errors->AddError("required property missing: nodeIds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetSearchResultsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeIds", internal::ToValue(node_ids_));
  return std::move(result);
}

std::unique_ptr<GetSearchResultsResult> GetSearchResultsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetSearchResultsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HideHighlightParams> HideHighlightParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HideHighlightParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HideHighlightParams> result(new HideHighlightParams());
  errors->Push();
  errors->SetName("HideHighlightParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HideHighlightParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<HideHighlightParams> HideHighlightParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HideHighlightParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HideHighlightResult> HideHighlightResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HideHighlightResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HideHighlightResult> result(new HideHighlightResult());
  errors->Push();
  errors->SetName("HideHighlightResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HideHighlightResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<HideHighlightResult> HideHighlightResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HideHighlightResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HighlightNodeParams> HighlightNodeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HighlightNodeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HighlightNodeParams> result(new HighlightNodeParams());
  errors->Push();
  errors->SetName("HighlightNodeParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HighlightNodeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<HighlightNodeParams> HighlightNodeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HighlightNodeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HighlightNodeResult> HighlightNodeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HighlightNodeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HighlightNodeResult> result(new HighlightNodeResult());
  errors->Push();
  errors->SetName("HighlightNodeResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HighlightNodeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<HighlightNodeResult> HighlightNodeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HighlightNodeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HighlightRectParams> HighlightRectParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HighlightRectParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HighlightRectParams> result(new HighlightRectParams());
  errors->Push();
  errors->SetName("HighlightRectParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HighlightRectParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<HighlightRectParams> HighlightRectParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HighlightRectParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HighlightRectResult> HighlightRectResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HighlightRectResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HighlightRectResult> result(new HighlightRectResult());
  errors->Push();
  errors->SetName("HighlightRectResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HighlightRectResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<HighlightRectResult> HighlightRectResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HighlightRectResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<MarkUndoableStateParams> MarkUndoableStateParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("MarkUndoableStateParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<MarkUndoableStateParams> result(new MarkUndoableStateParams());
  errors->Push();
  errors->SetName("MarkUndoableStateParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> MarkUndoableStateParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<MarkUndoableStateParams> MarkUndoableStateParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<MarkUndoableStateParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<MarkUndoableStateResult> MarkUndoableStateResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("MarkUndoableStateResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<MarkUndoableStateResult> result(new MarkUndoableStateResult());
  errors->Push();
  errors->SetName("MarkUndoableStateResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> MarkUndoableStateResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<MarkUndoableStateResult> MarkUndoableStateResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<MarkUndoableStateResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<MoveToParams> MoveToParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("MoveToParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<MoveToParams> result(new MoveToParams());
  errors->Push();
  errors->SetName("MoveToParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* target_node_id_value = value.FindKey("targetNodeId");
  if (target_node_id_value) {
    errors->SetName("targetNodeId");
    result->target_node_id_ = internal::FromValue<int>::Parse(*target_node_id_value, errors);
  } else {
    errors->AddError("required property missing: targetNodeId");
  }
  const base::Value* insert_before_node_id_value = value.FindKey("insertBeforeNodeId");
  if (insert_before_node_id_value) {
    errors->SetName("insertBeforeNodeId");
    result->insert_before_node_id_ = internal::FromValue<int>::Parse(*insert_before_node_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> MoveToParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("targetNodeId", internal::ToValue(target_node_id_));
  if (insert_before_node_id_)
    result->Set("insertBeforeNodeId", internal::ToValue(insert_before_node_id_.value()));
  return std::move(result);
}

std::unique_ptr<MoveToParams> MoveToParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<MoveToParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<MoveToResult> MoveToResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("MoveToResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<MoveToResult> result(new MoveToResult());
  errors->Push();
  errors->SetName("MoveToResult");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> MoveToResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<MoveToResult> MoveToResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<MoveToResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PerformSearchParams> PerformSearchParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PerformSearchParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PerformSearchParams> result(new PerformSearchParams());
  errors->Push();
  errors->SetName("PerformSearchParams");
  const base::Value* query_value = value.FindKey("query");
  if (query_value) {
    errors->SetName("query");
    result->query_ = internal::FromValue<std::string>::Parse(*query_value, errors);
  } else {
    errors->AddError("required property missing: query");
  }
  const base::Value* include_user_agent_shadowdom_value = value.FindKey("includeUserAgentShadowDOM");
  if (include_user_agent_shadowdom_value) {
    errors->SetName("includeUserAgentShadowDOM");
    result->include_user_agent_shadowdom_ = internal::FromValue<bool>::Parse(*include_user_agent_shadowdom_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PerformSearchParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("query", internal::ToValue(query_));
  if (include_user_agent_shadowdom_)
    result->Set("includeUserAgentShadowDOM", internal::ToValue(include_user_agent_shadowdom_.value()));
  return std::move(result);
}

std::unique_ptr<PerformSearchParams> PerformSearchParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PerformSearchParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PerformSearchResult> PerformSearchResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PerformSearchResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PerformSearchResult> result(new PerformSearchResult());
  errors->Push();
  errors->SetName("PerformSearchResult");
  const base::Value* search_id_value = value.FindKey("searchId");
  if (search_id_value) {
    errors->SetName("searchId");
    result->search_id_ = internal::FromValue<std::string>::Parse(*search_id_value, errors);
  } else {
    errors->AddError("required property missing: searchId");
  }
  const base::Value* result_count_value = value.FindKey("resultCount");
  if (result_count_value) {
    errors->SetName("resultCount");
    result->result_count_ = internal::FromValue<int>::Parse(*result_count_value, errors);
  } else {
    errors->AddError("required property missing: resultCount");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PerformSearchResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("searchId", internal::ToValue(search_id_));
  result->Set("resultCount", internal::ToValue(result_count_));
  return std::move(result);
}

std::unique_ptr<PerformSearchResult> PerformSearchResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PerformSearchResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PushNodeByPathToFrontendParams> PushNodeByPathToFrontendParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PushNodeByPathToFrontendParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PushNodeByPathToFrontendParams> result(new PushNodeByPathToFrontendParams());
  errors->Push();
  errors->SetName("PushNodeByPathToFrontendParams");
  const base::Value* path_value = value.FindKey("path");
  if (path_value) {
    errors->SetName("path");
    result->path_ = internal::FromValue<std::string>::Parse(*path_value, errors);
  } else {
    errors->AddError("required property missing: path");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PushNodeByPathToFrontendParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("path", internal::ToValue(path_));
  return std::move(result);
}

std::unique_ptr<PushNodeByPathToFrontendParams> PushNodeByPathToFrontendParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PushNodeByPathToFrontendParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PushNodeByPathToFrontendResult> PushNodeByPathToFrontendResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PushNodeByPathToFrontendResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PushNodeByPathToFrontendResult> result(new PushNodeByPathToFrontendResult());
  errors->Push();
  errors->SetName("PushNodeByPathToFrontendResult");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PushNodeByPathToFrontendResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<PushNodeByPathToFrontendResult> PushNodeByPathToFrontendResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PushNodeByPathToFrontendResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PushNodesByBackendIdsToFrontendParams> PushNodesByBackendIdsToFrontendParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PushNodesByBackendIdsToFrontendParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PushNodesByBackendIdsToFrontendParams> result(new PushNodesByBackendIdsToFrontendParams());
  errors->Push();
  errors->SetName("PushNodesByBackendIdsToFrontendParams");
  const base::Value* backend_node_ids_value = value.FindKey("backendNodeIds");
  if (backend_node_ids_value) {
    errors->SetName("backendNodeIds");
    result->backend_node_ids_ = internal::FromValue<std::vector<int>>::Parse(*backend_node_ids_value, errors);
  } else {
    errors->AddError("required property missing: backendNodeIds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PushNodesByBackendIdsToFrontendParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("backendNodeIds", internal::ToValue(backend_node_ids_));
  return std::move(result);
}

std::unique_ptr<PushNodesByBackendIdsToFrontendParams> PushNodesByBackendIdsToFrontendParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PushNodesByBackendIdsToFrontendParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PushNodesByBackendIdsToFrontendResult> PushNodesByBackendIdsToFrontendResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PushNodesByBackendIdsToFrontendResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PushNodesByBackendIdsToFrontendResult> result(new PushNodesByBackendIdsToFrontendResult());
  errors->Push();
  errors->SetName("PushNodesByBackendIdsToFrontendResult");
  const base::Value* node_ids_value = value.FindKey("nodeIds");
  if (node_ids_value) {
    errors->SetName("nodeIds");
    result->node_ids_ = internal::FromValue<std::vector<int>>::Parse(*node_ids_value, errors);
  } else {
    errors->AddError("required property missing: nodeIds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PushNodesByBackendIdsToFrontendResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeIds", internal::ToValue(node_ids_));
  return std::move(result);
}

std::unique_ptr<PushNodesByBackendIdsToFrontendResult> PushNodesByBackendIdsToFrontendResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PushNodesByBackendIdsToFrontendResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<QuerySelectorParams> QuerySelectorParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("QuerySelectorParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<QuerySelectorParams> result(new QuerySelectorParams());
  errors->Push();
  errors->SetName("QuerySelectorParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* selector_value = value.FindKey("selector");
  if (selector_value) {
    errors->SetName("selector");
    result->selector_ = internal::FromValue<std::string>::Parse(*selector_value, errors);
  } else {
    errors->AddError("required property missing: selector");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> QuerySelectorParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("selector", internal::ToValue(selector_));
  return std::move(result);
}

std::unique_ptr<QuerySelectorParams> QuerySelectorParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<QuerySelectorParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<QuerySelectorResult> QuerySelectorResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("QuerySelectorResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<QuerySelectorResult> result(new QuerySelectorResult());
  errors->Push();
  errors->SetName("QuerySelectorResult");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> QuerySelectorResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<QuerySelectorResult> QuerySelectorResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<QuerySelectorResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<QuerySelectorAllParams> QuerySelectorAllParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("QuerySelectorAllParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<QuerySelectorAllParams> result(new QuerySelectorAllParams());
  errors->Push();
  errors->SetName("QuerySelectorAllParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* selector_value = value.FindKey("selector");
  if (selector_value) {
    errors->SetName("selector");
    result->selector_ = internal::FromValue<std::string>::Parse(*selector_value, errors);
  } else {
    errors->AddError("required property missing: selector");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> QuerySelectorAllParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("selector", internal::ToValue(selector_));
  return std::move(result);
}

std::unique_ptr<QuerySelectorAllParams> QuerySelectorAllParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<QuerySelectorAllParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<QuerySelectorAllResult> QuerySelectorAllResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("QuerySelectorAllResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<QuerySelectorAllResult> result(new QuerySelectorAllResult());
  errors->Push();
  errors->SetName("QuerySelectorAllResult");
  const base::Value* node_ids_value = value.FindKey("nodeIds");
  if (node_ids_value) {
    errors->SetName("nodeIds");
    result->node_ids_ = internal::FromValue<std::vector<int>>::Parse(*node_ids_value, errors);
  } else {
    errors->AddError("required property missing: nodeIds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> QuerySelectorAllResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeIds", internal::ToValue(node_ids_));
  return std::move(result);
}

std::unique_ptr<QuerySelectorAllResult> QuerySelectorAllResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<QuerySelectorAllResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RedoParams> RedoParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RedoParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RedoParams> result(new RedoParams());
  errors->Push();
  errors->SetName("RedoParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RedoParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RedoParams> RedoParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RedoParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RedoResult> RedoResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RedoResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RedoResult> result(new RedoResult());
  errors->Push();
  errors->SetName("RedoResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RedoResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RedoResult> RedoResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RedoResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveAttributeParams> RemoveAttributeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveAttributeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveAttributeParams> result(new RemoveAttributeParams());
  errors->Push();
  errors->SetName("RemoveAttributeParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveAttributeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("name", internal::ToValue(name_));
  return std::move(result);
}

std::unique_ptr<RemoveAttributeParams> RemoveAttributeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveAttributeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveAttributeResult> RemoveAttributeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveAttributeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveAttributeResult> result(new RemoveAttributeResult());
  errors->Push();
  errors->SetName("RemoveAttributeResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveAttributeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveAttributeResult> RemoveAttributeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveAttributeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveNodeParams> RemoveNodeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveNodeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveNodeParams> result(new RemoveNodeParams());
  errors->Push();
  errors->SetName("RemoveNodeParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveNodeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<RemoveNodeParams> RemoveNodeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveNodeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveNodeResult> RemoveNodeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveNodeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveNodeResult> result(new RemoveNodeResult());
  errors->Push();
  errors->SetName("RemoveNodeResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveNodeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveNodeResult> RemoveNodeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveNodeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestChildNodesParams> RequestChildNodesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestChildNodesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestChildNodesParams> result(new RequestChildNodesParams());
  errors->Push();
  errors->SetName("RequestChildNodesParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* depth_value = value.FindKey("depth");
  if (depth_value) {
    errors->SetName("depth");
    result->depth_ = internal::FromValue<int>::Parse(*depth_value, errors);
  }
  const base::Value* pierce_value = value.FindKey("pierce");
  if (pierce_value) {
    errors->SetName("pierce");
    result->pierce_ = internal::FromValue<bool>::Parse(*pierce_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestChildNodesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  if (depth_)
    result->Set("depth", internal::ToValue(depth_.value()));
  if (pierce_)
    result->Set("pierce", internal::ToValue(pierce_.value()));
  return std::move(result);
}

std::unique_ptr<RequestChildNodesParams> RequestChildNodesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestChildNodesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestChildNodesResult> RequestChildNodesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestChildNodesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestChildNodesResult> result(new RequestChildNodesResult());
  errors->Push();
  errors->SetName("RequestChildNodesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestChildNodesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RequestChildNodesResult> RequestChildNodesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestChildNodesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestNodeParams> RequestNodeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestNodeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestNodeParams> result(new RequestNodeParams());
  errors->Push();
  errors->SetName("RequestNodeParams");
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  } else {
    errors->AddError("required property missing: objectId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestNodeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("objectId", internal::ToValue(object_id_));
  return std::move(result);
}

std::unique_ptr<RequestNodeParams> RequestNodeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestNodeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestNodeResult> RequestNodeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestNodeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestNodeResult> result(new RequestNodeResult());
  errors->Push();
  errors->SetName("RequestNodeResult");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestNodeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<RequestNodeResult> RequestNodeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestNodeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResolveNodeParams> ResolveNodeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResolveNodeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResolveNodeParams> result(new ResolveNodeParams());
  errors->Push();
  errors->SetName("ResolveNodeParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  }
  const base::Value* object_group_value = value.FindKey("objectGroup");
  if (object_group_value) {
    errors->SetName("objectGroup");
    result->object_group_ = internal::FromValue<std::string>::Parse(*object_group_value, errors);
  }
  const base::Value* execution_context_id_value = value.FindKey("executionContextId");
  if (execution_context_id_value) {
    errors->SetName("executionContextId");
    result->execution_context_id_ = internal::FromValue<int>::Parse(*execution_context_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResolveNodeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (node_id_)
    result->Set("nodeId", internal::ToValue(node_id_.value()));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  if (object_group_)
    result->Set("objectGroup", internal::ToValue(object_group_.value()));
  if (execution_context_id_)
    result->Set("executionContextId", internal::ToValue(execution_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<ResolveNodeParams> ResolveNodeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResolveNodeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResolveNodeResult> ResolveNodeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResolveNodeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResolveNodeResult> result(new ResolveNodeResult());
  errors->Push();
  errors->SetName("ResolveNodeResult");
  const base::Value* object_value = value.FindKey("object");
  if (object_value) {
    errors->SetName("object");
    result->object_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*object_value, errors);
  } else {
    errors->AddError("required property missing: object");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResolveNodeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("object", internal::ToValue(*object_));
  return std::move(result);
}

std::unique_ptr<ResolveNodeResult> ResolveNodeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResolveNodeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetAttributeValueParams> SetAttributeValueParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetAttributeValueParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetAttributeValueParams> result(new SetAttributeValueParams());
  errors->Push();
  errors->SetName("SetAttributeValueParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetAttributeValueParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<SetAttributeValueParams> SetAttributeValueParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetAttributeValueParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetAttributeValueResult> SetAttributeValueResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetAttributeValueResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetAttributeValueResult> result(new SetAttributeValueResult());
  errors->Push();
  errors->SetName("SetAttributeValueResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetAttributeValueResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetAttributeValueResult> SetAttributeValueResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetAttributeValueResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetAttributesAsTextParams> SetAttributesAsTextParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetAttributesAsTextParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetAttributesAsTextParams> result(new SetAttributesAsTextParams());
  errors->Push();
  errors->SetName("SetAttributesAsTextParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetAttributesAsTextParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("text", internal::ToValue(text_));
  if (name_)
    result->Set("name", internal::ToValue(name_.value()));
  return std::move(result);
}

std::unique_ptr<SetAttributesAsTextParams> SetAttributesAsTextParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetAttributesAsTextParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetAttributesAsTextResult> SetAttributesAsTextResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetAttributesAsTextResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetAttributesAsTextResult> result(new SetAttributesAsTextResult());
  errors->Push();
  errors->SetName("SetAttributesAsTextResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetAttributesAsTextResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetAttributesAsTextResult> SetAttributesAsTextResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetAttributesAsTextResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetFileInputFilesParams> SetFileInputFilesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetFileInputFilesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetFileInputFilesParams> result(new SetFileInputFilesParams());
  errors->Push();
  errors->SetName("SetFileInputFilesParams");
  const base::Value* files_value = value.FindKey("files");
  if (files_value) {
    errors->SetName("files");
    result->files_ = internal::FromValue<std::vector<std::string>>::Parse(*files_value, errors);
  } else {
    errors->AddError("required property missing: files");
  }
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  }
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetFileInputFilesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("files", internal::ToValue(files_));
  if (node_id_)
    result->Set("nodeId", internal::ToValue(node_id_.value()));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  if (object_id_)
    result->Set("objectId", internal::ToValue(object_id_.value()));
  return std::move(result);
}

std::unique_ptr<SetFileInputFilesParams> SetFileInputFilesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetFileInputFilesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetFileInputFilesResult> SetFileInputFilesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetFileInputFilesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetFileInputFilesResult> result(new SetFileInputFilesResult());
  errors->Push();
  errors->SetName("SetFileInputFilesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetFileInputFilesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetFileInputFilesResult> SetFileInputFilesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetFileInputFilesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetNodeStackTracesEnabledParams> SetNodeStackTracesEnabledParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetNodeStackTracesEnabledParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetNodeStackTracesEnabledParams> result(new SetNodeStackTracesEnabledParams());
  errors->Push();
  errors->SetName("SetNodeStackTracesEnabledParams");
  const base::Value* enable_value = value.FindKey("enable");
  if (enable_value) {
    errors->SetName("enable");
    result->enable_ = internal::FromValue<bool>::Parse(*enable_value, errors);
  } else {
    errors->AddError("required property missing: enable");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetNodeStackTracesEnabledParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("enable", internal::ToValue(enable_));
  return std::move(result);
}

std::unique_ptr<SetNodeStackTracesEnabledParams> SetNodeStackTracesEnabledParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetNodeStackTracesEnabledParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetNodeStackTracesEnabledResult> SetNodeStackTracesEnabledResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetNodeStackTracesEnabledResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetNodeStackTracesEnabledResult> result(new SetNodeStackTracesEnabledResult());
  errors->Push();
  errors->SetName("SetNodeStackTracesEnabledResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetNodeStackTracesEnabledResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetNodeStackTracesEnabledResult> SetNodeStackTracesEnabledResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetNodeStackTracesEnabledResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetNodeStackTracesParams> GetNodeStackTracesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetNodeStackTracesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetNodeStackTracesParams> result(new GetNodeStackTracesParams());
  errors->Push();
  errors->SetName("GetNodeStackTracesParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetNodeStackTracesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<GetNodeStackTracesParams> GetNodeStackTracesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetNodeStackTracesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetNodeStackTracesResult> GetNodeStackTracesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetNodeStackTracesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetNodeStackTracesResult> result(new GetNodeStackTracesResult());
  errors->Push();
  errors->SetName("GetNodeStackTracesResult");
  const base::Value* creation_value = value.FindKey("creation");
  if (creation_value) {
    errors->SetName("creation");
    result->creation_ = internal::FromValue<::headless::runtime::StackTrace>::Parse(*creation_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetNodeStackTracesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (creation_)
    result->Set("creation", internal::ToValue(*creation_.value()));
  return std::move(result);
}

std::unique_ptr<GetNodeStackTracesResult> GetNodeStackTracesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetNodeStackTracesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetFileInfoParams> GetFileInfoParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetFileInfoParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetFileInfoParams> result(new GetFileInfoParams());
  errors->Push();
  errors->SetName("GetFileInfoParams");
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  } else {
    errors->AddError("required property missing: objectId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetFileInfoParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("objectId", internal::ToValue(object_id_));
  return std::move(result);
}

std::unique_ptr<GetFileInfoParams> GetFileInfoParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetFileInfoParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetFileInfoResult> GetFileInfoResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetFileInfoResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetFileInfoResult> result(new GetFileInfoResult());
  errors->Push();
  errors->SetName("GetFileInfoResult");
  const base::Value* path_value = value.FindKey("path");
  if (path_value) {
    errors->SetName("path");
    result->path_ = internal::FromValue<std::string>::Parse(*path_value, errors);
  } else {
    errors->AddError("required property missing: path");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetFileInfoResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("path", internal::ToValue(path_));
  return std::move(result);
}

std::unique_ptr<GetFileInfoResult> GetFileInfoResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetFileInfoResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetInspectedNodeParams> SetInspectedNodeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetInspectedNodeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetInspectedNodeParams> result(new SetInspectedNodeParams());
  errors->Push();
  errors->SetName("SetInspectedNodeParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetInspectedNodeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<SetInspectedNodeParams> SetInspectedNodeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetInspectedNodeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetInspectedNodeResult> SetInspectedNodeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetInspectedNodeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetInspectedNodeResult> result(new SetInspectedNodeResult());
  errors->Push();
  errors->SetName("SetInspectedNodeResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetInspectedNodeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetInspectedNodeResult> SetInspectedNodeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetInspectedNodeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetNodeNameParams> SetNodeNameParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetNodeNameParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetNodeNameParams> result(new SetNodeNameParams());
  errors->Push();
  errors->SetName("SetNodeNameParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetNodeNameParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("name", internal::ToValue(name_));
  return std::move(result);
}

std::unique_ptr<SetNodeNameParams> SetNodeNameParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetNodeNameParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetNodeNameResult> SetNodeNameResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetNodeNameResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetNodeNameResult> result(new SetNodeNameResult());
  errors->Push();
  errors->SetName("SetNodeNameResult");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetNodeNameResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<SetNodeNameResult> SetNodeNameResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetNodeNameResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetNodeValueParams> SetNodeValueParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetNodeValueParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetNodeValueParams> result(new SetNodeValueParams());
  errors->Push();
  errors->SetName("SetNodeValueParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetNodeValueParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<SetNodeValueParams> SetNodeValueParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetNodeValueParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetNodeValueResult> SetNodeValueResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetNodeValueResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetNodeValueResult> result(new SetNodeValueResult());
  errors->Push();
  errors->SetName("SetNodeValueResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetNodeValueResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetNodeValueResult> SetNodeValueResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetNodeValueResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetOuterHTMLParams> SetOuterHTMLParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetOuterHTMLParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetOuterHTMLParams> result(new SetOuterHTMLParams());
  errors->Push();
  errors->SetName("SetOuterHTMLParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* outerhtml_value = value.FindKey("outerHTML");
  if (outerhtml_value) {
    errors->SetName("outerHTML");
    result->outerhtml_ = internal::FromValue<std::string>::Parse(*outerhtml_value, errors);
  } else {
    errors->AddError("required property missing: outerHTML");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetOuterHTMLParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("outerHTML", internal::ToValue(outerhtml_));
  return std::move(result);
}

std::unique_ptr<SetOuterHTMLParams> SetOuterHTMLParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetOuterHTMLParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetOuterHTMLResult> SetOuterHTMLResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetOuterHTMLResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetOuterHTMLResult> result(new SetOuterHTMLResult());
  errors->Push();
  errors->SetName("SetOuterHTMLResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetOuterHTMLResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetOuterHTMLResult> SetOuterHTMLResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetOuterHTMLResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<UndoParams> UndoParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("UndoParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<UndoParams> result(new UndoParams());
  errors->Push();
  errors->SetName("UndoParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> UndoParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<UndoParams> UndoParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<UndoParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<UndoResult> UndoResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("UndoResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<UndoResult> result(new UndoResult());
  errors->Push();
  errors->SetName("UndoResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> UndoResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<UndoResult> UndoResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<UndoResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetFrameOwnerParams> GetFrameOwnerParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetFrameOwnerParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetFrameOwnerParams> result(new GetFrameOwnerParams());
  errors->Push();
  errors->SetName("GetFrameOwnerParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetFrameOwnerParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  return std::move(result);
}

std::unique_ptr<GetFrameOwnerParams> GetFrameOwnerParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetFrameOwnerParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetFrameOwnerResult> GetFrameOwnerResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetFrameOwnerResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetFrameOwnerResult> result(new GetFrameOwnerResult());
  errors->Push();
  errors->SetName("GetFrameOwnerResult");
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  } else {
    errors->AddError("required property missing: backendNodeId");
  }
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetFrameOwnerResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("backendNodeId", internal::ToValue(backend_node_id_));
  if (node_id_)
    result->Set("nodeId", internal::ToValue(node_id_.value()));
  return std::move(result);
}

std::unique_ptr<GetFrameOwnerResult> GetFrameOwnerResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetFrameOwnerResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AttributeModifiedParams> AttributeModifiedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AttributeModifiedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AttributeModifiedParams> result(new AttributeModifiedParams());
  errors->Push();
  errors->SetName("AttributeModifiedParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AttributeModifiedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<AttributeModifiedParams> AttributeModifiedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AttributeModifiedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AttributeRemovedParams> AttributeRemovedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AttributeRemovedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AttributeRemovedParams> result(new AttributeRemovedParams());
  errors->Push();
  errors->SetName("AttributeRemovedParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AttributeRemovedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("name", internal::ToValue(name_));
  return std::move(result);
}

std::unique_ptr<AttributeRemovedParams> AttributeRemovedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AttributeRemovedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CharacterDataModifiedParams> CharacterDataModifiedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CharacterDataModifiedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CharacterDataModifiedParams> result(new CharacterDataModifiedParams());
  errors->Push();
  errors->SetName("CharacterDataModifiedParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* character_data_value = value.FindKey("characterData");
  if (character_data_value) {
    errors->SetName("characterData");
    result->character_data_ = internal::FromValue<std::string>::Parse(*character_data_value, errors);
  } else {
    errors->AddError("required property missing: characterData");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CharacterDataModifiedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("characterData", internal::ToValue(character_data_));
  return std::move(result);
}

std::unique_ptr<CharacterDataModifiedParams> CharacterDataModifiedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CharacterDataModifiedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ChildNodeCountUpdatedParams> ChildNodeCountUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ChildNodeCountUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ChildNodeCountUpdatedParams> result(new ChildNodeCountUpdatedParams());
  errors->Push();
  errors->SetName("ChildNodeCountUpdatedParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* child_node_count_value = value.FindKey("childNodeCount");
  if (child_node_count_value) {
    errors->SetName("childNodeCount");
    result->child_node_count_ = internal::FromValue<int>::Parse(*child_node_count_value, errors);
  } else {
    errors->AddError("required property missing: childNodeCount");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ChildNodeCountUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("childNodeCount", internal::ToValue(child_node_count_));
  return std::move(result);
}

std::unique_ptr<ChildNodeCountUpdatedParams> ChildNodeCountUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ChildNodeCountUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ChildNodeInsertedParams> ChildNodeInsertedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ChildNodeInsertedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ChildNodeInsertedParams> result(new ChildNodeInsertedParams());
  errors->Push();
  errors->SetName("ChildNodeInsertedParams");
  const base::Value* parent_node_id_value = value.FindKey("parentNodeId");
  if (parent_node_id_value) {
    errors->SetName("parentNodeId");
    result->parent_node_id_ = internal::FromValue<int>::Parse(*parent_node_id_value, errors);
  } else {
    errors->AddError("required property missing: parentNodeId");
  }
  const base::Value* previous_node_id_value = value.FindKey("previousNodeId");
  if (previous_node_id_value) {
    errors->SetName("previousNodeId");
    result->previous_node_id_ = internal::FromValue<int>::Parse(*previous_node_id_value, errors);
  } else {
    errors->AddError("required property missing: previousNodeId");
  }
  const base::Value* node_value = value.FindKey("node");
  if (node_value) {
    errors->SetName("node");
    result->node_ = internal::FromValue<::headless::dom::Node>::Parse(*node_value, errors);
  } else {
    errors->AddError("required property missing: node");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ChildNodeInsertedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("parentNodeId", internal::ToValue(parent_node_id_));
  result->Set("previousNodeId", internal::ToValue(previous_node_id_));
  result->Set("node", internal::ToValue(*node_));
  return std::move(result);
}

std::unique_ptr<ChildNodeInsertedParams> ChildNodeInsertedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ChildNodeInsertedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ChildNodeRemovedParams> ChildNodeRemovedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ChildNodeRemovedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ChildNodeRemovedParams> result(new ChildNodeRemovedParams());
  errors->Push();
  errors->SetName("ChildNodeRemovedParams");
  const base::Value* parent_node_id_value = value.FindKey("parentNodeId");
  if (parent_node_id_value) {
    errors->SetName("parentNodeId");
    result->parent_node_id_ = internal::FromValue<int>::Parse(*parent_node_id_value, errors);
  } else {
    errors->AddError("required property missing: parentNodeId");
  }
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ChildNodeRemovedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("parentNodeId", internal::ToValue(parent_node_id_));
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<ChildNodeRemovedParams> ChildNodeRemovedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ChildNodeRemovedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DistributedNodesUpdatedParams> DistributedNodesUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DistributedNodesUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DistributedNodesUpdatedParams> result(new DistributedNodesUpdatedParams());
  errors->Push();
  errors->SetName("DistributedNodesUpdatedParams");
  const base::Value* insertion_point_id_value = value.FindKey("insertionPointId");
  if (insertion_point_id_value) {
    errors->SetName("insertionPointId");
    result->insertion_point_id_ = internal::FromValue<int>::Parse(*insertion_point_id_value, errors);
  } else {
    errors->AddError("required property missing: insertionPointId");
  }
  const base::Value* distributed_nodes_value = value.FindKey("distributedNodes");
  if (distributed_nodes_value) {
    errors->SetName("distributedNodes");
    result->distributed_nodes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom::BackendNode>>>::Parse(*distributed_nodes_value, errors);
  } else {
    errors->AddError("required property missing: distributedNodes");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DistributedNodesUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("insertionPointId", internal::ToValue(insertion_point_id_));
  result->Set("distributedNodes", internal::ToValue(distributed_nodes_));
  return std::move(result);
}

std::unique_ptr<DistributedNodesUpdatedParams> DistributedNodesUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DistributedNodesUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DocumentUpdatedParams> DocumentUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DocumentUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DocumentUpdatedParams> result(new DocumentUpdatedParams());
  errors->Push();
  errors->SetName("DocumentUpdatedParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DocumentUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DocumentUpdatedParams> DocumentUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DocumentUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InlineStyleInvalidatedParams> InlineStyleInvalidatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InlineStyleInvalidatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InlineStyleInvalidatedParams> result(new InlineStyleInvalidatedParams());
  errors->Push();
  errors->SetName("InlineStyleInvalidatedParams");
  const base::Value* node_ids_value = value.FindKey("nodeIds");
  if (node_ids_value) {
    errors->SetName("nodeIds");
    result->node_ids_ = internal::FromValue<std::vector<int>>::Parse(*node_ids_value, errors);
  } else {
    errors->AddError("required property missing: nodeIds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InlineStyleInvalidatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeIds", internal::ToValue(node_ids_));
  return std::move(result);
}

std::unique_ptr<InlineStyleInvalidatedParams> InlineStyleInvalidatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InlineStyleInvalidatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PseudoElementAddedParams> PseudoElementAddedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PseudoElementAddedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PseudoElementAddedParams> result(new PseudoElementAddedParams());
  errors->Push();
  errors->SetName("PseudoElementAddedParams");
  const base::Value* parent_id_value = value.FindKey("parentId");
  if (parent_id_value) {
    errors->SetName("parentId");
    result->parent_id_ = internal::FromValue<int>::Parse(*parent_id_value, errors);
  } else {
    errors->AddError("required property missing: parentId");
  }
  const base::Value* pseudo_element_value = value.FindKey("pseudoElement");
  if (pseudo_element_value) {
    errors->SetName("pseudoElement");
    result->pseudo_element_ = internal::FromValue<::headless::dom::Node>::Parse(*pseudo_element_value, errors);
  } else {
    errors->AddError("required property missing: pseudoElement");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PseudoElementAddedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("parentId", internal::ToValue(parent_id_));
  result->Set("pseudoElement", internal::ToValue(*pseudo_element_));
  return std::move(result);
}

std::unique_ptr<PseudoElementAddedParams> PseudoElementAddedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PseudoElementAddedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PseudoElementRemovedParams> PseudoElementRemovedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PseudoElementRemovedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PseudoElementRemovedParams> result(new PseudoElementRemovedParams());
  errors->Push();
  errors->SetName("PseudoElementRemovedParams");
  const base::Value* parent_id_value = value.FindKey("parentId");
  if (parent_id_value) {
    errors->SetName("parentId");
    result->parent_id_ = internal::FromValue<int>::Parse(*parent_id_value, errors);
  } else {
    errors->AddError("required property missing: parentId");
  }
  const base::Value* pseudo_element_id_value = value.FindKey("pseudoElementId");
  if (pseudo_element_id_value) {
    errors->SetName("pseudoElementId");
    result->pseudo_element_id_ = internal::FromValue<int>::Parse(*pseudo_element_id_value, errors);
  } else {
    errors->AddError("required property missing: pseudoElementId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PseudoElementRemovedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("parentId", internal::ToValue(parent_id_));
  result->Set("pseudoElementId", internal::ToValue(pseudo_element_id_));
  return std::move(result);
}

std::unique_ptr<PseudoElementRemovedParams> PseudoElementRemovedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PseudoElementRemovedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetChildNodesParams> SetChildNodesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetChildNodesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetChildNodesParams> result(new SetChildNodesParams());
  errors->Push();
  errors->SetName("SetChildNodesParams");
  const base::Value* parent_id_value = value.FindKey("parentId");
  if (parent_id_value) {
    errors->SetName("parentId");
    result->parent_id_ = internal::FromValue<int>::Parse(*parent_id_value, errors);
  } else {
    errors->AddError("required property missing: parentId");
  }
  const base::Value* nodes_value = value.FindKey("nodes");
  if (nodes_value) {
    errors->SetName("nodes");
    result->nodes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom::Node>>>::Parse(*nodes_value, errors);
  } else {
    errors->AddError("required property missing: nodes");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetChildNodesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("parentId", internal::ToValue(parent_id_));
  result->Set("nodes", internal::ToValue(nodes_));
  return std::move(result);
}

std::unique_ptr<SetChildNodesParams> SetChildNodesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetChildNodesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ShadowRootPoppedParams> ShadowRootPoppedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ShadowRootPoppedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ShadowRootPoppedParams> result(new ShadowRootPoppedParams());
  errors->Push();
  errors->SetName("ShadowRootPoppedParams");
  const base::Value* host_id_value = value.FindKey("hostId");
  if (host_id_value) {
    errors->SetName("hostId");
    result->host_id_ = internal::FromValue<int>::Parse(*host_id_value, errors);
  } else {
    errors->AddError("required property missing: hostId");
  }
  const base::Value* root_id_value = value.FindKey("rootId");
  if (root_id_value) {
    errors->SetName("rootId");
    result->root_id_ = internal::FromValue<int>::Parse(*root_id_value, errors);
  } else {
    errors->AddError("required property missing: rootId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ShadowRootPoppedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("hostId", internal::ToValue(host_id_));
  result->Set("rootId", internal::ToValue(root_id_));
  return std::move(result);
}

std::unique_ptr<ShadowRootPoppedParams> ShadowRootPoppedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ShadowRootPoppedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ShadowRootPushedParams> ShadowRootPushedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ShadowRootPushedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ShadowRootPushedParams> result(new ShadowRootPushedParams());
  errors->Push();
  errors->SetName("ShadowRootPushedParams");
  const base::Value* host_id_value = value.FindKey("hostId");
  if (host_id_value) {
    errors->SetName("hostId");
    result->host_id_ = internal::FromValue<int>::Parse(*host_id_value, errors);
  } else {
    errors->AddError("required property missing: hostId");
  }
  const base::Value* root_value = value.FindKey("root");
  if (root_value) {
    errors->SetName("root");
    result->root_ = internal::FromValue<::headless::dom::Node>::Parse(*root_value, errors);
  } else {
    errors->AddError("required property missing: root");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ShadowRootPushedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("hostId", internal::ToValue(host_id_));
  result->Set("root", internal::ToValue(*root_));
  return std::move(result);
}

std::unique_ptr<ShadowRootPushedParams> ShadowRootPushedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ShadowRootPushedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace dom
}  // namespace headless
