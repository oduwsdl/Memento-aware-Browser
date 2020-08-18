// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/debugger.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace debugger {

ExperimentalDomain* Domain::GetExperimental() {
  return static_cast<ExperimentalDomain*>(this);
}

void Domain::AddObserver(Observer* observer) {
  RegisterEventHandlersIfNeeded();
  observers_.AddObserver(observer);
}

void Domain::RemoveObserver(Observer* observer) {
  observers_.RemoveObserver(observer);
}

void Domain::RegisterEventHandlersIfNeeded() {
  if (event_handlers_registered_)
    return;
  event_handlers_registered_ = true;
  dispatcher_->RegisterEventHandler(
      "Debugger.breakpointResolved",
      base::BindRepeating(&Domain::DispatchBreakpointResolvedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Debugger.paused",
      base::BindRepeating(&Domain::DispatchPausedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Debugger.resumed",
      base::BindRepeating(&Domain::DispatchResumedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Debugger.scriptFailedToParse",
      base::BindRepeating(&Domain::DispatchScriptFailedToParseEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Debugger.scriptParsed",
      base::BindRepeating(&Domain::DispatchScriptParsedEvent,
                          base::Unretained(this)));
}

void Domain::ContinueToLocation(std::unique_ptr<ContinueToLocationParams> params, base::OnceCallback<void(std::unique_ptr<ContinueToLocationResult>)> callback) {
  dispatcher_->SendMessage("Debugger.continueToLocation", params->Serialize(), base::BindOnce(&Domain::HandleContinueToLocationResponse, std::move(callback)));
}

void Domain::ContinueToLocation(std::unique_ptr<::headless::debugger::Location> location, base::OnceClosure callback) {
  std::unique_ptr<ContinueToLocationParams> params = ContinueToLocationParams::Builder()
      .SetLocation(std::move(location))
      .Build();
  dispatcher_->SendMessage("Debugger.continueToLocation", params->Serialize(), std::move(callback));
}
void Domain::ContinueToLocation(std::unique_ptr<ContinueToLocationParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.continueToLocation", params->Serialize(), std::move(callback));
}
void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("Debugger.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}

void Domain::Disable(base::OnceClosure callback) {
  std::unique_ptr<DisableParams> params = DisableParams::Builder()
      .Build();
  dispatcher_->SendMessage("Debugger.disable", params->Serialize(), std::move(callback));
}
void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.disable", params->Serialize(), std::move(callback));
}
void Domain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("Debugger.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}

void Domain::Enable(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  std::unique_ptr<EnableParams> params = EnableParams::Builder()
      .Build();
dispatcher_->SendMessage("Debugger.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}
void Domain::EvaluateOnCallFrame(std::unique_ptr<EvaluateOnCallFrameParams> params, base::OnceCallback<void(std::unique_ptr<EvaluateOnCallFrameResult>)> callback) {
  dispatcher_->SendMessage("Debugger.evaluateOnCallFrame", params->Serialize(), base::BindOnce(&Domain::HandleEvaluateOnCallFrameResponse, std::move(callback)));
}

void Domain::EvaluateOnCallFrame(const std::string& call_frame_id, const std::string& expression, base::OnceCallback<void(std::unique_ptr<EvaluateOnCallFrameResult>)> callback) {
  std::unique_ptr<EvaluateOnCallFrameParams> params = EvaluateOnCallFrameParams::Builder()
      .SetCallFrameId(std::move(call_frame_id))
      .SetExpression(std::move(expression))
      .Build();
dispatcher_->SendMessage("Debugger.evaluateOnCallFrame", params->Serialize(), base::BindOnce(&Domain::HandleEvaluateOnCallFrameResponse, std::move(callback)));
}
void ExperimentalDomain::ExecuteWasmEvaluator(std::unique_ptr<ExecuteWasmEvaluatorParams> params, base::OnceCallback<void(std::unique_ptr<ExecuteWasmEvaluatorResult>)> callback) {
  dispatcher_->SendMessage("Debugger.executeWasmEvaluator", params->Serialize(), base::BindOnce(&Domain::HandleExecuteWasmEvaluatorResponse, std::move(callback)));
}
void Domain::GetPossibleBreakpoints(std::unique_ptr<GetPossibleBreakpointsParams> params, base::OnceCallback<void(std::unique_ptr<GetPossibleBreakpointsResult>)> callback) {
  dispatcher_->SendMessage("Debugger.getPossibleBreakpoints", params->Serialize(), base::BindOnce(&Domain::HandleGetPossibleBreakpointsResponse, std::move(callback)));
}

void Domain::GetPossibleBreakpoints(std::unique_ptr<::headless::debugger::Location> start, base::OnceCallback<void(std::unique_ptr<GetPossibleBreakpointsResult>)> callback) {
  std::unique_ptr<GetPossibleBreakpointsParams> params = GetPossibleBreakpointsParams::Builder()
      .SetStart(std::move(start))
      .Build();
dispatcher_->SendMessage("Debugger.getPossibleBreakpoints", params->Serialize(), base::BindOnce(&Domain::HandleGetPossibleBreakpointsResponse, std::move(callback)));
}
void Domain::GetScriptSource(std::unique_ptr<GetScriptSourceParams> params, base::OnceCallback<void(std::unique_ptr<GetScriptSourceResult>)> callback) {
  dispatcher_->SendMessage("Debugger.getScriptSource", params->Serialize(), base::BindOnce(&Domain::HandleGetScriptSourceResponse, std::move(callback)));
}

void Domain::GetScriptSource(const std::string& script_id, base::OnceCallback<void(std::unique_ptr<GetScriptSourceResult>)> callback) {
  std::unique_ptr<GetScriptSourceParams> params = GetScriptSourceParams::Builder()
      .SetScriptId(std::move(script_id))
      .Build();
dispatcher_->SendMessage("Debugger.getScriptSource", params->Serialize(), base::BindOnce(&Domain::HandleGetScriptSourceResponse, std::move(callback)));
}
void Domain::GetWasmBytecode(std::unique_ptr<GetWasmBytecodeParams> params, base::OnceCallback<void(std::unique_ptr<GetWasmBytecodeResult>)> callback) {
  dispatcher_->SendMessage("Debugger.getWasmBytecode", params->Serialize(), base::BindOnce(&Domain::HandleGetWasmBytecodeResponse, std::move(callback)));
}

void Domain::GetWasmBytecode(const std::string& script_id, base::OnceCallback<void(std::unique_ptr<GetWasmBytecodeResult>)> callback) {
  std::unique_ptr<GetWasmBytecodeParams> params = GetWasmBytecodeParams::Builder()
      .SetScriptId(std::move(script_id))
      .Build();
dispatcher_->SendMessage("Debugger.getWasmBytecode", params->Serialize(), base::BindOnce(&Domain::HandleGetWasmBytecodeResponse, std::move(callback)));
}
void ExperimentalDomain::GetStackTrace(std::unique_ptr<GetStackTraceParams> params, base::OnceCallback<void(std::unique_ptr<GetStackTraceResult>)> callback) {
  dispatcher_->SendMessage("Debugger.getStackTrace", params->Serialize(), base::BindOnce(&Domain::HandleGetStackTraceResponse, std::move(callback)));
}
void Domain::Pause(std::unique_ptr<PauseParams> params, base::OnceCallback<void(std::unique_ptr<PauseResult>)> callback) {
  dispatcher_->SendMessage("Debugger.pause", params->Serialize(), base::BindOnce(&Domain::HandlePauseResponse, std::move(callback)));
}

void Domain::Pause(base::OnceClosure callback) {
  std::unique_ptr<PauseParams> params = PauseParams::Builder()
      .Build();
  dispatcher_->SendMessage("Debugger.pause", params->Serialize(), std::move(callback));
}
void Domain::Pause(std::unique_ptr<PauseParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.pause", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::PauseOnAsyncCall(std::unique_ptr<PauseOnAsyncCallParams> params, base::OnceCallback<void(std::unique_ptr<PauseOnAsyncCallResult>)> callback) {
  dispatcher_->SendMessage("Debugger.pauseOnAsyncCall", params->Serialize(), base::BindOnce(&Domain::HandlePauseOnAsyncCallResponse, std::move(callback)));
}
void Domain::RemoveBreakpoint(std::unique_ptr<RemoveBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<RemoveBreakpointResult>)> callback) {
  dispatcher_->SendMessage("Debugger.removeBreakpoint", params->Serialize(), base::BindOnce(&Domain::HandleRemoveBreakpointResponse, std::move(callback)));
}

void Domain::RemoveBreakpoint(const std::string& breakpoint_id, base::OnceClosure callback) {
  std::unique_ptr<RemoveBreakpointParams> params = RemoveBreakpointParams::Builder()
      .SetBreakpointId(std::move(breakpoint_id))
      .Build();
  dispatcher_->SendMessage("Debugger.removeBreakpoint", params->Serialize(), std::move(callback));
}
void Domain::RemoveBreakpoint(std::unique_ptr<RemoveBreakpointParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.removeBreakpoint", params->Serialize(), std::move(callback));
}
void Domain::RestartFrame(std::unique_ptr<RestartFrameParams> params, base::OnceCallback<void(std::unique_ptr<RestartFrameResult>)> callback) {
  dispatcher_->SendMessage("Debugger.restartFrame", params->Serialize(), base::BindOnce(&Domain::HandleRestartFrameResponse, std::move(callback)));
}

void Domain::RestartFrame(const std::string& call_frame_id, base::OnceCallback<void(std::unique_ptr<RestartFrameResult>)> callback) {
  std::unique_ptr<RestartFrameParams> params = RestartFrameParams::Builder()
      .SetCallFrameId(std::move(call_frame_id))
      .Build();
dispatcher_->SendMessage("Debugger.restartFrame", params->Serialize(), base::BindOnce(&Domain::HandleRestartFrameResponse, std::move(callback)));
}
void Domain::Resume(std::unique_ptr<ResumeParams> params, base::OnceCallback<void(std::unique_ptr<ResumeResult>)> callback) {
  dispatcher_->SendMessage("Debugger.resume", params->Serialize(), base::BindOnce(&Domain::HandleResumeResponse, std::move(callback)));
}

void Domain::Resume(base::OnceClosure callback) {
  std::unique_ptr<ResumeParams> params = ResumeParams::Builder()
      .Build();
  dispatcher_->SendMessage("Debugger.resume", params->Serialize(), std::move(callback));
}
void Domain::Resume(std::unique_ptr<ResumeParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.resume", params->Serialize(), std::move(callback));
}
void Domain::SearchInContent(std::unique_ptr<SearchInContentParams> params, base::OnceCallback<void(std::unique_ptr<SearchInContentResult>)> callback) {
  dispatcher_->SendMessage("Debugger.searchInContent", params->Serialize(), base::BindOnce(&Domain::HandleSearchInContentResponse, std::move(callback)));
}

void Domain::SearchInContent(const std::string& script_id, const std::string& query, base::OnceCallback<void(std::unique_ptr<SearchInContentResult>)> callback) {
  std::unique_ptr<SearchInContentParams> params = SearchInContentParams::Builder()
      .SetScriptId(std::move(script_id))
      .SetQuery(std::move(query))
      .Build();
dispatcher_->SendMessage("Debugger.searchInContent", params->Serialize(), base::BindOnce(&Domain::HandleSearchInContentResponse, std::move(callback)));
}
void Domain::SetAsyncCallStackDepth(std::unique_ptr<SetAsyncCallStackDepthParams> params, base::OnceCallback<void(std::unique_ptr<SetAsyncCallStackDepthResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setAsyncCallStackDepth", params->Serialize(), base::BindOnce(&Domain::HandleSetAsyncCallStackDepthResponse, std::move(callback)));
}

void Domain::SetAsyncCallStackDepth(int max_depth, base::OnceClosure callback) {
  std::unique_ptr<SetAsyncCallStackDepthParams> params = SetAsyncCallStackDepthParams::Builder()
      .SetMaxDepth(std::move(max_depth))
      .Build();
  dispatcher_->SendMessage("Debugger.setAsyncCallStackDepth", params->Serialize(), std::move(callback));
}
void Domain::SetAsyncCallStackDepth(std::unique_ptr<SetAsyncCallStackDepthParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.setAsyncCallStackDepth", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::SetBlackboxPatterns(std::unique_ptr<SetBlackboxPatternsParams> params, base::OnceCallback<void(std::unique_ptr<SetBlackboxPatternsResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setBlackboxPatterns", params->Serialize(), base::BindOnce(&Domain::HandleSetBlackboxPatternsResponse, std::move(callback)));
}
void ExperimentalDomain::SetBlackboxedRanges(std::unique_ptr<SetBlackboxedRangesParams> params, base::OnceCallback<void(std::unique_ptr<SetBlackboxedRangesResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setBlackboxedRanges", params->Serialize(), base::BindOnce(&Domain::HandleSetBlackboxedRangesResponse, std::move(callback)));
}
void Domain::SetBreakpoint(std::unique_ptr<SetBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<SetBreakpointResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setBreakpoint", params->Serialize(), base::BindOnce(&Domain::HandleSetBreakpointResponse, std::move(callback)));
}

void Domain::SetBreakpoint(std::unique_ptr<::headless::debugger::Location> location, base::OnceCallback<void(std::unique_ptr<SetBreakpointResult>)> callback) {
  std::unique_ptr<SetBreakpointParams> params = SetBreakpointParams::Builder()
      .SetLocation(std::move(location))
      .Build();
dispatcher_->SendMessage("Debugger.setBreakpoint", params->Serialize(), base::BindOnce(&Domain::HandleSetBreakpointResponse, std::move(callback)));
}
void Domain::SetInstrumentationBreakpoint(std::unique_ptr<SetInstrumentationBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<SetInstrumentationBreakpointResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setInstrumentationBreakpoint", params->Serialize(), base::BindOnce(&Domain::HandleSetInstrumentationBreakpointResponse, std::move(callback)));
}

void Domain::SetInstrumentationBreakpoint(::headless::debugger::SetInstrumentationBreakpointInstrumentation instrumentation, base::OnceCallback<void(std::unique_ptr<SetInstrumentationBreakpointResult>)> callback) {
  std::unique_ptr<SetInstrumentationBreakpointParams> params = SetInstrumentationBreakpointParams::Builder()
      .SetInstrumentation(std::move(instrumentation))
      .Build();
dispatcher_->SendMessage("Debugger.setInstrumentationBreakpoint", params->Serialize(), base::BindOnce(&Domain::HandleSetInstrumentationBreakpointResponse, std::move(callback)));
}
void Domain::SetBreakpointByUrl(std::unique_ptr<SetBreakpointByUrlParams> params, base::OnceCallback<void(std::unique_ptr<SetBreakpointByUrlResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setBreakpointByUrl", params->Serialize(), base::BindOnce(&Domain::HandleSetBreakpointByUrlResponse, std::move(callback)));
}

void Domain::SetBreakpointByUrl(int line_number, base::OnceCallback<void(std::unique_ptr<SetBreakpointByUrlResult>)> callback) {
  std::unique_ptr<SetBreakpointByUrlParams> params = SetBreakpointByUrlParams::Builder()
      .SetLineNumber(std::move(line_number))
      .Build();
dispatcher_->SendMessage("Debugger.setBreakpointByUrl", params->Serialize(), base::BindOnce(&Domain::HandleSetBreakpointByUrlResponse, std::move(callback)));
}
void ExperimentalDomain::SetBreakpointOnFunctionCall(std::unique_ptr<SetBreakpointOnFunctionCallParams> params, base::OnceCallback<void(std::unique_ptr<SetBreakpointOnFunctionCallResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setBreakpointOnFunctionCall", params->Serialize(), base::BindOnce(&Domain::HandleSetBreakpointOnFunctionCallResponse, std::move(callback)));
}
void Domain::SetBreakpointsActive(std::unique_ptr<SetBreakpointsActiveParams> params, base::OnceCallback<void(std::unique_ptr<SetBreakpointsActiveResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setBreakpointsActive", params->Serialize(), base::BindOnce(&Domain::HandleSetBreakpointsActiveResponse, std::move(callback)));
}

void Domain::SetBreakpointsActive(bool active, base::OnceClosure callback) {
  std::unique_ptr<SetBreakpointsActiveParams> params = SetBreakpointsActiveParams::Builder()
      .SetActive(std::move(active))
      .Build();
  dispatcher_->SendMessage("Debugger.setBreakpointsActive", params->Serialize(), std::move(callback));
}
void Domain::SetBreakpointsActive(std::unique_ptr<SetBreakpointsActiveParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.setBreakpointsActive", params->Serialize(), std::move(callback));
}
void Domain::SetPauseOnExceptions(std::unique_ptr<SetPauseOnExceptionsParams> params, base::OnceCallback<void(std::unique_ptr<SetPauseOnExceptionsResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setPauseOnExceptions", params->Serialize(), base::BindOnce(&Domain::HandleSetPauseOnExceptionsResponse, std::move(callback)));
}

void Domain::SetPauseOnExceptions(::headless::debugger::SetPauseOnExceptionsState state, base::OnceClosure callback) {
  std::unique_ptr<SetPauseOnExceptionsParams> params = SetPauseOnExceptionsParams::Builder()
      .SetState(std::move(state))
      .Build();
  dispatcher_->SendMessage("Debugger.setPauseOnExceptions", params->Serialize(), std::move(callback));
}
void Domain::SetPauseOnExceptions(std::unique_ptr<SetPauseOnExceptionsParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.setPauseOnExceptions", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::SetReturnValue(std::unique_ptr<SetReturnValueParams> params, base::OnceCallback<void(std::unique_ptr<SetReturnValueResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setReturnValue", params->Serialize(), base::BindOnce(&Domain::HandleSetReturnValueResponse, std::move(callback)));
}
void Domain::SetScriptSource(std::unique_ptr<SetScriptSourceParams> params, base::OnceCallback<void(std::unique_ptr<SetScriptSourceResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setScriptSource", params->Serialize(), base::BindOnce(&Domain::HandleSetScriptSourceResponse, std::move(callback)));
}

void Domain::SetScriptSource(const std::string& script_id, const std::string& script_source, base::OnceCallback<void(std::unique_ptr<SetScriptSourceResult>)> callback) {
  std::unique_ptr<SetScriptSourceParams> params = SetScriptSourceParams::Builder()
      .SetScriptId(std::move(script_id))
      .SetScriptSource(std::move(script_source))
      .Build();
dispatcher_->SendMessage("Debugger.setScriptSource", params->Serialize(), base::BindOnce(&Domain::HandleSetScriptSourceResponse, std::move(callback)));
}
void Domain::SetSkipAllPauses(std::unique_ptr<SetSkipAllPausesParams> params, base::OnceCallback<void(std::unique_ptr<SetSkipAllPausesResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setSkipAllPauses", params->Serialize(), base::BindOnce(&Domain::HandleSetSkipAllPausesResponse, std::move(callback)));
}

void Domain::SetSkipAllPauses(bool skip, base::OnceClosure callback) {
  std::unique_ptr<SetSkipAllPausesParams> params = SetSkipAllPausesParams::Builder()
      .SetSkip(std::move(skip))
      .Build();
  dispatcher_->SendMessage("Debugger.setSkipAllPauses", params->Serialize(), std::move(callback));
}
void Domain::SetSkipAllPauses(std::unique_ptr<SetSkipAllPausesParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.setSkipAllPauses", params->Serialize(), std::move(callback));
}
void Domain::SetVariableValue(std::unique_ptr<SetVariableValueParams> params, base::OnceCallback<void(std::unique_ptr<SetVariableValueResult>)> callback) {
  dispatcher_->SendMessage("Debugger.setVariableValue", params->Serialize(), base::BindOnce(&Domain::HandleSetVariableValueResponse, std::move(callback)));
}

void Domain::SetVariableValue(int scope_number, const std::string& variable_name, std::unique_ptr<::headless::runtime::CallArgument> new_value, const std::string& call_frame_id, base::OnceClosure callback) {
  std::unique_ptr<SetVariableValueParams> params = SetVariableValueParams::Builder()
      .SetScopeNumber(std::move(scope_number))
      .SetVariableName(std::move(variable_name))
      .SetNewValue(std::move(new_value))
      .SetCallFrameId(std::move(call_frame_id))
      .Build();
  dispatcher_->SendMessage("Debugger.setVariableValue", params->Serialize(), std::move(callback));
}
void Domain::SetVariableValue(std::unique_ptr<SetVariableValueParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.setVariableValue", params->Serialize(), std::move(callback));
}
void Domain::StepInto(std::unique_ptr<StepIntoParams> params, base::OnceCallback<void(std::unique_ptr<StepIntoResult>)> callback) {
  dispatcher_->SendMessage("Debugger.stepInto", params->Serialize(), base::BindOnce(&Domain::HandleStepIntoResponse, std::move(callback)));
}

void Domain::StepInto(base::OnceClosure callback) {
  std::unique_ptr<StepIntoParams> params = StepIntoParams::Builder()
      .Build();
  dispatcher_->SendMessage("Debugger.stepInto", params->Serialize(), std::move(callback));
}
void Domain::StepInto(std::unique_ptr<StepIntoParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.stepInto", params->Serialize(), std::move(callback));
}
void Domain::StepOut(std::unique_ptr<StepOutParams> params, base::OnceCallback<void(std::unique_ptr<StepOutResult>)> callback) {
  dispatcher_->SendMessage("Debugger.stepOut", params->Serialize(), base::BindOnce(&Domain::HandleStepOutResponse, std::move(callback)));
}

void Domain::StepOut(base::OnceClosure callback) {
  std::unique_ptr<StepOutParams> params = StepOutParams::Builder()
      .Build();
  dispatcher_->SendMessage("Debugger.stepOut", params->Serialize(), std::move(callback));
}
void Domain::StepOut(std::unique_ptr<StepOutParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.stepOut", params->Serialize(), std::move(callback));
}
void Domain::StepOver(std::unique_ptr<StepOverParams> params, base::OnceCallback<void(std::unique_ptr<StepOverResult>)> callback) {
  dispatcher_->SendMessage("Debugger.stepOver", params->Serialize(), base::BindOnce(&Domain::HandleStepOverResponse, std::move(callback)));
}

void Domain::StepOver(base::OnceClosure callback) {
  std::unique_ptr<StepOverParams> params = StepOverParams::Builder()
      .Build();
  dispatcher_->SendMessage("Debugger.stepOver", params->Serialize(), std::move(callback));
}
void Domain::StepOver(std::unique_ptr<StepOverParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Debugger.stepOver", params->Serialize(), std::move(callback));
}


// static
void Domain::HandleContinueToLocationResponse(base::OnceCallback<void(std::unique_ptr<ContinueToLocationResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ContinueToLocationResult> result = ContinueToLocationResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = DisableResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = EnableResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleEvaluateOnCallFrameResponse(base::OnceCallback<void(std::unique_ptr<EvaluateOnCallFrameResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<EvaluateOnCallFrameResult> result = EvaluateOnCallFrameResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleExecuteWasmEvaluatorResponse(base::OnceCallback<void(std::unique_ptr<ExecuteWasmEvaluatorResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ExecuteWasmEvaluatorResult> result = ExecuteWasmEvaluatorResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetPossibleBreakpointsResponse(base::OnceCallback<void(std::unique_ptr<GetPossibleBreakpointsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetPossibleBreakpointsResult> result = GetPossibleBreakpointsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetScriptSourceResponse(base::OnceCallback<void(std::unique_ptr<GetScriptSourceResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetScriptSourceResult> result = GetScriptSourceResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetWasmBytecodeResponse(base::OnceCallback<void(std::unique_ptr<GetWasmBytecodeResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetWasmBytecodeResult> result = GetWasmBytecodeResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetStackTraceResponse(base::OnceCallback<void(std::unique_ptr<GetStackTraceResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetStackTraceResult> result = GetStackTraceResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandlePauseResponse(base::OnceCallback<void(std::unique_ptr<PauseResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<PauseResult> result = PauseResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandlePauseOnAsyncCallResponse(base::OnceCallback<void(std::unique_ptr<PauseOnAsyncCallResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<PauseOnAsyncCallResult> result = PauseOnAsyncCallResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleRemoveBreakpointResponse(base::OnceCallback<void(std::unique_ptr<RemoveBreakpointResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<RemoveBreakpointResult> result = RemoveBreakpointResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleRestartFrameResponse(base::OnceCallback<void(std::unique_ptr<RestartFrameResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<RestartFrameResult> result = RestartFrameResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleResumeResponse(base::OnceCallback<void(std::unique_ptr<ResumeResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ResumeResult> result = ResumeResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSearchInContentResponse(base::OnceCallback<void(std::unique_ptr<SearchInContentResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SearchInContentResult> result = SearchInContentResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetAsyncCallStackDepthResponse(base::OnceCallback<void(std::unique_ptr<SetAsyncCallStackDepthResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetAsyncCallStackDepthResult> result = SetAsyncCallStackDepthResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetBlackboxPatternsResponse(base::OnceCallback<void(std::unique_ptr<SetBlackboxPatternsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetBlackboxPatternsResult> result = SetBlackboxPatternsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetBlackboxedRangesResponse(base::OnceCallback<void(std::unique_ptr<SetBlackboxedRangesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetBlackboxedRangesResult> result = SetBlackboxedRangesResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetBreakpointResponse(base::OnceCallback<void(std::unique_ptr<SetBreakpointResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetBreakpointResult> result = SetBreakpointResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetInstrumentationBreakpointResponse(base::OnceCallback<void(std::unique_ptr<SetInstrumentationBreakpointResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetInstrumentationBreakpointResult> result = SetInstrumentationBreakpointResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetBreakpointByUrlResponse(base::OnceCallback<void(std::unique_ptr<SetBreakpointByUrlResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetBreakpointByUrlResult> result = SetBreakpointByUrlResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetBreakpointOnFunctionCallResponse(base::OnceCallback<void(std::unique_ptr<SetBreakpointOnFunctionCallResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetBreakpointOnFunctionCallResult> result = SetBreakpointOnFunctionCallResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetBreakpointsActiveResponse(base::OnceCallback<void(std::unique_ptr<SetBreakpointsActiveResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetBreakpointsActiveResult> result = SetBreakpointsActiveResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetPauseOnExceptionsResponse(base::OnceCallback<void(std::unique_ptr<SetPauseOnExceptionsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetPauseOnExceptionsResult> result = SetPauseOnExceptionsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetReturnValueResponse(base::OnceCallback<void(std::unique_ptr<SetReturnValueResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetReturnValueResult> result = SetReturnValueResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetScriptSourceResponse(base::OnceCallback<void(std::unique_ptr<SetScriptSourceResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetScriptSourceResult> result = SetScriptSourceResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetSkipAllPausesResponse(base::OnceCallback<void(std::unique_ptr<SetSkipAllPausesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetSkipAllPausesResult> result = SetSkipAllPausesResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetVariableValueResponse(base::OnceCallback<void(std::unique_ptr<SetVariableValueResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetVariableValueResult> result = SetVariableValueResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStepIntoResponse(base::OnceCallback<void(std::unique_ptr<StepIntoResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StepIntoResult> result = StepIntoResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStepOutResponse(base::OnceCallback<void(std::unique_ptr<StepOutResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StepOutResult> result = StepOutResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStepOverResponse(base::OnceCallback<void(std::unique_ptr<StepOverResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StepOverResult> result = StepOverResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchBreakpointResolvedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<BreakpointResolvedParams> parsed_params(BreakpointResolvedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnBreakpointResolved(*parsed_params);
  }
}

void Domain::DispatchPausedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<PausedParams> parsed_params(PausedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnPaused(*parsed_params);
  }
}

void Domain::DispatchResumedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ResumedParams> parsed_params(ResumedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnResumed(*parsed_params);
  }
}

void Domain::DispatchScriptFailedToParseEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ScriptFailedToParseParams> parsed_params(ScriptFailedToParseParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnScriptFailedToParse(*parsed_params);
  }
}

void Domain::DispatchScriptParsedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ScriptParsedParams> parsed_params(ScriptParsedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnScriptParsed(*parsed_params);
  }
}

Domain::Domain(internal::MessageDispatcher* dispatcher)
    : dispatcher_(dispatcher) {
}

Domain::~Domain() {}

ExperimentalDomain::ExperimentalDomain(internal::MessageDispatcher* dispatcher)
    : Domain(dispatcher) {}

ExperimentalDomain::~ExperimentalDomain() {}

void ExperimentalDomain::AddObserver(ExperimentalObserver* observer) {
  RegisterEventHandlersIfNeeded();
  observers_.AddObserver(observer);
}

void ExperimentalDomain::RemoveObserver(ExperimentalObserver* observer) {
  observers_.RemoveObserver(observer);
}

}  // namespace debugger

} // namespace headless
