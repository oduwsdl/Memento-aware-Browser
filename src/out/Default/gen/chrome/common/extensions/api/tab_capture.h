// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/tab_capture.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_TAB_CAPTURE_H__
#define CHROME_COMMON_EXTENSIONS_API_TAB_CAPTURE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace tab_capture {

//
// Types
//

enum TabCaptureState {
  TAB_CAPTURE_STATE_NONE,
  TAB_CAPTURE_STATE_PENDING,
  TAB_CAPTURE_STATE_ACTIVE,
  TAB_CAPTURE_STATE_STOPPED,
  TAB_CAPTURE_STATE_ERROR,
  TAB_CAPTURE_STATE_LAST = TAB_CAPTURE_STATE_ERROR,
};


const char* ToString(TabCaptureState as_enum);
TabCaptureState ParseTabCaptureState(const std::string& as_string);

struct CaptureInfo {
  CaptureInfo();
  ~CaptureInfo();
  CaptureInfo(CaptureInfo&& rhs);
  CaptureInfo& operator=(CaptureInfo&& rhs);

  // Populates a CaptureInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, CaptureInfo* out);

  // Creates a CaptureInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<CaptureInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CaptureInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The id of the tab whose status changed.
  int tab_id;

  // The new capture status of the tab.
  TabCaptureState status;

  // Whether an element in the tab being captured is in fullscreen mode.
  bool fullscreen;


 private:
  DISALLOW_COPY_AND_ASSIGN(CaptureInfo);
};

struct MediaStreamConstraint {
  MediaStreamConstraint();
  ~MediaStreamConstraint();
  MediaStreamConstraint(MediaStreamConstraint&& rhs);
  MediaStreamConstraint& operator=(MediaStreamConstraint&& rhs);

  // Populates a MediaStreamConstraint object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, MediaStreamConstraint* out);

  // Creates a MediaStreamConstraint object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<MediaStreamConstraint> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MediaStreamConstraint object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  struct Mandatory {
    Mandatory();
    ~Mandatory();
    Mandatory(Mandatory&& rhs);
    Mandatory& operator=(Mandatory&& rhs);

    // Populates a Mandatory object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Mandatory* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Mandatory object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Mandatory);
  };

  struct Optional {
    Optional();
    ~Optional();
    Optional(Optional&& rhs);
    Optional& operator=(Optional&& rhs);

    // Populates a Optional object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Optional* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Optional object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Optional);
  };


  Mandatory mandatory;

  std::unique_ptr<Optional> optional;


 private:
  DISALLOW_COPY_AND_ASSIGN(MediaStreamConstraint);
};

struct CaptureOptions {
  CaptureOptions();
  ~CaptureOptions();
  CaptureOptions(CaptureOptions&& rhs);
  CaptureOptions& operator=(CaptureOptions&& rhs);

  // Populates a CaptureOptions object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, CaptureOptions* out);

  // Creates a CaptureOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<CaptureOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CaptureOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<bool> audio;

  std::unique_ptr<bool> video;

  std::unique_ptr<MediaStreamConstraint> audio_constraints;

  std::unique_ptr<MediaStreamConstraint> video_constraints;

  std::unique_ptr<std::string> presentation_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(CaptureOptions);
};

struct GetMediaStreamOptions {
  GetMediaStreamOptions();
  ~GetMediaStreamOptions();
  GetMediaStreamOptions(GetMediaStreamOptions&& rhs);
  GetMediaStreamOptions& operator=(GetMediaStreamOptions&& rhs);

  // Populates a GetMediaStreamOptions object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, GetMediaStreamOptions* out);

  // Creates a GetMediaStreamOptions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<GetMediaStreamOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this GetMediaStreamOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Optional tab id of the tab which will later invoke
  // <code>getUserMedia()</code> to consume the stream. If not specified then the
  // resulting stream can be used only by the calling extension. The stream can
  // only be used by frames in the given tab whose security origin matches the
  // consumber tab's origin. The tab's origin must be a secure origin, e.g. HTTPS.
  std::unique_ptr<int> consumer_tab_id;

  // Optional tab id of the tab which will be captured. If not specified then the
  // current active tab will be selected. Only tabs for which the extension has
  // been granted the <code>activeTab</code> permission can be used as the target
  // tab.
  std::unique_ptr<int> target_tab_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(GetMediaStreamOptions);
};


//
// Functions
//

namespace Capture {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Configures the returned media stream.
  CaptureOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Stream {
  Stream();
  ~Stream();
  Stream(Stream&& rhs);
  Stream& operator=(Stream&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Stream object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Stream);
};


std::unique_ptr<base::ListValue> Create(const Stream& stream);
}  // namespace Results

}  // namespace Capture

namespace GetCapturedTabs {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<CaptureInfo>& result);
}  // namespace Results

}  // namespace GetCapturedTabs

namespace CaptureOffscreenTab {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string start_url;

  // Constraints for the capture and returned MediaStream.
  CaptureOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Stream {
  Stream();
  ~Stream();
  Stream(Stream&& rhs);
  Stream& operator=(Stream&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Stream object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Stream);
};


std::unique_ptr<base::ListValue> Create(const Stream& stream);
}  // namespace Results

}  // namespace CaptureOffscreenTab

namespace GetMediaStreamId {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::unique_ptr<GetMediaStreamOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& stream_id);
}  // namespace Results

}  // namespace GetMediaStreamId

//
// Events
//

namespace OnStatusChanged {

extern const char kEventName[];  // "tabCapture.onStatusChanged"

// CaptureInfo with new capture status for the tab.
std::unique_ptr<base::ListValue> Create(const CaptureInfo& info);
}  // namespace OnStatusChanged

}  // namespace tab_capture
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_TAB_CAPTURE_H__
