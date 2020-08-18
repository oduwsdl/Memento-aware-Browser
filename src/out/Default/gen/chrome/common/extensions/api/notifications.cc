// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/notifications.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/notifications.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace notifications {
//
// Types
//

const char* ToString(TemplateType enum_param) {
  switch (enum_param) {
    case TEMPLATE_TYPE_BASIC:
      return "basic";
    case TEMPLATE_TYPE_IMAGE:
      return "image";
    case TEMPLATE_TYPE_LIST:
      return "list";
    case TEMPLATE_TYPE_PROGRESS:
      return "progress";
    case TEMPLATE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

TemplateType ParseTemplateType(const std::string& enum_string) {
  if (enum_string == "basic")
    return TEMPLATE_TYPE_BASIC;
  if (enum_string == "image")
    return TEMPLATE_TYPE_IMAGE;
  if (enum_string == "list")
    return TEMPLATE_TYPE_LIST;
  if (enum_string == "progress")
    return TEMPLATE_TYPE_PROGRESS;
  return TEMPLATE_TYPE_NONE;
}


const char* ToString(PermissionLevel enum_param) {
  switch (enum_param) {
    case PERMISSION_LEVEL_GRANTED:
      return "granted";
    case PERMISSION_LEVEL_DENIED:
      return "denied";
    case PERMISSION_LEVEL_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PermissionLevel ParsePermissionLevel(const std::string& enum_string) {
  if (enum_string == "granted")
    return PERMISSION_LEVEL_GRANTED;
  if (enum_string == "denied")
    return PERMISSION_LEVEL_DENIED;
  return PERMISSION_LEVEL_NONE;
}


NotificationItem::NotificationItem()
 {}

NotificationItem::~NotificationItem() {}
NotificationItem::NotificationItem(NotificationItem&& rhs)
: title(std::move(rhs.title)),
message(std::move(rhs.message)){
}

NotificationItem& NotificationItem::operator=(NotificationItem&& rhs)
{
title = std::move(rhs.title);
message = std::move(rhs.message);
return *this;
}

// static
bool NotificationItem::Populate(
    const base::Value& value, NotificationItem* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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
std::unique_ptr<NotificationItem> NotificationItem::FromValue(const base::Value& value) {
  std::unique_ptr<NotificationItem> out(new NotificationItem());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NotificationItem::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  to_value_result->SetWithoutPathExpansion("message", std::make_unique<base::Value>(this->message));


  return to_value_result;
}


NotificationBitmap::NotificationBitmap()
: width(0),
height(0) {}

NotificationBitmap::~NotificationBitmap() {}
NotificationBitmap::NotificationBitmap(NotificationBitmap&& rhs)
: width(rhs.width),
height(rhs.height),
data(std::move(rhs.data)){
}

NotificationBitmap& NotificationBitmap::operator=(NotificationBitmap&& rhs)
{
width = rhs.width;
height = rhs.height;
data = std::move(rhs.data);
return *this;
}

// static
bool NotificationBitmap::Populate(
    const base::Value& value, NotificationBitmap* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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

  const base::Value* data_value = NULL;
  if (dict->GetWithoutPathExpansion("data", &data_value)) {
    {
      if (!data_value->is_blob()) {
        return false;
      }
      else {
        out->data.reset(new std::vector<uint8_t>(data_value->GetBlob()));
      }
    }
  }

  return true;
}

// static
std::unique_ptr<NotificationBitmap> NotificationBitmap::FromValue(const base::Value& value) {
  std::unique_ptr<NotificationBitmap> out(new NotificationBitmap());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NotificationBitmap::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(this->width));

  to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(this->height));

  if (this->data.get()) {
    to_value_result->SetWithoutPathExpansion("data", std::make_unique<base::Value>(*this->data));

  }

  return to_value_result;
}


NotificationButton::NotificationButton()
 {}

NotificationButton::~NotificationButton() {}
NotificationButton::NotificationButton(NotificationButton&& rhs)
: title(std::move(rhs.title)),
icon_url(std::move(rhs.icon_url)),
icon_bitmap(std::move(rhs.icon_bitmap)){
}

NotificationButton& NotificationButton::operator=(NotificationButton&& rhs)
{
title = std::move(rhs.title);
icon_url = std::move(rhs.icon_url);
icon_bitmap = std::move(rhs.icon_bitmap);
return *this;
}

// static
bool NotificationButton::Populate(
    const base::Value& value, NotificationButton* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* title_value = NULL;
  if (!dict->GetWithoutPathExpansion("title", &title_value)) {
    return false;
  }
  {
    if (!title_value->GetAsString(&out->title)) {
      return false;
    }
  }

  const base::Value* icon_url_value = NULL;
  if (dict->GetWithoutPathExpansion("iconUrl", &icon_url_value)) {
    {
      std::string temp;
      if (!icon_url_value->GetAsString(&temp)) {
        out->icon_url.reset();
        return false;
      }
      else
        out->icon_url.reset(new std::string(temp));
    }
  }

  const base::Value* icon_bitmap_value = NULL;
  if (dict->GetWithoutPathExpansion("iconBitmap", &icon_bitmap_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!icon_bitmap_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<NotificationBitmap> temp(new NotificationBitmap());
        if (!NotificationBitmap::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->icon_bitmap = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<NotificationButton> NotificationButton::FromValue(const base::Value& value) {
  std::unique_ptr<NotificationButton> out(new NotificationButton());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NotificationButton::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  if (this->icon_url.get()) {
    to_value_result->SetWithoutPathExpansion("iconUrl", std::make_unique<base::Value>(*this->icon_url));

  }
  if (this->icon_bitmap.get()) {
    to_value_result->SetWithoutPathExpansion("iconBitmap", (this->icon_bitmap)->ToValue());

  }

  return to_value_result;
}


NotificationOptions::NotificationOptions()
: type(TEMPLATE_TYPE_NONE) {}

NotificationOptions::~NotificationOptions() {}
NotificationOptions::NotificationOptions(NotificationOptions&& rhs)
: type(rhs.type),
icon_url(std::move(rhs.icon_url)),
icon_bitmap(std::move(rhs.icon_bitmap)),
app_icon_mask_url(std::move(rhs.app_icon_mask_url)),
app_icon_mask_bitmap(std::move(rhs.app_icon_mask_bitmap)),
title(std::move(rhs.title)),
message(std::move(rhs.message)),
context_message(std::move(rhs.context_message)),
priority(std::move(rhs.priority)),
event_time(std::move(rhs.event_time)),
buttons(std::move(rhs.buttons)),
expanded_message(std::move(rhs.expanded_message)),
image_url(std::move(rhs.image_url)),
image_bitmap(std::move(rhs.image_bitmap)),
items(std::move(rhs.items)),
progress(std::move(rhs.progress)),
is_clickable(std::move(rhs.is_clickable)),
require_interaction(std::move(rhs.require_interaction)),
silent(std::move(rhs.silent)){
}

NotificationOptions& NotificationOptions::operator=(NotificationOptions&& rhs)
{
type = rhs.type;
icon_url = std::move(rhs.icon_url);
icon_bitmap = std::move(rhs.icon_bitmap);
app_icon_mask_url = std::move(rhs.app_icon_mask_url);
app_icon_mask_bitmap = std::move(rhs.app_icon_mask_bitmap);
title = std::move(rhs.title);
message = std::move(rhs.message);
context_message = std::move(rhs.context_message);
priority = std::move(rhs.priority);
event_time = std::move(rhs.event_time);
buttons = std::move(rhs.buttons);
expanded_message = std::move(rhs.expanded_message);
image_url = std::move(rhs.image_url);
image_bitmap = std::move(rhs.image_bitmap);
items = std::move(rhs.items);
progress = std::move(rhs.progress);
is_clickable = std::move(rhs.is_clickable);
require_interaction = std::move(rhs.require_interaction);
silent = std::move(rhs.silent);
return *this;
}

// static
bool NotificationOptions::Populate(
    const base::Value& value, NotificationOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->type = TEMPLATE_TYPE_NONE;
  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string template_type_as_string;
      if (!type_value->GetAsString(&template_type_as_string)) {
        return false;
      }
      out->type = ParseTemplateType(template_type_as_string);
      if (out->type == TEMPLATE_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = TEMPLATE_TYPE_NONE;
  }

  const base::Value* icon_url_value = NULL;
  if (dict->GetWithoutPathExpansion("iconUrl", &icon_url_value)) {
    {
      std::string temp;
      if (!icon_url_value->GetAsString(&temp)) {
        out->icon_url.reset();
        return false;
      }
      else
        out->icon_url.reset(new std::string(temp));
    }
  }

  const base::Value* icon_bitmap_value = NULL;
  if (dict->GetWithoutPathExpansion("iconBitmap", &icon_bitmap_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!icon_bitmap_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<NotificationBitmap> temp(new NotificationBitmap());
        if (!NotificationBitmap::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->icon_bitmap = std::move(temp);
      }
    }
  }

  const base::Value* app_icon_mask_url_value = NULL;
  if (dict->GetWithoutPathExpansion("appIconMaskUrl", &app_icon_mask_url_value)) {
    {
      std::string temp;
      if (!app_icon_mask_url_value->GetAsString(&temp)) {
        out->app_icon_mask_url.reset();
        return false;
      }
      else
        out->app_icon_mask_url.reset(new std::string(temp));
    }
  }

  const base::Value* app_icon_mask_bitmap_value = NULL;
  if (dict->GetWithoutPathExpansion("appIconMaskBitmap", &app_icon_mask_bitmap_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!app_icon_mask_bitmap_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<NotificationBitmap> temp(new NotificationBitmap());
        if (!NotificationBitmap::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->app_icon_mask_bitmap = std::move(temp);
      }
    }
  }

  const base::Value* title_value = NULL;
  if (dict->GetWithoutPathExpansion("title", &title_value)) {
    {
      std::string temp;
      if (!title_value->GetAsString(&temp)) {
        out->title.reset();
        return false;
      }
      else
        out->title.reset(new std::string(temp));
    }
  }

  const base::Value* message_value = NULL;
  if (dict->GetWithoutPathExpansion("message", &message_value)) {
    {
      std::string temp;
      if (!message_value->GetAsString(&temp)) {
        out->message.reset();
        return false;
      }
      else
        out->message.reset(new std::string(temp));
    }
  }

  const base::Value* context_message_value = NULL;
  if (dict->GetWithoutPathExpansion("contextMessage", &context_message_value)) {
    {
      std::string temp;
      if (!context_message_value->GetAsString(&temp)) {
        out->context_message.reset();
        return false;
      }
      else
        out->context_message.reset(new std::string(temp));
    }
  }

  const base::Value* priority_value = NULL;
  if (dict->GetWithoutPathExpansion("priority", &priority_value)) {
    {
      int temp;
      if (!priority_value->GetAsInteger(&temp)) {
        out->priority.reset();
        return false;
      }
      else
        out->priority.reset(new int(temp));
    }
  }

  const base::Value* event_time_value = NULL;
  if (dict->GetWithoutPathExpansion("eventTime", &event_time_value)) {
    {
      double temp;
      if (!event_time_value->GetAsDouble(&temp)) {
        out->event_time.reset();
        return false;
      }
      else
        out->event_time.reset(new double(temp));
    }
  }

  const base::Value* buttons_value = NULL;
  if (dict->GetWithoutPathExpansion("buttons", &buttons_value)) {
    {
      const base::ListValue* list = NULL;
      if (!buttons_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->buttons)) {
          return false;
        }
      }
    }
  }

  const base::Value* expanded_message_value = NULL;
  if (dict->GetWithoutPathExpansion("expandedMessage", &expanded_message_value)) {
    {
      std::string temp;
      if (!expanded_message_value->GetAsString(&temp)) {
        out->expanded_message.reset();
        return false;
      }
      else
        out->expanded_message.reset(new std::string(temp));
    }
  }

  const base::Value* image_url_value = NULL;
  if (dict->GetWithoutPathExpansion("imageUrl", &image_url_value)) {
    {
      std::string temp;
      if (!image_url_value->GetAsString(&temp)) {
        out->image_url.reset();
        return false;
      }
      else
        out->image_url.reset(new std::string(temp));
    }
  }

  const base::Value* image_bitmap_value = NULL;
  if (dict->GetWithoutPathExpansion("imageBitmap", &image_bitmap_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!image_bitmap_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<NotificationBitmap> temp(new NotificationBitmap());
        if (!NotificationBitmap::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->image_bitmap = std::move(temp);
      }
    }
  }

  const base::Value* items_value = NULL;
  if (dict->GetWithoutPathExpansion("items", &items_value)) {
    {
      const base::ListValue* list = NULL;
      if (!items_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->items)) {
          return false;
        }
      }
    }
  }

  const base::Value* progress_value = NULL;
  if (dict->GetWithoutPathExpansion("progress", &progress_value)) {
    {
      int temp;
      if (!progress_value->GetAsInteger(&temp)) {
        out->progress.reset();
        return false;
      }
      else
        out->progress.reset(new int(temp));
    }
  }

  const base::Value* is_clickable_value = NULL;
  if (dict->GetWithoutPathExpansion("isClickable", &is_clickable_value)) {
    {
      bool temp;
      if (!is_clickable_value->GetAsBoolean(&temp)) {
        out->is_clickable.reset();
        return false;
      }
      else
        out->is_clickable.reset(new bool(temp));
    }
  }

  const base::Value* require_interaction_value = NULL;
  if (dict->GetWithoutPathExpansion("requireInteraction", &require_interaction_value)) {
    {
      bool temp;
      if (!require_interaction_value->GetAsBoolean(&temp)) {
        out->require_interaction.reset();
        return false;
      }
      else
        out->require_interaction.reset(new bool(temp));
    }
  }

  const base::Value* silent_value = NULL;
  if (dict->GetWithoutPathExpansion("silent", &silent_value)) {
    {
      bool temp;
      if (!silent_value->GetAsBoolean(&temp)) {
        out->silent.reset();
        return false;
      }
      else
        out->silent.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<NotificationOptions> NotificationOptions::FromValue(const base::Value& value) {
  std::unique_ptr<NotificationOptions> out(new NotificationOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NotificationOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->type != TEMPLATE_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(notifications::ToString(this->type)));

  }
  if (this->icon_url.get()) {
    to_value_result->SetWithoutPathExpansion("iconUrl", std::make_unique<base::Value>(*this->icon_url));

  }
  if (this->icon_bitmap.get()) {
    to_value_result->SetWithoutPathExpansion("iconBitmap", (this->icon_bitmap)->ToValue());

  }
  if (this->app_icon_mask_url.get()) {
    to_value_result->SetWithoutPathExpansion("appIconMaskUrl", std::make_unique<base::Value>(*this->app_icon_mask_url));

  }
  if (this->app_icon_mask_bitmap.get()) {
    to_value_result->SetWithoutPathExpansion("appIconMaskBitmap", (this->app_icon_mask_bitmap)->ToValue());

  }
  if (this->title.get()) {
    to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(*this->title));

  }
  if (this->message.get()) {
    to_value_result->SetWithoutPathExpansion("message", std::make_unique<base::Value>(*this->message));

  }
  if (this->context_message.get()) {
    to_value_result->SetWithoutPathExpansion("contextMessage", std::make_unique<base::Value>(*this->context_message));

  }
  if (this->priority.get()) {
    to_value_result->SetWithoutPathExpansion("priority", std::make_unique<base::Value>(*this->priority));

  }
  if (this->event_time.get()) {
    to_value_result->SetWithoutPathExpansion("eventTime", std::make_unique<base::Value>(*this->event_time));

  }
  if (this->buttons.get()) {
    to_value_result->SetWithoutPathExpansion("buttons", json_schema_compiler::util::CreateValueFromOptionalArray(this->buttons));

  }
  if (this->expanded_message.get()) {
    to_value_result->SetWithoutPathExpansion("expandedMessage", std::make_unique<base::Value>(*this->expanded_message));

  }
  if (this->image_url.get()) {
    to_value_result->SetWithoutPathExpansion("imageUrl", std::make_unique<base::Value>(*this->image_url));

  }
  if (this->image_bitmap.get()) {
    to_value_result->SetWithoutPathExpansion("imageBitmap", (this->image_bitmap)->ToValue());

  }
  if (this->items.get()) {
    to_value_result->SetWithoutPathExpansion("items", json_schema_compiler::util::CreateValueFromOptionalArray(this->items));

  }
  if (this->progress.get()) {
    to_value_result->SetWithoutPathExpansion("progress", std::make_unique<base::Value>(*this->progress));

  }
  if (this->is_clickable.get()) {
    to_value_result->SetWithoutPathExpansion("isClickable", std::make_unique<base::Value>(*this->is_clickable));

  }
  if (this->require_interaction.get()) {
    to_value_result->SetWithoutPathExpansion("requireInteraction", std::make_unique<base::Value>(*this->require_interaction));

  }
  if (this->silent.get()) {
    to_value_result->SetWithoutPathExpansion("silent", std::make_unique<base::Value>(*this->silent));

  }

  return to_value_result;
}



//
// Functions
//

namespace Create {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* notification_id_value = NULL;
  if (args.Get(0, &notification_id_value) &&
      !notification_id_value->is_none()) {
    {
      std::string temp;
      if (!notification_id_value->GetAsString(&temp)) {
        params->notification_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->notification_id.reset(new std::string(temp));
    }
  }

  const base::Value* options_value = NULL;
  if (args.Get(1, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!NotificationOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& notification_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(notification_id));

  return create_results;
}
}  // namespace Create

namespace Update {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* notification_id_value = NULL;
  if (args.Get(0, &notification_id_value) &&
      !notification_id_value->is_none()) {
    {
      if (!notification_id_value->GetAsString(&params->notification_id)) {
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
      if (!NotificationOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool was_updated) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(was_updated));

  return create_results;
}
}  // namespace Update

namespace Clear {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* notification_id_value = NULL;
  if (args.Get(0, &notification_id_value) &&
      !notification_id_value->is_none()) {
    {
      if (!notification_id_value->GetAsString(&params->notification_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool was_cleared) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(was_cleared));

  return create_results;
}
}  // namespace Clear

namespace GetAll {

Results::Notifications::Notifications()
 {}

Results::Notifications::~Notifications() {}
Results::Notifications::Notifications(Notifications&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::Notifications& Results::Notifications::operator=(Notifications&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Notifications::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Notifications& notifications) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((notifications).ToValue());

  return create_results;
}
}  // namespace GetAll

namespace GetPermissionLevel {

std::unique_ptr<base::ListValue> Results::Create(const PermissionLevel& level) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(notifications::ToString(level)));

  return create_results;
}
}  // namespace GetPermissionLevel

//
// Events
//

namespace OnClosed {

const char kEventName[] = "notifications.onClosed";

std::unique_ptr<base::ListValue> Create(const std::string& notification_id, bool by_user) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(notification_id));

  create_results->Append(std::make_unique<base::Value>(by_user));

  return create_results;
}

}  // namespace OnClosed

namespace OnClicked {

const char kEventName[] = "notifications.onClicked";

std::unique_ptr<base::ListValue> Create(const std::string& notification_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(notification_id));

  return create_results;
}

}  // namespace OnClicked

namespace OnButtonClicked {

const char kEventName[] = "notifications.onButtonClicked";

std::unique_ptr<base::ListValue> Create(const std::string& notification_id, int button_index) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(notification_id));

  create_results->Append(std::make_unique<base::Value>(button_index));

  return create_results;
}

}  // namespace OnButtonClicked

namespace OnPermissionLevelChanged {

const char kEventName[] = "notifications.onPermissionLevelChanged";

std::unique_ptr<base::ListValue> Create(const PermissionLevel& level) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(notifications::ToString(level)));

  return create_results;
}

}  // namespace OnPermissionLevelChanged

namespace OnShowSettings {

const char kEventName[] = "notifications.onShowSettings";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnShowSettings

}  // namespace notifications
}  // namespace api
}  // namespace extensions

