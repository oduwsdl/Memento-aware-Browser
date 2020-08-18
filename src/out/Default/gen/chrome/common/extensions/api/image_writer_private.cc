// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/image_writer_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/image_writer_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace image_writer_private {
//
// Types
//

const char* ToString(Stage enum_param) {
  switch (enum_param) {
    case STAGE_CONFIRMATION:
      return "confirmation";
    case STAGE_DOWNLOAD:
      return "download";
    case STAGE_VERIFYDOWNLOAD:
      return "verifyDownload";
    case STAGE_UNZIP:
      return "unzip";
    case STAGE_WRITE:
      return "write";
    case STAGE_VERIFYWRITE:
      return "verifyWrite";
    case STAGE_UNKNOWN:
      return "unknown";
    case STAGE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Stage ParseStage(const std::string& enum_string) {
  if (enum_string == "confirmation")
    return STAGE_CONFIRMATION;
  if (enum_string == "download")
    return STAGE_DOWNLOAD;
  if (enum_string == "verifyDownload")
    return STAGE_VERIFYDOWNLOAD;
  if (enum_string == "unzip")
    return STAGE_UNZIP;
  if (enum_string == "write")
    return STAGE_WRITE;
  if (enum_string == "verifyWrite")
    return STAGE_VERIFYWRITE;
  if (enum_string == "unknown")
    return STAGE_UNKNOWN;
  return STAGE_NONE;
}


UrlWriteOptions::UrlWriteOptions()
 {}

UrlWriteOptions::~UrlWriteOptions() {}
UrlWriteOptions::UrlWriteOptions(UrlWriteOptions&& rhs)
: image_hash(std::move(rhs.image_hash)),
save_as_download(std::move(rhs.save_as_download)){
}

UrlWriteOptions& UrlWriteOptions::operator=(UrlWriteOptions&& rhs)
{
image_hash = std::move(rhs.image_hash);
save_as_download = std::move(rhs.save_as_download);
return *this;
}

// static
bool UrlWriteOptions::Populate(
    const base::Value& value, UrlWriteOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* image_hash_value = NULL;
  if (dict->GetWithoutPathExpansion("imageHash", &image_hash_value)) {
    {
      std::string temp;
      if (!image_hash_value->GetAsString(&temp)) {
        out->image_hash.reset();
        return false;
      }
      else
        out->image_hash.reset(new std::string(temp));
    }
  }

  const base::Value* save_as_download_value = NULL;
  if (dict->GetWithoutPathExpansion("saveAsDownload", &save_as_download_value)) {
    {
      bool temp;
      if (!save_as_download_value->GetAsBoolean(&temp)) {
        out->save_as_download.reset();
        return false;
      }
      else
        out->save_as_download.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<UrlWriteOptions> UrlWriteOptions::FromValue(const base::Value& value) {
  std::unique_ptr<UrlWriteOptions> out(new UrlWriteOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> UrlWriteOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->image_hash.get()) {
    to_value_result->SetWithoutPathExpansion("imageHash", std::make_unique<base::Value>(*this->image_hash));

  }
  if (this->save_as_download.get()) {
    to_value_result->SetWithoutPathExpansion("saveAsDownload", std::make_unique<base::Value>(*this->save_as_download));

  }

  return to_value_result;
}


ProgressInfo::ProgressInfo()
: stage(STAGE_NONE),
percent_complete(0) {}

ProgressInfo::~ProgressInfo() {}
ProgressInfo::ProgressInfo(ProgressInfo&& rhs)
: stage(rhs.stage),
percent_complete(rhs.percent_complete){
}

ProgressInfo& ProgressInfo::operator=(ProgressInfo&& rhs)
{
stage = rhs.stage;
percent_complete = rhs.percent_complete;
return *this;
}

// static
bool ProgressInfo::Populate(
    const base::Value& value, ProgressInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* stage_value = NULL;
  if (!dict->GetWithoutPathExpansion("stage", &stage_value)) {
    return false;
  }
  {
    std::string stage_as_string;
    if (!stage_value->GetAsString(&stage_as_string)) {
      return false;
    }
    out->stage = ParseStage(stage_as_string);
    if (out->stage == STAGE_NONE) {
      return false;
    }
  }

  const base::Value* percent_complete_value = NULL;
  if (!dict->GetWithoutPathExpansion("percentComplete", &percent_complete_value)) {
    return false;
  }
  {
    if (!percent_complete_value->GetAsInteger(&out->percent_complete)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ProgressInfo> ProgressInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ProgressInfo> out(new ProgressInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ProgressInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("stage", std::make_unique<base::Value>(image_writer_private::ToString(this->stage)));

  to_value_result->SetWithoutPathExpansion("percentComplete", std::make_unique<base::Value>(this->percent_complete));


  return to_value_result;
}


RemovableStorageDevice::RemovableStorageDevice()
: capacity(0.0),
removable(false) {}

RemovableStorageDevice::~RemovableStorageDevice() {}
RemovableStorageDevice::RemovableStorageDevice(RemovableStorageDevice&& rhs)
: storage_unit_id(std::move(rhs.storage_unit_id)),
capacity(rhs.capacity),
vendor(std::move(rhs.vendor)),
model(std::move(rhs.model)),
removable(rhs.removable){
}

RemovableStorageDevice& RemovableStorageDevice::operator=(RemovableStorageDevice&& rhs)
{
storage_unit_id = std::move(rhs.storage_unit_id);
capacity = rhs.capacity;
vendor = std::move(rhs.vendor);
model = std::move(rhs.model);
removable = rhs.removable;
return *this;
}

// static
bool RemovableStorageDevice::Populate(
    const base::Value& value, RemovableStorageDevice* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* storage_unit_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("storageUnitId", &storage_unit_id_value)) {
    return false;
  }
  {
    if (!storage_unit_id_value->GetAsString(&out->storage_unit_id)) {
      return false;
    }
  }

  const base::Value* capacity_value = NULL;
  if (!dict->GetWithoutPathExpansion("capacity", &capacity_value)) {
    return false;
  }
  {
    if (!capacity_value->GetAsDouble(&out->capacity)) {
      return false;
    }
  }

  const base::Value* vendor_value = NULL;
  if (!dict->GetWithoutPathExpansion("vendor", &vendor_value)) {
    return false;
  }
  {
    if (!vendor_value->GetAsString(&out->vendor)) {
      return false;
    }
  }

  const base::Value* model_value = NULL;
  if (!dict->GetWithoutPathExpansion("model", &model_value)) {
    return false;
  }
  {
    if (!model_value->GetAsString(&out->model)) {
      return false;
    }
  }

  const base::Value* removable_value = NULL;
  if (!dict->GetWithoutPathExpansion("removable", &removable_value)) {
    return false;
  }
  {
    if (!removable_value->GetAsBoolean(&out->removable)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<RemovableStorageDevice> RemovableStorageDevice::FromValue(const base::Value& value) {
  std::unique_ptr<RemovableStorageDevice> out(new RemovableStorageDevice());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RemovableStorageDevice::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("storageUnitId", std::make_unique<base::Value>(this->storage_unit_id));

  to_value_result->SetWithoutPathExpansion("capacity", std::make_unique<base::Value>(this->capacity));

  to_value_result->SetWithoutPathExpansion("vendor", std::make_unique<base::Value>(this->vendor));

  to_value_result->SetWithoutPathExpansion("model", std::make_unique<base::Value>(this->model));

  to_value_result->SetWithoutPathExpansion("removable", std::make_unique<base::Value>(this->removable));


  return to_value_result;
}



//
// Functions
//

namespace WriteFromUrl {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* storage_unit_id_value = NULL;
  if (args.Get(0, &storage_unit_id_value) &&
      !storage_unit_id_value->is_none()) {
    {
      if (!storage_unit_id_value->GetAsString(&params->storage_unit_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* image_url_value = NULL;
  if (args.Get(1, &image_url_value) &&
      !image_url_value->is_none()) {
    {
      if (!image_url_value->GetAsString(&params->image_url)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* options_value = NULL;
  if (args.Get(2, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<UrlWriteOptions> temp(new UrlWriteOptions());
        if (!UrlWriteOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace WriteFromUrl

namespace WriteFromFile {

Params::FileEntry::FileEntry()
 {}

Params::FileEntry::~FileEntry() {}
Params::FileEntry::FileEntry(FileEntry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::FileEntry& Params::FileEntry::operator=(FileEntry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::FileEntry::Populate(
    const base::Value& value, FileEntry* out) {
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

  const base::Value* storage_unit_id_value = NULL;
  if (args.Get(0, &storage_unit_id_value) &&
      !storage_unit_id_value->is_none()) {
    {
      if (!storage_unit_id_value->GetAsString(&params->storage_unit_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* file_entry_value = NULL;
  if (args.Get(1, &file_entry_value) &&
      !file_entry_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!file_entry_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!FileEntry::Populate(*dictionary, &params->file_entry)) {
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
}  // namespace WriteFromFile

namespace CancelWrite {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace CancelWrite

namespace DestroyPartitions {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* storage_unit_id_value = NULL;
  if (args.Get(0, &storage_unit_id_value) &&
      !storage_unit_id_value->is_none()) {
    {
      if (!storage_unit_id_value->GetAsString(&params->storage_unit_id)) {
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
}  // namespace DestroyPartitions

namespace ListRemovableStorageDevices {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<RemovableStorageDevice>& devices) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(devices));

  return create_results;
}
}  // namespace ListRemovableStorageDevices

//
// Events
//

namespace OnWriteProgress {

const char kEventName[] = "imageWriterPrivate.onWriteProgress";

std::unique_ptr<base::ListValue> Create(const ProgressInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnWriteProgress

namespace OnWriteComplete {

const char kEventName[] = "imageWriterPrivate.onWriteComplete";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnWriteComplete

namespace OnWriteError {

const char kEventName[] = "imageWriterPrivate.onWriteError";

std::unique_ptr<base::ListValue> Create(const ProgressInfo& info, const std::string& error) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  create_results->Append(std::make_unique<base::Value>(error));

  return create_results;
}

}  // namespace OnWriteError

namespace OnDeviceInserted {

const char kEventName[] = "imageWriterPrivate.onDeviceInserted";

std::unique_ptr<base::ListValue> Create(const RemovableStorageDevice& device) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device).ToValue());

  return create_results;
}

}  // namespace OnDeviceInserted

namespace OnDeviceRemoved {

const char kEventName[] = "imageWriterPrivate.onDeviceRemoved";

std::unique_ptr<base::ListValue> Create(const RemovableStorageDevice& device) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device).ToValue());

  return create_results;
}

}  // namespace OnDeviceRemoved

}  // namespace image_writer_private
}  // namespace api
}  // namespace extensions

