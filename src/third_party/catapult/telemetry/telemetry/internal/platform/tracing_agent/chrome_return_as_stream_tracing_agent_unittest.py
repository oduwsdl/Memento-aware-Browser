# Copyright 2020 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import os
import stat
import unittest

from telemetry import decorators
from telemetry.core import cros_interface
from telemetry.internal.platform.tracing_agent import (
    chrome_tracing_agent_unittest, chrome_return_as_stream_tracing_agent)
from telemetry.testing import options_for_unittests
from telemetry.timeline import tracing_config

from devil.android import device_utils


class FakeAndroidPlatformBackend(
    chrome_tracing_agent_unittest.FakePlatformBackend):
  def __init__(self):
    super(FakeAndroidPlatformBackend, self).__init__()
    devices = device_utils.DeviceUtils.HealthyDevices(None)
    self.device = devices[0]

  def GetOSName(self):
    return 'android'

class FakeCrOSPlatformBackend(
    chrome_tracing_agent_unittest.FakePlatformBackend):
  def __init__(self):
    super(FakeCrOSPlatformBackend, self).__init__()
    remote = options_for_unittests.GetCopy().cros_remote
    remote_ssh_port = options_for_unittests.GetCopy().cros_remote_ssh_port
    self.cri = cros_interface.CrOSInterface(
        remote, remote_ssh_port,
        options_for_unittests.GetCopy().cros_ssh_identity)

  def GetOSName(self):
    return 'chromeos'


class ChromeReturnAsStreamTracingAgentTest(unittest.TestCase):
  @decorators.Enabled('android')
  def testCreateAndRemoveTraceConfigFileOnAndroid(self):
    platform_backend = FakeAndroidPlatformBackend()
    agent = (chrome_return_as_stream_tracing_agent.
             ChromeReturnAsStreamTracingAgent(platform_backend))
    self.assertIsNone(agent.trace_config_file)

    config = tracing_config.TracingConfig()
    agent._CreateTraceConfigFile(config)
    self.assertIsNotNone(agent.trace_config_file)
    self.assertTrue(platform_backend.device.PathExists(agent.trace_config_file))
    config_file_str = platform_backend.device.ReadFile(agent.trace_config_file,
                                                       as_root=True)
    self.assertEqual(agent._CreateTraceConfigFileString(config),
                     config_file_str.strip())

    config_file_path = agent.trace_config_file
    agent._RemoveTraceConfigFile()
    self.assertFalse(platform_backend.device.PathExists(config_file_path))
    self.assertIsNone(agent.trace_config_file)
    # robust to multiple file removal
    agent._RemoveTraceConfigFile()
    self.assertFalse(platform_backend.device.PathExists(config_file_path))
    self.assertIsNone(agent.trace_config_file)

  @decorators.Enabled('chromeos')
  def testCreateAndRemoveTraceConfigFileOnCrOS(self):
    platform_backend = FakeCrOSPlatformBackend()
    cri = platform_backend.cri
    agent = (chrome_return_as_stream_tracing_agent.
             ChromeReturnAsStreamTracingAgent(platform_backend))
    self.assertIsNone(agent.trace_config_file)

    config = tracing_config.TracingConfig()
    agent._CreateTraceConfigFile(config)
    self.assertIsNotNone(agent.trace_config_file)
    self.assertTrue(cri.FileExistsOnDevice(agent.trace_config_file))
    config_file_str = cri.GetFileContents(agent.trace_config_file)
    self.assertEqual(agent._CreateTraceConfigFileString(config),
                     config_file_str.strip())

    config_file_path = agent.trace_config_file
    agent._RemoveTraceConfigFile()
    self.assertFalse(cri.FileExistsOnDevice(config_file_path))
    self.assertIsNone(agent.trace_config_file)
    # robust to multiple file removal
    agent._RemoveTraceConfigFile()
    self.assertFalse(cri.FileExistsOnDevice(config_file_path))
    self.assertIsNone(agent.trace_config_file)

  @decorators.Enabled('linux', 'mac', 'win')
  def testCreateAndRemoveTraceConfigFileOnDesktop(self):
    platform_backend = (chrome_tracing_agent_unittest.
                        FakeDesktopPlatformBackend())
    agent = (chrome_return_as_stream_tracing_agent.
             ChromeReturnAsStreamTracingAgent(platform_backend))
    self.assertIsNone(agent.trace_config_file)

    config = tracing_config.TracingConfig()
    agent._CreateTraceConfigFile(config)
    self.assertIsNotNone(agent.trace_config_file)
    self.assertTrue(os.path.exists(agent.trace_config_file))
    self.assertTrue(os.stat(agent.trace_config_file).st_mode & stat.S_IROTH)
    with open(agent.trace_config_file, 'r') as f:
      config_file_str = f.read()
      self.assertEqual(agent._CreateTraceConfigFileString(config),
                       config_file_str.strip())

    config_file_path = agent.trace_config_file
    agent._RemoveTraceConfigFile()
    self.assertFalse(os.path.exists(config_file_path))
    self.assertIsNone(agent.trace_config_file)
    # robust to multiple file removal
    agent._RemoveTraceConfigFile()
    self.assertFalse(os.path.exists(config_file_path))
    self.assertIsNone(agent.trace_config_file)
