# -*- coding: utf-8 -*-
# Copyright 2020 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

# TODO: Name the build target.
"""{Build Target} configs."""

from __future__ import print_function

# BUILD CONFIGS.

# TODO: Fill out BUILD_WORKON_PACKAGES.
# The packages that need to be `cros_workon`ed.
BUILD_WORKON_PACKAGES = (
    '',
)

# TODO: Fill out BUILD_PACKAGES.
# All packages that need to be built.
BUILD_PACKAGES = BUILD_WORKON_PACKAGES + (
    '',
)

# End BUILD CONFIGS.

# FLASH CONFIGS.

# TODO: Set any required force command constants with explanation.
# TODO: Delete this comment block.
# Force flash command constants: DEPLOY_{SSH,SERVO}_FORCE_{FLASHROM,FUTILITY}.
# Any of the constants may be used, simply set to True to enable.

def is_fast_required(use_futility, servo):
  """Returns true if --fast is necessary to flash successfully.

  TODO: Document the bug/reason for the force if this function is required,
    otherwise delete it all together.

  Args:
    use_futility (bool): True if futility is to be used, False if flashrom.
    servo (servo_lib.Servo): The servo connected to the target DUT.

  Returns:
    bool: True if fast is necessary, False otherwise.
  """
  return False


def get_commands(servo):
  """Get specific flash commands for the build target.

  Each board needs specific commands including the voltage for Vref, to turn
  on and turn off the SPI flash. The get_*_commands() functions provide a
  board-specific set of commands for these tasks. The voltage for this board
  needs to be set to 1.8 V.

  Args:
    servo (servo_lib.Servo): The servo connected to the target DUT.

  Returns:
    list: [dut_control_on, dut_control_off, flashrom_cmd, futility_cmd]
      dut_control*=2d arrays formmated like [["cmd1", "arg1", "arg2"],
                                             ["cmd2", "arg3", "arg4"]]
                     where cmd1 will be run before cmd2
      flashrom_cmd=command to flash via flashrom
      futility_cmd=command to flash via futility
  """
  dut_control_on = []
  dut_control_off = []
  # TODO: Add the supported servo cases and their commands.
  if servo:
    programmer = ''
  else:
    raise Exception('%s not supported' % servo.version)

  flashrom_cmd = ['flashrom', '-p', programmer, '-w']
  futility_cmd = ['futility', 'update', '-p', programmer, '-i']

  return [dut_control_on, dut_control_off, flashrom_cmd, futility_cmd]

# End FLASH CONFIGS.
