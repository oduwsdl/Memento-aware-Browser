# -*- coding: utf-8 -*-
# Copyright 2016 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Unit tests for cros_mark_android_as_stable.py."""

from __future__ import print_function

import os
import sys

import mock
from six.moves import zip as izip

from chromite.lib import constants
from chromite.lib import cros_build_lib
from chromite.lib import cros_logging as logging
from chromite.lib import cros_test_lib
from chromite.lib import git
from chromite.lib import gs
from chromite.lib import gs_unittest
from chromite.lib import osutils
from chromite.lib import partial_mock
from chromite.lib import portage_util
from chromite.scripts import cros_mark_android_as_stable

pytestmark = cros_test_lib.pytestmark_inside_only


assert sys.version_info >= (3, 6), 'This module requires Python 3.6+'


class CrosMarkAndroidAsStable(cros_test_lib.MockTempDirTestCase):
  """Tests for cros_mark_android_as_stable."""

  unstable_data = 'KEYWORDS="~x86 ~arm"'
  stable_data = 'KEYWORDS="x86 arm"'

  STAT_OUTPUT = """%s:
        Creation time:    Sat, 23 Aug 2014 06:53:20 GMT
        Content-Language: en
        Content-Length:   74
        Content-Type:   application/octet-stream
        Hash (crc32c):    BBPMPA==
        Hash (md5):   ms+qSYvgI9SjXn8tW/5UpQ==
        ETag:     CNCgocbmqMACEAE=
        Generation:   1408776800850000
        Metageneration:   1
      """

  def setUp(self):
    """Setup vars and create mock dir."""
    self.android_package = constants.ANDROID_CONTAINER_PACKAGE_KEYWORD

    self.tmp_overlay = os.path.join(self.tempdir, 'chromiumos-overlay')
    self.mock_android_dir = os.path.join(
        self.tmp_overlay,
        portage_util.GetFullAndroidPortagePackageName(self.android_package))

    ebuild = os.path.join(self.mock_android_dir,
                          self.android_package + '-%s.ebuild')
    self.unstable = ebuild % '9999'
    self.old_version = '25'
    self.old = ebuild % self.old_version
    self.old2_version = '50'
    self.old2 = ebuild % self.old2_version
    self.new_version = '100'
    self.new = ebuild % ('%s-r1' % self.new_version)
    self.partial_new_version = '150'
    self.not_new_version = '200'

    osutils.WriteFile(self.unstable, self.unstable_data, makedirs=True)
    osutils.WriteFile(self.old, self.stable_data, makedirs=True)
    osutils.WriteFile(self.old2, self.stable_data, makedirs=True)

    self.arm_acl_data = '-g google.com:READ'
    self.x86_acl_data = '-g google.com:WRITE'
    self.arm_acl = os.path.join(self.mock_android_dir,
                                'googlestorage_arm_acl.txt')
    self.x86_acl = os.path.join(self.mock_android_dir,
                                'googlestorage_x86_acl.txt')
    self.acls = {
        'ARM': self.arm_acl,
        'ARM64': self.arm_acl,
        'X86': self.x86_acl,
        'X86_64': self.x86_acl,
        'ARM64_USERDEBUG': self.arm_acl,
        'X86_USERDEBUG': self.x86_acl,
        'X86_64_USERDEBUG': self.x86_acl,
        'SDK_GOOGLE_X86_USERDEBUG': self.x86_acl,
        'SDK_GOOGLE_X86_64_USERDEBUG': self.x86_acl,
    }

    osutils.WriteFile(self.arm_acl, self.arm_acl_data, makedirs=True)
    osutils.WriteFile(self.x86_acl, self.x86_acl_data, makedirs=True)

    self.bucket_url = 'gs://u'
    self.build_branch = constants.ANDROID_PI_BUILD_BRANCH
    self.gs_mock = self.StartPatcher(gs_unittest.GSContextMock())
    self.arc_bucket_url = 'gs://a'
    self.runtime_artifacts_bucket_url = 'gs://r'
    self.targets = cros_mark_android_as_stable.MakeBuildTargetDict(
        self.android_package, self.build_branch).copy()

    # Remove targets which were historically not covered by tests.
    # TODO(crbug.com/1074145): List of targets is generated dynamically here but
    # hardcoded everywhere else. Figure out a better way to test this.
    del self.targets['APPS']
    del self.targets['ARM_USERDEBUG']

    builds = {
        'ARM': [
            self.old_version, self.old2_version, self.new_version,
            self.partial_new_version
        ],
        'ARM64': [
            self.old_version, self.old2_version, self.new_version,
        ],
        'X86': [self.old_version, self.old2_version, self.new_version],
        'X86_64': [self.old_version, self.old2_version, self.new_version],
        'ARM64_USERDEBUG': [
            self.old_version, self.old2_version, self.new_version,
        ],
        'X86_USERDEBUG': [
            self.old_version, self.old2_version, self.new_version
        ],
        'X86_64_USERDEBUG': [
            self.old_version, self.old2_version, self.new_version
        ],
        'SDK_GOOGLE_X86_USERDEBUG': [
            self.old_version, self.old2_version, self.new_version
        ],
        'SDK_GOOGLE_X86_64_USERDEBUG': [
            self.old_version, self.old2_version, self.new_version
        ],
    }
    for build_type, builds in builds.items():
      url = self.makeSrcTargetUrl(self.targets[build_type][0])
      builds = '\n'.join(os.path.join(url, version) for version in builds)
      self.gs_mock.AddCmdResult(['ls', '--', url], output=builds)

    for version in [self.old_version, self.old2_version, self.new_version]:
      for key in self.targets.keys():
        self.setupMockBuild(key, version)
    self.new_subpaths = {
        'ARM': 'linux-cheets_arm-user100',
        'ARM64': 'linux-cheets_arm64-user100',
        'X86': 'linux-cheets_x86-user100',
        'X86_64': 'linux-cheets_x86_64-user100',
        'ARM64_USERDEBUG': 'linux-cheets_arm64-userdebug100',
        'X86_USERDEBUG': 'linux-cheets_x86-userdebug100',
        'X86_64_USERDEBUG': 'linux-cheets_x86_64-userdebug100',
        'SDK_GOOGLE_X86_USERDEBUG': 'linux-sdk_cheets_x86-userdebug100',
        'SDK_GOOGLE_X86_64_USERDEBUG': 'linux-sdk_cheets_x86_64-userdebug100',
    }

    self.setupMockBuild('ARM', self.partial_new_version)
    self.setupMockBuild('ARM64', self.partial_new_version, valid=False)
    self.setupMockBuild('X86', self.partial_new_version, valid=False)
    self.setupMockBuild('X86_64', self.partial_new_version, valid=False)
    self.setupMockBuild('ARM64_USERDEBUG', self.partial_new_version,
                        valid=False)
    self.setupMockBuild('X86_USERDEBUG', self.partial_new_version, valid=False)
    self.setupMockBuild('X86_64_USERDEBUG', self.partial_new_version,
                        valid=False)
    self.setupMockBuild('SDK_GOOGLE_X86_USERDEBUG', self.partial_new_version,
                        valid=False)
    self.setupMockBuild('SDK_GOOGLE_X86_64_USERDEBUG', self.partial_new_version,
                        valid=False)

    for key in self.targets.keys():
      self.setupMockBuild(key, self.not_new_version, False)

  def setupMockBuild(self, key, version, valid=True):
    """Helper to mock a build."""
    def _RaiseGSNoSuchKey(*_args, **_kwargs):
      raise gs.GSNoSuchKey('file does not exist')

    target = self.targets[key][0]
    src_url = self.makeSrcUrl(target, version)
    if valid:
      # Show source subpath directory.
      src_subdir = os.path.join(src_url, self.makeSubpath(target, version))
      self.gs_mock.AddCmdResult(['ls', '--', src_url], output=src_subdir)

      # Show files.
      mock_file_template_list = {
          'ARM': ['file-%(version)s.zip', 'adb', 'sepolicy.zip'],
          'ARM64': ['cheets_arm64-file-%(version)s.zip', 'sepolicy.zip'],
          'X86': ['file-%(version)s.zip'],
          'X86_64': ['file-%(version)s.zip'],
          'ARM64_USERDEBUG': ['cheets_arm64-file-%(version)s.zip', 'adb',
                              'sepolicy.zip'],
          'X86_USERDEBUG': ['cheets_x86-file-%(version)s.zip', 'sepolicy.zip'],
          'X86_64_USERDEBUG': ['cheets_x86_64-file-%(version)s.zip'],
          'SDK_GOOGLE_X86_USERDEBUG':
              ['sdk_cheets_x86-file-%(version)s.zip'],
          'SDK_GOOGLE_X86_64_USERDEBUG':
              ['sdk_cheets_x86_64-file-%(version)s.zip'],
      }
      filelist = [template % {'version': version}
                  for template in mock_file_template_list[key]]
      src_filelist = [os.path.join(src_subdir, filename)
                      for filename in filelist]
      self.gs_mock.AddCmdResult(['ls', '--', src_subdir],
                                output='\n'.join(src_filelist))
      for src_file in src_filelist:
        self.gs_mock.AddCmdResult(['stat', '--', src_file],
                                  output=(self.STAT_OUTPUT) % src_url)

      # Show nothing in destination.
      dst_url = self.makeDstUrl(target, version)
      # Show files.
      mock_file_template_list = {
          'ARM': ['file-%(version)s.zip', 'adb', 'sepolicy.zip'],
          'ARM64': ['cheets_arm64-file-%(version)s.zip', 'sepolicy.zip'],
          'X86': ['file-%(version)s.zip'],
          'X86_64': ['file-%(version)s.zip'],
          'ARM64_USERDEBUG': ['cheets_arm64_userdebug-file-%(version)s.zip',
                              'adb', 'sepolicy.zip'],
          'X86_USERDEBUG':
              ['cheets_x86_userdebug-file-%(version)s.zip', 'sepolicy.zip'],
          'X86_64_USERDEBUG': ['cheets_x86_64_userdebug-file-%(version)s.zip'],
          'SDK_GOOGLE_X86_USERDEBUG':
              ['cheets_sdk_google_x86_userdebug-file-%(version)s.zip'],
          'SDK_GOOGLE_X86_64_USERDEBUG':
              ['cheets_sdk_google_x86_64_userdebug-file-%(version)s.zip'],
      }
      filelist = [template % {'version': version}
                  for template in mock_file_template_list[key]]
      dst_filelist = [os.path.join(dst_url, filename)
                      for filename in filelist]
      for dst_file in dst_filelist:
        self.gs_mock.AddCmdResult(['stat', '--', dst_file],
                                  side_effect=_RaiseGSNoSuchKey)
      logging.warning('mocking no %s', dst_url)

      # Allow copying of source to dest.
      for src_file, dst_file in izip(src_filelist, dst_filelist):
        self.gs_mock.AddCmdResult(['cp', '-v', '--', src_file, dst_file])
    else:
      self.gs_mock.AddCmdResult(['ls', '--', src_url],
                                side_effect=_RaiseGSNoSuchKey)

  def setupMockRuntimeDataBuild(self, android_version):
    """Helper to mock a build for runtime data."""
    def _RaiseGSNoSuchKey(*_args, **_kwargs):
      raise gs.GSNoSuchKey('file does not exist')

    archs = ['arm', 'arm64', 'x86', 'x86_64']
    build_types = ['user', 'userdebug']
    runtime_datas = ['gms_core_cache', 'ureadahead_pack']

    for arch in archs:
      for build_type in build_types:
        for runtime_data in runtime_datas:
          path = (f'{self.runtime_artifacts_bucket_url}/{runtime_data}_{arch}_'
                  f'{build_type}_{android_version}.tar')
          self.gs_mock.AddCmdResult(['stat', '--', path],
                                    side_effect=_RaiseGSNoSuchKey)

  def makeSrcTargetUrl(self, target):
    """Helper to return the url for a target."""
    return os.path.join(self.bucket_url,
                        '%s-%s' % (self.build_branch, target))

  def makeSrcUrl(self, target, version):
    """Helper to return the url for a build."""
    return os.path.join(self.makeSrcTargetUrl(target), version)

  def makeDstTargetUrl(self, target):
    """Helper to return the url for a target."""
    return os.path.join(self.arc_bucket_url,
                        '%s-%s' % (self.build_branch, target))

  def makeDstUrl(self, target, version):
    """Helper to return the url for a build."""
    return os.path.join(self.makeDstTargetUrl(target), version)

  def makeSubpath(self, target, version):
    """Helper to return the subpath for a build."""
    return '%s%s' % (target, version)

  def testIsBuildIdValid(self):
    """Test if checking if build valid."""
    subpaths = cros_mark_android_as_stable.IsBuildIdValid(self.bucket_url,
                                                          self.build_branch,
                                                          self.old_version,
                                                          self.targets)
    self.assertTrue(subpaths)
    self.assertEqual(len(subpaths), 9)
    self.assertEqual(subpaths['ARM'], 'linux-cheets_arm-user25')
    self.assertEqual(subpaths['ARM64'], 'linux-cheets_arm64-user25')
    self.assertEqual(subpaths['X86'], 'linux-cheets_x86-user25')
    self.assertEqual(subpaths['X86_64'], 'linux-cheets_x86_64-user25')
    self.assertEqual(subpaths['ARM64_USERDEBUG'],
                     'linux-cheets_arm64-userdebug25')
    self.assertEqual(subpaths['X86_USERDEBUG'],
                     'linux-cheets_x86-userdebug25')
    self.assertEqual(subpaths['X86_64_USERDEBUG'],
                     'linux-cheets_x86_64-userdebug25')
    self.assertEqual(subpaths['SDK_GOOGLE_X86_USERDEBUG'],
                     'linux-sdk_cheets_x86-userdebug25')
    self.assertEqual(subpaths['SDK_GOOGLE_X86_64_USERDEBUG'],
                     'linux-sdk_cheets_x86_64-userdebug25')

    subpaths = cros_mark_android_as_stable.IsBuildIdValid(self.bucket_url,
                                                          self.build_branch,
                                                          self.new_version,
                                                          self.targets)
    self.assertEqual(subpaths, self.new_subpaths)

    subpaths = cros_mark_android_as_stable.IsBuildIdValid(
        self.bucket_url, self.build_branch, self.partial_new_version,
        self.targets)
    self.assertEqual(subpaths, None)

    subpaths = cros_mark_android_as_stable.IsBuildIdValid(self.bucket_url,
                                                          self.build_branch,
                                                          self.not_new_version,
                                                          self.targets)
    self.assertEqual(subpaths, None)

  def testFindAndroidCandidates(self):
    """Test creation of stable ebuilds from mock dir."""
    (unstable, stable) = cros_mark_android_as_stable.FindAndroidCandidates(
        self.mock_android_dir)

    stable_ebuild_paths = [x.ebuild_path for x in stable]
    self.assertEqual(unstable.ebuild_path, self.unstable)
    self.assertEqual(len(stable), 2)
    self.assertIn(self.old, stable_ebuild_paths)
    self.assertIn(self.old2, stable_ebuild_paths)

  def testGetLatestBuild(self):
    """Test determination of latest build from gs bucket."""
    version, subpaths = cros_mark_android_as_stable.GetLatestBuild(
        self.bucket_url, self.build_branch, self.targets)
    self.assertEqual(version, self.new_version)
    self.assertTrue(subpaths)
    self.assertEqual(len(subpaths), 9)
    self.assertEqual(subpaths['ARM'], 'linux-cheets_arm-user100')
    self.assertEqual(subpaths['ARM64'], 'linux-cheets_arm64-user100')
    self.assertEqual(subpaths['X86'], 'linux-cheets_x86-user100')
    self.assertEqual(subpaths['X86_64'], 'linux-cheets_x86_64-user100')
    self.assertEqual(subpaths['ARM64_USERDEBUG'],
                     'linux-cheets_arm64-userdebug100')
    self.assertEqual(subpaths['X86_USERDEBUG'],
                     'linux-cheets_x86-userdebug100')
    self.assertEqual(subpaths['X86_64_USERDEBUG'],
                     'linux-cheets_x86_64-userdebug100')
    self.assertEqual(subpaths['SDK_GOOGLE_X86_USERDEBUG'],
                     'linux-sdk_cheets_x86-userdebug100')
    self.assertEqual(subpaths['SDK_GOOGLE_X86_64_USERDEBUG'],
                     'linux-sdk_cheets_x86_64-userdebug100')

  def _AuxGetArcBasename(self, build, basename):
    """Helper function for readability."""
    # pylint: disable=protected-access
    return cros_mark_android_as_stable._GetArcBasename(build, basename)

  def testGetArcBasenameNoRename(self):
    """Test build targets that don't require renaming."""
    default_bn = 'do_not_rename_basename'
    no_rename_build_targets = ['ARM', 'ARM64', 'X86']
    for build in no_rename_build_targets:
      self.assertEqual(self._AuxGetArcBasename(build, default_bn), default_bn)

    self.assertEqual(self._AuxGetArcBasename('UNKNOWN', default_bn), default_bn)
    self.assertEqual(self._AuxGetArcBasename('', default_bn), default_bn)
    self.assertEqual(self._AuxGetArcBasename(None, default_bn), default_bn)

  def testGetArcBasenameRenameValid(self):
    """Test renaming when input basename is valid."""
    # Actual name patterns.
    build_targets = {
        'X86_USERDEBUG':
            ('cheets_x86-target_files-25.zip',
             'cheets_x86_userdebug-target_files-25.zip'),
        'SDK_GOOGLE_X86_USERDEBUG':
            ('sdk_cheets_x86-target_files-25.zip',
             'cheets_sdk_google_x86_userdebug-target_files-25.zip'),
    }
    for build, (src, dst) in build_targets.items():
      self.assertEqual(self._AuxGetArcBasename(build, src), dst)

    # More generic name patterns.
    build_targets['X86_USERDEBUG'] = (
        ('cheets_-XXX', 'cheets_x86_userdebug-XXX')
    )
    build_targets['SDK_GOOGLE_X86_USERDEBUG'] = (
        ('cheets_-XXX', 'cheets_sdk_google_x86_userdebug-XXX')
    )
    for build, (src, dst) in build_targets.items():
      self.assertEqual(self._AuxGetArcBasename(build, src), dst)

    # Check bertha also.
    build_targets['X86_USERDEBUG'] = (
        ('bertha_-XXX', 'bertha_x86_userdebug-XXX')
    )
    build_targets['SDK_GOOGLE_X86_USERDEBUG'] = (
        ('bertha_-XXX', 'bertha_sdk_google_x86_userdebug-XXX')
    )
    for build, (src, dst) in build_targets.items():
      self.assertEqual(self._AuxGetArcBasename(build, src), dst)

  def testGetArcBasenameRenameInvalid(self):
    """Test that basename is unchanged if it's not as expected."""
    # Missing hyphen.
    self.assertEqual(self._AuxGetArcBasename('X86_USERDEBUG',
                                             'cheets_x86.zip'),
                     'cheets_x86.zip')
    # Missing 'cheets_' before first hyphen.
    self.assertEqual(self._AuxGetArcBasename('X86_USERDEBUG',
                                             'marlin_x86-25.zip'),
                     'marlin_x86-25.zip')
    self.assertEqual(self._AuxGetArcBasename('X86_USERDEBUG',
                                             'XX-cheets_x86-25.zip'),
                     'XX-cheets_x86-25.zip')

  def testCopyToArcBucket(self):
    """Test copying of images to ARC bucket."""
    # Allow setting of dest acls.
    self.gs_mock.AddCmdResult(partial_mock.In('acl'))
    cros_mark_android_as_stable.CopyToArcBucket(self.bucket_url,
                                                self.build_branch,
                                                self.new_version,
                                                self.new_subpaths,
                                                self.targets,
                                                self.arc_bucket_url,
                                                self.acls)

  def testMakeAclDict(self):
    """Test generation of acls dictionary."""
    acls = cros_mark_android_as_stable.MakeAclDict(self.mock_android_dir)
    self.assertEqual(acls['ARM'], os.path.join(self.mock_android_dir,
                                               'googlestorage_acl_arm.txt'))
    self.assertEqual(acls['ARM64'], os.path.join(self.mock_android_dir,
                                                 'googlestorage_acl_arm.txt'))
    self.assertEqual(acls['ARM64_USERDEBUG'],
                     os.path.join(self.mock_android_dir,
                                  'googlestorage_acl_arm.txt'))
    self.assertEqual(acls['X86'], os.path.join(self.mock_android_dir,
                                               'googlestorage_acl_x86.txt'))
    # Test that all PI targets have their ACLS set.
    for t in cros_mark_android_as_stable.MakeBuildTargetDict(
        constants.ANDROID_CONTAINER_PACKAGE_KEYWORD,
        constants.ANDROID_PI_BUILD_BRANCH).keys():
      self.assertIn(t, acls)
    # Test that all VMPI targets have their ACLS set.
    for t in cros_mark_android_as_stable.MakeBuildTargetDict(
        constants.ANDROID_VM_PACKAGE_KEYWORD,
        constants.ANDROID_VMPI_BUILD_BRANCH).keys():
      self.assertIn(t, acls)
    # Test that all VMMST targets have their ACLS set.
    for t in cros_mark_android_as_stable.MakeBuildTargetDict(
        constants.ANDROID_VM_PACKAGE_KEYWORD,
        constants.ANDROID_VMMST_BUILD_BRANCH).keys():
      self.assertIn(t, acls)

  def testMakeBuildTargetDictPI(self):
    """Test generation of PI build target dictionary.

    If the number of targets is correct and PI-specific targets are
    present, then the dictionary is correct.
    """
    targets = cros_mark_android_as_stable.MakeBuildTargetDict(
        'android-container-pi',
        constants.ANDROID_PI_BUILD_BRANCH)
    # Test the number of targets.
    self.assertEqual(len(targets),
                     len(constants.ANDROID_PI_BUILD_TARGETS))
    # Test that all PI-specific targets are in the dictionary.
    for target in constants.ANDROID_PI_BUILD_TARGETS:
      self.assertEqual(targets[target],
                       constants.ANDROID_PI_BUILD_TARGETS[target])

  def testMakeBuildTargetDictVMPI(self):
    """Test generation of VMPI build target dictionary.

    If the number of targets is correct and VMPI-specific targets are
    present, then the dictionary is correct.
    """
    targets = cros_mark_android_as_stable.MakeBuildTargetDict(
        'android-vm-pi',
        constants.ANDROID_VMPI_BUILD_BRANCH)
    # Test the number of targets.
    self.assertEqual(len(targets),
                     len(constants.ANDROID_VMPI_BUILD_TARGETS))
    # Test that all VMPI-specific targets are in the dictionary.
    for target in constants.ANDROID_VMPI_BUILD_TARGETS:
      self.assertEqual(targets[target],
                       constants.ANDROID_VMPI_BUILD_TARGETS[target])

  def testMakeBuildTargetDictVMMst(self):
    """Test generation of VMMst build target dictionary.

    If the number of targets is correct and VMMst-specific targets are
    present, then the dictionary is correct.
    """
    targets = cros_mark_android_as_stable.MakeBuildTargetDict(
        'android-vm-master',
        constants.ANDROID_VMMST_BUILD_BRANCH)
    # Test the number of targets.
    self.assertEqual(len(targets),
                     len(constants.ANDROID_VMMST_BUILD_TARGETS))
    # Test that all VMMst-specific targets are in the dictionary.
    for target in constants.ANDROID_VMMST_BUILD_TARGETS:
      self.assertEqual(targets[target],
                       constants.ANDROID_VMMST_BUILD_TARGETS[target])

  def testMakeBuildTargetDictException(self):
    """Test that passing invalid branch names throws ValueError exception."""
    self.assertRaises(ValueError,
                      cros_mark_android_as_stable.MakeBuildTargetDict,
                      constants.ANDROID_CONTAINER_PACKAGE_KEYWORD,
                      'INVALID_BRANCH_NAME')
    self.assertRaises(ValueError,
                      cros_mark_android_as_stable.MakeBuildTargetDict,
                      'invalid-package',
                      constants.ANDROID_VMPI_BUILD_BRANCH)

  def testMarkAndroidEBuildAsStable(self):
    """Test updating of ebuild."""
    self.PatchObject(cros_build_lib, 'run')
    self.PatchObject(portage_util.EBuild, 'GetCrosWorkonVars',
                     return_value=None)
    git_mock = self.PatchObject(git, 'RunGit')
    commit_mock = self.PatchObject(portage_util.EBuild, 'CommitChange')
    stable_candidate = portage_util.EBuild(self.old2)
    unstable = portage_util.EBuild(self.unstable)
    android_version = self.new_version
    package_dir = self.mock_android_dir
    self.setupMockRuntimeDataBuild(android_version)
    version_atom = cros_mark_android_as_stable.MarkAndroidEBuildAsStable(
        stable_candidate, unstable, self.android_package, android_version,
        package_dir, self.build_branch, self.arc_bucket_url,
        self.runtime_artifacts_bucket_url, self.targets)
    git_mock.assert_has_calls([
        mock.call(package_dir, ['add', self.new]),
        mock.call(package_dir, ['add', 'Manifest']),
    ])
    commit_mock.assert_called_with(partial_mock.HasString('latest'),
                                   package_dir)
    self.assertEqual(
        version_atom,
        '%s-%s-r1' % (
            portage_util.GetFullAndroidPortagePackageName(self.android_package),
            self.new_version))

  def testUpdateDataCollectorArtifacts(self):
    android_version = 100
    # Mock by default runtime artifacts are not found.
    self.setupMockRuntimeDataBuild(android_version)

    # Override few as existing.
    path1 = (f'{self.runtime_artifacts_bucket_url}/ureadahead_pack_x86_64_'
             f'user_{android_version}.tar')
    self.gs_mock.AddCmdResult(['stat', '--', path1],
                              stdout=(self.STAT_OUTPUT) % path1)
    path2 = (f'{self.runtime_artifacts_bucket_url}/gms_core_cache_arm_'
             f'userdebug_{android_version}.tar')
    self.gs_mock.AddCmdResult(['stat', '--', path2],
                              stdout=(self.STAT_OUTPUT) % path2)

    variables = cros_mark_android_as_stable.UpdateDataCollectorArtifacts(
        android_version, self.runtime_artifacts_bucket_url)

    self.assertEqual(2, len(variables))
    self.assertIn('X86_64_USER_UREADAHEAD_PACK', variables)
    version_reference = '${PV}'
    expectation1 = (f'{self.runtime_artifacts_bucket_url}/'
                    f'ureadahead_pack_x86_64_user_{version_reference}.tar')
    self.assertEqual(expectation1, variables['X86_64_USER_UREADAHEAD_PACK'])
    self.assertIn('ARM_USERDEBUG_GMS_CORE_CACHE', variables)
    expectation2 = (f'{self.runtime_artifacts_bucket_url}/'
                    f'gms_core_cache_arm_userdebug_{version_reference}.tar')
    self.assertEqual(expectation2, variables['ARM_USERDEBUG_GMS_CORE_CACHE'])
