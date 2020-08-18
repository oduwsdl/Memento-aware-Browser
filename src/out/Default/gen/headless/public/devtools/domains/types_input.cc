// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_input.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_input.h"

namespace headless {

namespace input {

std::unique_ptr<TouchPoint> TouchPoint::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TouchPoint");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TouchPoint> result(new TouchPoint());
  errors->Push();
  errors->SetName("TouchPoint");
  const base::Value* x_value = value.FindKey("x");
  if (x_value) {
    errors->SetName("x");
    result->x_ = internal::FromValue<double>::Parse(*x_value, errors);
  } else {
    errors->AddError("required property missing: x");
  }
  const base::Value* y_value = value.FindKey("y");
  if (y_value) {
    errors->SetName("y");
    result->y_ = internal::FromValue<double>::Parse(*y_value, errors);
  } else {
    errors->AddError("required property missing: y");
  }
  const base::Value* radiusx_value = value.FindKey("radiusX");
  if (radiusx_value) {
    errors->SetName("radiusX");
    result->radiusx_ = internal::FromValue<double>::Parse(*radiusx_value, errors);
  }
  const base::Value* radiusy_value = value.FindKey("radiusY");
  if (radiusy_value) {
    errors->SetName("radiusY");
    result->radiusy_ = internal::FromValue<double>::Parse(*radiusy_value, errors);
  }
  const base::Value* rotation_angle_value = value.FindKey("rotationAngle");
  if (rotation_angle_value) {
    errors->SetName("rotationAngle");
    result->rotation_angle_ = internal::FromValue<double>::Parse(*rotation_angle_value, errors);
  }
  const base::Value* force_value = value.FindKey("force");
  if (force_value) {
    errors->SetName("force");
    result->force_ = internal::FromValue<double>::Parse(*force_value, errors);
  }
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<double>::Parse(*id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TouchPoint::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("x", internal::ToValue(x_));
  result->Set("y", internal::ToValue(y_));
  if (radiusx_)
    result->Set("radiusX", internal::ToValue(radiusx_.value()));
  if (radiusy_)
    result->Set("radiusY", internal::ToValue(radiusy_.value()));
  if (rotation_angle_)
    result->Set("rotationAngle", internal::ToValue(rotation_angle_.value()));
  if (force_)
    result->Set("force", internal::ToValue(force_.value()));
  if (id_)
    result->Set("id", internal::ToValue(id_.value()));
  return std::move(result);
}

std::unique_ptr<TouchPoint> TouchPoint::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TouchPoint> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DispatchKeyEventParams> DispatchKeyEventParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DispatchKeyEventParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DispatchKeyEventParams> result(new DispatchKeyEventParams());
  errors->Push();
  errors->SetName("DispatchKeyEventParams");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::input::DispatchKeyEventType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* modifiers_value = value.FindKey("modifiers");
  if (modifiers_value) {
    errors->SetName("modifiers");
    result->modifiers_ = internal::FromValue<int>::Parse(*modifiers_value, errors);
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  }
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  }
  const base::Value* unmodified_text_value = value.FindKey("unmodifiedText");
  if (unmodified_text_value) {
    errors->SetName("unmodifiedText");
    result->unmodified_text_ = internal::FromValue<std::string>::Parse(*unmodified_text_value, errors);
  }
  const base::Value* key_identifier_value = value.FindKey("keyIdentifier");
  if (key_identifier_value) {
    errors->SetName("keyIdentifier");
    result->key_identifier_ = internal::FromValue<std::string>::Parse(*key_identifier_value, errors);
  }
  const base::Value* code_value = value.FindKey("code");
  if (code_value) {
    errors->SetName("code");
    result->code_ = internal::FromValue<std::string>::Parse(*code_value, errors);
  }
  const base::Value* key_value = value.FindKey("key");
  if (key_value) {
    errors->SetName("key");
    result->key_ = internal::FromValue<std::string>::Parse(*key_value, errors);
  }
  const base::Value* windows_virtual_key_code_value = value.FindKey("windowsVirtualKeyCode");
  if (windows_virtual_key_code_value) {
    errors->SetName("windowsVirtualKeyCode");
    result->windows_virtual_key_code_ = internal::FromValue<int>::Parse(*windows_virtual_key_code_value, errors);
  }
  const base::Value* native_virtual_key_code_value = value.FindKey("nativeVirtualKeyCode");
  if (native_virtual_key_code_value) {
    errors->SetName("nativeVirtualKeyCode");
    result->native_virtual_key_code_ = internal::FromValue<int>::Parse(*native_virtual_key_code_value, errors);
  }
  const base::Value* auto_repeat_value = value.FindKey("autoRepeat");
  if (auto_repeat_value) {
    errors->SetName("autoRepeat");
    result->auto_repeat_ = internal::FromValue<bool>::Parse(*auto_repeat_value, errors);
  }
  const base::Value* is_keypad_value = value.FindKey("isKeypad");
  if (is_keypad_value) {
    errors->SetName("isKeypad");
    result->is_keypad_ = internal::FromValue<bool>::Parse(*is_keypad_value, errors);
  }
  const base::Value* is_system_key_value = value.FindKey("isSystemKey");
  if (is_system_key_value) {
    errors->SetName("isSystemKey");
    result->is_system_key_ = internal::FromValue<bool>::Parse(*is_system_key_value, errors);
  }
  const base::Value* location_value = value.FindKey("location");
  if (location_value) {
    errors->SetName("location");
    result->location_ = internal::FromValue<int>::Parse(*location_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DispatchKeyEventParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  if (modifiers_)
    result->Set("modifiers", internal::ToValue(modifiers_.value()));
  if (timestamp_)
    result->Set("timestamp", internal::ToValue(timestamp_.value()));
  if (text_)
    result->Set("text", internal::ToValue(text_.value()));
  if (unmodified_text_)
    result->Set("unmodifiedText", internal::ToValue(unmodified_text_.value()));
  if (key_identifier_)
    result->Set("keyIdentifier", internal::ToValue(key_identifier_.value()));
  if (code_)
    result->Set("code", internal::ToValue(code_.value()));
  if (key_)
    result->Set("key", internal::ToValue(key_.value()));
  if (windows_virtual_key_code_)
    result->Set("windowsVirtualKeyCode", internal::ToValue(windows_virtual_key_code_.value()));
  if (native_virtual_key_code_)
    result->Set("nativeVirtualKeyCode", internal::ToValue(native_virtual_key_code_.value()));
  if (auto_repeat_)
    result->Set("autoRepeat", internal::ToValue(auto_repeat_.value()));
  if (is_keypad_)
    result->Set("isKeypad", internal::ToValue(is_keypad_.value()));
  if (is_system_key_)
    result->Set("isSystemKey", internal::ToValue(is_system_key_.value()));
  if (location_)
    result->Set("location", internal::ToValue(location_.value()));
  return std::move(result);
}

std::unique_ptr<DispatchKeyEventParams> DispatchKeyEventParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DispatchKeyEventParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DispatchKeyEventResult> DispatchKeyEventResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DispatchKeyEventResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DispatchKeyEventResult> result(new DispatchKeyEventResult());
  errors->Push();
  errors->SetName("DispatchKeyEventResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DispatchKeyEventResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DispatchKeyEventResult> DispatchKeyEventResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DispatchKeyEventResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InsertTextParams> InsertTextParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InsertTextParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InsertTextParams> result(new InsertTextParams());
  errors->Push();
  errors->SetName("InsertTextParams");
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InsertTextParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("text", internal::ToValue(text_));
  return std::move(result);
}

std::unique_ptr<InsertTextParams> InsertTextParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InsertTextParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InsertTextResult> InsertTextResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InsertTextResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InsertTextResult> result(new InsertTextResult());
  errors->Push();
  errors->SetName("InsertTextResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InsertTextResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<InsertTextResult> InsertTextResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InsertTextResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DispatchMouseEventParams> DispatchMouseEventParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DispatchMouseEventParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DispatchMouseEventParams> result(new DispatchMouseEventParams());
  errors->Push();
  errors->SetName("DispatchMouseEventParams");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::input::DispatchMouseEventType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* x_value = value.FindKey("x");
  if (x_value) {
    errors->SetName("x");
    result->x_ = internal::FromValue<double>::Parse(*x_value, errors);
  } else {
    errors->AddError("required property missing: x");
  }
  const base::Value* y_value = value.FindKey("y");
  if (y_value) {
    errors->SetName("y");
    result->y_ = internal::FromValue<double>::Parse(*y_value, errors);
  } else {
    errors->AddError("required property missing: y");
  }
  const base::Value* modifiers_value = value.FindKey("modifiers");
  if (modifiers_value) {
    errors->SetName("modifiers");
    result->modifiers_ = internal::FromValue<int>::Parse(*modifiers_value, errors);
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  }
  const base::Value* button_value = value.FindKey("button");
  if (button_value) {
    errors->SetName("button");
    result->button_ = internal::FromValue<::headless::input::MouseButton>::Parse(*button_value, errors);
  }
  const base::Value* buttons_value = value.FindKey("buttons");
  if (buttons_value) {
    errors->SetName("buttons");
    result->buttons_ = internal::FromValue<int>::Parse(*buttons_value, errors);
  }
  const base::Value* click_count_value = value.FindKey("clickCount");
  if (click_count_value) {
    errors->SetName("clickCount");
    result->click_count_ = internal::FromValue<int>::Parse(*click_count_value, errors);
  }
  const base::Value* deltax_value = value.FindKey("deltaX");
  if (deltax_value) {
    errors->SetName("deltaX");
    result->deltax_ = internal::FromValue<double>::Parse(*deltax_value, errors);
  }
  const base::Value* deltay_value = value.FindKey("deltaY");
  if (deltay_value) {
    errors->SetName("deltaY");
    result->deltay_ = internal::FromValue<double>::Parse(*deltay_value, errors);
  }
  const base::Value* pointer_type_value = value.FindKey("pointerType");
  if (pointer_type_value) {
    errors->SetName("pointerType");
    result->pointer_type_ = internal::FromValue<::headless::input::DispatchMouseEventPointerType>::Parse(*pointer_type_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DispatchMouseEventParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  result->Set("x", internal::ToValue(x_));
  result->Set("y", internal::ToValue(y_));
  if (modifiers_)
    result->Set("modifiers", internal::ToValue(modifiers_.value()));
  if (timestamp_)
    result->Set("timestamp", internal::ToValue(timestamp_.value()));
  if (button_)
    result->Set("button", internal::ToValue(button_.value()));
  if (buttons_)
    result->Set("buttons", internal::ToValue(buttons_.value()));
  if (click_count_)
    result->Set("clickCount", internal::ToValue(click_count_.value()));
  if (deltax_)
    result->Set("deltaX", internal::ToValue(deltax_.value()));
  if (deltay_)
    result->Set("deltaY", internal::ToValue(deltay_.value()));
  if (pointer_type_)
    result->Set("pointerType", internal::ToValue(pointer_type_.value()));
  return std::move(result);
}

std::unique_ptr<DispatchMouseEventParams> DispatchMouseEventParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DispatchMouseEventParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DispatchMouseEventResult> DispatchMouseEventResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DispatchMouseEventResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DispatchMouseEventResult> result(new DispatchMouseEventResult());
  errors->Push();
  errors->SetName("DispatchMouseEventResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DispatchMouseEventResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DispatchMouseEventResult> DispatchMouseEventResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DispatchMouseEventResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DispatchTouchEventParams> DispatchTouchEventParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DispatchTouchEventParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DispatchTouchEventParams> result(new DispatchTouchEventParams());
  errors->Push();
  errors->SetName("DispatchTouchEventParams");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::input::DispatchTouchEventType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* touch_points_value = value.FindKey("touchPoints");
  if (touch_points_value) {
    errors->SetName("touchPoints");
    result->touch_points_ = internal::FromValue<std::vector<std::unique_ptr<::headless::input::TouchPoint>>>::Parse(*touch_points_value, errors);
  } else {
    errors->AddError("required property missing: touchPoints");
  }
  const base::Value* modifiers_value = value.FindKey("modifiers");
  if (modifiers_value) {
    errors->SetName("modifiers");
    result->modifiers_ = internal::FromValue<int>::Parse(*modifiers_value, errors);
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DispatchTouchEventParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  result->Set("touchPoints", internal::ToValue(touch_points_));
  if (modifiers_)
    result->Set("modifiers", internal::ToValue(modifiers_.value()));
  if (timestamp_)
    result->Set("timestamp", internal::ToValue(timestamp_.value()));
  return std::move(result);
}

std::unique_ptr<DispatchTouchEventParams> DispatchTouchEventParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DispatchTouchEventParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DispatchTouchEventResult> DispatchTouchEventResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DispatchTouchEventResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DispatchTouchEventResult> result(new DispatchTouchEventResult());
  errors->Push();
  errors->SetName("DispatchTouchEventResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DispatchTouchEventResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DispatchTouchEventResult> DispatchTouchEventResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DispatchTouchEventResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EmulateTouchFromMouseEventParams> EmulateTouchFromMouseEventParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EmulateTouchFromMouseEventParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EmulateTouchFromMouseEventParams> result(new EmulateTouchFromMouseEventParams());
  errors->Push();
  errors->SetName("EmulateTouchFromMouseEventParams");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::input::EmulateTouchFromMouseEventType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* x_value = value.FindKey("x");
  if (x_value) {
    errors->SetName("x");
    result->x_ = internal::FromValue<int>::Parse(*x_value, errors);
  } else {
    errors->AddError("required property missing: x");
  }
  const base::Value* y_value = value.FindKey("y");
  if (y_value) {
    errors->SetName("y");
    result->y_ = internal::FromValue<int>::Parse(*y_value, errors);
  } else {
    errors->AddError("required property missing: y");
  }
  const base::Value* button_value = value.FindKey("button");
  if (button_value) {
    errors->SetName("button");
    result->button_ = internal::FromValue<::headless::input::MouseButton>::Parse(*button_value, errors);
  } else {
    errors->AddError("required property missing: button");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  }
  const base::Value* deltax_value = value.FindKey("deltaX");
  if (deltax_value) {
    errors->SetName("deltaX");
    result->deltax_ = internal::FromValue<double>::Parse(*deltax_value, errors);
  }
  const base::Value* deltay_value = value.FindKey("deltaY");
  if (deltay_value) {
    errors->SetName("deltaY");
    result->deltay_ = internal::FromValue<double>::Parse(*deltay_value, errors);
  }
  const base::Value* modifiers_value = value.FindKey("modifiers");
  if (modifiers_value) {
    errors->SetName("modifiers");
    result->modifiers_ = internal::FromValue<int>::Parse(*modifiers_value, errors);
  }
  const base::Value* click_count_value = value.FindKey("clickCount");
  if (click_count_value) {
    errors->SetName("clickCount");
    result->click_count_ = internal::FromValue<int>::Parse(*click_count_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EmulateTouchFromMouseEventParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  result->Set("x", internal::ToValue(x_));
  result->Set("y", internal::ToValue(y_));
  result->Set("button", internal::ToValue(button_));
  if (timestamp_)
    result->Set("timestamp", internal::ToValue(timestamp_.value()));
  if (deltax_)
    result->Set("deltaX", internal::ToValue(deltax_.value()));
  if (deltay_)
    result->Set("deltaY", internal::ToValue(deltay_.value()));
  if (modifiers_)
    result->Set("modifiers", internal::ToValue(modifiers_.value()));
  if (click_count_)
    result->Set("clickCount", internal::ToValue(click_count_.value()));
  return std::move(result);
}

std::unique_ptr<EmulateTouchFromMouseEventParams> EmulateTouchFromMouseEventParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EmulateTouchFromMouseEventParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EmulateTouchFromMouseEventResult> EmulateTouchFromMouseEventResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EmulateTouchFromMouseEventResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EmulateTouchFromMouseEventResult> result(new EmulateTouchFromMouseEventResult());
  errors->Push();
  errors->SetName("EmulateTouchFromMouseEventResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EmulateTouchFromMouseEventResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EmulateTouchFromMouseEventResult> EmulateTouchFromMouseEventResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EmulateTouchFromMouseEventResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetIgnoreInputEventsParams> SetIgnoreInputEventsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetIgnoreInputEventsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetIgnoreInputEventsParams> result(new SetIgnoreInputEventsParams());
  errors->Push();
  errors->SetName("SetIgnoreInputEventsParams");
  const base::Value* ignore_value = value.FindKey("ignore");
  if (ignore_value) {
    errors->SetName("ignore");
    result->ignore_ = internal::FromValue<bool>::Parse(*ignore_value, errors);
  } else {
    errors->AddError("required property missing: ignore");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetIgnoreInputEventsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("ignore", internal::ToValue(ignore_));
  return std::move(result);
}

std::unique_ptr<SetIgnoreInputEventsParams> SetIgnoreInputEventsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetIgnoreInputEventsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetIgnoreInputEventsResult> SetIgnoreInputEventsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetIgnoreInputEventsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetIgnoreInputEventsResult> result(new SetIgnoreInputEventsResult());
  errors->Push();
  errors->SetName("SetIgnoreInputEventsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetIgnoreInputEventsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetIgnoreInputEventsResult> SetIgnoreInputEventsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetIgnoreInputEventsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SynthesizePinchGestureParams> SynthesizePinchGestureParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SynthesizePinchGestureParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SynthesizePinchGestureParams> result(new SynthesizePinchGestureParams());
  errors->Push();
  errors->SetName("SynthesizePinchGestureParams");
  const base::Value* x_value = value.FindKey("x");
  if (x_value) {
    errors->SetName("x");
    result->x_ = internal::FromValue<double>::Parse(*x_value, errors);
  } else {
    errors->AddError("required property missing: x");
  }
  const base::Value* y_value = value.FindKey("y");
  if (y_value) {
    errors->SetName("y");
    result->y_ = internal::FromValue<double>::Parse(*y_value, errors);
  } else {
    errors->AddError("required property missing: y");
  }
  const base::Value* scale_factor_value = value.FindKey("scaleFactor");
  if (scale_factor_value) {
    errors->SetName("scaleFactor");
    result->scale_factor_ = internal::FromValue<double>::Parse(*scale_factor_value, errors);
  } else {
    errors->AddError("required property missing: scaleFactor");
  }
  const base::Value* relative_speed_value = value.FindKey("relativeSpeed");
  if (relative_speed_value) {
    errors->SetName("relativeSpeed");
    result->relative_speed_ = internal::FromValue<int>::Parse(*relative_speed_value, errors);
  }
  const base::Value* gesture_source_type_value = value.FindKey("gestureSourceType");
  if (gesture_source_type_value) {
    errors->SetName("gestureSourceType");
    result->gesture_source_type_ = internal::FromValue<::headless::input::GestureSourceType>::Parse(*gesture_source_type_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SynthesizePinchGestureParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("x", internal::ToValue(x_));
  result->Set("y", internal::ToValue(y_));
  result->Set("scaleFactor", internal::ToValue(scale_factor_));
  if (relative_speed_)
    result->Set("relativeSpeed", internal::ToValue(relative_speed_.value()));
  if (gesture_source_type_)
    result->Set("gestureSourceType", internal::ToValue(gesture_source_type_.value()));
  return std::move(result);
}

std::unique_ptr<SynthesizePinchGestureParams> SynthesizePinchGestureParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SynthesizePinchGestureParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SynthesizePinchGestureResult> SynthesizePinchGestureResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SynthesizePinchGestureResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SynthesizePinchGestureResult> result(new SynthesizePinchGestureResult());
  errors->Push();
  errors->SetName("SynthesizePinchGestureResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SynthesizePinchGestureResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SynthesizePinchGestureResult> SynthesizePinchGestureResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SynthesizePinchGestureResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SynthesizeScrollGestureParams> SynthesizeScrollGestureParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SynthesizeScrollGestureParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SynthesizeScrollGestureParams> result(new SynthesizeScrollGestureParams());
  errors->Push();
  errors->SetName("SynthesizeScrollGestureParams");
  const base::Value* x_value = value.FindKey("x");
  if (x_value) {
    errors->SetName("x");
    result->x_ = internal::FromValue<double>::Parse(*x_value, errors);
  } else {
    errors->AddError("required property missing: x");
  }
  const base::Value* y_value = value.FindKey("y");
  if (y_value) {
    errors->SetName("y");
    result->y_ = internal::FromValue<double>::Parse(*y_value, errors);
  } else {
    errors->AddError("required property missing: y");
  }
  const base::Value* x_distance_value = value.FindKey("xDistance");
  if (x_distance_value) {
    errors->SetName("xDistance");
    result->x_distance_ = internal::FromValue<double>::Parse(*x_distance_value, errors);
  }
  const base::Value* y_distance_value = value.FindKey("yDistance");
  if (y_distance_value) {
    errors->SetName("yDistance");
    result->y_distance_ = internal::FromValue<double>::Parse(*y_distance_value, errors);
  }
  const base::Value* x_overscroll_value = value.FindKey("xOverscroll");
  if (x_overscroll_value) {
    errors->SetName("xOverscroll");
    result->x_overscroll_ = internal::FromValue<double>::Parse(*x_overscroll_value, errors);
  }
  const base::Value* y_overscroll_value = value.FindKey("yOverscroll");
  if (y_overscroll_value) {
    errors->SetName("yOverscroll");
    result->y_overscroll_ = internal::FromValue<double>::Parse(*y_overscroll_value, errors);
  }
  const base::Value* prevent_fling_value = value.FindKey("preventFling");
  if (prevent_fling_value) {
    errors->SetName("preventFling");
    result->prevent_fling_ = internal::FromValue<bool>::Parse(*prevent_fling_value, errors);
  }
  const base::Value* speed_value = value.FindKey("speed");
  if (speed_value) {
    errors->SetName("speed");
    result->speed_ = internal::FromValue<int>::Parse(*speed_value, errors);
  }
  const base::Value* gesture_source_type_value = value.FindKey("gestureSourceType");
  if (gesture_source_type_value) {
    errors->SetName("gestureSourceType");
    result->gesture_source_type_ = internal::FromValue<::headless::input::GestureSourceType>::Parse(*gesture_source_type_value, errors);
  }
  const base::Value* repeat_count_value = value.FindKey("repeatCount");
  if (repeat_count_value) {
    errors->SetName("repeatCount");
    result->repeat_count_ = internal::FromValue<int>::Parse(*repeat_count_value, errors);
  }
  const base::Value* repeat_delay_ms_value = value.FindKey("repeatDelayMs");
  if (repeat_delay_ms_value) {
    errors->SetName("repeatDelayMs");
    result->repeat_delay_ms_ = internal::FromValue<int>::Parse(*repeat_delay_ms_value, errors);
  }
  const base::Value* interaction_marker_name_value = value.FindKey("interactionMarkerName");
  if (interaction_marker_name_value) {
    errors->SetName("interactionMarkerName");
    result->interaction_marker_name_ = internal::FromValue<std::string>::Parse(*interaction_marker_name_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SynthesizeScrollGestureParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("x", internal::ToValue(x_));
  result->Set("y", internal::ToValue(y_));
  if (x_distance_)
    result->Set("xDistance", internal::ToValue(x_distance_.value()));
  if (y_distance_)
    result->Set("yDistance", internal::ToValue(y_distance_.value()));
  if (x_overscroll_)
    result->Set("xOverscroll", internal::ToValue(x_overscroll_.value()));
  if (y_overscroll_)
    result->Set("yOverscroll", internal::ToValue(y_overscroll_.value()));
  if (prevent_fling_)
    result->Set("preventFling", internal::ToValue(prevent_fling_.value()));
  if (speed_)
    result->Set("speed", internal::ToValue(speed_.value()));
  if (gesture_source_type_)
    result->Set("gestureSourceType", internal::ToValue(gesture_source_type_.value()));
  if (repeat_count_)
    result->Set("repeatCount", internal::ToValue(repeat_count_.value()));
  if (repeat_delay_ms_)
    result->Set("repeatDelayMs", internal::ToValue(repeat_delay_ms_.value()));
  if (interaction_marker_name_)
    result->Set("interactionMarkerName", internal::ToValue(interaction_marker_name_.value()));
  return std::move(result);
}

std::unique_ptr<SynthesizeScrollGestureParams> SynthesizeScrollGestureParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SynthesizeScrollGestureParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SynthesizeScrollGestureResult> SynthesizeScrollGestureResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SynthesizeScrollGestureResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SynthesizeScrollGestureResult> result(new SynthesizeScrollGestureResult());
  errors->Push();
  errors->SetName("SynthesizeScrollGestureResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SynthesizeScrollGestureResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SynthesizeScrollGestureResult> SynthesizeScrollGestureResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SynthesizeScrollGestureResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SynthesizeTapGestureParams> SynthesizeTapGestureParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SynthesizeTapGestureParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SynthesizeTapGestureParams> result(new SynthesizeTapGestureParams());
  errors->Push();
  errors->SetName("SynthesizeTapGestureParams");
  const base::Value* x_value = value.FindKey("x");
  if (x_value) {
    errors->SetName("x");
    result->x_ = internal::FromValue<double>::Parse(*x_value, errors);
  } else {
    errors->AddError("required property missing: x");
  }
  const base::Value* y_value = value.FindKey("y");
  if (y_value) {
    errors->SetName("y");
    result->y_ = internal::FromValue<double>::Parse(*y_value, errors);
  } else {
    errors->AddError("required property missing: y");
  }
  const base::Value* duration_value = value.FindKey("duration");
  if (duration_value) {
    errors->SetName("duration");
    result->duration_ = internal::FromValue<int>::Parse(*duration_value, errors);
  }
  const base::Value* tap_count_value = value.FindKey("tapCount");
  if (tap_count_value) {
    errors->SetName("tapCount");
    result->tap_count_ = internal::FromValue<int>::Parse(*tap_count_value, errors);
  }
  const base::Value* gesture_source_type_value = value.FindKey("gestureSourceType");
  if (gesture_source_type_value) {
    errors->SetName("gestureSourceType");
    result->gesture_source_type_ = internal::FromValue<::headless::input::GestureSourceType>::Parse(*gesture_source_type_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SynthesizeTapGestureParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("x", internal::ToValue(x_));
  result->Set("y", internal::ToValue(y_));
  if (duration_)
    result->Set("duration", internal::ToValue(duration_.value()));
  if (tap_count_)
    result->Set("tapCount", internal::ToValue(tap_count_.value()));
  if (gesture_source_type_)
    result->Set("gestureSourceType", internal::ToValue(gesture_source_type_.value()));
  return std::move(result);
}

std::unique_ptr<SynthesizeTapGestureParams> SynthesizeTapGestureParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SynthesizeTapGestureParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SynthesizeTapGestureResult> SynthesizeTapGestureResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SynthesizeTapGestureResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SynthesizeTapGestureResult> result(new SynthesizeTapGestureResult());
  errors->Push();
  errors->SetName("SynthesizeTapGestureResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SynthesizeTapGestureResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SynthesizeTapGestureResult> SynthesizeTapGestureResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SynthesizeTapGestureResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace input
}  // namespace headless
