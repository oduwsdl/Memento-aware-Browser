// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_dom_debugger.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_dom_debugger.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace dom_debugger {

std::unique_ptr<EventListener> EventListener::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EventListener");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EventListener> result(new EventListener());
  errors->Push();
  errors->SetName("EventListener");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<std::string>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* use_capture_value = value.FindKey("useCapture");
  if (use_capture_value) {
    errors->SetName("useCapture");
    result->use_capture_ = internal::FromValue<bool>::Parse(*use_capture_value, errors);
  } else {
    errors->AddError("required property missing: useCapture");
  }
  const base::Value* passive_value = value.FindKey("passive");
  if (passive_value) {
    errors->SetName("passive");
    result->passive_ = internal::FromValue<bool>::Parse(*passive_value, errors);
  } else {
    errors->AddError("required property missing: passive");
  }
  const base::Value* once_value = value.FindKey("once");
  if (once_value) {
    errors->SetName("once");
    result->once_ = internal::FromValue<bool>::Parse(*once_value, errors);
  } else {
    errors->AddError("required property missing: once");
  }
  const base::Value* script_id_value = value.FindKey("scriptId");
  if (script_id_value) {
    errors->SetName("scriptId");
    result->script_id_ = internal::FromValue<std::string>::Parse(*script_id_value, errors);
  } else {
    errors->AddError("required property missing: scriptId");
  }
  const base::Value* line_number_value = value.FindKey("lineNumber");
  if (line_number_value) {
    errors->SetName("lineNumber");
    result->line_number_ = internal::FromValue<int>::Parse(*line_number_value, errors);
  } else {
    errors->AddError("required property missing: lineNumber");
  }
  const base::Value* column_number_value = value.FindKey("columnNumber");
  if (column_number_value) {
    errors->SetName("columnNumber");
    result->column_number_ = internal::FromValue<int>::Parse(*column_number_value, errors);
  } else {
    errors->AddError("required property missing: columnNumber");
  }
  const base::Value* handler_value = value.FindKey("handler");
  if (handler_value) {
    errors->SetName("handler");
    result->handler_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*handler_value, errors);
  }
  const base::Value* original_handler_value = value.FindKey("originalHandler");
  if (original_handler_value) {
    errors->SetName("originalHandler");
    result->original_handler_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*original_handler_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EventListener::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  result->Set("useCapture", internal::ToValue(use_capture_));
  result->Set("passive", internal::ToValue(passive_));
  result->Set("once", internal::ToValue(once_));
  result->Set("scriptId", internal::ToValue(script_id_));
  result->Set("lineNumber", internal::ToValue(line_number_));
  result->Set("columnNumber", internal::ToValue(column_number_));
  if (handler_)
    result->Set("handler", internal::ToValue(*handler_.value()));
  if (original_handler_)
    result->Set("originalHandler", internal::ToValue(*original_handler_.value()));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  return std::move(result);
}

std::unique_ptr<EventListener> EventListener::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EventListener> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetEventListenersParams> GetEventListenersParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetEventListenersParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetEventListenersParams> result(new GetEventListenersParams());
  errors->Push();
  errors->SetName("GetEventListenersParams");
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  } else {
    errors->AddError("required property missing: objectId");
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

std::unique_ptr<base::Value> GetEventListenersParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("objectId", internal::ToValue(object_id_));
  if (depth_)
    result->Set("depth", internal::ToValue(depth_.value()));
  if (pierce_)
    result->Set("pierce", internal::ToValue(pierce_.value()));
  return std::move(result);
}

std::unique_ptr<GetEventListenersParams> GetEventListenersParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetEventListenersParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetEventListenersResult> GetEventListenersResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetEventListenersResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetEventListenersResult> result(new GetEventListenersResult());
  errors->Push();
  errors->SetName("GetEventListenersResult");
  const base::Value* listeners_value = value.FindKey("listeners");
  if (listeners_value) {
    errors->SetName("listeners");
    result->listeners_ = internal::FromValue<std::vector<std::unique_ptr<::headless::dom_debugger::EventListener>>>::Parse(*listeners_value, errors);
  } else {
    errors->AddError("required property missing: listeners");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetEventListenersResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("listeners", internal::ToValue(listeners_));
  return std::move(result);
}

std::unique_ptr<GetEventListenersResult> GetEventListenersResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetEventListenersResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveDOMBreakpointParams> RemoveDOMBreakpointParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveDOMBreakpointParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveDOMBreakpointParams> result(new RemoveDOMBreakpointParams());
  errors->Push();
  errors->SetName("RemoveDOMBreakpointParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::dom_debugger::DOMBreakpointType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveDOMBreakpointParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("type", internal::ToValue(type_));
  return std::move(result);
}

std::unique_ptr<RemoveDOMBreakpointParams> RemoveDOMBreakpointParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveDOMBreakpointParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveDOMBreakpointResult> RemoveDOMBreakpointResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveDOMBreakpointResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveDOMBreakpointResult> result(new RemoveDOMBreakpointResult());
  errors->Push();
  errors->SetName("RemoveDOMBreakpointResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveDOMBreakpointResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveDOMBreakpointResult> RemoveDOMBreakpointResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveDOMBreakpointResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveEventListenerBreakpointParams> RemoveEventListenerBreakpointParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveEventListenerBreakpointParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveEventListenerBreakpointParams> result(new RemoveEventListenerBreakpointParams());
  errors->Push();
  errors->SetName("RemoveEventListenerBreakpointParams");
  const base::Value* event_name_value = value.FindKey("eventName");
  if (event_name_value) {
    errors->SetName("eventName");
    result->event_name_ = internal::FromValue<std::string>::Parse(*event_name_value, errors);
  } else {
    errors->AddError("required property missing: eventName");
  }
  const base::Value* target_name_value = value.FindKey("targetName");
  if (target_name_value) {
    errors->SetName("targetName");
    result->target_name_ = internal::FromValue<std::string>::Parse(*target_name_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveEventListenerBreakpointParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("eventName", internal::ToValue(event_name_));
  if (target_name_)
    result->Set("targetName", internal::ToValue(target_name_.value()));
  return std::move(result);
}

std::unique_ptr<RemoveEventListenerBreakpointParams> RemoveEventListenerBreakpointParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveEventListenerBreakpointParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveEventListenerBreakpointResult> RemoveEventListenerBreakpointResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveEventListenerBreakpointResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveEventListenerBreakpointResult> result(new RemoveEventListenerBreakpointResult());
  errors->Push();
  errors->SetName("RemoveEventListenerBreakpointResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveEventListenerBreakpointResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveEventListenerBreakpointResult> RemoveEventListenerBreakpointResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveEventListenerBreakpointResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveInstrumentationBreakpointParams> RemoveInstrumentationBreakpointParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveInstrumentationBreakpointParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveInstrumentationBreakpointParams> result(new RemoveInstrumentationBreakpointParams());
  errors->Push();
  errors->SetName("RemoveInstrumentationBreakpointParams");
  const base::Value* event_name_value = value.FindKey("eventName");
  if (event_name_value) {
    errors->SetName("eventName");
    result->event_name_ = internal::FromValue<std::string>::Parse(*event_name_value, errors);
  } else {
    errors->AddError("required property missing: eventName");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveInstrumentationBreakpointParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("eventName", internal::ToValue(event_name_));
  return std::move(result);
}

std::unique_ptr<RemoveInstrumentationBreakpointParams> RemoveInstrumentationBreakpointParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveInstrumentationBreakpointParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveInstrumentationBreakpointResult> RemoveInstrumentationBreakpointResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveInstrumentationBreakpointResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveInstrumentationBreakpointResult> result(new RemoveInstrumentationBreakpointResult());
  errors->Push();
  errors->SetName("RemoveInstrumentationBreakpointResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveInstrumentationBreakpointResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveInstrumentationBreakpointResult> RemoveInstrumentationBreakpointResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveInstrumentationBreakpointResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveXHRBreakpointParams> RemoveXHRBreakpointParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveXHRBreakpointParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveXHRBreakpointParams> result(new RemoveXHRBreakpointParams());
  errors->Push();
  errors->SetName("RemoveXHRBreakpointParams");
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

std::unique_ptr<base::Value> RemoveXHRBreakpointParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  return std::move(result);
}

std::unique_ptr<RemoveXHRBreakpointParams> RemoveXHRBreakpointParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveXHRBreakpointParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveXHRBreakpointResult> RemoveXHRBreakpointResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveXHRBreakpointResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveXHRBreakpointResult> result(new RemoveXHRBreakpointResult());
  errors->Push();
  errors->SetName("RemoveXHRBreakpointResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveXHRBreakpointResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveXHRBreakpointResult> RemoveXHRBreakpointResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveXHRBreakpointResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDOMBreakpointParams> SetDOMBreakpointParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDOMBreakpointParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDOMBreakpointParams> result(new SetDOMBreakpointParams());
  errors->Push();
  errors->SetName("SetDOMBreakpointParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::dom_debugger::DOMBreakpointType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDOMBreakpointParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("type", internal::ToValue(type_));
  return std::move(result);
}

std::unique_ptr<SetDOMBreakpointParams> SetDOMBreakpointParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDOMBreakpointParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDOMBreakpointResult> SetDOMBreakpointResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDOMBreakpointResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDOMBreakpointResult> result(new SetDOMBreakpointResult());
  errors->Push();
  errors->SetName("SetDOMBreakpointResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDOMBreakpointResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetDOMBreakpointResult> SetDOMBreakpointResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDOMBreakpointResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetEventListenerBreakpointParams> SetEventListenerBreakpointParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetEventListenerBreakpointParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetEventListenerBreakpointParams> result(new SetEventListenerBreakpointParams());
  errors->Push();
  errors->SetName("SetEventListenerBreakpointParams");
  const base::Value* event_name_value = value.FindKey("eventName");
  if (event_name_value) {
    errors->SetName("eventName");
    result->event_name_ = internal::FromValue<std::string>::Parse(*event_name_value, errors);
  } else {
    errors->AddError("required property missing: eventName");
  }
  const base::Value* target_name_value = value.FindKey("targetName");
  if (target_name_value) {
    errors->SetName("targetName");
    result->target_name_ = internal::FromValue<std::string>::Parse(*target_name_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetEventListenerBreakpointParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("eventName", internal::ToValue(event_name_));
  if (target_name_)
    result->Set("targetName", internal::ToValue(target_name_.value()));
  return std::move(result);
}

std::unique_ptr<SetEventListenerBreakpointParams> SetEventListenerBreakpointParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetEventListenerBreakpointParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetEventListenerBreakpointResult> SetEventListenerBreakpointResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetEventListenerBreakpointResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetEventListenerBreakpointResult> result(new SetEventListenerBreakpointResult());
  errors->Push();
  errors->SetName("SetEventListenerBreakpointResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetEventListenerBreakpointResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetEventListenerBreakpointResult> SetEventListenerBreakpointResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetEventListenerBreakpointResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetInstrumentationBreakpointParams> SetInstrumentationBreakpointParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetInstrumentationBreakpointParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetInstrumentationBreakpointParams> result(new SetInstrumentationBreakpointParams());
  errors->Push();
  errors->SetName("SetInstrumentationBreakpointParams");
  const base::Value* event_name_value = value.FindKey("eventName");
  if (event_name_value) {
    errors->SetName("eventName");
    result->event_name_ = internal::FromValue<std::string>::Parse(*event_name_value, errors);
  } else {
    errors->AddError("required property missing: eventName");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetInstrumentationBreakpointParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("eventName", internal::ToValue(event_name_));
  return std::move(result);
}

std::unique_ptr<SetInstrumentationBreakpointParams> SetInstrumentationBreakpointParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetInstrumentationBreakpointParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetInstrumentationBreakpointResult> SetInstrumentationBreakpointResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetInstrumentationBreakpointResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetInstrumentationBreakpointResult> result(new SetInstrumentationBreakpointResult());
  errors->Push();
  errors->SetName("SetInstrumentationBreakpointResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetInstrumentationBreakpointResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetInstrumentationBreakpointResult> SetInstrumentationBreakpointResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetInstrumentationBreakpointResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetXHRBreakpointParams> SetXHRBreakpointParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetXHRBreakpointParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetXHRBreakpointParams> result(new SetXHRBreakpointParams());
  errors->Push();
  errors->SetName("SetXHRBreakpointParams");
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

std::unique_ptr<base::Value> SetXHRBreakpointParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  return std::move(result);
}

std::unique_ptr<SetXHRBreakpointParams> SetXHRBreakpointParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetXHRBreakpointParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetXHRBreakpointResult> SetXHRBreakpointResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetXHRBreakpointResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetXHRBreakpointResult> result(new SetXHRBreakpointResult());
  errors->Push();
  errors->SetName("SetXHRBreakpointResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetXHRBreakpointResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetXHRBreakpointResult> SetXHRBreakpointResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetXHRBreakpointResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace dom_debugger
}  // namespace headless
