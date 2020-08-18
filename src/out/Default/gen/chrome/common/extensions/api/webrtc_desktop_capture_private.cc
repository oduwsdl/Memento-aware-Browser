// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/webrtc_desktop_capture_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/webrtc_desktop_capture_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace webrtc_desktop_capture_private {
//
// Types
//

RequestInfo::RequestInfo()
: guest_process_id(0),
guest_render_frame_id(0) {}

RequestInfo::~RequestInfo() {}
RequestInfo::RequestInfo(RequestInfo&& rhs)
: guest_process_id(rhs.guest_process_id),
guest_render_frame_id(rhs.guest_render_frame_id){
}

RequestInfo& RequestInfo::operator=(RequestInfo&& rhs)
{
guest_process_id = rhs.guest_process_id;
guest_render_frame_id = rhs.guest_render_frame_id;
return *this;
}

// static
bool RequestInfo::Populate(
    const base::Value& value, RequestInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* guest_process_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("guestProcessId", &guest_process_id_value)) {
    return false;
  }
  {
    if (!guest_process_id_value->GetAsInteger(&out->guest_process_id)) {
      return false;
    }
  }

  const base::Value* guest_render_frame_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("guestRenderFrameId", &guest_render_frame_id_value)) {
    return false;
  }
  {
    if (!guest_render_frame_id_value->GetAsInteger(&out->guest_render_frame_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<RequestInfo> RequestInfo::FromValue(const base::Value& value) {
  std::unique_ptr<RequestInfo> out(new RequestInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RequestInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("guestProcessId", std::make_unique<base::Value>(this->guest_process_id));

  to_value_result->SetWithoutPathExpansion("guestRenderFrameId", std::make_unique<base::Value>(this->guest_render_frame_id));


  return to_value_result;
}


const char* ToString(DesktopCaptureSourceType enum_param) {
  switch (enum_param) {
    case DESKTOP_CAPTURE_SOURCE_TYPE_SCREEN:
      return "screen";
    case DESKTOP_CAPTURE_SOURCE_TYPE_WINDOW:
      return "window";
    case DESKTOP_CAPTURE_SOURCE_TYPE_TAB:
      return "tab";
    case DESKTOP_CAPTURE_SOURCE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DesktopCaptureSourceType ParseDesktopCaptureSourceType(const std::string& enum_string) {
  if (enum_string == "screen")
    return DESKTOP_CAPTURE_SOURCE_TYPE_SCREEN;
  if (enum_string == "window")
    return DESKTOP_CAPTURE_SOURCE_TYPE_WINDOW;
  if (enum_string == "tab")
    return DESKTOP_CAPTURE_SOURCE_TYPE_TAB;
  return DESKTOP_CAPTURE_SOURCE_TYPE_NONE;
}



//
// Functions
//

namespace ChooseDesktopMedia {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* sources_value = NULL;
  if (args.Get(0, &sources_value) &&
      !sources_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!sources_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        for (const auto& it : *(list)) {
          DesktopCaptureSourceType tmp;
          std::string desktop_capture_source_type_as_string;
          if (!(it).GetAsString(&desktop_capture_source_type_as_string)) {
            return std::unique_ptr<Params>();
          }
          tmp = ParseDesktopCaptureSourceType(desktop_capture_source_type_as_string);
          if (tmp == DESKTOP_CAPTURE_SOURCE_TYPE_NONE) {
            return std::unique_ptr<Params>();
          }
          params->sources.push_back(tmp);
        }
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* request_value = NULL;
  if (args.Get(1, &request_value) &&
      !request_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!request_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!RequestInfo::Populate(*dictionary, &params->request)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& stream_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(stream_id));

  return create_results;
}
}  // namespace ChooseDesktopMedia

namespace CancelChooseDesktopMedia {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* desktop_media_request_id_value = NULL;
  if (args.Get(0, &desktop_media_request_id_value) &&
      !desktop_media_request_id_value->is_none()) {
    {
      if (!desktop_media_request_id_value->GetAsInteger(&params->desktop_media_request_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace CancelChooseDesktopMedia

}  // namespace webrtc_desktop_capture_private
}  // namespace api
}  // namespace extensions

