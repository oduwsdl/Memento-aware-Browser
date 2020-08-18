// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/webrtc_audio_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/webrtc_audio_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace webrtc_audio_private {
//
// Types
//

SinkInfo::SinkInfo()
: sample_rate(0),
is_ready(false),
is_default(false) {}

SinkInfo::~SinkInfo() {}
SinkInfo::SinkInfo(SinkInfo&& rhs)
: sink_id(std::move(rhs.sink_id)),
sink_label(std::move(rhs.sink_label)),
sample_rate(rhs.sample_rate),
is_ready(rhs.is_ready),
is_default(rhs.is_default){
}

SinkInfo& SinkInfo::operator=(SinkInfo&& rhs)
{
sink_id = std::move(rhs.sink_id);
sink_label = std::move(rhs.sink_label);
sample_rate = rhs.sample_rate;
is_ready = rhs.is_ready;
is_default = rhs.is_default;
return *this;
}

// static
bool SinkInfo::Populate(
    const base::Value& value, SinkInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* sink_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("sinkId", &sink_id_value)) {
    return false;
  }
  {
    if (!sink_id_value->GetAsString(&out->sink_id)) {
      return false;
    }
  }

  const base::Value* sink_label_value = NULL;
  if (!dict->GetWithoutPathExpansion("sinkLabel", &sink_label_value)) {
    return false;
  }
  {
    if (!sink_label_value->GetAsString(&out->sink_label)) {
      return false;
    }
  }

  const base::Value* sample_rate_value = NULL;
  if (!dict->GetWithoutPathExpansion("sampleRate", &sample_rate_value)) {
    return false;
  }
  {
    if (!sample_rate_value->GetAsInteger(&out->sample_rate)) {
      return false;
    }
  }

  const base::Value* is_ready_value = NULL;
  if (!dict->GetWithoutPathExpansion("isReady", &is_ready_value)) {
    return false;
  }
  {
    if (!is_ready_value->GetAsBoolean(&out->is_ready)) {
      return false;
    }
  }

  const base::Value* is_default_value = NULL;
  if (!dict->GetWithoutPathExpansion("isDefault", &is_default_value)) {
    return false;
  }
  {
    if (!is_default_value->GetAsBoolean(&out->is_default)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<SinkInfo> SinkInfo::FromValue(const base::Value& value) {
  std::unique_ptr<SinkInfo> out(new SinkInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SinkInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("sinkId", std::make_unique<base::Value>(this->sink_id));

  to_value_result->SetWithoutPathExpansion("sinkLabel", std::make_unique<base::Value>(this->sink_label));

  to_value_result->SetWithoutPathExpansion("sampleRate", std::make_unique<base::Value>(this->sample_rate));

  to_value_result->SetWithoutPathExpansion("isReady", std::make_unique<base::Value>(this->is_ready));

  to_value_result->SetWithoutPathExpansion("isDefault", std::make_unique<base::Value>(this->is_default));


  return to_value_result;
}



//
// Functions
//

namespace GetSinks {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<SinkInfo>& sink_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(sink_info));

  return create_results;
}
}  // namespace GetSinks

namespace GetAssociatedSink {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* security_origin_value = NULL;
  if (args.Get(0, &security_origin_value) &&
      !security_origin_value->is_none()) {
    {
      if (!security_origin_value->GetAsString(&params->security_origin)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* source_id_in_origin_value = NULL;
  if (args.Get(1, &source_id_in_origin_value) &&
      !source_id_in_origin_value->is_none()) {
    {
      if (!source_id_in_origin_value->GetAsString(&params->source_id_in_origin)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& sink_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(sink_id));

  return create_results;
}
}  // namespace GetAssociatedSink

//
// Events
//

namespace OnSinksChanged {

const char kEventName[] = "webrtcAudioPrivate.onSinksChanged";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnSinksChanged

}  // namespace webrtc_audio_private
}  // namespace api
}  // namespace extensions

