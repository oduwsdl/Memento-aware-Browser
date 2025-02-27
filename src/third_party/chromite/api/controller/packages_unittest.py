# -*- coding: utf-8 -*-
# Copyright 2019 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""packages controller unit tests."""

from __future__ import print_function

import sys

import mock

from chromite.api.api_config import ApiConfigMixin
from chromite.api.controller import controller_util
from chromite.api.controller import packages as packages_controller
from chromite.api.gen.chromiumos import common_pb2
from chromite.api.gen.chromite.api import binhost_pb2
from chromite.api.gen.chromite.api import packages_pb2
from chromite.lib import constants
from chromite.lib import cros_build_lib
from chromite.lib import cros_test_lib
from chromite.lib import portage_util
from chromite.lib import build_target_lib
from chromite.service import packages as packages_service


assert sys.version_info >= (3, 6), 'This module requires Python 3.6+'


class UprevTest(cros_test_lib.MockTestCase, ApiConfigMixin):
  """Uprev tests."""

  _PUBLIC = binhost_pb2.OVERLAYTYPE_PUBLIC
  _PRIVATE = binhost_pb2.OVERLAYTYPE_PRIVATE
  _BOTH = binhost_pb2.OVERLAYTYPE_BOTH
  _NONE = binhost_pb2.OVERLAYTYPE_NONE

  def setUp(self):
    self.uprev_patch = self.PatchObject(packages_service, 'uprev_build_targets')
    self.response = packages_pb2.UprevPackagesResponse()

  def _GetRequest(self, targets=None, overlay_type=None, output_dir=None):
    return packages_pb2.UprevPackagesRequest(
        build_targets=[{'name': name} for name in targets or []],
        overlay_type=overlay_type,
        output_dir=output_dir,
    )

  def testValidateOnly(self):
    """Sanity check that a validate only call does not execute any logic."""
    patch = self.PatchObject(packages_service, 'uprev_build_targets')

    targets = ['foo', 'bar']
    request = self._GetRequest(targets=targets, overlay_type=self._BOTH)
    packages_controller.Uprev(request, self.response, self.validate_only_config)
    patch.assert_not_called()

  def testMockCall(self):
    """Test that a mock call does not execute logic, returns mocked value."""
    patch = self.PatchObject(packages_service, 'uprev_build_targets')
    targets = ['foo', 'bar']
    request = self._GetRequest(targets=targets, overlay_type=self._BOTH)
    packages_controller.Uprev(request, self.response, self.mock_call_config)
    patch.assert_not_called()
    self.assertTrue(self.response.modified_ebuilds)

  def testNoOverlayTypeFails(self):
    """No overlay type provided should fail."""
    request = self._GetRequest(targets=['foo'])

    with self.assertRaises(cros_build_lib.DieSystemExit):
      packages_controller.Uprev(request, self.response, self.api_config)

  def testOverlayTypeNoneFails(self):
    """Overlay type none means nothing here and should fail."""
    request = self._GetRequest(targets=['foo'], overlay_type=self._NONE)

    with self.assertRaises(cros_build_lib.DieSystemExit):
      packages_controller.Uprev(request, self.response, self.api_config)

  def testSuccess(self):
    """Test overall successful argument handling."""
    targets = ['foo', 'bar']
    output_dir = '/tmp/uprev_output_dir'
    changed = ['/ebuild-1.0-r1.ebuild', '/ebuild-1.0-r2.ebuild']
    expected_type = constants.BOTH_OVERLAYS
    request = self._GetRequest(targets=targets, overlay_type=self._BOTH,
                               output_dir=output_dir)
    uprev_patch = self.PatchObject(packages_service, 'uprev_build_targets',
                                   return_value=changed)

    packages_controller.Uprev(request, self.response, self.api_config)

    # Make sure the type is right, verify build targets after.
    uprev_patch.assert_called_once_with(mock.ANY, expected_type, mock.ANY,
                                        output_dir)
    # First argument (build targets) of the first (only) call.
    call_targets = uprev_patch.call_args[0][0]
    self.assertCountEqual(targets, [t.name for t in call_targets])

    for ebuild in self.response.modified_ebuilds:
      self.assertIn(ebuild.path, changed)
      changed.remove(ebuild.path)
    self.assertFalse(changed)


class UprevVersionedPackageTest(cros_test_lib.MockTestCase, ApiConfigMixin):
  """UprevVersionedPackage tests."""

  def setUp(self):
    self.response = packages_pb2.UprevVersionedPackageResponse()

  def _addVersion(self, request, version):
    """Helper method to add a full version message to the request."""
    ref = request.versions.add()
    ref.repository = '/some/path'
    ref.ref = 'refs/tags/%s' % version
    ref.revision = 'abc123'

  def testValidateOnly(self):
    """Sanity check validate only calls are working properly."""
    service = self.PatchObject(packages_service, 'uprev_versioned_package')

    request = packages_pb2.UprevVersionedPackageRequest()
    self._addVersion(request, '1.2.3.4')
    request.package_info.category = 'chromeos-base'
    request.package_info.package_name = 'chromeos-chrome'

    packages_controller.UprevVersionedPackage(request, self.response,
                                              self.validate_only_config)

    service.assert_not_called()

  def testMockCall(self):
    """Test that a mock call does not execute logic, returns mocked value."""
    patch = self.PatchObject(packages_service, 'uprev_versioned_package')
    request = packages_pb2.UprevVersionedPackageRequest()
    packages_controller.UprevVersionedPackage(request, self.response,
                                              self.mock_call_config)
    patch.assert_not_called()
    self.assertTrue(self.response.responses)
    self.assertTrue(self.response.responses[0].modified_ebuilds)

  def testNoVersions(self):
    """Test no versions provided."""
    request = packages_pb2.UprevVersionedPackageRequest()
    request.package_info.category = 'chromeos-base'
    request.package_info.package_name = 'chromeos-chrome'

    with self.assertRaises(cros_build_lib.DieSystemExit):
      packages_controller.UprevVersionedPackage(request, self.response,
                                                self.api_config)

  def testNoPackageName(self):
    """Test no package name provided."""
    request = packages_pb2.UprevVersionedPackageRequest()
    self._addVersion(request, '1.2.3.4')
    request.package_info.category = 'chromeos-base'

    with self.assertRaises(cros_build_lib.DieSystemExit):
      packages_controller.UprevVersionedPackage(request, self.response,
                                                self.api_config)

  def testNoCategory(self):
    """Test no package category provided."""
    request = packages_pb2.UprevVersionedPackageRequest()
    self._addVersion(request, '1.2.3.4')
    request.package_info.package_name = 'chromeos-chrome'

    with self.assertRaises(cros_build_lib.DieSystemExit):
      packages_controller.UprevVersionedPackage(request, self.response,
                                                self.api_config)

  def testOutputHandling(self):
    """Test the modified files are getting correctly added to the output."""
    version = '1.2.3.4'
    result = packages_service.UprevVersionedPackageResult().add_result(
        version, ['/file/one', '/file/two'])

    self.PatchObject(
        packages_service, 'uprev_versioned_package', return_value=result)

    request = packages_pb2.UprevVersionedPackageRequest()
    self._addVersion(request, version)
    request.package_info.category = 'chromeos-base'
    request.package_info.package_name = 'chromeos-chrome'

    packages_controller.UprevVersionedPackage(request, self.response,
                                              self.api_config)

    for idx, uprev_response in enumerate(self.response.responses):
      self.assertEqual(result.modified[idx].new_version, uprev_response.version)
      self.assertCountEqual(
          result.modified[idx].files,
          [ebuild.path for ebuild in uprev_response.modified_ebuilds])


class GetBestVisibleTest(cros_test_lib.MockTestCase, ApiConfigMixin):
  """GetBestVisible tests."""

  def setUp(self):
    self.response = packages_pb2.GetBestVisibleResponse()

  def _GetRequest(self, atom=None):
    return packages_pb2.GetBestVisibleRequest(
        atom=atom,
    )

  def _MakeCpv(self, category, package, version):
    unused = {
        'cp': None,
        'cpv': None,
        'cpf': None,
        'pv': None,
        'version_no_rev': None,
        'rev': None,
    }
    return portage_util.CPV(
        category=category,
        package=package,
        version=version,
        **unused
    )

  def testValidateOnly(self):
    """Sanity check that a validate only call does not execute any logic."""
    patch = self.PatchObject(packages_service, 'get_best_visible')

    request = self._GetRequest(atom='chromeos-chrome')
    packages_controller.GetBestVisible(request, self.response,
                                       self.validate_only_config)
    patch.assert_not_called()

  def testMockCall(self):
    """Test that a mock call does not execute logic, returns mocked value."""
    patch = self.PatchObject(packages_service, 'get_best_visible')
    request = self._GetRequest(atom='chromeos-chrome')
    packages_controller.GetBestVisible(request, self.response,
                                       self.mock_call_config)
    patch.assert_not_called()
    self.assertTrue(self.response.package_info)
    self.assertTrue(self.response.package_info.category)
    self.assertTrue(self.response.package_info.package_name)
    self.assertTrue(self.response.package_info.version)

  def testNoAtomFails(self):
    """No atom provided should fail."""
    request = self._GetRequest()
    with self.assertRaises(cros_build_lib.DieSystemExit):
      packages_controller.GetBestVisible(request, self.response,
                                         self.api_config)

  def testSuccess(self):
    """Test overall success, argument handling, result forwarding."""
    cpv = self._MakeCpv('category', 'package', 'version')
    self.PatchObject(packages_service, 'get_best_visible', return_value=cpv)

    request = self._GetRequest(atom='chromeos-chrome')

    packages_controller.GetBestVisible(request, self.response, self.api_config)

    package_info = self.response.package_info
    self.assertEqual(package_info.category, cpv.category)
    self.assertEqual(package_info.package_name, cpv.package)
    self.assertEqual(package_info.version, cpv.version)


class GetChromeVersion(cros_test_lib.MockTestCase, ApiConfigMixin):
  """GetChromeVersion tests."""

  def setUp(self):
    self.response = packages_pb2.GetChromeVersionResponse()

  def _GetRequest(self, board=None):
    """Helper to build out a request."""
    request = packages_pb2.GetChromeVersionRequest()

    if board:
      request.build_target.name = board

    return request

  def testValidateOnly(self):
    """Sanity check that a validate only call does not execute any logic."""
    chrome_version = self.PatchObject(packages_service,
                                      'determine_chrome_version')
    request = self._GetRequest(board='betty')
    packages_controller.GetChromeVersion(request, self.response,
                                         self.validate_only_config)
    chrome_version.assert_not_called()

  def testMockCall(self):
    """Test that a mock call does not execute logic, returns mocked value."""
    chrome_version = self.PatchObject(packages_service,
                                      'determine_chrome_version')
    request = self._GetRequest(board='betty')
    packages_controller.GetChromeVersion(request, self.response,
                                         self.mock_call_config)
    chrome_version.assert_not_called()
    self.assertTrue(self.response.version)

  def testGetChromeVersion(self):
    """Verify basic return values."""
    chrome_version = '76.0.1.2'
    chrome_version_mock = self.PatchObject(packages_service,
                                           'determine_chrome_version',
                                           return_value=chrome_version)
    request = self._GetRequest(board='betty')
    packages_controller.GetChromeVersion(request, self.response,
                                         self.api_config)
    self.assertEqual(self.response.version, chrome_version)
    # Verify call to determine_chrome_version passes a build_target object.
    build_target = build_target_lib.BuildTarget('betty')
    chrome_version_mock.assert_called_with(build_target)

  def testGetChromeVersionHandleNone(self):
    """Verify basic return values."""
    self.PatchObject(packages_service, 'determine_chrome_version',
                     return_value=None)
    request = self._GetRequest(board='betty')
    packages_controller.GetChromeVersion(request, self.response,
                                         self.api_config)
    self.assertFalse(self.response.version)


class GetTargetVersionsTest(cros_test_lib.MockTestCase, ApiConfigMixin):
  """GetTargetVersions tests."""

  def setUp(self):
    self.response = packages_pb2.GetTargetVersionsResponse()

  def _GetRequest(self, board=None):
    """Helper to build out a request."""
    request = packages_pb2.GetTargetVersionsRequest()

    if board:
      request.build_target.name = board

    return request

  def testValidateOnly(self):
    """Sanity check that a validate only call does not execute any logic."""
    builds_chrome = self.PatchObject(
        packages_service, 'builds', return_value=True)
    patch_version = self.PatchObject(packages_service,
                                     'determine_android_version')
    patch_branch_version = self.PatchObject(packages_service,
                                            'determine_android_branch')
    patch_target_version = self.PatchObject(packages_service,
                                            'determine_android_target')
    chrome_version = self.PatchObject(packages_service,
                                      'determine_chrome_version')
    platform_version = self.PatchObject(packages_service,
                                        'determine_platform_version')
    milestone_version = self.PatchObject(packages_service,
                                         'determine_milestone_version')
    full_version = self.PatchObject(packages_service,
                                    'determine_full_version')

    request = self._GetRequest(board='betty')
    packages_controller.GetTargetVersions(request, self.response,
                                          self.validate_only_config)
    patch_version.assert_not_called()
    patch_branch_version.assert_not_called()
    patch_target_version.assert_not_called()
    builds_chrome.assert_not_called()
    chrome_version.assert_not_called()
    platform_version.assert_not_called()
    milestone_version.assert_not_called()
    full_version.assert_not_called()

  def testMockCall(self):
    """Test that a mock call does not execute logic, returns mocked value."""
    builds_chrome = self.PatchObject(
        packages_service, 'builds', return_value=True)
    patch_version = self.PatchObject(packages_service,
                                     'determine_android_version')
    patch_branch_version = self.PatchObject(packages_service,
                                            'determine_android_branch')
    patch_target_version = self.PatchObject(packages_service,
                                            'determine_android_target')
    chrome_version = self.PatchObject(packages_service,
                                      'determine_chrome_version')
    platform_version = self.PatchObject(packages_service,
                                        'determine_platform_version')
    milestone_version = self.PatchObject(packages_service,
                                         'determine_milestone_version')
    full_version = self.PatchObject(packages_service,
                                    'determine_full_version')

    request = self._GetRequest(board='betty')
    packages_controller.GetTargetVersions(request, self.response,
                                          self.mock_call_config)

    patch_version.assert_not_called()
    patch_branch_version.assert_not_called()
    patch_target_version.assert_not_called()
    builds_chrome.assert_not_called()
    chrome_version.assert_not_called()
    platform_version.assert_not_called()
    milestone_version.assert_not_called()
    full_version.assert_not_called()

    self.assertTrue(self.response.android_version)
    self.assertTrue(self.response.android_branch_version)
    self.assertTrue(self.response.android_target_version)
    self.assertTrue(self.response.chrome_version)
    self.assertTrue(self.response.platform_version)
    self.assertTrue(self.response.milestone_version)
    self.assertTrue(self.response.full_version)

  def testNoBuildTargetFails(self):
    """No build target argument should fail."""
    request = self._GetRequest()

    with self.assertRaises(cros_build_lib.DieSystemExit):
      packages_controller.GetTargetVersions(request, self.response,
                                            self.api_config)

  def testGetTargetVersions(self):
    """Verify basic return values."""
    # Mock that chrome is built and set the chrome_version.
    self.PatchObject(packages_service, 'builds', return_value=True)
    chrome_version = '76.0.1.2'
    chrome_version_mock = self.PatchObject(packages_service,
                                           'determine_chrome_version',
                                           return_value=chrome_version)
    android_version = 'android_test_version'
    android_version_mock = self.PatchObject(packages_service,
                                            'determine_android_version',
                                            return_value=android_version)
    android_branch = 'android_test_branch'
    android_branch_mock = self.PatchObject(packages_service,
                                           'determine_android_branch',
                                           return_value=android_branch)
    android_target = 'android_test_target'
    android_target_mock = self.PatchObject(packages_service,
                                           'determine_android_target',
                                           return_value=android_target)
    platform_version = '12345.1.2'
    self.PatchObject(packages_service, 'determine_platform_version',
                     return_value=platform_version)
    milestone_version = '79'
    self.PatchObject(packages_service, 'determine_milestone_version',
                     return_value=milestone_version)
    full_version = 'R79-12345.1.2'
    self.PatchObject(packages_service, 'determine_full_version',
                     return_value=full_version)
    request = self._GetRequest(board='betty')
    packages_controller.GetTargetVersions(request, self.response,
                                          self.api_config)
    self.assertEqual(self.response.android_version, android_version)
    self.assertEqual(self.response.android_branch_version, android_branch)
    self.assertEqual(self.response.android_target_version, android_target)
    self.assertEqual(self.response.chrome_version, chrome_version)
    self.assertEqual(self.response.platform_version, platform_version)
    self.assertEqual(self.response.milestone_version, milestone_version)
    self.assertEqual(self.response.full_version, full_version)
    # Verify call to determine_chrome_version passes a build_target object.
    build_target = build_target_lib.BuildTarget('betty')
    chrome_version_mock.assert_called_with(build_target)
    # Verify call to determine_android_version passes a list of the board name.
    android_version_mock.assert_called_with(['betty'])
    # Verify call to determine_android_branch passes a board name.
    android_branch_mock.assert_called_with('betty')
    # Verify call to determine_android_target passes a board name.
    android_target_mock.assert_called_with('betty')

  def testGetTargetVersionNoAndroidNoChrome(self):
    """Verify return values on a board that does not have android."""
    platform_version = '12345.1.2'
    self.PatchObject(packages_service, 'determine_platform_version',
                     return_value=platform_version)
    self.PatchObject(packages_service, 'builds', return_value=False)
    self.PatchObject(packages_service, 'determine_android_version',
                     return_value=None)
    self.PatchObject(packages_service, 'determine_android_branch',
                     return_value=None)
    self.PatchObject(packages_service, 'determine_android_target',
                     return_value=None)
    request = self._GetRequest(board='betty')
    packages_controller.GetTargetVersions(request, self.response,
                                          self.api_config)
    self.assertFalse(self.response.chrome_version)
    self.assertFalse(self.response.android_version)
    self.assertFalse(self.response.android_branch_version)
    self.assertFalse(self.response.android_target_version)
    self.assertEqual(self.response.platform_version, platform_version)


class GetBuilderMetadataTest(cros_test_lib.MockTestCase, ApiConfigMixin):
  """GetBuilderMetadata tests."""

  def setUp(self):
    self.response = packages_pb2.GetBuilderMetadataResponse()

  def _GetRequest(self, board=None):
    """Helper to build out a request."""
    request = packages_pb2.GetBuilderMetadataRequest()

    if board:
      request.build_target.name = board

    return request

  def testValidateOnly(self):
    """Sanity check that a validate only call does not execute any logic."""
    request = self._GetRequest(board='betty')
    patch_version = self.PatchObject(packages_service,
                                     'determine_android_version')
    patch_branch_version = self.PatchObject(packages_service,
                                            'determine_android_branch')
    patch_fw_versions = self.PatchObject(packages_service,
                                         'determine_firmware_versions')
    patch_fingerprints = self.PatchObject(packages_service,
                                          'find_fingerprints')
    patch_get_models = self.PatchObject(packages_service,
                                        'get_models')
    packages_controller.GetBuilderMetadata(request, self.response,
                                           self.validate_only_config)
    patch_version.assert_not_called()
    patch_branch_version.assert_not_called()
    patch_fw_versions.assert_not_called()
    patch_fingerprints.assert_not_called()
    patch_get_models.assert_not_called()

  def testMockCall(self):
    """Test that a mock call does not execute logic, returns mocked value."""
    request = self._GetRequest(board='betty')
    patch_version = self.PatchObject(packages_service,
                                     'determine_android_version')
    patch_branch_version = self.PatchObject(packages_service,
                                            'determine_android_branch')
    patch_fw_versions = self.PatchObject(packages_service,
                                         'determine_firmware_versions')
    patch_fingerprints = self.PatchObject(packages_service,
                                          'find_fingerprints')
    patch_get_models = self.PatchObject(packages_service,
                                        'get_models')
    packages_controller.GetBuilderMetadata(request, self.response,
                                           self.mock_call_config)
    patch_version.assert_not_called()
    patch_branch_version.assert_not_called()
    patch_fw_versions.assert_not_called()
    patch_fingerprints.assert_not_called()
    patch_get_models.assert_not_called()

    self.assertEqual(len(self.response.build_target_metadata), 1)
    self.assertEqual(self.response.build_target_metadata[0].build_target,
                     request.build_target.name)
    self.assertEqual(len(self.response.model_metadata), 1)
    self.assertTrue(self.response.model_metadata[0].model_name)
    self.assertTrue(self.response.model_metadata[0].ec_firmware_version)

  def testNoBuildTargetFails(self):
    """No build target argument should fail."""
    request = self._GetRequest()

    with self.assertRaises(cros_build_lib.DieSystemExit):
      packages_controller.GetBuilderMetadata(request, self.response,
                                             self.api_config)

  def testGetBuilderMetadata(self):
    """Verify basic return values."""
    android_version = 'android_test_version'
    android_version_mock = self.PatchObject(packages_service,
                                            'determine_android_version',
                                            return_value=android_version)
    android_branch = 'android_test_branch'
    android_branch_mock = self.PatchObject(packages_service,
                                           'determine_android_branch',
                                           return_value=android_branch)
    android_target = 'android_test_target'
    android_target_mock = self.PatchObject(packages_service,
                                           'determine_android_target',
                                           return_value=android_target)
    self.PatchObject(portage_util, 'GetBoardUseFlags',
                     return_value=['arc', 'arcvm', 'big_little', 'cheets'])
    package_result = ['sys-kernel/linux-headers-4.14-r24',
                      'sys-devel/flex-2.6.4-r1',
                      'sys-kernel/chromeos-kernel-4_4-4.4.223-r2209']
    self.PatchObject(portage_util, 'GetPackageDependencies',
                     return_value=package_result)

    fw_versions = packages_service.FirmwareVersions(
        None,
        'Google_Caroline.7820.263.0',
        'Google_Caroline.7820.286.0',
        'caroline_v1.9.357-ac5c7b4',
        'caroline_v1.9.370-e8b9bd2')
    self.PatchObject(packages_service, 'get_firmware_versions',
                     return_value=fw_versions)
    fingerprints = ['fingerprint1', 'fingerprint2']
    self.PatchObject(packages_service, 'find_fingerprints',
                     return_value=fingerprints)
    # Patch packages.get_models, packages.get_all_firmware_versions,
    # and packages.get_key_id for calls needed by model_metadata.
    model_list = ['pyro', 'reef']
    all_fw_versions = {
        'pyro': packages_service.FirmwareVersions(
            'pyro',
            'Google_Pyro.9042.87.1',
            'Google_Pyro.9042.110.0',
            'pyro_v1.1.5900-ab1ee51',
            'pyro_v1.1.5909-bd1f0c9'),
        'reef': packages_service.FirmwareVersions(
            'reef',
            'Google_Reef.9042.87.1',
            'Google_Reef.9042.110.0',
            'reef_v1.1.5900-ab1ee51',
            'reef_v1.1.5909-bd1f0c9')
    }
    self.PatchObject(packages_service, 'get_all_firmware_versions',
                     return_value=all_fw_versions)
    self.PatchObject(packages_service, 'get_models',
                     return_value=model_list)
    self.PatchObject(packages_service, 'get_key_id',
                     return_value='key')

    request = self._GetRequest(board='betty')
    packages_controller.GetBuilderMetadata(request, self.response,
                                           self.api_config)
    self.assertEqual(
        self.response.build_target_metadata[0].build_target,
        'betty')
    self.assertEqual(
        self.response.build_target_metadata[0].android_container_version,
        android_version)
    self.assertEqual(
        self.response.build_target_metadata[0].android_container_branch,
        android_branch)
    self.assertEqual(
        self.response.build_target_metadata[0].android_container_target,
        android_target)
    self.assertEqual(
        self.response.build_target_metadata[0].arc_use_set,
        True)
    # Verify call to determine_android_version passes list of the board name.
    android_version_mock.assert_called_with(['betty'])
    # Verify call to determine_android_branch passes board name.
    android_branch_mock.assert_called_with('betty')
    # Verify call to determine_android_target passes board name.
    android_target_mock.assert_called_with('betty')
    self.assertEqual(
        self.response.build_target_metadata[0].main_firmware_version,
        'Google_Caroline.7820.286.0')
    self.assertEqual(
        self.response.build_target_metadata[0].ec_firmware_version,
        'caroline_v1.9.370-e8b9bd2')
    self.assertEqual(
        self.response.build_target_metadata[0].kernel_version,
        '4.4.223-r2209')
    self.assertEqual(
        len(self.response.build_target_metadata[0].fingerprints),
        2)
    self.assertEqual(
        self.response.build_target_metadata[0].fingerprints,
        fingerprints)
    self.assertEqual(
        len(self.response.model_metadata), 2)
    self.assertEqual(
        self.response.model_metadata[0].model_name, 'pyro')
    self.assertEqual(
        self.response.model_metadata[0].ec_firmware_version,
        'pyro_v1.1.5909-bd1f0c9')
    self.assertEqual(
        self.response.model_metadata[0].firmware_key_id, 'key')
    self.assertEqual(
        self.response.model_metadata[0].main_readonly_firmware_version,
        'Google_Pyro.9042.87.1')
    self.assertEqual(
        self.response.model_metadata[0].main_readwrite_firmware_version,
        'Google_Pyro.9042.110.0')
    self.assertEqual(
        self.response.model_metadata[1].model_name, 'reef')
    self.assertEqual(
        self.response.model_metadata[1].ec_firmware_version,
        'reef_v1.1.5909-bd1f0c9')
    self.assertEqual(
        self.response.model_metadata[1].firmware_key_id, 'key')
    self.assertEqual(
        self.response.model_metadata[1].main_readonly_firmware_version,
        'Google_Reef.9042.87.1')
    self.assertEqual(
        self.response.model_metadata[1].main_readwrite_firmware_version,
        'Google_Reef.9042.110.0')

    # Test corner case where find_fingerprints returns None.
    # Re-patch find_fingerprints to now return None and re-execute
    # GetBuilderMetadata to verify behavior.
    response = packages_pb2.GetBuilderMetadataResponse()
    self.PatchObject(packages_service, 'find_fingerprints',
                     return_value=[])
    request = self._GetRequest(board='betty')
    packages_controller.GetBuilderMetadata(request, response,
                                           self.api_config)
    # Verify a non-fingerprint build_target_metdata field was still set.
    self.assertEqual(
        response.build_target_metadata[0].kernel_version,
        '4.4.223-r2209')
    # And then verify that fingerprints was empty.
    self.assertEqual(response.build_target_metadata[0].fingerprints, [])


class HasChromePrebuiltTest(cros_test_lib.MockTestCase, ApiConfigMixin):
  """HasChromePrebuilt tests."""

  def setUp(self):
    self.response = packages_pb2.HasChromePrebuiltResponse()

  def _GetRequest(self, board=None):
    """Helper to build out a request."""
    request = packages_pb2.HasChromePrebuiltRequest()

    if board:
      request.build_target.name = board

    return request

  def testValidateOnly(self):
    """Sanity check that a validate only call does not execute any logic."""
    patch = self.PatchObject(packages_service, 'has_prebuilt')

    request = self._GetRequest(board='betty')
    packages_controller.HasChromePrebuilt(request, self.response,
                                          self.validate_only_config)
    patch.assert_not_called()

  def testMockCall(self):
    """Test that a mock call does not execute logic, returns mocked value."""
    patch = self.PatchObject(packages_service, 'has_prebuilt')

    request = self._GetRequest(board='betty')
    packages_controller.HasChromePrebuilt(request, self.response,
                                          self.mock_call_config)
    patch.assert_not_called()
    self.assertTrue(self.response.has_prebuilt)

  def testNoBuildTargetFails(self):
    """No build target argument should fail."""
    request = self._GetRequest()

    with self.assertRaises(cros_build_lib.DieSystemExit):
      packages_controller.HasChromePrebuilt(request, self.response,
                                            self.api_config)


class BuildsChromeTest(cros_test_lib.MockTestCase, ApiConfigMixin):
  """BuildsChrome tests."""

  def setUp(self):
    self.response = packages_pb2.BuildsChromeResponse()

  def _GetRequest(self, board=None, packages=None):
    """Helper to build out a request."""
    request = packages_pb2.BuildsChromeRequest()

    if board:
      request.build_target.name = board

    if packages:
      request.packages.extend(packages)

    return request

  def testValidateOnly(self):
    """Sanity check that a validate only call does not execute any logic."""
    patch = self.PatchObject(packages_service, 'builds')

    request = self._GetRequest(board='betty')
    packages_controller.BuildsChrome(request, self.response,
                                     self.validate_only_config)
    patch.assert_not_called()

  def testNoBuildTargetFails(self):
    """No build target argument should fail."""
    request = self._GetRequest()

    with self.assertRaises(cros_build_lib.DieSystemExit):
      packages_controller.BuildsChrome(request, self.response, self.api_config)

  def testBuilds(self):
    """Test successful call handling."""
    patch = self.PatchObject(packages_service, 'builds', return_value=True)

    request = self._GetRequest(board='foo')
    packages_controller.BuildsChrome(request, self.response, self.api_config)
    self.assertTrue(self.response.builds_chrome)
    patch.assert_called_once_with(constants.CHROME_CP,
                                  build_target_lib.BuildTarget('foo'), [])

  def testBuildsChromeWithPackages(self):
    """Test successful call with packages handling."""
    patch = self.PatchObject(packages_service, 'builds', return_value=True)

    package = common_pb2.PackageInfo(
        category='category',
        package_name='name',
        version='1.01',
    )
    request = self._GetRequest(board='foo', packages=[package])
    packages_controller.BuildsChrome(request, self.response, self.api_config)
    self.assertTrue(self.response.builds_chrome)
    patch.assert_called_once_with(constants.CHROME_CP,
                                  build_target_lib.BuildTarget('foo'),
                                  [controller_util.PackageInfoToCPV(package)])
