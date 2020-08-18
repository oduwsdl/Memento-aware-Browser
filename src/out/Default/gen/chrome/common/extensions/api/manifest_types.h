// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/manifest_types.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_MANIFEST_TYPES_H__
#define CHROME_COMMON_EXTENSIONS_API_MANIFEST_TYPES_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace manifest_types {

//
// Types
//

// Chrome settings which can be overriden by an extension.
struct ChromeSettingsOverrides {
  ChromeSettingsOverrides();
  ~ChromeSettingsOverrides();
  ChromeSettingsOverrides(ChromeSettingsOverrides&& rhs);
  ChromeSettingsOverrides& operator=(ChromeSettingsOverrides&& rhs);

  // Populates a ChromeSettingsOverrides object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ChromeSettingsOverrides* out, base::string16* error);

  // Creates a ChromeSettingsOverrides object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ChromeSettingsOverrides> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ChromeSettingsOverrides object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // A search engine
  struct Search_provider {
    Search_provider();
    ~Search_provider();
    Search_provider(Search_provider&& rhs);
    Search_provider& operator=(Search_provider&& rhs);

    // Populates a Search_provider object from a base::Value. Returns whether
    // |out| was successfully populated.
    static bool Populate(const base::Value& value, Search_provider* out, base::string16* error);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Search_provider object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    // Name of the search engine displayed to user. This may only be omitted if
    // <em>prepopulated_id</em> is set.
    std::unique_ptr<std::string> name;

    // Omnibox keyword for the search engine. This may only be omitted if
    // <em>prepopulated_id</em> is set.
    std::unique_ptr<std::string> keyword;

    // An icon URL for the search engine. This may only be omitted if
    // <em>prepopulated_id</em> is set.
    std::unique_ptr<std::string> favicon_url;

    // An search URL used by the search engine.
    std::string search_url;

    // Encoding of the search term. This may only be omitted if
    // <em>prepopulated_id</em> is set.
    std::unique_ptr<std::string> encoding;

    // If omitted, this engine does not support suggestions.
    std::unique_ptr<std::string> suggest_url;

    // If omitted, this engine does not support image search.
    std::unique_ptr<std::string> image_url;

    // The string of post parameters to search_url
    std::unique_ptr<std::string> search_url_post_params;

    // The string of post parameters to suggest_url
    std::unique_ptr<std::string> suggest_url_post_params;

    // The string of post parameters to image_url
    std::unique_ptr<std::string> image_url_post_params;

    // A list of URL patterns that can be used, in addition to |search_url|.
    std::unique_ptr<std::vector<std::string>> alternate_urls;

    // An ID of the built-in search engine in Chrome.
    std::unique_ptr<int> prepopulated_id;

    // Specifies if the search provider should be default.
    bool is_default;


   private:
    DISALLOW_COPY_AND_ASSIGN(Search_provider);
  };


  // New value for the homepage.
  std::unique_ptr<std::string> homepage;

  // A search engine
  std::unique_ptr<Search_provider> search_provider;

  // An array of length one containing a URL to be used as the startup page.
  std::unique_ptr<std::vector<std::string>> startup_pages;


 private:
  DISALLOW_COPY_AND_ASSIGN(ChromeSettingsOverrides);
};

// For <code>"file"</code> the source is a file passed via
// <code>onLaunched</code> event. For <code>"device"</code> contents are fetched
// from an external device (eg. plugged via USB), without using
// <code>file_handlers</code>. Finally, for <code>"network"</code> source,
// contents should be fetched via network.
enum FileSystemProviderSource {
  FILE_SYSTEM_PROVIDER_SOURCE_NONE,
  FILE_SYSTEM_PROVIDER_SOURCE_FILE,
  FILE_SYSTEM_PROVIDER_SOURCE_DEVICE,
  FILE_SYSTEM_PROVIDER_SOURCE_NETWORK,
  FILE_SYSTEM_PROVIDER_SOURCE_LAST = FILE_SYSTEM_PROVIDER_SOURCE_NETWORK,
};


const char* ToString(FileSystemProviderSource as_enum);
FileSystemProviderSource ParseFileSystemProviderSource(const std::string& as_string);

// Represents capabilities of a providing extension.
struct FileSystemProviderCapabilities {
  FileSystemProviderCapabilities();
  ~FileSystemProviderCapabilities();
  FileSystemProviderCapabilities(FileSystemProviderCapabilities&& rhs);
  FileSystemProviderCapabilities& operator=(FileSystemProviderCapabilities&& rhs);

  // Populates a FileSystemProviderCapabilities object from a base::Value.
  // Returns whether |out| was successfully populated.
  static bool Populate(const base::Value& value, FileSystemProviderCapabilities* out, base::string16* error);

  // Creates a FileSystemProviderCapabilities object from a base::Value, or NULL
  // on failure.
  static std::unique_ptr<FileSystemProviderCapabilities> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FileSystemProviderCapabilities object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Whether configuring via <code>onConfigureRequested</code> is supported. By
  // default: <code>false</code>.
  std::unique_ptr<bool> configurable;

  // Whether multiple (more than one) mounted file systems are supported. By
  // default: <code>false</code>.
  std::unique_ptr<bool> multiple_mounts;

  // Whether setting watchers and notifying about changes is supported. By
  // default: <code>false</code>.
  std::unique_ptr<bool> watchable;

  // Source of data for mounted file systems.
  FileSystemProviderSource source;


 private:
  DISALLOW_COPY_AND_ASSIGN(FileSystemProviderCapabilities);
};


}  // namespace manifest_types
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_MANIFEST_TYPES_H__
