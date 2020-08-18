// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DEBUGGER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DEBUGGER_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace debugger {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Fired when breakpoint is resolved to an actual script and location.
  virtual void OnBreakpointResolved(const BreakpointResolvedParams& params) {}
  // Fired when the virtual machine stopped on breakpoint or exception or any other stop criteria.
  virtual void OnPaused(const PausedParams& params) {}
  // Fired when the virtual machine resumed execution.
  virtual void OnResumed(const ResumedParams& params) {}
  // Fired when virtual machine fails to parse the script.
  virtual void OnScriptFailedToParse(const ScriptFailedToParseParams& params) {}
  // Fired when virtual machine parses script. This event is also fired for all known and uncollected
  // scripts upon enabling debugger.
  virtual void OnScriptParsed(const ScriptParsedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Fired when breakpoint is resolved to an actual script and location.
  virtual void OnBreakpointResolved(const BreakpointResolvedParams& params) {}
  // Fired when the virtual machine stopped on breakpoint or exception or any other stop criteria.
  virtual void OnPaused(const PausedParams& params) {}
  // Fired when the virtual machine resumed execution.
  virtual void OnResumed(const ResumedParams& params) {}
  // Fired when virtual machine fails to parse the script.
  virtual void OnScriptFailedToParse(const ScriptFailedToParseParams& params) {}
  // Fired when virtual machine parses script. This event is also fired for all known and uncollected
  // scripts upon enabling debugger.
  virtual void OnScriptParsed(const ScriptParsedParams& params) {}
};

// Debugger domain exposes JavaScript debugging capabilities. It allows setting and removing
// breakpoints, stepping through execution, exploring stack traces, etc.
class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

  // Continues execution until specific location is reached.
  void ContinueToLocation(std::unique_ptr<ContinueToLocationParams> params, base::OnceCallback<void(std::unique_ptr<ContinueToLocationResult>)> callback = base::OnceCallback<void(std::unique_ptr<ContinueToLocationResult>)>());
  void ContinueToLocation(std::unique_ptr<::headless::debugger::Location> location, base::OnceClosure callback = base::OnceClosure());
  void ContinueToLocation(std::unique_ptr<ContinueToLocationParams> params, base::OnceClosure callback);

  // Disables debugger for given page.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());
  void Disable(base::OnceClosure callback = base::OnceClosure());
  void Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback);

  // Enables debugger for the given page. Clients should not assume that the debugging has been
  // enabled until the result for this command is received.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());
  void Enable(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Evaluates expression on a given call frame.
  void EvaluateOnCallFrame(std::unique_ptr<EvaluateOnCallFrameParams> params, base::OnceCallback<void(std::unique_ptr<EvaluateOnCallFrameResult>)> callback = base::OnceCallback<void(std::unique_ptr<EvaluateOnCallFrameResult>)>());
  void EvaluateOnCallFrame(const std::string& call_frame_id, const std::string& expression, base::OnceCallback<void(std::unique_ptr<EvaluateOnCallFrameResult>)> callback = base::OnceCallback<void(std::unique_ptr<EvaluateOnCallFrameResult>)>());

  // Returns possible locations for breakpoint. scriptId in start and end range locations should be
  // the same.
  void GetPossibleBreakpoints(std::unique_ptr<GetPossibleBreakpointsParams> params, base::OnceCallback<void(std::unique_ptr<GetPossibleBreakpointsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetPossibleBreakpointsResult>)>());
  void GetPossibleBreakpoints(std::unique_ptr<::headless::debugger::Location> start, base::OnceCallback<void(std::unique_ptr<GetPossibleBreakpointsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetPossibleBreakpointsResult>)>());

  // Returns source for the script with given id.
  void GetScriptSource(std::unique_ptr<GetScriptSourceParams> params, base::OnceCallback<void(std::unique_ptr<GetScriptSourceResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetScriptSourceResult>)>());
  void GetScriptSource(const std::string& script_id, base::OnceCallback<void(std::unique_ptr<GetScriptSourceResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetScriptSourceResult>)>());

  // This command is deprecated. Use getScriptSource instead.
  void GetWasmBytecode(std::unique_ptr<GetWasmBytecodeParams> params, base::OnceCallback<void(std::unique_ptr<GetWasmBytecodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetWasmBytecodeResult>)>());
  void GetWasmBytecode(const std::string& script_id, base::OnceCallback<void(std::unique_ptr<GetWasmBytecodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetWasmBytecodeResult>)>());

  // Stops on the next JavaScript statement.
  void Pause(std::unique_ptr<PauseParams> params, base::OnceCallback<void(std::unique_ptr<PauseResult>)> callback = base::OnceCallback<void(std::unique_ptr<PauseResult>)>());
  void Pause(base::OnceClosure callback = base::OnceClosure());
  void Pause(std::unique_ptr<PauseParams> params, base::OnceClosure callback);

  // Removes JavaScript breakpoint.
  void RemoveBreakpoint(std::unique_ptr<RemoveBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<RemoveBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<RemoveBreakpointResult>)>());
  void RemoveBreakpoint(const std::string& breakpoint_id, base::OnceClosure callback = base::OnceClosure());
  void RemoveBreakpoint(std::unique_ptr<RemoveBreakpointParams> params, base::OnceClosure callback);

  // Restarts particular call frame from the beginning.
  void RestartFrame(std::unique_ptr<RestartFrameParams> params, base::OnceCallback<void(std::unique_ptr<RestartFrameResult>)> callback = base::OnceCallback<void(std::unique_ptr<RestartFrameResult>)>());
  void RestartFrame(const std::string& call_frame_id, base::OnceCallback<void(std::unique_ptr<RestartFrameResult>)> callback = base::OnceCallback<void(std::unique_ptr<RestartFrameResult>)>());

  // Resumes JavaScript execution.
  void Resume(std::unique_ptr<ResumeParams> params, base::OnceCallback<void(std::unique_ptr<ResumeResult>)> callback = base::OnceCallback<void(std::unique_ptr<ResumeResult>)>());
  void Resume(base::OnceClosure callback = base::OnceClosure());
  void Resume(std::unique_ptr<ResumeParams> params, base::OnceClosure callback);

  // Searches for given string in script content.
  void SearchInContent(std::unique_ptr<SearchInContentParams> params, base::OnceCallback<void(std::unique_ptr<SearchInContentResult>)> callback = base::OnceCallback<void(std::unique_ptr<SearchInContentResult>)>());
  void SearchInContent(const std::string& script_id, const std::string& query, base::OnceCallback<void(std::unique_ptr<SearchInContentResult>)> callback = base::OnceCallback<void(std::unique_ptr<SearchInContentResult>)>());

  // Enables or disables async call stacks tracking.
  void SetAsyncCallStackDepth(std::unique_ptr<SetAsyncCallStackDepthParams> params, base::OnceCallback<void(std::unique_ptr<SetAsyncCallStackDepthResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetAsyncCallStackDepthResult>)>());
  void SetAsyncCallStackDepth(int max_depth, base::OnceClosure callback = base::OnceClosure());
  void SetAsyncCallStackDepth(std::unique_ptr<SetAsyncCallStackDepthParams> params, base::OnceClosure callback);

  // Sets JavaScript breakpoint at a given location.
  void SetBreakpoint(std::unique_ptr<SetBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<SetBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetBreakpointResult>)>());
  void SetBreakpoint(std::unique_ptr<::headless::debugger::Location> location, base::OnceCallback<void(std::unique_ptr<SetBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetBreakpointResult>)>());

  // Sets instrumentation breakpoint.
  void SetInstrumentationBreakpoint(std::unique_ptr<SetInstrumentationBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<SetInstrumentationBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetInstrumentationBreakpointResult>)>());
  void SetInstrumentationBreakpoint(::headless::debugger::SetInstrumentationBreakpointInstrumentation instrumentation, base::OnceCallback<void(std::unique_ptr<SetInstrumentationBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetInstrumentationBreakpointResult>)>());

  // Sets JavaScript breakpoint at given location specified either by URL or URL regex. Once this
  // command is issued, all existing parsed scripts will have breakpoints resolved and returned in
  // `locations` property. Further matching script parsing will result in subsequent
  // `breakpointResolved` events issued. This logical breakpoint will survive page reloads.
  void SetBreakpointByUrl(std::unique_ptr<SetBreakpointByUrlParams> params, base::OnceCallback<void(std::unique_ptr<SetBreakpointByUrlResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetBreakpointByUrlResult>)>());
  void SetBreakpointByUrl(int line_number, base::OnceCallback<void(std::unique_ptr<SetBreakpointByUrlResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetBreakpointByUrlResult>)>());

  // Activates / deactivates all breakpoints on the page.
  void SetBreakpointsActive(std::unique_ptr<SetBreakpointsActiveParams> params, base::OnceCallback<void(std::unique_ptr<SetBreakpointsActiveResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetBreakpointsActiveResult>)>());
  void SetBreakpointsActive(bool active, base::OnceClosure callback = base::OnceClosure());
  void SetBreakpointsActive(std::unique_ptr<SetBreakpointsActiveParams> params, base::OnceClosure callback);

  // Defines pause on exceptions state. Can be set to stop on all exceptions, uncaught exceptions or
  // no exceptions. Initial pause on exceptions state is `none`.
  void SetPauseOnExceptions(std::unique_ptr<SetPauseOnExceptionsParams> params, base::OnceCallback<void(std::unique_ptr<SetPauseOnExceptionsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetPauseOnExceptionsResult>)>());
  void SetPauseOnExceptions(::headless::debugger::SetPauseOnExceptionsState state, base::OnceClosure callback = base::OnceClosure());
  void SetPauseOnExceptions(std::unique_ptr<SetPauseOnExceptionsParams> params, base::OnceClosure callback);

  // Edits JavaScript source live.
  void SetScriptSource(std::unique_ptr<SetScriptSourceParams> params, base::OnceCallback<void(std::unique_ptr<SetScriptSourceResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetScriptSourceResult>)>());
  void SetScriptSource(const std::string& script_id, const std::string& script_source, base::OnceCallback<void(std::unique_ptr<SetScriptSourceResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetScriptSourceResult>)>());

  // Makes page not interrupt on any pauses (breakpoint, exception, dom exception etc).
  void SetSkipAllPauses(std::unique_ptr<SetSkipAllPausesParams> params, base::OnceCallback<void(std::unique_ptr<SetSkipAllPausesResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetSkipAllPausesResult>)>());
  void SetSkipAllPauses(bool skip, base::OnceClosure callback = base::OnceClosure());
  void SetSkipAllPauses(std::unique_ptr<SetSkipAllPausesParams> params, base::OnceClosure callback);

  // Changes value of variable in a callframe. Object-based scopes are not supported and must be
  // mutated manually.
  void SetVariableValue(std::unique_ptr<SetVariableValueParams> params, base::OnceCallback<void(std::unique_ptr<SetVariableValueResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetVariableValueResult>)>());
  void SetVariableValue(int scope_number, const std::string& variable_name, std::unique_ptr<::headless::runtime::CallArgument> new_value, const std::string& call_frame_id, base::OnceClosure callback = base::OnceClosure());
  void SetVariableValue(std::unique_ptr<SetVariableValueParams> params, base::OnceClosure callback);

  // Steps into the function call.
  void StepInto(std::unique_ptr<StepIntoParams> params, base::OnceCallback<void(std::unique_ptr<StepIntoResult>)> callback = base::OnceCallback<void(std::unique_ptr<StepIntoResult>)>());
  void StepInto(base::OnceClosure callback = base::OnceClosure());
  void StepInto(std::unique_ptr<StepIntoParams> params, base::OnceClosure callback);

  // Steps out of the function call.
  void StepOut(std::unique_ptr<StepOutParams> params, base::OnceCallback<void(std::unique_ptr<StepOutResult>)> callback = base::OnceCallback<void(std::unique_ptr<StepOutResult>)>());
  void StepOut(base::OnceClosure callback = base::OnceClosure());
  void StepOut(std::unique_ptr<StepOutParams> params, base::OnceClosure callback);

  // Steps over the statement.
  void StepOver(std::unique_ptr<StepOverParams> params, base::OnceCallback<void(std::unique_ptr<StepOverResult>)> callback = base::OnceCallback<void(std::unique_ptr<StepOverResult>)>());
  void StepOver(base::OnceClosure callback = base::OnceClosure());
  void StepOver(std::unique_ptr<StepOverParams> params, base::OnceClosure callback);

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleContinueToLocationResponse(base::OnceCallback<void(std::unique_ptr<ContinueToLocationResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleEvaluateOnCallFrameResponse(base::OnceCallback<void(std::unique_ptr<EvaluateOnCallFrameResult>)> callback, const base::Value& response);
  static void HandleExecuteWasmEvaluatorResponse(base::OnceCallback<void(std::unique_ptr<ExecuteWasmEvaluatorResult>)> callback, const base::Value& response);
  static void HandleGetPossibleBreakpointsResponse(base::OnceCallback<void(std::unique_ptr<GetPossibleBreakpointsResult>)> callback, const base::Value& response);
  static void HandleGetScriptSourceResponse(base::OnceCallback<void(std::unique_ptr<GetScriptSourceResult>)> callback, const base::Value& response);
  static void HandleGetWasmBytecodeResponse(base::OnceCallback<void(std::unique_ptr<GetWasmBytecodeResult>)> callback, const base::Value& response);
  static void HandleGetStackTraceResponse(base::OnceCallback<void(std::unique_ptr<GetStackTraceResult>)> callback, const base::Value& response);
  static void HandlePauseResponse(base::OnceCallback<void(std::unique_ptr<PauseResult>)> callback, const base::Value& response);
  static void HandlePauseOnAsyncCallResponse(base::OnceCallback<void(std::unique_ptr<PauseOnAsyncCallResult>)> callback, const base::Value& response);
  static void HandleRemoveBreakpointResponse(base::OnceCallback<void(std::unique_ptr<RemoveBreakpointResult>)> callback, const base::Value& response);
  static void HandleRestartFrameResponse(base::OnceCallback<void(std::unique_ptr<RestartFrameResult>)> callback, const base::Value& response);
  static void HandleResumeResponse(base::OnceCallback<void(std::unique_ptr<ResumeResult>)> callback, const base::Value& response);
  static void HandleSearchInContentResponse(base::OnceCallback<void(std::unique_ptr<SearchInContentResult>)> callback, const base::Value& response);
  static void HandleSetAsyncCallStackDepthResponse(base::OnceCallback<void(std::unique_ptr<SetAsyncCallStackDepthResult>)> callback, const base::Value& response);
  static void HandleSetBlackboxPatternsResponse(base::OnceCallback<void(std::unique_ptr<SetBlackboxPatternsResult>)> callback, const base::Value& response);
  static void HandleSetBlackboxedRangesResponse(base::OnceCallback<void(std::unique_ptr<SetBlackboxedRangesResult>)> callback, const base::Value& response);
  static void HandleSetBreakpointResponse(base::OnceCallback<void(std::unique_ptr<SetBreakpointResult>)> callback, const base::Value& response);
  static void HandleSetInstrumentationBreakpointResponse(base::OnceCallback<void(std::unique_ptr<SetInstrumentationBreakpointResult>)> callback, const base::Value& response);
  static void HandleSetBreakpointByUrlResponse(base::OnceCallback<void(std::unique_ptr<SetBreakpointByUrlResult>)> callback, const base::Value& response);
  static void HandleSetBreakpointOnFunctionCallResponse(base::OnceCallback<void(std::unique_ptr<SetBreakpointOnFunctionCallResult>)> callback, const base::Value& response);
  static void HandleSetBreakpointsActiveResponse(base::OnceCallback<void(std::unique_ptr<SetBreakpointsActiveResult>)> callback, const base::Value& response);
  static void HandleSetPauseOnExceptionsResponse(base::OnceCallback<void(std::unique_ptr<SetPauseOnExceptionsResult>)> callback, const base::Value& response);
  static void HandleSetReturnValueResponse(base::OnceCallback<void(std::unique_ptr<SetReturnValueResult>)> callback, const base::Value& response);
  static void HandleSetScriptSourceResponse(base::OnceCallback<void(std::unique_ptr<SetScriptSourceResult>)> callback, const base::Value& response);
  static void HandleSetSkipAllPausesResponse(base::OnceCallback<void(std::unique_ptr<SetSkipAllPausesResult>)> callback, const base::Value& response);
  static void HandleSetVariableValueResponse(base::OnceCallback<void(std::unique_ptr<SetVariableValueResult>)> callback, const base::Value& response);
  static void HandleStepIntoResponse(base::OnceCallback<void(std::unique_ptr<StepIntoResult>)> callback, const base::Value& response);
  static void HandleStepOutResponse(base::OnceCallback<void(std::unique_ptr<StepOutResult>)> callback, const base::Value& response);
  static void HandleStepOverResponse(base::OnceCallback<void(std::unique_ptr<StepOverResult>)> callback, const base::Value& response);

  void DispatchBreakpointResolvedEvent(const base::Value& params);
  void DispatchPausedEvent(const base::Value& params);
  void DispatchResumedEvent(const base::Value& params);
  void DispatchScriptFailedToParseEvent(const base::Value& params);
  void DispatchScriptParsedEvent(const base::Value& params);

  internal::MessageDispatcher* dispatcher_;  // Not owned.
  base::ObserverList<ExperimentalObserver>::Unchecked observers_;

 protected:
  void RegisterEventHandlersIfNeeded();

 private:
  bool event_handlers_registered_ = false;

  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();

  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(ExperimentalObserver* observer);
  void RemoveObserver(ExperimentalObserver* observer);

  // Execute a Wasm Evaluator module on a given call frame.
  void ExecuteWasmEvaluator(std::unique_ptr<ExecuteWasmEvaluatorParams> params, base::OnceCallback<void(std::unique_ptr<ExecuteWasmEvaluatorResult>)> callback = base::OnceCallback<void(std::unique_ptr<ExecuteWasmEvaluatorResult>)>());

  // Returns stack trace with given `stackTraceId`.
  void GetStackTrace(std::unique_ptr<GetStackTraceParams> params, base::OnceCallback<void(std::unique_ptr<GetStackTraceResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetStackTraceResult>)>());

  void PauseOnAsyncCall(std::unique_ptr<PauseOnAsyncCallParams> params, base::OnceCallback<void(std::unique_ptr<PauseOnAsyncCallResult>)> callback = base::OnceCallback<void(std::unique_ptr<PauseOnAsyncCallResult>)>());

  // Replace previous blackbox patterns with passed ones. Forces backend to skip stepping/pausing in
  // scripts with url matching one of the patterns. VM will try to leave blackboxed script by
  // performing 'step in' several times, finally resorting to 'step out' if unsuccessful.
  void SetBlackboxPatterns(std::unique_ptr<SetBlackboxPatternsParams> params, base::OnceCallback<void(std::unique_ptr<SetBlackboxPatternsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetBlackboxPatternsResult>)>());

  // Makes backend skip steps in the script in blackboxed ranges. VM will try leave blacklisted
  // scripts by performing 'step in' several times, finally resorting to 'step out' if unsuccessful.
  // Positions array contains positions where blackbox state is changed. First interval isn't
  // blackboxed. Array should be sorted.
  void SetBlackboxedRanges(std::unique_ptr<SetBlackboxedRangesParams> params, base::OnceCallback<void(std::unique_ptr<SetBlackboxedRangesResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetBlackboxedRangesResult>)>());

  // Sets JavaScript breakpoint before each call to the given function.
  // If another function was created from the same source as a given one,
  // calling it will also trigger the breakpoint.
  void SetBreakpointOnFunctionCall(std::unique_ptr<SetBreakpointOnFunctionCallParams> params, base::OnceCallback<void(std::unique_ptr<SetBreakpointOnFunctionCallResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetBreakpointOnFunctionCallResult>)>());

  // Changes return value in top frame. Available only at return break position.
  void SetReturnValue(std::unique_ptr<SetReturnValueParams> params, base::OnceCallback<void(std::unique_ptr<SetReturnValueResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetReturnValueResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace debugger
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DEBUGGER_H_
