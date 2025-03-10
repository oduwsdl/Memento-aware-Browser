// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/chromeos/policy/arc_app_install_event_log_manager.h"

#include "base/files/file_path.h"
#include "base/files/file_util.h"
#include "base/task/post_task.h"
#include "base/task/task_traits.h"
#include "base/task/thread_pool.h"
#include "base/task_runner_util.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/ui/app_list/arc/arc_app_utils.h"

namespace em = enterprise_management;

namespace policy {

namespace {

// The log file, stored in the user's profile directory.
constexpr base::FilePath::CharType kLogFileName[] =
    FILE_PATH_LITERAL("app_push_install_log");

// Returns the path to the app push-install event log file for |profile|.
base::FilePath GetLogFilePath(const Profile& profile) {
  return profile.GetPath().Append(kLogFileName);
}

}  // namespace

ArcAppInstallEventLogManager::ArcAppInstallEventLogManager(
    LogTaskRunnerWrapper* log_task_runner_wrapper,
    ArcAppInstallEventLogUploader* uploader,
    Profile* profile)
    : InstallEventLogManagerBase(log_task_runner_wrapper, profile),
      uploader_(uploader) {
  uploader_->SetDelegate(this);
  app_log_upload_ = std::make_unique<AppLogUpload>(this);
  log_ = std::make_unique<ArcLog>();
  base::PostTaskAndReplyWithResult(
      log_task_runner_.get(), FROM_HERE,
      base::BindOnce(&ArcLog::Init, base::Unretained(log_.get()),
                     GetLogFilePath(*profile)),
      base::BindOnce(&ArcAppInstallEventLogManager::AppLogUpload::OnLogInit,
                     app_log_upload_->log_weak_factory_.GetWeakPtr()));
  logger_ = std::make_unique<AppInstallEventLogger>(this, profile);
}

ArcAppInstallEventLogManager::~ArcAppInstallEventLogManager() {
  app_log_upload_.reset();
  logger_.reset();
  uploader_->SetDelegate(nullptr);
  log_task_runner_->DeleteSoon(FROM_HERE, std::move(log_));
}

// static
void ArcAppInstallEventLogManager::Clear(
    LogTaskRunnerWrapper* log_task_runner_wrapper,
    Profile* profile) {
  AppInstallEventLogger::Clear(profile);
  log_task_runner_wrapper->GetTaskRunner()->PostTask(
      FROM_HERE, base::BindOnce(
                     [](const base::FilePath& log_file_path) {
                       base::DeleteFile(log_file_path, false /* recursive */);
                     },
                     GetLogFilePath(*profile)));
}

void ArcAppInstallEventLogManager::Add(
    const std::set<std::string>& packages,
    const em::AppInstallReportLogEvent& event) {
  if (packages.empty()) {
    return;
  }
  base::PostTaskAndReplyWithResult(
      log_task_runner_.get(), FROM_HERE,
      base::BindOnce(&ArcLog::Add, base::Unretained(log_.get()), packages,
                     event),
      base::BindOnce(&ArcAppInstallEventLogManager::AppLogUpload::OnLogChange,
                     base::Unretained(app_log_upload_.get())));
}

void ArcAppInstallEventLogManager::GetAndroidId(
    AppInstallEventLogger::Delegate::AndroidIdCallback callback) const {
  arc::GetAndroidId(std::move(callback));
}

void ArcAppInstallEventLogManager::SerializeForUpload(
    ArcAppInstallEventLogUploader::Delegate::SerializationCallback callback) {
  base::PostTaskAndReplyWithResult(
      log_task_runner_.get(), FROM_HERE,
      base::BindOnce(&ArcAppInstallEventLogManager::ArcLog::Serialize,
                     base::Unretained(log_.get())),
      base::BindOnce(
          &ArcAppInstallEventLogManager::LogUpload::OnSerializeLogDone<
              ArcAppInstallEventLogUploader::Delegate::SerializationCallback,
              em::AppInstallReportRequest>,
          app_log_upload_->log_weak_factory_.GetWeakPtr(),
          std::move(callback)));
}

void ArcAppInstallEventLogManager::OnUploadSuccess() {
  if (app_log_upload_->store_scheduled_) {
    app_log_upload_->store_scheduled_ = false;
    app_log_upload_->store_weak_factory_.InvalidateWeakPtrs();
  }
  app_log_upload_->upload_requested_ = false;

  base::PostTaskAndReplyWithResult(
      log_task_runner_.get(), FROM_HERE,
      base::BindOnce(
          &ArcAppInstallEventLogManager::ArcLog::ClearSerializedAndStore,
          base::Unretained(log_.get())),
      base::BindOnce(&ArcAppInstallEventLogManager::AppLogUpload::OnLogChange,
                     app_log_upload_->log_weak_factory_.GetWeakPtr()));
}

ArcAppInstallEventLogManager::ArcLog::ArcLog() : InstallLog() {
  DETACH_FROM_SEQUENCE(sequence_checker_);
}

ArcAppInstallEventLogManager::ArcLog::~ArcLog() {}

std::unique_ptr<em::AppInstallReportRequest>
ArcAppInstallEventLogManager::ArcLog::Serialize() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  CHECK(log_);
  auto serialized_log = std::make_unique<em::AppInstallReportRequest>();
  log_->Serialize(serialized_log.get());
  return serialized_log;
}

ArcAppInstallEventLogManager::AppLogUpload::AppLogUpload(
    ArcAppInstallEventLogManager* owner)
    : owner_(owner) {}
ArcAppInstallEventLogManager::AppLogUpload::~AppLogUpload() = default;

void ArcAppInstallEventLogManager::AppLogUpload::StoreLog() {
  CHECK(owner_->log_);
  store_scheduled_ = false;
  owner_->log_task_runner_->PostTask(
      FROM_HERE,
      base::BindOnce(&ArcLog::Store, base::Unretained(owner_->log_.get())));
}

void ArcAppInstallEventLogManager::AppLogUpload::RequestUploadForUploader() {
  owner_->uploader_->RequestUpload();
}

}  // namespace policy
