# -*- coding: utf-8 -*-
# Copyright (c) 2012 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Module containing the various individual commands a builder can run."""

from __future__ import print_function

import base64
import collections
import datetime
import fnmatch
import glob
import json
import multiprocessing
import os
import re
import shutil
import subprocess
import sys
import tempfile

from google.protobuf import json_format
import six

from chromite.api.gen.chromite.api import android_pb2

from chromite.cbuildbot import swarming_lib
from chromite.cbuildbot import topology

from chromite.lib import buildbot_annotations
from chromite.lib import chroot_lib
from chromite.lib import cipd
from chromite.lib import config_lib
from chromite.lib import constants
from chromite.lib import cros_build_lib
from chromite.lib import cros_logging as logging
from chromite.lib import failures_lib
from chromite.lib import gob_util
from chromite.lib import gs
from chromite.lib import image_lib
from chromite.lib import metrics
from chromite.lib import osutils
from chromite.lib import parallel
from chromite.lib import path_util
from chromite.lib import pformat
from chromite.lib import portage_util
from chromite.lib import retry_util
from chromite.lib import sysroot_lib
from chromite.lib import timeout_util

from chromite.lib.paygen import filelib

from chromite.scripts import pushimage
from chromite.service import artifacts as artifacts_service


assert sys.version_info >= (3, 6), 'This module requires Python 3.6+'


_PACKAGE_FILE = '%(buildroot)s/src/scripts/cbuildbot_package.list'
CHROME_KEYWORDS_FILE = ('/build/%(board)s/etc/portage/package.keywords/chrome')
CHROME_UNMASK_FILE = ('/build/%(board)s/etc/portage/package.unmask/chrome')
_CROS_ARCHIVE_URL = 'CROS_ARCHIVE_URL'
_FACTORY_SHIM = 'factory_shim'
_AUTOTEST_RPC_CLIENT = ('/b/build_internal/scripts/slave-internal/autotest_rpc/'
                        'autotest_rpc_client.py')
_AUTOTEST_RPC_HOSTNAME = 'master2'
LOCAL_BUILD_FLAGS = ['--nousepkg']
UPLOADED_LIST_FILENAME = 'UPLOADED'
STATEFUL_FILE = 'stateful.tgz'
# For swarming proxy
_SWARMING_ADDITIONAL_TIMEOUT = 60 * 60
_DEFAULT_HWTEST_TIMEOUT_MINS = 1440
_SWARMING_EXPIRATION = 20 * 60
RUN_SUITE_PATH = '/usr/local/autotest/site_utils/run_suite.py'
SKYLAB_RUN_SUITE_PATH = '/usr/local/autotest/bin/run_suite_skylab'
_ABORT_SUITE_PATH = '/usr/local/autotest/site_utils/abort_suite.py'
_SKYLAB_ABORT_SUITE_PATH = '/usr/local/autotest/bin/abort_suite_skylab'
_MAX_HWTEST_CMD_RETRY = 10
SKYLAB_SUITE_BOT_POOL = 'ChromeOSSkylab-suite'
SUITE_BOT_POOL = 'default'
# Be very careful about retrying suite creation command as
# it may create multiple suites.
_MAX_HWTEST_START_CMD_RETRY = 1
# For json_dump json dictionary marker
JSON_DICT_START = '#JSON_START#'
JSON_DICT_END = '#JSON_END#'

# Filename for tarball containing Autotest server files needed for Server-Side
# Packaging.
AUTOTEST_SERVER_PACKAGE = 'autotest_server_package.tar.bz2'

# Directory within AUTOTEST_SERVER_PACKAGE where Tast files needed to run with
# Server-Side Packaging are stored.
_TAST_SSP_SUBDIR = 'tast'

# Tast files and directories to include in AUTOTEST_SERVER_PACKAGE relative to
# the build root. Public so it can be used by commands_unittest.py.
TAST_SSP_FILES = [
    'chroot/etc/tast/vars',  # Secret variables tast interprets.
    'chroot/usr/bin/remote_test_runner',  # Runs remote tests.
    'chroot/usr/bin/tast',  # Main Tast executable.
    'chroot/usr/libexec/tast/bundles',  # Dir containing test bundles.
    'chroot/usr/share/tast/data',  # Dir containing test data.
    'src/platform/tast/tools/run_tast.sh',  # Helper script to run SSP tast.
]

# =========================== Command Helpers =================================


def RunBuildScript(buildroot, cmd, chromite_cmd=False, **kwargs):
  """Run a build script, wrapping exceptions as needed.

  This wraps run(cmd, cwd=buildroot, **kwargs), adding extra logic to help
  determine the cause of command failures.
    - If a package fails to build, a PackageBuildFailure exception is thrown,
      which lists exactly which packages failed to build.
    - If the command fails for a different reason, a BuildScriptFailure
      exception is thrown.

  We detect what packages failed to build by creating a temporary status file,
  and passing that status file to parallel_emerge via the
  PARALLEL_EMERGE_STATUS_FILE variable.

  Args:
    buildroot: The root of the build directory.
    cmd: The command to run.
    chromite_cmd: Whether the command should be evaluated relative to the
      chromite/bin subdir of the |buildroot|.
    kwargs: Optional args passed to run; see cros_build_lib.run for specifics.
      In addition, if 'sudo' kwarg is True, sudo_run will be used.
  """
  assert not kwargs.get('shell', False), 'Cannot execute shell commands'
  kwargs.setdefault('cwd', buildroot)
  enter_chroot = kwargs.get('enter_chroot', False)
  sudo = kwargs.pop('sudo', False)

  if chromite_cmd:
    cmd = cmd[:]
    cmd[0] = os.path.join(buildroot, constants.CHROMITE_BIN_SUBDIR, cmd[0])
    if enter_chroot:
      cmd[0] = path_util.ToChrootPath(cmd[0])

  # If we are entering the chroot, create status file for tracking what
  # packages failed to build.
  chroot_tmp = os.path.join(buildroot, 'chroot', 'tmp')
  status_file = None
  with cros_build_lib.ContextManagerStack() as stack:
    if enter_chroot and os.path.exists(chroot_tmp):
      kwargs['extra_env'] = (kwargs.get('extra_env') or {}).copy()
      status_file = stack.Add(tempfile.NamedTemporaryFile, dir=chroot_tmp)
      kwargs['extra_env'][constants.PARALLEL_EMERGE_STATUS_FILE_ENVVAR] = \
          path_util.ToChrootPath(status_file.name)
    runcmd = cros_build_lib.run
    if sudo:
      runcmd = cros_build_lib.sudo_run
    try:
      return runcmd(cmd, **kwargs)
    except cros_build_lib.RunCommandError as ex:
      # Print the original exception.
      logging.error('\n%s', ex)

      # Check whether a specific package failed. If so, wrap the exception
      # appropriately. These failures are usually caused by a recent CL, so we
      # don't ever treat these failures as flaky.
      if status_file is not None:
        status_file.seek(0)
        failed_packages = status_file.read().split()
        if failed_packages:
          raise failures_lib.PackageBuildFailure(ex, cmd[0], failed_packages)

      # Looks like a generic failure. Raise a BuildScriptFailure.
      raise failures_lib.BuildScriptFailure(ex, cmd[0])


def ValidateClobber(buildroot):
  """Do due diligence if user wants to clobber buildroot.

  Args:
    buildroot: buildroot that's potentially clobbered.

  Returns:
    True if the clobber is ok.
  """
  cwd = os.path.dirname(os.path.realpath(__file__))
  if cwd.startswith(buildroot):
    cros_build_lib.Die('You are trying to clobber this chromite checkout!')

  if buildroot == '/':
    cros_build_lib.Die('Refusing to clobber your system!')

  if os.path.exists(buildroot):
    return cros_build_lib.BooleanPrompt(default=False)
  return True


# =========================== Main Commands ===================================


def WipeOldOutput(buildroot):
  """Wipes out build output directory.

  Args:
    buildroot: Root directory where build occurs.
    board: Delete image directories for this board name.
  """
  image_dir = os.path.join(buildroot, 'src', 'build', 'images')
  osutils.RmDir(image_dir, ignore_missing=True, sudo=True)


def MakeChroot(buildroot,
               replace,
               use_sdk,
               chrome_root=None,
               extra_env=None,
               use_image=False,
               cache_dir=None):
  """Wrapper around make_chroot."""
  cmd = ['cros_sdk', '--buildbot-log-version']
  if not use_image:
    cmd.append('--nouse-image')
  if use_sdk:
    cmd.append('--create')
  else:
    cmd.append('--bootstrap')

  if replace:
    cmd.append('--replace')

  if chrome_root:
    cmd.append('--chrome_root=%s' % chrome_root)

  if cache_dir:
    cmd += ['--cache-dir', cache_dir]

  RunBuildScript(buildroot, cmd, chromite_cmd=True, extra_env=extra_env)


def ListChrootSnapshots(buildroot):
  """Wrapper around cros_sdk --snapshot-list."""
  cmd = ['cros_sdk', '--snapshot-list']

  cmd_snapshots = RunBuildScript(
      buildroot, cmd, chromite_cmd=True, stdout=True)
  return cmd_snapshots.output.splitlines()


def RevertChrootToSnapshot(buildroot, snapshot_name):
  """Wrapper around cros_sdk --snapshot-restore."""
  cmd = ['cros_sdk', '--snapshot-restore', snapshot_name]

  result = RunBuildScript(buildroot, cmd, chromite_cmd=True, check=False)
  return result.returncode == 0


def CreateChrootSnapshot(buildroot, snapshot_name):
  """Wrapper around cros_sdk --snapshot-create."""
  cmd = ['cros_sdk', '--snapshot-create', snapshot_name]

  result = RunBuildScript(buildroot, cmd, chromite_cmd=True, check=False)
  return result.returncode == 0


def DeleteChrootSnapshot(buildroot, snapshot_name):
  """Wrapper around cros_sdk --snapshot-delete."""
  cmd = ['cros_sdk', '--snapshot-delete', snapshot_name]

  result = RunBuildScript(buildroot, cmd, chromite_cmd=True, check=False)
  return result.returncode == 0


def UpdateChroot(buildroot,
                 usepkg,
                 toolchain_boards=None,
                 extra_env=None,
                 chroot_args=None):
  """Wrapper around update_chroot.

  Args:
    buildroot: The buildroot of the current build.
    usepkg: Whether to use binary packages when setting up the toolchain.
    toolchain_boards: List of boards to always include.
    extra_env: A dictionary of environmental variables to set during generation.
    chroot_args: The args to the chroot.
  """
  cmd = ['./update_chroot']

  if not usepkg:
    cmd.extend(['--nousepkg'])

  if toolchain_boards:
    cmd.extend(['--toolchain_boards', ','.join(toolchain_boards)])

  # workaround https://crbug.com/225509
  # Building with FEATURES=separatedebug will create a dedicated tarball with
  # the debug files, and the debug files won't be in the glibc.tbz2, which is
  # where the build scripts expect them.
  extra_env_local = extra_env.copy()
  extra_env_local.setdefault('FEATURES', '')
  extra_env_local['FEATURES'] += ' -separatedebug splitdebug'

  RunBuildScript(
      buildroot,
      cmd,
      enter_chroot=True,
      chroot_args=chroot_args,
      extra_env=extra_env_local)


def SetupBoard(buildroot,
               board,
               usepkg,
               extra_env=None,
               force=False,
               profile=None,
               chroot_upgrade=True,
               chroot_args=None):
  """Wrapper around setup_board.

  Args:
    buildroot: The buildroot of the current build.
    board: The board to set up.
    usepkg: Whether to use binary packages when setting up the board.
    extra_env: A dictionary of environmental variables to set during generation.
    force: Whether to remove the board prior to setting it up.
    profile: The profile to use with this board.
    chroot_upgrade: Whether to update the chroot. If the chroot is already up to
      date, you can specify chroot_upgrade=False.
    chroot_args: The args to the chroot.
  """
  cmd = ['setup_board', '--board=%s' % board, '--accept-licenses=@CHROMEOS']

  # This isn't the greatest thing, but emerge's dependency calculation
  # isn't the speediest thing, so let callers skip this step when they
  # know the system is up-to-date already.
  if not chroot_upgrade:
    cmd.append('--skip-chroot-upgrade')

  if profile:
    cmd.append('--profile=%s' % profile)

  if not usepkg:
    # TODO(crbug.com/922144): Uses the underscore variant of an argument, will
    #  require updating tests when the arguments are cleaned up.
    cmd.extend(LOCAL_BUILD_FLAGS)

  if force:
    cmd.append('--force')

  RunBuildScript(
      buildroot,
      cmd,
      chromite_cmd=True,
      extra_env=extra_env,
      enter_chroot=True,
      chroot_args=chroot_args)


def LegacySetupBoard(buildroot,
                     board,
                     usepkg,
                     extra_env=None,
                     force=False,
                     profile=None,
                     chroot_upgrade=True,
                     chroot_args=None):
  """Wrapper around setup_board for the workspace stage only.

  This wrapper supports the old version of setup_board, and is only meant to be
  used for the workspace builders so they can support old firmware/factory
  branches.

  This function should not need to be changed until it's deleted.

  Args:
    buildroot: The buildroot of the current build.
    board: The board to set up.
    usepkg: Whether to use binary packages when setting up the board.
    extra_env: A dictionary of environmental variables to set during generation.
    force: Whether to remove the board prior to setting it up.
    profile: The profile to use with this board.
    chroot_upgrade: Whether to update the chroot. If the chroot is already up to
      date, you can specify chroot_upgrade=False.
    chroot_args: The args to the chroot.
  """
  cmd = ['./setup_board', '--board=%s' % board, '--accept_licenses=@CHROMEOS']

  # This isn't the greatest thing, but emerge's dependency calculation
  # isn't the speediest thing, so let callers skip this step when they
  # know the system is up-to-date already.
  if not chroot_upgrade:
    cmd.append('--skip_chroot_upgrade')

  if profile:
    cmd.append('--profile=%s' % profile)

  if not usepkg:
    cmd.extend(LOCAL_BUILD_FLAGS)

  if force:
    cmd.append('--force')

  RunBuildScript(
      buildroot,
      cmd,
      extra_env=extra_env,
      enter_chroot=True,
      chroot_args=chroot_args)


def BuildSDKBoard(buildroot,
                  board,
                  force=False,
                  extra_env=None,
                  chroot_args=None):
  """Wrapper around setup_host_board.

  Args:
    board (str): The name of the board.
    buildroot (str): The buildroot of the current build.
    force (bool): Whether to remove existing sysroot if it exists.
    extra_env (dict): A dictionary of environment variables to set.
    chroot_args (dict): The args to the chroot.
  """
  cmd = ['./build_sdk_board', '--board', board]
  if force:
    cmd.append('--force')

  RunBuildScript(
      buildroot,
      cmd,
      extra_env=extra_env,
      enter_chroot=True,
      chroot_args=chroot_args)


def SetupToolchains(buildroot,
                    usepkg=True,
                    create_packages=False,
                    targets=None,
                    sysroot=None,
                    boards=None,
                    output_dir=None,
                    **kwargs):
  """Install or update toolchains.

  See cros_setup_toolchains for more documentation about the arguments other
  than buildroot.

  Args:
    buildroot: str - The buildroot of the current build.
    usepkg: bool - Whether to use prebuilt packages.
    create_packages: bool - Whether to build redistributable packages.
    targets: str - Type of target for the toolchain install, e.g. 'boards'.
    sysroot: str - The sysroot in which to install the toolchains.
    boards: str|list - The board(s) whose toolchain should be installed.
    output_dir: str - The output directory.
  """
  kwargs.setdefault('chromite_cmd', True)
  kwargs.setdefault('enter_chroot', True)
  kwargs.setdefault('sudo', True)

  cmd = ['cros_setup_toolchains']
  if not usepkg:
    cmd.append('--nousepkg')
  if create_packages:
    cmd.append('--create-packages')
  if targets:
    cmd += ['--targets', targets]
  if sysroot:
    cmd += ['--sysroot', sysroot]
  if boards:
    boards_str = (boards if isinstance(boards, six.string_types)
                  else ','.join(boards))
    cmd += ['--include-boards', boards_str]
  if output_dir:
    cmd += ['--output-dir', output_dir]

  RunBuildScript(buildroot, cmd, **kwargs)


class MissingBinpkg(failures_lib.StepFailure):
  """Error class for when we are missing an essential binpkg."""


def VerifyBinpkg(buildroot, board, pkg, packages, extra_env=None):
  """Verify that an appropriate binary package exists for |pkg|.

  Using the depgraph from |packages|, check to see if |pkg| would be pulled in
  as a binary or from source.  If |pkg| isn't installed at all, then ignore it.

  Args:
    buildroot: The buildroot of the current build.
    board: The board to set up.
    pkg: The package to look for.
    packages: The list of packages that get installed on |board|.
    extra_env: A dictionary of environmental variables to set.

  Raises:
    If the package is found and is built from source, raise MissingBinpkg.
    If the package is not found, or it is installed from a binpkg, do nothing.
  """
  cmd = ['emerge-%s' % board, '-pegNuvq', '--with-bdeps=y', '--color=n'
        ] + list(packages)
  result = RunBuildScript(
      buildroot,
      cmd,
      capture_output=True,
      encoding='utf-8',
      enter_chroot=True,
      extra_env=extra_env)
  pattern = r'^\[(ebuild|binary).*%s' % re.escape(pkg)
  m = re.search(pattern, result.output, re.MULTILINE)
  if m and m.group(1) == 'ebuild':
    logging.info('(output):\n%s', result.output)
    msg = 'Cannot find prebuilts for %s on %s' % (pkg, board)
    raise MissingBinpkg(msg)


def RunLocalTryjob(buildroot, build_config, args=None, target_buildroot=None):
  """Run a local tryjob.

  Setting --git-cache-dir (probably to self._run.options.git_cache_dir) can
  have a huge impact on performance.

  This function will use cbuildbot_launch of the current checkout, which
  whatever patches are applied, but cbuildbot from the requested build.

  Args:
    buildroot: The buildroot of the current build.
    build_config: The name of the build config to build.
    args: List of strings giving additional command line arguments.
    target_buildroot: Buildroot for the tryjob. None for a tmpdir.
  """
  with osutils.TempDir() as tempdir:
    if not target_buildroot:
      target_buildroot = tempdir

    cmd = [
        'cros',
        'tryjob',
        '--local',
        '--yes',
        '--buildroot',
        target_buildroot,
        build_config,
    ]
    if args:
      cmd.extend(args)

    RunBuildScript(buildroot, cmd, chromite_cmd=True)


def Build(buildroot,
          board,
          build_autotest,
          usepkg,
          packages=(),
          skip_chroot_upgrade=True,
          extra_env=None,
          chrome_root=None,
          noretry=False,
          chroot_args=None,
          run_goma=False,
          build_all_with_goma=False,
          disable_revdep_logic=False):
  """Wrapper around build_packages.

  Args:
    buildroot: The buildroot of the current build.
    board: The board to set up.
    build_autotest: Whether to build autotest-related packages.
    usepkg: Whether to use binary packages.
    packages: Tuple of specific packages we want to build. If empty,
      build_packages will calculate a list of packages automatically.
    skip_chroot_upgrade: Whether to skip the chroot update. If the chroot is
      not yet up to date, you should specify skip_chroot_upgrade=False.
    extra_env: A dictionary of environmental variables to set during generation.
    chrome_root: The directory where chrome is stored.
    noretry: Do not retry package failures.
    chroot_args: The args to the chroot.
    build_all_with_goma: Use goma to build all board packages.
    run_goma: Set ./build_package --run_goma option, which starts and stops
      goma server in chroot while building packages.
    disable_revdep_logic: Pass --nowithrevdeps to build_packages, disabling the
      reverse dependency calculation step.
  """
  cmd = [
      './build_packages',
      '--board=%s' % board, '--accept_licenses=@CHROMEOS', '--withdebugsymbols'
  ]

  if not build_autotest:
    cmd.append('--nowithautotest')

  if skip_chroot_upgrade:
    cmd.append('--skip_chroot_upgrade')

  if not usepkg:
    cmd.extend(LOCAL_BUILD_FLAGS)

  if noretry:
    cmd.append('--nobuildretry')

  if disable_revdep_logic:
    cmd.append('--nowithrevdeps')

  if run_goma:
    cmd.append('--run_goma')

  if build_all_with_goma:
    cmd.append('--build_all_with_goma')

  if not chroot_args:
    chroot_args = []

  if chrome_root:
    chroot_args.append('--chrome_root=%s' % chrome_root)

  cmd.extend(packages)
  RunBuildScript(
      buildroot,
      cmd,
      extra_env=extra_env,
      chroot_args=chroot_args,
      enter_chroot=True)


FirmwareVersions = collections.namedtuple(
    'FirmwareVersions', ['model', 'main', 'main_rw', 'ec', 'ec_rw'])


def GetFirmwareVersionCmdResult(buildroot, board):
  """Gets the raw result output of the firmware updater version command.

  Args:
    buildroot: The buildroot of the current build.
    board: The board the firmware is for.

  Returns:
    Command execution result.
  """
  updater = os.path.join(buildroot, constants.DEFAULT_CHROOT_DIR,
                         cros_build_lib.GetSysroot(board).lstrip(os.path.sep),
                         'usr', 'sbin', 'chromeos-firmwareupdate')
  if not os.path.isfile(updater):
    return ''
  updater = path_util.ToChrootPath(updater)

  return cros_build_lib.run([updater, '-V'], enter_chroot=True,
                            capture_output=True, log_output=True,
                            encoding='utf-8', cwd=buildroot).stdout


def FindFirmwareVersions(cmd_output):
  """Finds firmware version output via regex matches against the cmd_output.

  Args:
    cmd_output: The raw output to search against.

  Returns:
    FirmwareVersions namedtuple with results.
    Each element will either be set to the string output by the firmware
    updater shellball, or None if there is no match.
  """

  # Sometimes a firmware bundle includes a special combination of RO+RW
  # firmware.  In this case, the RW firmware version is indicated with a "(RW)
  # version" field.  In other cases, the "(RW) version" field is not present.
  # Therefore, search for the "(RW)" fields first and if they aren't present,
  # fallback to the other format. e.g. just "BIOS version:".
  # TODO(aaboagye): Use JSON once the firmware updater supports it.
  main = None
  main_rw = None
  ec = None
  ec_rw = None
  model = None

  match = re.search(r'BIOS version:\s*(?P<version>.*)', cmd_output)
  if match:
    main = match.group('version')

  match = re.search(r'BIOS \(RW\) version:\s*(?P<version>.*)', cmd_output)
  if match:
    main_rw = match.group('version')

  match = re.search(r'EC version:\s*(?P<version>.*)', cmd_output)
  if match:
    ec = match.group('version')

  match = re.search(r'EC \(RW\) version:\s*(?P<version>.*)', cmd_output)
  if match:
    ec_rw = match.group('version')

  match = re.search(r'Model:\s*(?P<model>.*)', cmd_output)
  if match:
    model = match.group('model')

  return FirmwareVersions(model, main, main_rw, ec, ec_rw)


def GetAllFirmwareVersions(buildroot, board):
  """Extract firmware version for all models present.

  Args:
    buildroot: The buildroot of the current build.
    board: The board the firmware is for.

  Returns:
    A dict of FirmwareVersions namedtuple instances by model.
    Each element will be populated based on whether it was present in the
    command output.
  """
  result = {}
  cmd_result = GetFirmwareVersionCmdResult(buildroot, board)

  # There is a blank line between the version info for each model.
  firmware_version_payloads = cmd_result.split('\n\n')
  for firmware_version_payload in firmware_version_payloads:
    if 'BIOS' in firmware_version_payload:
      firmware_version = FindFirmwareVersions(firmware_version_payload)
      result[firmware_version.model] = firmware_version
  return result


def GetFirmwareVersions(buildroot, board):
  """Extract version information from the firmware updater, if one exists.

  Args:
    buildroot: The buildroot of the current build.
    board: The board the firmware is for.

  Returns:
    A FirmwareVersions namedtuple instance.
    Each element will either be set to the string output by the firmware
    updater shellball, or None if there is no firmware updater.
  """
  cmd_result = GetFirmwareVersionCmdResult(buildroot, board)
  if cmd_result:
    return FindFirmwareVersions(cmd_result)
  else:
    return FirmwareVersions(None, None, None, None, None)


def RunCrosConfigHost(buildroot, board, args, log_output=True):
  """Run the cros_config_host tool in the buildroot

  Args:
    buildroot: The buildroot of the current build.
    board: The board the build is for.
    args: List of arguments to pass.
    log_output: Whether to log the output of the cros_config_host.

  Returns:
    Output of the tool
  """
  tool = os.path.join(buildroot, constants.DEFAULT_CHROOT_DIR, 'usr', 'bin',
                      'cros_config_host')
  if not os.path.isfile(tool):
    return None
  tool = path_util.ToChrootPath(tool)

  config_fname = os.path.join(
      cros_build_lib.GetSysroot(board), 'usr', 'share', 'chromeos-config',
      'yaml', 'config.yaml')
  result = cros_build_lib.run(
      [tool, '-c', config_fname] + args,
      enter_chroot=True,
      capture_output=True,
      encoding='utf-8',
      log_output=log_output,
      cwd=buildroot,
      check=False)
  if result.returncode:
    # Show the output for debugging purposes.
    if 'No such file or directory' not in result.error:
      print('cros_config_host failed: %s\n' % result.error, file=sys.stderr)
    return None
  return result.output.strip().splitlines()


def GetModels(buildroot, board, log_output=True):
  """Obtain a list of models supported by a unified board

  This ignored whitelabel models since GoldenEye has no specific support for
  these at present.

  Args:
    buildroot: The buildroot of the current build.
    board: The board the build is for.
    log_output: Whether to log the output of the cros_config_host invocation.

  Returns:
    A list of models supported by this board, if it is a unified build; None,
    if it is not a unified build.
  """
  return RunCrosConfigHost(
      buildroot, board, ['list-models'], log_output=log_output)


def BuildImage(buildroot,
               board,
               images_to_build,
               version=None,
               builder_path=None,
               rootfs_verification=True,
               extra_env=None,
               disk_layout=None,
               chroot_args=None):
  """Run the script which builds images.

  Args:
    buildroot: The buildroot of the current build.
    board: The board of the image.
    images_to_build: The images to be built.
    version: The version of image.
    builder_path: The path of the builder to build the image.
    rootfs_verification: Whether to enable the rootfs verification.
    extra_env: A dictionary of environmental variables to set during generation.
    disk_layout: The disk layout.
    chroot_args: The args to the chroot.
  """

  # Default to base if images_to_build is passed empty.
  if not images_to_build:
    images_to_build = ['base']

  version_str = '--version=%s' % (version or '')

  builder_path_str = '--builder_path=%s' % (builder_path or '')

  cmd = [
      './build_image',
      '--board=%s' % board, '--replace', version_str, builder_path_str
  ]

  if not rootfs_verification:
    cmd += ['--noenable_rootfs_verification']

  if disk_layout:
    cmd += ['--disk_layout=%s' % disk_layout]

  cmd += images_to_build

  RunBuildScript(
      buildroot,
      cmd,
      enter_chroot=True,
      extra_env=extra_env,
      chroot_args=chroot_args)


def BuildVMImageForTesting(buildroot, board, extra_env=None, disk_layout=None):
  cmd = ['./image_to_vm.sh', '--board=%s' % board, '--test_image']

  if disk_layout:
    cmd += ['--disk_layout=%s' % disk_layout]

  RunBuildScript(buildroot, cmd, extra_env=extra_env, enter_chroot=True)


def RunTestImage(buildroot, board, image_dir, results_dir):
  """Executes test_image on the produced image in |image_dir|.

  The "test_image" script will be run as root in chroot. Running the script as
  root will allow the tests to read normally-forbidden files such as those
  owned by root. Running tests inside the chroot allows us to control
  dependencies better.

  Args:
    buildroot: The buildroot of the current build.
    board: The board the image was built for.
    image_dir: The directory in which to find the image.
    results_dir: The directory to store result files.

  Raises:
    failures_lib.BuildScriptFailure if the test script fails.
  """
  cmd = [
      'test_image',
      '--board',
      board,
      '--test_results_root',
      path_util.ToChrootPath(results_dir),
      path_util.ToChrootPath(image_dir),
  ]
  RunBuildScript(
      buildroot, cmd, enter_chroot=True, chromite_cmd=True, sudo=True)


def RunSignerTests(_buildroot, board):
  image_lib.SecurityTest(board=board)


def RunUnitTests(buildroot,
                 board,
                 blacklist=None,
                 extra_env=None,
                 build_stage=True,
                 chroot_args=None):
  cmd = ['cros_run_unit_tests', '--board=%s' % board, '--jobs=10']

  if blacklist:
    cmd += ['--blacklist_packages=%s' % ' '.join(blacklist)]

  if not build_stage:
    cmd += ['--assume-empty-sysroot']

  RunBuildScript(
      buildroot,
      cmd,
      chromite_cmd=True,
      enter_chroot=True,
      extra_env=extra_env or {},
      chroot_args=chroot_args)


def BuildAndArchiveTestResultsTarball(src_dir, buildroot):
  """Create a compressed tarball of test results.

  Args:
    src_dir: The directory containing the test results.
    buildroot: Build root directory.

  Returns:
    The name of the tarball.
  """
  target = '%s.tgz' % src_dir.rstrip(os.path.sep)
  chroot = os.path.join(buildroot, constants.DEFAULT_CHROOT_DIR)
  cros_build_lib.CreateTarball(
      target, src_dir, compression=cros_build_lib.COMP_GZIP, chroot=chroot)
  return os.path.basename(target)


# TODO(akeshet): Deprecate this undocumented type.
HWTestSuiteResult = collections.namedtuple('HWTestSuiteResult',
                                           ['to_raise', 'json_dump_result'])


@failures_lib.SetFailureType(failures_lib.SuiteTimedOut,
                             timeout_util.TimeoutError)
def RunHWTestSuite(build,
                   suite,
                   board,
                   model=None,
                   pool=None,
                   file_bugs=None,
                   wait_for_results=None,
                   priority=None,
                   timeout_mins=None,
                   max_runtime_mins=None,
                   retry=None,
                   max_retries=None,
                   minimum_duts=0,
                   suite_min_duts=0,
                   suite_args=None,
                   offload_failures_only=None,
                   debug=True,
                   skip_duts_check=False,
                   job_keyvals=None,
                   test_args=None):
  """Run the test suite in the Autotest lab.

  Args:
    build: The build is described as the bot_id and the build version.
      e.g. x86-mario-release/R18-1655.0.0-a1-b1584.
    suite: Name of the Autotest suite.
    board: The board the test suite should be scheduled against.
    model: A specific model to schedule the test suite against.
    pool: The pool of machines we should use to run the hw tests on.
    file_bugs: File bugs on test failures for this suite run.
    wait_for_results: If True, wait for autotest results before returning.
    priority: Priority of this suite run.
    timeout_mins: Timeout in minutes for the suite job and its sub-jobs.
    max_runtime_mins: Maximum runtime for the suite job and its sub-jobs.
    retry: If True, will enable job-level retry. Only works when
           wait_for_results is True.
    max_retries: Integer, maximum job retries allowed at suite level.
                 None for no max.
    minimum_duts: The minimum number of DUTs should be available in lab for the
                  suite job to be created. If it's set to 0, the check will be
                  skipped.
    suite_min_duts: Preferred minimum duts, lab will prioritize on getting
                    such many duts even if the suite is competing with
                    a suite that has higher priority.
    suite_args: Arguments passed to the suite.  This should be a dict
                representing keyword arguments.  The value is marshalled
                using repr(), so the dict values should be basic types.
    offload_failures_only: Only offload failed tests to Google Storage.
    debug: Whether we are in debug mode.
    skip_duts_check: If True, skip minimum available DUTs check.
    job_keyvals: A dict of job keyvals to be inject to suite control file.
    test_args: A dict of test parameters to be inject to suite control file.

  Returns:
    An instance of named tuple HWTestSuiteResult, the first element is the
    exception to be raised; the second element is the json dump cmd result,
    if json_dump cmd is not called, None will be returned.
  """
  try:
    cmd = [RUN_SUITE_PATH]
    cmd += _GetRunSuiteArgs(
        build,
        suite,
        board,
        model=model,
        pool=pool,
        file_bugs=file_bugs,
        priority=priority,
        timeout_mins=timeout_mins,
        max_runtime_mins=max_runtime_mins,
        retry=retry,
        max_retries=max_retries,
        minimum_duts=minimum_duts,
        suite_min_duts=suite_min_duts,
        suite_args=suite_args,
        offload_failures_only=offload_failures_only,
        subsystems=set([]),
        skip_duts_check=skip_duts_check,
        job_keyvals=job_keyvals,
        test_args=test_args)
    swarming_args = _CreateSwarmingArgs(build, suite, board, priority,
                                        timeout_mins)
    running_json_dump_flag = False
    json_dump_result = None
    job_id = _HWTestCreate(cmd, debug, **swarming_args)
    if job_id:
      if wait_for_results:
        pass_hwtest = _HWTestWait(cmd, job_id, **swarming_args)
      if wait_for_results:
        # Only dump the json output when tests don't pass, since the json
        # output is used to decide whether we can do subsystem based partial
        # submission.
        running_json_dump_flag = not pass_hwtest
        if running_json_dump_flag:
          json_dump_result = retry_util.RetryException(
              ValueError, 3, _HWTestDumpJson, cmd, job_id, **swarming_args)
    return HWTestSuiteResult(None, json_dump_result)
  except cros_build_lib.RunCommandError as e:
    result = e.result
    if not result.HasValidSummary():
      # swarming client has failed.
      logging.error('No valid task summary json generated, output:%s',
                    result.output)
      if result.task_summary_json:
        logging.error('Invalid task summary json:\n%s',
                      pformat.json(result.task_summary_json))
      to_raise = failures_lib.SwarmingProxyFailure(
          '** Failed to fullfill request with proxy server, code(%d) **' %
          result.returncode)
    elif result.GetValue('internal_failure'):
      logging.error(
          'Encountered swarming internal error:\n'
          'stdout: \n%s\n'
          'summary json content:\n%s', result.output,
          str(result.task_summary_json))
      to_raise = failures_lib.SwarmingProxyFailure(
          '** Failed to fullfill request with proxy server, code(%d) **' %
          result.returncode)
    else:
      logging.debug(
          'swarming info: name: %s, bot_id: %s, task_id: %s, '
          'created_ts: %s', result.GetValue('name'), result.GetValue('bot_id'),
          result.GetValue('id'), result.GetValue('created_ts'))
      # If running json_dump cmd, write the pass/fail subsys dict into console,
      # otherwise, write the cmd output to the console.
      outputs = result.GetValue('outputs', '')
      if running_json_dump_flag:
        s = ''.join(outputs)
        sys.stdout.write(s)
        sys.stdout.write('\n')
        try:
          # If we can't parse the JSON dump, subsystem based partial submission
          # will be skipped due to missing information about which individual
          # tests passed. This can happen for example when the JSON dump step
          # fails due to connectivity issues in which case we'll have no output
          # to parse. It's OK to just assume complete test failure in this case
          # though: since we don't know better anyways, we need to err on the
          # safe side and not submit any change. So we just log an error below
          # instead of raising an exception and allow the subsequent logic to
          # decide which failure condition to report. This is in the hope that
          # providing more information from the RunCommandError we encountered
          # will be useful in diagnosing the root cause of the failure.
          json_dump_result = _HWTestParseJSONDump(s)
        except ValueError as e:
          logging.error(
              'Failed to parse HWTest JSON dump string, '
              'subsystem based partial submission will be skipped:  %s', e)
      else:
        for output in outputs:
          sys.stdout.write(output)
        sys.stdout.flush()
      # swarming client has submitted task and returned task information.
      lab_warning_codes = (2,)
      infra_error_codes = (3,)
      timeout_codes = (4,)
      board_not_available_codes = (5,)
      proxy_failure_codes = (241,)

      if result.returncode in lab_warning_codes:
        to_raise = failures_lib.TestWarning(
            '** Suite passed with a warning code **')
      elif (result.returncode in infra_error_codes or
            result.returncode in proxy_failure_codes):
        to_raise = failures_lib.TestLabFailure(
            '** HWTest did not complete due to infrastructure issues '
            '(code %d) **' % result.returncode)
      elif result.returncode in timeout_codes:
        to_raise = failures_lib.SuiteTimedOut(
            '** Suite timed out before completion **')
      elif result.returncode in board_not_available_codes:
        to_raise = failures_lib.BoardNotAvailable(
            '** Board was not availble in the lab **')
      elif result.returncode != 0:
        to_raise = failures_lib.TestFailure(
            '** HWTest failed (code %d) **' % result.returncode)
      elif json_dump_result is None:
        to_raise = failures_lib.TestFailure('** Failed to decode JSON dump **')
    return HWTestSuiteResult(to_raise, json_dump_result)


def _GetSkylabWaitTaskArgs(task_id, timeout_mins=None):
  """Get arguments for the `skylab wait-task` command.

  Args:
    timeout_mins: maximum number of minutes to wait for task completion.
    task_id: id of the task to wait for.

  Returns:
    List of args for `skylab wait-task`, not including the subcommand itself.
  """
  args = ['-service-account-json', constants.CHROMEOS_SERVICE_ACCOUNT]
  if timeout_mins is not None:
    args += ['-timeout-mins', str(timeout_mins)]
  args += [task_id]
  return args


def _GetSkylabCreateSuiteArgs(build,
                              suite,
                              board,
                              pool,
                              model=None,
                              priority=None,
                              timeout_mins=None,
                              max_retries=None,
                              job_keyvals=None,
                              quota_account=None):
  """Get arguments for the `skylab create-suite` command.

  Command will run in -json mode.

  Args:
    build: string image name to use, e.g. elm-paladin/R99-12345
    suite: suite name to run
    board: board name to run suite for
    pool: pool to run the suite in
    model: (optional) model name to run suite for
    priority: (optional) integer priority for the suite. Higher number is a
        lower priority
    timeout_mins: (optional) suite timeout
    max_retries: (optional) max retries allowed across all child tasks
    job_keyvals: (optional) dictionary of {'key': 'value'} keyvals to be
                 injected into all children of suite.
    quota_account: (optional) quotascheduler account to use for child tasks

  Returns:
    A list of args for the `skylab create-suite` subcommand (not including)
    the subcommand itself.
  """
  args = ['-image', build, '-board', board]
  if model:
    args += ['-model', model]

  if pool is not None:
    args += ['-pool', pool]

  if priority is not None:
    args += ['-priority', str(priority)]

  if timeout_mins is not None:
    args += ['-timeout-mins', str(timeout_mins)]

  if max_retries is not None:
    args += ['-max-retries', str(max_retries)]

  if job_keyvals is not None:
    for key, value in job_keyvals.items():
      args += ['-keyval', '%s:%s' % (key, value)]

  if quota_account is not None:
    args += ['-qs-account', quota_account]

  args += ['-json']

  args += ['-service-account-json', constants.CHROMEOS_SERVICE_ACCOUNT]

  args += [suite]

  return args


def _InstallSkylabTool():
  """Install skylab tool.

  Returns:
    the path of installed skylab tool.
  """
  instance_id = cipd.GetInstanceID(cipd.GetCIPDFromCache(),
                                   constants.CIPD_SKYLAB_PACKAGE, 'latest')
  cache_dir = os.path.join(path_util.GetCacheDir(), 'cipd/packages')
  path = cipd.InstallPackage(cipd.GetCIPDFromCache(),
                             constants.CIPD_SKYLAB_PACKAGE, instance_id,
                             cache_dir)
  return os.path.join(path, 'skylab')


# pylint: disable=docstring-missing-args
def _SkylabCreateTestArgs(build,
                          pool,
                          test_name,
                          board=None,
                          model=None,
                          timeout_mins=None,
                          tags=None,
                          keyvals=None,
                          test_args=None):
  """Get a list of args for skylab create-test.

  Args:
    See args of RunSkylabHWTEST.

  Returns:
    A list of string args for skylab create-test.
  """
  args = ['-image', build]
  args += ['-pool', 'DUT_POOL_%s' % pool.upper()]
  if board is None and model is None:
    raise ValueError('Need to specify either board or model.')

  if board is not None:
    args += ['-board', board]

  if model is not None:
    args += ['-model', model]

  if timeout_mins is not None:
    args += ['-timeout-mins', str(timeout_mins)]

  if tags is not None:
    for tag in tags:
      args += ['-tag', tag]

  if keyvals is not None:
    for k in keyvals:
      args += ['-keyval', k]

  if test_args is not None:
    args += ['-test-args', test_args]

  args += ['-service-account-json', constants.CHROMEOS_SERVICE_ACCOUNT]

  return args + [test_name]

# TODO(crbug.com/1008919): Remove 120 default once config is properly set
# with default timeouts.
def RunSkylabHWTest(build,
                    pool,
                    test_name,
                    shown_test_name=None,
                    board=None,
                    model=None,
                    timeout_mins=120,
                    tags=None,
                    keyvals=None,
                    test_args=None):
  """Run a skylab test in the Autotest lab using skylab tool.

  Args:
    build: A string full image name.
    pool: A string pool to run the test on.
    test_name: A string testname to run.
    shown_test_name: A string to print the test in cbuildbot. Usually it's the
                     same as test_name. But for parameterized tests, it could
                     vary due to different test_args, e.g. for paygen au tests:
                       test_name: autoupdate_EndToEndTest
                       shown_test_name:
                         autoupdate_EndToEndTest_paygen_au_beta_full_11316.66.0
    board: A string board to run the test on.
    model: A string model to run the test on.
    timeout_mins: An integer to indicate the test's timeout.
    tags: A list of strings to tag the task in swarming.
    keyvals: A list of strings to be passed to the test as job_keyvals.
    test_args: A string to be passed to the test as arguments. The format is:
               'X1=Y1 X2=Y2 X3=Y3 ...'

  Returns:
    A swarming task link if the test is created successfully.
  """
  if shown_test_name is None:
    shown_test_name = test_name

  skylab_path = _InstallSkylabTool()
  args = _SkylabCreateTestArgs(build, pool, test_name, board, model,
                               timeout_mins, tags, keyvals, test_args)
  try:
    result = cros_build_lib.run(
        [skylab_path, 'create-test'] + args, stdout=True)
    return HWTestSuiteResult(None, None)
  except cros_build_lib.RunCommandError as e:
    result = e.result
    to_raise = failures_lib.TestFailure(
        '** HWTest failed (code %d) **' % result.returncode)
    return HWTestSuiteResult(to_raise, None)
  finally:
    # This is required to output buildbot annotations, e.g. 'STEP_LINKS'.
    output = result.output.strip()
    # The format of output is:
    #   Created Swarming task https://chromeos-swarming.appspot.com/task?id=XX
    sys.stdout.write('%s \n' % output)
    sys.stdout.write('######## Output for buildbot annotations ######## \n')
    sys.stdout.write('%s \n' % str(
        buildbot_annotations.StepLink(shown_test_name,
                                      output.split()[-1])))
    sys.stdout.write('######## END Output for buildbot annotations ######## \n')
    sys.stdout.flush()


# pylint: disable=docstring-missing-args
@failures_lib.SetFailureType(failures_lib.SuiteTimedOut,
                             timeout_util.TimeoutError)
def RunSkylabHWTestSuite(
    build,
    suite,
    board,
    model=None,
    # TODO(akeshet): Make this required argument a positional arg.
    pool=None,
    wait_for_results=False,
    priority=None,
    timeout_mins=120,
    # TODO(akeshet): Delete this ignored argument.
    retry=None,
    max_retries=None,
    # TODO(akeshet): Delete this ignored argument.
    suite_args=None,
    job_keyvals=None,
    quota_account=None):
  """Run the test suite in the Autotest lab using Skylab.

  Args:
    See args of RunHWTestSuite.

  Returns:
    See returns of RunHWTestSuite.
  """
  if suite_args:
    logging.warning(
        'Skylab suites do not support suite_args, although they '
        'were specified: %s', suite_args)

  if retry:
    logging.warning(
        'Skylab suites do not support retry arg, although it '
        'was specified: %s', retry)

  if not pool:
    raise ValueError('|pool| argument is required in Skylab, but was not '
                     'supplied.')

  if priority:
    priority = constants.SKYLAB_HWTEST_PRIORITIES_MAP[str(priority)]

  skylab_tool = _InstallSkylabTool()

  cmd = [skylab_tool, 'create-suite']

  cmd += _GetSkylabCreateSuiteArgs(
      build,
      suite,
      board,
      pool,
      model=model,
      priority=priority,
      timeout_mins=timeout_mins,
      max_retries=max_retries,
      job_keyvals=job_keyvals,
      quota_account=quota_account)

  try:
    output = cros_build_lib.run(cmd, stdout=True)
    report = json.loads(output.output)
    task_id = report['task_id']
    task_url = report['task_url']

    logging.info('Launched suite task %s', task_url)
    logging.PrintBuildbotLink('Suite task: %s' % suite, task_url)
    if not wait_for_results:
      return HWTestSuiteResult(None, None)

    wait_cmd = [skylab_tool, 'wait-task'] + _GetSkylabWaitTaskArgs(
        task_id, timeout_mins=timeout_mins)
    output = cros_build_lib.run(wait_cmd, stdout=True)
    try:
      report = json.loads(output.output)
    except:
      logging.error('Error when json parsing:\n%s', output.output)
      raise

    logging.info(
        'Suite ended in state %s (success=%s) with output:\n%s',
        report['task-result']['state'],
        report['task-result']['success'],
        report['stdout'],
    )

    error = None
    if not report['task-result']['success']:
      error = failures_lib.TestFailure('Suite failed.')

    return HWTestSuiteResult(error, None)

  except cros_build_lib.RunCommandError as e:
    result = e.result
    to_raise = failures_lib.TestFailure(
        '** HWTest failed (code %d) **' % result.returncode)
    return HWTestSuiteResult(to_raise, None)


def RunSkylabHWTestPlan(test_plan=None,
                        build=None,
                        legacy_suite=None,
                        pool=None,
                        board=None,
                        model=None,
                        timeout_mins=120,
                        tags=None,
                        keyvals=None):
  """Run a skylab test in the Autotest lab using skylab tool.

  Args:
    test_plan: A JSONpb string containing a TestPlan object.
    build: A string full image name.
    legacy_suite: A string suite name, if non-empty it overrides the test plan
                  on the autotest backend.
    pool: A string pool to run the test on.
    board: A string board to run the test on.
    model: A string model to run the test on.
    timeout_mins: An integer to indicate the test's timeout.
    tags: A list of strings to tag the task in swarming.
    keyvals: A list of strings to be passed to the test as job_keyvals.
  """
  if not test_plan:
    raise ValueError('Need to specify test plan.')
  if not build:
    raise ValueError('Need to specify build.')
  if not (board or model):
    raise ValueError('Need to specify either board or model.')

  args = ['-image', build]

  if legacy_suite:
    args += ['-legacy-suite', legacy_suite]

  if pool:
    args += ['-pool', pool]

  if board:
    args += ['-board', board]

  if model:
    args += ['-model', model]

  if timeout_mins:
    args += ['-timeout-mins', str(timeout_mins)]

  if tags:
    for tag in tags:
      args += ['-tag', tag]

  if keyvals is not None:
    for k, v in keyvals.items():
      args += ['-keyval', k+':'+v]

  args += ['-service-account-json', constants.CHROMEOS_SERVICE_ACCOUNT]

  args += ['-plan-file', '/dev/stdin']

  skylab_path = _InstallSkylabTool()

  try:
    result = cros_build_lib.run(
        [skylab_path, 'create-testplan'] + args,
        stdout=True,
        input=test_plan)

    task_url = ''
    try:
      report = json.loads(result.output)
      task_url = report.get('task_url')

      logging.info('Launched test plan task %s', task_url)
      logging.PrintBuildbotLink('Test plan task', task_url)

    except ValueError:
      logging.warning('Unable to parse output:\n%s', result.output)

    return HWTestSuiteResult(None, None)
  except cros_build_lib.RunCommandError as e:
    result = e.result
    to_raise = failures_lib.TestFailure(
        '** HWTest failed (code %d) **' % result.returncode)
    return HWTestSuiteResult(to_raise, None)


# pylint: disable=docstring-missing-args
def _GetRunSuiteArgs(build,
                     suite,
                     board,
                     model=None,
                     pool=None,
                     file_bugs=None,
                     priority=None,
                     timeout_mins=None,
                     max_runtime_mins=None,
                     retry=None,
                     max_retries=None,
                     minimum_duts=0,
                     suite_min_duts=0,
                     suite_args=None,
                     offload_failures_only=None,
                     subsystems=frozenset(),
                     skip_duts_check=False,
                     job_keyvals=None,
                     test_args=None):
  """Get a list of args for run_suite.

  Args:
    See RunHWTestSuite.

  Returns:
    A list of args for run_suite
  """
  args = ['--build', build, '--board', board]

  if model:
    args += ['--model', model]

  if subsystems:
    args += ['--suite_name', 'suite_attr_wrapper']
  else:
    args += ['--suite_name', suite]

  # Add optional arguments to command, if present.
  if pool is not None:
    args += ['--pool', pool]

  if file_bugs is not None:
    args += ['--file_bugs', str(file_bugs)]

  if priority is not None:
    args += ['--priority', str(priority)]

  if timeout_mins is not None:
    args += ['--timeout_mins', str(timeout_mins)]
    # The default for max_runtime_mins is one day. We increase this if longer
    # timeouts are requested to avoid premature (and unexpected) aborts.
    if not max_runtime_mins and timeout_mins > 1440:
      args += ['--max_runtime_mins', str(timeout_mins)]

  if max_runtime_mins is not None:
    args += ['--max_runtime_mins', str(max_runtime_mins)]

  if retry is not None:
    args += ['--retry', str(retry)]

  if max_retries is not None:
    args += ['--max_retries', str(max_retries)]

  if minimum_duts != 0:
    args += ['--minimum_duts', str(minimum_duts)]

  if suite_min_duts != 0:
    args += ['--suite_min_duts', str(suite_min_duts)]

  if suite_args is not None:
    args += ['--suite_args', repr(suite_args)]

  if offload_failures_only is not None:
    args += ['--offload_failures_only', str(offload_failures_only)]

  if subsystems:
    subsystem_attr = ['subsystem:%s' % x for x in subsystems]
    subsystems_attr_str = ' or '.join(subsystem_attr)

    if suite != 'suite_attr_wrapper':
      suite_attr_str = 'suite:%s' % suite
      attr_value = '(%s) and (%s)' % (suite_attr_str, subsystems_attr_str)
    else:
      attr_value = subsystems_attr_str

    suite_args_dict = repr({'attr_filter': attr_value})
    args += ['--suite_args', suite_args_dict]

    if skip_duts_check:
      args += ['--skip_duts_check']

  if job_keyvals:
    args += ['--job_keyvals', repr(job_keyvals)]

  if test_args:
    args += ['--test_args', repr(test_args)]

  return args


# pylint: enable=docstring-missing-args


def _CreateSwarmingArgs(build,
                        suite,
                        board,
                        priority,
                        timeout_mins=None,
                        run_skylab=False):
  """Create args for swarming client.

  Args:
    build: Name of the build, will be part of the swarming task name.
    suite: Name of the suite, will be part of the swarming task name.
    timeout_mins: run_suite timeout mins, will be used to figure out
                  timeouts for swarming task.
    board: Name of the board.
    priority: A String, e.g. CQ, representing the priority of this call.
    run_skylab: Indicate whether to create a swarming cmd for Skylab HWTest.

  Returns:
    A dictionary of args for swarming client.
  """

  swarming_timeout = timeout_mins or _DEFAULT_HWTEST_TIMEOUT_MINS
  swarming_timeout = swarming_timeout * 60 + _SWARMING_ADDITIONAL_TIMEOUT

  priority_num = None
  if run_skylab:
    swarming_server = topology.topology.get(
        topology.CHROME_SWARMING_PROXY_HOST_KEY)
    pool = SKYLAB_SUITE_BOT_POOL
    if priority:
      priority_num = constants.SKYLAB_HWTEST_PRIORITIES_MAP[str(priority)]
  else:
    swarming_server = topology.topology.get(topology.SWARMING_PROXY_HOST_KEY)
    pool = SUITE_BOT_POOL

  tags = {
      'task_name': '-'.join([build, suite]),
      'build': build,
      'suite': suite,
      'board': board,
      'priority': priority,
  }
  if run_skylab:
    tags['luci_project'] = 'chromeos'
    tags['skylab'] = 'run_suite'

  return {
      'swarming_server': swarming_server,
      'task_name': '-'.join([build, suite]),
      'priority': priority_num,
      'dimensions': [('os', 'Ubuntu-14.04'), ('pool', pool)],
      'print_status_updates': True,
      'timeout_secs': swarming_timeout,
      'io_timeout_secs': swarming_timeout,
      'hard_timeout_secs': swarming_timeout,
      'expiration_secs': _SWARMING_EXPIRATION,
      'tags': tags,
      'service_account_json': constants.CHROMEOS_SERVICE_ACCOUNT,
  }


def _HWTestCreate(cmd, debug=False, **kwargs):
  """Start a suite in the HWTest lab, and return its id.

  This method runs a command to create the suite. Since we are using
  swarming client, which contiuously send request to swarming server
  to poll task result, there is no need to retry on any network
  related failures.

  Args:
    cmd: Proxied run_suite command.
    debug: If True, log command rather than running it.
    kwargs: args to be passed to RunSwarmingCommand.

  Returns:
    Job id of created suite. Returned id will be None if no job id was created.
  """
  # Start the suite.
  start_cmd = list(cmd) + ['-c']

  if debug:
    logging.info('RunHWTestSuite would run: %s',
                 cros_build_lib.CmdToStr(start_cmd))
  else:
    result = swarming_lib.RunSwarmingCommandWithRetries(
        max_retry=_MAX_HWTEST_START_CMD_RETRY,
        error_check=swarming_lib.SwarmingRetriableErrorCheck,
        cmd=start_cmd,
        capture_output=True,
        encoding='utf-8',
        stderr=subprocess.STDOUT,
        **kwargs)
    # If the command succeeds, result.task_summary_json
    # should have the right content.
    for output in result.GetValue('outputs', ''):
      sys.stdout.write(output)
    sys.stdout.flush()
    m = re.search(r'Created task id: (?P<job_id>.*)', result.output)
    if m:
      return m.group('job_id')
  return None


def _HWTestWait(cmd, job_id, **kwargs):
  """Wait for HWTest suite to complete.

  Wait for the HWTest suite to complete. All the test related exceptions will
  be mute(swarming client side exception), only the swarming server side
  exception will be raised, e.g. swarming internal failure. The test related
  exception will be raised in _HWTestDumpJson step.

  Args:
    cmd: Proxied run_suite command.
    job_id: The job id of the suite that was created.
    kwargs: args to be passed to RunSwarmingCommand.

  Returns:
    True if all tests pass.
  """
  # Wait on the suite
  wait_cmd = list(cmd) + ['-m', str(job_id)]
  pass_hwtest = False
  try:
    result = swarming_lib.RunSwarmingCommandWithRetries(
        max_retry=_MAX_HWTEST_CMD_RETRY,
        error_check=swarming_lib.SwarmingRetriableErrorCheck,
        cmd=wait_cmd,
        capture_output=True,
        encoding='utf-8',
        stderr=subprocess.STDOUT,
        **kwargs)
    pass_hwtest = True
  except cros_build_lib.RunCommandError as e:
    result = e.result
    # Delay the lab-related exceptions, since those will be raised in the next
    # json_dump cmd run.
    if (not result.task_summary_json or not result.GetValue('outputs') or
        result.GetValue('internal_failure')):
      raise
    else:
      logging.error(
          'wait_cmd has lab failures: %s.\nException will be raised '
          'in the next json_dump run.', e.msg)
  for output in result.GetValue('outputs', ''):
    sys.stdout.write(output)
  sys.stdout.flush()

  return pass_hwtest


def _HWTestParseJSONDump(dump_output):
  """Parses JSON dump output and returns the parsed JSON dict.

  Args:
    dump_output: The string containing the HWTest result JSON dictionary to
        parse, marked up with #JSON_START# and #JSON_END# start/end delimiters.

  Returns:
    Decoded JSON dict. May raise ValueError upon failure to pass the embedded
    JSON object.
  """
  i = dump_output.find(JSON_DICT_START) + len(JSON_DICT_START)
  j = dump_output.find(JSON_DICT_END)
  if i == -1 or j == -1 or i > j:
    raise ValueError('Invalid swarming output: %s' % dump_output)
  return json.loads(dump_output[i:j])


def _HWTestDumpJson(cmd, job_id, **kwargs):
  """Consume HWTest suite json output and return passed/failed subsystems dict.

  Args:
    cmd: Proxied run_suite command.
    job_id: The job id of the suite that was created.
    kwargs: args to be passed to RunSwarmingCommand.

  Returns:
    The parsed json_dump dictionary.
  """
  dump_json_cmd = list(cmd) + ['--json_dump', '-m', str(job_id)]
  result = swarming_lib.RunSwarmingCommandWithRetries(
      max_retry=_MAX_HWTEST_CMD_RETRY,
      error_check=swarming_lib.SwarmingRetriableErrorCheck,
      cmd=dump_json_cmd,
      capture_output=True,
      encoding='utf-8',
      stderr=subprocess.STDOUT,
      **kwargs)
  for output in result.GetValue('outputs', ''):
    sys.stdout.write(output)
  sys.stdout.write('\n')
  sys.stdout.flush()
  return _HWTestParseJSONDump(''.join(result.GetValue('outputs', '')))


def AbortHWTests(config_type_or_name, version, debug, suite=''):
  """Abort the specified hardware tests for the given bot(s).

  Args:
    config_type_or_name: Either the name of the builder (e.g. link-paladin) or
                         the config type if you want to abort all HWTests for
                         that config (e.g. config_lib.CONFIG_TYPE_FULL).
    version: The version of the current build. E.g. R18-1655.0.0-rc1
    debug: Whether we are in debug mode.
    suite: Name of the Autotest suite. If empty, abort all suites.
  """
  # Abort all jobs for the given config and version.
  # Example for a specific config: link-paladin/R35-5542.0.0-rc1
  # Example for a config type: paladin/R35-5542.0.0-rc1
  substr = '%s/%s' % (config_type_or_name, version)
  abort_args = ['-i', substr, '-s', suite]
  try:
    cmd = [_ABORT_SUITE_PATH] + abort_args
    swarming_args = {
        'swarming_server':
            topology.topology.get(topology.SWARMING_PROXY_HOST_KEY),
        'task_name':
            '-'.join(['abort', substr, suite]),
        'dimensions': [('os', 'Ubuntu-14.04'), ('pool', 'default')],
        'print_status_updates':
            True,
        'expiration_secs':
            _SWARMING_EXPIRATION
    }
    if debug:
      logging.info(
          'AbortHWTests would run the cmd via '
          'swarming, cmd: %s, swarming_args: %s', cros_build_lib.CmdToStr(cmd),
          str(swarming_args))
    else:
      swarming_lib.RunSwarmingCommand(cmd, **swarming_args)
  except cros_build_lib.RunCommandError:
    logging.warning('AbortHWTests failed', exc_info=True)


def AbortSkylabHWTests(build, board, debug, suite):
  """Abort the specified hardware tests for the given bot(s).

  Args:
    build: A string build name, like 'link-paladin/R18-1655.0.0-rc1'.
    board: The name of the board.
    debug: Whether we are in debug mode.
    suite: Name of the Autotest suite.
  """
  abort_args = ['--board', board, '--suite_name', suite, '--build', build]

  try:
    cmd = [_SKYLAB_ABORT_SUITE_PATH] + abort_args
    swarming_args = {
        'swarming_server':
            topology.topology.get(topology.CHROME_SWARMING_PROXY_HOST_KEY),
        'task_name':
            '-'.join(['abort', build, suite]),
        'dimensions': [('os', 'Ubuntu-14.04'), ('pool', SKYLAB_SUITE_BOT_POOL)],
        'print_status_updates':
            True,
        'expiration_secs':
            _SWARMING_EXPIRATION,
        'tags': {
            'luci_project': 'chromeos',
            'skylab': 'abort_suite'
        }
    }
    if debug:
      logging.info(
          'AbortSkylabHWTests would run the cmd via '
          'swarming, cmd: %s, swarming_args: %s', cros_build_lib.CmdToStr(cmd),
          str(swarming_args))
    else:
      swarming_lib.RunSwarmingCommand(cmd, **swarming_args)
  except cros_build_lib.RunCommandError:
    logging.warning('AbortHWTests failed', exc_info=True)


def GenerateStackTraces(buildroot, board, test_results_dir, archive_dir,
                        got_symbols):
  """Generates stack traces for logs in |gzipped_test_tarball|

  Args:
    buildroot: Root directory where build occurs.
    board: Name of the board being worked on.
    test_results_dir: Directory of the test results.
    archive_dir: Local directory for archiving.
    got_symbols: True if breakpad symbols have been generated.

  Returns:
    List of stack trace file names.
  """
  stack_trace_filenames = []
  asan_log_signaled = False

  board_path = cros_build_lib.GetSysroot(board=board)
  symbol_dir = os.path.join(board_path, 'usr', 'lib', 'debug', 'breakpad')
  for curr_dir, _subdirs, files in os.walk(test_results_dir):
    for curr_file in files:
      full_file_path = os.path.join(curr_dir, curr_file)
      processed_file_path = '%s.txt' % full_file_path

      # Distinguish whether the current file is a minidump or asan_log.
      if curr_file.endswith('.dmp'):
        # Skip crash files that were purposely generated or if
        # breakpad symbols are absent.
        if not got_symbols or curr_file.find('crasher_nobreakpad') == 0:
          continue
        # Precess the minidump from within chroot.
        minidump = path_util.ToChrootPath(full_file_path)
        cwd = os.path.join(buildroot, 'src', 'scripts')
        cros_build_lib.run(['minidump_stackwalk', minidump, symbol_dir],
                           cwd=cwd,
                           enter_chroot=True,
                           check=False,
                           stderr=True,
                           debug_level=logging.DEBUG,
                           stdout=processed_file_path)
      # Process asan log.
      else:
        # Prepend '/chrome/$board' path to the stack trace in log.
        log_content = ''
        with open(full_file_path) as f:
          for line in f:
            # Stack frame line example to be matched here:
            #    #0 0x721d1831 (/opt/google/chrome/chrome+0xb837831)
            stackline_match = re.search(r'^ *#[0-9]* 0x.* \(', line)
            if stackline_match:
              frame_end = stackline_match.span()[1]
              line = line[:frame_end] + board_path + line[frame_end:]
            log_content += line
        # Symbolize and demangle it.
        raw = cros_build_lib.run(
            ['asan_symbolize.py'],
            input=log_content,
            enter_chroot=True,
            debug_level=logging.DEBUG,
            capture_output=True,
            encoding='utf-8',
            extra_env={'LLVM_SYMBOLIZER_PATH': '/usr/bin/llvm-symbolizer'})
        cros_build_lib.run(['c++filt'],
                           input=raw.output,
                           debug_level=logging.DEBUG,
                           cwd=buildroot,
                           stderr=True,
                           stdout=processed_file_path)
        # Break the bot if asan_log found. This is because some asan
        # crashes may not fail any test so the bot stays green.
        # Ex: crbug.com/167497
        if not asan_log_signaled:
          asan_log_signaled = True
          logging.error('Asan crash occurred. See asan_logs in Artifacts.')
          logging.PrintBuildbotStepFailure()

      # Append the processed file to archive.
      filename = ArchiveFile(processed_file_path, archive_dir)
      stack_trace_filenames.append(filename)

  return stack_trace_filenames


@failures_lib.SetFailureType(failures_lib.BuilderFailure)
def ArchiveFile(file_to_archive, archive_dir):
  """Archives the specified file.

  Args:
    file_to_archive: Full path to file to archive.
    archive_dir: Local directory for archiving.

  Returns:
    The base name of the archived file.
  """
  filename = os.path.basename(file_to_archive)
  if archive_dir:
    archived_file = os.path.join(archive_dir, filename)
    shutil.copy(file_to_archive, archived_file)
    os.chmod(archived_file, 0o644)

  return filename


class AndroidIsPinnedUprevError(failures_lib.InfrastructureFailure):
  """Raised when we try to uprev while Android is pinned."""

  def __init__(self, new_android_atom):
    """Initialize a AndroidIsPinnedUprevError.

    Args:
      new_android_atom: The Android atom that we failed to
                        uprev to, due to Android being pinned.
    """
    assert new_android_atom
    msg = ('Failed up uprev to Android version %s as Android was pinned.' %
           new_android_atom)
    super(AndroidIsPinnedUprevError, self).__init__(msg)
    self.new_android_atom = new_android_atom


class ChromeIsPinnedUprevError(failures_lib.InfrastructureFailure):
  """Raised when we try to uprev while chrome is pinned."""

  def __init__(self, new_chrome_atom):
    """Initialize a ChromeIsPinnedUprevError.

    Args:
      new_chrome_atom: The chrome atom that we failed to
                       uprev to, due to chrome being pinned.
    """
    msg = ('Failed up uprev to chrome version %s as chrome was pinned.' %
           new_chrome_atom)
    super(ChromeIsPinnedUprevError, self).__init__(msg)
    self.new_chrome_atom = new_chrome_atom


def MarkAndroidAsStable(buildroot,
                        tracking_branch,
                        android_package,
                        android_build_branch,
                        boards=None,
                        android_version=None):
  """Returns the portage atom for the revved Android ebuild - see man emerge."""
  input_msg = android_pb2.MarkStableRequest()
  input_msg.tracking_branch = tracking_branch
  input_msg.package_name = android_package
  input_msg.android_build_branch = android_build_branch
  if android_version:
    input_msg.android_version = android_version
  if boards:
    for board in boards:
      input_msg.build_targets.add().name = board

  result = CallBuildApiWithInputProto(
      buildroot, 'chromite.api.AndroidService/MarkStable',
      json_format.MessageToDict(input_msg))

  if result['status'] == android_pb2.MARK_STABLE_STATUS_EARLY_EXIT:
    # Early exit (nothing to uprev).
    return None

  # The result comes back with camelCase names rather than the underscore
  # separated names we use for the response objects. For now, adding support
  # for both just in case. Will need to fix that so we can use response
  # objects in the long term.
  atom = result.get('androidAtom') or result.get('android_atom')
  if not atom:
    logging.info('Found nothing to rev.')
    return None

  category = atom['category']
  package = atom.get('packageName') or atom.get('package_name')
  version = atom['version']
  android_atom = '%s/%s-%s' % (category, package, version)

  if result['status'] == android_pb2.MARK_STABLE_STATUS_PINNED:
    # Failed to emerge the new package, probably pinned.
    raise AndroidIsPinnedUprevError(android_atom)

  return android_atom


def MarkChromeAsStable(buildroot,
                       tracking_branch,
                       chrome_rev,
                       boards,
                       chrome_version=None):
  """Returns the portage atom for the revved chrome ebuild - see man emerge."""
  cwd = os.path.join(buildroot, 'src', 'scripts')
  extra_env = None
  chroot_args = None

  command = [
      '../../chromite/bin/cros_mark_chrome_as_stable',
      '--tracking_branch=%s' % tracking_branch
  ]
  if boards:
    command.append('--boards=%s' % ':'.join(boards))
  if chrome_version:
    command.append('--force_version=%s' % chrome_version)

  portage_atom_string = cros_build_lib.run(
      command + [chrome_rev],
      cwd=cwd,
      stdout=True,
      enter_chroot=True,
      chroot_args=chroot_args,
      extra_env=extra_env,
      encoding='utf-8').output.rstrip()
  chrome_atom = None
  if portage_atom_string:
    chrome_atom = portage_atom_string.splitlines()[-1].partition('=')[-1]
  if not chrome_atom:
    logging.info('Found nothing to rev.')
    return None

  for board in boards:
    # If we're using a version of Chrome other than the latest one, we need
    # to unmask it manually.
    if chrome_rev != constants.CHROME_REV_LATEST:
      keywords_file = CHROME_KEYWORDS_FILE % {'board': board}
      for keywords_file in (CHROME_KEYWORDS_FILE % {
          'board': board
      }, CHROME_UNMASK_FILE % {
          'board': board
      }):
        cros_build_lib.sudo_run(
            ['mkdir', '-p', os.path.dirname(keywords_file)],
            enter_chroot=True,
            cwd=cwd)
        cros_build_lib.sudo_run(['tee', keywords_file],
                                input='=%s\n' % chrome_atom,
                                enter_chroot=True, cwd=cwd)

    # Sanity check: We should always be able to merge the version of
    # Chrome we just unmasked.
    try:
      cros_build_lib.run(
          ['emerge-%s' % board, '-p', '--quiet',
           '=%s' % chrome_atom],
          enter_chroot=True)
    except cros_build_lib.RunCommandError:
      logging.error(
          'Cannot emerge-%s =%s\nIs Chrome pinned to an older '
          'version?', board, chrome_atom)
      raise ChromeIsPinnedUprevError(chrome_atom)

  return chrome_atom


def CleanupChromeKeywordsFile(boards, buildroot):
  """Cleans chrome uprev artifact if it exists."""
  for board in boards:
    keywords_path_in_chroot = CHROME_KEYWORDS_FILE % {'board': board}
    keywords_file = '%s/chroot%s' % (buildroot, keywords_path_in_chroot)
    if os.path.exists(keywords_file):
      cros_build_lib.sudo_run(['rm', '-f', keywords_file])


def UprevPackages(buildroot, boards, overlay_type, workspace=None):
  """Uprevs non-browser chromium os packages that have changed.

  Args:
    buildroot: Root directory where build occurs.
    boards: List of boards to uprev.
    overlay_type: A value from constants.VALID_OVERLAYS.
    workspace: Alternative buildroot directory to uprev.
  """
  assert overlay_type

  drop_file = _PACKAGE_FILE % {'buildroot': buildroot}
  cmd = [
      'cros_mark_as_stable',
      'commit',
      '--all',
      '--boards=%s' % ':'.join(boards),
      '--drop_file=%s' % drop_file,
      '--buildroot',
      workspace or buildroot,
      '--overlay-type',
      overlay_type,
  ]

  RunBuildScript(buildroot, cmd, chromite_cmd=True)


def RegenPortageCache(overlays):
  """Regenerate portage cache for the list of overlays."""
  task_inputs = [[o] for o in overlays if os.path.isdir(o)]
  parallel.RunTasksInProcessPool(portage_util.RegenCache, task_inputs)


def UprevPush(buildroot,
              overlay_type,
              dryrun=True,
              workspace=None):
  """Pushes uprev changes to the main line.

  Args:
    buildroot: Root directory where build occurs.
    dryrun: If True, do not actually push.
    overlay_type: A value from constants.VALID_OVERLAYS.
    workspace: Alternative buildroot directory to uprev.
  """
  assert overlay_type

  cmd = [
      'cros_mark_as_stable',
      'push',
      '--buildroot',
      workspace or buildroot,
      '--overlay-type',
      overlay_type,
  ]
  if dryrun:
    cmd.append('--dryrun')
  RunBuildScript(buildroot, cmd, chromite_cmd=True)


def ExtractDependencies(buildroot,
                        packages,
                        board=None,
                        useflags=None,
                        cpe_format=False,
                        raw_cmd_result=False):
  """Extracts dependencies for |packages|.

  Args:
    buildroot: The root directory where the build occurs.
    packages: A list of packages for which to extract dependencies.
    board: Board type that was built on this machine.
    useflags: A list of useflags for this build.
    cpe_format: Set output format to CPE-only JSON; otherwise,
      output traditional deps.
    raw_cmd_result: If set True, returns the CommandResult object.
      Otherwise, returns the dependencies as a dictionary.

  Returns:
    Returns the CommandResult object if |raw_cmd_result| is set; returns
    the dependencies in a dictionary otherwise.
  """
  cmd = ['cros_extract_deps']
  if board:
    cmd += ['--board', board]
  if cpe_format:
    cmd += ['--format=cpe']
  else:
    cmd += ['--format=deps']
  cmd += packages
  env = {}
  if useflags:
    env['USE'] = ' '.join(useflags)

  if raw_cmd_result:
    return RunBuildScript(
        buildroot,
        cmd,
        enter_chroot=True,
        chromite_cmd=True,
        capture_output=True,
        encoding='utf-8',
        extra_env=env)

  # The stdout of cros_extract_deps may contain undesirable
  # output. Avoid that by instructing the script to explicitly dump
  # the deps into a file.
  with tempfile.NamedTemporaryFile(
      dir=os.path.join(buildroot, 'chroot', 'tmp')) as f:
    cmd += ['--output-path', path_util.ToChrootPath(f.name)]
    RunBuildScript(
        buildroot,
        cmd,
        enter_chroot=True,
        chromite_cmd=True,
        capture_output=True,
        extra_env=env)
    return json.loads(f.read())


def ExtractBuildDepsGraph(buildroot, board):
  """Extract the build deps graph for |board| using build_api proto service.

  Args:
    buildroot: The root directory where the build occurs.
    board: Board type that was built on this machine.
  """
  input_proto = {
      'build_target': {
          'name': board,
      },
  }
  json_output = CallBuildApiWithInputProto(
      buildroot, 'chromite.api.DependencyService/GetBuildDependencyGraph',
      input_proto)
  return json_output['depGraph']


def GenerateBuildConfigs(board, config_useflags):
  """Generate build configs..

  Args:
    board: Board type that was built on this machine.
    config_useflags: A list of useflags for this build set by the cbuildbot
      configs.

  Returns:
    A jsonizable object which is the combination of config.yaml (for unibuild)
    and use flags.
  """
  config_chroot_path = os.path.join(
      cros_build_lib.GetSysroot(board), 'usr', 'share', 'chromeos-config',
      'yaml', 'config.yaml')

  config_fname = path_util.FromChrootPath(config_chroot_path)

  results = {}
  if os.path.exists(config_fname):
    with open(config_fname) as f:
      results = json.load(f)
  else:
    logging.warning('Cannot find config.yaml file in %s', config_fname)

  results['board'] = board
  results['useflags'] = portage_util.PortageqEnvvar(
      variable='USE', board=board, allow_undefined=False)

  if config_useflags:
    results['config_useflags'] = config_useflags

  return results


def GenerateCPEExport(buildroot, board, useflags=None):
  """Generate CPE export.

  Args:
    buildroot: The root directory where the build occurs.
    board: Board type that was built on this machine.
    useflags: A list of useflags for this build.

  Returns:
    A CommandResult object with the results of running the CPE
    export command.
  """
  return ExtractDependencies(
      buildroot, ['virtual/target-os'],
      board=board,
      useflags=useflags,
      cpe_format=True,
      raw_cmd_result=True)


def GenerateBreakpadSymbols(buildroot,
                            board,
                            debug,
                            extra_env=None,
                            chroot_args=None):
  """Generate breakpad symbols.

  Args:
    buildroot: The root directory where the build occurs.
    board: Board type that was built on this machine.
    debug: Include extra debugging output.
    extra_env: A dictionary of environmental variables to set during generation.
    chroot_args: The args to the chroot.
  """
  # We don't care about firmware symbols.
  # See https://crbug.com/213670.
  exclude_dirs = ['firmware']

  cmd = [
      'cros_generate_breakpad_symbols',
      '--board=%s' % board, '--jobs',
      str(max([1, multiprocessing.cpu_count() // 2]))
  ]
  cmd += ['--exclude-dir=%s' % x for x in exclude_dirs]
  if debug:
    cmd += ['--debug']
  RunBuildScript(
      buildroot,
      cmd,
      enter_chroot=True,
      chromite_cmd=True,
      chroot_args=chroot_args,
      extra_env=extra_env)


def GenerateAndroidBreakpadSymbols(buildroot,
                                   board,
                                   symbols_file,
                                   extra_env=None,
                                   chroot_args=None):
  """Generate breakpad symbols of Android binaries.

  Args:
    buildroot: The root directory where the build occurs.
    board: Board type that was built on this machine.
    symbols_file: Path to a symbol archive file.
    extra_env: A dictionary of environmental variables to set during generation.
    chroot_args: The args to the chroot.
  """
  board_path = cros_build_lib.GetSysroot(board=board)
  breakpad_dir = os.path.join(board_path, 'usr', 'lib', 'debug', 'breakpad')
  cmd = [
      'cros_generate_android_breakpad_symbols',
      '--symbols_file=%s' % path_util.ToChrootPath(symbols_file),
      '--breakpad_dir=%s' % breakpad_dir
  ]
  RunBuildScript(
      buildroot,
      cmd,
      enter_chroot=True,
      chromite_cmd=True,
      chroot_args=chroot_args,
      extra_env=extra_env)


def GenerateDebugTarball(buildroot,
                         board,
                         archive_path,
                         gdb_symbols,
                         archive_name='debug.tgz',
                         chroot_compression=True):
  """Generates a debug tarball in the archive_dir.

  Args:
    buildroot: The root directory where the build occurs.
    board: Board type that was built on this machine
    archive_path: Directory where tarball should be stored.
    gdb_symbols: Include *.debug files for debugging core files with gdb.
    archive_name: Name of the tarball to generate.
    chroot_compression: Whether to use compression tools in the chroot if
                        they're available.

  Returns:
    The filename of the created debug tarball.
  """
  # Generate debug tarball. This needs to run as root because some of the
  # symbols are only readable by root.
  chroot = os.path.join(buildroot, 'chroot')
  board_dir = os.path.join(chroot, 'build', board, 'usr', 'lib')
  debug_tarball = os.path.join(archive_path, archive_name)
  extra_args = None
  inputs = None

  if gdb_symbols:
    extra_args = [
        '--exclude',
        os.path.join('debug', constants.AUTOTEST_BUILD_PATH), '--exclude',
        'debug/tests'
    ]
    inputs = ['debug']
  else:
    inputs = ['debug/breakpad']

  compression_chroot = None
  if chroot_compression:
    compression_chroot = chroot

  compression = cros_build_lib.CompressionExtToType(debug_tarball)
  cros_build_lib.CreateTarball(
      debug_tarball,
      board_dir,
      sudo=True,
      compression=compression,
      chroot=compression_chroot,
      inputs=inputs,
      extra_args=extra_args)

  # Fix permissions and ownership on debug tarball.
  cros_build_lib.sudo_run(['chown', str(os.getuid()), debug_tarball])
  os.chmod(debug_tarball, 0o644)

  return os.path.basename(debug_tarball)


def GenerateUploadJSON(filepath, archive_path, uploaded):
  """Generate upload.json file given a set of filenames.

  The JSON is a dictionary keyed by filename, with entries for size, and hashes.

  Args:
    filepath: complete output filepath as string.
    archive_path: location of files.
    uploaded: file with list of uploaded filepaths, relative to archive_path.
  """
  utcnow = datetime.datetime.utcnow
  start = utcnow()

  result = {}
  files = osutils.ReadFile(uploaded).splitlines()
  for f in files:
    path = os.path.join(archive_path, f)
    # Ignore directories.
    if os.path.isdir(path):
      continue
    size = os.path.getsize(path)
    sha1, sha256 = filelib.ShaSums(path)
    result[f] = {'size': size, 'sha1': sha1, 'sha256': sha256}
  osutils.WriteFile(filepath, pformat.json(result))
  logging.info('GenerateUploadJSON completed in %s.', utcnow() - start)


def GenerateHtmlIndex(index, files, title='Index', url_base=None):
  """Generate a simple index.html file given a set of filenames

  Args:
    index: The file to write the html index to.
    files: The list of files to create the index of.  If a string, then it
           may be a path to a file (with one file per line), or a directory
           (which will be listed).
    title: Title string for the HTML file.
    url_base: The URL to prefix to all elements (otherwise they'll be relative).
  """

  def GenLink(target, name=None):
    if name == '':
      return ''
    return ('<li><a href="%s%s">%s</a></li>' % (url_base, target,
                                                name if name else target))

  if isinstance(files, six.string_types):
    if os.path.isdir(files):
      files = os.listdir(files)
    else:
      files = osutils.ReadFile(files).splitlines()
  url_base = url_base + '/' if url_base else ''

  # Head + open list.
  html = '<html>'
  html += '<head><title>%s</title></head>' % title
  html += '<body><h2>%s</h2><ul>' % title

  # List members.
  dot = ('.',)
  dot_dot = ('..',)
  links = []
  for a in sorted(set(files)):
    a = a.split('|')
    if a[0] == '.':
      dot = a
    elif a[0] == '..':
      dot_dot = a
    else:
      links.append(GenLink(*a))
  links.insert(0, GenLink(*dot_dot))
  links.insert(0, GenLink(*dot))
  html += '\n'.join(links)

  # Close list and file.
  html += '</ul></body></html>'

  osutils.WriteFile(index, html)


def GenerateHtmlTimeline(timeline, rows, title):
  """Generate a simple timeline.html file given a list of timings.

  Args:
    timeline: The file to write the html index to.
    rows: The list of rows to generate a timeline of.  Each row should be
          tuple of (entry, start_time, end_time)
    title: Title of the timeline.
  """

  _HTML = """<html>
  <head>
    <title>%(title)s</title>
    %(javascript)s
  </head>
  <body>
    <h2>%(title)s</h2>
    <!--Div that will hold the timeline-->
    <div id="chart_div"></div>
  </body>
</html>
"""

  _JAVASCRIPT_HEAD = """
    <!--Load the AJAX API-->
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <script type="text/javascript">

      // Load the Visualization API and the timeline package.
      google.charts.load('current', {'packages':['timeline']});

      // Set a callback to run when the Google Visualization API is loaded.
      google.charts.setOnLoadCallback(drawChart);

      // Callback that creates and populates a data table,
      // instantiates the timeline, passes in the data and
      // draws it.
      function drawChart() {

        // Create the data table.
        var container = document.getElementById('chart_div');
        var data = new google.visualization.DataTable();
        data.addColumn('string', 'Entry');
        data.addColumn('datetime', 'Start Time');
        data.addColumn('datetime', 'Finish Time');
"""

  _JAVASCRIPT_TAIL = """
        // Set chart options
        var height = data.getNumberOfRows() * 50 + 30;
        var options = {'title':'timings',
                       'width':'100%',
                       'height':height};

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.Timeline(container);
        chart.draw(data, options);
      }
    </script>
"""

  def GenRow(entry, start, end):

    def GenDate(time):
      # Javascript months are 0..11 instead of 1..12
      return ('new Date(%d, %d, %d, %d, %d, %d)' %
              (time.year, time.month - 1, time.day, time.hour, time.minute,
               time.second))

    return ('data.addRow(["%s", %s, %s]);\n' % (entry, GenDate(start),
                                                GenDate(end)))

  now = datetime.datetime.utcnow()
  rows = [(entry, start, end or now)
          for (entry, start, end) in rows
          if entry and start]

  javascript = [_JAVASCRIPT_HEAD]
  javascript += [GenRow(entry, start, end) for (entry, start, end) in rows]
  javascript.append(_JAVASCRIPT_TAIL)

  data = {'javascript': ''.join(javascript), 'title': title if title else ''}

  html = _HTML % data

  osutils.WriteFile(timeline, html)


@failures_lib.SetFailureType(failures_lib.GSUploadFailure)
def _UploadPathToGS(local_path, upload_urls, debug, timeout, acl=None):
  """Upload |local_path| to Google Storage.

  Args:
    local_path: Local path to upload.
    upload_urls: Iterable of GS locations to upload to.
    debug: Whether we are in debug mode.
    filename: Filename of the file to upload.
    timeout: Timeout in seconds.
    acl: Canned gsutil acl to use.
  """
  gs_context = gs.GSContext(acl=acl, dry_run=debug)
  for upload_url in upload_urls:
    with timeout_util.Timeout(timeout):
      gs_context.CopyInto(local_path, upload_url, parallel=True, recursive=True)


@failures_lib.SetFailureType(failures_lib.InfrastructureFailure)
def ExportToGCloud(build_root,
                   creds_file,
                   filename,
                   namespace=None,
                   parent_key=None,
                   project_id=None,
                   caller=None):
  """Export the given file to gCloud Datastore using export_to_gcloud

  Args:
    build_root: The root of the chromium os checkout.
    creds_file: Filename of gcloud credential file
    filename: Name of file to export.
    namespace: Optional, namespace to store entities. Defaults to
               datastore credentials
    parent_key: Optional, Key of parent entity to insert into, expects tuple.
    project_id: Optional, project_id of datastore to write to. Defaults to
                datastore credentials
    caller: Optional, name of the caller. We emit a metric for each run with
            this value in the metric:caller field.

  Returns:
    If command was successfully run or not
  """
  export_cmd = os.path.join(build_root, 'chromite', 'bin', 'export_to_gcloud')

  cmd = [export_cmd, creds_file, filename]

  if namespace:
    cmd.extend(['--namespace', namespace])

  if parent_key:
    cmd.extend(['--parent_key', repr(parent_key)])

  if project_id:
    cmd.extend(['--project_id', project_id])

  try:
    cros_build_lib.run(cmd)
    success = True
  except cros_build_lib.RunCommandError as e:
    logging.warning('Unable to export to datastore: %s', e)
    success = False

  metrics.Counter(constants.MON_EXPORT_TO_GCLOUD).increment(fields={
      'caller': str(caller),
      'success': success
  })

  return success


@failures_lib.SetFailureType(failures_lib.InfrastructureFailure)
def UploadArchivedFile(archive_dir,
                       upload_urls,
                       filename,
                       debug,
                       update_list=False,
                       timeout=2 * 60 * 60,
                       acl=None):
  """Uploads |filename| in |archive_dir| to Google Storage.

  Args:
    archive_dir: Path to the archive directory.
    upload_urls: Iterable of GS locations to upload to.
    debug: Whether we are in debug mode.
    filename: Name of the file to upload.
    update_list: Flag to update the list of uploaded files.
    timeout: Timeout in seconds.
    acl: Canned gsutil acl to use.
  """
  # Upload the file.
  file_path = os.path.join(archive_dir, filename)
  _UploadPathToGS(file_path, upload_urls, debug, timeout, acl=acl)

  if update_list:
    # Append |filename| to the local list of uploaded files and archive
    # the list to Google Storage. As long as the |filename| string is
    # less than PIPE_BUF (> 512 bytes), the append is atomic.
    uploaded_file_path = os.path.join(archive_dir, UPLOADED_LIST_FILENAME)
    osutils.WriteFile(uploaded_file_path, filename + '\n', mode='a')
    _UploadPathToGS(uploaded_file_path, upload_urls, debug, timeout)


def UploadSymbols(buildroot,
                  board=None,
                  official=False,
                  cnt=None,
                  failed_list=None,
                  breakpad_root=None,
                  product_name=None,
                  extra_env=None,
                  chroot_args=None):
  """Upload debug symbols for this build."""
  cmd = ['upload_symbols', '--yes', '--dedupe']

  if board is not None:
    # Board requires both root and board to be set to be useful.
    cmd += [
        '--root',
        os.path.join(buildroot, constants.DEFAULT_CHROOT_DIR), '--board', board
    ]
  if official:
    cmd.append('--official_build')
  if cnt is not None:
    cmd += ['--upload-limit', str(cnt)]
  if failed_list is not None:
    cmd += ['--failed-list', str(failed_list)]
  if breakpad_root is not None:
    cmd += ['--breakpad_root', breakpad_root]
  if product_name is not None:
    cmd += ['--product_name', product_name]

  # We don't want to import upload_symbols directly because it uses the
  # swarming module which itself imports a _lot_ of stuff.  It has also
  # been known to hang.  We want to keep cbuildbot isolated & robust.
  RunBuildScript(
      buildroot,
      cmd,
      chromite_cmd=True,
      chroot_args=chroot_args,
      extra_env=extra_env)


def PushImages(board,
               archive_url,
               dryrun,
               profile,
               sign_types=(),
               buildroot=None):
  """Push the generated image to the release bucket for signing."""
  # Log the equivalent command for debugging purposes.
  log_cmd = ['pushimage', '--board=%s' % board]

  if dryrun:
    log_cmd.append('-n')

  if profile:
    log_cmd.append('--profile=%s' % profile)

  if sign_types:
    log_cmd.append('--sign-types=%s' % ' '.join(sign_types))

  if buildroot:
    log_cmd.append('--buildroot=%s' % buildroot)

  log_cmd.append(archive_url)
  logging.info('Running: %s', cros_build_lib.CmdToStr(log_cmd))

  try:
    return pushimage.PushImage(
        archive_url,
        board,
        profile=profile,
        sign_types=sign_types,
        dry_run=dryrun,
        buildroot=buildroot)
  except pushimage.PushError as e:
    logging.PrintBuildbotStepFailure()
    return e.args[1]


def BuildFactoryInstallImage(buildroot, board, extra_env):
  """Build a factory install image.

  Args:
    buildroot: Root directory where build occurs.
    board: Board type that was built on this machine
    extra_env: Flags to be added to the environment for the new process.

  Returns:
    The basename of the symlink created for the image.
  """

  # We use build_attempt=3 here to ensure that this image uses a different
  # output directory from our regular image and the factory test image.
  alias = _FACTORY_SHIM
  cmd = [
      './build_image',
      '--board=%s' % board, '--replace', '--noeclean',
      '--symlink=%s' % alias, '--build_attempt=3', 'factory_install'
  ]
  RunBuildScript(
      buildroot,
      cmd,
      extra_env=extra_env,
      capture_output=True,
      enter_chroot=True)
  return alias


def MakeNetboot(buildroot, board, image_dir):
  """Build a netboot image.

  Args:
    buildroot: Root directory where build occurs.
    board: Board type that was built on this machine.
    image_dir: Directory containing factory install shim.
  """
  cmd = [
      './make_netboot.sh',
      '--board=%s' % board,
      '--image_dir=%s' % path_util.ToChrootPath(image_dir)
  ]
  RunBuildScript(buildroot, cmd, capture_output=True, enter_chroot=True)


def BuildRecoveryImage(buildroot, board, image_dir, extra_env):
  """Build a recovery image.

  Args:
    buildroot: Root directory where build occurs.
    board: Board type that was built on this machine.
    image_dir: Directory containing base image.
    extra_env: Flags to be added to the environment for the new process.
  """
  base_image = os.path.join(image_dir, constants.BASE_IMAGE_BIN)
  # mod_image_for_recovery leaves behind some artifacts in the source directory
  # that we don't care about. So, use a tempdir as the working directory.
  # This tempdir needs to be at a chroot accessible path.
  with osutils.TempDir(base_dir=image_dir) as tempdir:
    tempdir_base_image = os.path.join(tempdir, constants.BASE_IMAGE_BIN)
    tempdir_recovery_image = os.path.join(tempdir, constants.RECOVERY_IMAGE_BIN)

    # Copy the base image. Symlinking isn't enough because image building
    # scripts follow symlinks by design.
    shutil.copyfile(base_image, tempdir_base_image)
    cmd = [
        './mod_image_for_recovery.sh',
        '--board=%s' % board,
        '--image=%s' % path_util.ToChrootPath(tempdir_base_image)
    ]
    RunBuildScript(
        buildroot,
        cmd,
        extra_env=extra_env,
        capture_output=True,
        enter_chroot=True)
    shutil.move(tempdir_recovery_image, image_dir)


def BuildTarball(buildroot,
                 input_list,
                 tarball_output,
                 cwd=None,
                 compressed=True,
                 **kwargs):
  """Tars and zips files and directories from input_list to tarball_output.

  Args:
    buildroot: Root directory where build occurs.
    input_list: A list of files and directories to be archived.
    tarball_output: Path of output tar archive file.
    cwd: Current working directory when tar command is executed.
    compressed: Whether or not the tarball should be compressed with pbzip2.
    **kwargs: Keyword arguments to pass to CreateTarball.

  Returns:
    Return value of cros_build_lib.CreateTarball.
  """
  compressor = cros_build_lib.COMP_NONE
  chroot = None
  if compressed:
    compressor = cros_build_lib.COMP_BZIP2
    chroot = os.path.join(buildroot, 'chroot')
  return cros_build_lib.CreateTarball(
      tarball_output,
      cwd,
      compression=compressor,
      chroot=chroot,
      inputs=input_list,
      **kwargs)


def FindFilesWithPattern(pattern, target='./', cwd=os.curdir, exclude_dirs=()):
  """Search the root directory recursively for matching filenames.

  Args:
    pattern: the pattern used to match the filenames.
    target: the target directory to search.
    cwd: current working directory.
    exclude_dirs: Directories to not include when searching.

  Returns:
    A list of paths of the matched files.
  """
  # Backup the current working directory before changing it
  old_cwd = os.getcwd()
  os.chdir(cwd)

  matches = []
  for root, _, filenames in os.walk(target):
    if not any(root.startswith(e) for e in exclude_dirs):
      for filename in fnmatch.filter(filenames, pattern):
        matches.append(os.path.join(root, filename))

  # Restore the working directory
  os.chdir(old_cwd)

  return matches


def BuildAutotestControlFilesTarball(buildroot, cwd, tarball_dir):
  """Tar up the autotest control files.

  Args:
    buildroot: Root directory where build occurs.
    cwd: Current working directory.
    tarball_dir: Location for storing autotest tarball.

  Returns:
    Path of the partial autotest control files tarball.
  """
  # Find the control files in autotest/
  control_files = FindFilesWithPattern(
      'control*',
      target='autotest',
      cwd=cwd,
      exclude_dirs=['autotest/test_suites'])
  control_files_tarball = os.path.join(tarball_dir, 'control_files.tar')
  BuildTarball(
      buildroot,
      control_files,
      control_files_tarball,
      cwd=cwd,
      compressed=False)
  return control_files_tarball


def BuildAutotestPackagesTarball(buildroot, cwd, tarball_dir):
  """Tar up the autotest packages.

  Args:
    buildroot: Root directory where build occurs.
    cwd: Current working directory.
    tarball_dir: Location for storing autotest tarball.

  Returns:
    Path of the partial autotest packages tarball.
  """
  input_list = ['autotest/packages']
  packages_tarball = os.path.join(tarball_dir, 'autotest_packages.tar')
  BuildTarball(
      buildroot, input_list, packages_tarball, cwd=cwd, compressed=False)
  return packages_tarball


def BuildAutotestTestSuitesTarball(buildroot, cwd, tarball_dir):
  """Tar up the autotest test suite control files.

  Args:
    buildroot: Root directory where build occurs.
    cwd: Current working directory.
    tarball_dir: Location for storing autotest tarball.

  Returns:
    Path of the autotest test suites tarball.
  """
  test_suites_tarball = os.path.join(tarball_dir, 'test_suites.tar.bz2')
  BuildTarball(
      buildroot, ['autotest/test_suites'], test_suites_tarball, cwd=cwd)
  return test_suites_tarball


def BuildAutotestServerPackageTarball(buildroot, cwd, tarball_dir):
  """Tar up the autotest files required by the server package.

  Args:
    buildroot: Root directory where build occurs.
    cwd: Current working directory.
    tarball_dir: Location for storing autotest tarballs.

  Returns:
    The path of the autotest server package tarball.
  """
  # Find all files in autotest excluding certain directories.
  autotest_files = FindFilesWithPattern(
      '*',
      target='autotest',
      cwd=cwd,
      exclude_dirs=('autotest/packages', 'autotest/client/deps/',
                    'autotest/client/tests', 'autotest/client/site_tests'))

  tast_files, transforms = _GetTastServerFilesAndTarTransforms(buildroot)

  tarball = os.path.join(tarball_dir, AUTOTEST_SERVER_PACKAGE)
  BuildTarball(
      buildroot,
      autotest_files + tast_files,
      tarball,
      cwd=cwd,
      extra_args=transforms,
      check=False)
  return tarball


def _GetTastServerFilesAndTarTransforms(buildroot):
  """Returns Tast server files and corresponding tar transform flags.

  The returned paths should be included in AUTOTEST_SERVER_PACKAGE. The
  --transform arguments should be passed to GNU tar to convert the paths to
  appropriate destinations in the tarball.

  Args:
    buildroot: Absolute path to root build directory.

  Returns:
    (files, transforms), where files is a list of absolute paths to Tast server
        files/directories and transforms is a list of --transform arguments to
        pass to GNU tar when archiving those files.
  """
  files = []
  transforms = []

  for p in TAST_SSP_FILES:
    path = os.path.join(buildroot, p)
    if os.path.exists(path):
      files.append(path)
      dest = os.path.join(_TAST_SSP_SUBDIR, os.path.basename(path))
      transforms.append(
          '--transform=s|^%s|%s|' % (os.path.relpath(path, '/'), dest))

  return files, transforms


def BuildAutotestTarballsForHWTest(buildroot, cwd, tarball_dir):
  """Generate the "usual" autotest tarballs required for running HWTests.

  These tarballs are created in multiple places wherever they need to be staged
  for running HWTests.

  Args:
    buildroot: Root directory where build occurs.
    cwd: Current working directory.
    tarball_dir: Location for storing autotest tarballs.

  Returns:
    A list of paths of the generated tarballs.

  TODO(crbug.com/924655): Has been ported to a build API endpoint. Remove this
  function and any unused child functions when the stages have been updated to
  use the API call.
  """
  return [
      BuildAutotestControlFilesTarball(buildroot, cwd, tarball_dir),
      BuildAutotestPackagesTarball(buildroot, cwd, tarball_dir),
      BuildAutotestTestSuitesTarball(buildroot, cwd, tarball_dir),
      BuildAutotestServerPackageTarball(buildroot, cwd, tarball_dir),
  ]


def BuildTastBundleTarball(buildroot, cwd, tarball_dir):
  """Tar up the Tast private test bundles.

  Args:
    buildroot: Root directory where build occurs.
    cwd: Current working directory pointing /build/$board/build.
    tarball_dir: Location for storing the tarball.

  Returns:
    Path of the generated tarball, or None if there is no private test bundles.
  """
  chroot = chroot_lib.Chroot(os.path.join(buildroot, 'chroot'))
  sysroot_path = cwd.replace(chroot.path, '', 1)
  sysroot_path = sysroot_path.rstrip('build').rstrip(os.sep)
  sysroot = sysroot_lib.Sysroot(sysroot_path)

  return artifacts_service.BundleTastFiles(chroot, sysroot, tarball_dir)


def BuildPinnedGuestImagesTarball(buildroot, board, tarball_dir):
  """Create a tarball of Guest VM and Container images for testing.

  Args:
    buildroot: Root directory where build occurs.
    board: Board name of build target.
    tarball_dir: Location for storing the images and tarball.

  Returns:
    Path of the generated tarball, or None if there are no images.
  """
  pins_root = os.path.abspath(
      os.path.join(buildroot, 'chroot', 'build', board,
                   constants.GUEST_IMAGES_PINS_PATH))
  gs_context = gs.GSContext()
  files = []
  for pin_file in sorted(glob.iglob(os.path.join(pins_root, '*.json'))):
    with open(pin_file) as f:
      pin = json.load(f)
      try:
        filename = os.path.join(tarball_dir, pin[constants.PIN_KEY_FILENAME])
        gs_context.Copy(pin[constants.PIN_KEY_GSURI], filename)
        files.append(pin[constants.PIN_KEY_FILENAME])
      except KeyError as e:
        logging.warning("Skipping invalid pin file '%s': %r", pin_file, e)

  if not files:
    return None
  tarball = os.path.join(tarball_dir, 'guest_images.tar')
  BuildTarball(buildroot, files, tarball, cwd=tarball_dir, compressed=False)
  return tarball


def BuildFullAutotestTarball(buildroot, board, tarball_dir):
  """Tar up the full autotest directory into image_dir.

  Args:
    buildroot: Root directory where build occurs.
    board: Board type that was built on this machine.
    tarball_dir: Location for storing autotest tarballs.

  Returns:
    A tuple the path of the full autotest tarball.
  """

  tarball = os.path.join(tarball_dir, 'autotest.tar.bz2')
  cwd = os.path.abspath(
      os.path.join(buildroot, 'chroot', 'build', board,
                   constants.AUTOTEST_BUILD_PATH, '..'))
  result = BuildTarball(
      buildroot, ['autotest'], tarball, cwd=cwd, check=False)

  # Emerging the autotest package to the factory test image while this is
  # running modifies the timestamp on /build/autotest/server by
  # adding a tmp directory underneath it.
  # When tar spots this, it flags this and returns
  # status code 1. The tarball is still OK, although there might be a few
  # unneeded (and garbled) tmp files. If tar fails in a different way, it'll
  # return an error code other than 1.
  # TODO: Fix the autotest ebuild. See https://crbug.com/237537
  if result.returncode not in (0, 1):
    raise Exception('Autotest tarball creation failed with exit code %s' %
                    (result.returncode))

  return tarball


def BuildUnitTestTarball(buildroot, board, tarball_dir):
  """Tar up the UnitTest binaries."""
  tarball = 'unit_tests.tar'
  tarball_path = os.path.join(tarball_dir, tarball)
  cwd = os.path.abspath(
      os.path.join(buildroot, 'chroot', 'build', board,
                   constants.UNITTEST_PKG_PATH))
  # UnitTest binaries are already compressed so just create a tar file.
  BuildTarball(
      buildroot, ['.'],
      tarball_path,
      cwd=cwd,
      compressed=False,
      check=False)
  return tarball


def BuildImageZip(archive_dir, image_dir):
  """Build image.zip in archive_dir from contents of image_dir.

  Exclude the dev image from the zipfile.

  Args:
    archive_dir: Directory to store image.zip.
    image_dir: Directory to zip up.

  Returns:
    The basename of the zipfile.
  """
  filename = 'image.zip'
  zipfile = os.path.join(archive_dir, filename)
  cros_build_lib.run(['zip', zipfile, '-r', '.'],
                     cwd=image_dir, capture_output=True)
  return filename


def BuildStandaloneArchive(archive_dir, image_dir, artifact_info):
  """Create a compressed archive from the specified image information.

  The artifact info is derived from a JSON file in the board overlay. It
  should be in the following format:
  {
  "artifacts": [
    { artifact },
    { artifact },
    ...
  ]
  }
  Each artifact can contain the following keys:
  input - Required. A list of paths and globs that expands to
      the list of files to archive.
  output - the name of the archive to be created. If omitted,
      it will default to the first filename, stripped of
      extensions, plus the appropriate .tar.gz or other suffix.
  archive - "tar" or "zip". If omitted, files will be uploaded
      directly, without being archived together.
  compress - a value cros_build_lib.CompressionStrToType knows about. Only
      useful for tar. If omitted, an uncompressed tar will be created.

  Args:
    archive_dir: Directory to store image zip.
    image_dir: Base path for all inputs.
    artifact_info: Extended archive configuration dictionary containing:
      - paths - required, list of files to archive.
      - output, archive & compress entries from the JSON file.

  Returns:
    The base name of the archive.

  Raises:
    A ValueError if the compression or archive values are unknown.
    A KeyError is a required field is missing from artifact_info.
  """
  if 'archive' not in artifact_info:
    # Copy the file in 'paths' as is to the archive directory.
    if len(artifact_info['paths']) > 1:
      raise ValueError('default archive type does not support multiple inputs')
    src_path = os.path.join(image_dir, artifact_info['paths'][0])
    tgt_path = os.path.join(archive_dir, artifact_info['paths'][0])
    if not os.path.exists(tgt_path):
      # The image may have already been copied into place. If so, overwriting it
      # can affect parallel processes.
      if os.path.isdir(src_path):
        shutil.copytree(src_path, tgt_path)
      else:
        shutil.copy(src_path, tgt_path)
    return artifact_info['paths']

  inputs = artifact_info['paths']
  archive = artifact_info['archive']
  compress = artifact_info.get('compress')
  compress_type = cros_build_lib.CompressionStrToType(compress)
  if compress_type is None:
    raise ValueError('unknown compression type: %s' % compress)

  # If the output is fixed, use that. Otherwise, construct it
  # from the name of the first archived file, stripping extensions.
  filename = artifact_info.get(
      'output', '%s.%s' % (os.path.splitext(inputs[0])[0], archive))
  if archive == 'tar':
    # Add the .compress extension if we don't have a fixed name.
    if 'output' not in artifact_info and compress:
      filename = '%s.%s' % (filename, compress)
    extra_env = {'XZ_OPT': '-1'}
    cros_build_lib.CreateTarball(
        os.path.join(archive_dir, filename),
        image_dir,
        inputs=inputs,
        compression=compress_type,
        extra_env=extra_env)
  elif archive == 'zip':
    cros_build_lib.run(
        ['zip', os.path.join(archive_dir, filename), '-r'] + inputs,
        cwd=image_dir,
        capture_output=True)
  else:
    raise ValueError('unknown archive type: %s' % archive)

  return [filename]


def BuildStrippedPackagesTarball(buildroot, board, package_globs, archive_dir):
  """Builds a tarball containing stripped packages.

  Args:
    buildroot: Root directory where build occurs.
    board: The board for which packages should be tarred up.
    package_globs: List of package search patterns. Each pattern is used to
        search for packages via `equery list`.
    archive_dir: The directory to drop the tarball in.

  Returns:
    The file name of the output tarball, None if no package found.
  """
  chroot_path = os.path.join(buildroot, constants.DEFAULT_CHROOT_DIR)
  board_path = os.path.join(chroot_path, 'build', board)
  stripped_pkg_dir = os.path.join(board_path, 'stripped-packages')
  tarball_paths = []
  for pattern in package_globs:
    packages = portage_util.FindPackageNameMatches(
        pattern, board, buildroot=buildroot)
    for cpv in packages:
      cmd = ['strip_package', '--board', board, cpv.cpf]
      cros_build_lib.run(cmd, cwd=buildroot, enter_chroot=True)
      # Find the stripped package.
      files = glob.glob(os.path.join(stripped_pkg_dir, cpv.cpf) + '.*')
      if not files:
        raise AssertionError('Silent failure to strip binary %s? '
                             'Failed to find stripped files at %s.' %
                             (cpv.cpf, os.path.join(stripped_pkg_dir, cpv.cpf)))
      if len(files) > 1:
        logging.PrintBuildbotStepWarnings()
        logging.warning('Expected one stripped package for %s, found %d',
                        cpv.cpf, len(files))

      tarball = sorted(files)[-1]
      tarball_paths.append(os.path.relpath(tarball, board_path))

  if not tarball_paths:
    # tar barfs on an empty list of files, so skip tarring completely.
    return None

  tarball_output = os.path.join(archive_dir, 'stripped-packages.tar')
  BuildTarball(buildroot, tarball_paths, tarball_output, compressed=False,
               cwd=board_path)
  return os.path.basename(tarball_output)


def BuildEbuildLogsTarball(buildroot, board, archive_dir):
  """Builds a tarball containing ebuild logs.

  Args:
    buildroot: Root directory where build occurs.
    board: The board for which packages should be tarred up.
    archive_dir: The directory to drop the tarball in.

  Returns:
    The file name of the output tarball, None if no package found.
  """
  sysroot = sysroot_lib.Sysroot(os.path.join('build', board))
  chroot = chroot_lib.Chroot(path=os.path.join(buildroot, 'chroot'))
  return artifacts_service.BundleEBuildLogsTarball(chroot, sysroot, archive_dir)


def BuildChromeOSConfig(buildroot, board, archive_dir):
  """Builds the ChromeOS Config JSON payload.

  Args:
    buildroot: Root directory where the build occurs.
    board: The board for which ChromeOS Configs payload should be built.
    archive_dir: The directory to drop the payload in.

  Returns:
    The file name of the output payload.
  """
  sysroot = sysroot_lib.Sysroot(os.path.join('build', board))
  chroot = chroot_lib.Chroot(path=os.path.join(buildroot, 'chroot'))
  return artifacts_service.BundleChromeOSConfig(chroot, sysroot, archive_dir)


def BuildGceTarball(archive_dir, image_dir, image):
  """Builds a tarball that can be converted into a GCE image.

  GCE has some very specific requirements about the format of VM
  images. The full list can be found at
  https://cloud.google.com/compute/docs/tutorials/building-images#requirements

  Args:
    archive_dir: Directory to store the output tarball.
    image_dir: Directory where raw disk file can be found.
    image: Name of raw disk file.

  Returns:
    The file name of the output tarball.
  """
  with osutils.TempDir() as tempdir:
    temp_disk_raw = os.path.join(tempdir, 'disk.raw')
    output = constants.ImageBinToGceTar(image)
    output_file = os.path.join(archive_dir, output)
    os.symlink(os.path.join(image_dir, image), temp_disk_raw)

    cros_build_lib.CreateTarball(
        output_file,
        tempdir,
        inputs=['disk.raw'],
        compression=cros_build_lib.COMP_GZIP,
        extra_args=['--dereference'])
    return os.path.basename(output_file)


def BuildFirmwareArchive(buildroot,
                         board,
                         archive_dir,
                         archive_name=constants.FIRMWARE_ARCHIVE_NAME):
  """Build firmware_from_source.tar.bz2 in archive_dir from build root.

  Args:
    buildroot: Root directory where build occurs.
    board: Board name of build target.
    archive_dir: Directory to store output file.
    archive_name: Name of file to create in archive_dir.

  Returns:
    The basename of the archived file, or None if the target board does
    not have firmware from source.
  """
  sysroot = sysroot_lib.Sysroot(os.path.join('build', board))
  chroot = chroot_lib.Chroot(path=os.path.join(buildroot, 'chroot'))

  archive_file = artifacts_service.BuildFirmwareArchive(
      chroot, sysroot, archive_dir
  )
  if archive_file is None:
    return None
  else:
    shutil.move(archive_file, os.path.join(archive_dir, archive_name))
    return archive_name


def CallBuildApiWithInputProto(buildroot, build_api_command, input_proto):
  """Call BuildApi with the input_proto and buildroot.

  Args:
    buildroot: Root directory where build occurs.
    build_api_command: Service (command) to execute.
    input_proto (dict): The input proto as a dict.

  Returns:
    The json-encoded output proto.
  """
  cmd = ['build_api', build_api_command]
  with osutils.TempDir() as tmpdir:
    input_proto_file = os.path.join(tmpdir, 'input.json')
    output_proto_file = os.path.join(tmpdir, 'output.json')
    pformat.json(input_proto, fp=input_proto_file)
    cmd += [
        '--input-json', input_proto_file, '--output-json', output_proto_file
    ]
    RunBuildScript(buildroot, cmd, chromite_cmd=True, stdout=True)
    return json.loads(osutils.ReadFile(output_proto_file))


def BuildFactoryZip(buildroot,
                    board,
                    archive_dir,
                    factory_shim_dir,
                    version=None):
  """Build factory_image.zip in archive_dir.

  Args:
    buildroot: Root directory where build occurs.
    board: Board name of build target.
    archive_dir: Directory to store factory_image.zip.
    factory_shim_dir: Directory containing factory shim.
    version: The version string to be included in the factory image.zip.

  Returns:
    The basename of the zipfile.
  """
  filename = 'factory_image.zip'

  # Creates a staging temporary folder.
  temp_dir = tempfile.mkdtemp(prefix='cbuildbot_factory')

  zipfile = os.path.join(archive_dir, filename)
  cmd = ['zip', '-r', zipfile, '.']

  # Rules for archive: { folder: pattern }
  rules = {
      factory_shim_dir: [
          '*factory_install*.bin', '*partition*',
          os.path.join('netboot', '*')
      ],
  }

  for folder, patterns in rules.items():
    if not folder or not os.path.exists(folder):
      continue
    basename = os.path.basename(folder)
    target = os.path.join(temp_dir, basename)
    os.symlink(folder, target)
    for pattern in patterns:
      cmd.extend(['--include', os.path.join(basename, pattern)])

  # Everything in /usr/local/factory/bundle gets overlaid into the
  # bundle.
  bundle_src_dir = os.path.join(buildroot, 'chroot', 'build', board, 'usr',
                                'local', 'factory', 'bundle')
  if os.path.exists(bundle_src_dir):
    for f in os.listdir(bundle_src_dir):
      src_path = os.path.join(bundle_src_dir, f)
      os.symlink(src_path, os.path.join(temp_dir, f))
      cmd.extend([
          '--include', f if os.path.isfile(src_path) else os.path.join(f, '*')
      ])

  # Add a version file in the zip file.
  if version is not None:
    version_file = os.path.join(temp_dir, 'BUILD_VERSION')
    osutils.WriteFile(version_file, version)
    cmd.extend(['--include', version_file])

  cros_build_lib.run(cmd, cwd=temp_dir, capture_output=True)
  osutils.RmDir(temp_dir)
  return filename


def ArchiveHWQual(buildroot, hwqual_name, archive_dir, image_dir):
  """Create a hwqual tarball in archive_dir.

  Args:
    buildroot: Root directory where build occurs.
    hwqual_name: Name for tarball.
    archive_dir: Local directory for hwqual tarball.
    image_dir: Directory containing test image.
  """
  script_dir = os.path.join(buildroot, 'src', 'platform', 'crostestutils')
  ssh_private_key = os.path.join(image_dir, constants.TEST_KEY_PRIVATE)
  cmd = [
      os.path.join(script_dir, 'archive_hwqual'), '--from', archive_dir,
      '--image_dir', image_dir, '--ssh_private_key', ssh_private_key,
      '--output_tag', hwqual_name
  ]
  cros_build_lib.run(cmd, capture_output=True)
  return '%s.tar.bz2' % hwqual_name


def CreateTestRoot(build_root):
  """Returns a temporary directory for test results in chroot.

  Returns:
    The path inside the chroot rather than whole path.
  """
  # Create test directory within tmp in chroot.
  chroot = os.path.join(build_root, 'chroot')
  chroot_tmp = os.path.join(chroot, 'tmp')
  test_root = tempfile.mkdtemp(prefix='cbuildbot', dir=chroot_tmp)

  # Path inside chroot.
  return os.path.sep + os.path.relpath(test_root, start=chroot)


def GenerateQuickProvisionPayloads(target_image_path, archive_dir):
  """Generates payloads needed for quick_provision script.

  Args:
    target_image_path: The path to the image to extract the partitions.
    archive_dir: Where to store partitions when generated.
  """
  # TODO(saklein): Remove this function entirely in favor of a combined call to
  #   the endpoint with GeneratePayloads when its arguments have been added to
  #   the API.
  artifacts_service.GenerateQuickProvisionPayloads(target_image_path,
                                                   archive_dir)

def GeneratePayloads(target_image_path,
                     archive_dir,
                     full=False,
                     delta=False,
                     stateful=False,
                     dlc=False):
  """Generates the payloads for hw testing.

  Args:
    target_image_path: The path to the image to generate payloads to.
    archive_dir: Where to store payloads we generated.
    full: Generate full payloads.
    delta: Generate delta payloads.
    stateful: Generate stateful payload.
    dlc: Generate dummy-dlc payloads.
  """
  # TODO(saklein): Change to a combined call to the endpoint with
  #   GenerateQuickProvisionPayloads after the payload type arguments have been
  #   added.
  artifacts_service.GenerateTestPayloads(target_image_path, archive_dir,
                                         full=full, delta=delta,
                                         stateful=stateful, dlc=dlc)


def GetChromeLKGM(revision):
  """Returns the ChromeOS LKGM from Chrome given the git revision."""
  revision = revision or 'refs/heads/master'
  lkgm_url_path = '%s/+/%s/%s?format=text' % (
      constants.CHROMIUM_SRC_PROJECT, revision, constants.PATH_TO_CHROME_LKGM)
  contents_b64 = gob_util.FetchUrl(config_lib.GetSiteParams().EXTERNAL_GOB_HOST,
                                   lkgm_url_path)
  # TODO(crbug.com/997354): for Python 3 support, it probably makes
  # sense to return a string here, not bytes.
  return base64.b64decode(contents_b64).strip()


def SyncChrome(build_root,
               chrome_root,
               useflags,
               tag=None,
               revision=None,
               git_cache_dir=None):
  """Sync chrome.

  Args:
    build_root: The root of the chromium os checkout.
    chrome_root: The directory where chrome is stored.
    useflags: Array of use flags.
    tag: If supplied, the Chrome tag to sync.
    revision: If supplied, the Chrome revision to sync.
    git_cache_dir: Directory to use for git-cache.
  """
  sync_chrome = os.path.join(build_root, 'chromite', 'bin', 'sync_chrome')
  internal = constants.USE_CHROME_INTERNAL in useflags
  # --reset tells sync_chrome to blow away local changes and to feel
  # free to delete any directories that get in the way of syncing. This
  # is needed for unattended operation.
  # --ignore-locks tells sync_chrome to ignore git-cache locks.
  cmd = [sync_chrome, '--reset', '--ignore_locks']
  if internal:
    cmd += ['--internal']
  if tag:
    cmd += ['--tag', tag]
  if revision:
    cmd += ['--revision', revision]
  if git_cache_dir:
    cmd += ['--git_cache_dir', git_cache_dir]
  cmd += [chrome_root]
  retry_util.RunCommandWithRetries(constants.SYNC_RETRIES, cmd, cwd=build_root)


class ChromeSDK(object):
  """Wrapper for the 'cros chrome-sdk' command."""

  DEFAULT_GOMA_JOBS = '80'

  def __init__(self,
               cwd,
               board,
               extra_args=None,
               chrome_src=None,
               goma=False,
               debug_log=True,
               cache_dir=None,
               target_tc=None,
               toolchain_url=None):
    """Initialization.

    Args:
      cwd: Where to invoke 'cros chrome-sdk'.
      board: The board to run chrome-sdk for.
      extra_args: Extra args to pass in on the command line.
      chrome_src: Path to pass in with --chrome-src.
      goma: If True, run using goma.
      debug_log: If set, run with debug log-level.
      cache_dir: Specify non-default cache directory.
      target_tc: Override target toolchain.
      toolchain_url: Override toolchain url pattern.
    """
    self.cwd = cwd
    self.board = board
    self.extra_args = extra_args or []
    if chrome_src:
      self.extra_args += ['--chrome-src', chrome_src]
    self.goma = goma
    if not self.goma:
      self.extra_args.append('--nogoma')
    self.debug_log = debug_log
    self.cache_dir = cache_dir
    self.target_tc = target_tc
    self.toolchain_url = toolchain_url

  def Run(self, cmd, extra_args=None, run_args=None):
    """Run a command inside the chrome-sdk context.

    Args:
      cmd: Command (list) to run inside 'cros chrome-sdk'.
      extra_args: Extra arguments for 'cros chorme-sdk'.
      run_args: If set (dict), pass to run as kwargs.

    Returns:
      A CommandResult object.
    """
    if run_args is None:
      run_args = {}
    cros_cmd = ['cros']
    if self.debug_log:
      cros_cmd += ['--log-level', 'debug']
    if self.cache_dir:
      cros_cmd += ['--cache-dir', self.cache_dir]
    if self.target_tc:
      self.extra_args += ['--target-tc', self.target_tc]
    if self.toolchain_url:
      self.extra_args += ['--toolchain-url', self.toolchain_url]
    cros_cmd += ['chrome-sdk', '--board', self.board] + self.extra_args
    cros_cmd += (extra_args or []) + ['--'] + cmd
    return cros_build_lib.run(cros_cmd, cwd=self.cwd, **run_args)

  def Ninja(self, debug=False, run_args=None):
    """Run 'ninja' inside a chrome-sdk context.

    Args:
      debug: Whether to do a Debug build (defaults to Release).
      run_args: If set (dict), pass to run as kwargs.

    Returns:
      A CommandResult object.
    """
    return self.Run(self.GetNinjaCommand(debug=debug), run_args=run_args)

  def GetNinjaCommand(self, debug=False):
    """Returns a command line to run "ninja".

    Args:
      debug: Whether to do a Debug build (defaults to Release).

    Returns:
      Command line to run "ninja".
    """
    cmd = ['autoninja']
    if self.goma:
      cmd += ['-j', self.DEFAULT_GOMA_JOBS]
    cmd += ['-C', self._GetOutDirectory(debug=debug), 'chromiumos_preflight']
    return cmd

  def VMTest(self, image_path, debug=False):
    """Run cros_run_test in a VM.

    Only run tests for boards where we build a VM.

    Args:
      image_path: VM image path.
      debug: True if this is a debug build.

    Returns:
      A CommandResult object.
    """
    return self.Run([
        'cros_run_test',
        '--copy-on-write',
        '--deploy',
        '--board=%s' % self.board,
        '--image-path=%s' % image_path,
        '--build-dir=%s' % self._GetOutDirectory(debug=debug),
    ])

  def _GetOutDirectory(self, debug=False):
    """Returns the path to the output directory.

    Args:
      debug: Whether to do a Debug build (defaults to Release).

    Returns:
      Path to the output directory.
    """
    flavor = 'Debug' if debug else 'Release'
    return 'out_%s/%s' % (self.board, flavor)

  def GetNinjaLogPath(self, debug=False):
    """Returns the path to the .ninja_log file.

    Args:
      debug: Whether to do a Debug build (defaults to Release).

    Returns:
      Path to the .ninja_log file.
    """
    return os.path.join(self._GetOutDirectory(debug=debug), '.ninja_log')


def GenerateAFDOArtifacts(buildroot, chrome_root, board, output_path, target):
  """Command to generate AFDO artifacts.

  This is only a wrapper of the build API. It doesn't validate the inputs.

  Args:
    buildroot: The path to build root.
    chrome_root: The path to Chrome root.
    board: Name of the board.
    output_path: The path to save output.
    target: A valid toolchain_pb2.AFDOArtifactType.

  Returns:
    List of artifact names.
  """
  input_proto = {
      'chroot': {
          'path': os.path.join(buildroot, 'chroot'),
          'chrome_dir': chrome_root,
      },
      'build_target': {
          'name': board,
      },
      'output_dir': output_path,
      'artifact_type': target
  }

  output = CallBuildApiWithInputProto(
      buildroot,
      'chromite.api.ArtifactsService/BundleAFDOGenerationArtifacts',
      input_proto
  )

  return [artifact['path'] for artifact in output['artifacts']]


def VerifyAFDOArtifacts(buildroot, board, target, build_api):
  """Command to verify AFDO artifacts.

  This is only a wrapper of the build API. It doesn't validate the inputs.

  Args:
    buildroot: The path to build root.
    board: Name of the board.
    target: A valid toolchain_pb2.AFDOArtifactType.
    build_api: Full path of the build API. Only applies to APIs that returns
    a single field containing the status.

  Returns:
    True of False: The status of the build API.
  """
  input_proto = {
      'build_target': {
          'name': board,
      },
      'artifact_type': target
  }

  output = CallBuildApiWithInputProto(buildroot, build_api, input_proto)

  return output['status']


class ApiMismatchError(Exception):
  """Raised by GetTargetChromiteApiVersion."""


class NoChromiteError(Exception):
  """Raised when an expected chromite installation was missing."""


def GetTargetChromiteApiVersion(buildroot, validate_version=True):
  """Get the re-exec API version of the target chromite.

  Args:
    buildroot: The directory containing the chromite to check.
    validate_version: If set to true, checks the target chromite for
      compatibility, and raises an ApiMismatchError when there is an
      incompatibility.

  Returns:
    The version number in (major, minor) tuple.

  Raises:
    May raise an ApiMismatchError if validate_version is set.
  """
  try:
    api = cros_build_lib.run(
        [constants.PATH_TO_CBUILDBOT, '--reexec-api-version'],
        cwd=buildroot, check=False, encoding='utf-8', capture_output=True)
  except cros_build_lib.RunCommandError:
    # Although check=False was used, this exception will still be raised
    # if the executible did not exist.
    full_cbuildbot_path = os.path.join(buildroot, constants.PATH_TO_CBUILDBOT)
    if not os.path.exists(full_cbuildbot_path):
      raise NoChromiteError('No cbuildbot found in buildroot %s, expected to '
                            'find %s. ' % (buildroot, full_cbuildbot_path))
    raise

  # If the command failed, then we're targeting a cbuildbot that lacks the
  # option; assume 0:0 (ie, initial state).
  major = minor = 0
  if api.returncode == 0:
    major, minor = (int(x) for x in api.output.strip().split('.', 1))

  if validate_version and major != constants.REEXEC_API_MAJOR:
    raise ApiMismatchError(
        'The targeted version of chromite in buildroot %s requires '
        'api version %i, but we are api version %i.  We cannot proceed.'
        % (buildroot, major, constants.REEXEC_API_MAJOR))

  return major, minor
