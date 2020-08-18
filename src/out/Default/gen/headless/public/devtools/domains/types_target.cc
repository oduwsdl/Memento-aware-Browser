// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_browser.h"
#include "headless/public/devtools/domains/types_target.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_browser.h"
#include "headless/public/devtools/internal/type_conversions_target.h"

namespace headless {

namespace target {

std::unique_ptr<TargetInfo> TargetInfo::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TargetInfo");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TargetInfo> result(new TargetInfo());
  errors->Push();
  errors->SetName("TargetInfo");
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  } else {
    errors->AddError("required property missing: targetId");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<std::string>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* title_value = value.FindKey("title");
  if (title_value) {
    errors->SetName("title");
    result->title_ = internal::FromValue<std::string>::Parse(*title_value, errors);
  } else {
    errors->AddError("required property missing: title");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* attached_value = value.FindKey("attached");
  if (attached_value) {
    errors->SetName("attached");
    result->attached_ = internal::FromValue<bool>::Parse(*attached_value, errors);
  } else {
    errors->AddError("required property missing: attached");
  }
  const base::Value* opener_id_value = value.FindKey("openerId");
  if (opener_id_value) {
    errors->SetName("openerId");
    result->opener_id_ = internal::FromValue<std::string>::Parse(*opener_id_value, errors);
  }
  const base::Value* browser_context_id_value = value.FindKey("browserContextId");
  if (browser_context_id_value) {
    errors->SetName("browserContextId");
    result->browser_context_id_ = internal::FromValue<std::string>::Parse(*browser_context_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TargetInfo::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetId", internal::ToValue(target_id_));
  result->Set("type", internal::ToValue(type_));
  result->Set("title", internal::ToValue(title_));
  result->Set("url", internal::ToValue(url_));
  result->Set("attached", internal::ToValue(attached_));
  if (opener_id_)
    result->Set("openerId", internal::ToValue(opener_id_.value()));
  if (browser_context_id_)
    result->Set("browserContextId", internal::ToValue(browser_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<TargetInfo> TargetInfo::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TargetInfo> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoteLocation> RemoteLocation::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoteLocation");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoteLocation> result(new RemoteLocation());
  errors->Push();
  errors->SetName("RemoteLocation");
  const base::Value* host_value = value.FindKey("host");
  if (host_value) {
    errors->SetName("host");
    result->host_ = internal::FromValue<std::string>::Parse(*host_value, errors);
  } else {
    errors->AddError("required property missing: host");
  }
  const base::Value* port_value = value.FindKey("port");
  if (port_value) {
    errors->SetName("port");
    result->port_ = internal::FromValue<int>::Parse(*port_value, errors);
  } else {
    errors->AddError("required property missing: port");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoteLocation::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("host", internal::ToValue(host_));
  result->Set("port", internal::ToValue(port_));
  return std::move(result);
}

std::unique_ptr<RemoteLocation> RemoteLocation::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoteLocation> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ActivateTargetParams> ActivateTargetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ActivateTargetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ActivateTargetParams> result(new ActivateTargetParams());
  errors->Push();
  errors->SetName("ActivateTargetParams");
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  } else {
    errors->AddError("required property missing: targetId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ActivateTargetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetId", internal::ToValue(target_id_));
  return std::move(result);
}

std::unique_ptr<ActivateTargetParams> ActivateTargetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ActivateTargetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ActivateTargetResult> ActivateTargetResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ActivateTargetResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ActivateTargetResult> result(new ActivateTargetResult());
  errors->Push();
  errors->SetName("ActivateTargetResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ActivateTargetResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ActivateTargetResult> ActivateTargetResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ActivateTargetResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AttachToTargetParams> AttachToTargetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AttachToTargetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AttachToTargetParams> result(new AttachToTargetParams());
  errors->Push();
  errors->SetName("AttachToTargetParams");
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  } else {
    errors->AddError("required property missing: targetId");
  }
  const base::Value* flatten_value = value.FindKey("flatten");
  if (flatten_value) {
    errors->SetName("flatten");
    result->flatten_ = internal::FromValue<bool>::Parse(*flatten_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AttachToTargetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetId", internal::ToValue(target_id_));
  if (flatten_)
    result->Set("flatten", internal::ToValue(flatten_.value()));
  return std::move(result);
}

std::unique_ptr<AttachToTargetParams> AttachToTargetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AttachToTargetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AttachToTargetResult> AttachToTargetResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AttachToTargetResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AttachToTargetResult> result(new AttachToTargetResult());
  errors->Push();
  errors->SetName("AttachToTargetResult");
  const base::Value* session_id_value = value.FindKey("sessionId");
  if (session_id_value) {
    errors->SetName("sessionId");
    result->session_id_ = internal::FromValue<std::string>::Parse(*session_id_value, errors);
  } else {
    errors->AddError("required property missing: sessionId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AttachToTargetResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("sessionId", internal::ToValue(session_id_));
  return std::move(result);
}

std::unique_ptr<AttachToTargetResult> AttachToTargetResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AttachToTargetResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AttachToBrowserTargetParams> AttachToBrowserTargetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AttachToBrowserTargetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AttachToBrowserTargetParams> result(new AttachToBrowserTargetParams());
  errors->Push();
  errors->SetName("AttachToBrowserTargetParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AttachToBrowserTargetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<AttachToBrowserTargetParams> AttachToBrowserTargetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AttachToBrowserTargetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AttachToBrowserTargetResult> AttachToBrowserTargetResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AttachToBrowserTargetResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AttachToBrowserTargetResult> result(new AttachToBrowserTargetResult());
  errors->Push();
  errors->SetName("AttachToBrowserTargetResult");
  const base::Value* session_id_value = value.FindKey("sessionId");
  if (session_id_value) {
    errors->SetName("sessionId");
    result->session_id_ = internal::FromValue<std::string>::Parse(*session_id_value, errors);
  } else {
    errors->AddError("required property missing: sessionId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AttachToBrowserTargetResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("sessionId", internal::ToValue(session_id_));
  return std::move(result);
}

std::unique_ptr<AttachToBrowserTargetResult> AttachToBrowserTargetResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AttachToBrowserTargetResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CloseTargetParams> CloseTargetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CloseTargetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CloseTargetParams> result(new CloseTargetParams());
  errors->Push();
  errors->SetName("CloseTargetParams");
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  } else {
    errors->AddError("required property missing: targetId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CloseTargetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetId", internal::ToValue(target_id_));
  return std::move(result);
}

std::unique_ptr<CloseTargetParams> CloseTargetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CloseTargetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CloseTargetResult> CloseTargetResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CloseTargetResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CloseTargetResult> result(new CloseTargetResult());
  errors->Push();
  errors->SetName("CloseTargetResult");
  const base::Value* success_value = value.FindKey("success");
  if (success_value) {
    errors->SetName("success");
    result->success_ = internal::FromValue<bool>::Parse(*success_value, errors);
  } else {
    errors->AddError("required property missing: success");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CloseTargetResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("success", internal::ToValue(success_));
  return std::move(result);
}

std::unique_ptr<CloseTargetResult> CloseTargetResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CloseTargetResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ExposeDevToolsProtocolParams> ExposeDevToolsProtocolParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ExposeDevToolsProtocolParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ExposeDevToolsProtocolParams> result(new ExposeDevToolsProtocolParams());
  errors->Push();
  errors->SetName("ExposeDevToolsProtocolParams");
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  } else {
    errors->AddError("required property missing: targetId");
  }
  const base::Value* binding_name_value = value.FindKey("bindingName");
  if (binding_name_value) {
    errors->SetName("bindingName");
    result->binding_name_ = internal::FromValue<std::string>::Parse(*binding_name_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ExposeDevToolsProtocolParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetId", internal::ToValue(target_id_));
  if (binding_name_)
    result->Set("bindingName", internal::ToValue(binding_name_.value()));
  return std::move(result);
}

std::unique_ptr<ExposeDevToolsProtocolParams> ExposeDevToolsProtocolParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ExposeDevToolsProtocolParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ExposeDevToolsProtocolResult> ExposeDevToolsProtocolResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ExposeDevToolsProtocolResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ExposeDevToolsProtocolResult> result(new ExposeDevToolsProtocolResult());
  errors->Push();
  errors->SetName("ExposeDevToolsProtocolResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ExposeDevToolsProtocolResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ExposeDevToolsProtocolResult> ExposeDevToolsProtocolResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ExposeDevToolsProtocolResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CreateBrowserContextParams> CreateBrowserContextParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CreateBrowserContextParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CreateBrowserContextParams> result(new CreateBrowserContextParams());
  errors->Push();
  errors->SetName("CreateBrowserContextParams");
  const base::Value* dispose_on_detach_value = value.FindKey("disposeOnDetach");
  if (dispose_on_detach_value) {
    errors->SetName("disposeOnDetach");
    result->dispose_on_detach_ = internal::FromValue<bool>::Parse(*dispose_on_detach_value, errors);
  }
  const base::Value* proxy_server_value = value.FindKey("proxyServer");
  if (proxy_server_value) {
    errors->SetName("proxyServer");
    result->proxy_server_ = internal::FromValue<std::string>::Parse(*proxy_server_value, errors);
  }
  const base::Value* proxy_bypass_list_value = value.FindKey("proxyBypassList");
  if (proxy_bypass_list_value) {
    errors->SetName("proxyBypassList");
    result->proxy_bypass_list_ = internal::FromValue<std::string>::Parse(*proxy_bypass_list_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CreateBrowserContextParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (dispose_on_detach_)
    result->Set("disposeOnDetach", internal::ToValue(dispose_on_detach_.value()));
  if (proxy_server_)
    result->Set("proxyServer", internal::ToValue(proxy_server_.value()));
  if (proxy_bypass_list_)
    result->Set("proxyBypassList", internal::ToValue(proxy_bypass_list_.value()));
  return std::move(result);
}

std::unique_ptr<CreateBrowserContextParams> CreateBrowserContextParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CreateBrowserContextParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CreateBrowserContextResult> CreateBrowserContextResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CreateBrowserContextResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CreateBrowserContextResult> result(new CreateBrowserContextResult());
  errors->Push();
  errors->SetName("CreateBrowserContextResult");
  const base::Value* browser_context_id_value = value.FindKey("browserContextId");
  if (browser_context_id_value) {
    errors->SetName("browserContextId");
    result->browser_context_id_ = internal::FromValue<std::string>::Parse(*browser_context_id_value, errors);
  } else {
    errors->AddError("required property missing: browserContextId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CreateBrowserContextResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("browserContextId", internal::ToValue(browser_context_id_));
  return std::move(result);
}

std::unique_ptr<CreateBrowserContextResult> CreateBrowserContextResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CreateBrowserContextResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBrowserContextsParams> GetBrowserContextsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBrowserContextsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBrowserContextsParams> result(new GetBrowserContextsParams());
  errors->Push();
  errors->SetName("GetBrowserContextsParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBrowserContextsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetBrowserContextsParams> GetBrowserContextsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBrowserContextsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBrowserContextsResult> GetBrowserContextsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBrowserContextsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBrowserContextsResult> result(new GetBrowserContextsResult());
  errors->Push();
  errors->SetName("GetBrowserContextsResult");
  const base::Value* browser_context_ids_value = value.FindKey("browserContextIds");
  if (browser_context_ids_value) {
    errors->SetName("browserContextIds");
    result->browser_context_ids_ = internal::FromValue<std::vector<std::string>>::Parse(*browser_context_ids_value, errors);
  } else {
    errors->AddError("required property missing: browserContextIds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBrowserContextsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("browserContextIds", internal::ToValue(browser_context_ids_));
  return std::move(result);
}

std::unique_ptr<GetBrowserContextsResult> GetBrowserContextsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBrowserContextsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CreateTargetParams> CreateTargetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CreateTargetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CreateTargetParams> result(new CreateTargetParams());
  errors->Push();
  errors->SetName("CreateTargetParams");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* width_value = value.FindKey("width");
  if (width_value) {
    errors->SetName("width");
    result->width_ = internal::FromValue<int>::Parse(*width_value, errors);
  }
  const base::Value* height_value = value.FindKey("height");
  if (height_value) {
    errors->SetName("height");
    result->height_ = internal::FromValue<int>::Parse(*height_value, errors);
  }
  const base::Value* browser_context_id_value = value.FindKey("browserContextId");
  if (browser_context_id_value) {
    errors->SetName("browserContextId");
    result->browser_context_id_ = internal::FromValue<std::string>::Parse(*browser_context_id_value, errors);
  }
  const base::Value* enable_begin_frame_control_value = value.FindKey("enableBeginFrameControl");
  if (enable_begin_frame_control_value) {
    errors->SetName("enableBeginFrameControl");
    result->enable_begin_frame_control_ = internal::FromValue<bool>::Parse(*enable_begin_frame_control_value, errors);
  }
  const base::Value* new_window_value = value.FindKey("newWindow");
  if (new_window_value) {
    errors->SetName("newWindow");
    result->new_window_ = internal::FromValue<bool>::Parse(*new_window_value, errors);
  }
  const base::Value* background_value = value.FindKey("background");
  if (background_value) {
    errors->SetName("background");
    result->background_ = internal::FromValue<bool>::Parse(*background_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CreateTargetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  if (width_)
    result->Set("width", internal::ToValue(width_.value()));
  if (height_)
    result->Set("height", internal::ToValue(height_.value()));
  if (browser_context_id_)
    result->Set("browserContextId", internal::ToValue(browser_context_id_.value()));
  if (enable_begin_frame_control_)
    result->Set("enableBeginFrameControl", internal::ToValue(enable_begin_frame_control_.value()));
  if (new_window_)
    result->Set("newWindow", internal::ToValue(new_window_.value()));
  if (background_)
    result->Set("background", internal::ToValue(background_.value()));
  return std::move(result);
}

std::unique_ptr<CreateTargetParams> CreateTargetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CreateTargetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CreateTargetResult> CreateTargetResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CreateTargetResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CreateTargetResult> result(new CreateTargetResult());
  errors->Push();
  errors->SetName("CreateTargetResult");
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  } else {
    errors->AddError("required property missing: targetId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CreateTargetResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetId", internal::ToValue(target_id_));
  return std::move(result);
}

std::unique_ptr<CreateTargetResult> CreateTargetResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CreateTargetResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DetachFromTargetParams> DetachFromTargetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DetachFromTargetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DetachFromTargetParams> result(new DetachFromTargetParams());
  errors->Push();
  errors->SetName("DetachFromTargetParams");
  const base::Value* session_id_value = value.FindKey("sessionId");
  if (session_id_value) {
    errors->SetName("sessionId");
    result->session_id_ = internal::FromValue<std::string>::Parse(*session_id_value, errors);
  }
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DetachFromTargetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (session_id_)
    result->Set("sessionId", internal::ToValue(session_id_.value()));
  if (target_id_)
    result->Set("targetId", internal::ToValue(target_id_.value()));
  return std::move(result);
}

std::unique_ptr<DetachFromTargetParams> DetachFromTargetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DetachFromTargetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DetachFromTargetResult> DetachFromTargetResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DetachFromTargetResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DetachFromTargetResult> result(new DetachFromTargetResult());
  errors->Push();
  errors->SetName("DetachFromTargetResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DetachFromTargetResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DetachFromTargetResult> DetachFromTargetResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DetachFromTargetResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisposeBrowserContextParams> DisposeBrowserContextParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisposeBrowserContextParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisposeBrowserContextParams> result(new DisposeBrowserContextParams());
  errors->Push();
  errors->SetName("DisposeBrowserContextParams");
  const base::Value* browser_context_id_value = value.FindKey("browserContextId");
  if (browser_context_id_value) {
    errors->SetName("browserContextId");
    result->browser_context_id_ = internal::FromValue<std::string>::Parse(*browser_context_id_value, errors);
  } else {
    errors->AddError("required property missing: browserContextId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisposeBrowserContextParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("browserContextId", internal::ToValue(browser_context_id_));
  return std::move(result);
}

std::unique_ptr<DisposeBrowserContextParams> DisposeBrowserContextParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisposeBrowserContextParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisposeBrowserContextResult> DisposeBrowserContextResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisposeBrowserContextResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisposeBrowserContextResult> result(new DisposeBrowserContextResult());
  errors->Push();
  errors->SetName("DisposeBrowserContextResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisposeBrowserContextResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisposeBrowserContextResult> DisposeBrowserContextResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisposeBrowserContextResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetTargetInfoParams> GetTargetInfoParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetTargetInfoParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetTargetInfoParams> result(new GetTargetInfoParams());
  errors->Push();
  errors->SetName("GetTargetInfoParams");
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetTargetInfoParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (target_id_)
    result->Set("targetId", internal::ToValue(target_id_.value()));
  return std::move(result);
}

std::unique_ptr<GetTargetInfoParams> GetTargetInfoParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetTargetInfoParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetTargetInfoResult> GetTargetInfoResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetTargetInfoResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetTargetInfoResult> result(new GetTargetInfoResult());
  errors->Push();
  errors->SetName("GetTargetInfoResult");
  const base::Value* target_info_value = value.FindKey("targetInfo");
  if (target_info_value) {
    errors->SetName("targetInfo");
    result->target_info_ = internal::FromValue<::headless::target::TargetInfo>::Parse(*target_info_value, errors);
  } else {
    errors->AddError("required property missing: targetInfo");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetTargetInfoResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetInfo", internal::ToValue(*target_info_));
  return std::move(result);
}

std::unique_ptr<GetTargetInfoResult> GetTargetInfoResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetTargetInfoResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetTargetsParams> GetTargetsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetTargetsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetTargetsParams> result(new GetTargetsParams());
  errors->Push();
  errors->SetName("GetTargetsParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetTargetsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetTargetsParams> GetTargetsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetTargetsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetTargetsResult> GetTargetsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetTargetsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetTargetsResult> result(new GetTargetsResult());
  errors->Push();
  errors->SetName("GetTargetsResult");
  const base::Value* target_infos_value = value.FindKey("targetInfos");
  if (target_infos_value) {
    errors->SetName("targetInfos");
    result->target_infos_ = internal::FromValue<std::vector<std::unique_ptr<::headless::target::TargetInfo>>>::Parse(*target_infos_value, errors);
  } else {
    errors->AddError("required property missing: targetInfos");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetTargetsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetInfos", internal::ToValue(target_infos_));
  return std::move(result);
}

std::unique_ptr<GetTargetsResult> GetTargetsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetTargetsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SendMessageToTargetParams> SendMessageToTargetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SendMessageToTargetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SendMessageToTargetParams> result(new SendMessageToTargetParams());
  errors->Push();
  errors->SetName("SendMessageToTargetParams");
  const base::Value* message_value = value.FindKey("message");
  if (message_value) {
    errors->SetName("message");
    result->message_ = internal::FromValue<std::string>::Parse(*message_value, errors);
  } else {
    errors->AddError("required property missing: message");
  }
  const base::Value* session_id_value = value.FindKey("sessionId");
  if (session_id_value) {
    errors->SetName("sessionId");
    result->session_id_ = internal::FromValue<std::string>::Parse(*session_id_value, errors);
  }
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SendMessageToTargetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("message", internal::ToValue(message_));
  if (session_id_)
    result->Set("sessionId", internal::ToValue(session_id_.value()));
  if (target_id_)
    result->Set("targetId", internal::ToValue(target_id_.value()));
  return std::move(result);
}

std::unique_ptr<SendMessageToTargetParams> SendMessageToTargetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SendMessageToTargetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SendMessageToTargetResult> SendMessageToTargetResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SendMessageToTargetResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SendMessageToTargetResult> result(new SendMessageToTargetResult());
  errors->Push();
  errors->SetName("SendMessageToTargetResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SendMessageToTargetResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SendMessageToTargetResult> SendMessageToTargetResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SendMessageToTargetResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetAutoAttachParams> SetAutoAttachParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetAutoAttachParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetAutoAttachParams> result(new SetAutoAttachParams());
  errors->Push();
  errors->SetName("SetAutoAttachParams");
  const base::Value* auto_attach_value = value.FindKey("autoAttach");
  if (auto_attach_value) {
    errors->SetName("autoAttach");
    result->auto_attach_ = internal::FromValue<bool>::Parse(*auto_attach_value, errors);
  } else {
    errors->AddError("required property missing: autoAttach");
  }
  const base::Value* wait_for_debugger_on_start_value = value.FindKey("waitForDebuggerOnStart");
  if (wait_for_debugger_on_start_value) {
    errors->SetName("waitForDebuggerOnStart");
    result->wait_for_debugger_on_start_ = internal::FromValue<bool>::Parse(*wait_for_debugger_on_start_value, errors);
  } else {
    errors->AddError("required property missing: waitForDebuggerOnStart");
  }
  const base::Value* flatten_value = value.FindKey("flatten");
  if (flatten_value) {
    errors->SetName("flatten");
    result->flatten_ = internal::FromValue<bool>::Parse(*flatten_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetAutoAttachParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("autoAttach", internal::ToValue(auto_attach_));
  result->Set("waitForDebuggerOnStart", internal::ToValue(wait_for_debugger_on_start_));
  if (flatten_)
    result->Set("flatten", internal::ToValue(flatten_.value()));
  return std::move(result);
}

std::unique_ptr<SetAutoAttachParams> SetAutoAttachParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetAutoAttachParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetAutoAttachResult> SetAutoAttachResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetAutoAttachResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetAutoAttachResult> result(new SetAutoAttachResult());
  errors->Push();
  errors->SetName("SetAutoAttachResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetAutoAttachResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetAutoAttachResult> SetAutoAttachResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetAutoAttachResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDiscoverTargetsParams> SetDiscoverTargetsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDiscoverTargetsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDiscoverTargetsParams> result(new SetDiscoverTargetsParams());
  errors->Push();
  errors->SetName("SetDiscoverTargetsParams");
  const base::Value* discover_value = value.FindKey("discover");
  if (discover_value) {
    errors->SetName("discover");
    result->discover_ = internal::FromValue<bool>::Parse(*discover_value, errors);
  } else {
    errors->AddError("required property missing: discover");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDiscoverTargetsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("discover", internal::ToValue(discover_));
  return std::move(result);
}

std::unique_ptr<SetDiscoverTargetsParams> SetDiscoverTargetsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDiscoverTargetsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDiscoverTargetsResult> SetDiscoverTargetsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDiscoverTargetsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDiscoverTargetsResult> result(new SetDiscoverTargetsResult());
  errors->Push();
  errors->SetName("SetDiscoverTargetsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDiscoverTargetsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetDiscoverTargetsResult> SetDiscoverTargetsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDiscoverTargetsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetRemoteLocationsParams> SetRemoteLocationsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetRemoteLocationsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetRemoteLocationsParams> result(new SetRemoteLocationsParams());
  errors->Push();
  errors->SetName("SetRemoteLocationsParams");
  const base::Value* locations_value = value.FindKey("locations");
  if (locations_value) {
    errors->SetName("locations");
    result->locations_ = internal::FromValue<std::vector<std::unique_ptr<::headless::target::RemoteLocation>>>::Parse(*locations_value, errors);
  } else {
    errors->AddError("required property missing: locations");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetRemoteLocationsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("locations", internal::ToValue(locations_));
  return std::move(result);
}

std::unique_ptr<SetRemoteLocationsParams> SetRemoteLocationsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetRemoteLocationsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetRemoteLocationsResult> SetRemoteLocationsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetRemoteLocationsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetRemoteLocationsResult> result(new SetRemoteLocationsResult());
  errors->Push();
  errors->SetName("SetRemoteLocationsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetRemoteLocationsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetRemoteLocationsResult> SetRemoteLocationsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetRemoteLocationsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AttachedToTargetParams> AttachedToTargetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AttachedToTargetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AttachedToTargetParams> result(new AttachedToTargetParams());
  errors->Push();
  errors->SetName("AttachedToTargetParams");
  const base::Value* session_id_value = value.FindKey("sessionId");
  if (session_id_value) {
    errors->SetName("sessionId");
    result->session_id_ = internal::FromValue<std::string>::Parse(*session_id_value, errors);
  } else {
    errors->AddError("required property missing: sessionId");
  }
  const base::Value* target_info_value = value.FindKey("targetInfo");
  if (target_info_value) {
    errors->SetName("targetInfo");
    result->target_info_ = internal::FromValue<::headless::target::TargetInfo>::Parse(*target_info_value, errors);
  } else {
    errors->AddError("required property missing: targetInfo");
  }
  const base::Value* waiting_for_debugger_value = value.FindKey("waitingForDebugger");
  if (waiting_for_debugger_value) {
    errors->SetName("waitingForDebugger");
    result->waiting_for_debugger_ = internal::FromValue<bool>::Parse(*waiting_for_debugger_value, errors);
  } else {
    errors->AddError("required property missing: waitingForDebugger");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AttachedToTargetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("sessionId", internal::ToValue(session_id_));
  result->Set("targetInfo", internal::ToValue(*target_info_));
  result->Set("waitingForDebugger", internal::ToValue(waiting_for_debugger_));
  return std::move(result);
}

std::unique_ptr<AttachedToTargetParams> AttachedToTargetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AttachedToTargetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DetachedFromTargetParams> DetachedFromTargetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DetachedFromTargetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DetachedFromTargetParams> result(new DetachedFromTargetParams());
  errors->Push();
  errors->SetName("DetachedFromTargetParams");
  const base::Value* session_id_value = value.FindKey("sessionId");
  if (session_id_value) {
    errors->SetName("sessionId");
    result->session_id_ = internal::FromValue<std::string>::Parse(*session_id_value, errors);
  } else {
    errors->AddError("required property missing: sessionId");
  }
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DetachedFromTargetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("sessionId", internal::ToValue(session_id_));
  if (target_id_)
    result->Set("targetId", internal::ToValue(target_id_.value()));
  return std::move(result);
}

std::unique_ptr<DetachedFromTargetParams> DetachedFromTargetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DetachedFromTargetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReceivedMessageFromTargetParams> ReceivedMessageFromTargetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReceivedMessageFromTargetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReceivedMessageFromTargetParams> result(new ReceivedMessageFromTargetParams());
  errors->Push();
  errors->SetName("ReceivedMessageFromTargetParams");
  const base::Value* session_id_value = value.FindKey("sessionId");
  if (session_id_value) {
    errors->SetName("sessionId");
    result->session_id_ = internal::FromValue<std::string>::Parse(*session_id_value, errors);
  } else {
    errors->AddError("required property missing: sessionId");
  }
  const base::Value* message_value = value.FindKey("message");
  if (message_value) {
    errors->SetName("message");
    result->message_ = internal::FromValue<std::string>::Parse(*message_value, errors);
  } else {
    errors->AddError("required property missing: message");
  }
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReceivedMessageFromTargetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("sessionId", internal::ToValue(session_id_));
  result->Set("message", internal::ToValue(message_));
  if (target_id_)
    result->Set("targetId", internal::ToValue(target_id_.value()));
  return std::move(result);
}

std::unique_ptr<ReceivedMessageFromTargetParams> ReceivedMessageFromTargetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReceivedMessageFromTargetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TargetCreatedParams> TargetCreatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TargetCreatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TargetCreatedParams> result(new TargetCreatedParams());
  errors->Push();
  errors->SetName("TargetCreatedParams");
  const base::Value* target_info_value = value.FindKey("targetInfo");
  if (target_info_value) {
    errors->SetName("targetInfo");
    result->target_info_ = internal::FromValue<::headless::target::TargetInfo>::Parse(*target_info_value, errors);
  } else {
    errors->AddError("required property missing: targetInfo");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TargetCreatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetInfo", internal::ToValue(*target_info_));
  return std::move(result);
}

std::unique_ptr<TargetCreatedParams> TargetCreatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TargetCreatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TargetDestroyedParams> TargetDestroyedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TargetDestroyedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TargetDestroyedParams> result(new TargetDestroyedParams());
  errors->Push();
  errors->SetName("TargetDestroyedParams");
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  } else {
    errors->AddError("required property missing: targetId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TargetDestroyedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetId", internal::ToValue(target_id_));
  return std::move(result);
}

std::unique_ptr<TargetDestroyedParams> TargetDestroyedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TargetDestroyedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TargetCrashedParams> TargetCrashedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TargetCrashedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TargetCrashedParams> result(new TargetCrashedParams());
  errors->Push();
  errors->SetName("TargetCrashedParams");
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  } else {
    errors->AddError("required property missing: targetId");
  }
  const base::Value* status_value = value.FindKey("status");
  if (status_value) {
    errors->SetName("status");
    result->status_ = internal::FromValue<std::string>::Parse(*status_value, errors);
  } else {
    errors->AddError("required property missing: status");
  }
  const base::Value* error_code_value = value.FindKey("errorCode");
  if (error_code_value) {
    errors->SetName("errorCode");
    result->error_code_ = internal::FromValue<int>::Parse(*error_code_value, errors);
  } else {
    errors->AddError("required property missing: errorCode");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TargetCrashedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetId", internal::ToValue(target_id_));
  result->Set("status", internal::ToValue(status_));
  result->Set("errorCode", internal::ToValue(error_code_));
  return std::move(result);
}

std::unique_ptr<TargetCrashedParams> TargetCrashedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TargetCrashedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TargetInfoChangedParams> TargetInfoChangedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TargetInfoChangedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TargetInfoChangedParams> result(new TargetInfoChangedParams());
  errors->Push();
  errors->SetName("TargetInfoChangedParams");
  const base::Value* target_info_value = value.FindKey("targetInfo");
  if (target_info_value) {
    errors->SetName("targetInfo");
    result->target_info_ = internal::FromValue<::headless::target::TargetInfo>::Parse(*target_info_value, errors);
  } else {
    errors->AddError("required property missing: targetInfo");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TargetInfoChangedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("targetInfo", internal::ToValue(*target_info_));
  return std::move(result);
}

std::unique_ptr<TargetInfoChangedParams> TargetInfoChangedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TargetInfoChangedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace target
}  // namespace headless
