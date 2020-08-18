// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_headless_experimental.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_headless_experimental.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace headless_experimental {

std::unique_ptr<ScreenshotParams> ScreenshotParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ScreenshotParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ScreenshotParams> result(new ScreenshotParams());
  errors->Push();
  errors->SetName("ScreenshotParams");
  const base::Value* format_value = value.FindKey("format");
  if (format_value) {
    errors->SetName("format");
    result->format_ = internal::FromValue<::headless::headless_experimental::ScreenshotParamsFormat>::Parse(*format_value, errors);
  }
  const base::Value* quality_value = value.FindKey("quality");
  if (quality_value) {
    errors->SetName("quality");
    result->quality_ = internal::FromValue<int>::Parse(*quality_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ScreenshotParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (format_)
    result->Set("format", internal::ToValue(format_.value()));
  if (quality_)
    result->Set("quality", internal::ToValue(quality_.value()));
  return std::move(result);
}

std::unique_ptr<ScreenshotParams> ScreenshotParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ScreenshotParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BeginFrameParams> BeginFrameParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BeginFrameParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BeginFrameParams> result(new BeginFrameParams());
  errors->Push();
  errors->SetName("BeginFrameParams");
  const base::Value* frame_time_ticks_value = value.FindKey("frameTimeTicks");
  if (frame_time_ticks_value) {
    errors->SetName("frameTimeTicks");
    result->frame_time_ticks_ = internal::FromValue<double>::Parse(*frame_time_ticks_value, errors);
  }
  const base::Value* interval_value = value.FindKey("interval");
  if (interval_value) {
    errors->SetName("interval");
    result->interval_ = internal::FromValue<double>::Parse(*interval_value, errors);
  }
  const base::Value* no_display_updates_value = value.FindKey("noDisplayUpdates");
  if (no_display_updates_value) {
    errors->SetName("noDisplayUpdates");
    result->no_display_updates_ = internal::FromValue<bool>::Parse(*no_display_updates_value, errors);
  }
  const base::Value* screenshot_value = value.FindKey("screenshot");
  if (screenshot_value) {
    errors->SetName("screenshot");
    result->screenshot_ = internal::FromValue<::headless::headless_experimental::ScreenshotParams>::Parse(*screenshot_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BeginFrameParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (frame_time_ticks_)
    result->Set("frameTimeTicks", internal::ToValue(frame_time_ticks_.value()));
  if (interval_)
    result->Set("interval", internal::ToValue(interval_.value()));
  if (no_display_updates_)
    result->Set("noDisplayUpdates", internal::ToValue(no_display_updates_.value()));
  if (screenshot_)
    result->Set("screenshot", internal::ToValue(*screenshot_.value()));
  return std::move(result);
}

std::unique_ptr<BeginFrameParams> BeginFrameParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BeginFrameParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BeginFrameResult> BeginFrameResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BeginFrameResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BeginFrameResult> result(new BeginFrameResult());
  errors->Push();
  errors->SetName("BeginFrameResult");
  const base::Value* has_damage_value = value.FindKey("hasDamage");
  if (has_damage_value) {
    errors->SetName("hasDamage");
    result->has_damage_ = internal::FromValue<bool>::Parse(*has_damage_value, errors);
  } else {
    errors->AddError("required property missing: hasDamage");
  }
  const base::Value* screenshot_data_value = value.FindKey("screenshotData");
  if (screenshot_data_value) {
    errors->SetName("screenshotData");
    result->screenshot_data_ = internal::FromValue<protocol::Binary>::Parse(*screenshot_data_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BeginFrameResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("hasDamage", internal::ToValue(has_damage_));
  if (screenshot_data_)
    result->Set("screenshotData", internal::ToValue(screenshot_data_.value()));
  return std::move(result);
}

std::unique_ptr<BeginFrameResult> BeginFrameResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BeginFrameResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableParams> DisableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableParams> result(new DisableParams());
  errors->Push();
  errors->SetName("DisableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableParams> DisableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableResult> DisableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableResult> result(new DisableResult());
  errors->Push();
  errors->SetName("DisableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableResult> DisableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableParams> EnableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableParams> result(new EnableParams());
  errors->Push();
  errors->SetName("EnableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableParams> EnableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableResult> EnableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableResult> result(new EnableResult());
  errors->Push();
  errors->SetName("EnableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableResult> EnableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NeedsBeginFramesChangedParams> NeedsBeginFramesChangedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NeedsBeginFramesChangedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NeedsBeginFramesChangedParams> result(new NeedsBeginFramesChangedParams());
  errors->Push();
  errors->SetName("NeedsBeginFramesChangedParams");
  const base::Value* needs_begin_frames_value = value.FindKey("needsBeginFrames");
  if (needs_begin_frames_value) {
    errors->SetName("needsBeginFrames");
    result->needs_begin_frames_ = internal::FromValue<bool>::Parse(*needs_begin_frames_value, errors);
  } else {
    errors->AddError("required property missing: needsBeginFrames");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NeedsBeginFramesChangedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("needsBeginFrames", internal::ToValue(needs_begin_frames_));
  return std::move(result);
}

std::unique_ptr<NeedsBeginFramesChangedParams> NeedsBeginFramesChangedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NeedsBeginFramesChangedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace headless_experimental
}  // namespace headless
