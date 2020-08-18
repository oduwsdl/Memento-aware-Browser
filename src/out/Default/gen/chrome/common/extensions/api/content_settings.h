// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/content_settings.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_CONTENT_SETTINGS_H__
#define CHROME_COMMON_EXTENSIONS_API_CONTENT_SETTINGS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace content_settings {

//
// Properties
//

//
// Types
//

// The only content type using resource identifiers is
// $(ref:contentSettings.plugins). For more information, see <a
// href="contentSettings#resource-identifiers">Resource Identifiers</a>.
struct ResourceIdentifier {
  ResourceIdentifier();
  ~ResourceIdentifier();
  ResourceIdentifier(ResourceIdentifier&& rhs);
  ResourceIdentifier& operator=(ResourceIdentifier&& rhs);

  // Populates a ResourceIdentifier object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ResourceIdentifier* out);

  // Creates a ResourceIdentifier object from a base::Value, or NULL on failure.
  static std::unique_ptr<ResourceIdentifier> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ResourceIdentifier object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The resource identifier for the given content type.
  std::string id;

  // A human readable description of the resource.
  std::unique_ptr<std::string> description;


 private:
  DISALLOW_COPY_AND_ASSIGN(ResourceIdentifier);
};

// The scope of the ContentSetting. One of<br><var>regular</var>: setting for
// regular profile (which is inherited by the incognito profile if not
// overridden elsewhere),<br><var>incognito_session_only</var>: setting for
// incognito profile that can only be set during an incognito session and is
// deleted when the incognito session ends (overrides regular settings).
enum Scope {
  SCOPE_NONE,
  SCOPE_REGULAR,
  SCOPE_INCOGNITO_SESSION_ONLY,
  SCOPE_LAST = SCOPE_INCOGNITO_SESSION_ONLY,
};


const char* ToString(Scope as_enum);
Scope ParseScope(const std::string& as_string);

namespace ContentSetting {

namespace Clear {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // Where to clear the setting (default: regular).
    Scope scope;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Clear

namespace Get {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The primary URL for which the content setting should be retrieved. Note that
    // the meaning of a primary URL depends on the content type.
    std::string primary_url;

    // The secondary URL for which the content setting should be retrieved. Defaults
    // to the primary URL. Note that the meaning of a secondary URL depends on the
    // content type, and not all content types use secondary URLs.
    std::unique_ptr<std::string> secondary_url;

    // A more specific identifier of the type of content for which the settings
    // should be retrieved.
    std::unique_ptr<ResourceIdentifier> resource_identifier;

    // Whether to check the content settings for an incognito session. (default
    // false)
    std::unique_ptr<bool> incognito;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The content setting. See the description of the individual ContentSetting
  // objects for the possible values.
  std::unique_ptr<base::Value> setting;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace Results

}  // namespace Get

namespace Set {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The pattern for the primary URL. For details on the format of a pattern, see
    // <a href='contentSettings#patterns'>Content Setting Patterns</a>.
    std::string primary_pattern;

    // The pattern for the secondary URL. Defaults to matching all URLs. For details
    // on the format of a pattern, see <a href='contentSettings#patterns'>Content
    // Setting Patterns</a>.
    std::unique_ptr<std::string> secondary_pattern;

    // The resource identifier for the content type.
    std::unique_ptr<ResourceIdentifier> resource_identifier;

    // The setting applied by this rule. See the description of the individual
    // ContentSetting objects for the possible values.
    std::unique_ptr<base::Value> setting;

    // Where to set the setting (default: regular).
    Scope scope;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Set

namespace GetResourceIdentifiers {

namespace Results {

// A list of resource identifiers for this content type, or <var>undefined</var>
// if this content type does not use resource identifiers.
std::unique_ptr<base::ListValue> Create(const std::vector<ResourceIdentifier>& resource_identifiers);
}  // namespace Results

}  // namespace GetResourceIdentifiers

}  // namespace ContentSetting

enum CookiesContentSetting {
  COOKIES_CONTENT_SETTING_NONE,
  COOKIES_CONTENT_SETTING_ALLOW,
  COOKIES_CONTENT_SETTING_BLOCK,
  COOKIES_CONTENT_SETTING_SESSION_ONLY,
  COOKIES_CONTENT_SETTING_LAST = COOKIES_CONTENT_SETTING_SESSION_ONLY,
};


const char* ToString(CookiesContentSetting as_enum);
CookiesContentSetting ParseCookiesContentSetting(const std::string& as_string);

enum ImagesContentSetting {
  IMAGES_CONTENT_SETTING_NONE,
  IMAGES_CONTENT_SETTING_ALLOW,
  IMAGES_CONTENT_SETTING_BLOCK,
  IMAGES_CONTENT_SETTING_LAST = IMAGES_CONTENT_SETTING_BLOCK,
};


const char* ToString(ImagesContentSetting as_enum);
ImagesContentSetting ParseImagesContentSetting(const std::string& as_string);

enum JavascriptContentSetting {
  JAVASCRIPT_CONTENT_SETTING_NONE,
  JAVASCRIPT_CONTENT_SETTING_ALLOW,
  JAVASCRIPT_CONTENT_SETTING_BLOCK,
  JAVASCRIPT_CONTENT_SETTING_LAST = JAVASCRIPT_CONTENT_SETTING_BLOCK,
};


const char* ToString(JavascriptContentSetting as_enum);
JavascriptContentSetting ParseJavascriptContentSetting(const std::string& as_string);

enum LocationContentSetting {
  LOCATION_CONTENT_SETTING_NONE,
  LOCATION_CONTENT_SETTING_ALLOW,
  LOCATION_CONTENT_SETTING_BLOCK,
  LOCATION_CONTENT_SETTING_ASK,
  LOCATION_CONTENT_SETTING_LAST = LOCATION_CONTENT_SETTING_ASK,
};


const char* ToString(LocationContentSetting as_enum);
LocationContentSetting ParseLocationContentSetting(const std::string& as_string);

enum PluginsContentSetting {
  PLUGINS_CONTENT_SETTING_NONE,
  PLUGINS_CONTENT_SETTING_ALLOW,
  PLUGINS_CONTENT_SETTING_BLOCK,
  PLUGINS_CONTENT_SETTING_DETECT_IMPORTANT_CONTENT,
  PLUGINS_CONTENT_SETTING_LAST = PLUGINS_CONTENT_SETTING_DETECT_IMPORTANT_CONTENT,
};


const char* ToString(PluginsContentSetting as_enum);
PluginsContentSetting ParsePluginsContentSetting(const std::string& as_string);

enum PopupsContentSetting {
  POPUPS_CONTENT_SETTING_NONE,
  POPUPS_CONTENT_SETTING_ALLOW,
  POPUPS_CONTENT_SETTING_BLOCK,
  POPUPS_CONTENT_SETTING_LAST = POPUPS_CONTENT_SETTING_BLOCK,
};


const char* ToString(PopupsContentSetting as_enum);
PopupsContentSetting ParsePopupsContentSetting(const std::string& as_string);

enum NotificationsContentSetting {
  NOTIFICATIONS_CONTENT_SETTING_NONE,
  NOTIFICATIONS_CONTENT_SETTING_ALLOW,
  NOTIFICATIONS_CONTENT_SETTING_BLOCK,
  NOTIFICATIONS_CONTENT_SETTING_ASK,
  NOTIFICATIONS_CONTENT_SETTING_LAST = NOTIFICATIONS_CONTENT_SETTING_ASK,
};


const char* ToString(NotificationsContentSetting as_enum);
NotificationsContentSetting ParseNotificationsContentSetting(const std::string& as_string);

enum FullscreenContentSetting {
  FULLSCREEN_CONTENT_SETTING_NONE,
  FULLSCREEN_CONTENT_SETTING_ALLOW,
  FULLSCREEN_CONTENT_SETTING_LAST = FULLSCREEN_CONTENT_SETTING_ALLOW,
};


const char* ToString(FullscreenContentSetting as_enum);
FullscreenContentSetting ParseFullscreenContentSetting(const std::string& as_string);

enum MouselockContentSetting {
  MOUSELOCK_CONTENT_SETTING_NONE,
  MOUSELOCK_CONTENT_SETTING_ALLOW,
  MOUSELOCK_CONTENT_SETTING_LAST = MOUSELOCK_CONTENT_SETTING_ALLOW,
};


const char* ToString(MouselockContentSetting as_enum);
MouselockContentSetting ParseMouselockContentSetting(const std::string& as_string);

enum MicrophoneContentSetting {
  MICROPHONE_CONTENT_SETTING_NONE,
  MICROPHONE_CONTENT_SETTING_ALLOW,
  MICROPHONE_CONTENT_SETTING_BLOCK,
  MICROPHONE_CONTENT_SETTING_ASK,
  MICROPHONE_CONTENT_SETTING_LAST = MICROPHONE_CONTENT_SETTING_ASK,
};


const char* ToString(MicrophoneContentSetting as_enum);
MicrophoneContentSetting ParseMicrophoneContentSetting(const std::string& as_string);

enum CameraContentSetting {
  CAMERA_CONTENT_SETTING_NONE,
  CAMERA_CONTENT_SETTING_ALLOW,
  CAMERA_CONTENT_SETTING_BLOCK,
  CAMERA_CONTENT_SETTING_ASK,
  CAMERA_CONTENT_SETTING_LAST = CAMERA_CONTENT_SETTING_ASK,
};


const char* ToString(CameraContentSetting as_enum);
CameraContentSetting ParseCameraContentSetting(const std::string& as_string);

enum PpapiBrokerContentSetting {
  PPAPI_BROKER_CONTENT_SETTING_NONE,
  PPAPI_BROKER_CONTENT_SETTING_ALLOW,
  PPAPI_BROKER_CONTENT_SETTING_BLOCK,
  PPAPI_BROKER_CONTENT_SETTING_ASK,
  PPAPI_BROKER_CONTENT_SETTING_LAST = PPAPI_BROKER_CONTENT_SETTING_ASK,
};


const char* ToString(PpapiBrokerContentSetting as_enum);
PpapiBrokerContentSetting ParsePpapiBrokerContentSetting(const std::string& as_string);

enum MultipleAutomaticDownloadsContentSetting {
  MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_NONE,
  MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_ALLOW,
  MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_BLOCK,
  MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_ASK,
  MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_LAST = MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_ASK,
};


const char* ToString(MultipleAutomaticDownloadsContentSetting as_enum);
MultipleAutomaticDownloadsContentSetting ParseMultipleAutomaticDownloadsContentSetting(const std::string& as_string);


}  // namespace content_settings
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_CONTENT_SETTINGS_H__
