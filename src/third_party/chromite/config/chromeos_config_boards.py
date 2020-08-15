# -*- coding: utf-8 -*-
# Copyright (c) 2012 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Configuration options for cbuildbot boards."""

from __future__ import print_function

#
# Define assorted constants describing various sets of boards.
#

# Base per-board configuration.
# Every board must appear in exactly 1 of the following sets.

#
# Define assorted constants describing various sets of boards.
#

# Base per-board configuration.
# Every board must appear in exactly 1 of the following sets.

arm_internal_release_boards = frozenset([
    'arkham',
    'beaglebone',
    'beaglebone_servo',
    'capri-zfpga',
    'gale',
    'kevin-arc64',
    'littlejoe',
    'nyan_big',
    'nyan_blaze',
    'oak',
    'veyron_jaq',
    'veyron_jerry',
    'veyron_mighty',
    'veyron_minnie',
    'veyron_rialto',
    'veyron_speedy',
    'viking',
    'viking-poc2',
    'whirlwind',
])

arm_external_boards = frozenset([
    'arm-generic',
    'arm64-generic',
    'arm64-llvmpipe',
    'tael',
])

x86_internal_release_boards = frozenset([
    'deltaur',
    'falco_li',
    'glados',
    'guado_labstation',
    'jecht',
    'lakitu',
    'lakitu-gpu',
    'lakitu_next',
    'monroe',
    'poppy',
    'samus-kernelnext',
    'sludge',
    'wristpin',
])

x86_external_boards = frozenset([
    'amd64-generic',
    'moblab-generic-vm',
    'tatl',
    'x32-generic',
])

# Board can appear in 1 or more of the following sets.
brillo_boards = frozenset([
    'arkham',
    'gale',
    'mistral',
    'whirlwind',
])

accelerator_boards = frozenset([
    'fizz-accelerator',
])

beaglebone_boards = frozenset([
    'beaglebone',
    'beaglebone_servo',
])

dustbuster_boards = frozenset([
    'wristpin',
])

lakitu_boards = frozenset([
    # Although its name doesn't indicate any lakitu relevance,
    # kumo board is developed by the lakitu-dev team.
    'kumo',
    'lakitu',
    'lakitu-gpu',
    'lakitu-nc',
    'lakitu-st',
    'lakitu_next',
])

lassen_boards = frozenset([
    'lassen',
])

loonix_boards = frozenset([
    'capri',
    'capri-zfpga',
    'cobblepot',
    'gonzo',
    'lasilla-ground',
    'octavius',
    'romer',
    'wooten',
])

reven_boards = frozenset([
    'reven',
])

wshwos_boards = frozenset([
    'littlejoe',
    'viking',
    'viking-poc2',
])

moblab_boards = frozenset([
    'fizz-moblab',
    'moblab-generic-vm',
])

scribe_boards = frozenset([
    'guado-macrophage',
])

termina_boards = frozenset([
    'sludge',
    'tatl',
    'tael',
])

nofactory_boards = (
    lakitu_boards | termina_boards | lassen_boards | reven_boards | frozenset([
        'x30evb',
    ])
)

toolchains_from_source = frozenset([
    'x32-generic',
])

noimagetest_boards = (lakitu_boards | loonix_boards | termina_boards
                      | scribe_boards | wshwos_boards | dustbuster_boards)

nohwqual_boards = (lakitu_boards | lassen_boards | loonix_boards
                   | termina_boards | beaglebone_boards | wshwos_boards
                   | dustbuster_boards | reven_boards)

norootfs_verification_boards = frozenset([
    'kumo',
])

base_layout_boards = lakitu_boards | termina_boards

builder_incompatible_binaries_boards = frozenset([
    'grunt',
    'zork',
])
