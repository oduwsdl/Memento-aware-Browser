# -*- coding: utf-8 -*-
# Copyright 2020 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
"""Library to generate a DLC (Downloadable Content) artifact."""

from __future__ import division
from __future__ import print_function

import hashlib
import json
import math
import os
import re
import shutil
import sys

from chromite.lib import cros_build_lib
from chromite.lib import cros_logging as logging
from chromite.lib import osutils
from chromite.lib import pformat

from chromite.licensing import licenses_lib
from chromite.scripts import cros_set_lsb_release

assert sys.version_info >= (3, 6), 'This module requires Python 3.6+'

DLC_META_DIR = 'opt/google/dlc/'
DLC_TMP_META_DIR = 'meta'
DLC_BUILD_DIR = 'build/rootfs/dlc/'
LICENSE = 'LICENSE'
LSB_RELEASE = 'etc/lsb-release'
DLC_IMAGE = 'dlc.img'
IMAGELOADER_JSON = 'imageloader.json'
EBUILD_PARAMETERS = 'ebuild_parameters.json'

# This file has major and minor version numbers that the update_engine client
# supports. These values are needed for generating a delta/full payload.
UPDATE_ENGINE_CONF = 'etc/update_engine.conf'

_EXTRA_RESOURCES = (UPDATE_ENGINE_CONF,)

DLC_ID_KEY = 'DLC_ID'
DLC_PACKAGE_KEY = 'DLC_PACKAGE'
DLC_NAME_KEY = 'DLC_NAME'
DLC_APPID_KEY = 'DLC_RELEASE_APPID'

SQUASHFS_TYPE = 'squashfs'
EXT4_TYPE = 'ext4'

USED_BY_USER = 'user'
USED_BY_SYSTEM = 'system'

_MAX_ID_NAME = 40


def HashFile(file_path):
  """Calculate the sha256 hash of a file.

  Args:
    file_path: (str) path to the file.

  Returns:
    [str]: The sha256 hash of the file.
  """
  sha256 = hashlib.sha256()
  with open(file_path, 'rb') as f:
    for b in iter(lambda: f.read(2048), b''):
      sha256.update(b)
  return sha256.hexdigest()


def GetValueInJsonFile(json_path, key, default_value=None):
  """Reads file containing JSON and returns value or default_value for key.

  Args:
    json_path: (str) File containing JSON.
    key: (str) The desired key to lookup.
    default_value: (default:None) The default value returned in case of missing
      key.
  """
  with open(json_path) as fd:
    return json.load(fd).get(key, default_value)


class EbuildParams(object):
  """Object to store and retrieve DLC ebuild parameters.

  Attributes:
    dlc_id: (str) DLC ID.
    dlc_package: (str) DLC package.
    fs_type: (str) file system type.
    pre_allocated_blocks: (int) number of blocks pre-allocated on device.
    version: (str) DLC version.
    name: (str) DLC name.
    description: (str) DLC description.
    preload: (bool) allow for preloading DLC.
    used_by: (str) The user of this DLC, e.g. "system" or "user"
    fullnamerev: (str) The full package & version name.
  """

  def __init__(self, dlc_id, dlc_package, fs_type, pre_allocated_blocks,
               version, name, description, preload, used_by, fullnamerev):
    self.dlc_id = dlc_id
    self.dlc_package = dlc_package
    self.fs_type = fs_type
    self.pre_allocated_blocks = pre_allocated_blocks
    self.version = version
    self.name = name
    self.description = description
    self.preload = preload
    self.used_by = used_by
    self.fullnamerev = fullnamerev

  def StoreDlcParameters(self, install_root_dir, sudo):
    """Store DLC parameters defined in the ebuild.

    Store DLC parameters defined in the ebuild in a temporary file so they can
    be retrieved in the build_image phase.

    Args:
      install_root_dir: (str) The path to the root installation directory.
      sudo: (bool) Use sudo to write the file.
    """
    ebuild_params_path = EbuildParams.GetParamsPath(install_root_dir,
                                                    self.dlc_id,
                                                    self.dlc_package)
    osutils.WriteFile(ebuild_params_path,
                      json.dumps(self.__dict__),
                      makedirs=True, sudo=sudo)

  @staticmethod
  def GetParamsPath(install_root_dir, dlc_id, dlc_package):
    """Get the path to the file storing the ebuild parameters.

    Args:
      install_root_dir: (str) The path to the root installation directory.
      dlc_id: (str) DLC ID.
      dlc_package: (str) DLC package.

    Returns:
      [str]: Path to |EBUILD_PARAMETERS|.
    """
    return os.path.join(install_root_dir, DLC_BUILD_DIR, dlc_id, dlc_package,
                        EBUILD_PARAMETERS)

  @classmethod
  def LoadEbuildParams(cls, sysroot, dlc_id, dlc_package):
    """Read the stored ebuild parameters file and return a class instance.

    Args:
      dlc_id: (str) DLC ID.
      dlc_package: (str) DLC package.
      sysroot: (str) The path to the build root directory.

    Returns:
      [bool] : True if |ebuild_params_path| exists, False otherwise.
    """
    path = cls.GetParamsPath(sysroot, dlc_id, dlc_package)
    if not os.path.exists(path):
      return None

    with open(path, 'rb') as fp:
      return cls(**json.load(fp))

  def __str__(self):
    return str(self.__dict__)


class DlcGenerator(object):
  """Object to generate DLC artifacts."""
  # Block size for the DLC image.
  # We use 4K for various reasons:
  # 1. it's what imageloader (linux kernel) supports.
  # 2. it's what verity supports.
  _BLOCK_SIZE = 4096
  # Blocks in the initial sparse image.
  _BLOCKS = 500000
  # Version of manifest file.
  _MANIFEST_VERSION = 1

  # The DLC root path inside the DLC module.
  _DLC_ROOT_DIR = 'root'

  def __init__(self, ebuild_params, sysroot, install_root_dir, board,
               src_dir=None):
    """Object initializer.

    Args:
      sysroot: (str) The path to the build root directory.
      install_root_dir: (str) The path to the root installation directory.
      ebuild_params: (EbuildParams) Ebuild variables.
      board: (str) The target board we are building for.
      src_dir: (str) Optional path to the DLC source root directory. When None,
               the default directory in |DLC_BUILD_DIR| is used.
    """
    # Use a temporary directory to avoid having to use sudo every time we write
    # into the build directory.
    self.temp_root = osutils.TempDir(prefix='dlc', sudo_rm=True)
    self.src_dir = src_dir
    self.sysroot = sysroot
    self.install_root_dir = install_root_dir
    self.board = board
    self.ebuild_params = ebuild_params
    # If the client is not overriding the src_dir, use the default one.
    if not self.src_dir:
      self.src_dir = os.path.join(self.sysroot, DLC_BUILD_DIR,
                                  self.ebuild_params.dlc_id,
                                  self.ebuild_params.dlc_package,
                                  self._DLC_ROOT_DIR)

    self.image_dir = os.path.join(self.temp_root.tempdir,
                                  DLC_BUILD_DIR,
                                  self.ebuild_params.dlc_id,
                                  self.ebuild_params.dlc_package)

    self.meta_dir = os.path.join(self.image_dir, DLC_TMP_META_DIR)

    # Create path for all final artifacts.
    self.dest_image = os.path.join(self.image_dir, DLC_IMAGE)
    self.dest_table = os.path.join(self.meta_dir, 'table')
    self.dest_imageloader_json = os.path.join(self.meta_dir, IMAGELOADER_JSON)

    # Log out the member variable values initially set.
    logging.debug('Initial internal values of DlcGenerator: %s',
                  repr({k:str(i) for k, i in self.__dict__.items()}))

  def CopyTempContentsToBuildDir(self):
    """Copy the temp files to the build directory using sudo."""
    src = self.temp_root.tempdir.rstrip('/') + '/.'
    dst = self.install_root_dir
    logging.info(
        'Copy files from temporary directory (%s) to build directory (%s).',
        src, dst)
    cros_build_lib.sudo_run(['cp', '-dR', src, dst])

  def SquashOwnerships(self, path):
    """Squash the owernships & permissions for files.

    Args:
      path: (str) path that contains all files to be processed.
    """
    cros_build_lib.sudo_run(['chown', '-R', '0:0', path])
    cros_build_lib.sudo_run([
        'find', path, '-exec', 'touch', '-h', '-t', '197001010000.00', '{}', '+'
    ])

  def CreateExt4Image(self):
    """Create an ext4 image."""
    with osutils.TempDir(prefix='dlc_') as temp_dir:
      mount_point = os.path.join(temp_dir, 'mount_point')
      # Create the directory where the image is located if it doesn't exist.
      osutils.SafeMakedirs(os.path.split(self.dest_image)[0])
      # Create a raw image file.
      with open(self.dest_image, 'w') as f:
        f.truncate(self._BLOCKS * self._BLOCK_SIZE)
      # Create an ext4 file system on the raw image.
      cros_build_lib.run([
          '/sbin/mkfs.ext4', '-b',
          str(self._BLOCK_SIZE), '-O', '^has_journal', self.dest_image
      ],
                         capture_output=True)
      # Create the mount_point directory.
      osutils.SafeMakedirs(mount_point)
      # Mount the ext4 image.
      osutils.MountDir(self.dest_image, mount_point, mount_opts=('loop', 'rw'))

      try:
        self.SetupDlcImageFiles(mount_point)
      finally:
        # Unmount the ext4 image.
        osutils.UmountDir(mount_point)
      # Shrink to minimum size.
      cros_build_lib.run(['/sbin/e2fsck', '-y', '-f', self.dest_image],
                         capture_output=True)
      cros_build_lib.run(['/sbin/resize2fs', '-M', self.dest_image],
                         capture_output=True)

  def CreateSquashfsImage(self):
    """Create a squashfs image."""
    with osutils.TempDir(prefix='dlc_') as temp_dir:
      squashfs_root = os.path.join(temp_dir, 'squashfs-root')
      self.SetupDlcImageFiles(squashfs_root)

      cros_build_lib.run([
          'mksquashfs', squashfs_root, self.dest_image, '-4k-align', '-noappend'
      ],
                         capture_output=True)

      # We changed the ownership and permissions of the squashfs_root
      # directory. Now we need to remove it manually.
      osutils.RmDir(squashfs_root, sudo=True)

  def SetupDlcImageFiles(self, dlc_dir):
    """Prepares the directory dlc_dir with all the files a DLC needs.

    Args:
      dlc_dir: (str) The path to where to setup files inside the DLC.
    """
    dlc_root_dir = os.path.join(dlc_dir, self._DLC_ROOT_DIR)
    osutils.SafeMakedirs(dlc_root_dir)
    osutils.CopyDirContents(self.src_dir, dlc_root_dir, symlinks=True)
    self.PrepareLsbRelease(dlc_dir)
    self.AddLicensingFile(dlc_dir)
    self.CollectExtraResources(dlc_dir)
    self.SquashOwnerships(dlc_dir)

  def PrepareLsbRelease(self, dlc_dir):
    """Prepare the file /etc/lsb-release in the DLC module.

    This file is used dropping some identification parameters for the DLC.

    Args:
      dlc_dir: (str) The path to the mounted point during image creation.
    """
    # Reading the platform APPID and creating the DLC APPID.
    platform_lsb_release = osutils.ReadFile(
        os.path.join(self.sysroot, LSB_RELEASE))
    app_id = None
    for line in platform_lsb_release.split('\n'):
      if line.startswith(cros_set_lsb_release.LSB_KEY_APPID_RELEASE):
        app_id = line.split('=')[1]
    if app_id is None:
      raise Exception(
          '%s does not have a valid key %s' %
          (platform_lsb_release, cros_set_lsb_release.LSB_KEY_APPID_RELEASE))

    fields = (
        (DLC_ID_KEY, self.ebuild_params.dlc_id),
        (DLC_PACKAGE_KEY, self.ebuild_params.dlc_package),
        (DLC_NAME_KEY, self.ebuild_params.name),
        # The DLC appid is generated by concatenating the platform appid with
        # the DLC ID using an underscore. This pattern should never be changed
        # once set otherwise it can break a lot of things!
        (DLC_APPID_KEY, '%s_%s' % (app_id, self.ebuild_params.dlc_id)),
    )

    lsb_release = os.path.join(dlc_dir, LSB_RELEASE)
    osutils.SafeMakedirs(os.path.dirname(lsb_release))
    content = ''.join('%s=%s\n' % (k, v) for k, v in fields)
    osutils.WriteFile(lsb_release, content)

  def AddLicensingFile(self, dlc_dir):
    """Add the licensing file for this DLC.

    Args:
      dlc_dir: (str) The path to the mounted point during image creation.
    """
    if not self.ebuild_params.fullnamerev:
      return

    licensing = licenses_lib.Licensing(self.board,
                                       [self.ebuild_params.fullnamerev], True)
    licensing.LoadPackageInfo()
    licensing.ProcessPackageLicenses()
    license_path = os.path.join(dlc_dir, LICENSE)
    # The first (and only) item contains the values for |self.fullnamerev|.
    _, license_txt = next(iter(licensing.GenerateLicenseText().items()))
    osutils.WriteFile(license_path, license_txt)

  def CollectExtraResources(self, dlc_dir):
    """Collect the extra resources needed by the DLC module.

    Look at the documentation around _EXTRA_RESOURCES.

    Args:
      dlc_dir: (str) The path to the mounted point during image creation.
    """
    for r in _EXTRA_RESOURCES:
      source_path = os.path.join(self.sysroot, r)
      target_path = os.path.join(dlc_dir, r)
      osutils.SafeMakedirs(os.path.dirname(target_path))
      shutil.copyfile(source_path, target_path)

  def CreateImage(self):
    """Create the image and copy the DLC files to it."""
    logging.info('Creating the DLC image.')
    if self.ebuild_params.fs_type == EXT4_TYPE:
      self.CreateExt4Image()
    elif self.ebuild_params.fs_type == SQUASHFS_TYPE:
      self.CreateSquashfsImage()
    else:
      raise ValueError('Wrong fs type: %s used:' % self.ebuild_params.fs_type)

  def VerifyImageSize(self):
    """Verify the image can fit to the reserved file."""
    logging.info('Verifying the DLC image size.')
    image_bytes = os.path.getsize(self.dest_image)
    preallocated_bytes = (self.ebuild_params.pre_allocated_blocks *
                          self._BLOCK_SIZE)
    # Verifies the actual size of the DLC image is NOT smaller than the
    # preallocated space.
    if preallocated_bytes < image_bytes:
      raise ValueError(
          'The DLC_PREALLOC_BLOCKS (%s) value set in DLC ebuild resulted in a '
          'max size of DLC_PREALLOC_BLOCKS * 4K (%s) bytes the DLC image is '
          'allowed to occupy. The value is smaller than the actual image size '
          '(%s) required. Increase DLC_PREALLOC_BLOCKS in your ebuild to at '
          'least %d.' %
          (self.ebuild_params.pre_allocated_blocks, preallocated_bytes,
           image_bytes, self.GetOptimalImageBlockSize(image_bytes)))

  def GetOptimalImageBlockSize(self, image_bytes):
    """Given the image bytes, get the least amount of blocks required."""
    return int(math.ceil(image_bytes / self._BLOCK_SIZE))

  def GetImageloaderJsonContent(self, image_hash, table_hash, blocks):
    """Return the content of imageloader.json file.

    Args:
      image_hash: (str) sha256 hash of the DLC image.
      table_hash: (str) sha256 hash of the DLC table file.
      blocks: (int) number of blocks in the DLC image.

    Returns:
      [str]: content of imageloader.json file.
    """
    return {
        'fs-type': self.ebuild_params.fs_type,
        'id': self.ebuild_params.dlc_id,
        'package': self.ebuild_params.dlc_package,
        'image-sha256-hash': image_hash,
        'image-type': 'dlc',
        'is-removable': True,
        'manifest-version': self._MANIFEST_VERSION,
        'name': self.ebuild_params.name,
        'description': self.ebuild_params.description,
        'pre-allocated-size':
            str(self.ebuild_params.pre_allocated_blocks * self._BLOCK_SIZE),
        'size': str(blocks * self._BLOCK_SIZE),
        'table-sha256-hash': table_hash,
        'version': self.ebuild_params.version,
        'preload-allowed': self.ebuild_params.preload,
        'used-by': self.ebuild_params.used_by,
    }

  def GenerateVerity(self):
    """Generate verity parameters and hashes for the image."""
    logging.info('Generating DLC image verity.')
    with osutils.TempDir(prefix='dlc_') as temp_dir:
      hash_tree = os.path.join(temp_dir, 'hash_tree')
      # Get blocks in the image.
      blocks = math.ceil(os.path.getsize(self.dest_image) / self._BLOCK_SIZE)
      result = cros_build_lib.run([
          'verity', 'mode=create', 'alg=sha256', 'payload=' + self.dest_image,
          'payload_blocks=' + str(blocks), 'hashtree=' + hash_tree,
          'salt=random'
      ],
                                  capture_output=True)
      table = result.output

      # Append the merkle tree to the image.
      osutils.WriteFile(
          self.dest_image, osutils.ReadFile(hash_tree, mode='rb'), mode='a+b')

      # Write verity parameter to table file.
      osutils.WriteFile(self.dest_table, table, mode='wb')

      # Compute image hash.
      image_hash = HashFile(self.dest_image)
      table_hash = HashFile(self.dest_table)
      # Write image hash to imageloader.json file.
      blocks = math.ceil(os.path.getsize(self.dest_image) / self._BLOCK_SIZE)
      imageloader_json_content = self.GetImageloaderJsonContent(
          image_hash, table_hash, int(blocks))
      pformat.json(imageloader_json_content, fp=self.dest_imageloader_json)

  def GenerateDLC(self):
    """Generate a DLC artifact."""
    # Create directories.
    osutils.SafeMakedirs(self.image_dir)
    osutils.SafeMakedirs(self.meta_dir)

    # Create the image into |self.temp_root| and copy the DLC files to it.
    self.CreateImage()
    # Verify the image created is within pre-allocated size.
    self.VerifyImageSize()
    # Generate hash tree and other metadata and save them under
    # |self.temp_root|.
    self.GenerateVerity()
    # Copy the files from |self.temp_root| into the build directory.
    self.CopyTempContentsToBuildDir()

    # Now that the image was successfully generated, delete |ebuild_params_path|
    # to indicate that the image in the build directory is in sync with the
    # files installed during the build_package phase.
    ebuild_params_path = EbuildParams.GetParamsPath(
        self.sysroot, self.ebuild_params.dlc_id, self.ebuild_params.dlc_package)
    osutils.SafeUnlink(ebuild_params_path, sudo=True)


def IsDlcPreloadingAllowed(dlc_id, dlc_build_dir):
  """Validates that DLC and it's packages all were built with DLC_PRELOAD=true.

  Args:
    dlc_id: (str) DLC ID.
    dlc_build_dir: (str) the root path where DLC build files reside.
  """

  dlc_id_meta_dir = os.path.join(dlc_build_dir, dlc_id)
  if not os.path.exists(dlc_id_meta_dir):
    logging.error('DLC build directory (%s) does not exist for preloading '
                  'check, will not preload', dlc_id_meta_dir)
    return False

  packages = os.listdir(dlc_id_meta_dir)
  if not packages:
    logging.error('DLC ID build directory (%s) does not have any '
                  'packages, will not preload.', dlc_id_meta_dir)
    return False

  for package in packages:
    image_loader_json = os.path.join(dlc_id_meta_dir, package, DLC_TMP_META_DIR,
                                     IMAGELOADER_JSON)
    if not os.path.exists(image_loader_json):
      logging.error('DLC metadata file (%s) does not exist, will not preload.',
                    image_loader_json)
      return False
    if not GetValueInJsonFile(json_path=image_loader_json,
                              key='preload-allowed', default_value=False):
      return False
  # All packages support preload.
  return True


def InstallDlcImages(sysroot, board, dlc_id=None, install_root_dir=None,
                     preload=False, rootfs=None, src_dir=None):
  """Copies all DLC image files into the images directory.

  Copies the DLC image files in the given build directory into the given DLC
  image directory. If the DLC build directory does not exist, or there is no DLC
  for that board, this function does nothing.

  Args:
    sysroot: Path to directory containing DLC images, e.g /build/<board>.
    board: The target board we are building for.
    dlc_id: (str) DLC ID. If None, all the DLCs will be installed.
    install_root_dir: Path to DLC output directory, e.g.
      src/build/images/<board>/<version>. If None, the image will be generated
      but will not be copied to a destination.
    preload: When true, only copies DLC(s) if built with DLC_PRELOAD=true.
    rootfs: (str) Path to the platform rootfs.
    src_dir: (str) Path to the DLC source root directory.
  """
  dlc_build_dir = os.path.join(sysroot, DLC_BUILD_DIR)
  if not os.path.exists(dlc_build_dir):
    logging.info('DLC build directory (%s) does not exist, ignoring.',
                 dlc_build_dir)
    return

  if dlc_id is not None:
    if not os.path.exists(os.path.join(dlc_build_dir, dlc_id)):
      raise Exception(
          'DLC "%s" does not exist in the build directory %s.' %
          (dlc_id, dlc_build_dir))
    dlc_ids = [dlc_id]
  else:
    # Process all DLCs.
    dlc_ids = os.listdir(dlc_build_dir)
    if not dlc_ids:
      logging.info('There are no DLC(s) to copy to output, ignoring.')
      return

    logging.info('Detected the following DLCs: %s', ', '.join(dlc_ids))

  for d_id in dlc_ids:
    dlc_id_path = os.path.join(dlc_build_dir, d_id)
    dlc_packages = [direct for direct in os.listdir(dlc_id_path)
                    if os.path.isdir(os.path.join(dlc_id_path, direct))]
    for d_package in dlc_packages:
      logging.info('Building image: DLC %s', d_id)
      params = EbuildParams.LoadEbuildParams(sysroot=sysroot, dlc_id=d_id,
                                             dlc_package=d_package)
      # Because portage sandboxes every ebuild package during build_packages
      # phase, we cannot delete the old image during that phase, but we can use
      # the existence of the file |EBUILD_PARAMETERS| to know if the image
      # has to be generated or not.
      if not params:
        logging.info('The ebuild parameters file (%s) for DLC (%s) does not '
                     'exist. This means that the image was already '
                     'generated and there is no need to create it again.',
                     EbuildParams.GetParamsPath(sysroot, d_id, d_package), d_id)
      else:
        dlc_generator = DlcGenerator(
            src_dir=src_dir,
            sysroot=sysroot,
            install_root_dir=sysroot,
            board=board,
            ebuild_params=params)
        dlc_generator.GenerateDLC()

      # Copy the dlc images to install_root_dir.
      if install_root_dir:
        if preload and not IsDlcPreloadingAllowed(d_id, dlc_build_dir):
          logging.info('Skipping installation of DLC %s because the preload '
                       'flag is set and the DLC does not support preloading.',
                       d_id)
        else:
          osutils.SafeMakedirsNonRoot(install_root_dir)
          install_dlc_dir = os.path.join(install_root_dir, d_id, d_package)
          osutils.SafeMakedirsNonRoot(install_dlc_dir)
          source_dlc_dir = os.path.join(dlc_build_dir, d_id, d_package)
          for filepath in (os.path.join(source_dlc_dir, fname) for fname in
                           os.listdir(source_dlc_dir) if
                           fname.endswith('.img')):
            logging.info('Copying DLC(%s) image from %s to %s: ', d_id,
                         filepath, install_dlc_dir)
            shutil.copy(filepath, install_dlc_dir)
            logging.info('Done copying DLC to %s.', install_dlc_dir)
      else:
        logging.info('install_root_dir value was not provided. Copying dlc'
                     ' image skipped.')

      # Create metadata directory in rootfs.
      if rootfs:
        meta_rootfs = os.path.join(rootfs, DLC_META_DIR, d_id, d_package)
        osutils.SafeMakedirs(meta_rootfs, sudo=True)
        # Copy the metadata files to rootfs.
        meta_dir_src = os.path.join(dlc_build_dir, d_id, d_package,
                                    DLC_TMP_META_DIR)
        logging.info('Copying DLC(%s) metadata from %s to %s: ', d_id,
                     meta_dir_src, meta_rootfs)
        # Use sudo_run since osutils.CopyDirContents doesn't support sudo.
        cros_build_lib.sudo_run(['cp', '-dR',
                                 meta_dir_src.rstrip('/') + '/.',
                                 meta_rootfs], print_cmd=False, stderr=True)

      else:
        logging.info('rootfs value was not provided. Copying metadata skipped.')

  logging.info('Done installing DLCs.')


def ValidateDlcIdentifier(name):
  """Validates the DLC identifiers like ID and package names.

  The name specifications are:
    - No underscore.
    - First character should be only alphanumeric.
    - Other characters can be alphanumeric and '-' (dash).
    - Maximum length of 40 (_MAX_ID_NAME) characters.

  For more info see:
  https://chromium.googlesource.com/chromiumos/platform2/+/master/dlcservice/docs/developer.md#create-a-dlc-module

  Args:
    name: The value of the string to be validated.
  """
  errors = []
  if not name:
    errors.append('Must not be empty.')
  if not name[0].isalnum():
    errors.append('Must start with alphanumeric character.')
  if not re.match(r'^[a-zA-Z0-9][a-zA-Z0-9-]*$', name):
    errors.append('Must only use alphanumeric and - (dash).')
  if len(name) > _MAX_ID_NAME:
    errors.append('Must be within %d characters.' % _MAX_ID_NAME)

  if errors:
    msg = '%s is invalid:\n%s' % (name, '\n'.join(errors))
    raise Exception(msg)
