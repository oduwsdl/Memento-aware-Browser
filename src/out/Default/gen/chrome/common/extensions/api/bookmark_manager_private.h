// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/bookmark_manager_private.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_BOOKMARK_MANAGER_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_BOOKMARK_MANAGER_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"
#include "chrome/common/extensions/api/bookmarks.h"


namespace extensions {
namespace api {
namespace bookmark_manager_private {

//
// Types
//

struct BookmarkNodeDataElement {
  BookmarkNodeDataElement();
  ~BookmarkNodeDataElement();
  BookmarkNodeDataElement(BookmarkNodeDataElement&& rhs);
  BookmarkNodeDataElement& operator=(BookmarkNodeDataElement&& rhs);

  // Populates a BookmarkNodeDataElement object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, BookmarkNodeDataElement* out);

  // Creates a BookmarkNodeDataElement object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<BookmarkNodeDataElement> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this BookmarkNodeDataElement object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the bookmark. This is only provided if the data is from the same
  // profile.
  std::unique_ptr<std::string> id;

  // The ID of the parent of the bookmark. This is only provided if the data is
  // from the same profile.
  std::unique_ptr<std::string> parent_id;

  std::string title;

  std::unique_ptr<std::string> url;

  std::vector<BookmarkNodeDataElement> children;


 private:
  DISALLOW_COPY_AND_ASSIGN(BookmarkNodeDataElement);
};

// Information about the drag and drop data for use with drag and drop events.
struct BookmarkNodeData {
  BookmarkNodeData();
  ~BookmarkNodeData();
  BookmarkNodeData(BookmarkNodeData&& rhs);
  BookmarkNodeData& operator=(BookmarkNodeData&& rhs);

  // Populates a BookmarkNodeData object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, BookmarkNodeData* out);

  // Creates a BookmarkNodeData object from a base::Value, or NULL on failure.
  static std::unique_ptr<BookmarkNodeData> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this BookmarkNodeData object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  bool same_profile;

  std::vector<BookmarkNodeDataElement> elements;


 private:
  DISALLOW_COPY_AND_ASSIGN(BookmarkNodeData);
};


//
// Functions
//

namespace Copy {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An array of string-valued ids
  std::vector<std::string> id_list;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Copy

namespace Cut {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An array of string-valued ids
  std::vector<std::string> id_list;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Cut

namespace Paste {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string parent_id;

  // An array of string-valued ids for selected bookmarks.
  std::unique_ptr<std::vector<std::string>> selected_id_list;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Paste

namespace CanPaste {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the folder to paste into.
  std::string parent_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace CanPaste

namespace SortChildren {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the folder to sort the children of.
  std::string parent_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SortChildren

namespace StartDrag {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An array of string-valued ids.
  std::vector<std::string> id_list;

  // The index of the dragged node in |idList|
  int drag_node_index;

  // True if the drag was initiated from touch.
  bool is_from_touch;

  // The clientX of the dragStart event
  int x;

  // The clientY of the dragStart event
  int y;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace StartDrag

namespace Drop {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the folder that the drop was made.
  std::string parent_id;

  // The index of the position to drop at. If left out the dropped items will be
  // placed at the end of the existing children.
  std::unique_ptr<int> index;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Drop

namespace GetSubtree {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // ID of the root of the tree to pull.  If empty, the entire tree will be
  // returned.
  std::string id;

  // Pass true to only return folders.
  bool folders_only;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<extensions::api::bookmarks::BookmarkTreeNode>& results);
}  // namespace Results

}  // namespace GetSubtree

namespace RemoveTrees {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An array of string-valued ids.
  std::vector<std::string> id_list;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RemoveTrees

namespace Undo {

}  // namespace Undo

namespace Redo {

}  // namespace Redo

//
// Events
//

namespace OnDragEnter {

extern const char kEventName[];  // "bookmarkManagerPrivate.onDragEnter"

std::unique_ptr<base::ListValue> Create(const BookmarkNodeData& bookmark_node_data);
}  // namespace OnDragEnter

namespace OnDragLeave {

extern const char kEventName[];  // "bookmarkManagerPrivate.onDragLeave"

std::unique_ptr<base::ListValue> Create(const BookmarkNodeData& bookmark_node_data);
}  // namespace OnDragLeave

namespace OnDrop {

extern const char kEventName[];  // "bookmarkManagerPrivate.onDrop"

std::unique_ptr<base::ListValue> Create(const BookmarkNodeData& bookmark_node_data);
}  // namespace OnDrop

}  // namespace bookmark_manager_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_BOOKMARK_MANAGER_PRIVATE_H__
