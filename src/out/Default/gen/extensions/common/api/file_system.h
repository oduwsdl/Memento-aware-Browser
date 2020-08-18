// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/file_system.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_FILE_SYSTEM_H__
#define EXTENSIONS_COMMON_API_FILE_SYSTEM_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace file_system {

//
// Types
//

struct AcceptOption {
  AcceptOption();
  ~AcceptOption();
  AcceptOption(AcceptOption&& rhs);
  AcceptOption& operator=(AcceptOption&& rhs);

  // Populates a AcceptOption object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, AcceptOption* out);

  // Creates a AcceptOption object from a base::Value, or NULL on failure.
  static std::unique_ptr<AcceptOption> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AcceptOption object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // This is the optional text description for this option. If not present, a
  // description will be automatically generated; typically containing an expanded
  // list of valid extensions (e.g. "text/html" may expand to "*.html, *.htm").
  std::unique_ptr<std::string> description;

  // Mime-types to accept, e.g. "image/jpeg" or "audio/*". One of mimeTypes or
  // extensions must contain at least one valid element.
  std::unique_ptr<std::vector<std::string>> mime_types;

  // Extensions to accept, e.g. "jpg", "gif", "crx".
  std::unique_ptr<std::vector<std::string>> extensions;


 private:
  DISALLOW_COPY_AND_ASSIGN(AcceptOption);
};

enum ChooseEntryType {
  CHOOSE_ENTRY_TYPE_NONE,
  CHOOSE_ENTRY_TYPE_OPENFILE,
  CHOOSE_ENTRY_TYPE_OPENWRITABLEFILE,
  CHOOSE_ENTRY_TYPE_SAVEFILE,
  CHOOSE_ENTRY_TYPE_OPENDIRECTORY,
  CHOOSE_ENTRY_TYPE_LAST = CHOOSE_ENTRY_TYPE_OPENDIRECTORY,
};


const char* ToString(ChooseEntryType as_enum);
ChooseEntryType ParseChooseEntryType(const std::string& as_string);

struct ChooseEntryOptions {
  ChooseEntryOptions();
  ~ChooseEntryOptions();
  ChooseEntryOptions(ChooseEntryOptions&& rhs);
  ChooseEntryOptions& operator=(ChooseEntryOptions&& rhs);

  // Populates a ChooseEntryOptions object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ChooseEntryOptions* out);

  // Creates a ChooseEntryOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<ChooseEntryOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ChooseEntryOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Type of the prompt to show. The default is 'openFile'.
  ChooseEntryType type;

  // The suggested file name that will be presented to the user as the default
  // name to read or write. This is optional.
  std::unique_ptr<std::string> suggested_name;

  // The optional list of accept options for this file opener. Each option will be
  // presented as a unique group to the end-user.
  std::unique_ptr<std::vector<AcceptOption>> accepts;

  // Whether to accept all file types, in addition to the options specified in the
  // accepts argument. The default is true. If the accepts field is unset or
  // contains no valid entries, this will always be reset to true.
  std::unique_ptr<bool> accepts_all_types;

  // Whether to accept multiple files. This is only supported for openFile and
  // openWritableFile. The callback to chooseEntry will be called with a list of
  // entries if this is set to true. Otherwise it will be called with a single
  // Entry.
  std::unique_ptr<bool> accepts_multiple;


 private:
  DISALLOW_COPY_AND_ASSIGN(ChooseEntryOptions);
};

struct RequestFileSystemOptions {
  RequestFileSystemOptions();
  ~RequestFileSystemOptions();
  RequestFileSystemOptions(RequestFileSystemOptions&& rhs);
  RequestFileSystemOptions& operator=(RequestFileSystemOptions&& rhs);

  // Populates a RequestFileSystemOptions object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, RequestFileSystemOptions* out);

  // Creates a RequestFileSystemOptions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<RequestFileSystemOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RequestFileSystemOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the requested volume.
  std::string volume_id;

  // Whether the requested file system should be writable. The default is
  // read-only.
  std::unique_ptr<bool> writable;


 private:
  DISALLOW_COPY_AND_ASSIGN(RequestFileSystemOptions);
};

struct Volume {
  Volume();
  ~Volume();
  Volume(Volume&& rhs);
  Volume& operator=(Volume&& rhs);

  // Populates a Volume object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Volume* out);

  // Creates a Volume object from a base::Value, or NULL on failure.
  static std::unique_ptr<Volume> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Volume object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string volume_id;

  bool writable;


 private:
  DISALLOW_COPY_AND_ASSIGN(Volume);
};

struct VolumeListChangedEvent {
  VolumeListChangedEvent();
  ~VolumeListChangedEvent();
  VolumeListChangedEvent(VolumeListChangedEvent&& rhs);
  VolumeListChangedEvent& operator=(VolumeListChangedEvent&& rhs);

  // Populates a VolumeListChangedEvent object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, VolumeListChangedEvent* out);

  // Creates a VolumeListChangedEvent object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<VolumeListChangedEvent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this VolumeListChangedEvent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::vector<Volume> volumes;


 private:
  DISALLOW_COPY_AND_ASSIGN(VolumeListChangedEvent);
};


//
// Functions
//

namespace GetDisplayPath {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Entry {
    Entry();
    ~Entry();
    Entry(Entry&& rhs);
    Entry& operator=(Entry&& rhs);

    // Populates a Entry object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Entry* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Entry);
  };


  Entry entry;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& display_path);
}  // namespace Results

}  // namespace GetDisplayPath

namespace GetWritableEntry {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Entry {
    Entry();
    ~Entry();
    Entry(Entry&& rhs);
    Entry& operator=(Entry&& rhs);

    // Populates a Entry object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Entry* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Entry);
  };


  Entry entry;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Entry {
  Entry();
  ~Entry();
  Entry(Entry&& rhs);
  Entry& operator=(Entry&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Entry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Entry);
};


std::unique_ptr<base::ListValue> Create(const Entry& entry);
}  // namespace Results

}  // namespace GetWritableEntry

namespace IsWritableEntry {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Entry {
    Entry();
    ~Entry();
    Entry(Entry&& rhs);
    Entry& operator=(Entry&& rhs);

    // Populates a Entry object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Entry* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Entry);
  };


  Entry entry;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool is_writable);
}  // namespace Results

}  // namespace IsWritableEntry

namespace ChooseEntry {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::unique_ptr<ChooseEntryOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Entry {
  Entry();
  ~Entry();
  Entry(Entry&& rhs);
  Entry& operator=(Entry&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Entry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Entry);
};

struct FileEntriesType {
  FileEntriesType();
  ~FileEntriesType();
  FileEntriesType(FileEntriesType&& rhs);
  FileEntriesType& operator=(FileEntriesType&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FileEntriesType object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(FileEntriesType);
};



std::unique_ptr<base::ListValue> Create(const Entry& entry, const std::vector<FileEntriesType>& file_entries);
}  // namespace Results

}  // namespace ChooseEntry

namespace RestoreEntry {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Entry {
  Entry();
  ~Entry();
  Entry(Entry&& rhs);
  Entry& operator=(Entry&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Entry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Entry);
};


std::unique_ptr<base::ListValue> Create(const Entry& entry);
}  // namespace Results

}  // namespace RestoreEntry

namespace IsRestorable {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool is_restorable);
}  // namespace Results

}  // namespace IsRestorable

namespace RetainEntry {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Entry {
    Entry();
    ~Entry();
    Entry(Entry&& rhs);
    Entry& operator=(Entry&& rhs);

    // Populates a Entry object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Entry* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Entry);
  };


  Entry entry;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RetainEntry

namespace RequestFileSystem {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestFileSystemOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct FileSystem {
  FileSystem();
  ~FileSystem();
  FileSystem(FileSystem&& rhs);
  FileSystem& operator=(FileSystem&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FileSystem object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(FileSystem);
};


std::unique_ptr<base::ListValue> Create(const FileSystem& file_system);
}  // namespace Results

}  // namespace RequestFileSystem

namespace GetVolumeList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Volume>& volumes);
}  // namespace Results

}  // namespace GetVolumeList

//
// Events
//

namespace OnVolumeListChanged {

extern const char kEventName[];  // "fileSystem.onVolumeListChanged"

std::unique_ptr<base::ListValue> Create(const VolumeListChangedEvent& event);
}  // namespace OnVolumeListChanged

}  // namespace file_system
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_FILE_SYSTEM_H__
