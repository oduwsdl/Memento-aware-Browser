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

namespace page {

std::unique_ptr<Frame> Frame::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Frame");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Frame> result(new Frame());
  errors->Push();
  errors->SetName("Frame");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<std::string>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  const base::Value* parent_id_value = value.FindKey("parentId");
  if (parent_id_value) {
    errors->SetName("parentId");
    result->parent_id_ = internal::FromValue<std::string>::Parse(*parent_id_value, errors);
  }
  const base::Value* loader_id_value = value.FindKey("loaderId");
  if (loader_id_value) {
    errors->SetName("loaderId");
    result->loader_id_ = internal::FromValue<std::string>::Parse(*loader_id_value, errors);
  } else {
    errors->AddError("required property missing: loaderId");
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* url_fragment_value = value.FindKey("urlFragment");
  if (url_fragment_value) {
    errors->SetName("urlFragment");
    result->url_fragment_ = internal::FromValue<std::string>::Parse(*url_fragment_value, errors);
  }
  const base::Value* security_origin_value = value.FindKey("securityOrigin");
  if (security_origin_value) {
    errors->SetName("securityOrigin");
    result->security_origin_ = internal::FromValue<std::string>::Parse(*security_origin_value, errors);
  } else {
    errors->AddError("required property missing: securityOrigin");
  }
  const base::Value* mime_type_value = value.FindKey("mimeType");
  if (mime_type_value) {
    errors->SetName("mimeType");
    result->mime_type_ = internal::FromValue<std::string>::Parse(*mime_type_value, errors);
  } else {
    errors->AddError("required property missing: mimeType");
  }
  const base::Value* unreachable_url_value = value.FindKey("unreachableUrl");
  if (unreachable_url_value) {
    errors->SetName("unreachableUrl");
    result->unreachable_url_ = internal::FromValue<std::string>::Parse(*unreachable_url_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Frame::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  if (parent_id_)
    result->Set("parentId", internal::ToValue(parent_id_.value()));
  result->Set("loaderId", internal::ToValue(loader_id_));
  if (name_)
    result->Set("name", internal::ToValue(name_.value()));
  result->Set("url", internal::ToValue(url_));
  if (url_fragment_)
    result->Set("urlFragment", internal::ToValue(url_fragment_.value()));
  result->Set("securityOrigin", internal::ToValue(security_origin_));
  result->Set("mimeType", internal::ToValue(mime_type_));
  if (unreachable_url_)
    result->Set("unreachableUrl", internal::ToValue(unreachable_url_.value()));
  return std::move(result);
}

std::unique_ptr<Frame> Frame::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Frame> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameResource> FrameResource::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameResource");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameResource> result(new FrameResource());
  errors->Push();
  errors->SetName("FrameResource");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::network::ResourceType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* mime_type_value = value.FindKey("mimeType");
  if (mime_type_value) {
    errors->SetName("mimeType");
    result->mime_type_ = internal::FromValue<std::string>::Parse(*mime_type_value, errors);
  } else {
    errors->AddError("required property missing: mimeType");
  }
  const base::Value* last_modified_value = value.FindKey("lastModified");
  if (last_modified_value) {
    errors->SetName("lastModified");
    result->last_modified_ = internal::FromValue<double>::Parse(*last_modified_value, errors);
  }
  const base::Value* content_size_value = value.FindKey("contentSize");
  if (content_size_value) {
    errors->SetName("contentSize");
    result->content_size_ = internal::FromValue<double>::Parse(*content_size_value, errors);
  }
  const base::Value* failed_value = value.FindKey("failed");
  if (failed_value) {
    errors->SetName("failed");
    result->failed_ = internal::FromValue<bool>::Parse(*failed_value, errors);
  }
  const base::Value* canceled_value = value.FindKey("canceled");
  if (canceled_value) {
    errors->SetName("canceled");
    result->canceled_ = internal::FromValue<bool>::Parse(*canceled_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FrameResource::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  result->Set("type", internal::ToValue(type_));
  result->Set("mimeType", internal::ToValue(mime_type_));
  if (last_modified_)
    result->Set("lastModified", internal::ToValue(last_modified_.value()));
  if (content_size_)
    result->Set("contentSize", internal::ToValue(content_size_.value()));
  if (failed_)
    result->Set("failed", internal::ToValue(failed_.value()));
  if (canceled_)
    result->Set("canceled", internal::ToValue(canceled_.value()));
  return std::move(result);
}

std::unique_ptr<FrameResource> FrameResource::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameResource> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameResourceTree> FrameResourceTree::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameResourceTree");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameResourceTree> result(new FrameResourceTree());
  errors->Push();
  errors->SetName("FrameResourceTree");
  const base::Value* frame_value = value.FindKey("frame");
  if (frame_value) {
    errors->SetName("frame");
    result->frame_ = internal::FromValue<::headless::page::Frame>::Parse(*frame_value, errors);
  } else {
    errors->AddError("required property missing: frame");
  }
  const base::Value* child_frames_value = value.FindKey("childFrames");
  if (child_frames_value) {
    errors->SetName("childFrames");
    result->child_frames_ = internal::FromValue<std::vector<std::unique_ptr<::headless::page::FrameResourceTree>>>::Parse(*child_frames_value, errors);
  }
  const base::Value* resources_value = value.FindKey("resources");
  if (resources_value) {
    errors->SetName("resources");
    result->resources_ = internal::FromValue<std::vector<std::unique_ptr<::headless::page::FrameResource>>>::Parse(*resources_value, errors);
  } else {
    errors->AddError("required property missing: resources");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FrameResourceTree::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frame", internal::ToValue(*frame_));
  if (child_frames_)
    result->Set("childFrames", internal::ToValue(child_frames_.value()));
  result->Set("resources", internal::ToValue(resources_));
  return std::move(result);
}

std::unique_ptr<FrameResourceTree> FrameResourceTree::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameResourceTree> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameTree> FrameTree::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameTree");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameTree> result(new FrameTree());
  errors->Push();
  errors->SetName("FrameTree");
  const base::Value* frame_value = value.FindKey("frame");
  if (frame_value) {
    errors->SetName("frame");
    result->frame_ = internal::FromValue<::headless::page::Frame>::Parse(*frame_value, errors);
  } else {
    errors->AddError("required property missing: frame");
  }
  const base::Value* child_frames_value = value.FindKey("childFrames");
  if (child_frames_value) {
    errors->SetName("childFrames");
    result->child_frames_ = internal::FromValue<std::vector<std::unique_ptr<::headless::page::FrameTree>>>::Parse(*child_frames_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FrameTree::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frame", internal::ToValue(*frame_));
  if (child_frames_)
    result->Set("childFrames", internal::ToValue(child_frames_.value()));
  return std::move(result);
}

std::unique_ptr<FrameTree> FrameTree::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameTree> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NavigationEntry> NavigationEntry::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NavigationEntry");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NavigationEntry> result(new NavigationEntry());
  errors->Push();
  errors->SetName("NavigationEntry");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<int>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* user_typedurl_value = value.FindKey("userTypedURL");
  if (user_typedurl_value) {
    errors->SetName("userTypedURL");
    result->user_typedurl_ = internal::FromValue<std::string>::Parse(*user_typedurl_value, errors);
  } else {
    errors->AddError("required property missing: userTypedURL");
  }
  const base::Value* title_value = value.FindKey("title");
  if (title_value) {
    errors->SetName("title");
    result->title_ = internal::FromValue<std::string>::Parse(*title_value, errors);
  } else {
    errors->AddError("required property missing: title");
  }
  const base::Value* transition_type_value = value.FindKey("transitionType");
  if (transition_type_value) {
    errors->SetName("transitionType");
    result->transition_type_ = internal::FromValue<::headless::page::TransitionType>::Parse(*transition_type_value, errors);
  } else {
    errors->AddError("required property missing: transitionType");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NavigationEntry::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  result->Set("url", internal::ToValue(url_));
  result->Set("userTypedURL", internal::ToValue(user_typedurl_));
  result->Set("title", internal::ToValue(title_));
  result->Set("transitionType", internal::ToValue(transition_type_));
  return std::move(result);
}

std::unique_ptr<NavigationEntry> NavigationEntry::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NavigationEntry> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ScreencastFrameMetadata> ScreencastFrameMetadata::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ScreencastFrameMetadata");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ScreencastFrameMetadata> result(new ScreencastFrameMetadata());
  errors->Push();
  errors->SetName("ScreencastFrameMetadata");
  const base::Value* offset_top_value = value.FindKey("offsetTop");
  if (offset_top_value) {
    errors->SetName("offsetTop");
    result->offset_top_ = internal::FromValue<double>::Parse(*offset_top_value, errors);
  } else {
    errors->AddError("required property missing: offsetTop");
  }
  const base::Value* page_scale_factor_value = value.FindKey("pageScaleFactor");
  if (page_scale_factor_value) {
    errors->SetName("pageScaleFactor");
    result->page_scale_factor_ = internal::FromValue<double>::Parse(*page_scale_factor_value, errors);
  } else {
    errors->AddError("required property missing: pageScaleFactor");
  }
  const base::Value* device_width_value = value.FindKey("deviceWidth");
  if (device_width_value) {
    errors->SetName("deviceWidth");
    result->device_width_ = internal::FromValue<double>::Parse(*device_width_value, errors);
  } else {
    errors->AddError("required property missing: deviceWidth");
  }
  const base::Value* device_height_value = value.FindKey("deviceHeight");
  if (device_height_value) {
    errors->SetName("deviceHeight");
    result->device_height_ = internal::FromValue<double>::Parse(*device_height_value, errors);
  } else {
    errors->AddError("required property missing: deviceHeight");
  }
  const base::Value* scroll_offsetx_value = value.FindKey("scrollOffsetX");
  if (scroll_offsetx_value) {
    errors->SetName("scrollOffsetX");
    result->scroll_offsetx_ = internal::FromValue<double>::Parse(*scroll_offsetx_value, errors);
  } else {
    errors->AddError("required property missing: scrollOffsetX");
  }
  const base::Value* scroll_offsety_value = value.FindKey("scrollOffsetY");
  if (scroll_offsety_value) {
    errors->SetName("scrollOffsetY");
    result->scroll_offsety_ = internal::FromValue<double>::Parse(*scroll_offsety_value, errors);
  } else {
    errors->AddError("required property missing: scrollOffsetY");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ScreencastFrameMetadata::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("offsetTop", internal::ToValue(offset_top_));
  result->Set("pageScaleFactor", internal::ToValue(page_scale_factor_));
  result->Set("deviceWidth", internal::ToValue(device_width_));
  result->Set("deviceHeight", internal::ToValue(device_height_));
  result->Set("scrollOffsetX", internal::ToValue(scroll_offsetx_));
  result->Set("scrollOffsetY", internal::ToValue(scroll_offsety_));
  if (timestamp_)
    result->Set("timestamp", internal::ToValue(timestamp_.value()));
  return std::move(result);
}

std::unique_ptr<ScreencastFrameMetadata> ScreencastFrameMetadata::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ScreencastFrameMetadata> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AppManifestError> AppManifestError::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AppManifestError");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AppManifestError> result(new AppManifestError());
  errors->Push();
  errors->SetName("AppManifestError");
  const base::Value* message_value = value.FindKey("message");
  if (message_value) {
    errors->SetName("message");
    result->message_ = internal::FromValue<std::string>::Parse(*message_value, errors);
  } else {
    errors->AddError("required property missing: message");
  }
  const base::Value* critical_value = value.FindKey("critical");
  if (critical_value) {
    errors->SetName("critical");
    result->critical_ = internal::FromValue<int>::Parse(*critical_value, errors);
  } else {
    errors->AddError("required property missing: critical");
  }
  const base::Value* line_value = value.FindKey("line");
  if (line_value) {
    errors->SetName("line");
    result->line_ = internal::FromValue<int>::Parse(*line_value, errors);
  } else {
    errors->AddError("required property missing: line");
  }
  const base::Value* column_value = value.FindKey("column");
  if (column_value) {
    errors->SetName("column");
    result->column_ = internal::FromValue<int>::Parse(*column_value, errors);
  } else {
    errors->AddError("required property missing: column");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AppManifestError::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("message", internal::ToValue(message_));
  result->Set("critical", internal::ToValue(critical_));
  result->Set("line", internal::ToValue(line_));
  result->Set("column", internal::ToValue(column_));
  return std::move(result);
}

std::unique_ptr<AppManifestError> AppManifestError::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AppManifestError> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AppManifestParsedProperties> AppManifestParsedProperties::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AppManifestParsedProperties");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AppManifestParsedProperties> result(new AppManifestParsedProperties());
  errors->Push();
  errors->SetName("AppManifestParsedProperties");
  const base::Value* scope_value = value.FindKey("scope");
  if (scope_value) {
    errors->SetName("scope");
    result->scope_ = internal::FromValue<std::string>::Parse(*scope_value, errors);
  } else {
    errors->AddError("required property missing: scope");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AppManifestParsedProperties::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("scope", internal::ToValue(scope_));
  return std::move(result);
}

std::unique_ptr<AppManifestParsedProperties> AppManifestParsedProperties::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AppManifestParsedProperties> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<LayoutViewport> LayoutViewport::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LayoutViewport");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LayoutViewport> result(new LayoutViewport());
  errors->Push();
  errors->SetName("LayoutViewport");
  const base::Value* pagex_value = value.FindKey("pageX");
  if (pagex_value) {
    errors->SetName("pageX");
    result->pagex_ = internal::FromValue<int>::Parse(*pagex_value, errors);
  } else {
    errors->AddError("required property missing: pageX");
  }
  const base::Value* pagey_value = value.FindKey("pageY");
  if (pagey_value) {
    errors->SetName("pageY");
    result->pagey_ = internal::FromValue<int>::Parse(*pagey_value, errors);
  } else {
    errors->AddError("required property missing: pageY");
  }
  const base::Value* client_width_value = value.FindKey("clientWidth");
  if (client_width_value) {
    errors->SetName("clientWidth");
    result->client_width_ = internal::FromValue<int>::Parse(*client_width_value, errors);
  } else {
    errors->AddError("required property missing: clientWidth");
  }
  const base::Value* client_height_value = value.FindKey("clientHeight");
  if (client_height_value) {
    errors->SetName("clientHeight");
    result->client_height_ = internal::FromValue<int>::Parse(*client_height_value, errors);
  } else {
    errors->AddError("required property missing: clientHeight");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LayoutViewport::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("pageX", internal::ToValue(pagex_));
  result->Set("pageY", internal::ToValue(pagey_));
  result->Set("clientWidth", internal::ToValue(client_width_));
  result->Set("clientHeight", internal::ToValue(client_height_));
  return std::move(result);
}

std::unique_ptr<LayoutViewport> LayoutViewport::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LayoutViewport> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<VisualViewport> VisualViewport::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("VisualViewport");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<VisualViewport> result(new VisualViewport());
  errors->Push();
  errors->SetName("VisualViewport");
  const base::Value* offsetx_value = value.FindKey("offsetX");
  if (offsetx_value) {
    errors->SetName("offsetX");
    result->offsetx_ = internal::FromValue<double>::Parse(*offsetx_value, errors);
  } else {
    errors->AddError("required property missing: offsetX");
  }
  const base::Value* offsety_value = value.FindKey("offsetY");
  if (offsety_value) {
    errors->SetName("offsetY");
    result->offsety_ = internal::FromValue<double>::Parse(*offsety_value, errors);
  } else {
    errors->AddError("required property missing: offsetY");
  }
  const base::Value* pagex_value = value.FindKey("pageX");
  if (pagex_value) {
    errors->SetName("pageX");
    result->pagex_ = internal::FromValue<double>::Parse(*pagex_value, errors);
  } else {
    errors->AddError("required property missing: pageX");
  }
  const base::Value* pagey_value = value.FindKey("pageY");
  if (pagey_value) {
    errors->SetName("pageY");
    result->pagey_ = internal::FromValue<double>::Parse(*pagey_value, errors);
  } else {
    errors->AddError("required property missing: pageY");
  }
  const base::Value* client_width_value = value.FindKey("clientWidth");
  if (client_width_value) {
    errors->SetName("clientWidth");
    result->client_width_ = internal::FromValue<double>::Parse(*client_width_value, errors);
  } else {
    errors->AddError("required property missing: clientWidth");
  }
  const base::Value* client_height_value = value.FindKey("clientHeight");
  if (client_height_value) {
    errors->SetName("clientHeight");
    result->client_height_ = internal::FromValue<double>::Parse(*client_height_value, errors);
  } else {
    errors->AddError("required property missing: clientHeight");
  }
  const base::Value* scale_value = value.FindKey("scale");
  if (scale_value) {
    errors->SetName("scale");
    result->scale_ = internal::FromValue<double>::Parse(*scale_value, errors);
  } else {
    errors->AddError("required property missing: scale");
  }
  const base::Value* zoom_value = value.FindKey("zoom");
  if (zoom_value) {
    errors->SetName("zoom");
    result->zoom_ = internal::FromValue<double>::Parse(*zoom_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> VisualViewport::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("offsetX", internal::ToValue(offsetx_));
  result->Set("offsetY", internal::ToValue(offsety_));
  result->Set("pageX", internal::ToValue(pagex_));
  result->Set("pageY", internal::ToValue(pagey_));
  result->Set("clientWidth", internal::ToValue(client_width_));
  result->Set("clientHeight", internal::ToValue(client_height_));
  result->Set("scale", internal::ToValue(scale_));
  if (zoom_)
    result->Set("zoom", internal::ToValue(zoom_.value()));
  return std::move(result);
}

std::unique_ptr<VisualViewport> VisualViewport::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<VisualViewport> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Viewport> Viewport::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Viewport");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Viewport> result(new Viewport());
  errors->Push();
  errors->SetName("Viewport");
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
  const base::Value* scale_value = value.FindKey("scale");
  if (scale_value) {
    errors->SetName("scale");
    result->scale_ = internal::FromValue<double>::Parse(*scale_value, errors);
  } else {
    errors->AddError("required property missing: scale");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Viewport::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("x", internal::ToValue(x_));
  result->Set("y", internal::ToValue(y_));
  result->Set("width", internal::ToValue(width_));
  result->Set("height", internal::ToValue(height_));
  result->Set("scale", internal::ToValue(scale_));
  return std::move(result);
}

std::unique_ptr<Viewport> Viewport::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Viewport> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FontFamilies> FontFamilies::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FontFamilies");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FontFamilies> result(new FontFamilies());
  errors->Push();
  errors->SetName("FontFamilies");
  const base::Value* standard_value = value.FindKey("standard");
  if (standard_value) {
    errors->SetName("standard");
    result->standard_ = internal::FromValue<std::string>::Parse(*standard_value, errors);
  }
  const base::Value* fixed_value = value.FindKey("fixed");
  if (fixed_value) {
    errors->SetName("fixed");
    result->fixed_ = internal::FromValue<std::string>::Parse(*fixed_value, errors);
  }
  const base::Value* serif_value = value.FindKey("serif");
  if (serif_value) {
    errors->SetName("serif");
    result->serif_ = internal::FromValue<std::string>::Parse(*serif_value, errors);
  }
  const base::Value* sans_serif_value = value.FindKey("sansSerif");
  if (sans_serif_value) {
    errors->SetName("sansSerif");
    result->sans_serif_ = internal::FromValue<std::string>::Parse(*sans_serif_value, errors);
  }
  const base::Value* cursive_value = value.FindKey("cursive");
  if (cursive_value) {
    errors->SetName("cursive");
    result->cursive_ = internal::FromValue<std::string>::Parse(*cursive_value, errors);
  }
  const base::Value* fantasy_value = value.FindKey("fantasy");
  if (fantasy_value) {
    errors->SetName("fantasy");
    result->fantasy_ = internal::FromValue<std::string>::Parse(*fantasy_value, errors);
  }
  const base::Value* pictograph_value = value.FindKey("pictograph");
  if (pictograph_value) {
    errors->SetName("pictograph");
    result->pictograph_ = internal::FromValue<std::string>::Parse(*pictograph_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FontFamilies::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (standard_)
    result->Set("standard", internal::ToValue(standard_.value()));
  if (fixed_)
    result->Set("fixed", internal::ToValue(fixed_.value()));
  if (serif_)
    result->Set("serif", internal::ToValue(serif_.value()));
  if (sans_serif_)
    result->Set("sansSerif", internal::ToValue(sans_serif_.value()));
  if (cursive_)
    result->Set("cursive", internal::ToValue(cursive_.value()));
  if (fantasy_)
    result->Set("fantasy", internal::ToValue(fantasy_.value()));
  if (pictograph_)
    result->Set("pictograph", internal::ToValue(pictograph_.value()));
  return std::move(result);
}

std::unique_ptr<FontFamilies> FontFamilies::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FontFamilies> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FontSizes> FontSizes::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FontSizes");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FontSizes> result(new FontSizes());
  errors->Push();
  errors->SetName("FontSizes");
  const base::Value* standard_value = value.FindKey("standard");
  if (standard_value) {
    errors->SetName("standard");
    result->standard_ = internal::FromValue<int>::Parse(*standard_value, errors);
  }
  const base::Value* fixed_value = value.FindKey("fixed");
  if (fixed_value) {
    errors->SetName("fixed");
    result->fixed_ = internal::FromValue<int>::Parse(*fixed_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FontSizes::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (standard_)
    result->Set("standard", internal::ToValue(standard_.value()));
  if (fixed_)
    result->Set("fixed", internal::ToValue(fixed_.value()));
  return std::move(result);
}

std::unique_ptr<FontSizes> FontSizes::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FontSizes> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InstallabilityErrorArgument> InstallabilityErrorArgument::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InstallabilityErrorArgument");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InstallabilityErrorArgument> result(new InstallabilityErrorArgument());
  errors->Push();
  errors->SetName("InstallabilityErrorArgument");
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

std::unique_ptr<base::Value> InstallabilityErrorArgument::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<InstallabilityErrorArgument> InstallabilityErrorArgument::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InstallabilityErrorArgument> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InstallabilityError> InstallabilityError::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InstallabilityError");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InstallabilityError> result(new InstallabilityError());
  errors->Push();
  errors->SetName("InstallabilityError");
  const base::Value* error_id_value = value.FindKey("errorId");
  if (error_id_value) {
    errors->SetName("errorId");
    result->error_id_ = internal::FromValue<std::string>::Parse(*error_id_value, errors);
  } else {
    errors->AddError("required property missing: errorId");
  }
  const base::Value* error_arguments_value = value.FindKey("errorArguments");
  if (error_arguments_value) {
    errors->SetName("errorArguments");
    result->error_arguments_ = internal::FromValue<std::vector<std::unique_ptr<::headless::page::InstallabilityErrorArgument>>>::Parse(*error_arguments_value, errors);
  } else {
    errors->AddError("required property missing: errorArguments");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InstallabilityError::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("errorId", internal::ToValue(error_id_));
  result->Set("errorArguments", internal::ToValue(error_arguments_));
  return std::move(result);
}

std::unique_ptr<InstallabilityError> InstallabilityError::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InstallabilityError> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddScriptToEvaluateOnLoadParams> AddScriptToEvaluateOnLoadParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddScriptToEvaluateOnLoadParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddScriptToEvaluateOnLoadParams> result(new AddScriptToEvaluateOnLoadParams());
  errors->Push();
  errors->SetName("AddScriptToEvaluateOnLoadParams");
  const base::Value* script_source_value = value.FindKey("scriptSource");
  if (script_source_value) {
    errors->SetName("scriptSource");
    result->script_source_ = internal::FromValue<std::string>::Parse(*script_source_value, errors);
  } else {
    errors->AddError("required property missing: scriptSource");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddScriptToEvaluateOnLoadParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("scriptSource", internal::ToValue(script_source_));
  return std::move(result);
}

std::unique_ptr<AddScriptToEvaluateOnLoadParams> AddScriptToEvaluateOnLoadParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddScriptToEvaluateOnLoadParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddScriptToEvaluateOnLoadResult> AddScriptToEvaluateOnLoadResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddScriptToEvaluateOnLoadResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddScriptToEvaluateOnLoadResult> result(new AddScriptToEvaluateOnLoadResult());
  errors->Push();
  errors->SetName("AddScriptToEvaluateOnLoadResult");
  const base::Value* identifier_value = value.FindKey("identifier");
  if (identifier_value) {
    errors->SetName("identifier");
    result->identifier_ = internal::FromValue<std::string>::Parse(*identifier_value, errors);
  } else {
    errors->AddError("required property missing: identifier");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddScriptToEvaluateOnLoadResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("identifier", internal::ToValue(identifier_));
  return std::move(result);
}

std::unique_ptr<AddScriptToEvaluateOnLoadResult> AddScriptToEvaluateOnLoadResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddScriptToEvaluateOnLoadResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddScriptToEvaluateOnNewDocumentParams> AddScriptToEvaluateOnNewDocumentParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddScriptToEvaluateOnNewDocumentParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddScriptToEvaluateOnNewDocumentParams> result(new AddScriptToEvaluateOnNewDocumentParams());
  errors->Push();
  errors->SetName("AddScriptToEvaluateOnNewDocumentParams");
  const base::Value* source_value = value.FindKey("source");
  if (source_value) {
    errors->SetName("source");
    result->source_ = internal::FromValue<std::string>::Parse(*source_value, errors);
  } else {
    errors->AddError("required property missing: source");
  }
  const base::Value* world_name_value = value.FindKey("worldName");
  if (world_name_value) {
    errors->SetName("worldName");
    result->world_name_ = internal::FromValue<std::string>::Parse(*world_name_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddScriptToEvaluateOnNewDocumentParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("source", internal::ToValue(source_));
  if (world_name_)
    result->Set("worldName", internal::ToValue(world_name_.value()));
  return std::move(result);
}

std::unique_ptr<AddScriptToEvaluateOnNewDocumentParams> AddScriptToEvaluateOnNewDocumentParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddScriptToEvaluateOnNewDocumentParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddScriptToEvaluateOnNewDocumentResult> AddScriptToEvaluateOnNewDocumentResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddScriptToEvaluateOnNewDocumentResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddScriptToEvaluateOnNewDocumentResult> result(new AddScriptToEvaluateOnNewDocumentResult());
  errors->Push();
  errors->SetName("AddScriptToEvaluateOnNewDocumentResult");
  const base::Value* identifier_value = value.FindKey("identifier");
  if (identifier_value) {
    errors->SetName("identifier");
    result->identifier_ = internal::FromValue<std::string>::Parse(*identifier_value, errors);
  } else {
    errors->AddError("required property missing: identifier");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddScriptToEvaluateOnNewDocumentResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("identifier", internal::ToValue(identifier_));
  return std::move(result);
}

std::unique_ptr<AddScriptToEvaluateOnNewDocumentResult> AddScriptToEvaluateOnNewDocumentResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddScriptToEvaluateOnNewDocumentResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BringToFrontParams> BringToFrontParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BringToFrontParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BringToFrontParams> result(new BringToFrontParams());
  errors->Push();
  errors->SetName("BringToFrontParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BringToFrontParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<BringToFrontParams> BringToFrontParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BringToFrontParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BringToFrontResult> BringToFrontResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BringToFrontResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BringToFrontResult> result(new BringToFrontResult());
  errors->Push();
  errors->SetName("BringToFrontResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BringToFrontResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<BringToFrontResult> BringToFrontResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BringToFrontResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CaptureScreenshotParams> CaptureScreenshotParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CaptureScreenshotParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CaptureScreenshotParams> result(new CaptureScreenshotParams());
  errors->Push();
  errors->SetName("CaptureScreenshotParams");
  const base::Value* format_value = value.FindKey("format");
  if (format_value) {
    errors->SetName("format");
    result->format_ = internal::FromValue<::headless::page::CaptureScreenshotFormat>::Parse(*format_value, errors);
  }
  const base::Value* quality_value = value.FindKey("quality");
  if (quality_value) {
    errors->SetName("quality");
    result->quality_ = internal::FromValue<int>::Parse(*quality_value, errors);
  }
  const base::Value* clip_value = value.FindKey("clip");
  if (clip_value) {
    errors->SetName("clip");
    result->clip_ = internal::FromValue<::headless::page::Viewport>::Parse(*clip_value, errors);
  }
  const base::Value* from_surface_value = value.FindKey("fromSurface");
  if (from_surface_value) {
    errors->SetName("fromSurface");
    result->from_surface_ = internal::FromValue<bool>::Parse(*from_surface_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CaptureScreenshotParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (format_)
    result->Set("format", internal::ToValue(format_.value()));
  if (quality_)
    result->Set("quality", internal::ToValue(quality_.value()));
  if (clip_)
    result->Set("clip", internal::ToValue(*clip_.value()));
  if (from_surface_)
    result->Set("fromSurface", internal::ToValue(from_surface_.value()));
  return std::move(result);
}

std::unique_ptr<CaptureScreenshotParams> CaptureScreenshotParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CaptureScreenshotParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CaptureScreenshotResult> CaptureScreenshotResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CaptureScreenshotResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CaptureScreenshotResult> result(new CaptureScreenshotResult());
  errors->Push();
  errors->SetName("CaptureScreenshotResult");
  const base::Value* data_value = value.FindKey("data");
  if (data_value) {
    errors->SetName("data");
    result->data_ = internal::FromValue<protocol::Binary>::Parse(*data_value, errors);
  } else {
    errors->AddError("required property missing: data");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CaptureScreenshotResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("data", internal::ToValue(data_));
  return std::move(result);
}

std::unique_ptr<CaptureScreenshotResult> CaptureScreenshotResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CaptureScreenshotResult> result = Parse(*Serialize(), &errors);
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
  const base::Value* format_value = value.FindKey("format");
  if (format_value) {
    errors->SetName("format");
    result->format_ = internal::FromValue<::headless::page::CaptureSnapshotFormat>::Parse(*format_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CaptureSnapshotParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (format_)
    result->Set("format", internal::ToValue(format_.value()));
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
  const base::Value* data_value = value.FindKey("data");
  if (data_value) {
    errors->SetName("data");
    result->data_ = internal::FromValue<std::string>::Parse(*data_value, errors);
  } else {
    errors->AddError("required property missing: data");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CaptureSnapshotResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("data", internal::ToValue(data_));
  return std::move(result);
}

std::unique_ptr<CaptureSnapshotResult> CaptureSnapshotResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CaptureSnapshotResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearDeviceMetricsOverrideParams> ClearDeviceMetricsOverrideParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearDeviceMetricsOverrideParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearDeviceMetricsOverrideParams> result(new ClearDeviceMetricsOverrideParams());
  errors->Push();
  errors->SetName("ClearDeviceMetricsOverrideParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearDeviceMetricsOverrideParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearDeviceMetricsOverrideParams> ClearDeviceMetricsOverrideParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearDeviceMetricsOverrideParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearDeviceMetricsOverrideResult> ClearDeviceMetricsOverrideResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearDeviceMetricsOverrideResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearDeviceMetricsOverrideResult> result(new ClearDeviceMetricsOverrideResult());
  errors->Push();
  errors->SetName("ClearDeviceMetricsOverrideResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearDeviceMetricsOverrideResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearDeviceMetricsOverrideResult> ClearDeviceMetricsOverrideResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearDeviceMetricsOverrideResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearDeviceOrientationOverrideParams> ClearDeviceOrientationOverrideParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearDeviceOrientationOverrideParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearDeviceOrientationOverrideParams> result(new ClearDeviceOrientationOverrideParams());
  errors->Push();
  errors->SetName("ClearDeviceOrientationOverrideParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearDeviceOrientationOverrideParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearDeviceOrientationOverrideParams> ClearDeviceOrientationOverrideParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearDeviceOrientationOverrideParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearDeviceOrientationOverrideResult> ClearDeviceOrientationOverrideResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearDeviceOrientationOverrideResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearDeviceOrientationOverrideResult> result(new ClearDeviceOrientationOverrideResult());
  errors->Push();
  errors->SetName("ClearDeviceOrientationOverrideResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearDeviceOrientationOverrideResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearDeviceOrientationOverrideResult> ClearDeviceOrientationOverrideResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearDeviceOrientationOverrideResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearGeolocationOverrideParams> ClearGeolocationOverrideParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearGeolocationOverrideParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearGeolocationOverrideParams> result(new ClearGeolocationOverrideParams());
  errors->Push();
  errors->SetName("ClearGeolocationOverrideParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearGeolocationOverrideParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearGeolocationOverrideParams> ClearGeolocationOverrideParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearGeolocationOverrideParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearGeolocationOverrideResult> ClearGeolocationOverrideResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearGeolocationOverrideResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearGeolocationOverrideResult> result(new ClearGeolocationOverrideResult());
  errors->Push();
  errors->SetName("ClearGeolocationOverrideResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearGeolocationOverrideResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearGeolocationOverrideResult> ClearGeolocationOverrideResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearGeolocationOverrideResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CreateIsolatedWorldParams> CreateIsolatedWorldParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CreateIsolatedWorldParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CreateIsolatedWorldParams> result(new CreateIsolatedWorldParams());
  errors->Push();
  errors->SetName("CreateIsolatedWorldParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* world_name_value = value.FindKey("worldName");
  if (world_name_value) {
    errors->SetName("worldName");
    result->world_name_ = internal::FromValue<std::string>::Parse(*world_name_value, errors);
  }
  const base::Value* grant_univeral_access_value = value.FindKey("grantUniveralAccess");
  if (grant_univeral_access_value) {
    errors->SetName("grantUniveralAccess");
    result->grant_univeral_access_ = internal::FromValue<bool>::Parse(*grant_univeral_access_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CreateIsolatedWorldParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  if (world_name_)
    result->Set("worldName", internal::ToValue(world_name_.value()));
  if (grant_univeral_access_)
    result->Set("grantUniveralAccess", internal::ToValue(grant_univeral_access_.value()));
  return std::move(result);
}

std::unique_ptr<CreateIsolatedWorldParams> CreateIsolatedWorldParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CreateIsolatedWorldParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CreateIsolatedWorldResult> CreateIsolatedWorldResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CreateIsolatedWorldResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CreateIsolatedWorldResult> result(new CreateIsolatedWorldResult());
  errors->Push();
  errors->SetName("CreateIsolatedWorldResult");
  const base::Value* execution_context_id_value = value.FindKey("executionContextId");
  if (execution_context_id_value) {
    errors->SetName("executionContextId");
    result->execution_context_id_ = internal::FromValue<int>::Parse(*execution_context_id_value, errors);
  } else {
    errors->AddError("required property missing: executionContextId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CreateIsolatedWorldResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("executionContextId", internal::ToValue(execution_context_id_));
  return std::move(result);
}

std::unique_ptr<CreateIsolatedWorldResult> CreateIsolatedWorldResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CreateIsolatedWorldResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteCookieParams> DeleteCookieParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteCookieParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteCookieParams> result(new DeleteCookieParams());
  errors->Push();
  errors->SetName("DeleteCookieParams");
  const base::Value* cookie_name_value = value.FindKey("cookieName");
  if (cookie_name_value) {
    errors->SetName("cookieName");
    result->cookie_name_ = internal::FromValue<std::string>::Parse(*cookie_name_value, errors);
  } else {
    errors->AddError("required property missing: cookieName");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteCookieParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cookieName", internal::ToValue(cookie_name_));
  result->Set("url", internal::ToValue(url_));
  return std::move(result);
}

std::unique_ptr<DeleteCookieParams> DeleteCookieParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteCookieParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteCookieResult> DeleteCookieResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteCookieResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteCookieResult> result(new DeleteCookieResult());
  errors->Push();
  errors->SetName("DeleteCookieResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteCookieResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DeleteCookieResult> DeleteCookieResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteCookieResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<GetAppManifestParams> GetAppManifestParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetAppManifestParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetAppManifestParams> result(new GetAppManifestParams());
  errors->Push();
  errors->SetName("GetAppManifestParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetAppManifestParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetAppManifestParams> GetAppManifestParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetAppManifestParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetAppManifestResult> GetAppManifestResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetAppManifestResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetAppManifestResult> result(new GetAppManifestResult());
  errors->Push();
  errors->SetName("GetAppManifestResult");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* errors_value = value.FindKey("errors");
  if (errors_value) {
    errors->SetName("errors");
    result->errors_ = internal::FromValue<std::vector<std::unique_ptr<::headless::page::AppManifestError>>>::Parse(*errors_value, errors);
  } else {
    errors->AddError("required property missing: errors");
  }
  const base::Value* data_value = value.FindKey("data");
  if (data_value) {
    errors->SetName("data");
    result->data_ = internal::FromValue<std::string>::Parse(*data_value, errors);
  }
  const base::Value* parsed_value = value.FindKey("parsed");
  if (parsed_value) {
    errors->SetName("parsed");
    result->parsed_ = internal::FromValue<::headless::page::AppManifestParsedProperties>::Parse(*parsed_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetAppManifestResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  result->Set("errors", internal::ToValue(errors_));
  if (data_)
    result->Set("data", internal::ToValue(data_.value()));
  if (parsed_)
    result->Set("parsed", internal::ToValue(*parsed_.value()));
  return std::move(result);
}

std::unique_ptr<GetAppManifestResult> GetAppManifestResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetAppManifestResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetInstallabilityErrorsParams> GetInstallabilityErrorsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetInstallabilityErrorsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetInstallabilityErrorsParams> result(new GetInstallabilityErrorsParams());
  errors->Push();
  errors->SetName("GetInstallabilityErrorsParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetInstallabilityErrorsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetInstallabilityErrorsParams> GetInstallabilityErrorsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetInstallabilityErrorsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetInstallabilityErrorsResult> GetInstallabilityErrorsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetInstallabilityErrorsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetInstallabilityErrorsResult> result(new GetInstallabilityErrorsResult());
  errors->Push();
  errors->SetName("GetInstallabilityErrorsResult");
  const base::Value* installability_errors_value = value.FindKey("installabilityErrors");
  if (installability_errors_value) {
    errors->SetName("installabilityErrors");
    result->installability_errors_ = internal::FromValue<std::vector<std::unique_ptr<::headless::page::InstallabilityError>>>::Parse(*installability_errors_value, errors);
  } else {
    errors->AddError("required property missing: installabilityErrors");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetInstallabilityErrorsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("installabilityErrors", internal::ToValue(installability_errors_));
  return std::move(result);
}

std::unique_ptr<GetInstallabilityErrorsResult> GetInstallabilityErrorsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetInstallabilityErrorsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetManifestIconsParams> GetManifestIconsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetManifestIconsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetManifestIconsParams> result(new GetManifestIconsParams());
  errors->Push();
  errors->SetName("GetManifestIconsParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetManifestIconsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetManifestIconsParams> GetManifestIconsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetManifestIconsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetManifestIconsResult> GetManifestIconsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetManifestIconsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetManifestIconsResult> result(new GetManifestIconsResult());
  errors->Push();
  errors->SetName("GetManifestIconsResult");
  const base::Value* primary_icon_value = value.FindKey("primaryIcon");
  if (primary_icon_value) {
    errors->SetName("primaryIcon");
    result->primary_icon_ = internal::FromValue<protocol::Binary>::Parse(*primary_icon_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetManifestIconsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (primary_icon_)
    result->Set("primaryIcon", internal::ToValue(primary_icon_.value()));
  return std::move(result);
}

std::unique_ptr<GetManifestIconsResult> GetManifestIconsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetManifestIconsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCookiesParams> GetCookiesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCookiesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCookiesParams> result(new GetCookiesParams());
  errors->Push();
  errors->SetName("GetCookiesParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCookiesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetCookiesParams> GetCookiesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCookiesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCookiesResult> GetCookiesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCookiesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCookiesResult> result(new GetCookiesResult());
  errors->Push();
  errors->SetName("GetCookiesResult");
  const base::Value* cookies_value = value.FindKey("cookies");
  if (cookies_value) {
    errors->SetName("cookies");
    result->cookies_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::Cookie>>>::Parse(*cookies_value, errors);
  } else {
    errors->AddError("required property missing: cookies");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCookiesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cookies", internal::ToValue(cookies_));
  return std::move(result);
}

std::unique_ptr<GetCookiesResult> GetCookiesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCookiesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetFrameTreeParams> GetFrameTreeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetFrameTreeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetFrameTreeParams> result(new GetFrameTreeParams());
  errors->Push();
  errors->SetName("GetFrameTreeParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetFrameTreeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetFrameTreeParams> GetFrameTreeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetFrameTreeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetFrameTreeResult> GetFrameTreeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetFrameTreeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetFrameTreeResult> result(new GetFrameTreeResult());
  errors->Push();
  errors->SetName("GetFrameTreeResult");
  const base::Value* frame_tree_value = value.FindKey("frameTree");
  if (frame_tree_value) {
    errors->SetName("frameTree");
    result->frame_tree_ = internal::FromValue<::headless::page::FrameTree>::Parse(*frame_tree_value, errors);
  } else {
    errors->AddError("required property missing: frameTree");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetFrameTreeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameTree", internal::ToValue(*frame_tree_));
  return std::move(result);
}

std::unique_ptr<GetFrameTreeResult> GetFrameTreeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetFrameTreeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetLayoutMetricsParams> GetLayoutMetricsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetLayoutMetricsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetLayoutMetricsParams> result(new GetLayoutMetricsParams());
  errors->Push();
  errors->SetName("GetLayoutMetricsParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetLayoutMetricsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetLayoutMetricsParams> GetLayoutMetricsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetLayoutMetricsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetLayoutMetricsResult> GetLayoutMetricsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetLayoutMetricsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetLayoutMetricsResult> result(new GetLayoutMetricsResult());
  errors->Push();
  errors->SetName("GetLayoutMetricsResult");
  const base::Value* layout_viewport_value = value.FindKey("layoutViewport");
  if (layout_viewport_value) {
    errors->SetName("layoutViewport");
    result->layout_viewport_ = internal::FromValue<::headless::page::LayoutViewport>::Parse(*layout_viewport_value, errors);
  } else {
    errors->AddError("required property missing: layoutViewport");
  }
  const base::Value* visual_viewport_value = value.FindKey("visualViewport");
  if (visual_viewport_value) {
    errors->SetName("visualViewport");
    result->visual_viewport_ = internal::FromValue<::headless::page::VisualViewport>::Parse(*visual_viewport_value, errors);
  } else {
    errors->AddError("required property missing: visualViewport");
  }
  const base::Value* content_size_value = value.FindKey("contentSize");
  if (content_size_value) {
    errors->SetName("contentSize");
    result->content_size_ = internal::FromValue<::headless::dom::Rect>::Parse(*content_size_value, errors);
  } else {
    errors->AddError("required property missing: contentSize");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetLayoutMetricsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("layoutViewport", internal::ToValue(*layout_viewport_));
  result->Set("visualViewport", internal::ToValue(*visual_viewport_));
  result->Set("contentSize", internal::ToValue(*content_size_));
  return std::move(result);
}

std::unique_ptr<GetLayoutMetricsResult> GetLayoutMetricsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetLayoutMetricsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetNavigationHistoryParams> GetNavigationHistoryParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetNavigationHistoryParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetNavigationHistoryParams> result(new GetNavigationHistoryParams());
  errors->Push();
  errors->SetName("GetNavigationHistoryParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetNavigationHistoryParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetNavigationHistoryParams> GetNavigationHistoryParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetNavigationHistoryParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetNavigationHistoryResult> GetNavigationHistoryResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetNavigationHistoryResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetNavigationHistoryResult> result(new GetNavigationHistoryResult());
  errors->Push();
  errors->SetName("GetNavigationHistoryResult");
  const base::Value* current_index_value = value.FindKey("currentIndex");
  if (current_index_value) {
    errors->SetName("currentIndex");
    result->current_index_ = internal::FromValue<int>::Parse(*current_index_value, errors);
  } else {
    errors->AddError("required property missing: currentIndex");
  }
  const base::Value* entries_value = value.FindKey("entries");
  if (entries_value) {
    errors->SetName("entries");
    result->entries_ = internal::FromValue<std::vector<std::unique_ptr<::headless::page::NavigationEntry>>>::Parse(*entries_value, errors);
  } else {
    errors->AddError("required property missing: entries");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetNavigationHistoryResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("currentIndex", internal::ToValue(current_index_));
  result->Set("entries", internal::ToValue(entries_));
  return std::move(result);
}

std::unique_ptr<GetNavigationHistoryResult> GetNavigationHistoryResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetNavigationHistoryResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResetNavigationHistoryParams> ResetNavigationHistoryParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResetNavigationHistoryParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResetNavigationHistoryParams> result(new ResetNavigationHistoryParams());
  errors->Push();
  errors->SetName("ResetNavigationHistoryParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResetNavigationHistoryParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ResetNavigationHistoryParams> ResetNavigationHistoryParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResetNavigationHistoryParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResetNavigationHistoryResult> ResetNavigationHistoryResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResetNavigationHistoryResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResetNavigationHistoryResult> result(new ResetNavigationHistoryResult());
  errors->Push();
  errors->SetName("ResetNavigationHistoryResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResetNavigationHistoryResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ResetNavigationHistoryResult> ResetNavigationHistoryResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResetNavigationHistoryResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetResourceContentParams> GetResourceContentParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetResourceContentParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetResourceContentParams> result(new GetResourceContentParams());
  errors->Push();
  errors->SetName("GetResourceContentParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetResourceContentParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("url", internal::ToValue(url_));
  return std::move(result);
}

std::unique_ptr<GetResourceContentParams> GetResourceContentParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetResourceContentParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetResourceContentResult> GetResourceContentResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetResourceContentResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetResourceContentResult> result(new GetResourceContentResult());
  errors->Push();
  errors->SetName("GetResourceContentResult");
  const base::Value* content_value = value.FindKey("content");
  if (content_value) {
    errors->SetName("content");
    result->content_ = internal::FromValue<std::string>::Parse(*content_value, errors);
  } else {
    errors->AddError("required property missing: content");
  }
  const base::Value* base64_encoded_value = value.FindKey("base64Encoded");
  if (base64_encoded_value) {
    errors->SetName("base64Encoded");
    result->base64_encoded_ = internal::FromValue<bool>::Parse(*base64_encoded_value, errors);
  } else {
    errors->AddError("required property missing: base64Encoded");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetResourceContentResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("content", internal::ToValue(content_));
  result->Set("base64Encoded", internal::ToValue(base64_encoded_));
  return std::move(result);
}

std::unique_ptr<GetResourceContentResult> GetResourceContentResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetResourceContentResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetResourceTreeParams> GetResourceTreeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetResourceTreeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetResourceTreeParams> result(new GetResourceTreeParams());
  errors->Push();
  errors->SetName("GetResourceTreeParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetResourceTreeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetResourceTreeParams> GetResourceTreeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetResourceTreeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetResourceTreeResult> GetResourceTreeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetResourceTreeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetResourceTreeResult> result(new GetResourceTreeResult());
  errors->Push();
  errors->SetName("GetResourceTreeResult");
  const base::Value* frame_tree_value = value.FindKey("frameTree");
  if (frame_tree_value) {
    errors->SetName("frameTree");
    result->frame_tree_ = internal::FromValue<::headless::page::FrameResourceTree>::Parse(*frame_tree_value, errors);
  } else {
    errors->AddError("required property missing: frameTree");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetResourceTreeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameTree", internal::ToValue(*frame_tree_));
  return std::move(result);
}

std::unique_ptr<GetResourceTreeResult> GetResourceTreeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetResourceTreeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HandleJavaScriptDialogParams> HandleJavaScriptDialogParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HandleJavaScriptDialogParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HandleJavaScriptDialogParams> result(new HandleJavaScriptDialogParams());
  errors->Push();
  errors->SetName("HandleJavaScriptDialogParams");
  const base::Value* accept_value = value.FindKey("accept");
  if (accept_value) {
    errors->SetName("accept");
    result->accept_ = internal::FromValue<bool>::Parse(*accept_value, errors);
  } else {
    errors->AddError("required property missing: accept");
  }
  const base::Value* prompt_text_value = value.FindKey("promptText");
  if (prompt_text_value) {
    errors->SetName("promptText");
    result->prompt_text_ = internal::FromValue<std::string>::Parse(*prompt_text_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HandleJavaScriptDialogParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("accept", internal::ToValue(accept_));
  if (prompt_text_)
    result->Set("promptText", internal::ToValue(prompt_text_.value()));
  return std::move(result);
}

std::unique_ptr<HandleJavaScriptDialogParams> HandleJavaScriptDialogParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HandleJavaScriptDialogParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HandleJavaScriptDialogResult> HandleJavaScriptDialogResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HandleJavaScriptDialogResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HandleJavaScriptDialogResult> result(new HandleJavaScriptDialogResult());
  errors->Push();
  errors->SetName("HandleJavaScriptDialogResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HandleJavaScriptDialogResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<HandleJavaScriptDialogResult> HandleJavaScriptDialogResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HandleJavaScriptDialogResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NavigateParams> NavigateParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NavigateParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NavigateParams> result(new NavigateParams());
  errors->Push();
  errors->SetName("NavigateParams");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* referrer_value = value.FindKey("referrer");
  if (referrer_value) {
    errors->SetName("referrer");
    result->referrer_ = internal::FromValue<std::string>::Parse(*referrer_value, errors);
  }
  const base::Value* transition_type_value = value.FindKey("transitionType");
  if (transition_type_value) {
    errors->SetName("transitionType");
    result->transition_type_ = internal::FromValue<::headless::page::TransitionType>::Parse(*transition_type_value, errors);
  }
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  }
  const base::Value* referrer_policy_value = value.FindKey("referrerPolicy");
  if (referrer_policy_value) {
    errors->SetName("referrerPolicy");
    result->referrer_policy_ = internal::FromValue<::headless::page::ReferrerPolicy>::Parse(*referrer_policy_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NavigateParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  if (referrer_)
    result->Set("referrer", internal::ToValue(referrer_.value()));
  if (transition_type_)
    result->Set("transitionType", internal::ToValue(transition_type_.value()));
  if (frame_id_)
    result->Set("frameId", internal::ToValue(frame_id_.value()));
  if (referrer_policy_)
    result->Set("referrerPolicy", internal::ToValue(referrer_policy_.value()));
  return std::move(result);
}

std::unique_ptr<NavigateParams> NavigateParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NavigateParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NavigateResult> NavigateResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NavigateResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NavigateResult> result(new NavigateResult());
  errors->Push();
  errors->SetName("NavigateResult");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* loader_id_value = value.FindKey("loaderId");
  if (loader_id_value) {
    errors->SetName("loaderId");
    result->loader_id_ = internal::FromValue<std::string>::Parse(*loader_id_value, errors);
  }
  const base::Value* error_text_value = value.FindKey("errorText");
  if (error_text_value) {
    errors->SetName("errorText");
    result->error_text_ = internal::FromValue<std::string>::Parse(*error_text_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NavigateResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  if (loader_id_)
    result->Set("loaderId", internal::ToValue(loader_id_.value()));
  if (error_text_)
    result->Set("errorText", internal::ToValue(error_text_.value()));
  return std::move(result);
}

std::unique_ptr<NavigateResult> NavigateResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NavigateResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NavigateToHistoryEntryParams> NavigateToHistoryEntryParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NavigateToHistoryEntryParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NavigateToHistoryEntryParams> result(new NavigateToHistoryEntryParams());
  errors->Push();
  errors->SetName("NavigateToHistoryEntryParams");
  const base::Value* entry_id_value = value.FindKey("entryId");
  if (entry_id_value) {
    errors->SetName("entryId");
    result->entry_id_ = internal::FromValue<int>::Parse(*entry_id_value, errors);
  } else {
    errors->AddError("required property missing: entryId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NavigateToHistoryEntryParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("entryId", internal::ToValue(entry_id_));
  return std::move(result);
}

std::unique_ptr<NavigateToHistoryEntryParams> NavigateToHistoryEntryParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NavigateToHistoryEntryParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NavigateToHistoryEntryResult> NavigateToHistoryEntryResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NavigateToHistoryEntryResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NavigateToHistoryEntryResult> result(new NavigateToHistoryEntryResult());
  errors->Push();
  errors->SetName("NavigateToHistoryEntryResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NavigateToHistoryEntryResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<NavigateToHistoryEntryResult> NavigateToHistoryEntryResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NavigateToHistoryEntryResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PrintToPDFParams> PrintToPDFParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PrintToPDFParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PrintToPDFParams> result(new PrintToPDFParams());
  errors->Push();
  errors->SetName("PrintToPDFParams");
  const base::Value* landscape_value = value.FindKey("landscape");
  if (landscape_value) {
    errors->SetName("landscape");
    result->landscape_ = internal::FromValue<bool>::Parse(*landscape_value, errors);
  }
  const base::Value* display_header_footer_value = value.FindKey("displayHeaderFooter");
  if (display_header_footer_value) {
    errors->SetName("displayHeaderFooter");
    result->display_header_footer_ = internal::FromValue<bool>::Parse(*display_header_footer_value, errors);
  }
  const base::Value* print_background_value = value.FindKey("printBackground");
  if (print_background_value) {
    errors->SetName("printBackground");
    result->print_background_ = internal::FromValue<bool>::Parse(*print_background_value, errors);
  }
  const base::Value* scale_value = value.FindKey("scale");
  if (scale_value) {
    errors->SetName("scale");
    result->scale_ = internal::FromValue<double>::Parse(*scale_value, errors);
  }
  const base::Value* paper_width_value = value.FindKey("paperWidth");
  if (paper_width_value) {
    errors->SetName("paperWidth");
    result->paper_width_ = internal::FromValue<double>::Parse(*paper_width_value, errors);
  }
  const base::Value* paper_height_value = value.FindKey("paperHeight");
  if (paper_height_value) {
    errors->SetName("paperHeight");
    result->paper_height_ = internal::FromValue<double>::Parse(*paper_height_value, errors);
  }
  const base::Value* margin_top_value = value.FindKey("marginTop");
  if (margin_top_value) {
    errors->SetName("marginTop");
    result->margin_top_ = internal::FromValue<double>::Parse(*margin_top_value, errors);
  }
  const base::Value* margin_bottom_value = value.FindKey("marginBottom");
  if (margin_bottom_value) {
    errors->SetName("marginBottom");
    result->margin_bottom_ = internal::FromValue<double>::Parse(*margin_bottom_value, errors);
  }
  const base::Value* margin_left_value = value.FindKey("marginLeft");
  if (margin_left_value) {
    errors->SetName("marginLeft");
    result->margin_left_ = internal::FromValue<double>::Parse(*margin_left_value, errors);
  }
  const base::Value* margin_right_value = value.FindKey("marginRight");
  if (margin_right_value) {
    errors->SetName("marginRight");
    result->margin_right_ = internal::FromValue<double>::Parse(*margin_right_value, errors);
  }
  const base::Value* page_ranges_value = value.FindKey("pageRanges");
  if (page_ranges_value) {
    errors->SetName("pageRanges");
    result->page_ranges_ = internal::FromValue<std::string>::Parse(*page_ranges_value, errors);
  }
  const base::Value* ignore_invalid_page_ranges_value = value.FindKey("ignoreInvalidPageRanges");
  if (ignore_invalid_page_ranges_value) {
    errors->SetName("ignoreInvalidPageRanges");
    result->ignore_invalid_page_ranges_ = internal::FromValue<bool>::Parse(*ignore_invalid_page_ranges_value, errors);
  }
  const base::Value* header_template_value = value.FindKey("headerTemplate");
  if (header_template_value) {
    errors->SetName("headerTemplate");
    result->header_template_ = internal::FromValue<std::string>::Parse(*header_template_value, errors);
  }
  const base::Value* footer_template_value = value.FindKey("footerTemplate");
  if (footer_template_value) {
    errors->SetName("footerTemplate");
    result->footer_template_ = internal::FromValue<std::string>::Parse(*footer_template_value, errors);
  }
  const base::Value* prefercss_page_size_value = value.FindKey("preferCSSPageSize");
  if (prefercss_page_size_value) {
    errors->SetName("preferCSSPageSize");
    result->prefercss_page_size_ = internal::FromValue<bool>::Parse(*prefercss_page_size_value, errors);
  }
  const base::Value* transfer_mode_value = value.FindKey("transferMode");
  if (transfer_mode_value) {
    errors->SetName("transferMode");
    result->transfer_mode_ = internal::FromValue<::headless::page::PrintToPDFTransferMode>::Parse(*transfer_mode_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PrintToPDFParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (landscape_)
    result->Set("landscape", internal::ToValue(landscape_.value()));
  if (display_header_footer_)
    result->Set("displayHeaderFooter", internal::ToValue(display_header_footer_.value()));
  if (print_background_)
    result->Set("printBackground", internal::ToValue(print_background_.value()));
  if (scale_)
    result->Set("scale", internal::ToValue(scale_.value()));
  if (paper_width_)
    result->Set("paperWidth", internal::ToValue(paper_width_.value()));
  if (paper_height_)
    result->Set("paperHeight", internal::ToValue(paper_height_.value()));
  if (margin_top_)
    result->Set("marginTop", internal::ToValue(margin_top_.value()));
  if (margin_bottom_)
    result->Set("marginBottom", internal::ToValue(margin_bottom_.value()));
  if (margin_left_)
    result->Set("marginLeft", internal::ToValue(margin_left_.value()));
  if (margin_right_)
    result->Set("marginRight", internal::ToValue(margin_right_.value()));
  if (page_ranges_)
    result->Set("pageRanges", internal::ToValue(page_ranges_.value()));
  if (ignore_invalid_page_ranges_)
    result->Set("ignoreInvalidPageRanges", internal::ToValue(ignore_invalid_page_ranges_.value()));
  if (header_template_)
    result->Set("headerTemplate", internal::ToValue(header_template_.value()));
  if (footer_template_)
    result->Set("footerTemplate", internal::ToValue(footer_template_.value()));
  if (prefercss_page_size_)
    result->Set("preferCSSPageSize", internal::ToValue(prefercss_page_size_.value()));
  if (transfer_mode_)
    result->Set("transferMode", internal::ToValue(transfer_mode_.value()));
  return std::move(result);
}

std::unique_ptr<PrintToPDFParams> PrintToPDFParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PrintToPDFParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PrintToPDFResult> PrintToPDFResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PrintToPDFResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PrintToPDFResult> result(new PrintToPDFResult());
  errors->Push();
  errors->SetName("PrintToPDFResult");
  const base::Value* data_value = value.FindKey("data");
  if (data_value) {
    errors->SetName("data");
    result->data_ = internal::FromValue<protocol::Binary>::Parse(*data_value, errors);
  } else {
    errors->AddError("required property missing: data");
  }
  const base::Value* stream_value = value.FindKey("stream");
  if (stream_value) {
    errors->SetName("stream");
    result->stream_ = internal::FromValue<std::string>::Parse(*stream_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PrintToPDFResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("data", internal::ToValue(data_));
  if (stream_)
    result->Set("stream", internal::ToValue(stream_.value()));
  return std::move(result);
}

std::unique_ptr<PrintToPDFResult> PrintToPDFResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PrintToPDFResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReloadParams> ReloadParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReloadParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReloadParams> result(new ReloadParams());
  errors->Push();
  errors->SetName("ReloadParams");
  const base::Value* ignore_cache_value = value.FindKey("ignoreCache");
  if (ignore_cache_value) {
    errors->SetName("ignoreCache");
    result->ignore_cache_ = internal::FromValue<bool>::Parse(*ignore_cache_value, errors);
  }
  const base::Value* script_to_evaluate_on_load_value = value.FindKey("scriptToEvaluateOnLoad");
  if (script_to_evaluate_on_load_value) {
    errors->SetName("scriptToEvaluateOnLoad");
    result->script_to_evaluate_on_load_ = internal::FromValue<std::string>::Parse(*script_to_evaluate_on_load_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReloadParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (ignore_cache_)
    result->Set("ignoreCache", internal::ToValue(ignore_cache_.value()));
  if (script_to_evaluate_on_load_)
    result->Set("scriptToEvaluateOnLoad", internal::ToValue(script_to_evaluate_on_load_.value()));
  return std::move(result);
}

std::unique_ptr<ReloadParams> ReloadParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReloadParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReloadResult> ReloadResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReloadResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReloadResult> result(new ReloadResult());
  errors->Push();
  errors->SetName("ReloadResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReloadResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ReloadResult> ReloadResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReloadResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveScriptToEvaluateOnLoadParams> RemoveScriptToEvaluateOnLoadParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveScriptToEvaluateOnLoadParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveScriptToEvaluateOnLoadParams> result(new RemoveScriptToEvaluateOnLoadParams());
  errors->Push();
  errors->SetName("RemoveScriptToEvaluateOnLoadParams");
  const base::Value* identifier_value = value.FindKey("identifier");
  if (identifier_value) {
    errors->SetName("identifier");
    result->identifier_ = internal::FromValue<std::string>::Parse(*identifier_value, errors);
  } else {
    errors->AddError("required property missing: identifier");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveScriptToEvaluateOnLoadParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("identifier", internal::ToValue(identifier_));
  return std::move(result);
}

std::unique_ptr<RemoveScriptToEvaluateOnLoadParams> RemoveScriptToEvaluateOnLoadParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveScriptToEvaluateOnLoadParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveScriptToEvaluateOnLoadResult> RemoveScriptToEvaluateOnLoadResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveScriptToEvaluateOnLoadResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveScriptToEvaluateOnLoadResult> result(new RemoveScriptToEvaluateOnLoadResult());
  errors->Push();
  errors->SetName("RemoveScriptToEvaluateOnLoadResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveScriptToEvaluateOnLoadResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveScriptToEvaluateOnLoadResult> RemoveScriptToEvaluateOnLoadResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveScriptToEvaluateOnLoadResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentParams> RemoveScriptToEvaluateOnNewDocumentParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveScriptToEvaluateOnNewDocumentParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentParams> result(new RemoveScriptToEvaluateOnNewDocumentParams());
  errors->Push();
  errors->SetName("RemoveScriptToEvaluateOnNewDocumentParams");
  const base::Value* identifier_value = value.FindKey("identifier");
  if (identifier_value) {
    errors->SetName("identifier");
    result->identifier_ = internal::FromValue<std::string>::Parse(*identifier_value, errors);
  } else {
    errors->AddError("required property missing: identifier");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveScriptToEvaluateOnNewDocumentParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("identifier", internal::ToValue(identifier_));
  return std::move(result);
}

std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentParams> RemoveScriptToEvaluateOnNewDocumentParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentResult> RemoveScriptToEvaluateOnNewDocumentResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveScriptToEvaluateOnNewDocumentResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentResult> result(new RemoveScriptToEvaluateOnNewDocumentResult());
  errors->Push();
  errors->SetName("RemoveScriptToEvaluateOnNewDocumentResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveScriptToEvaluateOnNewDocumentResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentResult> RemoveScriptToEvaluateOnNewDocumentResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ScreencastFrameAckParams> ScreencastFrameAckParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ScreencastFrameAckParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ScreencastFrameAckParams> result(new ScreencastFrameAckParams());
  errors->Push();
  errors->SetName("ScreencastFrameAckParams");
  const base::Value* session_id_value = value.FindKey("sessionId");
  if (session_id_value) {
    errors->SetName("sessionId");
    result->session_id_ = internal::FromValue<int>::Parse(*session_id_value, errors);
  } else {
    errors->AddError("required property missing: sessionId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ScreencastFrameAckParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("sessionId", internal::ToValue(session_id_));
  return std::move(result);
}

std::unique_ptr<ScreencastFrameAckParams> ScreencastFrameAckParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ScreencastFrameAckParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ScreencastFrameAckResult> ScreencastFrameAckResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ScreencastFrameAckResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ScreencastFrameAckResult> result(new ScreencastFrameAckResult());
  errors->Push();
  errors->SetName("ScreencastFrameAckResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ScreencastFrameAckResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ScreencastFrameAckResult> ScreencastFrameAckResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ScreencastFrameAckResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SearchInResourceParams> SearchInResourceParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SearchInResourceParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SearchInResourceParams> result(new SearchInResourceParams());
  errors->Push();
  errors->SetName("SearchInResourceParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* query_value = value.FindKey("query");
  if (query_value) {
    errors->SetName("query");
    result->query_ = internal::FromValue<std::string>::Parse(*query_value, errors);
  } else {
    errors->AddError("required property missing: query");
  }
  const base::Value* case_sensitive_value = value.FindKey("caseSensitive");
  if (case_sensitive_value) {
    errors->SetName("caseSensitive");
    result->case_sensitive_ = internal::FromValue<bool>::Parse(*case_sensitive_value, errors);
  }
  const base::Value* is_regex_value = value.FindKey("isRegex");
  if (is_regex_value) {
    errors->SetName("isRegex");
    result->is_regex_ = internal::FromValue<bool>::Parse(*is_regex_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SearchInResourceParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("url", internal::ToValue(url_));
  result->Set("query", internal::ToValue(query_));
  if (case_sensitive_)
    result->Set("caseSensitive", internal::ToValue(case_sensitive_.value()));
  if (is_regex_)
    result->Set("isRegex", internal::ToValue(is_regex_.value()));
  return std::move(result);
}

std::unique_ptr<SearchInResourceParams> SearchInResourceParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SearchInResourceParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SearchInResourceResult> SearchInResourceResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SearchInResourceResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SearchInResourceResult> result(new SearchInResourceResult());
  errors->Push();
  errors->SetName("SearchInResourceResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<std::vector<std::unique_ptr<::headless::debugger::SearchMatch>>>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SearchInResourceResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(result_));
  return std::move(result);
}

std::unique_ptr<SearchInResourceResult> SearchInResourceResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SearchInResourceResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetAdBlockingEnabledParams> SetAdBlockingEnabledParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetAdBlockingEnabledParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetAdBlockingEnabledParams> result(new SetAdBlockingEnabledParams());
  errors->Push();
  errors->SetName("SetAdBlockingEnabledParams");
  const base::Value* enabled_value = value.FindKey("enabled");
  if (enabled_value) {
    errors->SetName("enabled");
    result->enabled_ = internal::FromValue<bool>::Parse(*enabled_value, errors);
  } else {
    errors->AddError("required property missing: enabled");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetAdBlockingEnabledParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("enabled", internal::ToValue(enabled_));
  return std::move(result);
}

std::unique_ptr<SetAdBlockingEnabledParams> SetAdBlockingEnabledParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetAdBlockingEnabledParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetAdBlockingEnabledResult> SetAdBlockingEnabledResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetAdBlockingEnabledResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetAdBlockingEnabledResult> result(new SetAdBlockingEnabledResult());
  errors->Push();
  errors->SetName("SetAdBlockingEnabledResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetAdBlockingEnabledResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetAdBlockingEnabledResult> SetAdBlockingEnabledResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetAdBlockingEnabledResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetBypassCSPParams> SetBypassCSPParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetBypassCSPParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetBypassCSPParams> result(new SetBypassCSPParams());
  errors->Push();
  errors->SetName("SetBypassCSPParams");
  const base::Value* enabled_value = value.FindKey("enabled");
  if (enabled_value) {
    errors->SetName("enabled");
    result->enabled_ = internal::FromValue<bool>::Parse(*enabled_value, errors);
  } else {
    errors->AddError("required property missing: enabled");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetBypassCSPParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("enabled", internal::ToValue(enabled_));
  return std::move(result);
}

std::unique_ptr<SetBypassCSPParams> SetBypassCSPParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetBypassCSPParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetBypassCSPResult> SetBypassCSPResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetBypassCSPResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetBypassCSPResult> result(new SetBypassCSPResult());
  errors->Push();
  errors->SetName("SetBypassCSPResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetBypassCSPResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetBypassCSPResult> SetBypassCSPResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetBypassCSPResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDeviceMetricsOverrideParams> SetDeviceMetricsOverrideParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDeviceMetricsOverrideParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDeviceMetricsOverrideParams> result(new SetDeviceMetricsOverrideParams());
  errors->Push();
  errors->SetName("SetDeviceMetricsOverrideParams");
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
  const base::Value* device_scale_factor_value = value.FindKey("deviceScaleFactor");
  if (device_scale_factor_value) {
    errors->SetName("deviceScaleFactor");
    result->device_scale_factor_ = internal::FromValue<double>::Parse(*device_scale_factor_value, errors);
  } else {
    errors->AddError("required property missing: deviceScaleFactor");
  }
  const base::Value* mobile_value = value.FindKey("mobile");
  if (mobile_value) {
    errors->SetName("mobile");
    result->mobile_ = internal::FromValue<bool>::Parse(*mobile_value, errors);
  } else {
    errors->AddError("required property missing: mobile");
  }
  const base::Value* scale_value = value.FindKey("scale");
  if (scale_value) {
    errors->SetName("scale");
    result->scale_ = internal::FromValue<double>::Parse(*scale_value, errors);
  }
  const base::Value* screen_width_value = value.FindKey("screenWidth");
  if (screen_width_value) {
    errors->SetName("screenWidth");
    result->screen_width_ = internal::FromValue<int>::Parse(*screen_width_value, errors);
  }
  const base::Value* screen_height_value = value.FindKey("screenHeight");
  if (screen_height_value) {
    errors->SetName("screenHeight");
    result->screen_height_ = internal::FromValue<int>::Parse(*screen_height_value, errors);
  }
  const base::Value* positionx_value = value.FindKey("positionX");
  if (positionx_value) {
    errors->SetName("positionX");
    result->positionx_ = internal::FromValue<int>::Parse(*positionx_value, errors);
  }
  const base::Value* positiony_value = value.FindKey("positionY");
  if (positiony_value) {
    errors->SetName("positionY");
    result->positiony_ = internal::FromValue<int>::Parse(*positiony_value, errors);
  }
  const base::Value* dont_set_visible_size_value = value.FindKey("dontSetVisibleSize");
  if (dont_set_visible_size_value) {
    errors->SetName("dontSetVisibleSize");
    result->dont_set_visible_size_ = internal::FromValue<bool>::Parse(*dont_set_visible_size_value, errors);
  }
  const base::Value* screen_orientation_value = value.FindKey("screenOrientation");
  if (screen_orientation_value) {
    errors->SetName("screenOrientation");
    result->screen_orientation_ = internal::FromValue<::headless::emulation::ScreenOrientation>::Parse(*screen_orientation_value, errors);
  }
  const base::Value* viewport_value = value.FindKey("viewport");
  if (viewport_value) {
    errors->SetName("viewport");
    result->viewport_ = internal::FromValue<::headless::page::Viewport>::Parse(*viewport_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDeviceMetricsOverrideParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("width", internal::ToValue(width_));
  result->Set("height", internal::ToValue(height_));
  result->Set("deviceScaleFactor", internal::ToValue(device_scale_factor_));
  result->Set("mobile", internal::ToValue(mobile_));
  if (scale_)
    result->Set("scale", internal::ToValue(scale_.value()));
  if (screen_width_)
    result->Set("screenWidth", internal::ToValue(screen_width_.value()));
  if (screen_height_)
    result->Set("screenHeight", internal::ToValue(screen_height_.value()));
  if (positionx_)
    result->Set("positionX", internal::ToValue(positionx_.value()));
  if (positiony_)
    result->Set("positionY", internal::ToValue(positiony_.value()));
  if (dont_set_visible_size_)
    result->Set("dontSetVisibleSize", internal::ToValue(dont_set_visible_size_.value()));
  if (screen_orientation_)
    result->Set("screenOrientation", internal::ToValue(*screen_orientation_.value()));
  if (viewport_)
    result->Set("viewport", internal::ToValue(*viewport_.value()));
  return std::move(result);
}

std::unique_ptr<SetDeviceMetricsOverrideParams> SetDeviceMetricsOverrideParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDeviceMetricsOverrideParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDeviceMetricsOverrideResult> SetDeviceMetricsOverrideResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDeviceMetricsOverrideResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDeviceMetricsOverrideResult> result(new SetDeviceMetricsOverrideResult());
  errors->Push();
  errors->SetName("SetDeviceMetricsOverrideResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDeviceMetricsOverrideResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetDeviceMetricsOverrideResult> SetDeviceMetricsOverrideResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDeviceMetricsOverrideResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDeviceOrientationOverrideParams> SetDeviceOrientationOverrideParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDeviceOrientationOverrideParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDeviceOrientationOverrideParams> result(new SetDeviceOrientationOverrideParams());
  errors->Push();
  errors->SetName("SetDeviceOrientationOverrideParams");
  const base::Value* alpha_value = value.FindKey("alpha");
  if (alpha_value) {
    errors->SetName("alpha");
    result->alpha_ = internal::FromValue<double>::Parse(*alpha_value, errors);
  } else {
    errors->AddError("required property missing: alpha");
  }
  const base::Value* beta_value = value.FindKey("beta");
  if (beta_value) {
    errors->SetName("beta");
    result->beta_ = internal::FromValue<double>::Parse(*beta_value, errors);
  } else {
    errors->AddError("required property missing: beta");
  }
  const base::Value* gamma_value = value.FindKey("gamma");
  if (gamma_value) {
    errors->SetName("gamma");
    result->gamma_ = internal::FromValue<double>::Parse(*gamma_value, errors);
  } else {
    errors->AddError("required property missing: gamma");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDeviceOrientationOverrideParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("alpha", internal::ToValue(alpha_));
  result->Set("beta", internal::ToValue(beta_));
  result->Set("gamma", internal::ToValue(gamma_));
  return std::move(result);
}

std::unique_ptr<SetDeviceOrientationOverrideParams> SetDeviceOrientationOverrideParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDeviceOrientationOverrideParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDeviceOrientationOverrideResult> SetDeviceOrientationOverrideResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDeviceOrientationOverrideResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDeviceOrientationOverrideResult> result(new SetDeviceOrientationOverrideResult());
  errors->Push();
  errors->SetName("SetDeviceOrientationOverrideResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDeviceOrientationOverrideResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetDeviceOrientationOverrideResult> SetDeviceOrientationOverrideResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDeviceOrientationOverrideResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetFontFamiliesParams> SetFontFamiliesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetFontFamiliesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetFontFamiliesParams> result(new SetFontFamiliesParams());
  errors->Push();
  errors->SetName("SetFontFamiliesParams");
  const base::Value* font_families_value = value.FindKey("fontFamilies");
  if (font_families_value) {
    errors->SetName("fontFamilies");
    result->font_families_ = internal::FromValue<::headless::page::FontFamilies>::Parse(*font_families_value, errors);
  } else {
    errors->AddError("required property missing: fontFamilies");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetFontFamiliesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("fontFamilies", internal::ToValue(*font_families_));
  return std::move(result);
}

std::unique_ptr<SetFontFamiliesParams> SetFontFamiliesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetFontFamiliesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetFontFamiliesResult> SetFontFamiliesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetFontFamiliesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetFontFamiliesResult> result(new SetFontFamiliesResult());
  errors->Push();
  errors->SetName("SetFontFamiliesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetFontFamiliesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetFontFamiliesResult> SetFontFamiliesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetFontFamiliesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetFontSizesParams> SetFontSizesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetFontSizesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetFontSizesParams> result(new SetFontSizesParams());
  errors->Push();
  errors->SetName("SetFontSizesParams");
  const base::Value* font_sizes_value = value.FindKey("fontSizes");
  if (font_sizes_value) {
    errors->SetName("fontSizes");
    result->font_sizes_ = internal::FromValue<::headless::page::FontSizes>::Parse(*font_sizes_value, errors);
  } else {
    errors->AddError("required property missing: fontSizes");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetFontSizesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("fontSizes", internal::ToValue(*font_sizes_));
  return std::move(result);
}

std::unique_ptr<SetFontSizesParams> SetFontSizesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetFontSizesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetFontSizesResult> SetFontSizesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetFontSizesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetFontSizesResult> result(new SetFontSizesResult());
  errors->Push();
  errors->SetName("SetFontSizesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetFontSizesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetFontSizesResult> SetFontSizesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetFontSizesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDocumentContentParams> SetDocumentContentParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDocumentContentParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDocumentContentParams> result(new SetDocumentContentParams());
  errors->Push();
  errors->SetName("SetDocumentContentParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* html_value = value.FindKey("html");
  if (html_value) {
    errors->SetName("html");
    result->html_ = internal::FromValue<std::string>::Parse(*html_value, errors);
  } else {
    errors->AddError("required property missing: html");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDocumentContentParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("html", internal::ToValue(html_));
  return std::move(result);
}

std::unique_ptr<SetDocumentContentParams> SetDocumentContentParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDocumentContentParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDocumentContentResult> SetDocumentContentResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDocumentContentResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDocumentContentResult> result(new SetDocumentContentResult());
  errors->Push();
  errors->SetName("SetDocumentContentResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDocumentContentResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetDocumentContentResult> SetDocumentContentResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDocumentContentResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDownloadBehaviorParams> SetDownloadBehaviorParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDownloadBehaviorParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDownloadBehaviorParams> result(new SetDownloadBehaviorParams());
  errors->Push();
  errors->SetName("SetDownloadBehaviorParams");
  const base::Value* behavior_value = value.FindKey("behavior");
  if (behavior_value) {
    errors->SetName("behavior");
    result->behavior_ = internal::FromValue<::headless::page::SetDownloadBehaviorBehavior>::Parse(*behavior_value, errors);
  } else {
    errors->AddError("required property missing: behavior");
  }
  const base::Value* download_path_value = value.FindKey("downloadPath");
  if (download_path_value) {
    errors->SetName("downloadPath");
    result->download_path_ = internal::FromValue<std::string>::Parse(*download_path_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDownloadBehaviorParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("behavior", internal::ToValue(behavior_));
  if (download_path_)
    result->Set("downloadPath", internal::ToValue(download_path_.value()));
  return std::move(result);
}

std::unique_ptr<SetDownloadBehaviorParams> SetDownloadBehaviorParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDownloadBehaviorParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDownloadBehaviorResult> SetDownloadBehaviorResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDownloadBehaviorResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDownloadBehaviorResult> result(new SetDownloadBehaviorResult());
  errors->Push();
  errors->SetName("SetDownloadBehaviorResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDownloadBehaviorResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetDownloadBehaviorResult> SetDownloadBehaviorResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDownloadBehaviorResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetGeolocationOverrideParams> SetGeolocationOverrideParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetGeolocationOverrideParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetGeolocationOverrideParams> result(new SetGeolocationOverrideParams());
  errors->Push();
  errors->SetName("SetGeolocationOverrideParams");
  const base::Value* latitude_value = value.FindKey("latitude");
  if (latitude_value) {
    errors->SetName("latitude");
    result->latitude_ = internal::FromValue<double>::Parse(*latitude_value, errors);
  }
  const base::Value* longitude_value = value.FindKey("longitude");
  if (longitude_value) {
    errors->SetName("longitude");
    result->longitude_ = internal::FromValue<double>::Parse(*longitude_value, errors);
  }
  const base::Value* accuracy_value = value.FindKey("accuracy");
  if (accuracy_value) {
    errors->SetName("accuracy");
    result->accuracy_ = internal::FromValue<double>::Parse(*accuracy_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetGeolocationOverrideParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (latitude_)
    result->Set("latitude", internal::ToValue(latitude_.value()));
  if (longitude_)
    result->Set("longitude", internal::ToValue(longitude_.value()));
  if (accuracy_)
    result->Set("accuracy", internal::ToValue(accuracy_.value()));
  return std::move(result);
}

std::unique_ptr<SetGeolocationOverrideParams> SetGeolocationOverrideParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetGeolocationOverrideParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetGeolocationOverrideResult> SetGeolocationOverrideResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetGeolocationOverrideResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetGeolocationOverrideResult> result(new SetGeolocationOverrideResult());
  errors->Push();
  errors->SetName("SetGeolocationOverrideResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetGeolocationOverrideResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetGeolocationOverrideResult> SetGeolocationOverrideResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetGeolocationOverrideResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetLifecycleEventsEnabledParams> SetLifecycleEventsEnabledParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetLifecycleEventsEnabledParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetLifecycleEventsEnabledParams> result(new SetLifecycleEventsEnabledParams());
  errors->Push();
  errors->SetName("SetLifecycleEventsEnabledParams");
  const base::Value* enabled_value = value.FindKey("enabled");
  if (enabled_value) {
    errors->SetName("enabled");
    result->enabled_ = internal::FromValue<bool>::Parse(*enabled_value, errors);
  } else {
    errors->AddError("required property missing: enabled");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetLifecycleEventsEnabledParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("enabled", internal::ToValue(enabled_));
  return std::move(result);
}

std::unique_ptr<SetLifecycleEventsEnabledParams> SetLifecycleEventsEnabledParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetLifecycleEventsEnabledParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetLifecycleEventsEnabledResult> SetLifecycleEventsEnabledResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetLifecycleEventsEnabledResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetLifecycleEventsEnabledResult> result(new SetLifecycleEventsEnabledResult());
  errors->Push();
  errors->SetName("SetLifecycleEventsEnabledResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetLifecycleEventsEnabledResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetLifecycleEventsEnabledResult> SetLifecycleEventsEnabledResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetLifecycleEventsEnabledResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetTouchEmulationEnabledParams> SetTouchEmulationEnabledParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetTouchEmulationEnabledParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetTouchEmulationEnabledParams> result(new SetTouchEmulationEnabledParams());
  errors->Push();
  errors->SetName("SetTouchEmulationEnabledParams");
  const base::Value* enabled_value = value.FindKey("enabled");
  if (enabled_value) {
    errors->SetName("enabled");
    result->enabled_ = internal::FromValue<bool>::Parse(*enabled_value, errors);
  } else {
    errors->AddError("required property missing: enabled");
  }
  const base::Value* configuration_value = value.FindKey("configuration");
  if (configuration_value) {
    errors->SetName("configuration");
    result->configuration_ = internal::FromValue<::headless::page::SetTouchEmulationEnabledConfiguration>::Parse(*configuration_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetTouchEmulationEnabledParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("enabled", internal::ToValue(enabled_));
  if (configuration_)
    result->Set("configuration", internal::ToValue(configuration_.value()));
  return std::move(result);
}

std::unique_ptr<SetTouchEmulationEnabledParams> SetTouchEmulationEnabledParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetTouchEmulationEnabledParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetTouchEmulationEnabledResult> SetTouchEmulationEnabledResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetTouchEmulationEnabledResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetTouchEmulationEnabledResult> result(new SetTouchEmulationEnabledResult());
  errors->Push();
  errors->SetName("SetTouchEmulationEnabledResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetTouchEmulationEnabledResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetTouchEmulationEnabledResult> SetTouchEmulationEnabledResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetTouchEmulationEnabledResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartScreencastParams> StartScreencastParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartScreencastParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartScreencastParams> result(new StartScreencastParams());
  errors->Push();
  errors->SetName("StartScreencastParams");
  const base::Value* format_value = value.FindKey("format");
  if (format_value) {
    errors->SetName("format");
    result->format_ = internal::FromValue<::headless::page::StartScreencastFormat>::Parse(*format_value, errors);
  }
  const base::Value* quality_value = value.FindKey("quality");
  if (quality_value) {
    errors->SetName("quality");
    result->quality_ = internal::FromValue<int>::Parse(*quality_value, errors);
  }
  const base::Value* max_width_value = value.FindKey("maxWidth");
  if (max_width_value) {
    errors->SetName("maxWidth");
    result->max_width_ = internal::FromValue<int>::Parse(*max_width_value, errors);
  }
  const base::Value* max_height_value = value.FindKey("maxHeight");
  if (max_height_value) {
    errors->SetName("maxHeight");
    result->max_height_ = internal::FromValue<int>::Parse(*max_height_value, errors);
  }
  const base::Value* every_nth_frame_value = value.FindKey("everyNthFrame");
  if (every_nth_frame_value) {
    errors->SetName("everyNthFrame");
    result->every_nth_frame_ = internal::FromValue<int>::Parse(*every_nth_frame_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartScreencastParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (format_)
    result->Set("format", internal::ToValue(format_.value()));
  if (quality_)
    result->Set("quality", internal::ToValue(quality_.value()));
  if (max_width_)
    result->Set("maxWidth", internal::ToValue(max_width_.value()));
  if (max_height_)
    result->Set("maxHeight", internal::ToValue(max_height_.value()));
  if (every_nth_frame_)
    result->Set("everyNthFrame", internal::ToValue(every_nth_frame_.value()));
  return std::move(result);
}

std::unique_ptr<StartScreencastParams> StartScreencastParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartScreencastParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartScreencastResult> StartScreencastResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartScreencastResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartScreencastResult> result(new StartScreencastResult());
  errors->Push();
  errors->SetName("StartScreencastResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartScreencastResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartScreencastResult> StartScreencastResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartScreencastResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopLoadingParams> StopLoadingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopLoadingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopLoadingParams> result(new StopLoadingParams());
  errors->Push();
  errors->SetName("StopLoadingParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopLoadingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopLoadingParams> StopLoadingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopLoadingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopLoadingResult> StopLoadingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopLoadingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopLoadingResult> result(new StopLoadingResult());
  errors->Push();
  errors->SetName("StopLoadingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopLoadingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopLoadingResult> StopLoadingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopLoadingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CrashParams> CrashParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CrashParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CrashParams> result(new CrashParams());
  errors->Push();
  errors->SetName("CrashParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CrashParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CrashParams> CrashParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CrashParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CrashResult> CrashResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CrashResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CrashResult> result(new CrashResult());
  errors->Push();
  errors->SetName("CrashResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CrashResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CrashResult> CrashResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CrashResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CloseParams> CloseParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CloseParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CloseParams> result(new CloseParams());
  errors->Push();
  errors->SetName("CloseParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CloseParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CloseParams> CloseParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CloseParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CloseResult> CloseResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CloseResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CloseResult> result(new CloseResult());
  errors->Push();
  errors->SetName("CloseResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CloseResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CloseResult> CloseResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CloseResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetWebLifecycleStateParams> SetWebLifecycleStateParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetWebLifecycleStateParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetWebLifecycleStateParams> result(new SetWebLifecycleStateParams());
  errors->Push();
  errors->SetName("SetWebLifecycleStateParams");
  const base::Value* state_value = value.FindKey("state");
  if (state_value) {
    errors->SetName("state");
    result->state_ = internal::FromValue<::headless::page::SetWebLifecycleStateState>::Parse(*state_value, errors);
  } else {
    errors->AddError("required property missing: state");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetWebLifecycleStateParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("state", internal::ToValue(state_));
  return std::move(result);
}

std::unique_ptr<SetWebLifecycleStateParams> SetWebLifecycleStateParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetWebLifecycleStateParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetWebLifecycleStateResult> SetWebLifecycleStateResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetWebLifecycleStateResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetWebLifecycleStateResult> result(new SetWebLifecycleStateResult());
  errors->Push();
  errors->SetName("SetWebLifecycleStateResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetWebLifecycleStateResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetWebLifecycleStateResult> SetWebLifecycleStateResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetWebLifecycleStateResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopScreencastParams> StopScreencastParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopScreencastParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopScreencastParams> result(new StopScreencastParams());
  errors->Push();
  errors->SetName("StopScreencastParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopScreencastParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopScreencastParams> StopScreencastParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopScreencastParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopScreencastResult> StopScreencastResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopScreencastResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopScreencastResult> result(new StopScreencastResult());
  errors->Push();
  errors->SetName("StopScreencastResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopScreencastResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopScreencastResult> StopScreencastResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopScreencastResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetProduceCompilationCacheParams> SetProduceCompilationCacheParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetProduceCompilationCacheParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetProduceCompilationCacheParams> result(new SetProduceCompilationCacheParams());
  errors->Push();
  errors->SetName("SetProduceCompilationCacheParams");
  const base::Value* enabled_value = value.FindKey("enabled");
  if (enabled_value) {
    errors->SetName("enabled");
    result->enabled_ = internal::FromValue<bool>::Parse(*enabled_value, errors);
  } else {
    errors->AddError("required property missing: enabled");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetProduceCompilationCacheParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("enabled", internal::ToValue(enabled_));
  return std::move(result);
}

std::unique_ptr<SetProduceCompilationCacheParams> SetProduceCompilationCacheParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetProduceCompilationCacheParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetProduceCompilationCacheResult> SetProduceCompilationCacheResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetProduceCompilationCacheResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetProduceCompilationCacheResult> result(new SetProduceCompilationCacheResult());
  errors->Push();
  errors->SetName("SetProduceCompilationCacheResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetProduceCompilationCacheResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetProduceCompilationCacheResult> SetProduceCompilationCacheResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetProduceCompilationCacheResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddCompilationCacheParams> AddCompilationCacheParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddCompilationCacheParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddCompilationCacheParams> result(new AddCompilationCacheParams());
  errors->Push();
  errors->SetName("AddCompilationCacheParams");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* data_value = value.FindKey("data");
  if (data_value) {
    errors->SetName("data");
    result->data_ = internal::FromValue<protocol::Binary>::Parse(*data_value, errors);
  } else {
    errors->AddError("required property missing: data");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddCompilationCacheParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  result->Set("data", internal::ToValue(data_));
  return std::move(result);
}

std::unique_ptr<AddCompilationCacheParams> AddCompilationCacheParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddCompilationCacheParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddCompilationCacheResult> AddCompilationCacheResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddCompilationCacheResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddCompilationCacheResult> result(new AddCompilationCacheResult());
  errors->Push();
  errors->SetName("AddCompilationCacheResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddCompilationCacheResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<AddCompilationCacheResult> AddCompilationCacheResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddCompilationCacheResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearCompilationCacheParams> ClearCompilationCacheParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearCompilationCacheParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearCompilationCacheParams> result(new ClearCompilationCacheParams());
  errors->Push();
  errors->SetName("ClearCompilationCacheParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearCompilationCacheParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearCompilationCacheParams> ClearCompilationCacheParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearCompilationCacheParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearCompilationCacheResult> ClearCompilationCacheResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearCompilationCacheResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearCompilationCacheResult> result(new ClearCompilationCacheResult());
  errors->Push();
  errors->SetName("ClearCompilationCacheResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearCompilationCacheResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearCompilationCacheResult> ClearCompilationCacheResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearCompilationCacheResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GenerateTestReportParams> GenerateTestReportParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GenerateTestReportParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GenerateTestReportParams> result(new GenerateTestReportParams());
  errors->Push();
  errors->SetName("GenerateTestReportParams");
  const base::Value* message_value = value.FindKey("message");
  if (message_value) {
    errors->SetName("message");
    result->message_ = internal::FromValue<std::string>::Parse(*message_value, errors);
  } else {
    errors->AddError("required property missing: message");
  }
  const base::Value* group_value = value.FindKey("group");
  if (group_value) {
    errors->SetName("group");
    result->group_ = internal::FromValue<std::string>::Parse(*group_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GenerateTestReportParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("message", internal::ToValue(message_));
  if (group_)
    result->Set("group", internal::ToValue(group_.value()));
  return std::move(result);
}

std::unique_ptr<GenerateTestReportParams> GenerateTestReportParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GenerateTestReportParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GenerateTestReportResult> GenerateTestReportResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GenerateTestReportResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GenerateTestReportResult> result(new GenerateTestReportResult());
  errors->Push();
  errors->SetName("GenerateTestReportResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GenerateTestReportResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GenerateTestReportResult> GenerateTestReportResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GenerateTestReportResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WaitForDebuggerParams> WaitForDebuggerParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WaitForDebuggerParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WaitForDebuggerParams> result(new WaitForDebuggerParams());
  errors->Push();
  errors->SetName("WaitForDebuggerParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WaitForDebuggerParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<WaitForDebuggerParams> WaitForDebuggerParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WaitForDebuggerParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WaitForDebuggerResult> WaitForDebuggerResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WaitForDebuggerResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WaitForDebuggerResult> result(new WaitForDebuggerResult());
  errors->Push();
  errors->SetName("WaitForDebuggerResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WaitForDebuggerResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<WaitForDebuggerResult> WaitForDebuggerResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WaitForDebuggerResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetInterceptFileChooserDialogParams> SetInterceptFileChooserDialogParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetInterceptFileChooserDialogParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetInterceptFileChooserDialogParams> result(new SetInterceptFileChooserDialogParams());
  errors->Push();
  errors->SetName("SetInterceptFileChooserDialogParams");
  const base::Value* enabled_value = value.FindKey("enabled");
  if (enabled_value) {
    errors->SetName("enabled");
    result->enabled_ = internal::FromValue<bool>::Parse(*enabled_value, errors);
  } else {
    errors->AddError("required property missing: enabled");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetInterceptFileChooserDialogParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("enabled", internal::ToValue(enabled_));
  return std::move(result);
}

std::unique_ptr<SetInterceptFileChooserDialogParams> SetInterceptFileChooserDialogParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetInterceptFileChooserDialogParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetInterceptFileChooserDialogResult> SetInterceptFileChooserDialogResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetInterceptFileChooserDialogResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetInterceptFileChooserDialogResult> result(new SetInterceptFileChooserDialogResult());
  errors->Push();
  errors->SetName("SetInterceptFileChooserDialogResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetInterceptFileChooserDialogResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetInterceptFileChooserDialogResult> SetInterceptFileChooserDialogResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetInterceptFileChooserDialogResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DomContentEventFiredParams> DomContentEventFiredParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DomContentEventFiredParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DomContentEventFiredParams> result(new DomContentEventFiredParams());
  errors->Push();
  errors->SetName("DomContentEventFiredParams");
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DomContentEventFiredParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("timestamp", internal::ToValue(timestamp_));
  return std::move(result);
}

std::unique_ptr<DomContentEventFiredParams> DomContentEventFiredParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DomContentEventFiredParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FileChooserOpenedParams> FileChooserOpenedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FileChooserOpenedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FileChooserOpenedParams> result(new FileChooserOpenedParams());
  errors->Push();
  errors->SetName("FileChooserOpenedParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  } else {
    errors->AddError("required property missing: backendNodeId");
  }
  const base::Value* mode_value = value.FindKey("mode");
  if (mode_value) {
    errors->SetName("mode");
    result->mode_ = internal::FromValue<::headless::page::FileChooserOpenedMode>::Parse(*mode_value, errors);
  } else {
    errors->AddError("required property missing: mode");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FileChooserOpenedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("backendNodeId", internal::ToValue(backend_node_id_));
  result->Set("mode", internal::ToValue(mode_));
  return std::move(result);
}

std::unique_ptr<FileChooserOpenedParams> FileChooserOpenedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FileChooserOpenedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameAttachedParams> FrameAttachedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameAttachedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameAttachedParams> result(new FrameAttachedParams());
  errors->Push();
  errors->SetName("FrameAttachedParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* parent_frame_id_value = value.FindKey("parentFrameId");
  if (parent_frame_id_value) {
    errors->SetName("parentFrameId");
    result->parent_frame_id_ = internal::FromValue<std::string>::Parse(*parent_frame_id_value, errors);
  } else {
    errors->AddError("required property missing: parentFrameId");
  }
  const base::Value* stack_value = value.FindKey("stack");
  if (stack_value) {
    errors->SetName("stack");
    result->stack_ = internal::FromValue<::headless::runtime::StackTrace>::Parse(*stack_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FrameAttachedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("parentFrameId", internal::ToValue(parent_frame_id_));
  if (stack_)
    result->Set("stack", internal::ToValue(*stack_.value()));
  return std::move(result);
}

std::unique_ptr<FrameAttachedParams> FrameAttachedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameAttachedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameClearedScheduledNavigationParams> FrameClearedScheduledNavigationParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameClearedScheduledNavigationParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameClearedScheduledNavigationParams> result(new FrameClearedScheduledNavigationParams());
  errors->Push();
  errors->SetName("FrameClearedScheduledNavigationParams");
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

std::unique_ptr<base::Value> FrameClearedScheduledNavigationParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  return std::move(result);
}

std::unique_ptr<FrameClearedScheduledNavigationParams> FrameClearedScheduledNavigationParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameClearedScheduledNavigationParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameDetachedParams> FrameDetachedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameDetachedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameDetachedParams> result(new FrameDetachedParams());
  errors->Push();
  errors->SetName("FrameDetachedParams");
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

std::unique_ptr<base::Value> FrameDetachedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  return std::move(result);
}

std::unique_ptr<FrameDetachedParams> FrameDetachedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameDetachedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameNavigatedParams> FrameNavigatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameNavigatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameNavigatedParams> result(new FrameNavigatedParams());
  errors->Push();
  errors->SetName("FrameNavigatedParams");
  const base::Value* frame_value = value.FindKey("frame");
  if (frame_value) {
    errors->SetName("frame");
    result->frame_ = internal::FromValue<::headless::page::Frame>::Parse(*frame_value, errors);
  } else {
    errors->AddError("required property missing: frame");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FrameNavigatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frame", internal::ToValue(*frame_));
  return std::move(result);
}

std::unique_ptr<FrameNavigatedParams> FrameNavigatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameNavigatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameResizedParams> FrameResizedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameResizedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameResizedParams> result(new FrameResizedParams());
  errors->Push();
  errors->SetName("FrameResizedParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FrameResizedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<FrameResizedParams> FrameResizedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameResizedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameRequestedNavigationParams> FrameRequestedNavigationParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameRequestedNavigationParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameRequestedNavigationParams> result(new FrameRequestedNavigationParams());
  errors->Push();
  errors->SetName("FrameRequestedNavigationParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* reason_value = value.FindKey("reason");
  if (reason_value) {
    errors->SetName("reason");
    result->reason_ = internal::FromValue<::headless::page::ClientNavigationReason>::Parse(*reason_value, errors);
  } else {
    errors->AddError("required property missing: reason");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* disposition_value = value.FindKey("disposition");
  if (disposition_value) {
    errors->SetName("disposition");
    result->disposition_ = internal::FromValue<::headless::page::ClientNavigationDisposition>::Parse(*disposition_value, errors);
  } else {
    errors->AddError("required property missing: disposition");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FrameRequestedNavigationParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("reason", internal::ToValue(reason_));
  result->Set("url", internal::ToValue(url_));
  result->Set("disposition", internal::ToValue(disposition_));
  return std::move(result);
}

std::unique_ptr<FrameRequestedNavigationParams> FrameRequestedNavigationParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameRequestedNavigationParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameScheduledNavigationParams> FrameScheduledNavigationParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameScheduledNavigationParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameScheduledNavigationParams> result(new FrameScheduledNavigationParams());
  errors->Push();
  errors->SetName("FrameScheduledNavigationParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* delay_value = value.FindKey("delay");
  if (delay_value) {
    errors->SetName("delay");
    result->delay_ = internal::FromValue<double>::Parse(*delay_value, errors);
  } else {
    errors->AddError("required property missing: delay");
  }
  const base::Value* reason_value = value.FindKey("reason");
  if (reason_value) {
    errors->SetName("reason");
    result->reason_ = internal::FromValue<::headless::page::ClientNavigationReason>::Parse(*reason_value, errors);
  } else {
    errors->AddError("required property missing: reason");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FrameScheduledNavigationParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("delay", internal::ToValue(delay_));
  result->Set("reason", internal::ToValue(reason_));
  result->Set("url", internal::ToValue(url_));
  return std::move(result);
}

std::unique_ptr<FrameScheduledNavigationParams> FrameScheduledNavigationParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameScheduledNavigationParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameStartedLoadingParams> FrameStartedLoadingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameStartedLoadingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameStartedLoadingParams> result(new FrameStartedLoadingParams());
  errors->Push();
  errors->SetName("FrameStartedLoadingParams");
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

std::unique_ptr<base::Value> FrameStartedLoadingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  return std::move(result);
}

std::unique_ptr<FrameStartedLoadingParams> FrameStartedLoadingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameStartedLoadingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameStoppedLoadingParams> FrameStoppedLoadingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameStoppedLoadingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameStoppedLoadingParams> result(new FrameStoppedLoadingParams());
  errors->Push();
  errors->SetName("FrameStoppedLoadingParams");
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

std::unique_ptr<base::Value> FrameStoppedLoadingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  return std::move(result);
}

std::unique_ptr<FrameStoppedLoadingParams> FrameStoppedLoadingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameStoppedLoadingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DownloadWillBeginParams> DownloadWillBeginParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DownloadWillBeginParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DownloadWillBeginParams> result(new DownloadWillBeginParams());
  errors->Push();
  errors->SetName("DownloadWillBeginParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* guid_value = value.FindKey("guid");
  if (guid_value) {
    errors->SetName("guid");
    result->guid_ = internal::FromValue<std::string>::Parse(*guid_value, errors);
  } else {
    errors->AddError("required property missing: guid");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* suggested_filename_value = value.FindKey("suggestedFilename");
  if (suggested_filename_value) {
    errors->SetName("suggestedFilename");
    result->suggested_filename_ = internal::FromValue<std::string>::Parse(*suggested_filename_value, errors);
  } else {
    errors->AddError("required property missing: suggestedFilename");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DownloadWillBeginParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("guid", internal::ToValue(guid_));
  result->Set("url", internal::ToValue(url_));
  result->Set("suggestedFilename", internal::ToValue(suggested_filename_));
  return std::move(result);
}

std::unique_ptr<DownloadWillBeginParams> DownloadWillBeginParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DownloadWillBeginParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DownloadProgressParams> DownloadProgressParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DownloadProgressParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DownloadProgressParams> result(new DownloadProgressParams());
  errors->Push();
  errors->SetName("DownloadProgressParams");
  const base::Value* guid_value = value.FindKey("guid");
  if (guid_value) {
    errors->SetName("guid");
    result->guid_ = internal::FromValue<std::string>::Parse(*guid_value, errors);
  } else {
    errors->AddError("required property missing: guid");
  }
  const base::Value* total_bytes_value = value.FindKey("totalBytes");
  if (total_bytes_value) {
    errors->SetName("totalBytes");
    result->total_bytes_ = internal::FromValue<double>::Parse(*total_bytes_value, errors);
  } else {
    errors->AddError("required property missing: totalBytes");
  }
  const base::Value* received_bytes_value = value.FindKey("receivedBytes");
  if (received_bytes_value) {
    errors->SetName("receivedBytes");
    result->received_bytes_ = internal::FromValue<double>::Parse(*received_bytes_value, errors);
  } else {
    errors->AddError("required property missing: receivedBytes");
  }
  const base::Value* state_value = value.FindKey("state");
  if (state_value) {
    errors->SetName("state");
    result->state_ = internal::FromValue<::headless::page::DownloadProgressState>::Parse(*state_value, errors);
  } else {
    errors->AddError("required property missing: state");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DownloadProgressParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("guid", internal::ToValue(guid_));
  result->Set("totalBytes", internal::ToValue(total_bytes_));
  result->Set("receivedBytes", internal::ToValue(received_bytes_));
  result->Set("state", internal::ToValue(state_));
  return std::move(result);
}

std::unique_ptr<DownloadProgressParams> DownloadProgressParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DownloadProgressParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InterstitialHiddenParams> InterstitialHiddenParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InterstitialHiddenParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InterstitialHiddenParams> result(new InterstitialHiddenParams());
  errors->Push();
  errors->SetName("InterstitialHiddenParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InterstitialHiddenParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<InterstitialHiddenParams> InterstitialHiddenParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InterstitialHiddenParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InterstitialShownParams> InterstitialShownParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InterstitialShownParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InterstitialShownParams> result(new InterstitialShownParams());
  errors->Push();
  errors->SetName("InterstitialShownParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InterstitialShownParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<InterstitialShownParams> InterstitialShownParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InterstitialShownParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<JavascriptDialogClosedParams> JavascriptDialogClosedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("JavascriptDialogClosedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<JavascriptDialogClosedParams> result(new JavascriptDialogClosedParams());
  errors->Push();
  errors->SetName("JavascriptDialogClosedParams");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<bool>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  const base::Value* user_input_value = value.FindKey("userInput");
  if (user_input_value) {
    errors->SetName("userInput");
    result->user_input_ = internal::FromValue<std::string>::Parse(*user_input_value, errors);
  } else {
    errors->AddError("required property missing: userInput");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> JavascriptDialogClosedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(result_));
  result->Set("userInput", internal::ToValue(user_input_));
  return std::move(result);
}

std::unique_ptr<JavascriptDialogClosedParams> JavascriptDialogClosedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<JavascriptDialogClosedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<JavascriptDialogOpeningParams> JavascriptDialogOpeningParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("JavascriptDialogOpeningParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<JavascriptDialogOpeningParams> result(new JavascriptDialogOpeningParams());
  errors->Push();
  errors->SetName("JavascriptDialogOpeningParams");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* message_value = value.FindKey("message");
  if (message_value) {
    errors->SetName("message");
    result->message_ = internal::FromValue<std::string>::Parse(*message_value, errors);
  } else {
    errors->AddError("required property missing: message");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::page::DialogType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* has_browser_handler_value = value.FindKey("hasBrowserHandler");
  if (has_browser_handler_value) {
    errors->SetName("hasBrowserHandler");
    result->has_browser_handler_ = internal::FromValue<bool>::Parse(*has_browser_handler_value, errors);
  } else {
    errors->AddError("required property missing: hasBrowserHandler");
  }
  const base::Value* default_prompt_value = value.FindKey("defaultPrompt");
  if (default_prompt_value) {
    errors->SetName("defaultPrompt");
    result->default_prompt_ = internal::FromValue<std::string>::Parse(*default_prompt_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> JavascriptDialogOpeningParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  result->Set("message", internal::ToValue(message_));
  result->Set("type", internal::ToValue(type_));
  result->Set("hasBrowserHandler", internal::ToValue(has_browser_handler_));
  if (default_prompt_)
    result->Set("defaultPrompt", internal::ToValue(default_prompt_.value()));
  return std::move(result);
}

std::unique_ptr<JavascriptDialogOpeningParams> JavascriptDialogOpeningParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<JavascriptDialogOpeningParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<LifecycleEventParams> LifecycleEventParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LifecycleEventParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LifecycleEventParams> result(new LifecycleEventParams());
  errors->Push();
  errors->SetName("LifecycleEventParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* loader_id_value = value.FindKey("loaderId");
  if (loader_id_value) {
    errors->SetName("loaderId");
    result->loader_id_ = internal::FromValue<std::string>::Parse(*loader_id_value, errors);
  } else {
    errors->AddError("required property missing: loaderId");
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LifecycleEventParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("loaderId", internal::ToValue(loader_id_));
  result->Set("name", internal::ToValue(name_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  return std::move(result);
}

std::unique_ptr<LifecycleEventParams> LifecycleEventParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LifecycleEventParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<LoadEventFiredParams> LoadEventFiredParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LoadEventFiredParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LoadEventFiredParams> result(new LoadEventFiredParams());
  errors->Push();
  errors->SetName("LoadEventFiredParams");
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LoadEventFiredParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("timestamp", internal::ToValue(timestamp_));
  return std::move(result);
}

std::unique_ptr<LoadEventFiredParams> LoadEventFiredParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LoadEventFiredParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NavigatedWithinDocumentParams> NavigatedWithinDocumentParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NavigatedWithinDocumentParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NavigatedWithinDocumentParams> result(new NavigatedWithinDocumentParams());
  errors->Push();
  errors->SetName("NavigatedWithinDocumentParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NavigatedWithinDocumentParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("url", internal::ToValue(url_));
  return std::move(result);
}

std::unique_ptr<NavigatedWithinDocumentParams> NavigatedWithinDocumentParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NavigatedWithinDocumentParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ScreencastFrameParams> ScreencastFrameParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ScreencastFrameParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ScreencastFrameParams> result(new ScreencastFrameParams());
  errors->Push();
  errors->SetName("ScreencastFrameParams");
  const base::Value* data_value = value.FindKey("data");
  if (data_value) {
    errors->SetName("data");
    result->data_ = internal::FromValue<protocol::Binary>::Parse(*data_value, errors);
  } else {
    errors->AddError("required property missing: data");
  }
  const base::Value* metadata_value = value.FindKey("metadata");
  if (metadata_value) {
    errors->SetName("metadata");
    result->metadata_ = internal::FromValue<::headless::page::ScreencastFrameMetadata>::Parse(*metadata_value, errors);
  } else {
    errors->AddError("required property missing: metadata");
  }
  const base::Value* session_id_value = value.FindKey("sessionId");
  if (session_id_value) {
    errors->SetName("sessionId");
    result->session_id_ = internal::FromValue<int>::Parse(*session_id_value, errors);
  } else {
    errors->AddError("required property missing: sessionId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ScreencastFrameParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("data", internal::ToValue(data_));
  result->Set("metadata", internal::ToValue(*metadata_));
  result->Set("sessionId", internal::ToValue(session_id_));
  return std::move(result);
}

std::unique_ptr<ScreencastFrameParams> ScreencastFrameParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ScreencastFrameParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ScreencastVisibilityChangedParams> ScreencastVisibilityChangedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ScreencastVisibilityChangedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ScreencastVisibilityChangedParams> result(new ScreencastVisibilityChangedParams());
  errors->Push();
  errors->SetName("ScreencastVisibilityChangedParams");
  const base::Value* visible_value = value.FindKey("visible");
  if (visible_value) {
    errors->SetName("visible");
    result->visible_ = internal::FromValue<bool>::Parse(*visible_value, errors);
  } else {
    errors->AddError("required property missing: visible");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ScreencastVisibilityChangedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("visible", internal::ToValue(visible_));
  return std::move(result);
}

std::unique_ptr<ScreencastVisibilityChangedParams> ScreencastVisibilityChangedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ScreencastVisibilityChangedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WindowOpenParams> WindowOpenParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WindowOpenParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WindowOpenParams> result(new WindowOpenParams());
  errors->Push();
  errors->SetName("WindowOpenParams");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* window_name_value = value.FindKey("windowName");
  if (window_name_value) {
    errors->SetName("windowName");
    result->window_name_ = internal::FromValue<std::string>::Parse(*window_name_value, errors);
  } else {
    errors->AddError("required property missing: windowName");
  }
  const base::Value* window_features_value = value.FindKey("windowFeatures");
  if (window_features_value) {
    errors->SetName("windowFeatures");
    result->window_features_ = internal::FromValue<std::vector<std::string>>::Parse(*window_features_value, errors);
  } else {
    errors->AddError("required property missing: windowFeatures");
  }
  const base::Value* user_gesture_value = value.FindKey("userGesture");
  if (user_gesture_value) {
    errors->SetName("userGesture");
    result->user_gesture_ = internal::FromValue<bool>::Parse(*user_gesture_value, errors);
  } else {
    errors->AddError("required property missing: userGesture");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WindowOpenParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  result->Set("windowName", internal::ToValue(window_name_));
  result->Set("windowFeatures", internal::ToValue(window_features_));
  result->Set("userGesture", internal::ToValue(user_gesture_));
  return std::move(result);
}

std::unique_ptr<WindowOpenParams> WindowOpenParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WindowOpenParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CompilationCacheProducedParams> CompilationCacheProducedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CompilationCacheProducedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CompilationCacheProducedParams> result(new CompilationCacheProducedParams());
  errors->Push();
  errors->SetName("CompilationCacheProducedParams");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* data_value = value.FindKey("data");
  if (data_value) {
    errors->SetName("data");
    result->data_ = internal::FromValue<protocol::Binary>::Parse(*data_value, errors);
  } else {
    errors->AddError("required property missing: data");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CompilationCacheProducedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  result->Set("data", internal::ToValue(data_));
  return std::move(result);
}

std::unique_ptr<CompilationCacheProducedParams> CompilationCacheProducedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CompilationCacheProducedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace page
}  // namespace headless
