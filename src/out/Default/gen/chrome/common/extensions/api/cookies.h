// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/cookies.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_COOKIES_H__
#define CHROME_COMMON_EXTENSIONS_API_COOKIES_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace cookies {

//
// Types
//

// A cookie's 'SameSite' state
// (https://tools.ietf.org/html/draft-west-first-party-cookies).
// 'no_restriction' corresponds to a cookie set with 'SameSite=None', 'lax' to
// 'SameSite=Lax', and 'strict' to 'SameSite=Strict'. 'unspecified' corresponds
// to a cookie set without the SameSite attribute.
enum SameSiteStatus {
  SAME_SITE_STATUS_NONE,
  SAME_SITE_STATUS_NO_RESTRICTION,
  SAME_SITE_STATUS_LAX,
  SAME_SITE_STATUS_STRICT,
  SAME_SITE_STATUS_UNSPECIFIED,
  SAME_SITE_STATUS_LAST = SAME_SITE_STATUS_UNSPECIFIED,
};


const char* ToString(SameSiteStatus as_enum);
SameSiteStatus ParseSameSiteStatus(const std::string& as_string);

// Represents information about an HTTP cookie.
struct Cookie {
  Cookie();
  ~Cookie();
  Cookie(Cookie&& rhs);
  Cookie& operator=(Cookie&& rhs);

  // Populates a Cookie object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Cookie* out);

  // Creates a Cookie object from a base::Value, or NULL on failure.
  static std::unique_ptr<Cookie> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Cookie object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The name of the cookie.
  std::string name;

  // The value of the cookie.
  std::string value;

  // The domain of the cookie (e.g. "www.google.com", "example.com").
  std::string domain;

  // True if the cookie is a host-only cookie (i.e. a request's host must exactly
  // match the domain of the cookie).
  bool host_only;

  // The path of the cookie.
  std::string path;

  // True if the cookie is marked as Secure (i.e. its scope is limited to secure
  // channels, typically HTTPS).
  bool secure;

  // True if the cookie is marked as HttpOnly (i.e. the cookie is inaccessible to
  // client-side scripts).
  bool http_only;

  // The cookie's same-site status (i.e. whether the cookie is sent with
  // cross-site requests).
  SameSiteStatus same_site;

  // True if the cookie is a session cookie, as opposed to a persistent cookie
  // with an expiration date.
  bool session;

  // The expiration date of the cookie as the number of seconds since the UNIX
  // epoch. Not provided for session cookies.
  std::unique_ptr<double> expiration_date;

  // The ID of the cookie store containing this cookie, as provided in
  // getAllCookieStores().
  std::string store_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(Cookie);
};

// Represents a cookie store in the browser. An incognito mode window, for
// instance, uses a separate cookie store from a non-incognito window.
struct CookieStore {
  CookieStore();
  ~CookieStore();
  CookieStore(CookieStore&& rhs);
  CookieStore& operator=(CookieStore&& rhs);

  // Populates a CookieStore object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, CookieStore* out);

  // Creates a CookieStore object from a base::Value, or NULL on failure.
  static std::unique_ptr<CookieStore> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CookieStore object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The unique identifier for the cookie store.
  std::string id;

  // Identifiers of all the browser tabs that share this cookie store.
  std::vector<int> tab_ids;


 private:
  DISALLOW_COPY_AND_ASSIGN(CookieStore);
};

// The underlying reason behind the cookie's change. If a cookie was inserted,
// or removed via an explicit call to "chrome.cookies.remove", "cause" will be
// "explicit". If a cookie was automatically removed due to expiry, "cause" will
// be "expired". If a cookie was removed due to being overwritten with an
// already-expired expiration date, "cause" will be set to "expired_overwrite".
// If a cookie was automatically removed due to garbage collection, "cause" will
// be "evicted".  If a cookie was automatically removed due to a "set" call that
// overwrote it, "cause" will be "overwrite". Plan your response accordingly.
enum OnChangedCause {
  ON_CHANGED_CAUSE_NONE,
  ON_CHANGED_CAUSE_EVICTED,
  ON_CHANGED_CAUSE_EXPIRED,
  ON_CHANGED_CAUSE_EXPLICIT,
  ON_CHANGED_CAUSE_EXPIRED_OVERWRITE,
  ON_CHANGED_CAUSE_OVERWRITE,
  ON_CHANGED_CAUSE_LAST = ON_CHANGED_CAUSE_OVERWRITE,
};


const char* ToString(OnChangedCause as_enum);
OnChangedCause ParseOnChangedCause(const std::string& as_string);


//
// Functions
//

namespace Get {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Details to identify the cookie being retrieved.
  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The URL with which the cookie to retrieve is associated. This argument may be
    // a full URL, in which case any data following the URL path (e.g. the query
    // string) is simply ignored. If host permissions for this URL are not specified
    // in the manifest file, the API call will fail.
    std::string url;

    // The name of the cookie to retrieve.
    std::string name;

    // The ID of the cookie store in which to look for the cookie. By default, the
    // current execution context's cookie store will be used.
    std::unique_ptr<std::string> store_id;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  // Details to identify the cookie being retrieved.
  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Contains details about the cookie. This parameter is null if no such cookie
// was found.
std::unique_ptr<base::ListValue> Create(const Cookie& cookie);
}  // namespace Results

}  // namespace Get

namespace GetAll {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Information to filter the cookies being retrieved.
  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // Restricts the retrieved cookies to those that would match the given URL.
    std::unique_ptr<std::string> url;

    // Filters the cookies by name.
    std::unique_ptr<std::string> name;

    // Restricts the retrieved cookies to those whose domains match or are
    // subdomains of this one.
    std::unique_ptr<std::string> domain;

    // Restricts the retrieved cookies to those whose path exactly matches this
    // string.
    std::unique_ptr<std::string> path;

    // Filters the cookies by their Secure property.
    std::unique_ptr<bool> secure;

    // Filters out session vs. persistent cookies.
    std::unique_ptr<bool> session;

    // The cookie store to retrieve cookies from. If omitted, the current execution
    // context's cookie store will be used.
    std::unique_ptr<std::string> store_id;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  // Information to filter the cookies being retrieved.
  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// All the existing, unexpired cookies that match the given cookie info.
std::unique_ptr<base::ListValue> Create(const std::vector<Cookie>& cookies);
}  // namespace Results

}  // namespace GetAll

namespace Set {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Details about the cookie being set.
  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The request-URI to associate with the setting of the cookie. This value can
    // affect the default domain and path values of the created cookie. If host
    // permissions for this URL are not specified in the manifest file, the API call
    // will fail.
    std::string url;

    // The name of the cookie. Empty by default if omitted.
    std::unique_ptr<std::string> name;

    // The value of the cookie. Empty by default if omitted.
    std::unique_ptr<std::string> value;

    // The domain of the cookie. If omitted, the cookie becomes a host-only cookie.
    std::unique_ptr<std::string> domain;

    // The path of the cookie. Defaults to the path portion of the url parameter.
    std::unique_ptr<std::string> path;

    // Whether the cookie should be marked as Secure. Defaults to false.
    std::unique_ptr<bool> secure;

    // Whether the cookie should be marked as HttpOnly. Defaults to false.
    std::unique_ptr<bool> http_only;

    // The cookie's same-site status. Defaults to "unspecified", i.e., if omitted,
    // the cookie is set without specifying a SameSite attribute.
    SameSiteStatus same_site;

    // The expiration date of the cookie as the number of seconds since the UNIX
    // epoch. If omitted, the cookie becomes a session cookie.
    std::unique_ptr<double> expiration_date;

    // The ID of the cookie store in which to set the cookie. By default, the cookie
    // is set in the current execution context's cookie store.
    std::unique_ptr<std::string> store_id;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  // Details about the cookie being set.
  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Contains details about the cookie that's been set.  If setting failed for any
// reason, this will be "null", and $(ref:runtime.lastError) will be set.
std::unique_ptr<base::ListValue> Create(const Cookie& cookie);
}  // namespace Results

}  // namespace Set

namespace Remove {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Information to identify the cookie to remove.
  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The URL associated with the cookie. If host permissions for this URL are not
    // specified in the manifest file, the API call will fail.
    std::string url;

    // The name of the cookie to remove.
    std::string name;

    // The ID of the cookie store to look in for the cookie. If unspecified, the
    // cookie is looked for by default in the current execution context's cookie
    // store.
    std::unique_ptr<std::string> store_id;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  // Information to identify the cookie to remove.
  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Contains details about the cookie that's been removed.  If removal failed for
// any reason, this will be "null", and $(ref:runtime.lastError) will be set.
struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The URL associated with the cookie that's been removed.
  std::string url;

  // The name of the cookie that's been removed.
  std::string name;

  // The ID of the cookie store from which the cookie was removed.
  std::string store_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


// Contains details about the cookie that's been removed.  If removal failed for
// any reason, this will be "null", and $(ref:runtime.lastError) will be set.
std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace Results

}  // namespace Remove

namespace GetAllCookieStores {

namespace Results {

// All the existing cookie stores.
std::unique_ptr<base::ListValue> Create(const std::vector<CookieStore>& cookie_stores);
}  // namespace Results

}  // namespace GetAllCookieStores

//
// Events
//

namespace OnChanged {

extern const char kEventName[];  // "cookies.onChanged"

struct ChangeInfo {
  ChangeInfo();
  ~ChangeInfo();
  ChangeInfo(ChangeInfo&& rhs);
  ChangeInfo& operator=(ChangeInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ChangeInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // True if a cookie was removed.
  bool removed;

  // Information about the cookie that was set or removed.
  Cookie cookie;

  // The underlying reason behind the cookie's change.
  OnChangedCause cause;


 private:
  DISALLOW_COPY_AND_ASSIGN(ChangeInfo);
};


std::unique_ptr<base::ListValue> Create(const ChangeInfo& change_info);
}  // namespace OnChanged

}  // namespace cookies
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_COOKIES_H__
