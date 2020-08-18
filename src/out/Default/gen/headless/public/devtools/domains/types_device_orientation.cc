// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_device_orientation.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_device_orientation.h"

namespace headless {

namespace device_orientation {

std::unique_ptr<ClearDeviceOrientationOverrideParams> ClearDeviceOrientationOverrideParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearDeviceOrientationOverrideParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearDeviceOrientationOverrideParams> result(new ClearDeviceOrientationOverrideParams());
  errors->Push();
  errors->SetName("ClearDeviceOrientationOverrideParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearDeviceOrientationOverrideParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearDeviceOrientationOverrideParams> ClearDeviceOrientationOverrideParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearDeviceOrientationOverrideParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearDeviceOrientationOverrideResult> ClearDeviceOrientationOverrideResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearDeviceOrientationOverrideResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearDeviceOrientationOverrideResult> result(new ClearDeviceOrientationOverrideResult());
  errors->Push();
  errors->SetName("ClearDeviceOrientationOverrideResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearDeviceOrientationOverrideResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearDeviceOrientationOverrideResult> ClearDeviceOrientationOverrideResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearDeviceOrientationOverrideResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDeviceOrientationOverrideParams> SetDeviceOrientationOverrideParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDeviceOrientationOverrideParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDeviceOrientationOverrideParams> result(new SetDeviceOrientationOverrideParams());
  errors->Push();
  errors->SetName("SetDeviceOrientationOverrideParams");
  const base::Value* alpha_value = value.FindKey("alpha");
  if (alpha_value) {
    errors->SetName("alpha");
    result->alpha_ = internal::FromValue<double>::Parse(*alpha_value, errors);
  } else {
    errors->AddError("required property missing: alpha");
  }
  const base::Value* beta_value = value.FindKey("beta");
  if (beta_value) {
    errors->SetName("beta");
    result->beta_ = internal::FromValue<double>::Parse(*beta_value, errors);
  } else {
    errors->AddError("required property missing: beta");
  }
  const base::Value* gamma_value = value.FindKey("gamma");
  if (gamma_value) {
    errors->SetName("gamma");
    result->gamma_ = internal::FromValue<double>::Parse(*gamma_value, errors);
  } else {
    errors->AddError("required property missing: gamma");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDeviceOrientationOverrideParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("alpha", internal::ToValue(alpha_));
  result->Set("beta", internal::ToValue(beta_));
  result->Set("gamma", internal::ToValue(gamma_));
  return std::move(result);
}

std::unique_ptr<SetDeviceOrientationOverrideParams> SetDeviceOrientationOverrideParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDeviceOrientationOverrideParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDeviceOrientationOverrideResult> SetDeviceOrientationOverrideResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDeviceOrientationOverrideResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDeviceOrientationOverrideResult> result(new SetDeviceOrientationOverrideResult());
  errors->Push();
  errors->SetName("SetDeviceOrientationOverrideResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDeviceOrientationOverrideResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetDeviceOrientationOverrideResult> SetDeviceOrientationOverrideResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDeviceOrientationOverrideResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace device_orientation
}  // namespace headless
