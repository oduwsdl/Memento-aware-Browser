// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/developer_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/developer_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace developer_private {
//
// Types
//

const char* ToString(ItemType enum_param) {
  switch (enum_param) {
    case ITEM_TYPE_HOSTED_APP:
      return "hosted_app";
    case ITEM_TYPE_PACKAGED_APP:
      return "packaged_app";
    case ITEM_TYPE_LEGACY_PACKAGED_APP:
      return "legacy_packaged_app";
    case ITEM_TYPE_EXTENSION:
      return "extension";
    case ITEM_TYPE_THEME:
      return "theme";
    case ITEM_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ItemType ParseItemType(const std::string& enum_string) {
  if (enum_string == "hosted_app")
    return ITEM_TYPE_HOSTED_APP;
  if (enum_string == "packaged_app")
    return ITEM_TYPE_PACKAGED_APP;
  if (enum_string == "legacy_packaged_app")
    return ITEM_TYPE_LEGACY_PACKAGED_APP;
  if (enum_string == "extension")
    return ITEM_TYPE_EXTENSION;
  if (enum_string == "theme")
    return ITEM_TYPE_THEME;
  return ITEM_TYPE_NONE;
}


ItemInspectView::ItemInspectView()
: render_process_id(0),
render_view_id(0),
incognito(false),
generated_background_page(false) {}

ItemInspectView::~ItemInspectView() {}
ItemInspectView::ItemInspectView(ItemInspectView&& rhs)
: path(std::move(rhs.path)),
render_process_id(rhs.render_process_id),
render_view_id(rhs.render_view_id),
incognito(rhs.incognito),
generated_background_page(rhs.generated_background_page){
}

ItemInspectView& ItemInspectView::operator=(ItemInspectView&& rhs)
{
path = std::move(rhs.path);
render_process_id = rhs.render_process_id;
render_view_id = rhs.render_view_id;
incognito = rhs.incognito;
generated_background_page = rhs.generated_background_page;
return *this;
}

// static
bool ItemInspectView::Populate(
    const base::Value& value, ItemInspectView* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* path_value = NULL;
  if (!dict->GetWithoutPathExpansion("path", &path_value)) {
    return false;
  }
  {
    if (!path_value->GetAsString(&out->path)) {
      return false;
    }
  }

  const base::Value* render_process_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("render_process_id", &render_process_id_value)) {
    return false;
  }
  {
    if (!render_process_id_value->GetAsInteger(&out->render_process_id)) {
      return false;
    }
  }

  const base::Value* render_view_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("render_view_id", &render_view_id_value)) {
    return false;
  }
  {
    if (!render_view_id_value->GetAsInteger(&out->render_view_id)) {
      return false;
    }
  }

  const base::Value* incognito_value = NULL;
  if (!dict->GetWithoutPathExpansion("incognito", &incognito_value)) {
    return false;
  }
  {
    if (!incognito_value->GetAsBoolean(&out->incognito)) {
      return false;
    }
  }

  const base::Value* generated_background_page_value = NULL;
  if (!dict->GetWithoutPathExpansion("generatedBackgroundPage", &generated_background_page_value)) {
    return false;
  }
  {
    if (!generated_background_page_value->GetAsBoolean(&out->generated_background_page)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ItemInspectView> ItemInspectView::FromValue(const base::Value& value) {
  std::unique_ptr<ItemInspectView> out(new ItemInspectView());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ItemInspectView::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("path", std::make_unique<base::Value>(this->path));

  to_value_result->SetWithoutPathExpansion("render_process_id", std::make_unique<base::Value>(this->render_process_id));

  to_value_result->SetWithoutPathExpansion("render_view_id", std::make_unique<base::Value>(this->render_view_id));

  to_value_result->SetWithoutPathExpansion("incognito", std::make_unique<base::Value>(this->incognito));

  to_value_result->SetWithoutPathExpansion("generatedBackgroundPage", std::make_unique<base::Value>(this->generated_background_page));


  return to_value_result;
}


InspectOptions::Render_process_id::Render_process_id()
 {}

InspectOptions::Render_process_id::~Render_process_id() {}
InspectOptions::Render_process_id::Render_process_id(Render_process_id&& rhs)
: as_string(std::move(rhs.as_string)),
as_integer(std::move(rhs.as_integer)){
}

InspectOptions::Render_process_id& InspectOptions::Render_process_id::operator=(Render_process_id&& rhs)
{
as_string = std::move(rhs.as_string);
as_integer = std::move(rhs.as_integer);
return *this;
}

// static
bool InspectOptions::Render_process_id::Populate(
    const base::Value& value, Render_process_id* out) {
  if (value.type() == base::Value::Type::STRING) {
    {
      std::string temp;
      if (!(&value)->GetAsString(&temp)) {
        out->as_string.reset();
        return false;
      }
      else
        out->as_string.reset(new std::string(temp));
    }
    return true;
  }
  if (value.type() == base::Value::Type::INTEGER) {
    {
      int temp;
      if (!(&value)->GetAsInteger(&temp)) {
        out->as_integer.reset();
        return false;
      }
      else
        out->as_integer.reset(new int(temp));
    }
    return true;
  }
  return false;
}

std::unique_ptr<base::Value> InspectOptions::Render_process_id::ToValue() const {
  std::unique_ptr<base::Value> result;
  if (as_string) {
    DCHECK(!result) << "Cannot set multiple choices for render_process_id";
    result = std::make_unique<base::Value>(*as_string);

  }
  if (as_integer) {
    DCHECK(!result) << "Cannot set multiple choices for render_process_id";
    result = std::make_unique<base::Value>(*as_integer);

  }
  DCHECK(result) << "Must set at least one choice for render_process_id";
  return result;
}


InspectOptions::Render_view_id::Render_view_id()
 {}

InspectOptions::Render_view_id::~Render_view_id() {}
InspectOptions::Render_view_id::Render_view_id(Render_view_id&& rhs)
: as_string(std::move(rhs.as_string)),
as_integer(std::move(rhs.as_integer)){
}

InspectOptions::Render_view_id& InspectOptions::Render_view_id::operator=(Render_view_id&& rhs)
{
as_string = std::move(rhs.as_string);
as_integer = std::move(rhs.as_integer);
return *this;
}

// static
bool InspectOptions::Render_view_id::Populate(
    const base::Value& value, Render_view_id* out) {
  if (value.type() == base::Value::Type::STRING) {
    {
      std::string temp;
      if (!(&value)->GetAsString(&temp)) {
        out->as_string.reset();
        return false;
      }
      else
        out->as_string.reset(new std::string(temp));
    }
    return true;
  }
  if (value.type() == base::Value::Type::INTEGER) {
    {
      int temp;
      if (!(&value)->GetAsInteger(&temp)) {
        out->as_integer.reset();
        return false;
      }
      else
        out->as_integer.reset(new int(temp));
    }
    return true;
  }
  return false;
}

std::unique_ptr<base::Value> InspectOptions::Render_view_id::ToValue() const {
  std::unique_ptr<base::Value> result;
  if (as_string) {
    DCHECK(!result) << "Cannot set multiple choices for render_view_id";
    result = std::make_unique<base::Value>(*as_string);

  }
  if (as_integer) {
    DCHECK(!result) << "Cannot set multiple choices for render_view_id";
    result = std::make_unique<base::Value>(*as_integer);

  }
  DCHECK(result) << "Must set at least one choice for render_view_id";
  return result;
}



InspectOptions::InspectOptions()
: incognito(false) {}

InspectOptions::~InspectOptions() {}
InspectOptions::InspectOptions(InspectOptions&& rhs)
: extension_id(std::move(rhs.extension_id)),
render_process_id(std::move(rhs.render_process_id)),
render_view_id(std::move(rhs.render_view_id)),
incognito(rhs.incognito){
}

InspectOptions& InspectOptions::operator=(InspectOptions&& rhs)
{
extension_id = std::move(rhs.extension_id);
render_process_id = std::move(rhs.render_process_id);
render_view_id = std::move(rhs.render_view_id);
incognito = rhs.incognito;
return *this;
}

// static
bool InspectOptions::Populate(
    const base::Value& value, InspectOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* extension_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("extension_id", &extension_id_value)) {
    return false;
  }
  {
    if (!extension_id_value->GetAsString(&out->extension_id)) {
      return false;
    }
  }

  const base::Value* render_process_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("render_process_id", &render_process_id_value)) {
    return false;
  }
  {
    if (!Render_process_id::Populate(*render_process_id_value, &out->render_process_id))
      return false;
  }

  const base::Value* render_view_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("render_view_id", &render_view_id_value)) {
    return false;
  }
  {
    if (!Render_view_id::Populate(*render_view_id_value, &out->render_view_id))
      return false;
  }

  const base::Value* incognito_value = NULL;
  if (!dict->GetWithoutPathExpansion("incognito", &incognito_value)) {
    return false;
  }
  {
    if (!incognito_value->GetAsBoolean(&out->incognito)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<InspectOptions> InspectOptions::FromValue(const base::Value& value) {
  std::unique_ptr<InspectOptions> out(new InspectOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> InspectOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("extension_id", std::make_unique<base::Value>(this->extension_id));

  to_value_result->SetWithoutPathExpansion("render_process_id", (this->render_process_id).ToValue());

  to_value_result->SetWithoutPathExpansion("render_view_id", (this->render_view_id).ToValue());

  to_value_result->SetWithoutPathExpansion("incognito", std::make_unique<base::Value>(this->incognito));


  return to_value_result;
}


InstallWarning::InstallWarning()
 {}

InstallWarning::~InstallWarning() {}
InstallWarning::InstallWarning(InstallWarning&& rhs)
: message(std::move(rhs.message)){
}

InstallWarning& InstallWarning::operator=(InstallWarning&& rhs)
{
message = std::move(rhs.message);
return *this;
}

// static
bool InstallWarning::Populate(
    const base::Value& value, InstallWarning* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* message_value = NULL;
  if (!dict->GetWithoutPathExpansion("message", &message_value)) {
    return false;
  }
  {
    if (!message_value->GetAsString(&out->message)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<InstallWarning> InstallWarning::FromValue(const base::Value& value) {
  std::unique_ptr<InstallWarning> out(new InstallWarning());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> InstallWarning::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("message", std::make_unique<base::Value>(this->message));


  return to_value_result;
}


const char* ToString(ExtensionType enum_param) {
  switch (enum_param) {
    case EXTENSION_TYPE_HOSTED_APP:
      return "HOSTED_APP";
    case EXTENSION_TYPE_PLATFORM_APP:
      return "PLATFORM_APP";
    case EXTENSION_TYPE_LEGACY_PACKAGED_APP:
      return "LEGACY_PACKAGED_APP";
    case EXTENSION_TYPE_EXTENSION:
      return "EXTENSION";
    case EXTENSION_TYPE_THEME:
      return "THEME";
    case EXTENSION_TYPE_SHARED_MODULE:
      return "SHARED_MODULE";
    case EXTENSION_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ExtensionType ParseExtensionType(const std::string& enum_string) {
  if (enum_string == "HOSTED_APP")
    return EXTENSION_TYPE_HOSTED_APP;
  if (enum_string == "PLATFORM_APP")
    return EXTENSION_TYPE_PLATFORM_APP;
  if (enum_string == "LEGACY_PACKAGED_APP")
    return EXTENSION_TYPE_LEGACY_PACKAGED_APP;
  if (enum_string == "EXTENSION")
    return EXTENSION_TYPE_EXTENSION;
  if (enum_string == "THEME")
    return EXTENSION_TYPE_THEME;
  if (enum_string == "SHARED_MODULE")
    return EXTENSION_TYPE_SHARED_MODULE;
  return EXTENSION_TYPE_NONE;
}


const char* ToString(Location enum_param) {
  switch (enum_param) {
    case LOCATION_FROM_STORE:
      return "FROM_STORE";
    case LOCATION_UNPACKED:
      return "UNPACKED";
    case LOCATION_THIRD_PARTY:
      return "THIRD_PARTY";
    case LOCATION_UNKNOWN:
      return "UNKNOWN";
    case LOCATION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Location ParseLocation(const std::string& enum_string) {
  if (enum_string == "FROM_STORE")
    return LOCATION_FROM_STORE;
  if (enum_string == "UNPACKED")
    return LOCATION_UNPACKED;
  if (enum_string == "THIRD_PARTY")
    return LOCATION_THIRD_PARTY;
  if (enum_string == "UNKNOWN")
    return LOCATION_UNKNOWN;
  return LOCATION_NONE;
}


const char* ToString(ViewType enum_param) {
  switch (enum_param) {
    case VIEW_TYPE_APP_WINDOW:
      return "APP_WINDOW";
    case VIEW_TYPE_BACKGROUND_CONTENTS:
      return "BACKGROUND_CONTENTS";
    case VIEW_TYPE_COMPONENT:
      return "COMPONENT";
    case VIEW_TYPE_EXTENSION_BACKGROUND_PAGE:
      return "EXTENSION_BACKGROUND_PAGE";
    case VIEW_TYPE_EXTENSION_DIALOG:
      return "EXTENSION_DIALOG";
    case VIEW_TYPE_EXTENSION_GUEST:
      return "EXTENSION_GUEST";
    case VIEW_TYPE_EXTENSION_POPUP:
      return "EXTENSION_POPUP";
    case VIEW_TYPE_TAB_CONTENTS:
      return "TAB_CONTENTS";
    case VIEW_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ViewType ParseViewType(const std::string& enum_string) {
  if (enum_string == "APP_WINDOW")
    return VIEW_TYPE_APP_WINDOW;
  if (enum_string == "BACKGROUND_CONTENTS")
    return VIEW_TYPE_BACKGROUND_CONTENTS;
  if (enum_string == "COMPONENT")
    return VIEW_TYPE_COMPONENT;
  if (enum_string == "EXTENSION_BACKGROUND_PAGE")
    return VIEW_TYPE_EXTENSION_BACKGROUND_PAGE;
  if (enum_string == "EXTENSION_DIALOG")
    return VIEW_TYPE_EXTENSION_DIALOG;
  if (enum_string == "EXTENSION_GUEST")
    return VIEW_TYPE_EXTENSION_GUEST;
  if (enum_string == "EXTENSION_POPUP")
    return VIEW_TYPE_EXTENSION_POPUP;
  if (enum_string == "TAB_CONTENTS")
    return VIEW_TYPE_TAB_CONTENTS;
  return VIEW_TYPE_NONE;
}


const char* ToString(ErrorType enum_param) {
  switch (enum_param) {
    case ERROR_TYPE_MANIFEST:
      return "MANIFEST";
    case ERROR_TYPE_RUNTIME:
      return "RUNTIME";
    case ERROR_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ErrorType ParseErrorType(const std::string& enum_string) {
  if (enum_string == "MANIFEST")
    return ERROR_TYPE_MANIFEST;
  if (enum_string == "RUNTIME")
    return ERROR_TYPE_RUNTIME;
  return ERROR_TYPE_NONE;
}


const char* ToString(ErrorLevel enum_param) {
  switch (enum_param) {
    case ERROR_LEVEL_LOG:
      return "LOG";
    case ERROR_LEVEL_WARN:
      return "WARN";
    case ERROR_LEVEL_ERROR:
      return "ERROR";
    case ERROR_LEVEL_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ErrorLevel ParseErrorLevel(const std::string& enum_string) {
  if (enum_string == "LOG")
    return ERROR_LEVEL_LOG;
  if (enum_string == "WARN")
    return ERROR_LEVEL_WARN;
  if (enum_string == "ERROR")
    return ERROR_LEVEL_ERROR;
  return ERROR_LEVEL_NONE;
}


const char* ToString(ExtensionState enum_param) {
  switch (enum_param) {
    case EXTENSION_STATE_ENABLED:
      return "ENABLED";
    case EXTENSION_STATE_DISABLED:
      return "DISABLED";
    case EXTENSION_STATE_TERMINATED:
      return "TERMINATED";
    case EXTENSION_STATE_BLACKLISTED:
      return "BLACKLISTED";
    case EXTENSION_STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ExtensionState ParseExtensionState(const std::string& enum_string) {
  if (enum_string == "ENABLED")
    return EXTENSION_STATE_ENABLED;
  if (enum_string == "DISABLED")
    return EXTENSION_STATE_DISABLED;
  if (enum_string == "TERMINATED")
    return EXTENSION_STATE_TERMINATED;
  if (enum_string == "BLACKLISTED")
    return EXTENSION_STATE_BLACKLISTED;
  return EXTENSION_STATE_NONE;
}


const char* ToString(CommandScope enum_param) {
  switch (enum_param) {
    case COMMAND_SCOPE_GLOBAL:
      return "GLOBAL";
    case COMMAND_SCOPE_CHROME:
      return "CHROME";
    case COMMAND_SCOPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

CommandScope ParseCommandScope(const std::string& enum_string) {
  if (enum_string == "GLOBAL")
    return COMMAND_SCOPE_GLOBAL;
  if (enum_string == "CHROME")
    return COMMAND_SCOPE_CHROME;
  return COMMAND_SCOPE_NONE;
}


AccessModifier::AccessModifier()
: is_enabled(false),
is_active(false) {}

AccessModifier::~AccessModifier() {}
AccessModifier::AccessModifier(AccessModifier&& rhs)
: is_enabled(rhs.is_enabled),
is_active(rhs.is_active){
}

AccessModifier& AccessModifier::operator=(AccessModifier&& rhs)
{
is_enabled = rhs.is_enabled;
is_active = rhs.is_active;
return *this;
}

// static
bool AccessModifier::Populate(
    const base::Value& value, AccessModifier* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* is_enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("isEnabled", &is_enabled_value)) {
    return false;
  }
  {
    if (!is_enabled_value->GetAsBoolean(&out->is_enabled)) {
      return false;
    }
  }

  const base::Value* is_active_value = NULL;
  if (!dict->GetWithoutPathExpansion("isActive", &is_active_value)) {
    return false;
  }
  {
    if (!is_active_value->GetAsBoolean(&out->is_active)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<AccessModifier> AccessModifier::FromValue(const base::Value& value) {
  std::unique_ptr<AccessModifier> out(new AccessModifier());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AccessModifier::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("isEnabled", std::make_unique<base::Value>(this->is_enabled));

  to_value_result->SetWithoutPathExpansion("isActive", std::make_unique<base::Value>(this->is_active));


  return to_value_result;
}


StackFrame::StackFrame()
: line_number(0),
column_number(0) {}

StackFrame::~StackFrame() {}
StackFrame::StackFrame(StackFrame&& rhs)
: line_number(rhs.line_number),
column_number(rhs.column_number),
url(std::move(rhs.url)),
function_name(std::move(rhs.function_name)){
}

StackFrame& StackFrame::operator=(StackFrame&& rhs)
{
line_number = rhs.line_number;
column_number = rhs.column_number;
url = std::move(rhs.url);
function_name = std::move(rhs.function_name);
return *this;
}

// static
bool StackFrame::Populate(
    const base::Value& value, StackFrame* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* line_number_value = NULL;
  if (!dict->GetWithoutPathExpansion("lineNumber", &line_number_value)) {
    return false;
  }
  {
    if (!line_number_value->GetAsInteger(&out->line_number)) {
      return false;
    }
  }

  const base::Value* column_number_value = NULL;
  if (!dict->GetWithoutPathExpansion("columnNumber", &column_number_value)) {
    return false;
  }
  {
    if (!column_number_value->GetAsInteger(&out->column_number)) {
      return false;
    }
  }

  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* function_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("functionName", &function_name_value)) {
    return false;
  }
  {
    if (!function_name_value->GetAsString(&out->function_name)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<StackFrame> StackFrame::FromValue(const base::Value& value) {
  std::unique_ptr<StackFrame> out(new StackFrame());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> StackFrame::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("lineNumber", std::make_unique<base::Value>(this->line_number));

  to_value_result->SetWithoutPathExpansion("columnNumber", std::make_unique<base::Value>(this->column_number));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("functionName", std::make_unique<base::Value>(this->function_name));


  return to_value_result;
}


ManifestError::ManifestError()
: type(ERROR_TYPE_NONE),
from_incognito(false),
id(0) {}

ManifestError::~ManifestError() {}
ManifestError::ManifestError(ManifestError&& rhs)
: type(rhs.type),
extension_id(std::move(rhs.extension_id)),
from_incognito(rhs.from_incognito),
source(std::move(rhs.source)),
message(std::move(rhs.message)),
id(rhs.id),
manifest_key(std::move(rhs.manifest_key)),
manifest_specific(std::move(rhs.manifest_specific)){
}

ManifestError& ManifestError::operator=(ManifestError&& rhs)
{
type = rhs.type;
extension_id = std::move(rhs.extension_id);
from_incognito = rhs.from_incognito;
source = std::move(rhs.source);
message = std::move(rhs.message);
id = rhs.id;
manifest_key = std::move(rhs.manifest_key);
manifest_specific = std::move(rhs.manifest_specific);
return *this;
}

// static
bool ManifestError::Populate(
    const base::Value& value, ManifestError* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string error_type_as_string;
    if (!type_value->GetAsString(&error_type_as_string)) {
      return false;
    }
    out->type = ParseErrorType(error_type_as_string);
    if (out->type == ERROR_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* extension_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    return false;
  }
  {
    if (!extension_id_value->GetAsString(&out->extension_id)) {
      return false;
    }
  }

  const base::Value* from_incognito_value = NULL;
  if (!dict->GetWithoutPathExpansion("fromIncognito", &from_incognito_value)) {
    return false;
  }
  {
    if (!from_incognito_value->GetAsBoolean(&out->from_incognito)) {
      return false;
    }
  }

  const base::Value* source_value = NULL;
  if (!dict->GetWithoutPathExpansion("source", &source_value)) {
    return false;
  }
  {
    if (!source_value->GetAsString(&out->source)) {
      return false;
    }
  }

  const base::Value* message_value = NULL;
  if (!dict->GetWithoutPathExpansion("message", &message_value)) {
    return false;
  }
  {
    if (!message_value->GetAsString(&out->message)) {
      return false;
    }
  }

  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsInteger(&out->id)) {
      return false;
    }
  }

  const base::Value* manifest_key_value = NULL;
  if (!dict->GetWithoutPathExpansion("manifestKey", &manifest_key_value)) {
    return false;
  }
  {
    if (!manifest_key_value->GetAsString(&out->manifest_key)) {
      return false;
    }
  }

  const base::Value* manifest_specific_value = NULL;
  if (dict->GetWithoutPathExpansion("manifestSpecific", &manifest_specific_value)) {
    {
      std::string temp;
      if (!manifest_specific_value->GetAsString(&temp)) {
        out->manifest_specific.reset();
        return false;
      }
      else
        out->manifest_specific.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ManifestError> ManifestError::FromValue(const base::Value& value) {
  std::unique_ptr<ManifestError> out(new ManifestError());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManifestError::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(developer_private::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(this->extension_id));

  to_value_result->SetWithoutPathExpansion("fromIncognito", std::make_unique<base::Value>(this->from_incognito));

  to_value_result->SetWithoutPathExpansion("source", std::make_unique<base::Value>(this->source));

  to_value_result->SetWithoutPathExpansion("message", std::make_unique<base::Value>(this->message));

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("manifestKey", std::make_unique<base::Value>(this->manifest_key));

  if (this->manifest_specific.get()) {
    to_value_result->SetWithoutPathExpansion("manifestSpecific", std::make_unique<base::Value>(*this->manifest_specific));

  }

  return to_value_result;
}


RuntimeError::RuntimeError()
: type(ERROR_TYPE_NONE),
from_incognito(false),
id(0),
severity(ERROR_LEVEL_NONE),
occurrences(0),
render_view_id(0),
render_process_id(0),
can_inspect(false) {}

RuntimeError::~RuntimeError() {}
RuntimeError::RuntimeError(RuntimeError&& rhs)
: type(rhs.type),
extension_id(std::move(rhs.extension_id)),
from_incognito(rhs.from_incognito),
source(std::move(rhs.source)),
message(std::move(rhs.message)),
id(rhs.id),
severity(rhs.severity),
context_url(std::move(rhs.context_url)),
occurrences(rhs.occurrences),
render_view_id(rhs.render_view_id),
render_process_id(rhs.render_process_id),
can_inspect(rhs.can_inspect),
stack_trace(std::move(rhs.stack_trace)){
}

RuntimeError& RuntimeError::operator=(RuntimeError&& rhs)
{
type = rhs.type;
extension_id = std::move(rhs.extension_id);
from_incognito = rhs.from_incognito;
source = std::move(rhs.source);
message = std::move(rhs.message);
id = rhs.id;
severity = rhs.severity;
context_url = std::move(rhs.context_url);
occurrences = rhs.occurrences;
render_view_id = rhs.render_view_id;
render_process_id = rhs.render_process_id;
can_inspect = rhs.can_inspect;
stack_trace = std::move(rhs.stack_trace);
return *this;
}

// static
bool RuntimeError::Populate(
    const base::Value& value, RuntimeError* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string error_type_as_string;
    if (!type_value->GetAsString(&error_type_as_string)) {
      return false;
    }
    out->type = ParseErrorType(error_type_as_string);
    if (out->type == ERROR_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* extension_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    return false;
  }
  {
    if (!extension_id_value->GetAsString(&out->extension_id)) {
      return false;
    }
  }

  const base::Value* from_incognito_value = NULL;
  if (!dict->GetWithoutPathExpansion("fromIncognito", &from_incognito_value)) {
    return false;
  }
  {
    if (!from_incognito_value->GetAsBoolean(&out->from_incognito)) {
      return false;
    }
  }

  const base::Value* source_value = NULL;
  if (!dict->GetWithoutPathExpansion("source", &source_value)) {
    return false;
  }
  {
    if (!source_value->GetAsString(&out->source)) {
      return false;
    }
  }

  const base::Value* message_value = NULL;
  if (!dict->GetWithoutPathExpansion("message", &message_value)) {
    return false;
  }
  {
    if (!message_value->GetAsString(&out->message)) {
      return false;
    }
  }

  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsInteger(&out->id)) {
      return false;
    }
  }

  const base::Value* severity_value = NULL;
  if (!dict->GetWithoutPathExpansion("severity", &severity_value)) {
    return false;
  }
  {
    std::string error_level_as_string;
    if (!severity_value->GetAsString(&error_level_as_string)) {
      return false;
    }
    out->severity = ParseErrorLevel(error_level_as_string);
    if (out->severity == ERROR_LEVEL_NONE) {
      return false;
    }
  }

  const base::Value* context_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("contextUrl", &context_url_value)) {
    return false;
  }
  {
    if (!context_url_value->GetAsString(&out->context_url)) {
      return false;
    }
  }

  const base::Value* occurrences_value = NULL;
  if (!dict->GetWithoutPathExpansion("occurrences", &occurrences_value)) {
    return false;
  }
  {
    if (!occurrences_value->GetAsInteger(&out->occurrences)) {
      return false;
    }
  }

  const base::Value* render_view_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("renderViewId", &render_view_id_value)) {
    return false;
  }
  {
    if (!render_view_id_value->GetAsInteger(&out->render_view_id)) {
      return false;
    }
  }

  const base::Value* render_process_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("renderProcessId", &render_process_id_value)) {
    return false;
  }
  {
    if (!render_process_id_value->GetAsInteger(&out->render_process_id)) {
      return false;
    }
  }

  const base::Value* can_inspect_value = NULL;
  if (!dict->GetWithoutPathExpansion("canInspect", &can_inspect_value)) {
    return false;
  }
  {
    if (!can_inspect_value->GetAsBoolean(&out->can_inspect)) {
      return false;
    }
  }

  const base::Value* stack_trace_value = NULL;
  if (!dict->GetWithoutPathExpansion("stackTrace", &stack_trace_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!stack_trace_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->stack_trace)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<RuntimeError> RuntimeError::FromValue(const base::Value& value) {
  std::unique_ptr<RuntimeError> out(new RuntimeError());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RuntimeError::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(developer_private::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(this->extension_id));

  to_value_result->SetWithoutPathExpansion("fromIncognito", std::make_unique<base::Value>(this->from_incognito));

  to_value_result->SetWithoutPathExpansion("source", std::make_unique<base::Value>(this->source));

  to_value_result->SetWithoutPathExpansion("message", std::make_unique<base::Value>(this->message));

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("severity", std::make_unique<base::Value>(developer_private::ToString(this->severity)));

  to_value_result->SetWithoutPathExpansion("contextUrl", std::make_unique<base::Value>(this->context_url));

  to_value_result->SetWithoutPathExpansion("occurrences", std::make_unique<base::Value>(this->occurrences));

  to_value_result->SetWithoutPathExpansion("renderViewId", std::make_unique<base::Value>(this->render_view_id));

  to_value_result->SetWithoutPathExpansion("renderProcessId", std::make_unique<base::Value>(this->render_process_id));

  to_value_result->SetWithoutPathExpansion("canInspect", std::make_unique<base::Value>(this->can_inspect));

  to_value_result->SetWithoutPathExpansion("stackTrace", json_schema_compiler::util::CreateValueFromArray(this->stack_trace));


  return to_value_result;
}


DisableReasons::DisableReasons()
: suspicious_install(false),
corrupt_install(false),
update_required(false),
blocked_by_policy(false),
custodian_approval_required(false),
parent_disabled_permissions(false) {}

DisableReasons::~DisableReasons() {}
DisableReasons::DisableReasons(DisableReasons&& rhs)
: suspicious_install(rhs.suspicious_install),
corrupt_install(rhs.corrupt_install),
update_required(rhs.update_required),
blocked_by_policy(rhs.blocked_by_policy),
custodian_approval_required(rhs.custodian_approval_required),
parent_disabled_permissions(rhs.parent_disabled_permissions){
}

DisableReasons& DisableReasons::operator=(DisableReasons&& rhs)
{
suspicious_install = rhs.suspicious_install;
corrupt_install = rhs.corrupt_install;
update_required = rhs.update_required;
blocked_by_policy = rhs.blocked_by_policy;
custodian_approval_required = rhs.custodian_approval_required;
parent_disabled_permissions = rhs.parent_disabled_permissions;
return *this;
}

// static
bool DisableReasons::Populate(
    const base::Value& value, DisableReasons* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* suspicious_install_value = NULL;
  if (!dict->GetWithoutPathExpansion("suspiciousInstall", &suspicious_install_value)) {
    return false;
  }
  {
    if (!suspicious_install_value->GetAsBoolean(&out->suspicious_install)) {
      return false;
    }
  }

  const base::Value* corrupt_install_value = NULL;
  if (!dict->GetWithoutPathExpansion("corruptInstall", &corrupt_install_value)) {
    return false;
  }
  {
    if (!corrupt_install_value->GetAsBoolean(&out->corrupt_install)) {
      return false;
    }
  }

  const base::Value* update_required_value = NULL;
  if (!dict->GetWithoutPathExpansion("updateRequired", &update_required_value)) {
    return false;
  }
  {
    if (!update_required_value->GetAsBoolean(&out->update_required)) {
      return false;
    }
  }

  const base::Value* blocked_by_policy_value = NULL;
  if (!dict->GetWithoutPathExpansion("blockedByPolicy", &blocked_by_policy_value)) {
    return false;
  }
  {
    if (!blocked_by_policy_value->GetAsBoolean(&out->blocked_by_policy)) {
      return false;
    }
  }

  const base::Value* custodian_approval_required_value = NULL;
  if (!dict->GetWithoutPathExpansion("custodianApprovalRequired", &custodian_approval_required_value)) {
    return false;
  }
  {
    if (!custodian_approval_required_value->GetAsBoolean(&out->custodian_approval_required)) {
      return false;
    }
  }

  const base::Value* parent_disabled_permissions_value = NULL;
  if (!dict->GetWithoutPathExpansion("parentDisabledPermissions", &parent_disabled_permissions_value)) {
    return false;
  }
  {
    if (!parent_disabled_permissions_value->GetAsBoolean(&out->parent_disabled_permissions)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<DisableReasons> DisableReasons::FromValue(const base::Value& value) {
  std::unique_ptr<DisableReasons> out(new DisableReasons());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DisableReasons::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("suspiciousInstall", std::make_unique<base::Value>(this->suspicious_install));

  to_value_result->SetWithoutPathExpansion("corruptInstall", std::make_unique<base::Value>(this->corrupt_install));

  to_value_result->SetWithoutPathExpansion("updateRequired", std::make_unique<base::Value>(this->update_required));

  to_value_result->SetWithoutPathExpansion("blockedByPolicy", std::make_unique<base::Value>(this->blocked_by_policy));

  to_value_result->SetWithoutPathExpansion("custodianApprovalRequired", std::make_unique<base::Value>(this->custodian_approval_required));

  to_value_result->SetWithoutPathExpansion("parentDisabledPermissions", std::make_unique<base::Value>(this->parent_disabled_permissions));


  return to_value_result;
}


OptionsPage::OptionsPage()
: open_in_tab(false) {}

OptionsPage::~OptionsPage() {}
OptionsPage::OptionsPage(OptionsPage&& rhs)
: open_in_tab(rhs.open_in_tab),
url(std::move(rhs.url)){
}

OptionsPage& OptionsPage::operator=(OptionsPage&& rhs)
{
open_in_tab = rhs.open_in_tab;
url = std::move(rhs.url);
return *this;
}

// static
bool OptionsPage::Populate(
    const base::Value& value, OptionsPage* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* open_in_tab_value = NULL;
  if (!dict->GetWithoutPathExpansion("openInTab", &open_in_tab_value)) {
    return false;
  }
  {
    if (!open_in_tab_value->GetAsBoolean(&out->open_in_tab)) {
      return false;
    }
  }

  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<OptionsPage> OptionsPage::FromValue(const base::Value& value) {
  std::unique_ptr<OptionsPage> out(new OptionsPage());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> OptionsPage::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("openInTab", std::make_unique<base::Value>(this->open_in_tab));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));


  return to_value_result;
}


HomePage::HomePage()
: specified(false) {}

HomePage::~HomePage() {}
HomePage::HomePage(HomePage&& rhs)
: url(std::move(rhs.url)),
specified(rhs.specified){
}

HomePage& HomePage::operator=(HomePage&& rhs)
{
url = std::move(rhs.url);
specified = rhs.specified;
return *this;
}

// static
bool HomePage::Populate(
    const base::Value& value, HomePage* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* specified_value = NULL;
  if (!dict->GetWithoutPathExpansion("specified", &specified_value)) {
    return false;
  }
  {
    if (!specified_value->GetAsBoolean(&out->specified)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<HomePage> HomePage::FromValue(const base::Value& value) {
  std::unique_ptr<HomePage> out(new HomePage());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> HomePage::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("specified", std::make_unique<base::Value>(this->specified));


  return to_value_result;
}


ExtensionView::ExtensionView()
: render_process_id(0),
render_view_id(0),
incognito(false),
is_iframe(false),
type(VIEW_TYPE_NONE) {}

ExtensionView::~ExtensionView() {}
ExtensionView::ExtensionView(ExtensionView&& rhs)
: url(std::move(rhs.url)),
render_process_id(rhs.render_process_id),
render_view_id(rhs.render_view_id),
incognito(rhs.incognito),
is_iframe(rhs.is_iframe),
type(rhs.type){
}

ExtensionView& ExtensionView::operator=(ExtensionView&& rhs)
{
url = std::move(rhs.url);
render_process_id = rhs.render_process_id;
render_view_id = rhs.render_view_id;
incognito = rhs.incognito;
is_iframe = rhs.is_iframe;
type = rhs.type;
return *this;
}

// static
bool ExtensionView::Populate(
    const base::Value& value, ExtensionView* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* render_process_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("renderProcessId", &render_process_id_value)) {
    return false;
  }
  {
    if (!render_process_id_value->GetAsInteger(&out->render_process_id)) {
      return false;
    }
  }

  const base::Value* render_view_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("renderViewId", &render_view_id_value)) {
    return false;
  }
  {
    if (!render_view_id_value->GetAsInteger(&out->render_view_id)) {
      return false;
    }
  }

  const base::Value* incognito_value = NULL;
  if (!dict->GetWithoutPathExpansion("incognito", &incognito_value)) {
    return false;
  }
  {
    if (!incognito_value->GetAsBoolean(&out->incognito)) {
      return false;
    }
  }

  const base::Value* is_iframe_value = NULL;
  if (!dict->GetWithoutPathExpansion("isIframe", &is_iframe_value)) {
    return false;
  }
  {
    if (!is_iframe_value->GetAsBoolean(&out->is_iframe)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string view_type_as_string;
    if (!type_value->GetAsString(&view_type_as_string)) {
      return false;
    }
    out->type = ParseViewType(view_type_as_string);
    if (out->type == VIEW_TYPE_NONE) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ExtensionView> ExtensionView::FromValue(const base::Value& value) {
  std::unique_ptr<ExtensionView> out(new ExtensionView());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ExtensionView::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("renderProcessId", std::make_unique<base::Value>(this->render_process_id));

  to_value_result->SetWithoutPathExpansion("renderViewId", std::make_unique<base::Value>(this->render_view_id));

  to_value_result->SetWithoutPathExpansion("incognito", std::make_unique<base::Value>(this->incognito));

  to_value_result->SetWithoutPathExpansion("isIframe", std::make_unique<base::Value>(this->is_iframe));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(developer_private::ToString(this->type)));


  return to_value_result;
}


const char* ToString(ControllerType enum_param) {
  switch (enum_param) {
    case CONTROLLER_TYPE_POLICY:
      return "POLICY";
    case CONTROLLER_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ControllerType ParseControllerType(const std::string& enum_string) {
  if (enum_string == "POLICY")
    return CONTROLLER_TYPE_POLICY;
  return CONTROLLER_TYPE_NONE;
}


const char* ToString(HostAccess enum_param) {
  switch (enum_param) {
    case HOST_ACCESS_ON_CLICK:
      return "ON_CLICK";
    case HOST_ACCESS_ON_SPECIFIC_SITES:
      return "ON_SPECIFIC_SITES";
    case HOST_ACCESS_ON_ALL_SITES:
      return "ON_ALL_SITES";
    case HOST_ACCESS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

HostAccess ParseHostAccess(const std::string& enum_string) {
  if (enum_string == "ON_CLICK")
    return HOST_ACCESS_ON_CLICK;
  if (enum_string == "ON_SPECIFIC_SITES")
    return HOST_ACCESS_ON_SPECIFIC_SITES;
  if (enum_string == "ON_ALL_SITES")
    return HOST_ACCESS_ON_ALL_SITES;
  return HOST_ACCESS_NONE;
}


ControlledInfo::ControlledInfo()
: type(CONTROLLER_TYPE_NONE) {}

ControlledInfo::~ControlledInfo() {}
ControlledInfo::ControlledInfo(ControlledInfo&& rhs)
: type(rhs.type),
text(std::move(rhs.text)){
}

ControlledInfo& ControlledInfo::operator=(ControlledInfo&& rhs)
{
type = rhs.type;
text = std::move(rhs.text);
return *this;
}

// static
bool ControlledInfo::Populate(
    const base::Value& value, ControlledInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string controller_type_as_string;
    if (!type_value->GetAsString(&controller_type_as_string)) {
      return false;
    }
    out->type = ParseControllerType(controller_type_as_string);
    if (out->type == CONTROLLER_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* text_value = NULL;
  if (!dict->GetWithoutPathExpansion("text", &text_value)) {
    return false;
  }
  {
    if (!text_value->GetAsString(&out->text)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ControlledInfo> ControlledInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ControlledInfo> out(new ControlledInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ControlledInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(developer_private::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("text", std::make_unique<base::Value>(this->text));


  return to_value_result;
}


Command::Command()
: is_active(false),
scope(COMMAND_SCOPE_NONE),
is_extension_action(false) {}

Command::~Command() {}
Command::Command(Command&& rhs)
: description(std::move(rhs.description)),
keybinding(std::move(rhs.keybinding)),
name(std::move(rhs.name)),
is_active(rhs.is_active),
scope(rhs.scope),
is_extension_action(rhs.is_extension_action){
}

Command& Command::operator=(Command&& rhs)
{
description = std::move(rhs.description);
keybinding = std::move(rhs.keybinding);
name = std::move(rhs.name);
is_active = rhs.is_active;
scope = rhs.scope;
is_extension_action = rhs.is_extension_action;
return *this;
}

// static
bool Command::Populate(
    const base::Value& value, Command* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* description_value = NULL;
  if (!dict->GetWithoutPathExpansion("description", &description_value)) {
    return false;
  }
  {
    if (!description_value->GetAsString(&out->description)) {
      return false;
    }
  }

  const base::Value* keybinding_value = NULL;
  if (!dict->GetWithoutPathExpansion("keybinding", &keybinding_value)) {
    return false;
  }
  {
    if (!keybinding_value->GetAsString(&out->keybinding)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* is_active_value = NULL;
  if (!dict->GetWithoutPathExpansion("isActive", &is_active_value)) {
    return false;
  }
  {
    if (!is_active_value->GetAsBoolean(&out->is_active)) {
      return false;
    }
  }

  const base::Value* scope_value = NULL;
  if (!dict->GetWithoutPathExpansion("scope", &scope_value)) {
    return false;
  }
  {
    std::string command_scope_as_string;
    if (!scope_value->GetAsString(&command_scope_as_string)) {
      return false;
    }
    out->scope = ParseCommandScope(command_scope_as_string);
    if (out->scope == COMMAND_SCOPE_NONE) {
      return false;
    }
  }

  const base::Value* is_extension_action_value = NULL;
  if (!dict->GetWithoutPathExpansion("isExtensionAction", &is_extension_action_value)) {
    return false;
  }
  {
    if (!is_extension_action_value->GetAsBoolean(&out->is_extension_action)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Command> Command::FromValue(const base::Value& value) {
  std::unique_ptr<Command> out(new Command());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Command::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(this->description));

  to_value_result->SetWithoutPathExpansion("keybinding", std::make_unique<base::Value>(this->keybinding));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("isActive", std::make_unique<base::Value>(this->is_active));

  to_value_result->SetWithoutPathExpansion("scope", std::make_unique<base::Value>(developer_private::ToString(this->scope)));

  to_value_result->SetWithoutPathExpansion("isExtensionAction", std::make_unique<base::Value>(this->is_extension_action));


  return to_value_result;
}


DependentExtension::DependentExtension()
 {}

DependentExtension::~DependentExtension() {}
DependentExtension::DependentExtension(DependentExtension&& rhs)
: id(std::move(rhs.id)),
name(std::move(rhs.name)){
}

DependentExtension& DependentExtension::operator=(DependentExtension&& rhs)
{
id = std::move(rhs.id);
name = std::move(rhs.name);
return *this;
}

// static
bool DependentExtension::Populate(
    const base::Value& value, DependentExtension* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<DependentExtension> DependentExtension::FromValue(const base::Value& value) {
  std::unique_ptr<DependentExtension> out(new DependentExtension());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DependentExtension::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));


  return to_value_result;
}


Permission::Permission()
 {}

Permission::~Permission() {}
Permission::Permission(Permission&& rhs)
: message(std::move(rhs.message)),
submessages(std::move(rhs.submessages)){
}

Permission& Permission::operator=(Permission&& rhs)
{
message = std::move(rhs.message);
submessages = std::move(rhs.submessages);
return *this;
}

// static
bool Permission::Populate(
    const base::Value& value, Permission* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* message_value = NULL;
  if (!dict->GetWithoutPathExpansion("message", &message_value)) {
    return false;
  }
  {
    if (!message_value->GetAsString(&out->message)) {
      return false;
    }
  }

  const base::Value* submessages_value = NULL;
  if (!dict->GetWithoutPathExpansion("submessages", &submessages_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!submessages_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->submessages)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Permission> Permission::FromValue(const base::Value& value) {
  std::unique_ptr<Permission> out(new Permission());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Permission::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("message", std::make_unique<base::Value>(this->message));

  to_value_result->SetWithoutPathExpansion("submessages", json_schema_compiler::util::CreateValueFromArray(this->submessages));


  return to_value_result;
}


SiteControl::SiteControl()
: granted(false) {}

SiteControl::~SiteControl() {}
SiteControl::SiteControl(SiteControl&& rhs)
: host(std::move(rhs.host)),
granted(rhs.granted){
}

SiteControl& SiteControl::operator=(SiteControl&& rhs)
{
host = std::move(rhs.host);
granted = rhs.granted;
return *this;
}

// static
bool SiteControl::Populate(
    const base::Value& value, SiteControl* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* host_value = NULL;
  if (!dict->GetWithoutPathExpansion("host", &host_value)) {
    return false;
  }
  {
    if (!host_value->GetAsString(&out->host)) {
      return false;
    }
  }

  const base::Value* granted_value = NULL;
  if (!dict->GetWithoutPathExpansion("granted", &granted_value)) {
    return false;
  }
  {
    if (!granted_value->GetAsBoolean(&out->granted)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<SiteControl> SiteControl::FromValue(const base::Value& value) {
  std::unique_ptr<SiteControl> out(new SiteControl());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SiteControl::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("host", std::make_unique<base::Value>(this->host));

  to_value_result->SetWithoutPathExpansion("granted", std::make_unique<base::Value>(this->granted));


  return to_value_result;
}


RuntimeHostPermissions::RuntimeHostPermissions()
: has_all_hosts(false),
host_access(HOST_ACCESS_NONE) {}

RuntimeHostPermissions::~RuntimeHostPermissions() {}
RuntimeHostPermissions::RuntimeHostPermissions(RuntimeHostPermissions&& rhs)
: has_all_hosts(rhs.has_all_hosts),
host_access(rhs.host_access),
hosts(std::move(rhs.hosts)){
}

RuntimeHostPermissions& RuntimeHostPermissions::operator=(RuntimeHostPermissions&& rhs)
{
has_all_hosts = rhs.has_all_hosts;
host_access = rhs.host_access;
hosts = std::move(rhs.hosts);
return *this;
}

// static
bool RuntimeHostPermissions::Populate(
    const base::Value& value, RuntimeHostPermissions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* has_all_hosts_value = NULL;
  if (!dict->GetWithoutPathExpansion("hasAllHosts", &has_all_hosts_value)) {
    return false;
  }
  {
    if (!has_all_hosts_value->GetAsBoolean(&out->has_all_hosts)) {
      return false;
    }
  }

  const base::Value* host_access_value = NULL;
  if (!dict->GetWithoutPathExpansion("hostAccess", &host_access_value)) {
    return false;
  }
  {
    std::string host_access_as_string;
    if (!host_access_value->GetAsString(&host_access_as_string)) {
      return false;
    }
    out->host_access = ParseHostAccess(host_access_as_string);
    if (out->host_access == HOST_ACCESS_NONE) {
      return false;
    }
  }

  const base::Value* hosts_value = NULL;
  if (!dict->GetWithoutPathExpansion("hosts", &hosts_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!hosts_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->hosts)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<RuntimeHostPermissions> RuntimeHostPermissions::FromValue(const base::Value& value) {
  std::unique_ptr<RuntimeHostPermissions> out(new RuntimeHostPermissions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RuntimeHostPermissions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("hasAllHosts", std::make_unique<base::Value>(this->has_all_hosts));

  to_value_result->SetWithoutPathExpansion("hostAccess", std::make_unique<base::Value>(developer_private::ToString(this->host_access)));

  to_value_result->SetWithoutPathExpansion("hosts", json_schema_compiler::util::CreateValueFromArray(this->hosts));


  return to_value_result;
}


Permissions::Permissions()
 {}

Permissions::~Permissions() {}
Permissions::Permissions(Permissions&& rhs)
: simple_permissions(std::move(rhs.simple_permissions)),
runtime_host_permissions(std::move(rhs.runtime_host_permissions)){
}

Permissions& Permissions::operator=(Permissions&& rhs)
{
simple_permissions = std::move(rhs.simple_permissions);
runtime_host_permissions = std::move(rhs.runtime_host_permissions);
return *this;
}

// static
bool Permissions::Populate(
    const base::Value& value, Permissions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* simple_permissions_value = NULL;
  if (!dict->GetWithoutPathExpansion("simplePermissions", &simple_permissions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!simple_permissions_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->simple_permissions)) {
        return false;
      }
    }
  }

  const base::Value* runtime_host_permissions_value = NULL;
  if (dict->GetWithoutPathExpansion("runtimeHostPermissions", &runtime_host_permissions_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!runtime_host_permissions_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<RuntimeHostPermissions> temp(new RuntimeHostPermissions());
        if (!RuntimeHostPermissions::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->runtime_host_permissions = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Permissions> Permissions::FromValue(const base::Value& value) {
  std::unique_ptr<Permissions> out(new Permissions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Permissions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("simplePermissions", json_schema_compiler::util::CreateValueFromArray(this->simple_permissions));

  if (this->runtime_host_permissions.get()) {
    to_value_result->SetWithoutPathExpansion("runtimeHostPermissions", (this->runtime_host_permissions)->ToValue());

  }

  return to_value_result;
}


ExtensionInfo::ExtensionInfo()
: location(LOCATION_NONE),
must_remain_installed(false),
offline_enabled(false),
state(EXTENSION_STATE_NONE),
type(EXTENSION_TYPE_NONE),
user_may_modify(false) {}

ExtensionInfo::~ExtensionInfo() {}
ExtensionInfo::ExtensionInfo(ExtensionInfo&& rhs)
: blacklist_text(std::move(rhs.blacklist_text)),
commands(std::move(rhs.commands)),
controlled_info(std::move(rhs.controlled_info)),
dependent_extensions(std::move(rhs.dependent_extensions)),
description(std::move(rhs.description)),
disable_reasons(std::move(rhs.disable_reasons)),
error_collection(std::move(rhs.error_collection)),
file_access(std::move(rhs.file_access)),
home_page(std::move(rhs.home_page)),
icon_url(std::move(rhs.icon_url)),
id(std::move(rhs.id)),
incognito_access(std::move(rhs.incognito_access)),
install_warnings(std::move(rhs.install_warnings)),
launch_url(std::move(rhs.launch_url)),
location(rhs.location),
location_text(std::move(rhs.location_text)),
manifest_errors(std::move(rhs.manifest_errors)),
manifest_home_page_url(std::move(rhs.manifest_home_page_url)),
must_remain_installed(rhs.must_remain_installed),
name(std::move(rhs.name)),
offline_enabled(rhs.offline_enabled),
options_page(std::move(rhs.options_page)),
path(std::move(rhs.path)),
permissions(std::move(rhs.permissions)),
prettified_path(std::move(rhs.prettified_path)),
runtime_errors(std::move(rhs.runtime_errors)),
runtime_warnings(std::move(rhs.runtime_warnings)),
state(rhs.state),
type(rhs.type),
update_url(std::move(rhs.update_url)),
user_may_modify(rhs.user_may_modify),
version(std::move(rhs.version)),
views(std::move(rhs.views)),
web_store_url(std::move(rhs.web_store_url)){
}

ExtensionInfo& ExtensionInfo::operator=(ExtensionInfo&& rhs)
{
blacklist_text = std::move(rhs.blacklist_text);
commands = std::move(rhs.commands);
controlled_info = std::move(rhs.controlled_info);
dependent_extensions = std::move(rhs.dependent_extensions);
description = std::move(rhs.description);
disable_reasons = std::move(rhs.disable_reasons);
error_collection = std::move(rhs.error_collection);
file_access = std::move(rhs.file_access);
home_page = std::move(rhs.home_page);
icon_url = std::move(rhs.icon_url);
id = std::move(rhs.id);
incognito_access = std::move(rhs.incognito_access);
install_warnings = std::move(rhs.install_warnings);
launch_url = std::move(rhs.launch_url);
location = rhs.location;
location_text = std::move(rhs.location_text);
manifest_errors = std::move(rhs.manifest_errors);
manifest_home_page_url = std::move(rhs.manifest_home_page_url);
must_remain_installed = rhs.must_remain_installed;
name = std::move(rhs.name);
offline_enabled = rhs.offline_enabled;
options_page = std::move(rhs.options_page);
path = std::move(rhs.path);
permissions = std::move(rhs.permissions);
prettified_path = std::move(rhs.prettified_path);
runtime_errors = std::move(rhs.runtime_errors);
runtime_warnings = std::move(rhs.runtime_warnings);
state = rhs.state;
type = rhs.type;
update_url = std::move(rhs.update_url);
user_may_modify = rhs.user_may_modify;
version = std::move(rhs.version);
views = std::move(rhs.views);
web_store_url = std::move(rhs.web_store_url);
return *this;
}

// static
bool ExtensionInfo::Populate(
    const base::Value& value, ExtensionInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* blacklist_text_value = NULL;
  if (dict->GetWithoutPathExpansion("blacklistText", &blacklist_text_value)) {
    {
      std::string temp;
      if (!blacklist_text_value->GetAsString(&temp)) {
        out->blacklist_text.reset();
        return false;
      }
      else
        out->blacklist_text.reset(new std::string(temp));
    }
  }

  const base::Value* commands_value = NULL;
  if (!dict->GetWithoutPathExpansion("commands", &commands_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!commands_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->commands)) {
        return false;
      }
    }
  }

  const base::Value* controlled_info_value = NULL;
  if (dict->GetWithoutPathExpansion("controlledInfo", &controlled_info_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!controlled_info_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ControlledInfo> temp(new ControlledInfo());
        if (!ControlledInfo::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->controlled_info = std::move(temp);
      }
    }
  }

  const base::Value* dependent_extensions_value = NULL;
  if (!dict->GetWithoutPathExpansion("dependentExtensions", &dependent_extensions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!dependent_extensions_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->dependent_extensions)) {
        return false;
      }
    }
  }

  const base::Value* description_value = NULL;
  if (!dict->GetWithoutPathExpansion("description", &description_value)) {
    return false;
  }
  {
    if (!description_value->GetAsString(&out->description)) {
      return false;
    }
  }

  const base::Value* disable_reasons_value = NULL;
  if (!dict->GetWithoutPathExpansion("disableReasons", &disable_reasons_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!disable_reasons_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!DisableReasons::Populate(*dictionary, &out->disable_reasons)) {
      return false;
    }
  }

  const base::Value* error_collection_value = NULL;
  if (!dict->GetWithoutPathExpansion("errorCollection", &error_collection_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!error_collection_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!AccessModifier::Populate(*dictionary, &out->error_collection)) {
      return false;
    }
  }

  const base::Value* file_access_value = NULL;
  if (!dict->GetWithoutPathExpansion("fileAccess", &file_access_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!file_access_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!AccessModifier::Populate(*dictionary, &out->file_access)) {
      return false;
    }
  }

  const base::Value* home_page_value = NULL;
  if (!dict->GetWithoutPathExpansion("homePage", &home_page_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!home_page_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!HomePage::Populate(*dictionary, &out->home_page)) {
      return false;
    }
  }

  const base::Value* icon_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("iconUrl", &icon_url_value)) {
    return false;
  }
  {
    if (!icon_url_value->GetAsString(&out->icon_url)) {
      return false;
    }
  }

  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* incognito_access_value = NULL;
  if (!dict->GetWithoutPathExpansion("incognitoAccess", &incognito_access_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!incognito_access_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!AccessModifier::Populate(*dictionary, &out->incognito_access)) {
      return false;
    }
  }

  const base::Value* install_warnings_value = NULL;
  if (!dict->GetWithoutPathExpansion("installWarnings", &install_warnings_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!install_warnings_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->install_warnings)) {
        return false;
      }
    }
  }

  const base::Value* launch_url_value = NULL;
  if (dict->GetWithoutPathExpansion("launchUrl", &launch_url_value)) {
    {
      std::string temp;
      if (!launch_url_value->GetAsString(&temp)) {
        out->launch_url.reset();
        return false;
      }
      else
        out->launch_url.reset(new std::string(temp));
    }
  }

  const base::Value* location_value = NULL;
  if (!dict->GetWithoutPathExpansion("location", &location_value)) {
    return false;
  }
  {
    std::string location_as_string;
    if (!location_value->GetAsString(&location_as_string)) {
      return false;
    }
    out->location = ParseLocation(location_as_string);
    if (out->location == LOCATION_NONE) {
      return false;
    }
  }

  const base::Value* location_text_value = NULL;
  if (dict->GetWithoutPathExpansion("locationText", &location_text_value)) {
    {
      std::string temp;
      if (!location_text_value->GetAsString(&temp)) {
        out->location_text.reset();
        return false;
      }
      else
        out->location_text.reset(new std::string(temp));
    }
  }

  const base::Value* manifest_errors_value = NULL;
  if (!dict->GetWithoutPathExpansion("manifestErrors", &manifest_errors_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!manifest_errors_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->manifest_errors)) {
        return false;
      }
    }
  }

  const base::Value* manifest_home_page_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("manifestHomePageUrl", &manifest_home_page_url_value)) {
    return false;
  }
  {
    if (!manifest_home_page_url_value->GetAsString(&out->manifest_home_page_url)) {
      return false;
    }
  }

  const base::Value* must_remain_installed_value = NULL;
  if (!dict->GetWithoutPathExpansion("mustRemainInstalled", &must_remain_installed_value)) {
    return false;
  }
  {
    if (!must_remain_installed_value->GetAsBoolean(&out->must_remain_installed)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* offline_enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("offlineEnabled", &offline_enabled_value)) {
    return false;
  }
  {
    if (!offline_enabled_value->GetAsBoolean(&out->offline_enabled)) {
      return false;
    }
  }

  const base::Value* options_page_value = NULL;
  if (dict->GetWithoutPathExpansion("optionsPage", &options_page_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_page_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<OptionsPage> temp(new OptionsPage());
        if (!OptionsPage::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->options_page = std::move(temp);
      }
    }
  }

  const base::Value* path_value = NULL;
  if (dict->GetWithoutPathExpansion("path", &path_value)) {
    {
      std::string temp;
      if (!path_value->GetAsString(&temp)) {
        out->path.reset();
        return false;
      }
      else
        out->path.reset(new std::string(temp));
    }
  }

  const base::Value* permissions_value = NULL;
  if (!dict->GetWithoutPathExpansion("permissions", &permissions_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!permissions_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Permissions::Populate(*dictionary, &out->permissions)) {
      return false;
    }
  }

  const base::Value* prettified_path_value = NULL;
  if (dict->GetWithoutPathExpansion("prettifiedPath", &prettified_path_value)) {
    {
      std::string temp;
      if (!prettified_path_value->GetAsString(&temp)) {
        out->prettified_path.reset();
        return false;
      }
      else
        out->prettified_path.reset(new std::string(temp));
    }
  }

  const base::Value* runtime_errors_value = NULL;
  if (!dict->GetWithoutPathExpansion("runtimeErrors", &runtime_errors_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!runtime_errors_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->runtime_errors)) {
        return false;
      }
    }
  }

  const base::Value* runtime_warnings_value = NULL;
  if (!dict->GetWithoutPathExpansion("runtimeWarnings", &runtime_warnings_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!runtime_warnings_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->runtime_warnings)) {
        return false;
      }
    }
  }

  const base::Value* state_value = NULL;
  if (!dict->GetWithoutPathExpansion("state", &state_value)) {
    return false;
  }
  {
    std::string extension_state_as_string;
    if (!state_value->GetAsString(&extension_state_as_string)) {
      return false;
    }
    out->state = ParseExtensionState(extension_state_as_string);
    if (out->state == EXTENSION_STATE_NONE) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string extension_type_as_string;
    if (!type_value->GetAsString(&extension_type_as_string)) {
      return false;
    }
    out->type = ParseExtensionType(extension_type_as_string);
    if (out->type == EXTENSION_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* update_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("updateUrl", &update_url_value)) {
    return false;
  }
  {
    if (!update_url_value->GetAsString(&out->update_url)) {
      return false;
    }
  }

  const base::Value* user_may_modify_value = NULL;
  if (!dict->GetWithoutPathExpansion("userMayModify", &user_may_modify_value)) {
    return false;
  }
  {
    if (!user_may_modify_value->GetAsBoolean(&out->user_may_modify)) {
      return false;
    }
  }

  const base::Value* version_value = NULL;
  if (!dict->GetWithoutPathExpansion("version", &version_value)) {
    return false;
  }
  {
    if (!version_value->GetAsString(&out->version)) {
      return false;
    }
  }

  const base::Value* views_value = NULL;
  if (!dict->GetWithoutPathExpansion("views", &views_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!views_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->views)) {
        return false;
      }
    }
  }

  const base::Value* web_store_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("webStoreUrl", &web_store_url_value)) {
    return false;
  }
  {
    if (!web_store_url_value->GetAsString(&out->web_store_url)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ExtensionInfo> ExtensionInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ExtensionInfo> out(new ExtensionInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ExtensionInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->blacklist_text.get()) {
    to_value_result->SetWithoutPathExpansion("blacklistText", std::make_unique<base::Value>(*this->blacklist_text));

  }
  to_value_result->SetWithoutPathExpansion("commands", json_schema_compiler::util::CreateValueFromArray(this->commands));

  if (this->controlled_info.get()) {
    to_value_result->SetWithoutPathExpansion("controlledInfo", (this->controlled_info)->ToValue());

  }
  to_value_result->SetWithoutPathExpansion("dependentExtensions", json_schema_compiler::util::CreateValueFromArray(this->dependent_extensions));

  to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(this->description));

  to_value_result->SetWithoutPathExpansion("disableReasons", (this->disable_reasons).ToValue());

  to_value_result->SetWithoutPathExpansion("errorCollection", (this->error_collection).ToValue());

  to_value_result->SetWithoutPathExpansion("fileAccess", (this->file_access).ToValue());

  to_value_result->SetWithoutPathExpansion("homePage", (this->home_page).ToValue());

  to_value_result->SetWithoutPathExpansion("iconUrl", std::make_unique<base::Value>(this->icon_url));

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("incognitoAccess", (this->incognito_access).ToValue());

  to_value_result->SetWithoutPathExpansion("installWarnings", json_schema_compiler::util::CreateValueFromArray(this->install_warnings));

  if (this->launch_url.get()) {
    to_value_result->SetWithoutPathExpansion("launchUrl", std::make_unique<base::Value>(*this->launch_url));

  }
  to_value_result->SetWithoutPathExpansion("location", std::make_unique<base::Value>(developer_private::ToString(this->location)));

  if (this->location_text.get()) {
    to_value_result->SetWithoutPathExpansion("locationText", std::make_unique<base::Value>(*this->location_text));

  }
  to_value_result->SetWithoutPathExpansion("manifestErrors", json_schema_compiler::util::CreateValueFromArray(this->manifest_errors));

  to_value_result->SetWithoutPathExpansion("manifestHomePageUrl", std::make_unique<base::Value>(this->manifest_home_page_url));

  to_value_result->SetWithoutPathExpansion("mustRemainInstalled", std::make_unique<base::Value>(this->must_remain_installed));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("offlineEnabled", std::make_unique<base::Value>(this->offline_enabled));

  if (this->options_page.get()) {
    to_value_result->SetWithoutPathExpansion("optionsPage", (this->options_page)->ToValue());

  }
  if (this->path.get()) {
    to_value_result->SetWithoutPathExpansion("path", std::make_unique<base::Value>(*this->path));

  }
  to_value_result->SetWithoutPathExpansion("permissions", (this->permissions).ToValue());

  if (this->prettified_path.get()) {
    to_value_result->SetWithoutPathExpansion("prettifiedPath", std::make_unique<base::Value>(*this->prettified_path));

  }
  to_value_result->SetWithoutPathExpansion("runtimeErrors", json_schema_compiler::util::CreateValueFromArray(this->runtime_errors));

  to_value_result->SetWithoutPathExpansion("runtimeWarnings", json_schema_compiler::util::CreateValueFromArray(this->runtime_warnings));

  to_value_result->SetWithoutPathExpansion("state", std::make_unique<base::Value>(developer_private::ToString(this->state)));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(developer_private::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("updateUrl", std::make_unique<base::Value>(this->update_url));

  to_value_result->SetWithoutPathExpansion("userMayModify", std::make_unique<base::Value>(this->user_may_modify));

  to_value_result->SetWithoutPathExpansion("version", std::make_unique<base::Value>(this->version));

  to_value_result->SetWithoutPathExpansion("views", json_schema_compiler::util::CreateValueFromArray(this->views));

  to_value_result->SetWithoutPathExpansion("webStoreUrl", std::make_unique<base::Value>(this->web_store_url));


  return to_value_result;
}


ProfileInfo::ProfileInfo()
: can_load_unpacked(false),
in_developer_mode(false),
is_developer_mode_controlled_by_policy(false),
is_incognito_available(false),
is_supervised(false) {}

ProfileInfo::~ProfileInfo() {}
ProfileInfo::ProfileInfo(ProfileInfo&& rhs)
: can_load_unpacked(rhs.can_load_unpacked),
in_developer_mode(rhs.in_developer_mode),
is_developer_mode_controlled_by_policy(rhs.is_developer_mode_controlled_by_policy),
is_incognito_available(rhs.is_incognito_available),
is_supervised(rhs.is_supervised){
}

ProfileInfo& ProfileInfo::operator=(ProfileInfo&& rhs)
{
can_load_unpacked = rhs.can_load_unpacked;
in_developer_mode = rhs.in_developer_mode;
is_developer_mode_controlled_by_policy = rhs.is_developer_mode_controlled_by_policy;
is_incognito_available = rhs.is_incognito_available;
is_supervised = rhs.is_supervised;
return *this;
}

// static
bool ProfileInfo::Populate(
    const base::Value& value, ProfileInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* can_load_unpacked_value = NULL;
  if (!dict->GetWithoutPathExpansion("canLoadUnpacked", &can_load_unpacked_value)) {
    return false;
  }
  {
    if (!can_load_unpacked_value->GetAsBoolean(&out->can_load_unpacked)) {
      return false;
    }
  }

  const base::Value* in_developer_mode_value = NULL;
  if (!dict->GetWithoutPathExpansion("inDeveloperMode", &in_developer_mode_value)) {
    return false;
  }
  {
    if (!in_developer_mode_value->GetAsBoolean(&out->in_developer_mode)) {
      return false;
    }
  }

  const base::Value* is_developer_mode_controlled_by_policy_value = NULL;
  if (!dict->GetWithoutPathExpansion("isDeveloperModeControlledByPolicy", &is_developer_mode_controlled_by_policy_value)) {
    return false;
  }
  {
    if (!is_developer_mode_controlled_by_policy_value->GetAsBoolean(&out->is_developer_mode_controlled_by_policy)) {
      return false;
    }
  }

  const base::Value* is_incognito_available_value = NULL;
  if (!dict->GetWithoutPathExpansion("isIncognitoAvailable", &is_incognito_available_value)) {
    return false;
  }
  {
    if (!is_incognito_available_value->GetAsBoolean(&out->is_incognito_available)) {
      return false;
    }
  }

  const base::Value* is_supervised_value = NULL;
  if (!dict->GetWithoutPathExpansion("isSupervised", &is_supervised_value)) {
    return false;
  }
  {
    if (!is_supervised_value->GetAsBoolean(&out->is_supervised)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ProfileInfo> ProfileInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ProfileInfo> out(new ProfileInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ProfileInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("canLoadUnpacked", std::make_unique<base::Value>(this->can_load_unpacked));

  to_value_result->SetWithoutPathExpansion("inDeveloperMode", std::make_unique<base::Value>(this->in_developer_mode));

  to_value_result->SetWithoutPathExpansion("isDeveloperModeControlledByPolicy", std::make_unique<base::Value>(this->is_developer_mode_controlled_by_policy));

  to_value_result->SetWithoutPathExpansion("isIncognitoAvailable", std::make_unique<base::Value>(this->is_incognito_available));

  to_value_result->SetWithoutPathExpansion("isSupervised", std::make_unique<base::Value>(this->is_supervised));


  return to_value_result;
}


ItemInfo::ItemInfo()
: may_disable(false),
enabled(false),
is_app(false),
type(ITEM_TYPE_NONE),
allow_activity(false),
allow_file_access(false),
wants_file_access(false),
incognito_enabled(false),
is_unpacked(false),
allow_reload(false),
terminated(false),
allow_incognito(false),
offline_enabled(false) {}

ItemInfo::~ItemInfo() {}
ItemInfo::ItemInfo(ItemInfo&& rhs)
: id(std::move(rhs.id)),
name(std::move(rhs.name)),
version(std::move(rhs.version)),
description(std::move(rhs.description)),
may_disable(rhs.may_disable),
enabled(rhs.enabled),
is_app(rhs.is_app),
type(rhs.type),
allow_activity(rhs.allow_activity),
allow_file_access(rhs.allow_file_access),
wants_file_access(rhs.wants_file_access),
incognito_enabled(rhs.incognito_enabled),
is_unpacked(rhs.is_unpacked),
allow_reload(rhs.allow_reload),
terminated(rhs.terminated),
allow_incognito(rhs.allow_incognito),
icon_url(std::move(rhs.icon_url)),
path(std::move(rhs.path)),
options_url(std::move(rhs.options_url)),
app_launch_url(std::move(rhs.app_launch_url)),
homepage_url(std::move(rhs.homepage_url)),
update_url(std::move(rhs.update_url)),
install_warnings(std::move(rhs.install_warnings)),
manifest_errors(std::move(rhs.manifest_errors)),
runtime_errors(std::move(rhs.runtime_errors)),
offline_enabled(rhs.offline_enabled),
views(std::move(rhs.views)){
}

ItemInfo& ItemInfo::operator=(ItemInfo&& rhs)
{
id = std::move(rhs.id);
name = std::move(rhs.name);
version = std::move(rhs.version);
description = std::move(rhs.description);
may_disable = rhs.may_disable;
enabled = rhs.enabled;
is_app = rhs.is_app;
type = rhs.type;
allow_activity = rhs.allow_activity;
allow_file_access = rhs.allow_file_access;
wants_file_access = rhs.wants_file_access;
incognito_enabled = rhs.incognito_enabled;
is_unpacked = rhs.is_unpacked;
allow_reload = rhs.allow_reload;
terminated = rhs.terminated;
allow_incognito = rhs.allow_incognito;
icon_url = std::move(rhs.icon_url);
path = std::move(rhs.path);
options_url = std::move(rhs.options_url);
app_launch_url = std::move(rhs.app_launch_url);
homepage_url = std::move(rhs.homepage_url);
update_url = std::move(rhs.update_url);
install_warnings = std::move(rhs.install_warnings);
manifest_errors = std::move(rhs.manifest_errors);
runtime_errors = std::move(rhs.runtime_errors);
offline_enabled = rhs.offline_enabled;
views = std::move(rhs.views);
return *this;
}

// static
bool ItemInfo::Populate(
    const base::Value& value, ItemInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* version_value = NULL;
  if (!dict->GetWithoutPathExpansion("version", &version_value)) {
    return false;
  }
  {
    if (!version_value->GetAsString(&out->version)) {
      return false;
    }
  }

  const base::Value* description_value = NULL;
  if (!dict->GetWithoutPathExpansion("description", &description_value)) {
    return false;
  }
  {
    if (!description_value->GetAsString(&out->description)) {
      return false;
    }
  }

  const base::Value* may_disable_value = NULL;
  if (!dict->GetWithoutPathExpansion("may_disable", &may_disable_value)) {
    return false;
  }
  {
    if (!may_disable_value->GetAsBoolean(&out->may_disable)) {
      return false;
    }
  }

  const base::Value* enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("enabled", &enabled_value)) {
    return false;
  }
  {
    if (!enabled_value->GetAsBoolean(&out->enabled)) {
      return false;
    }
  }

  const base::Value* is_app_value = NULL;
  if (!dict->GetWithoutPathExpansion("isApp", &is_app_value)) {
    return false;
  }
  {
    if (!is_app_value->GetAsBoolean(&out->is_app)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string item_type_as_string;
    if (!type_value->GetAsString(&item_type_as_string)) {
      return false;
    }
    out->type = ParseItemType(item_type_as_string);
    if (out->type == ITEM_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* allow_activity_value = NULL;
  if (!dict->GetWithoutPathExpansion("allow_activity", &allow_activity_value)) {
    return false;
  }
  {
    if (!allow_activity_value->GetAsBoolean(&out->allow_activity)) {
      return false;
    }
  }

  const base::Value* allow_file_access_value = NULL;
  if (!dict->GetWithoutPathExpansion("allow_file_access", &allow_file_access_value)) {
    return false;
  }
  {
    if (!allow_file_access_value->GetAsBoolean(&out->allow_file_access)) {
      return false;
    }
  }

  const base::Value* wants_file_access_value = NULL;
  if (!dict->GetWithoutPathExpansion("wants_file_access", &wants_file_access_value)) {
    return false;
  }
  {
    if (!wants_file_access_value->GetAsBoolean(&out->wants_file_access)) {
      return false;
    }
  }

  const base::Value* incognito_enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("incognito_enabled", &incognito_enabled_value)) {
    return false;
  }
  {
    if (!incognito_enabled_value->GetAsBoolean(&out->incognito_enabled)) {
      return false;
    }
  }

  const base::Value* is_unpacked_value = NULL;
  if (!dict->GetWithoutPathExpansion("is_unpacked", &is_unpacked_value)) {
    return false;
  }
  {
    if (!is_unpacked_value->GetAsBoolean(&out->is_unpacked)) {
      return false;
    }
  }

  const base::Value* allow_reload_value = NULL;
  if (!dict->GetWithoutPathExpansion("allow_reload", &allow_reload_value)) {
    return false;
  }
  {
    if (!allow_reload_value->GetAsBoolean(&out->allow_reload)) {
      return false;
    }
  }

  const base::Value* terminated_value = NULL;
  if (!dict->GetWithoutPathExpansion("terminated", &terminated_value)) {
    return false;
  }
  {
    if (!terminated_value->GetAsBoolean(&out->terminated)) {
      return false;
    }
  }

  const base::Value* allow_incognito_value = NULL;
  if (!dict->GetWithoutPathExpansion("allow_incognito", &allow_incognito_value)) {
    return false;
  }
  {
    if (!allow_incognito_value->GetAsBoolean(&out->allow_incognito)) {
      return false;
    }
  }

  const base::Value* icon_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("icon_url", &icon_url_value)) {
    return false;
  }
  {
    if (!icon_url_value->GetAsString(&out->icon_url)) {
      return false;
    }
  }

  const base::Value* path_value = NULL;
  if (dict->GetWithoutPathExpansion("path", &path_value)) {
    {
      std::string temp;
      if (!path_value->GetAsString(&temp)) {
        out->path.reset();
        return false;
      }
      else
        out->path.reset(new std::string(temp));
    }
  }

  const base::Value* options_url_value = NULL;
  if (dict->GetWithoutPathExpansion("options_url", &options_url_value)) {
    {
      std::string temp;
      if (!options_url_value->GetAsString(&temp)) {
        out->options_url.reset();
        return false;
      }
      else
        out->options_url.reset(new std::string(temp));
    }
  }

  const base::Value* app_launch_url_value = NULL;
  if (dict->GetWithoutPathExpansion("app_launch_url", &app_launch_url_value)) {
    {
      std::string temp;
      if (!app_launch_url_value->GetAsString(&temp)) {
        out->app_launch_url.reset();
        return false;
      }
      else
        out->app_launch_url.reset(new std::string(temp));
    }
  }

  const base::Value* homepage_url_value = NULL;
  if (dict->GetWithoutPathExpansion("homepage_url", &homepage_url_value)) {
    {
      std::string temp;
      if (!homepage_url_value->GetAsString(&temp)) {
        out->homepage_url.reset();
        return false;
      }
      else
        out->homepage_url.reset(new std::string(temp));
    }
  }

  const base::Value* update_url_value = NULL;
  if (dict->GetWithoutPathExpansion("update_url", &update_url_value)) {
    {
      std::string temp;
      if (!update_url_value->GetAsString(&temp)) {
        out->update_url.reset();
        return false;
      }
      else
        out->update_url.reset(new std::string(temp));
    }
  }

  const base::Value* install_warnings_value = NULL;
  if (!dict->GetWithoutPathExpansion("install_warnings", &install_warnings_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!install_warnings_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->install_warnings)) {
        return false;
      }
    }
  }

  const base::Value* manifest_errors_value = NULL;
  if (!dict->GetWithoutPathExpansion("manifest_errors", &manifest_errors_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!manifest_errors_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->manifest_errors)) {
        return false;
      }
    }
  }

  const base::Value* runtime_errors_value = NULL;
  if (!dict->GetWithoutPathExpansion("runtime_errors", &runtime_errors_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!runtime_errors_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->runtime_errors)) {
        return false;
      }
    }
  }

  const base::Value* offline_enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("offline_enabled", &offline_enabled_value)) {
    return false;
  }
  {
    if (!offline_enabled_value->GetAsBoolean(&out->offline_enabled)) {
      return false;
    }
  }

  const base::Value* views_value = NULL;
  if (!dict->GetWithoutPathExpansion("views", &views_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!views_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->views)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ItemInfo> ItemInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ItemInfo> out(new ItemInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ItemInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("version", std::make_unique<base::Value>(this->version));

  to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(this->description));

  to_value_result->SetWithoutPathExpansion("may_disable", std::make_unique<base::Value>(this->may_disable));

  to_value_result->SetWithoutPathExpansion("enabled", std::make_unique<base::Value>(this->enabled));

  to_value_result->SetWithoutPathExpansion("isApp", std::make_unique<base::Value>(this->is_app));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(developer_private::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("allow_activity", std::make_unique<base::Value>(this->allow_activity));

  to_value_result->SetWithoutPathExpansion("allow_file_access", std::make_unique<base::Value>(this->allow_file_access));

  to_value_result->SetWithoutPathExpansion("wants_file_access", std::make_unique<base::Value>(this->wants_file_access));

  to_value_result->SetWithoutPathExpansion("incognito_enabled", std::make_unique<base::Value>(this->incognito_enabled));

  to_value_result->SetWithoutPathExpansion("is_unpacked", std::make_unique<base::Value>(this->is_unpacked));

  to_value_result->SetWithoutPathExpansion("allow_reload", std::make_unique<base::Value>(this->allow_reload));

  to_value_result->SetWithoutPathExpansion("terminated", std::make_unique<base::Value>(this->terminated));

  to_value_result->SetWithoutPathExpansion("allow_incognito", std::make_unique<base::Value>(this->allow_incognito));

  to_value_result->SetWithoutPathExpansion("icon_url", std::make_unique<base::Value>(this->icon_url));

  if (this->path.get()) {
    to_value_result->SetWithoutPathExpansion("path", std::make_unique<base::Value>(*this->path));

  }
  if (this->options_url.get()) {
    to_value_result->SetWithoutPathExpansion("options_url", std::make_unique<base::Value>(*this->options_url));

  }
  if (this->app_launch_url.get()) {
    to_value_result->SetWithoutPathExpansion("app_launch_url", std::make_unique<base::Value>(*this->app_launch_url));

  }
  if (this->homepage_url.get()) {
    to_value_result->SetWithoutPathExpansion("homepage_url", std::make_unique<base::Value>(*this->homepage_url));

  }
  if (this->update_url.get()) {
    to_value_result->SetWithoutPathExpansion("update_url", std::make_unique<base::Value>(*this->update_url));

  }
  to_value_result->SetWithoutPathExpansion("install_warnings", json_schema_compiler::util::CreateValueFromArray(this->install_warnings));

  to_value_result->SetWithoutPathExpansion("manifest_errors", json_schema_compiler::util::CreateValueFromArray(this->manifest_errors));

  to_value_result->SetWithoutPathExpansion("runtime_errors", json_schema_compiler::util::CreateValueFromArray(this->runtime_errors));

  to_value_result->SetWithoutPathExpansion("offline_enabled", std::make_unique<base::Value>(this->offline_enabled));

  to_value_result->SetWithoutPathExpansion("views", json_schema_compiler::util::CreateValueFromArray(this->views));


  return to_value_result;
}


GetExtensionsInfoOptions::GetExtensionsInfoOptions()
 {}

GetExtensionsInfoOptions::~GetExtensionsInfoOptions() {}
GetExtensionsInfoOptions::GetExtensionsInfoOptions(GetExtensionsInfoOptions&& rhs)
: include_disabled(std::move(rhs.include_disabled)),
include_terminated(std::move(rhs.include_terminated)){
}

GetExtensionsInfoOptions& GetExtensionsInfoOptions::operator=(GetExtensionsInfoOptions&& rhs)
{
include_disabled = std::move(rhs.include_disabled);
include_terminated = std::move(rhs.include_terminated);
return *this;
}

// static
bool GetExtensionsInfoOptions::Populate(
    const base::Value& value, GetExtensionsInfoOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* include_disabled_value = NULL;
  if (dict->GetWithoutPathExpansion("includeDisabled", &include_disabled_value)) {
    {
      bool temp;
      if (!include_disabled_value->GetAsBoolean(&temp)) {
        out->include_disabled.reset();
        return false;
      }
      else
        out->include_disabled.reset(new bool(temp));
    }
  }

  const base::Value* include_terminated_value = NULL;
  if (dict->GetWithoutPathExpansion("includeTerminated", &include_terminated_value)) {
    {
      bool temp;
      if (!include_terminated_value->GetAsBoolean(&temp)) {
        out->include_terminated.reset();
        return false;
      }
      else
        out->include_terminated.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<GetExtensionsInfoOptions> GetExtensionsInfoOptions::FromValue(const base::Value& value) {
  std::unique_ptr<GetExtensionsInfoOptions> out(new GetExtensionsInfoOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> GetExtensionsInfoOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->include_disabled.get()) {
    to_value_result->SetWithoutPathExpansion("includeDisabled", std::make_unique<base::Value>(*this->include_disabled));

  }
  if (this->include_terminated.get()) {
    to_value_result->SetWithoutPathExpansion("includeTerminated", std::make_unique<base::Value>(*this->include_terminated));

  }

  return to_value_result;
}


ExtensionConfigurationUpdate::ExtensionConfigurationUpdate()
: host_access(HOST_ACCESS_NONE) {}

ExtensionConfigurationUpdate::~ExtensionConfigurationUpdate() {}
ExtensionConfigurationUpdate::ExtensionConfigurationUpdate(ExtensionConfigurationUpdate&& rhs)
: extension_id(std::move(rhs.extension_id)),
file_access(std::move(rhs.file_access)),
incognito_access(std::move(rhs.incognito_access)),
error_collection(std::move(rhs.error_collection)),
host_access(rhs.host_access){
}

ExtensionConfigurationUpdate& ExtensionConfigurationUpdate::operator=(ExtensionConfigurationUpdate&& rhs)
{
extension_id = std::move(rhs.extension_id);
file_access = std::move(rhs.file_access);
incognito_access = std::move(rhs.incognito_access);
error_collection = std::move(rhs.error_collection);
host_access = rhs.host_access;
return *this;
}

// static
bool ExtensionConfigurationUpdate::Populate(
    const base::Value& value, ExtensionConfigurationUpdate* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->host_access = HOST_ACCESS_NONE;
  const base::Value* extension_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    return false;
  }
  {
    if (!extension_id_value->GetAsString(&out->extension_id)) {
      return false;
    }
  }

  const base::Value* file_access_value = NULL;
  if (dict->GetWithoutPathExpansion("fileAccess", &file_access_value)) {
    {
      bool temp;
      if (!file_access_value->GetAsBoolean(&temp)) {
        out->file_access.reset();
        return false;
      }
      else
        out->file_access.reset(new bool(temp));
    }
  }

  const base::Value* incognito_access_value = NULL;
  if (dict->GetWithoutPathExpansion("incognitoAccess", &incognito_access_value)) {
    {
      bool temp;
      if (!incognito_access_value->GetAsBoolean(&temp)) {
        out->incognito_access.reset();
        return false;
      }
      else
        out->incognito_access.reset(new bool(temp));
    }
  }

  const base::Value* error_collection_value = NULL;
  if (dict->GetWithoutPathExpansion("errorCollection", &error_collection_value)) {
    {
      bool temp;
      if (!error_collection_value->GetAsBoolean(&temp)) {
        out->error_collection.reset();
        return false;
      }
      else
        out->error_collection.reset(new bool(temp));
    }
  }

  const base::Value* host_access_value = NULL;
  if (dict->GetWithoutPathExpansion("hostAccess", &host_access_value)) {
    {
      std::string host_access_as_string;
      if (!host_access_value->GetAsString(&host_access_as_string)) {
        return false;
      }
      out->host_access = ParseHostAccess(host_access_as_string);
      if (out->host_access == HOST_ACCESS_NONE) {
        return false;
      }
    }
    } else {
    out->host_access = HOST_ACCESS_NONE;
  }

  return true;
}

// static
std::unique_ptr<ExtensionConfigurationUpdate> ExtensionConfigurationUpdate::FromValue(const base::Value& value) {
  std::unique_ptr<ExtensionConfigurationUpdate> out(new ExtensionConfigurationUpdate());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ExtensionConfigurationUpdate::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(this->extension_id));

  if (this->file_access.get()) {
    to_value_result->SetWithoutPathExpansion("fileAccess", std::make_unique<base::Value>(*this->file_access));

  }
  if (this->incognito_access.get()) {
    to_value_result->SetWithoutPathExpansion("incognitoAccess", std::make_unique<base::Value>(*this->incognito_access));

  }
  if (this->error_collection.get()) {
    to_value_result->SetWithoutPathExpansion("errorCollection", std::make_unique<base::Value>(*this->error_collection));

  }
  if (this->host_access != HOST_ACCESS_NONE) {
    to_value_result->SetWithoutPathExpansion("hostAccess", std::make_unique<base::Value>(developer_private::ToString(this->host_access)));

  }

  return to_value_result;
}


ProfileConfigurationUpdate::ProfileConfigurationUpdate()
 {}

ProfileConfigurationUpdate::~ProfileConfigurationUpdate() {}
ProfileConfigurationUpdate::ProfileConfigurationUpdate(ProfileConfigurationUpdate&& rhs)
: in_developer_mode(std::move(rhs.in_developer_mode)){
}

ProfileConfigurationUpdate& ProfileConfigurationUpdate::operator=(ProfileConfigurationUpdate&& rhs)
{
in_developer_mode = std::move(rhs.in_developer_mode);
return *this;
}

// static
bool ProfileConfigurationUpdate::Populate(
    const base::Value& value, ProfileConfigurationUpdate* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* in_developer_mode_value = NULL;
  if (dict->GetWithoutPathExpansion("inDeveloperMode", &in_developer_mode_value)) {
    {
      bool temp;
      if (!in_developer_mode_value->GetAsBoolean(&temp)) {
        out->in_developer_mode.reset();
        return false;
      }
      else
        out->in_developer_mode.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ProfileConfigurationUpdate> ProfileConfigurationUpdate::FromValue(const base::Value& value) {
  std::unique_ptr<ProfileConfigurationUpdate> out(new ProfileConfigurationUpdate());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ProfileConfigurationUpdate::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->in_developer_mode.get()) {
    to_value_result->SetWithoutPathExpansion("inDeveloperMode", std::make_unique<base::Value>(*this->in_developer_mode));

  }

  return to_value_result;
}


ExtensionCommandUpdate::ExtensionCommandUpdate()
: scope(COMMAND_SCOPE_NONE) {}

ExtensionCommandUpdate::~ExtensionCommandUpdate() {}
ExtensionCommandUpdate::ExtensionCommandUpdate(ExtensionCommandUpdate&& rhs)
: extension_id(std::move(rhs.extension_id)),
command_name(std::move(rhs.command_name)),
scope(rhs.scope),
keybinding(std::move(rhs.keybinding)){
}

ExtensionCommandUpdate& ExtensionCommandUpdate::operator=(ExtensionCommandUpdate&& rhs)
{
extension_id = std::move(rhs.extension_id);
command_name = std::move(rhs.command_name);
scope = rhs.scope;
keybinding = std::move(rhs.keybinding);
return *this;
}

// static
bool ExtensionCommandUpdate::Populate(
    const base::Value& value, ExtensionCommandUpdate* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->scope = COMMAND_SCOPE_NONE;
  const base::Value* extension_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    return false;
  }
  {
    if (!extension_id_value->GetAsString(&out->extension_id)) {
      return false;
    }
  }

  const base::Value* command_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("commandName", &command_name_value)) {
    return false;
  }
  {
    if (!command_name_value->GetAsString(&out->command_name)) {
      return false;
    }
  }

  const base::Value* scope_value = NULL;
  if (dict->GetWithoutPathExpansion("scope", &scope_value)) {
    {
      std::string command_scope_as_string;
      if (!scope_value->GetAsString(&command_scope_as_string)) {
        return false;
      }
      out->scope = ParseCommandScope(command_scope_as_string);
      if (out->scope == COMMAND_SCOPE_NONE) {
        return false;
      }
    }
    } else {
    out->scope = COMMAND_SCOPE_NONE;
  }

  const base::Value* keybinding_value = NULL;
  if (dict->GetWithoutPathExpansion("keybinding", &keybinding_value)) {
    {
      std::string temp;
      if (!keybinding_value->GetAsString(&temp)) {
        out->keybinding.reset();
        return false;
      }
      else
        out->keybinding.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ExtensionCommandUpdate> ExtensionCommandUpdate::FromValue(const base::Value& value) {
  std::unique_ptr<ExtensionCommandUpdate> out(new ExtensionCommandUpdate());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ExtensionCommandUpdate::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(this->extension_id));

  to_value_result->SetWithoutPathExpansion("commandName", std::make_unique<base::Value>(this->command_name));

  if (this->scope != COMMAND_SCOPE_NONE) {
    to_value_result->SetWithoutPathExpansion("scope", std::make_unique<base::Value>(developer_private::ToString(this->scope)));

  }
  if (this->keybinding.get()) {
    to_value_result->SetWithoutPathExpansion("keybinding", std::make_unique<base::Value>(*this->keybinding));

  }

  return to_value_result;
}


ReloadOptions::ReloadOptions()
 {}

ReloadOptions::~ReloadOptions() {}
ReloadOptions::ReloadOptions(ReloadOptions&& rhs)
: fail_quietly(std::move(rhs.fail_quietly)),
populate_error_for_unpacked(std::move(rhs.populate_error_for_unpacked)){
}

ReloadOptions& ReloadOptions::operator=(ReloadOptions&& rhs)
{
fail_quietly = std::move(rhs.fail_quietly);
populate_error_for_unpacked = std::move(rhs.populate_error_for_unpacked);
return *this;
}

// static
bool ReloadOptions::Populate(
    const base::Value& value, ReloadOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* fail_quietly_value = NULL;
  if (dict->GetWithoutPathExpansion("failQuietly", &fail_quietly_value)) {
    {
      bool temp;
      if (!fail_quietly_value->GetAsBoolean(&temp)) {
        out->fail_quietly.reset();
        return false;
      }
      else
        out->fail_quietly.reset(new bool(temp));
    }
  }

  const base::Value* populate_error_for_unpacked_value = NULL;
  if (dict->GetWithoutPathExpansion("populateErrorForUnpacked", &populate_error_for_unpacked_value)) {
    {
      bool temp;
      if (!populate_error_for_unpacked_value->GetAsBoolean(&temp)) {
        out->populate_error_for_unpacked.reset();
        return false;
      }
      else
        out->populate_error_for_unpacked.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ReloadOptions> ReloadOptions::FromValue(const base::Value& value) {
  std::unique_ptr<ReloadOptions> out(new ReloadOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ReloadOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->fail_quietly.get()) {
    to_value_result->SetWithoutPathExpansion("failQuietly", std::make_unique<base::Value>(*this->fail_quietly));

  }
  if (this->populate_error_for_unpacked.get()) {
    to_value_result->SetWithoutPathExpansion("populateErrorForUnpacked", std::make_unique<base::Value>(*this->populate_error_for_unpacked));

  }

  return to_value_result;
}


LoadUnpackedOptions::LoadUnpackedOptions()
 {}

LoadUnpackedOptions::~LoadUnpackedOptions() {}
LoadUnpackedOptions::LoadUnpackedOptions(LoadUnpackedOptions&& rhs)
: fail_quietly(std::move(rhs.fail_quietly)),
populate_error(std::move(rhs.populate_error)),
retry_guid(std::move(rhs.retry_guid)),
use_dragged_path(std::move(rhs.use_dragged_path)){
}

LoadUnpackedOptions& LoadUnpackedOptions::operator=(LoadUnpackedOptions&& rhs)
{
fail_quietly = std::move(rhs.fail_quietly);
populate_error = std::move(rhs.populate_error);
retry_guid = std::move(rhs.retry_guid);
use_dragged_path = std::move(rhs.use_dragged_path);
return *this;
}

// static
bool LoadUnpackedOptions::Populate(
    const base::Value& value, LoadUnpackedOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* fail_quietly_value = NULL;
  if (dict->GetWithoutPathExpansion("failQuietly", &fail_quietly_value)) {
    {
      bool temp;
      if (!fail_quietly_value->GetAsBoolean(&temp)) {
        out->fail_quietly.reset();
        return false;
      }
      else
        out->fail_quietly.reset(new bool(temp));
    }
  }

  const base::Value* populate_error_value = NULL;
  if (dict->GetWithoutPathExpansion("populateError", &populate_error_value)) {
    {
      bool temp;
      if (!populate_error_value->GetAsBoolean(&temp)) {
        out->populate_error.reset();
        return false;
      }
      else
        out->populate_error.reset(new bool(temp));
    }
  }

  const base::Value* retry_guid_value = NULL;
  if (dict->GetWithoutPathExpansion("retryGuid", &retry_guid_value)) {
    {
      std::string temp;
      if (!retry_guid_value->GetAsString(&temp)) {
        out->retry_guid.reset();
        return false;
      }
      else
        out->retry_guid.reset(new std::string(temp));
    }
  }

  const base::Value* use_dragged_path_value = NULL;
  if (dict->GetWithoutPathExpansion("useDraggedPath", &use_dragged_path_value)) {
    {
      bool temp;
      if (!use_dragged_path_value->GetAsBoolean(&temp)) {
        out->use_dragged_path.reset();
        return false;
      }
      else
        out->use_dragged_path.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<LoadUnpackedOptions> LoadUnpackedOptions::FromValue(const base::Value& value) {
  std::unique_ptr<LoadUnpackedOptions> out(new LoadUnpackedOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> LoadUnpackedOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->fail_quietly.get()) {
    to_value_result->SetWithoutPathExpansion("failQuietly", std::make_unique<base::Value>(*this->fail_quietly));

  }
  if (this->populate_error.get()) {
    to_value_result->SetWithoutPathExpansion("populateError", std::make_unique<base::Value>(*this->populate_error));

  }
  if (this->retry_guid.get()) {
    to_value_result->SetWithoutPathExpansion("retryGuid", std::make_unique<base::Value>(*this->retry_guid));

  }
  if (this->use_dragged_path.get()) {
    to_value_result->SetWithoutPathExpansion("useDraggedPath", std::make_unique<base::Value>(*this->use_dragged_path));

  }

  return to_value_result;
}


const char* ToString(PackStatus enum_param) {
  switch (enum_param) {
    case PACK_STATUS_SUCCESS:
      return "SUCCESS";
    case PACK_STATUS_ERROR:
      return "ERROR";
    case PACK_STATUS_WARNING:
      return "WARNING";
    case PACK_STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PackStatus ParsePackStatus(const std::string& enum_string) {
  if (enum_string == "SUCCESS")
    return PACK_STATUS_SUCCESS;
  if (enum_string == "ERROR")
    return PACK_STATUS_ERROR;
  if (enum_string == "WARNING")
    return PACK_STATUS_WARNING;
  return PACK_STATUS_NONE;
}


const char* ToString(FileType enum_param) {
  switch (enum_param) {
    case FILE_TYPE_LOAD:
      return "LOAD";
    case FILE_TYPE_PEM:
      return "PEM";
    case FILE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

FileType ParseFileType(const std::string& enum_string) {
  if (enum_string == "LOAD")
    return FILE_TYPE_LOAD;
  if (enum_string == "PEM")
    return FILE_TYPE_PEM;
  return FILE_TYPE_NONE;
}


const char* ToString(SelectType enum_param) {
  switch (enum_param) {
    case SELECT_TYPE_FILE:
      return "FILE";
    case SELECT_TYPE_FOLDER:
      return "FOLDER";
    case SELECT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SelectType ParseSelectType(const std::string& enum_string) {
  if (enum_string == "FILE")
    return SELECT_TYPE_FILE;
  if (enum_string == "FOLDER")
    return SELECT_TYPE_FOLDER;
  return SELECT_TYPE_NONE;
}


const char* ToString(EventType enum_param) {
  switch (enum_param) {
    case EVENT_TYPE_INSTALLED:
      return "INSTALLED";
    case EVENT_TYPE_UNINSTALLED:
      return "UNINSTALLED";
    case EVENT_TYPE_LOADED:
      return "LOADED";
    case EVENT_TYPE_UNLOADED:
      return "UNLOADED";
    case EVENT_TYPE_VIEW_REGISTERED:
      return "VIEW_REGISTERED";
    case EVENT_TYPE_VIEW_UNREGISTERED:
      return "VIEW_UNREGISTERED";
    case EVENT_TYPE_ERROR_ADDED:
      return "ERROR_ADDED";
    case EVENT_TYPE_ERRORS_REMOVED:
      return "ERRORS_REMOVED";
    case EVENT_TYPE_PREFS_CHANGED:
      return "PREFS_CHANGED";
    case EVENT_TYPE_WARNINGS_CHANGED:
      return "WARNINGS_CHANGED";
    case EVENT_TYPE_COMMAND_ADDED:
      return "COMMAND_ADDED";
    case EVENT_TYPE_COMMAND_REMOVED:
      return "COMMAND_REMOVED";
    case EVENT_TYPE_PERMISSIONS_CHANGED:
      return "PERMISSIONS_CHANGED";
    case EVENT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

EventType ParseEventType(const std::string& enum_string) {
  if (enum_string == "INSTALLED")
    return EVENT_TYPE_INSTALLED;
  if (enum_string == "UNINSTALLED")
    return EVENT_TYPE_UNINSTALLED;
  if (enum_string == "LOADED")
    return EVENT_TYPE_LOADED;
  if (enum_string == "UNLOADED")
    return EVENT_TYPE_UNLOADED;
  if (enum_string == "VIEW_REGISTERED")
    return EVENT_TYPE_VIEW_REGISTERED;
  if (enum_string == "VIEW_UNREGISTERED")
    return EVENT_TYPE_VIEW_UNREGISTERED;
  if (enum_string == "ERROR_ADDED")
    return EVENT_TYPE_ERROR_ADDED;
  if (enum_string == "ERRORS_REMOVED")
    return EVENT_TYPE_ERRORS_REMOVED;
  if (enum_string == "PREFS_CHANGED")
    return EVENT_TYPE_PREFS_CHANGED;
  if (enum_string == "WARNINGS_CHANGED")
    return EVENT_TYPE_WARNINGS_CHANGED;
  if (enum_string == "COMMAND_ADDED")
    return EVENT_TYPE_COMMAND_ADDED;
  if (enum_string == "COMMAND_REMOVED")
    return EVENT_TYPE_COMMAND_REMOVED;
  if (enum_string == "PERMISSIONS_CHANGED")
    return EVENT_TYPE_PERMISSIONS_CHANGED;
  return EVENT_TYPE_NONE;
}


PackDirectoryResponse::PackDirectoryResponse()
: override_flags(0),
status(PACK_STATUS_NONE) {}

PackDirectoryResponse::~PackDirectoryResponse() {}
PackDirectoryResponse::PackDirectoryResponse(PackDirectoryResponse&& rhs)
: message(std::move(rhs.message)),
item_path(std::move(rhs.item_path)),
pem_path(std::move(rhs.pem_path)),
override_flags(rhs.override_flags),
status(rhs.status){
}

PackDirectoryResponse& PackDirectoryResponse::operator=(PackDirectoryResponse&& rhs)
{
message = std::move(rhs.message);
item_path = std::move(rhs.item_path);
pem_path = std::move(rhs.pem_path);
override_flags = rhs.override_flags;
status = rhs.status;
return *this;
}

// static
bool PackDirectoryResponse::Populate(
    const base::Value& value, PackDirectoryResponse* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* message_value = NULL;
  if (!dict->GetWithoutPathExpansion("message", &message_value)) {
    return false;
  }
  {
    if (!message_value->GetAsString(&out->message)) {
      return false;
    }
  }

  const base::Value* item_path_value = NULL;
  if (!dict->GetWithoutPathExpansion("item_path", &item_path_value)) {
    return false;
  }
  {
    if (!item_path_value->GetAsString(&out->item_path)) {
      return false;
    }
  }

  const base::Value* pem_path_value = NULL;
  if (!dict->GetWithoutPathExpansion("pem_path", &pem_path_value)) {
    return false;
  }
  {
    if (!pem_path_value->GetAsString(&out->pem_path)) {
      return false;
    }
  }

  const base::Value* override_flags_value = NULL;
  if (!dict->GetWithoutPathExpansion("override_flags", &override_flags_value)) {
    return false;
  }
  {
    if (!override_flags_value->GetAsInteger(&out->override_flags)) {
      return false;
    }
  }

  const base::Value* status_value = NULL;
  if (!dict->GetWithoutPathExpansion("status", &status_value)) {
    return false;
  }
  {
    std::string pack_status_as_string;
    if (!status_value->GetAsString(&pack_status_as_string)) {
      return false;
    }
    out->status = ParsePackStatus(pack_status_as_string);
    if (out->status == PACK_STATUS_NONE) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<PackDirectoryResponse> PackDirectoryResponse::FromValue(const base::Value& value) {
  std::unique_ptr<PackDirectoryResponse> out(new PackDirectoryResponse());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PackDirectoryResponse::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("message", std::make_unique<base::Value>(this->message));

  to_value_result->SetWithoutPathExpansion("item_path", std::make_unique<base::Value>(this->item_path));

  to_value_result->SetWithoutPathExpansion("pem_path", std::make_unique<base::Value>(this->pem_path));

  to_value_result->SetWithoutPathExpansion("override_flags", std::make_unique<base::Value>(this->override_flags));

  to_value_result->SetWithoutPathExpansion("status", std::make_unique<base::Value>(developer_private::ToString(this->status)));


  return to_value_result;
}


ProjectInfo::ProjectInfo()
 {}

ProjectInfo::~ProjectInfo() {}
ProjectInfo::ProjectInfo(ProjectInfo&& rhs)
: name(std::move(rhs.name)){
}

ProjectInfo& ProjectInfo::operator=(ProjectInfo&& rhs)
{
name = std::move(rhs.name);
return *this;
}

// static
bool ProjectInfo::Populate(
    const base::Value& value, ProjectInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ProjectInfo> ProjectInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ProjectInfo> out(new ProjectInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ProjectInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));


  return to_value_result;
}


EventData::EventData()
: event_type(EVENT_TYPE_NONE) {}

EventData::~EventData() {}
EventData::EventData(EventData&& rhs)
: event_type(rhs.event_type),
item_id(std::move(rhs.item_id)),
extension_info(std::move(rhs.extension_info)){
}

EventData& EventData::operator=(EventData&& rhs)
{
event_type = rhs.event_type;
item_id = std::move(rhs.item_id);
extension_info = std::move(rhs.extension_info);
return *this;
}

// static
bool EventData::Populate(
    const base::Value& value, EventData* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* event_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("event_type", &event_type_value)) {
    return false;
  }
  {
    std::string event_type_as_string;
    if (!event_type_value->GetAsString(&event_type_as_string)) {
      return false;
    }
    out->event_type = ParseEventType(event_type_as_string);
    if (out->event_type == EVENT_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* item_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("item_id", &item_id_value)) {
    return false;
  }
  {
    if (!item_id_value->GetAsString(&out->item_id)) {
      return false;
    }
  }

  const base::Value* extension_info_value = NULL;
  if (dict->GetWithoutPathExpansion("extensionInfo", &extension_info_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!extension_info_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ExtensionInfo> temp(new ExtensionInfo());
        if (!ExtensionInfo::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->extension_info = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<EventData> EventData::FromValue(const base::Value& value) {
  std::unique_ptr<EventData> out(new EventData());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> EventData::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("event_type", std::make_unique<base::Value>(developer_private::ToString(this->event_type)));

  to_value_result->SetWithoutPathExpansion("item_id", std::make_unique<base::Value>(this->item_id));

  if (this->extension_info.get()) {
    to_value_result->SetWithoutPathExpansion("extensionInfo", (this->extension_info)->ToValue());

  }

  return to_value_result;
}


ErrorFileSource::ErrorFileSource()
 {}

ErrorFileSource::~ErrorFileSource() {}
ErrorFileSource::ErrorFileSource(ErrorFileSource&& rhs)
: before_highlight(std::move(rhs.before_highlight)),
highlight(std::move(rhs.highlight)),
after_highlight(std::move(rhs.after_highlight)){
}

ErrorFileSource& ErrorFileSource::operator=(ErrorFileSource&& rhs)
{
before_highlight = std::move(rhs.before_highlight);
highlight = std::move(rhs.highlight);
after_highlight = std::move(rhs.after_highlight);
return *this;
}

// static
bool ErrorFileSource::Populate(
    const base::Value& value, ErrorFileSource* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* before_highlight_value = NULL;
  if (!dict->GetWithoutPathExpansion("beforeHighlight", &before_highlight_value)) {
    return false;
  }
  {
    if (!before_highlight_value->GetAsString(&out->before_highlight)) {
      return false;
    }
  }

  const base::Value* highlight_value = NULL;
  if (!dict->GetWithoutPathExpansion("highlight", &highlight_value)) {
    return false;
  }
  {
    if (!highlight_value->GetAsString(&out->highlight)) {
      return false;
    }
  }

  const base::Value* after_highlight_value = NULL;
  if (!dict->GetWithoutPathExpansion("afterHighlight", &after_highlight_value)) {
    return false;
  }
  {
    if (!after_highlight_value->GetAsString(&out->after_highlight)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ErrorFileSource> ErrorFileSource::FromValue(const base::Value& value) {
  std::unique_ptr<ErrorFileSource> out(new ErrorFileSource());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ErrorFileSource::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("beforeHighlight", std::make_unique<base::Value>(this->before_highlight));

  to_value_result->SetWithoutPathExpansion("highlight", std::make_unique<base::Value>(this->highlight));

  to_value_result->SetWithoutPathExpansion("afterHighlight", std::make_unique<base::Value>(this->after_highlight));


  return to_value_result;
}


LoadError::LoadError()
 {}

LoadError::~LoadError() {}
LoadError::LoadError(LoadError&& rhs)
: error(std::move(rhs.error)),
path(std::move(rhs.path)),
source(std::move(rhs.source)),
retry_guid(std::move(rhs.retry_guid)){
}

LoadError& LoadError::operator=(LoadError&& rhs)
{
error = std::move(rhs.error);
path = std::move(rhs.path);
source = std::move(rhs.source);
retry_guid = std::move(rhs.retry_guid);
return *this;
}

// static
bool LoadError::Populate(
    const base::Value& value, LoadError* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* error_value = NULL;
  if (!dict->GetWithoutPathExpansion("error", &error_value)) {
    return false;
  }
  {
    if (!error_value->GetAsString(&out->error)) {
      return false;
    }
  }

  const base::Value* path_value = NULL;
  if (!dict->GetWithoutPathExpansion("path", &path_value)) {
    return false;
  }
  {
    if (!path_value->GetAsString(&out->path)) {
      return false;
    }
  }

  const base::Value* source_value = NULL;
  if (dict->GetWithoutPathExpansion("source", &source_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!source_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ErrorFileSource> temp(new ErrorFileSource());
        if (!ErrorFileSource::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->source = std::move(temp);
      }
    }
  }

  const base::Value* retry_guid_value = NULL;
  if (!dict->GetWithoutPathExpansion("retryGuid", &retry_guid_value)) {
    return false;
  }
  {
    if (!retry_guid_value->GetAsString(&out->retry_guid)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<LoadError> LoadError::FromValue(const base::Value& value) {
  std::unique_ptr<LoadError> out(new LoadError());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> LoadError::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("error", std::make_unique<base::Value>(this->error));

  to_value_result->SetWithoutPathExpansion("path", std::make_unique<base::Value>(this->path));

  if (this->source.get()) {
    to_value_result->SetWithoutPathExpansion("source", (this->source)->ToValue());

  }
  to_value_result->SetWithoutPathExpansion("retryGuid", std::make_unique<base::Value>(this->retry_guid));


  return to_value_result;
}


RequestFileSourceProperties::RequestFileSourceProperties()
 {}

RequestFileSourceProperties::~RequestFileSourceProperties() {}
RequestFileSourceProperties::RequestFileSourceProperties(RequestFileSourceProperties&& rhs)
: extension_id(std::move(rhs.extension_id)),
path_suffix(std::move(rhs.path_suffix)),
message(std::move(rhs.message)),
manifest_key(std::move(rhs.manifest_key)),
manifest_specific(std::move(rhs.manifest_specific)),
line_number(std::move(rhs.line_number)){
}

RequestFileSourceProperties& RequestFileSourceProperties::operator=(RequestFileSourceProperties&& rhs)
{
extension_id = std::move(rhs.extension_id);
path_suffix = std::move(rhs.path_suffix);
message = std::move(rhs.message);
manifest_key = std::move(rhs.manifest_key);
manifest_specific = std::move(rhs.manifest_specific);
line_number = std::move(rhs.line_number);
return *this;
}

// static
bool RequestFileSourceProperties::Populate(
    const base::Value& value, RequestFileSourceProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* extension_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    return false;
  }
  {
    if (!extension_id_value->GetAsString(&out->extension_id)) {
      return false;
    }
  }

  const base::Value* path_suffix_value = NULL;
  if (!dict->GetWithoutPathExpansion("pathSuffix", &path_suffix_value)) {
    return false;
  }
  {
    if (!path_suffix_value->GetAsString(&out->path_suffix)) {
      return false;
    }
  }

  const base::Value* message_value = NULL;
  if (!dict->GetWithoutPathExpansion("message", &message_value)) {
    return false;
  }
  {
    if (!message_value->GetAsString(&out->message)) {
      return false;
    }
  }

  const base::Value* manifest_key_value = NULL;
  if (dict->GetWithoutPathExpansion("manifestKey", &manifest_key_value)) {
    {
      std::string temp;
      if (!manifest_key_value->GetAsString(&temp)) {
        out->manifest_key.reset();
        return false;
      }
      else
        out->manifest_key.reset(new std::string(temp));
    }
  }

  const base::Value* manifest_specific_value = NULL;
  if (dict->GetWithoutPathExpansion("manifestSpecific", &manifest_specific_value)) {
    {
      std::string temp;
      if (!manifest_specific_value->GetAsString(&temp)) {
        out->manifest_specific.reset();
        return false;
      }
      else
        out->manifest_specific.reset(new std::string(temp));
    }
  }

  const base::Value* line_number_value = NULL;
  if (dict->GetWithoutPathExpansion("lineNumber", &line_number_value)) {
    {
      int temp;
      if (!line_number_value->GetAsInteger(&temp)) {
        out->line_number.reset();
        return false;
      }
      else
        out->line_number.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<RequestFileSourceProperties> RequestFileSourceProperties::FromValue(const base::Value& value) {
  std::unique_ptr<RequestFileSourceProperties> out(new RequestFileSourceProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RequestFileSourceProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(this->extension_id));

  to_value_result->SetWithoutPathExpansion("pathSuffix", std::make_unique<base::Value>(this->path_suffix));

  to_value_result->SetWithoutPathExpansion("message", std::make_unique<base::Value>(this->message));

  if (this->manifest_key.get()) {
    to_value_result->SetWithoutPathExpansion("manifestKey", std::make_unique<base::Value>(*this->manifest_key));

  }
  if (this->manifest_specific.get()) {
    to_value_result->SetWithoutPathExpansion("manifestSpecific", std::make_unique<base::Value>(*this->manifest_specific));

  }
  if (this->line_number.get()) {
    to_value_result->SetWithoutPathExpansion("lineNumber", std::make_unique<base::Value>(*this->line_number));

  }

  return to_value_result;
}


RequestFileSourceResponse::RequestFileSourceResponse()
 {}

RequestFileSourceResponse::~RequestFileSourceResponse() {}
RequestFileSourceResponse::RequestFileSourceResponse(RequestFileSourceResponse&& rhs)
: highlight(std::move(rhs.highlight)),
before_highlight(std::move(rhs.before_highlight)),
after_highlight(std::move(rhs.after_highlight)),
title(std::move(rhs.title)),
message(std::move(rhs.message)){
}

RequestFileSourceResponse& RequestFileSourceResponse::operator=(RequestFileSourceResponse&& rhs)
{
highlight = std::move(rhs.highlight);
before_highlight = std::move(rhs.before_highlight);
after_highlight = std::move(rhs.after_highlight);
title = std::move(rhs.title);
message = std::move(rhs.message);
return *this;
}

// static
bool RequestFileSourceResponse::Populate(
    const base::Value& value, RequestFileSourceResponse* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* highlight_value = NULL;
  if (!dict->GetWithoutPathExpansion("highlight", &highlight_value)) {
    return false;
  }
  {
    if (!highlight_value->GetAsString(&out->highlight)) {
      return false;
    }
  }

  const base::Value* before_highlight_value = NULL;
  if (!dict->GetWithoutPathExpansion("beforeHighlight", &before_highlight_value)) {
    return false;
  }
  {
    if (!before_highlight_value->GetAsString(&out->before_highlight)) {
      return false;
    }
  }

  const base::Value* after_highlight_value = NULL;
  if (!dict->GetWithoutPathExpansion("afterHighlight", &after_highlight_value)) {
    return false;
  }
  {
    if (!after_highlight_value->GetAsString(&out->after_highlight)) {
      return false;
    }
  }

  const base::Value* title_value = NULL;
  if (!dict->GetWithoutPathExpansion("title", &title_value)) {
    return false;
  }
  {
    if (!title_value->GetAsString(&out->title)) {
      return false;
    }
  }

  const base::Value* message_value = NULL;
  if (!dict->GetWithoutPathExpansion("message", &message_value)) {
    return false;
  }
  {
    if (!message_value->GetAsString(&out->message)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<RequestFileSourceResponse> RequestFileSourceResponse::FromValue(const base::Value& value) {
  std::unique_ptr<RequestFileSourceResponse> out(new RequestFileSourceResponse());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RequestFileSourceResponse::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("highlight", std::make_unique<base::Value>(this->highlight));

  to_value_result->SetWithoutPathExpansion("beforeHighlight", std::make_unique<base::Value>(this->before_highlight));

  to_value_result->SetWithoutPathExpansion("afterHighlight", std::make_unique<base::Value>(this->after_highlight));

  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  to_value_result->SetWithoutPathExpansion("message", std::make_unique<base::Value>(this->message));


  return to_value_result;
}


OpenDevToolsProperties::OpenDevToolsProperties()
: render_view_id(0),
render_process_id(0) {}

OpenDevToolsProperties::~OpenDevToolsProperties() {}
OpenDevToolsProperties::OpenDevToolsProperties(OpenDevToolsProperties&& rhs)
: extension_id(std::move(rhs.extension_id)),
render_view_id(rhs.render_view_id),
render_process_id(rhs.render_process_id),
incognito(std::move(rhs.incognito)),
url(std::move(rhs.url)),
line_number(std::move(rhs.line_number)),
column_number(std::move(rhs.column_number)){
}

OpenDevToolsProperties& OpenDevToolsProperties::operator=(OpenDevToolsProperties&& rhs)
{
extension_id = std::move(rhs.extension_id);
render_view_id = rhs.render_view_id;
render_process_id = rhs.render_process_id;
incognito = std::move(rhs.incognito);
url = std::move(rhs.url);
line_number = std::move(rhs.line_number);
column_number = std::move(rhs.column_number);
return *this;
}

// static
bool OpenDevToolsProperties::Populate(
    const base::Value& value, OpenDevToolsProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* extension_id_value = NULL;
  if (dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    {
      std::string temp;
      if (!extension_id_value->GetAsString(&temp)) {
        out->extension_id.reset();
        return false;
      }
      else
        out->extension_id.reset(new std::string(temp));
    }
  }

  const base::Value* render_view_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("renderViewId", &render_view_id_value)) {
    return false;
  }
  {
    if (!render_view_id_value->GetAsInteger(&out->render_view_id)) {
      return false;
    }
  }

  const base::Value* render_process_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("renderProcessId", &render_process_id_value)) {
    return false;
  }
  {
    if (!render_process_id_value->GetAsInteger(&out->render_process_id)) {
      return false;
    }
  }

  const base::Value* incognito_value = NULL;
  if (dict->GetWithoutPathExpansion("incognito", &incognito_value)) {
    {
      bool temp;
      if (!incognito_value->GetAsBoolean(&temp)) {
        out->incognito.reset();
        return false;
      }
      else
        out->incognito.reset(new bool(temp));
    }
  }

  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      std::string temp;
      if (!url_value->GetAsString(&temp)) {
        out->url.reset();
        return false;
      }
      else
        out->url.reset(new std::string(temp));
    }
  }

  const base::Value* line_number_value = NULL;
  if (dict->GetWithoutPathExpansion("lineNumber", &line_number_value)) {
    {
      int temp;
      if (!line_number_value->GetAsInteger(&temp)) {
        out->line_number.reset();
        return false;
      }
      else
        out->line_number.reset(new int(temp));
    }
  }

  const base::Value* column_number_value = NULL;
  if (dict->GetWithoutPathExpansion("columnNumber", &column_number_value)) {
    {
      int temp;
      if (!column_number_value->GetAsInteger(&temp)) {
        out->column_number.reset();
        return false;
      }
      else
        out->column_number.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<OpenDevToolsProperties> OpenDevToolsProperties::FromValue(const base::Value& value) {
  std::unique_ptr<OpenDevToolsProperties> out(new OpenDevToolsProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> OpenDevToolsProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->extension_id.get()) {
    to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(*this->extension_id));

  }
  to_value_result->SetWithoutPathExpansion("renderViewId", std::make_unique<base::Value>(this->render_view_id));

  to_value_result->SetWithoutPathExpansion("renderProcessId", std::make_unique<base::Value>(this->render_process_id));

  if (this->incognito.get()) {
    to_value_result->SetWithoutPathExpansion("incognito", std::make_unique<base::Value>(*this->incognito));

  }
  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }
  if (this->line_number.get()) {
    to_value_result->SetWithoutPathExpansion("lineNumber", std::make_unique<base::Value>(*this->line_number));

  }
  if (this->column_number.get()) {
    to_value_result->SetWithoutPathExpansion("columnNumber", std::make_unique<base::Value>(*this->column_number));

  }

  return to_value_result;
}


DeleteExtensionErrorsProperties::DeleteExtensionErrorsProperties()
: type(ERROR_TYPE_NONE) {}

DeleteExtensionErrorsProperties::~DeleteExtensionErrorsProperties() {}
DeleteExtensionErrorsProperties::DeleteExtensionErrorsProperties(DeleteExtensionErrorsProperties&& rhs)
: extension_id(std::move(rhs.extension_id)),
error_ids(std::move(rhs.error_ids)),
type(rhs.type){
}

DeleteExtensionErrorsProperties& DeleteExtensionErrorsProperties::operator=(DeleteExtensionErrorsProperties&& rhs)
{
extension_id = std::move(rhs.extension_id);
error_ids = std::move(rhs.error_ids);
type = rhs.type;
return *this;
}

// static
bool DeleteExtensionErrorsProperties::Populate(
    const base::Value& value, DeleteExtensionErrorsProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->type = ERROR_TYPE_NONE;
  const base::Value* extension_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    return false;
  }
  {
    if (!extension_id_value->GetAsString(&out->extension_id)) {
      return false;
    }
  }

  const base::Value* error_ids_value = NULL;
  if (dict->GetWithoutPathExpansion("errorIds", &error_ids_value)) {
    {
      const base::ListValue* list = NULL;
      if (!error_ids_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->error_ids)) {
          return false;
        }
      }
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string error_type_as_string;
      if (!type_value->GetAsString(&error_type_as_string)) {
        return false;
      }
      out->type = ParseErrorType(error_type_as_string);
      if (out->type == ERROR_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = ERROR_TYPE_NONE;
  }

  return true;
}

// static
std::unique_ptr<DeleteExtensionErrorsProperties> DeleteExtensionErrorsProperties::FromValue(const base::Value& value) {
  std::unique_ptr<DeleteExtensionErrorsProperties> out(new DeleteExtensionErrorsProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DeleteExtensionErrorsProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(this->extension_id));

  if (this->error_ids.get()) {
    to_value_result->SetWithoutPathExpansion("errorIds", json_schema_compiler::util::CreateValueFromOptionalArray(this->error_ids));

  }
  if (this->type != ERROR_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(developer_private::ToString(this->type)));

  }

  return to_value_result;
}



//
// Functions
//

namespace AutoUpdate {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace AutoUpdate

namespace GetExtensionsInfo {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* options_value = NULL;
  if (args.Get(0, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<GetExtensionsInfoOptions> temp(new GetExtensionsInfoOptions());
        if (!GetExtensionsInfoOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<ExtensionInfo>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetExtensionsInfo

namespace GetExtensionInfo {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ExtensionInfo& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetExtensionInfo

namespace GetExtensionSize {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& string) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(string));

  return create_results;
}
}  // namespace GetExtensionSize

namespace GetItemsInfo {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* include_disabled_value = NULL;
  if (args.Get(0, &include_disabled_value) &&
      !include_disabled_value->is_none()) {
    {
      if (!include_disabled_value->GetAsBoolean(&params->include_disabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* include_terminated_value = NULL;
  if (args.Get(1, &include_terminated_value) &&
      !include_terminated_value->is_none()) {
    {
      if (!include_terminated_value->GetAsBoolean(&params->include_terminated)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<ItemInfo>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetItemsInfo

namespace GetProfileConfiguration {

std::unique_ptr<base::ListValue> Results::Create(const ProfileInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace GetProfileConfiguration

namespace UpdateProfileConfiguration {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* update_value = NULL;
  if (args.Get(0, &update_value) &&
      !update_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!update_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ProfileConfigurationUpdate::Populate(*dictionary, &params->update)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace UpdateProfileConfiguration

namespace ShowPermissionsDialog {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* extension_id_value = NULL;
  if (args.Get(0, &extension_id_value) &&
      !extension_id_value->is_none()) {
    {
      if (!extension_id_value->GetAsString(&params->extension_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace ShowPermissionsDialog

namespace Reload {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* extension_id_value = NULL;
  if (args.Get(0, &extension_id_value) &&
      !extension_id_value->is_none()) {
    {
      if (!extension_id_value->GetAsString(&params->extension_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* options_value = NULL;
  if (args.Get(1, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<ReloadOptions> temp(new ReloadOptions());
        if (!ReloadOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const LoadError& error) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((error).ToValue());

  return create_results;
}
}  // namespace Reload

namespace UpdateExtensionConfiguration {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* update_value = NULL;
  if (args.Get(0, &update_value) &&
      !update_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!update_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ExtensionConfigurationUpdate::Populate(*dictionary, &params->update)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace UpdateExtensionConfiguration

namespace LoadUnpacked {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* options_value = NULL;
  if (args.Get(0, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<LoadUnpackedOptions> temp(new LoadUnpackedOptions());
        if (!LoadUnpackedOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const LoadError& error) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((error).ToValue());

  return create_results;
}
}  // namespace LoadUnpacked

namespace InstallDroppedFile {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace InstallDroppedFile

namespace NotifyDragInstallInProgress {

}  // namespace NotifyDragInstallInProgress

namespace LoadDirectory {

Params::Directory::Directory()
 {}

Params::Directory::~Directory() {}
Params::Directory::Directory(Directory&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::Directory& Params::Directory::operator=(Directory&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::Directory::Populate(
    const base::Value& value, Directory* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* directory_value = NULL;
  if (args.Get(0, &directory_value) &&
      !directory_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!directory_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Directory::Populate(*dictionary, &params->directory)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& string) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(string));

  return create_results;
}
}  // namespace LoadDirectory

namespace ChoosePath {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* select_type_value = NULL;
  if (args.Get(0, &select_type_value) &&
      !select_type_value->is_none()) {
    {
      std::string select_type_as_string;
      if (!select_type_value->GetAsString(&select_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->select_type = ParseSelectType(select_type_as_string);
      if (params->select_type == SELECT_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* file_type_value = NULL;
  if (args.Get(1, &file_type_value) &&
      !file_type_value->is_none()) {
    {
      std::string file_type_as_string;
      if (!file_type_value->GetAsString(&file_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->file_type = ParseFileType(file_type_as_string);
      if (params->file_type == FILE_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& string) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(string));

  return create_results;
}
}  // namespace ChoosePath

namespace PackDirectory {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* path_value = NULL;
  if (args.Get(0, &path_value) &&
      !path_value->is_none()) {
    {
      if (!path_value->GetAsString(&params->path)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* private_key_path_value = NULL;
  if (args.Get(1, &private_key_path_value) &&
      !private_key_path_value->is_none()) {
    {
      std::string temp;
      if (!private_key_path_value->GetAsString(&temp)) {
        params->private_key_path.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->private_key_path.reset(new std::string(temp));
    }
  }

  const base::Value* flags_value = NULL;
  if (args.Get(2, &flags_value) &&
      !flags_value->is_none()) {
    {
      int temp;
      if (!flags_value->GetAsInteger(&temp)) {
        params->flags.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->flags.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const PackDirectoryResponse& response) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((response).ToValue());

  return create_results;
}
}  // namespace PackDirectory

namespace IsProfileManaged {

std::unique_ptr<base::ListValue> Results::Create(bool result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace IsProfileManaged

namespace RequestFileSource {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* properties_value = NULL;
  if (args.Get(0, &properties_value) &&
      !properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!RequestFileSourceProperties::Populate(*dictionary, &params->properties)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const RequestFileSourceResponse& response) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((response).ToValue());

  return create_results;
}
}  // namespace RequestFileSource

namespace OpenDevTools {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* properties_value = NULL;
  if (args.Get(0, &properties_value) &&
      !properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!OpenDevToolsProperties::Populate(*dictionary, &params->properties)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace OpenDevTools

namespace DeleteExtensionErrors {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* properties_value = NULL;
  if (args.Get(0, &properties_value) &&
      !properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!DeleteExtensionErrorsProperties::Populate(*dictionary, &params->properties)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace DeleteExtensionErrors

namespace RepairExtension {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* extension_id_value = NULL;
  if (args.Get(0, &extension_id_value) &&
      !extension_id_value->is_none()) {
    {
      if (!extension_id_value->GetAsString(&params->extension_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace RepairExtension

namespace ShowOptions {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* extension_id_value = NULL;
  if (args.Get(0, &extension_id_value) &&
      !extension_id_value->is_none()) {
    {
      if (!extension_id_value->GetAsString(&params->extension_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace ShowOptions

namespace ShowPath {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* extension_id_value = NULL;
  if (args.Get(0, &extension_id_value) &&
      !extension_id_value->is_none()) {
    {
      if (!extension_id_value->GetAsString(&params->extension_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace ShowPath

namespace SetShortcutHandlingSuspended {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* is_suspended_value = NULL;
  if (args.Get(0, &is_suspended_value) &&
      !is_suspended_value->is_none()) {
    {
      if (!is_suspended_value->GetAsBoolean(&params->is_suspended)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SetShortcutHandlingSuspended

namespace UpdateExtensionCommand {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* update_value = NULL;
  if (args.Get(0, &update_value) &&
      !update_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!update_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ExtensionCommandUpdate::Populate(*dictionary, &params->update)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace UpdateExtensionCommand

namespace AddHostPermission {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* extension_id_value = NULL;
  if (args.Get(0, &extension_id_value) &&
      !extension_id_value->is_none()) {
    {
      if (!extension_id_value->GetAsString(&params->extension_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* host_value = NULL;
  if (args.Get(1, &host_value) &&
      !host_value->is_none()) {
    {
      if (!host_value->GetAsString(&params->host)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace AddHostPermission

namespace RemoveHostPermission {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* extension_id_value = NULL;
  if (args.Get(0, &extension_id_value) &&
      !extension_id_value->is_none()) {
    {
      if (!extension_id_value->GetAsString(&params->extension_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* host_value = NULL;
  if (args.Get(1, &host_value) &&
      !host_value->is_none()) {
    {
      if (!host_value->GetAsString(&params->host)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace RemoveHostPermission

//
// Events
//

namespace OnItemStateChanged {

const char kEventName[] = "developerPrivate.onItemStateChanged";

std::unique_ptr<base::ListValue> Create(const EventData& response) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((response).ToValue());

  return create_results;
}

}  // namespace OnItemStateChanged

namespace OnProfileStateChanged {

const char kEventName[] = "developerPrivate.onProfileStateChanged";

std::unique_ptr<base::ListValue> Create(const ProfileInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnProfileStateChanged

}  // namespace developer_private
}  // namespace api
}  // namespace extensions

