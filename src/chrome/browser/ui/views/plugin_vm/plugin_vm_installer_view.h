// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_VIEWS_PLUGIN_VM_PLUGIN_VM_INSTALLER_VIEW_H_
#define CHROME_BROWSER_UI_VIEWS_PLUGIN_VM_PLUGIN_VM_INSTALLER_VIEW_H_

#include "base/callback.h"
#include "base/macros.h"
#include "chrome/browser/chromeos/plugin_vm/plugin_vm_installer.h"
#include "ui/views/bubble/bubble_dialog_delegate_view.h"

namespace views {
class ImageView;
class Label;
class ProgressBar;
}  // namespace views

class Profile;

// The front end for Plugin VM, shown the first time the user launches it.
class PluginVmInstallerView : public views::BubbleDialogDelegateView,
                              public plugin_vm::PluginVmInstaller::Observer {
 public:
  explicit PluginVmInstallerView(Profile* profile);

  static PluginVmInstallerView* GetActiveViewForTesting();

  // views::BubbleDialogDelegateView implementation.
  bool ShouldShowCloseButton() const override;
  bool ShouldShowWindowTitle() const override;
  bool Accept() override;
  bool Cancel() override;
  gfx::Size CalculatePreferredSize() const override;

  // plugin_vm::PluginVmImageDownload::Observer implementation.
  void OnStateUpdated(
      plugin_vm::PluginVmInstaller::InstallingState new_state) override;
  void OnProgressUpdated(double fraction_complete) override;
  void OnDownloadProgressUpdated(uint64_t bytes_downloaded,
                                 int64_t content_length) override;
  void OnVmExists() override;
  void OnCreated() override;
  void OnImported() override;
  void OnError(plugin_vm::PluginVmInstaller::FailureReason reason) override;
  void OnCancelFinished() override;

  // Public for testing purposes.
  base::string16 GetBigMessage() const;
  base::string16 GetMessage() const;

  void SetFinishedCallbackForTesting(
      base::OnceCallback<void(bool success)> callback);

 private:
  enum class State {
    kConfirmInstall,  // Waiting for user to start installation.
    kInstalling,      // Installation in progress.
    kCreated,         // A brand new VM has been created using ISO image.
    kImported,        // Downloaded VM image has been imported successfully.
    kError,           // Something unexpected happened.
  };

  using InstallingState = plugin_vm::PluginVmInstaller::InstallingState;

  ~PluginVmInstallerView() override;

  int GetCurrentDialogButtons() const;
  base::string16 GetCurrentDialogButtonLabel(ui::DialogButton button) const;

  void OnStateUpdated();
  // views::BubbleDialogDelegateView implementation.
  void AddedToWidget() override;

  base::string16 GetDownloadProgressMessage(uint64_t downlaoded_bytes,
                                            int64_t content_length) const;
  void SetBigMessageLabel();
  void SetMessageLabel();
  void SetBigImage();

  void StartInstallation();

  Profile* profile_ = nullptr;
  base::string16 app_name_;
  plugin_vm::PluginVmInstaller* plugin_vm_installer_ = nullptr;
  views::Label* big_message_label_ = nullptr;
  views::Label* message_label_ = nullptr;
  views::ProgressBar* progress_bar_ = nullptr;
  views::Label* download_progress_message_label_ = nullptr;
  views::ImageView* big_image_ = nullptr;
  base::TimeTicks setup_start_tick_;

  State state_ = State::kConfirmInstall;
  InstallingState installing_state_ = InstallingState::kInactive;
  base::Optional<plugin_vm::PluginVmInstaller::FailureReason> reason_;

  base::OnceCallback<void(bool success)> finished_callback_for_testing_;

  DISALLOW_COPY_AND_ASSIGN(PluginVmInstallerView);
};

#endif  // CHROME_BROWSER_UI_VIEWS_PLUGIN_VM_PLUGIN_VM_INSTALLER_VIEW_H_
