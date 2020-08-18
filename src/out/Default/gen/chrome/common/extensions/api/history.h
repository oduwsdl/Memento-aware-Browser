// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/history.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_HISTORY_H__
#define CHROME_COMMON_EXTENSIONS_API_HISTORY_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace history {

//
// Types
//

// The <a href='#transition_types'>transition type</a> for this visit from its
// referrer.
enum TransitionType {
  TRANSITION_TYPE_NONE,
  TRANSITION_TYPE_LINK,
  TRANSITION_TYPE_TYPED,
  TRANSITION_TYPE_AUTO_BOOKMARK,
  TRANSITION_TYPE_AUTO_SUBFRAME,
  TRANSITION_TYPE_MANUAL_SUBFRAME,
  TRANSITION_TYPE_GENERATED,
  TRANSITION_TYPE_AUTO_TOPLEVEL,
  TRANSITION_TYPE_FORM_SUBMIT,
  TRANSITION_TYPE_RELOAD,
  TRANSITION_TYPE_KEYWORD,
  TRANSITION_TYPE_KEYWORD_GENERATED,
  TRANSITION_TYPE_LAST = TRANSITION_TYPE_KEYWORD_GENERATED,
};


const char* ToString(TransitionType as_enum);
TransitionType ParseTransitionType(const std::string& as_string);

// An object encapsulating one result of a history query.
struct HistoryItem {
  HistoryItem();
  ~HistoryItem();
  HistoryItem(HistoryItem&& rhs);
  HistoryItem& operator=(HistoryItem&& rhs);

  // Populates a HistoryItem object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, HistoryItem* out);

  // Creates a HistoryItem object from a base::Value, or NULL on failure.
  static std::unique_ptr<HistoryItem> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this HistoryItem object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The unique identifier for the item.
  std::string id;

  // The URL navigated to by a user.
  std::unique_ptr<std::string> url;

  // The title of the page when it was last loaded.
  std::unique_ptr<std::string> title;

  // When this page was last loaded, represented in milliseconds since the epoch.
  std::unique_ptr<double> last_visit_time;

  // The number of times the user has navigated to this page.
  std::unique_ptr<int> visit_count;

  // The number of times the user has navigated to this page by typing in the
  // address.
  std::unique_ptr<int> typed_count;


 private:
  DISALLOW_COPY_AND_ASSIGN(HistoryItem);
};

// An object encapsulating one visit to a URL.
struct VisitItem {
  VisitItem();
  ~VisitItem();
  VisitItem(VisitItem&& rhs);
  VisitItem& operator=(VisitItem&& rhs);

  // Populates a VisitItem object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, VisitItem* out);

  // Creates a VisitItem object from a base::Value, or NULL on failure.
  static std::unique_ptr<VisitItem> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this VisitItem object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The unique identifier for the item.
  std::string id;

  // The unique identifier for this visit.
  std::string visit_id;

  // When this visit occurred, represented in milliseconds since the epoch.
  std::unique_ptr<double> visit_time;

  // The visit ID of the referrer.
  std::string referring_visit_id;

  // The <a href='#transition_types'>transition type</a> for this visit from its
  // referrer.
  TransitionType transition;


 private:
  DISALLOW_COPY_AND_ASSIGN(VisitItem);
};


//
// Functions
//

namespace Search {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Query {
    Query();
    ~Query();
    Query(Query&& rhs);
    Query& operator=(Query&& rhs);

    // Populates a Query object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Query* out);

    // A free-text query to the history service.  Leave empty to retrieve all pages.
    std::string text;

    // Limit results to those visited after this date, represented in milliseconds
    // since the epoch. If not specified, this defaults to 24 hours in the past.
    std::unique_ptr<double> start_time;

    // Limit results to those visited before this date, represented in milliseconds
    // since the epoch.
    std::unique_ptr<double> end_time;

    // The maximum number of results to retrieve.  Defaults to 100.
    std::unique_ptr<int> max_results;


   private:
    DISALLOW_COPY_AND_ASSIGN(Query);
  };


  Query query;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<HistoryItem>& results);
}  // namespace Results

}  // namespace Search

namespace GetVisits {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The URL for which to retrieve visit information.  It must be in the format as
    // returned from a call to history.search.
    std::string url;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<VisitItem>& results);
}  // namespace Results

}  // namespace GetVisits

namespace AddUrl {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The URL to add.
    std::string url;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace AddUrl

namespace DeleteUrl {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The URL to remove.
    std::string url;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DeleteUrl

namespace DeleteRange {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Range {
    Range();
    ~Range();
    Range(Range&& rhs);
    Range& operator=(Range&& rhs);

    // Populates a Range object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Range* out);

    // Items added to history after this date, represented in milliseconds since the
    // epoch.
    double start_time;

    // Items added to history before this date, represented in milliseconds since
    // the epoch.
    double end_time;


   private:
    DISALLOW_COPY_AND_ASSIGN(Range);
  };


  Range range;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DeleteRange

namespace DeleteAll {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DeleteAll

//
// Events
//

namespace OnVisited {

extern const char kEventName[];  // "history.onVisited"

std::unique_ptr<base::ListValue> Create(const HistoryItem& result);
}  // namespace OnVisited

namespace OnVisitRemoved {

extern const char kEventName[];  // "history.onVisitRemoved"

struct Removed {
  Removed();
  ~Removed();
  Removed(Removed&& rhs);
  Removed& operator=(Removed&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Removed object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // True if all history was removed.  If true, then urls will be empty.
  bool all_history;

  std::unique_ptr<std::vector<std::string>> urls;


 private:
  DISALLOW_COPY_AND_ASSIGN(Removed);
};


std::unique_ptr<base::ListValue> Create(const Removed& removed);
}  // namespace OnVisitRemoved

}  // namespace history
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_HISTORY_H__
