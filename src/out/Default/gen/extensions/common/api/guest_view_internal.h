// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/guest_view_internal.json
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_GUEST_VIEW_INTERNAL_H__
#define EXTENSIONS_COMMON_API_GUEST_VIEW_INTERNAL_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace guest_view_internal {

//
// Types
//

struct Size {
  Size();
  ~Size();
  Size(Size&& rhs);
  Size& operator=(Size&& rhs);

  // Populates a Size object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Size* out);

  // Creates a Size object from a base::Value, or NULL on failure.
  static std::unique_ptr<Size> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Size object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int width;

  int height;


 private:
  DISALLOW_COPY_AND_ASSIGN(Size);
};

// Size parameters.
struct SizeParams {
  SizeParams();
  ~SizeParams();
  SizeParams(SizeParams&& rhs);
  SizeParams& operator=(SizeParams&& rhs);

  // Populates a SizeParams object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, SizeParams* out);

  // Creates a SizeParams object from a base::Value, or NULL on failure.
  static std::unique_ptr<SizeParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SizeParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<bool> enable_auto_size;

  std::unique_ptr<Size> min;

  std::unique_ptr<Size> max;

  std::unique_ptr<Size> normal;


 private:
  DISALLOW_COPY_AND_ASSIGN(SizeParams);
};


//
// Functions
//

namespace CreateGuest {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct CreateParams {
    CreateParams();
    ~CreateParams();
    CreateParams(CreateParams&& rhs);
    CreateParams& operator=(CreateParams&& rhs);

    // Populates a CreateParams object from a base::Value. Returns whether |out|
    // was successfully populated.
    static bool Populate(const base::Value& value, CreateParams* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(CreateParams);
  };


  std::string view_type;

  CreateParams create_params;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct ReturnParams {
  ReturnParams();
  ~ReturnParams();
  ReturnParams(ReturnParams&& rhs);
  ReturnParams& operator=(ReturnParams&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ReturnParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(ReturnParams);
};


std::unique_ptr<base::ListValue> Create(const ReturnParams& return_params);
}  // namespace Results

}  // namespace CreateGuest

namespace DestroyGuest {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DestroyGuest

namespace SetSize {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the guest &lt;webview&gt; process. This not exposed to
  // developers through the API.
  int instance_id;

  SizeParams params;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetSize

}  // namespace guest_view_internal
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_GUEST_VIEW_INTERNAL_H__
