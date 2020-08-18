// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/clipboard.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_CLIPBOARD_H__
#define EXTENSIONS_COMMON_API_CLIPBOARD_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace clipboard {

//
// Types
//

// Supported image types.
enum ImageType {
  IMAGE_TYPE_NONE,
  IMAGE_TYPE_PNG,
  IMAGE_TYPE_JPEG,
  IMAGE_TYPE_LAST = IMAGE_TYPE_JPEG,
};


const char* ToString(ImageType as_enum);
ImageType ParseImageType(const std::string& as_string);

enum DataItemType {
  DATA_ITEM_TYPE_NONE,
  DATA_ITEM_TYPE_TEXTPLAIN,
  DATA_ITEM_TYPE_TEXTHTML,
  DATA_ITEM_TYPE_LAST = DATA_ITEM_TYPE_TEXTHTML,
};


const char* ToString(DataItemType as_enum);
DataItemType ParseDataItemType(const std::string& as_string);

struct AdditionalDataItem {
  AdditionalDataItem();
  ~AdditionalDataItem();
  AdditionalDataItem(AdditionalDataItem&& rhs);
  AdditionalDataItem& operator=(AdditionalDataItem&& rhs);

  // Populates a AdditionalDataItem object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AdditionalDataItem* out);

  // Creates a AdditionalDataItem object from a base::Value, or NULL on failure.
  static std::unique_ptr<AdditionalDataItem> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AdditionalDataItem object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Type of the additional data item.
  DataItemType type;

  // Content of the additional data item. Either the plain text string if |type|
  // is "textPlain" or markup string if |type| is "textHtml". The data can not
  // exceed 2MB.
  std::string data;


 private:
  DISALLOW_COPY_AND_ASSIGN(AdditionalDataItem);
};


//
// Functions
//

namespace SetImageData {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The encoded image data.
  std::vector<uint8_t> image_data;

  // The type of image being passed.
  ImageType type;

  // Additional data items for describing image data. The callback is called with
  // <code>chrome.runtime.lastError</code> set to error code if there is an error.
  // Requires clipboard and clipboardWrite permissions.
  std::unique_ptr<std::vector<AdditionalDataItem>> additional_items;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetImageData

//
// Events
//

namespace OnClipboardDataChanged {

extern const char kEventName[];  // "clipboard.onClipboardDataChanged"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnClipboardDataChanged

}  // namespace clipboard
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_CLIPBOARD_H__
