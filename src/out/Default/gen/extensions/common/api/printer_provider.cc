// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/printer_provider.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/printer_provider.h"
#include <set>
#include <utility>
#include "extensions/common/api/usb.h"


using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace printer_provider {
//
// Types
//

const char* ToString(PrintError enum_param) {
  switch (enum_param) {
    case PRINT_ERROR_OK:
      return "OK";
    case PRINT_ERROR_FAILED:
      return "FAILED";
    case PRINT_ERROR_INVALID_TICKET:
      return "INVALID_TICKET";
    case PRINT_ERROR_INVALID_DATA:
      return "INVALID_DATA";
    case PRINT_ERROR_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PrintError ParsePrintError(const std::string& enum_string) {
  if (enum_string == "OK")
    return PRINT_ERROR_OK;
  if (enum_string == "FAILED")
    return PRINT_ERROR_FAILED;
  if (enum_string == "INVALID_TICKET")
    return PRINT_ERROR_INVALID_TICKET;
  if (enum_string == "INVALID_DATA")
    return PRINT_ERROR_INVALID_DATA;
  return PRINT_ERROR_NONE;
}


PrinterInfo::PrinterInfo()
 {}

PrinterInfo::~PrinterInfo() {}
PrinterInfo::PrinterInfo(PrinterInfo&& rhs)
: id(std::move(rhs.id)),
name(std::move(rhs.name)),
description(std::move(rhs.description)){
}

PrinterInfo& PrinterInfo::operator=(PrinterInfo&& rhs)
{
id = std::move(rhs.id);
name = std::move(rhs.name);
description = std::move(rhs.description);
return *this;
}

// static
bool PrinterInfo::Populate(
    const base::Value& value, PrinterInfo* out) {
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

  const base::Value* description_value = NULL;
  if (dict->GetWithoutPathExpansion("description", &description_value)) {
    {
      std::string temp;
      if (!description_value->GetAsString(&temp)) {
        out->description.reset();
        return false;
      }
      else
        out->description.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<PrinterInfo> PrinterInfo::FromValue(const base::Value& value) {
  std::unique_ptr<PrinterInfo> out(new PrinterInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PrinterInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  if (this->description.get()) {
    to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(*this->description));

  }

  return to_value_result;
}


PrintJob::Ticket::Ticket()
 {}

PrintJob::Ticket::~Ticket() {}
PrintJob::Ticket::Ticket(Ticket&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

PrintJob::Ticket& PrintJob::Ticket::operator=(Ticket&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool PrintJob::Ticket::Populate(
    const base::Value& value, Ticket* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> PrintJob::Ticket::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


PrintJob::Document::Document()
 {}

PrintJob::Document::~Document() {}
PrintJob::Document::Document(Document&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

PrintJob::Document& PrintJob::Document::operator=(Document&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool PrintJob::Document::Populate(
    const base::Value& value, Document* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> PrintJob::Document::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



PrintJob::PrintJob()
 {}

PrintJob::~PrintJob() {}
PrintJob::PrintJob(PrintJob&& rhs)
: printer_id(std::move(rhs.printer_id)),
title(std::move(rhs.title)),
ticket(std::move(rhs.ticket)),
content_type(std::move(rhs.content_type)),
document(std::move(rhs.document)){
}

PrintJob& PrintJob::operator=(PrintJob&& rhs)
{
printer_id = std::move(rhs.printer_id);
title = std::move(rhs.title);
ticket = std::move(rhs.ticket);
content_type = std::move(rhs.content_type);
document = std::move(rhs.document);
return *this;
}

// static
bool PrintJob::Populate(
    const base::Value& value, PrintJob* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* printer_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("printerId", &printer_id_value)) {
    return false;
  }
  {
    if (!printer_id_value->GetAsString(&out->printer_id)) {
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

  const base::Value* ticket_value = NULL;
  if (!dict->GetWithoutPathExpansion("ticket", &ticket_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!ticket_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Ticket::Populate(*dictionary, &out->ticket)) {
      return false;
    }
  }

  const base::Value* content_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("contentType", &content_type_value)) {
    return false;
  }
  {
    if (!content_type_value->GetAsString(&out->content_type)) {
      return false;
    }
  }

  const base::Value* document_value = NULL;
  if (!dict->GetWithoutPathExpansion("document", &document_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!document_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Document::Populate(*dictionary, &out->document)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<PrintJob> PrintJob::FromValue(const base::Value& value) {
  std::unique_ptr<PrintJob> out(new PrintJob());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PrintJob::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("printerId", std::make_unique<base::Value>(this->printer_id));

  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  to_value_result->SetWithoutPathExpansion("ticket", (this->ticket).ToValue());

  to_value_result->SetWithoutPathExpansion("contentType", std::make_unique<base::Value>(this->content_type));

  to_value_result->SetWithoutPathExpansion("document", (this->document).ToValue());


  return to_value_result;
}



//
// Events
//

namespace OnGetPrintersRequested {

const char kEventName[] = "printerProvider.onGetPrintersRequested";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnGetPrintersRequested

namespace OnGetUsbPrinterInfoRequested {

const char kEventName[] = "printerProvider.onGetUsbPrinterInfoRequested";

std::unique_ptr<base::ListValue> Create(const extensions::api::usb::Device& device) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device).ToValue());

  return create_results;
}

}  // namespace OnGetUsbPrinterInfoRequested

namespace OnGetCapabilityRequested {

const char kEventName[] = "printerProvider.onGetCapabilityRequested";

std::unique_ptr<base::ListValue> Create(const std::string& printer_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(printer_id));

  return create_results;
}

}  // namespace OnGetCapabilityRequested

namespace OnPrintRequested {

const char kEventName[] = "printerProvider.onPrintRequested";

std::unique_ptr<base::ListValue> Create(const PrintJob& print_job) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((print_job).ToValue());

  return create_results;
}

}  // namespace OnPrintRequested

}  // namespace printer_provider
}  // namespace api
}  // namespace extensions

