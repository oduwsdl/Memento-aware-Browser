// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/autotest_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_AUTOTEST_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_AUTOTEST_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace autotest_private {

//
// Types
//

enum ShelfAlignmentType {
  SHELF_ALIGNMENT_TYPE_NONE,
  SHELF_ALIGNMENT_TYPE_BOTTOM,
  SHELF_ALIGNMENT_TYPE_LEFT,
  SHELF_ALIGNMENT_TYPE_RIGHT,
  SHELF_ALIGNMENT_TYPE_LAST = SHELF_ALIGNMENT_TYPE_RIGHT,
};


const char* ToString(ShelfAlignmentType as_enum);
ShelfAlignmentType ParseShelfAlignmentType(const std::string& as_string);

// A mapping of ash::ShelfItemType.
enum ShelfItemType {
  SHELF_ITEM_TYPE_NONE,
  SHELF_ITEM_TYPE_APP,
  SHELF_ITEM_TYPE_PINNEDAPP,
  SHELF_ITEM_TYPE_BROWSERSHORTCUT,
  SHELF_ITEM_TYPE_DIALOG,
  SHELF_ITEM_TYPE_LAST = SHELF_ITEM_TYPE_DIALOG,
};


const char* ToString(ShelfItemType as_enum);
ShelfItemType ParseShelfItemType(const std::string& as_string);

// A mapping of ash::ShelfItemStatus.
enum ShelfItemStatus {
  SHELF_ITEM_STATUS_NONE,
  SHELF_ITEM_STATUS_CLOSED,
  SHELF_ITEM_STATUS_RUNNING,
  SHELF_ITEM_STATUS_ATTENTION,
  SHELF_ITEM_STATUS_LAST = SHELF_ITEM_STATUS_ATTENTION,
};


const char* ToString(ShelfItemStatus as_enum);
ShelfItemStatus ParseShelfItemStatus(const std::string& as_string);

// A mapping of apps::mojom::Type
enum AppType {
  APP_TYPE_NONE,
  APP_TYPE_ARC,
  APP_TYPE_BUILTIN,
  APP_TYPE_CROSTINI,
  APP_TYPE_EXTENSION,
  APP_TYPE_WEB,
  APP_TYPE_MACNATIVE,
  APP_TYPE_PLUGINVM,
  APP_TYPE_LACROS,
  APP_TYPE_LAST = APP_TYPE_LACROS,
};


const char* ToString(AppType as_enum);
AppType ParseAppType(const std::string& as_string);

// A mapping of apps::mojom::Readiness
enum AppReadiness {
  APP_READINESS_NONE,
  APP_READINESS_READY,
  APP_READINESS_DISABLEDBYBLACKLIST,
  APP_READINESS_DISABLEDBYPOLICY,
  APP_READINESS_DISABLEDBYUSER,
  APP_READINESS_TERMINATED,
  APP_READINESS_UNINSTALLEDBYUSER,
  APP_READINESS_LAST = APP_READINESS_UNINSTALLEDBYUSER,
};


const char* ToString(AppReadiness as_enum);
AppReadiness ParseAppReadiness(const std::string& as_string);

// A subset of Window State types in ash::WindowStateType. We may add more into
// the set in the future.
enum WindowStateType {
  WINDOW_STATE_TYPE_NONE,
  WINDOW_STATE_TYPE_NORMAL,
  WINDOW_STATE_TYPE_MINIMIZED,
  WINDOW_STATE_TYPE_MAXIMIZED,
  WINDOW_STATE_TYPE_FULLSCREEN,
  WINDOW_STATE_TYPE_LEFTSNAPPED,
  WINDOW_STATE_TYPE_RIGHTSNAPPED,
  WINDOW_STATE_TYPE_PIP,
  WINDOW_STATE_TYPE_LAST = WINDOW_STATE_TYPE_PIP,
};


const char* ToString(WindowStateType as_enum);
WindowStateType ParseWindowStateType(const std::string& as_string);

// A subset of WM event types in ash::WMEventType. We may add more in the set in
// the future.
enum WMEventType {
  WM_EVENT_TYPE_NONE,
  WM_EVENT_TYPE_WMEVENTNORMAL,
  WM_EVENT_TYPE_WMEVENTMAXIMIZE,
  WM_EVENT_TYPE_WMEVENTMINIMIZE,
  WM_EVENT_TYPE_WMEVENTFULLSCREEN,
  WM_EVENT_TYPE_WMEVENTSNAPLEFT,
  WM_EVENT_TYPE_WMEVENTSNAPRIGHT,
  WM_EVENT_TYPE_LAST = WM_EVENT_TYPE_WMEVENTSNAPRIGHT,
};


const char* ToString(WMEventType as_enum);
WMEventType ParseWMEventType(const std::string& as_string);

// Display orientation type.
enum RotationType {
  ROTATION_TYPE_NONE,
  ROTATION_TYPE_ROTATE0,
  ROTATION_TYPE_ROTATE90,
  ROTATION_TYPE_ROTATE180,
  ROTATION_TYPE_ROTATE270,
  ROTATION_TYPE_LAST = ROTATION_TYPE_ROTATE270,
};


const char* ToString(RotationType as_enum);
RotationType ParseRotationType(const std::string& as_string);

enum LauncherStateType {
  LAUNCHER_STATE_TYPE_NONE,
  LAUNCHER_STATE_TYPE_CLOSED,
  LAUNCHER_STATE_TYPE_PEEKING,
  LAUNCHER_STATE_TYPE_HALF,
  LAUNCHER_STATE_TYPE_FULLSCREENALLAPPS,
  LAUNCHER_STATE_TYPE_FULLSCREENSEARCH,
  LAUNCHER_STATE_TYPE_LAST = LAUNCHER_STATE_TYPE_FULLSCREENSEARCH,
};


const char* ToString(LauncherStateType as_enum);
LauncherStateType ParseLauncherStateType(const std::string& as_string);

enum OverviewStateType {
  OVERVIEW_STATE_TYPE_NONE,
  OVERVIEW_STATE_TYPE_SHOWN,
  OVERVIEW_STATE_TYPE_HIDDEN,
  OVERVIEW_STATE_TYPE_LAST = OVERVIEW_STATE_TYPE_HIDDEN,
};


const char* ToString(OverviewStateType as_enum);
OverviewStateType ParseOverviewStateType(const std::string& as_string);

enum MouseButton {
  MOUSE_BUTTON_NONE,
  MOUSE_BUTTON_LEFT,
  MOUSE_BUTTON_MIDDLE,
  MOUSE_BUTTON_RIGHT,
  MOUSE_BUTTON_LAST = MOUSE_BUTTON_RIGHT,
};


const char* ToString(MouseButton as_enum);
MouseButton ParseMouseButton(const std::string& as_string);

struct WindowStateChangeDict {
  WindowStateChangeDict();
  ~WindowStateChangeDict();
  WindowStateChangeDict(WindowStateChangeDict&& rhs);
  WindowStateChangeDict& operator=(WindowStateChangeDict&& rhs);

  // Populates a WindowStateChangeDict object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, WindowStateChangeDict* out);

  // Creates a WindowStateChangeDict object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<WindowStateChangeDict> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this WindowStateChangeDict object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The WM event to change the ARC window state.
  WMEventType event_type;

  // If the initial state is already same as the expected state, should we treat
  // this case as a failure? Default value is false.
  std::unique_ptr<bool> fail_if_no_change;


 private:
  DISALLOW_COPY_AND_ASSIGN(WindowStateChangeDict);
};

struct LoginStatusDict {
  LoginStatusDict();
  ~LoginStatusDict();
  LoginStatusDict(LoginStatusDict&& rhs);
  LoginStatusDict& operator=(LoginStatusDict&& rhs);

  // Populates a LoginStatusDict object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, LoginStatusDict* out);

  // Creates a LoginStatusDict object from a base::Value, or NULL on failure.
  static std::unique_ptr<LoginStatusDict> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this LoginStatusDict object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Are we logged in?
  bool is_logged_in;

  // Is the logged-in user the owner?
  bool is_owner;

  // Is the screen locked?
  bool is_screen_locked;

  // Is the screen ready for password?
  bool is_ready_for_password;

  // Is the logged-in user a regular user?
  bool is_regular_user;

  // Are we logged into the guest account?
  bool is_guest;

  // Are we logged into kiosk-app mode?
  bool is_kiosk;

  std::string email;

  std::string display_email;

  // User image: 'file', 'profile' or a number.
  std::string user_image;


 private:
  DISALLOW_COPY_AND_ASSIGN(LoginStatusDict);
};

struct ExtensionInfoDict {
  ExtensionInfoDict();
  ~ExtensionInfoDict();
  ExtensionInfoDict(ExtensionInfoDict&& rhs);
  ExtensionInfoDict& operator=(ExtensionInfoDict&& rhs);

  // Populates a ExtensionInfoDict object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ExtensionInfoDict* out);

  // Creates a ExtensionInfoDict object from a base::Value, or NULL on failure.
  static std::unique_ptr<ExtensionInfoDict> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ExtensionInfoDict object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string id;

  std::string version;

  std::string name;

  std::string public_key;

  std::string description;

  std::string background_url;

  std::string options_url;

  std::vector<std::string> host_permissions;

  std::vector<std::string> effective_host_permissions;

  std::vector<std::string> api_permissions;

  bool is_component;

  bool is_internal;

  bool is_user_installed;

  bool is_enabled;

  bool allowed_in_incognito;

  bool has_page_action;


 private:
  DISALLOW_COPY_AND_ASSIGN(ExtensionInfoDict);
};

struct ExtensionsInfoArray {
  ExtensionsInfoArray();
  ~ExtensionsInfoArray();
  ExtensionsInfoArray(ExtensionsInfoArray&& rhs);
  ExtensionsInfoArray& operator=(ExtensionsInfoArray&& rhs);

  // Populates a ExtensionsInfoArray object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ExtensionsInfoArray* out);

  // Creates a ExtensionsInfoArray object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ExtensionsInfoArray> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ExtensionsInfoArray object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::vector<ExtensionInfoDict> extensions;


 private:
  DISALLOW_COPY_AND_ASSIGN(ExtensionsInfoArray);
};

struct Notification {
  Notification();
  ~Notification();
  Notification(Notification&& rhs);
  Notification& operator=(Notification&& rhs);

  // Populates a Notification object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, Notification* out);

  // Creates a Notification object from a base::Value, or NULL on failure.
  static std::unique_ptr<Notification> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Notification object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string id;

  std::string type;

  std::string title;

  std::string message;

  int priority;

  int progress;


 private:
  DISALLOW_COPY_AND_ASSIGN(Notification);
};

struct Printer {
  Printer();
  ~Printer();
  Printer(Printer&& rhs);
  Printer& operator=(Printer&& rhs);

  // Populates a Printer object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Printer* out);

  // Creates a Printer object from a base::Value, or NULL on failure.
  static std::unique_ptr<Printer> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Printer object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string printer_name;

  std::unique_ptr<std::string> printer_id;

  std::unique_ptr<std::string> printer_type;

  std::unique_ptr<std::string> printer_desc;

  std::unique_ptr<std::string> printer_make_and_model;

  std::unique_ptr<std::string> printer_uri;

  std::unique_ptr<std::string> printer_ppd;


 private:
  DISALLOW_COPY_AND_ASSIGN(Printer);
};

struct ArcState {
  ArcState();
  ~ArcState();
  ArcState(ArcState&& rhs);
  ArcState& operator=(ArcState&& rhs);

  // Populates a ArcState object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, ArcState* out);

  // Creates a ArcState object from a base::Value, or NULL on failure.
  static std::unique_ptr<ArcState> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ArcState object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Whether the ARC is provisioned.
  bool provisioned;

  // Whether ARC Terms of Service needs to be shown.
  bool tos_needed;


 private:
  DISALLOW_COPY_AND_ASSIGN(ArcState);
};

struct PlayStoreState {
  PlayStoreState();
  ~PlayStoreState();
  PlayStoreState(PlayStoreState&& rhs);
  PlayStoreState& operator=(PlayStoreState&& rhs);

  // Populates a PlayStoreState object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, PlayStoreState* out);

  // Creates a PlayStoreState object from a base::Value, or NULL on failure.
  static std::unique_ptr<PlayStoreState> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PlayStoreState object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Whether the Play Store allowed for the current user.
  bool allowed;

  // Whether the Play Store currently enabled.
  std::unique_ptr<bool> enabled;

  // Whether the Play Store managed by policy.
  std::unique_ptr<bool> managed;


 private:
  DISALLOW_COPY_AND_ASSIGN(PlayStoreState);
};

struct AssistantQueryResponse {
  AssistantQueryResponse();
  ~AssistantQueryResponse();
  AssistantQueryResponse(AssistantQueryResponse&& rhs);
  AssistantQueryResponse& operator=(AssistantQueryResponse&& rhs);

  // Populates a AssistantQueryResponse object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, AssistantQueryResponse* out);

  // Creates a AssistantQueryResponse object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<AssistantQueryResponse> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AssistantQueryResponse object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Text response returned from server.
  std::unique_ptr<std::string> text;

  // HTML response returned from server, usually accompanied with fallback text.
  std::unique_ptr<std::string> html_response;

  // Text messages used as the "fallback" for HTML card rendering. Generally the
  // fallback text is similar to transcribed TTS, e.g. "It's exactly 6 o'clock."
  // or "Turning bluetooth off.".
  std::unique_ptr<std::string> html_fallback;


 private:
  DISALLOW_COPY_AND_ASSIGN(AssistantQueryResponse);
};

struct AssistantQueryStatus {
  AssistantQueryStatus();
  ~AssistantQueryStatus();
  AssistantQueryStatus(AssistantQueryStatus&& rhs);
  AssistantQueryStatus& operator=(AssistantQueryStatus&& rhs);

  // Populates a AssistantQueryStatus object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AssistantQueryStatus* out);

  // Creates a AssistantQueryStatus object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<AssistantQueryStatus> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AssistantQueryStatus object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Indicates whether this might be a voice interaction.
  bool is_mic_open;

  // Query text sent to Assistant. In the event of a voice interaction, this field
  // will be same as the speech recognition final result.
  std::string query_text;

  // Response for the current query.
  AssistantQueryResponse query_response;


 private:
  DISALLOW_COPY_AND_ASSIGN(AssistantQueryStatus);
};

struct ArcAppDict {
  ArcAppDict();
  ~ArcAppDict();
  ArcAppDict(ArcAppDict&& rhs);
  ArcAppDict& operator=(ArcAppDict&& rhs);

  // Populates a ArcAppDict object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, ArcAppDict* out);

  // Creates a ArcAppDict object from a base::Value, or NULL on failure.
  static std::unique_ptr<ArcAppDict> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ArcAppDict object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string name;

  std::string package_name;

  std::string activity;

  std::string intent_uri;

  std::string icon_resource_id;

  double last_launch_time;

  double install_time;

  bool sticky;

  bool notifications_enabled;

  bool ready;

  bool suspended;

  bool show_in_launcher;

  bool shortcut;

  bool launchable;


 private:
  DISALLOW_COPY_AND_ASSIGN(ArcAppDict);
};

struct ArcPackageDict {
  ArcPackageDict();
  ~ArcPackageDict();
  ArcPackageDict(ArcPackageDict&& rhs);
  ArcPackageDict& operator=(ArcPackageDict&& rhs);

  // Populates a ArcPackageDict object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ArcPackageDict* out);

  // Creates a ArcPackageDict object from a base::Value, or NULL on failure.
  static std::unique_ptr<ArcPackageDict> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ArcPackageDict object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string package_name;

  int package_version;

  std::string last_backup_android_id;

  double last_backup_time;

  bool should_sync;

  bool system;

  bool vpn_provider;


 private:
  DISALLOW_COPY_AND_ASSIGN(ArcPackageDict);
};

struct Location {
  Location();
  ~Location();
  Location(Location&& rhs);
  Location& operator=(Location&& rhs);

  // Populates a Location object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Location* out);

  // Creates a Location object from a base::Value, or NULL on failure.
  static std::unique_ptr<Location> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Location object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  double x;

  double y;


 private:
  DISALLOW_COPY_AND_ASSIGN(Location);
};

struct Bounds {
  Bounds();
  ~Bounds();
  Bounds(Bounds&& rhs);
  Bounds& operator=(Bounds&& rhs);

  // Populates a Bounds object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Bounds* out);

  // Creates a Bounds object from a base::Value, or NULL on failure.
  static std::unique_ptr<Bounds> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Bounds object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  double left;

  double top;

  double width;

  double height;


 private:
  DISALLOW_COPY_AND_ASSIGN(Bounds);
};

struct ArcAppTracingInfo {
  ArcAppTracingInfo();
  ~ArcAppTracingInfo();
  ArcAppTracingInfo(ArcAppTracingInfo&& rhs);
  ArcAppTracingInfo& operator=(ArcAppTracingInfo&& rhs);

  // Populates a ArcAppTracingInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ArcAppTracingInfo* out);

  // Creates a ArcAppTracingInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ArcAppTracingInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ArcAppTracingInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  bool success;

  double fps;

  double commit_deviation;

  double render_quality;


 private:
  DISALLOW_COPY_AND_ASSIGN(ArcAppTracingInfo);
};

struct App {
  App();
  ~App();
  App(App&& rhs);
  App& operator=(App&& rhs);

  // Populates a App object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, App* out);

  // Creates a App object from a base::Value, or NULL on failure.
  static std::unique_ptr<App> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this App object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string app_id;

  std::string name;

  std::string short_name;

  AppType type;

  AppReadiness readiness;

  std::vector<std::string> additional_search_terms;

  std::unique_ptr<bool> show_in_launcher;

  std::unique_ptr<bool> show_in_search;


 private:
  DISALLOW_COPY_AND_ASSIGN(App);
};

struct ShelfItem {
  ShelfItem();
  ~ShelfItem();
  ShelfItem(ShelfItem&& rhs);
  ShelfItem& operator=(ShelfItem&& rhs);

  // Populates a ShelfItem object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, ShelfItem* out);

  // Creates a ShelfItem object from a base::Value, or NULL on failure.
  static std::unique_ptr<ShelfItem> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ShelfItem object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string app_id;

  std::string launch_id;

  std::string title;

  ShelfItemType type;

  ShelfItemStatus status;

  bool shows_tooltip;

  bool pinned_by_policy;

  bool has_notification;


 private:
  DISALLOW_COPY_AND_ASSIGN(ShelfItem);
};

// A mapping of ash::AppType.
enum AppWindowType {
  APP_WINDOW_TYPE_NONE,
  APP_WINDOW_TYPE_BROWSER,
  APP_WINDOW_TYPE_CHROMEAPP,
  APP_WINDOW_TYPE_ARCAPP,
  APP_WINDOW_TYPE_CROSTINIAPP,
  APP_WINDOW_TYPE_SYSTEMAPP,
  APP_WINDOW_TYPE_EXTENSIONAPP,
  APP_WINDOW_TYPE_LAST = APP_WINDOW_TYPE_EXTENSIONAPP,
};


const char* ToString(AppWindowType as_enum);
AppWindowType ParseAppWindowType(const std::string& as_string);

// A mapping of HotseatState in ash/public/cpp/shelf_types.h.
enum HotseatState {
  HOTSEAT_STATE_NONE,
  HOTSEAT_STATE_HIDDEN,
  HOTSEAT_STATE_SHOWNCLAMSHELL,
  HOTSEAT_STATE_SHOWNHOMELAUNCHER,
  HOTSEAT_STATE_EXTENDED,
  HOTSEAT_STATE_LAST = HOTSEAT_STATE_EXTENDED,
};


const char* ToString(HotseatState as_enum);
HotseatState ParseHotseatState(const std::string& as_string);

// The frame mode of a window. None if the window is framesless.
enum FrameMode {
  FRAME_MODE_NONE,
  FRAME_MODE_NORMAL,
  FRAME_MODE_IMMERSIVE,
  FRAME_MODE_LAST = FRAME_MODE_IMMERSIVE,
};


const char* ToString(FrameMode as_enum);
FrameMode ParseFrameMode(const std::string& as_string);

struct OverviewInfo {
  OverviewInfo();
  ~OverviewInfo();
  OverviewInfo(OverviewInfo&& rhs);
  OverviewInfo& operator=(OverviewInfo&& rhs);

  // Populates a OverviewInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, OverviewInfo* out);

  // Creates a OverviewInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<OverviewInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this OverviewInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Bounds in screen of an OverviewItem.
  Bounds bounds;

  // Whether an OverviewItem is being dragged in overview.
  bool is_dragged;


 private:
  DISALLOW_COPY_AND_ASSIGN(OverviewInfo);
};

struct AppWindowInfo {
  AppWindowInfo();
  ~AppWindowInfo();
  AppWindowInfo(AppWindowInfo&& rhs);
  AppWindowInfo& operator=(AppWindowInfo&& rhs);

  // Populates a AppWindowInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, AppWindowInfo* out);

  // Creates a AppWindowInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<AppWindowInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AppWindowInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The identifier of the window. This shouldn't change across the time.
  int id;

  // The name of the window object -- typically internal class name of the window
  // (like 'BrowserFrame').
  std::string name;

  AppWindowType window_type;

  WindowStateType state_type;

  // The bounds of the window, in the coordinate of the root window (i.e. relative
  // to the display where this window resides).
  Bounds bounds_in_root;

  // The identifier of the display where this window resides.
  std::string display_id;

  bool is_visible;

  bool can_focus;

  // The title of the window; this can be seen in the window caption, or in the
  // overview mode. Typically, this provides the title of the webpage or the title
  // supplied by the application.
  std::string title;

  // Whether some animation is ongoing on the window or not.
  bool is_animating;

  // The final bounds of the window when the animation completes. This should be
  // same as |boundsInRoot| when |isAnimating| is false.
  Bounds target_bounds;

  // Whether or not the window is going to be visible after the animation
  // completes. This should be same as |isVisible| when |isAnimating| is false.
  bool target_visibility;

  // WM Releated states
  bool is_active;

  bool has_focus;

  bool on_active_desk;

  bool has_capture;

  bool can_resize;

  // Window frame info
  FrameMode frame_mode;

  bool is_frame_visible;

  int caption_height;

  // The bitset of the enabled caption buttons. See
  // ui/views/window/caption_button_types.h.
  int caption_button_enabled_status;

  // The bitset of the caption buttons which are visible on the frame.
  int caption_button_visible_status;

  std::unique_ptr<std::string> arc_package_name;

  std::unique_ptr<OverviewInfo> overview_info;


 private:
  DISALLOW_COPY_AND_ASSIGN(AppWindowInfo);
};

struct Accelerator {
  Accelerator();
  ~Accelerator();
  Accelerator(Accelerator&& rhs);
  Accelerator& operator=(Accelerator&& rhs);

  // Populates a Accelerator object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, Accelerator* out);

  // Creates a Accelerator object from a base::Value, or NULL on failure.
  static std::unique_ptr<Accelerator> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Accelerator object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string key_code;

  bool shift;

  bool control;

  bool alt;

  bool search;

  bool pressed;


 private:
  DISALLOW_COPY_AND_ASSIGN(Accelerator);
};

struct ScrollableShelfState {
  ScrollableShelfState();
  ~ScrollableShelfState();
  ScrollableShelfState(ScrollableShelfState&& rhs);
  ScrollableShelfState& operator=(ScrollableShelfState&& rhs);

  // Populates a ScrollableShelfState object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ScrollableShelfState* out);

  // Creates a ScrollableShelfState object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ScrollableShelfState> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ScrollableShelfState object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<double> scroll_distance;


 private:
  DISALLOW_COPY_AND_ASSIGN(ScrollableShelfState);
};

struct ShelfState {
  ShelfState();
  ~ShelfState();
  ShelfState(ShelfState&& rhs);
  ShelfState& operator=(ShelfState&& rhs);

  // Populates a ShelfState object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, ShelfState* out);

  // Creates a ShelfState object from a base::Value, or NULL on failure.
  static std::unique_ptr<ShelfState> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ShelfState object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<double> scroll_distance;


 private:
  DISALLOW_COPY_AND_ASSIGN(ShelfState);
};

struct ScrollableShelfInfo {
  ScrollableShelfInfo();
  ~ScrollableShelfInfo();
  ScrollableShelfInfo(ScrollableShelfInfo&& rhs);
  ScrollableShelfInfo& operator=(ScrollableShelfInfo&& rhs);

  // Populates a ScrollableShelfInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ScrollableShelfInfo* out);

  // Creates a ScrollableShelfInfo object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ScrollableShelfInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ScrollableShelfInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  double main_axis_offset;

  double page_offset;

  std::unique_ptr<double> target_main_axis_offset;

  Bounds left_arrow_bounds;

  Bounds right_arrow_bounds;

  bool is_animating;

  bool is_overflow;

  std::vector<Bounds> icons_bounds_in_screen;

  bool is_shelf_widget_animating;


 private:
  DISALLOW_COPY_AND_ASSIGN(ScrollableShelfInfo);
};

struct HotseatSwipeDescriptor {
  HotseatSwipeDescriptor();
  ~HotseatSwipeDescriptor();
  HotseatSwipeDescriptor(HotseatSwipeDescriptor&& rhs);
  HotseatSwipeDescriptor& operator=(HotseatSwipeDescriptor&& rhs);

  // Populates a HotseatSwipeDescriptor object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, HotseatSwipeDescriptor* out);

  // Creates a HotseatSwipeDescriptor object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<HotseatSwipeDescriptor> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this HotseatSwipeDescriptor object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  Location swipe_start_location;

  Location swipe_end_location;


 private:
  DISALLOW_COPY_AND_ASSIGN(HotseatSwipeDescriptor);
};

struct HotseatInfo {
  HotseatInfo();
  ~HotseatInfo();
  HotseatInfo(HotseatInfo&& rhs);
  HotseatInfo& operator=(HotseatInfo&& rhs);

  // Populates a HotseatInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, HotseatInfo* out);

  // Creates a HotseatInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<HotseatInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this HotseatInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  HotseatSwipeDescriptor swipe_up;

  HotseatState state;

  bool is_animating;


 private:
  DISALLOW_COPY_AND_ASSIGN(HotseatInfo);
};

struct ShelfUIInfo {
  ShelfUIInfo();
  ~ShelfUIInfo();
  ShelfUIInfo(ShelfUIInfo&& rhs);
  ShelfUIInfo& operator=(ShelfUIInfo&& rhs);

  // Populates a ShelfUIInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ShelfUIInfo* out);

  // Creates a ShelfUIInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ShelfUIInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ShelfUIInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  HotseatInfo hotseat_info;

  ScrollableShelfInfo scrollable_shelf_info;


 private:
  DISALLOW_COPY_AND_ASSIGN(ShelfUIInfo);
};

struct TraceConfig {
  TraceConfig();
  ~TraceConfig();
  TraceConfig(TraceConfig&& rhs);
  TraceConfig& operator=(TraceConfig&& rhs);

  // Populates a TraceConfig object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, TraceConfig* out);

  // Creates a TraceConfig object from a base::Value, or NULL on failure.
  static std::unique_ptr<TraceConfig> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this TraceConfig object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The recording mode of the trace. Possible options are: "record-until-full",
  // "record-continuously", "record-as-much-as-possible", and "trace-to-console".
  std::unique_ptr<std::string> record_mode;

  // Stop trace after capturing |trace_buffer_size_in_events| events.
  std::unique_ptr<int> trace_buffer_size_in_events;

  // Stop trace after capturing |trace_buffer_size_in_kb| kilobytes worth of
  // events.
  std::unique_ptr<int> trace_buffer_size_in_kb;

  // Determines whether systrace events should be included in the trace.
  std::unique_ptr<bool> enable_systrace;

  // Enables argument filter.
  std::unique_ptr<bool> enable_argument_filter;

  // A list of categories that should be included in the trace.
  std::unique_ptr<std::vector<std::string>> included_categories;

  // A list of categories that should be excluded from the the trace.
  std::unique_ptr<std::vector<std::string>> excluded_categories;

  // A list of processes from which events should be included in the trace. If
  // this parameter is empty or missing, traces from all processes are included.
  std::unique_ptr<std::vector<std::string>> included_process_ids;

  // A list of Systrace events that will be included in the trace.
  std::unique_ptr<std::vector<std::string>> enable_systrace_events;


 private:
  DISALLOW_COPY_AND_ASSIGN(TraceConfig);
};

struct SetWindowBoundsResult {
  SetWindowBoundsResult();
  ~SetWindowBoundsResult();
  SetWindowBoundsResult(SetWindowBoundsResult&& rhs);
  SetWindowBoundsResult& operator=(SetWindowBoundsResult&& rhs);

  // Populates a SetWindowBoundsResult object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, SetWindowBoundsResult* out);

  // Creates a SetWindowBoundsResult object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<SetWindowBoundsResult> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SetWindowBoundsResult object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Bounds of the window.
  Bounds bounds;

  // Display ID of the display the window is on.
  std::string display_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(SetWindowBoundsResult);
};


//
// Functions
//

namespace InitializeEvents {

}  // namespace InitializeEvents

namespace Logout {

}  // namespace Logout

namespace Restart {

}  // namespace Restart

namespace Shutdown {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // if set, ignore ongoing downloads and onunbeforeunload handlers.
  bool force;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Shutdown

namespace LoginStatus {

namespace Results {

std::unique_ptr<base::ListValue> Create(const LoginStatusDict& status);
}  // namespace Results

}  // namespace LoginStatus

namespace LockScreen {

}  // namespace LockScreen

namespace GetExtensionsInfo {

namespace Results {

std::unique_ptr<base::ListValue> Create(const ExtensionsInfoArray& info);
}  // namespace Results

}  // namespace GetExtensionsInfo

namespace GetAllEnterprisePolicies {

namespace Results {

std::unique_ptr<base::ListValue> Create(const base::Value& all_policies);
}  // namespace Results

}  // namespace GetAllEnterprisePolicies

namespace RefreshEnterprisePolicies {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RefreshEnterprisePolicies

namespace SimulateAsanMemoryBug {

}  // namespace SimulateAsanMemoryBug

namespace SetTouchpadSensitivity {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the pointer sensitivity setting index.
  int value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetTouchpadSensitivity

namespace SetTapToClick {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // if set, enable tap-to-click.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetTapToClick

namespace SetThreeFingerClick {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // if set, enable three finger click.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetThreeFingerClick

namespace SetTapDragging {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // if set, enable tap dragging.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetTapDragging

namespace SetNaturalScroll {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // if set, enable Australian scrolling.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetNaturalScroll

namespace SetMouseSensitivity {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the pointer sensitivity setting index.
  int value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetMouseSensitivity

namespace SetPrimaryButtonRight {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // if set, swap the primary mouse button.
  bool right;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetPrimaryButtonRight

namespace SetMouseReverseScroll {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // if set, enable reverse scrolling.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetMouseReverseScroll

namespace GetVisibleNotifications {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Notification>& notifications);
}  // namespace Results

}  // namespace GetVisibleNotifications

namespace GetArcStartTime {

namespace Results {

std::unique_ptr<base::ListValue> Create(double start_time);
}  // namespace Results

}  // namespace GetArcStartTime

namespace GetArcState {

namespace Results {

std::unique_ptr<base::ListValue> Create(const ArcState& result);
}  // namespace Results

}  // namespace GetArcState

namespace GetPlayStoreState {

namespace Results {

std::unique_ptr<base::ListValue> Create(const PlayStoreState& result);
}  // namespace Results

}  // namespace GetPlayStoreState

namespace GetPrinterList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Printer>& printers);
}  // namespace Results

}  // namespace GetPrinterList

namespace IsAppShown {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string app_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool app_shown);
}  // namespace Results

}  // namespace IsAppShown

namespace IsArcProvisioned {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool arc_provisioned);
}  // namespace Results

}  // namespace IsArcProvisioned

namespace GetArcApp {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string app_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ArcAppDict& package);
}  // namespace Results

}  // namespace GetArcApp

namespace GetArcPackage {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string package_name;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ArcPackageDict& package);
}  // namespace Results

}  // namespace GetArcPackage

namespace LaunchArcApp {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string app_id;

  std::string intent;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool app_launched);
}  // namespace Results

}  // namespace LaunchArcApp

namespace LaunchApp {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string app_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace LaunchApp

namespace CloseApp {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string app_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace CloseApp

namespace UpdatePrinter {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  Printer printer;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace UpdatePrinter

namespace RemovePrinter {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string printer_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RemovePrinter

namespace SetPlayStoreEnabled {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // if set, enable the Play Store.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetPlayStoreEnabled

namespace GetClipboardTextData {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& data);
}  // namespace Results

}  // namespace GetClipboardTextData

namespace SetClipboardTextData {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string data;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetClipboardTextData

namespace RunCrostiniInstaller {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RunCrostiniInstaller

namespace RunCrostiniUninstaller {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RunCrostiniUninstaller

namespace SetCrostiniEnabled {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Enable Crostini.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetCrostiniEnabled

namespace ExportCrostini {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The path in Downloads to save the export.
  std::string path;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ExportCrostini

namespace ImportCrostini {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The path in Downloads to read the import.
  std::string path;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ImportCrostini

namespace InstallPluginVM {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // URL to the image to install.
  std::string image_url;

  // Hash for the provided image.
  std::string image_hash;

  // License key for Plugin VM.
  std::string license_key;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace InstallPluginVM

namespace SetPluginVMPolicy {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // URL to the image to install.
  std::string image_url;

  // Hash for the provided image.
  std::string image_hash;

  // License key for Plugin VM.
  std::string license_key;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetPluginVMPolicy

namespace ShowPluginVMInstaller {

}  // namespace ShowPluginVMInstaller

namespace RegisterComponent {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The name of the component.
  std::string name;

  // Path to the component.
  std::string path;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RegisterComponent

namespace TakeScreenshot {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& base64_png);
}  // namespace Results

}  // namespace TakeScreenshot

namespace TakeScreenshotForDisplay {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the display id of the display.
  std::string display_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& base64_png);
}  // namespace Results

}  // namespace TakeScreenshotForDisplay

namespace BootstrapMachineLearningService {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace BootstrapMachineLearningService

namespace SetAssistantEnabled {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool enabled;

  int timeout_ms;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetAssistantEnabled

namespace EnableAssistantAndWaitForReady {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace EnableAssistantAndWaitForReady

namespace SendAssistantTextQuery {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string query;

  int timeout_ms;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const AssistantQueryStatus& status);
}  // namespace Results

}  // namespace SendAssistantTextQuery

namespace WaitForAssistantQueryStatus {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int timeout_s;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const AssistantQueryStatus& status);
}  // namespace Results

}  // namespace WaitForAssistantQueryStatus

namespace IsArcPackageListInitialRefreshed {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool refreshed);
}  // namespace Results

}  // namespace IsArcPackageListInitialRefreshed

namespace SetWhitelistedPref {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string pref_name;

  std::unique_ptr<base::Value> value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetWhitelistedPref

namespace SetCrostiniAppScaled {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The Crostini application ID.
  std::string app_id;

  // The app is "scaled" when shown, which means it uses low display
  // density.
  bool scaled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetCrostiniAppScaled

namespace GetPrimaryDisplayScaleFactor {

namespace Results {

std::unique_ptr<base::ListValue> Create(double scale_factor);
}  // namespace Results

}  // namespace GetPrimaryDisplayScaleFactor

namespace IsTabletModeEnabled {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool enabled);
}  // namespace Results

}  // namespace IsTabletModeEnabled

namespace SetTabletModeEnabled {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // if set, enable tablet mode.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool enabled);
}  // namespace Results

}  // namespace SetTabletModeEnabled

namespace GetAllInstalledApps {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<App>& apps);
}  // namespace Results

}  // namespace GetAllInstalledApps

namespace GetShelfItems {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<ShelfItem>& items);
}  // namespace Results

}  // namespace GetShelfItems

namespace GetShelfAutoHideBehavior {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // display that contains the shelf. |callback| is invoked with the shelf auto
  // hide behavior. Possible behavior values are: "always", "never" or "hidden".
  std::string display_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& behavior);
}  // namespace Results

}  // namespace GetShelfAutoHideBehavior

namespace SetShelfAutoHideBehavior {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // display that contains the shelf.
  std::string display_id;

  // an enum of "always", "never" or "hidden".
  std::string behavior;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetShelfAutoHideBehavior

namespace GetShelfAlignment {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // display that contains the shelf. |callback| is invoked with the shelf
  // alignment type.
  std::string display_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ShelfAlignmentType& alignment);
}  // namespace Results

}  // namespace GetShelfAlignment

namespace SetShelfAlignment {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // display that contains the shelf.
  std::string display_id;

  // the type of alignment to set.
  ShelfAlignmentType alignment;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetShelfAlignment

namespace PinShelfIcon {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string app_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace PinShelfIcon

namespace SetOverviewModeState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // whether entering to or exiting from the overview mode.
  bool start;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool finished);
}  // namespace Results

}  // namespace SetOverviewModeState

namespace ShowVirtualKeyboardIfEnabled {

}  // namespace ShowVirtualKeyboardIfEnabled

namespace ArcAppTracingStart {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ArcAppTracingStart

namespace ArcAppTracingStopAndAnalyze {

namespace Results {

std::unique_ptr<base::ListValue> Create(const ArcAppTracingInfo& info);
}  // namespace Results

}  // namespace ArcAppTracingStopAndAnalyze

namespace SwapWindowsInSplitView {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SwapWindowsInSplitView

namespace SetArcAppWindowFocus {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the package name of the ARC app window.
  std::string package_name;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetArcAppWindowFocus

namespace WaitForDisplayRotation {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // display that contains the shelf.
  std::string display_id;

  // the target rotation.
  RotationType rotation;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace WaitForDisplayRotation

namespace GetAppWindowList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<AppWindowInfo>& window_list);
}  // namespace Results

}  // namespace GetAppWindowList

namespace SetAppWindowState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the id of the window
  int id;

  // WM event type to send to the app window.
  WindowStateChangeDict change;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const WindowStateType& current_type);
}  // namespace Results

}  // namespace SetAppWindowState

namespace CloseAppWindow {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the id of the window
  int id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace CloseAppWindow

namespace InstallPWAForCurrentURL {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Timeout in milliseconds for the operation to complete.
  int timeout_ms;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& app_id);
}  // namespace Results

}  // namespace InstallPWAForCurrentURL

namespace ActivateAccelerator {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the accelerator to activate.
  Accelerator accelerator;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace ActivateAccelerator

namespace WaitForLauncherState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the target launcher state.
  LauncherStateType launcher_state;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace WaitForLauncherState

namespace WaitForOverviewState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the target overview state.
  OverviewStateType overview_state;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace WaitForOverviewState

namespace CreateNewDesk {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace CreateNewDesk

namespace ActivateDeskAtIndex {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the zero-based index of the desk desired to be activated.
  int index;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace ActivateDeskAtIndex

namespace RemoveActiveDesk {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace RemoveActiveDesk

namespace MouseClick {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the mouse button for the click event.
  MouseButton button;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace MouseClick

namespace MousePress {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the mouse button to be pressed.
  MouseButton button;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace MousePress

namespace MouseRelease {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the mouse button to be released.
  MouseButton button;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace MouseRelease

namespace MouseMove {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the target location (in display's coordinate).
  Location location;

  // the duration (in milliseconds) for the mouse movement.    The mouse will move
  // linearly. 0 means moving immediately.
  double duration_in_ms;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace MouseMove

namespace SetMetricsEnabled {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Enable metrics reporting.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetMetricsEnabled

namespace StartTracing {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the tracing configuration.
  TraceConfig config;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace StartTracing

namespace StopTracing {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& data);
}  // namespace Results

}  // namespace StopTracing

namespace SetArcTouchMode {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetArcTouchMode

namespace GetScrollableShelfInfoForState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  ScrollableShelfState state;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ScrollableShelfInfo& info);
}  // namespace Results

}  // namespace GetScrollableShelfInfoForState

namespace GetShelfUIInfoForState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  ShelfState state;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ShelfUIInfo& info);
}  // namespace Results

}  // namespace GetShelfUIInfoForState

namespace SetWindowBounds {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the id of the window.
  int id;

  // bounds the window should be set to.
  Bounds bounds;

  // id of display to move the window to.
  std::string display_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const SetWindowBoundsResult& result);
}  // namespace Results

}  // namespace SetWindowBounds

namespace StartSmoothnessTracking {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::unique_ptr<std::string> display_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace StartSmoothnessTracking

namespace StopSmoothnessTracking {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::unique_ptr<std::string> display_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int smoothness);
}  // namespace Results

}  // namespace StopSmoothnessTracking

namespace DisableSwitchAccessDialog {

}  // namespace DisableSwitchAccessDialog

namespace WaitForAmbientPhotoAnimation {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // photo refresh interval in seconds.
  int photo_refresh_interval;

  // number of completions of the animation.
  int num_completions;

  // the timeout in seconds.
  int timeout;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace WaitForAmbientPhotoAnimation

//
// Events
//

namespace OnClipboardDataChanged {

extern const char kEventName[];  // "autotestPrivate.onClipboardDataChanged"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnClipboardDataChanged

}  // namespace autotest_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_AUTOTEST_PRIVATE_H__
