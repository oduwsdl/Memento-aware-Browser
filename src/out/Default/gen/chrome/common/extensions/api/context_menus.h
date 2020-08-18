// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/context_menus.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_CONTEXT_MENUS_H__
#define CHROME_COMMON_EXTENSIONS_API_CONTEXT_MENUS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace context_menus {

//
// Properties
//

// The maximum number of top level extension items that can be added to an
// extension action context menu. Any items beyond this limit will be ignored.
extern const int ACTION_MENU_TOP_LEVEL_LIMIT;

//
// Types
//

// The different contexts a menu can appear in. Specifying 'all' is equivalent
// to the combination of all other contexts except for 'launcher'. The
// 'launcher' context is only supported by apps and is used to add menu items to
// the context menu that appears when clicking the app icon in the
// launcher/taskbar/dock/etc. Different platforms might put limitations on what
// is actually supported in a launcher context menu.
enum ContextType {
  CONTEXT_TYPE_NONE,
  CONTEXT_TYPE_ALL,
  CONTEXT_TYPE_PAGE,
  CONTEXT_TYPE_FRAME,
  CONTEXT_TYPE_SELECTION,
  CONTEXT_TYPE_LINK,
  CONTEXT_TYPE_EDITABLE,
  CONTEXT_TYPE_IMAGE,
  CONTEXT_TYPE_VIDEO,
  CONTEXT_TYPE_AUDIO,
  CONTEXT_TYPE_LAUNCHER,
  CONTEXT_TYPE_BROWSER_ACTION,
  CONTEXT_TYPE_PAGE_ACTION,
  CONTEXT_TYPE_LAST = CONTEXT_TYPE_PAGE_ACTION,
};


const char* ToString(ContextType as_enum);
ContextType ParseContextType(const std::string& as_string);

// The type of menu item.
enum ItemType {
  ITEM_TYPE_NONE,
  ITEM_TYPE_NORMAL,
  ITEM_TYPE_CHECKBOX,
  ITEM_TYPE_RADIO,
  ITEM_TYPE_SEPARATOR,
  ITEM_TYPE_LAST = ITEM_TYPE_SEPARATOR,
};


const char* ToString(ItemType as_enum);
ItemType ParseItemType(const std::string& as_string);


//
// Functions
//

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


    // The type of menu item. Defaults to <code>normal</code>.
    ItemType type;

    // The unique ID to assign to this item. Mandatory for event pages. Cannot be
    // the same as another ID for this extension.
    std::unique_ptr<std::string> id;

    // The text to display in the item; this is <em>required</em> unless
    // <code>type</code> is <code>separator</code>. When the context is
    // <code>selection</code>, use <code>%s</code> within the string to show the
    // selected text. For example, if this parameter's value is "Translate '%s' to
    // Pig Latin" and the user selects the word "cool", the context menu item for
    // the selection is "Translate 'cool' to Pig Latin".
    std::unique_ptr<std::string> title;

    // The initial state of a checkbox or radio button: <code>true</code> for
    // selected, <code>false</code> for unselected. Only one radio button can be
    // selected at a time in a given group.
    std::unique_ptr<bool> checked;

    // List of contexts this menu item will appear in. Defaults to
    // <code>['page']</code>.
    std::unique_ptr<std::vector<ContextType>> contexts;

    // Whether the item is visible in the menu.
    std::unique_ptr<bool> visible;

    // A function that is called back when the menu item is clicked. Event pages
    // cannot use this; instead, they should register a listener for
    // $(ref:contextMenus.onClicked).
    std::unique_ptr<base::DictionaryValue> onclick;

    // The ID of a parent menu item; this makes the item a child of a previously
    // added item.
    std::unique_ptr<ParentId> parent_id;

    // Restricts the item to apply only to documents or frames whose URL matches one
    // of the given patterns. For details on pattern formats, see <a
    // href='match_patterns'>Match Patterns</a>.
    std::unique_ptr<std::vector<std::string>> document_url_patterns;

    // Similar to <code>documentUrlPatterns</code>, filters based on the
    // <code>src</code> attribute of <code>img</code>, <code>audio</code>, and
    // <code>video</code> tags and the <code>href</code> attribute of <code>a</code>
    // tags.
    std::unique_ptr<std::vector<std::string>> target_url_patterns;

    // Whether this context menu item is enabled or disabled. Defaults to
    // <code>true</code>.
    std::unique_ptr<bool> enabled;


   private:
    DISALLOW_COPY_AND_ASSIGN(CreateProperties);
  };


  CreateProperties create_properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Create

namespace Update {

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

  // The properties to update. Accepts the same values as the
  // $(ref:contextMenus.create) function.
  struct UpdateProperties {
    UpdateProperties();
    ~UpdateProperties();
    UpdateProperties(UpdateProperties&& rhs);
    UpdateProperties& operator=(UpdateProperties&& rhs);

    // Populates a UpdateProperties object from a base::Value. Returns whether
    // |out| was successfully populated.
    static bool Populate(const base::Value& value, UpdateProperties* out);

    // The ID of the item to be made this item's parent. Note: You cannot set an
    // item to become a child of its own descendant.
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


    ItemType type;

    std::unique_ptr<std::string> title;

    std::unique_ptr<bool> checked;

    std::unique_ptr<std::vector<ContextType>> contexts;

    // Whether the item is visible in the menu.
    std::unique_ptr<bool> visible;

    std::unique_ptr<base::DictionaryValue> onclick;

    // The ID of the item to be made this item's parent. Note: You cannot set an
    // item to become a child of its own descendant.
    std::unique_ptr<ParentId> parent_id;

    std::unique_ptr<std::vector<std::string>> document_url_patterns;

    std::unique_ptr<std::vector<std::string>> target_url_patterns;

    std::unique_ptr<bool> enabled;


   private:
    DISALLOW_COPY_AND_ASSIGN(UpdateProperties);
  };


  // The ID of the item to update.
  Id id;

  // The properties to update. Accepts the same values as the
  // $(ref:contextMenus.create) function.
  UpdateProperties update_properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Update

namespace Remove {

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


  // The ID of the context menu item to remove.
  MenuItemId menu_item_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Remove

namespace RemoveAll {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RemoveAll

//
// Events
//

namespace OnClicked {

extern const char kEventName[];  // "contextMenus.onClicked"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnClicked

}  // namespace context_menus
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_CONTEXT_MENUS_H__
