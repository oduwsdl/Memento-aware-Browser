// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/storage.json
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_STORAGE_H__
#define EXTENSIONS_COMMON_API_STORAGE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace storage {

//
// Properties
//

// Items in the <code>sync</code> storage area are synced using Chrome Sync.
namespace sync {
  // The maximum total amount (in bytes) of data that can be stored in sync
  // storage, as measured by the JSON stringification of every value plus every
  // key's length. Updates that would cause this limit to be exceeded fail
  // immediately and set $(ref:runtime.lastError).
  extern const int QUOTA_BYTES;
  // The maximum size (in bytes) of each individual item in sync storage, as
  // measured by the JSON stringification of its value plus its key length.
  // Updates containing items larger than this limit will fail immediately and set
  // $(ref:runtime.lastError).
  extern const int QUOTA_BYTES_PER_ITEM;
  // The maximum number of items that can be stored in sync storage. Updates that
  // would cause this limit to be exceeded will fail immediately and set
  // $(ref:runtime.lastError).
  extern const int MAX_ITEMS;
  // <p>The maximum number of <code>set</code>, <code>remove</code>, or
  // <code>clear</code> operations that can be performed each hour. This is 1
  // every 2 seconds, a lower ceiling than the short term higher writes-per-minute
  // limit.</p><p>Updates that would cause this limit to be exceeded fail
  // immediately and set $(ref:runtime.lastError).</p>
  extern const int MAX_WRITE_OPERATIONS_PER_HOUR;
  // <p>The maximum number of <code>set</code>, <code>remove</code>, or
  // <code>clear</code> operations that can be performed each minute. This is 2
  // per second, providing higher throughput than writes-per-hour over a shorter
  // period of time.</p><p>Updates that would cause this limit to be exceeded fail
  // immediately and set $(ref:runtime.lastError).</p>
  extern const int MAX_WRITE_OPERATIONS_PER_MINUTE;
  //
  extern const int MAX_SUSTAINED_WRITE_OPERATIONS_PER_MINUTE;
}  // namespace sync

// Items in the <code>local</code> storage area are local to each machine.
namespace local {
  // The maximum amount (in bytes) of data that can be stored in local storage, as
  // measured by the JSON stringification of every value plus every key's length.
  // This value will be ignored if the extension has the
  // <code>unlimitedStorage</code> permission. Updates that would cause this limit
  // to be exceeded fail immediately and set $(ref:runtime.lastError).
  extern const int QUOTA_BYTES;
}  // namespace local

//
// Types
//

struct StorageChange {
  StorageChange();
  ~StorageChange();
  StorageChange(StorageChange&& rhs);
  StorageChange& operator=(StorageChange&& rhs);

  // Populates a StorageChange object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, StorageChange* out);

  // Creates a StorageChange object from a base::Value, or NULL on failure.
  static std::unique_ptr<StorageChange> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this StorageChange object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The old value of the item, if there was an old value.
  std::unique_ptr<base::Value> old_value;

  // The new value of the item, if there is a new value.
  std::unique_ptr<base::Value> new_value;


 private:
  DISALLOW_COPY_AND_ASSIGN(StorageChange);
};

namespace StorageArea {

namespace Get {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // A single key to get, list of keys to get, or a dictionary specifying default
  // values (see description of the object).  An empty list or object will return
  // an empty result object.  Pass in <code>null</code> to get the entire contents
  // of storage.
  struct Keys {
    Keys();
    ~Keys();
    Keys(Keys&& rhs);
    Keys& operator=(Keys&& rhs);

    // Populates a Keys object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Keys* out);
    // Storage items to return in the callback, where the values are replaced with
    // those from storage if they exist.
    struct Object {
      Object();
      ~Object();
      Object(Object&& rhs);
      Object& operator=(Object&& rhs);

      // Populates a Object object from a base::Value. Returns whether |out| was
      // successfully populated.
      static bool Populate(const base::Value& value, Object* out);

      base::DictionaryValue additional_properties;

     private:
      DISALLOW_COPY_AND_ASSIGN(Object);
    };


    // Choices:
    std::unique_ptr<std::string> as_string;
    std::unique_ptr<std::vector<std::string>> as_strings;
    std::unique_ptr<Object> as_object;

   private:
    DISALLOW_COPY_AND_ASSIGN(Keys);
  };


  // A single key to get, list of keys to get, or a dictionary specifying default
  // values (see description of the object).  An empty list or object will return
  // an empty result object.  Pass in <code>null</code> to get the entire contents
  // of storage.
  std::unique_ptr<Keys> keys;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Object with items in their key-value mappings.
struct Items {
  Items();
  ~Items();
  Items(Items&& rhs);
  Items& operator=(Items&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Items object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Items);
};


// Object with items in their key-value mappings.
std::unique_ptr<base::ListValue> Create(const Items& items);
}  // namespace Results

}  // namespace Get

namespace GetBytesInUse {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // A single key or list of keys to get the total usage for. An empty list will
  // return 0. Pass in <code>null</code> to get the total usage of all of storage.
  struct Keys {
    Keys();
    ~Keys();
    Keys(Keys&& rhs);
    Keys& operator=(Keys&& rhs);

    // Populates a Keys object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Keys* out);
    // Choices:
    std::unique_ptr<std::string> as_string;
    std::unique_ptr<std::vector<std::string>> as_strings;

   private:
    DISALLOW_COPY_AND_ASSIGN(Keys);
  };


  // A single key or list of keys to get the total usage for. An empty list will
  // return 0. Pass in <code>null</code> to get the total usage of all of storage.
  std::unique_ptr<Keys> keys;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Amount of space being used in storage, in bytes.
std::unique_ptr<base::ListValue> Create(int bytes_in_use);
}  // namespace Results

}  // namespace GetBytesInUse

namespace Set {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // <p>An object which gives each key/value pair to update storage with. Any
  // other key/value pairs in storage will not be affected.</p><p>Primitive values
  // such as numbers will serialize as expected. Values with a <code>typeof</code>
  // <code>"object"</code> and <code>"function"</code> will typically serialize to
  // <code>{}</code>, with the exception of <code>Array</code> (serializes as
  // expected), <code>Date</code>, and <code>Regex</code> (serialize using their
  // <code>String</code> representation).</p>
  struct Items {
    Items();
    ~Items();
    Items(Items&& rhs);
    Items& operator=(Items&& rhs);

    // Populates a Items object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Items* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Items);
  };


  // <p>An object which gives each key/value pair to update storage with. Any
  // other key/value pairs in storage will not be affected.</p><p>Primitive values
  // such as numbers will serialize as expected. Values with a <code>typeof</code>
  // <code>"object"</code> and <code>"function"</code> will typically serialize to
  // <code>{}</code>, with the exception of <code>Array</code> (serializes as
  // expected), <code>Date</code>, and <code>Regex</code> (serialize using their
  // <code>String</code> representation).</p>
  Items items;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Set

namespace Remove {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // A single key or a list of keys for items to remove.
  struct Keys {
    Keys();
    ~Keys();
    Keys(Keys&& rhs);
    Keys& operator=(Keys&& rhs);

    // Populates a Keys object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Keys* out);
    // Choices:
    std::unique_ptr<std::string> as_string;
    std::unique_ptr<std::vector<std::string>> as_strings;

   private:
    DISALLOW_COPY_AND_ASSIGN(Keys);
  };


  // A single key or a list of keys for items to remove.
  Keys keys;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Remove

namespace Clear {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Clear

}  // namespace StorageArea


//
// Events
//

namespace OnChanged {

extern const char kEventName[];  // "storage.onChanged"

// Object mapping each key that changed to its corresponding
// $(ref:storage.StorageChange) for that item.
struct Changes {
  Changes();
  ~Changes();
  Changes(Changes&& rhs);
  Changes& operator=(Changes&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Changes object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::map<std::string, StorageChange> additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Changes);
};


// Object mapping each key that changed to its corresponding
// $(ref:storage.StorageChange) for that item.
// The name of the storage area (<code>"sync"</code>, <code>"local"</code> or
// <code>"managed"</code>) the changes are for.
std::unique_ptr<base::ListValue> Create(const Changes& changes, const std::string& area_name);
}  // namespace OnChanged

}  // namespace storage
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_STORAGE_H__
