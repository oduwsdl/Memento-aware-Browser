// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/activity_log_private.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_ACTIVITY_LOG_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_ACTIVITY_LOG_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace activity_log_private {

//
// Types
//

enum ExtensionActivityType {
  EXTENSION_ACTIVITY_TYPE_NONE,
  EXTENSION_ACTIVITY_TYPE_API_CALL,
  EXTENSION_ACTIVITY_TYPE_API_EVENT,
  EXTENSION_ACTIVITY_TYPE_CONTENT_SCRIPT,
  EXTENSION_ACTIVITY_TYPE_DOM_ACCESS,
  EXTENSION_ACTIVITY_TYPE_DOM_EVENT,
  EXTENSION_ACTIVITY_TYPE_WEB_REQUEST,
  EXTENSION_ACTIVITY_TYPE_LAST = EXTENSION_ACTIVITY_TYPE_WEB_REQUEST,
};


const char* ToString(ExtensionActivityType as_enum);
ExtensionActivityType ParseExtensionActivityType(const std::string& as_string);

// Exact match or any
enum ExtensionActivityFilter {
  EXTENSION_ACTIVITY_FILTER_NONE,
  EXTENSION_ACTIVITY_FILTER_API_CALL,
  EXTENSION_ACTIVITY_FILTER_API_EVENT,
  EXTENSION_ACTIVITY_FILTER_CONTENT_SCRIPT,
  EXTENSION_ACTIVITY_FILTER_DOM_ACCESS,
  EXTENSION_ACTIVITY_FILTER_DOM_EVENT,
  EXTENSION_ACTIVITY_FILTER_WEB_REQUEST,
  EXTENSION_ACTIVITY_FILTER_ANY,
  EXTENSION_ACTIVITY_FILTER_LAST = EXTENSION_ACTIVITY_FILTER_ANY,
};


const char* ToString(ExtensionActivityFilter as_enum);
ExtensionActivityFilter ParseExtensionActivityFilter(const std::string& as_string);

enum ExtensionActivityDomVerb {
  EXTENSION_ACTIVITY_DOM_VERB_NONE,
  EXTENSION_ACTIVITY_DOM_VERB_GETTER,
  EXTENSION_ACTIVITY_DOM_VERB_SETTER,
  EXTENSION_ACTIVITY_DOM_VERB_METHOD,
  EXTENSION_ACTIVITY_DOM_VERB_INSERTED,
  EXTENSION_ACTIVITY_DOM_VERB_XHR,
  EXTENSION_ACTIVITY_DOM_VERB_WEBREQUEST,
  EXTENSION_ACTIVITY_DOM_VERB_MODIFIED,
  EXTENSION_ACTIVITY_DOM_VERB_LAST = EXTENSION_ACTIVITY_DOM_VERB_MODIFIED,
};


const char* ToString(ExtensionActivityDomVerb as_enum);
ExtensionActivityDomVerb ParseExtensionActivityDomVerb(const std::string& as_string);

// This corresponds to a row from the ActivityLog database. Fields will be blank
// if they were specified precisely in a lookup filter.
struct ExtensionActivity {
  ExtensionActivity();
  ~ExtensionActivity();
  ExtensionActivity(ExtensionActivity&& rhs);
  ExtensionActivity& operator=(ExtensionActivity&& rhs);

  // Populates a ExtensionActivity object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ExtensionActivity* out);

  // Creates a ExtensionActivity object from a base::Value, or NULL on failure.
  static std::unique_ptr<ExtensionActivity> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ExtensionActivity object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  struct Other {
    Other();
    ~Other();
    Other(Other&& rhs);
    Other& operator=(Other&& rhs);

    // Populates a Other object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Other* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Other object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    std::unique_ptr<bool> prerender;

    ExtensionActivityDomVerb dom_verb;

    std::unique_ptr<std::string> web_request;

    std::unique_ptr<std::string> extra;


   private:
    DISALLOW_COPY_AND_ASSIGN(Other);
  };


  // An ID of a row in the ActivityLog database that corresponds to the activity.
  // ID is set only on activities retrieved from the database.
  std::unique_ptr<std::string> activity_id;

  std::unique_ptr<std::string> extension_id;

  ExtensionActivityType activity_type;

  std::unique_ptr<double> time;

  std::unique_ptr<std::string> api_call;

  std::unique_ptr<std::string> args;

  std::unique_ptr<double> count;

  std::unique_ptr<std::string> page_url;

  std::unique_ptr<std::string> page_title;

  std::unique_ptr<std::string> arg_url;

  std::unique_ptr<Other> other;


 private:
  DISALLOW_COPY_AND_ASSIGN(ExtensionActivity);
};

// Used to specify values for a lookup.
struct Filter {
  Filter();
  ~Filter();
  Filter(Filter&& rhs);
  Filter& operator=(Filter&& rhs);

  // Populates a Filter object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Filter* out);

  // Creates a Filter object from a base::Value, or NULL on failure.
  static std::unique_ptr<Filter> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Filter object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Exact match
  std::unique_ptr<std::string> extension_id;

  ExtensionActivityFilter activity_type;

  // Exact match
  std::unique_ptr<std::string> api_call;

  // Treated as a prefix
  std::unique_ptr<std::string> page_url;

  // Treated as a prefix
  std::unique_ptr<std::string> arg_url;

  // Used to lookup a precise day; today is 0
  std::unique_ptr<int> days_ago;


 private:
  DISALLOW_COPY_AND_ASSIGN(Filter);
};

// This holds the results of a lookup, the filter of the lookup, the time of the
// lookup, and whether there are more results that match.
struct ActivityResultSet {
  ActivityResultSet();
  ~ActivityResultSet();
  ActivityResultSet(ActivityResultSet&& rhs);
  ActivityResultSet& operator=(ActivityResultSet&& rhs);

  // Populates a ActivityResultSet object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ActivityResultSet* out);

  // Creates a ActivityResultSet object from a base::Value, or NULL on failure.
  static std::unique_ptr<ActivityResultSet> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ActivityResultSet object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::vector<ExtensionActivity> activities;


 private:
  DISALLOW_COPY_AND_ASSIGN(ActivityResultSet);
};


//
// Functions
//

namespace GetExtensionActivities {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Fill out the fields that you want to search for in the database.
  Filter filter;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ActivityResultSet& result);
}  // namespace Results

}  // namespace GetExtensionActivities

namespace DeleteActivities {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Erases only the activities which IDs are listed in the array.
  std::vector<std::string> activity_ids;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DeleteActivities

namespace DeleteActivitiesByExtension {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the extension to delete activities for.
  std::string extension_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DeleteActivitiesByExtension

namespace DeleteDatabase {

}  // namespace DeleteDatabase

namespace DeleteUrls {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Erases only the URLs listed; if empty, erases all URLs.
  std::unique_ptr<std::vector<std::string>> urls;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace DeleteUrls

//
// Events
//

namespace OnExtensionActivity {

extern const char kEventName[];  // "activityLogPrivate.onExtensionActivity"

std::unique_ptr<base::ListValue> Create(const ExtensionActivity& activity);
}  // namespace OnExtensionActivity

}  // namespace activity_log_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_ACTIVITY_LOG_PRIVATE_H__
