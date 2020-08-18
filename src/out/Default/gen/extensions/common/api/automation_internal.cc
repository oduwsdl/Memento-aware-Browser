// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/automation_internal.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/automation_internal.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace automation_internal {
//
// Types
//

AXEventParams::AXEventParams()
 {}

AXEventParams::~AXEventParams() {}
AXEventParams::AXEventParams(AXEventParams&& rhs)
{
}

AXEventParams& AXEventParams::operator=(AXEventParams&& rhs)
{

return *this;
}

// static
bool AXEventParams::Populate(
    const base::Value& value, AXEventParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<AXEventParams> AXEventParams::FromValue(const base::Value& value) {
  std::unique_ptr<AXEventParams> out(new AXEventParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AXEventParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


  return to_value_result;
}


AXTextLocationParams::AXTextLocationParams()
: node_id(0),
result(false),
left(0),
top(0),
width(0),
height(0),
request_id(0) {}

AXTextLocationParams::~AXTextLocationParams() {}
AXTextLocationParams::AXTextLocationParams(AXTextLocationParams&& rhs)
: tree_id(std::move(rhs.tree_id)),
node_id(rhs.node_id),
result(rhs.result),
left(rhs.left),
top(rhs.top),
width(rhs.width),
height(rhs.height),
request_id(rhs.request_id){
}

AXTextLocationParams& AXTextLocationParams::operator=(AXTextLocationParams&& rhs)
{
tree_id = std::move(rhs.tree_id);
node_id = rhs.node_id;
result = rhs.result;
left = rhs.left;
top = rhs.top;
width = rhs.width;
height = rhs.height;
request_id = rhs.request_id;
return *this;
}

// static
bool AXTextLocationParams::Populate(
    const base::Value& value, AXTextLocationParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* tree_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("treeID", &tree_id_value)) {
    return false;
  }
  {
    if (!tree_id_value->GetAsString(&out->tree_id)) {
      return false;
    }
  }

  const base::Value* node_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("nodeID", &node_id_value)) {
    return false;
  }
  {
    if (!node_id_value->GetAsInteger(&out->node_id)) {
      return false;
    }
  }

  const base::Value* result_value = NULL;
  if (!dict->GetWithoutPathExpansion("result", &result_value)) {
    return false;
  }
  {
    if (!result_value->GetAsBoolean(&out->result)) {
      return false;
    }
  }

  const base::Value* left_value = NULL;
  if (!dict->GetWithoutPathExpansion("left", &left_value)) {
    return false;
  }
  {
    if (!left_value->GetAsInteger(&out->left)) {
      return false;
    }
  }

  const base::Value* top_value = NULL;
  if (!dict->GetWithoutPathExpansion("top", &top_value)) {
    return false;
  }
  {
    if (!top_value->GetAsInteger(&out->top)) {
      return false;
    }
  }

  const base::Value* width_value = NULL;
  if (!dict->GetWithoutPathExpansion("width", &width_value)) {
    return false;
  }
  {
    if (!width_value->GetAsInteger(&out->width)) {
      return false;
    }
  }

  const base::Value* height_value = NULL;
  if (!dict->GetWithoutPathExpansion("height", &height_value)) {
    return false;
  }
  {
    if (!height_value->GetAsInteger(&out->height)) {
      return false;
    }
  }

  const base::Value* request_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("requestID", &request_id_value)) {
    return false;
  }
  {
    if (!request_id_value->GetAsInteger(&out->request_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<AXTextLocationParams> AXTextLocationParams::FromValue(const base::Value& value) {
  std::unique_ptr<AXTextLocationParams> out(new AXTextLocationParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AXTextLocationParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("treeID", std::make_unique<base::Value>(this->tree_id));

  to_value_result->SetWithoutPathExpansion("nodeID", std::make_unique<base::Value>(this->node_id));

  to_value_result->SetWithoutPathExpansion("result", std::make_unique<base::Value>(this->result));

  to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(this->left));

  to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(this->top));

  to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(this->width));

  to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(this->height));

  to_value_result->SetWithoutPathExpansion("requestID", std::make_unique<base::Value>(this->request_id));


  return to_value_result;
}


const char* ToString(ActionTypePrivate enum_param) {
  switch (enum_param) {
    case ACTION_TYPE_PRIVATE_RESUMEMEDIA:
      return "resumeMedia";
    case ACTION_TYPE_PRIVATE_STARTDUCKINGMEDIA:
      return "startDuckingMedia";
    case ACTION_TYPE_PRIVATE_STOPDUCKINGMEDIA:
      return "stopDuckingMedia";
    case ACTION_TYPE_PRIVATE_SUSPENDMEDIA:
      return "suspendMedia";
    case ACTION_TYPE_PRIVATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ActionTypePrivate ParseActionTypePrivate(const std::string& enum_string) {
  if (enum_string == "resumeMedia")
    return ACTION_TYPE_PRIVATE_RESUMEMEDIA;
  if (enum_string == "startDuckingMedia")
    return ACTION_TYPE_PRIVATE_STARTDUCKINGMEDIA;
  if (enum_string == "stopDuckingMedia")
    return ACTION_TYPE_PRIVATE_STOPDUCKINGMEDIA;
  if (enum_string == "suspendMedia")
    return ACTION_TYPE_PRIVATE_SUSPENDMEDIA;
  return ACTION_TYPE_PRIVATE_NONE;
}


PerformActionRequiredParams::PerformActionRequiredParams()
: automation_node_id(0) {}

PerformActionRequiredParams::~PerformActionRequiredParams() {}
PerformActionRequiredParams::PerformActionRequiredParams(PerformActionRequiredParams&& rhs)
: tree_id(std::move(rhs.tree_id)),
automation_node_id(rhs.automation_node_id),
action_type(std::move(rhs.action_type)),
request_id(std::move(rhs.request_id)){
}

PerformActionRequiredParams& PerformActionRequiredParams::operator=(PerformActionRequiredParams&& rhs)
{
tree_id = std::move(rhs.tree_id);
automation_node_id = rhs.automation_node_id;
action_type = std::move(rhs.action_type);
request_id = std::move(rhs.request_id);
return *this;
}

// static
bool PerformActionRequiredParams::Populate(
    const base::Value& value, PerformActionRequiredParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* tree_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("treeID", &tree_id_value)) {
    return false;
  }
  {
    if (!tree_id_value->GetAsString(&out->tree_id)) {
      return false;
    }
  }

  const base::Value* automation_node_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("automationNodeID", &automation_node_id_value)) {
    return false;
  }
  {
    if (!automation_node_id_value->GetAsInteger(&out->automation_node_id)) {
      return false;
    }
  }

  const base::Value* action_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("actionType", &action_type_value)) {
    return false;
  }
  {
    if (!action_type_value->GetAsString(&out->action_type)) {
      return false;
    }
  }

  const base::Value* request_id_value = NULL;
  if (dict->GetWithoutPathExpansion("requestID", &request_id_value)) {
    {
      int temp;
      if (!request_id_value->GetAsInteger(&temp)) {
        out->request_id.reset();
        return false;
      }
      else
        out->request_id.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<PerformActionRequiredParams> PerformActionRequiredParams::FromValue(const base::Value& value) {
  std::unique_ptr<PerformActionRequiredParams> out(new PerformActionRequiredParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PerformActionRequiredParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("treeID", std::make_unique<base::Value>(this->tree_id));

  to_value_result->SetWithoutPathExpansion("automationNodeID", std::make_unique<base::Value>(this->automation_node_id));

  to_value_result->SetWithoutPathExpansion("actionType", std::make_unique<base::Value>(this->action_type));

  if (this->request_id.get()) {
    to_value_result->SetWithoutPathExpansion("requestID", std::make_unique<base::Value>(*this->request_id));

  }

  return to_value_result;
}


PerformCustomActionParams::PerformCustomActionParams()
: custom_action_id(0) {}

PerformCustomActionParams::~PerformCustomActionParams() {}
PerformCustomActionParams::PerformCustomActionParams(PerformCustomActionParams&& rhs)
: custom_action_id(rhs.custom_action_id){
}

PerformCustomActionParams& PerformCustomActionParams::operator=(PerformCustomActionParams&& rhs)
{
custom_action_id = rhs.custom_action_id;
return *this;
}

// static
bool PerformCustomActionParams::Populate(
    const base::Value& value, PerformCustomActionParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* custom_action_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("customActionID", &custom_action_id_value)) {
    return false;
  }
  {
    if (!custom_action_id_value->GetAsInteger(&out->custom_action_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<PerformCustomActionParams> PerformCustomActionParams::FromValue(const base::Value& value) {
  std::unique_ptr<PerformCustomActionParams> out(new PerformCustomActionParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PerformCustomActionParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("customActionID", std::make_unique<base::Value>(this->custom_action_id));


  return to_value_result;
}


SetSelectionParams::SetSelectionParams()
: focus_node_id(0),
anchor_offset(0),
focus_offset(0) {}

SetSelectionParams::~SetSelectionParams() {}
SetSelectionParams::SetSelectionParams(SetSelectionParams&& rhs)
: focus_node_id(rhs.focus_node_id),
anchor_offset(rhs.anchor_offset),
focus_offset(rhs.focus_offset){
}

SetSelectionParams& SetSelectionParams::operator=(SetSelectionParams&& rhs)
{
focus_node_id = rhs.focus_node_id;
anchor_offset = rhs.anchor_offset;
focus_offset = rhs.focus_offset;
return *this;
}

// static
bool SetSelectionParams::Populate(
    const base::Value& value, SetSelectionParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* focus_node_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("focusNodeID", &focus_node_id_value)) {
    return false;
  }
  {
    if (!focus_node_id_value->GetAsInteger(&out->focus_node_id)) {
      return false;
    }
  }

  const base::Value* anchor_offset_value = NULL;
  if (!dict->GetWithoutPathExpansion("anchorOffset", &anchor_offset_value)) {
    return false;
  }
  {
    if (!anchor_offset_value->GetAsInteger(&out->anchor_offset)) {
      return false;
    }
  }

  const base::Value* focus_offset_value = NULL;
  if (!dict->GetWithoutPathExpansion("focusOffset", &focus_offset_value)) {
    return false;
  }
  {
    if (!focus_offset_value->GetAsInteger(&out->focus_offset)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<SetSelectionParams> SetSelectionParams::FromValue(const base::Value& value) {
  std::unique_ptr<SetSelectionParams> out(new SetSelectionParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SetSelectionParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("focusNodeID", std::make_unique<base::Value>(this->focus_node_id));

  to_value_result->SetWithoutPathExpansion("anchorOffset", std::make_unique<base::Value>(this->anchor_offset));

  to_value_result->SetWithoutPathExpansion("focusOffset", std::make_unique<base::Value>(this->focus_offset));


  return to_value_result;
}


ReplaceSelectedTextParams::ReplaceSelectedTextParams()
 {}

ReplaceSelectedTextParams::~ReplaceSelectedTextParams() {}
ReplaceSelectedTextParams::ReplaceSelectedTextParams(ReplaceSelectedTextParams&& rhs)
: value(std::move(rhs.value)){
}

ReplaceSelectedTextParams& ReplaceSelectedTextParams::operator=(ReplaceSelectedTextParams&& rhs)
{
value = std::move(rhs.value);
return *this;
}

// static
bool ReplaceSelectedTextParams::Populate(
    const base::Value& value, ReplaceSelectedTextParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* value_value = NULL;
  if (!dict->GetWithoutPathExpansion("value", &value_value)) {
    return false;
  }
  {
    if (!value_value->GetAsString(&out->value)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ReplaceSelectedTextParams> ReplaceSelectedTextParams::FromValue(const base::Value& value) {
  std::unique_ptr<ReplaceSelectedTextParams> out(new ReplaceSelectedTextParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ReplaceSelectedTextParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(this->value));


  return to_value_result;
}


SetValueParams::SetValueParams()
 {}

SetValueParams::~SetValueParams() {}
SetValueParams::SetValueParams(SetValueParams&& rhs)
: value(std::move(rhs.value)){
}

SetValueParams& SetValueParams::operator=(SetValueParams&& rhs)
{
value = std::move(rhs.value);
return *this;
}

// static
bool SetValueParams::Populate(
    const base::Value& value, SetValueParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* value_value = NULL;
  if (!dict->GetWithoutPathExpansion("value", &value_value)) {
    return false;
  }
  {
    if (!value_value->GetAsString(&out->value)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<SetValueParams> SetValueParams::FromValue(const base::Value& value) {
  std::unique_ptr<SetValueParams> out(new SetValueParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SetValueParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(this->value));


  return to_value_result;
}


QuerySelectorRequiredParams::QuerySelectorRequiredParams()
: automation_node_id(0) {}

QuerySelectorRequiredParams::~QuerySelectorRequiredParams() {}
QuerySelectorRequiredParams::QuerySelectorRequiredParams(QuerySelectorRequiredParams&& rhs)
: tree_id(std::move(rhs.tree_id)),
automation_node_id(rhs.automation_node_id),
selector(std::move(rhs.selector)){
}

QuerySelectorRequiredParams& QuerySelectorRequiredParams::operator=(QuerySelectorRequiredParams&& rhs)
{
tree_id = std::move(rhs.tree_id);
automation_node_id = rhs.automation_node_id;
selector = std::move(rhs.selector);
return *this;
}

// static
bool QuerySelectorRequiredParams::Populate(
    const base::Value& value, QuerySelectorRequiredParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* tree_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("treeID", &tree_id_value)) {
    return false;
  }
  {
    if (!tree_id_value->GetAsString(&out->tree_id)) {
      return false;
    }
  }

  const base::Value* automation_node_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("automationNodeID", &automation_node_id_value)) {
    return false;
  }
  {
    if (!automation_node_id_value->GetAsInteger(&out->automation_node_id)) {
      return false;
    }
  }

  const base::Value* selector_value = NULL;
  if (!dict->GetWithoutPathExpansion("selector", &selector_value)) {
    return false;
  }
  {
    if (!selector_value->GetAsString(&out->selector)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<QuerySelectorRequiredParams> QuerySelectorRequiredParams::FromValue(const base::Value& value) {
  std::unique_ptr<QuerySelectorRequiredParams> out(new QuerySelectorRequiredParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> QuerySelectorRequiredParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("treeID", std::make_unique<base::Value>(this->tree_id));

  to_value_result->SetWithoutPathExpansion("automationNodeID", std::make_unique<base::Value>(this->automation_node_id));

  to_value_result->SetWithoutPathExpansion("selector", std::make_unique<base::Value>(this->selector));


  return to_value_result;
}


EnableTabParams::EnableTabParams()
 {}

EnableTabParams::~EnableTabParams() {}
EnableTabParams::EnableTabParams(EnableTabParams&& rhs)
: tab_id(std::move(rhs.tab_id)){
}

EnableTabParams& EnableTabParams::operator=(EnableTabParams&& rhs)
{
tab_id = std::move(rhs.tab_id);
return *this;
}

// static
bool EnableTabParams::Populate(
    const base::Value& value, EnableTabParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* tab_id_value = NULL;
  if (dict->GetWithoutPathExpansion("tabID", &tab_id_value)) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        out->tab_id.reset();
        return false;
      }
      else
        out->tab_id.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<EnableTabParams> EnableTabParams::FromValue(const base::Value& value) {
  std::unique_ptr<EnableTabParams> out(new EnableTabParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> EnableTabParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->tab_id.get()) {
    to_value_result->SetWithoutPathExpansion("tabID", std::make_unique<base::Value>(*this->tab_id));

  }

  return to_value_result;
}


GetImageDataParams::GetImageDataParams()
: max_width(0),
max_height(0) {}

GetImageDataParams::~GetImageDataParams() {}
GetImageDataParams::GetImageDataParams(GetImageDataParams&& rhs)
: max_width(rhs.max_width),
max_height(rhs.max_height){
}

GetImageDataParams& GetImageDataParams::operator=(GetImageDataParams&& rhs)
{
max_width = rhs.max_width;
max_height = rhs.max_height;
return *this;
}

// static
bool GetImageDataParams::Populate(
    const base::Value& value, GetImageDataParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* max_width_value = NULL;
  if (!dict->GetWithoutPathExpansion("maxWidth", &max_width_value)) {
    return false;
  }
  {
    if (!max_width_value->GetAsInteger(&out->max_width)) {
      return false;
    }
  }

  const base::Value* max_height_value = NULL;
  if (!dict->GetWithoutPathExpansion("maxHeight", &max_height_value)) {
    return false;
  }
  {
    if (!max_height_value->GetAsInteger(&out->max_height)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<GetImageDataParams> GetImageDataParams::FromValue(const base::Value& value) {
  std::unique_ptr<GetImageDataParams> out(new GetImageDataParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> GetImageDataParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("maxWidth", std::make_unique<base::Value>(this->max_width));

  to_value_result->SetWithoutPathExpansion("maxHeight", std::make_unique<base::Value>(this->max_height));


  return to_value_result;
}


HitTestParams::HitTestParams()
: x(0),
y(0) {}

HitTestParams::~HitTestParams() {}
HitTestParams::HitTestParams(HitTestParams&& rhs)
: x(rhs.x),
y(rhs.y),
event_to_fire(std::move(rhs.event_to_fire)){
}

HitTestParams& HitTestParams::operator=(HitTestParams&& rhs)
{
x = rhs.x;
y = rhs.y;
event_to_fire = std::move(rhs.event_to_fire);
return *this;
}

// static
bool HitTestParams::Populate(
    const base::Value& value, HitTestParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* x_value = NULL;
  if (!dict->GetWithoutPathExpansion("x", &x_value)) {
    return false;
  }
  {
    if (!x_value->GetAsInteger(&out->x)) {
      return false;
    }
  }

  const base::Value* y_value = NULL;
  if (!dict->GetWithoutPathExpansion("y", &y_value)) {
    return false;
  }
  {
    if (!y_value->GetAsInteger(&out->y)) {
      return false;
    }
  }

  const base::Value* event_to_fire_value = NULL;
  if (!dict->GetWithoutPathExpansion("eventToFire", &event_to_fire_value)) {
    return false;
  }
  {
    if (!event_to_fire_value->GetAsString(&out->event_to_fire)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<HitTestParams> HitTestParams::FromValue(const base::Value& value) {
  std::unique_ptr<HitTestParams> out(new HitTestParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> HitTestParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("x", std::make_unique<base::Value>(this->x));

  to_value_result->SetWithoutPathExpansion("y", std::make_unique<base::Value>(this->y));

  to_value_result->SetWithoutPathExpansion("eventToFire", std::make_unique<base::Value>(this->event_to_fire));


  return to_value_result;
}


GetTextLocationDataParams::GetTextLocationDataParams()
: start_index(0),
end_index(0) {}

GetTextLocationDataParams::~GetTextLocationDataParams() {}
GetTextLocationDataParams::GetTextLocationDataParams(GetTextLocationDataParams&& rhs)
: start_index(rhs.start_index),
end_index(rhs.end_index){
}

GetTextLocationDataParams& GetTextLocationDataParams::operator=(GetTextLocationDataParams&& rhs)
{
start_index = rhs.start_index;
end_index = rhs.end_index;
return *this;
}

// static
bool GetTextLocationDataParams::Populate(
    const base::Value& value, GetTextLocationDataParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* start_index_value = NULL;
  if (!dict->GetWithoutPathExpansion("startIndex", &start_index_value)) {
    return false;
  }
  {
    if (!start_index_value->GetAsInteger(&out->start_index)) {
      return false;
    }
  }

  const base::Value* end_index_value = NULL;
  if (!dict->GetWithoutPathExpansion("endIndex", &end_index_value)) {
    return false;
  }
  {
    if (!end_index_value->GetAsInteger(&out->end_index)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<GetTextLocationDataParams> GetTextLocationDataParams::FromValue(const base::Value& value) {
  std::unique_ptr<GetTextLocationDataParams> out(new GetTextLocationDataParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> GetTextLocationDataParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("startIndex", std::make_unique<base::Value>(this->start_index));

  to_value_result->SetWithoutPathExpansion("endIndex", std::make_unique<base::Value>(this->end_index));


  return to_value_result;
}



//
// Functions
//

namespace EnableTab {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* args_value = NULL;
  if (args.Get(0, &args_value) &&
      !args_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!args_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!EnableTabParams::Populate(*dictionary, &params->args)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& tree_id, int tab_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tree_id));

  create_results->Append(std::make_unique<base::Value>(tab_id));

  return create_results;
}
}  // namespace EnableTab

namespace EnableTree {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tree_id_value = NULL;
  if (args.Get(0, &tree_id_value) &&
      !tree_id_value->is_none()) {
    {
      if (!tree_id_value->GetAsString(&params->tree_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace EnableTree

namespace EnableDesktop {

std::unique_ptr<base::ListValue> Results::Create(const std::string& tree_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tree_id));

  return create_results;
}
}  // namespace EnableDesktop

namespace PerformAction {

Params::Opt_args::Opt_args()
 {}

Params::Opt_args::~Opt_args() {}
Params::Opt_args::Opt_args(Opt_args&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::Opt_args& Params::Opt_args::operator=(Opt_args&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::Opt_args::Populate(
    const base::Value& value, Opt_args* out) {
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
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* args_value = NULL;
  if (args.Get(0, &args_value) &&
      !args_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!args_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!PerformActionRequiredParams::Populate(*dictionary, &params->args)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* opt_args_value = NULL;
  if (args.Get(1, &opt_args_value) &&
      !opt_args_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!opt_args_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Opt_args::Populate(*dictionary, &params->opt_args)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace PerformAction

namespace QuerySelector {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* args_value = NULL;
  if (args.Get(0, &args_value) &&
      !args_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!args_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!QuerySelectorRequiredParams::Populate(*dictionary, &params->args)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int result_automation_node_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result_automation_node_id));

  return create_results;
}
}  // namespace QuerySelector

//
// Events
//

namespace OnAccessibilityEvent {

const char kEventName[] = "automationInternal.onAccessibilityEvent";

std::unique_ptr<base::ListValue> Create(const AXEventParams& update) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((update).ToValue());

  return create_results;
}

}  // namespace OnAccessibilityEvent

namespace OnAccessibilityTreeDestroyed {

const char kEventName[] = "automationInternal.onAccessibilityTreeDestroyed";

std::unique_ptr<base::ListValue> Create(const std::string& tree_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tree_id));

  return create_results;
}

}  // namespace OnAccessibilityTreeDestroyed

namespace OnGetTextLocationResult {

const char kEventName[] = "automationInternal.onGetTextLocationResult";

std::unique_ptr<base::ListValue> Create(const AXTextLocationParams& params) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((params).ToValue());

  return create_results;
}

}  // namespace OnGetTextLocationResult

namespace OnTreeChange {

const char kEventName[] = "automationInternal.onTreeChange";

std::unique_ptr<base::ListValue> Create(int observer_id, const std::string& tree_id, int node_id, const std::string& change_type) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(observer_id));

  create_results->Append(std::make_unique<base::Value>(tree_id));

  create_results->Append(std::make_unique<base::Value>(node_id));

  create_results->Append(std::make_unique<base::Value>(change_type));

  return create_results;
}

}  // namespace OnTreeChange

namespace OnChildTreeID {

const char kEventName[] = "automationInternal.onChildTreeID";

std::unique_ptr<base::ListValue> Create(const std::string& tree_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tree_id));

  return create_results;
}

}  // namespace OnChildTreeID

namespace OnNodesRemoved {

const char kEventName[] = "automationInternal.onNodesRemoved";

std::unique_ptr<base::ListValue> Create(const std::string& tree_id, const std::vector<int>& node_i_ds) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tree_id));

  create_results->Append(json_schema_compiler::util::CreateValueFromArray(node_i_ds));

  return create_results;
}

}  // namespace OnNodesRemoved

namespace OnAccessibilityTreeSerializationError {

const char kEventName[] = "automationInternal.onAccessibilityTreeSerializationError";

std::unique_ptr<base::ListValue> Create(const std::string& tree_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tree_id));

  return create_results;
}

}  // namespace OnAccessibilityTreeSerializationError

namespace OnActionResult {

const char kEventName[] = "automationInternal.onActionResult";

std::unique_ptr<base::ListValue> Create(const std::string& tree_id, int request_id, bool result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tree_id));

  create_results->Append(std::make_unique<base::Value>(request_id));

  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}

}  // namespace OnActionResult

}  // namespace automation_internal
}  // namespace api
}  // namespace extensions

