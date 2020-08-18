// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/notifications.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_NOTIFICATIONS_H__
#define CHROME_COMMON_EXTENSIONS_API_NOTIFICATIONS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace notifications {

//
// Types
//

enum TemplateType {
  TEMPLATE_TYPE_NONE,
  TEMPLATE_TYPE_BASIC,
  TEMPLATE_TYPE_IMAGE,
  TEMPLATE_TYPE_LIST,
  TEMPLATE_TYPE_PROGRESS,
  TEMPLATE_TYPE_LAST = TEMPLATE_TYPE_PROGRESS,
};


const char* ToString(TemplateType as_enum);
TemplateType ParseTemplateType(const std::string& as_string);

enum PermissionLevel {
  PERMISSION_LEVEL_NONE,
  PERMISSION_LEVEL_GRANTED,
  PERMISSION_LEVEL_DENIED,
  PERMISSION_LEVEL_LAST = PERMISSION_LEVEL_DENIED,
};


const char* ToString(PermissionLevel as_enum);
PermissionLevel ParsePermissionLevel(const std::string& as_string);

struct NotificationItem {
  NotificationItem();
  ~NotificationItem();
  NotificationItem(NotificationItem&& rhs);
  NotificationItem& operator=(NotificationItem&& rhs);

  // Populates a NotificationItem object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, NotificationItem* out);

  // Creates a NotificationItem object from a base::Value, or NULL on failure.
  static std::unique_ptr<NotificationItem> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this NotificationItem object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Title of one item of a list notification.
  std::string title;

  // Additional details about this item.
  std::string message;


 private:
  DISALLOW_COPY_AND_ASSIGN(NotificationItem);
};

struct NotificationBitmap {
  NotificationBitmap();
  ~NotificationBitmap();
  NotificationBitmap(NotificationBitmap&& rhs);
  NotificationBitmap& operator=(NotificationBitmap&& rhs);

  // Populates a NotificationBitmap object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, NotificationBitmap* out);

  // Creates a NotificationBitmap object from a base::Value, or NULL on failure.
  static std::unique_ptr<NotificationBitmap> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this NotificationBitmap object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int width;

  int height;

  std::unique_ptr<std::vector<uint8_t>> data;


 private:
  DISALLOW_COPY_AND_ASSIGN(NotificationBitmap);
};

struct NotificationButton {
  NotificationButton();
  ~NotificationButton();
  NotificationButton(NotificationButton&& rhs);
  NotificationButton& operator=(NotificationButton&& rhs);

  // Populates a NotificationButton object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, NotificationButton* out);

  // Creates a NotificationButton object from a base::Value, or NULL on failure.
  static std::unique_ptr<NotificationButton> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this NotificationButton object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string title;

  std::unique_ptr<std::string> icon_url;

  std::unique_ptr<NotificationBitmap> icon_bitmap;


 private:
  DISALLOW_COPY_AND_ASSIGN(NotificationButton);
};

struct NotificationOptions {
  NotificationOptions();
  ~NotificationOptions();
  NotificationOptions(NotificationOptions&& rhs);
  NotificationOptions& operator=(NotificationOptions&& rhs);

  // Populates a NotificationOptions object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, NotificationOptions* out);

  // Creates a NotificationOptions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<NotificationOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this NotificationOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Which type of notification to display. <em>Required for
  // $(ref:notifications.create)</em> method.
  TemplateType type;

  // <p>A URL to the sender's avatar, app icon, or a thumbnail for image
  // notifications.</p><p>URLs can be a data URL, a blob URL, or a URL relative to
  // a resource within this extension's .crx file <em>Required for
  // $(ref:notifications.create)</em> method.</p>
  std::unique_ptr<std::string> icon_url;

  std::unique_ptr<NotificationBitmap> icon_bitmap;

  // <p>A URL to the app icon mask. URLs have the same restrictions as
  // $(ref:notifications.NotificationOptions.iconUrl iconUrl).</p><p>The app icon
  // mask should be in alpha channel, as only the alpha channel of the image will
  // be considered.</p>
  std::unique_ptr<std::string> app_icon_mask_url;

  std::unique_ptr<NotificationBitmap> app_icon_mask_bitmap;

  // Title of the notification (e.g. sender name for email). <em>Required for
  // $(ref:notifications.create)</em> method.
  std::unique_ptr<std::string> title;

  // Main notification content. <em>Required for $(ref:notifications.create)</em>
  // method.
  std::unique_ptr<std::string> message;

  // Alternate notification content with a lower-weight font.
  std::unique_ptr<std::string> context_message;

  // Priority ranges from -2 to 2. -2 is lowest priority. 2 is highest. Zero is
  // default.  On platforms that don't support a notification center (Windows,
  // Linux & Mac), -2 and -1 result in an error as notifications with those
  // priorities will not be shown at all.
  std::unique_ptr<int> priority;

  // A timestamp associated with the notification, in milliseconds past the epoch
  // (e.g. <code>Date.now() + n</code>).
  std::unique_ptr<double> event_time;

  // Text and icons for up to two notification action buttons.
  std::unique_ptr<std::vector<NotificationButton>> buttons;

  // Secondary notification content.
  std::unique_ptr<std::string> expanded_message;

  // A URL to the image thumbnail for image-type notifications. URLs have the same
  // restrictions as $(ref:notifications.NotificationOptions.iconUrl iconUrl).
  std::unique_ptr<std::string> image_url;

  std::unique_ptr<NotificationBitmap> image_bitmap;

  // Items for multi-item notifications. Users on Mac OS X only see the first
  // item.
  std::unique_ptr<std::vector<NotificationItem>> items;

  // Current progress ranges from 0 to 100.
  std::unique_ptr<int> progress;

  std::unique_ptr<bool> is_clickable;

  // Indicates that the notification should remain visible on screen until the
  // user activates or dismisses the notification. This defaults to false.
  std::unique_ptr<bool> require_interaction;

  // Indicates that no sounds or vibrations should be made when the notification
  // is being shown. This defaults to false.
  std::unique_ptr<bool> silent;


 private:
  DISALLOW_COPY_AND_ASSIGN(NotificationOptions);
};


//
// Functions
//

namespace Create {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // <p>Identifier of the notification. If not set or empty, an ID will
  // automatically be generated. If it matches an existing notification, this
  // method first clears that notification before proceeding with the create
  // operation. The identifier may not be longer than 500 characters.</p><p>The
  // <code>notificationId</code> parameter is required before Chrome 42.</p>
  std::unique_ptr<std::string> notification_id;

  // Contents of the notification.
  NotificationOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& notification_id);
}  // namespace Results

}  // namespace Create

namespace Update {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the notification to be updated. This is returned by
  // $(ref:notifications.create) method.
  std::string notification_id;

  // Contents of the notification to update to.
  NotificationOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool was_updated);
}  // namespace Results

}  // namespace Update

namespace Clear {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the notification to be cleared. This is returned by
  // $(ref:notifications.create) method.
  std::string notification_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool was_cleared);
}  // namespace Results

}  // namespace Clear

namespace GetAll {

namespace Results {

struct Notifications {
  Notifications();
  ~Notifications();
  Notifications(Notifications&& rhs);
  Notifications& operator=(Notifications&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Notifications object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Notifications);
};


std::unique_ptr<base::ListValue> Create(const Notifications& notifications);
}  // namespace Results

}  // namespace GetAll

namespace GetPermissionLevel {

namespace Results {

std::unique_ptr<base::ListValue> Create(const PermissionLevel& level);
}  // namespace Results

}  // namespace GetPermissionLevel

//
// Events
//

namespace OnClosed {

extern const char kEventName[];  // "notifications.onClosed"

std::unique_ptr<base::ListValue> Create(const std::string& notification_id, bool by_user);
}  // namespace OnClosed

namespace OnClicked {

extern const char kEventName[];  // "notifications.onClicked"

std::unique_ptr<base::ListValue> Create(const std::string& notification_id);
}  // namespace OnClicked

namespace OnButtonClicked {

extern const char kEventName[];  // "notifications.onButtonClicked"

std::unique_ptr<base::ListValue> Create(const std::string& notification_id, int button_index);
}  // namespace OnButtonClicked

namespace OnPermissionLevelChanged {

extern const char kEventName[];  // "notifications.onPermissionLevelChanged"

std::unique_ptr<base::ListValue> Create(const PermissionLevel& level);
}  // namespace OnPermissionLevelChanged

namespace OnShowSettings {

extern const char kEventName[];  // "notifications.onShowSettings"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnShowSettings

}  // namespace notifications
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_NOTIFICATIONS_H__
