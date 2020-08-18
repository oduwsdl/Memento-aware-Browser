// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/hid.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/hid.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace hid {
//
// Types
//

HidCollectionInfo::HidCollectionInfo()
: usage_page(0),
usage(0) {}

HidCollectionInfo::~HidCollectionInfo() {}
HidCollectionInfo::HidCollectionInfo(HidCollectionInfo&& rhs)
: usage_page(rhs.usage_page),
usage(rhs.usage),
report_ids(std::move(rhs.report_ids)){
}

HidCollectionInfo& HidCollectionInfo::operator=(HidCollectionInfo&& rhs)
{
usage_page = rhs.usage_page;
usage = rhs.usage;
report_ids = std::move(rhs.report_ids);
return *this;
}

// static
bool HidCollectionInfo::Populate(
    const base::Value& value, HidCollectionInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* usage_page_value = NULL;
  if (!dict->GetWithoutPathExpansion("usagePage", &usage_page_value)) {
    return false;
  }
  {
    if (!usage_page_value->GetAsInteger(&out->usage_page)) {
      return false;
    }
  }

  const base::Value* usage_value = NULL;
  if (!dict->GetWithoutPathExpansion("usage", &usage_value)) {
    return false;
  }
  {
    if (!usage_value->GetAsInteger(&out->usage)) {
      return false;
    }
  }

  const base::Value* report_ids_value = NULL;
  if (!dict->GetWithoutPathExpansion("reportIds", &report_ids_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!report_ids_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->report_ids)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<HidCollectionInfo> HidCollectionInfo::FromValue(const base::Value& value) {
  std::unique_ptr<HidCollectionInfo> out(new HidCollectionInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> HidCollectionInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("usagePage", std::make_unique<base::Value>(this->usage_page));

  to_value_result->SetWithoutPathExpansion("usage", std::make_unique<base::Value>(this->usage));

  to_value_result->SetWithoutPathExpansion("reportIds", json_schema_compiler::util::CreateValueFromArray(this->report_ids));


  return to_value_result;
}


HidDeviceInfo::HidDeviceInfo()
: device_id(0),
vendor_id(0),
product_id(0),
max_input_report_size(0),
max_output_report_size(0),
max_feature_report_size(0) {}

HidDeviceInfo::~HidDeviceInfo() {}
HidDeviceInfo::HidDeviceInfo(HidDeviceInfo&& rhs)
: device_id(rhs.device_id),
vendor_id(rhs.vendor_id),
product_id(rhs.product_id),
product_name(std::move(rhs.product_name)),
serial_number(std::move(rhs.serial_number)),
collections(std::move(rhs.collections)),
max_input_report_size(rhs.max_input_report_size),
max_output_report_size(rhs.max_output_report_size),
max_feature_report_size(rhs.max_feature_report_size),
report_descriptor(std::move(rhs.report_descriptor)){
}

HidDeviceInfo& HidDeviceInfo::operator=(HidDeviceInfo&& rhs)
{
device_id = rhs.device_id;
vendor_id = rhs.vendor_id;
product_id = rhs.product_id;
product_name = std::move(rhs.product_name);
serial_number = std::move(rhs.serial_number);
collections = std::move(rhs.collections);
max_input_report_size = rhs.max_input_report_size;
max_output_report_size = rhs.max_output_report_size;
max_feature_report_size = rhs.max_feature_report_size;
report_descriptor = std::move(rhs.report_descriptor);
return *this;
}

// static
bool HidDeviceInfo::Populate(
    const base::Value& value, HidDeviceInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* device_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("deviceId", &device_id_value)) {
    return false;
  }
  {
    if (!device_id_value->GetAsInteger(&out->device_id)) {
      return false;
    }
  }

  const base::Value* vendor_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("vendorId", &vendor_id_value)) {
    return false;
  }
  {
    if (!vendor_id_value->GetAsInteger(&out->vendor_id)) {
      return false;
    }
  }

  const base::Value* product_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("productId", &product_id_value)) {
    return false;
  }
  {
    if (!product_id_value->GetAsInteger(&out->product_id)) {
      return false;
    }
  }

  const base::Value* product_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("productName", &product_name_value)) {
    return false;
  }
  {
    if (!product_name_value->GetAsString(&out->product_name)) {
      return false;
    }
  }

  const base::Value* serial_number_value = NULL;
  if (!dict->GetWithoutPathExpansion("serialNumber", &serial_number_value)) {
    return false;
  }
  {
    if (!serial_number_value->GetAsString(&out->serial_number)) {
      return false;
    }
  }

  const base::Value* collections_value = NULL;
  if (!dict->GetWithoutPathExpansion("collections", &collections_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!collections_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->collections)) {
        return false;
      }
    }
  }

  const base::Value* max_input_report_size_value = NULL;
  if (!dict->GetWithoutPathExpansion("maxInputReportSize", &max_input_report_size_value)) {
    return false;
  }
  {
    if (!max_input_report_size_value->GetAsInteger(&out->max_input_report_size)) {
      return false;
    }
  }

  const base::Value* max_output_report_size_value = NULL;
  if (!dict->GetWithoutPathExpansion("maxOutputReportSize", &max_output_report_size_value)) {
    return false;
  }
  {
    if (!max_output_report_size_value->GetAsInteger(&out->max_output_report_size)) {
      return false;
    }
  }

  const base::Value* max_feature_report_size_value = NULL;
  if (!dict->GetWithoutPathExpansion("maxFeatureReportSize", &max_feature_report_size_value)) {
    return false;
  }
  {
    if (!max_feature_report_size_value->GetAsInteger(&out->max_feature_report_size)) {
      return false;
    }
  }

  const base::Value* report_descriptor_value = NULL;
  if (!dict->GetWithoutPathExpansion("reportDescriptor", &report_descriptor_value)) {
    return false;
  }
  {
    if (!report_descriptor_value->is_blob()) {
      return false;
    }
    else {
      out->report_descriptor = report_descriptor_value->GetBlob();
    }
  }

  return true;
}

// static
std::unique_ptr<HidDeviceInfo> HidDeviceInfo::FromValue(const base::Value& value) {
  std::unique_ptr<HidDeviceInfo> out(new HidDeviceInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> HidDeviceInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("deviceId", std::make_unique<base::Value>(this->device_id));

  to_value_result->SetWithoutPathExpansion("vendorId", std::make_unique<base::Value>(this->vendor_id));

  to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(this->product_id));

  to_value_result->SetWithoutPathExpansion("productName", std::make_unique<base::Value>(this->product_name));

  to_value_result->SetWithoutPathExpansion("serialNumber", std::make_unique<base::Value>(this->serial_number));

  to_value_result->SetWithoutPathExpansion("collections", json_schema_compiler::util::CreateValueFromArray(this->collections));

  to_value_result->SetWithoutPathExpansion("maxInputReportSize", std::make_unique<base::Value>(this->max_input_report_size));

  to_value_result->SetWithoutPathExpansion("maxOutputReportSize", std::make_unique<base::Value>(this->max_output_report_size));

  to_value_result->SetWithoutPathExpansion("maxFeatureReportSize", std::make_unique<base::Value>(this->max_feature_report_size));

  to_value_result->SetWithoutPathExpansion("reportDescriptor", std::make_unique<base::Value>(this->report_descriptor));


  return to_value_result;
}


HidConnectInfo::HidConnectInfo()
: connection_id(0) {}

HidConnectInfo::~HidConnectInfo() {}
HidConnectInfo::HidConnectInfo(HidConnectInfo&& rhs)
: connection_id(rhs.connection_id){
}

HidConnectInfo& HidConnectInfo::operator=(HidConnectInfo&& rhs)
{
connection_id = rhs.connection_id;
return *this;
}

// static
bool HidConnectInfo::Populate(
    const base::Value& value, HidConnectInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* connection_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("connectionId", &connection_id_value)) {
    return false;
  }
  {
    if (!connection_id_value->GetAsInteger(&out->connection_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<HidConnectInfo> HidConnectInfo::FromValue(const base::Value& value) {
  std::unique_ptr<HidConnectInfo> out(new HidConnectInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> HidConnectInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("connectionId", std::make_unique<base::Value>(this->connection_id));


  return to_value_result;
}


DeviceFilter::DeviceFilter()
 {}

DeviceFilter::~DeviceFilter() {}
DeviceFilter::DeviceFilter(DeviceFilter&& rhs)
: vendor_id(std::move(rhs.vendor_id)),
product_id(std::move(rhs.product_id)),
usage_page(std::move(rhs.usage_page)),
usage(std::move(rhs.usage)){
}

DeviceFilter& DeviceFilter::operator=(DeviceFilter&& rhs)
{
vendor_id = std::move(rhs.vendor_id);
product_id = std::move(rhs.product_id);
usage_page = std::move(rhs.usage_page);
usage = std::move(rhs.usage);
return *this;
}

// static
bool DeviceFilter::Populate(
    const base::Value& value, DeviceFilter* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* vendor_id_value = NULL;
  if (dict->GetWithoutPathExpansion("vendorId", &vendor_id_value)) {
    {
      int temp;
      if (!vendor_id_value->GetAsInteger(&temp)) {
        out->vendor_id.reset();
        return false;
      }
      else
        out->vendor_id.reset(new int(temp));
    }
  }

  const base::Value* product_id_value = NULL;
  if (dict->GetWithoutPathExpansion("productId", &product_id_value)) {
    {
      int temp;
      if (!product_id_value->GetAsInteger(&temp)) {
        out->product_id.reset();
        return false;
      }
      else
        out->product_id.reset(new int(temp));
    }
  }

  const base::Value* usage_page_value = NULL;
  if (dict->GetWithoutPathExpansion("usagePage", &usage_page_value)) {
    {
      int temp;
      if (!usage_page_value->GetAsInteger(&temp)) {
        out->usage_page.reset();
        return false;
      }
      else
        out->usage_page.reset(new int(temp));
    }
  }

  const base::Value* usage_value = NULL;
  if (dict->GetWithoutPathExpansion("usage", &usage_value)) {
    {
      int temp;
      if (!usage_value->GetAsInteger(&temp)) {
        out->usage.reset();
        return false;
      }
      else
        out->usage.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DeviceFilter> DeviceFilter::FromValue(const base::Value& value) {
  std::unique_ptr<DeviceFilter> out(new DeviceFilter());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DeviceFilter::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->vendor_id.get()) {
    to_value_result->SetWithoutPathExpansion("vendorId", std::make_unique<base::Value>(*this->vendor_id));

  }
  if (this->product_id.get()) {
    to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(*this->product_id));

  }
  if (this->usage_page.get()) {
    to_value_result->SetWithoutPathExpansion("usagePage", std::make_unique<base::Value>(*this->usage_page));

  }
  if (this->usage.get()) {
    to_value_result->SetWithoutPathExpansion("usage", std::make_unique<base::Value>(*this->usage));

  }

  return to_value_result;
}


GetDevicesOptions::GetDevicesOptions()
 {}

GetDevicesOptions::~GetDevicesOptions() {}
GetDevicesOptions::GetDevicesOptions(GetDevicesOptions&& rhs)
: vendor_id(std::move(rhs.vendor_id)),
product_id(std::move(rhs.product_id)),
filters(std::move(rhs.filters)){
}

GetDevicesOptions& GetDevicesOptions::operator=(GetDevicesOptions&& rhs)
{
vendor_id = std::move(rhs.vendor_id);
product_id = std::move(rhs.product_id);
filters = std::move(rhs.filters);
return *this;
}

// static
bool GetDevicesOptions::Populate(
    const base::Value& value, GetDevicesOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* vendor_id_value = NULL;
  if (dict->GetWithoutPathExpansion("vendorId", &vendor_id_value)) {
    {
      int temp;
      if (!vendor_id_value->GetAsInteger(&temp)) {
        out->vendor_id.reset();
        return false;
      }
      else
        out->vendor_id.reset(new int(temp));
    }
  }

  const base::Value* product_id_value = NULL;
  if (dict->GetWithoutPathExpansion("productId", &product_id_value)) {
    {
      int temp;
      if (!product_id_value->GetAsInteger(&temp)) {
        out->product_id.reset();
        return false;
      }
      else
        out->product_id.reset(new int(temp));
    }
  }

  const base::Value* filters_value = NULL;
  if (dict->GetWithoutPathExpansion("filters", &filters_value)) {
    {
      const base::ListValue* list = NULL;
      if (!filters_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->filters)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<GetDevicesOptions> GetDevicesOptions::FromValue(const base::Value& value) {
  std::unique_ptr<GetDevicesOptions> out(new GetDevicesOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> GetDevicesOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->vendor_id.get()) {
    to_value_result->SetWithoutPathExpansion("vendorId", std::make_unique<base::Value>(*this->vendor_id));

  }
  if (this->product_id.get()) {
    to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(*this->product_id));

  }
  if (this->filters.get()) {
    to_value_result->SetWithoutPathExpansion("filters", json_schema_compiler::util::CreateValueFromOptionalArray(this->filters));

  }

  return to_value_result;
}


DevicePromptOptions::DevicePromptOptions()
 {}

DevicePromptOptions::~DevicePromptOptions() {}
DevicePromptOptions::DevicePromptOptions(DevicePromptOptions&& rhs)
: multiple(std::move(rhs.multiple)),
filters(std::move(rhs.filters)){
}

DevicePromptOptions& DevicePromptOptions::operator=(DevicePromptOptions&& rhs)
{
multiple = std::move(rhs.multiple);
filters = std::move(rhs.filters);
return *this;
}

// static
bool DevicePromptOptions::Populate(
    const base::Value& value, DevicePromptOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* multiple_value = NULL;
  if (dict->GetWithoutPathExpansion("multiple", &multiple_value)) {
    {
      bool temp;
      if (!multiple_value->GetAsBoolean(&temp)) {
        out->multiple.reset();
        return false;
      }
      else
        out->multiple.reset(new bool(temp));
    }
  }

  const base::Value* filters_value = NULL;
  if (dict->GetWithoutPathExpansion("filters", &filters_value)) {
    {
      const base::ListValue* list = NULL;
      if (!filters_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->filters)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<DevicePromptOptions> DevicePromptOptions::FromValue(const base::Value& value) {
  std::unique_ptr<DevicePromptOptions> out(new DevicePromptOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DevicePromptOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->multiple.get()) {
    to_value_result->SetWithoutPathExpansion("multiple", std::make_unique<base::Value>(*this->multiple));

  }
  if (this->filters.get()) {
    to_value_result->SetWithoutPathExpansion("filters", json_schema_compiler::util::CreateValueFromOptionalArray(this->filters));

  }

  return to_value_result;
}



//
// Functions
//

namespace GetDevices {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
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
      if (!GetDevicesOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<HidDeviceInfo>& devices) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(devices));

  return create_results;
}
}  // namespace GetDevices

namespace GetUserSelectedDevices {

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
        std::unique_ptr<DevicePromptOptions> temp(new DevicePromptOptions());
        if (!DevicePromptOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<HidDeviceInfo>& devices) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(devices));

  return create_results;
}
}  // namespace GetUserSelectedDevices

namespace Connect {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* device_id_value = NULL;
  if (args.Get(0, &device_id_value) &&
      !device_id_value->is_none()) {
    {
      if (!device_id_value->GetAsInteger(&params->device_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const HidConnectInfo& connection) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((connection).ToValue());

  return create_results;
}
}  // namespace Connect

namespace Disconnect {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
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
}  // namespace Disconnect

namespace Receive {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int report_id, const std::vector<uint8_t>& data) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(report_id));

  create_results->Append(std::make_unique<base::Value>(data));

  return create_results;
}
}  // namespace Receive

namespace Send {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* report_id_value = NULL;
  if (args.Get(1, &report_id_value) &&
      !report_id_value->is_none()) {
    {
      if (!report_id_value->GetAsInteger(&params->report_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* data_value = NULL;
  if (args.Get(2, &data_value) &&
      !data_value->is_none()) {
    {
      if (!data_value->is_blob()) {
        return std::unique_ptr<Params>();
      }
      else {
        params->data = data_value->GetBlob();
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
}  // namespace Send

namespace ReceiveFeatureReport {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* report_id_value = NULL;
  if (args.Get(1, &report_id_value) &&
      !report_id_value->is_none()) {
    {
      if (!report_id_value->GetAsInteger(&params->report_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<uint8_t>& data) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(data));

  return create_results;
}
}  // namespace ReceiveFeatureReport

namespace SendFeatureReport {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* report_id_value = NULL;
  if (args.Get(1, &report_id_value) &&
      !report_id_value->is_none()) {
    {
      if (!report_id_value->GetAsInteger(&params->report_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* data_value = NULL;
  if (args.Get(2, &data_value) &&
      !data_value->is_none()) {
    {
      if (!data_value->is_blob()) {
        return std::unique_ptr<Params>();
      }
      else {
        params->data = data_value->GetBlob();
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
}  // namespace SendFeatureReport

//
// Events
//

namespace OnDeviceAdded {

const char kEventName[] = "hid.onDeviceAdded";

std::unique_ptr<base::ListValue> Create(const HidDeviceInfo& device) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device).ToValue());

  return create_results;
}

}  // namespace OnDeviceAdded

namespace OnDeviceRemoved {

const char kEventName[] = "hid.onDeviceRemoved";

std::unique_ptr<base::ListValue> Create(int device_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(device_id));

  return create_results;
}

}  // namespace OnDeviceRemoved

}  // namespace hid
}  // namespace api
}  // namespace extensions

