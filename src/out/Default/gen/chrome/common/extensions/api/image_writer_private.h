// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/image_writer_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_IMAGE_WRITER_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_IMAGE_WRITER_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace image_writer_private {

//
// Types
//

// <p>The different stages of a write call.</p><p><dl>    <dt>confirmation</dt>
// <dd>The process starts by prompting the user for confirmation.</dd>
// <dt>download</dt>    <dd>The image file is being download if a remote image
// was    requested.</dd>    <dt>verifyDownload</dt>    <dd>The download is
// being verified to match the image hash, if    provided</dd>    <dt>unzip</dt>
// <dd>The image is being extracted from the downloaded zip file</dd>
// <dt>write</dt>    <dd>The image is being written to disk.</dd>
// <dt>verifyWrite</dt>    <dt>The system is verifying that the written image
// matches the    downloaded image.</dd> <dl></p>
enum Stage {
  STAGE_NONE,
  STAGE_CONFIRMATION,
  STAGE_DOWNLOAD,
  STAGE_VERIFYDOWNLOAD,
  STAGE_UNZIP,
  STAGE_WRITE,
  STAGE_VERIFYWRITE,
  STAGE_UNKNOWN,
  STAGE_LAST = STAGE_UNKNOWN,
};


const char* ToString(Stage as_enum);
Stage ParseStage(const std::string& as_string);

struct UrlWriteOptions {
  UrlWriteOptions();
  ~UrlWriteOptions();
  UrlWriteOptions(UrlWriteOptions&& rhs);
  UrlWriteOptions& operator=(UrlWriteOptions&& rhs);

  // Populates a UrlWriteOptions object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, UrlWriteOptions* out);

  // Creates a UrlWriteOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<UrlWriteOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this UrlWriteOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // If present, verify that the downloaded image matches this hash.
  std::unique_ptr<std::string> image_hash;

  // If true, save the downloaded image as a file using the user's downloads
  // preferences.
  std::unique_ptr<bool> save_as_download;


 private:
  DISALLOW_COPY_AND_ASSIGN(UrlWriteOptions);
};

struct ProgressInfo {
  ProgressInfo();
  ~ProgressInfo();
  ProgressInfo(ProgressInfo&& rhs);
  ProgressInfo& operator=(ProgressInfo&& rhs);

  // Populates a ProgressInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ProgressInfo* out);

  // Creates a ProgressInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ProgressInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ProgressInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The $(ref:Stage) that the write process is currently in.
  Stage stage;

  // Current progress within the stage.
  int percent_complete;


 private:
  DISALLOW_COPY_AND_ASSIGN(ProgressInfo);
};

struct RemovableStorageDevice {
  RemovableStorageDevice();
  ~RemovableStorageDevice();
  RemovableStorageDevice(RemovableStorageDevice&& rhs);
  RemovableStorageDevice& operator=(RemovableStorageDevice&& rhs);

  // Populates a RemovableStorageDevice object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, RemovableStorageDevice* out);

  // Creates a RemovableStorageDevice object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<RemovableStorageDevice> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RemovableStorageDevice object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string storage_unit_id;

  double capacity;

  std::string vendor;

  std::string model;

  bool removable;


 private:
  DISALLOW_COPY_AND_ASSIGN(RemovableStorageDevice);
};


//
// Functions
//

namespace WriteFromUrl {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The identifier for the storage unit
  std::string storage_unit_id;

  // The url of the image to download which will be written to the storage unit
  // identified by |storageUnitId|
  std::string image_url;

  // Optional parameters if comparing the download with a given hash or saving the
  // download to the users Downloads folder instead of a temporary directory is
  // desired
  std::unique_ptr<UrlWriteOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace WriteFromUrl

namespace WriteFromFile {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The FileEntry object of the image to be burned.
  struct FileEntry {
    FileEntry();
    ~FileEntry();
    FileEntry(FileEntry&& rhs);
    FileEntry& operator=(FileEntry&& rhs);

    // Populates a FileEntry object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, FileEntry* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(FileEntry);
  };


  // The identifier for the storage unit
  std::string storage_unit_id;

  // The FileEntry object of the image to be burned.
  FileEntry file_entry;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace WriteFromFile

namespace CancelWrite {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace CancelWrite

namespace DestroyPartitions {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The identifier of the storage unit to wipe
  std::string storage_unit_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DestroyPartitions

namespace ListRemovableStorageDevices {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<RemovableStorageDevice>& devices);
}  // namespace Results

}  // namespace ListRemovableStorageDevices

//
// Events
//

namespace OnWriteProgress {

extern const char kEventName[];  // "imageWriterPrivate.onWriteProgress"

std::unique_ptr<base::ListValue> Create(const ProgressInfo& info);
}  // namespace OnWriteProgress

namespace OnWriteComplete {

extern const char kEventName[];  // "imageWriterPrivate.onWriteComplete"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnWriteComplete

namespace OnWriteError {

extern const char kEventName[];  // "imageWriterPrivate.onWriteError"

std::unique_ptr<base::ListValue> Create(const ProgressInfo& info, const std::string& error);
}  // namespace OnWriteError

namespace OnDeviceInserted {

extern const char kEventName[];  // "imageWriterPrivate.onDeviceInserted"

std::unique_ptr<base::ListValue> Create(const RemovableStorageDevice& device);
}  // namespace OnDeviceInserted

namespace OnDeviceRemoved {

extern const char kEventName[];  // "imageWriterPrivate.onDeviceRemoved"

std::unique_ptr<base::ListValue> Create(const RemovableStorageDevice& device);
}  // namespace OnDeviceRemoved

}  // namespace image_writer_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_IMAGE_WRITER_PRIVATE_H__
