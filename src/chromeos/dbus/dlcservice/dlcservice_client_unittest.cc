// Copyright (c) 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chromeos/dbus/dlcservice/dlcservice_client.h"

#include <algorithm>
#include <atomic>
#include <functional>
#include <memory>
#include <utility>
#include <vector>

#include "base/bind.h"
#include "base/run_loop.h"
#include "base/test/task_environment.h"
#include "dbus/mock_bus.h"
#include "dbus/mock_object_proxy.h"
#include "dbus/object_path.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "testing/gtest/include/gtest/gtest.h"

using ::testing::_;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::WithArg;

namespace chromeos {

namespace {
std::unique_ptr<dbus::Signal> CreateSignal(
    const dlcservice::DlcState& dlc_state) {
  auto signal =
      std::make_unique<dbus::Signal>("com.example.Interface", "SomeSignal");
  dbus::MessageWriter writer(signal.get());
  writer.AppendProtoAsArrayOfBytes(dlc_state);
  return signal;
}
}  // namespace

class DlcserviceClientTest : public testing::Test {
 public:
  void SetUp() override {
    dbus::Bus::Options options;
    options.bus_type = dbus::Bus::SYSTEM;

    mock_bus_ = base::MakeRefCounted<::testing::NiceMock<dbus::MockBus>>(
        dbus::Bus::Options());

    mock_proxy_ = base::MakeRefCounted<dbus::MockObjectProxy>(
        mock_bus_.get(), dlcservice::kDlcServiceServiceName,
        dbus::ObjectPath(dlcservice::kDlcServiceServicePath));

    EXPECT_CALL(
        *mock_bus_.get(),
        GetObjectProxy(dlcservice::kDlcServiceServiceName,
                       dbus::ObjectPath(dlcservice::kDlcServiceServicePath)))
        .WillOnce(Return(mock_proxy_.get()));

    EXPECT_CALL(*mock_proxy_.get(),
                DoConnectToSignal(dlcservice::kDlcServiceInterface, _, _, _))
        .WillOnce(Invoke(this, &DlcserviceClientTest::ConnectToSignal));

    DlcserviceClient::Initialize(mock_bus_.get());
    client_ = DlcserviceClient::Get();

    base::RunLoop().RunUntilIdle();
  }

  void TearDown() override { DlcserviceClient::Shutdown(); }

  void CallMethodWithErrorResponse(
      dbus::MethodCall* method_call,
      int timeout_ms,
      dbus::ObjectProxy::ResponseOrErrorCallback* callback) {
    dbus::Response* response = nullptr;
    dbus::ErrorResponse* err_response = nullptr;
    if (!responses_.empty()) {
      used_responses_.push_back(std::move(responses_.front()));
      responses_.pop_front();
      response = used_responses_.back().get();
    }
    if (!err_responses_.empty()) {
      used_err_responses_.push_back(std::move(err_responses_.front()));
      err_responses_.pop_front();
      err_response = used_err_responses_.back().get();
    }
    CHECK((response != nullptr) != (err_response != nullptr));
    task_environment_.GetMainThreadTaskRunner()->PostTask(
        FROM_HERE,
        base::BindOnce(std::move(*callback), response, err_response));
  }

 protected:
  base::test::SingleThreadTaskEnvironment task_environment_;
  DlcserviceClient* client_;
  scoped_refptr<dbus::MockBus> mock_bus_;
  scoped_refptr<dbus::MockObjectProxy> mock_proxy_;
  std::deque<std::unique_ptr<dbus::Response>> responses_;
  std::deque<std::unique_ptr<dbus::ErrorResponse>> err_responses_;

 private:
  void ConnectToSignal(
      const std::string& interface_name,
      const std::string& signal_name,
      dbus::ObjectProxy::SignalCallback signal_callback,
      dbus::ObjectProxy::OnConnectedCallback* on_connected_callback) {
    EXPECT_EQ(interface_name, dlcservice::kDlcServiceInterface);
    task_environment_.GetMainThreadTaskRunner()->PostTask(
        FROM_HERE,
        base::BindOnce(std::move(*on_connected_callback), interface_name,
                       signal_name, true /* success */));
  }

  std::deque<std::unique_ptr<dbus::Response>> used_responses_;
  std::deque<std::unique_ptr<dbus::ErrorResponse>> used_err_responses_;
};

class MockObserver : public DlcserviceClient::Observer {
 public:
  MOCK_METHOD(void,
              OnDlcStateChanged,
              (const dlcservice::DlcState& dlc_state),
              ());
};

TEST_F(DlcserviceClientTest, GetExistingDlcsSuccessTest) {
  responses_.push_back(dbus::Response::CreateEmpty());
  dbus::Response* response = responses_.front().get();
  dbus::MessageWriter writer(response);
  dlcservice::DlcsWithContent dlcs_with_content;
  writer.AppendProtoAsArrayOfBytes(dlcs_with_content);

  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillOnce(
          Invoke(this, &DlcserviceClientTest::CallMethodWithErrorResponse));

  DlcserviceClient::GetExistingDlcsCallback callback = base::BindOnce(
      [](const std::string& err, const dlcservice::DlcsWithContent&) {
        EXPECT_EQ(dlcservice::kErrorNone, err);
      });
  client_->GetExistingDlcs(std::move(callback));
  base::RunLoop().RunUntilIdle();
}

TEST_F(DlcserviceClientTest, GetExistingDlcsFailureTest) {
  dbus::MethodCall method_call(dlcservice::kDlcServiceInterface,
                               dlcservice::kGetExistingDlcsMethod);
  method_call.SetSerial(123);
  err_responses_.push_back(dbus::ErrorResponse::FromMethodCall(
      &method_call, DBUS_ERROR_FAILED, "some-unknown-error"));

  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillRepeatedly(
          Invoke(this, &DlcserviceClientTest::CallMethodWithErrorResponse));

  client_->GetExistingDlcs(base::BindOnce(
      [](const std::string& err, const dlcservice::DlcsWithContent&) {
        EXPECT_EQ(dlcservice::kErrorInternal, err);
      }));
  base::RunLoop().RunUntilIdle();

  err_responses_.push_back(dbus::ErrorResponse::FromMethodCall(
      &method_call, dlcservice::kErrorInvalidDlc,
      "Some error due to bad DLC."));

  client_->GetExistingDlcs(base::BindOnce(
      [](const std::string& err, const dlcservice::DlcsWithContent&) {
        EXPECT_EQ(dlcservice::kErrorInvalidDlc, err);
      }));
  base::RunLoop().RunUntilIdle();
}

TEST_F(DlcserviceClientTest, UninstallSuccessTest) {
  responses_.push_back(dbus::Response::CreateEmpty());

  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillOnce(
          Invoke(this, &DlcserviceClientTest::CallMethodWithErrorResponse));

  DlcserviceClient::UninstallCallback callback = base::BindOnce(
      [](const std::string& err) { EXPECT_EQ(dlcservice::kErrorNone, err); });
  client_->Uninstall("some-dlc-id", std::move(callback));
  base::RunLoop().RunUntilIdle();
}

TEST_F(DlcserviceClientTest, UninstallFailureTest) {
  dbus::MethodCall method_call(dlcservice::kDlcServiceInterface,
                               dlcservice::kUninstallMethod);
  method_call.SetSerial(123);
  err_responses_.push_back(dbus::ErrorResponse::FromMethodCall(
      &method_call, dlcservice::kErrorInternal, ""));

  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillRepeatedly(
          Invoke(this, &DlcserviceClientTest::CallMethodWithErrorResponse));

  DlcserviceClient::UninstallCallback callback =
      base::BindOnce([](const std::string& err) {
        EXPECT_EQ(dlcservice::kErrorInternal, err);
      });
  client_->Uninstall("some-dlc-id", std::move(callback));
  base::RunLoop().RunUntilIdle();
}

TEST_F(DlcserviceClientTest, UninstallBusyStatusTest) {
  dbus::MethodCall method_call(dlcservice::kDlcServiceInterface,
                               dlcservice::kUninstallMethod);
  method_call.SetSerial(123);
  err_responses_.push_back(dbus::ErrorResponse::FromMethodCall(
      &method_call, dlcservice::kErrorBusy, ""));

  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillRepeatedly(
          Invoke(this, &DlcserviceClientTest::CallMethodWithErrorResponse));

  DlcserviceClient::UninstallCallback callback = base::BindOnce(
      [](const std::string& err) { EXPECT_EQ(dlcservice::kErrorBusy, err); });
  client_->Uninstall("some-dlc-id", std::move(callback));
  base::RunLoop().RunUntilIdle();
}

TEST_F(DlcserviceClientTest, PurgeSuccessTest) {
  responses_.push_back(dbus::Response::CreateEmpty());

  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillOnce(
          Invoke(this, &DlcserviceClientTest::CallMethodWithErrorResponse));

  DlcserviceClient::PurgeCallback callback = base::BindOnce(
      [](const std::string& err) { EXPECT_EQ(dlcservice::kErrorNone, err); });
  client_->Purge("some-dlc-id", std::move(callback));
  base::RunLoop().RunUntilIdle();
}

TEST_F(DlcserviceClientTest, PurgeFailureTest) {
  dbus::MethodCall method_call(dlcservice::kDlcServiceInterface,
                               dlcservice::kPurgeMethod);
  method_call.SetSerial(123);
  err_responses_.push_back(dbus::ErrorResponse::FromMethodCall(
      &method_call, dlcservice::kErrorInternal, ""));

  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillRepeatedly(
          Invoke(this, &DlcserviceClientTest::CallMethodWithErrorResponse));

  DlcserviceClient::PurgeCallback callback =
      base::BindOnce([](const std::string& err) {
        EXPECT_EQ(dlcservice::kErrorInternal, err);
      });
  client_->Purge("some-dlc-id", std::move(callback));
  base::RunLoop().RunUntilIdle();
}

TEST_F(DlcserviceClientTest, PurgeBusyStatusTest) {
  dbus::MethodCall method_call(dlcservice::kDlcServiceInterface,
                               dlcservice::kPurgeMethod);
  method_call.SetSerial(123);
  err_responses_.push_back(dbus::ErrorResponse::FromMethodCall(
      &method_call, dlcservice::kErrorBusy, ""));

  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillRepeatedly(
          Invoke(this, &DlcserviceClientTest::CallMethodWithErrorResponse));

  DlcserviceClient::PurgeCallback callback = base::BindOnce(
      [](const std::string& err) { EXPECT_EQ(dlcservice::kErrorBusy, err); });
  client_->Purge("some-dlc-id", std::move(callback));
  base::RunLoop().RunUntilIdle();
}

TEST_F(DlcserviceClientTest, InstallSuccessTest) {
  responses_.push_back(dbus::Response::CreateEmpty());

  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillOnce(
          Invoke(this, &DlcserviceClientTest::CallMethodWithErrorResponse));

  DlcserviceClient::InstallCallback install_callback =
      base::BindOnce([](const DlcserviceClient::InstallResult& install_result) {
        EXPECT_EQ(dlcservice::kErrorNone, install_result.error);
      });
  client_->Install("foo-dlc", std::move(install_callback),
                   DlcserviceClient::IgnoreProgress);
  base::RunLoop().RunUntilIdle();
}

TEST_F(DlcserviceClientTest, InstallFailureTest) {
  dbus::MethodCall method_call(dlcservice::kDlcServiceInterface,
                               dlcservice::kInstallMethod);
  method_call.SetSerial(123);
  err_responses_.push_back(dbus::ErrorResponse::FromMethodCall(
      &method_call, dlcservice::kErrorInternal, ""));

  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillOnce(
          Invoke(this, &DlcserviceClientTest::CallMethodWithErrorResponse));

  DlcserviceClient::InstallCallback install_callback =
      base::BindOnce([](const DlcserviceClient::InstallResult& install_result) {
        EXPECT_EQ(dlcservice::kErrorInternal, install_result.error);
      });
  client_->Install("foo-dlc", std::move(install_callback),
                   DlcserviceClient::IgnoreProgress);
  base::RunLoop().RunUntilIdle();
}

TEST_F(DlcserviceClientTest, InstallProgressTest) {
  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillOnce(Return());
  std::atomic<size_t> counter{0};
  DlcserviceClient::InstallCallback install_callback = base::BindOnce(
      [](const DlcserviceClient::InstallResult& install_result) {});
  DlcserviceClient::ProgressCallback progress_callback = base::BindRepeating(
      [](decltype(counter)* counter, double) { ++*counter; }, &counter);

  client_->Install({}, std::move(install_callback),
                   std::move(progress_callback));
  base::RunLoop().RunUntilIdle();
  EXPECT_EQ(0u, counter.load());

  dlcservice::DlcState dlc_state;
  dlc_state.set_state(dlcservice::DlcState::INSTALLING);
  auto signal = CreateSignal(dlc_state);

  client_->DlcStateChangedForTest(signal.get());
  base::RunLoop().RunUntilIdle();
  EXPECT_EQ(1u, counter.load());
}

TEST_F(DlcserviceClientTest, InstallProgressSkipUnheldDlcIdsTest) {
  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillOnce(Return());
  std::atomic<size_t> counter{0};
  DlcserviceClient::InstallCallback install_callback = base::BindOnce(
      [](const DlcserviceClient::InstallResult& install_result) {});
  DlcserviceClient::ProgressCallback progress_callback = base::BindRepeating(
      [](decltype(counter)* counter, double) { ++*counter; }, &counter);

  client_->Install({"foo"}, std::move(install_callback),
                   std::move(progress_callback));
  base::RunLoop().RunUntilIdle();
  EXPECT_EQ(0u, counter.load());

  dlcservice::DlcState dlc_state;
  dlc_state.set_id("bar-is-not-foo");
  dlc_state.set_state(dlcservice::DlcState::INSTALLING);
  auto signal = CreateSignal(dlc_state);

  client_->DlcStateChangedForTest(signal.get());
  base::RunLoop().RunUntilIdle();
  EXPECT_EQ(0u, counter.load());
}

TEST_F(DlcserviceClientTest, InstallBusyStatusTest) {
  dbus::MethodCall method_call(dlcservice::kDlcServiceInterface,
                               dlcservice::kInstallMethod);
  method_call.SetSerial(123);
  err_responses_.push_back(dbus::ErrorResponse::FromMethodCall(
      &method_call, dlcservice::kErrorBusy, ""));
  err_responses_.push_back(dbus::ErrorResponse::FromMethodCall(
      &method_call, dlcservice::kErrorNone, ""));

  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .WillRepeatedly(
          Invoke(this, &DlcserviceClientTest::CallMethodWithErrorResponse));

  DlcserviceClient::InstallCallback install_callback =
      base::BindOnce([](const DlcserviceClient::InstallResult& install_result) {
        EXPECT_EQ(dlcservice::kErrorNone, install_result.error);
      });
  client_->Install("foo-dlc", std::move(install_callback),
                   DlcserviceClient::IgnoreProgress);
  base::RunLoop().RunUntilIdle();
}

TEST_F(DlcserviceClientTest, PendingTaskTest) {
  const size_t kLoopCount = 3;
  EXPECT_CALL(*mock_proxy_.get(), DoCallMethodWithErrorResponse(_, _, _))
      .Times(kLoopCount)
      .WillRepeatedly(Return());
  std::atomic<size_t> counter{0};

  // All |Install()| request after the first should be queued.
  for (size_t i = 0; i < kLoopCount; ++i) {
    DlcserviceClient::InstallCallback install_callback = base::BindOnce(
        [](decltype(counter)* counter,
           const DlcserviceClient::InstallResult& install_result) {
          ++*counter;
        },
        &counter);
    client_->Install({}, std::move(install_callback),
                     DlcserviceClient::IgnoreProgress);
  }
  base::RunLoop().RunUntilIdle();
  EXPECT_EQ(0u, counter.load());

  dlcservice::DlcState dlc_state;
  dlc_state.set_state(dlcservice::DlcState::INSTALLED);
  auto signal = CreateSignal(dlc_state);

  for (size_t i = 1; i < 100; ++i) {
    client_->DlcStateChangedForTest(signal.get());
    base::RunLoop().RunUntilIdle();
    EXPECT_EQ(i <= kLoopCount ? i : kLoopCount, counter.load());
  }
}

TEST_F(DlcserviceClientTest, StateChangeObserver) {
  dlcservice::DlcState dlc_state;
  dlc_state.set_state(dlcservice::DlcState::INSTALLED);
  auto signal = CreateSignal(dlc_state);

  MockObserver observer;
  // If no observer has been added, nothing should be called.
  EXPECT_CALL(observer, OnDlcStateChanged(_)).Times(0);
  client_->DlcStateChangedForTest(signal.get());

  // Adding one observer should call once.
  EXPECT_CALL(observer, OnDlcStateChanged(_)).Times(1);
  client_->AddObserver(&observer);
  client_->DlcStateChangedForTest(signal.get());

  // Removing the observer causes nothing to be called.
  EXPECT_CALL(observer, OnDlcStateChanged(_)).Times(0);
  client_->RemoveObserver(&observer);
  client_->DlcStateChangedForTest(signal.get());
}

}  // namespace chromeos
