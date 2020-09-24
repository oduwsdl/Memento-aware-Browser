# -*- coding: utf-8 -*-
# Copyright 2019 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Packages service tests."""

from __future__ import print_function

import json
import os
import re

from google.protobuf import json_format
from google.protobuf.field_mask_pb2 import FieldMask
import pytest

import chromite as cr
from chromite.api.gen.config.replication_config_pb2 import (
    ReplicationConfig, FileReplicationRule, FILE_TYPE_JSON,
    REPLICATION_TYPE_FILTER
)
from chromite.cbuildbot import manifest_version
from chromite.lib import build_target_lib
from chromite.lib import constants
from chromite.lib import cros_build_lib
from chromite.lib import cros_test_lib
from chromite.lib import osutils
from chromite.lib import partial_mock
from chromite.lib import portage_util
from chromite.lib import uprev_lib
from chromite.lib.chroot_lib import Chroot
from chromite.lib.uprev_lib import GitRef
from chromite.service import packages


D = cros_test_lib.Directory


class UprevAndroidTest(cros_test_lib.RunCommandTestCase):
  """Uprev android tests."""

  def test_success(self):
    """Test successful run handling."""
    self.rc.AddCmdResult(partial_mock.In('cros_mark_android_as_stable'),
                         stdout='ANDROID_ATOM=android/android-1.0\n')
    build_targets = [build_target_lib.BuildTarget(t) for t in ['foo', 'bar']]

    packages.uprev_android('refs/tracking-branch', 'android/package',
                           'refs/android-build-branch', Chroot(),
                           build_targets=build_targets)
    self.assertCommandContains(['cros_mark_android_as_stable',
                                '--boards=foo:bar'])
    self.assertCommandContains(['emerge-foo'])
    self.assertCommandContains(['emerge-bar'])

  def test_no_uprev(self):
    """Test no uprev handling."""
    self.rc.AddCmdResult(partial_mock.In('cros_mark_android_as_stable'),
                         stdout='')
    build_targets = [build_target_lib.BuildTarget(t) for t in ['foo', 'bar']]
    packages.uprev_android('refs/tracking-branch', 'android/package',
                           'refs/android-build-branch', Chroot(),
                           build_targets=build_targets)

    self.assertCommandContains(['cros_mark_android_as_stable',
                                '--boards=foo:bar'])
    self.assertCommandContains(['emerge-foo'], expected=False)
    self.assertCommandContains(['emerge-bar'], expected=False)


class UprevBuildTargetsTest(cros_test_lib.RunCommandTestCase):
  """uprev_build_targets tests."""

  def test_invalid_type_fails(self):
    """Test invalid type fails."""
    with self.assertRaises(AssertionError):
      packages.uprev_build_targets([build_target_lib.BuildTarget('foo')],
                                   'invalid')

  def test_none_type_fails(self):
    """Test None type fails."""
    with self.assertRaises(AssertionError):
      packages.uprev_build_targets([build_target_lib.BuildTarget('foo')],
                                   None)


class UprevsVersionedPackageTest(cros_test_lib.MockTestCase):
  """uprevs_versioned_package decorator test."""

  @packages.uprevs_versioned_package('category/package')
  def uprev_category_package(self, *args, **kwargs):
    """Registered function for testing."""

  def test_calls_function(self):
    """Test calling a registered function."""
    self.PatchObject(self, 'uprev_category_package')

    cpv = portage_util.SplitCPV('category/package', strict=False)
    packages.uprev_versioned_package(cpv, [], [], Chroot())

    # TODO(crbug/1065172): Invalid assertion that had previously been mocked.
    # patch.assert_called()

  def test_unregistered_package(self):
    """Test calling with an unregistered package."""
    cpv = portage_util.SplitCPV('does-not/exist', strict=False)

    with self.assertRaises(packages.UnknownPackageError):
      packages.uprev_versioned_package(cpv, [], [], Chroot())


class UprevEbuildFromPinTest(cros_test_lib.RunCommandTempDirTestCase):
  """Tests uprev_ebuild_from_pin function"""

  package = 'category/package'
  version = '1.2.3'
  new_version = '1.2.4'
  ebuild_template = 'package-%s-r1.ebuild'
  ebuild = ebuild_template % version
  version_pin = 'VERSION-PIN'
  manifest = 'Manifest'

  def test_uprev_ebuild(self):
    """Tests uprev of ebuild with version path"""
    file_layout = (
        D(self.package, [self.ebuild, self.version_pin, self.manifest]),
    )
    cros_test_lib.CreateOnDiskHierarchy(self.tempdir, file_layout)

    package_path = os.path.join(self.tempdir, self.package)
    version_pin_path = os.path.join(package_path, self.version_pin)
    self.WriteTempFile(version_pin_path, self.new_version)

    result = packages.uprev_ebuild_from_pin(package_path, version_pin_path,
                                            chroot=Chroot())
    self.assertEqual(len(result.modified), 1,
                     'unexpected number of results: %s' % len(result.modified))

    mod = result.modified[0]
    self.assertEqual(mod.new_version, self.new_version,
                     'unexpected version number: %s' % mod.new_version)

    old_ebuild_path = os.path.join(package_path,
                                   self.ebuild_template % self.version)
    new_ebuild_path = os.path.join(package_path,
                                   self.ebuild_template % self.new_version)
    manifest_path = os.path.join(package_path, 'Manifest')

    expected_modified_files = [old_ebuild_path, new_ebuild_path, manifest_path]
    self.assertCountEqual(mod.files, expected_modified_files)

    self.assertCommandContains(['ebuild', 'manifest'])

  def test_no_ebuild(self):
    """Tests assertion is raised if package has no ebuilds"""
    file_layout = (
        D(self.package, [self.version_pin, self.manifest]),
    )
    cros_test_lib.CreateOnDiskHierarchy(self.tempdir, file_layout)

    package_path = os.path.join(self.tempdir, self.package)
    version_pin_path = os.path.join(package_path, self.version_pin)
    self.WriteTempFile(version_pin_path, self.new_version)

    with self.assertRaises(packages.UprevError):
      packages.uprev_ebuild_from_pin(package_path, version_pin_path,
                                     chroot=Chroot())

  def test_multiple_ebuilds(self):
    """Tests assertion is raised if multiple ebuilds are present for package"""
    file_layout = (
        D(self.package, [self.version_pin, self.ebuild,
                         self.ebuild_template % '1.2.1',
                         self.manifest]),
    )
    cros_test_lib.CreateOnDiskHierarchy(self.tempdir, file_layout)

    package_path = os.path.join(self.tempdir, self.package)
    version_pin_path = os.path.join(package_path, self.version_pin)
    self.WriteTempFile(version_pin_path, self.new_version)

    with self.assertRaises(packages.UprevError):
      packages.uprev_ebuild_from_pin(package_path, version_pin_path,
                                     chroot=Chroot())


class ReplicatePrivateConfigTest(cros_test_lib.RunCommandTempDirTestCase):
  """replicate_private_config tests."""

  def setUp(self):
    # Set up fake public and private chromeos-config overlays.
    private_package_root = (
        'src/private-overlays/overlay-coral-private/chromeos-base/'
        'chromeos-config-bsp'
    )
    self.public_package_root = (
        'src/overlays/overlay-coral/chromeos-base/chromeos-config-bsp')
    file_layout = (
        D(os.path.join(private_package_root, 'files'), ['build_config.json']),
        D(private_package_root, ['replication_config.jsonpb']),
        D(
            os.path.join(self.public_package_root, 'files'),
            ['build_config.json']),
    )

    cros_test_lib.CreateOnDiskHierarchy(self.tempdir, file_layout)

    # Private config contains 'a' and 'b' fields.
    self.private_config_path = os.path.join(private_package_root, 'files',
                                            'build_config.json')
    self.WriteTempFile(
        self.private_config_path,
        json.dumps({'chromeos': {
            'configs': [{
                'a': 3,
                'b': 2
            }]
        }}))

    # Public config only contains the 'a' field. Note that the value of 'a' is
    # 1 in the public config; it will get updated to 3 when the private config
    # is replicated.
    self.public_config_path = os.path.join(self.public_package_root, 'files',
                                           'build_config.json')
    self.WriteTempFile(self.public_config_path,
                       json.dumps({'chromeos': {
                           'configs': [{
                               'a': 1
                           }]
                       }}))

    # Put a ReplicationConfig JSONPB in the private package. Note that it
    # specifies only the 'a' field is replicated.
    self.replication_config_path = os.path.join(self.tempdir,
                                                private_package_root,
                                                'replication_config.jsonpb')
    replication_config = ReplicationConfig(file_replication_rules=[
        FileReplicationRule(
            source_path=self.private_config_path,
            destination_path=self.public_config_path,
            file_type=FILE_TYPE_JSON,
            replication_type=REPLICATION_TYPE_FILTER,
            destination_fields=FieldMask(paths=['a']))
    ])

    osutils.WriteFile(self.replication_config_path,
                      json_format.MessageToJson(replication_config))
    self.PatchObject(constants, 'SOURCE_ROOT', new=self.tempdir)

    self.rc.SetDefaultCmdResult(side_effect=self._write_generated_c_files)

  def _write_generated_c_files(self, *_args, **_kwargs):
    """Write fake generated C files to the public output dir.

    Note that this function accepts args and kwargs so it can be used as a side
    effect.
    """
    output_dir = os.path.join(self.public_package_root, 'files')
    self.WriteTempFile(os.path.join(output_dir, 'config.c'), '')
    self.WriteTempFile(os.path.join(output_dir, 'ec_config.c'), '')
    self.WriteTempFile(os.path.join(output_dir, 'ec_config.h'), '')

  def _write_incorrect_generated_c_files(self, *_args, **_kwargs):
    """Similar to _write_generated_c_files, with an expected file missing.

    Note that this function accepts args and kwargs so it can be used as a side
    effect.
    """
    output_dir = os.path.join(self.public_package_root, 'files')
    self.WriteTempFile(os.path.join(output_dir, 'config.c'), '')
    self.WriteTempFile(os.path.join(output_dir, 'ec_config.c'), '')

  def test_replicate_private_config(self):
    """Basic replication test."""
    refs = [
        GitRef(
            path='/chromeos/overlays/overlay-coral-private',
            ref='master',
            revision='123')
    ]
    chroot = Chroot()
    result = packages.replicate_private_config(
        _build_targets=None, refs=refs, chroot=chroot)

    self.assertCommandContains([
        'cros_config_schema', '-m',
        os.path.join(constants.CHROOT_SOURCE_ROOT, self.public_config_path),
        '-g',
        os.path.join(constants.CHROOT_SOURCE_ROOT, self.public_package_root,
                     'files'), '-f', '"TRUE"'
    ],
                               enter_chroot=True,
                               chroot_args=chroot.get_enter_args())

    self.assertEqual(len(result.modified), 1)
    # The public build_config.json and generated C files were modified.
    expected_modified_files = [
        os.path.join(self.tempdir, self.public_config_path),
        os.path.join(self.tempdir, self.public_package_root, 'files',
                     'config.c'),
        os.path.join(self.tempdir, self.public_package_root, 'files',
                     'ec_config.c'),
        os.path.join(self.tempdir, self.public_package_root, 'files',
                     'ec_config.h'),
    ]
    self.assertEqual(result.modified[0].files, expected_modified_files)
    self.assertEqual(result.modified[0].new_version, '123')

    # The update from the private build_config.json was copied to the public.
    # Note that only the 'a' field is present, as per destination_fields.
    self.assertEqual(
        json.loads(self.ReadTempFile(self.public_config_path)),
        {'chromeos': {
            'configs': [{
                'a': 3
            }]
        }})

  def test_replicate_private_config_no_build_config(self):
    """If there is no build config, don't generate C files."""
    # Modify the replication config to write to "other_config.json" instead of
    # "build_config.json"
    modified_destination_path = self.public_config_path.replace(
        'build_config', 'other_config')
    replication_config = ReplicationConfig(file_replication_rules=[
        FileReplicationRule(
            source_path=self.private_config_path,
            destination_path=modified_destination_path,
            file_type=FILE_TYPE_JSON,
            replication_type=REPLICATION_TYPE_FILTER,
            destination_fields=FieldMask(paths=['a']))
    ])
    osutils.WriteFile(self.replication_config_path,
                      json_format.MessageToJson(replication_config))

    refs = [
        GitRef(
            path='/chromeos/overlays/overlay-coral-private',
            ref='master',
            revision='123')
    ]
    result = packages.replicate_private_config(
        _build_targets=None, refs=refs, chroot=Chroot())

    self.assertEqual(len(result.modified), 1)
    self.assertEqual(result.modified[0].files,
                     [os.path.join(self.tempdir, modified_destination_path)])

  def test_replicate_private_config_multiple_build_configs(self):
    """An error is thrown if there is more than one build config."""
    replication_config = ReplicationConfig(file_replication_rules=[
        FileReplicationRule(
            source_path=self.private_config_path,
            destination_path=self.public_config_path,
            file_type=FILE_TYPE_JSON,
            replication_type=REPLICATION_TYPE_FILTER,
            destination_fields=FieldMask(paths=['a'])),
        FileReplicationRule(
            source_path=self.private_config_path,
            destination_path=self.public_config_path,
            file_type=FILE_TYPE_JSON,
            replication_type=REPLICATION_TYPE_FILTER,
            destination_fields=FieldMask(paths=['a']))
    ])

    osutils.WriteFile(self.replication_config_path,
                      json_format.MessageToJson(replication_config))

    refs = [
        GitRef(
            path='/chromeos/overlays/overlay-coral-private',
            ref='master',
            revision='123')
    ]
    with self.assertRaisesRegex(
        ValueError, 'Expected at most one build_config.json destination path.'):
      packages.replicate_private_config(
          _build_targets=None, refs=refs, chroot=Chroot())

  def test_replicate_private_config_generated_files_incorrect(self):
    """An error is thrown if generated C files are missing."""
    self.rc.SetDefaultCmdResult(
        side_effect=self._write_incorrect_generated_c_files)

    refs = [
        GitRef(
            path='/chromeos/overlays/overlay-coral-private',
            ref='master',
            revision='123')
    ]
    chroot = Chroot()

    with self.assertRaisesRegex(packages.GeneratedCrosConfigFilesError,
                                'Expected to find generated C files'):
      packages.replicate_private_config(
          _build_targets=None, refs=refs, chroot=chroot)

  def test_replicate_private_config_wrong_number_of_refs(self):
    """An error is thrown if there is not exactly one ref."""
    with self.assertRaisesRegex(ValueError, 'Expected exactly one ref'):
      packages.replicate_private_config(
          _build_targets=None, refs=[], chroot=None)

    with self.assertRaisesRegex(ValueError, 'Expected exactly one ref'):
      refs = [
          GitRef(path='a', ref='master', revision='1'),
          GitRef(path='a', ref='master', revision='2')
      ]
      packages.replicate_private_config(
          _build_targets=None, refs=refs, chroot=None)

  def test_replicate_private_config_replication_config_missing(self):
    """An error is thrown if there is not a replication config."""
    os.remove(self.replication_config_path)
    with self.assertRaisesRegex(
        ValueError, 'Expected ReplicationConfig missing at %s' %
        self.replication_config_path):
      refs = [
          GitRef(
              path='/chromeos/overlays/overlay-coral-private',
              ref='master',
              revision='123')
      ]
      packages.replicate_private_config(
          _build_targets=None, refs=refs, chroot=None)

  def test_replicate_private_config_wrong_git_ref_path(self):
    """An error is thrown if the git ref doesn't point to a private overlay."""
    with self.assertRaisesRegex(ValueError, 'ref.path must match the pattern'):
      refs = [
          GitRef(
              path='a/b/c',
              ref='master',
              revision='123')
      ]
      packages.replicate_private_config(
          _build_targets=None, refs=refs, chroot=None)


class GetBestVisibleTest(cros_test_lib.TestCase):
  """get_best_visible tests."""

  def test_empty_atom_fails(self):
    with self.assertRaises(AssertionError):
      packages.get_best_visible('')


class HasPrebuiltTest(cros_test_lib.MockTestCase):
  """has_prebuilt tests."""

  def test_empty_atom_fails(self):
    """Test an empty atom results in an error."""
    with self.assertRaises(AssertionError):
      packages.has_prebuilt('')

  def test_use_flags(self):
    """Test use flags get propagated correctly."""
    # We don't really care about the result, just the env handling.
    patch = self.PatchObject(portage_util, 'HasPrebuilt', return_value=True)
    # Ignore any flags that may be in the environment.
    self.PatchObject(os.environ, 'get', return_value='')

    packages.has_prebuilt('cat/pkg-1.2.3', useflags='useflag')
    patch.assert_called_with('cat/pkg-1.2.3', board=None,
                             extra_env={'USE': 'useflag'})

  def test_env_use_flags(self):
    """Test env use flags get propagated correctly with passed useflags."""
    # We don't really care about the result, just the env handling.
    patch = self.PatchObject(portage_util, 'HasPrebuilt', return_value=True)
    # Add some flags to the environment.
    existing_flags = 'already set flags'
    self.PatchObject(os.environ, 'get', return_value=existing_flags)

    new_flags = 'useflag'
    packages.has_prebuilt('cat/pkg-1.2.3', useflags=new_flags)
    expected = '%s %s' % (existing_flags, new_flags)
    patch.assert_called_with('cat/pkg-1.2.3', board=None,
                             extra_env={'USE': expected})



class AndroidVersionsTest(cros_test_lib.MockTestCase):
  """Tests getting android versions."""

  def setUp(self):
    package_result = [
        'chromeos-base/android-container-nyc-4717008-r1',
        'chromeos-base/update_engine-0.0.3-r3408']
    self.PatchObject(portage_util, 'GetPackageDependencies',
                     return_value=package_result)
    self.board = 'board'
    self.PatchObject(portage_util, 'FindEbuildForBoardPackage',
                     return_value='chromeos-base/android-container-nyc')
    FakeEnvironment = {
        'ARM_TARGET': '3-linux-target',
    }
    self.PatchObject(osutils, 'SourceEnvironment',
                     return_value=FakeEnvironment)

  def test_determine_android_version(self):
    """Tests that a valid android version is returned."""
    version = packages.determine_android_version(self.board)
    self.assertEqual(version, '4717008')

  def test_determine_android_version_when_not_present(self):
    """Tests that a None is returned for version when android is not present."""
    package_result = ['chromeos-base/update_engine-0.0.3-r3408']
    self.PatchObject(portage_util, 'GetPackageDependencies',
                     return_value=package_result)
    version = packages.determine_android_version(self.board)
    self.assertEqual(version, None)

  def test_determine_android_branch(self):
    """Tests that a valid android branch is returned."""
    branch = packages.determine_android_branch(self.board)
    self.assertEqual(branch, '3')

  def test_determine_android_branch_64bit_targets(self):
    """Tests that a valid android branch is returned with only 64bit targets."""
    self.PatchObject(osutils, 'SourceEnvironment',
                     return_value={'ARM64_TARGET': '3-linux-target'})
    branch = packages.determine_android_branch(self.board)
    self.assertEqual(branch, '3')

  def test_determine_android_branch_when_not_present(self):
    """Tests that a None is returned for branch when android is not present."""
    package_result = ['chromeos-base/update_engine-0.0.3-r3408']
    self.PatchObject(portage_util, 'GetPackageDependencies',
                     return_value=package_result)
    branch = packages.determine_android_branch(self.board)
    self.assertEqual(branch, None)

  def test_determine_android_target(self):
    """Tests that a valid android target is returned."""
    target = packages.determine_android_target(self.board)
    self.assertEqual(target, 'cheets')

  def test_determine_android_target_when_not_present(self):
    """Tests that a None is returned for target when android is not present."""
    package_result = ['chromeos-base/update_engine-0.0.3-r3408']
    self.PatchObject(portage_util, 'GetPackageDependencies',
                     return_value=package_result)
    target = packages.determine_android_target(self.board)
    self.assertEqual(target, None)

  def test_determine_android_version_handle_exception(self):
    """Tests handling RunCommandError inside determine_android_version."""
    # Mock what happens when portage returns that bubbles up (via RunCommand)
    # inside portage_util.GetPackageDependencies.
    self.PatchObject(portage_util, 'GetPackageDependencies',
                     side_effect=cros_build_lib.RunCommandError('error'))
    target = packages.determine_android_version(self.board)
    self.assertEqual(target, None)

  def test_determine_android_package_handle_exception(self):
    """Tests handling RunCommandError inside determine_android_package."""
    # Mock what happens when portage returns that bubbles up (via RunCommand)
    # inside portage_util.GetPackageDependencies.
    self.PatchObject(portage_util, 'GetPackageDependencies',
                     side_effect=cros_build_lib.RunCommandError('error'))
    target = packages.determine_android_package(self.board)
    self.assertEqual(target, None)

  def test_determine_android_package_callers_handle_exception(self):
    """Tests handling RunCommandError by determine_android_package callers."""
    # Mock what happens when portage returns that bubbles up (via RunCommand)
    # inside portage_util.GetPackageDependencies.
    self.PatchObject(portage_util, 'GetPackageDependencies',
                     side_effect=cros_build_lib.RunCommandError('error'))
    # Verify that target is None, as expected.
    target = packages.determine_android_package(self.board)
    self.assertEqual(target, None)
    # determine_android_branch calls determine_android_package
    branch = packages.determine_android_branch(self.board)
    self.assertEqual(branch, None)
    # determine_android_target calls determine_android_package
    target = packages.determine_android_target(self.board)
    self.assertEqual(target, None)


@pytest.mark.usefixtures('testcase_caplog', 'testcase_monkeypatch')
class FindFingerprintsTest(cros_test_lib.RunCommandTempDirTestCase):
  """Tests for find_fingerprints."""

  def setUp(self):
    self.board = 'test-board'
    # Create cheets-fingerprints.txt based on tempdir/src...
    self.fingerprint_contents = (
        'google/test-board/test-board_cheets'
        ':9/R99-12345.0.9999/123456:user/release-keys')
    fingerprint_path = os.path.join(
        self.tempdir,
        'src/build/images/test-board/latest/cheets-fingerprint.txt')
    self.chroot = Chroot(self.tempdir)
    osutils.WriteFile(fingerprint_path, self.fingerprint_contents,
                      makedirs=True)

  def test_find_fingerprints_with_test_path(self):
    """Tests get_firmware_versions with mocked output."""
    self.monkeypatch.setattr(constants, 'SOURCE_ROOT', self.tempdir)
    build_target = build_target_lib.BuildTarget(self.board)
    result = packages.find_fingerprints(build_target)
    self.assertEqual(result, [self.fingerprint_contents])
    self.assertIn('Reading fingerprint file', self.caplog.text)

  def test_find_fingerprints(self):
    """Tests get_firmware_versions with mocked output."""
    # Use board name whose path for fingerprint file does not exist.
    # Verify that fingerprint file is not found and None is returned.
    build_target = build_target_lib.BuildTarget('wrong-boardname')
    self.monkeypatch.setattr(constants, 'SOURCE_ROOT', self.tempdir)
    result = packages.find_fingerprints(build_target)
    self.assertEqual(result, [])
    self.assertIn('Fingerprint file not found', self.caplog.text)


class GetAllFirmwareVersionsTest(cros_test_lib.RunCommandTempDirTestCase):
  """Tests for get_firmware_versions."""

  def setUp(self):
    self.board = 'test-board'
    self.rc.SetDefaultCmdResult(output="""

flashrom(8): 68935ee2fcfcffa47af81b966269cd2b */build/reef/usr/sbin/flashrom
             ELF 64-bit LSB executable, x86-64, version 1 (SYSV), statically linked, for GNU/Linux 2.6.32, BuildID[sha1]=e102cc98d45300b50088999d53775acbeff407dc, stripped
             0.9.9  : bbb2d6a : Jul 28 2017 15:12:34 UTC

Model:        reef
BIOS image:   1b535280fe688ac284d95276492b06f6 */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/reef/image.bin
BIOS version: Google_Reef.9042.87.1
BIOS (RW) image:   0ef265eb8f2d228c09f75b011adbdcbb */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/reef/image.binrw
BIOS (RW) version: Google_Reef.9042.110.0
EC image:     2e8b4b5fa73cc5dbca4496de97a917a9 */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/reef/ec.bin
EC version:   reef_v1.1.5900-ab1ee51
EC (RW) version: reef_v1.1.5909-bd1f0c9

Model:        pyro
BIOS image:   9e62447ebf22a724a4a835018ab6234e */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/pyro/image.bin
BIOS version: Google_Pyro.9042.87.1
BIOS (RW) image:   1897457303c85de99f3e98b2eaa0eccc */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/pyro/image.binrw
BIOS (RW) version: Google_Pyro.9042.110.0
EC image:     44b93ed591733519e752e05aa0529eb5 */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/pyro/ec.bin
EC version:   pyro_v1.1.5900-ab1ee51
EC (RW) version: pyro_v1.1.5909-bd1f0c9

Model:        snappy
BIOS image:   3ab63ff080596bd7de4e7619f003bb64 */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/snappy/image.bin
BIOS version: Google_Snappy.9042.110.0
EC image:     c4db159e84428391d2ee25368c5fe5b6 */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/snappy/ec.bin
EC version:   snappy_v1.1.5909-bd1f0c9

Model:        sand
BIOS image:   387da034a4f0a3f53e278ebfdcc2a412 */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/sand/image.bin
BIOS version: Google_Sand.9042.110.0
EC image:     411562e0589dacec131f5fdfbe95a561 */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/sand/ec.bin
EC version:   sand_v1.1.5909-bd1f0c9

Model:        electro
BIOS image:   1b535280fe688ac284d95276492b06f6 */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/reef/image.bin
BIOS version: Google_Reef.9042.87.1
BIOS (RW) image:   0ef265eb8f2d228c09f75b011adbdcbb */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/reef/image.binrw
BIOS (RW) version: Google_Reef.9042.110.0
EC image:     2e8b4b5fa73cc5dbca4496de97a917a9 */build/reef/tmp/portage/chromeos-base/chromeos-firmware-reef-0.0.1-r79/temp/tmp7rHApL.pack_firmware-99001/models/reef/ec.bin
EC version:   reef_v1.1.5900-ab1ee51
EC (RW) version: reef_v1.1.5909-bd1f0c9

Package Content:
612e7bb6ed1fb0a05abf2ebdc834c18b *./updater4.sh
0eafbee07282315829d0f42135ec7c0c *./gbb_utility
6074e3ca424cb30a67c378c1d9681f9c *./mosys
68935ee2fcfcffa47af81b966269cd2b *./flashrom
0eafbee07282315829d0f42135ec7c0c *./dump_fmap
490c95d6123c208d20d84d7c16857c7c *./crosfw.sh
60899148600b8673ddb711faa55aee40 *./common.sh
3c3a99346d1ca1273cbcd86c104851ff *./shflags
de7ce035e1f82a89f8909d888ee402c0 *./crosutil.sh
f9334372bdb9036ba09a6fd9bf30e7a2 *./crossystem
22257a8d5f0adc1f50a1916c3a4a35dd *./models/reef/ec.bin
faf12dbb7cdaf21ce153bdffb67841fd *./models/reef/bios.bin
c9bbb417b7921b85a7ed999ee42f550e *./models/reef/setvars.sh
29823d46f1ec1491ecacd7b830fd2686 *./models/pyro/ec.bin
2320463aba8b22eb5ea836f094d281b3 *./models/pyro/bios.bin
81614833ad77c9cd093360ba7bea76b8 *./models/pyro/setvars.sh
411562e0589dacec131f5fdfbe95a561 *./models/sand/ec.bin
387da034a4f0a3f53e278ebfdcc2a412 *./models/sand/bios.bin
fcd8cb0ac0e2ed6be220aaae435d43ff *./models/sand/setvars.sh
c4db159e84428391d2ee25368c5fe5b6 *./models/snappy/ec.bin
3ab63ff080596bd7de4e7619f003bb64 *./models/snappy/bios.bin
fe5d699f2e9e4a7de031497953313dbd *./models/snappy/setvars.sh
79aabd7cd8a215a54234c53d7bb2e6fb *./vpd
""")

  def test_get_firmware_versions(self):
    """Tests get_firmware_versions with mocked output."""
    build_target = build_target_lib.BuildTarget(self.board)
    result = packages.get_all_firmware_versions(build_target)
    self.assertEqual(len(result), 5)
    self.assertEqual(
        result['reef'],
        packages.FirmwareVersions(
            'reef',
            'Google_Reef.9042.87.1',
            'Google_Reef.9042.110.0',
            'reef_v1.1.5900-ab1ee51',
            'reef_v1.1.5909-bd1f0c9'))
    self.assertEqual(
        result['pyro'],
        packages.FirmwareVersions(
            'pyro',
            'Google_Pyro.9042.87.1',
            'Google_Pyro.9042.110.0',
            'pyro_v1.1.5900-ab1ee51',
            'pyro_v1.1.5909-bd1f0c9'))
    self.assertEqual(
        result['snappy'],
        packages.FirmwareVersions(
            'snappy',
            'Google_Snappy.9042.110.0',
            None,
            'snappy_v1.1.5909-bd1f0c9',
            None))
    self.assertEqual(
        result['sand'],
        packages.FirmwareVersions(
            'sand',
            'Google_Sand.9042.110.0',
            None,
            'sand_v1.1.5909-bd1f0c9',
            None))
    self.assertEqual(
        result['electro'],
        packages.FirmwareVersions(
            'electro',
            'Google_Reef.9042.87.1',
            'Google_Reef.9042.110.0',
            'reef_v1.1.5900-ab1ee51',
            'reef_v1.1.5909-bd1f0c9'))


class GetFirmwareVersionsTest(cros_test_lib.RunCommandTempDirTestCase):
  """Tests for get_firmware_versions."""

  def setUp(self):
    self.board = 'test-board'
    self.rc.SetDefaultCmdResult(output="""

flashrom(8): a8f99c2e61e7dc09c4b25ef5a76ef692 */build/kevin/usr/sbin/flashrom
             ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), statically linked, for GNU/Linux 2.d
             0.9.4  : 860875a : Apr 10 2017 23:54:29 UTC

BIOS image:   6b5b855a0b8fd1657546d1402c15b206 *chromeos-firmware-kevin-0.0.1/.dist/kevin_fw_8785.178.0.n
BIOS version: Google_Kevin.8785.178.0
EC image:     1ebfa9518e6cac0558a80b7ab2f5b489 *chromeos-firmware-kevin-0.0.1/.dist/kevin_ec_8785.178.0.n
EC version:kevin_v1.10.184-459421c

Package Content:
a8f99c2e61e7dc09c4b25ef5a76ef692 *./flashrom
3c3a99346d1ca1273cbcd86c104851ff *./shflags
457a8dc8546764affc9700f8da328d23 *./dump_fmap
c392980ddb542639edf44a965a59361a *./updater5.sh
490c95d6123c208d20d84d7c16857c7c *./crosfw.sh
6b5b855a0b8fd1657546d1402c15b206 *./bios.bin
7b5bef0d2da90c23ff2e157250edf0fa *./crosutil.sh
d78722e4f1a0dc2d8c3d6b0bc7010ae3 *./crossystem
457a8dc8546764affc9700f8da328d23 *./gbb_utility
1ebfa9518e6cac0558a80b7ab2f5b489 *./ec.bin
c98ca54db130886142ad582a58e90ddc *./common.sh
5ba978bdec0f696f47f0f0de90936880 *./mosys
312e8ee6122057f2a246d7bcf1572f49 *./vpd
""")

  def test_get_firmware_versions(self):
    """Tests get_firmware_versions with mocked output."""
    build_target = build_target_lib.BuildTarget(self.board)
    result = packages.get_firmware_versions(build_target)
    versions = packages.FirmwareVersions(
        None, 'Google_Kevin.8785.178.0', None, 'kevin_v1.10.184-459421c', None)
    self.assertEqual(result, versions)


class DetermineKernelVersionTest(cros_test_lib.RunCommandTempDirTestCase):
  """Tests for determine_kernel_version."""

  def setUp(self):
    self.board = 'test-board'
    self.build_target = build_target_lib.BuildTarget(self.board)

  def test_determine_kernel_version(self):
    """Tests that a valid kernel version is returned."""
    package_result = ['sys-kernel/linux-headers-4.14-r24',
                      'sys-devel/flex-2.6.4-r1',
                      'sys-kernel/chromeos-kernel-4_4-4.4.223-r2209']
    self.PatchObject(portage_util, 'GetPackageDependencies',
                     return_value=package_result)

    result = packages.determine_kernel_version(self.build_target)
    self.assertEqual(result, '4.4.223-r2209')

  def test_determine_kernel_version_exception(self):
    """Tests that portage_util exceptions result in returning None."""
    self.PatchObject(portage_util, 'GetPackageDependencies',
                     side_effect=cros_build_lib.RunCommandError('error'))
    result = packages.determine_kernel_version(self.build_target)
    self.assertEqual(result, None)

class ChromeVersionsTest(cros_test_lib.MockTestCase):
  """Tests getting chrome version."""

  def setUp(self):
    self.build_target = build_target_lib.BuildTarget('board')

  def test_determine_chrome_version(self):
    """Tests that a valid chrome version is returned."""
    # Mock PortageqBestVisible to return a valid chrome version string.
    r1_cpf = 'chromeos-base/chromeos-chrome-78.0.3900.0_rc-r1'
    r1_cpv = portage_util.SplitCPV(r1_cpf)
    self.PatchObject(portage_util, 'PortageqBestVisible',
                     return_value=r1_cpv)

    chrome_version = packages.determine_chrome_version(self.build_target)
    version_numbers = chrome_version.split('.')
    self.assertEqual(len(version_numbers), 4)
    self.assertEqual(int(version_numbers[0]), 78)

  def test_determine_chrome_version_handle_exception(self):
    # Mock what happens when portage throws an exception that bubbles up (via
    # RunCommand)inside portage_util.PortageqBestVisible.
    self.PatchObject(portage_util, 'PortageqBestVisible',
                     side_effect=cros_build_lib.RunCommandError('error'))
    target = packages.determine_chrome_version(self.build_target)
    self.assertEqual(target, None)


class PlatformVersionsTest(cros_test_lib.MockTestCase):
  """Tests getting platform version."""

  def test_determine_platform_version(self):
    """Test checking that a valid platform version is returned."""
    platform_version = packages.determine_platform_version()
    # The returned platform version is something like 12603.0.0.
    version_string_list = platform_version.split('.')
    self.assertEqual(len(version_string_list), 3)
    # We don't want to check an exact version, but the first number should be
    # non-zero.
    self.assertGreaterEqual(int(version_string_list[0]), 1)

  def test_determine_milestone_version(self):
    """Test checking that a valid milestone version is returned."""
    milestone_version = packages.determine_milestone_version()
    # Milestone version should be non-zero
    self.assertGreaterEqual(int(milestone_version), 1)

  def test_determine_full_version(self):
    """Test checking that a valid full version is returned."""
    full_version = packages.determine_full_version()
    pattern = r'^R(\d+)-(\d+.\d+.\d+(-rc\d+)*)'
    m = re.match(pattern, full_version)
    self.assertTrue(m)
    milestone_version = m.group(1)
    self.assertGreaterEqual(int(milestone_version), 1)

  def test_versions_based_on_mock(self):
    # Create a test version_info object, and than mock VersionInfo.from_repo
    # return it.
    test_platform_version = '12575.0.0'
    test_chrome_branch = '75'
    version_info_mock = manifest_version.VersionInfo(test_platform_version)
    version_info_mock.chrome_branch = test_chrome_branch
    self.PatchObject(manifest_version.VersionInfo, 'from_repo',
                     return_value=version_info_mock)
    test_full_version = 'R' + test_chrome_branch + '-' + test_platform_version
    platform_version = packages.determine_platform_version()
    milestone_version = packages.determine_milestone_version()
    full_version = packages.determine_full_version()
    self.assertEqual(platform_version, test_platform_version)
    self.assertEqual(milestone_version, test_chrome_branch)
    self.assertEqual(full_version, test_full_version)


# Each of the columns in the following table is a separate dimension along
# which Chrome uprev test cases can vary in behavior. The full test space would
# be the Cartesian product of the possible values of each column.
# 'CHROME_EBUILD' refers to the relationship between the version of the existing
# Chrome ebuild vs. the requested uprev version. 'FOLLOWER_EBUILDS' refers to
# the same relationship but for the packages defined in OTHER_CHROME_PACKAGES.
# 'EBUILDS MODIFIED' refers to whether any of the existing 9999 ebuilds have
# modified contents relative to their corresponding stable ebuilds.
#
# CHROME_EBUILD            FOLLOWER_EBUILDS           EBUILDS_MODIFIED
#
# HIGHER                   HIGHER                     YES
# SAME                     SAME                       NO
# LOWER                    LOWER
#                          DOESN'T EXIST YET

# These test cases cover both CHROME & FOLLOWER ebuilds being identically
# higher, lower, or the same versions, with no modified ebuilds.
UPREV_VERSION_CASES = (
    pytest.param(
        '80.0.8080.0',
        '81.0.8181.0',
        # One added and one deleted for chrome and each "other" package.
        2 * (1 + len(constants.OTHER_CHROME_PACKAGES)),
        id='newer_chrome_version',
    ),
    # No files should be changed in these cases.
    pytest.param(
        '80.0.8080.0',
        '80.0.8080.0',
        0,
        id='same_chrome_version',
    ),
    pytest.param(
        '80.0.8080.0',
        '79.0.7979.0',
        0,
        id='older_chrome_version',
    ),
)


@pytest.mark.parametrize('old_version, new_version, expected_count',
                         UPREV_VERSION_CASES)
def test_uprev_chrome_all_files_already_exist(old_version, new_version,
                                              expected_count, monkeypatch,
                                              overlay_stack):
  """Test Chrome uprevs work as expected when all packages already exist."""
  overlay, = overlay_stack(1)
  monkeypatch.setattr(uprev_lib, '_CHROME_OVERLAY_PATH', overlay.path)

  unstable_chrome = cr.test.Package(
      'chromeos-base', 'chromeos-chrome', version='9999', keywords='~*')
  stable_chrome = cr.test.Package(
      'chromeos-base', 'chromeos-chrome', version=f'{old_version}_rc-r1')

  overlay.add_package(unstable_chrome)
  overlay.add_package(stable_chrome)

  for pkg_str in constants.OTHER_CHROME_PACKAGES:
    category, pkg_name = pkg_str.split('/')
    unstable_pkg = cr.test.Package(
        category, pkg_name, version='9999', keywords='~*')
    stable_pkg = cr.test.Package(
        category, pkg_name, version=f'{old_version}_rc-r1')

    overlay.add_package(unstable_pkg)
    overlay.add_package(stable_pkg)

  git_refs = [
      GitRef(
          path='/foo', ref=f'refs/tags/{new_version}', revision='dummycommit')
  ]
  res = packages.uprev_chrome(build_targets=None, refs=git_refs, chroot=None)

  modified_file_count = sum(len(m.files) for m in res.modified)
  assert modified_file_count == expected_count


@pytest.mark.usefixtures('testcase_monkeypatch')
class GetModelsTest(cros_test_lib.RunCommandTempDirTestCase):
  """Tests for get_models."""

  def setUp(self):
    self.board = 'test-board'
    self.rc.SetDefaultCmdResult(output='pyro\nreef\nsnappy\n')
    self.monkeypatch.setattr(constants, 'SOURCE_ROOT', self.tempdir)
    build_bin = os.path.join(self.tempdir, constants.DEFAULT_CHROOT_DIR,
                             'usr', 'bin')
    osutils.Touch(os.path.join(build_bin, 'cros_config_host'), makedirs=True)


  def testGetModels(self):
    """Test get_models."""
    build_target = build_target_lib.BuildTarget(self.board)
    result = packages.get_models(build_target)
    self.assertEqual(result, ['pyro', 'reef', 'snappy'])


class GetKeyIdTest(cros_test_lib.MockTestCase):
  """Tests for get_key_id."""

  def setUp(self):
    self.board = 'test-board'
    self.build_target = build_target_lib.BuildTarget(self.board)

  def testGetKeyId(self):
    """Test get_key_id when _run_cros_config_host returns a key."""
    self.PatchObject(packages, '_run_cros_config_host',
                     return_value=['key'])
    result = packages.get_key_id(self.build_target, 'model')
    self.assertEqual(result, 'key')

  def testGetKeyIdNoKey(self):
    """Test get_key_id when None should be returned."""
    self.PatchObject(packages, '_run_cros_config_host',
                     return_value=['key1', 'key2'])
    result = packages.get_key_id(self.build_target, 'model')
    self.assertEqual(result, None)
