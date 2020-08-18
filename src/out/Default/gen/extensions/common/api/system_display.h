// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/system_display.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_SYSTEM_DISPLAY_H__
#define EXTENSIONS_COMMON_API_SYSTEM_DISPLAY_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace system_display {

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

  // The x-coordinate of the upper-left corner.
  int left;

  // The y-coordinate of the upper-left corner.
  int top;

  // The width of the display in pixels.
  int width;

  // The height of the display in pixels.
  int height;


 private:
  DISALLOW_COPY_AND_ASSIGN(Bounds);
};

struct Insets {
  Insets();
  ~Insets();
  Insets(Insets&& rhs);
  Insets& operator=(Insets&& rhs);

  // Populates a Insets object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Insets* out);

  // Creates a Insets object from a base::Value, or NULL on failure.
  static std::unique_ptr<Insets> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Insets object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The x-axis distance from the left bound.
  int left;

  // The y-axis distance from the top bound.
  int top;

  // The x-axis distance from the right bound.
  int right;

  // The y-axis distance from the bottom bound.
  int bottom;


 private:
  DISALLOW_COPY_AND_ASSIGN(Insets);
};

struct Point {
  Point();
  ~Point();
  Point(Point&& rhs);
  Point& operator=(Point&& rhs);

  // Populates a Point object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Point* out);

  // Creates a Point object from a base::Value, or NULL on failure.
  static std::unique_ptr<Point> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Point object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The x-coordinate of the point.
  int x;

  // The y-coordinate of the point.
  int y;


 private:
  DISALLOW_COPY_AND_ASSIGN(Point);
};

struct TouchCalibrationPair {
  TouchCalibrationPair();
  ~TouchCalibrationPair();
  TouchCalibrationPair(TouchCalibrationPair&& rhs);
  TouchCalibrationPair& operator=(TouchCalibrationPair&& rhs);

  // Populates a TouchCalibrationPair object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, TouchCalibrationPair* out);

  // Creates a TouchCalibrationPair object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<TouchCalibrationPair> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this TouchCalibrationPair object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The coordinates of the display point.
  Point display_point;

  // The coordinates of the touch point corresponding to the display point.
  Point touch_point;


 private:
  DISALLOW_COPY_AND_ASSIGN(TouchCalibrationPair);
};

struct TouchCalibrationPairQuad {
  TouchCalibrationPairQuad();
  ~TouchCalibrationPairQuad();
  TouchCalibrationPairQuad(TouchCalibrationPairQuad&& rhs);
  TouchCalibrationPairQuad& operator=(TouchCalibrationPairQuad&& rhs);

  // Populates a TouchCalibrationPairQuad object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, TouchCalibrationPairQuad* out);

  // Creates a TouchCalibrationPairQuad object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<TouchCalibrationPairQuad> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this TouchCalibrationPairQuad object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // First pair of touch and display point required for touch calibration.
  TouchCalibrationPair pair1;

  // Second pair of touch and display point required for touch calibration.
  TouchCalibrationPair pair2;

  // Third pair of touch and display point required for touch calibration.
  TouchCalibrationPair pair3;

  // Fourth pair of touch and display point required for touch calibration.
  TouchCalibrationPair pair4;


 private:
  DISALLOW_COPY_AND_ASSIGN(TouchCalibrationPairQuad);
};

struct DisplayMode {
  DisplayMode();
  ~DisplayMode();
  DisplayMode(DisplayMode&& rhs);
  DisplayMode& operator=(DisplayMode&& rhs);

  // Populates a DisplayMode object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DisplayMode* out);

  // Creates a DisplayMode object from a base::Value, or NULL on failure.
  static std::unique_ptr<DisplayMode> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DisplayMode object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The display mode width in device independent (user visible) pixels.
  int width;

  // The display mode height in device independent (user visible) pixels.
  int height;

  // The display mode width in native pixels.
  int width_in_native_pixels;

  // The display mode height in native pixels.
  int height_in_native_pixels;

  // The display mode UI scale factor.
  std::unique_ptr<double> ui_scale;

  // The display mode device scale factor.
  double device_scale_factor;

  // The display mode refresh rate in hertz.
  double refresh_rate;

  // True if the mode is the display's native mode.
  bool is_native;

  // True if the display mode is currently selected.
  bool is_selected;

  // True if this mode is interlaced, false if not provided.
  std::unique_ptr<bool> is_interlaced;


 private:
  DISALLOW_COPY_AND_ASSIGN(DisplayMode);
};

// Layout position, i.e. edge of parent that the display is attached to.
enum LayoutPosition {
  LAYOUT_POSITION_NONE,
  LAYOUT_POSITION_TOP,
  LAYOUT_POSITION_RIGHT,
  LAYOUT_POSITION_BOTTOM,
  LAYOUT_POSITION_LEFT,
  LAYOUT_POSITION_LAST = LAYOUT_POSITION_LEFT,
};


const char* ToString(LayoutPosition as_enum);
LayoutPosition ParseLayoutPosition(const std::string& as_string);

struct DisplayLayout {
  DisplayLayout();
  ~DisplayLayout();
  DisplayLayout(DisplayLayout&& rhs);
  DisplayLayout& operator=(DisplayLayout&& rhs);

  // Populates a DisplayLayout object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DisplayLayout* out);

  // Creates a DisplayLayout object from a base::Value, or NULL on failure.
  static std::unique_ptr<DisplayLayout> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DisplayLayout object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The unique identifier of the display.
  std::string id;

  // The unique identifier of the parent display. Empty if this is the root.
  std::string parent_id;

  // The layout position of this display relative to the parent. This will be
  // ignored for the root.
  LayoutPosition position;

  // The offset of the display along the connected edge. 0 indicates that the
  // topmost or leftmost corners are aligned.
  int offset;


 private:
  DISALLOW_COPY_AND_ASSIGN(DisplayLayout);
};

struct Edid {
  Edid();
  ~Edid();
  Edid(Edid&& rhs);
  Edid& operator=(Edid&& rhs);

  // Populates a Edid object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Edid* out);

  // Creates a Edid object from a base::Value, or NULL on failure.
  static std::unique_ptr<Edid> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Edid object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // 3 character manufacturer code. See Sec. 3.4.1 page 21. Required in v1.4.
  std::string manufacturer_id;

  // 2 byte manufacturer-assigned code, Sec. 3.4.2 page 21. Required in v1.4.
  std::string product_id;

  // Year of manufacturer, Sec. 3.4.4 page 22. Required in v1.4.
  int year_of_manufacture;


 private:
  DISALLOW_COPY_AND_ASSIGN(Edid);
};

struct DisplayUnitInfo {
  DisplayUnitInfo();
  ~DisplayUnitInfo();
  DisplayUnitInfo(DisplayUnitInfo&& rhs);
  DisplayUnitInfo& operator=(DisplayUnitInfo&& rhs);

  // Populates a DisplayUnitInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, DisplayUnitInfo* out);

  // Creates a DisplayUnitInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<DisplayUnitInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DisplayUnitInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The unique identifier of the display.
  std::string id;

  // The user-friendly name (e.g. "HP LCD monitor").
  std::string name;

  // NOTE: This is only available to Chrome OS Kiosk apps and Web UI.
  std::unique_ptr<Edid> edid;

  // Chrome OS only. Identifier of the display that is being mirrored if mirroring
  // is enabled, otherwise empty. This will be set for all displays (including the
  // display being mirrored).
  std::string mirroring_source_id;

  // Chrome OS only. Identifiers of the displays to which the source display is
  // being mirrored. Empty if no displays are being mirrored. This will be set to
  // the same value for all displays. This must not include |mirroringSourceId|.
  std::vector<std::string> mirroring_destination_ids;

  // True if this is the primary display.
  bool is_primary;

  // True if this is an internal display.
  bool is_internal;

  // True if this display is enabled.
  bool is_enabled;

  // True for all displays when in unified desktop mode. See documentation for
  // $(ref:enableUnifiedDesktop).
  bool is_unified;

  // True when the device is in a tablet physical state (e.g. device is flipped or
  // detached), which is independent from the state of the UI which maybe in
  // tablet or clamshell modes. Provided for ChromeOS Settings UI only.
  // TODO(stevenjb): Remove when Settings switches to a mojo API.
  std::unique_ptr<bool> is_in_tablet_physical_state;

  // The number of pixels per inch along the x-axis.
  double dpi_x;

  // The number of pixels per inch along the y-axis.
  double dpi_y;

  // The display's clockwise rotation in degrees relative to the vertical
  // position. Currently exposed only on ChromeOS. Will be set to 0 on other
  // platforms. A value of -1 will be interpreted as auto-rotate when the device
  // is in a physical tablet state.
  int rotation;

  // The display's logical bounds.
  Bounds bounds;

  // The display's insets within its screen's bounds. Currently exposed only on
  // ChromeOS. Will be set to empty insets on other platforms.
  Insets overscan;

  // The usable work area of the display within the display bounds. The work area
  // excludes areas of the display reserved for OS, for example taskbar and
  // launcher.
  Bounds work_area;

  // The list of available display modes. The current mode will have
  // isSelected=true. Only available on Chrome OS. Will be set to an empty array
  // on other platforms.
  std::vector<DisplayMode> modes;

  // True if this display has a touch input device associated with it.
  bool has_touch_support;

  // True if this display has an accelerometer associated with it. Provided for
  // ChromeOS Settings UI only. TODO(stevenjb): Remove when Settings switches to a
  // mojo API. NOTE: The name of this may change.
  bool has_accelerometer_support;

  // A list of zoom factor values that can be set for the display.
  std::vector<double> available_display_zoom_factors;

  // The ratio between the display's current and default zoom. For example, value
  // 1 is equivalent to 100% zoom, and value 1.5 is equivalent to 150% zoom.
  double display_zoom_factor;


 private:
  DISALLOW_COPY_AND_ASSIGN(DisplayUnitInfo);
};

struct DisplayProperties {
  DisplayProperties();
  ~DisplayProperties();
  DisplayProperties(DisplayProperties&& rhs);
  DisplayProperties& operator=(DisplayProperties&& rhs);

  // Populates a DisplayProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, DisplayProperties* out);

  // Creates a DisplayProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<DisplayProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DisplayProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Chrome OS only. If set to true, changes the display mode to unified desktop
  // (see $(ref:enableUnifiedDesktop) for details). If set to false, unified
  // desktop mode will be disabled. This is only valid for the primary display. If
  // provided, mirroringSourceId must not be provided and other properties will be
  // ignored. This is has no effect if not provided.
  std::unique_ptr<bool> is_unified;

  // Chrome OS only. If set and not empty, enables mirroring for this display
  // only. Otherwise disables mirroring for all displays. This value should
  // indicate the id of the source display to mirror, which must not be the same
  // as the id passed to setDisplayProperties. If set, no other property may be
  // set.
  std::unique_ptr<std::string> mirroring_source_id;

  // If set to true, makes the display primary. No-op if set to false. Note: If
  // set, the display is considered primary for all other properties (i.e.
  // $(ref:isUnified) may be set and bounds origin may not).
  std::unique_ptr<bool> is_primary;

  // If set, sets the display's overscan insets to the provided values. Note that
  // overscan values may not be negative or larger than a half of the screen's
  // size. Overscan cannot be changed on the internal monitor.
  std::unique_ptr<Insets> overscan;

  // If set, updates the display's rotation. Legal values are [0, 90, 180, 270].
  // The rotation is set clockwise, relative to the display's vertical position.
  std::unique_ptr<int> rotation;

  // If set, updates the display's logical bounds origin along the x-axis. Applied
  // together with $(ref:boundsOriginY). Defaults to the current value if not set
  // and $(ref:boundsOriginY) is set. Note that when updating the display origin,
  // some constraints will be applied, so the final bounds origin may be different
  // than the one set. The final bounds can be retrieved using $(ref:getInfo). The
  // bounds origin cannot be changed on the primary display.
  std::unique_ptr<int> bounds_origin_x;

  // If set, updates the display's logical bounds origin along the y-axis. See
  // documentation for $(ref:boundsOriginX) parameter.
  std::unique_ptr<int> bounds_origin_y;

  // If set, updates the display mode to the mode matching this value. If other
  // parameters are invalid, this will not be applied. If the display mode is
  // invalid, it will not be applied and an error will be set, but other
  // properties will still be applied.
  std::unique_ptr<DisplayMode> display_mode;

  // If set, updates the zoom associated with the display. This zoom performs
  // re-layout and repaint thus resulting in a better quality zoom than just
  // performing a pixel by pixel stretch enlargement.
  std::unique_ptr<double> display_zoom_factor;


 private:
  DISALLOW_COPY_AND_ASSIGN(DisplayProperties);
};

struct GetInfoFlags {
  GetInfoFlags();
  ~GetInfoFlags();
  GetInfoFlags(GetInfoFlags&& rhs);
  GetInfoFlags& operator=(GetInfoFlags&& rhs);

  // Populates a GetInfoFlags object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, GetInfoFlags* out);

  // Creates a GetInfoFlags object from a base::Value, or NULL on failure.
  static std::unique_ptr<GetInfoFlags> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this GetInfoFlags object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // If set to true, only a single $(ref:DisplayUnitInfo) will be returned by
  // $(ref:getInfo) when in unified desktop mode (see
  // $(ref:enableUnifiedDesktop)). Defaults to false.
  std::unique_ptr<bool> single_unified;


 private:
  DISALLOW_COPY_AND_ASSIGN(GetInfoFlags);
};

// Mirror mode, i.e. different ways of how a display is mirrored to other
// displays.
enum MirrorMode {
  MIRROR_MODE_NONE,
  MIRROR_MODE_OFF,
  MIRROR_MODE_NORMAL,
  MIRROR_MODE_MIXED,
  MIRROR_MODE_LAST = MIRROR_MODE_MIXED,
};


const char* ToString(MirrorMode as_enum);
MirrorMode ParseMirrorMode(const std::string& as_string);

struct MirrorModeInfo {
  MirrorModeInfo();
  ~MirrorModeInfo();
  MirrorModeInfo(MirrorModeInfo&& rhs);
  MirrorModeInfo& operator=(MirrorModeInfo&& rhs);

  // Populates a MirrorModeInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, MirrorModeInfo* out);

  // Creates a MirrorModeInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<MirrorModeInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MirrorModeInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The mirror mode that should be set.
  MirrorMode mode;

  // The id of the mirroring source display. This is only valid for 'mixed'.
  std::unique_ptr<std::string> mirroring_source_id;

  // The ids of the mirroring destination displays. This is only valid for
  // 'mixed'.
  std::unique_ptr<std::vector<std::string>> mirroring_destination_ids;


 private:
  DISALLOW_COPY_AND_ASSIGN(MirrorModeInfo);
};


//
// Functions
//

namespace GetInfo {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Options affecting how the information is returned.
  std::unique_ptr<GetInfoFlags> flags;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<DisplayUnitInfo>& display_info);
}  // namespace Results

}  // namespace GetInfo

namespace GetDisplayLayout {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<DisplayLayout>& layouts);
}  // namespace Results

}  // namespace GetDisplayLayout

namespace SetDisplayProperties {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The display's unique identifier.
  std::string id;

  // The information about display properties that should be changed.     A
  // property will be changed only if a new value for it is specified in
  // |info|.
  DisplayProperties info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetDisplayProperties

namespace SetDisplayLayout {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The layout information, required for all displays except     the primary
  // display.
  std::vector<DisplayLayout> layouts;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetDisplayLayout

namespace EnableUnifiedDesktop {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // True if unified desktop should be enabled.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace EnableUnifiedDesktop

namespace OverscanCalibrationStart {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The display's unique identifier.
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace OverscanCalibrationStart

namespace OverscanCalibrationAdjust {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The display's unique identifier.
  std::string id;

  // The amount to change the overscan insets.
  Insets delta;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace OverscanCalibrationAdjust

namespace OverscanCalibrationReset {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The display's unique identifier.
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace OverscanCalibrationReset

namespace OverscanCalibrationComplete {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The display's unique identifier.
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace OverscanCalibrationComplete

namespace ShowNativeTouchCalibration {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The display's unique identifier.
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace ShowNativeTouchCalibration

namespace StartCustomTouchCalibration {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The display's unique identifier.
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace StartCustomTouchCalibration

namespace CompleteCustomTouchCalibration {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The pairs of point used to calibrate the display.
  TouchCalibrationPairQuad pairs;

  // Bounds of the display when the touch calibration was performed.
  // |bounds.left| and |bounds.top| values are ignored.
  Bounds bounds;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace CompleteCustomTouchCalibration

namespace ClearTouchCalibration {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The display's unique identifier.
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace ClearTouchCalibration

namespace SetMirrorMode {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The information of the mirror mode that should be applied to the     display
  // mode.
  MirrorModeInfo info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetMirrorMode

//
// Events
//

namespace OnDisplayChanged {

extern const char kEventName[];  // "system.display.onDisplayChanged"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnDisplayChanged

}  // namespace system_display
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_SYSTEM_DISPLAY_H__
