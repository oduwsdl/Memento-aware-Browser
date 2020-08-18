// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/tab_capture.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/tab_capture.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace tab_capture {
//
// Types
//

const char* ToString(TabCaptureState enum_param) {
  switch (enum_param) {
    case TAB_CAPTURE_STATE_PENDING:
      return "pending";
    case TAB_CAPTURE_STATE_ACTIVE:
      return "active";
    case TAB_CAPTURE_STATE_STOPPED:
      return "stopped";
    case TAB_CAPTURE_STATE_ERROR:
      return "error";
    case TAB_CAPTURE_STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

TabCaptureState ParseTabCaptureState(const std::string& enum_string) {
  if (enum_string == "pending")
    return TAB_CAPTURE_STATE_PENDING;
  if (enum_string == "active")
    return TAB_CAPTURE_STATE_ACTIVE;
  if (enum_string == "stopped")
    return TAB_CAPTURE_STATE_STOPPED;
  if (enum_string == "error")
    return TAB_CAPTURE_STATE_ERROR;
  return TAB_CAPTURE_STATE_NONE;
}


CaptureInfo::CaptureInfo()
: tab_id(0),
status(TAB_CAPTURE_STATE_NONE),
fullscreen(false) {}

CaptureInfo::~CaptureInfo() {}
CaptureInfo::CaptureInfo(CaptureInfo&& rhs)
: tab_id(rhs.tab_id),
status(rhs.status),
fullscreen(rhs.fullscreen){
}

CaptureInfo& CaptureInfo::operator=(CaptureInfo&& rhs)
{
tab_id = rhs.tab_id;
status = rhs.status;
fullscreen = rhs.fullscreen;
return *this;
}

// static
bool CaptureInfo::Populate(
    const base::Value& value, CaptureInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* tab_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("tabId", &tab_id_value)) {
    return false;
  }
  {
    if (!tab_id_value->GetAsInteger(&out->tab_id)) {
      return false;
    }
  }

  const base::Value* status_value = NULL;
  if (!dict->GetWithoutPathExpansion("status", &status_value)) {
    return false;
  }
  {
    std::string tab_capture_state_as_string;
    if (!status_value->GetAsString(&tab_capture_state_as_string)) {
      return false;
    }
    out->status = ParseTabCaptureState(tab_capture_state_as_string);
    if (out->status == TAB_CAPTURE_STATE_NONE) {
      return false;
    }
  }

  const base::Value* fullscreen_value = NULL;
  if (!dict->GetWithoutPathExpansion("fullscreen", &fullscreen_value)) {
    return false;
  }
  {
    if (!fullscreen_value->GetAsBoolean(&out->fullscreen)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<CaptureInfo> CaptureInfo::FromValue(const base::Value& value) {
  std::unique_ptr<CaptureInfo> out(new CaptureInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CaptureInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("status", std::make_unique<base::Value>(tab_capture::ToString(this->status)));

  to_value_result->SetWithoutPathExpansion("fullscreen", std::make_unique<base::Value>(this->fullscreen));


  return to_value_result;
}


MediaStreamConstraint::Mandatory::Mandatory()
 {}

MediaStreamConstraint::Mandatory::~Mandatory() {}
MediaStreamConstraint::Mandatory::Mandatory(Mandatory&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

MediaStreamConstraint::Mandatory& MediaStreamConstraint::Mandatory::operator=(Mandatory&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool MediaStreamConstraint::Mandatory::Populate(
    const base::Value& value, Mandatory* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> MediaStreamConstraint::Mandatory::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


MediaStreamConstraint::Optional::Optional()
 {}

MediaStreamConstraint::Optional::~Optional() {}
MediaStreamConstraint::Optional::Optional(Optional&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

MediaStreamConstraint::Optional& MediaStreamConstraint::Optional::operator=(Optional&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool MediaStreamConstraint::Optional::Populate(
    const base::Value& value, Optional* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> MediaStreamConstraint::Optional::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



MediaStreamConstraint::MediaStreamConstraint()
 {}

MediaStreamConstraint::~MediaStreamConstraint() {}
MediaStreamConstraint::MediaStreamConstraint(MediaStreamConstraint&& rhs)
: mandatory(std::move(rhs.mandatory)),
optional(std::move(rhs.optional)){
}

MediaStreamConstraint& MediaStreamConstraint::operator=(MediaStreamConstraint&& rhs)
{
mandatory = std::move(rhs.mandatory);
optional = std::move(rhs.optional);
return *this;
}

// static
bool MediaStreamConstraint::Populate(
    const base::Value& value, MediaStreamConstraint* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* mandatory_value = NULL;
  if (!dict->GetWithoutPathExpansion("mandatory", &mandatory_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!mandatory_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Mandatory::Populate(*dictionary, &out->mandatory)) {
      return false;
    }
  }

  const base::Value* optional_value = NULL;
  if (dict->GetWithoutPathExpansion("optional", &optional_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!optional_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Optional> temp(new Optional());
        if (!Optional::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->optional = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<MediaStreamConstraint> MediaStreamConstraint::FromValue(const base::Value& value) {
  std::unique_ptr<MediaStreamConstraint> out(new MediaStreamConstraint());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MediaStreamConstraint::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("mandatory", (this->mandatory).ToValue());

  if (this->optional.get()) {
    to_value_result->SetWithoutPathExpansion("optional", (this->optional)->ToValue());

  }

  return to_value_result;
}


CaptureOptions::CaptureOptions()
 {}

CaptureOptions::~CaptureOptions() {}
CaptureOptions::CaptureOptions(CaptureOptions&& rhs)
: audio(std::move(rhs.audio)),
video(std::move(rhs.video)),
audio_constraints(std::move(rhs.audio_constraints)),
video_constraints(std::move(rhs.video_constraints)),
presentation_id(std::move(rhs.presentation_id)){
}

CaptureOptions& CaptureOptions::operator=(CaptureOptions&& rhs)
{
audio = std::move(rhs.audio);
video = std::move(rhs.video);
audio_constraints = std::move(rhs.audio_constraints);
video_constraints = std::move(rhs.video_constraints);
presentation_id = std::move(rhs.presentation_id);
return *this;
}

// static
bool CaptureOptions::Populate(
    const base::Value& value, CaptureOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* audio_value = NULL;
  if (dict->GetWithoutPathExpansion("audio", &audio_value)) {
    {
      bool temp;
      if (!audio_value->GetAsBoolean(&temp)) {
        out->audio.reset();
        return false;
      }
      else
        out->audio.reset(new bool(temp));
    }
  }

  const base::Value* video_value = NULL;
  if (dict->GetWithoutPathExpansion("video", &video_value)) {
    {
      bool temp;
      if (!video_value->GetAsBoolean(&temp)) {
        out->video.reset();
        return false;
      }
      else
        out->video.reset(new bool(temp));
    }
  }

  const base::Value* audio_constraints_value = NULL;
  if (dict->GetWithoutPathExpansion("audioConstraints", &audio_constraints_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!audio_constraints_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<MediaStreamConstraint> temp(new MediaStreamConstraint());
        if (!MediaStreamConstraint::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->audio_constraints = std::move(temp);
      }
    }
  }

  const base::Value* video_constraints_value = NULL;
  if (dict->GetWithoutPathExpansion("videoConstraints", &video_constraints_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!video_constraints_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<MediaStreamConstraint> temp(new MediaStreamConstraint());
        if (!MediaStreamConstraint::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->video_constraints = std::move(temp);
      }
    }
  }

  const base::Value* presentation_id_value = NULL;
  if (dict->GetWithoutPathExpansion("presentationId", &presentation_id_value)) {
    {
      std::string temp;
      if (!presentation_id_value->GetAsString(&temp)) {
        out->presentation_id.reset();
        return false;
      }
      else
        out->presentation_id.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<CaptureOptions> CaptureOptions::FromValue(const base::Value& value) {
  std::unique_ptr<CaptureOptions> out(new CaptureOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CaptureOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->audio.get()) {
    to_value_result->SetWithoutPathExpansion("audio", std::make_unique<base::Value>(*this->audio));

  }
  if (this->video.get()) {
    to_value_result->SetWithoutPathExpansion("video", std::make_unique<base::Value>(*this->video));

  }
  if (this->audio_constraints.get()) {
    to_value_result->SetWithoutPathExpansion("audioConstraints", (this->audio_constraints)->ToValue());

  }
  if (this->video_constraints.get()) {
    to_value_result->SetWithoutPathExpansion("videoConstraints", (this->video_constraints)->ToValue());

  }
  if (this->presentation_id.get()) {
    to_value_result->SetWithoutPathExpansion("presentationId", std::make_unique<base::Value>(*this->presentation_id));

  }

  return to_value_result;
}


GetMediaStreamOptions::GetMediaStreamOptions()
 {}

GetMediaStreamOptions::~GetMediaStreamOptions() {}
GetMediaStreamOptions::GetMediaStreamOptions(GetMediaStreamOptions&& rhs)
: consumer_tab_id(std::move(rhs.consumer_tab_id)),
target_tab_id(std::move(rhs.target_tab_id)){
}

GetMediaStreamOptions& GetMediaStreamOptions::operator=(GetMediaStreamOptions&& rhs)
{
consumer_tab_id = std::move(rhs.consumer_tab_id);
target_tab_id = std::move(rhs.target_tab_id);
return *this;
}

// static
bool GetMediaStreamOptions::Populate(
    const base::Value& value, GetMediaStreamOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* consumer_tab_id_value = NULL;
  if (dict->GetWithoutPathExpansion("consumerTabId", &consumer_tab_id_value)) {
    {
      int temp;
      if (!consumer_tab_id_value->GetAsInteger(&temp)) {
        out->consumer_tab_id.reset();
        return false;
      }
      else
        out->consumer_tab_id.reset(new int(temp));
    }
  }

  const base::Value* target_tab_id_value = NULL;
  if (dict->GetWithoutPathExpansion("targetTabId", &target_tab_id_value)) {
    {
      int temp;
      if (!target_tab_id_value->GetAsInteger(&temp)) {
        out->target_tab_id.reset();
        return false;
      }
      else
        out->target_tab_id.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<GetMediaStreamOptions> GetMediaStreamOptions::FromValue(const base::Value& value) {
  std::unique_ptr<GetMediaStreamOptions> out(new GetMediaStreamOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> GetMediaStreamOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->consumer_tab_id.get()) {
    to_value_result->SetWithoutPathExpansion("consumerTabId", std::make_unique<base::Value>(*this->consumer_tab_id));

  }
  if (this->target_tab_id.get()) {
    to_value_result->SetWithoutPathExpansion("targetTabId", std::make_unique<base::Value>(*this->target_tab_id));

  }

  return to_value_result;
}



//
// Functions
//

namespace Capture {

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
      if (!CaptureOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


Results::Stream::Stream()
 {}

Results::Stream::~Stream() {}
Results::Stream::Stream(Stream&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::Stream& Results::Stream::operator=(Stream&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Stream::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Stream& stream) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((stream).ToValue());

  return create_results;
}
}  // namespace Capture

namespace GetCapturedTabs {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<CaptureInfo>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetCapturedTabs

namespace CaptureOffscreenTab {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* start_url_value = NULL;
  if (args.Get(0, &start_url_value) &&
      !start_url_value->is_none()) {
    {
      if (!start_url_value->GetAsString(&params->start_url)) {
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
      if (!CaptureOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


Results::Stream::Stream()
 {}

Results::Stream::~Stream() {}
Results::Stream::Stream(Stream&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::Stream& Results::Stream::operator=(Stream&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Stream::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Stream& stream) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((stream).ToValue());

  return create_results;
}
}  // namespace CaptureOffscreenTab

namespace GetMediaStreamId {

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
        std::unique_ptr<GetMediaStreamOptions> temp(new GetMediaStreamOptions());
        if (!GetMediaStreamOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& stream_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(stream_id));

  return create_results;
}
}  // namespace GetMediaStreamId

//
// Events
//

namespace OnStatusChanged {

const char kEventName[] = "tabCapture.onStatusChanged";

std::unique_ptr<base::ListValue> Create(const CaptureInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnStatusChanged

}  // namespace tab_capture
}  // namespace api
}  // namespace extensions

