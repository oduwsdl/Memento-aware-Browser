// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/input.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace input {

ExperimentalDomain* Domain::GetExperimental() {
  return static_cast<ExperimentalDomain*>(this);
}


void Domain::DispatchKeyEvent(std::unique_ptr<DispatchKeyEventParams> params, base::OnceCallback<void(std::unique_ptr<DispatchKeyEventResult>)> callback) {
  dispatcher_->SendMessage("Input.dispatchKeyEvent", params->Serialize(), base::BindOnce(&Domain::HandleDispatchKeyEventResponse, std::move(callback)));
}

void Domain::DispatchKeyEvent(::headless::input::DispatchKeyEventType type, base::OnceClosure callback) {
  std::unique_ptr<DispatchKeyEventParams> params = DispatchKeyEventParams::Builder()
      .SetType(std::move(type))
      .Build();
  dispatcher_->SendMessage("Input.dispatchKeyEvent", params->Serialize(), std::move(callback));
}
void Domain::DispatchKeyEvent(std::unique_ptr<DispatchKeyEventParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Input.dispatchKeyEvent", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::InsertText(std::unique_ptr<InsertTextParams> params, base::OnceCallback<void(std::unique_ptr<InsertTextResult>)> callback) {
  dispatcher_->SendMessage("Input.insertText", params->Serialize(), base::BindOnce(&Domain::HandleInsertTextResponse, std::move(callback)));
}
void Domain::DispatchMouseEvent(std::unique_ptr<DispatchMouseEventParams> params, base::OnceCallback<void(std::unique_ptr<DispatchMouseEventResult>)> callback) {
  dispatcher_->SendMessage("Input.dispatchMouseEvent", params->Serialize(), base::BindOnce(&Domain::HandleDispatchMouseEventResponse, std::move(callback)));
}

void Domain::DispatchMouseEvent(::headless::input::DispatchMouseEventType type, double x, double y, base::OnceClosure callback) {
  std::unique_ptr<DispatchMouseEventParams> params = DispatchMouseEventParams::Builder()
      .SetType(std::move(type))
      .SetX(std::move(x))
      .SetY(std::move(y))
      .Build();
  dispatcher_->SendMessage("Input.dispatchMouseEvent", params->Serialize(), std::move(callback));
}
void Domain::DispatchMouseEvent(std::unique_ptr<DispatchMouseEventParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Input.dispatchMouseEvent", params->Serialize(), std::move(callback));
}
void Domain::DispatchTouchEvent(std::unique_ptr<DispatchTouchEventParams> params, base::OnceCallback<void(std::unique_ptr<DispatchTouchEventResult>)> callback) {
  dispatcher_->SendMessage("Input.dispatchTouchEvent", params->Serialize(), base::BindOnce(&Domain::HandleDispatchTouchEventResponse, std::move(callback)));
}

void Domain::DispatchTouchEvent(::headless::input::DispatchTouchEventType type, std::vector<std::unique_ptr<::headless::input::TouchPoint>> touch_points, base::OnceClosure callback) {
  std::unique_ptr<DispatchTouchEventParams> params = DispatchTouchEventParams::Builder()
      .SetType(std::move(type))
      .SetTouchPoints(std::move(touch_points))
      .Build();
  dispatcher_->SendMessage("Input.dispatchTouchEvent", params->Serialize(), std::move(callback));
}
void Domain::DispatchTouchEvent(std::unique_ptr<DispatchTouchEventParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Input.dispatchTouchEvent", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::EmulateTouchFromMouseEvent(std::unique_ptr<EmulateTouchFromMouseEventParams> params, base::OnceCallback<void(std::unique_ptr<EmulateTouchFromMouseEventResult>)> callback) {
  dispatcher_->SendMessage("Input.emulateTouchFromMouseEvent", params->Serialize(), base::BindOnce(&Domain::HandleEmulateTouchFromMouseEventResponse, std::move(callback)));
}
void Domain::SetIgnoreInputEvents(std::unique_ptr<SetIgnoreInputEventsParams> params, base::OnceCallback<void(std::unique_ptr<SetIgnoreInputEventsResult>)> callback) {
  dispatcher_->SendMessage("Input.setIgnoreInputEvents", params->Serialize(), base::BindOnce(&Domain::HandleSetIgnoreInputEventsResponse, std::move(callback)));
}

void Domain::SetIgnoreInputEvents(bool ignore, base::OnceClosure callback) {
  std::unique_ptr<SetIgnoreInputEventsParams> params = SetIgnoreInputEventsParams::Builder()
      .SetIgnore(std::move(ignore))
      .Build();
  dispatcher_->SendMessage("Input.setIgnoreInputEvents", params->Serialize(), std::move(callback));
}
void Domain::SetIgnoreInputEvents(std::unique_ptr<SetIgnoreInputEventsParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Input.setIgnoreInputEvents", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::SynthesizePinchGesture(std::unique_ptr<SynthesizePinchGestureParams> params, base::OnceCallback<void(std::unique_ptr<SynthesizePinchGestureResult>)> callback) {
  dispatcher_->SendMessage("Input.synthesizePinchGesture", params->Serialize(), base::BindOnce(&Domain::HandleSynthesizePinchGestureResponse, std::move(callback)));
}
void ExperimentalDomain::SynthesizeScrollGesture(std::unique_ptr<SynthesizeScrollGestureParams> params, base::OnceCallback<void(std::unique_ptr<SynthesizeScrollGestureResult>)> callback) {
  dispatcher_->SendMessage("Input.synthesizeScrollGesture", params->Serialize(), base::BindOnce(&Domain::HandleSynthesizeScrollGestureResponse, std::move(callback)));
}
void ExperimentalDomain::SynthesizeTapGesture(std::unique_ptr<SynthesizeTapGestureParams> params, base::OnceCallback<void(std::unique_ptr<SynthesizeTapGestureResult>)> callback) {
  dispatcher_->SendMessage("Input.synthesizeTapGesture", params->Serialize(), base::BindOnce(&Domain::HandleSynthesizeTapGestureResponse, std::move(callback)));
}


// static
void Domain::HandleDispatchKeyEventResponse(base::OnceCallback<void(std::unique_ptr<DispatchKeyEventResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DispatchKeyEventResult> result = DispatchKeyEventResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleInsertTextResponse(base::OnceCallback<void(std::unique_ptr<InsertTextResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<InsertTextResult> result = InsertTextResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleDispatchMouseEventResponse(base::OnceCallback<void(std::unique_ptr<DispatchMouseEventResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DispatchMouseEventResult> result = DispatchMouseEventResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleDispatchTouchEventResponse(base::OnceCallback<void(std::unique_ptr<DispatchTouchEventResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DispatchTouchEventResult> result = DispatchTouchEventResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleEmulateTouchFromMouseEventResponse(base::OnceCallback<void(std::unique_ptr<EmulateTouchFromMouseEventResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<EmulateTouchFromMouseEventResult> result = EmulateTouchFromMouseEventResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetIgnoreInputEventsResponse(base::OnceCallback<void(std::unique_ptr<SetIgnoreInputEventsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetIgnoreInputEventsResult> result = SetIgnoreInputEventsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSynthesizePinchGestureResponse(base::OnceCallback<void(std::unique_ptr<SynthesizePinchGestureResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SynthesizePinchGestureResult> result = SynthesizePinchGestureResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSynthesizeScrollGestureResponse(base::OnceCallback<void(std::unique_ptr<SynthesizeScrollGestureResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SynthesizeScrollGestureResult> result = SynthesizeScrollGestureResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSynthesizeTapGestureResponse(base::OnceCallback<void(std::unique_ptr<SynthesizeTapGestureResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SynthesizeTapGestureResult> result = SynthesizeTapGestureResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

Domain::Domain(internal::MessageDispatcher* dispatcher)
    : dispatcher_(dispatcher) {
}

Domain::~Domain() {}

ExperimentalDomain::ExperimentalDomain(internal::MessageDispatcher* dispatcher)
    : Domain(dispatcher) {}

ExperimentalDomain::~ExperimentalDomain() {}


}  // namespace input

} // namespace headless
