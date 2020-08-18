// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/chrome_web_view_internal.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_CHROME_WEB_VIEW_INTERNAL_H__
#define CHROME_COMMON_EXTENSIONS_API_CHROME_WEB_VIEW_INTERNAL_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"
#include "chrome/common/extensions/api/context_menus.h"
#include "chrome/common/extensions/api/context_menus.h"
#include "chrome/common/extensions/api/context_menus.h"
#include "chrome/common/extensions/api/context_menus.h"


namespace extensions {
namespace api {
namespace chrome_web_view_internal {

//
// Types
//

// An item in the context menu.
struct ContextMenuItem {
  ContextMenuItem();
  ~ContextMenuItem();
  ContextMenuItem(ContextMenuItem&& rhs);
  ContextMenuItem& operator=(ContextMenuItem&& rhs);

  // Populates a ContextMenuItem object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ContextMenuItem* out);

  // Creates a ContextMenuItem object from a base::Value, or NULL on failure.
  static std::unique_ptr<ContextMenuItem> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ContextMenuItem object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // label of the item
  std::unique_ptr<std::string> label;

  // id of the input item
  int command_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(ContextMenuItem);
};


//
// Functions
//

namespace ContextMenusCreate {

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

    // The ID of a parent menu item; this makes the item a child of a previously
    // added item.
    struct ParentId {
      ParentId();
      ~ParentId();
      ParentId(ParentId&& rhs);
      ParentId& operator=(ParentId&& rhs);

      // Populates a ParentId object from a base::Value. Returns whether |out| was
      // successfully populated.
      static bool Populate(const base::Value& value, ParentId* out);
      // Choices:
      std::unique_ptr<int> as_integer;
      std::unique_ptr<std::string> as_string;

     private:
      DISALLOW_COPY_AND_ASSIGN(ParentId);
    };


    // The type of menu item. Defaults to 'normal' if not specified.
    extensions::api::context_menus::ItemType type;

    // The unique ID to assign to this item. Cannot be the same as another ID for
    // this webview.
    std::unique_ptr<std::string> id;

    // The text to be displayed in the item; this is <em>required</em> unless
    // <em>type</em> is 'separator'. When the context is 'selection', you can use
    // <code>%s</code> within the string to show the selected text. For example, if
    // this parameter's value is "Translate '%s' to Pig Latin" and the user selects
    // the word "cool", the context menu item for the selection is "Translate 'cool'
    // to Pig Latin".
    std::unique_ptr<std::string> title;

    // The initial state of a checkbox or radio item: true for selected and false
    // for unselected. Only one radio item can be selected at a time in a given
    // group of radio items.
    std::unique_ptr<bool> checked;

    // List of contexts this menu item will appear in. Defaults to ['page'] if not
    // specified.
    std::unique_ptr<std::vector<extensions::api::context_menus::ContextType>> contexts;

    // Whether the item is visible in the menu.
    std::unique_ptr<bool> visible;

    // A function that will be called back when the menu item is clicked.
    std::unique_ptr<base::DictionaryValue> onclick;

    // The ID of a parent menu item; this makes the item a child of a previously
    // added item.
    std::unique_ptr<ParentId> parent_id;

    // Lets you restrict the item to apply only to documents whose URL matches one
    // of the given patterns. (This applies to frames as well.) For details on the
    // format of a pattern, see <a href='match_patterns'>Match Patterns</a>.
    std::unique_ptr<std::vector<std::string>> document_url_patterns;

    // Similar to documentUrlPatterns, but lets you filter based on the src
    // attribute of img/audio/video tags and the href of anchor tags.
    std::unique_ptr<std::vector<std::string>> target_url_patterns;

    // Whether this context menu item is enabled or disabled. Defaults to true.
    std::unique_ptr<bool> enabled;


   private:
    DISALLOW_COPY_AND_ASSIGN(CreateProperties);
  };


  int instance_id;

  CreateProperties create_properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ContextMenusCreate

namespace ContextMenusUpdate {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the item to update.
  struct Id {
    Id();
    ~Id();
    Id(Id&& rhs);
    Id& operator=(Id&& rhs);

    // Populates a Id object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Id* out);
    // Choices:
    std::unique_ptr<int> as_integer;
    std::unique_ptr<std::string> as_string;

   private:
    DISALLOW_COPY_AND_ASSIGN(Id);
  };

  // The properties to update. Accepts the same values as the create function.
  struct UpdateProperties {
    UpdateProperties();
    ~UpdateProperties();
    UpdateProperties(UpdateProperties&& rhs);
    UpdateProperties& operator=(UpdateProperties&& rhs);

    // Populates a UpdateProperties object from a base::Value. Returns whether
    // |out| was successfully populated.
    static bool Populate(const base::Value& value, UpdateProperties* out);

    // Note: You cannot change an item to be a child of one of its own descendants.
    struct ParentId {
      ParentId();
      ~ParentId();
      ParentId(ParentId&& rhs);
      ParentId& operator=(ParentId&& rhs);

      // Populates a ParentId object from a base::Value. Returns whether |out| was
      // successfully populated.
      static bool Populate(const base::Value& value, ParentId* out);
      // Choices:
      std::unique_ptr<int> as_integer;
      std::unique_ptr<std::string> as_string;

     private:
      DISALLOW_COPY_AND_ASSIGN(ParentId);
    };


    extensions::api::context_menus::ItemType type;

    std::unique_ptr<std::string> title;

    std::unique_ptr<bool> checked;

    // List of contexts this menu item will appear in. Defaults to ['page'] if not
    // specified.
    std::unique_ptr<std::vector<extensions::api::context_menus::ContextType>> contexts;

    // Whether the item is visible in the menu.
    std::unique_ptr<bool> visible;

    std::unique_ptr<base::DictionaryValue> onclick;

    // Note: You cannot change an item to be a child of one of its own descendants.
    std::unique_ptr<ParentId> parent_id;

    std::unique_ptr<std::vector<std::string>> document_url_patterns;

    std::unique_ptr<std::vector<std::string>> target_url_patterns;

    std::unique_ptr<bool> enabled;


   private:
    DISALLOW_COPY_AND_ASSIGN(UpdateProperties);
  };


  int instance_id;

  // The ID of the item to update.
  Id id;

  // The properties to update. Accepts the same values as the create function.
  UpdateProperties update_properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ContextMenusUpdate

namespace ContextMenusRemove {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the context menu item to remove.
  struct MenuItemId {
    MenuItemId();
    ~MenuItemId();
    MenuItemId(MenuItemId&& rhs);
    MenuItemId& operator=(MenuItemId&& rhs);

    // Populates a MenuItemId object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, MenuItemId* out);
    // Choices:
    std::unique_ptr<int> as_integer;
    std::unique_ptr<std::string> as_string;

   private:
    DISALLOW_COPY_AND_ASSIGN(MenuItemId);
  };


  int instance_id;

  // The ID of the context menu item to remove.
  MenuItemId menu_item_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ContextMenusRemove

namespace ContextMenusRemoveAll {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ContextMenusRemoveAll

namespace ShowContextMenu {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest &lt;webview&gt; process. This not exposed to
  // developers through the API.
  int instance_id;

  // The strictly increasing request counter that serves as ID for the context
  // menu. This not exposed to developers through the API.
  int request_id;

  // Items to be shown in the context menu. These are top level items as opposed
  // to children items.
  std::unique_ptr<std::vector<ContextMenuItem>> items_to_show;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace ShowContextMenu

//
// Events
//

namespace OnClicked {

extern const char kEventName[];  // "chromeWebViewInternal.onClicked"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnClicked

namespace OnShow {

extern const char kEventName[];  // "chromeWebViewInternal.onShow"

struct Event {
  Event();
  ~Event();
  Event(Event&& rhs);
  Event& operator=(Event&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Event object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue prevent_default;


 private:
  DISALLOW_COPY_AND_ASSIGN(Event);
};


std::unique_ptr<base::ListValue> Create(const Event& event);
}  // namespace OnShow

}  // namespace chrome_web_view_internal
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_CHROME_WEB_VIEW_INTERNAL_H__
