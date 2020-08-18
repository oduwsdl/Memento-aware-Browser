// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/sessions.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_SESSIONS_H__
#define CHROME_COMMON_EXTENSIONS_API_SESSIONS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"
#include "chrome/common/extensions/api/tabs.h"
#include "chrome/common/extensions/api/windows.h"


namespace extensions {
namespace api {
namespace sessions {

//
// Properties
//

// The maximum number of $(ref:sessions.Session) that will be included in a
// requested list.
extern const int MAX_SESSION_RESULTS;

//
// Types
//

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

  // The maximum number of entries to be fetched in the requested list. Omit this
  // parameter to fetch the maximum number of entries
  // ($(ref:sessions.MAX_SESSION_RESULTS)).
  std::unique_ptr<int> max_results;


 private:
  DISALLOW_COPY_AND_ASSIGN(Filter);
};

struct Session {
  Session();
  ~Session();
  Session(Session&& rhs);
  Session& operator=(Session&& rhs);

  // Populates a Session object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Session* out);

  // Creates a Session object from a base::Value, or NULL on failure.
  static std::unique_ptr<Session> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Session object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The time when the window or tab was closed or modified, represented in
  // milliseconds since the epoch.
  int last_modified;

  // The $(ref:tabs.Tab), if this entry describes a tab. Either this or
  // $(ref:sessions.Session.window) will be set.
  std::unique_ptr<extensions::api::tabs::Tab> tab;

  // The $(ref:windows.Window), if this entry describes a window. Either this or
  // $(ref:sessions.Session.tab) will be set.
  std::unique_ptr<extensions::api::windows::Window> window;


 private:
  DISALLOW_COPY_AND_ASSIGN(Session);
};

struct Device {
  Device();
  ~Device();
  Device(Device&& rhs);
  Device& operator=(Device&& rhs);

  // Populates a Device object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Device* out);

  // Creates a Device object from a base::Value, or NULL on failure.
  static std::unique_ptr<Device> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Device object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string info;

  // The name of the foreign device.
  std::string device_name;

  // A list of open window sessions for the foreign device, sorted from most
  // recently to least recently modified session.
  std::vector<Session> sessions;


 private:
  DISALLOW_COPY_AND_ASSIGN(Device);
};


//
// Functions
//

namespace GetRecentlyClosed {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::unique_ptr<Filter> filter;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The list of closed entries in reverse order that they were closed (the most
// recently closed tab or window will be at index <code>0</code>). The entries
// may contain either tabs or windows.
std::unique_ptr<base::ListValue> Create(const std::vector<Session>& sessions);
}  // namespace Results

}  // namespace GetRecentlyClosed

namespace GetDevices {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::unique_ptr<Filter> filter;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The list of $(ref:sessions.Device) objects for each synced session, sorted in
// order from device with most recently modified session to device with least
// recently modified session. $(ref:tabs.Tab) objects are sorted by recency in
// the $(ref:windows.Window) of the $(ref:sessions.Session) objects.
std::unique_ptr<base::ListValue> Create(const std::vector<Device>& devices);
}  // namespace Results

}  // namespace GetDevices

namespace Restore {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The $(ref:windows.Window.sessionId), or $(ref:tabs.Tab.sessionId) to restore.
  // If this parameter is not specified, the most recently closed session is
  // restored.
  std::unique_ptr<std::string> session_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// A $(ref:sessions.Session) containing the restored $(ref:windows.Window) or
// $(ref:tabs.Tab) object.
std::unique_ptr<base::ListValue> Create(const Session& restored_session);
}  // namespace Results

}  // namespace Restore

//
// Events
//

namespace OnChanged {

extern const char kEventName[];  // "sessions.onChanged"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnChanged

}  // namespace sessions
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_SESSIONS_H__
