// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/app_current_window_internal.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_APP_CURRENT_WINDOW_INTERNAL_H__
#define EXTENSIONS_COMMON_API_APP_CURRENT_WINDOW_INTERNAL_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace app_current_window_internal {

//
// Types
//

struct Bounds {
  Bounds();
  ~Bounds();
  Bounds(Bounds&& rhs);
  Bounds& operator=(Bounds&& rhs);

  // Populates a Bounds object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Bounds* out);

  // Creates a Bounds object from a base::Value, or NULL on failure.
  static std::unique_ptr<Bounds> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Bounds object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<int> left;

  std::unique_ptr<int> top;

  std::unique_ptr<int> width;

  std::unique_ptr<int> height;


 private:
  DISALLOW_COPY_AND_ASSIGN(Bounds);
};

struct SizeConstraints {
  SizeConstraints();
  ~SizeConstraints();
  SizeConstraints(SizeConstraints&& rhs);
  SizeConstraints& operator=(SizeConstraints&& rhs);

  // Populates a SizeConstraints object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, SizeConstraints* out);

  // Creates a SizeConstraints object from a base::Value, or NULL on failure.
  static std::unique_ptr<SizeConstraints> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SizeConstraints object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<int> min_width;

  std::unique_ptr<int> min_height;

  std::unique_ptr<int> max_width;

  std::unique_ptr<int> max_height;


 private:
  DISALLOW_COPY_AND_ASSIGN(SizeConstraints);
};

struct RegionRect {
  RegionRect();
  ~RegionRect();
  RegionRect(RegionRect&& rhs);
  RegionRect& operator=(RegionRect&& rhs);

  // Populates a RegionRect object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, RegionRect* out);

  // Creates a RegionRect object from a base::Value, or NULL on failure.
  static std::unique_ptr<RegionRect> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RegionRect object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int left;

  int top;

  int width;

  int height;


 private:
  DISALLOW_COPY_AND_ASSIGN(RegionRect);
};

struct Region {
  Region();
  ~Region();
  Region(Region&& rhs);
  Region& operator=(Region&& rhs);

  // Populates a Region object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Region* out);

  // Creates a Region object from a base::Value, or NULL on failure.
  static std::unique_ptr<Region> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Region object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::vector<RegionRect>> rects;


 private:
  DISALLOW_COPY_AND_ASSIGN(Region);
};


//
// Functions
//

namespace Focus {

}  // namespace Focus

namespace Fullscreen {

}  // namespace Fullscreen

namespace Minimize {

}  // namespace Minimize

namespace Maximize {

}  // namespace Maximize

namespace Restore {

}  // namespace Restore

namespace DrawAttention {

}  // namespace DrawAttention

namespace ClearAttention {

}  // namespace ClearAttention

namespace Show {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::unique_ptr<bool> focused;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Show

namespace Hide {

}  // namespace Hide

namespace SetBounds {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string bounds_type;

  Bounds bounds;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetBounds

namespace SetSizeConstraints {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string bounds_type;

  SizeConstraints constraints;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetSizeConstraints

namespace SetIcon {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string icon_url;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetIcon

namespace SetShape {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  Region region;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetShape

namespace SetAlwaysOnTop {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool always_on_top;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetAlwaysOnTop

namespace SetVisibleOnAllWorkspaces {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool always_visible;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetVisibleOnAllWorkspaces

namespace SetActivateOnPointer {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool activate_on_pointer;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetActivateOnPointer

//
// Events
//

namespace OnClosed {

extern const char kEventName[];  // "app.currentWindowInternal.onClosed"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnClosed

namespace OnBoundsChanged {

extern const char kEventName[];  // "app.currentWindowInternal.onBoundsChanged"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnBoundsChanged

namespace OnFullscreened {

extern const char kEventName[];  // "app.currentWindowInternal.onFullscreened"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnFullscreened

namespace OnMinimized {

extern const char kEventName[];  // "app.currentWindowInternal.onMinimized"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnMinimized

namespace OnMaximized {

extern const char kEventName[];  // "app.currentWindowInternal.onMaximized"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnMaximized

namespace OnRestored {

extern const char kEventName[];  // "app.currentWindowInternal.onRestored"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnRestored

namespace OnAlphaEnabledChanged {

extern const char kEventName[];  // "app.currentWindowInternal.onAlphaEnabledChanged"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnAlphaEnabledChanged

}  // namespace app_current_window_internal
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_APP_CURRENT_WINDOW_INTERNAL_H__
