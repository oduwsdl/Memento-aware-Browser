// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/automation_internal.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_AUTOMATION_INTERNAL_H__
#define EXTENSIONS_COMMON_API_AUTOMATION_INTERNAL_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace automation_internal {

//
// Types
//

struct AXEventParams {
  AXEventParams();
  ~AXEventParams();
  AXEventParams(AXEventParams&& rhs);
  AXEventParams& operator=(AXEventParams&& rhs);

  // Populates a AXEventParams object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, AXEventParams* out);

  // Creates a AXEventParams object from a base::Value, or NULL on failure.
  static std::unique_ptr<AXEventParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AXEventParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(AXEventParams);
};

struct AXTextLocationParams {
  AXTextLocationParams();
  ~AXTextLocationParams();
  AXTextLocationParams(AXTextLocationParams&& rhs);
  AXTextLocationParams& operator=(AXTextLocationParams&& rhs);

  // Populates a AXTextLocationParams object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AXTextLocationParams* out);

  // Creates a AXTextLocationParams object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<AXTextLocationParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AXTextLocationParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string tree_id;

  int node_id;

  bool result;

  int left;

  int top;

  int width;

  int height;

  int request_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(AXTextLocationParams);
};

// Actions internally used by automation.
enum ActionTypePrivate {
  ACTION_TYPE_PRIVATE_NONE,
  ACTION_TYPE_PRIVATE_RESUMEMEDIA,
  ACTION_TYPE_PRIVATE_STARTDUCKINGMEDIA,
  ACTION_TYPE_PRIVATE_STOPDUCKINGMEDIA,
  ACTION_TYPE_PRIVATE_SUSPENDMEDIA,
  ACTION_TYPE_PRIVATE_LAST = ACTION_TYPE_PRIVATE_SUSPENDMEDIA,
};


const char* ToString(ActionTypePrivate as_enum);
ActionTypePrivate ParseActionTypePrivate(const std::string& as_string);

struct PerformActionRequiredParams {
  PerformActionRequiredParams();
  ~PerformActionRequiredParams();
  PerformActionRequiredParams(PerformActionRequiredParams&& rhs);
  PerformActionRequiredParams& operator=(PerformActionRequiredParams&& rhs);

  // Populates a PerformActionRequiredParams object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, PerformActionRequiredParams* out);

  // Creates a PerformActionRequiredParams object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<PerformActionRequiredParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PerformActionRequiredParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string tree_id;

  int automation_node_id;

  // This can be either automation::ActionType or
  // automation_internal::ActionTypePrivate.
  std::string action_type;

  std::unique_ptr<int> request_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(PerformActionRequiredParams);
};

struct PerformCustomActionParams {
  PerformCustomActionParams();
  ~PerformCustomActionParams();
  PerformCustomActionParams(PerformCustomActionParams&& rhs);
  PerformCustomActionParams& operator=(PerformCustomActionParams&& rhs);

  // Populates a PerformCustomActionParams object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, PerformCustomActionParams* out);

  // Creates a PerformCustomActionParams object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<PerformCustomActionParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PerformCustomActionParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int custom_action_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(PerformCustomActionParams);
};

struct SetSelectionParams {
  SetSelectionParams();
  ~SetSelectionParams();
  SetSelectionParams(SetSelectionParams&& rhs);
  SetSelectionParams& operator=(SetSelectionParams&& rhs);

  // Populates a SetSelectionParams object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, SetSelectionParams* out);

  // Creates a SetSelectionParams object from a base::Value, or NULL on failure.
  static std::unique_ptr<SetSelectionParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SetSelectionParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Reuses ActionRequiredParams automationNodeID to mean anchor node id, and
  // treeID to apply to both anchor and focus node ids.
  int focus_node_id;

  int anchor_offset;

  int focus_offset;


 private:
  DISALLOW_COPY_AND_ASSIGN(SetSelectionParams);
};

struct ReplaceSelectedTextParams {
  ReplaceSelectedTextParams();
  ~ReplaceSelectedTextParams();
  ReplaceSelectedTextParams(ReplaceSelectedTextParams&& rhs);
  ReplaceSelectedTextParams& operator=(ReplaceSelectedTextParams&& rhs);

  // Populates a ReplaceSelectedTextParams object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ReplaceSelectedTextParams* out);

  // Creates a ReplaceSelectedTextParams object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ReplaceSelectedTextParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ReplaceSelectedTextParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string value;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReplaceSelectedTextParams);
};

struct SetValueParams {
  SetValueParams();
  ~SetValueParams();
  SetValueParams(SetValueParams&& rhs);
  SetValueParams& operator=(SetValueParams&& rhs);

  // Populates a SetValueParams object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, SetValueParams* out);

  // Creates a SetValueParams object from a base::Value, or NULL on failure.
  static std::unique_ptr<SetValueParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SetValueParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string value;


 private:
  DISALLOW_COPY_AND_ASSIGN(SetValueParams);
};

struct QuerySelectorRequiredParams {
  QuerySelectorRequiredParams();
  ~QuerySelectorRequiredParams();
  QuerySelectorRequiredParams(QuerySelectorRequiredParams&& rhs);
  QuerySelectorRequiredParams& operator=(QuerySelectorRequiredParams&& rhs);

  // Populates a QuerySelectorRequiredParams object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, QuerySelectorRequiredParams* out);

  // Creates a QuerySelectorRequiredParams object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<QuerySelectorRequiredParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this QuerySelectorRequiredParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string tree_id;

  int automation_node_id;

  std::string selector;


 private:
  DISALLOW_COPY_AND_ASSIGN(QuerySelectorRequiredParams);
};

struct EnableTabParams {
  EnableTabParams();
  ~EnableTabParams();
  EnableTabParams(EnableTabParams&& rhs);
  EnableTabParams& operator=(EnableTabParams&& rhs);

  // Populates a EnableTabParams object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, EnableTabParams* out);

  // Creates a EnableTabParams object from a base::Value, or NULL on failure.
  static std::unique_ptr<EnableTabParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this EnableTabParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<int> tab_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(EnableTabParams);
};

struct GetImageDataParams {
  GetImageDataParams();
  ~GetImageDataParams();
  GetImageDataParams(GetImageDataParams&& rhs);
  GetImageDataParams& operator=(GetImageDataParams&& rhs);

  // Populates a GetImageDataParams object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, GetImageDataParams* out);

  // Creates a GetImageDataParams object from a base::Value, or NULL on failure.
  static std::unique_ptr<GetImageDataParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this GetImageDataParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int max_width;

  int max_height;


 private:
  DISALLOW_COPY_AND_ASSIGN(GetImageDataParams);
};

struct HitTestParams {
  HitTestParams();
  ~HitTestParams();
  HitTestParams(HitTestParams&& rhs);
  HitTestParams& operator=(HitTestParams&& rhs);

  // Populates a HitTestParams object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, HitTestParams* out);

  // Creates a HitTestParams object from a base::Value, or NULL on failure.
  static std::unique_ptr<HitTestParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this HitTestParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int x;

  int y;

  std::string event_to_fire;


 private:
  DISALLOW_COPY_AND_ASSIGN(HitTestParams);
};

struct GetTextLocationDataParams {
  GetTextLocationDataParams();
  ~GetTextLocationDataParams();
  GetTextLocationDataParams(GetTextLocationDataParams&& rhs);
  GetTextLocationDataParams& operator=(GetTextLocationDataParams&& rhs);

  // Populates a GetTextLocationDataParams object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, GetTextLocationDataParams* out);

  // Creates a GetTextLocationDataParams object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<GetTextLocationDataParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this GetTextLocationDataParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int start_index;

  int end_index;


 private:
  DISALLOW_COPY_AND_ASSIGN(GetTextLocationDataParams);
};


//
// Functions
//

namespace EnableTab {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  EnableTabParams args;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& tree_id, int tab_id);
}  // namespace Results

}  // namespace EnableTab

namespace EnableTree {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string tree_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace EnableTree

namespace EnableDesktop {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& tree_id);
}  // namespace Results

}  // namespace EnableDesktop

namespace PerformAction {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Opt_args {
    Opt_args();
    ~Opt_args();
    Opt_args(Opt_args&& rhs);
    Opt_args& operator=(Opt_args&& rhs);

    // Populates a Opt_args object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Opt_args* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Opt_args);
  };


  PerformActionRequiredParams args;

  Opt_args opt_args;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace PerformAction

namespace QuerySelector {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  QuerySelectorRequiredParams args;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int result_automation_node_id);
}  // namespace Results

}  // namespace QuerySelector

//
// Events
//

namespace OnAccessibilityEvent {

extern const char kEventName[];  // "automationInternal.onAccessibilityEvent"

std::unique_ptr<base::ListValue> Create(const AXEventParams& update);
}  // namespace OnAccessibilityEvent

namespace OnAccessibilityTreeDestroyed {

extern const char kEventName[];  // "automationInternal.onAccessibilityTreeDestroyed"

std::unique_ptr<base::ListValue> Create(const std::string& tree_id);
}  // namespace OnAccessibilityTreeDestroyed

namespace OnGetTextLocationResult {

extern const char kEventName[];  // "automationInternal.onGetTextLocationResult"

std::unique_ptr<base::ListValue> Create(const AXTextLocationParams& params);
}  // namespace OnGetTextLocationResult

namespace OnTreeChange {

extern const char kEventName[];  // "automationInternal.onTreeChange"

std::unique_ptr<base::ListValue> Create(int observer_id, const std::string& tree_id, int node_id, const std::string& change_type);
}  // namespace OnTreeChange

namespace OnChildTreeID {

extern const char kEventName[];  // "automationInternal.onChildTreeID"

std::unique_ptr<base::ListValue> Create(const std::string& tree_id);
}  // namespace OnChildTreeID

namespace OnNodesRemoved {

extern const char kEventName[];  // "automationInternal.onNodesRemoved"

std::unique_ptr<base::ListValue> Create(const std::string& tree_id, const std::vector<int>& node_i_ds);
}  // namespace OnNodesRemoved

namespace OnAccessibilityTreeSerializationError {

extern const char kEventName[];  // "automationInternal.onAccessibilityTreeSerializationError"

std::unique_ptr<base::ListValue> Create(const std::string& tree_id);
}  // namespace OnAccessibilityTreeSerializationError

namespace OnActionResult {

extern const char kEventName[];  // "automationInternal.onActionResult"

std::unique_ptr<base::ListValue> Create(const std::string& tree_id, int request_id, bool result);
}  // namespace OnActionResult

}  // namespace automation_internal
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_AUTOMATION_INTERNAL_H__
