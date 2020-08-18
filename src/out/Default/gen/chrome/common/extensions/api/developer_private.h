// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/developer_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_DEVELOPER_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_DEVELOPER_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace developer_private {

//
// Types
//

// DEPRECATED: Prefer ExtensionType.
enum ItemType {
  ITEM_TYPE_NONE,
  ITEM_TYPE_HOSTED_APP,
  ITEM_TYPE_PACKAGED_APP,
  ITEM_TYPE_LEGACY_PACKAGED_APP,
  ITEM_TYPE_EXTENSION,
  ITEM_TYPE_THEME,
  ITEM_TYPE_LAST = ITEM_TYPE_THEME,
};


const char* ToString(ItemType as_enum);
ItemType ParseItemType(const std::string& as_string);

struct ItemInspectView {
  ItemInspectView();
  ~ItemInspectView();
  ItemInspectView(ItemInspectView&& rhs);
  ItemInspectView& operator=(ItemInspectView&& rhs);

  // Populates a ItemInspectView object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ItemInspectView* out);

  // Creates a ItemInspectView object from a base::Value, or NULL on failure.
  static std::unique_ptr<ItemInspectView> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ItemInspectView object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // path to the inspect page.
  std::string path;

  // For lazy background pages, the value is -1.
  int render_process_id;

  // This actually refers to a render frame.
  int render_view_id;

  bool incognito;

  bool generated_background_page;


 private:
  DISALLOW_COPY_AND_ASSIGN(ItemInspectView);
};

struct InspectOptions {
  InspectOptions();
  ~InspectOptions();
  InspectOptions(InspectOptions&& rhs);
  InspectOptions& operator=(InspectOptions&& rhs);

  // Populates a InspectOptions object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, InspectOptions* out);

  // Creates a InspectOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<InspectOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this InspectOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  struct Render_process_id {
    Render_process_id();
    ~Render_process_id();
    Render_process_id(Render_process_id&& rhs);
    Render_process_id& operator=(Render_process_id&& rhs);

    // Populates a Render_process_id object from a base::Value. Returns whether
    // |out| was successfully populated.
    static bool Populate(const base::Value& value, Render_process_id* out);

    // Returns a new base::Value representing the serialized form of this
    // Render_process_id object.
    std::unique_ptr<base::Value> ToValue() const;
    // Choices:
    std::unique_ptr<std::string> as_string;
    std::unique_ptr<int> as_integer;

   private:
    DISALLOW_COPY_AND_ASSIGN(Render_process_id);
  };

  struct Render_view_id {
    Render_view_id();
    ~Render_view_id();
    Render_view_id(Render_view_id&& rhs);
    Render_view_id& operator=(Render_view_id&& rhs);

    // Populates a Render_view_id object from a base::Value. Returns whether |out|
    // was successfully populated.
    static bool Populate(const base::Value& value, Render_view_id* out);

    // Returns a new base::Value representing the serialized form of this
    // Render_view_id object.
    std::unique_ptr<base::Value> ToValue() const;
    // Choices:
    std::unique_ptr<std::string> as_string;
    std::unique_ptr<int> as_integer;

   private:
    DISALLOW_COPY_AND_ASSIGN(Render_view_id);
  };


  std::string extension_id;

  Render_process_id render_process_id;

  Render_view_id render_view_id;

  bool incognito;


 private:
  DISALLOW_COPY_AND_ASSIGN(InspectOptions);
};

struct InstallWarning {
  InstallWarning();
  ~InstallWarning();
  InstallWarning(InstallWarning&& rhs);
  InstallWarning& operator=(InstallWarning&& rhs);

  // Populates a InstallWarning object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, InstallWarning* out);

  // Creates a InstallWarning object from a base::Value, or NULL on failure.
  static std::unique_ptr<InstallWarning> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this InstallWarning object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string message;


 private:
  DISALLOW_COPY_AND_ASSIGN(InstallWarning);
};

enum ExtensionType {
  EXTENSION_TYPE_NONE,
  EXTENSION_TYPE_HOSTED_APP,
  EXTENSION_TYPE_PLATFORM_APP,
  EXTENSION_TYPE_LEGACY_PACKAGED_APP,
  EXTENSION_TYPE_EXTENSION,
  EXTENSION_TYPE_THEME,
  EXTENSION_TYPE_SHARED_MODULE,
  EXTENSION_TYPE_LAST = EXTENSION_TYPE_SHARED_MODULE,
};


const char* ToString(ExtensionType as_enum);
ExtensionType ParseExtensionType(const std::string& as_string);

enum Location {
  LOCATION_NONE,
  LOCATION_FROM_STORE,
  LOCATION_UNPACKED,
  LOCATION_THIRD_PARTY,
  LOCATION_UNKNOWN,
  LOCATION_LAST = LOCATION_UNKNOWN,
};


const char* ToString(Location as_enum);
Location ParseLocation(const std::string& as_string);

enum ViewType {
  VIEW_TYPE_NONE,
  VIEW_TYPE_APP_WINDOW,
  VIEW_TYPE_BACKGROUND_CONTENTS,
  VIEW_TYPE_COMPONENT,
  VIEW_TYPE_EXTENSION_BACKGROUND_PAGE,
  VIEW_TYPE_EXTENSION_DIALOG,
  VIEW_TYPE_EXTENSION_GUEST,
  VIEW_TYPE_EXTENSION_POPUP,
  VIEW_TYPE_TAB_CONTENTS,
  VIEW_TYPE_LAST = VIEW_TYPE_TAB_CONTENTS,
};


const char* ToString(ViewType as_enum);
ViewType ParseViewType(const std::string& as_string);

enum ErrorType {
  ERROR_TYPE_NONE,
  ERROR_TYPE_MANIFEST,
  ERROR_TYPE_RUNTIME,
  ERROR_TYPE_LAST = ERROR_TYPE_RUNTIME,
};


const char* ToString(ErrorType as_enum);
ErrorType ParseErrorType(const std::string& as_string);

enum ErrorLevel {
  ERROR_LEVEL_NONE,
  ERROR_LEVEL_LOG,
  ERROR_LEVEL_WARN,
  ERROR_LEVEL_ERROR,
  ERROR_LEVEL_LAST = ERROR_LEVEL_ERROR,
};


const char* ToString(ErrorLevel as_enum);
ErrorLevel ParseErrorLevel(const std::string& as_string);

enum ExtensionState {
  EXTENSION_STATE_NONE,
  EXTENSION_STATE_ENABLED,
  EXTENSION_STATE_DISABLED,
  EXTENSION_STATE_TERMINATED,
  EXTENSION_STATE_BLACKLISTED,
  EXTENSION_STATE_LAST = EXTENSION_STATE_BLACKLISTED,
};


const char* ToString(ExtensionState as_enum);
ExtensionState ParseExtensionState(const std::string& as_string);

enum CommandScope {
  COMMAND_SCOPE_NONE,
  COMMAND_SCOPE_GLOBAL,
  COMMAND_SCOPE_CHROME,
  COMMAND_SCOPE_LAST = COMMAND_SCOPE_CHROME,
};


const char* ToString(CommandScope as_enum);
CommandScope ParseCommandScope(const std::string& as_string);

struct AccessModifier {
  AccessModifier();
  ~AccessModifier();
  AccessModifier(AccessModifier&& rhs);
  AccessModifier& operator=(AccessModifier&& rhs);

  // Populates a AccessModifier object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, AccessModifier* out);

  // Creates a AccessModifier object from a base::Value, or NULL on failure.
  static std::unique_ptr<AccessModifier> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AccessModifier object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  bool is_enabled;

  bool is_active;


 private:
  DISALLOW_COPY_AND_ASSIGN(AccessModifier);
};

struct StackFrame {
  StackFrame();
  ~StackFrame();
  StackFrame(StackFrame&& rhs);
  StackFrame& operator=(StackFrame&& rhs);

  // Populates a StackFrame object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, StackFrame* out);

  // Creates a StackFrame object from a base::Value, or NULL on failure.
  static std::unique_ptr<StackFrame> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this StackFrame object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int line_number;

  int column_number;

  std::string url;

  std::string function_name;


 private:
  DISALLOW_COPY_AND_ASSIGN(StackFrame);
};

struct ManifestError {
  ManifestError();
  ~ManifestError();
  ManifestError(ManifestError&& rhs);
  ManifestError& operator=(ManifestError&& rhs);

  // Populates a ManifestError object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ManifestError* out);

  // Creates a ManifestError object from a base::Value, or NULL on failure.
  static std::unique_ptr<ManifestError> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManifestError object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ErrorType type;

  std::string extension_id;

  bool from_incognito;

  std::string source;

  std::string message;

  int id;

  std::string manifest_key;

  std::unique_ptr<std::string> manifest_specific;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManifestError);
};

struct RuntimeError {
  RuntimeError();
  ~RuntimeError();
  RuntimeError(RuntimeError&& rhs);
  RuntimeError& operator=(RuntimeError&& rhs);

  // Populates a RuntimeError object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, RuntimeError* out);

  // Creates a RuntimeError object from a base::Value, or NULL on failure.
  static std::unique_ptr<RuntimeError> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RuntimeError object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ErrorType type;

  std::string extension_id;

  bool from_incognito;

  std::string source;

  std::string message;

  int id;

  ErrorLevel severity;

  std::string context_url;

  int occurrences;

  int render_view_id;

  int render_process_id;

  bool can_inspect;

  std::vector<StackFrame> stack_trace;


 private:
  DISALLOW_COPY_AND_ASSIGN(RuntimeError);
};

struct DisableReasons {
  DisableReasons();
  ~DisableReasons();
  DisableReasons(DisableReasons&& rhs);
  DisableReasons& operator=(DisableReasons&& rhs);

  // Populates a DisableReasons object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DisableReasons* out);

  // Creates a DisableReasons object from a base::Value, or NULL on failure.
  static std::unique_ptr<DisableReasons> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DisableReasons object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  bool suspicious_install;

  bool corrupt_install;

  bool update_required;

  bool blocked_by_policy;

  bool custodian_approval_required;

  bool parent_disabled_permissions;


 private:
  DISALLOW_COPY_AND_ASSIGN(DisableReasons);
};

struct OptionsPage {
  OptionsPage();
  ~OptionsPage();
  OptionsPage(OptionsPage&& rhs);
  OptionsPage& operator=(OptionsPage&& rhs);

  // Populates a OptionsPage object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, OptionsPage* out);

  // Creates a OptionsPage object from a base::Value, or NULL on failure.
  static std::unique_ptr<OptionsPage> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this OptionsPage object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  bool open_in_tab;

  std::string url;


 private:
  DISALLOW_COPY_AND_ASSIGN(OptionsPage);
};

struct HomePage {
  HomePage();
  ~HomePage();
  HomePage(HomePage&& rhs);
  HomePage& operator=(HomePage&& rhs);

  // Populates a HomePage object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, HomePage* out);

  // Creates a HomePage object from a base::Value, or NULL on failure.
  static std::unique_ptr<HomePage> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this HomePage object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string url;

  bool specified;


 private:
  DISALLOW_COPY_AND_ASSIGN(HomePage);
};

struct ExtensionView {
  ExtensionView();
  ~ExtensionView();
  ExtensionView(ExtensionView&& rhs);
  ExtensionView& operator=(ExtensionView&& rhs);

  // Populates a ExtensionView object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ExtensionView* out);

  // Creates a ExtensionView object from a base::Value, or NULL on failure.
  static std::unique_ptr<ExtensionView> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ExtensionView object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string url;

  int render_process_id;

  // This actually refers to a render frame.
  int render_view_id;

  bool incognito;

  bool is_iframe;

  ViewType type;


 private:
  DISALLOW_COPY_AND_ASSIGN(ExtensionView);
};

enum ControllerType {
  CONTROLLER_TYPE_NONE,
  CONTROLLER_TYPE_POLICY,
  CONTROLLER_TYPE_LAST = CONTROLLER_TYPE_POLICY,
};


const char* ToString(ControllerType as_enum);
ControllerType ParseControllerType(const std::string& as_string);

enum HostAccess {
  HOST_ACCESS_NONE,
  HOST_ACCESS_ON_CLICK,
  HOST_ACCESS_ON_SPECIFIC_SITES,
  HOST_ACCESS_ON_ALL_SITES,
  HOST_ACCESS_LAST = HOST_ACCESS_ON_ALL_SITES,
};


const char* ToString(HostAccess as_enum);
HostAccess ParseHostAccess(const std::string& as_string);

struct ControlledInfo {
  ControlledInfo();
  ~ControlledInfo();
  ControlledInfo(ControlledInfo&& rhs);
  ControlledInfo& operator=(ControlledInfo&& rhs);

  // Populates a ControlledInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ControlledInfo* out);

  // Creates a ControlledInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ControlledInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ControlledInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ControllerType type;

  std::string text;


 private:
  DISALLOW_COPY_AND_ASSIGN(ControlledInfo);
};

struct Command {
  Command();
  ~Command();
  Command(Command&& rhs);
  Command& operator=(Command&& rhs);

  // Populates a Command object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Command* out);

  // Creates a Command object from a base::Value, or NULL on failure.
  static std::unique_ptr<Command> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Command object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string description;

  std::string keybinding;

  std::string name;

  bool is_active;

  CommandScope scope;

  bool is_extension_action;


 private:
  DISALLOW_COPY_AND_ASSIGN(Command);
};

struct DependentExtension {
  DependentExtension();
  ~DependentExtension();
  DependentExtension(DependentExtension&& rhs);
  DependentExtension& operator=(DependentExtension&& rhs);

  // Populates a DependentExtension object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, DependentExtension* out);

  // Creates a DependentExtension object from a base::Value, or NULL on failure.
  static std::unique_ptr<DependentExtension> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DependentExtension object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string id;

  std::string name;


 private:
  DISALLOW_COPY_AND_ASSIGN(DependentExtension);
};

struct Permission {
  Permission();
  ~Permission();
  Permission(Permission&& rhs);
  Permission& operator=(Permission&& rhs);

  // Populates a Permission object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Permission* out);

  // Creates a Permission object from a base::Value, or NULL on failure.
  static std::unique_ptr<Permission> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Permission object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string message;

  std::vector<std::string> submessages;


 private:
  DISALLOW_COPY_AND_ASSIGN(Permission);
};

struct SiteControl {
  SiteControl();
  ~SiteControl();
  SiteControl(SiteControl&& rhs);
  SiteControl& operator=(SiteControl&& rhs);

  // Populates a SiteControl object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, SiteControl* out);

  // Creates a SiteControl object from a base::Value, or NULL on failure.
  static std::unique_ptr<SiteControl> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SiteControl object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The host pattern for the site.
  std::string host;

  // Whether the pattern has been granted.
  bool granted;


 private:
  DISALLOW_COPY_AND_ASSIGN(SiteControl);
};

struct RuntimeHostPermissions {
  RuntimeHostPermissions();
  ~RuntimeHostPermissions();
  RuntimeHostPermissions(RuntimeHostPermissions&& rhs);
  RuntimeHostPermissions& operator=(RuntimeHostPermissions&& rhs);

  // Populates a RuntimeHostPermissions object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, RuntimeHostPermissions* out);

  // Creates a RuntimeHostPermissions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<RuntimeHostPermissions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RuntimeHostPermissions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // True if |hosts| contains an all hosts like pattern.
  bool has_all_hosts;

  // The current HostAccess setting for the extension.
  HostAccess host_access;

  // The site controls for all granted and requested patterns.
  std::vector<SiteControl> hosts;


 private:
  DISALLOW_COPY_AND_ASSIGN(RuntimeHostPermissions);
};

struct Permissions {
  Permissions();
  ~Permissions();
  Permissions(Permissions&& rhs);
  Permissions& operator=(Permissions&& rhs);

  // Populates a Permissions object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, Permissions* out);

  // Creates a Permissions object from a base::Value, or NULL on failure.
  static std::unique_ptr<Permissions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Permissions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::vector<Permission> simple_permissions;

  // Only populated for extensions that can be affected by the runtime host
  // permissions feature.
  std::unique_ptr<RuntimeHostPermissions> runtime_host_permissions;


 private:
  DISALLOW_COPY_AND_ASSIGN(Permissions);
};

struct ExtensionInfo {
  ExtensionInfo();
  ~ExtensionInfo();
  ExtensionInfo(ExtensionInfo&& rhs);
  ExtensionInfo& operator=(ExtensionInfo&& rhs);

  // Populates a ExtensionInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ExtensionInfo* out);

  // Creates a ExtensionInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ExtensionInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ExtensionInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::string> blacklist_text;

  std::vector<Command> commands;

  std::unique_ptr<ControlledInfo> controlled_info;

  std::vector<DependentExtension> dependent_extensions;

  std::string description;

  DisableReasons disable_reasons;

  AccessModifier error_collection;

  AccessModifier file_access;

  HomePage home_page;

  std::string icon_url;

  std::string id;

  AccessModifier incognito_access;

  std::vector<std::string> install_warnings;

  std::unique_ptr<std::string> launch_url;

  Location location;

  std::unique_ptr<std::string> location_text;

  std::vector<ManifestError> manifest_errors;

  std::string manifest_home_page_url;

  bool must_remain_installed;

  std::string name;

  bool offline_enabled;

  std::unique_ptr<OptionsPage> options_page;

  std::unique_ptr<std::string> path;

  Permissions permissions;

  std::unique_ptr<std::string> prettified_path;

  std::vector<RuntimeError> runtime_errors;

  std::vector<std::string> runtime_warnings;

  ExtensionState state;

  ExtensionType type;

  std::string update_url;

  bool user_may_modify;

  std::string version;

  std::vector<ExtensionView> views;

  std::string web_store_url;


 private:
  DISALLOW_COPY_AND_ASSIGN(ExtensionInfo);
};

struct ProfileInfo {
  ProfileInfo();
  ~ProfileInfo();
  ProfileInfo(ProfileInfo&& rhs);
  ProfileInfo& operator=(ProfileInfo&& rhs);

  // Populates a ProfileInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ProfileInfo* out);

  // Creates a ProfileInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ProfileInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ProfileInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  bool can_load_unpacked;

  bool in_developer_mode;

  bool is_developer_mode_controlled_by_policy;

  bool is_incognito_available;

  bool is_supervised;


 private:
  DISALLOW_COPY_AND_ASSIGN(ProfileInfo);
};

struct ItemInfo {
  ItemInfo();
  ~ItemInfo();
  ItemInfo(ItemInfo&& rhs);
  ItemInfo& operator=(ItemInfo&& rhs);

  // Populates a ItemInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, ItemInfo* out);

  // Creates a ItemInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ItemInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ItemInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string id;

  std::string name;

  std::string version;

  std::string description;

  bool may_disable;

  bool enabled;

  bool is_app;

  ItemType type;

  bool allow_activity;

  bool allow_file_access;

  bool wants_file_access;

  bool incognito_enabled;

  bool is_unpacked;

  bool allow_reload;

  bool terminated;

  bool allow_incognito;

  std::string icon_url;

  // Path of an unpacked extension.
  std::unique_ptr<std::string> path;

  // Options settings page for the item.
  std::unique_ptr<std::string> options_url;

  std::unique_ptr<std::string> app_launch_url;

  std::unique_ptr<std::string> homepage_url;

  std::unique_ptr<std::string> update_url;

  std::vector<InstallWarning> install_warnings;

  std::vector<std::unique_ptr<base::Value>> manifest_errors;

  std::vector<std::unique_ptr<base::Value>> runtime_errors;

  bool offline_enabled;

  // All views of the current extension.
  std::vector<ItemInspectView> views;


 private:
  DISALLOW_COPY_AND_ASSIGN(ItemInfo);
};

struct GetExtensionsInfoOptions {
  GetExtensionsInfoOptions();
  ~GetExtensionsInfoOptions();
  GetExtensionsInfoOptions(GetExtensionsInfoOptions&& rhs);
  GetExtensionsInfoOptions& operator=(GetExtensionsInfoOptions&& rhs);

  // Populates a GetExtensionsInfoOptions object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, GetExtensionsInfoOptions* out);

  // Creates a GetExtensionsInfoOptions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<GetExtensionsInfoOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this GetExtensionsInfoOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<bool> include_disabled;

  std::unique_ptr<bool> include_terminated;


 private:
  DISALLOW_COPY_AND_ASSIGN(GetExtensionsInfoOptions);
};

struct ExtensionConfigurationUpdate {
  ExtensionConfigurationUpdate();
  ~ExtensionConfigurationUpdate();
  ExtensionConfigurationUpdate(ExtensionConfigurationUpdate&& rhs);
  ExtensionConfigurationUpdate& operator=(ExtensionConfigurationUpdate&& rhs);

  // Populates a ExtensionConfigurationUpdate object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ExtensionConfigurationUpdate* out);

  // Creates a ExtensionConfigurationUpdate object from a base::Value, or NULL
  // on failure.
  static std::unique_ptr<ExtensionConfigurationUpdate> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ExtensionConfigurationUpdate object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string extension_id;

  std::unique_ptr<bool> file_access;

  std::unique_ptr<bool> incognito_access;

  std::unique_ptr<bool> error_collection;

  HostAccess host_access;


 private:
  DISALLOW_COPY_AND_ASSIGN(ExtensionConfigurationUpdate);
};

struct ProfileConfigurationUpdate {
  ProfileConfigurationUpdate();
  ~ProfileConfigurationUpdate();
  ProfileConfigurationUpdate(ProfileConfigurationUpdate&& rhs);
  ProfileConfigurationUpdate& operator=(ProfileConfigurationUpdate&& rhs);

  // Populates a ProfileConfigurationUpdate object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ProfileConfigurationUpdate* out);

  // Creates a ProfileConfigurationUpdate object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ProfileConfigurationUpdate> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ProfileConfigurationUpdate object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<bool> in_developer_mode;


 private:
  DISALLOW_COPY_AND_ASSIGN(ProfileConfigurationUpdate);
};

struct ExtensionCommandUpdate {
  ExtensionCommandUpdate();
  ~ExtensionCommandUpdate();
  ExtensionCommandUpdate(ExtensionCommandUpdate&& rhs);
  ExtensionCommandUpdate& operator=(ExtensionCommandUpdate&& rhs);

  // Populates a ExtensionCommandUpdate object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ExtensionCommandUpdate* out);

  // Creates a ExtensionCommandUpdate object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ExtensionCommandUpdate> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ExtensionCommandUpdate object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string extension_id;

  std::string command_name;

  CommandScope scope;

  std::unique_ptr<std::string> keybinding;


 private:
  DISALLOW_COPY_AND_ASSIGN(ExtensionCommandUpdate);
};

struct ReloadOptions {
  ReloadOptions();
  ~ReloadOptions();
  ReloadOptions(ReloadOptions&& rhs);
  ReloadOptions& operator=(ReloadOptions&& rhs);

  // Populates a ReloadOptions object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ReloadOptions* out);

  // Creates a ReloadOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<ReloadOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ReloadOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // If false, an alert dialog will show in the event of a reload error. Defaults
  // to false.
  std::unique_ptr<bool> fail_quietly;

  // If true, populates a LoadError for the response rather than setting
  // lastError. Only relevant for unpacked extensions; it will be ignored for any
  // other extension.
  std::unique_ptr<bool> populate_error_for_unpacked;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReloadOptions);
};

struct LoadUnpackedOptions {
  LoadUnpackedOptions();
  ~LoadUnpackedOptions();
  LoadUnpackedOptions(LoadUnpackedOptions&& rhs);
  LoadUnpackedOptions& operator=(LoadUnpackedOptions&& rhs);

  // Populates a LoadUnpackedOptions object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, LoadUnpackedOptions* out);

  // Creates a LoadUnpackedOptions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<LoadUnpackedOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this LoadUnpackedOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // If false, an alert dialog will show in the event of a reload error. Defaults
  // to false.
  std::unique_ptr<bool> fail_quietly;

  // If true, populates a LoadError for the response rather than setting
  // lastError.
  std::unique_ptr<bool> populate_error;

  // A unique identifier for retrying a previous failed load. This should be the
  // identifier returned in the LoadError. If specified, the path associated with
  // the identifier will be loaded, and the file chooser will be skipped.
  std::unique_ptr<std::string> retry_guid;

  // True if the function should try to load an extension from the drop data of
  // the page. notifyDragInstallInProgress() needs to be called prior to this
  // being used. This cannot be used with |retryGuid|.
  std::unique_ptr<bool> use_dragged_path;


 private:
  DISALLOW_COPY_AND_ASSIGN(LoadUnpackedOptions);
};

enum PackStatus {
  PACK_STATUS_NONE,
  PACK_STATUS_SUCCESS,
  PACK_STATUS_ERROR,
  PACK_STATUS_WARNING,
  PACK_STATUS_LAST = PACK_STATUS_WARNING,
};


const char* ToString(PackStatus as_enum);
PackStatus ParsePackStatus(const std::string& as_string);

enum FileType {
  FILE_TYPE_NONE,
  FILE_TYPE_LOAD,
  FILE_TYPE_PEM,
  FILE_TYPE_LAST = FILE_TYPE_PEM,
};


const char* ToString(FileType as_enum);
FileType ParseFileType(const std::string& as_string);

enum SelectType {
  SELECT_TYPE_NONE,
  SELECT_TYPE_FILE,
  SELECT_TYPE_FOLDER,
  SELECT_TYPE_LAST = SELECT_TYPE_FOLDER,
};


const char* ToString(SelectType as_enum);
SelectType ParseSelectType(const std::string& as_string);

enum EventType {
  EVENT_TYPE_NONE,
  EVENT_TYPE_INSTALLED,
  EVENT_TYPE_UNINSTALLED,
  EVENT_TYPE_LOADED,
  EVENT_TYPE_UNLOADED,
  EVENT_TYPE_VIEW_REGISTERED,
  EVENT_TYPE_VIEW_UNREGISTERED,
  EVENT_TYPE_ERROR_ADDED,
  EVENT_TYPE_ERRORS_REMOVED,
  EVENT_TYPE_PREFS_CHANGED,
  EVENT_TYPE_WARNINGS_CHANGED,
  EVENT_TYPE_COMMAND_ADDED,
  EVENT_TYPE_COMMAND_REMOVED,
  EVENT_TYPE_PERMISSIONS_CHANGED,
  EVENT_TYPE_LAST = EVENT_TYPE_PERMISSIONS_CHANGED,
};


const char* ToString(EventType as_enum);
EventType ParseEventType(const std::string& as_string);

struct PackDirectoryResponse {
  PackDirectoryResponse();
  ~PackDirectoryResponse();
  PackDirectoryResponse(PackDirectoryResponse&& rhs);
  PackDirectoryResponse& operator=(PackDirectoryResponse&& rhs);

  // Populates a PackDirectoryResponse object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, PackDirectoryResponse* out);

  // Creates a PackDirectoryResponse object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<PackDirectoryResponse> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PackDirectoryResponse object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The response message of success or error.
  std::string message;

  // Unpacked items's path.
  std::string item_path;

  // Permanent key path.
  std::string pem_path;

  int override_flags;

  PackStatus status;


 private:
  DISALLOW_COPY_AND_ASSIGN(PackDirectoryResponse);
};

struct ProjectInfo {
  ProjectInfo();
  ~ProjectInfo();
  ProjectInfo(ProjectInfo&& rhs);
  ProjectInfo& operator=(ProjectInfo&& rhs);

  // Populates a ProjectInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ProjectInfo* out);

  // Creates a ProjectInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ProjectInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ProjectInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string name;


 private:
  DISALLOW_COPY_AND_ASSIGN(ProjectInfo);
};

struct EventData {
  EventData();
  ~EventData();
  EventData(EventData&& rhs);
  EventData& operator=(EventData&& rhs);

  // Populates a EventData object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, EventData* out);

  // Creates a EventData object from a base::Value, or NULL on failure.
  static std::unique_ptr<EventData> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this EventData object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  EventType event_type;

  std::string item_id;

  std::unique_ptr<ExtensionInfo> extension_info;


 private:
  DISALLOW_COPY_AND_ASSIGN(EventData);
};

struct ErrorFileSource {
  ErrorFileSource();
  ~ErrorFileSource();
  ErrorFileSource(ErrorFileSource&& rhs);
  ErrorFileSource& operator=(ErrorFileSource&& rhs);

  // Populates a ErrorFileSource object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ErrorFileSource* out);

  // Creates a ErrorFileSource object from a base::Value, or NULL on failure.
  static std::unique_ptr<ErrorFileSource> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ErrorFileSource object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The region before the "highlight" portion. If the region which threw the
  // error was not found, the full contents of the file will be in the
  // "beforeHighlight" section.
  std::string before_highlight;

  // The region of the code which threw the error, and should be highlighted.
  std::string highlight;

  // The region after the "highlight" portion.
  std::string after_highlight;


 private:
  DISALLOW_COPY_AND_ASSIGN(ErrorFileSource);
};

struct LoadError {
  LoadError();
  ~LoadError();
  LoadError(LoadError&& rhs);
  LoadError& operator=(LoadError&& rhs);

  // Populates a LoadError object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, LoadError* out);

  // Creates a LoadError object from a base::Value, or NULL on failure.
  static std::unique_ptr<LoadError> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this LoadError object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The error that occurred when trying to load the extension.
  std::string error;

  // The path to the extension.
  std::string path;

  // The file source for the error, if it could be retrieved.
  std::unique_ptr<ErrorFileSource> source;

  // A unique identifier to pass to developerPrivate.loadUnpacked to retry loading
  // the extension at the same path.
  std::string retry_guid;


 private:
  DISALLOW_COPY_AND_ASSIGN(LoadError);
};

struct RequestFileSourceProperties {
  RequestFileSourceProperties();
  ~RequestFileSourceProperties();
  RequestFileSourceProperties(RequestFileSourceProperties&& rhs);
  RequestFileSourceProperties& operator=(RequestFileSourceProperties&& rhs);

  // Populates a RequestFileSourceProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, RequestFileSourceProperties* out);

  // Creates a RequestFileSourceProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<RequestFileSourceProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RequestFileSourceProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the extension owning the file.
  std::string extension_id;

  // The path of the file, relative to the extension; e.g., manifest.json,
  // script.js, or main.html.
  std::string path_suffix;

  // The error message which was thrown as a result of the error in the file.
  std::string message;

  // The key in the manifest which caused the error (e.g., "permissions").
  // (Required for "manifest.json" files)
  std::unique_ptr<std::string> manifest_key;

  // The specific portion of the manifest key which caused the error (e.g., "foo"
  // in the "permissions" key). (Optional for "manifest.json" file).
  std::unique_ptr<std::string> manifest_specific;

  // The line number which caused the error (optional for non-manifest files).
  std::unique_ptr<int> line_number;


 private:
  DISALLOW_COPY_AND_ASSIGN(RequestFileSourceProperties);
};

struct RequestFileSourceResponse {
  RequestFileSourceResponse();
  ~RequestFileSourceResponse();
  RequestFileSourceResponse(RequestFileSourceResponse&& rhs);
  RequestFileSourceResponse& operator=(RequestFileSourceResponse&& rhs);

  // Populates a RequestFileSourceResponse object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, RequestFileSourceResponse* out);

  // Creates a RequestFileSourceResponse object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<RequestFileSourceResponse> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RequestFileSourceResponse object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The region of the code which threw the error, and should be highlighted.
  std::string highlight;

  // The region before the "highlight" portion. If the region which threw the
  // error was not found, the full contents of the file will be in the
  // "beforeHighlight" section.
  std::string before_highlight;

  // The region after the "highlight" portion.
  std::string after_highlight;

  // A title for the file in the form '<extension name>: <file name>'.
  std::string title;

  // The error message.
  std::string message;


 private:
  DISALLOW_COPY_AND_ASSIGN(RequestFileSourceResponse);
};

struct OpenDevToolsProperties {
  OpenDevToolsProperties();
  ~OpenDevToolsProperties();
  OpenDevToolsProperties(OpenDevToolsProperties&& rhs);
  OpenDevToolsProperties& operator=(OpenDevToolsProperties&& rhs);

  // Populates a OpenDevToolsProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, OpenDevToolsProperties* out);

  // Creates a OpenDevToolsProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<OpenDevToolsProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this OpenDevToolsProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the extension. This is only needed if opening the background page
  // (where renderViewId and renderProcessId are -1).
  std::unique_ptr<std::string> extension_id;

  // The ID of the render frame in which the error occurred. Despite being called
  // renderViewId, this refers to a render frame.
  int render_view_id;

  // The ID of the process in which the error occurred.
  int render_process_id;

  std::unique_ptr<bool> incognito;

  // The URL in which the error occurred.
  std::unique_ptr<std::string> url;

  // The line to focus the devtools at.
  std::unique_ptr<int> line_number;

  // The column to focus the devtools at.
  std::unique_ptr<int> column_number;


 private:
  DISALLOW_COPY_AND_ASSIGN(OpenDevToolsProperties);
};

struct DeleteExtensionErrorsProperties {
  DeleteExtensionErrorsProperties();
  ~DeleteExtensionErrorsProperties();
  DeleteExtensionErrorsProperties(DeleteExtensionErrorsProperties&& rhs);
  DeleteExtensionErrorsProperties& operator=(DeleteExtensionErrorsProperties&& rhs);

  // Populates a DeleteExtensionErrorsProperties object from a base::Value.
  // Returns whether |out| was successfully populated.
  static bool Populate(const base::Value& value, DeleteExtensionErrorsProperties* out);

  // Creates a DeleteExtensionErrorsProperties object from a base::Value, or
  // NULL on failure.
  static std::unique_ptr<DeleteExtensionErrorsProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DeleteExtensionErrorsProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string extension_id;

  std::unique_ptr<std::vector<int>> error_ids;

  ErrorType type;


 private:
  DISALLOW_COPY_AND_ASSIGN(DeleteExtensionErrorsProperties);
};


//
// Functions
//

namespace AutoUpdate {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace AutoUpdate

namespace GetExtensionsInfo {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Options to restrict the items returned.
  std::unique_ptr<GetExtensionsInfoOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<ExtensionInfo>& result);
}  // namespace Results

}  // namespace GetExtensionsInfo

namespace GetExtensionInfo {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension.
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ExtensionInfo& result);
}  // namespace Results

}  // namespace GetExtensionInfo

namespace GetExtensionSize {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension.
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& string);
}  // namespace Results

}  // namespace GetExtensionSize

namespace GetItemsInfo {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // include disabled items.
  bool include_disabled;

  // include terminated items.
  bool include_terminated;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<ItemInfo>& result);
}  // namespace Results

}  // namespace GetItemsInfo

namespace GetProfileConfiguration {

namespace Results {

std::unique_ptr<base::ListValue> Create(const ProfileInfo& info);
}  // namespace Results

}  // namespace GetProfileConfiguration

namespace UpdateProfileConfiguration {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The parameters for updating the profile's configuration.  Any     properties
  // omitted from |update| will not be changed.
  ProfileConfigurationUpdate update;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace UpdateProfileConfiguration

namespace ShowPermissionsDialog {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension to show permissions for.
  std::string extension_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ShowPermissionsDialog

namespace Reload {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension to reload.
  std::string extension_id;

  // Additional configuration parameters.
  std::unique_ptr<ReloadOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const LoadError& error);
}  // namespace Results

}  // namespace Reload

namespace UpdateExtensionConfiguration {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The parameters for updating the extension's configuration.     Any properties
  // omitted from |update| will not be changed.
  ExtensionConfigurationUpdate update;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace UpdateExtensionConfiguration

namespace LoadUnpacked {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Additional configuration parameters.
  std::unique_ptr<LoadUnpackedOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const LoadError& error);
}  // namespace Results

}  // namespace LoadUnpacked

namespace InstallDroppedFile {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace InstallDroppedFile

namespace NotifyDragInstallInProgress {

}  // namespace NotifyDragInstallInProgress

namespace LoadDirectory {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The directory to load the extension from.
  struct Directory {
    Directory();
    ~Directory();
    Directory(Directory&& rhs);
    Directory& operator=(Directory&& rhs);

    // Populates a Directory object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Directory* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Directory);
  };


  // The directory to load the extension from.
  Directory directory;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& string);
}  // namespace Results

}  // namespace LoadDirectory

namespace ChoosePath {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Select a file or a folder.
  SelectType select_type;

  // Required file type. For example, pem type is for private key and load type is
  // for an unpacked item.
  FileType file_type;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& string);
}  // namespace Results

}  // namespace ChoosePath

namespace PackDirectory {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string path;

  // The path of the private key, if one is given.
  std::unique_ptr<std::string> private_key_path;

  // Special flags to apply to the loading process, if any.
  std::unique_ptr<int> flags;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const PackDirectoryResponse& response);
}  // namespace Results

}  // namespace PackDirectory

namespace IsProfileManaged {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace IsProfileManaged

namespace RequestFileSource {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestFileSourceProperties properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const RequestFileSourceResponse& response);
}  // namespace Results

}  // namespace RequestFileSource

namespace OpenDevTools {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  OpenDevToolsProperties properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace OpenDevTools

namespace DeleteExtensionErrors {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The properties specifying the errors to remove.
  DeleteExtensionErrorsProperties properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DeleteExtensionErrors

namespace RepairExtension {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension to repair.
  std::string extension_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RepairExtension

namespace ShowOptions {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension to show the options page for.
  std::string extension_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ShowOptions

namespace ShowPath {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension to show the path for.
  std::string extension_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ShowPath

namespace SetShortcutHandlingSuspended {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Whether or not shortcut handling should be suspended.
  bool is_suspended;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetShortcutHandlingSuspended

namespace UpdateExtensionCommand {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The parameters for updating the extension command.
  ExtensionCommandUpdate update;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace UpdateExtensionCommand

namespace AddHostPermission {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension to modify.
  std::string extension_id;

  // The host to add.
  std::string host;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace AddHostPermission

namespace RemoveHostPermission {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension to modify.
  std::string extension_id;

  // The host to remove.
  std::string host;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RemoveHostPermission

//
// Events
//

namespace OnItemStateChanged {

extern const char kEventName[];  // "developerPrivate.onItemStateChanged"

std::unique_ptr<base::ListValue> Create(const EventData& response);
}  // namespace OnItemStateChanged

namespace OnProfileStateChanged {

extern const char kEventName[];  // "developerPrivate.onProfileStateChanged"

std::unique_ptr<base::ListValue> Create(const ProfileInfo& info);
}  // namespace OnProfileStateChanged

}  // namespace developer_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_DEVELOPER_PRIVATE_H__
