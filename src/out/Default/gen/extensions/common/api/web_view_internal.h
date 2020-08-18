// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/web_view_internal.json
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_WEB_VIEW_INTERNAL_H__
#define EXTENSIONS_COMMON_API_WEB_VIEW_INTERNAL_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"
#include "extensions/common/api/extension_types.h"
#include "extensions/common/api/extension_types.h"
#include "extensions/common/api/extension_types.h"
#include "extensions/common/api/extension_types.h"


namespace extensions {
namespace api {
namespace web_view_internal {

//
// Types
//

// A set of data types. Missing data types are interpreted as
// <code>false</code>.
struct DataTypeSet {
  DataTypeSet();
  ~DataTypeSet();
  DataTypeSet(DataTypeSet&& rhs);
  DataTypeSet& operator=(DataTypeSet&& rhs);

  // Populates a DataTypeSet object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DataTypeSet* out);

  // Creates a DataTypeSet object from a base::Value, or NULL on failure.
  static std::unique_ptr<DataTypeSet> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DataTypeSet object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Websites' appcaches.
  std::unique_ptr<bool> appcache;

  // The Websites' cookies. This will remove both session and persistent cookies
  std::unique_ptr<bool> cookies;

  // The Websites' session cookies.
  std::unique_ptr<bool> session_cookies;

  // The Websites' persistent cookies.
  std::unique_ptr<bool> persistent_cookies;

  // Websites' file systems.
  std::unique_ptr<bool> file_systems;

  // Websites' IndexedDB data.
  std::unique_ptr<bool> indexed_db;

  // Websites' local storage data.
  std::unique_ptr<bool> local_storage;

  // Websites' WebSQL data.
  std::unique_ptr<bool> web_sql;

  // The Websites' cache data. Note: when removing data, this clears the
  // <em>entire</em> cache: it is not limited to the range you specify.
  std::unique_ptr<bool> cache;


 private:
  DISALLOW_COPY_AND_ASSIGN(DataTypeSet);
};

// Options that determine exactly what data will be removed.
struct RemovalOptions {
  RemovalOptions();
  ~RemovalOptions();
  RemovalOptions(RemovalOptions&& rhs);
  RemovalOptions& operator=(RemovalOptions&& rhs);

  // Populates a RemovalOptions object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, RemovalOptions* out);

  // Creates a RemovalOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<RemovalOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RemovalOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Remove data accumulated on or after this date, represented in milliseconds
  // since the epoch (accessible via the <code>getTime</code> method of the
  // JavaScript <code>Date</code> object). If absent, defaults to 0 (which would
  // remove all browsing data).
  std::unique_ptr<double> since;


 private:
  DISALLOW_COPY_AND_ASSIGN(RemovalOptions);
};

// Defines the how zooming is handled in the webview.
enum ZoomMode {
  ZOOM_MODE_NONE,
  ZOOM_MODE_PER_ORIGIN,
  ZOOM_MODE_PER_VIEW,
  ZOOM_MODE_DISABLED,
  ZOOM_MODE_LAST = ZOOM_MODE_DISABLED,
};


const char* ToString(ZoomMode as_enum);
ZoomMode ParseZoomMode(const std::string& as_string);

// Determines what to do with the active match after the find session has ended.
// 'clear' will clear the highlighting over the active match; 'keep' will keep
// the active match highlighted; 'activate' will keep the active match
// highlighted and simulate a user click on that match.
enum StopFindingAction {
  STOP_FINDING_ACTION_NONE,
  STOP_FINDING_ACTION_CLEAR,
  STOP_FINDING_ACTION_KEEP,
  STOP_FINDING_ACTION_ACTIVATE,
  STOP_FINDING_ACTION_LAST = STOP_FINDING_ACTION_ACTIVATE,
};


const char* ToString(StopFindingAction as_enum);
StopFindingAction ParseStopFindingAction(const std::string& as_string);

enum SetPermissionAction {
  SET_PERMISSION_ACTION_NONE,
  SET_PERMISSION_ACTION_ALLOW,
  SET_PERMISSION_ACTION_DENY,
  SET_PERMISSION_ACTION_DEFAULT,
  SET_PERMISSION_ACTION_LAST = SET_PERMISSION_ACTION_DEFAULT,
};


const char* ToString(SetPermissionAction as_enum);
SetPermissionAction ParseSetPermissionAction(const std::string& as_string);

// The type of injection item: code or a set of files.
struct InjectionItems {
  InjectionItems();
  ~InjectionItems();
  InjectionItems(InjectionItems&& rhs);
  InjectionItems& operator=(InjectionItems&& rhs);

  // Populates a InjectionItems object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, InjectionItems* out);

  // Creates a InjectionItems object from a base::Value, or NULL on failure.
  static std::unique_ptr<InjectionItems> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this InjectionItems object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // JavaScript code or CSS to be injected into matching pages.
  std::unique_ptr<std::string> code;

  // The list of JavaScript or CSS files to be injected into matching pages. These
  // are injected in the order they appear in this array.
  std::unique_ptr<std::vector<std::string>> files;


 private:
  DISALLOW_COPY_AND_ASSIGN(InjectionItems);
};

// Details of the content script to inject.
struct ContentScriptDetails {
  ContentScriptDetails();
  ~ContentScriptDetails();
  ContentScriptDetails(ContentScriptDetails&& rhs);
  ContentScriptDetails& operator=(ContentScriptDetails&& rhs);

  // Populates a ContentScriptDetails object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ContentScriptDetails* out);

  // Creates a ContentScriptDetails object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ContentScriptDetails> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ContentScriptDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The name of the content script to inject.
  std::string name;

  // Specifies which pages this content script will be injected into.
  std::vector<std::string> matches;

  // Excludes pages that this content script would otherwise be injected into.
  std::unique_ptr<std::vector<std::string>> exclude_matches;

  // Whether to insert the content script on about:blank and about:srcdoc. Content
  // scripts will only be injected on pages when their inherit URL is matched by
  // one of the declared patterns in the matches field. The inherit URL is the URL
  // of the document that created the frame or window. Content scripts cannot be
  // inserted in sandboxed frames.
  std::unique_ptr<bool> match_about_blank;

  // The CSS code or a list of CSS files to be injected into matching pages. These
  // are injected in the order they appear, before any DOM is constructed or
  // displayed for the page.
  std::unique_ptr<InjectionItems> css;

  // The JavaScript code or a list of JavaScript files to be injected into
  // matching pages. These are injected in the order they appear.
  std::unique_ptr<InjectionItems> js;

  // The soonest that the JavaScript or CSS will be injected into the tab.
  // Defaults to "document_idle".
  extensions::api::extension_types::RunAt run_at;

  // If allFrames is <code>true</code>, implies that the JavaScript or CSS should
  // be injected into all frames of current page. By default, it's
  // <code>false</code> and is only injected into the top frame.
  std::unique_ptr<bool> all_frames;

  // Applied after matches to include only those URLs that also match this glob.
  // Intended to emulate the @include Greasemonkey keyword.
  std::unique_ptr<std::vector<std::string>> include_globs;

  // Applied after matches to exclude URLs that match this glob. Intended to
  // emulate the @exclude Greasemonkey keyword.
  std::unique_ptr<std::vector<std::string>> exclude_globs;


 private:
  DISALLOW_COPY_AND_ASSIGN(ContentScriptDetails);
};


//
// Functions
//

namespace GetAudioState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool audible);
}  // namespace Results

}  // namespace GetAudioState

namespace SetAudioMuted {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  // Mute audio value.
  bool mute;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetAudioMuted

namespace IsAudioMuted {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool muted);
}  // namespace Results

}  // namespace IsAudioMuted

namespace ExecuteScript {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  // The src of the guest <webview> tag.
  std::string src;

  // Details of the script to run.
  extensions::api::extension_types::InjectDetails details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The result of the script in every injected frame.
std::unique_ptr<base::ListValue> Create(const std::vector<std::unique_ptr<base::Value>>& result);
}  // namespace Results

}  // namespace ExecuteScript

namespace InsertCSS {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  // The src of the guest <webview> tag.
  std::string src;

  // Details of the CSS text to insert.
  extensions::api::extension_types::InjectDetails details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace InsertCSS

namespace AddContentScripts {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  // Details of the content scripts to add.
  std::vector<ContentScriptDetails> content_script_list;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace AddContentScripts

namespace RemoveContentScripts {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  // A list of names of content scripts that will be removed. If the list is
  // empty, all the content scripts added to the <webview> page will be removed.
  std::unique_ptr<std::vector<std::string>> script_name_list;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RemoveContentScripts

namespace SetZoom {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  // The new zoom factor.
  double zoom_factor;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetZoom

namespace GetZoom {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The current zoom factor.
std::unique_ptr<base::ListValue> Create(double zoom_factor);
}  // namespace Results

}  // namespace GetZoom

namespace SetZoomMode {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  // Defines how zooming is handled in the webview.
  ZoomMode zoom_mode;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetZoomMode

namespace GetZoomMode {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The webview's current zoom mode.
std::unique_ptr<base::ListValue> Create(const ZoomMode& zoom_mode);
}  // namespace Results

}  // namespace GetZoomMode

namespace Find {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Options {
    Options();
    ~Options();
    Options(Options&& rhs);
    Options& operator=(Options&& rhs);

    // Populates a Options object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Options* out);

    // Flag to find matches in reverse order.
    std::unique_ptr<bool> backward;

    // Flag to match |searchText| with case-sensitivity.
    std::unique_ptr<bool> match_case;


   private:
    DISALLOW_COPY_AND_ASSIGN(Options);
  };


  // The instance ID of the guest <webview> process.
  int instance_id;

  // The string to find in the page.
  std::string search_text;

  std::unique_ptr<Options> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Results {
  Results();
  ~Results();
  Results(Results&& rhs);
  Results& operator=(Results&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Results object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Describes a rectangle around the active match.
  struct SelectionRect {
    SelectionRect();
    ~SelectionRect();
    SelectionRect(SelectionRect&& rhs);
    SelectionRect& operator=(SelectionRect&& rhs);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this SelectionRect object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    int left;

    int top;

    int width;

    int height;


   private:
    DISALLOW_COPY_AND_ASSIGN(SelectionRect);
  };


  // The number of times |searchText| was matched on the page.
  int number_of_matches;

  // The ordinal number of the current match.
  int active_match_ordinal;

  // Describes a rectangle around the active match.
  SelectionRect selection_rect;

  // Indicates whether this find request was canceled.
  bool canceled;


 private:
  DISALLOW_COPY_AND_ASSIGN(Results);
};


std::unique_ptr<base::ListValue> Create(const Results& results);
}  // namespace Results

}  // namespace Find

namespace StopFinding {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  // Determines what to do with the active match after the find session has ended.
  StopFindingAction action;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace StopFinding

namespace LoadDataWithBaseUrl {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  // The data URL to load.
  std::string data_url;

  // The base URL that will be used for relative links.
  std::string base_url;

  // The URL that will be displayed to the user.
  std::unique_ptr<std::string> virtual_url;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace LoadDataWithBaseUrl

namespace Go {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;

  int relative_index;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Indicates whether the navigation was successful.
std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace Go

namespace OverrideUserAgent {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;

  std::string user_agent_override;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace OverrideUserAgent

namespace Reload {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Reload

namespace SetAllowTransparency {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;

  bool allow;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetAllowTransparency

namespace SetAllowScaling {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;

  bool allow;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetAllowScaling

namespace SetName {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;

  std::string frame_name;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetName

namespace SetPermission {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;

  int request_id;

  SetPermissionAction action;

  std::unique_ptr<std::string> user_input;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool allowed);
}  // namespace Results

}  // namespace SetPermission

namespace Navigate {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;

  std::string src;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Navigate

namespace Stop {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Stop

namespace Terminate {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Terminate

namespace CaptureVisibleRegion {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  std::unique_ptr<extensions::api::extension_types::ImageDetails> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// A data URL which encodes an image of the visible area of the captured tab.
// May be assigned to the 'src' property of an HTML Image element for display.
std::unique_ptr<base::ListValue> Create(const std::string& data_url);
}  // namespace Results

}  // namespace CaptureVisibleRegion

namespace SetSpatialNavigationEnabled {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  // Spatial navigation state value.
  bool spatial_nav_enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetSpatialNavigationEnabled

namespace IsSpatialNavigationEnabled {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool spatial_nav_enabled);
}  // namespace Results

}  // namespace IsSpatialNavigationEnabled

namespace ClearData {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest <webview> process.
  int instance_id;

  RemovalOptions options;

  // The set of data types to remove.
  DataTypeSet data_to_remove;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ClearData

}  // namespace web_view_internal
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_WEB_VIEW_INTERNAL_H__
