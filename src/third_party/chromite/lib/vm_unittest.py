# -*- coding: utf-8 -*-
# Copyright 2019 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Unit tests for VM."""

from __future__ import print_function

import fcntl
import multiprocessing
import os
import socket
import stat
import sys

import mock

from chromite.cli.cros import cros_chrome_sdk
from chromite.lib import constants
from chromite.lib import cros_build_lib
from chromite.lib import cros_logging as logging
from chromite.lib import cros_test_lib
from chromite.lib import device
from chromite.lib import osutils
from chromite.lib import partial_mock
from chromite.lib import remote_access
from chromite.lib import vm

pytestmark = cros_test_lib.pytestmark_inside_only


assert sys.version_info >= (3, 6), 'This module requires Python 3.6+'


# pylint: disable=protected-access
class VMTester(cros_test_lib.RunCommandTempDirTestCase):
  """Test vm.VM."""

  def setUp(self):
    """Common set up method for all tests."""
    opts = vm.VM.GetParser().parse_args([])
    opts.enable_kvm = True
    with mock.patch.object(multiprocessing, 'cpu_count', return_value=8):
      self._vm = vm.VM(opts)
    self._vm.use_sudo = False
    self._vm.board = 'amd64-generic'
    self._vm.cache_dir = self.tempdir
    self._vm.image_path = self.TempFilePath('chromiumos_qemu_image.bin')
    osutils.Touch(self._vm.image_path)

    self.nested_kvm_file = self.TempFilePath('kvm_intel_nested')
    osutils.WriteFile(self.nested_kvm_file, 'N')
    # Make the glob match the path we just created for nested_kvm_file.
    self._vm.NESTED_KVM_GLOB = os.path.join(
        os.path.dirname(self.nested_kvm_file), 'kvm_*_nested')

    # Satisfy QEMU version check.
    version_str = ('QEMU emulator version 2.6.0, Copyright (c) '
                   '2003-2008 Fabrice Bellard')
    self.rc.AddCmdResult(partial_mock.In('--version'), output=version_str)

    self.ssh_port = self._vm.ssh_port

  def TempFilePath(self, file_path):
    return os.path.join(self.tempdir, file_path)

  def TempVMPath(self, kvm_file):
    return self.TempFilePath(os.path.join('cros_vm_%d' % self.ssh_port,
                                          kvm_file))

  def FindPathInArgs(self, args, path):
    """Checks the called commands to see if the path is present.

    Args:
      args: List of called commands.
      path: Path to check if present in the called commands.

    Returns:
      Whether the path is found in the called commands.
    """
    for call in args:
      # A typical call looks like:
      # call(['.../chroot/usr/bin/qemu-system-x86_64', '--version'],
      #      capture_output=True)
      if any(path in a for a in call[0][0]):
        return True
    return False

  def testStart(self):
    self._vm.Start()
    self.assertCommandContains([self._vm.qemu_path])
    self.assertCommandContains(['-m', '8G', '-smp', '8', '-vga', 'virtio',
                                '-daemonize', '-usbdevice', 'tablet',])
    self.assertCommandContains([
        '-pidfile', self.TempVMPath('kvm.pid'),
        '-chardev', 'pipe,id=control_pipe,path=%s'
        % self.TempVMPath('kvm.monitor'),
        '-serial', 'file:%s' % self.TempVMPath('kvm.monitor.serial'),
        '-mon', 'chardev=control_pipe',
    ])
    self.assertCommandContains([
        '-cpu', 'SandyBridge,-invpcid,-tsc-deadline,check',
    ])
    self.assertCommandContains([
        '-device', 'virtio-net,netdev=eth0',
        '-netdev', 'user,id=eth0,net=10.0.2.0/27,hostfwd=tcp:127.0.0.1:9222-:22'
    ])
    self.assertCommandContains([
        '-device', 'virtio-scsi-pci,id=scsi', '-device', 'scsi-hd,drive=hd',
        '-drive', 'if=none,id=hd,file=%s,cache=unsafe,format=raw'
        % self.TempFilePath('chromiumos_qemu_image.bin'),
    ])
    self.assertCommandContains(['-enable-kvm'])

  @mock.patch('chromite.lib.device.Device.WaitForBoot')
  def testStartRetriesSuccess(self, mock_wait):
    """Start() should return normally if WaitForBoot fails transiently once."""
    mock_wait.side_effect = (
        device.DeviceError('error'),
        True,
    )
    self._vm.Start()

  @mock.patch('chromite.lib.device.Device.WaitForBoot')
  def testStartRetriesFailure(self, mock_wait):
    """Start() should raise a DeviceError if WaitForBoot fails all attempts."""
    mock_wait.side_effect = (
        device.DeviceError('error'),
        device.DeviceError('error'),
    )
    self.assertRaises(device.DeviceError, self._vm.Start)

  def testStartWithVMX(self):
    """Verify vmx is enabled if the host supports nested virtualizaton."""
    osutils.WriteFile(self.nested_kvm_file, '1')
    self._vm.Start()
    self.assertCommandContains([
        '-cpu', 'SandyBridge,-invpcid,-tsc-deadline,check,vmx=on',
    ])

  def testStop(self):
    pid = '12345'
    self.assertEqual(self._vm.pidfile, self.TempVMPath('kvm.pid'))
    osutils.WriteFile(self._vm.pidfile, pid)
    self._vm.Stop()
    self.assertCommandContains(['kill', '-9', pid])

  def testBuiltVMImagePath(self):
    """Verify locally built VM image path is picked up by vm.VM."""
    self._vm.image_path = None
    expected_vm_image_path = os.path.join(constants.SOURCE_ROOT,
                                          'src/build/images/%s/latest/'
                                          'chromiumos_qemu_image.bin'
                                          % self._vm.board)
    osutils.Touch(expected_vm_image_path, makedirs=True)
    self._vm.Start()
    self.assertTrue(self.FindPathInArgs(self.rc.call_args_list,
                                        expected_vm_image_path))

  def testSDKVMImagePath(self):
    """Verify vm.VM picks up the downloaded VM in the SDK."""
    self._vm.image_path = None
    vm_image_dir = cros_test_lib.FakeSDKCache(
        self._vm.cache_dir).CreateCacheReference(self._vm.board,
                                                 constants.VM_IMAGE_TAR)
    vm_image_path = os.path.join(vm_image_dir, constants.VM_IMAGE_BIN)
    osutils.Touch(vm_image_path, makedirs=True)
    self._vm.Start()
    expected_vm_image_path = os.path.join(
        self._vm.cache_dir,
        'chrome-sdk/symlinks/%s+12225.0.0+chromiumos_qemu_image.tar.xz/'
        'chromiumos_qemu_image.bin' % self._vm.board)
    self.assertTrue(self.FindPathInArgs(self.rc.call_args_list,
                                        expected_vm_image_path))

  def testVMImageNotFound(self):
    """Verify that VMError is raised when a fake board image cannot be found."""
    self._vm.image_path = None
    self._vm.board = 'fake_board_name'
    self.assertRaises(vm.VMError, self._vm.Start)

  def testVMImageDoesNotExist(self):
    """Verify that VMError is raised when image path is not real."""
    self._vm.image_path = '/fake/path/to/the/vm/image'
    self.assertRaises(vm.VMError, self._vm.Start)

  def testAppendBinFile(self):
    """When image-path points to a directory, we should append the bin file."""
    self._vm.image_path = self.tempdir
    self._vm.Start()
    self.assertEqual(self._vm.image_path,
                     self.TempFilePath('chromiumos_qemu_image.bin'))

  def testChrootQemuPath(self):
    """Verify that QEMU in the chroot is picked up by vm.VM."""
    if cros_build_lib.IsInsideChroot():
      self._vm._SetQemuPath()
      self.assertTrue('usr/bin/qemu-system-x86_64' in self._vm.qemu_path)

  def testSDKQemuPath(self):
    """Verify vm.VM picks up the downloaded QEMU in the SDK."""
    self._vm.qemu_path = None
    qemu_dir_path = cros_chrome_sdk.SDKFetcher.QEMU_BIN_PATH
    # Creates a fake SDK cache with the QEMU binary.
    qemu_path = cros_test_lib.FakeSDKCache(
        self._vm.cache_dir).CreateCacheReference(self._vm.board, qemu_dir_path)
    qemu_path = os.path.join(qemu_path,
                             'usr', 'bin', 'qemu-system-x86_64')
    osutils.Touch(qemu_path, makedirs=True)
    self._vm._SetQemuPath()
    self.assertEqual(self._vm.qemu_path, qemu_path)

  @mock.patch('chromite.lib.vm.VM._CheckQemuMinVersion')
  def testSystemQemuPath(self, check_min_version_mock):
    """Verify that QEMU in the system is picked up by vm.VM."""
    # Skip the SDK Cache.
    os.environ[cros_chrome_sdk.SDKFetcher.SDK_VERSION_ENV] = 'None'

    # Skip the Chroot.
    self._vm.chroot_path = 'fake/path'

    # Checks the QEMU path in the system.
    qemu_path = self.TempFilePath('qemu-system-x86_64')
    osutils.Touch(qemu_path, mode=stat.S_IRWXU, makedirs=True)
    qemu_dir = os.path.dirname(qemu_path)

    os.environ['PATH'] = qemu_dir
    self._vm._SetQemuPath()

    # SetQemuPath() calls _CheckQemuMinVersion().
    # Checks that mock version has been called.
    check_min_version_mock.assert_called()

    self.assertEqual(self._vm.qemu_path, qemu_path)

  def testInvalidQemuBiosPath(self):
    """Verify that VMError is raised for nonexistent qemu bios path."""
    self._vm.qemu_bios_path = '/invalid/qemu/bios/path/'
    self.assertRaises(vm.VMError, self._vm.Start)

  def testCreateQcow2Image(self):
    """Tests that a qcow2 image is created with --copy-on-write."""
    self._vm.copy_on_write = True
    initial_img_path = self._vm.image_path
    self._vm.Start()

    # The command that creates the Qcow2 image.
    self.assertCommandContains([
        self._vm.qemu_img_path, 'create', '-f', 'qcow2', '-o',
        'backing_file=%s' % initial_img_path, os.path.join(self._vm.vm_dir,
                                                           'qcow2.img')])
    # The command that launches a VM with the new Qcow2 image.
    self.assertCommandContains([
        '-drive', 'if=none,id=hd,file=%s,cache=unsafe,format=qcow2'
        % os.path.join(self._vm.vm_dir, 'qcow2.img')
    ])

  @mock.patch('os.path.isfile', return_value=False)
  @mock.patch('chromite.lib.osutils.Which', return_value=None)
  def testQemuNotFound(self, which_mock, is_file_mock):
    """Verify that VMError is raised when qemu path cannot be set."""
    self.assertRaises(vm.VMError, self._vm._SetQemuPath)
    which_mock.assert_called()
    is_file_mock.assert_called()

  def testQemuImageNotFound(self):
    """Veryify that VMError is raised for nonexistent qemu image path."""
    self._vm.copy_on_write = True
    self._vm.qemu_img_path = '/invalid/qemu/img/path/'
    self.assertRaises(vm.VMError, self._vm._SetQemuPath)

  def testRmVMDir(self):
    """Verify that the vm directory is removed after calling RmVMDir."""
    self.assertExists(self._vm.vm_dir)
    self._vm.use_sudo = False
    self._vm.Stop()
    self.assertNotExists(self._vm.vm_dir)

  @mock.patch('chromite.lib.osutils.SafeMakedirs', return_value=False)
  def testCreateVMDirError(self, make_dir_mock):
    """Verify that an error is raised when vm_dir is not a valid directory."""
    self._vm.vm_dir = '/not/a/valid/dir'
    self.assertRaises(AssertionError, self._vm._CreateVMDir)
    make_dir_mock.assert_called()

  @mock.patch('chromite.lib.osutils.SafeMakedirs', return_value=False)
  def testCreateVMDirLinkError(self, make_dir_mock):
    """Verify that an error is raised when vm_dir is a symbolic link."""
    # Create the symlink.
    symlink = self.TempFilePath('symlink')
    os.symlink(self.TempFilePath('fakepath'), symlink)
    self._vm.vm_dir = symlink

    self.assertRaises(AssertionError, self._vm._CreateVMDir)
    make_dir_mock.assert_called()

  @mock.patch('chromite.lib.osutils.SafeMakedirs', return_value=False)
  @mock.patch('os.getuid')
  def testCreateVMDirStatError(self, getuid_mock, make_dir_mock):
    """Verify an error is raised  when user does not own the vm dir."""
    self.assertRaises(AssertionError, self._vm._CreateVMDir)
    getuid_mock.assert_called()
    make_dir_mock.assert_called()

  def testQemuVersionError(self):
    """Verify that VMError is raised without an expected QEMU version number."""
    version_str = 'Fake Version String'
    self.rc.AddCmdResult(partial_mock.In('--version'), output=version_str)
    self.assertRaises(vm.VMError, self._vm._SetQemuPath)

  def testQemuVersion(self):
    """Verify that the correct QEMU version is identified."""
    version_str = ('QEMU emulator version 2.8.0, Copyright (c) '
                   '2003-2008 Fabrice Bellard')
    self.rc.AddCmdResult(partial_mock.In('--version'), output=version_str)
    self._vm._SetQemuPath()
    self.assertEqual('2.8.0', self._vm.QemuVersion())
    self.assertCommandContains([self._vm.qemu_path, '--version'])

  def testCheckQemuError(self):
    """Verify that VMError is raised when the QEMU version is too old."""
    version_str = ('QEMU emulator version 2.5.0, Copyright (c) '
                   '2003-2008 Fabrice Bellard')
    self.rc.AddCmdResult(partial_mock.In('--version'), output=version_str)
    self.assertRaises(vm.VMError, self._vm._SetQemuPath)

  def testRunError(self):
    """Verify that VMError is raised when no action is specified."""
    self._vm.start = False
    self._vm.stop = False
    self._vm.cmd = None
    self.assertRaises(vm.VMError, self._vm.Run)

  def testIsRunningError(self):
    """Verify that VMError is raised when VM is not running."""
    self._vm.cmd = ['fake_command', '--test_cmd']
    self.assertRaises(vm.VMError, self._vm.Run)

  @mock.patch('chromite.lib.vm.VM.IsRunning', return_value=True)
  def testRunRemoteCmd(self, is_running_mock):
    """Tests that the VM runs with a specific command."""
    self._vm.cmd = ['fake_command', '--test_cmd']
    self._vm.Run()
    self.assertCommandContains([
        'ssh', '-p', '9222', 'root@localhost', '--',
        'fake_command', '--test_cmd'])
    is_running_mock.assert_called()

  def testGetVMPidDir(self):
    """Verify that isRunning is False with a nonexistent directory."""
    self._vm.vm_dir = 'fake/directory'
    self.assertFalse(self._vm.IsRunning())

  def testGetVMPidFile(self):
    """Verify that isRunning is False with a nonexistent pid file."""
    self._vm.pidfile = 'fake/pid/file'
    self.assertFalse(self._vm.IsRunning())

  def testPidString(self):
    """Verify that isRunning is False if the pid is not an integer."""
    osutils.WriteFile(self._vm.pidfile, 'fake_pid')
    self.assertFalse(self._vm.IsRunning())

  def testGetVMPid(self):
    """Verify that a proper pid number kills the VM process."""
    # Using this process's pid to fake the VM's pid.
    pid = str(os.getpid())
    osutils.WriteFile(self._vm.pidfile, pid)
    self.assertTrue(self._vm.IsRunning())
    self._vm.Stop()
    self.assertCommandContains(['kill', '-9', pid])

  def testBiosPath(self):
    """Verify QEMU bios path."""
    self._vm.qemu_bios_path = self.TempFilePath('qemu/bios/path')
    osutils.SafeMakedirs(self._vm.qemu_bios_path)
    self._vm.Start()
    self.assertCommandContains(['-L', self._vm.qemu_bios_path])

  def testQemuHost(self):
    """Verify QEMU host forwarding."""
    self._vm.ssh_port = 1028
    self._vm.qemu_hostfwd = ['tcp:127.0.0.1:1024-:22']
    self._vm.Start()
    self.assertCommandContains(
        ['-netdev', 'user,id=eth0,net=10.0.2.0/27,'
         'hostfwd=tcp:127.0.0.1:1028-:22,hostfwd=tcp:127.0.0.1:1024-:22'])

  def testQemuArgs(self):
    """Verify QEMU arguments."""
    self._vm.qemu_args = ['-portrait', '-full-screen', '-no-reboot']
    self._vm.Start()
    self.assertCommandContains(['-portrait', '-full-screen', '-no-reboot'])

  def testNoDisplay(self):
    """Check the command call's arguments when there is no display."""
    self._vm.display = False
    self._vm.Start()
    self.assertCommandContains(['-display', 'none'])

  def testWaitForSSHPort(self):
    """Verify VM correctly waits on the SSH port if it is busy."""
    # Assigning an unused port to the VM SSH Port.
    self._vm.ssh_port = remote_access.GetUnusedPort()
    sock = socket.socket()
    sock.bind((remote_access.LOCALHOST_IP, self._vm.ssh_port))

    # Look for retry messages in output.
    with cros_test_lib.LoggingCapturer(log_level=logging.INFO) as logger:
      self.assertRaises(vm.VMError, self._vm._WaitForSSHPort, sleep=0)
    in_use_message = 'SSH port %d in use' % self._vm.ssh_port
    self.assertTrue(logger.LogsMatch((in_use_message + '...\n') * 11 +
                                     in_use_message + '\n'))

    # Verify the VM works correctly when the port is not in use.
    # There should be no retries after the port is released.
    # Another process could grab the unused port between closing it
    # and calling _WaitForSSHPort but this is extremely unlikely.
    sock.close()
    with cros_test_lib.LoggingCapturer(log_level=logging.INFO) as logger:
      self._vm._WaitForSSHPort()
    self.assertEqual(logger.messages, '')

  @mock.patch('chromite.lib.remote_access.RemoteDevice.GetRunningPids',
              return_value=[])
  def testWaitForProcsError(self, pid_mocker):
    """Verify an error is raised when no chrome processes are running."""
    # Look for retry messages in output.
    with cros_test_lib.LoggingCapturer(log_level=logging.INFO) as logger:
      self.assertRaises(vm.VMError, self._vm._WaitForProcs, sleep=0)

    pid_message = 'chrome pids: []\n'
    self.assertTrue(logger.LogsContain(pid_message * 6))
    self.assertTrue(
        logger.LogsContain('_WaitForProcs failed: timed out while waiting'
                           ' for 8 chrome processes to start.\n'))
    pid_mocker.assert_called()

  @mock.patch('chromite.lib.remote_access.RemoteDevice.GetRunningPids',
              return_value=[756, 905, 1065, 1092, 1096, 1171, 1180, 1181])
  def testWaitForProcs(self, pid_mocker):
    """Verify VM waits for chrome processes to launch."""
    # Check the log output for expected chrome pids.
    with cros_test_lib.LoggingCapturer(log_level=logging.INFO) as logger:
      self._vm._WaitForProcs(sleep=0)
    self.assertEqual(logger.messages, 'chrome pids: '
                     '[756, 905, 1065, 1092, 1096, 1171, 1180, 1181]\n')
    pid_mocker.assert_called()

  @mock.patch('chromite.lib.vm.VM._WaitForProcs')
  @mock.patch('chromite.lib.device.Device.WaitForBoot')
  @mock.patch('chromite.lib.vm.VM.Start')
  def testWaitForBoot(self, start_mock, boot_mock, procs_mock):
    """Verify that we wait for the VM to boot up under different conditions."""
    # Testing with an existing VM directory and hardware emulation.
    self._vm.vm_dir = self.TempFilePath('vm_dir')
    osutils.SafeMakedirs(self._vm.vm_dir)
    self._vm.enable_kvm = True
    self._vm.WaitForBoot()
    start_mock.assert_not_called()
    boot_mock.assert_called()
    procs_mock.assert_not_called()

    start_mock.reset_mock()
    boot_mock.reset_mock()
    procs_mock.reset_mock()

    # Testing with a non-existent VM directory and software emulation.
    self._vm._RmVMDir()
    self._vm.enable_kvm = False
    self._vm.WaitForBoot()
    start_mock.assert_called()
    boot_mock.assert_called()
    procs_mock.assert_called()

  @mock.patch('fcntl.fcntl')
  def testSaveVMImageOnShutdownBasic(self, fcntl_mock):
    # mock.mock_open only seems to properly mock out read, not readline, so
    # do it ourselves.
    def readline_impl():
      readline_impl.count += 1
      if readline_impl.count == 1:
        return 'some_output\n'
      return 'thisisafakecommand\n'
    readline_impl.count = 0

    fcntl_mock.return_value = 0

    builtin = '__builtin__' if sys.version_info[0] == 2 else 'builtins'
    m = mock.mock_open()
    filehandle = m()
    filehandle.readline.side_effect = readline_impl
    with mock.patch('%s.open' % builtin, m, create=True):
      self._vm.SaveVMImageOnShutdown('/some/dir/')

    self.assertTrue(self._vm.copy_image_on_shutdown)
    self.assertEqual(self._vm.image_copy_dir, '/some/dir/')

    write_calls = [
        mock.call('savevm chromite_lib_vm_snapshot\n'),
        mock.call('thisisafakecommand\n'),
    ]
    filehandle.write.assert_has_calls(write_calls)
    self.assertEqual(filehandle.write.call_count, 2)

    fcntl_calls = [
        mock.call(mock.ANY, fcntl.F_GETFL),
        mock.call(mock.ANY, fcntl.F_SETFL, os.O_NONBLOCK),
    ]
    fcntl_mock.assert_has_calls(fcntl_calls)
    self.assertEqual(fcntl_mock.call_count, 2)

  @mock.patch('fcntl.fcntl')
  @mock.patch('time.time')
  @mock.patch('time.sleep')
  def testSaveVMImageOnShutdownTimeout(self, sleep_mock, time_mock, fcntl_mock):
    def time_impl():
      time_impl.count += 1
      if time_impl.count <= 2:
        return 0
      if time_impl.count == 3:
        return 30
      if time_impl.count == 4:
        return 31
      return 100
    time_impl.count = 0
    time_mock.side_effect = time_impl

    fcntl_mock.return_value = 0

    self._vm.copy_on_write = True
    builtin = '__builtin__' if sys.version_info[0] == 2 else 'builtins'
    m = mock.mock_open()
    filehandle = m()
    filehandle.readline.side_effect = IOError(
        'Resource temporarily unavailable')
    with mock.patch('%s.open' % builtin, m, create=True):
      self._vm.SaveVMImageOnShutdown('/some/dir/')

    self.assertEqual(sleep_mock.call_count, 1)

    self.assertTrue(self._vm.copy_image_on_shutdown)
    self.assertEqual(self._vm.image_copy_dir, '/some/dir/')

    write_calls = [
        mock.call('savevm chromite_lib_vm_snapshot\n'),
        mock.call('thisisafakecommand\n'),
    ]
    filehandle.write.assert_has_calls(write_calls)
    self.assertEqual(filehandle.write.call_count, 2)

    fcntl_calls = [
        mock.call(mock.ANY, fcntl.F_GETFL),
        mock.call(mock.ANY, fcntl.F_SETFL, os.O_NONBLOCK),
    ]
    fcntl_mock.assert_has_calls(fcntl_calls)
    self.assertEqual(fcntl_mock.call_count, 2)
