// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <getopt.h>

#include <array>
#include <chrono>
#include <iostream>

#include "absl/strings/str_cat.h"
#include "cast/common/public/service_info.h"
#include "cast/receiver/channel/static_credentials.h"
#include "cast/standalone_receiver/cast_agent.h"
#include "cast/streaming/ssrc.h"
#include "discovery/common/config.h"
#include "discovery/common/reporting_client.h"
#include "discovery/public/dns_sd_service_factory.h"
#include "discovery/public/dns_sd_service_publisher.h"
#include "platform/api/time.h"
#include "platform/api/udp_socket.h"
#include "platform/base/error.h"
#include "platform/base/ip_address.h"
#include "platform/impl/logging.h"
#include "platform/impl/network_interface.h"
#include "platform/impl/platform_client_posix.h"
#include "platform/impl/task_runner.h"
#include "platform/impl/text_trace_logging_platform.h"
#include "util/chrono_helpers.h"
#include "util/stringprintf.h"
#include "util/trace_logging.h"

namespace openscreen {
namespace cast {
namespace {

class DiscoveryReportingClient : public discovery::ReportingClient {
  void OnFatalError(Error error) override {
    OSP_LOG_FATAL << "Encountered fatal discovery error: " << error;
  }

  void OnRecoverableError(Error error) override {
    OSP_LOG_ERROR << "Encountered recoverable discovery error: " << error;
  }
};

struct DiscoveryState {
  SerialDeletePtr<discovery::DnsSdService> service;
  std::unique_ptr<DiscoveryReportingClient> reporting_client;
  std::unique_ptr<discovery::DnsSdServicePublisher<ServiceInfo>> publisher;
};

ErrorOr<std::unique_ptr<DiscoveryState>> StartDiscovery(
    TaskRunner* task_runner,
    const InterfaceInfo& interface,
    const std::string& friendly_name,
    const std::string& model_name) {
  TRACE_DEFAULT_SCOPED(TraceCategory::kStandaloneReceiver);
  discovery::Config config;

  discovery::Config::NetworkInfo::AddressFamilies supported_address_families =
      discovery::Config::NetworkInfo::kNoAddressFamily;
  if (interface.GetIpAddressV4()) {
    supported_address_families |= discovery::Config::NetworkInfo::kUseIpV4;
  }
  if (interface.GetIpAddressV6()) {
    supported_address_families |= discovery::Config::NetworkInfo::kUseIpV6;
  }
  OSP_CHECK(supported_address_families !=
            discovery::Config::NetworkInfo::kNoAddressFamily)
      << "No address families supported by the selected interface";
  config.network_info.push_back({interface, supported_address_families});

  auto state = std::make_unique<DiscoveryState>();
  state->reporting_client = std::make_unique<DiscoveryReportingClient>();
  state->service = discovery::CreateDnsSdService(
      task_runner, state->reporting_client.get(), config);

  ServiceInfo info;
  info.port = kDefaultCastPort;

  if (std::all_of(interface.hardware_address.begin(),
                  interface.hardware_address.end(),
                  [](int e) { return e == 0; })) {
    OSP_LOG_WARN
        << "Hardware address is empty. Either you are on a loopback device "
           "or getting the network interface information failed somehow.";
  }
  info.unique_id = HexEncode(interface.hardware_address);
  info.friendly_name = friendly_name;
  info.model_name = model_name;

  state->publisher =
      std::make_unique<discovery::DnsSdServicePublisher<ServiceInfo>>(
          state->service.get(), kCastV2ServiceId, ServiceInfoToDnsSdInstance);

  auto error = state->publisher->Register(info);
  if (!error.ok()) {
    return error;
  }
  return state;
}

std::unique_ptr<CastAgent> StartCastAgent(TaskRunnerImpl* task_runner,
                                          const InterfaceInfo& interface,
                                          GeneratedCredentials* creds) {
  TRACE_DEFAULT_SCOPED(TraceCategory::kStandaloneReceiver);
  auto agent = std::make_unique<CastAgent>(
      task_runner, interface, creds->provider.get(), creds->tls_credentials);
  const auto error = agent->Start();
  if (!error.ok()) {
    OSP_LOG_ERROR << "Error occurred while starting agent: " << error;
    agent.reset();
  }
  return agent;
}

void LogUsage(const char* argv0) {
  std::cerr << R"(
usage: )" << argv0
            << R"( <options> <interface>

options:
    interface
        Specifies the network interface to bind to. The interface is
        looked up from the system interface registry.
        Mandatory, as it must be known for publishing discovery.

    -p, --private-key=path-to-key: Path to OpenSSL-generated private key to be
                    used for TLS authentication. If a private key is not
                    provided, a randomly generated one will be used for this
                    session.

    -s, --developer-certificate=path-to-cert: Path to PEM file containing a
                           developer generated server root TLS certificate.
                           If a root server certificate is not provided, one
                           will be generated using a randomly generated
                           private key. Note that if a certificate path is
                           passed, the private key path is a mandatory field.

    -g, --generate-credentials: Instructs the binary to generate a private key
                                and self-signed root certificate with the CA
                                bit set to true, and then exit. The resulting
                                private key and certificate can then be used as
                                values for the -p and -s flags.

    -f, --friendly-name: Friendly name to be used for device discovery.

    -m, --model-name: Model name to be used for device discovery.

    -t, --tracing: Enable performance tracing logging.

    -v, --verbose: Enable verbose logging.

    -h, --help: Show this help message.
  )";
}

InterfaceInfo GetInterfaceInfoFromName(const char* name) {
  OSP_CHECK(name != nullptr) << "Missing mandatory argument: interface.";
  InterfaceInfo interface_info;
  std::vector<InterfaceInfo> network_interfaces = GetNetworkInterfaces();
  for (auto& interface : network_interfaces) {
    if (interface.name == name) {
      interface_info = std::move(interface);
      break;
    }
  }

  if (interface_info.name.empty()) {
    auto error_or_info = GetLoopbackInterfaceForTesting();
    if (error_or_info.has_value()) {
      if (error_or_info.value().name == name) {
        interface_info = std::move(error_or_info.value());
      }
    }
  }
  OSP_CHECK(!interface_info.name.empty()) << "Invalid interface specified.";
  return interface_info;
}

int RunStandaloneReceiver(int argc, char* argv[]) {
#if !defined(CAST_ALLOW_DEVELOPER_CERTIFICATE)
  OSP_LOG_FATAL
      << "It compiled! However cast_receiver currently only supports using a "
         "passed-in certificate and private key, and must be built with "
         "cast_allow_developer_certificate=true set in the GN args to "
         "actually do anything interesting.";
  return 1;
#endif

  // A note about modifying command line arguments: consider uniformity
  // between all Open Screen executables. If it is a platform feature
  // being exposed, consider if it applies to the standalone receiver,
  // standalone sender, osp demo, and test_main argument options.
  const struct option kArgumentOptions[] = {
      {"private-key", required_argument, nullptr, 'p'},
      {"developer-certificate", required_argument, nullptr, 'd'},
      {"generate-credentials", no_argument, nullptr, 'g'},
      {"friendly-name", required_argument, nullptr, 'f'},
      {"model-name", required_argument, nullptr, 'm'},
      {"tracing", no_argument, nullptr, 't'},
      {"verbose", no_argument, nullptr, 'v'},
      {"help", no_argument, nullptr, 'h'},

      // Discovery is enabled by default, however there are cases where it
      // needs to be disabled, such as on Mac OS X.
      {"disable-discovery", no_argument, nullptr, 'x'},
      {nullptr, 0, nullptr, 0}};

  bool is_verbose = false;
  bool discovery_enabled = true;
  std::string private_key_path;
  std::string developer_certificate_path;
  std::string friendly_name = "Cast Standalone Receiver";
  std::string model_name = "cast_standalone_receiver";
  bool should_generate_credentials = false;
  std::unique_ptr<openscreen::TextTraceLoggingPlatform> trace_logger;
  int ch = -1;
  while ((ch = getopt_long(argc, argv, "p:d:f:m:gtvhx", kArgumentOptions,
                           nullptr)) != -1) {
    switch (ch) {
      case 'p':
        private_key_path = optarg;
        break;
      case 'd':
        developer_certificate_path = optarg;
        break;
      case 'f':
        friendly_name = optarg;
        break;
      case 'm':
        model_name = optarg;
        break;
      case 'g':
        should_generate_credentials = true;
        break;
      case 't':
        trace_logger = std::make_unique<openscreen::TextTraceLoggingPlatform>();
        break;
      case 'v':
        is_verbose = true;
        break;
      case 'x':
        discovery_enabled = false;
        break;
      case 'h':
        LogUsage(argv[0]);
        return 1;
    }
  }

  SetLogLevel(is_verbose ? openscreen::LogLevel::kVerbose
                         : openscreen::LogLevel::kInfo);

  // Either -g is required, or both -p and -d.
  if (should_generate_credentials) {
    GenerateDeveloperCredentialsToFile();
    return 0;
  }
  if (private_key_path.empty() || developer_certificate_path.empty()) {
    OSP_LOG_FATAL << "You must either invoke with -g to generate credentials, "
                     "or provide both a private key path and root certificate "
                     "using -p and -d";
    return 1;
  }

  auto* const task_runner = new TaskRunnerImpl(&Clock::now);
  PlatformClientPosix::Create(milliseconds(50), milliseconds(50),
                              std::unique_ptr<TaskRunnerImpl>(task_runner));

  // Post tasks to kick-off the CastAgent and, if successful, start discovery to
  // make this standalone receiver visible to senders on the network.
  std::unique_ptr<DiscoveryState> discovery_state;
  std::unique_ptr<CastAgent> cast_agent;
  const char* interface_name = argv[optind];
  OSP_CHECK(interface_name && strlen(interface_name) > 0)
      << "No interface name provided.";

  std::string device_id =
      absl::StrCat("Standalone Receiver on ", interface_name);
  ErrorOr<GeneratedCredentials> creds = GenerateCredentials(
      device_id, private_key_path, developer_certificate_path);
  OSP_CHECK(creds.is_value()) << creds.error();
  task_runner->PostTask(
      [&, interface = GetInterfaceInfoFromName(interface_name)] {
        cast_agent = StartCastAgent(task_runner, interface, &(creds.value()));
        OSP_CHECK(cast_agent) << "Failed to start CastAgent.";

        if (discovery_enabled) {
          auto result =
              StartDiscovery(task_runner, interface, friendly_name, model_name);
          OSP_CHECK(result.is_value()) << "Failed to start discovery.";
          discovery_state = std::move(result.value());
        }
      });

  // Run the event loop until an exit is requested (e.g., the video player GUI
  // window is closed, a SIGINT or SIGTERM is received, or whatever other
  // appropriate user indication that shutdown is requested).
  task_runner->RunUntilSignaled();

  // Shutdown the Cast Agent and discovery-related entities. This may cause one
  // or more tasks to be posted, and so the TaskRunner is spun to give them a
  // chance to execute.
  discovery_state.reset();
  cast_agent.reset();
  task_runner->PostTask([task_runner] { task_runner->RequestStopSoon(); });
  task_runner->RunUntilStopped();

  PlatformClientPosix::ShutDown();
  return 0;
}

}  // namespace
}  // namespace cast
}  // namespace openscreen

int main(int argc, char* argv[]) {
  return openscreen::cast::RunStandaloneReceiver(argc, argv);
}
