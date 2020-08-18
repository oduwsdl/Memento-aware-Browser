// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/app_runtime.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_APP_RUNTIME_H__
#define EXTENSIONS_COMMON_API_APP_RUNTIME_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace app_runtime {

//
// Types
//

struct LaunchItem {
  LaunchItem();
  ~LaunchItem();
  LaunchItem(LaunchItem&& rhs);
  LaunchItem& operator=(LaunchItem&& rhs);

  // Populates a LaunchItem object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, LaunchItem* out);

  // Creates a LaunchItem object from a base::Value, or NULL on failure.
  static std::unique_ptr<LaunchItem> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this LaunchItem object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Entry for the item.
  struct Entry {
    Entry();
    ~Entry();
    Entry(Entry&& rhs);
    Entry& operator=(Entry&& rhs);

    // Populates a Entry object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Entry* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Entry object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Entry);
  };


  // Entry for the item.
  Entry entry;

  // The MIME type of the file.
  std::unique_ptr<std::string> type;


 private:
  DISALLOW_COPY_AND_ASSIGN(LaunchItem);
};

// Enumeration of app launch sources. This should be kept in sync with
// AppLaunchSource in components/services/app_service/public/mojom/types.mojom,
// and GetLaunchSourceEnum() in
// extensions/browser/api/app_runtime/app_runtime_api.cc. Note the enumeration
// is used in UMA histogram so entries should not be re-ordered or removed.
enum LaunchSource {
  LAUNCH_SOURCE_NONE,
  LAUNCH_SOURCE_UNTRACKED,
  LAUNCH_SOURCE_APP_LAUNCHER,
  LAUNCH_SOURCE_NEW_TAB_PAGE,
  LAUNCH_SOURCE_RELOAD,
  LAUNCH_SOURCE_RESTART,
  LAUNCH_SOURCE_LOAD_AND_LAUNCH,
  LAUNCH_SOURCE_COMMAND_LINE,
  LAUNCH_SOURCE_FILE_HANDLER,
  LAUNCH_SOURCE_URL_HANDLER,
  LAUNCH_SOURCE_SYSTEM_TRAY,
  LAUNCH_SOURCE_ABOUT_PAGE,
  LAUNCH_SOURCE_KEYBOARD,
  LAUNCH_SOURCE_EXTENSIONS_PAGE,
  LAUNCH_SOURCE_MANAGEMENT_API,
  LAUNCH_SOURCE_EPHEMERAL_APP,
  LAUNCH_SOURCE_BACKGROUND,
  LAUNCH_SOURCE_KIOSK,
  LAUNCH_SOURCE_CHROME_INTERNAL,
  LAUNCH_SOURCE_TEST,
  LAUNCH_SOURCE_INSTALLED_NOTIFICATION,
  LAUNCH_SOURCE_CONTEXT_MENU,
  LAUNCH_SOURCE_ARC,
  LAUNCH_SOURCE_INTENT_URL,
  LAUNCH_SOURCE_LAST = LAUNCH_SOURCE_INTENT_URL,
};


const char* ToString(LaunchSource as_enum);
LaunchSource ParseLaunchSource(const std::string& as_string);

// An app can be launched with a specific action in mind, for example, to create
// a new note. The type of action the app was launched with is available inside
// of the |actionData| field from the LaunchData instance.
enum ActionType {
  ACTION_TYPE_NONE,
  ACTION_TYPE_NEW_NOTE,
  ACTION_TYPE_LAST = ACTION_TYPE_NEW_NOTE,
};


const char* ToString(ActionType as_enum);
ActionType ParseActionType(const std::string& as_string);

struct ActionData {
  ActionData();
  ~ActionData();
  ActionData(ActionData&& rhs);
  ActionData& operator=(ActionData&& rhs);

  // Populates a ActionData object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, ActionData* out);

  // Creates a ActionData object from a base::Value, or NULL on failure.
  static std::unique_ptr<ActionData> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ActionData object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ActionType action_type;

  // <p>Whether the action was requested on Chrome OS lock screen.</p> <p>
  // Launch events with this valued set to <code>true</code> are fired   in lock
  // screen context, where apps have reduced access to extension   APIs, but are
  // able to create windows on lock screen. </p> <p>   Note that this value will
  // be set to <code>true</code> only if the app   is set as the lock screen
  // enabled action handler by the user. </p>
  std::unique_ptr<bool> is_lock_screen_action;

  // Currently, used only with lock screen actions. If set, indicates whether the
  // app should attempt to restore state from when the action was last handled.
  std::unique_ptr<bool> restore_last_action_state;


 private:
  DISALLOW_COPY_AND_ASSIGN(ActionData);
};

struct LaunchData {
  LaunchData();
  ~LaunchData();
  LaunchData(LaunchData&& rhs);
  LaunchData& operator=(LaunchData&& rhs);

  // Populates a LaunchData object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, LaunchData* out);

  // Creates a LaunchData object from a base::Value, or NULL on failure.
  static std::unique_ptr<LaunchData> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this LaunchData object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the file or URL handler that the app is being invoked with. Handler
  // IDs are the top-level keys in the <code>file_handlers</code> and/or
  // <code>url_handlers</code> dictionaries in the manifest.
  std::unique_ptr<std::string> id;

  // The file entries for the <code>onLaunched</code> event triggered by a
  // matching file handler in the <code>file_handlers</code> manifest key.
  std::unique_ptr<std::vector<LaunchItem>> items;

  // The URL for the <code>onLaunched</code> event triggered by a matching URL
  // handler in the <code>url_handlers</code> manifest key.
  std::unique_ptr<std::string> url;

  // The referrer URL for the <code>onLaunched</code> event triggered by a
  // matching URL handler in the <code>url_handlers</code> manifest key.
  std::unique_ptr<std::string> referrer_url;

  // Whether the app is launched in a Chrome OS Demo Mode session. Used for
  // default-installed Demo Mode Chrome apps.
  std::unique_ptr<bool> is_demo_session;

  // Whether the app is being launched in a <a
  // href="https://support.google.com/chromebook/answer/3134673">Chrome OS kiosk
  // session</a>.
  std::unique_ptr<bool> is_kiosk_session;

  // Whether the app is being launched in a <a
  // href="https://support.google.com/chrome/a/answer/3017014">Chrome OS public
  // session</a>.
  std::unique_ptr<bool> is_public_session;

  // Where the app is launched from.
  LaunchSource source;

  // Contains data that specifies the <code>ActionType</code> this app was
  // launched with. This is null if the app was not launched with a specific
  // action intent.
  std::unique_ptr<ActionData> action_data;


 private:
  DISALLOW_COPY_AND_ASSIGN(LaunchData);
};

struct EmbedRequest {
  EmbedRequest();
  ~EmbedRequest();
  EmbedRequest(EmbedRequest&& rhs);
  EmbedRequest& operator=(EmbedRequest&& rhs);

  // Populates a EmbedRequest object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, EmbedRequest* out);

  // Creates a EmbedRequest object from a base::Value, or NULL on failure.
  static std::unique_ptr<EmbedRequest> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this EmbedRequest object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string embedder_id;

  // Optional developer specified data that the app to be embedded can use when
  // making an embedding decision.
  std::unique_ptr<base::Value> data;


 private:
  DISALLOW_COPY_AND_ASSIGN(EmbedRequest);
};


//
// Events
//

namespace OnEmbedRequested {

extern const char kEventName[];  // "app.runtime.onEmbedRequested"

std::unique_ptr<base::ListValue> Create(const EmbedRequest& request);
}  // namespace OnEmbedRequested

namespace OnLaunched {

extern const char kEventName[];  // "app.runtime.onLaunched"

std::unique_ptr<base::ListValue> Create(const LaunchData& launch_data);
}  // namespace OnLaunched

namespace OnRestarted {

extern const char kEventName[];  // "app.runtime.onRestarted"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnRestarted

}  // namespace app_runtime
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_APP_RUNTIME_H__
