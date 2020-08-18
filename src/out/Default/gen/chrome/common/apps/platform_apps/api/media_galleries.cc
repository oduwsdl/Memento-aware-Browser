// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/apps/platform_apps/api/media_galleries.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/apps/platform_apps/api/media_galleries.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace chrome_apps {
namespace api {
namespace media_galleries {
//
// Types
//

const char* ToString(GalleryChangeType enum_param) {
  switch (enum_param) {
    case GALLERY_CHANGE_TYPE_CONTENTS_CHANGED:
      return "contents_changed";
    case GALLERY_CHANGE_TYPE_WATCH_DROPPED:
      return "watch_dropped";
    case GALLERY_CHANGE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

GalleryChangeType ParseGalleryChangeType(const std::string& enum_string) {
  if (enum_string == "contents_changed")
    return GALLERY_CHANGE_TYPE_CONTENTS_CHANGED;
  if (enum_string == "watch_dropped")
    return GALLERY_CHANGE_TYPE_WATCH_DROPPED;
  return GALLERY_CHANGE_TYPE_NONE;
}


const char* ToString(GetMediaFileSystemsInteractivity enum_param) {
  switch (enum_param) {
    case GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_NO:
      return "no";
    case GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_YES:
      return "yes";
    case GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_IF_NEEDED:
      return "if_needed";
    case GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

GetMediaFileSystemsInteractivity ParseGetMediaFileSystemsInteractivity(const std::string& enum_string) {
  if (enum_string == "no")
    return GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_NO;
  if (enum_string == "yes")
    return GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_YES;
  if (enum_string == "if_needed")
    return GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_IF_NEEDED;
  return GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_NONE;
}


const char* ToString(GetMetadataType enum_param) {
  switch (enum_param) {
    case GET_METADATA_TYPE_ALL:
      return "all";
    case GET_METADATA_TYPE_MIMETYPEANDTAGS:
      return "mimeTypeAndTags";
    case GET_METADATA_TYPE_MIMETYPEONLY:
      return "mimeTypeOnly";
    case GET_METADATA_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

GetMetadataType ParseGetMetadataType(const std::string& enum_string) {
  if (enum_string == "all")
    return GET_METADATA_TYPE_ALL;
  if (enum_string == "mimeTypeAndTags")
    return GET_METADATA_TYPE_MIMETYPEANDTAGS;
  if (enum_string == "mimeTypeOnly")
    return GET_METADATA_TYPE_MIMETYPEONLY;
  return GET_METADATA_TYPE_NONE;
}


GalleryChangeDetails::GalleryChangeDetails()
: type(GALLERY_CHANGE_TYPE_NONE) {}

GalleryChangeDetails::~GalleryChangeDetails() {}
GalleryChangeDetails::GalleryChangeDetails(GalleryChangeDetails&& rhs)
: type(rhs.type),
gallery_id(std::move(rhs.gallery_id)){
}

GalleryChangeDetails& GalleryChangeDetails::operator=(GalleryChangeDetails&& rhs)
{
type = rhs.type;
gallery_id = std::move(rhs.gallery_id);
return *this;
}

// static
bool GalleryChangeDetails::Populate(
    const base::Value& value, GalleryChangeDetails* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string gallery_change_type_as_string;
    if (!type_value->GetAsString(&gallery_change_type_as_string)) {
      return false;
    }
    out->type = ParseGalleryChangeType(gallery_change_type_as_string);
    if (out->type == GALLERY_CHANGE_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* gallery_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("galleryId", &gallery_id_value)) {
    return false;
  }
  {
    if (!gallery_id_value->GetAsString(&out->gallery_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<GalleryChangeDetails> GalleryChangeDetails::FromValue(const base::Value& value) {
  std::unique_ptr<GalleryChangeDetails> out(new GalleryChangeDetails());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> GalleryChangeDetails::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(media_galleries::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("galleryId", std::make_unique<base::Value>(this->gallery_id));


  return to_value_result;
}


MediaFileSystemsDetails::MediaFileSystemsDetails()
: interactive(GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_NONE) {}

MediaFileSystemsDetails::~MediaFileSystemsDetails() {}
MediaFileSystemsDetails::MediaFileSystemsDetails(MediaFileSystemsDetails&& rhs)
: interactive(rhs.interactive){
}

MediaFileSystemsDetails& MediaFileSystemsDetails::operator=(MediaFileSystemsDetails&& rhs)
{
interactive = rhs.interactive;
return *this;
}

// static
bool MediaFileSystemsDetails::Populate(
    const base::Value& value, MediaFileSystemsDetails* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->interactive = GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_NONE;
  const base::Value* interactive_value = NULL;
  if (dict->GetWithoutPathExpansion("interactive", &interactive_value)) {
    {
      std::string get_media_file_systems_interactivity_as_string;
      if (!interactive_value->GetAsString(&get_media_file_systems_interactivity_as_string)) {
        return false;
      }
      out->interactive = ParseGetMediaFileSystemsInteractivity(get_media_file_systems_interactivity_as_string);
      if (out->interactive == GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_NONE) {
        return false;
      }
    }
    } else {
    out->interactive = GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_NONE;
  }

  return true;
}

// static
std::unique_ptr<MediaFileSystemsDetails> MediaFileSystemsDetails::FromValue(const base::Value& value) {
  std::unique_ptr<MediaFileSystemsDetails> out(new MediaFileSystemsDetails());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MediaFileSystemsDetails::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->interactive != GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_NONE) {
    to_value_result->SetWithoutPathExpansion("interactive", std::make_unique<base::Value>(media_galleries::ToString(this->interactive)));

  }

  return to_value_result;
}


MediaMetadataOptions::MediaMetadataOptions()
: metadata_type(GET_METADATA_TYPE_NONE) {}

MediaMetadataOptions::~MediaMetadataOptions() {}
MediaMetadataOptions::MediaMetadataOptions(MediaMetadataOptions&& rhs)
: metadata_type(rhs.metadata_type){
}

MediaMetadataOptions& MediaMetadataOptions::operator=(MediaMetadataOptions&& rhs)
{
metadata_type = rhs.metadata_type;
return *this;
}

// static
bool MediaMetadataOptions::Populate(
    const base::Value& value, MediaMetadataOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->metadata_type = GET_METADATA_TYPE_NONE;
  const base::Value* metadata_type_value = NULL;
  if (dict->GetWithoutPathExpansion("metadataType", &metadata_type_value)) {
    {
      std::string get_metadata_type_as_string;
      if (!metadata_type_value->GetAsString(&get_metadata_type_as_string)) {
        return false;
      }
      out->metadata_type = ParseGetMetadataType(get_metadata_type_as_string);
      if (out->metadata_type == GET_METADATA_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->metadata_type = GET_METADATA_TYPE_NONE;
  }

  return true;
}

// static
std::unique_ptr<MediaMetadataOptions> MediaMetadataOptions::FromValue(const base::Value& value) {
  std::unique_ptr<MediaMetadataOptions> out(new MediaMetadataOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MediaMetadataOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->metadata_type != GET_METADATA_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("metadataType", std::make_unique<base::Value>(media_galleries::ToString(this->metadata_type)));

  }

  return to_value_result;
}


MediaFileSystemMetadata::MediaFileSystemMetadata()
: is_removable(false),
is_media_device(false),
is_available(false) {}

MediaFileSystemMetadata::~MediaFileSystemMetadata() {}
MediaFileSystemMetadata::MediaFileSystemMetadata(MediaFileSystemMetadata&& rhs)
: name(std::move(rhs.name)),
gallery_id(std::move(rhs.gallery_id)),
device_id(std::move(rhs.device_id)),
is_removable(rhs.is_removable),
is_media_device(rhs.is_media_device),
is_available(rhs.is_available){
}

MediaFileSystemMetadata& MediaFileSystemMetadata::operator=(MediaFileSystemMetadata&& rhs)
{
name = std::move(rhs.name);
gallery_id = std::move(rhs.gallery_id);
device_id = std::move(rhs.device_id);
is_removable = rhs.is_removable;
is_media_device = rhs.is_media_device;
is_available = rhs.is_available;
return *this;
}

// static
bool MediaFileSystemMetadata::Populate(
    const base::Value& value, MediaFileSystemMetadata* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* gallery_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("galleryId", &gallery_id_value)) {
    return false;
  }
  {
    if (!gallery_id_value->GetAsString(&out->gallery_id)) {
      return false;
    }
  }

  const base::Value* device_id_value = NULL;
  if (dict->GetWithoutPathExpansion("deviceId", &device_id_value)) {
    {
      std::string temp;
      if (!device_id_value->GetAsString(&temp)) {
        out->device_id.reset();
        return false;
      }
      else
        out->device_id.reset(new std::string(temp));
    }
  }

  const base::Value* is_removable_value = NULL;
  if (!dict->GetWithoutPathExpansion("isRemovable", &is_removable_value)) {
    return false;
  }
  {
    if (!is_removable_value->GetAsBoolean(&out->is_removable)) {
      return false;
    }
  }

  const base::Value* is_media_device_value = NULL;
  if (!dict->GetWithoutPathExpansion("isMediaDevice", &is_media_device_value)) {
    return false;
  }
  {
    if (!is_media_device_value->GetAsBoolean(&out->is_media_device)) {
      return false;
    }
  }

  const base::Value* is_available_value = NULL;
  if (!dict->GetWithoutPathExpansion("isAvailable", &is_available_value)) {
    return false;
  }
  {
    if (!is_available_value->GetAsBoolean(&out->is_available)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<MediaFileSystemMetadata> MediaFileSystemMetadata::FromValue(const base::Value& value) {
  std::unique_ptr<MediaFileSystemMetadata> out(new MediaFileSystemMetadata());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MediaFileSystemMetadata::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("galleryId", std::make_unique<base::Value>(this->gallery_id));

  if (this->device_id.get()) {
    to_value_result->SetWithoutPathExpansion("deviceId", std::make_unique<base::Value>(*this->device_id));

  }
  to_value_result->SetWithoutPathExpansion("isRemovable", std::make_unique<base::Value>(this->is_removable));

  to_value_result->SetWithoutPathExpansion("isMediaDevice", std::make_unique<base::Value>(this->is_media_device));

  to_value_result->SetWithoutPathExpansion("isAvailable", std::make_unique<base::Value>(this->is_available));


  return to_value_result;
}


StreamInfo::Tags::Tags()
 {}

StreamInfo::Tags::~Tags() {}
StreamInfo::Tags::Tags(Tags&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

StreamInfo::Tags& StreamInfo::Tags::operator=(Tags&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool StreamInfo::Tags::Populate(
    const base::Value& value, Tags* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> StreamInfo::Tags::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



StreamInfo::StreamInfo()
 {}

StreamInfo::~StreamInfo() {}
StreamInfo::StreamInfo(StreamInfo&& rhs)
: type(std::move(rhs.type)),
tags(std::move(rhs.tags)){
}

StreamInfo& StreamInfo::operator=(StreamInfo&& rhs)
{
type = std::move(rhs.type);
tags = std::move(rhs.tags);
return *this;
}

// static
bool StreamInfo::Populate(
    const base::Value& value, StreamInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    if (!type_value->GetAsString(&out->type)) {
      return false;
    }
  }

  const base::Value* tags_value = NULL;
  if (!dict->GetWithoutPathExpansion("tags", &tags_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!tags_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Tags::Populate(*dictionary, &out->tags)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<StreamInfo> StreamInfo::FromValue(const base::Value& value) {
  std::unique_ptr<StreamInfo> out(new StreamInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> StreamInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(this->type));

  to_value_result->SetWithoutPathExpansion("tags", (this->tags).ToValue());


  return to_value_result;
}


MediaMetadata::AttachedImagesType::AttachedImagesType()
 {}

MediaMetadata::AttachedImagesType::~AttachedImagesType() {}
MediaMetadata::AttachedImagesType::AttachedImagesType(AttachedImagesType&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

MediaMetadata::AttachedImagesType& MediaMetadata::AttachedImagesType::operator=(AttachedImagesType&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool MediaMetadata::AttachedImagesType::Populate(
    const base::Value& value, AttachedImagesType* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> MediaMetadata::AttachedImagesType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}




MediaMetadata::MediaMetadata()
 {}

MediaMetadata::~MediaMetadata() {}
MediaMetadata::MediaMetadata(MediaMetadata&& rhs)
: mime_type(std::move(rhs.mime_type)),
height(std::move(rhs.height)),
width(std::move(rhs.width)),
duration(std::move(rhs.duration)),
rotation(std::move(rhs.rotation)),
album(std::move(rhs.album)),
artist(std::move(rhs.artist)),
comment(std::move(rhs.comment)),
copyright(std::move(rhs.copyright)),
disc(std::move(rhs.disc)),
genre(std::move(rhs.genre)),
language(std::move(rhs.language)),
title(std::move(rhs.title)),
track(std::move(rhs.track)),
raw_tags(std::move(rhs.raw_tags)),
attached_images(std::move(rhs.attached_images)){
}

MediaMetadata& MediaMetadata::operator=(MediaMetadata&& rhs)
{
mime_type = std::move(rhs.mime_type);
height = std::move(rhs.height);
width = std::move(rhs.width);
duration = std::move(rhs.duration);
rotation = std::move(rhs.rotation);
album = std::move(rhs.album);
artist = std::move(rhs.artist);
comment = std::move(rhs.comment);
copyright = std::move(rhs.copyright);
disc = std::move(rhs.disc);
genre = std::move(rhs.genre);
language = std::move(rhs.language);
title = std::move(rhs.title);
track = std::move(rhs.track);
raw_tags = std::move(rhs.raw_tags);
attached_images = std::move(rhs.attached_images);
return *this;
}

// static
bool MediaMetadata::Populate(
    const base::Value& value, MediaMetadata* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* mime_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("mimeType", &mime_type_value)) {
    return false;
  }
  {
    if (!mime_type_value->GetAsString(&out->mime_type)) {
      return false;
    }
  }

  const base::Value* height_value = NULL;
  if (dict->GetWithoutPathExpansion("height", &height_value)) {
    {
      int temp;
      if (!height_value->GetAsInteger(&temp)) {
        out->height.reset();
        return false;
      }
      else
        out->height.reset(new int(temp));
    }
  }

  const base::Value* width_value = NULL;
  if (dict->GetWithoutPathExpansion("width", &width_value)) {
    {
      int temp;
      if (!width_value->GetAsInteger(&temp)) {
        out->width.reset();
        return false;
      }
      else
        out->width.reset(new int(temp));
    }
  }

  const base::Value* duration_value = NULL;
  if (dict->GetWithoutPathExpansion("duration", &duration_value)) {
    {
      double temp;
      if (!duration_value->GetAsDouble(&temp)) {
        out->duration.reset();
        return false;
      }
      else
        out->duration.reset(new double(temp));
    }
  }

  const base::Value* rotation_value = NULL;
  if (dict->GetWithoutPathExpansion("rotation", &rotation_value)) {
    {
      int temp;
      if (!rotation_value->GetAsInteger(&temp)) {
        out->rotation.reset();
        return false;
      }
      else
        out->rotation.reset(new int(temp));
    }
  }

  const base::Value* album_value = NULL;
  if (dict->GetWithoutPathExpansion("album", &album_value)) {
    {
      std::string temp;
      if (!album_value->GetAsString(&temp)) {
        out->album.reset();
        return false;
      }
      else
        out->album.reset(new std::string(temp));
    }
  }

  const base::Value* artist_value = NULL;
  if (dict->GetWithoutPathExpansion("artist", &artist_value)) {
    {
      std::string temp;
      if (!artist_value->GetAsString(&temp)) {
        out->artist.reset();
        return false;
      }
      else
        out->artist.reset(new std::string(temp));
    }
  }

  const base::Value* comment_value = NULL;
  if (dict->GetWithoutPathExpansion("comment", &comment_value)) {
    {
      std::string temp;
      if (!comment_value->GetAsString(&temp)) {
        out->comment.reset();
        return false;
      }
      else
        out->comment.reset(new std::string(temp));
    }
  }

  const base::Value* copyright_value = NULL;
  if (dict->GetWithoutPathExpansion("copyright", &copyright_value)) {
    {
      std::string temp;
      if (!copyright_value->GetAsString(&temp)) {
        out->copyright.reset();
        return false;
      }
      else
        out->copyright.reset(new std::string(temp));
    }
  }

  const base::Value* disc_value = NULL;
  if (dict->GetWithoutPathExpansion("disc", &disc_value)) {
    {
      int temp;
      if (!disc_value->GetAsInteger(&temp)) {
        out->disc.reset();
        return false;
      }
      else
        out->disc.reset(new int(temp));
    }
  }

  const base::Value* genre_value = NULL;
  if (dict->GetWithoutPathExpansion("genre", &genre_value)) {
    {
      std::string temp;
      if (!genre_value->GetAsString(&temp)) {
        out->genre.reset();
        return false;
      }
      else
        out->genre.reset(new std::string(temp));
    }
  }

  const base::Value* language_value = NULL;
  if (dict->GetWithoutPathExpansion("language", &language_value)) {
    {
      std::string temp;
      if (!language_value->GetAsString(&temp)) {
        out->language.reset();
        return false;
      }
      else
        out->language.reset(new std::string(temp));
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

  const base::Value* track_value = NULL;
  if (dict->GetWithoutPathExpansion("track", &track_value)) {
    {
      int temp;
      if (!track_value->GetAsInteger(&temp)) {
        out->track.reset();
        return false;
      }
      else
        out->track.reset(new int(temp));
    }
  }

  const base::Value* raw_tags_value = NULL;
  if (!dict->GetWithoutPathExpansion("rawTags", &raw_tags_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!raw_tags_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->raw_tags)) {
        return false;
      }
    }
  }

  const base::Value* attached_images_value = NULL;
  if (!dict->GetWithoutPathExpansion("attachedImages", &attached_images_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!attached_images_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->attached_images)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<MediaMetadata> MediaMetadata::FromValue(const base::Value& value) {
  std::unique_ptr<MediaMetadata> out(new MediaMetadata());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MediaMetadata::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("mimeType", std::make_unique<base::Value>(this->mime_type));

  if (this->height.get()) {
    to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(*this->height));

  }
  if (this->width.get()) {
    to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(*this->width));

  }
  if (this->duration.get()) {
    to_value_result->SetWithoutPathExpansion("duration", std::make_unique<base::Value>(*this->duration));

  }
  if (this->rotation.get()) {
    to_value_result->SetWithoutPathExpansion("rotation", std::make_unique<base::Value>(*this->rotation));

  }
  if (this->album.get()) {
    to_value_result->SetWithoutPathExpansion("album", std::make_unique<base::Value>(*this->album));

  }
  if (this->artist.get()) {
    to_value_result->SetWithoutPathExpansion("artist", std::make_unique<base::Value>(*this->artist));

  }
  if (this->comment.get()) {
    to_value_result->SetWithoutPathExpansion("comment", std::make_unique<base::Value>(*this->comment));

  }
  if (this->copyright.get()) {
    to_value_result->SetWithoutPathExpansion("copyright", std::make_unique<base::Value>(*this->copyright));

  }
  if (this->disc.get()) {
    to_value_result->SetWithoutPathExpansion("disc", std::make_unique<base::Value>(*this->disc));

  }
  if (this->genre.get()) {
    to_value_result->SetWithoutPathExpansion("genre", std::make_unique<base::Value>(*this->genre));

  }
  if (this->language.get()) {
    to_value_result->SetWithoutPathExpansion("language", std::make_unique<base::Value>(*this->language));

  }
  if (this->title.get()) {
    to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(*this->title));

  }
  if (this->track.get()) {
    to_value_result->SetWithoutPathExpansion("track", std::make_unique<base::Value>(*this->track));

  }
  to_value_result->SetWithoutPathExpansion("rawTags", json_schema_compiler::util::CreateValueFromArray(this->raw_tags));

  to_value_result->SetWithoutPathExpansion("attachedImages", json_schema_compiler::util::CreateValueFromArray(this->attached_images));


  return to_value_result;
}


AddGalleryWatchResult::AddGalleryWatchResult()
: success(false) {}

AddGalleryWatchResult::~AddGalleryWatchResult() {}
AddGalleryWatchResult::AddGalleryWatchResult(AddGalleryWatchResult&& rhs)
: gallery_id(std::move(rhs.gallery_id)),
success(rhs.success){
}

AddGalleryWatchResult& AddGalleryWatchResult::operator=(AddGalleryWatchResult&& rhs)
{
gallery_id = std::move(rhs.gallery_id);
success = rhs.success;
return *this;
}

// static
bool AddGalleryWatchResult::Populate(
    const base::Value& value, AddGalleryWatchResult* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* gallery_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("galleryId", &gallery_id_value)) {
    return false;
  }
  {
    if (!gallery_id_value->GetAsString(&out->gallery_id)) {
      return false;
    }
  }

  const base::Value* success_value = NULL;
  if (!dict->GetWithoutPathExpansion("success", &success_value)) {
    return false;
  }
  {
    if (!success_value->GetAsBoolean(&out->success)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<AddGalleryWatchResult> AddGalleryWatchResult::FromValue(const base::Value& value) {
  std::unique_ptr<AddGalleryWatchResult> out(new AddGalleryWatchResult());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AddGalleryWatchResult::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("galleryId", std::make_unique<base::Value>(this->gallery_id));

  to_value_result->SetWithoutPathExpansion("success", std::make_unique<base::Value>(this->success));


  return to_value_result;
}



//
// Functions
//

namespace GetMediaFileSystems {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* details_value = NULL;
  if (args.Get(0, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<MediaFileSystemsDetails> temp(new MediaFileSystemsDetails());
        if (!MediaFileSystemsDetails::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->details = std::move(temp);
      }
    }
  }

  return params;
}


Results::MediaFileSystemsType::MediaFileSystemsType()
 {}

Results::MediaFileSystemsType::~MediaFileSystemsType() {}
Results::MediaFileSystemsType::MediaFileSystemsType(MediaFileSystemsType&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::MediaFileSystemsType& Results::MediaFileSystemsType::operator=(MediaFileSystemsType&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::MediaFileSystemsType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



std::unique_ptr<base::ListValue> Results::Create(const std::vector<MediaFileSystemsType>& media_file_systems) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(media_file_systems));

  return create_results;
}
}  // namespace GetMediaFileSystems

namespace AddUserSelectedFolder {

Results::MediaFileSystemsType::MediaFileSystemsType()
 {}

Results::MediaFileSystemsType::~MediaFileSystemsType() {}
Results::MediaFileSystemsType::MediaFileSystemsType(MediaFileSystemsType&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::MediaFileSystemsType& Results::MediaFileSystemsType::operator=(MediaFileSystemsType&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::MediaFileSystemsType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



std::unique_ptr<base::ListValue> Results::Create(const std::vector<MediaFileSystemsType>& media_file_systems, const std::string& selected_file_system_name) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(media_file_systems));

  create_results->Append(std::make_unique<base::Value>(selected_file_system_name));

  return create_results;
}
}  // namespace AddUserSelectedFolder

namespace GetMetadata {

Params::MediaFile::MediaFile()
 {}

Params::MediaFile::~MediaFile() {}
Params::MediaFile::MediaFile(MediaFile&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::MediaFile& Params::MediaFile::operator=(MediaFile&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::MediaFile::Populate(
    const base::Value& value, MediaFile* out) {
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
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* media_file_value = NULL;
  if (args.Get(0, &media_file_value) &&
      !media_file_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!media_file_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!MediaFile::Populate(*dictionary, &params->media_file)) {
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
      else {
        std::unique_ptr<MediaMetadataOptions> temp(new MediaMetadataOptions());
        if (!MediaMetadataOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const MediaMetadata& metadata) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((metadata).ToValue());

  return create_results;
}
}  // namespace GetMetadata

namespace AddGalleryWatch {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* gallery_id_value = NULL;
  if (args.Get(0, &gallery_id_value) &&
      !gallery_id_value->is_none()) {
    {
      if (!gallery_id_value->GetAsString(&params->gallery_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const AddGalleryWatchResult& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace AddGalleryWatch

namespace RemoveGalleryWatch {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* gallery_id_value = NULL;
  if (args.Get(0, &gallery_id_value) &&
      !gallery_id_value->is_none()) {
    {
      if (!gallery_id_value->GetAsString(&params->gallery_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace RemoveGalleryWatch

//
// Events
//

namespace OnGalleryChanged {

const char kEventName[] = "mediaGalleries.onGalleryChanged";

std::unique_ptr<base::ListValue> Create(const GalleryChangeDetails& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnGalleryChanged

}  // namespace media_galleries
}  // namespace api
}  // namespace chrome_apps

