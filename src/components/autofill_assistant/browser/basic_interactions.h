// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_ASSISTANT_BROWSER_BASIC_INTERACTIONS_H_
#define COMPONENTS_AUTOFILL_ASSISTANT_BROWSER_BASIC_INTERACTIONS_H_

#include "base/bind_helpers.h"
#include "base/memory/weak_ptr.h"
#include "components/autofill_assistant/browser/client_status.h"
#include "components/autofill_assistant/browser/generic_ui.pb.h"

namespace autofill_assistant {
class ScriptExecutorDelegate;

// Provides basic interactions for use by the generic UI framework. These
// methods are intended to be bound to by the corresponding interaction
// handlers.
class BasicInteractions {
 public:
  // Constructor. |delegate| must outlive this instance.
  BasicInteractions(ScriptExecutorDelegate* delegate);
  ~BasicInteractions();

  BasicInteractions(const BasicInteractions&) = delete;
  BasicInteractions& operator=(const BasicInteractions&) = delete;

  base::WeakPtr<BasicInteractions> GetWeakPtr();

  // Performs the computation specified by |proto| and writes the result to
  // |user_model_|. Returns true on success, false on error.
  bool ComputeValue(const ComputeValueProto& proto);

  // Sets a value in |user_model_| as specified by |proto|. Returns true on
  // success, false on error.
  bool SetValue(const SetModelValueProto& proto);

  // Replaces the set of available user actions as specified by |proto|. Returns
  // true on success, false on error.
  bool SetUserActions(const SetUserActionsProto& proto);

  // Enables or disables a user action. Returns true on success, false on error.
  bool ToggleUserAction(const ToggleUserActionProto& proto);

  // Ends the current action. Can only be called during a ShowGenericUiAction.
  bool EndAction(const ClientStatus& status);

  // Runs |view_inflation_finished_callback_| to notify its owner that view
  // inflation has finished. Can only be called during a ShowGenericUiAction.
  bool NotifyViewInflationFinished(const ClientStatus& status);

  // Sets the callback to end the current ShowGenericUiAction.
  void SetEndActionCallback(
      base::OnceCallback<void(const ClientStatus&)> end_action_callback);

  // Sets the callback to indicate whether view inflation was successful or not.
  void SetViewInflationFinishedCallback(
      base::OnceCallback<void(const ClientStatus&)>
          view_inflation_finished_callback);

  // Clears all callbacks associated with the current ShowGenericUi action.
  void ClearCallbacks();

  // Runs |callback| if |condition_identifier| points to a single boolean set to
  // 'true'. Returns true on success (i.e., condition was evaluated
  // successfully), false on failure.
  bool RunConditionalCallback(const std::string& condition_identifier,
                              base::RepeatingCallback<void()> callback);

  // Disables all radio buttons in |model_identifiers| except
  // |selected_model_identifier|. Fails if one or more model identifiers are not
  // found.
  bool UpdateRadioButtonGroup(const std::vector<std::string>& model_identifiers,
                              const std::string& selected_model_identifier);

 private:
  ScriptExecutorDelegate* delegate_;
  // Only valid during a ShowGenericUiAction.
  base::OnceCallback<void(const ClientStatus&)> end_action_callback_;
  base::OnceCallback<void(const ClientStatus&)>
      view_inflation_finished_callback_;
  base::WeakPtrFactory<BasicInteractions> weak_ptr_factory_{this};
};

}  // namespace autofill_assistant

#endif  // COMPONENTS_AUTOFILL_ASSISTANT_BROWSER_BASIC_INTERACTIONS_H_
