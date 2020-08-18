// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/context_menus_internal.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_CONTEXT_MENUS_INTERNAL_H__
#define CHROME_COMMON_EXTENSIONS_API_CONTEXT_MENUS_INTERNAL_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"
#include "chrome/common/extensions/api/tabs.h"


namespace extensions {
namespace api {
namespace context_menus_internal {

//
// Types
//

// Information sent when a context menu item is clicked.
struct OnClickData {
  OnClickData();
  ~OnClickData();
  OnClickData(OnClickData&& rhs);
  OnClickData& operator=(OnClickData&& rhs);

  // Populates a OnClickData object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, OnClickData* out);

  // Creates a OnClickData object from a base::Value, or NULL on failure.
  static std::unique_ptr<OnClickData> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this OnClickData object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the menu item that was clicked.
  struct MenuItemId {
    MenuItemId();
    ~MenuItemId();
    MenuItemId(MenuItemId&& rhs);
    MenuItemId& operator=(MenuItemId&& rhs);

    // Populates a MenuItemId object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, MenuItemId* out);

    // Returns a new base::Value representing the serialized form of this
    // MenuItemId object.
    std::unique_ptr<base::Value> ToValue() const;
    // Choices:
    std::unique_ptr<int> as_integer;
    std::unique_ptr<std::string> as_string;

   private:
    DISALLOW_COPY_AND_ASSIGN(MenuItemId);
  };

  // The parent ID, if any, for the item clicked.
  struct ParentMenuItemId {
    ParentMenuItemId();
    ~ParentMenuItemId();
    ParentMenuItemId(ParentMenuItemId&& rhs);
    ParentMenuItemId& operator=(ParentMenuItemId&& rhs);

    // Populates a ParentMenuItemId object from a base::Value. Returns whether
    // |out| was successfully populated.
    static bool Populate(const base::Value& value, ParentMenuItemId* out);

    // Returns a new base::Value representing the serialized form of this
    // ParentMenuItemId object.
    std::unique_ptr<base::Value> ToValue() const;
    // Choices:
    std::unique_ptr<int> as_integer;
    std::unique_ptr<std::string> as_string;

   private:
    DISALLOW_COPY_AND_ASSIGN(ParentMenuItemId);
  };


  // The ID of the menu item that was clicked.
  MenuItemId menu_item_id;

  // The parent ID, if any, for the item clicked.
  std::unique_ptr<ParentMenuItemId> parent_menu_item_id;

  // One of 'image', 'video', or 'audio' if the context menu was activated on one
  // of these types of elements.
  std::unique_ptr<std::string> media_type;

  // If the element is a link, the URL it points to.
  std::unique_ptr<std::string> link_url;

  // Will be present for elements with a 'src' URL.
  std::unique_ptr<std::string> src_url;

  // The URL of the page where the menu item was clicked. This property is not set
  // if the click occured in a context where there is no current page, such as in
  // a launcher context menu.
  std::unique_ptr<std::string> page_url;

  //  The URL of the frame of the element where the context menu was clicked, if
  // it was in a frame.
  std::unique_ptr<std::string> frame_url;

  //  The <a href='webNavigation#frame_ids'>ID of the frame</a> of the element
  // where the context menu was clicked, if it was in a frame.
  std::unique_ptr<int> frame_id;

  // The text for the context selection, if any.
  std::unique_ptr<std::string> selection_text;

  // A flag indicating whether the element is editable (text input, textarea,
  // etc.).
  bool editable;

  // A flag indicating the state of a checkbox or radio item before it was
  // clicked.
  std::unique_ptr<bool> was_checked;

  // A flag indicating the state of a checkbox or radio item after it is clicked.
  std::unique_ptr<bool> checked;


 private:
  DISALLOW_COPY_AND_ASSIGN(OnClickData);
};


//
// Events
//

namespace OnClicked {

extern const char kEventName[];  // "contextMenusInternal.onClicked"

// Information about the item clicked and the context where the click happened.
// The details of the tab where the click took place. If the click did not take
// place in a tab, this parameter will be missing.
std::unique_ptr<base::ListValue> Create(const OnClickData& info, const extensions::api::tabs::Tab& tab);
}  // namespace OnClicked

}  // namespace context_menus_internal
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_CONTEXT_MENUS_INTERNAL_H__
