// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/bookmarks.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_BOOKMARKS_H__
#define CHROME_COMMON_EXTENSIONS_API_BOOKMARKS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace bookmarks {

//
// Properties
//

//
extern const int MAX_WRITE_OPERATIONS_PER_HOUR;

//
extern const int MAX_SUSTAINED_WRITE_OPERATIONS_PER_MINUTE;

//
// Types
//

// Indicates the reason why this node is unmodifiable. The <var>managed</var>
// value indicates that this node was configured by the system administrator.
// Omitted if the node can be modified by the user and the extension (default).
enum BookmarkTreeNodeUnmodifiable {
  BOOKMARK_TREE_NODE_UNMODIFIABLE_NONE,
  BOOKMARK_TREE_NODE_UNMODIFIABLE_MANAGED,
  BOOKMARK_TREE_NODE_UNMODIFIABLE_LAST = BOOKMARK_TREE_NODE_UNMODIFIABLE_MANAGED,
};


const char* ToString(BookmarkTreeNodeUnmodifiable as_enum);
BookmarkTreeNodeUnmodifiable ParseBookmarkTreeNodeUnmodifiable(const std::string& as_string);

// A node (either a bookmark or a folder) in the bookmark tree.  Child nodes are
// ordered within their parent folder.
struct BookmarkTreeNode {
  BookmarkTreeNode();
  ~BookmarkTreeNode();
  BookmarkTreeNode(BookmarkTreeNode&& rhs);
  BookmarkTreeNode& operator=(BookmarkTreeNode&& rhs);

  // Populates a BookmarkTreeNode object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, BookmarkTreeNode* out);

  // Creates a BookmarkTreeNode object from a base::Value, or NULL on failure.
  static std::unique_ptr<BookmarkTreeNode> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this BookmarkTreeNode object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The unique identifier for the node. IDs are unique within the current
  // profile, and they remain valid even after the browser is restarted.
  std::string id;

  // The <code>id</code> of the parent folder.  Omitted for the root node.
  std::unique_ptr<std::string> parent_id;

  // The 0-based position of this node within its parent folder.
  std::unique_ptr<int> index;

  // The URL navigated to when a user clicks the bookmark. Omitted for folders.
  std::unique_ptr<std::string> url;

  // The text displayed for the node.
  std::string title;

  // When this node was created, in milliseconds since the epoch (<code>new
  // Date(dateAdded)</code>).
  std::unique_ptr<double> date_added;

  // When the contents of this folder last changed, in milliseconds since the
  // epoch.
  std::unique_ptr<double> date_group_modified;

  // Indicates the reason why this node is unmodifiable. The <var>managed</var>
  // value indicates that this node was configured by the system administrator or
  // by the custodian of a supervised user. Omitted if the node can be modified by
  // the user and the extension (default).
  BookmarkTreeNodeUnmodifiable unmodifiable;

  // An ordered list of children of this node.
  std::unique_ptr<std::vector<BookmarkTreeNode>> children;


 private:
  DISALLOW_COPY_AND_ASSIGN(BookmarkTreeNode);
};

// Object passed to the create() function.
struct CreateDetails {
  CreateDetails();
  ~CreateDetails();
  CreateDetails(CreateDetails&& rhs);
  CreateDetails& operator=(CreateDetails&& rhs);

  // Populates a CreateDetails object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, CreateDetails* out);

  // Creates a CreateDetails object from a base::Value, or NULL on failure.
  static std::unique_ptr<CreateDetails> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CreateDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Defaults to the Other Bookmarks folder.
  std::unique_ptr<std::string> parent_id;

  std::unique_ptr<int> index;

  std::unique_ptr<std::string> title;

  std::unique_ptr<std::string> url;


 private:
  DISALLOW_COPY_AND_ASSIGN(CreateDetails);
};


//
// Functions
//

namespace Get {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // A single string-valued id, or an array of string-valued ids
  struct IdOrIdList {
    IdOrIdList();
    ~IdOrIdList();
    IdOrIdList(IdOrIdList&& rhs);
    IdOrIdList& operator=(IdOrIdList&& rhs);

    // Populates a IdOrIdList object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, IdOrIdList* out);
    // Choices:
    std::unique_ptr<std::string> as_string;
    std::unique_ptr<std::vector<std::string>> as_strings;

   private:
    DISALLOW_COPY_AND_ASSIGN(IdOrIdList);
  };


  // A single string-valued id, or an array of string-valued ids
  IdOrIdList id_or_id_list;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<BookmarkTreeNode>& results);
}  // namespace Results

}  // namespace Get

namespace GetChildren {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<BookmarkTreeNode>& results);
}  // namespace Results

}  // namespace GetChildren

namespace GetRecent {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The maximum number of items to return.
  int number_of_items;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<BookmarkTreeNode>& results);
}  // namespace Results

}  // namespace GetRecent

namespace GetTree {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<BookmarkTreeNode>& results);
}  // namespace Results

}  // namespace GetTree

namespace GetSubTree {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the root of the subtree to retrieve.
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<BookmarkTreeNode>& results);
}  // namespace Results

}  // namespace GetSubTree

namespace Search {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Either a string of words and quoted phrases that are matched against bookmark
  // URLs and titles, or an object. If an object, the properties
  // <code>query</code>, <code>url</code>, and <code>title</code> may be specified
  // and bookmarks matching all specified properties will be produced.
  struct Query {
    Query();
    ~Query();
    Query(Query&& rhs);
    Query& operator=(Query&& rhs);

    // Populates a Query object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Query* out);
    // An object specifying properties and values to match when searching. Produces
    // bookmarks matching all properties.
    struct Object {
      Object();
      ~Object();
      Object(Object&& rhs);
      Object& operator=(Object&& rhs);

      // Populates a Object object from a base::Value. Returns whether |out| was
      // successfully populated.
      static bool Populate(const base::Value& value, Object* out);

      // A string of words and quoted phrases that are matched against bookmark URLs
      // and titles.
      std::unique_ptr<std::string> query;

      // The URL of the bookmark; matches verbatim. Note that folders have no URL.
      std::unique_ptr<std::string> url;

      // The title of the bookmark; matches verbatim.
      std::unique_ptr<std::string> title;


     private:
      DISALLOW_COPY_AND_ASSIGN(Object);
    };


    // Choices:
    std::unique_ptr<std::string> as_string;
    std::unique_ptr<Object> as_object;

   private:
    DISALLOW_COPY_AND_ASSIGN(Query);
  };


  // Either a string of words and quoted phrases that are matched against bookmark
  // URLs and titles, or an object. If an object, the properties
  // <code>query</code>, <code>url</code>, and <code>title</code> may be specified
  // and bookmarks matching all specified properties will be produced.
  Query query;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<BookmarkTreeNode>& results);
}  // namespace Results

}  // namespace Search

namespace Create {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  CreateDetails bookmark;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const BookmarkTreeNode& result);
}  // namespace Results

}  // namespace Create

namespace Move {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Destination {
    Destination();
    ~Destination();
    Destination(Destination&& rhs);
    Destination& operator=(Destination&& rhs);

    // Populates a Destination object from a base::Value. Returns whether |out|
    // was successfully populated.
    static bool Populate(const base::Value& value, Destination* out);

    std::unique_ptr<std::string> parent_id;

    std::unique_ptr<int> index;


   private:
    DISALLOW_COPY_AND_ASSIGN(Destination);
  };


  std::string id;

  Destination destination;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const BookmarkTreeNode& result);
}  // namespace Results

}  // namespace Move

namespace Update {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Changes {
    Changes();
    ~Changes();
    Changes(Changes&& rhs);
    Changes& operator=(Changes&& rhs);

    // Populates a Changes object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Changes* out);

    std::unique_ptr<std::string> title;

    std::unique_ptr<std::string> url;


   private:
    DISALLOW_COPY_AND_ASSIGN(Changes);
  };


  std::string id;

  Changes changes;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const BookmarkTreeNode& result);
}  // namespace Results

}  // namespace Update

namespace Remove {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Remove

namespace RemoveTree {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RemoveTree

namespace Import {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Import

namespace Export {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Export

//
// Events
//

namespace OnCreated {

extern const char kEventName[];  // "bookmarks.onCreated"

std::unique_ptr<base::ListValue> Create(const std::string& id, const BookmarkTreeNode& bookmark);
}  // namespace OnCreated

namespace OnRemoved {

extern const char kEventName[];  // "bookmarks.onRemoved"

struct RemoveInfo {
  RemoveInfo();
  ~RemoveInfo();
  RemoveInfo(RemoveInfo&& rhs);
  RemoveInfo& operator=(RemoveInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RemoveInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string parent_id;

  int index;

  BookmarkTreeNode node;


 private:
  DISALLOW_COPY_AND_ASSIGN(RemoveInfo);
};


std::unique_ptr<base::ListValue> Create(const std::string& id, const RemoveInfo& remove_info);
}  // namespace OnRemoved

namespace OnChanged {

extern const char kEventName[];  // "bookmarks.onChanged"

struct ChangeInfo {
  ChangeInfo();
  ~ChangeInfo();
  ChangeInfo(ChangeInfo&& rhs);
  ChangeInfo& operator=(ChangeInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ChangeInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string title;

  std::unique_ptr<std::string> url;


 private:
  DISALLOW_COPY_AND_ASSIGN(ChangeInfo);
};


std::unique_ptr<base::ListValue> Create(const std::string& id, const ChangeInfo& change_info);
}  // namespace OnChanged

namespace OnMoved {

extern const char kEventName[];  // "bookmarks.onMoved"

struct MoveInfo {
  MoveInfo();
  ~MoveInfo();
  MoveInfo(MoveInfo&& rhs);
  MoveInfo& operator=(MoveInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MoveInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string parent_id;

  int index;

  std::string old_parent_id;

  int old_index;


 private:
  DISALLOW_COPY_AND_ASSIGN(MoveInfo);
};


std::unique_ptr<base::ListValue> Create(const std::string& id, const MoveInfo& move_info);
}  // namespace OnMoved

namespace OnChildrenReordered {

extern const char kEventName[];  // "bookmarks.onChildrenReordered"

struct ReorderInfo {
  ReorderInfo();
  ~ReorderInfo();
  ReorderInfo(ReorderInfo&& rhs);
  ReorderInfo& operator=(ReorderInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ReorderInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::vector<std::string> child_ids;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReorderInfo);
};


std::unique_ptr<base::ListValue> Create(const std::string& id, const ReorderInfo& reorder_info);
}  // namespace OnChildrenReordered

namespace OnImportBegan {

extern const char kEventName[];  // "bookmarks.onImportBegan"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnImportBegan

namespace OnImportEnded {

extern const char kEventName[];  // "bookmarks.onImportEnded"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnImportEnded

}  // namespace bookmarks
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_BOOKMARKS_H__
