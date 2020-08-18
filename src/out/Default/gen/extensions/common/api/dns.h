// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/dns.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_DNS_H__
#define EXTENSIONS_COMMON_API_DNS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace dns {

//
// Types
//

struct ResolveCallbackResolveInfo {
  ResolveCallbackResolveInfo();
  ~ResolveCallbackResolveInfo();
  ResolveCallbackResolveInfo(ResolveCallbackResolveInfo&& rhs);
  ResolveCallbackResolveInfo& operator=(ResolveCallbackResolveInfo&& rhs);

  // Populates a ResolveCallbackResolveInfo object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ResolveCallbackResolveInfo* out);

  // Creates a ResolveCallbackResolveInfo object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ResolveCallbackResolveInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ResolveCallbackResolveInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The result code. Zero indicates success.
  int result_code;

  // A string representing the IP address literal. Supplied only if resultCode
  // indicates success. Note that we presently return only IPv4 addresses.
  std::unique_ptr<std::string> address;


 private:
  DISALLOW_COPY_AND_ASSIGN(ResolveCallbackResolveInfo);
};


//
// Functions
//

namespace Resolve {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The hostname to resolve.
  std::string hostname;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ResolveCallbackResolveInfo& resolve_info);
}  // namespace Results

}  // namespace Resolve

}  // namespace dns
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_DNS_H__
