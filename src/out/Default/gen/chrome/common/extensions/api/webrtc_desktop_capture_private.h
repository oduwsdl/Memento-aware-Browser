// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/webrtc_desktop_capture_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_WEBRTC_DESKTOP_CAPTURE_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_WEBRTC_DESKTOP_CAPTURE_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace webrtc_desktop_capture_private {

//
// Types
//

struct RequestInfo {
  RequestInfo();
  ~RequestInfo();
  RequestInfo(RequestInfo&& rhs);
  RequestInfo& operator=(RequestInfo&& rhs);

  // Populates a RequestInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, RequestInfo* out);

  // Creates a RequestInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<RequestInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RequestInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The guest process id for the requester.
  int guest_process_id;

  // The webview render frame id for the requester.
  int guest_render_frame_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(RequestInfo);
};

enum DesktopCaptureSourceType {
  DESKTOP_CAPTURE_SOURCE_TYPE_NONE,
  DESKTOP_CAPTURE_SOURCE_TYPE_SCREEN,
  DESKTOP_CAPTURE_SOURCE_TYPE_WINDOW,
  DESKTOP_CAPTURE_SOURCE_TYPE_TAB,
  DESKTOP_CAPTURE_SOURCE_TYPE_LAST = DESKTOP_CAPTURE_SOURCE_TYPE_TAB,
};


const char* ToString(DesktopCaptureSourceType as_enum);
DesktopCaptureSourceType ParseDesktopCaptureSourceType(const std::string& as_string);


//
// Functions
//

namespace ChooseDesktopMedia {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::vector<DesktopCaptureSourceType> sources;

  RequestInfo request;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& stream_id);
}  // namespace Results

}  // namespace ChooseDesktopMedia

namespace CancelChooseDesktopMedia {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int desktop_media_request_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace CancelChooseDesktopMedia

}  // namespace webrtc_desktop_capture_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_WEBRTC_DESKTOP_CAPTURE_PRIVATE_H__
