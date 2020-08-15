# -*- coding: utf-8 -*-
# Copyright 2018 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""This module tests the `cros branch` command."""

from __future__ import print_function

import os
import sys

import mock

from chromite.cbuildbot.manifest_version import VersionInfo
from chromite.cli import command_unittest
from chromite.cli.cros.cros_branch import Branch
from chromite.cli.cros.cros_branch import BranchCommand
from chromite.cli.cros.cros_branch import BranchError
from chromite.cli.cros.cros_branch import CanBranchProject
from chromite.cli.cros.cros_branch import CanPinProject
from chromite.cli.cros.cros_branch import CrosCheckout
from chromite.cli.cros.cros_branch import FactoryBranch
from chromite.cli.cros.cros_branch import FirmwareBranch
from chromite.cli.cros.cros_branch import ManifestRepository
from chromite.cli.cros.cros_branch import ProjectBranch
from chromite.cli.cros.cros_branch import ReleaseBranch
from chromite.cli.cros.cros_branch import StabilizeBranch
from chromite.lib import config_lib
from chromite.lib import constants
from chromite.lib import cros_build_lib
from chromite.lib import cros_test_lib
from chromite.lib import git
from chromite.lib import osutils
from chromite.lib import partial_mock
from chromite.lib import repo_manifest
from chromite.lib import repo_util


assert sys.version_info >= (3, 6), 'This module requires Python 3.6+'


def FileUrl(*args):
  """Map path components to a qualified local URL."""
  return 'file://%s' % os.path.join(*args)


def ManifestXml(*args):
  """Joins arbitrary XML and wraps it in a <manifest> element."""
  xml = '\n'.join(args)
  return '<?xml version="1.0" encoding="UTF-8"?><manifest>%s</manifest>' % xml


def AsAttrDict(*args):
  """Create AttrDict from string values, indexed by CAPS_CASE value."""
  return config_lib.AttrDict({v.upper().replace('-', '_'): v for v in args})


# A "project" in this dictionary is actually a project ID, which
# is used by helper functions to generate project name/path/revision/etc.
# If you add a project to this list, remember to update the categories below
# as well as PROJECTS_EXTERNAL_XML and its internal equivalent.
PROJECTS = AsAttrDict('manifest', 'manifest-internal', 'chromiumos-overlay',
                      'multicheckout-a', 'multicheckout-b', 'implicit-pinned',
                      'explicit-tot', 'explicit-branch', 'explicit-pinned',
                      'non-default-group')

# Categorize the projects above for use in testing.
PINNED_PROJECTS = (PROJECTS.EXPLICIT_PINNED, PROJECTS.IMPLICIT_PINNED)
TOT_PROJECTS = (PROJECTS.EXPLICIT_TOT,)
MULTI_CHECKOUT_PROJECTS = (PROJECTS.MULTICHECKOUT_A, PROJECTS.MULTICHECKOUT_B)
SINGLE_CHECKOUT_PROJECTS = (PROJECTS.CHROMIUMOS_OVERLAY,
                            PROJECTS.EXPLICIT_BRANCH, PROJECTS.MANIFEST,
                            PROJECTS.MANIFEST_INTERNAL,
                            PROJECTS.NON_DEFAULT_GROUP)
BRANCHED_PROJECTS = SINGLE_CHECKOUT_PROJECTS + MULTI_CHECKOUT_PROJECTS
NON_BRANCHED_PROJECTS = PINNED_PROJECTS + TOT_PROJECTS
MANIFEST_PROJECTS = (PROJECTS.MANIFEST, PROJECTS.MANIFEST_INTERNAL)
EXTERNAL_PROJECTS = (PROJECTS.MANIFEST, PROJECTS.CHROMIUMOS_OVERLAY,
                     PROJECTS.IMPLICIT_PINNED, PROJECTS.MULTICHECKOUT_A,
                     PROJECTS.MULTICHECKOUT_B)
INTERNAL_PROJECTS = (PROJECTS.MANIFEST_INTERNAL, PROJECTS.EXPLICIT_TOT,
                     PROJECTS.EXPLICIT_BRANCH, PROJECTS.EXPLICIT_PINNED)

# Define remotes. There is a public and an internal remote.
REMOTES = AsAttrDict('cros', 'cros-internal')

# Store commonly used values for convenience.
EXTERNAL_FILE_NAME = 'external.xml'
INTERNAL_FILE_NAME = 'internal.xml'
REMOTES_FILE_NAME = '_remotes.xml'

# Create the raw XML based on the above data. Note that by convention,
# the leaf directory of the project path MUST end with the project ID.
DEFAULT_XML = """
  <default revision="refs/heads/master" remote="cros"/>
"""

REMOTE_EXTERNAL_XML = """
  <remote name="cros" fetch="ext-fetch" revision="refs/heads/master"/>
"""

REMOTE_INTERNAL_XML = """
  <remote name="cros-internal" fetch="int-fetch" revision="refs/heads/master"/>
"""

PROJECTS_EXTERNAL_XML = """
  <project name="chromiumos/manifest" path="manifest"/>

  <project name="chromiumos/overlays/chromiumos-overlay"
           path="src/third_party/chromiumos-overlay"/>

  <project name="external/implicit-pinned"
           path="src/third_party/implicit-pinned"
           revision="refs/heads/implicit-pinned"/>

  <project name="chromiumos/multicheckout"
           path="src/third_party/multicheckout-a"
           revision="refs/heads/multicheckout-a"/>

  <project name="chromiumos/multicheckout"
           path="src/third_party/multicheckout-b"
           revision="refs/heads/multicheckout-b"/>

  <project name="chromiumos/non-default-group"
           path="src/third_party/non-default-group"
           revision="refs/heads/master"
           groups="notdefault,special-group"/>
"""

PROJECTS_INTERNAL_XML = """
  <project name="chromeos/manifest-internal"
           path="manifest-internal"
           remote="cros-internal"/>

  <project name="chromeos/explicit-pinned"
           path="src/explicit-pinned"
           revision="refs/heads/explicit-pinned"
           remote="cros-internal">
    <annotation name="branch-mode" value="pin"/>
  </project>

  <project name="chromeos/explicit-branch"
           path="src/explicit-branch"
           remote="cros-internal">
    <annotation name="branch-mode" value="create"/>
  </project>

  <project name="chromeos/explicit-tot"
           path="src/explicit-tot"
           remote="cros-internal">
    <annotation name="branch-mode" value="tot"/>
  </project>
"""

INCLUDE_REMOTES_XML = """
  <include name="_remotes.xml"/>
"""

INCLUDE_EXTERNAL_XML = """
  <include name="external.xml"/>
"""

INCLUDE_INTERNAL_XML = """
  <include name="internal.xml"/>
"""

# Combine the XML chunks above into meaningful files. Create files for
# both manifest and manifest-internal projects, once for TOT and once
# for a branch named new-branch.
MANIFEST_FILES = {
    REMOTES_FILE_NAME:
        ManifestXml(REMOTE_EXTERNAL_XML),
    EXTERNAL_FILE_NAME:
        ManifestXml(DEFAULT_XML, INCLUDE_REMOTES_XML, PROJECTS_EXTERNAL_XML),
    constants.DEFAULT_MANIFEST:
        ManifestXml(INCLUDE_EXTERNAL_XML),
}

MANIFEST_INTERNAL_FILES = {
    REMOTES_FILE_NAME:
        ManifestXml(REMOTE_EXTERNAL_XML, REMOTE_INTERNAL_XML),
    EXTERNAL_FILE_NAME:
        MANIFEST_FILES[EXTERNAL_FILE_NAME],
    INTERNAL_FILE_NAME:
        ManifestXml(DEFAULT_XML, INCLUDE_REMOTES_XML, PROJECTS_INTERNAL_XML),
    constants.OFFICIAL_MANIFEST:
        ManifestXml(INCLUDE_INTERNAL_XML, INCLUDE_EXTERNAL_XML),
    constants.DEFAULT_MANIFEST:
        ManifestXml(INCLUDE_INTERNAL_XML, INCLUDE_EXTERNAL_XML),
}

# Store the full, parsed manifest XML for TOT.
FULL_TOT_XML = ManifestXml(DEFAULT_XML, REMOTE_EXTERNAL_XML,
                           REMOTE_INTERNAL_XML, PROJECTS_EXTERNAL_XML,
                           PROJECTS_INTERNAL_XML)

# Now create a branched version of the above XML.
DEFAULT_BRANCHED_XML = """
  <default remote="cros"/>
"""

PROJECTS_EXTERNAL_BRANCHED_XML = """
  <project name="chromiumos/manifest"
           path="manifest"
           revision="refs/heads/old-branch"/>

  <project name="chromiumos/overlays/chromiumos-overlay"
           path="src/third_party/chromiumos-overlay"
           revision="refs/heads/old-branch"/>

  <project name="external/implicit-pinned"
           path="src/third_party/implicit-pinned"
           revision="refs/heads/implicit-pinned"/>

  <project name="chromiumos/multicheckout"
           path="src/third_party/multicheckout-a"
           revision="refs/heads/old-branch-multicheckout-a"/>

  <project name="chromiumos/multicheckout"
           path="src/third_party/multicheckout-b"
           revision="refs/heads/old-branch-multicheckout-b"/>

  <project name="chromiumos/non-default-group"
           path="src/third_party/non-default-group"
           revision="refs/heads/old-branch"
           groups="notdefault,special-group"/>
"""

PROJECTS_INTERNAL_BRANCHED_XML = """
  <project name="chromeos/manifest-internal"
           path="manifest-internal"
           remote="cros-internal"
           revision="refs/heads/old-branch"/>

  <project name="chromeos/explicit-pinned"
           path="src/explicit-pinned"
           revision="refs/heads/explicit-pinned"
           remote="cros-internal">
    <annotation name="branch-mode" value="pin"/>
  </project>

  <project name="chromeos/explicit-branch"
           path="src/explicit-branch"
           remote="cros-internal"
           revision="refs/heads/old-branch">
    <annotation name="branch-mode" value="create"/>
  </project>

  <project name="chromeos/explicit-tot"
           path="src/explicit-tot"
           remote="cros-internal"
           revision="refs/heads/master">
    <annotation name="branch-mode" value="tot"/>
  </project>
"""

MANIFEST_BRANCHED_FILES = {
    REMOTES_FILE_NAME:
        ManifestXml(REMOTE_EXTERNAL_XML),
    EXTERNAL_FILE_NAME:
        ManifestXml(DEFAULT_BRANCHED_XML, INCLUDE_REMOTES_XML,
                    PROJECTS_EXTERNAL_BRANCHED_XML),
    constants.DEFAULT_MANIFEST:
        ManifestXml(INCLUDE_EXTERNAL_XML),
}

MANIFEST_INTERNAL_BRANCHED_FILES = {
    REMOTES_FILE_NAME:
        ManifestXml(REMOTE_EXTERNAL_XML, REMOTE_INTERNAL_XML),
    EXTERNAL_FILE_NAME:
        MANIFEST_BRANCHED_FILES[EXTERNAL_FILE_NAME],
    INTERNAL_FILE_NAME:
        ManifestXml(DEFAULT_BRANCHED_XML, INCLUDE_REMOTES_XML,
                    PROJECTS_INTERNAL_BRANCHED_XML),
    constants.OFFICIAL_MANIFEST:
        ManifestXml(INCLUDE_INTERNAL_XML, INCLUDE_EXTERNAL_XML),
    constants.DEFAULT_MANIFEST:
        ManifestXml(INCLUDE_INTERNAL_XML, INCLUDE_EXTERNAL_XML),
}

FULL_BRANCHED_XML = ManifestXml(
    DEFAULT_BRANCHED_XML, REMOTE_INTERNAL_XML, REMOTE_EXTERNAL_XML,
    PROJECTS_INTERNAL_BRANCHED_XML, PROJECTS_EXTERNAL_BRANCHED_XML)


class ManifestTestCase(cros_test_lib.TestCase):
  """Test case providing valid manifest test data.

  This class generates a diverse collection of manifest XML strings, and
  provides convenience methods for reading from those manifests.
  """

  def NameFor(self, pid, manifest=None):
    """Return the test project's name.

    Args:
      pid: The test project ID (e.g. 'chromiumos-overlay').
      manifest: The repo_manifest.Manifest to read from.
          Uses full_manifest if None.

    Returns:
      Name of the project, e.g. 'chromeos/manifest-internal'.
    """
    return self.ProjectFor(pid, manifest).name

  def PathFor(self, pid, manifest=None):
    """Return the test project's path.

    Args:
      pid: The test project ID (e.g. 'chromiumos-overlay').
      manifest: The repo_manifest.Manifest to read from.
          Uses full_manifest if None.

    Returns:
      Path to the project, always of the form '<test path>/<project ID>'.
    """
    return self.ProjectFor(pid, manifest).Path()

  def PathListRegexFor(self, pid, manifest=None):
    """Return the test project's path as a ListRegex.

    Args:
      pid: The test project ID (e.g. 'chromiumos-overlay').
      manifest: The repo_manifest.Manifest to read from.
          Uses full_manifest if None.

    Returns:
      partial_mock.ListRegex for project path.
    """
    return partial_mock.ListRegex('.*/%s' % self.PathFor(pid, manifest))

  def RevisionFor(self, pid, manifest=None):
    """Return the test project's revision.

    Args:
      pid: The test project ID (e.g. 'chromiumos-overlay')
      manifest: The repo_manifest.Manifest to read from.
          Uses full_manifest if None.

    Returns:
      Reivision for the project, always of form 'refs/heads/<project ID>'.
    """
    return self.ProjectFor(pid, manifest).Revision()

  def RemoteFor(self, pid, manifest=None):
    """Return the test project's remote name.

    Args:
      pid: The test project ID (e.g. 'chromiumos-overlay')
      manifest: The repo_manifest.Manifest to read from.
          Uses full_manifest if None.

    Returns:
      Remote name for the project, e.g. 'cros'.
    """
    return self.ProjectFor(pid, manifest).Remote().GitName()

  def ProjectFor(self, pid, manifest=None):
    """Return the test project's repo_manifest.Project.

    Args:
      pid: The test project ID (e.g. 'chromiumos-overlay')
      manifest: The repo_manifest.Manifest to read from.
          Uses full_manifest if None.

    Returns:
      Corresponding repo_manifest.Project.
    """
    manifest = manifest or self.full_manifest
    # Project paths always end with the project ID, so use that as key.
    match = [p for p in manifest.Projects() if p.Path().endswith(pid)]
    assert len(match) == 1
    return match[0]

  def PidFor(self, project):
    """Return the project's ID.

    Args:
      project: The repo_manifest.Project object.

    Returns:
      The project ID, always stored as the last component of its path.
    """
    return os.path.basename(project.Path())

  def setUp(self):
    # Parse and cache the full TOT manifest to take advantage of the
    # utility functions in repo_manifest.
    self.full_manifest = repo_manifest.Manifest.FromString(FULL_TOT_XML)

    # Ditto for the branched manifest.
    self.full_branched_manifest = repo_manifest.Manifest.FromString(
        FULL_BRANCHED_XML)


class UtilitiesTest(ManifestTestCase, cros_test_lib.MockTestCase):
  """Tests for all top-level utility functions."""

  def testCanBranchProjectAcceptsBranchableProjects(self):
    """Test CanBranchProject returns true when project is branchable."""
    for project in BRANCHED_PROJECTS:
      self.assertTrue(CanBranchProject(self.ProjectFor(project)))

  def testCanBranchProjectRejectsNonBranchableProjects(self):
    """Test CanBranchProject returns false when project is not branchable."""
    for project in NON_BRANCHED_PROJECTS:
      self.assertFalse(CanBranchProject(self.ProjectFor(project)))

  def testCanPinProjectAcceptsPinnedProjects(self):
    """Test CanPinProject returns true when project is pinned."""
    for project in PINNED_PROJECTS:
      self.assertTrue(CanPinProject(self.ProjectFor(project)))

  def testCanPinProjectRejectsNonPinnedProjects(self):
    """Test CanPinProject returns false when project is not pinned."""
    for project in BRANCHED_PROJECTS + TOT_PROJECTS:
      self.assertFalse(CanPinProject(self.ProjectFor(project)))

  def testTotMutualExclusivity(self):
    """Test CanBranch/PinProject both return false only when project is TOT."""
    for pid in PROJECTS.values():
      project = self.ProjectFor(pid)
      if not CanBranchProject(project) and not CanPinProject(project):
        self.assertIn(pid, TOT_PROJECTS)


class ManifestRepositoryTest(ManifestTestCase, cros_test_lib.MockTestCase):
  """Tests for ManifestRepository functions."""

  def GitRevisionMock(self, project):
    """Mock git.GetGitRepoRevision returning fake revision for given project.

    Args:
      project: Project to get the revision for.

    Returns:
      The repo HEAD as a string.
    """
    return project.Revision()

  def FromFileMock(self, path, allow_unsupported_features=False):
    """Forward repo_manifest.FromFile to repo_manifest.FromString.

    Args:
      path: File path for internal manifest. Used to look up XML in a table.
      allow_unsupported_features: See repo_manifest.Manifest.

    Returns:
      repo_manifest.Manifest created from test data.
    """
    return repo_manifest.Manifest.FromString(
        MANIFEST_INTERNAL_FILES[os.path.basename(path)],
        allow_unsupported_features=allow_unsupported_features)

  def PathExistsMock(self, path):
    """Returns true if the fake manifest file exists.

    Args:
      path: Path to the manifest.

    Returns:
      True if we have a fake manifest under the given name.
    """
    return os.path.basename(path) in MANIFEST_INTERNAL_FILES

  def setUp(self):
    self.PatchObject(CrosCheckout, 'GitRevision', self.GitRevisionMock)
    self.PatchObject(CrosCheckout, 'EnsureProject')
    self.PatchObject(repo_manifest.Manifest, 'FromFile', self.FromFileMock)
    self.PatchObject(os.path, 'exists', self.PathExistsMock)

    self.root = '/root'
    self.checkout = CrosCheckout(self.root, manifest=self.full_manifest)
    self.project = self.ProjectFor(PROJECTS.MANIFEST_INTERNAL)
    self.manifest_repo = ManifestRepository(self.checkout, self.project)

  def testRepairManifestDeletesDefaultRevision(self):
    """Test RepairManifest deletes revision attr on <default> and <remote>."""
    branches = {
        self.PathFor(PROJECTS.MANIFEST_INTERNAL): 'beep',
        self.PathFor(PROJECTS.EXPLICIT_BRANCH): 'boop',
    }
    actual = self.manifest_repo.RepairManifest(INTERNAL_FILE_NAME, branches)
    self.assertIsNone(actual.Default().revision)

  def testRepairManifestDeletesRemoteRevision(self):
    """Test RepairManifest deletes revision attr on <default> and <remote>."""
    branches = {
        self.PathFor(PROJECTS.MANIFEST_INTERNAL): 'beep',
        self.PathFor(PROJECTS.EXPLICIT_BRANCH): 'boop',
    }
    actual = self.manifest_repo.RepairManifest(REMOTES_FILE_NAME, branches)
    self.assertIsNone(actual.GetRemote(REMOTES.CROS_INTERNAL).revision)

  def testRepairManifestUpdatesBranchedProjectRevisions(self):
    """Test RepairManifest updates revision=branch on branched projects."""
    branches = {
        self.PathFor(PROJECTS.MANIFEST_INTERNAL): 'branch-a',
        self.PathFor(PROJECTS.EXPLICIT_BRANCH): 'branch-b'
    }
    actual = self.manifest_repo.RepairManifest(INTERNAL_FILE_NAME, branches)

    manifest_internal = actual.GetUniqueProject(
        self.NameFor(PROJECTS.MANIFEST_INTERNAL))
    self.assertEqual(manifest_internal.revision, 'refs/heads/branch-a')

    explicit_branch = actual.GetUniqueProject(
        self.NameFor(PROJECTS.EXPLICIT_BRANCH))
    self.assertEqual(explicit_branch.revision, 'refs/heads/branch-b')

  def testRepairManifestUpdatesPinnedProjectRevisions(self):
    """Test RepairManifest retains revision attr on pinned projects."""
    branches = {
        self.PathFor(PROJECTS.MANIFEST_INTERNAL): 'irrelevant',
        self.PathFor(PROJECTS.EXPLICIT_BRANCH): 'should-not-matter'
    }
    actual = self.manifest_repo.RepairManifest(INTERNAL_FILE_NAME, branches)
    proj = actual.GetUniqueProject(self.NameFor(PROJECTS.EXPLICIT_PINNED))
    self.assertEqual(proj.revision, self.RevisionFor(PROJECTS.EXPLICIT_PINNED))

  def testRepairManifestUpdatesTotProjectRevisions(self):
    """Test RepairManifest sets revision=refs/heads/master on TOT projects."""
    branches = {
        self.PathFor(PROJECTS.MANIFEST_INTERNAL): 'irrelevant',
        self.PathFor(PROJECTS.EXPLICIT_BRANCH): 'should-not-matter'
    }
    actual = self.manifest_repo.RepairManifest(INTERNAL_FILE_NAME, branches)
    proj = actual.GetUniqueProject(self.NameFor(PROJECTS.EXPLICIT_TOT))
    self.assertEqual(proj.revision, 'refs/heads/master')

  def testRepairManifestsOnDisk(self):
    """Test RepairManifestsOnDisk writes all manifests."""
    repair = self.PatchObject(
        ManifestRepository, 'RepairManifest', return_value=self.full_manifest)
    write = self.PatchObject(repo_manifest.Manifest, 'Write')

    branches = [
        ProjectBranch(self.ProjectFor(PROJECTS.MANIFEST_INTERNAL), 'branch-a'),
        ProjectBranch(self.ProjectFor(PROJECTS.EXPLICIT_BRANCH), 'branch-b'),
    ]
    branches_by_path = {
        self.PathFor(PROJECTS.MANIFEST_INTERNAL): 'branch-a',
        self.PathFor(PROJECTS.EXPLICIT_BRANCH): 'branch-b',
    }

    self.manifest_repo.RepairManifestsOnDisk(branches)
    self.assertCountEqual(repair.call_args_list, [
        mock.call('/root/manifest-internal/default.xml', branches_by_path),
        mock.call('/root/manifest-internal/official.xml', branches_by_path),
        mock.call('/root/manifest-internal/internal.xml', branches_by_path),
        mock.call('/root/manifest-internal/external.xml', branches_by_path),
        mock.call('/root/manifest-internal/_remotes.xml', branches_by_path),
    ])
    self.assertCountEqual(write.call_args_list, [
        mock.call('/root/manifest-internal/default.xml'),
        mock.call('/root/manifest-internal/official.xml'),
        mock.call('/root/manifest-internal/internal.xml'),
        mock.call('/root/manifest-internal/external.xml'),
        mock.call('/root/manifest-internal/_remotes.xml'),
    ])


class CrosCheckoutTest(ManifestTestCase, cros_test_lib.MockTestCase):
  """Tests for nontrivial methods in CrosCheckout."""

  def setUp(self):
    self.rc_mock = cros_test_lib.RunCommandMock()
    self.rc_mock.SetDefaultCmdResult()
    self.StartPatcher(self.rc_mock)

    self.PatchObject(repo_util.Repository, '__init__', return_value=None)
    self.PatchObject(
        repo_util.Repository, 'Manifest', return_value=self.full_manifest)
    self.PatchObject(
        config_lib,
        'GetSiteParams',
        return_value=config_lib.AttrDict(
            EXTERNAL_MANIFEST_VERSIONS_PATH='manifest-versions',
            INTERNAL_MANIFEST_VERSIONS_PATH='manifest-versions-internal',
        ))
    self.make_dirs = self.PatchObject(osutils, 'SafeMakedirs')
    self.initialize = self.PatchObject(repo_util.Repository, 'Initialize')
    self.match_branch_name = self.PatchObject(
        git, 'MatchBranchName', return_value=['branch'])
    self.get_current_branch = self.PatchObject(
        git, 'GetCurrentBranch', return_value='local-branch')
    self.get_git_repo_revision = self.PatchObject(
        git, 'GetGitRepoRevision', return_value='abcdef')
    self.commit_exists = self.PatchObject(
        git, 'DoesCommitExistInRepo', return_value=False)
    self.from_repo = self.PatchObject(
        VersionInfo, 'from_repo', return_value=VersionInfo('1.2.3'))
    self.increment_version = self.PatchObject(VersionInfo, 'IncrementVersion')
    self.update_version = self.PatchObject(VersionInfo, 'UpdateVersionFile')
    self.PatchObject(constants, 'CHROMITE_DIR', new='/run-root/chromite')

  def testInitialize(self):
    """Test Initialize calls the correct functions with the correct data."""
    self.PatchObject(git, 'FindRepoCheckoutRoot', return_value=None)
    checkout = CrosCheckout.Initialize(
        '/root',
        'manifest.com',
        repo_url='repo',
        repo_branch='default',
        groups='all')
    self.assertEqual(checkout.root, '/root')
    self.assertEqual(checkout.manifest_url, 'manifest.com')
    self.assertEqual(checkout.repo_url, 'repo')
    self.assertEqual(checkout.groups, 'all')
    self.assertEqual(self.make_dirs.call_count, 1)
    self.assertEqual(self.initialize.call_args_list, [
        mock.call(
            '/root',
            'manifest.com',
            repo_url='repo',
            repo_branch='default',
            groups='all')
    ])

  def testInitializeNoRepoInit(self):
    """Test Initialize does not call repo init when already initialized."""
    self.PatchObject(git, 'FindRepoCheckoutRoot', return_value='/root')
    checkout = CrosCheckout.Initialize(
        '/root', 'manifest.com', repo_url='repo', repo_branch='default')
    self.assertEqual(checkout.root, '/root')
    self.assertEqual(checkout.manifest_url, 'manifest.com')
    self.assertEqual(checkout.repo_url, 'repo')
    self.assertFalse(self.initialize.call_count)

  def testSyncVersionMinimal(self):
    """Test SyncVersion passes minimal args to repo_sync_manifest."""
    checkout = CrosCheckout('/root')
    checkout.SyncVersion('1.2.3')
    self.rc_mock.assertCommandContains([
        '/run-root/chromite/scripts/repo_sync_manifest', '--repo-root', '/root',
        '--manifest-versions-int', '/root/manifest-versions-internal',
        '--manifest-versions-ext', '/root/manifest-versions', '--version',
        '1.2.3'
    ])

  def testSyncVersionAllOptions(self):
    """Test SyncVersion passes all args to repo_sync_manifest."""
    checkout = CrosCheckout(
        '/root', repo_url='repo.com', manifest_url='manifest.com')
    checkout.SyncVersion('1.2.3')
    self.rc_mock.assertCommandContains([
        '/run-root/chromite/scripts/repo_sync_manifest', '--repo-root', '/root',
        '--manifest-versions-int', '/root/manifest-versions-internal',
        '--manifest-versions-ext', '/root/manifest-versions', '--version',
        '1.2.3', '--repo-url', 'repo.com', '--manifest-url', 'manifest.com'
    ])

  def testSyncBranchMinimal(self):
    """Test SyncBranch passes minimal args to repo_sync_manifest."""
    checkout = CrosCheckout('/root')
    checkout.SyncBranch('branch')
    self.rc_mock.assertCommandContains([
        '/run-root/chromite/scripts/repo_sync_manifest', '--repo-root', '/root',
        '--branch', 'branch'
    ])

  def testSyncBranchAllOptions(self):
    """Test SyncBranch passes all args to repo_sync_manifest."""
    checkout = CrosCheckout(
        '/root', repo_url='repo.com', manifest_url='manifest.com')
    checkout.SyncBranch('branch')
    self.rc_mock.assertCommandContains([
        '/run-root/chromite/scripts/repo_sync_manifest', '--repo-root', '/root',
        '--branch', 'branch', '--repo-url', 'repo.com', '--manifest-url',
        'manifest.com'
    ])

  def testSyncFileMinimal(self):
    """Test SyncFile passes correct args to repo_sync_manifest."""
    checkout = CrosCheckout('/root')
    checkout.SyncFile('manifest.xml')
    manifest_path = os.path.abspath('manifest.xml')
    self.rc_mock.assertCommandContains(
        ['repo', 'sync', '--manifest-name', manifest_path], cwd='/root')

  def testSyncFileAllOptions(self):
    """Test SyncFile passes all args to repo_sync_manifest."""
    checkout = CrosCheckout(
        '/root', repo_url='repo.com', manifest_url='manifest.com')
    checkout.SyncFile('manifest.xml')
    manifest_path = os.path.abspath('manifest.xml')
    self.rc_mock.assertCommandContains(
        ['repo', 'sync', '--manifest-name', manifest_path], cwd='/root')

  def testAbsolutePath(self):
    """Test AbsolutePath joins root to given path."""
    checkout = CrosCheckout('/foo')
    self.assertEqual(checkout.AbsolutePath('bar'), '/foo/bar')

  def testAbsoluteProjectPath(self):
    """Test AbsoluteProjectPath joins root and project path."""
    checkout = CrosCheckout('/foo')
    project = self.ProjectFor(PROJECTS.MANIFEST)
    actual = checkout.AbsoluteProjectPath(project, 'bar')
    self.assertEqual(actual, '/foo/manifest/bar')

  def testEnsureProjectBadProject(self):
    """Test EnsurePath raises error if project does not exist."""
    self.PatchObject(os.path, 'exists', return_value=False)
    checkout = CrosCheckout('/foo')
    project = self.ProjectFor(PROJECTS.MANIFEST)
    with self.assertRaises(BranchError):
      checkout.EnsureProject(project)

  def testEnsureProjectGoodProject(self):
    """Test EnsurePath raises error if project does not exist."""
    self.PatchObject(os.path, 'exists', return_value=True)
    checkout = CrosCheckout('/foo')
    project = self.ProjectFor(PROJECTS.MANIFEST)
    checkout.EnsureProject(project)

  def testReadVersion(self):
    """Test ReadVersion does not modify VersionInfo."""
    checkout = CrosCheckout('/root')
    vinfo = checkout.ReadVersion()
    self.assertEqual(vinfo.build_number, '1')
    self.assertEqual(vinfo.branch_build_number, '2')
    self.assertEqual(vinfo.patch_number, '3')

  def testBumpVersionMinimal(self):
    """Test BumpVersion with minimal arguments."""
    checkout = CrosCheckout('/root')
    checkout.BumpVersion('patch', 'my-branch', 'My message.')

    self.assertEqual(self.from_repo.call_args_list,
                     [mock.call('/root', incr_type='patch')])
    self.assertEqual(self.increment_version.call_count, 1)
    self.assertEqual(self.update_version.call_args_list, [
        mock.call(
            'My message.',
            dry_run=True,
            push_to=git.RemoteRef('cros', 'refs/heads/my-branch'))
    ])

  def testBumpVersionAllOptions(self):
    """Test BumpVersion properly defers to manifest_version functions."""
    checkout = CrosCheckout('/root')
    checkout.BumpVersion(
        'patch', 'my-branch', 'My message.', fetch=True, dry_run=False)

    self.rc_mock.assertCommandContains(
        ['git', 'fetch', 'cros', 'refs/heads/my-branch'],
        cwd='/root/src/third_party/chromiumos-overlay')
    self.rc_mock.assertCommandContains(
        ['git', 'checkout', '-B', 'my-branch', 'FETCH_HEAD'],
        cwd='/root/src/third_party/chromiumos-overlay')
    self.assertEqual(self.from_repo.call_args_list,
                     [mock.call('/root', incr_type='patch')])
    self.assertEqual(self.increment_version.call_count, 1)
    self.assertEqual(self.update_version.call_args_list, [
        mock.call(
            'My message.',
            dry_run=False,
            push_to=git.RemoteRef('cros', 'refs/heads/my-branch'))
    ])

  def testRunGit(self):
    """Test RunGit runs git command in project directory."""
    checkout = CrosCheckout('/root')
    project = self.ProjectFor(PROJECTS.MANIFEST)

    checkout.RunGit(project, ['branch', '-m', 'foo'])
    self.rc_mock.assertCommandContains(['git', 'branch', '-m', 'foo'],
                                       cwd='/root/manifest',
                                       print_cmd=True)

  def testGitRevision(self):
    """Test GitRevision properly forwards project path."""
    checkout = CrosCheckout('/root')
    project = self.ProjectFor(PROJECTS.MANIFEST)

    actual = checkout.GitRevision(project)
    self.assertEqual(self.get_git_repo_revision.call_args_list,
                     [mock.call('/root/manifest')])
    self.assertEqual(actual, 'abcdef')

  def testGitBranch(self):
    """Test GitBranch properly forwards project path."""
    checkout = CrosCheckout('/root')
    project = self.ProjectFor(PROJECTS.MANIFEST)

    actual = checkout.GitBranch(project)
    self.assertEqual(self.get_current_branch.call_args_list,
                     [mock.call('/root/manifest')])
    self.assertEqual(actual, 'local-branch')

  def testBranchExists(self):
    checkout = CrosCheckout('/root')
    project = self.ProjectFor(PROJECTS.MANIFEST_INTERNAL)

    actual = checkout.BranchExists(project, 'my-branch')
    self.assertTrue(actual)
    self.assertEqual(self.match_branch_name.call_args_list,
                     [mock.call('/root/manifest-internal', 'my-branch')])


class BranchTest(ManifestTestCase, cros_test_lib.MockTestCase):
  """Tests core functionality of Branch class."""

  def SetVersion(self, version):
    """Mock VersionInfo.from_repo to always return the given version.

    Args:
      version: The version string to return.
    """
    self.PatchObject(
        CrosCheckout, 'ReadVersion', return_value=VersionInfo(version))

  def AssertBranchPushed(self, project, branch):
    """Assert given branch pushed to remote for given project.

    Args:
      project: Project ID.
      branch: Expected name for the branch.
    """
    self.rc_mock.assertCommandContains(
        ['git', 'push',
         self.RemoteFor(project),
         'HEAD:refs/heads/%s' % branch],
        cwd=self.PathListRegexFor(project))

  def AssertRemoteBranchDeleted(self, project, branch):
    """Assert given branch deleted on remote for given project.

    Args:
      project: Project ID.
      branch: Expected name for the branch.
    """
    self.rc_mock.assertCommandContains([
        'git', 'push',
        self.RemoteFor(project), '--delete',
        'refs/heads/%s' % branch
    ],
                                       cwd=self.PathListRegexFor(project))

  def AssertNoPush(self, project):
    """Assert no push operation run inside the given project.

    Args:
      project: Project ID.
    """
    self.rc_mock.assertCommandContains(['git', 'push'],
                                       cwd=self.PathListRegexFor(project),
                                       expected=False)

  def AssertManifestRepairsCommitted(self):
    """Assert commits made to all manifest repositories."""
    for manifest_project in MANIFEST_PROJECTS:
      self.rc_mock.assertCommandContains(['git', 'commit', '-a'],
                                         cwd=partial_mock.ListRegex(
                                             '.*/%s' % manifest_project))

  def setUp(self):
    self.rc_mock = cros_test_lib.RunCommandMock()
    self.rc_mock.SetDefaultCmdResult()
    self.StartPatcher(self.rc_mock)

    # ManifestRepository and CrosCheckout tested separately, so mock them.
    self.PatchObject(ManifestRepository, 'RepairManifestsOnDisk')
    self.PatchObject(
        CrosCheckout, 'ReadVersion', return_value=VersionInfo('1.2.0'))
    self.bump_version = self.PatchObject(CrosCheckout, 'BumpVersion')

    # Fake checkouts for each test.
    self.checkout = CrosCheckout('/', manifest=self.full_manifest)
    self.branched_checkout = CrosCheckout(
        '/', manifest=self.full_branched_manifest)

  def testCreateRepairsManifests(self):
    """Test Create commits repairs to manifest repositories."""
    Branch(self.checkout, 'new-branch').Create()
    self.AssertManifestRepairsCommitted()

  def testCreateBumpsBranchNumber(self):
    """Test WhichVersionShouldBump bumps branch number on X.0.0 version."""
    self.SetVersion('1.0.0')
    Branch(self.checkout, 'new-branch').Create()
    self.assertEqual(self.bump_version.call_args_list, [
        mock.call('branch', 'new-branch', mock.ANY, dry_run=True),
        mock.call('build', 'master', mock.ANY, dry_run=True)
    ])

  def testCreateBumpsPatchNumber(self):
    """Test WhichVersionShouldBump bumps patch number on X.X.0 version."""
    self.SetVersion('1.2.0')
    Branch(self.checkout, 'new-branch').Create()
    self.assertEqual(self.bump_version.call_args_list, [
        mock.call('patch', 'new-branch', mock.ANY, dry_run=True),
        mock.call('branch', 'master', mock.ANY, dry_run=True)
    ])

  def testCreateDiesOnNonzeroPatchNumber(self):
    """Test WhichVersionShouldBump dies on X.X.X version."""
    self.SetVersion('1.2.3')
    with self.assertRaises(AssertionError):
      Branch(self.checkout, 'new-branch').Create()

  def testCreatePushesToRemote(self):
    """Test Create pushes new branch to remote."""
    Branch(self.checkout, 'new-branch').Create(push=True)
    for project in SINGLE_CHECKOUT_PROJECTS:
      self.AssertBranchPushed(project, 'new-branch')
    for project in MULTI_CHECKOUT_PROJECTS:
      self.AssertBranchPushed(project, 'new-branch-' + project)
    for project in NON_BRANCHED_PROJECTS:
      self.AssertNoPush(project)

  def testRenameRepairsManifests(self):
    """Test Rename commits repairs to manifest repositories."""
    Branch(self.branched_checkout, 'new-branch').Rename('old-branch')
    self.AssertManifestRepairsCommitted()

  def testRenamePushesNewBranch(self):
    """Test Rename pushes the new branch to remote."""
    Branch(self.branched_checkout, 'new-branch').Rename('old-branch', push=True)
    for project in SINGLE_CHECKOUT_PROJECTS:
      self.AssertBranchPushed(project, 'new-branch')
    for project in MULTI_CHECKOUT_PROJECTS:
      self.AssertBranchPushed(project, 'new-branch-' + project)
    for project in NON_BRANCHED_PROJECTS:
      self.AssertNoPush(project)

  def testRenamePushesDeletionOfOldBranch(self):
    """Test rename deletes old branch on remote."""
    Branch(self.branched_checkout, 'new-branch').Rename('old-branch', push=True)
    for project in SINGLE_CHECKOUT_PROJECTS:
      self.AssertRemoteBranchDeleted(project, 'old-branch')
    for project in MULTI_CHECKOUT_PROJECTS:
      self.AssertRemoteBranchDeleted(project, 'old-branch-' + project)
    for project in NON_BRANCHED_PROJECTS:
      self.AssertNoPush(project)

  def testDeleteRequiresForceForRemotePush(self):
    """Verify Delete does nothing when push is True but force is False."""
    with self.assertRaises(BranchError):
      Branch(self.branched_checkout, 'old-branch').Delete(push=True)
    for project in PROJECTS.values():
      self.AssertNoPush(project)

  def testDeletePushesDeletions(self):
    """Verify delete deletes remote branches when push=force=True."""
    Branch(self.branched_checkout, 'old-branch').Delete(push=True, force=True)
    for project in SINGLE_CHECKOUT_PROJECTS:
      self.AssertRemoteBranchDeleted(project, 'old-branch')
    for project in MULTI_CHECKOUT_PROJECTS:
      self.AssertRemoteBranchDeleted(project, 'old-branch-' + project)
    for project in NON_BRANCHED_PROJECTS:
      self.AssertNoPush(project)


class StandardBranchTest(ManifestTestCase, cros_test_lib.MockTestCase):
  """Tests branch logic specific to the standard branches."""

  def SetVersion(self, milestone, version):
    """Mock VersionInfo to always return the given versions.

    Args:
      milestone: The Chrome branch number, e.g. '47'
      version: The manifest version string, e.g. '1.2.0'
    """
    self.PatchObject(
        CrosCheckout,
        'ReadVersion',
        return_value=VersionInfo(version, milestone))

  def setUp(self):
    self.checkout = CrosCheckout('/', manifest=self.full_manifest)

  def testGenerateNameWithoutBranchVersion(self):
    """Test name generation on a X.0.0 version."""
    self.SetVersion('12', '3.0.0')
    branch_names = {
        'release-R12-3.B': ReleaseBranch,
        'factory-3.B': FactoryBranch,
        'firmware-3.B': FirmwareBranch,
        'stabilize-3.B': StabilizeBranch,
    }
    for branch_name, branch_type in branch_names.items():
      self.assertEqual(branch_type(self.checkout).name, branch_name)

  def testGenerateNameWithBranchVersion(self):
    """Test name generation on a X.X.0 version."""
    self.SetVersion('12', '3.4.0')
    branch_names = {
        'release-R12-3.4.B': ReleaseBranch,
        'factory-3.4.B': FactoryBranch,
        'firmware-3.4.B': FirmwareBranch,
        'stabilize-3.4.B': StabilizeBranch,
    }
    for branch_name, cls in branch_names.items():
      self.assertEqual(cls(self.checkout).name, branch_name)

  def testGenerateNameWithDescriptor(self):
    """Test name generation with a descriptor."""
    self.SetVersion('12', '3.4.0')
    branch_names = {
        'release-board-R12-3.4.B': ReleaseBranch,
        'factory-board-3.4.B': FactoryBranch,
        'firmware-board-3.4.B': FirmwareBranch,
        'stabilize-board-3.4.B': StabilizeBranch,
    }
    for branch_name, cls in branch_names.items():
      self.assertEqual(cls(self.checkout, 'board').name, branch_name)


class MockBranchCommand(command_unittest.MockCommand):
  """Mock out the `cros branch` command."""
  TARGET = 'chromite.cli.cros.cros_branch.BranchCommand'
  TARGET_CLASS = BranchCommand
  COMMAND = 'branch'


class BranchCommandTest(ManifestTestCase, cros_test_lib.MockTestCase):
  """Tests for BranchCommand functions."""

  def RunCommandMock(self, args):
    """Patch the mock command and run it.

    Args:
      args: List of arguments for the command.
    """
    self.cmd = MockBranchCommand(args)
    self.StartPatcher(self.cmd)
    self.cmd.inst.Run()

  def AssertSynced(self, args):
    """Assert repo_sync_manifest was run with at least the given args.

    Args:
      args: Expected args for repo_sync_manifest.
    """
    self.cmd.rc_mock.assertCommandContains(
        [partial_mock.ListRegex('.*/repo_sync_manifest')] + args)

  def AssertSyncedUsingRepo(self, args):
    """Assert repo sync was run with at least the given args.

    Args:
      args: Expected args for repo sync.
    """
    self.cmd.rc_mock.assertCommandContains(['repo', 'sync'] + args)

  def AssertNoDangerousOptions(self):
    """Assert that force and push were not set."""
    self.assertFalse(self.cmd.inst.options.force)
    self.assertFalse(self.cmd.inst.options.push)

  def setUp(self):
    self.cmd = None
    self.create = self.PatchObject(Branch, 'Create')
    self.PatchObject(ReleaseBranch, 'Create')
    self.PatchObject(Branch, 'Rename')
    self.PatchObject(Branch, 'Delete')
    self.PatchObject(repo_util, 'Repository')
    self.PatchObject(
        repo_util.Repository, 'Manifest', return_value=self.full_manifest)
    self.PatchObject(
        CrosCheckout,
        'Initialize',
        return_value=CrosCheckout('', manifest=self.full_manifest))
    self.PatchObject(
        CrosCheckout, 'ReadVersion', return_value=VersionInfo('1.2.0'))
    self.PatchObject(CrosCheckout, 'BranchExists', return_value=False)
    self.get_input = self.PatchObject(
        cros_build_lib, 'GetInput', return_value='yes')
    td_context = self.PatchObject(CrosCheckout, 'TempRoot')
    td_context.return_value.__enter__.return_value = '/td'

  def testCreateDiesWhenNonzeroPatchNumber(self):
    """Test create validates zero patch number."""
    with self.assertRaises(BranchError):
      self.RunCommandMock(['create', '--version', '1.2.3', '--release'])

  def testCreateDiesWhenVersionAlreadyBranched(self):
    """Test create validates version has no existing branches."""
    branch_exists = self.PatchObject(
        CrosCheckout, 'BranchExists', return_value=True)
    with self.assertRaises(BranchError):
      self.RunCommandMock(['create', '--version', '1.2.0', '--release'])
    self.assertEqual(branch_exists.call_args_list,
                     [mock.call(mock.ANY, '.*-1\\.2\\.B$')])

  def testCreateWithForceDoesNotCheckVersion(self):
    """Test create validates version has no existing branches."""
    branch_exists = self.PatchObject(
        CrosCheckout, 'BranchExists', return_value=True)
    self.RunCommandMock(
        ['--force', 'create', '--version', '1.2.0', '--release'])
    self.assertEqual(branch_exists.call_args_list,
                     [mock.call(mock.ANY, '.*-1\\.2\\.B$')])

  def testCreateConfirmsGeneratedBranchNameNoAnswer(self):
    """Test create confirms generated branch names with users."""
    self.get_input = self.PatchObject(
        cros_build_lib, 'GetInput', return_value='no')
    self.RunCommandMock(['create', '--version', '1.2.0', '--factory'])
    self.assertEqual(self.get_input.call_args_list, [
        mock.call(
            '\nNew branch will be named factory-1.2.B. Continue? (yes/No)? ')
    ])
    self.assertFalse(self.create.call_count)

  def testCreateDoesNotConfirmGeneratedBranchNameWithYesFlag(self):
    """Tests --yes flag (which skips the name confirmation prompt)."""
    self.get_input = self.PatchObject(cros_build_lib, 'GetInput')
    self.RunCommandMock(['create', '--version', '1.2.0', '--factory', '--yes'])
    self.assertEqual(self.get_input.call_args_list, [])
    self.assertEqual(self.create.call_count, 1)

  def testCreateReleaseCommandParses(self):
    """Test `cros branch create` parses with '--release' flag."""
    self.RunCommandMock(['create', '--version', '1.2.0', '--release'])
    self.assertIs(self.cmd.inst.options.cls, ReleaseBranch)
    self.AssertNoDangerousOptions()

  def testCreateFactoryCommandParses(self):
    """Test `cros branch create` parses with '--factory' flag."""
    self.RunCommandMock(['create', '--version', '1.2.0', '--factory'])
    self.assertIs(self.cmd.inst.options.cls, FactoryBranch)
    self.AssertNoDangerousOptions()

  def testCreateFirmwareCommandParses(self):
    """Test `cros branch create` parses with '--firmware' flag."""
    self.RunCommandMock(['create', '--version', '1.2.0', '--firmware'])
    self.assertIs(self.cmd.inst.options.cls, FirmwareBranch)
    self.AssertNoDangerousOptions()

  def testCreateStabilizeCommandParses(self):
    """Test `cros branch create` parses with '--stabilize' flag."""
    self.RunCommandMock(['create', '--version', '1.2.0', '--stabilize'])
    self.assertIs(self.cmd.inst.options.cls, StabilizeBranch)
    self.AssertNoDangerousOptions()

  def testCreateCustomCommandParses(self):
    """Test `cros branch create` parses with '--custom' flag."""
    self.RunCommandMock(['create', '--version', '1.2.0', '--custom', 'branch'])
    self.assertEqual(self.cmd.inst.options.name, 'branch')
    self.assertIsNone(self.cmd.inst.options.cls)
    self.AssertNoDangerousOptions()

  def testCreateCustomCannotBeUsedWithDescriptor(self):
    """Test `cros branch create` does not allow --descriptor with --custom."""
    with self.assertRaises(BranchError):
      self.RunCommandMock([
          'create', '--version', '1.2.0', '--custom', 'branch', '--descriptor',
          'blah'
      ])

  def testCreateSyncsToFile(self):
    """Test `cros branch create` calls repo_sync_manifest to sync to file."""
    self.RunCommandMock(['create', '--file', 'manifest.xml', '--stabilize'])
    manifest_path = os.path.abspath('manifest.xml')
    self.AssertSyncedUsingRepo(['--manifest-name', manifest_path])

  def testCreateSyncsToVersion(self):
    """Test `cros branch create` calls repo_sync_manifest to sync to version."""
    self.RunCommandMock(['create', '--version', '1.2.0', '--stabilize'])
    self.AssertSynced(['--version', '1.2.0'])

  def testRenameSyncsToBranch(self):
    """Test `cros branch rename` calls repo_sync_manifest to sync to branch."""
    self.RunCommandMock(['rename', 'branch', 'new-branch'])
    self.AssertSynced(['--branch', 'branch'])

  def testDeleteSyncsToBranch(self):
    """Test `cros branch delete` calls repo_sync_manifest to sync to branch."""
    self.RunCommandMock(['delete', 'branch'])
    self.AssertSynced(['--branch', 'branch'])
