// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/cryptotoken_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_CRYPTOTOKEN_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_CRYPTOTOKEN_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace cryptotoken_private {

//
// Types
//

struct CanAppIdGetAttestationOptions {
  CanAppIdGetAttestationOptions();
  ~CanAppIdGetAttestationOptions();
  CanAppIdGetAttestationOptions(CanAppIdGetAttestationOptions&& rhs);
  CanAppIdGetAttestationOptions& operator=(CanAppIdGetAttestationOptions&& rhs);

  // Populates a CanAppIdGetAttestationOptions object from a base::Value.
  // Returns whether |out| was successfully populated.
  static bool Populate(const base::Value& value, CanAppIdGetAttestationOptions* out);

  // Creates a CanAppIdGetAttestationOptions object from a base::Value, or NULL
  // on failure.
  static std::unique_ptr<CanAppIdGetAttestationOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CanAppIdGetAttestationOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The AppId (see definition, above) that was used in the registration request
  // and which has been authenticated by |canOriginAssertAppId|.
  std::string app_id;

  // The origin of the caller.
  std::string origin;

  // Identifies the tab in which the registration is occuring so that any
  // permissions prompt is correctly located.
  int tab_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(CanAppIdGetAttestationOptions);
};


//
// Functions
//

namespace CanOriginAssertAppId {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string security_origin;

  std::string app_id_url;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace CanOriginAssertAppId

namespace IsAppIdHashInEnterpriseContext {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::vector<uint8_t> app_id_hash;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace IsAppIdHashInEnterpriseContext

namespace CanAppIdGetAttestation {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  CanAppIdGetAttestationOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace CanAppIdGetAttestation

namespace RecordRegisterRequest {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int tab_id;

  int frame_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RecordRegisterRequest

namespace RecordSignRequest {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int tab_id;

  int frame_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RecordSignRequest

}  // namespace cryptotoken_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_CRYPTOTOKEN_PRIVATE_H__
