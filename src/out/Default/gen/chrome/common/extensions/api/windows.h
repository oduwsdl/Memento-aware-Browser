// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/windows.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_WINDOWS_H__
#define CHROME_COMMON_EXTENSIONS_API_WINDOWS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace tabs {
struct Tab;
}  // namespace tabs
}  // namespace api
}  // namespace extensions

namespace extensions {
namespace api {
namespace windows {

//
// Properties
//

// The windowId value that represents the absence of a chrome browser window.
extern const int WINDOW_ID_NONE;

// The windowId value that represents the <a
// href='windows#current-window'>current window</a>.
extern const int WINDOW_ID_CURRENT;

//
// Types
//

// The type of browser window this is. In some circumstances a window may not be
// assigned a <code>type</code> property; for example, when querying closed
// windows from the $(ref:sessions) API.
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

// The state of this browser window. In some circumstances a window may not be
// assigned a <code>state</code> property; for example, when querying closed
// windows from the $(ref:sessions) API.
enum WindowState {
  WINDOW_STATE_NONE,
  WINDOW_STATE_NORMAL,
  WINDOW_STATE_MINIMIZED,
  WINDOW_STATE_MAXIMIZED,
  WINDOW_STATE_FULLSCREEN,
  WINDOW_STATE_LOCKED_FULLSCREEN,
  WINDOW_STATE_LAST = WINDOW_STATE_LOCKED_FULLSCREEN,
};


const char* ToString(WindowState as_enum);
WindowState ParseWindowState(const std::string& as_string);

struct Window {
  Window();
  ~Window();
  Window(Window&& rhs);
  Window& operator=(Window&& rhs);

  // Populates a Window object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Window* out);

  // Creates a Window object from a base::Value, or NULL on failure.
  static std::unique_ptr<Window> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Window object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the window. Window IDs are unique within a browser session. In some
  // circumstances a window may not be assigned an <code>ID</code> property; for
  // example, when querying windows using the $(ref:sessions) API, in which case a
  // session ID may be present.
  std::unique_ptr<int> id;

  // Whether the window is currently the focused window.
  bool focused;

  // The offset of the window from the top edge of the screen in pixels. In some
  // circumstances a window may not be assigned a <code>top</code> property; for
  // example, when querying closed windows from the $(ref:sessions) API.
  std::unique_ptr<int> top;

  // The offset of the window from the left edge of the screen in pixels. In some
  // circumstances a window may not be assigned a <code>left</code> property; for
  // example, when querying closed windows from the $(ref:sessions) API.
  std::unique_ptr<int> left;

  // The width of the window, including the frame, in pixels. In some
  // circumstances a window may not be assigned a <code>width</code> property; for
  // example, when querying closed windows from the $(ref:sessions) API.
  std::unique_ptr<int> width;

  // The height of the window, including the frame, in pixels. In some
  // circumstances a window may not be assigned a <code>height</code> property;
  // for example, when querying closed windows from the $(ref:sessions) API.
  std::unique_ptr<int> height;

  // Array of $(ref:tabs.Tab) objects representing the current tabs in the window.
  std::unique_ptr<std::vector<extensions::api::tabs::Tab>> tabs;

  // Whether the window is incognito.
  bool incognito;

  // The type of browser window this is.
  WindowType type;

  // The state of this browser window.
  WindowState state;

  // Whether the window is set to be always on top.
  bool always_on_top;

  // The session ID used to uniquely identify a window, obtained from the
  // $(ref:sessions) API.
  std::unique_ptr<std::string> session_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(Window);
};

// Specifies what type of browser window to create. 'panel' is deprecated and is
// available only to existing whitelisted extensions on Chrome OS.
enum CreateType {
  CREATE_TYPE_NONE,
  CREATE_TYPE_NORMAL,
  CREATE_TYPE_POPUP,
  CREATE_TYPE_PANEL,
  CREATE_TYPE_LAST = CREATE_TYPE_PANEL,
};


const char* ToString(CreateType as_enum);
CreateType ParseCreateType(const std::string& as_string);


//
// Functions
//

namespace Get {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct GetInfo {
    GetInfo();
    ~GetInfo();
    GetInfo(GetInfo&& rhs);
    GetInfo& operator=(GetInfo&& rhs);

    // Populates a GetInfo object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, GetInfo* out);

    // If true, the $(ref:windows.Window) object has a <var>tabs</var> property that
    // contains a list of the $(ref:tabs.Tab) objects. The <code>Tab</code> objects
    // only contain the <code>url</code>, <code>pendingUrl</code>,
    // <code>title</code>, and <code>favIconUrl</code> properties if the extension's
    // manifest file includes the <code>"tabs"</code> permission.
    std::unique_ptr<bool> populate;

    // If set, the $(ref:windows.Window) returned is filtered based on its type. If
    // unset, the default filter is set to <code>['normal', 'popup']</code>.
    std::unique_ptr<std::vector<WindowType>> window_types;


   private:
    DISALLOW_COPY_AND_ASSIGN(GetInfo);
  };


  int window_id;

  std::unique_ptr<GetInfo> get_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Window& window);
}  // namespace Results

}  // namespace Get

namespace GetCurrent {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct GetInfo {
    GetInfo();
    ~GetInfo();
    GetInfo(GetInfo&& rhs);
    GetInfo& operator=(GetInfo&& rhs);

    // Populates a GetInfo object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, GetInfo* out);

    // If true, the $(ref:windows.Window) object has a <var>tabs</var> property that
    // contains a list of the $(ref:tabs.Tab) objects. The <code>Tab</code> objects
    // only contain the <code>url</code>, <code>pendingUrl</code>,
    // <code>title</code>, and <code>favIconUrl</code> properties if the extension's
    // manifest file includes the <code>"tabs"</code> permission.
    std::unique_ptr<bool> populate;

    // If set, the $(ref:windows.Window) returned is filtered based on its type. If
    // unset, the default filter is set to <code>['normal', 'popup']</code>.
    std::unique_ptr<std::vector<WindowType>> window_types;


   private:
    DISALLOW_COPY_AND_ASSIGN(GetInfo);
  };


  std::unique_ptr<GetInfo> get_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Window& window);
}  // namespace Results

}  // namespace GetCurrent

namespace GetLastFocused {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct GetInfo {
    GetInfo();
    ~GetInfo();
    GetInfo(GetInfo&& rhs);
    GetInfo& operator=(GetInfo&& rhs);

    // Populates a GetInfo object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, GetInfo* out);

    // If true, the $(ref:windows.Window) object has a <var>tabs</var> property that
    // contains a list of the $(ref:tabs.Tab) objects. The <code>Tab</code> objects
    // only contain the <code>url</code>, <code>pendingUrl</code>,
    // <code>title</code>, and <code>favIconUrl</code> properties if the extension's
    // manifest file includes the <code>"tabs"</code> permission.
    std::unique_ptr<bool> populate;

    // If set, the $(ref:windows.Window) returned is filtered based on its type. If
    // unset, the default filter is set to <code>['normal', 'popup']</code>.
    std::unique_ptr<std::vector<WindowType>> window_types;


   private:
    DISALLOW_COPY_AND_ASSIGN(GetInfo);
  };


  std::unique_ptr<GetInfo> get_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Window& window);
}  // namespace Results

}  // namespace GetLastFocused

namespace GetAll {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct GetInfo {
    GetInfo();
    ~GetInfo();
    GetInfo(GetInfo&& rhs);
    GetInfo& operator=(GetInfo&& rhs);

    // Populates a GetInfo object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, GetInfo* out);

    // If true, each $(ref:windows.Window) object has a <var>tabs</var> property
    // that contains a list of the $(ref:tabs.Tab) objects for that window. The
    // <code>Tab</code> objects only contain the <code>url</code>,
    // <code>pendingUrl</code>, <code>title</code>, and <code>favIconUrl</code>
    // properties if the extension's manifest file includes the <code>"tabs"</code>
    // permission.
    std::unique_ptr<bool> populate;

    // If set, the $(ref:windows.Window) returned is filtered based on its type. If
    // unset, the default filter is set to <code>['normal', 'popup']</code>.
    std::unique_ptr<std::vector<WindowType>> window_types;


   private:
    DISALLOW_COPY_AND_ASSIGN(GetInfo);
  };


  std::unique_ptr<GetInfo> get_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Window>& windows);
}  // namespace Results

}  // namespace GetAll

namespace Create {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct CreateData {
    CreateData();
    ~CreateData();
    CreateData(CreateData&& rhs);
    CreateData& operator=(CreateData&& rhs);

    // Populates a CreateData object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, CreateData* out);

    // A URL or array of URLs to open as tabs in the window. Fully-qualified URLs
    // must include a scheme, e.g., 'http://www.google.com', not 'www.google.com'.
    // Non-fully-qualified URLs are considered relative within the extension.
    // Defaults to the New Tab Page.
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


    // A URL or array of URLs to open as tabs in the window. Fully-qualified URLs
    // must include a scheme, e.g., 'http://www.google.com', not 'www.google.com'.
    // Non-fully-qualified URLs are considered relative within the extension.
    // Defaults to the New Tab Page.
    std::unique_ptr<Url> url;

    // The ID of the tab to add to the new window.
    std::unique_ptr<int> tab_id;

    // The number of pixels to position the new window from the left edge of the
    // screen. If not specified, the new window is offset naturally from the last
    // focused window. This value is ignored for panels.
    std::unique_ptr<int> left;

    // The number of pixels to position the new window from the top edge of the
    // screen. If not specified, the new window is offset naturally from the last
    // focused window. This value is ignored for panels.
    std::unique_ptr<int> top;

    // The width in pixels of the new window, including the frame. If not specified,
    // defaults to a natural width.
    std::unique_ptr<int> width;

    // The height in pixels of the new window, including the frame. If not
    // specified, defaults to a natural height.
    std::unique_ptr<int> height;

    // If <code>true</code>, opens an active window. If <code>false</code>, opens an
    // inactive window.
    std::unique_ptr<bool> focused;

    // Whether the new window should be an incognito window.
    std::unique_ptr<bool> incognito;

    // Specifies what type of browser window to create.
    CreateType type;

    // The initial state of the window. The <code>minimized</code>,
    // <code>maximized</code>, and <code>fullscreen</code> states cannot be combined
    // with <code>left</code>, <code>top</code>, <code>width</code>, or
    // <code>height</code>.
    WindowState state;

    // If <code>true</code>, the newly-created window's 'window.opener' is set to
    // the caller and is in the same <a
    // href="https://www.w3.org/TR/html51/browsers.html#unit-of-related-browsing-contexts">unit of related browsing contexts</a> as the caller.
    std::unique_ptr<bool> set_self_as_opener;


   private:
    DISALLOW_COPY_AND_ASSIGN(CreateData);
  };


  std::unique_ptr<CreateData> create_data;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Contains details about the created window.
std::unique_ptr<base::ListValue> Create(const Window& window);
}  // namespace Results

}  // namespace Create

namespace Update {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct UpdateInfo {
    UpdateInfo();
    ~UpdateInfo();
    UpdateInfo(UpdateInfo&& rhs);
    UpdateInfo& operator=(UpdateInfo&& rhs);

    // Populates a UpdateInfo object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, UpdateInfo* out);

    // The offset from the left edge of the screen to move the window to in pixels.
    // This value is ignored for panels.
    std::unique_ptr<int> left;

    // The offset from the top edge of the screen to move the window to in pixels.
    // This value is ignored for panels.
    std::unique_ptr<int> top;

    // The width to resize the window to in pixels. This value is ignored for
    // panels.
    std::unique_ptr<int> width;

    // The height to resize the window to in pixels. This value is ignored for
    // panels.
    std::unique_ptr<int> height;

    // If <code>true</code>, brings the window to the front; cannot be combined with
    // the state 'minimized'. If <code>false</code>, brings the next window in the
    // z-order to the front; cannot be combined with the state 'fullscreen' or
    // 'maximized'.
    std::unique_ptr<bool> focused;

    // If <code>true</code>, causes the window to be displayed in a manner that
    // draws the user's attention to the window, without changing the focused
    // window. The effect lasts until the user changes focus to the window. This
    // option has no effect if the window already has focus. Set to
    // <code>false</code> to cancel a previous <code>drawAttention</code> request.
    std::unique_ptr<bool> draw_attention;

    // The new state of the window. The 'minimized', 'maximized', and 'fullscreen'
    // states cannot be combined with 'left', 'top', 'width', or 'height'.
    WindowState state;


   private:
    DISALLOW_COPY_AND_ASSIGN(UpdateInfo);
  };


  int window_id;

  UpdateInfo update_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Window& window);
}  // namespace Results

}  // namespace Update

namespace Remove {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int window_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Remove

//
// Events
//

namespace OnCreated {

extern const char kEventName[];  // "windows.onCreated"

// Details of the created window.
std::unique_ptr<base::ListValue> Create(const Window& window);
}  // namespace OnCreated

namespace OnRemoved {

extern const char kEventName[];  // "windows.onRemoved"

// ID of the removed window.
std::unique_ptr<base::ListValue> Create(int window_id);
}  // namespace OnRemoved

namespace OnFocusChanged {

extern const char kEventName[];  // "windows.onFocusChanged"

// ID of the newly-focused window.
std::unique_ptr<base::ListValue> Create(int window_id);
}  // namespace OnFocusChanged

}  // namespace windows
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_WINDOWS_H__
