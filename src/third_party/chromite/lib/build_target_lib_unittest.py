# -*- coding: utf-8 -*-
# Copyright 2019 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""build_target_lib tests."""

from __future__ import print_function

import os

from chromite.lib.build_target_lib import BuildTarget
from chromite.lib.build_target_lib import InvalidNameError
from chromite.lib import cros_test_lib
from chromite.lib import osutils


class BuildTargetTest(cros_test_lib.TempDirTestCase):
  """BuildTarget tests."""

  def setUp(self):
    self.sysroot = os.path.join(self.tempdir, 'sysroot')
    self.sysroot_denormalized = os.path.join(self.tempdir, 'dne', '..',
                                             'sysroot')
    osutils.SafeMakedirs(self.sysroot)

  def testEqual(self):
    """Sanity check for __eq__ method."""
    bt1 = BuildTarget('board', profile='base')
    bt2 = BuildTarget('board', profile='base')
    bt3 = BuildTarget('different', profile='base')
    self.assertEqual(bt1, bt2)
    self.assertNotEqual(bt1, bt3)

  def testInvalidName(self):
    """Test invalid name check."""
    with self.assertRaises(InvalidNameError):
      BuildTarget('')

  def testNormalRoot(self):
    """Test normalized sysroot path."""
    target = BuildTarget('board', build_root=self.sysroot)
    self.assertEqual(self.sysroot, target.root)

  def testDenormalizedRoot(self):
    """Test a non-normal sysroot path."""
    target = BuildTarget('board', build_root=self.sysroot_denormalized)
    self.assertEqual(self.sysroot, target.root)

  def testDefaultRoot(self):
    """Test the default sysroot path."""
    target = BuildTarget('board')
    self.assertEqual('/build/board', target.root)

  def testFullPath(self):
    """Test full_path functionality."""
    build_target = BuildTarget('board')
    result = build_target.full_path('some/path')
    self.assertEqual(result, '/build/board/some/path')

  def testFullPathWithExtraArgs(self):
    """Test full_path functionality with extra args passed."""
    build_target = BuildTarget('board')
    path1 = 'some/path'
    result = build_target.full_path(path1, '/abc', 'def', '/g/h/i')
    self.assertEqual(result, '/build/board/some/path/abc/def/g/h/i')
