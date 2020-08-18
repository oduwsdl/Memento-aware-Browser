// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/instance_id.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_INSTANCE_ID_H__
#define CHROME_COMMON_EXTENSIONS_API_INSTANCE_ID_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace instance_id {

//
// Functions
//

namespace GetID {

namespace Results {

// An Instance ID assigned to the app instance.
std::unique_ptr<base::ListValue> Create(const std::string& instance_id);
}  // namespace Results

}  // namespace GetID

namespace GetCreationTime {

namespace Results {

// The time when the Instance ID has been generated, represented in milliseconds
// since the epoch.
std::unique_ptr<base::ListValue> Create(double creation_time);
}  // namespace Results

}  // namespace GetCreationTime

namespace GetToken {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Parameters for getToken.
  struct GetTokenParams {
    GetTokenParams();
    ~GetTokenParams();
    GetTokenParams(GetTokenParams&& rhs);
    GetTokenParams& operator=(GetTokenParams&& rhs);

    // Populates a GetTokenParams object from a base::Value. Returns whether |out|
    // was successfully populated.
    static bool Populate(const base::Value& value, GetTokenParams* out);

    // Allows including a small number of string key/value pairs that will be
    // associated with the token and may be used in processing the request.
    struct Options {
      Options();
      ~Options();
      Options(Options&& rhs);
      Options& operator=(Options&& rhs);

      // Populates a Options object from a base::Value. Returns whether |out| was
      // successfully populated.
      static bool Populate(const base::Value& value, Options* out);

      std::map<std::string, std::string> additional_properties;

     private:
      DISALLOW_COPY_AND_ASSIGN(Options);
    };


    // Identifies the entity that is authorized to access resources associated with
    // this Instance ID. It can be a project ID from <a
    // href='https://code.google.com/apis/console'>Google developer console</a>.
    std::string authorized_entity;

    // Identifies authorized actions that the authorized entity can take. E.g. for
    // sending GCM messages, <code>GCM</code> scope should be used.
    std::string scope;

    // Allows including a small number of string key/value pairs that will be
    // associated with the token and may be used in processing the request.
    std::unique_ptr<Options> options;


   private:
    DISALLOW_COPY_AND_ASSIGN(GetTokenParams);
  };


  // Parameters for getToken.
  GetTokenParams get_token_params;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// A token assigned by the requested service.
std::unique_ptr<base::ListValue> Create(const std::string& token);
}  // namespace Results

}  // namespace GetToken

namespace DeleteToken {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Parameters for deleteToken.
  struct DeleteTokenParams {
    DeleteTokenParams();
    ~DeleteTokenParams();
    DeleteTokenParams(DeleteTokenParams&& rhs);
    DeleteTokenParams& operator=(DeleteTokenParams&& rhs);

    // Populates a DeleteTokenParams object from a base::Value. Returns whether
    // |out| was successfully populated.
    static bool Populate(const base::Value& value, DeleteTokenParams* out);

    // The authorized entity that is used to obtain the token.
    std::string authorized_entity;

    // The scope that is used to obtain the token.
    std::string scope;


   private:
    DISALLOW_COPY_AND_ASSIGN(DeleteTokenParams);
  };


  // Parameters for deleteToken.
  DeleteTokenParams delete_token_params;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DeleteToken

namespace DeleteID {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DeleteID

//
// Events
//

namespace OnTokenRefresh {

extern const char kEventName[];  // "instanceID.onTokenRefresh"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnTokenRefresh

}  // namespace instance_id
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_INSTANCE_ID_H__
