# Copyright 2016 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Test runners for iOS."""

import errno
import signal
import sys

import collections
import distutils.version
import logging
import os
import psutil
import re
import shutil
import subprocess
import threading
import time

import coverage_util
import gtest_utils
import iossim_util
import standard_json_util as sju
import test_apps
import xctest_utils

LOGGER = logging.getLogger(__name__)
DERIVED_DATA = os.path.expanduser('~/Library/Developer/Xcode/DerivedData')
READLINE_TIMEOUT = 180


class Error(Exception):
  """Base class for errors."""
  pass


class OtoolError(Error):
  """OTool non-zero error code"""

  def __init__(self, code):
    super(OtoolError,
          self).__init__('otool returned a non-zero return code: %s' % code)


class TestRunnerError(Error):
  """Base class for TestRunner-related errors."""
  pass


class AppLaunchError(TestRunnerError):
  """The app failed to launch."""
  pass


class AppNotFoundError(TestRunnerError):
  """The requested app was not found."""
  def __init__(self, app_path):
    super(AppNotFoundError, self).__init__(
      'App does not exist: %s' % app_path)


class SystemAlertPresentError(TestRunnerError):
  """System alert is shown on the device."""
  def __init__(self):
    super(SystemAlertPresentError, self).__init__(
      'System alert is shown on the device.')


class DeviceDetectionError(TestRunnerError):
  """Unexpected number of devices detected."""
  def __init__(self, udids):
    super(DeviceDetectionError, self).__init__(
      'Expected one device, found %s:\n%s' % (len(udids), '\n'.join(udids)))


class DeviceRestartError(TestRunnerError):
  """Error restarting a device."""
  def __init__(self):
    super(DeviceRestartError, self).__init__('Error restarting a device')


class PlugInsNotFoundError(TestRunnerError):
  """The PlugIns directory was not found."""
  def __init__(self, plugins_dir):
    super(PlugInsNotFoundError, self).__init__(
      'PlugIns directory does not exist: %s' % plugins_dir)


class SimulatorNotFoundError(TestRunnerError):
  """The given simulator binary was not found."""
  def __init__(self, iossim_path):
    super(SimulatorNotFoundError, self).__init__(
        'Simulator does not exist: %s' % iossim_path)


class TestDataExtractionError(TestRunnerError):
  """Error extracting test data or crash reports from a device."""
  def __init__(self):
    super(TestDataExtractionError, self).__init__('Failed to extract test data')


class XcodeVersionNotFoundError(TestRunnerError):
  """The requested version of Xcode was not found."""
  def __init__(self, xcode_version):
    super(XcodeVersionNotFoundError, self).__init__(
        'Xcode version not found: %s' % xcode_version)


class XCTestConfigError(TestRunnerError):
  """Error related with XCTest config."""

  def __init__(self, message):
    super(XCTestConfigError,
          self).__init__('Incorrect config related with XCTest: %s' % message)


class XCTestPlugInNotFoundError(TestRunnerError):
  """The .xctest PlugIn was not found."""
  def __init__(self, xctest_path):
    super(XCTestPlugInNotFoundError, self).__init__(
        'XCTest not found: %s' % xctest_path)


class MacToolchainNotFoundError(TestRunnerError):
  """The mac_toolchain is not specified."""
  def __init__(self, mac_toolchain):
    super(MacToolchainNotFoundError, self).__init__(
        'mac_toolchain is not specified or not found: "%s"' % mac_toolchain)


class XcodePathNotFoundError(TestRunnerError):
  """The path to Xcode.app is not specified."""
  def __init__(self, xcode_path):
    super(XcodePathNotFoundError, self).__init__(
        'xcode_path is not specified or does not exist: "%s"' % xcode_path)


class ShardingDisabledError(TestRunnerError):
  """Temporary error indicating that sharding is not yet implemented."""
  def __init__(self):
    super(ShardingDisabledError, self).__init__(
      'Sharding has not been implemented!')


def get_device_ios_version(udid):
  """Gets device iOS version.

  Args:
    udid: (str) iOS device UDID.

  Returns:
    Device UDID.
  """
  return subprocess.check_output(['ideviceinfo',
                                  '--udid', udid,
                                  '-k', 'ProductVersion']).strip()


def defaults_write(d, key, value):
  """Run 'defaults write d key value' command.

  Args:
    d: (str) A dictionary.
    key: (str) A key.
    value: (str) A value.
  """
  LOGGER.info('Run \'defaults write %s %s %s\'' % (d, key, value))
  subprocess.call(['defaults', 'write', d, key, value])


def defaults_delete(d, key):
  """Run 'defaults delete d key' command.

  Args:
    d: (str) A dictionary.
    key: (str) Key to delete.
  """
  LOGGER.info('Run \'defaults delete %s %s\'' % (d, key))
  subprocess.call(['defaults', 'delete', d, key])


def terminate_process(proc, proc_name):
  """Terminates the process.

  If an error occurs ignore it, just print out a message.

  Args:
    proc: A subprocess to terminate.
    proc_name: A name of process.
  """
  try:
    LOGGER.info('Killing hung process %s' % proc.pid)
    proc.terminate()
    attempts_to_kill = 3
    ps = psutil.Process(proc.pid)
    for _ in range(attempts_to_kill):
      # Check whether proc.pid process is still alive.
      if ps.is_running():
        LOGGER.info(
            'Process %s is still alive! %s process might block it.',
            psutil.Process(proc.pid).name(), proc_name)
        running_processes = [
            p for p in psutil.process_iter()
            # Use as_dict() to avoid API changes across versions of psutil.
            if proc_name == p.as_dict(attrs=['name'])['name']]
        if not running_processes:
          LOGGER.debug('There are no running %s processes.', proc_name)
          break
        LOGGER.debug('List of running %s processes: %s'
                     % (proc_name, running_processes))
        # Killing running processes with proc_name
        for p in running_processes:
          p.send_signal(signal.SIGKILL)
        psutil.wait_procs(running_processes)
      else:
        LOGGER.info('Process was killed!')
        break
  except OSError as ex:
    LOGGER.info('Error while killing a process: %s' % ex)


# TODO(crbug.com/1044812): Moved print_process_output to utils class.
def print_process_output(proc,
                         proc_name=None,
                         parser=None,
                         timeout=READLINE_TIMEOUT):
  """Logs process messages in console and waits until process is done.

  Method waits until no output message and if no message for timeout seconds,
  process will be terminated.

  Args:
    proc: A running process.
    proc_name: (str) A process name that has to be killed
      if no output occurs in specified timeout. Sometimes proc generates
      child process that may block its parent and for such cases
      proc_name refers to the name of child process.
      If proc_name is not specified, process name will be used to kill process.
    parser: A parser.
    timeout: A timeout(in seconds) to subprocess.stdout.readline method.
  """
  out = []
  if not proc_name:
    proc_name = psutil.Process(proc.pid).name()
  while True:
    # subprocess.stdout.readline() might be stuck from time to time
    # and tests fail because of TIMEOUT.
    # Try to fix the issue by adding timer-thread for `timeout` seconds
    # that will kill `frozen` running process if no new line is read
    # and will finish test attempt.
    # If new line appears in timeout, just cancel timer.
    try:
      timer = threading.Timer(timeout, terminate_process, [proc, proc_name])
      timer.start()
      line = proc.stdout.readline()
    finally:
      timer.cancel()
    if not line:
      break
    line = line.rstrip()
    out.append(line)
    if parser:
      parser.ProcessLine(line)
    LOGGER.info(line)
    sys.stdout.flush()
  LOGGER.debug('Finished print_process_output.')
  return out


def get_current_xcode_info():
  """Returns the current Xcode path, version, and build number.

  Returns:
    A dict with 'path', 'version', and 'build' keys.
      'path': The absolute path to the Xcode installation.
      'version': The Xcode version.
      'build': The Xcode build version.
  """
  try:
    out = subprocess.check_output(['xcodebuild', '-version']).splitlines()
    version, build_version = out[0].split(' ')[-1], out[1].split(' ')[-1]
    path = subprocess.check_output(['xcode-select', '--print-path']).rstrip()
  except subprocess.CalledProcessError:
    version = build_version = path = None

  return {
    'path': path,
    'version': version,
    'build': build_version,
  }


def get_xctest_from_app(app):
  """Gets xctest path for an app.

  Args:
    app: (str) A path to an app.

  Returns:
    The xctest path.
  """
  plugins_dir = os.path.join(app, 'PlugIns')
  if not os.path.exists(plugins_dir):
    # TODO(crbug.com/1001667): Throw error when all device unit test should run
    # with xctest.
    LOGGER.warning('PlugIns dir doesn\'t exist in app.\n')
    return None
  for plugin in os.listdir(plugins_dir):
    if plugin.endswith('.xctest'):
      return os.path.join(plugins_dir, plugin)
  # TODO(crbug.com/1001667): Throw error when all device unit test should run
  # with xctest.
  LOGGER.warning('.xctest doesn\'t exist in app PlugIns dir.\n')
  return None


class TestRunner(object):
  """Base class containing common functionality."""

  def __init__(
    self,
    app_path,
    out_dir,
    env_vars=None,
    retries=None,
    shards=None,
    test_args=None,
    test_cases=None,
    xctest=False,
  ):
    """Initializes a new instance of this class.

    Args:
      app_path: Path to the compiled .app to run.
      out_dir: Directory to emit test data into.
      env_vars: List of environment variables to pass to the test itself.
      retries: Number of times to retry failed test cases.
      test_args: List of strings to pass as arguments to the test when
        launching.
      test_cases: List of tests to be included in the test run. None or [] to
        include all tests.
      xctest: Whether or not this is an XCTest.

    Raises:
      AppNotFoundError: If the given app does not exist.
      PlugInsNotFoundError: If the PlugIns directory does not exist for XCTests.
      XcodeVersionNotFoundError: If the given Xcode version does not exist.
      XCTestPlugInNotFoundError: If the .xctest PlugIn does not exist.
    """
    app_path = os.path.abspath(app_path)
    if not os.path.exists(app_path):
      raise AppNotFoundError(app_path)

    xcode_info = get_current_xcode_info()
    LOGGER.info('Using Xcode version %s build %s at %s',
                 xcode_info['version'],
                 xcode_info['build'],
                 xcode_info['path'])

    if not os.path.exists(out_dir):
      os.makedirs(out_dir)

    self.app_name = os.path.splitext(os.path.split(app_path)[-1])[0]
    self.app_path = app_path
    self.cfbundleid = test_apps.get_bundle_id(app_path)
    self.env_vars = env_vars or []
    self.logs = collections.OrderedDict()
    self.out_dir = out_dir
    self.retries = retries or 0
    self.shards = shards or 1
    self.test_args = test_args or []
    self.test_cases = test_cases or []
    self.xctest_path = ''
    # TODO(crbug.com/1006881): Separate "running style" from "parser style"
    #  for XCtests and Gtests.
    self.xctest = xctest

    self.test_results = {}
    self.test_results['version'] = 3
    self.test_results['path_delimiter'] = '.'
    self.test_results['seconds_since_epoch'] = int(time.time())
    # This will be overwritten when the tests complete successfully.
    self.test_results['interrupted'] = True

    if self.xctest:
      plugins_dir = os.path.join(self.app_path, 'PlugIns')
      if not os.path.exists(plugins_dir):
        raise PlugInsNotFoundError(plugins_dir)
      for plugin in os.listdir(plugins_dir):
        if plugin.endswith('.xctest'):
          self.xctest_path = os.path.join(plugins_dir, plugin)
      if not os.path.exists(self.xctest_path):
        raise XCTestPlugInNotFoundError(self.xctest_path)

  def get_launch_command(self, test_app, out_dir, destination, shards=1):
    """Returns the command that can be used to launch the test app.

    Args:
      test_app: An app that stores data about test required to run.
      out_dir: (str) A path for results.
      destination: (str) A destination of device/simulator.
      shards: (int) How many shards the tests should be divided into.

    Returns:
      A list of strings forming the command to launch the test.
    """
    raise NotImplementedError

  def get_launch_env(self):
    """Returns a dict of environment variables to use to launch the test app.

    Returns:
      A dict of environment variables.
    """
    return os.environ.copy()

  def start_proc(self, cmd):
    """Starts a process with cmd command and os.environ.

    Returns:
      An instance of process.
    """
    return subprocess.Popen(
        cmd,
        env=self.get_launch_env(),
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
    )

  def shutdown_and_restart(self):
    """Restart a device or relaunch a simulator."""
    pass

  def set_up(self):
    """Performs setup actions which must occur prior to every test launch."""
    raise NotImplementedError

  def tear_down(self):
    """Performs cleanup actions which must occur after every test launch."""
    raise NotImplementedError

  def screenshot_desktop(self):
    """Saves a screenshot of the desktop in the output directory."""
    subprocess.check_call([
        'screencapture',
        os.path.join(self.out_dir, 'desktop_%s.png' % time.time()),
    ])

  def retrieve_derived_data(self):
    """Retrieves the contents of DerivedData"""
    # DerivedData contains some logs inside workspace-specific directories.
    # Since we don't control the name of the workspace or project, most of
    # the directories are just called "temporary", making it hard to tell
    # which directory we need to retrieve. Instead we just delete the
    # entire contents of this directory before starting and return the
    # entire contents after the test is over.
    if os.path.exists(DERIVED_DATA):
      os.mkdir(os.path.join(self.out_dir, 'DerivedData'))
      derived_data = os.path.join(self.out_dir, 'DerivedData')
      for directory in os.listdir(DERIVED_DATA):
        LOGGER.info('Copying %s directory', directory)
        shutil.move(os.path.join(DERIVED_DATA, directory), derived_data)

  def wipe_derived_data(self):
    """Removes the contents of Xcode's DerivedData directory."""
    if os.path.exists(DERIVED_DATA):
      shutil.rmtree(DERIVED_DATA)
      os.mkdir(DERIVED_DATA)

  def run_tests(self, cmd=None):
    """Runs passed-in tests.

    Args:
      cmd: Command to run tests.

    Return:
      out: (list) List of strings of subprocess's output.
      returncode: (int) Return code of subprocess.
    """
    raise NotImplementedError

  def set_sigterm_handler(self, handler):
    """Sets the SIGTERM handler for the test runner.

    This is its own separate function so it can be mocked in tests.

    Args:
      handler: The handler to be called when a SIGTERM is caught

    Returns:
      The previous SIGTERM handler for the test runner.
    """
    LOGGER.debug('Setting sigterm handler.')
    return signal.signal(signal.SIGTERM, handler)

  def handle_sigterm(self, proc):
    """Handles a SIGTERM sent while a test command is executing.

    Will SIGKILL the currently executing test process, then
    attempt to exit gracefully.

    Args:
      proc: The currently executing test process.
    """
    LOGGER.warning('Sigterm caught during test run. Killing test process.')
    proc.kill()

  def _run(self, cmd, shards=1):
    """Runs the specified command, parsing GTest output.

    Args:
      cmd: List of strings forming the command to run.

    Returns:
      GTestResult instance.
    """
    result = gtest_utils.GTestResult(cmd)
    if self.xctest:
      parser = xctest_utils.XCTestLogParser()
    else:
      parser = gtest_utils.GTestLogParser()

    # TODO(crbug.com/812705): Implement test sharding for unit tests.
    # TODO(crbug.com/812712): Use thread pool for DeviceTestRunner as well.
    proc = self.start_proc(cmd)
    old_handler = self.set_sigterm_handler(
        lambda _signum, _frame: self.handle_sigterm(proc))
    print_process_output(proc, 'xcodebuild', parser)
    LOGGER.info('Waiting for test process to terminate.')
    proc.wait()
    LOGGER.info('Test process terminated.')
    self.set_sigterm_handler(old_handler)
    sys.stdout.flush()
    LOGGER.debug('Stdout flushed after test process.')
    returncode = proc.returncode

    if self.xctest and parser.SystemAlertPresent():
      raise SystemAlertPresentError()

    LOGGER.debug('Processing test results.')
    for test in parser.FailedTests(include_flaky=True):
      # Test cases are named as <test group>.<test case>. If the test case
      # is prefixed with "FLAKY_", it should be reported as flaked not failed.
      if '.' in test and test.split('.', 1)[1].startswith('FLAKY_'):
        result.flaked_tests[test] = parser.FailureDescription(test)
      else:
        result.failed_tests[test] = parser.FailureDescription(test)

    result.passed_tests.extend(parser.PassedTests(include_flaky=True))

    # Only GTest outputs compiled tests in a json file.
    if not self.xctest:
      result.disabled_tests_from_compiled_tests_file.extend(
          parser.DisabledTestsFromCompiledTestsFile())

    LOGGER.info('%s returned %s\n', cmd[0], returncode)

    # xcodebuild can return 5 if it exits noncleanly even if all tests passed.
    # Therefore we cannot rely on process exit code to determine success.
    result.finalize(returncode, parser.CompletedWithoutFailure())
    return result

  def launch(self):
    """Launches the test app."""
    self.set_up()
    destination = 'id=%s' % self.udid
    if self.xctest:
      test_app = test_apps.EgtestsApp(
          self.app_path,
          included_tests=self.test_cases,
          env_vars=self.env_vars,
          test_args=self.test_args)
    elif self.xctest_path:

      if self.__class__.__name__ == 'DeviceTestRunner':
        # When self.xctest is False and (bool)self.xctest_path is True and it's
        # using a device runner, this is a XCTest hosted unit test, which is
        # currently running on real devices.
        # TODO(crbug.com/1006881): Separate "running style" from "parser style"
        # for XCtests and Gtests.
        test_app = test_apps.DeviceXCTestUnitTestsApp(
            self.app_path,
            included_tests=self.test_cases,
            env_vars=self.env_vars,
            test_args=self.test_args)
      else:
        raise XCTestConfigError('Trying to run a DeviceXCTestUnitTestsApp on a'
                                'non device runner!')

    else:
      test_app = test_apps.GTestsApp(
          self.app_path,
          included_tests=self.test_cases,
          env_vars=self.env_vars,
          test_args=self.test_args)
    out_dir = os.path.join(self.out_dir, 'TestResults')
    cmd = self.get_launch_command(test_app, out_dir, destination, self.shards)
    try:
      result = self._run(cmd=cmd, shards=self.shards or 1)
      if result.crashed and not result.crashed_test:
        # If the app crashed but not during any particular test case, assume
        # it crashed on startup. Try one more time.
        self.shutdown_and_restart()
        LOGGER.warning('Crashed on startup, retrying...\n')
        out_dir = os.path.join(self.out_dir, 'retry_after_crash_on_startup')
        cmd = self.get_launch_command(test_app, out_dir, destination,
                                      self.shards)
        result = self._run(cmd)

      if result.crashed and not result.crashed_test:
        raise AppLaunchError

      passed = result.passed_tests
      failed = result.failed_tests
      flaked = result.flaked_tests
      disabled = result.disabled_tests_from_compiled_tests_file

      try:
        while result.crashed and result.crashed_test:
          # If the app crashes during a specific test case, then resume at the
          # next test case. This is achieved by filtering out every test case
          # which has already run.
          LOGGER.warning('Crashed during %s, resuming...\n',
                         result.crashed_test)
          test_app.excluded_tests = passed + failed.keys() + flaked.keys()
          retry_out_dir = os.path.join(
              self.out_dir, 'retry_after_crash_%d' % int(time.time()))
          result = self._run(
              self.get_launch_command(
                  test_app, os.path.join(retry_out_dir, str(int(time.time()))),
                  destination))
          passed.extend(result.passed_tests)
          failed.update(result.failed_tests)
          flaked.update(result.flaked_tests)
          if not disabled:
            disabled = result.disabled_tests_from_compiled_tests_file

      except OSError as e:
        if e.errno == errno.E2BIG:
          LOGGER.error('Too many test cases to resume.')
        else:
          raise

      # Instantiate this after crash retries so that all tests have a first
      # pass before entering the retry block below.
      # For each retry that passes, we want to mark it separately as passed
      # (ie/ "FAIL PASS"), with is_flaky=True.
      output = sju.StdJson(passed=passed, failed=failed, flaked=flaked)

      # Retry failed test cases.
      retry_results = {}
      test_app.excluded_tests = []
      if self.retries and failed:
        LOGGER.warning('%s tests failed and will be retried.\n', len(failed))
        for i in xrange(self.retries):
          for test in failed.keys():
            LOGGER.info('Retry #%s for %s.\n', i + 1, test)
            test_app.included_tests = [test]
            retry_out_dir = os.path.join(self.out_dir, test + '_failed',
                                         'retry_%d' % i)
            retry_result = self._run(
                self.get_launch_command(test_app, retry_out_dir, destination))
            # If the test passed on retry, consider it flake instead of failure.
            if test in retry_result.passed_tests:
              flaked[test] = failed.pop(test)
              output.mark_passed(test, flaky=True)
            # Save the result of the latest run for each test.
            retry_results[test] = retry_result

      output.mark_all_skipped(disabled)

      # Build test_results.json.
      # Check if if any of the retries crashed in addition to the original run.
      interrupted = (result.crashed or
                     any([r.crashed for r in retry_results.values()]))
      self.test_results['interrupted'] = interrupted
      self.test_results['num_failures_by_type'] = {
        'FAIL': len(failed) + len(flaked),
        'PASS': len(passed),
      }

      self.test_results['tests'] = output.tests

      self.logs['passed tests'] = passed
      if disabled:
        self.logs['disabled tests'] = disabled
      if flaked:
        self.logs['flaked tests'] = flaked
      if failed:
        self.logs['failed tests'] = failed
      for test, log_lines in failed.iteritems():
        self.logs[test] = log_lines
      for test, log_lines in flaked.iteritems():
        self.logs[test] = log_lines

      return not failed and not interrupted
    finally:
      self.tear_down()


class SimulatorTestRunner(TestRunner):
  """Class for running tests on iossim."""

  def __init__(
      self,
      app_path,
      iossim_path,
      platform,
      version,
      out_dir,
      env_vars=None,
      retries=None,
      shards=None,
      test_args=None,
      test_cases=None,
      use_clang_coverage=False,
      wpr_tools_path='',
      xctest=False,
  ):
    """Initializes a new instance of this class.

    Args:
      app_path: Path to the compiled .app or .ipa to run.
      iossim_path: Path to the compiled iossim binary to use.
      platform: Name of the platform to simulate. Supported values can be found
        by running "iossim -l". e.g. "iPhone 5s", "iPad Retina".
      version: Version of iOS the platform should be running. Supported values
        can be found by running "iossim -l". e.g. "9.3", "8.2", "7.1".
      out_dir: Directory to emit test data into.
      env_vars: List of environment variables to pass to the test itself.
      retries: Number of times to retry failed test cases.
      test_args: List of strings to pass as arguments to the test when
        launching.
      test_cases: List of tests to be included in the test run. None or [] to
        include all tests.
      use_clang_coverage: Whether code coverage is enabled in this run.
      wpr_tools_path: Path to pre-installed WPR-related tools
      xctest: Whether or not this is an XCTest.

    Raises:
      AppNotFoundError: If the given app does not exist.
      PlugInsNotFoundError: If the PlugIns directory does not exist for XCTests.
      XcodeVersionNotFoundError: If the given Xcode version does not exist.
      XCTestPlugInNotFoundError: If the .xctest PlugIn does not exist.
    """
    super(SimulatorTestRunner, self).__init__(
        app_path,
        out_dir,
        env_vars=env_vars,
        retries=retries,
        test_args=test_args,
        test_cases=test_cases,
        xctest=xctest,
    )

    iossim_path = os.path.abspath(iossim_path)
    if not os.path.exists(iossim_path):
      raise SimulatorNotFoundError(iossim_path)

    self.homedir = ''
    self.iossim_path = iossim_path
    self.platform = platform
    self.start_time = None
    self.version = version
    self.shards = shards
    self.wpr_tools_path = wpr_tools_path
    self.udid = iossim_util.get_simulator(self.platform, self.version)
    self.use_clang_coverage = use_clang_coverage

  @staticmethod
  def kill_simulators():
    """Kills all running simulators."""
    try:
      LOGGER.info('Killing simulators.')
      subprocess.check_call([
          'pkill',
          '-9',
          '-x',
          # The simulator's name varies by Xcode version.
          'com.apple.CoreSimulator.CoreSimulatorService', # crbug.com/684305
          'iPhone Simulator', # Xcode 5
          'iOS Simulator', # Xcode 6
          'Simulator', # Xcode 7+
          'simctl', # https://crbug.com/637429
          'xcodebuild', # https://crbug.com/684305
      ])
      # If a signal was sent, wait for the simulators to actually be killed.
      time.sleep(5)
    except subprocess.CalledProcessError as e:
      if e.returncode != 1:
        # Ignore a 1 exit code (which means there were no simulators to kill).
        raise

  def wipe_simulator(self):
    """Wipes the simulator."""
    iossim_util.wipe_simulator_by_udid(self.udid)

  def get_home_directory(self):
    """Returns the simulator's home directory."""
    return iossim_util.get_home_directory(self.platform, self.version)

  def set_up(self):
    """Performs setup actions which must occur prior to every test launch."""
    self.kill_simulators()
    self.wipe_simulator()
    self.wipe_derived_data()
    self.homedir = self.get_home_directory()
    # Crash reports have a timestamp in their file name, formatted as
    # YYYY-MM-DD-HHMMSS. Save the current time in the same format so
    # we can compare and fetch crash reports from this run later on.
    self.start_time = time.strftime('%Y-%m-%d-%H%M%S', time.localtime())

  def extract_test_data(self):
    """Extracts data emitted by the test."""
    if hasattr(self, 'use_clang_coverage') and self.use_clang_coverage:
      coverage_util.move_raw_coverage_data(self.udid, self.out_dir)

    # Find the Documents directory of the test app. The app directory names
    # don't correspond with any known information, so we have to examine them
    # all until we find one with a matching CFBundleIdentifier.
    apps_dir = os.path.join(
        self.homedir, 'Containers', 'Data', 'Application')
    if os.path.exists(apps_dir):
      for appid_dir in os.listdir(apps_dir):
        docs_dir = os.path.join(apps_dir, appid_dir, 'Documents')
        metadata_plist = os.path.join(
            apps_dir,
            appid_dir,
            '.com.apple.mobile_container_manager.metadata.plist',
        )
        if os.path.exists(docs_dir) and os.path.exists(metadata_plist):
          cfbundleid = subprocess.check_output([
              '/usr/libexec/PlistBuddy',
              '-c', 'Print:MCMMetadataIdentifier',
              metadata_plist,
          ]).rstrip()
          if cfbundleid == self.cfbundleid:
            shutil.copytree(docs_dir, os.path.join(self.out_dir, 'Documents'))
            return

  def retrieve_crash_reports(self):
    """Retrieves crash reports produced by the test."""
    # A crash report's naming scheme is [app]_[timestamp]_[hostname].crash.
    # e.g. net_unittests_2014-05-13-15-0900_vm1-a1.crash.
    crash_reports_dir = os.path.expanduser(os.path.join(
        '~', 'Library', 'Logs', 'DiagnosticReports'))

    if not os.path.exists(crash_reports_dir):
      return

    for crash_report in os.listdir(crash_reports_dir):
      report_name, ext = os.path.splitext(crash_report)
      if report_name.startswith(self.app_name) and ext == '.crash':
        report_time = report_name[len(self.app_name) + 1:].split('_')[0]

        # The timestamp format in a crash report is big-endian and therefore
        # a straight string comparison works.
        if report_time > self.start_time:
          with open(os.path.join(crash_reports_dir, crash_report)) as f:
            self.logs['crash report (%s)' % report_time] = (
                f.read().splitlines())

  def tear_down(self):
    """Performs cleanup actions which must occur after every test launch."""
    LOGGER.debug('Extracting test data.')
    self.extract_test_data()
    LOGGER.debug('Retrieving crash reports.')
    self.retrieve_crash_reports()
    LOGGER.debug('Retrieving derived data.')
    self.retrieve_derived_data()
    LOGGER.debug('Making desktop screenshots.')
    self.screenshot_desktop()
    LOGGER.debug('Killing simulators.')
    self.kill_simulators()
    LOGGER.debug('Wiping simulator.')
    self.wipe_simulator()
    if os.path.exists(self.homedir):
      shutil.rmtree(self.homedir, ignore_errors=True)
      self.homedir = ''
    LOGGER.debug('End of tear_down.')

  def run_tests(self, cmd):
    """Runs passed-in tests. Builds a command and create a simulator to
      run tests.
    Args:
      cmd: A running command.

    Return:
      out: (list) List of strings of subprocess's output.
      returncode: (int) Return code of subprocess.
    """
    proc = self.start_proc(cmd)
    out = print_process_output(proc, 'xcodebuild',
                               xctest_utils.XCTestLogParser())
    self.deleteSimulator(self.udid)
    return (out, proc.returncode)

  def getSimulator(self):
    """Gets a simulator or creates a new one by device types and runtimes.
      Returns the udid for the created simulator instance.

    Returns:
      An udid of a simulator device.
    """
    return iossim_util.get_simulator(self.platform, self.version)

  def deleteSimulator(self, udid=None):
    """Removes dynamically created simulator devices."""
    if udid:
      iossim_util.delete_simulator_by_udid(udid)

  def get_launch_command(self, test_app, out_dir, destination, shards=1):
    """Returns the command that can be used to launch the test app.

    Args:
      test_app: An app that stores data about test required to run.
      out_dir: (str) A path for results.
      destination: (str) A destination of device/simulator.
      shards: (int) How many shards the tests should be divided into.

    Returns:
      A list of strings forming the command to launch the test.
    """
    return test_app.command(out_dir, destination, shards)

  def get_launch_env(self):
    """Returns a dict of environment variables to use to launch the test app.

    Returns:
      A dict of environment variables.
    """
    env = super(SimulatorTestRunner, self).get_launch_env()
    if self.xctest_path:
      env['NSUnbufferedIO'] = 'YES'
    return env


class DeviceTestRunner(TestRunner):
  """Class for running tests on devices."""

  def __init__(
    self,
    app_path,
    out_dir,
    env_vars=None,
    restart=False,
    retries=None,
    shards=None,
    test_args=None,
    test_cases=None,
    xctest=False,
  ):
    """Initializes a new instance of this class.

    Args:
      app_path: Path to the compiled .app to run.
      out_dir: Directory to emit test data into.
      env_vars: List of environment variables to pass to the test itself.
      restart: Whether or not restart device when test app crashes on startup.
      retries: Number of times to retry failed test cases.
      test_args: List of strings to pass as arguments to the test when
        launching.
      test_cases: List of tests to be included in the test run. None or [] to
        include all tests.
      xctest: Whether or not this is an XCTest.

    Raises:
      AppNotFoundError: If the given app does not exist.
      PlugInsNotFoundError: If the PlugIns directory does not exist for XCTests.
      XcodeVersionNotFoundError: If the given Xcode version does not exist.
      XCTestPlugInNotFoundError: If the .xctest PlugIn does not exist.
    """
    super(DeviceTestRunner, self).__init__(
      app_path,
      out_dir,
      env_vars=env_vars,
      retries=retries,
      test_args=test_args,
      test_cases=test_cases,
      xctest=xctest,
    )

    self.udid = subprocess.check_output(['idevice_id', '--list']).rstrip()
    if len(self.udid.splitlines()) != 1:
      raise DeviceDetectionError(self.udid)

    # GTest-based unittests are invoked via XCTest for all devices
    # but produce GTest-style log output that is parsed with a GTestLogParser.
    self.xctest_path = get_xctest_from_app(self.app_path)

    self.restart = restart

  def uninstall_apps(self):
    """Uninstalls all apps found on the device."""
    for app in self.get_installed_packages():
      cmd = ['ideviceinstaller', '--udid', self.udid, '--uninstall', app]
      print_process_output(self.start_proc(cmd))

  def install_app(self):
    """Installs the app."""
    cmd = ['ideviceinstaller', '--udid', self.udid, '--install', self.app_path]
    print_process_output(self.start_proc(cmd))

  def get_installed_packages(self):
    """Gets a list of installed packages on a device.

    Returns:
      A list of installed packages on a device.
    """
    cmd = ['idevicefs', '--udid', self.udid, 'ls', '@']
    return print_process_output(self.start_proc(cmd))

  def set_up(self):
    """Performs setup actions which must occur prior to every test launch."""
    self.uninstall_apps()
    self.wipe_derived_data()
    self.install_app()

  def extract_test_data(self):
    """Extracts data emitted by the test."""
    cmd = [
        'idevicefs',
        '--udid', self.udid,
        'pull',
        '@%s/Documents' % self.cfbundleid,
        os.path.join(self.out_dir, 'Documents'),
    ]
    try:
      print_process_output(self.start_proc(cmd))
    except subprocess.CalledProcessError:
      raise TestDataExtractionError()

  def shutdown_and_restart(self):
    """Restart the device, wait for two minutes."""
    # TODO(crbug.com/760399): swarming bot ios 11 devices turn to be unavailable
    # in a few hours unexpectedly, which is assumed as an ios beta issue. Should
    # remove this method once the bug is fixed.
    if self.restart:
      LOGGER.info('Restarting device, wait for two minutes.')
      try:
        subprocess.check_call(
          ['idevicediagnostics', 'restart', '--udid', self.udid])
      except subprocess.CalledProcessError:
        raise DeviceRestartError()
      time.sleep(120)

  def retrieve_crash_reports(self):
    """Retrieves crash reports produced by the test."""
    logs_dir = os.path.join(self.out_dir, 'Logs')
    os.mkdir(logs_dir)
    cmd = [
        'idevicecrashreport',
        '--extract',
        '--udid', self.udid,
        logs_dir,
    ]
    try:
      print_process_output(self.start_proc(cmd))
    except subprocess.CalledProcessError:
      # TODO(crbug.com/828951): Raise the exception when the bug is fixed.
      LOGGER.warning('Failed to retrieve crash reports from device.')

  def tear_down(self):
    """Performs cleanup actions which must occur after every test launch."""
    self.screenshot_desktop()
    self.retrieve_derived_data()
    self.extract_test_data()
    self.retrieve_crash_reports()
    self.uninstall_apps()

  def get_launch_command(self, test_app, out_dir, destination, shards=1):
    """Returns the command that can be used to launch the test app.

    Args:
      test_app: An app that stores data about test required to run.
      out_dir: (str) A path for results.
      destination: (str) A destination of device/simulator.
      shards: (int) How many shards the tests should be divided into.

    Returns:
      A list of strings forming the command to launch the test.
    """
    if self.xctest_path:
      return test_app.command(out_dir, destination, shards)

    cmd = [
      'idevice-app-runner',
      '--udid', self.udid,
      '--start', self.cfbundleid,
    ]
    args = []
    gtest_filter = []
    kif_filter = []

    if test_app.included_tests:
      kif_filter = test_apps.get_kif_test_filter(test_app.included_tests,
                                                 invert=False)
      gtest_filter = test_apps.get_gtest_filter(test_app.included_tests,
                                                invert=False)
    elif test_app.excluded_tests:
      kif_filter = test_apps.get_kif_test_filter(test_app.excluded_tests,
                                                 invert=True)
      gtest_filter = test_apps.get_gtest_filter(test_app.excluded_tests,
                                                invert=True)

    if kif_filter:
      cmd.extend(['-D', 'GKIF_SCENARIO_FILTER=%s' % kif_filter])
    if gtest_filter:
      args.append('--gtest_filter=%s' % gtest_filter)

    for env_var in self.env_vars:
      cmd.extend(['-D', env_var])

    if args or self.test_args:
      cmd.append('--args')
      cmd.extend(self.test_args)
      cmd.extend(args)

    return cmd

  def get_launch_env(self):
    """Returns a dict of environment variables to use to launch the test app.

    Returns:
      A dict of environment variables.
    """
    env = super(DeviceTestRunner, self).get_launch_env()
    if self.xctest_path:
      env['NSUnbufferedIO'] = 'YES'
      # e.g. ios_web_shell_egtests
      env['APP_TARGET_NAME'] = os.path.splitext(
          os.path.basename(self.app_path))[0]
      # e.g. ios_web_shell_egtests_module
      env['TEST_TARGET_NAME'] = env['APP_TARGET_NAME'] + '_module'
    return env
