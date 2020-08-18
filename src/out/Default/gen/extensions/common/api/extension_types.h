// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/extension_types.json
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_EXTENSION_TYPES_H__
#define EXTENSIONS_COMMON_API_EXTENSION_TYPES_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace extension_types {

//
// Types
//

// The format of an image.
enum ImageFormat {
  IMAGE_FORMAT_NONE,
  IMAGE_FORMAT_JPEG,
  IMAGE_FORMAT_PNG,
  IMAGE_FORMAT_LAST = IMAGE_FORMAT_PNG,
};


const char* ToString(ImageFormat as_enum);
ImageFormat ParseImageFormat(const std::string& as_string);

// Details about the format and quality of an image.
struct ImageDetails {
  ImageDetails();
  ~ImageDetails();
  ImageDetails(ImageDetails&& rhs);
  ImageDetails& operator=(ImageDetails&& rhs);

  // Populates a ImageDetails object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ImageDetails* out);

  // Creates a ImageDetails object from a base::Value, or NULL on failure.
  static std::unique_ptr<ImageDetails> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ImageDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The format of the resulting image.  Default is <code>"jpeg"</code>.
  ImageFormat format;

  // When format is <code>"jpeg"</code>, controls the quality of the resulting
  // image.  This value is ignored for PNG images.  As quality is decreased, the
  // resulting image will have more visual artifacts, and the number of bytes
  // needed to store it will decrease.
  std::unique_ptr<int> quality;


 private:
  DISALLOW_COPY_AND_ASSIGN(ImageDetails);
};

// The soonest that the JavaScript or CSS will be injected into the tab.
enum RunAt {
  RUN_AT_NONE,
  RUN_AT_DOCUMENT_START,
  RUN_AT_DOCUMENT_END,
  RUN_AT_DOCUMENT_IDLE,
  RUN_AT_LAST = RUN_AT_DOCUMENT_IDLE,
};


const char* ToString(RunAt as_enum);
RunAt ParseRunAt(const std::string& as_string);

// The <a
// href="https://www.w3.org/TR/css3-cascade/#cascading-origins">origin</a> of
// injected CSS.
enum CSSOrigin {
  CSS_ORIGIN_NONE,
  CSS_ORIGIN_AUTHOR,
  CSS_ORIGIN_USER,
  CSS_ORIGIN_LAST = CSS_ORIGIN_USER,
};


const char* ToString(CSSOrigin as_enum);
CSSOrigin ParseCSSOrigin(const std::string& as_string);

// Details of the script or CSS to inject. Either the code or the file property
// must be set, but both may not be set at the same time.
struct InjectDetails {
  InjectDetails();
  ~InjectDetails();
  InjectDetails(InjectDetails&& rhs);
  InjectDetails& operator=(InjectDetails&& rhs);

  // Populates a InjectDetails object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, InjectDetails* out);

  // Creates a InjectDetails object from a base::Value, or NULL on failure.
  static std::unique_ptr<InjectDetails> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this InjectDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // JavaScript or CSS code to inject.<br><br><b>Warning:</b><br>Be careful using
  // the <code>code</code> parameter. Incorrect use of it may open your extension
  // to <a href="https://en.wikipedia.org/wiki/Cross-site_scripting">cross site
  // scripting</a> attacks.
  std::unique_ptr<std::string> code;

  // JavaScript or CSS file to inject.
  std::unique_ptr<std::string> file;

  // If allFrames is <code>true</code>, implies that the JavaScript or CSS should
  // be injected into all frames of current page. By default, it's
  // <code>false</code> and is only injected into the top frame. If
  // <code>true</code> and <code>frameId</code> is set, then the code is inserted
  // in the selected frame and all of its child frames.
  std::unique_ptr<bool> all_frames;

  // The <a href='webNavigation#frame_ids'>frame</a> where the script or CSS
  // should be injected. Defaults to 0 (the top-level frame).
  std::unique_ptr<int> frame_id;

  // If matchAboutBlank is true, then the code is also injected in about:blank and
  // about:srcdoc frames if your extension has access to its parent document. Code
  // cannot be inserted in top-level about:-frames. By default it is
  // <code>false</code>.
  std::unique_ptr<bool> match_about_blank;

  // The soonest that the JavaScript or CSS will be injected into the tab.
  // Defaults to "document_idle".
  RunAt run_at;

  // The <a
  // href="https://www.w3.org/TR/css3-cascade/#cascading-origins">origin</a> of
  // the CSS to inject. This may only be specified for CSS, not JavaScript.
  // Defaults to <code>"author"</code>.
  CSSOrigin css_origin;


 private:
  DISALLOW_COPY_AND_ASSIGN(InjectDetails);
};


}  // namespace extension_types
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_EXTENSION_TYPES_H__
