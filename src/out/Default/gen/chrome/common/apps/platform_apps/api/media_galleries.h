// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/apps/platform_apps/api/media_galleries.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_APPS_PLATFORM_APPS_API_MEDIA_GALLERIES_H__
#define CHROME_COMMON_APPS_PLATFORM_APPS_API_MEDIA_GALLERIES_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace chrome_apps {
namespace api {
namespace media_galleries {

//
// Types
//

enum GalleryChangeType {
  GALLERY_CHANGE_TYPE_NONE,
  GALLERY_CHANGE_TYPE_CONTENTS_CHANGED,
  GALLERY_CHANGE_TYPE_WATCH_DROPPED,
  GALLERY_CHANGE_TYPE_LAST = GALLERY_CHANGE_TYPE_WATCH_DROPPED,
};


const char* ToString(GalleryChangeType as_enum);
GalleryChangeType ParseGalleryChangeType(const std::string& as_string);

enum GetMediaFileSystemsInteractivity {
  GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_NONE,
  GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_NO,
  GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_YES,
  GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_IF_NEEDED,
  GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_LAST = GET_MEDIA_FILE_SYSTEMS_INTERACTIVITY_IF_NEEDED,
};


const char* ToString(GetMediaFileSystemsInteractivity as_enum);
GetMediaFileSystemsInteractivity ParseGetMediaFileSystemsInteractivity(const std::string& as_string);

enum GetMetadataType {
  GET_METADATA_TYPE_NONE,
  GET_METADATA_TYPE_ALL,
  GET_METADATA_TYPE_MIMETYPEANDTAGS,
  GET_METADATA_TYPE_MIMETYPEONLY,
  GET_METADATA_TYPE_LAST = GET_METADATA_TYPE_MIMETYPEONLY,
};


const char* ToString(GetMetadataType as_enum);
GetMetadataType ParseGetMetadataType(const std::string& as_string);

struct GalleryChangeDetails {
  GalleryChangeDetails();
  ~GalleryChangeDetails();
  GalleryChangeDetails(GalleryChangeDetails&& rhs);
  GalleryChangeDetails& operator=(GalleryChangeDetails&& rhs);

  // Populates a GalleryChangeDetails object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, GalleryChangeDetails* out);

  // Creates a GalleryChangeDetails object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<GalleryChangeDetails> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this GalleryChangeDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Type of change event.
  GalleryChangeType type;

  // Identifies the modified gallery.
  std::string gallery_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(GalleryChangeDetails);
};

struct MediaFileSystemsDetails {
  MediaFileSystemsDetails();
  ~MediaFileSystemsDetails();
  MediaFileSystemsDetails(MediaFileSystemsDetails&& rhs);
  MediaFileSystemsDetails& operator=(MediaFileSystemsDetails&& rhs);

  // Populates a MediaFileSystemsDetails object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, MediaFileSystemsDetails* out);

  // Creates a MediaFileSystemsDetails object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<MediaFileSystemsDetails> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MediaFileSystemsDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Whether to prompt the user for permission to additional media galleries
  // before returning the permitted set. Default is silent.  If the value 'yes' is
  // passed, or if the application has not been granted access to any media
  // galleries and the value 'if_needed' is passed, then the media gallery
  // configuration dialog will be displayed.
  GetMediaFileSystemsInteractivity interactive;


 private:
  DISALLOW_COPY_AND_ASSIGN(MediaFileSystemsDetails);
};

struct MediaMetadataOptions {
  MediaMetadataOptions();
  ~MediaMetadataOptions();
  MediaMetadataOptions(MediaMetadataOptions&& rhs);
  MediaMetadataOptions& operator=(MediaMetadataOptions&& rhs);

  // Populates a MediaMetadataOptions object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, MediaMetadataOptions* out);

  // Creates a MediaMetadataOptions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<MediaMetadataOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MediaMetadataOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Specifies which subset of the metadata to retrieve. Defaults to 'all' if the
  // option is omitted.
  GetMetadataType metadata_type;


 private:
  DISALLOW_COPY_AND_ASSIGN(MediaMetadataOptions);
};

struct MediaFileSystemMetadata {
  MediaFileSystemMetadata();
  ~MediaFileSystemMetadata();
  MediaFileSystemMetadata(MediaFileSystemMetadata&& rhs);
  MediaFileSystemMetadata& operator=(MediaFileSystemMetadata&& rhs);

  // Populates a MediaFileSystemMetadata object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, MediaFileSystemMetadata* out);

  // Creates a MediaFileSystemMetadata object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<MediaFileSystemMetadata> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MediaFileSystemMetadata object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The name of the file system.
  std::string name;

  // A unique and persistent id for the media gallery.
  std::string gallery_id;

  // If the media gallery is on a removable device, a unique id for the device
  // while the device is online.
  std::unique_ptr<std::string> device_id;

  // True if the media gallery is on a removable device.
  bool is_removable;

  // True if the device the media gallery is on was detected as a media device.
  // i.e. a PTP or MTP device, or a DCIM directory is present.
  bool is_media_device;

  // True if the device is currently available.
  bool is_available;


 private:
  DISALLOW_COPY_AND_ASSIGN(MediaFileSystemMetadata);
};

struct StreamInfo {
  StreamInfo();
  ~StreamInfo();
  StreamInfo(StreamInfo&& rhs);
  StreamInfo& operator=(StreamInfo&& rhs);

  // Populates a StreamInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, StreamInfo* out);

  // Creates a StreamInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<StreamInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this StreamInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // An unfiltered string->string dictionary of tags for the stream.
  struct Tags {
    Tags();
    ~Tags();
    Tags(Tags&& rhs);
    Tags& operator=(Tags&& rhs);

    // Populates a Tags object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Tags* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Tags object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Tags);
  };


  // Describes format of container or codec of stream, i.e. "mp3", "h264".
  std::string type;

  // An unfiltered string->string dictionary of tags for the stream.
  Tags tags;


 private:
  DISALLOW_COPY_AND_ASSIGN(StreamInfo);
};

struct MediaMetadata {
  MediaMetadata();
  ~MediaMetadata();
  MediaMetadata(MediaMetadata&& rhs);
  MediaMetadata& operator=(MediaMetadata&& rhs);

  // Populates a MediaMetadata object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, MediaMetadata* out);

  // Creates a MediaMetadata object from a base::Value, or NULL on failure.
  static std::unique_ptr<MediaMetadata> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MediaMetadata object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  struct AttachedImagesType {
    AttachedImagesType();
    ~AttachedImagesType();
    AttachedImagesType(AttachedImagesType&& rhs);
    AttachedImagesType& operator=(AttachedImagesType&& rhs);

    // Populates a AttachedImagesType object from a base::Value. Returns whether
    // |out| was successfully populated.
    static bool Populate(const base::Value& value, AttachedImagesType* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this AttachedImagesType object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(AttachedImagesType);
  };



  // The browser sniffed mime type.
  std::string mime_type;

  // Defined for video. In pixels.
  std::unique_ptr<int> height;

  std::unique_ptr<int> width;

  // Defined for audio and video. In seconds.
  std::unique_ptr<double> duration;

  // Defined for video. In degrees.
  std::unique_ptr<int> rotation;

  // Defined for audio and video.
  std::unique_ptr<std::string> album;

  std::unique_ptr<std::string> artist;

  std::unique_ptr<std::string> comment;

  std::unique_ptr<std::string> copyright;

  std::unique_ptr<int> disc;

  std::unique_ptr<std::string> genre;

  std::unique_ptr<std::string> language;

  std::unique_ptr<std::string> title;

  std::unique_ptr<int> track;

  // All the metadata in the media file. For formats with multiple streams, stream
  // order will be preserved. Container metadata is the first element.
  std::vector<StreamInfo> raw_tags;

  // The images embedded in the media file's metadata. This is most often used for
  // album art or video thumbnails.
  std::vector<AttachedImagesType> attached_images;


 private:
  DISALLOW_COPY_AND_ASSIGN(MediaMetadata);
};

struct AddGalleryWatchResult {
  AddGalleryWatchResult();
  ~AddGalleryWatchResult();
  AddGalleryWatchResult(AddGalleryWatchResult&& rhs);
  AddGalleryWatchResult& operator=(AddGalleryWatchResult&& rhs);

  // Populates a AddGalleryWatchResult object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, AddGalleryWatchResult* out);

  // Creates a AddGalleryWatchResult object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<AddGalleryWatchResult> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AddGalleryWatchResult object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string gallery_id;

  bool success;


 private:
  DISALLOW_COPY_AND_ASSIGN(AddGalleryWatchResult);
};


//
// Functions
//

namespace GetMediaFileSystems {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::unique_ptr<MediaFileSystemsDetails> details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct MediaFileSystemsType {
  MediaFileSystemsType();
  ~MediaFileSystemsType();
  MediaFileSystemsType(MediaFileSystemsType&& rhs);
  MediaFileSystemsType& operator=(MediaFileSystemsType&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MediaFileSystemsType object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(MediaFileSystemsType);
};



std::unique_ptr<base::ListValue> Create(const std::vector<MediaFileSystemsType>& media_file_systems);
}  // namespace Results

}  // namespace GetMediaFileSystems

namespace AddUserSelectedFolder {

namespace Results {

struct MediaFileSystemsType {
  MediaFileSystemsType();
  ~MediaFileSystemsType();
  MediaFileSystemsType(MediaFileSystemsType&& rhs);
  MediaFileSystemsType& operator=(MediaFileSystemsType&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MediaFileSystemsType object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(MediaFileSystemsType);
};



std::unique_ptr<base::ListValue> Create(const std::vector<MediaFileSystemsType>& media_file_systems, const std::string& selected_file_system_name);
}  // namespace Results

}  // namespace AddUserSelectedFolder

namespace GetMetadata {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct MediaFile {
    MediaFile();
    ~MediaFile();
    MediaFile(MediaFile&& rhs);
    MediaFile& operator=(MediaFile&& rhs);

    // Populates a MediaFile object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, MediaFile* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(MediaFile);
  };


  MediaFile media_file;

  std::unique_ptr<MediaMetadataOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const MediaMetadata& metadata);
}  // namespace Results

}  // namespace GetMetadata

namespace AddGalleryWatch {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string gallery_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const AddGalleryWatchResult& result);
}  // namespace Results

}  // namespace AddGalleryWatch

namespace RemoveGalleryWatch {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string gallery_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RemoveGalleryWatch

//
// Events
//

namespace OnGalleryChanged {

extern const char kEventName[];  // "mediaGalleries.onGalleryChanged"

std::unique_ptr<base::ListValue> Create(const GalleryChangeDetails& details);
}  // namespace OnGalleryChanged

}  // namespace media_galleries
}  // namespace api
}  // namespace chrome_apps
#endif  // CHROME_COMMON_APPS_PLATFORM_APPS_API_MEDIA_GALLERIES_H__
