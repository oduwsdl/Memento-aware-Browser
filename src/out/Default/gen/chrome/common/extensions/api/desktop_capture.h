// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/desktop_capture.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_DESKTOP_CAPTURE_H__
#define CHROME_COMMON_EXTENSIONS_API_DESKTOP_CAPTURE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"
#include "chrome/common/extensions/api/tabs.h"


namespace extensions {
namespace api {
namespace desktop_capture {

//
// Types
//

// Enum used to define set of desktop media sources used in
// chooseDesktopMedia().
enum DesktopCaptureSourceType {
  DESKTOP_CAPTURE_SOURCE_TYPE_NONE,
  DESKTOP_CAPTURE_SOURCE_TYPE_SCREEN,
  DESKTOP_CAPTURE_SOURCE_TYPE_WINDOW,
  DESKTOP_CAPTURE_SOURCE_TYPE_TAB,
  DESKTOP_CAPTURE_SOURCE_TYPE_AUDIO,
  DESKTOP_CAPTURE_SOURCE_TYPE_LAST = DESKTOP_CAPTURE_SOURCE_TYPE_AUDIO,
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

  // Set of sources that should be shown to the user. The sources order in the set
  // decides the tab order in the picker.
  std::vector<DesktopCaptureSourceType> sources;

  // Optional tab for which the stream is created. If not specified then the
  // resulting stream can be used only by the calling extension. The stream can
  // only be used by frames in the given tab whose security origin matches
  // <code>tab.url</code>. The tab's origin must be a secure origin, e.g. HTTPS.
  std::unique_ptr<extensions::api::tabs::Tab> target_tab;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Contains properties that describe the stream.
struct Options {
  Options();
  ~Options();
  Options(Options&& rhs);
  Options& operator=(Options&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Options object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // True if "audio" is included in parameter sources, and the end user does not
  // uncheck the "Share audio" checkbox. Otherwise false, and in this case, one
  // should not ask for audio stream through getUserMedia call.
  bool can_request_audio_track;


 private:
  DISALLOW_COPY_AND_ASSIGN(Options);
};


// An opaque string that can be passed to <code>getUserMedia()</code> API to
// generate media stream that corresponds to the source selected by the user. If
// user didn't select any source (i.e. canceled the prompt) then the callback is
// called with an empty <code>streamId</code>. The created <code>streamId</code>
// can be used only once and expires after a few seconds when it is not used.
// Contains properties that describe the stream.
std::unique_ptr<base::ListValue> Create(const std::string& stream_id, const Options& options);
}  // namespace Results

}  // namespace ChooseDesktopMedia

namespace CancelChooseDesktopMedia {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Id returned by chooseDesktopMedia()
  int desktop_media_request_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace CancelChooseDesktopMedia

}  // namespace desktop_capture
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_DESKTOP_CAPTURE_H__
