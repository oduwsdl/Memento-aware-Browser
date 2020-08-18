// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/tabs.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_TABS_H__
#define CHROME_COMMON_EXTENSIONS_API_TABS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"
#include "extensions/common/api/extension_types.h"
#include "extensions/common/api/extension_types.h"
#include "chrome/common/extensions/api/windows.h"


namespace extensions {
namespace api {
namespace extension_types {
struct ImageDetails;
}  // namespace extension_types
}  // namespace api
}  // namespace extensions

namespace extensions {
namespace api {
namespace tabs {

//
// Properties
//

// An ID that represents the absence of a browser tab.
extern const int TAB_ID_NONE;

//
// Types
//

// The tab's loading status.
enum TabStatus {
  TAB_STATUS_NONE,
  TAB_STATUS_UNLOADED,
  TAB_STATUS_LOADING,
  TAB_STATUS_COMPLETE,
  TAB_STATUS_LAST = TAB_STATUS_COMPLETE,
};


const char* ToString(TabStatus as_enum);
TabStatus ParseTabStatus(const std::string& as_string);

// An event that caused a muted state change.
enum MutedInfoReason {
  MUTED_INFO_REASON_NONE,
  MUTED_INFO_REASON_USER,
  MUTED_INFO_REASON_CAPTURE,
  MUTED_INFO_REASON_EXTENSION,
  MUTED_INFO_REASON_LAST = MUTED_INFO_REASON_EXTENSION,
};


const char* ToString(MutedInfoReason as_enum);
MutedInfoReason ParseMutedInfoReason(const std::string& as_string);

// The tab's muted state and the reason for the last state change.
struct MutedInfo {
  MutedInfo();
  ~MutedInfo();
  MutedInfo(MutedInfo&& rhs);
  MutedInfo& operator=(MutedInfo&& rhs);

  // Populates a MutedInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, MutedInfo* out);

  // Creates a MutedInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<MutedInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MutedInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Whether the tab is muted (prevented from playing sound). The tab may be muted
  // even if it has not played or is not currently playing sound. Equivalent to
  // whether the 'muted' audio indicator is showing.
  bool muted;

  // The reason the tab was muted or unmuted. Not set if the tab's mute state has
  // never been changed.
  MutedInfoReason reason;

  // The ID of the extension that changed the muted state. Not set if an extension
  // was not the reason the muted state last changed.
  std::unique_ptr<std::string> extension_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(MutedInfo);
};

struct Tab {
  Tab();
  ~Tab();
  Tab(Tab&& rhs);
  Tab& operator=(Tab&& rhs);

  // Populates a Tab object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Tab* out);

  // Creates a Tab object from a base::Value, or NULL on failure.
  static std::unique_ptr<Tab> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Tab object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the tab. Tab IDs are unique within a browser session. Under some
  // circumstances a tab may not be assigned an ID; for example, when querying
  // foreign tabs using the $(ref:sessions) API, in which case a session ID may be
  // present. Tab ID can also be set to <code>chrome.tabs.TAB_ID_NONE</code> for
  // apps and devtools windows.
  std::unique_ptr<int> id;

  // The zero-based index of the tab within its window.
  int index;

  // The ID of the window that contains the tab.
  int window_id;

  // The ID of the tab that opened this tab, if any. This property is only present
  // if the opener tab still exists.
  std::unique_ptr<int> opener_tab_id;

  // Whether the tab is selected.
  bool selected;

  // Whether the tab is highlighted.
  bool highlighted;

  // Whether the tab is active in its window. Does not necessarily mean the window
  // is focused.
  bool active;

  // Whether the tab is pinned.
  bool pinned;

  // Whether the tab has produced sound over the past couple of seconds (but it
  // might not be heard if also muted). Equivalent to whether the 'speaker audio'
  // indicator is showing.
  std::unique_ptr<bool> audible;

  // Whether the tab is discarded. A discarded tab is one whose content has been
  // unloaded from memory, but is still visible in the tab strip. Its content is
  // reloaded the next time it is activated.
  bool discarded;

  // Whether the tab can be discarded automatically by the browser when resources
  // are low.
  bool auto_discardable;

  // The tab's muted state and the reason for the last state change.
  std::unique_ptr<MutedInfo> muted_info;

  // The last committed URL of the main frame of the tab. This property is only
  // present if the extension's manifest includes the <code>"tabs"</code>
  // permission and may be an empty string if the tab has not yet committed. See
  // also $(ref:Tab.pendingUrl).
  std::unique_ptr<std::string> url;

  // The URL the tab is navigating to, before it has committed. This property is
  // only present if the extension's manifest includes the <code>"tabs"</code>
  // permission and there is a pending navigation.
  std::unique_ptr<std::string> pending_url;

  // The title of the tab. This property is only present if the extension's
  // manifest includes the <code>"tabs"</code> permission.
  std::unique_ptr<std::string> title;

  // The URL of the tab's favicon. This property is only present if the
  // extension's manifest includes the <code>"tabs"</code> permission. It may also
  // be an empty string if the tab is loading.
  std::unique_ptr<std::string> fav_icon_url;

  // The tab's loading status.
  TabStatus status;

  // Whether the tab is in an incognito window.
  bool incognito;

  // The width of the tab in pixels.
  std::unique_ptr<int> width;

  // The height of the tab in pixels.
  std::unique_ptr<int> height;

  // The session ID used to uniquely identify a tab obtained from the
  // $(ref:sessions) API.
  std::unique_ptr<std::string> session_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(Tab);
};

// Defines how zoom changes are handled, i.e., which entity is responsible for
// the actual scaling of the page; defaults to <code>automatic</code>.
enum ZoomSettingsMode {
  ZOOM_SETTINGS_MODE_NONE,
  ZOOM_SETTINGS_MODE_AUTOMATIC,
  ZOOM_SETTINGS_MODE_MANUAL,
  ZOOM_SETTINGS_MODE_DISABLED,
  ZOOM_SETTINGS_MODE_LAST = ZOOM_SETTINGS_MODE_DISABLED,
};


const char* ToString(ZoomSettingsMode as_enum);
ZoomSettingsMode ParseZoomSettingsMode(const std::string& as_string);

// Defines whether zoom changes persist for the page's origin, or only take
// effect in this tab; defaults to <code>per-origin</code> when in
// <code>automatic</code> mode, and <code>per-tab</code> otherwise.
enum ZoomSettingsScope {
  ZOOM_SETTINGS_SCOPE_NONE,
  ZOOM_SETTINGS_SCOPE_PER_ORIGIN,
  ZOOM_SETTINGS_SCOPE_PER_TAB,
  ZOOM_SETTINGS_SCOPE_LAST = ZOOM_SETTINGS_SCOPE_PER_TAB,
};


const char* ToString(ZoomSettingsScope as_enum);
ZoomSettingsScope ParseZoomSettingsScope(const std::string& as_string);

// Defines how zoom changes in a tab are handled and at what scope.
struct ZoomSettings {
  ZoomSettings();
  ~ZoomSettings();
  ZoomSettings(ZoomSettings&& rhs);
  ZoomSettings& operator=(ZoomSettings&& rhs);

  // Populates a ZoomSettings object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ZoomSettings* out);

  // Creates a ZoomSettings object from a base::Value, or NULL on failure.
  static std::unique_ptr<ZoomSettings> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ZoomSettings object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Defines how zoom changes are handled, i.e., which entity is responsible for
  // the actual scaling of the page; defaults to <code>automatic</code>.
  ZoomSettingsMode mode;

  // Defines whether zoom changes persist for the page's origin, or only take
  // effect in this tab; defaults to <code>per-origin</code> when in
  // <code>automatic</code> mode, and <code>per-tab</code> otherwise.
  ZoomSettingsScope scope;

  // Used to return the default zoom level for the current tab in calls to
  // tabs.getZoomSettings.
  std::unique_ptr<double> default_zoom_factor;


 private:
  DISALLOW_COPY_AND_ASSIGN(ZoomSettings);
};

// The type of window.
enum WindowType {
  WINDOW_TYPE_NONE,
  WINDOW_TYPE_NORMAL,
  WINDOW_TYPE_POPUP,
  WINDOW_TYPE_PANEL,
  WINDOW_TYPE_APP,
  WINDOW_TYPE_DEVTOOLS,
  WINDOW_TYPE_LAST = WINDOW_TYPE_DEVTOOLS,
};


const char* ToString(WindowType as_enum);
WindowType ParseWindowType(const std::string& as_string);


//
// Functions
//

namespace Get {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int tab_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Tab& tab);
}  // namespace Results

}  // namespace Get

namespace GetCurrent {

namespace Results {

std::unique_ptr<base::ListValue> Create(const Tab& tab);
}  // namespace Results

}  // namespace GetCurrent

namespace GetSelected {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Defaults to the <a href='windows#current-window'>current window</a>.
  std::unique_ptr<int> window_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Tab& tab);
}  // namespace Results

}  // namespace GetSelected

namespace GetAllInWindow {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Defaults to the <a href='windows#current-window'>current window</a>.
  std::unique_ptr<int> window_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Tab>& tabs);
}  // namespace Results

}  // namespace GetAllInWindow

namespace Create {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct CreateProperties {
    CreateProperties();
    ~CreateProperties();
    CreateProperties(CreateProperties&& rhs);
    CreateProperties& operator=(CreateProperties&& rhs);

    // Populates a CreateProperties object from a base::Value. Returns whether
    // |out| was successfully populated.
    static bool Populate(const base::Value& value, CreateProperties* out);

    // The window in which to create the new tab. Defaults to the <a
    // href='windows#current-window'>current window</a>.
    std::unique_ptr<int> window_id;

    // The position the tab should take in the window. The provided value is clamped
    // to between zero and the number of tabs in the window.
    std::unique_ptr<int> index;

    // The URL to initially navigate the tab to. Fully-qualified URLs must include a
    // scheme (i.e., 'http://www.google.com', not 'www.google.com'). Relative URLs
    // are relative to the current page within the extension. Defaults to the New
    // Tab Page.
    std::unique_ptr<std::string> url;

    // Whether the tab should become the active tab in the window. Does not affect
    // whether the window is focused (see $(ref:windows.update)). Defaults to
    // <var>true</var>.
    std::unique_ptr<bool> active;

    // Whether the tab should become the selected tab in the window. Defaults to
    // <var>true</var>
    std::unique_ptr<bool> selected;

    // Whether the tab should be pinned. Defaults to <var>false</var>
    std::unique_ptr<bool> pinned;

    // The ID of the tab that opened this tab. If specified, the opener tab must be
    // in the same window as the newly created tab.
    std::unique_ptr<int> opener_tab_id;


   private:
    DISALLOW_COPY_AND_ASSIGN(CreateProperties);
  };


  CreateProperties create_properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The created tab.
std::unique_ptr<base::ListValue> Create(const Tab& tab);
}  // namespace Results

}  // namespace Create

namespace Duplicate {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the tab to duplicate.
  int tab_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Details about the duplicated tab. The $(ref:tabs.Tab) object does not contain
// <code>url</code>, <code>pendingUrl</code>, <code>title</code>, and
// <code>favIconUrl</code> if the <code>"tabs"</code> permission has not been
// requested.
std::unique_ptr<base::ListValue> Create(const Tab& tab);
}  // namespace Results

}  // namespace Duplicate

namespace Query {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct QueryInfo {
    QueryInfo();
    ~QueryInfo();
    QueryInfo(QueryInfo&& rhs);
    QueryInfo& operator=(QueryInfo&& rhs);

    // Populates a QueryInfo object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, QueryInfo* out);

    // Match tabs against one or more <a href='match_patterns'>URL patterns</a>.
    // Fragment identifiers are not matched. This property is ignored if the
    // extension does not have the <code>"tabs"</code> permission.
    struct Url {
      Url();
      ~Url();
      Url(Url&& rhs);
      Url& operator=(Url&& rhs);

      // Populates a Url object from a base::Value. Returns whether |out| was
      // successfully populated.
      static bool Populate(const base::Value& value, Url* out);
      // Choices:
      std::unique_ptr<std::string> as_string;
      std::unique_ptr<std::vector<std::string>> as_strings;

     private:
      DISALLOW_COPY_AND_ASSIGN(Url);
    };


    // Whether the tabs are active in their windows.
    std::unique_ptr<bool> active;

    // Whether the tabs are pinned.
    std::unique_ptr<bool> pinned;

    // Whether the tabs are audible.
    std::unique_ptr<bool> audible;

    // Whether the tabs are muted.
    std::unique_ptr<bool> muted;

    // Whether the tabs are highlighted.
    std::unique_ptr<bool> highlighted;

    // Whether the tabs are discarded. A discarded tab is one whose content has been
    // unloaded from memory, but is still visible in the tab strip. Its content is
    // reloaded the next time it is activated.
    std::unique_ptr<bool> discarded;

    // Whether the tabs can be discarded automatically by the browser when resources
    // are low.
    std::unique_ptr<bool> auto_discardable;

    // Whether the tabs are in the <a href='windows#current-window'>current
    // window</a>.
    std::unique_ptr<bool> current_window;

    // Whether the tabs are in the last focused window.
    std::unique_ptr<bool> last_focused_window;

    // The tab loading status.
    TabStatus status;

    // Match page titles against a pattern. This property is ignored if the
    // extension does not have the <code>"tabs"</code> permission.
    std::unique_ptr<std::string> title;

    // Match tabs against one or more <a href='match_patterns'>URL patterns</a>.
    // Fragment identifiers are not matched. This property is ignored if the
    // extension does not have the <code>"tabs"</code> permission.
    std::unique_ptr<Url> url;

    // The ID of the parent window, or $(ref:windows.WINDOW_ID_CURRENT) for the <a
    // href='windows#current-window'>current window</a>.
    std::unique_ptr<int> window_id;

    // The type of window the tabs are in.
    WindowType window_type;

    // The position of the tabs within their windows.
    std::unique_ptr<int> index;


   private:
    DISALLOW_COPY_AND_ASSIGN(QueryInfo);
  };


  QueryInfo query_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Tab>& result);
}  // namespace Results

}  // namespace Query

namespace Highlight {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct HighlightInfo {
    HighlightInfo();
    ~HighlightInfo();
    HighlightInfo(HighlightInfo&& rhs);
    HighlightInfo& operator=(HighlightInfo&& rhs);

    // Populates a HighlightInfo object from a base::Value. Returns whether |out|
    // was successfully populated.
    static bool Populate(const base::Value& value, HighlightInfo* out);

    // One or more tab indices to highlight.
    struct Tabs {
      Tabs();
      ~Tabs();
      Tabs(Tabs&& rhs);
      Tabs& operator=(Tabs&& rhs);

      // Populates a Tabs object from a base::Value. Returns whether |out| was
      // successfully populated.
      static bool Populate(const base::Value& value, Tabs* out);
      // Choices:
      std::unique_ptr<std::vector<int>> as_integers;
      std::unique_ptr<int> as_integer;

     private:
      DISALLOW_COPY_AND_ASSIGN(Tabs);
    };


    // The window that contains the tabs.
    std::unique_ptr<int> window_id;

    // One or more tab indices to highlight.
    Tabs tabs;


   private:
    DISALLOW_COPY_AND_ASSIGN(HighlightInfo);
  };


  HighlightInfo highlight_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Contains details about the window whose tabs were highlighted.
std::unique_ptr<base::ListValue> Create(const extensions::api::windows::Window& window);
}  // namespace Results

}  // namespace Highlight

namespace Update {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct UpdateProperties {
    UpdateProperties();
    ~UpdateProperties();
    UpdateProperties(UpdateProperties&& rhs);
    UpdateProperties& operator=(UpdateProperties&& rhs);

    // Populates a UpdateProperties object from a base::Value. Returns whether
    // |out| was successfully populated.
    static bool Populate(const base::Value& value, UpdateProperties* out);

    // A URL to navigate the tab to. JavaScript URLs are not supported; use
    // $(ref:tabs.executeScript) instead.
    std::unique_ptr<std::string> url;

    // Whether the tab should be active. Does not affect whether the window is
    // focused (see $(ref:windows.update)).
    std::unique_ptr<bool> active;

    // Adds or removes the tab from the current selection.
    std::unique_ptr<bool> highlighted;

    // Whether the tab should be selected.
    std::unique_ptr<bool> selected;

    // Whether the tab should be pinned.
    std::unique_ptr<bool> pinned;

    // Whether the tab should be muted.
    std::unique_ptr<bool> muted;

    // The ID of the tab that opened this tab. If specified, the opener tab must be
    // in the same window as this tab.
    std::unique_ptr<int> opener_tab_id;

    // Whether the tab should be discarded automatically by the browser when
    // resources are low.
    std::unique_ptr<bool> auto_discardable;


   private:
    DISALLOW_COPY_AND_ASSIGN(UpdateProperties);
  };


  // Defaults to the selected tab of the <a href='windows#current-window'>current
  // window</a>.
  std::unique_ptr<int> tab_id;

  UpdateProperties update_properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Details about the updated tab. The $(ref:tabs.Tab) object does not contain
// <code>url</code>, <code>pendingUrl</code>, <code>title</code>, and
// <code>favIconUrl</code> if the <code>"tabs"</code> permission has not been
// requested.
std::unique_ptr<base::ListValue> Create(const Tab& tab);
}  // namespace Results

}  // namespace Update

namespace Move {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The tab ID or list of tab IDs to move.
  struct TabIds {
    TabIds();
    ~TabIds();
    TabIds(TabIds&& rhs);
    TabIds& operator=(TabIds&& rhs);

    // Populates a TabIds object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, TabIds* out);
    // Choices:
    std::unique_ptr<int> as_integer;
    std::unique_ptr<std::vector<int>> as_integers;

   private:
    DISALLOW_COPY_AND_ASSIGN(TabIds);
  };

  struct MoveProperties {
    MoveProperties();
    ~MoveProperties();
    MoveProperties(MoveProperties&& rhs);
    MoveProperties& operator=(MoveProperties&& rhs);

    // Populates a MoveProperties object from a base::Value. Returns whether |out|
    // was successfully populated.
    static bool Populate(const base::Value& value, MoveProperties* out);

    // Defaults to the window the tab is currently in.
    std::unique_ptr<int> window_id;

    // The position to move the window to. Use <code>-1</code> to place the tab at
    // the end of the window.
    int index;


   private:
    DISALLOW_COPY_AND_ASSIGN(MoveProperties);
  };


  // The tab ID or list of tab IDs to move.
  TabIds tab_ids;

  MoveProperties move_properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Details about the moved tabs.
struct Tabs {
  Tabs();
  ~Tabs();
  Tabs(Tabs&& rhs);
  Tabs& operator=(Tabs&& rhs);

  // Returns a new base::Value representing the serialized form of this Tabs
  // object.
  std::unique_ptr<base::Value> ToValue() const;
  // Choices:
  std::unique_ptr<Tab> as_tab;
  std::unique_ptr<std::vector<Tab>> as_tabs;

 private:
  DISALLOW_COPY_AND_ASSIGN(Tabs);
};


// Details about the moved tabs.
std::unique_ptr<base::ListValue> Create(const Tabs& tabs);
}  // namespace Results

}  // namespace Move

namespace Reload {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct ReloadProperties {
    ReloadProperties();
    ~ReloadProperties();
    ReloadProperties(ReloadProperties&& rhs);
    ReloadProperties& operator=(ReloadProperties&& rhs);

    // Populates a ReloadProperties object from a base::Value. Returns whether
    // |out| was successfully populated.
    static bool Populate(const base::Value& value, ReloadProperties* out);

    // Whether to bypass local caching. Defaults to <code>false</code>.
    std::unique_ptr<bool> bypass_cache;


   private:
    DISALLOW_COPY_AND_ASSIGN(ReloadProperties);
  };


  // The ID of the tab to reload; defaults to the selected tab of the current
  // window.
  std::unique_ptr<int> tab_id;

  std::unique_ptr<ReloadProperties> reload_properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Reload

namespace Remove {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The tab ID or list of tab IDs to close.
  struct TabIds {
    TabIds();
    ~TabIds();
    TabIds(TabIds&& rhs);
    TabIds& operator=(TabIds&& rhs);

    // Populates a TabIds object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, TabIds* out);
    // Choices:
    std::unique_ptr<int> as_integer;
    std::unique_ptr<std::vector<int>> as_integers;

   private:
    DISALLOW_COPY_AND_ASSIGN(TabIds);
  };


  // The tab ID or list of tab IDs to close.
  TabIds tab_ids;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Remove

namespace DetectLanguage {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Defaults to the active tab of the <a href='windows#current-window'>current
  // window</a>.
  std::unique_ptr<int> tab_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// An ISO language code such as <code>en</code> or <code>fr</code>. For a
// complete list of languages supported by this method, see <a
// href='http://src.chromium.org/viewvc/chrome/trunk/src/third_party/cld/languages/internal/languages.cc'>kLanguageInfoTable</a>. The second to fourth columns are checked and the first non-NULL value is returned, except for Simplified Chinese for which <code>zh-CN</code> is returned. For an unknown/undefined language, <code>und</code> is returned.
std::unique_ptr<base::ListValue> Create(const std::string& language);
}  // namespace Results

}  // namespace DetectLanguage

namespace CaptureVisibleTab {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The target window. Defaults to the <a href='windows#current-window'>current
  // window</a>.
  std::unique_ptr<int> window_id;

  std::unique_ptr<extensions::api::extension_types::ImageDetails> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// A data URL that encodes an image of the visible area of the captured tab. May
// be assigned to the 'src' property of an HTML <code>img</code> element for
// display.
std::unique_ptr<base::ListValue> Create(const std::string& data_url);
}  // namespace Results

}  // namespace CaptureVisibleTab

namespace ExecuteScript {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the tab in which to run the script; defaults to the active tab of
  // the current window.
  std::unique_ptr<int> tab_id;

  // Details of the script to run. Either the code or the file property must be
  // set, but both may not be set at the same time.
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

  // The ID of the tab in which to insert the CSS; defaults to the active tab of
  // the current window.
  std::unique_ptr<int> tab_id;

  // Details of the CSS text to insert. Either the code or the file property must
  // be set, but both may not be set at the same time.
  extensions::api::extension_types::InjectDetails details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace InsertCSS

namespace SetZoom {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the tab to zoom; defaults to the active tab of the current window.
  std::unique_ptr<int> tab_id;

  // The new zoom factor. A value of <code>0</code> sets the tab to its current
  // default zoom factor. Values greater than <code>0</code> specify a (possibly
  // non-default) zoom factor for the tab.
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

  // The ID of the tab to get the current zoom factor from; defaults to the active
  // tab of the current window.
  std::unique_ptr<int> tab_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The tab's current zoom factor.
std::unique_ptr<base::ListValue> Create(double zoom_factor);
}  // namespace Results

}  // namespace GetZoom

namespace SetZoomSettings {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the tab to change the zoom settings for; defaults to the active tab
  // of the current window.
  std::unique_ptr<int> tab_id;

  // Defines how zoom changes are handled and at what scope.
  ZoomSettings zoom_settings;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetZoomSettings

namespace GetZoomSettings {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the tab to get the current zoom settings from; defaults to the
  // active tab of the current window.
  std::unique_ptr<int> tab_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The tab's current zoom settings.
std::unique_ptr<base::ListValue> Create(const ZoomSettings& zoom_settings);
}  // namespace Results

}  // namespace GetZoomSettings

namespace Discard {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the tab to be discarded. If specified, the tab is discarded unless
  // it is active or already discarded. If omitted, the browser discards the least
  // important tab. This can fail if no discardable tabs exist.
  std::unique_ptr<int> tab_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The discarded tab, if it was successfully discarded; undefined otherwise.
std::unique_ptr<base::ListValue> Create(const Tab& tab);
}  // namespace Results

}  // namespace Discard

namespace GoForward {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the tab to navigate forward; defaults to the selected tab of the
  // current window.
  std::unique_ptr<int> tab_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace GoForward

namespace GoBack {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the tab to navigate back; defaults to the selected tab of the
  // current window.
  std::unique_ptr<int> tab_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace GoBack

//
// Events
//

namespace OnCreated {

extern const char kEventName[];  // "tabs.onCreated"

// Details of the tab that was created.
std::unique_ptr<base::ListValue> Create(const Tab& tab);
}  // namespace OnCreated

namespace OnUpdated {

extern const char kEventName[];  // "tabs.onUpdated"

// Lists the changes to the state of the tab that was updated.
struct ChangeInfo {
  ChangeInfo();
  ~ChangeInfo();
  ChangeInfo(ChangeInfo&& rhs);
  ChangeInfo& operator=(ChangeInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ChangeInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The tab's loading status.
  TabStatus status;

  // The tab's URL if it has changed.
  std::unique_ptr<std::string> url;

  // The tab's new pinned state.
  std::unique_ptr<bool> pinned;

  // The tab's new audible state.
  std::unique_ptr<bool> audible;

  // The tab's new discarded state.
  std::unique_ptr<bool> discarded;

  // The tab's new auto-discardable state.
  std::unique_ptr<bool> auto_discardable;

  // The tab's new muted state and the reason for the change.
  std::unique_ptr<MutedInfo> muted_info;

  // The tab's new favicon URL.
  std::unique_ptr<std::string> fav_icon_url;

  // The tab's new title.
  std::unique_ptr<std::string> title;


 private:
  DISALLOW_COPY_AND_ASSIGN(ChangeInfo);
};


// Lists the changes to the state of the tab that was updated.
// Gives the state of the tab that was updated.
std::unique_ptr<base::ListValue> Create(int tab_id, const ChangeInfo& change_info, const Tab& tab);
}  // namespace OnUpdated

namespace OnMoved {

extern const char kEventName[];  // "tabs.onMoved"

struct MoveInfo {
  MoveInfo();
  ~MoveInfo();
  MoveInfo(MoveInfo&& rhs);
  MoveInfo& operator=(MoveInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MoveInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int window_id;

  int from_index;

  int to_index;


 private:
  DISALLOW_COPY_AND_ASSIGN(MoveInfo);
};


std::unique_ptr<base::ListValue> Create(int tab_id, const MoveInfo& move_info);
}  // namespace OnMoved

namespace OnSelectionChanged {

extern const char kEventName[];  // "tabs.onSelectionChanged"

struct SelectInfo {
  SelectInfo();
  ~SelectInfo();
  SelectInfo(SelectInfo&& rhs);
  SelectInfo& operator=(SelectInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SelectInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the window the selected tab changed inside of.
  int window_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(SelectInfo);
};


// The ID of the tab that has become active.
std::unique_ptr<base::ListValue> Create(int tab_id, const SelectInfo& select_info);
}  // namespace OnSelectionChanged

namespace OnActiveChanged {

extern const char kEventName[];  // "tabs.onActiveChanged"

struct SelectInfo {
  SelectInfo();
  ~SelectInfo();
  SelectInfo(SelectInfo&& rhs);
  SelectInfo& operator=(SelectInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SelectInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the window the selected tab changed inside of.
  int window_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(SelectInfo);
};


// The ID of the tab that has become active.
std::unique_ptr<base::ListValue> Create(int tab_id, const SelectInfo& select_info);
}  // namespace OnActiveChanged

namespace OnActivated {

extern const char kEventName[];  // "tabs.onActivated"

struct ActiveInfo {
  ActiveInfo();
  ~ActiveInfo();
  ActiveInfo(ActiveInfo&& rhs);
  ActiveInfo& operator=(ActiveInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ActiveInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the tab that has become active.
  int tab_id;

  // The ID of the window the active tab changed inside of.
  int window_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(ActiveInfo);
};


std::unique_ptr<base::ListValue> Create(const ActiveInfo& active_info);
}  // namespace OnActivated

namespace OnHighlightChanged {

extern const char kEventName[];  // "tabs.onHighlightChanged"

struct SelectInfo {
  SelectInfo();
  ~SelectInfo();
  SelectInfo(SelectInfo&& rhs);
  SelectInfo& operator=(SelectInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SelectInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The window whose tabs changed.
  int window_id;

  // All highlighted tabs in the window.
  std::vector<int> tab_ids;


 private:
  DISALLOW_COPY_AND_ASSIGN(SelectInfo);
};


std::unique_ptr<base::ListValue> Create(const SelectInfo& select_info);
}  // namespace OnHighlightChanged

namespace OnHighlighted {

extern const char kEventName[];  // "tabs.onHighlighted"

struct HighlightInfo {
  HighlightInfo();
  ~HighlightInfo();
  HighlightInfo(HighlightInfo&& rhs);
  HighlightInfo& operator=(HighlightInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this HighlightInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The window whose tabs changed.
  int window_id;

  // All highlighted tabs in the window.
  std::vector<int> tab_ids;


 private:
  DISALLOW_COPY_AND_ASSIGN(HighlightInfo);
};


std::unique_ptr<base::ListValue> Create(const HighlightInfo& highlight_info);
}  // namespace OnHighlighted

namespace OnDetached {

extern const char kEventName[];  // "tabs.onDetached"

struct DetachInfo {
  DetachInfo();
  ~DetachInfo();
  DetachInfo(DetachInfo&& rhs);
  DetachInfo& operator=(DetachInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DetachInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int old_window_id;

  int old_position;


 private:
  DISALLOW_COPY_AND_ASSIGN(DetachInfo);
};


std::unique_ptr<base::ListValue> Create(int tab_id, const DetachInfo& detach_info);
}  // namespace OnDetached

namespace OnAttached {

extern const char kEventName[];  // "tabs.onAttached"

struct AttachInfo {
  AttachInfo();
  ~AttachInfo();
  AttachInfo(AttachInfo&& rhs);
  AttachInfo& operator=(AttachInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AttachInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int new_window_id;

  int new_position;


 private:
  DISALLOW_COPY_AND_ASSIGN(AttachInfo);
};


std::unique_ptr<base::ListValue> Create(int tab_id, const AttachInfo& attach_info);
}  // namespace OnAttached

namespace OnRemoved {

extern const char kEventName[];  // "tabs.onRemoved"

struct RemoveInfo {
  RemoveInfo();
  ~RemoveInfo();
  RemoveInfo(RemoveInfo&& rhs);
  RemoveInfo& operator=(RemoveInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RemoveInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The window whose tab is closed.
  int window_id;

  // True when the tab was closed because its parent window was closed.
  bool is_window_closing;


 private:
  DISALLOW_COPY_AND_ASSIGN(RemoveInfo);
};


std::unique_ptr<base::ListValue> Create(int tab_id, const RemoveInfo& remove_info);
}  // namespace OnRemoved

namespace OnReplaced {

extern const char kEventName[];  // "tabs.onReplaced"

std::unique_ptr<base::ListValue> Create(int added_tab_id, int removed_tab_id);
}  // namespace OnReplaced

namespace OnZoomChange {

extern const char kEventName[];  // "tabs.onZoomChange"

struct ZoomChangeInfo {
  ZoomChangeInfo();
  ~ZoomChangeInfo();
  ZoomChangeInfo(ZoomChangeInfo&& rhs);
  ZoomChangeInfo& operator=(ZoomChangeInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ZoomChangeInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int tab_id;

  double old_zoom_factor;

  double new_zoom_factor;

  ZoomSettings zoom_settings;


 private:
  DISALLOW_COPY_AND_ASSIGN(ZoomChangeInfo);
};


std::unique_ptr<base::ListValue> Create(const ZoomChangeInfo& zoom_change_info);
}  // namespace OnZoomChange

}  // namespace tabs
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_TABS_H__
