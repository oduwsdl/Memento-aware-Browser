// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/desktop_capture.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/desktop_capture.h"
#include <set>
#include <utility>
#include "chrome/common/extensions/api/tabs.h"


using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace desktop_capture {
//
// Types
//

const char* ToString(DesktopCaptureSourceType enum_param) {
  switch (enum_param) {
    case DESKTOP_CAPTURE_SOURCE_TYPE_SCREEN:
      return "screen";
    case DESKTOP_CAPTURE_SOURCE_TYPE_WINDOW:
      return "window";
    case DESKTOP_CAPTURE_SOURCE_TYPE_TAB:
      return "tab";
    case DESKTOP_CAPTURE_SOURCE_TYPE_AUDIO:
      return "audio";
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
  if (enum_string == "audio")
    return DESKTOP_CAPTURE_SOURCE_TYPE_AUDIO;
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
  if (args.GetSize() < 1 || args.GetSize() > 2) {
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

  const base::Value* target_tab_value = NULL;
  if (args.Get(1, &target_tab_value) &&
      !target_tab_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!target_tab_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<extensions::api::tabs::Tab> temp(new extensions::api::tabs::Tab());
        if (!extensions::api::tabs::Tab::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->target_tab = std::move(temp);
      }
    }
  }

  return params;
}


Results::Options::Options()
: can_request_audio_track(false) {}

Results::Options::~Options() {}
Results::Options::Options(Options&& rhs)
: can_request_audio_track(rhs.can_request_audio_track){
}

Results::Options& Results::Options::operator=(Options&& rhs)
{
can_request_audio_track = rhs.can_request_audio_track;
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Options::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("canRequestAudioTrack", std::make_unique<base::Value>(this->can_request_audio_track));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& stream_id, const Options& options) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(stream_id));

  create_results->Append((options).ToValue());

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

}  // namespace desktop_capture
}  // namespace api
}  // namespace extensions

