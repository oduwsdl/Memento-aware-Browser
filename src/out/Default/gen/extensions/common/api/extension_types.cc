// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/extension_types.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/extension_types.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace extension_types {
//
// Types
//

const char* ToString(ImageFormat enum_param) {
  switch (enum_param) {
    case IMAGE_FORMAT_JPEG:
      return "jpeg";
    case IMAGE_FORMAT_PNG:
      return "png";
    case IMAGE_FORMAT_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ImageFormat ParseImageFormat(const std::string& enum_string) {
  if (enum_string == "jpeg")
    return IMAGE_FORMAT_JPEG;
  if (enum_string == "png")
    return IMAGE_FORMAT_PNG;
  return IMAGE_FORMAT_NONE;
}


ImageDetails::ImageDetails()
: format(IMAGE_FORMAT_NONE) {}

ImageDetails::~ImageDetails() {}
ImageDetails::ImageDetails(ImageDetails&& rhs)
: format(rhs.format),
quality(std::move(rhs.quality)){
}

ImageDetails& ImageDetails::operator=(ImageDetails&& rhs)
{
format = rhs.format;
quality = std::move(rhs.quality);
return *this;
}

// static
bool ImageDetails::Populate(
    const base::Value& value, ImageDetails* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->format = IMAGE_FORMAT_NONE;
  const base::Value* format_value = NULL;
  if (dict->GetWithoutPathExpansion("format", &format_value)) {
    {
      std::string image_format_as_string;
      if (!format_value->GetAsString(&image_format_as_string)) {
        return false;
      }
      out->format = ParseImageFormat(image_format_as_string);
      if (out->format == IMAGE_FORMAT_NONE) {
        return false;
      }
    }
    } else {
    out->format = IMAGE_FORMAT_NONE;
  }

  const base::Value* quality_value = NULL;
  if (dict->GetWithoutPathExpansion("quality", &quality_value)) {
    {
      int temp;
      if (!quality_value->GetAsInteger(&temp)) {
        out->quality.reset();
        return false;
      }
      else
        out->quality.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ImageDetails> ImageDetails::FromValue(const base::Value& value) {
  std::unique_ptr<ImageDetails> out(new ImageDetails());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ImageDetails::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->format != IMAGE_FORMAT_NONE) {
    to_value_result->SetWithoutPathExpansion("format", std::make_unique<base::Value>(extension_types::ToString(this->format)));

  }
  if (this->quality.get()) {
    to_value_result->SetWithoutPathExpansion("quality", std::make_unique<base::Value>(*this->quality));

  }

  return to_value_result;
}


const char* ToString(RunAt enum_param) {
  switch (enum_param) {
    case RUN_AT_DOCUMENT_START:
      return "document_start";
    case RUN_AT_DOCUMENT_END:
      return "document_end";
    case RUN_AT_DOCUMENT_IDLE:
      return "document_idle";
    case RUN_AT_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

RunAt ParseRunAt(const std::string& enum_string) {
  if (enum_string == "document_start")
    return RUN_AT_DOCUMENT_START;
  if (enum_string == "document_end")
    return RUN_AT_DOCUMENT_END;
  if (enum_string == "document_idle")
    return RUN_AT_DOCUMENT_IDLE;
  return RUN_AT_NONE;
}


const char* ToString(CSSOrigin enum_param) {
  switch (enum_param) {
    case CSS_ORIGIN_AUTHOR:
      return "author";
    case CSS_ORIGIN_USER:
      return "user";
    case CSS_ORIGIN_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

CSSOrigin ParseCSSOrigin(const std::string& enum_string) {
  if (enum_string == "author")
    return CSS_ORIGIN_AUTHOR;
  if (enum_string == "user")
    return CSS_ORIGIN_USER;
  return CSS_ORIGIN_NONE;
}


InjectDetails::InjectDetails()
: run_at(RUN_AT_NONE),
css_origin(CSS_ORIGIN_NONE) {}

InjectDetails::~InjectDetails() {}
InjectDetails::InjectDetails(InjectDetails&& rhs)
: code(std::move(rhs.code)),
file(std::move(rhs.file)),
all_frames(std::move(rhs.all_frames)),
frame_id(std::move(rhs.frame_id)),
match_about_blank(std::move(rhs.match_about_blank)),
run_at(rhs.run_at),
css_origin(rhs.css_origin){
}

InjectDetails& InjectDetails::operator=(InjectDetails&& rhs)
{
code = std::move(rhs.code);
file = std::move(rhs.file);
all_frames = std::move(rhs.all_frames);
frame_id = std::move(rhs.frame_id);
match_about_blank = std::move(rhs.match_about_blank);
run_at = rhs.run_at;
css_origin = rhs.css_origin;
return *this;
}

// static
bool InjectDetails::Populate(
    const base::Value& value, InjectDetails* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->run_at = RUN_AT_NONE;
  out->css_origin = CSS_ORIGIN_NONE;
  const base::Value* code_value = NULL;
  if (dict->GetWithoutPathExpansion("code", &code_value)) {
    {
      std::string temp;
      if (!code_value->GetAsString(&temp)) {
        out->code.reset();
        return false;
      }
      else
        out->code.reset(new std::string(temp));
    }
  }

  const base::Value* file_value = NULL;
  if (dict->GetWithoutPathExpansion("file", &file_value)) {
    {
      std::string temp;
      if (!file_value->GetAsString(&temp)) {
        out->file.reset();
        return false;
      }
      else
        out->file.reset(new std::string(temp));
    }
  }

  const base::Value* all_frames_value = NULL;
  if (dict->GetWithoutPathExpansion("allFrames", &all_frames_value)) {
    {
      bool temp;
      if (!all_frames_value->GetAsBoolean(&temp)) {
        out->all_frames.reset();
        return false;
      }
      else
        out->all_frames.reset(new bool(temp));
    }
  }

  const base::Value* frame_id_value = NULL;
  if (dict->GetWithoutPathExpansion("frameId", &frame_id_value)) {
    {
      int temp;
      if (!frame_id_value->GetAsInteger(&temp)) {
        out->frame_id.reset();
        return false;
      }
      else
        out->frame_id.reset(new int(temp));
    }
  }

  const base::Value* match_about_blank_value = NULL;
  if (dict->GetWithoutPathExpansion("matchAboutBlank", &match_about_blank_value)) {
    {
      bool temp;
      if (!match_about_blank_value->GetAsBoolean(&temp)) {
        out->match_about_blank.reset();
        return false;
      }
      else
        out->match_about_blank.reset(new bool(temp));
    }
  }

  const base::Value* run_at_value = NULL;
  if (dict->GetWithoutPathExpansion("runAt", &run_at_value)) {
    {
      std::string run_at_as_string;
      if (!run_at_value->GetAsString(&run_at_as_string)) {
        return false;
      }
      out->run_at = ParseRunAt(run_at_as_string);
      if (out->run_at == RUN_AT_NONE) {
        return false;
      }
    }
    } else {
    out->run_at = RUN_AT_NONE;
  }

  const base::Value* css_origin_value = NULL;
  if (dict->GetWithoutPathExpansion("cssOrigin", &css_origin_value)) {
    {
      std::string css_origin_as_string;
      if (!css_origin_value->GetAsString(&css_origin_as_string)) {
        return false;
      }
      out->css_origin = ParseCSSOrigin(css_origin_as_string);
      if (out->css_origin == CSS_ORIGIN_NONE) {
        return false;
      }
    }
    } else {
    out->css_origin = CSS_ORIGIN_NONE;
  }

  return true;
}

// static
std::unique_ptr<InjectDetails> InjectDetails::FromValue(const base::Value& value) {
  std::unique_ptr<InjectDetails> out(new InjectDetails());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> InjectDetails::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->code.get()) {
    to_value_result->SetWithoutPathExpansion("code", std::make_unique<base::Value>(*this->code));

  }
  if (this->file.get()) {
    to_value_result->SetWithoutPathExpansion("file", std::make_unique<base::Value>(*this->file));

  }
  if (this->all_frames.get()) {
    to_value_result->SetWithoutPathExpansion("allFrames", std::make_unique<base::Value>(*this->all_frames));

  }
  if (this->frame_id.get()) {
    to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(*this->frame_id));

  }
  if (this->match_about_blank.get()) {
    to_value_result->SetWithoutPathExpansion("matchAboutBlank", std::make_unique<base::Value>(*this->match_about_blank));

  }
  if (this->run_at != RUN_AT_NONE) {
    to_value_result->SetWithoutPathExpansion("runAt", std::make_unique<base::Value>(extension_types::ToString(this->run_at)));

  }
  if (this->css_origin != CSS_ORIGIN_NONE) {
    to_value_result->SetWithoutPathExpansion("cssOrigin", std::make_unique<base::Value>(extension_types::ToString(this->css_origin)));

  }

  return to_value_result;
}



}  // namespace extension_types
}  // namespace api
}  // namespace extensions

