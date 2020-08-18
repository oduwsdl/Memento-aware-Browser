// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_INPUT_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_INPUT_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_input.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace input {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT Domain {
 public:

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

  // Dispatches a key event to the page.
  void DispatchKeyEvent(std::unique_ptr<DispatchKeyEventParams> params, base::OnceCallback<void(std::unique_ptr<DispatchKeyEventResult>)> callback = base::OnceCallback<void(std::unique_ptr<DispatchKeyEventResult>)>());
  void DispatchKeyEvent(::headless::input::DispatchKeyEventType type, base::OnceClosure callback = base::OnceClosure());
  void DispatchKeyEvent(std::unique_ptr<DispatchKeyEventParams> params, base::OnceClosure callback);

  // Dispatches a mouse event to the page.
  void DispatchMouseEvent(std::unique_ptr<DispatchMouseEventParams> params, base::OnceCallback<void(std::unique_ptr<DispatchMouseEventResult>)> callback = base::OnceCallback<void(std::unique_ptr<DispatchMouseEventResult>)>());
  void DispatchMouseEvent(::headless::input::DispatchMouseEventType type, double x, double y, base::OnceClosure callback = base::OnceClosure());
  void DispatchMouseEvent(std::unique_ptr<DispatchMouseEventParams> params, base::OnceClosure callback);

  // Dispatches a touch event to the page.
  void DispatchTouchEvent(std::unique_ptr<DispatchTouchEventParams> params, base::OnceCallback<void(std::unique_ptr<DispatchTouchEventResult>)> callback = base::OnceCallback<void(std::unique_ptr<DispatchTouchEventResult>)>());
  void DispatchTouchEvent(::headless::input::DispatchTouchEventType type, std::vector<std::unique_ptr<::headless::input::TouchPoint>> touch_points, base::OnceClosure callback = base::OnceClosure());
  void DispatchTouchEvent(std::unique_ptr<DispatchTouchEventParams> params, base::OnceClosure callback);

  // Ignores input events (useful while auditing page).
  void SetIgnoreInputEvents(std::unique_ptr<SetIgnoreInputEventsParams> params, base::OnceCallback<void(std::unique_ptr<SetIgnoreInputEventsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetIgnoreInputEventsResult>)>());
  void SetIgnoreInputEvents(bool ignore, base::OnceClosure callback = base::OnceClosure());
  void SetIgnoreInputEvents(std::unique_ptr<SetIgnoreInputEventsParams> params, base::OnceClosure callback);

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleDispatchKeyEventResponse(base::OnceCallback<void(std::unique_ptr<DispatchKeyEventResult>)> callback, const base::Value& response);
  static void HandleInsertTextResponse(base::OnceCallback<void(std::unique_ptr<InsertTextResult>)> callback, const base::Value& response);
  static void HandleDispatchMouseEventResponse(base::OnceCallback<void(std::unique_ptr<DispatchMouseEventResult>)> callback, const base::Value& response);
  static void HandleDispatchTouchEventResponse(base::OnceCallback<void(std::unique_ptr<DispatchTouchEventResult>)> callback, const base::Value& response);
  static void HandleEmulateTouchFromMouseEventResponse(base::OnceCallback<void(std::unique_ptr<EmulateTouchFromMouseEventResult>)> callback, const base::Value& response);
  static void HandleSetIgnoreInputEventsResponse(base::OnceCallback<void(std::unique_ptr<SetIgnoreInputEventsResult>)> callback, const base::Value& response);
  static void HandleSynthesizePinchGestureResponse(base::OnceCallback<void(std::unique_ptr<SynthesizePinchGestureResult>)> callback, const base::Value& response);
  static void HandleSynthesizeScrollGestureResponse(base::OnceCallback<void(std::unique_ptr<SynthesizeScrollGestureResult>)> callback, const base::Value& response);
  static void HandleSynthesizeTapGestureResponse(base::OnceCallback<void(std::unique_ptr<SynthesizeTapGestureResult>)> callback, const base::Value& response);


  internal::MessageDispatcher* dispatcher_;  // Not owned.

 private:
  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();


  // This method emulates inserting text that doesn't come from a key press,
  // for example an emoji keyboard or an IME.
  void InsertText(std::unique_ptr<InsertTextParams> params, base::OnceCallback<void(std::unique_ptr<InsertTextResult>)> callback = base::OnceCallback<void(std::unique_ptr<InsertTextResult>)>());

  // Emulates touch event from the mouse event parameters.
  void EmulateTouchFromMouseEvent(std::unique_ptr<EmulateTouchFromMouseEventParams> params, base::OnceCallback<void(std::unique_ptr<EmulateTouchFromMouseEventResult>)> callback = base::OnceCallback<void(std::unique_ptr<EmulateTouchFromMouseEventResult>)>());

  // Synthesizes a pinch gesture over a time period by issuing appropriate touch events.
  void SynthesizePinchGesture(std::unique_ptr<SynthesizePinchGestureParams> params, base::OnceCallback<void(std::unique_ptr<SynthesizePinchGestureResult>)> callback = base::OnceCallback<void(std::unique_ptr<SynthesizePinchGestureResult>)>());

  // Synthesizes a scroll gesture over a time period by issuing appropriate touch events.
  void SynthesizeScrollGesture(std::unique_ptr<SynthesizeScrollGestureParams> params, base::OnceCallback<void(std::unique_ptr<SynthesizeScrollGestureResult>)> callback = base::OnceCallback<void(std::unique_ptr<SynthesizeScrollGestureResult>)>());

  // Synthesizes a tap gesture over a time period by issuing appropriate touch events.
  void SynthesizeTapGesture(std::unique_ptr<SynthesizeTapGestureParams> params, base::OnceCallback<void(std::unique_ptr<SynthesizeTapGestureResult>)> callback = base::OnceCallback<void(std::unique_ptr<SynthesizeTapGestureResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace input
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_INPUT_H_
