// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_css.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_dom_debugger.h"
#include "headless/public/devtools/domains/types_dom_snapshot.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_css.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_dom_debugger.h"
#include "headless/public/devtools/internal/type_conversions_dom_snapshot.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace dom_snapshot {

std::unique_ptr<DOMNode> DOMNode::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DOMNode");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DOMNode> result(new DOMNode());
  errors->Push();
  errors->SetName("DOMNode");
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
  const base::Value* node_value_value = value.FindKey("nodeValue");
  if (node_value_value) {
    errors->SetName("nodeValue");
    result->node_value_ = internal::FromValue<std::string>::Parse(*node_value_value, errors);
  } else {
    errors->AddError("required property missing: nodeValue");
  }
  const base::Value* text_value_value = value.FindKey("textValue");
  if (text_value_value) {
    errors->SetName("textValue");
    result->text_value_ = internal::FromValue<std::string>::Parse(*text_value_value, errors);
  }
  const base::Value* input_value_value = value.FindKey("inputValue");
  if (input_value_value) {
    errors->SetName("inputValue");
    result->input_value_ = internal::FromValue<std::string>::Parse(*input_value_value, errors);
  }
  const base::Value* input_checked_value = value.FindKey("inputChecked");
  if (input_checked_value) {
    errors->SetName("inputChecked");
    result->input_checked_ = internal::FromValue<bool>::Parse(*input_checked_value, errors);
  }
  const base::Value* option_selected_value = value.FindKey("optionSelected");
  if (option_selected_value) {
    errors->SetName("optionSelected");
    result->option_selected_ = internal::FromValue<bool>::Parse(*option_selected_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  } else {
    errors->AddError("required property missing: backendNodeId");
  }
  const base::Value* child_node_indexes_value = value.FindKey("childNodeIndexes");
  if (child_node_indexes_value) {
    errors->SetName("childNodeIndexes");
    result->child_node_indexes_ = internal::FromValue<std::vector<int>>::Parse(*child_node_indexes_value, errors);
  }
  const base::Value* attributes_value = value.FindKey("attributes");
  if (attributes_value) {
    errors->SetName("attributes");
    result->attributes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom_snapshot::NameValue>>>::Parse(*attributes_value, errors);
  }
  const base::Value* pseudo_element_indexes_value = value.FindKey("pseudoElementIndexes");
  if (pseudo_element_indexes_value) {
    errors->SetName("pseudoElementIndexes");
    result->pseudo_element_indexes_ = internal::FromValue<std::vector<int>>::Parse(*pseudo_element_indexes_value, errors);
  }
  const base::Value* layout_node_index_value = value.FindKey("layoutNodeIndex");
  if (layout_node_index_value) {
    errors->SetName("layoutNodeIndex");
    result->layout_node_index_ = internal::FromValue<int>::Parse(*layout_node_index_value, errors);
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
  const base::Value* content_language_value = value.FindKey("contentLanguage");
  if (content_language_value) {
    errors->SetName("contentLanguage");
    result->content_language_ = internal::FromValue<std::string>::Parse(*content_language_value, errors);
  }
  const base::Value* document_encoding_value = value.FindKey("documentEncoding");
  if (document_encoding_value) {
    errors->SetName("documentEncoding");
    result->document_encoding_ = internal::FromValue<std::string>::Parse(*document_encoding_value, errors);
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
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  }
  const base::Value* content_document_index_value = value.FindKey("contentDocumentIndex");
  if (content_document_index_value) {
    errors->SetName("contentDocumentIndex");
    result->content_document_index_ = internal::FromValue<int>::Parse(*content_document_index_value, errors);
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
  const base::Value* is_clickable_value = value.FindKey("isClickable");
  if (is_clickable_value) {
    errors->SetName("isClickable");
    result->is_clickable_ = internal::FromValue<bool>::Parse(*is_clickable_value, errors);
  }
  const base::Value* event_listeners_value = value.FindKey("eventListeners");
  if (event_listeners_value) {
    errors->SetName("eventListeners");
    result->event_listeners_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom_debugger::EventListener>>>::Parse(*event_listeners_value, errors);
  }
  const base::Value* current_sourceurl_value = value.FindKey("currentSourceURL");
  if (current_sourceurl_value) {
    errors->SetName("currentSourceURL");
    result->current_sourceurl_ = internal::FromValue<std::string>::Parse(*current_sourceurl_value, errors);
  }
  const base::Value* originurl_value = value.FindKey("originURL");
  if (originurl_value) {
    errors->SetName("originURL");
    result->originurl_ = internal::FromValue<std::string>::Parse(*originurl_value, errors);
  }
  const base::Value* scroll_offsetx_value = value.FindKey("scrollOffsetX");
  if (scroll_offsetx_value) {
    errors->SetName("scrollOffsetX");
    result->scroll_offsetx_ = internal::FromValue<double>::Parse(*scroll_offsetx_value, errors);
  }
  const base::Value* scroll_offsety_value = value.FindKey("scrollOffsetY");
  if (scroll_offsety_value) {
    errors->SetName("scrollOffsetY");
    result->scroll_offsety_ = internal::FromValue<double>::Parse(*scroll_offsety_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DOMNode::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeType", internal::ToValue(node_type_));
  result->Set("nodeName", internal::ToValue(node_name_));
  result->Set("nodeValue", internal::ToValue(node_value_));
  if (text_value_)
    result->Set("textValue", internal::ToValue(text_value_.value()));
  if (input_value_)
    result->Set("inputValue", internal::ToValue(input_value_.value()));
  if (input_checked_)
    result->Set("inputChecked", internal::ToValue(input_checked_.value()));
  if (option_selected_)
    result->Set("optionSelected", internal::ToValue(option_selected_.value()));
  result->Set("backendNodeId", internal::ToValue(backend_node_id_));
  if (child_node_indexes_)
    result->Set("childNodeIndexes", internal::ToValue(child_node_indexes_.value()));
  if (attributes_)
    result->Set("attributes", internal::ToValue(attributes_.value()));
  if (pseudo_element_indexes_)
    result->Set("pseudoElementIndexes", internal::ToValue(pseudo_element_indexes_.value()));
  if (layout_node_index_)
    result->Set("layoutNodeIndex", internal::ToValue(layout_node_index_.value()));
  if (documenturl_)
    result->Set("documentURL", internal::ToValue(documenturl_.value()));
  if (baseurl_)
    result->Set("baseURL", internal::ToValue(baseurl_.value()));
  if (content_language_)
    result->Set("contentLanguage", internal::ToValue(content_language_.value()));
  if (document_encoding_)
    result->Set("documentEncoding", internal::ToValue(document_encoding_.value()));
  if (public_id_)
    result->Set("publicId", internal::ToValue(public_id_.value()));
  if (system_id_)
    result->Set("systemId", internal::ToValue(system_id_.value()));
  if (frame_id_)
    result->Set("frameId", internal::ToValue(frame_id_.value()));
  if (content_document_index_)
    result->Set("contentDocumentIndex", internal::ToValue(content_document_index_.value()));
  if (pseudo_type_)
    result->Set("pseudoType", internal::ToValue(pseudo_type_.value()));
  if (shadow_root_type_)
    result->Set("shadowRootType", internal::ToValue(shadow_root_type_.value()));
  if (is_clickable_)
    result->Set("isClickable", internal::ToValue(is_clickable_.value()));
  if (event_listeners_)
    result->Set("eventListeners", internal::ToValue(event_listeners_.value()));
  if (current_sourceurl_)
    result->Set("currentSourceURL", internal::ToValue(current_sourceurl_.value()));
  if (originurl_)
    result->Set("originURL", internal::ToValue(originurl_.value()));
  if (scroll_offsetx_)
    result->Set("scrollOffsetX", internal::ToValue(scroll_offsetx_.value()));
  if (scroll_offsety_)
    result->Set("scrollOffsetY", internal::ToValue(scroll_offsety_.value()));
  return std::move(result);
}

std::unique_ptr<DOMNode> DOMNode::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DOMNode> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InlineTextBox> InlineTextBox::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InlineTextBox");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InlineTextBox> result(new InlineTextBox());
  errors->Push();
  errors->SetName("InlineTextBox");
  const base::Value* bounding_box_value = value.FindKey("boundingBox");
  if (bounding_box_value) {
    errors->SetName("boundingBox");
    result->bounding_box_ = internal::FromValue<::headless::dom::Rect>::Parse(*bounding_box_value, errors);
  } else {
    errors->AddError("required property missing: boundingBox");
  }
  const base::Value* start_character_index_value = value.FindKey("startCharacterIndex");
  if (start_character_index_value) {
    errors->SetName("startCharacterIndex");
    result->start_character_index_ = internal::FromValue<int>::Parse(*start_character_index_value, errors);
  } else {
    errors->AddError("required property missing: startCharacterIndex");
  }
  const base::Value* num_characters_value = value.FindKey("numCharacters");
  if (num_characters_value) {
    errors->SetName("numCharacters");
    result->num_characters_ = internal::FromValue<int>::Parse(*num_characters_value, errors);
  } else {
    errors->AddError("required property missing: numCharacters");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InlineTextBox::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("boundingBox", internal::ToValue(*bounding_box_));
  result->Set("startCharacterIndex", internal::ToValue(start_character_index_));
  result->Set("numCharacters", internal::ToValue(num_characters_));
  return std::move(result);
}

std::unique_ptr<InlineTextBox> InlineTextBox::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InlineTextBox> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<LayoutTreeNode> LayoutTreeNode::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LayoutTreeNode");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LayoutTreeNode> result(new LayoutTreeNode());
  errors->Push();
  errors->SetName("LayoutTreeNode");
  const base::Value* dom_node_index_value = value.FindKey("domNodeIndex");
  if (dom_node_index_value) {
    errors->SetName("domNodeIndex");
    result->dom_node_index_ = internal::FromValue<int>::Parse(*dom_node_index_value, errors);
  } else {
    errors->AddError("required property missing: domNodeIndex");
  }
  const base::Value* bounding_box_value = value.FindKey("boundingBox");
  if (bounding_box_value) {
    errors->SetName("boundingBox");
    result->bounding_box_ = internal::FromValue<::headless::dom::Rect>::Parse(*bounding_box_value, errors);
  } else {
    errors->AddError("required property missing: boundingBox");
  }
  const base::Value* layout_text_value = value.FindKey("layoutText");
  if (layout_text_value) {
    errors->SetName("layoutText");
    result->layout_text_ = internal::FromValue<std::string>::Parse(*layout_text_value, errors);
  }
  const base::Value* inline_text_nodes_value = value.FindKey("inlineTextNodes");
  if (inline_text_nodes_value) {
    errors->SetName("inlineTextNodes");
    result->inline_text_nodes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom_snapshot::InlineTextBox>>>::Parse(*inline_text_nodes_value, errors);
  }
  const base::Value* style_index_value = value.FindKey("styleIndex");
  if (style_index_value) {
    errors->SetName("styleIndex");
    result->style_index_ = internal::FromValue<int>::Parse(*style_index_value, errors);
  }
  const base::Value* paint_order_value = value.FindKey("paintOrder");
  if (paint_order_value) {
    errors->SetName("paintOrder");
    result->paint_order_ = internal::FromValue<int>::Parse(*paint_order_value, errors);
  }
  const base::Value* is_stacking_context_value = value.FindKey("isStackingContext");
  if (is_stacking_context_value) {
    errors->SetName("isStackingContext");
    result->is_stacking_context_ = internal::FromValue<bool>::Parse(*is_stacking_context_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LayoutTreeNode::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("domNodeIndex", internal::ToValue(dom_node_index_));
  result->Set("boundingBox", internal::ToValue(*bounding_box_));
  if (layout_text_)
    result->Set("layoutText", internal::ToValue(layout_text_.value()));
  if (inline_text_nodes_)
    result->Set("inlineTextNodes", internal::ToValue(inline_text_nodes_.value()));
  if (style_index_)
    result->Set("styleIndex", internal::ToValue(style_index_.value()));
  if (paint_order_)
    result->Set("paintOrder", internal::ToValue(paint_order_.value()));
  if (is_stacking_context_)
    result->Set("isStackingContext", internal::ToValue(is_stacking_context_.value()));
  return std::move(result);
}

std::unique_ptr<LayoutTreeNode> LayoutTreeNode::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LayoutTreeNode> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ComputedStyle> ComputedStyle::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ComputedStyle");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ComputedStyle> result(new ComputedStyle());
  errors->Push();
  errors->SetName("ComputedStyle");
  const base::Value* properties_value = value.FindKey("properties");
  if (properties_value) {
    errors->SetName("properties");
    result->properties_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom_snapshot::NameValue>>>::Parse(*properties_value, errors);
  } else {
    errors->AddError("required property missing: properties");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ComputedStyle::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("properties", internal::ToValue(properties_));
  return std::move(result);
}

std::unique_ptr<ComputedStyle> ComputedStyle::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ComputedStyle> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NameValue> NameValue::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NameValue");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NameValue> result(new NameValue());
  errors->Push();
  errors->SetName("NameValue");
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

std::unique_ptr<base::Value> NameValue::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<NameValue> NameValue::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NameValue> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RareStringData> RareStringData::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RareStringData");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RareStringData> result(new RareStringData());
  errors->Push();
  errors->SetName("RareStringData");
  const base::Value* index_value = value.FindKey("index");
  if (index_value) {
    errors->SetName("index");
    result->index_ = internal::FromValue<std::vector<int>>::Parse(*index_value, errors);
  } else {
    errors->AddError("required property missing: index");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::vector<int>>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RareStringData::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("index", internal::ToValue(index_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<RareStringData> RareStringData::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RareStringData> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RareBooleanData> RareBooleanData::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RareBooleanData");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RareBooleanData> result(new RareBooleanData());
  errors->Push();
  errors->SetName("RareBooleanData");
  const base::Value* index_value = value.FindKey("index");
  if (index_value) {
    errors->SetName("index");
    result->index_ = internal::FromValue<std::vector<int>>::Parse(*index_value, errors);
  } else {
    errors->AddError("required property missing: index");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RareBooleanData::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("index", internal::ToValue(index_));
  return std::move(result);
}

std::unique_ptr<RareBooleanData> RareBooleanData::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RareBooleanData> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RareIntegerData> RareIntegerData::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RareIntegerData");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RareIntegerData> result(new RareIntegerData());
  errors->Push();
  errors->SetName("RareIntegerData");
  const base::Value* index_value = value.FindKey("index");
  if (index_value) {
    errors->SetName("index");
    result->index_ = internal::FromValue<std::vector<int>>::Parse(*index_value, errors);
  } else {
    errors->AddError("required property missing: index");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::vector<int>>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RareIntegerData::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("index", internal::ToValue(index_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<RareIntegerData> RareIntegerData::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RareIntegerData> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DocumentSnapshot> DocumentSnapshot::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DocumentSnapshot");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DocumentSnapshot> result(new DocumentSnapshot());
  errors->Push();
  errors->SetName("DocumentSnapshot");
  const base::Value* documenturl_value = value.FindKey("documentURL");
  if (documenturl_value) {
    errors->SetName("documentURL");
    result->documenturl_ = internal::FromValue<int>::Parse(*documenturl_value, errors);
  } else {
    errors->AddError("required property missing: documentURL");
  }
  const base::Value* title_value = value.FindKey("title");
  if (title_value) {
    errors->SetName("title");
    result->title_ = internal::FromValue<int>::Parse(*title_value, errors);
  } else {
    errors->AddError("required property missing: title");
  }
  const base::Value* baseurl_value = value.FindKey("baseURL");
  if (baseurl_value) {
    errors->SetName("baseURL");
    result->baseurl_ = internal::FromValue<int>::Parse(*baseurl_value, errors);
  } else {
    errors->AddError("required property missing: baseURL");
  }
  const base::Value* content_language_value = value.FindKey("contentLanguage");
  if (content_language_value) {
    errors->SetName("contentLanguage");
    result->content_language_ = internal::FromValue<int>::Parse(*content_language_value, errors);
  } else {
    errors->AddError("required property missing: contentLanguage");
  }
  const base::Value* encoding_name_value = value.FindKey("encodingName");
  if (encoding_name_value) {
    errors->SetName("encodingName");
    result->encoding_name_ = internal::FromValue<int>::Parse(*encoding_name_value, errors);
  } else {
    errors->AddError("required property missing: encodingName");
  }
  const base::Value* public_id_value = value.FindKey("publicId");
  if (public_id_value) {
    errors->SetName("publicId");
    result->public_id_ = internal::FromValue<int>::Parse(*public_id_value, errors);
  } else {
    errors->AddError("required property missing: publicId");
  }
  const base::Value* system_id_value = value.FindKey("systemId");
  if (system_id_value) {
    errors->SetName("systemId");
    result->system_id_ = internal::FromValue<int>::Parse(*system_id_value, errors);
  } else {
    errors->AddError("required property missing: systemId");
  }
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<int>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* nodes_value = value.FindKey("nodes");
  if (nodes_value) {
    errors->SetName("nodes");
    result->nodes_ = internal::FromValue<::headless::dom_snapshot::NodeTreeSnapshot>::Parse(*nodes_value, errors);
  } else {
    errors->AddError("required property missing: nodes");
  }
  const base::Value* layout_value = value.FindKey("layout");
  if (layout_value) {
    errors->SetName("layout");
    result->layout_ = internal::FromValue<::headless::dom_snapshot::LayoutTreeSnapshot>::Parse(*layout_value, errors);
  } else {
    errors->AddError("required property missing: layout");
  }
  const base::Value* text_boxes_value = value.FindKey("textBoxes");
  if (text_boxes_value) {
    errors->SetName("textBoxes");
    result->text_boxes_ = internal::FromValue<::headless::dom_snapshot::TextBoxSnapshot>::Parse(*text_boxes_value, errors);
  } else {
    errors->AddError("required property missing: textBoxes");
  }
  const base::Value* scroll_offsetx_value = value.FindKey("scrollOffsetX");
  if (scroll_offsetx_value) {
    errors->SetName("scrollOffsetX");
    result->scroll_offsetx_ = internal::FromValue<double>::Parse(*scroll_offsetx_value, errors);
  }
  const base::Value* scroll_offsety_value = value.FindKey("scrollOffsetY");
  if (scroll_offsety_value) {
    errors->SetName("scrollOffsetY");
    result->scroll_offsety_ = internal::FromValue<double>::Parse(*scroll_offsety_value, errors);
  }
  const base::Value* content_width_value = value.FindKey("contentWidth");
  if (content_width_value) {
    errors->SetName("contentWidth");
    result->content_width_ = internal::FromValue<double>::Parse(*content_width_value, errors);
  }
  const base::Value* content_height_value = value.FindKey("contentHeight");
  if (content_height_value) {
    errors->SetName("contentHeight");
    result->content_height_ = internal::FromValue<double>::Parse(*content_height_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DocumentSnapshot::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("documentURL", internal::ToValue(documenturl_));
  result->Set("title", internal::ToValue(title_));
  result->Set("baseURL", internal::ToValue(baseurl_));
  result->Set("contentLanguage", internal::ToValue(content_language_));
  result->Set("encodingName", internal::ToValue(encoding_name_));
  result->Set("publicId", internal::ToValue(public_id_));
  result->Set("systemId", internal::ToValue(system_id_));
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("nodes", internal::ToValue(*nodes_));
  result->Set("layout", internal::ToValue(*layout_));
  result->Set("textBoxes", internal::ToValue(*text_boxes_));
  if (scroll_offsetx_)
    result->Set("scrollOffsetX", internal::ToValue(scroll_offsetx_.value()));
  if (scroll_offsety_)
    result->Set("scrollOffsetY", internal::ToValue(scroll_offsety_.value()));
  if (content_width_)
    result->Set("contentWidth", internal::ToValue(content_width_.value()));
  if (content_height_)
    result->Set("contentHeight", internal::ToValue(content_height_.value()));
  return std::move(result);
}

std::unique_ptr<DocumentSnapshot> DocumentSnapshot::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DocumentSnapshot> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NodeTreeSnapshot> NodeTreeSnapshot::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NodeTreeSnapshot");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NodeTreeSnapshot> result(new NodeTreeSnapshot());
  errors->Push();
  errors->SetName("NodeTreeSnapshot");
  const base::Value* parent_index_value = value.FindKey("parentIndex");
  if (parent_index_value) {
    errors->SetName("parentIndex");
    result->parent_index_ = internal::FromValue<std::vector<int>>::Parse(*parent_index_value, errors);
  }
  const base::Value* node_type_value = value.FindKey("nodeType");
  if (node_type_value) {
    errors->SetName("nodeType");
    result->node_type_ = internal::FromValue<std::vector<int>>::Parse(*node_type_value, errors);
  }
  const base::Value* node_name_value = value.FindKey("nodeName");
  if (node_name_value) {
    errors->SetName("nodeName");
    result->node_name_ = internal::FromValue<std::vector<int>>::Parse(*node_name_value, errors);
  }
  const base::Value* node_value_value = value.FindKey("nodeValue");
  if (node_value_value) {
    errors->SetName("nodeValue");
    result->node_value_ = internal::FromValue<std::vector<int>>::Parse(*node_value_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<std::vector<int>>::Parse(*backend_node_id_value, errors);
  }
  const base::Value* attributes_value = value.FindKey("attributes");
  if (attributes_value) {
    errors->SetName("attributes");
    result->attributes_ = internal::FromValue<std::vector<std::vector<int>>>::Parse(*attributes_value, errors);
  }
  const base::Value* text_value_value = value.FindKey("textValue");
  if (text_value_value) {
    errors->SetName("textValue");
    result->text_value_ = internal::FromValue<::headless::dom_snapshot::RareStringData>::Parse(*text_value_value, errors);
  }
  const base::Value* input_value_value = value.FindKey("inputValue");
  if (input_value_value) {
    errors->SetName("inputValue");
    result->input_value_ = internal::FromValue<::headless::dom_snapshot::RareStringData>::Parse(*input_value_value, errors);
  }
  const base::Value* input_checked_value = value.FindKey("inputChecked");
  if (input_checked_value) {
    errors->SetName("inputChecked");
    result->input_checked_ = internal::FromValue<::headless::dom_snapshot::RareBooleanData>::Parse(*input_checked_value, errors);
  }
  const base::Value* option_selected_value = value.FindKey("optionSelected");
  if (option_selected_value) {
    errors->SetName("optionSelected");
    result->option_selected_ = internal::FromValue<::headless::dom_snapshot::RareBooleanData>::Parse(*option_selected_value, errors);
  }
  const base::Value* content_document_index_value = value.FindKey("contentDocumentIndex");
  if (content_document_index_value) {
    errors->SetName("contentDocumentIndex");
    result->content_document_index_ = internal::FromValue<::headless::dom_snapshot::RareIntegerData>::Parse(*content_document_index_value, errors);
  }
  const base::Value* pseudo_type_value = value.FindKey("pseudoType");
  if (pseudo_type_value) {
    errors->SetName("pseudoType");
    result->pseudo_type_ = internal::FromValue<::headless::dom_snapshot::RareStringData>::Parse(*pseudo_type_value, errors);
  }
  const base::Value* is_clickable_value = value.FindKey("isClickable");
  if (is_clickable_value) {
    errors->SetName("isClickable");
    result->is_clickable_ = internal::FromValue<::headless::dom_snapshot::RareBooleanData>::Parse(*is_clickable_value, errors);
  }
  const base::Value* current_sourceurl_value = value.FindKey("currentSourceURL");
  if (current_sourceurl_value) {
    errors->SetName("currentSourceURL");
    result->current_sourceurl_ = internal::FromValue<::headless::dom_snapshot::RareStringData>::Parse(*current_sourceurl_value, errors);
  }
  const base::Value* originurl_value = value.FindKey("originURL");
  if (originurl_value) {
    errors->SetName("originURL");
    result->originurl_ = internal::FromValue<::headless::dom_snapshot::RareStringData>::Parse(*originurl_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NodeTreeSnapshot::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (parent_index_)
    result->Set("parentIndex", internal::ToValue(parent_index_.value()));
  if (node_type_)
    result->Set("nodeType", internal::ToValue(node_type_.value()));
  if (node_name_)
    result->Set("nodeName", internal::ToValue(node_name_.value()));
  if (node_value_)
    result->Set("nodeValue", internal::ToValue(node_value_.value()));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  if (attributes_)
    result->Set("attributes", internal::ToValue(attributes_.value()));
  if (text_value_)
    result->Set("textValue", internal::ToValue(*text_value_.value()));
  if (input_value_)
    result->Set("inputValue", internal::ToValue(*input_value_.value()));
  if (input_checked_)
    result->Set("inputChecked", internal::ToValue(*input_checked_.value()));
  if (option_selected_)
    result->Set("optionSelected", internal::ToValue(*option_selected_.value()));
  if (content_document_index_)
    result->Set("contentDocumentIndex", internal::ToValue(*content_document_index_.value()));
  if (pseudo_type_)
    result->Set("pseudoType", internal::ToValue(*pseudo_type_.value()));
  if (is_clickable_)
    result->Set("isClickable", internal::ToValue(*is_clickable_.value()));
  if (current_sourceurl_)
    result->Set("currentSourceURL", internal::ToValue(*current_sourceurl_.value()));
  if (originurl_)
    result->Set("originURL", internal::ToValue(*originurl_.value()));
  return std::move(result);
}

std::unique_ptr<NodeTreeSnapshot> NodeTreeSnapshot::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NodeTreeSnapshot> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<LayoutTreeSnapshot> LayoutTreeSnapshot::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LayoutTreeSnapshot");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LayoutTreeSnapshot> result(new LayoutTreeSnapshot());
  errors->Push();
  errors->SetName("LayoutTreeSnapshot");
  const base::Value* node_index_value = value.FindKey("nodeIndex");
  if (node_index_value) {
    errors->SetName("nodeIndex");
    result->node_index_ = internal::FromValue<std::vector<int>>::Parse(*node_index_value, errors);
  } else {
    errors->AddError("required property missing: nodeIndex");
  }
  const base::Value* styles_value = value.FindKey("styles");
  if (styles_value) {
    errors->SetName("styles");
    result->styles_ = internal::FromValue<std::vector<std::vector<int>>>::Parse(*styles_value, errors);
  } else {
    errors->AddError("required property missing: styles");
  }
  const base::Value* bounds_value = value.FindKey("bounds");
  if (bounds_value) {
    errors->SetName("bounds");
    result->bounds_ = internal::FromValue<std::vector<std::vector<double>>>::Parse(*bounds_value, errors);
  } else {
    errors->AddError("required property missing: bounds");
  }
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::vector<int>>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  const base::Value* stacking_contexts_value = value.FindKey("stackingContexts");
  if (stacking_contexts_value) {
    errors->SetName("stackingContexts");
    result->stacking_contexts_ = internal::FromValue<::headless::dom_snapshot::RareBooleanData>::Parse(*stacking_contexts_value, errors);
  } else {
    errors->AddError("required property missing: stackingContexts");
  }
  const base::Value* paint_orders_value = value.FindKey("paintOrders");
  if (paint_orders_value) {
    errors->SetName("paintOrders");
    result->paint_orders_ = internal::FromValue<std::vector<int>>::Parse(*paint_orders_value, errors);
  }
  const base::Value* offset_rects_value = value.FindKey("offsetRects");
  if (offset_rects_value) {
    errors->SetName("offsetRects");
    result->offset_rects_ = internal::FromValue<std::vector<std::vector<double>>>::Parse(*offset_rects_value, errors);
  }
  const base::Value* scroll_rects_value = value.FindKey("scrollRects");
  if (scroll_rects_value) {
    errors->SetName("scrollRects");
    result->scroll_rects_ = internal::FromValue<std::vector<std::vector<double>>>::Parse(*scroll_rects_value, errors);
  }
  const base::Value* client_rects_value = value.FindKey("clientRects");
  if (client_rects_value) {
    errors->SetName("clientRects");
    result->client_rects_ = internal::FromValue<std::vector<std::vector<double>>>::Parse(*client_rects_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LayoutTreeSnapshot::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeIndex", internal::ToValue(node_index_));
  result->Set("styles", internal::ToValue(styles_));
  result->Set("bounds", internal::ToValue(bounds_));
  result->Set("text", internal::ToValue(text_));
  result->Set("stackingContexts", internal::ToValue(*stacking_contexts_));
  if (paint_orders_)
    result->Set("paintOrders", internal::ToValue(paint_orders_.value()));
  if (offset_rects_)
    result->Set("offsetRects", internal::ToValue(offset_rects_.value()));
  if (scroll_rects_)
    result->Set("scrollRects", internal::ToValue(scroll_rects_.value()));
  if (client_rects_)
    result->Set("clientRects", internal::ToValue(client_rects_.value()));
  return std::move(result);
}

std::unique_ptr<LayoutTreeSnapshot> LayoutTreeSnapshot::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LayoutTreeSnapshot> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TextBoxSnapshot> TextBoxSnapshot::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TextBoxSnapshot");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TextBoxSnapshot> result(new TextBoxSnapshot());
  errors->Push();
  errors->SetName("TextBoxSnapshot");
  const base::Value* layout_index_value = value.FindKey("layoutIndex");
  if (layout_index_value) {
    errors->SetName("layoutIndex");
    result->layout_index_ = internal::FromValue<std::vector<int>>::Parse(*layout_index_value, errors);
  } else {
    errors->AddError("required property missing: layoutIndex");
  }
  const base::Value* bounds_value = value.FindKey("bounds");
  if (bounds_value) {
    errors->SetName("bounds");
    result->bounds_ = internal::FromValue<std::vector<std::vector<double>>>::Parse(*bounds_value, errors);
  } else {
    errors->AddError("required property missing: bounds");
  }
  const base::Value* start_value = value.FindKey("start");
  if (start_value) {
    errors->SetName("start");
    result->start_ = internal::FromValue<std::vector<int>>::Parse(*start_value, errors);
  } else {
    errors->AddError("required property missing: start");
  }
  const base::Value* length_value = value.FindKey("length");
  if (length_value) {
    errors->SetName("length");
    result->length_ = internal::FromValue<std::vector<int>>::Parse(*length_value, errors);
  } else {
    errors->AddError("required property missing: length");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TextBoxSnapshot::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("layoutIndex", internal::ToValue(layout_index_));
  result->Set("bounds", internal::ToValue(bounds_));
  result->Set("start", internal::ToValue(start_));
  result->Set("length", internal::ToValue(length_));
  return std::move(result);
}

std::unique_ptr<TextBoxSnapshot> TextBoxSnapshot::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TextBoxSnapshot> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<GetSnapshotParams> GetSnapshotParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetSnapshotParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetSnapshotParams> result(new GetSnapshotParams());
  errors->Push();
  errors->SetName("GetSnapshotParams");
  const base::Value* computed_style_whitelist_value = value.FindKey("computedStyleWhitelist");
  if (computed_style_whitelist_value) {
    errors->SetName("computedStyleWhitelist");
    result->computed_style_whitelist_ = internal::FromValue<std::vector<std::string>>::Parse(*computed_style_whitelist_value, errors);
  } else {
    errors->AddError("required property missing: computedStyleWhitelist");
  }
  const base::Value* include_event_listeners_value = value.FindKey("includeEventListeners");
  if (include_event_listeners_value) {
    errors->SetName("includeEventListeners");
    result->include_event_listeners_ = internal::FromValue<bool>::Parse(*include_event_listeners_value, errors);
  }
  const base::Value* include_paint_order_value = value.FindKey("includePaintOrder");
  if (include_paint_order_value) {
    errors->SetName("includePaintOrder");
    result->include_paint_order_ = internal::FromValue<bool>::Parse(*include_paint_order_value, errors);
  }
  const base::Value* include_user_agent_shadow_tree_value = value.FindKey("includeUserAgentShadowTree");
  if (include_user_agent_shadow_tree_value) {
    errors->SetName("includeUserAgentShadowTree");
    result->include_user_agent_shadow_tree_ = internal::FromValue<bool>::Parse(*include_user_agent_shadow_tree_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetSnapshotParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("computedStyleWhitelist", internal::ToValue(computed_style_whitelist_));
  if (include_event_listeners_)
    result->Set("includeEventListeners", internal::ToValue(include_event_listeners_.value()));
  if (include_paint_order_)
    result->Set("includePaintOrder", internal::ToValue(include_paint_order_.value()));
  if (include_user_agent_shadow_tree_)
    result->Set("includeUserAgentShadowTree", internal::ToValue(include_user_agent_shadow_tree_.value()));
  return std::move(result);
}

std::unique_ptr<GetSnapshotParams> GetSnapshotParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetSnapshotParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetSnapshotResult> GetSnapshotResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetSnapshotResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetSnapshotResult> result(new GetSnapshotResult());
  errors->Push();
  errors->SetName("GetSnapshotResult");
  const base::Value* dom_nodes_value = value.FindKey("domNodes");
  if (dom_nodes_value) {
    errors->SetName("domNodes");
    result->dom_nodes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom_snapshot::DOMNode>>>::Parse(*dom_nodes_value, errors);
  } else {
    errors->AddError("required property missing: domNodes");
  }
  const base::Value* layout_tree_nodes_value = value.FindKey("layoutTreeNodes");
  if (layout_tree_nodes_value) {
    errors->SetName("layoutTreeNodes");
    result->layout_tree_nodes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom_snapshot::LayoutTreeNode>>>::Parse(*layout_tree_nodes_value, errors);
  } else {
    errors->AddError("required property missing: layoutTreeNodes");
  }
  const base::Value* computed_styles_value = value.FindKey("computedStyles");
  if (computed_styles_value) {
    errors->SetName("computedStyles");
    result->computed_styles_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom_snapshot::ComputedStyle>>>::Parse(*computed_styles_value, errors);
  } else {
    errors->AddError("required property missing: computedStyles");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetSnapshotResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("domNodes", internal::ToValue(dom_nodes_));
  result->Set("layoutTreeNodes", internal::ToValue(layout_tree_nodes_));
  result->Set("computedStyles", internal::ToValue(computed_styles_));
  return std::move(result);
}

std::unique_ptr<GetSnapshotResult> GetSnapshotResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetSnapshotResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CaptureSnapshotParams> CaptureSnapshotParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CaptureSnapshotParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CaptureSnapshotParams> result(new CaptureSnapshotParams());
  errors->Push();
  errors->SetName("CaptureSnapshotParams");
  const base::Value* computed_styles_value = value.FindKey("computedStyles");
  if (computed_styles_value) {
    errors->SetName("computedStyles");
    result->computed_styles_ = internal::FromValue<std::vector<std::string>>::Parse(*computed_styles_value, errors);
  } else {
    errors->AddError("required property missing: computedStyles");
  }
  const base::Value* include_paint_order_value = value.FindKey("includePaintOrder");
  if (include_paint_order_value) {
    errors->SetName("includePaintOrder");
    result->include_paint_order_ = internal::FromValue<bool>::Parse(*include_paint_order_value, errors);
  }
  const base::Value* includedom_rects_value = value.FindKey("includeDOMRects");
  if (includedom_rects_value) {
    errors->SetName("includeDOMRects");
    result->includedom_rects_ = internal::FromValue<bool>::Parse(*includedom_rects_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CaptureSnapshotParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("computedStyles", internal::ToValue(computed_styles_));
  if (include_paint_order_)
    result->Set("includePaintOrder", internal::ToValue(include_paint_order_.value()));
  if (includedom_rects_)
    result->Set("includeDOMRects", internal::ToValue(includedom_rects_.value()));
  return std::move(result);
}

std::unique_ptr<CaptureSnapshotParams> CaptureSnapshotParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CaptureSnapshotParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CaptureSnapshotResult> CaptureSnapshotResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CaptureSnapshotResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CaptureSnapshotResult> result(new CaptureSnapshotResult());
  errors->Push();
  errors->SetName("CaptureSnapshotResult");
  const base::Value* documents_value = value.FindKey("documents");
  if (documents_value) {
    errors->SetName("documents");
    result->documents_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom_snapshot::DocumentSnapshot>>>::Parse(*documents_value, errors);
  } else {
    errors->AddError("required property missing: documents");
  }
  const base::Value* strings_value = value.FindKey("strings");
  if (strings_value) {
    errors->SetName("strings");
    result->strings_ = internal::FromValue<std::vector<std::string>>::Parse(*strings_value, errors);
  } else {
    errors->AddError("required property missing: strings");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CaptureSnapshotResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("documents", internal::ToValue(documents_));
  result->Set("strings", internal::ToValue(strings_));
  return std::move(result);
}

std::unique_ptr<CaptureSnapshotResult> CaptureSnapshotResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CaptureSnapshotResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace dom_snapshot
}  // namespace headless
