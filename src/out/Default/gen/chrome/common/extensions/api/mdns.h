// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/mdns.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_MDNS_H__
#define CHROME_COMMON_EXTENSIONS_API_MDNS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace mdns {

//
// Properties
//

// The maximum number of service instances that will be included in
// onServiceList events.  If more instances are available, they may be truncated
// from the onServiceList event.
extern const int MAX_SERVICE_INSTANCES_PER_EVENT;

//
// Types
//

struct MDnsService {
  MDnsService();
  ~MDnsService();
  MDnsService(MDnsService&& rhs);
  MDnsService& operator=(MDnsService&& rhs);

  // Populates a MDnsService object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, MDnsService* out);

  // Creates a MDnsService object from a base::Value, or NULL on failure.
  static std::unique_ptr<MDnsService> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MDnsService object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The service name of an mDNS advertised service,
  // <instance_name>.<service_type>.
  std::string service_name;

  // The host:port pair of an mDNS advertised service.
  std::string service_host_port;

  // The IP address of an mDNS advertised service.
  std::string ip_address;

  // Metadata for an mDNS advertised service.
  std::vector<std::string> service_data;


 private:
  DISALLOW_COPY_AND_ASSIGN(MDnsService);
};


//
// Functions
//

namespace ForceDiscovery {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ForceDiscovery

//
// Events
//

namespace OnServiceList {

extern const char kEventName[];  // "mdns.onServiceList"

std::unique_ptr<base::ListValue> Create(const std::vector<MDnsService>& services);
}  // namespace OnServiceList

}  // namespace mdns
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_MDNS_H__
