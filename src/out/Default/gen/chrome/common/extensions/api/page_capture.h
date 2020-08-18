// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/page_capture.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_PAGE_CAPTURE_H__
#define CHROME_COMMON_EXTENSIONS_API_PAGE_CAPTURE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace page_capture {

//
// Functions
//

namespace SaveAsMHTML {

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

    // The id of the tab to save as MHTML.
    int tab_id;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The MHTML data as a Blob.
std::unique_ptr<base::ListValue> Create(const std::vector<uint8_t>& mhtml_data);
}  // namespace Results

}  // namespace SaveAsMHTML

}  // namespace page_capture
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_PAGE_CAPTURE_H__
